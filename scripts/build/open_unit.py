#!/usr/bin/env python3
"""Ouvre une unité de travail : la déclare, puis écrit sa source de départ.

    make open S=CRunScript

La source part entièrement en `INCLUDE_ASM`, dans l'ordre des adresses — celui
que l'éditeur de liens attend. La construction doit alors rendre les octets du
disque sans qu'une ligne de C++ soit écrite : c'est ce qui prouve que la plage
est bien découpée, et le point de départ contre lequel chaque fonction se
mesurera ensuite.

Reste à lancer `make setup` pour que le désassembleur écrive les fonctions de
la plage une par fichier, puis `make build`.
"""

from __future__ import annotations

import argparse
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from lib.project import CONFIG_DIR, ROOT, SRC_DIR  # noqa: E402
from build.units import (class_of, group_by_class, intruders,  # noqa: E402
                         read_declared, read_functions)

TEMPLATE = """\
/* {title}
 *
 * Unité ouverte par `make open` : {count} fonctions, {octets} octets, de
 * 0x{start:08X} à 0x{end:08X}. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

"""


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("symbol", help="la classe dont ouvrir l'unité")
    parser.add_argument("--name", help="nom du fichier source (défaut : la classe en minuscules)")
    parser.add_argument("--force", action="store_true",
                        help="réécrit la source même si elle existe")
    args = parser.parse_args()

    functions = read_functions()
    groups = group_by_class(functions)

    group = groups.get(args.symbol)
    if group is None:
        raise SystemExit(f"{args.symbol} : aucune méthode ne porte cette classe")

    others = intruders(group, functions)
    if others:
        names = ", ".join(sorted({class_of(f.name) or "?" for f in others})[:4])
        raise SystemExit(
            f"{args.symbol} est entrecoupée par {len(others)} fonctions "
            f"d'ailleurs ({names}…).\n"
            f"Déclarez une plage plus large dans config/units.txt, "
            f"puis relancez avec le nom voulu."
        )

    name = args.name or args.symbol.lower()
    source = SRC_DIR / f"{name}.cpp"
    if source.exists() and not args.force:
        raise SystemExit(f"{source.relative_to(ROOT)} existe déjà")

    # La borne haute est la fin de la dernière fonction, non le début de la
    # suivante. Le remplissage qui les sépare appartient au sous-segment
    # d'après : le compilateur ne le produit pas, et l'éditeur de liens ne le
    # comble que si la section suivante s'aligne assez large — celle du gros
    # bloc ne demande que quatre octets. L'inclure décale alors tout ce qui
    # suit d'un mot, et le symptôme est un `jal` dont la cible perd 4 octets.
    end = group.end

    for start, stop, existing in read_declared():
        if start < end and group.start < stop:
            raise SystemExit(f"la plage recouvre l'unité « {existing} » déjà déclarée")

    ordered = sorted(group.functions, key=lambda f: f.address)

    SRC_DIR.mkdir(exist_ok=True)
    body = TEMPLATE.format(
        title=f"{args.symbol} — à décrire.", count=len(ordered),
        octets=group.own_bytes, start=group.start, end=end,
    )
    body += "\n".join(
        f'INCLUDE_ASM("nonmatchings/{name}", {f.name});' for f in ordered
    ) + "\n"
    source.write_text(body, encoding="utf-8")

    units = CONFIG_DIR / "units.txt"
    line = (f"\n# {args.symbol} : {len(ordered)} fonctions, {group.own_bytes} octets.\n"
            f"0x{group.start:08X} 0x{end:08X} {name}\n")
    with units.open("a", encoding="utf-8") as handle:
        handle.write(line)

    print(f"unité « {name} » : {len(ordered)} fonctions, {group.own_bytes} octets,"
          f" 0x{group.start:08X} .. 0x{end:08X}")
    print(f"  déclarée dans {units.relative_to(ROOT)}")
    print(f"  source       {source.relative_to(ROOT)}")
    print(f"\nEnsuite : make setup && make build")
    return 0


if __name__ == "__main__":
    sys.exit(main())
