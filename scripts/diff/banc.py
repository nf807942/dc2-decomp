#!/usr/bin/env python3
"""Mesure N formes d'une fonction en une compilation et un diff.

    make banc S=<symbole> N=32     # éprouve la fidélité du banc

**Le nombre de formes qu'une question supporte décide de ce qu'on peut lui
demander**, et c'est le seul levier qui vaille à l'échelle du binaire. Le
chemin parcouru :

| harnais | coût par forme |
|---|---|
| `make diff` sur l'unité | 2 500 à 5 000 ms |
| `make lot`, une forme par compilation | 546 ms |
| ce banc, N formes par compilation | mesuré ci-dessous |

Le profil disait où aller : sur les 244 ms d'une compilation, **108 ms sont le
seul démarrage de wibo et de MWCC**, et 26 ms l'appel à objdiff. Tout cela est
un coût fixe, donc il s'amortit dès qu'une compilation porte plusieurs formes.

Le dessin est le suivant. Chaque forme reçoit un suffixe propre — sur la
fonction et sur chaque type qu'elle définit — et les N formes tiennent dans une
seule unité de traduction, précédée d'un seul exemplaire du contexte. En face,
une **référence synthétique** porte les mêmes N noms : le désassemblage de la
fonction, recopié N fois avec ses étiquettes renommées. objdiff compare alors
les deux objets d'un coup, symbole par symbole, sans qu'on ait à lui demander
quoi que ce soit.

**Une forme qui ne compile pas emporte tout le lot.** Le banc coupe alors le lot
en deux et recommence : log(N) compilations suffisent à isoler la fautive, et
c'est encore très loin de N.

Ce que cela ne remplace pas : la reconstruction complète reste le seul verdict
sur un gain. Ce banc départage des formes, il ne prouve rien.
"""

from __future__ import annotations

import argparse
import hashlib
import json
import os
import re
import sys
import tempfile
import time
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from lib.project import ROOT, run  # noqa: E402

sys.path.insert(0, str(Path(__file__).resolve().parent))
import lot  # noqa: E402

if hasattr(sys.stdout, "reconfigure"):
    sys.stdout.reconfigure(encoding="utf-8", errors="replace")

CACHE = ROOT / "build" / "banc"
AS = "mips-ps2-decompals-as"
ASFLAGS = ["-EL", "-march=r5900", "-mabi=eabi", "-G0", "-mno-pdr",
           "-non_shared", "-I", "include", "-I", "asm"]

# `glabel Nom` ouvre une fonction ; `nmlabel` ou le `glabel` suivant la ferme.
_OUVRE = re.compile(r"^glabel (\w+)\s*$", re.MULTILINE)
_FERME = re.compile(r"^(?:glabel|nmlabel) ", re.MULTILINE)
# Un type que le fragment définit lui-même, et qu'il faut donc suffixer pour que
# N exemplaires cohabitent.
_DEFINIT = re.compile(r"\b(?:typedef\s+)?(?:struct|class|union)\s+(\w+)\s*\{")


def _bloc_reference(unite: str, symbole: str) -> str | None:
    """Le désassemblage de la seule fonction visée, étiquettes comprises."""
    source = ROOT / "ref" / "asm" / "text" / (unite + ".s")
    if not source.exists():
        return None
    texte = source.read_text(encoding="utf-8", errors="replace")
    debut = None
    for trouve in _OUVRE.finditer(texte):
        if trouve.group(1) == symbole:
            debut = trouve.start()
            break
    if debut is None:
        return None
    suite = _FERME.search(texte, trouve.end())
    return texte[debut:suite.start() if suite else len(texte)]


def _suffixe(bloc: str, symbole: str, rang: int) -> str:
    """Le bloc assembleur d'une copie, ses étiquettes locales renommées.

    Les étiquettes internes — `.L00195E70` — se répètent d'une copie à l'autre et
    l'assembleur refuse un symbole défini deux fois. Elles reçoivent donc le même
    suffixe que la fonction.
    """
    marque = "__v%d" % rang
    # `glabel` ouvre la fonction et `endlabel` la referme, toutes deux sous son
    # nom : ne renommer que l'ouverture laissait `.size` porter sur un symbole
    # que rien ne définissait plus.
    bloc = re.sub(r"\b%s\b" % re.escape(symbole), symbole + marque, bloc)
    return re.sub(r"(\.L[0-9A-Fa-f]+)", r"\1" + marque, bloc)


def reference(unite: str, symbole: str, combien: int,
              travail: Path) -> Path | None:
    """Assemble une référence portant `combien` copies nommées de la fonction."""
    empreinte = hashlib.sha1(("%s|%s|%d" % (unite, symbole, combien))
                             .encode()).hexdigest()[:12]
    CACHE.mkdir(parents=True, exist_ok=True)
    objet = CACHE / ("%s.o" % empreinte)
    if objet.exists():
        return objet
    bloc = _bloc_reference(unite, symbole)
    if bloc is None:
        return None
    texte = ('.include "macro.inc"\n\n.set noat\n.set noreorder\n\n'
             '.section .text, "ax"\n\n')
    texte += "\n".join(_suffixe(bloc, symbole, rang) for rang in range(combien))
    source = travail / "reference.s"
    source.write_text(texte, encoding="utf-8")
    fait = run([AS, *ASFLAGS, "-o", str(objet), str(source)],
               capture_output=True, text=True)
    if fait.returncode != 0 or not objet.exists():
        return None
    return objet


