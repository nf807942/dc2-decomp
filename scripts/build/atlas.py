#!/usr/bin/env python3
"""L'atlas des types : ce que m2c infère du binaire entier, fusionné.

    make atlas                 relève tout, écrit progress/atlas.json
    make atlas ARGS=--type=CMap   ce que l'atlas dit d'un type

m2c infère la disposition d'une structure à partir des accès qu'il voit. Sur
une fonction, il en tire quatre champs ; sur une unité entière, plusieurs
dizaines ; sur les 414 unités du binaire, la disposition de tout ce que le jeu
manipule. Personne ne fusionnait ces inférences — c'est tout l'objet de ce
module, et c'est le seul chantier sur le chemin critique du projet.

**La passe tourne sans contexte, et c'est essentiel.** Un type déclaré au
contexte — même pauvre, même vide — fait cesser l'inférence : `ClsMes` rendait
zéro champ avec contexte et 136 sans. Le contexte se construit *à partir* de
l'atlas, jamais l'inverse.

Ce que l'atlas ne dit pas, et qu'il ne faut pas lui faire dire : les noms de
champs restent ceux que m2c invente ; une union ou un héritage fausse les
décalages ; et il ignore les tables virtuelles. Ce qu'il donne est la
disposition, qui est précisément ce qui bloque le reste.

Le fichier est dérivé du binaire : il ne se versionne pas.
"""

from __future__ import annotations

import argparse
import collections
import json
import re
import subprocess
import sys
import tempfile
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from lib.mangling import demangle  # noqa: E402
from lib.project import (REF_DIR, ROOT, functions,  # noqa: E402
                         grafted_symbols)

ATLAS = ROOT / "progress" / "atlas.json"
M2C = ROOT / "tools" / "m2c" / "m2c.py"
CIBLE = "mipsee-mwcc-c++"

# Le marqueur que le désassembleur pose devant chaque symbole non apparié ; m2c
# y voit une instruction hors fonction et s'arrête dessus.
_NMLABEL = re.compile(r"^\s*nmlabel\b")
# `typedef struct X {` … `} X;` — une structure inférée, et son nom.
_BLOC = re.compile(r"^typedef struct (\w+) \{(.*?)^\} \1;", re.MULTILINE | re.DOTALL)
# `/* 0x1C */ f32 unk1C;   /* inferred */` — un champ, son décalage, son type.
_CHAMP = re.compile(r"/\* (0x[0-9A-Fa-f]+) \*/\s+(.+?)\s+(\w+)(\[[^\]]*\])?;")


def releve(chemin: Path) -> dict[str, dict[int, str]]:
    """Les structures que m2c infère d'une unité, par type et par décalage."""
    texte = chemin.read_text(encoding="utf-8", errors="replace")
    propre = "".join(ligne for ligne in texte.splitlines(keepends=True)
                     if not _NMLABEL.match(ligne))

    with tempfile.NamedTemporaryFile("w", suffix=".s", encoding="utf-8",
                                     delete=False) as fichier:
        fichier.write(propre)
        provisoire = fichier.name
    try:
        rendu = subprocess.run(
            [sys.executable, str(M2C), "--target", CIBLE, provisoire],
            cwd=ROOT, capture_output=True, text=True, timeout=900)
    except subprocess.TimeoutExpired:
        return {}
    finally:
        Path(provisoire).unlink(missing_ok=True)

    trouve: dict[str, dict[int, str]] = {}
    for nom, corps in _BLOC.findall(rendu.stdout):
        champs: dict[int, str] = {}
        for decalage, kind, champ, tableau in _CHAMP.findall(corps):
            # Le remplissage n'est pas un champ : c'est ce que m2c n'a pas vu.
            if champ.startswith("pad"):
                continue
            champs[int(decalage, 16)] = (kind + (tableau or "")).strip()
        if champs:
            trouve[nom] = champs
    return trouve


def fusionne(releves: list[dict[str, dict[int, str]]]) -> dict:
    """Réunit les relevés : par type, par décalage, chaque type vu et son compte.

    Le compte des témoins est ce qui départagera plus tard : un type proposé par
    douze unités et un autre par une seule ne se valent pas, et l'arbitrage doit
    voir cet écart plutôt que de trancher à l'aveugle.
    """
    atlas: dict[str, dict[int, collections.Counter]] = {}
    unites: collections.Counter = collections.Counter()
    for trouve in releves:
        for nom, champs in trouve.items():
            unites[nom] += 1
            table = atlas.setdefault(nom, {})
            for decalage, kind in champs.items():
                table.setdefault(decalage, collections.Counter())[kind] += 1
    return {
        "types": {
            nom: {
                "unites": unites[nom],
                "etendue": max(champs) if champs else 0,
                "champs": {
                    "0x%X" % decalage: dict(propositions.most_common())
                    for decalage, propositions in sorted(champs.items())
                },
            }
            for nom, champs in sorted(atlas.items())
        }
    }


