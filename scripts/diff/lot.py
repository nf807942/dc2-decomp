#!/usr/bin/env python3
"""Mesure plusieurs formes d'une fonction sans regreffer son unité.

    make lot S=<symbole> N=40        # éprouve la fidélité sur N tirages
    from lot import formes           # l'interface que l'affinage emploie

**Le nombre d'essais qu'une question supporte décide de ce qu'on peut lui
demander.** Chaque mesure passait jusqu'ici par un `make` sur l'unité entière :
2,1 s de coût fixe plus 8,5 ms par greffe, soit deux à cinq secondes. Une
question ne pouvait donc porter que sur une dizaine de formes, et le permuteur
comme l'affinage travaillaient à ce rythme.

La greffe n'est pourtant pas nécessaire pour *mesurer* : objdiff compare deux
objets symbole par symbole, et notre objet n'a besoin de porter que la fonction
visée. On compile donc l'unité privée de ses `INCLUDE_ASM`, avec le fragment à
la place de la greffe, et l'on interroge objdiff sur ce seul symbole.

**La réserve du dépôt a été levée par la mesure, non par le raisonnement.**
« La position d'une fonction dans sa section décide de l'alignement de ses têtes
de boucle » : si cela mordait, une fonction mesurée hors greffe ne rendrait pas
le score qu'elle rend en unité. Sur quarante fonctions tirées au hasard dans le
corpus des quasi-succès, **trente-six ont rendu le même score au centième près,
aucune n'a divergé**, et les quatre restantes échouaient déjà à compiler en
unité, pour péremption du fragment. Le coût tombe à 550 ms.

Ce que cela ne remplace pas : la reconstruction complète reste le seul verdict
sur un gain. `match_percent` départage deux formes ; il ne prouve rien.
"""

from __future__ import annotations

import argparse
import json
import os
import random
import re
import sys
import tempfile
import time
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from lib.project import ROOT, run  # noqa: E402

if hasattr(sys.stdout, "reconfigure"):
    sys.stdout.reconfigure(encoding="utf-8", errors="replace")

MWCC = ROOT / "tools" / "compilers" / "mwcps2-3.0-011126" / "mwccps2.exe"
CORPUS = ROOT / "build" / "proches"

# Les mêmes drapeaux que le Makefile, moins ce qui ne concerne que mwccgap.
# `-c` y est explicite : c'est mwccgap qui l'ajoutait.
DRAPEAUX = ["-c", "-O4,p", "-lang", "c++", "-char", "unsigned",
            "-str", "readonly", "-Cpp_exceptions", "off", "-RTTI", "off",
            "-sym", "on", "-i", "include", "-i", "src"]


def contexte(unite: str) -> str:
    """Ce que l'unité déclare, sans ses greffes.

    Inventer les déclarations manquantes ne marche qu'à moitié : un nom inconnu
    peut être un appelé, une globale ou un type, et se tromper coûte la fonction
    entière — une sonde qui déclarait tout nom inconnu comme fonction perdait
    seize fonctions sur quarante. L'unité, elle, les porte déjà et exactes.

    **La taille déclarée d'une globale décide de `%gp_rel` contre `%hi`/`%lo`** :
    c'est la raison de fond de ne rien improviser ici.

    Seuls les `INCLUDE_ASM` s'en vont : MWCC seul ne sait pas les lire, et ce
    qu'ils désignent n'entre pas dans la mesure d'un symbole.
    """
    source = ROOT / "src" / (unite + ".cpp")
    if not source.exists():
        return ""
    texte = source.read_text(encoding="utf-8", errors="replace")
    return "".join(ligne for ligne in texte.splitlines(keepends=True)
                   if "INCLUDE_ASM(" not in ligne)


def _compile(texte: str, travail: Path) -> tuple[Path | None, str]:
    """Compile un texte entier. Rend l'objet, ou la plainte de MWCC."""
    source = travail / "lot.c"      # `.c` comme mwccgap : `-lang c++` tranche
    objet = travail / "lot.o"
    source.write_text(texte, encoding="utf-8")
    if objet.exists():
        objet.unlink()
    fait = run(["wibo", str(MWCC), *DRAPEAUX, "-o", str(objet), str(source)],
               capture_output=True, text=True,
               env={**os.environ, "MWCIncludes": "include"})
    if objet.exists():
        return objet, ""
    plainte = (fait.stdout or "") + (fait.stderr or "")
    lignes = [l.rstrip() for l in plainte.splitlines()
              if l.startswith("#") and not l.startswith("###")]
    return None, "\n".join(lignes[-8:])


