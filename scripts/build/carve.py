#!/usr/bin/env python3
"""Découpe le code du jeu en unités, de bout en bout.

    make carve                 les plages proposées, et ce qui reste dehors
    make carve CARVE_ARGS=--apply   les déclare et écrit leurs sources

Les frontières des 49 unités de traduction d'origine ne sont pas dans le
binaire : deux contributions d'objet y portent 91 % du code. Elles se décident
donc, et ce script les décide de la seule chose que le binaire montre — les
classes que le mangling nomme.

Les réunir toutes dès qu'elles s'entrecoupent ne donne rien : sur les 5 002
fonctions du premier secteur, cela ne fait que trois composantes dont une de
1,4 Mo. Les classes s'entrelacent trop pour qu'un point de coupure propre
existe. Le découpage vise donc une taille, et choisit dans une fenêtre autour
d'elle la frontière qui laisse le moins de classes à cheval — ce qui range les
petites classes d'un seul tenant sans prétendre reconstituer les grandes.

Deux choses la bornent :

  * une unité commence sur un multiple de seize, et aucune de ses fonctions n'y
    manque. Le compilateur aligne ainsi la section de chaque fonction, et
    l'éditeur de liens comble jusque-là : une fonction que le binaire place
    ailleurs serait poussée, avec tout ce qui la suit. Le code du jeu s'y
    conforme à 99 %, et les rares fonctions qui n'y sont pas restent dehors, en
    assembleur, entre deux unités ;

  * une fonction qui saute par table emmène celle-ci, qui vit en lecture seule
    mais désigne des étiquettes de son corps.
"""

from __future__ import annotations

import argparse
import sys
from dataclasses import dataclass, field
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from lib.project import CONFIG_DIR, ROOT, SRC_DIR  # noqa: E402
from build.units import (Function, class_of, read_declared,  # noqa: E402
                         read_functions, read_jump_tables,
                         rodata_is_contiguous)

# Le compilateur aligne la section de chaque fonction sur seize octets.
ALIGN = 16


@dataclass
class Unit:
    """Une tranche continue du secteur, telle qu'elle sera déclarée."""
    functions: list[Function] = field(default_factory=list)
    # La borne haute est le début de la fonction suivante, non la fin de la
    # dernière : tant que celle-ci est greffée, son désassemblage porte le
    # remplissage qui l'en sépare, et l'exclure décalerait tout d'un mot.
    end: int = 0

    @property
    def start(self) -> int:
        return self.functions[0].address

    @property
    def size(self) -> int:
        return sum(f.size for f in self.functions)

    @property
    def weights(self) -> dict[str, int]:
        weight: dict[str, int] = {}
        for function in self.functions:
            owner = class_of(function.name)
            if owner:
                weight[owner] = weight.get(owner, 0) + function.size
        return weight

    @property
    def classes(self) -> list[str]:
        """Les classes de l'unité, la plus lourde d'abord."""
        weight = self.weights
        return sorted(weight, key=lambda k: -weight[k])

    @property
    def name(self) -> str:
        """Le nom du fichier source : la classe la plus grosse, ou l'adresse.

        Une unité en porte souvent plusieurs — c'est ce que le binaire fait de
        son côté —, et rien ne dit laquelle l'a nommée. Celle qui pèse le plus
        est le choix le moins arbitraire ; les autres restent en commentaire.
        """
        ordered = self.classes
        return ordered[0].lower() if ordered else f"text_{self.start:08X}"


def read_sectors() -> list[tuple[int, int]]:
    path = CONFIG_DIR / "sectors.txt"
    sectors = []
    for line in path.read_text(encoding="utf-8").splitlines():
        fields = line.split("#", 1)[0].split()
        if len(fields) == 2:
            sectors.append((int(fields[0], 16), int(fields[1], 16)))
    return sectors


def class_spans(functions: list[Function]) -> dict[str, tuple[int, int]]:
    """La plage que chaque classe occupe, de sa première à sa dernière méthode."""
    spans: dict[str, tuple[int, int]] = {}
    for function in functions:
        owner = class_of(function.name)
        if owner is None:
            continue
        low, high = spans.get(owner, (function.address, function.end))
        spans[owner] = (min(low, function.address), max(high, function.end))
    return spans


def straddled(spans: dict[str, tuple[int, int]], cut: int) -> int:
    """Combien de classes une coupure à cette adresse laisserait à cheval."""
    return sum(1 for low, high in spans.values() if low < cut < high)


