#!/usr/bin/env python3
"""Compare l'image construite à celle du disque.

Le verdict utile n'est pas « identique ou non » mais « où et combien » : tant
que le projet remplace du désassemblage par du C++, un écart désigne la
fonction qui vient de changer.
"""

from __future__ import annotations

import hashlib
import sys
from pathlib import Path

# L'adresse de chargement, pour que les écarts se lisent en adresses du jeu.
LOAD_VADDR = 0x00100000


def main() -> int:
    if len(sys.argv) != 3:
        print("usage : verify.py <construit> <référence>", file=sys.stderr)
        return 2

    built_path, reference_path = Path(sys.argv[1]), Path(sys.argv[2])
    if not reference_path.exists():
        print(f"référence absente : {reference_path} — lancez `make setup`",
              file=sys.stderr)
        return 2

    built = built_path.read_bytes()
    reference = reference_path.read_bytes()

    if built == reference:
        print(f"identique au disque — {len(built)} octets, "
              f"sha1 {hashlib.sha1(built).hexdigest()}")
        return 0

    if len(built) != len(reference):
        print(f"taille : construit {len(built)} octets, disque {len(reference)}")

    # Les écarts se regroupent en plages : une fonction qui diffère donne une
    # plage, pas des octets épars.
    common = min(len(built), len(reference))
    ranges: list[list[int]] = []
    for i in range(common):
        if built[i] == reference[i]:
            continue
        if ranges and i - ranges[-1][1] <= 16:
            ranges[-1][1] = i
        else:
            ranges.append([i, i])

    total = sum(end - start + 1 for start, end in ranges)
    print(f"{total} octets diffèrent sur {common} "
          f"({100 * total / common:.3f} %), en {len(ranges)} plages")

    for start, end in ranges[:20]:
        print(f"  0x{LOAD_VADDR + start:08X} .. 0x{LOAD_VADDR + end:08X}"
              f"  ({end - start + 1} octets)")
    if len(ranges) > 20:
        print(f"  … et {len(ranges) - 20} autres plages")

    return 1


if __name__ == "__main__":
    sys.exit(main())