def _renomme(fragment: str, symbole: str, rang: int) -> str:
    """Une forme, tous ses noms propres suffixés, pour cohabiter avec les autres.

    Le suffixe porte sur la fonction *et* sur chaque type que le fragment
    définit : deux formes peuvent différer par leur structure, et les poser
    côte à côte sans les distinguer rendrait « tag redefined ».
    """
    marque = "__v%d" % rang
    rendu = re.sub(r"\b%s\b" % re.escape(symbole), symbole + marque, fragment)
    for tag in sorted(set(_DEFINIT.findall(fragment)), key=len, reverse=True):
        rendu = re.sub(r"\b%s\b" % re.escape(tag), tag + marque, rendu)
    return rendu


def _compile_lot(amont: str, formes: list[str], symbole: str,
                 rangs: list[int], travail: Path) -> tuple[Path | None, str]:
    texte = amont + "\n".join(_renomme(forme, symbole, rang)
                              for forme, rang in zip(formes, rangs))
    return lot._compile(texte, travail)


def _mesures(notre: Path, cible: Path) -> dict[str, float]:
    """L'appariement de chaque symbole, en un seul appel à objdiff."""
    fait = run(["objdiff-cli", "diff", "-1", str(cible), "-2", str(notre),
                "-o", "-", "--format", "json"],
               capture_output=True, text=True)
    if fait.returncode != 0:
        return {}
    try:
        charge = json.loads(fait.stdout)
    except json.JSONDecodeError:
        return {}
    return {e["name"]: e.get("match_percent")
            for e in charge.get("right", {}).get("symbols", [])
            if e.get("name")}


def banc(symbole: str, unite: str,
         variantes: list[str]) -> list[float | None]:
    """Mesure toutes les formes. Rend un appariement par forme, `None` si perdue.

    Une forme qui ne compile pas emporte le lot ; on coupe alors en deux. Le
    coût reste logarithmique, et une seule forme fautive ne fait pas retomber
    au rythme d'une compilation par forme.
    """
    amont = lot.contexte(unite)
    rendu: list[float | None] = [None] * len(variantes)
    with tempfile.TemporaryDirectory() as tmp:
        travail = Path(tmp)
        cible = reference(unite, symbole, len(variantes), travail)
        if cible is None:
            return rendu

        a_faire = [list(range(len(variantes)))]
        while a_faire:
            rangs = a_faire.pop()
            objet, _ = _compile_lot(amont, [variantes[r] for r in rangs],
                                    symbole, rangs, travail)
            if objet is None:
                if len(rangs) == 1:
                    continue        # cette forme-là ne compile pas
                milieu = len(rangs) // 2
                a_faire += [rangs[:milieu], rangs[milieu:]]
                continue
            scores = _mesures(objet, cible)
            for rang in rangs:
                rendu[rang] = scores.get("%s__v%d" % (symbole, rang))
    return rendu


def fidelite(symbole: str, combien: int) -> int:
    """Le banc rend-il ce que la mesure une-à-une rend ? Sans quoi il ne sert à rien.

    La réserve est celle du dépôt : la position d'une fonction dans sa section
    décide de l'alignement de ses têtes de boucle. N copies à la file, c'est
    précisément N positions différentes.
    """
    fiches = json.loads((ROOT / "progress" / "classes.json")
                        .read_text(encoding="utf-8"))
    fiche = fiches[symbole]
    fragment = (lot.CORPUS / (symbole + ".cpp")).read_text(encoding="utf-8")
    formes = [fragment] * combien

    depart = time.time()
    groupe = banc(symbole, fiche["unite"], formes)
    cout_banc = time.time() - depart

    depart = time.time()
    (seule, _), = lot.formes(symbole, fiche["unite"], [fragment])
    cout_seul = time.time() - depart

    distincts = sorted({p for p in groupe if p is not None})
    print("%s, %d copies identiques" % (symbole, combien))
    print("  une à une : %6.2f %%   %6.0f ms" % (seule or -1, 1000 * cout_seul))
    print("  au banc   : %s   %6.0f ms au total, %.0f ms par forme"
          % (", ".join("%.2f %%" % p for p in distincts) or "rien",
             1000 * cout_banc, 1000 * cout_banc / combien))
    perdus = sum(1 for p in groupe if p is None)
    if perdus:
        print("  %d formes sans mesure" % perdus)
    if len(distincts) == 1 and abs(distincts[0] - (seule or -1)) < 0.005:
        print("  le banc rend le même chiffre que la mesure une à une")
        return 0
    print("  ÉCART : le banc ne rend pas le même chiffre")
    return 1


def main(argv: list[str]) -> int:
    parseur = argparse.ArgumentParser(description=__doc__)
    parseur.add_argument("--symbole", default="GetReadBGInfo__FPc")
    parseur.add_argument("--combien", type=int, default=32)
    options = parseur.parse_args(argv)
    return fidelite(options.symbole, options.combien)


if __name__ == "__main__":
    raise SystemExit(main(sys.argv[1:]))
