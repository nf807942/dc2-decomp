#!/usr/bin/env python3
"""Engendre `objdiff.json` depuis le découpage.

Une unité par objet du binaire : sa cible est l'objet assemblé depuis le
désassemblage de référence — le commerce au bit près —, sa base l'objet
compilé depuis la source, quand une source existe. C'est ce fichier que lit
l'interface objdiff comme `objdiff-cli report`.

Chaque unité est rangée dans un secteur, déduit du préfixe de ses symboles.
Le budget de code du binaire s'y lit d'un coup d'œil, et l'avancement devient
lisible par provenance : reconstruire le middleware de Level-5 et reconstruire
le jeu ne sont pas le même travail.
"""

from __future__ import annotations

import json
import re
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from lib.project import CONFIG_DIR, REF_DIR, ROOT, symbol_sources  # noqa: E402

_GLABEL = re.compile(r"^\s*glabel\s+(\S+)\s*$", re.MULTILINE)
_FUNC = re.compile(
    r"^(\S+)\s*=\s*0x([0-9A-Fa-f]+);.*?type:func(?:.*?size:0x([0-9A-Fa-f]+))?",
    re.MULTILINE)

# Les secteurs, dans l'ordre où ils s'affichent. Le premier motif qui accepte
# un sujet décide, donc l'ordre compte : `mgCTextureManager` porte un `C` de
# classe comme celles du jeu, et doit être reconnu avant.
SECTORS: list[tuple[str, str, re.Pattern[str]]] = [
    ("sdk", "SDK Sony", re.compile(
        r"^(sce|Sce|sif|Sif|cdvd|Cdvd|mce|libmc|snd[A-Z])")),
    ("middleware", "Middleware Level-5", re.compile(r"^_?mg")),
    # La bibliothèque standard Metrowerks : les préfixes que le compilateur
    # réserve, et les fonctions C que le binaire porte sous leur nom entier.
    ("runtime", "Runtime Metrowerks", re.compile(
        r"^(__|_\$|std$|Vu_"
        r"|(mem|str|wcs|wmem)[a-z]+$"
        r"|(s|f|v|vf|sn)?(printf|scanf)$"
        r"|(m|c|re)?alloc$|free$|new$|delete$|operator"
        r"|abort$|assert$|exit$|atexit$|ato[fil]$|strto[dl]u?l?$"
        r"|qsort$|bsearch$|s?rand$|setjmp$|longjmp$"
        r"|l?div$|l?abs$|fabsf?$|sqrtf?$|powf?$|expf?$|log[2f]?$|f?modf?$"
        r"|sin$|cos$|tan$|a(sin|cos|tan2?)$|floor$|ceil$|frexp$|ldexp$|modf$"
        r"|to(upper|lower)$|is[a-z]+$"
        # L'émulation logicielle du flottant, qu'aucun préfixe ne désigne :
        # deux unités jumelles, `dp*` en double et `fp*` en simple précision.
        # Le vote de leur unité les rattraperait — les quatre noms en `__`
        # qu'elles portent suffisent à la faire pencher —, mais il ne tient
        # qu'au découpage : les nommer ici les en rend indépendantes.
        r"|_?fpadd_parts\w*$|(dp|fp)(add|sub|mul|div|cmp)$"
        r"|sitofp$|fpto(si|ui)$|litodp$|dpto(li|ul|fp)$)")),
    ("game", "Jeu", re.compile(r".")),
]

# Le mangling Metrowerks range la classe après la fonction, précédée de sa
# longueur : `Draw__9mgCFrameFv` est `mgCFrame::Draw`. Classer sur le début du
# symbole rangerait donc tout le middleware avec le jeu — c'est la classe qui
# dit la provenance.
_CLASS = re.compile(r"__(?:Q\d+)?(\d+)([A-Za-z_]\w*)")


def subject_of(symbol: str) -> str:
    """Ce dont le symbole relève : sa classe s'il en a une, sinon lui-même."""
    match = _CLASS.search(symbol)
    if match:
        length, rest = int(match.group(1)), match.group(2)
        name = rest[:length]
        if name:
            return name
    return symbol


