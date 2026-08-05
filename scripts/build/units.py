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
from lib.project import CONFIG_DIR, REF_DIR  # noqa: E402

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


_SIZED = re.compile(r"^\S+\s*=\s*0x([0-9A-Fa-f]+);.*?size:0x([0-9A-Fa-f]+)",
                    re.MULTILINE)


def read_sized_symbols() -> list[tuple[int, int]]:
    """Les symboles que le binaire dimensionne : leur début et leur fin."""
    table = CONFIG_DIR / "elf_symbol_addrs.txt"
    if not table.exists():
        raise SystemExit("config/elf_symbol_addrs.txt absent — lancez `make setup`")
    return sorted((int(a, 16), int(a, 16) + int(s, 16))
                  for a, s in _SIZED.findall(table.read_text(encoding="utf-8")))


def rodata_is_contiguous(low: int, high: int) -> bool:
    """Dit si une plage de lecture seule peut voyager avec son unité.

    Le désassembleur migre vers la fonction chaque symbole de la plage, et
    mwccgap en fait une section de sa taille propre. Ce qui les séparait dans le
    binaire — le remplissage d'alignement — n'y est plus, et tout ce qui suit se
    tasse d'autant. Une plage dont les symboles se touchent ne perd rien ; le
    remplissage qui la termine, lui, revient de l'alignement du sous-segment
    voisin.
    """
    inside = [(start, end) for start, end in read_sized_symbols()
              if low <= start < high]
    if not inside or inside[0][0] != low:
        return False
    return all(end == start for (_a, end), (start, _b) in zip(inside, inside[1:]))


def rodata_holds_only(low: int, high: int, migrated: set[int]) -> bool:
    """Dit si la plage ne contient que des symboles que le découpage y met.

    Le désassembleur ne verse dans le sous-segment d'une unité que ce qu'il
    migre vers ses fonctions ; un symbole de la plage qu'il ne migre pas n'est
    plus écrit nulle part, et l'éditeur de liens s'arrête sur une faute de
    segmentation devant la référence qui lui reste.
    """
    return all(start in migrated for start, _end in read_sized_symbols()
               if low <= start < high)


def read_declared() -> list[tuple[int, int, str]]:
    """Les unités déjà déclarées : début, fin, nom.

    Une ligne porte trois champs, ou quatre quand une plage `rodata:` accompagne
    l'unité. Les compter à trois seulement rendait invisible toute unité à table
    de saut, que `make units` reproposait alors comme si elle était libre.
    """
    path = CONFIG_DIR / "units.txt"
    if not path.exists():
        return []
    declared = []
    for line in path.read_text(encoding="utf-8").splitlines():
        fields = line.split("#", 1)[0].split()
        if len(fields) >= 3:
            declared.append((int(fields[0], 16), int(fields[1], 16), fields[2]))
    return declared


@dataclass
class JumpTable:
    """Une table de saut : là où elle vit, et les étiquettes qu'elle désigne."""
    name: str
    address: int
    size: int
    targets: list[int]

    @property
    def end(self) -> int:
        return self.address + self.size


# Une table de saut se reconnaît à son contenu : des mots qui désignent des
# étiquettes de code, que le désassembleur écrit `.L<adresse>`. Rien d'autre en
# lecture seule n'a cette forme.
_DLABEL = re.compile(r"^dlabel\s+(\S+)\s*$")
_JUMP_WORD = re.compile(
    r"/\*\s*\w+\s+([0-9A-Fa-f]{8})\s+\w+\s*\*/\s*\.word\s+\.L([0-9A-Fa-f]{8})")


def read_jump_tables() -> list[JumpTable]:
    """Les tables de saut du binaire, lues dans le désassemblage de référence.

    Une fonction qui saute par table ne peut pas s'ouvrir sans elle : la table
    vit en lecture seule mais désigne des étiquettes du corps, et l'objet doit
    porter les deux. C'est ce que la plage `rodata:` de `config/units.txt`
    déclare, et c'est d'ici qu'on la déduit.
    """
    rodata = REF_DIR / "data" / "rodata"
    if not rodata.is_dir():
        raise SystemExit("ref/asm absent — lancez `make setup`")

    tables: list[JumpTable] = []
    for path in sorted(rodata.glob("*.s")):
        name: str | None = None
        entries: list[tuple[int, int]] = []
        for line in path.read_text(encoding="utf-8", errors="replace").splitlines():
            label = _DLABEL.match(line.strip())
            if label:
                name, entries = label.group(1), []
                continue
            if name is None:
                continue
            word = _JUMP_WORD.search(line)
            if word:
                entries.append((int(word.group(1), 16), int(word.group(2), 16)))
            elif line.strip().startswith("enddlabel"):
                # Une table n'a que des étiquettes : un bloc qui en mêle
                # d'autres mots est une donnée qui se trouve en contenir.
                if entries:
                    start = entries[0][0]
                    tables.append(JumpTable(name, start, entries[-1][0] + 4 - start,
                                            [t for _a, t in entries]))
                name, entries = None, []
    return tables


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
