#!/usr/bin/env python3
"""Ce que m2c ne sait pas lire, et combien de fonctions cela coûte.

    make instructions

Une fonction dont une seule instruction échappe à m2c est perdue **entière** :
il rend `M2C_ERROR` et le bloc entier devient illisible. Le coût d'une
instruction ne se compte donc pas en occurrences mais en fonctions touchées, et
en octets de binaire.

C'est ce compte qui a désigné l'accumulateur flottant du R5900 — `mula.s`,
`madd.s`, `adda.s` — comme le plus gros verrou du projet : 428 fonctions,
99 256 octets, rouvertes par un correctif de trente lignes.

**Le relevé sait se tromper dans un sens, jamais dans l'autre.** Il compare les
mnémoniques du désassemblage à celles que le source de m2c cite littéralement ;
une instruction traitée par une règle (le second pipeline multiplicateur, dont
`mult1` se ramène à `mult`) passe donc pour inconnue alors qu'elle est gérée. Ce
qu'il rend est une liste de suspects à vérifier, non un verdict — et la
vérification est d'une ligne : `scripts/diff/decompile.py <fonction>`.
"""

from __future__ import annotations

import argparse
import collections
import re
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from lib.project import ROOT, functions  # noqa: E402

# `/* 0C3490 001C3490 C0FFBD27 */  addiu  $sp, $sp, -0x40` — le mnémonique vient
# après les trois champs que le désassembleur met en commentaire.
_MNEMONIQUE = re.compile(r"^\s*/\*[^*]*\*/\s+([a-z][a-z0-9._]*)\s", re.M)
# Toute chaîne que la cible MIPS de m2c cite : ses tables d'instructions.
_CITEE = re.compile(r'"([a-z][a-z0-9._]*)"')


def connues() -> set[str]:
    """Les mnémoniques que le source de m2c nomme."""
    source = (ROOT / "tools" / "m2c" / "m2c" / "arch_mips.py").read_text(
        encoding="utf-8")
    trouvees = set(_CITEE.findall(source))
    # `mult1` se ramène à `mult` : m2c ôte le `1` du second pipeline avant de
    # chercher la règle. Sans cette reprise, 38 fonctions passaient pour
    # bloquées alors qu'elles se traduisent.
    trouvees |= {nom + "1" for nom in trouvees}
    return trouvees | {"glabel"}


def releve() -> tuple[dict[str, int], dict[str, int], int, int]:
    """Par mnémonique inconnue : les fonctions touchées et leurs octets."""
    table = functions()
    absentes = set()
    touchees: collections.Counter[str] = collections.Counter()
    octets: collections.Counter[str] = collections.Counter()
    total_fn = total_o = 0
    su = connues()
    for chemin in (ROOT / "asm" / "nonmatchings").rglob("*.s"):
        fonction = table.get(chemin.stem)
        if fonction is None:
            continue
        vues = set(_MNEMONIQUE.findall(
            chemin.read_text(encoding="utf-8", errors="replace")))
        manquantes = vues - su
        if not manquantes:
            continue
        absentes |= manquantes
        total_fn += 1
        total_o += fonction.size
        for nom in manquantes:
            touchees[nom] += 1
            octets[nom] += fonction.size
    return touchees, octets, total_fn, total_o


def main(argv: list[str]) -> int:
    parseur = argparse.ArgumentParser(description=__doc__)
    parseur.add_argument("--combien", type=int, default=20)
    options = parseur.parse_args(argv)

    touchees, octets, total_fn, total_o = releve()
    print("%d fonctions greffées portent une mnémonique que m2c ne cite pas, "
          "%d octets" % (total_fn, total_o))
    print("\n%-16s %8s %10s" % ("mnémonique", "fonctions", "octets"))
    for nom, compte in sorted(octets.items(), key=lambda kv: -kv[1])[:options.combien]:
        print("%-16s %8d %10d" % (nom, touchees[nom], compte))
    print("\nune ligne pour trancher : scripts/diff/decompile.py <fonction>")
    return 0


if __name__ == "__main__":
    raise SystemExit(main(sys.argv[1:]))
