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

Deux choses la bornent encore.

Une frontière de contribution d'objet l'emporte sur une unité déclarée : le
désassembleur en fait un sous-segment et tronque sans un mot celle qui l'enjambe.
Le découpage y coupe donc.

Et une fonction qui saute par table emmène celle-ci, qui vit en lecture seule
mais désigne des étiquettes de son corps. La plage porte alors tout ce qui
s'intercale entre la première table et la dernière, et le désassembleur ne migre
d'un symbole que ce qu'une seule fonction atteint. Une plage n'est sûre que si
chacun des siens est dans ce cas, et que cette fonction est dans l'unité.

Ce qui ne l'est pas se resserre : redécoupée à une table par unité, la plage se
réduit à cette table et rien d'étranger ne s'y intercale plus. La taille visée
passe alors au second rang — c'est ce qui produit des unités d'une seule
fonction —, et le resserrement n'a lieu que là où la coupure large échoue.

L'alignement des fonctions, lui, ne borne plus : mwccgap le prend de l'adresse
que le désassemblage donne à chaque fonction greffée, là où MWCC demandait
seize octets pour toutes.
"""

from __future__ import annotations

import argparse
import re
import sys
from dataclasses import dataclass, field
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from lib.project import CONFIG_DIR, ROOT, SRC_DIR  # noqa: E402
from build.gen_objdiff import sectors_by_symbol  # noqa: E402
from build.units import (Function, class_of, read_contributions,  # noqa: E402
                         read_declared, read_functions, read_jump_tables,
                         rodata_is_contiguous, rodata_is_migrable)


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

        Le code de bibliothèque n'a pas de classe : ses contributions portent
        une poignée de fonctions libres, et c'est la plus lourde qui nomme
        l'unité. `sceGsResetPath` vaut mieux que son adresse.
        """
        ordered = self.classes
        if ordered:
            return ordered[0].lower()
        heaviest = max(self.functions, key=lambda f: (f.size, f.name))
        return file_name(heaviest.name) or f"text_{self.start:08X}"


# Ce qu'un nom de fichier accepte. Le mangling Metrowerks porte des chiffres de
# longueur, des chevrons et des `$` qu'aucun système de fichiers ne veut, et le
# nom sert ici de chemin autant que d'étiquette.
_UNSAFE = re.compile(r"[^a-z0-9_]+")


def file_name(symbol: str) -> str:
    """Un nom de fichier tiré d'un symbole, assaini et borné en longueur."""
    cleaned = _UNSAFE.sub("_", symbol.lower()).strip("_")
    return cleaned[:48]


def read_sectors() -> list[tuple[int, int]]:
    path = CONFIG_DIR / "sectors.txt"
    sectors = []
    for line in path.read_text(encoding="utf-8").splitlines():
        fields = line.split("#", 1)[0].split()
        if len(fields) == 2:
            sectors.append((int(fields[0], 16), int(fields[1], 16)))
    return sectors


def text_span(functions: list[Function]) -> tuple[int, int]:
    """De la première fonction de `.text` à la fin de la section.

    Le découpage couvre tout le texte, non les seules plages du jeu : une
    fonction hors unité ne peut pas s'écrire en C++, le remplacement fonction
    par fonction demandant un sous-segment `cpp` et un `INCLUDE_ASM`. Le code de
    bibliothèque n'y échappe donc pas, même livré compilé.

    La borne haute est le début de `.vutext`, non la dernière fonction du
    binaire : les 49 initialiseurs statiques `__sinit_*` sont des `FUNC` mais
    vivent après les données, en `0x00379680`. Les prendre pour du texte fait
    d'eux une unité dont le script de lien range le `.text` avec celui du jeu,
    et tout ce qui les sépare des données glisse — le symptôme est un
    débordement `%gp_rel`, les petites données s'étant éloignées de `_gp`.
    """
    return functions[0].address, read_contributions(".vutext")[0]


def sector_dirs() -> dict[str, str]:
    """Le dossier de `src/` où chaque secteur range ses unités.

    La provenance est ce qui décide du travail à faire : le SDK Sony a ses
    prototypes dans `ps2sdk`, le middleware ses signatures dans DCDecomp, le
    runtime Metrowerks ses sources dans l'installateur CodeWarrior, et le jeu
    n'a que le binaire. Les séparer dans l'arborescence rend cette différence
    lisible d'un coup d'œil.
    """
    return {"sdk": "sdk", "middleware": "mglib", "runtime": "runtime",
            "game": "game"}


def sector_of_unit(unit: Unit, sectors: dict[str, str]) -> str:
    """Le secteur d'une unité : celui qui pèse le plus d'octets.

    Une unité en mêle souvent deux — le middleware est dispersé dans les
    plages du jeu —, et le vote se fait sur les octets plutôt que sur le compte,
    une contribution pouvant porter un nom trompeur sur une fonction minuscule.
    """
    weight: dict[str, int] = {}
    for function in unit.functions:
        key = sectors.get(function.name, "game")
        weight[key] = weight.get(key, 0) + function.size
    return max(weight, key=lambda k: (weight[k], k)) if weight else "game"


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


def table_holders(functions: list[Function], tables) -> list[int]:
    """Les indices des fonctions qu'une table de saut sert, en ordre croissant.

    Une table désigne les étiquettes d'un seul corps ; c'est celui-ci qui la
    tient, et c'est lui qui l'emmène quand l'unité s'ouvre.
    """
    held = set()
    for table in tables:
        for index, function in enumerate(functions):
            if any(function.address <= target < function.end
                   for target in table.targets):
                held.add(index)
                break
    return sorted(held)