def sector_of(symbol: str) -> str:
    """Le secteur que le seul nom désigne.

    Suffisant dans les unités du jeu, où le mangling porte la classe. Ailleurs
    c'est l'emplacement qui tranche, et `sectors_by_symbol` s'en charge.
    """
    subject = subject_of(symbol)
    for ident, _name, pattern in SECTORS:
        if pattern.match(subject):
            return ident
    return "game"


def function_sizes() -> dict[str, int]:
    """Taille de chaque fonction, telle que le binaire la déclare."""
    return {name: size for name, (_addr, size) in function_table().items()}


def function_table() -> dict[str, tuple[int, int]]:
    """Adresse et taille de chaque fonction, telles que le binaire les déclare."""
    table = CONFIG_DIR / "elf_symbol_addrs.txt"
    if not table.exists():
        raise SystemExit("config/elf_symbol_addrs.txt absent — lancez `make setup`")
    return {
        name: (int(addr, 16), int(size, 16) if size else 0)
        for name, addr, size in _FUNC.findall(table.read_text(encoding="utf-8"))
    }


def game_ranges() -> list[tuple[int, int]]:
    """Les plages où vit le code écrit pour le jeu, déclarées à la main."""
    path = CONFIG_DIR / "sectors.txt"
    if not path.exists():
        return []
    ranges = []
    for line in path.read_text(encoding="utf-8").splitlines():
        line = line.split("#", 1)[0].split()
        if len(line) == 2:
            ranges.append((int(line[0], 16), int(line[1], 16)))
    return ranges


def contributions() -> list[tuple[int, set[str]]]:
    """Les contributions d'objet, par adresse croissante.

    Un fichier du désassemblage de référence en est une : les symboles de
    section les bornent, à raison d'une par unité de traduction que l'éditeur
    de liens a reçue.
    """
    addresses = {name: addr for name, (addr, _s) in function_table().items()}
    found = []
    for asm in (REF_DIR / "text").rglob("*.s"):
        symbols = set(_GLABEL.findall(asm.read_text(encoding="utf-8", errors="replace")))
        here = [addresses[s] for s in symbols if s in addresses]
        if here:
            found.append((min(here), symbols))
    return sorted(found)


def sectors_by_symbol() -> dict[str, str]:
    """Le secteur de chaque fonction, l'emplacement primant sur le nom.

    Dans les unités du jeu, le nom décide : le middleware de Level-5 y est
    dispersé, et sa classe le désigne. Ailleurs le nom se tait — le code de
    bibliothèque de cette époque ne porte pas de préfixe d'éditeur —, mais la
    contribution le dit : elle est d'un seul tenant, livrée par une seule
    archive. Son secteur est celui que ses noms désignent, et celle qu'aucun ne
    désigne hérite de sa voisine, l'éditeur de liens rangeant côte à côte les
    membres d'une même archive.
    """
    addresses = {name: addr for name, (addr, _s) in function_table().items()}
    sizes = {name: size for name, (_a, size) in function_table().items()}
    ranges = game_ranges()

    def in_game(addr: int) -> bool:
        return any(low <= addr < high for low, high in ranges)

    table: dict[str, str] = {}
    library: list[tuple[int, set[str], str | None]] = []

    for start, symbols in contributions():
        if in_game(start) or not ranges:
            for symbol in symbols:
                table[symbol] = sector_of(symbol)
            continue
        # Le vote se fait sur les octets, non sur le compte : une contribution
        # peut porter un nom trompeur sur une fonction minuscule.
        votes: dict[str, int] = {}
        for symbol in symbols:
            named = sector_of(symbol)
            if named != "game":
                votes[named] = votes.get(named, 0) + sizes.get(symbol, 0)
        library.append((start, symbols, max(votes, key=votes.get) if votes else None))

    for i, (_start, symbols, decided) in enumerate(library):
        if decided is None:
            decided = next((s for _a, _y, s in reversed(library[:i]) if s), None)
            decided = decided or next((s for _a, _y, s in library[i + 1:] if s), None)
        for symbol in symbols:
            # Un nom qui se désigne lui-même l'emporte sur le voisinage.
            named = sector_of(symbol)
            table[symbol] = named if named != "game" else (decided or "game")

    for symbol in addresses:
        table.setdefault(symbol, sector_of(symbol))
    return table


