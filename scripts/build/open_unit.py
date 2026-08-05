#!/usr/bin/env python3
"""Ouvre une unité de travail : la déclare, puis écrit sa source de départ.

    make open S=CRunScript              par la classe qu'elle porte
    make open S=0x0012C2C0-0x00131560 OPEN_ARGS="--name mgmath"

La source part entièrement en `INCLUDE_ASM`, dans l'ordre des adresses — celui
que l'éditeur de liens attend. La construction doit alors rendre les octets du
disque sans qu'une ligne de C++ soit écrite : c'est ce qui prouve que la plage
est bien découpée, et le point de départ contre lequel chaque fonction se
mesurera ensuite.

Ouvrir par plage sert le découpage exhaustif : une unité de traduction du
binaire porte plusieurs classes et les fonctions libres qui les accompagnent,
et aucune classe ne la nomme.

Reste à lancer `make setup` pour que le désassembleur écrive les fonctions de
la plage une par fichier, puis `make build`.
"""

from __future__ import annotations

import argparse
import re
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from lib.project import CONFIG_DIR, ROOT, SRC_DIR  # noqa: E402
from build.units import (class_of, group_by_class, intruders,  # noqa: E402
                         read_declared, read_functions, read_jump_tables)

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

_RANGE = re.compile(r"^(0[xX][0-9A-Fa-f]+)-(0[xX][0-9A-Fa-f]+)$")


def rodata_span(start: int, end: int) -> tuple[int, int] | None:
    """La plage de lecture seule que les fonctions de [start, end) réclament.

    Une table de saut désigne des étiquettes du corps qu'elle sert : séparées,
    l'objet compilé n'expose plus ces étiquettes et l'éditeur de liens s'arrête
    sur une faute de segmentation. La plage va donc de la première table à la
    dernière, et pas au-delà : un symbole qu'elle avalerait sans que le
    désassembleur le migre disparaîtrait du binaire.
    """
    held = [t for t in read_jump_tables()
            if any(start <= target < end for target in t.targets)]
    if not held:
        return None

    return min(t.address for t in held), max(t.end for t in held)


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("symbol", help="la classe dont ouvrir l'unité, "
                                       "ou une plage « 0xdébut-0xfin »")
    parser.add_argument("--name", help="nom du fichier source "
                                       "(défaut : la classe en minuscules)")
    parser.add_argument("--force", action="store_true",
                        help="réécrit la source même si elle existe")
    args = parser.parse_args()

    functions = read_functions()
    span = _RANGE.match(args.symbol)

    if span:
        start, end = int(span.group(1), 16), int(span.group(2), 16)
        if end <= start:
            raise SystemExit("la plage finit avant de commencer")
        held = [f for f in functions if start <= f.address < end]
        if not held:
            raise SystemExit(f"aucune fonction entre 0x{start:08X} et 0x{end:08X}")
        # Une plage commence et finit sur une frontière de fonction : couper au
        # milieu d'une d'entre elles laisserait des instructions sans étiquette
        # dans l'unité voisine.
        straddling = [f for f in functions if f.address < start < f.end
                      or f.address < end < f.end]
        if straddling:
            names = ", ".join(f.name for f in straddling[:3])
            raise SystemExit(f"la plage coupe {len(straddling)} fonctions "
                             f"en deux ({names}…)")
        # Le compilateur aligne sur seize octets la section de chaque fonction,
        # et l'éditeur de liens comble jusque-là. Une fonction que le binaire
        # place ailleurs se retrouve donc poussée, et tout ce qui suit avec
        # elle. Le code du jeu s'aligne ainsi de lui-même à 99 %.
        misaligned = [f for f in held if f.address % 16]
        if misaligned:
            names = ", ".join(f"0x{f.address:08X} {f.name}" for f in misaligned[:3])
            raise SystemExit(
                f"{len(misaligned)} fonctions de la plage ne commencent pas sur "
                f"un multiple de seize ({names}…).\n"
                f"L'objet compilé les décalerait ; bornez l'unité avant."
            )
        if not args.name:
            raise SystemExit("une plage demande --name")
        name, title = args.name, f"0x{start:08X} .. 0x{end:08X} — à décrire."
        octets = sum(f.size for f in held)
    else:
        group = group_by_class(functions).get(args.symbol)
        if group is None:
            raise SystemExit(f"{args.symbol} : aucune méthode ne porte cette classe")
        others = intruders(group, functions)
        if others:
            names = ", ".join(sorted({class_of(f.name) or "?" for f in others})[:4])
            raise SystemExit(
                f"{args.symbol} est entrecoupée par {len(others)} fonctions "
                f"d'ailleurs ({names}…).\n"
                f"Ouvrez plutôt la plage 0x{group.start:08X}-0x{group.end:08X}, "
                f"qui les emmène avec elle."
            )
        # La borne haute est la fin de la dernière fonction, non le début de la
        # suivante. Le remplissage qui les sépare est produit quand la dernière
        # fonction est greffée — l'assembleur aligne alors la fin de la
        # section — et absent quand elle est compilée. `make build` tranche, et
        # l'autre borne est le premier essai à faire.
        start, end = group.start, group.end
        held = list(group.functions)
        name = args.name or args.symbol.lower()
        title, octets = f"{args.symbol} — à décrire.", group.own_bytes

    source = SRC_DIR / f"{name}.cpp"
    if source.exists() and not args.force:
        raise SystemExit(f"{source.relative_to(ROOT)} existe déjà")

    for low, high, existing in read_declared():
        if low < end and start < high:
            raise SystemExit(f"la plage recouvre l'unité « {existing} » déjà déclarée")

    ordered = sorted(held, key=lambda f: f.address)

    SRC_DIR.mkdir(exist_ok=True)
    body = TEMPLATE.format(title=title, count=len(ordered), octets=octets,
                           start=start, end=end)
    body += "\n".join(
        f'INCLUDE_ASM("nonmatchings/{name}", {f.name});' for f in ordered
    ) + "\n"
    source.write_text(body, encoding="utf-8")

    rodata = rodata_span(start, end)
    declaration = f"0x{start:08X} 0x{end:08X} {name}"
    if rodata:
        declaration += f" rodata:0x{rodata[0]:08X}-0x{rodata[1]:08X}"

    units = CONFIG_DIR / "units.txt"
    with units.open("a", encoding="utf-8") as handle:
        handle.write(f"\n# {title.split(' — ')[0]} : {len(ordered)} fonctions,"
                     f" {octets} octets.\n{declaration}\n")

    print(f"unité « {name} » : {len(ordered)} fonctions, {octets} octets,"
          f" 0x{start:08X} .. 0x{end:08X}")
    if rodata:
        print(f"  tables de saut : 0x{rodata[0]:08X} .. 0x{rodata[1]:08X}"
              f" ({rodata[1] - rodata[0]} octets de lecture seule emmenés)")
    print(f"  déclarée dans {units.relative_to(ROOT)}")
    print(f"  source       {source.relative_to(ROOT)}")
    print(f"\nEnsuite : make setup && make build")
    return 0


if __name__ == "__main__":
    sys.exit(main())
