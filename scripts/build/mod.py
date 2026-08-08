#!/usr/bin/env python3
"""Retouche l'exécutable construit, sans toucher aux sources.

    make mod M="IsGeoStone__16CDngFloorManagerFi=1"
    make mod M="IsGeoStone__16CDngFloorManagerFi=1 IsSealFloor__16CDngFloorManagerFi=0"

Une fonction ainsi nommée est remplacée par un retour de la constante donnée,
dans `build/SCES_511.90` puis dans l'image. Les sources restent celles qui
rendent les octets du disque : le mod vit dans le fichier produit, jamais dans
ce qu'on écrit.

C'est la voie à prendre pour éprouver un comportement sans rien risquer : la
fonction garde sa taille, donc rien ne bouge autour d'elle et l'image reste
celle du commerce à cette fonction près.

La contrainte qui la justifiait, elle, est tombée. Le texte peut désormais
grossir : le bss est couvert par un segment déclaré, `_gp` se calcule depuis la
fin du fichier, et `pack.py` sait porter un exécutable plus long jusqu'à
l'image. Ce qui reste borné est le *petit* : les données atteintes par `$gp`
n'ont que seize octets de marge sous leur symbole le plus bas, et recentrer
`_gp` coûterait l'identité au disque — qu'on garde tant que tout n'est pas
recompilé, puisqu'elle est le seul oracle.
"""

from __future__ import annotations

import argparse
import struct
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from lib.project import BUILD_DIR, ROOT  # noqa: E402

BOOT_NAME = "SCES_511.90"

# `jr $ra` puis, dans son créneau de délai, `addiu $v0, $zero, valeur`. Deux
# instructions suffisent : ce qui suit dans la fonction n'est plus atteint.
JR_RA = 0x03E00008


def function_span(elf: bytes, symbol: str) -> tuple[int, int, int]:
    """L'adresse, la taille et l'offset dans le fichier d'une fonction."""
    shoff = struct.unpack_from("<I", elf, 0x20)[0]
    shentsize = struct.unpack_from("<H", elf, 0x2E)[0]
    shnum = struct.unpack_from("<H", elf, 0x30)[0]
    shstrndx = struct.unpack_from("<H", elf, 0x32)[0]

    sections = [struct.unpack_from("<10I", elf, shoff + i * shentsize)
                for i in range(shnum)]
    shstr = sections[shstrndx][4]

    def name_at(base: int, index: int) -> str:
        return elf[base + index:elf.index(b"\x00", base + index)].decode("latin1")

    main = next(s for s in sections if name_at(shstr, s[0]) == "main")

    for section in sections:
        if section[1] != 2:  # SHT_SYMTAB
            continue
        strtab = sections[section[6]][4]
        for i in range(section[5] // 16):
            offset = section[4] + i * 16
            name_idx, value, size, info, _other, _shndx = struct.unpack_from(
                "<IIIBBH", elf, offset)
            if (info & 0xF) == 2 and name_at(strtab, name_idx) == symbol:
                # main est chargée à son adresse virtuelle, donc le décalage
                # entre les deux est constant.
                return value, size, main[4] + value - main[3]

    raise SystemExit(f"{symbol} : aucune fonction de ce nom dans l'exécutable")


def apply(elf: bytearray, symbol: str, value: int) -> None:
    address, size, offset = function_span(bytes(elf), symbol)
    if size < 8:
        raise SystemExit(f"{symbol} ne fait que {size} octets")

    struct.pack_into("<I", elf, offset, JR_RA)
    # addiu $v0, $zero, valeur — la constante tient sur seize bits signés.
    struct.pack_into("<I", elf, offset + 4, 0x24020000 | (value & 0xFFFF))
    # Le reste de la fonction devient du remplissage : sa taille ne change pas,
    # donc rien de ce qui suit ne bouge.
    for pad in range(offset + 8, offset + size, 4):
        struct.pack_into("<I", elf, pad, 0)

    print(f"  {symbol}  0x{address:08X}  rend {value}"
          f"  ({size} octets conservés)")


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("assignments", nargs="+", metavar="SYMBOLE=VALEUR")
    args = parser.parse_args()

    executable = BUILD_DIR / BOOT_NAME
    if not executable.exists():
        raise SystemExit("build/SCES_511.90 absent — lancez `make elf`")

    elf = bytearray(executable.read_bytes())
    for assignment in args.assignments:
        if "=" not in assignment:
            raise SystemExit(f"« {assignment} » n'est pas SYMBOLE=VALEUR")
        symbol, raw = assignment.split("=", 1)
        apply(elf, symbol, int(raw, 0))

    executable.write_bytes(bytes(elf))
    print(f"\n{executable.relative_to(ROOT)} retouché."
          f" `make iso` porte le résultat dans l'image.")
    return 0


if __name__ == "__main__":
    sys.exit(main())