def runs(functions: list[Function],
         limit: int) -> list[tuple[list[Function], int]]:
    """Les suites de fonctions que seize octets alignent toutes, et leur borne.

    Celles qui n'y sont pas restent en assembleur, entre deux unités : le
    compilateur alignerait leur section, et tout ce qui suit se décalerait. La
    borne d'une suite est donc l'adresse de la fonction écartée qui la ferme.
    """
    groups: list[tuple[list[Function], int]] = []
    run: list[Function] = []
    for function in functions:
        if function.address % ALIGN:
            if run:
                groups.append((run, function.address))
            run = []
            continue
        run.append(function)
    if run:
        groups.append((run, limit))
    return groups


def carve(functions: list[Function], limit: int, target: int) -> list[Unit]:
    """Découpe une suite de fonctions en unités d'environ `target` octets.

    La coupure se cherche dans une fenêtre autour de la taille visée, et va à
    la frontière qui laisse le moins de classes à cheval — à égalité, la plus
    proche de la cible.
    """
    spans = class_spans(functions)
    units: list[Unit] = []

    for group, group_end in runs(functions, limit):
        start = 0
        while start < len(group):
            # Les bornes de la fenêtre, en nombre de fonctions : on avance
            # jusqu'à ce que la tranche pèse assez, puis on cherche jusqu'à ce
            # qu'elle pèse trop.
            taken, low_index, high_index = 0, None, len(group)
            for index in range(start, len(group)):
                taken += group[index].size
                if low_index is None and taken >= target * 0.6:
                    low_index = index + 1
                if taken >= target * 1.4:
                    high_index = index + 1
                    break
            if low_index is None or high_index >= len(group):
                cut = len(group)
            else:
                candidates = range(low_index, high_index + 1)
                cut = min(candidates,
                          key=lambda i: (straddled(spans, group[i].address),
                                         abs(sum(f.size for f in group[start:i])
                                             - target)))

            # Ce qui suit dans le même groupe commence l'unité d'après ; à la
            # fin du groupe, la borne est la fonction écartée qui le ferme.
            end = group[cut].address if cut < len(group) else group_end
            units.append(Unit(group[start:cut], end))
            start = cut

    # La borne d'une unité est le début de la suivante quand les deux se
    # touchent : le remplissage qui les sépare appartient au désassemblage de
    # la dernière fonction greffée.
    for unit, following in zip(units, units[1:]):
        if unit.end > following.start:
            unit.end = following.start
    return units


def rodata_of(unit: Unit, tables) -> tuple[int, int] | None:
    held = [t for t in tables
            if any(unit.start <= target < unit.end for target in t.targets)]

    if not held:
        return None
    # La plage s'arrête exactement où la dernière table finit. L'étendre au
    # symbole suivant l'y ferait entrer sans que le désassembleur l'y migre, et
    # il disparaîtrait ; le remplissage qui suit revient de lui-même au voisin,
    # dont le contenu ne demande pas plus de quatre octets d'alignement.
    return min(t.address for t in held), max(t.end for t in held)


def gaps(low: int, high: int,
         declared: list[tuple[int, int, str]]) -> list[tuple[int, int]]:
    """Ce qui reste d'un secteur une fois les unités déclarées retirées."""
    free = []
    cursor = low
    for start, end, _name in sorted(declared):
        if end <= low or start >= high:
            continue
        if start > cursor:
            free.append((cursor, start))
        cursor = max(cursor, end)
    if cursor < high:
        free.append((cursor, high))
    return free


def keeps_its_tables(unit: Unit, tables) -> bool:
    """Dit si toutes les tables de la plage servent des fonctions de l'unité.

    Une table prise dans la plage mais qui désigne le corps d'une fonction
    restée dehors emmène des étiquettes que plus aucun objet ne définit, et
    l'éditeur de liens s'arrête sur une faute de segmentation.
    """
    span = rodata_of(unit, tables)
    if span is None:
        return True
    return all(all(unit.start <= target < unit.end for target in table.targets)
               for table in tables if span[0] <= table.address < span[1])


def tables_follow_text(unit: Unit, tables) -> bool:
    """Dit si les tables de l'unité suivent l'ordre des fonctions qu'elles servent.

    Chacune est migrée dans le désassemblage de sa fonction, et mwccgap les
    concatène dans l'ordre des fonctions. Deux tables que le binaire range à
    l'inverse de leurs corps se retrouvent donc échangées, et chaque saut mène
    ailleurs.
    """
    span = rodata_of(unit, tables)
    if span is None:
        return True
    held = sorted((t for t in tables if span[0] <= t.address < span[1]),
                  key=lambda t: t.address)
    targets = [min(t.targets) for t in held]
    return targets == sorted(targets)