def source_for(symbols: set[str]) -> Path | None:
    """La source qui reconstruit cette unité, si elle existe.

    Une source appartient à l'unité dont elle définit des symboles, ce que la
    table tirée des objets compilés établit — le texte d'une source ne porte pas
    les noms manglés que le binaire emploie.
    """
    table = symbol_sources()
    for symbol in sorted(symbols):
        found = table.get(symbol)
        if found is not None:
            return found
    return None


def main() -> int:
    if not REF_DIR.is_dir():
        raise SystemExit("ref/asm absent — lancez `make setup`")

    sizes = function_sizes()
    sectors = sectors_by_symbol()
    units = []
    totals: dict[str, int] = {}

    # La cible est le désassemblage de référence : il couvre tout le binaire,
    # y compris les unités qu'une source reconstruit déjà.
    for asm in sorted(REF_DIR.rglob("*.s")):
        relative = asm.relative_to(ROOT)
        symbols = set(_GLABEL.findall(asm.read_text(encoding="utf-8", errors="replace")))

        # Le secteur de l'unité est celui qui y porte le plus d'octets : c'est
        # une étiquette de navigation, et une unité de traduction mêle rarement
        # deux provenances. Le budget, lui, se compte par symbole — attribuer
        # l'unité entière à son secteur dominant efface toute provenance qui
        # n'est jamais majoritaire, et le middleware l'est rarement.
        weight: dict[str, int] = {}
        for symbol in symbols:
            sector = sectors.get(symbol) or sector_of(symbol)
            octets = sizes.get(symbol, 0)
            weight[sector] = weight.get(sector, 0) + octets
            totals[sector] = totals.get(sector, 0) + octets
        sector = max(weight, key=lambda k: weight[k]) if weight else "game"

        source = source_for(symbols)

        unit: dict[str, object] = {
            "name": str(relative.with_suffix("")).replace("\\", "/"),
            "target_path": str(BUILD_PREFIX / relative.with_suffix(".o")).replace("\\", "/"),
            "metadata": {
                "progress_categories": [sector],
                # Une unité sans source n'est pas commencée ; une unité qui en
                # a une n'est complète que si la construction entière reste
                # identique au disque, ce que `make build` tranche seul.
                "complete": False,
            },
        }
        if source is not None:
            unit["base_path"] = str(
                BUILD_PREFIX / source.relative_to(ROOT).with_suffix(".o")
            ).replace("\\", "/")
            unit["metadata"]["source_path"] = str(source.relative_to(ROOT)).replace("\\", "/")

        units.append(unit)

    config = {
        "$schema": "https://raw.githubusercontent.com/encounter/objdiff/main/config.schema.json",
        "min_version": "2.0.0",
        "custom_make": "make",
        # objdiff reconstruit ce qu'il compare : la cible vient du
        # désassemblage, la base de la source.
        "build_target": True,
        "build_base": True,
        "watch_patterns": ["*.c", "*.cpp", "*.h", "*.hpp", "*.s", "*.inc"],
        "ignore_patterns": ["build/**/*", "asm/**/*"],
        "progress_categories": [
            {"id": ident, "name": name} for ident, name, _ in SECTORS
        ],
        "units": units,
        "options": {
            # Le mangling du binaire est celui de Metrowerks ; le deviner
            # marche presque toujours, le nommer marche toujours.
            "demangler": "codewarrior",
        },
    }

    output = ROOT / "objdiff.json"
    output.write_text(json.dumps(config, indent=2) + "\n", encoding="utf-8")

    print(f"{len(units)} unités dans objdiff.json")
    for ident, name, _ in SECTORS:
        octets = totals.get(ident, 0)
        share = 100 * octets / sum(totals.values()) if totals else 0
        print(f"  {name:22s} {octets:9d} octets  {share:5.1f} %")
    return 0


BUILD_PREFIX = Path("build")

if __name__ == "__main__":
    sys.exit(main())
