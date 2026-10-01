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


def alignment_of(address: int) -> int:
    """L'alignement que l'adresse d'un symbole de lecture seule impose.

    Seize est le plafond : MWCC ne demande pas davantage pour une section de
    lecture seule, et c'est ce que mwccgap reporte depuis l'adresse.
    """
    for align in (16, 8, 4):
        if address % align == 0:
            return align
    return 4


def rodata_is_contiguous(low: int, high: int) -> bool:
    """Dit si une plage de lecture seule peut voyager avec son unité.

    Le désassembleur migre vers la fonction chaque symbole de la plage, et
    mwccgap en fait une section à part. Ce qui les sépare dans le binaire n'y
    revient donc que de l'alignement des sections, et une plage n'est sûre que
    si chaque trou vaut exactement le remplissage que l'adresse du symbole
    suivant réclame. Un trou plus large est autre chose — une donnée que le
    désassembleur ne nomme pas —, et il serait perdu.

    Le remplissage qui *termine* la plage, lui, revient de l'alignement du
    sous-segment voisin.

    Cette condition ne dit rien de ce que la plage porte : c'est
    `rodata_is_migrable` qui tranche si chaque symbole suivra bien une fonction.

    Une plage qui ne porte qu'un symbole n'a pas de trou à expliquer, et c'est
    le seul cas où elle se juge sur ce que le désassembleur nomme plutôt que sur
    ce que le binaire dimensionne : les tables de saut du code de bibliothèque
    n'ont pas de symbole dans le binaire — splat les nomme lui-même `jtbl_…` —,
    donc aucune taille ne les borne.
    """
    named = rodata_symbols(low, high)
    if len(named) == 1 and named[0].address == low:
        return True

    inside = [(start, end) for start, end in read_sized_symbols()
              if low <= start < high]
    if not inside or inside[0][0] != low:
        return False
    return all(padded(end, alignment_of(start)) == start
               for (_a, end), (start, _b) in zip(inside, inside[1:]))


def padded(offset: int, align: int) -> int:
    """L'adresse que l'alignement atteint depuis celle-ci."""
    return offset + (-offset % align)


# Une référence à un symbole de lecture seule, telle que le désassembleur
# l'écrit : `%hi(_2109)`, `%lo(_2109)`, ou le mot d'une table.
_REFERENCE = re.compile(r"%(?:hi|lo|gp_rel)\(([A-Za-z_@$][\w@$]*)\)")
_GLABEL_LINE = re.compile(r"^\s*glabel\s+(\S+)")

_REFERENCED: dict[str, set[str]] | None = None


def read_references() -> dict[str, set[str]]:
    """Quelles fonctions atteignent chaque symbole, lu dans la référence.

    C'est ce qui décide si une plage `rodata:` peut voyager avec une unité : le
    désassembleur ne verse dans son sous-segment que ce qu'il migre vers ses
    fonctions, et un symbole de la plage qu'il ne migre pas n'est plus écrit
    nulle part. L'éditeur de liens s'arrête alors sur une faute de segmentation,
    précédée de débordements `%gp_rel` — le contenu manquant ayant rapproché les
    petites données de `_gp`, dont le plus proche symbole n'est déjà qu'à seize
    octets de la limite des ±32 Kio.
    """
    global _REFERENCED
    if _REFERENCED is not None:
        return _REFERENCED

    table: dict[str, set[str]] = {}
    # Récursif : une unité rangée dans le dossier de son secteur donne au
    # désassemblage de référence un sous-dossier de même nom, et une lecture
    # plate n'y verrait plus aucune de ses fonctions.
    for path in sorted((REF_DIR / "text").rglob("*.s")):
        function = ""
        for line in path.read_text(encoding="utf-8", errors="replace").splitlines():
            label = _GLABEL_LINE.match(line)
            if label:
                function = label.group(1).rstrip(",")
                continue
            for name in _REFERENCE.findall(line):
                table.setdefault(name, set()).add(function)

    _REFERENCED = table
    return table


def rodata_is_migrable(low: int, high: int, functions: list[Function]) -> bool:
    """Dit si chaque symbole de la plage suivra une fonction de l'unité.

    La règle est celle de spimdisasm, `SymbolRodata.shouldMigrate`, à trois
    termes : le symbole doit être d'une forme migrable, une seule fonction doit
    l'atteindre, et cette fonction doit être dans l'unité. Un symbole que rien
    n'atteint n'est emporté que s'il se trouve entre deux qui le sont, ce qui
    dépend de l'ordre — on ne s'y fie pas.
    """
    inside = {f.name for f in functions}
    referenced = read_references()
    return all(symbol.migrable
               and referenced.get(symbol.name, set()) <= inside
               and len(referenced.get(symbol.name, set())) == 1
               for symbol in rodata_symbols(low, high))


@dataclass
class RodataSymbol:
    """Un symbole de lecture seule, et s'il peut suivre une fonction."""
    address: int
    name: str
    migrable: bool


_RODATA_LABEL = re.compile(r"^\s*(?:dlabel|glabel)\s+(\S+)")
# `/* <offset> <vram> [<octets>] */ .word .L…` — la ligne d'un octet de donnée.
# Les octets manquent sous une chaîne, que le désassembleur rend en clair.
_RODATA_DATA = re.compile(
    r"^\s*/\*\s+\S+\s+([0-9A-Fa-f]{8})(?:\s+\S+)?\s+\*/\s*\.(\w+)\s*(.*)$")

