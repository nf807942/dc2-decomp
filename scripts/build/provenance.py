#!/usr/bin/env python3
"""Ce que `.mwcats` dit de l'origine de chaque fonction.

    make provenance            le compte, et ce qui contredit le découpage

Le binaire porte une section `.mwcats` de 56 392 octets, propre à l'utilitaire
CATS de Metrowerks et non documentée publiquement — Ghidra a une demande ouverte
pour la reconnaître. Son format se lit pourtant sans peine, et il a été vérifié
sur les 6 912 enregistrements qu'elle contient :

    u16  marqueur   2, ou 258 (0x0102)
    u16  taille     la taille de la fonction, exacte dans 100 % des cas
    u32  adresse    son début

**Ce qu'elle apporte n'est pas la taille, que la table des symboles donne déjà,
mais la frontière.** Le compilateur n'y inscrit que ce qu'il compile lui-même :
les 928 fonctions qui en sont absentes sont, sans exception, le SDK Sony et le
runtime Metrowerks — du code livré compilé, dans un `.a` que l'éditeur de liens
a simplement recopié.

Le classement par dossier de `config/units.txt` est, lui, une heuristique qui
vote sur le poids des octets. Celle-ci ne vote pas : une fonction est dans
`.mwcats` ou elle n'y est pas.

C'est la réponse à deux questions du projet : quelles fonctions relèvent des
bibliothèques externes — celles dont l'oracle est ailleurs, pas dans le binaire
— et où le découpage actuel se trompe.
"""

from __future__ import annotations

import argparse
import collections
import struct
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from lib.project import ROOT, functions, unit_of  # noqa: E402

BINAIRE = ROOT / "rom" / "SCES_511.90"
# Le décalage et la taille que `objdump -h` donne pour `.mwcats`.
DEBUT, TAILLE = 0x0030CEB0, 0xDC48


def compilees() -> set[int]:
    """Les adresses que `.mwcats` porte, donc compilées depuis une source.

    L'appariement se fait sur le couple (adresse, taille) et non sur l'adresse
    seule : c'est lui qui a permis de vérifier le format, et il écarte les
    coïncidences d'un entier qui ressemblerait à une adresse.
    """
    if not BINAIRE.exists():
        raise SystemExit("rom/SCES_511.90 absent — lancez `make setup`")
    section = BINAIRE.read_bytes()[DEBUT:DEBUT + TAILLE]
    tailles = {(f.address, f.size) for f in functions().values()}

    trouve = set()
    for rang in range(0, len(section) - 7, 4):
        taille, = struct.unpack_from("<H", section, rang + 2)
        adresse, = struct.unpack_from("<I", section, rang + 4)
        if (adresse, taille) in tailles:
            trouve.add(adresse)
    return trouve


def main(argv: list[str]) -> int:
    parseur = argparse.ArgumentParser(description=__doc__)
    parseur.add_argument("--desaccords", action="store_true",
                         help="les fonctions que le découpage classe autrement")
    options = parseur.parse_args(argv)

    table = functions()
    dedans = compilees()

    externes = [(nom, f) for nom, f in table.items() if f.address not in dedans]
    print("fonctions du binaire            : %d" % len(table))
    print("compilées depuis une source     : %d" % len(dedans))
    print("venues d'une bibliothèque       : %d  (%d octets)"
          % (len(externes), sum(f.size for _, f in externes)))

    par_secteur = collections.Counter(
        (unit_of(nom) or "hors unité").split("/")[0] for nom, _ in externes)
    print("\nce que le découpage en dit :")
    for secteur, compte in par_secteur.most_common():
        print("   %-12s %4d" % (secteur, compte))

    # Le désaccord dans les deux sens : ce que le découpage range en
    # bibliothèque alors que le compilateur l'a compilé, et l'inverse.
    range_biblio = {nom for nom in table
                    if (unit_of(nom) or "").split("/")[0] in ("sdk", "runtime")}
    absentes = {nom for nom, _ in externes}
    a_tort = sorted(range_biblio - absentes)
    manque = sorted(absentes - range_biblio)

    print("\ndésaccords avec le découpage :")
    print("   rangées en bibliothèque, mais compilées avec le jeu : %d" % len(a_tort))
    print("   rangées dans le jeu, mais venues d'une bibliothèque : %d" % len(manque))

    if options.desaccords:
        for nom in a_tort[:40]:
            print("   %-46s %s" % (nom[:46], unit_of(nom)))
        if len(a_tort) > 40:
            print("   … et %d autres" % (len(a_tort) - 40))
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