def _mesure(objet: Path, unite: str, symbole: str) -> float | None:
    """L'appariement de ce seul symbole, contre le désassemblage de référence."""
    cible = ROOT / "build" / "ref" / "asm" / "text" / (unite + ".o")
    fait = run(["objdiff-cli", "diff", "-1", str(cible), "-2", str(objet),
                "-o", "-", "--format", "json", symbole],
               capture_output=True, text=True)
    if fait.returncode != 0:
        return None
    try:
        charge = json.loads(fait.stdout)
    except json.JSONDecodeError:
        return None
    for entree in charge.get("right", {}).get("symbols", []):
        if entree.get("name") == symbole:
            return entree.get("match_percent")
    return None


def formes(symbole: str, unite: str,
           variantes: list[str]) -> list[tuple[float | None, str]]:
    """Mesure chaque forme du fragment. Rend (appariement, plainte) par forme.

    Le contexte de l'unité se calcule une fois pour tout le lot : c'est ce qui
    rend l'essai marginal aussi bon marché qu'une compilation.
    """
    amont = contexte(unite)
    rendu = []
    with tempfile.TemporaryDirectory() as tmp:
        travail = Path(tmp)
        for variante in variantes:
            objet, plainte = _compile(amont + variante, travail)
            if objet is None:
                rendu.append((None, plainte))
                continue
            rendu.append((_mesure(objet, unite, symbole), ""))
    return rendu


def fidelite(combien: int) -> int:
    """Le score hors greffe est-il celui de l'unité ? La question de l'axe.

    On tire dans le corpus des quasi-succès, dont le score en unité est connu et
    enregistré, et l'on compare. C'est la seule mesure qui autorise à employer ce
    module partout ailleurs.
    """
    fiches = json.loads((ROOT / "progress" / "classes.json")
                        .read_text(encoding="utf-8"))
    tirage = sorted(fiches)
    random.Random(0).shuffle(tirage)
    tirage = tirage[:combien]

    exact = ecart = rate = 0
    depart = time.time()
    for symbole in tirage:
        fiche = fiches[symbole]
        chemin = CORPUS / (symbole + ".cpp")
        if not chemin.exists():
            continue
        (part, plainte), = formes(symbole, fiche["unite"],
                                  [chemin.read_text(encoding="utf-8")])
        if part is None:
            rate += 1
            print("  %-44s ne compile pas hors greffe" % symbole[:44],
                  flush=True)
            continue
        if abs(part - fiche["part"]) < 0.005:
            exact += 1
        else:
            ecart += 1
            print("  %-44s hors greffe %6.2f %%, en unité %6.2f %%"
                  % (symbole[:44], part, fiche["part"]), flush=True)
    juges = exact + ecart
    print()
    print("%d identiques sur %d jugées, %d écarts, %d ne compilent pas"
          % (exact, juges, ecart, rate))
    print("%.0f ms par mesure" % (1000 * (time.time() - depart)
                                  / max(len(tirage), 1)))
    return 0 if ecart == 0 else 1


def main(argv: list[str]) -> int:
    parseur = argparse.ArgumentParser(description=__doc__)
    parseur.add_argument("--fidelite", type=int, metavar="N",
                         help="compare N mesures hors greffe à celles de l'unité")
    parseur.add_argument("--symbole", help="mesure ce seul fragment du corpus")
    options = parseur.parse_args(argv)

    if options.fidelite:
        return fidelite(options.fidelite)
    if options.symbole:
        fiches = json.loads((ROOT / "progress" / "classes.json")
                            .read_text(encoding="utf-8"))
        fiche = fiches[options.symbole]
        fragment = (CORPUS / (options.symbole + ".cpp")).read_text(
            encoding="utf-8")
        (part, plainte), = formes(options.symbole, fiche["unite"], [fragment])
        print("%s : %s" % (options.symbole,
                           "%.2f %%" % part if part is not None
                           else "ne compile pas\n" + plainte))
        return 0
    parseur.print_help()
    return 1


if __name__ == "__main__":
    raise SystemExit(main(sys.argv[1:]))