_RODATA: list[RodataSymbol] | None = None


def is_migrable(kind: str, operands: list[str]) -> bool:
    """Dit si le désassembleur emporte ce symbole avec la fonction qui l'atteint.

    `MWCCPS2` porte `allowRdataMigration = False` chez spimdisasm : ce qui passe
    pour une constante ne bouge pas. Ne restent donc migrables qu'une chaîne, une
    table de saut — trois étiquettes au moins — et un flottant dont la queue est
    nulle, ce que `SymbolRodata.isMaybeConstVariable` écarte.

    Une table peut finir sur des mots nuls sans cesser d'en être une :
    `isJumpTable` répond du type que le `jr` a donné au symbole, non de son
    contenu. Six tables du code de bibliothèque sont dans ce cas.
    """
    if kind in ("asciz", "ascii"):
        return True
    if kind == "word":
        labels = [o for o in operands if o.startswith(".L")]
        tail = operands[len(labels):]
        return (len(labels) >= 3
                and operands[:len(labels)] == labels
                and all(o in ("0x00000000", "0") for o in tail))
    if kind in ("float", "double"):
        head = 1 if kind == "float" else 2
        return all(o in ("0", "0.0", "-0") for o in operands[head:])
    return False


def read_rodata() -> list[RodataSymbol]:
    """Les symboles de lecture seule du binaire, lus dans la référence."""
    global _RODATA
    if _RODATA is not None:
        return _RODATA

    found: list[RodataSymbol] = []
    for path in sorted((REF_DIR / "data" / "rodata").glob("*.s")):
        name: str | None = None
        address = 0
        kind = ""
        operands: list[str] = []

        def close() -> None:
            if name is not None:
                found.append(RodataSymbol(address, name,
                                          is_migrable(kind, operands)))

        for line in path.read_text(encoding="utf-8", errors="replace").splitlines():
            label = _RODATA_LABEL.match(line)
            if label:
                close()
                name, kind, operands = label.group(1).rstrip(","), "", []
                continue
            # Le remplissage qui suit une fin de symbole n'en fait pas partie :
            # l'y laisser fait passer une table de saut pour une donnée mêlée.
            if name is not None and line.strip().startswith("enddlabel"):
                close()
                name = None
                continue
            data = _RODATA_DATA.match(line)
            if name is not None and data:
                if not kind:
                    kind, address = data.group(2), int(data.group(1), 16)
                operands.append(data.group(3).strip())
        close()

    _RODATA = sorted(found, key=lambda s: s.address)
    return _RODATA


def rodata_symbols(low: int, high: int) -> list[RodataSymbol]:
    """Les symboles de lecture seule d'une plage."""
    return [s for s in read_rodata() if low <= s.address < high]


def read_contributions(section: str = ".text") -> list[int]:
    """Les adresses où commence chaque contribution d'objet de la section.

    Le désassembleur en fait un sous-segment chacune, et il l'emporte sur une
    unité déclarée : celle qui enjambe une frontière se voit tronquée là, sans
    un mot, et les fonctions qu'elle perd ne sont écrites nulle part — sa source
    réclame alors un `INCLUDE_ASM` dont le fichier n'existe pas. Les deux gros
    blocs du jeu n'en portent aucune à l'intérieur ; le code de bibliothèque en
    porte une par fonction.
    """
    path = CONFIG_DIR / "elf_sections.txt"
    if not path.exists():
        raise SystemExit("config/elf_sections.txt absent — lancez `make setup`")
    return sorted(int(fields[1], 16)
                  for fields in (line.split() for line
                                 in path.read_text(encoding="utf-8").splitlines())
                  if len(fields) == 2 and fields[0] == section)


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
# Le mot nul dont certaines tables sont suivies, à l'intérieur du même symbole.
_NULL_WORD = re.compile(
    r"/\*\s*\w+\s+([0-9A-Fa-f]{8})\s+\w+\s*\*/\s*\.word\s+(?:0x0+|0)\s*$")


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
        last = 0
        for line in path.read_text(encoding="utf-8", errors="replace").splitlines():
            label = _DLABEL.match(line.strip())
            if label:
                name, entries, last = label.group(1), [], 0
                continue
            if name is None:
                continue
            word = _JUMP_WORD.search(line)
            null = _NULL_WORD.search(line)
            if word:
                entries.append((int(word.group(1), 16), int(word.group(2), 16)))
                last = entries[-1][0]
            elif null and entries:
                # La table s'arrête où son symbole s'arrête, non à sa dernière
                # étiquette : six d'entre elles finissent sur un mot nul, et
                # borner avant lui couperait le symbole que la plage doit porter
                # entier.
                last = int(null.group(1), 16)
            elif line.strip().startswith("enddlabel"):
                # Une table n'a que des étiquettes, éventuellement suivies de
                # mots nuls : un bloc qui en mêle d'autres est une donnée qui se
                # trouve en contenir.
                if entries:
                    start = entries[0][0]
                    tables.append(JumpTable(name, start, last + 4 - start,
                                            [t for _a, t in entries]))
                name, entries, last = None, [], 0
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