def carve(functions: list[Function], limit: int, target: int,
          tables=None) -> list[Unit]:
    """Découpe une suite de fonctions en unités d'environ `target` octets.

    La coupure se cherche dans une fenêtre autour de la taille visée, et va à
    la frontière qui laisse le moins de classes à cheval — à égalité, la plus
    proche de la cible.

    `tables` plafonne la coupure à la deuxième fonction porteuse de table, de
    sorte qu'une unité n'en tienne qu'une : sa plage de lecture seule se réduit
    alors à cette table, et rien d'étranger ne s'y intercale. C'est le repli de
    `main` quand la coupure large donne une plage que le désassembleur ne
    migrerait pas ; la taille visée passe alors au second rang.
    """
    spans = class_spans(functions)
    holders = table_holders(functions, tables) if tables is not None else []
    units: list[Unit] = []

    group, start = functions, 0
    while start < len(group):
        # Les bornes de la fenêtre, en nombre de fonctions : on avance jusqu'à
        # ce que la tranche pèse assez, puis on cherche jusqu'à ce qu'elle pèse
        # trop.
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

        remaining = [index for index in holders if index >= start]
        if len(remaining) > 1:
            # La deuxième porteuse ouvre l'unité suivante ; l'unité tient donc
            # une fonction au moins, fût-elle seule à peser sa taille.
            cut = max(min(cut, remaining[1]), start + 1)

        # Ce qui suit commence l'unité d'après ; à la fin, la borne est celle
        # que la plage donne.
        end = group[cut].address if cut < len(group) else limit
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


def split_at(low: int, high: int, cuts: list[int]) -> list[tuple[int, int]]:
    """Découpe une plage à chacune des adresses qui tombent dedans."""
    edges = [low, *(c for c in cuts if low < c < high), high]
    return list(zip(edges, edges[1:]))


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


def is_safe(unit: Unit, tables) -> bool:
    """Dit si l'unité peut s'ouvrir avec la plage de lecture seule qu'elle prend.

    Trois conditions, toutes vérifiées contre le désassemblage de référence : la
    plage n'a pas de trou qu'un alignement n'explique, chacun de ses symboles
    suivra une fonction de l'unité, et aucune de ses tables ne sert un corps
    resté dehors.
    """
    span = rodata_of(unit, tables)
    if span is not None and not (rodata_is_contiguous(*span)
                                 and rodata_is_migrable(*span, unit.functions)):
        return False
    return keeps_its_tables(unit, tables)


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

    contributions = read_contributions()

    units: list[Unit] = []
    for low, high in [text_span(functions)]:
        # Une unité déjà déclarée garde la main : le découpage la contourne, et
        # ce qui l'entoure se découpe de part et d'autre plutôt qu'à travers.
        for begin, stop in gaps(low, high, declared):
            # Une frontière de contribution d'objet l'emporte sur une unité
            # déclarée : le découpage y coupe plutôt que de se faire tronquer.
            for start, end in split_at(begin, stop, contributions):
                inside = [f for f in functions if start <= f.address < end]
                if not inside:
                    continue
                for unit in carve(inside, end, args.target):
                    # Une plage qui porte un symbole que le désassembleur ne
                    # migrerait pas se resserre : redécoupée à une table par
                    # unité, elle ne tient plus que celle-ci, et rien d'étranger
                    # ne peut s'y intercaler.
                    if is_safe(unit, tables):
                        units.append(unit)
                    else:
                        units.extend(carve(unit.functions, unit.end,
                                           args.target, tables))

    # Ce qui résiste au resserrement attend encore : une fonction qui porte
    # plusieurs tables les emmène toutes, et la plage reprend ce qu'elles
    # encadrent.
    tassed = [u for u in units if not is_safe(u, tables)]
    units = [u for u in units if u not in tassed]

    kept = units
    if args.limit:
        kept = sorted(kept, key=lambda u: -u.size)[:args.limit]
    kept.sort(key=lambda u: u.start)

    print(f"{len(kept)} unités à ouvrir, {sum(u.size for u in kept)} octets, "
          f"{sum(len(u.functions) for u in kept)} fonctions")
    print(f"{len(tassed)} unités attendent, faute d'une plage de lecture seule "
          f"sûre")

    overlap = clashing_rodata(kept, tables)
    if overlap:
        print(f"attention : {overlap} plages de lecture seule se recouvrent")

    # Chaque unité se range dans le dossier de son secteur, la provenance
    # décidant du travail à faire sur elle.
    symbol_sectors = sectors_by_symbol()
    dirs = sector_dirs()
    named = []
    for unit in kept:
        folder = dirs[sector_of_unit(unit, symbol_sectors)]
        name = f"{folder}/{unit.name}"
        # Deux unités peuvent porter la même classe dominante ; l'adresse les
        # départage, comme elle départage les symboles homonymes.
        if name in taken_names:
            name = f"{name}_{unit.start:08X}"
        taken_names.add(name)
        named.append((unit, name))

    if not args.apply:
        for unit, name in named[:30]:
            span = rodata_of(unit, tables)
            suffix = f" rodata:0x{span[0]:08X}-0x{span[1]:08X}" if span else ""
            print(f"0x{unit.start:08X} 0x{unit.end:08X} {name}{suffix}"
                  f"   # {len(unit.functions)} fonctions, {unit.size} octets")
        if len(named) > 30:
            print(f"… et {len(named) - 30} autres (--apply les déclare toutes)")
        return 0

    SRC_DIR.mkdir(exist_ok=True)
    lines: list[str] = []
    for unit, name in named:
        source = SRC_DIR / f"{name}.cpp"
        source.parent.mkdir(parents=True, exist_ok=True)
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