def rapport(atlas: dict) -> None:
    """Ce que l'atlas porte, et ce qu'il faudra arbitrer."""
    types = atlas["types"]
    champs = sum(len(t["champs"]) for t in types.values())
    conflits = sum(1 for t in types.values()
                   for propositions in t["champs"].values()
                   if len(propositions) > 1)
    inconnus = sum(1 for t in types.values()
                   for propositions in t["champs"].values()
                   if "?" in propositions)

    print("\natlas : %d types, %d champs" % (len(types), champs))
    print("  décalages contredits : %d  (%.1f %%)"
          % (conflits, 100 * conflits / champs if champs else 0))
    print("  décalages que m2c ne type pas : %d" % inconnus)

    # Ce que l'atlas couvre des classes qui restent à écrire : c'est là que se
    # joue la suite, et non sur le compte brut de types.
    greffees = grafted_symbols()
    par_classe: collections.Counter = collections.Counter()
    for nom in greffees:
        symbole = demangle(nom)
        if symbole and symbole.cls:
            par_classe[symbole.cls] += 1
    lourdes = [nom for nom, compte in par_classe.items() if compte > 10]
    couvertes = [nom for nom in lourdes if nom in types]
    print("  classes de plus de dix méthodes : %d couvertes sur %d"
          % (len(couvertes), len(lourdes)))

    table = functions()
    poids = sum(table[n].size for n in greffees
                if (s := demangle(n)) and s.cls in types and n in table)
    print("  octets restants dont la classe est décrite : %d" % poids)

    print("\n  les mieux décrits :")
    for nom, decrit in sorted(types.items(),
                              key=lambda kv: -len(kv[1]["champs"]))[:10]:
        print("    %-28s %4d champs, étendue 0x%X, vu dans %d unités"
              % (nom, len(decrit["champs"]), decrit["etendue"], decrit["unites"]))


def main(argv: list[str]) -> int:
    parseur = argparse.ArgumentParser(description=__doc__)
    parseur.add_argument("--type", help="montre ce que l'atlas dit d'un type")
    parseur.add_argument("--fils", type=int, default=8)
    options = parseur.parse_args(argv)

    if options.type:
        if not ATLAS.exists():
            raise SystemExit("progress/atlas.json absent — lancez `make atlas`")
        decrit = json.loads(ATLAS.read_text(encoding="utf-8"))["types"]
        trouve = decrit.get(options.type)
        if trouve is None:
            raise SystemExit("%s : l'atlas ne le connaît pas" % options.type)
        print("%s — %d champs, étendue 0x%X, vu dans %d unités\n"
              % (options.type, len(trouve["champs"]), trouve["etendue"],
                 trouve["unites"]))
        for decalage, propositions in trouve["champs"].items():
            rendu = ", ".join("%s ×%d" % (kind, compte)
                              for kind, compte in propositions.items())
            marque = " <-- contredit" if len(propositions) > 1 else ""
            print("  %-8s %s%s" % (decalage, rendu, marque))
        return 0

    unites = sorted((REF_DIR / "text").rglob("*.s"))
    if not unites:
        raise SystemExit("ref/asm/text absent — lancez `make setup`")
    print("relevé de %d unités, %d fils" % (len(unites), options.fils))

    faits = 0
    releves = []
    with ThreadPoolExecutor(max_workers=options.fils) as pool:
        for trouve in pool.map(releve, unites):
            releves.append(trouve)
            faits += 1
            if faits % 50 == 0:
                print("  %d / %d" % (faits, len(unites)), flush=True)

    atlas = fusionne(releves)
    ATLAS.parent.mkdir(exist_ok=True)
    ATLAS.write_text(json.dumps(atlas, ensure_ascii=False, indent=1),
                     encoding="utf-8")
    rapport(atlas)
    print("\natlas : %s  (%d Kio)"
          % (ATLAS.relative_to(ROOT), ATLAS.stat().st_size // 1024))
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
