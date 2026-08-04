#!/usr/bin/env python3
"""Propose des unités de travail, et dit ce que celles déjà ouvertes contiennent.

    make units                 les plages candidates, les plus grosses d'abord
    make units S=mgCFrame      ce qu'une classe couvre, et si elle est contiguë

Les frontières des 49 unités de traduction ne sont pas dans le binaire. Mais
une classe et ses méthodes se suivent le plus souvent, et le démanglage les
nomme : 150 des 230 classes du gros bloc occupent une plage qu'aucune autre
n'entrecoupe. C'est de là que sortent les lignes de `config/units.txt`.

Une classe entrecoupée n'interdit rien : elle demande seulement de choisir une
plage plus large, ou d'accepter plusieurs classes dans la même unité — ce que
le binaire fait de son côté, une unité de traduction en portant plusieurs.
"""

from __future__ import annotations

import argparse
import re
import sys
from dataclasses import dataclass, field
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from lib.project import CONFIG_DIR  # noqa: E402

_FUNC = re.compile(
    r"^(\S+)\s*=\s*0x([0-9A-Fa-f]+);.*?type:func(?:.*?size:0x([0-9A-Fa-f]+))?",
    re.MULTILINE)

# Le mangling Metrowerks range la classe après le nom de la fonction, précédée
# de sa longueur : `Draw__8mgCFrameFv` est `mgCFrame::Draw`.
_CLASS = re.compile(r"__(?:Q\d+)?(\d+)([A-Za-z_]\w*)")


@dataclass
class Function:
    name: str
    address: int
    size: int

    @property
    def end(self) -> int:
        return self.address + self.size


@dataclass
class Group:
    """Les fonctions d'une même classe, et ce qui s'intercale entre elles."""
    name: str
    functions: list[Function] = field(default_factory=list)

    @property
    def start(self) -> int:
        return min(f.address for f in self.functions)

    @property
    def end(self) -> int:
        return max(f.end for f in self.functions)

    @property
    def own_bytes(self) -> int:
        return sum(f.size for f in self.functions)


def class_of(symbol: str) -> str | None:
    match = _CLASS.search(symbol)
    if not match:
        return None
    name = match.group(2)[:int(match.group(1))]
    return name or None


def read_functions() -> list[Function]:
    table = CONFIG_DIR / "elf_symbol_addrs.txt"
    if not table.exists():
        raise SystemExit("config/elf_symbol_addrs.txt absent — lancez `make setup`")
    rows = [
        Function(name, int(addr, 16), int(size, 16) if size else 0)
        for name, addr, size in _FUNC.findall(table.read_text(encoding="utf-8"))
    ]
    return sorted(rows, key=lambda f: f.address)


def read_declared() -> list[tuple[int, int, str]]:
    path = CONFIG_DIR / "units.txt"
    if not path.exists():
        return []
    declared = []
    for line in path.read_text(encoding="utf-8").splitlines():
        line = line.split("#", 1)[0].strip()
        if line and len(line.split()) == 3:
            start, end, name = line.split()
            declared.append((int(start, 16), int(end, 16), name))
    return declared


def group_by_class(functions: list[Function]) -> dict[str, Group]:
    groups: dict[str, Group] = {}
    for function in functions:
        name = class_of(function.name)
        if name is None:
            continue
        groups.setdefault(name, Group(name)).functions.append(function)
    return groups


def intruders(group: Group, functions: list[Function]) -> list[Function]:
    """Les fonctions d'ailleurs qui tombent dans la plage de cette classe."""
    return [
        f for f in functions
        if group.start <= f.address < group.end and class_of(f.name) != group.name
    ]


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("symbol", nargs="?", help="une classe à détailler")
    parser.add_argument("--limit", type=int, default=25)
    parser.add_argument("--all", action="store_true",
                        help="inclut les classes entrecoupées")
    args = parser.parse_args()

    functions = read_functions()
    groups = group_by_class(functions)
    declared = read_declared()
    taken = {name for _s, _e, name in declared}

    def is_declared(group: Group) -> str | None:
        for start, end, name in declared:
            if start <= group.start and group.end <= end:
                return name
        return None

    if args.symbol:
        group = groups.get(args.symbol)
        if group is None:
            raise SystemExit(f"{args.symbol} : aucune méthode ne porte cette classe")
        others = intruders(group, functions)
        print(f"{group.name} : {len(group.functions)} méthodes, "
              f"{group.own_bytes} octets")
        print(f"  plage 0x{group.start:08X} .. 0x{group.end:08X}")
        print(f"  entrecoupée par {len(others)} fonctions d'ailleurs")
        held = is_declared(group)
        if held:
            print(f"  déjà dans l'unité « {held} »")
        print()
        for function in sorted(group.functions, key=lambda f: f.address):
            print(f"  0x{function.address:08X} {function.size:6d}  {function.name}")
        if others:
            print(f"\n  intrus, les dix premiers :")
            for function in others[:10]:
                print(f"  0x{function.address:08X} {function.size:6d}  {function.name}"
                      f"   [{class_of(function.name)}]")
        return 0

    # Une plage se propose quand rien d'étranger ne la traverse : la déclarer
    # suffit alors, sans arbitrage.
    clean, mixed = [], []
    for group in groups.values():
        if is_declared(group) or group.name in taken:
            continue
        (clean if not intruders(group, functions) else mixed).append(group)

    clean.sort(key=lambda g: -g.own_bytes)
    mixed.sort(key=lambda g: -g.own_bytes)

    print(f"{len(clean)} classes occupent une plage que rien n'entrecoupe."
          f" À déclarer dans config/units.txt :\n")
    for group in clean[:args.limit]:
        print(f"0x{group.start:08X} 0x{group.end:08X} {group.name.lower()}"
              f"   # {len(group.functions)} méthodes, {group.own_bytes} octets")

    if args.all and mixed:
        print(f"\n{len(mixed)} classes sont entrecoupées — la plage y couvrira"
              f" plusieurs classes :\n")
        for group in mixed[:args.limit]:
            print(f"  {group.name:28s} {len(group.functions):4d} méthodes,"
                  f" {group.own_bytes:7d} octets,"
                  f" {len(intruders(group, functions)):5d} intrus")
    elif mixed:
        print(f"\n{len(mixed)} autres classes sont entrecoupées (--all les liste).")

    if declared:
        print(f"\ndéjà ouvertes : {', '.join(n for _s, _e, n in declared)}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