def clashing_rodata(units: list[Unit], tables) -> int:
    """Les plages de lecture seule que deux unités se disputeraient.

    Deux unités ne peuvent pas réclamer la même : le découpage n'en ferait
    qu'un sous-segment, et l'une des deux perdrait sa table.
    """
    spans = sorted(filter(None, (rodata_of(u, tables) for u in units)))
    return sum(1 for a, b in zip(spans, spans[1:]) if b[0] < a[1])


TEMPLATE = """\
/* {classes}
 *
 * Unité découpée par `make carve` : {count} fonctions, {octets} octets, de
 * 0x{start:08X} à 0x{end:08X}. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

"""


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--apply", action="store_true",
                        help="déclare les unités et écrit leurs sources")
    parser.add_argument("--target", type=int, default=24576,
                        help="taille visée d'une unité, en octets")
    parser.add_argument("--limit", type=int,
                        help="ne traite que les N plus grosses unités")
    args = parser.parse_args()

    functions = read_functions()
    tables = read_jump_tables()
    declared = read_declared()
    taken_names = {name for _s, _e, name in declared}

    units: list[Unit] = []
    outside = 0
    for low, high in read_sectors():
        # Une unité déjà déclarée garde la main : le découpage la contourne, et
        # ce qui l'entoure se découpe de part et d'autre plutôt qu'à travers.
        for begin, stop in gaps(low, high, declared):
            inside = [f for f in functions if begin <= f.address < stop]
            if not inside:
                continue
            outside += sum(1 for f in inside if f.address % ALIGN)
            units.extend(carve(inside, stop, args.target))

    # Une unité dont la plage de lecture seule perdrait son remplissage
    # intérieur attend : elle demande une coupure que ce découpage ne sait pas
    # encore choisir, et la déclarer décalerait tout ce qui la suit.
    tassed = [u for u in units
              if ((span := rodata_of(u, tables))
                  and not rodata_is_contiguous(*span))
              or not keeps_its_tables(u, tables)
              or not tables_follow_text(u, tables)]
    units = [u for u in units if u not in tassed]

    kept = units
    if args.limit:
        kept = sorted(kept, key=lambda u: -u.size)[:args.limit]
    kept.sort(key=lambda u: u.start)

    print(f"{len(kept)} unités à ouvrir, {sum(u.size for u in kept)} octets, "
          f"{sum(len(u.functions) for u in kept)} fonctions")
    print(f"{outside} fonctions restent dehors faute d'un début aligné, "
          f"{len(tassed)} unités faute d'une plage de lecture seule d'un tenant")

    overlap = clashing_rodata(kept, tables)
    if overlap:
        print(f"attention : {overlap} plages de lecture seule se recouvrent")

    if not args.apply:
        for unit in kept[:30]:
            span = rodata_of(unit, tables)
            suffix = f" rodata:0x{span[0]:08X}-0x{span[1]:08X}" if span else ""
            print(f"0x{unit.start:08X} 0x{unit.end:08X} {unit.name}{suffix}"
                  f"   # {len(unit.functions)} fonctions, {unit.size} octets")
        if len(kept) > 30:
            print(f"… et {len(kept) - 30} autres (--apply les déclare toutes)")
        return 0

    SRC_DIR.mkdir(exist_ok=True)
    lines: list[str] = []
    for unit in kept:
        name = unit.name
        # Deux unités peuvent porter la même classe dominante ; l'adresse les
        # départage, comme elle départage les symboles homonymes.
        if name in taken_names:
            name = f"{name}_{unit.start:08X}"
        taken_names.add(name)

        source = SRC_DIR / f"{name}.cpp"
        body = TEMPLATE.format(
            classes=", ".join(unit.classes) or "Fonctions libres — à décrire.",
            count=len(unit.functions), octets=unit.size,
            start=unit.start, end=unit.end,
        )
        body += "\n".join(
            f'INCLUDE_ASM("nonmatchings/{name}", {f.name});'
            for f in unit.functions
        ) + "\n"
        source.write_text(body, encoding="utf-8")

        span = rodata_of(unit, tables)
        suffix = f" rodata:0x{span[0]:08X}-0x{span[1]:08X}" if span else ""
        lines.append(f"\n# {', '.join(unit.classes) or 'fonctions libres'} :"
                     f" {len(unit.functions)} fonctions, {unit.size} octets.\n"
                     f"0x{unit.start:08X} 0x{unit.end:08X} {name}{suffix}")

    with (CONFIG_DIR / "units.txt").open("a", encoding="utf-8") as handle:
        handle.write("\n".join(lines) + "\n")

    print(f"déclarées dans config/units.txt, sources sous "
          f"{SRC_DIR.relative_to(ROOT)}/")
    print("\nEnsuite : make setup && make build")
    return 0


if __name__ == "__main__":
    sys.exit(main())
