#!/usr/bin/env python3
"""Ce que les outils du projet ont en commun : trouver un symbole, son
désassemblage et l'objet qui le porte."""

from __future__ import annotations

import re
import subprocess
import sys
from dataclasses import dataclass
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
ASM_DIR = ROOT / "asm"
# Le désassemblage de référence, complet : une unité passée en C++ n'est plus
# extraite sous `asm/`, et c'est ici que la fonction reconstruite garde
# l'original contre lequel on la mesure.
REF_DIR = ROOT / "ref" / "asm"
SRC_DIR = ROOT / "src"
INCLUDE_DIR = ROOT / "include"
BUILD_DIR = ROOT / "build"
CONFIG_DIR = ROOT / "config"

_GLABEL = re.compile(r"^\s*(?:glabel|jlabel|dlabel)\s+(\S+)\s*$", re.MULTILINE)


@dataclass
class Location:
    """Où une fonction se trouve : son fichier de référence et son objet."""
    symbol: str
    asm_file: Path
    source_file: Path | None

    @property
    def target_object(self) -> Path:
        """L'objet assemblé depuis le désassemblage — la référence."""
        return BUILD_DIR / self.asm_file.relative_to(ROOT).with_suffix(".o")

    @property
    def base_object(self) -> Path | None:
        """L'objet compilé depuis la source, quand une source existe."""
        if self.source_file is None:
            return None
        return BUILD_DIR / self.source_file.relative_to(ROOT).with_suffix(".o")


def sources() -> list[Path]:
    """Les unités de traduction du projet, celles qu'on écrit."""
    if not SRC_DIR.is_dir():
        return []
    return sorted(list(SRC_DIR.rglob("*.cpp")) + list(SRC_DIR.rglob("*.c")))


# `INCLUDE_ASM("nonmatchings/<unite>", <symbole>);`
_INCLUDE_ASM = re.compile(r'INCLUDE_ASM\s*\(\s*"[^"]*"\s*,\s*(\S+?)\s*\)')


def grafted_symbols() -> set[str]:
    """Les fonctions qu'une source laisse en assembleur.

    mwccgap greffe leurs octets d'origine dans l'objet compilé : elles y sont
    identiques à la référence, et tout ce qui compare les deux les donnerait
    pour appariées. Ouvrir une unité afficherait alors ses fonctions comme
    reconstruites sans qu'une ligne de C++ soit écrite.
    """
    return {name for names in grafted_by_source().values() for name in names}


def grafted_by_source() -> dict[Path, set[str]]:
    """Les fonctions greffées, rangées sous la source qui les laisse.

    La provenance d'une fonction est celle de son unité, non celle que son nom
    suggère : `src/sdk/` porte des symboles que rien dans leur nom ne distingue
    de ceux du jeu.
    """
    table: dict[Path, set[str]] = {}
    for path in sources():
        table[path] = set(_INCLUDE_ASM.findall(
            path.read_text(encoding="utf-8", errors="replace")))
    return table


@dataclass
class Function:
    """Une fonction du binaire : le nom qu'il porte, son adresse, sa taille."""
    name: str
    address: int
    size: int


# `<nom> = 0x<adresse>; // type:func size:0x<taille>` — la taille manque pour
# les quelques symboles que l'ELF ne dimensionne pas.
_FUNC = re.compile(
    r"^(\S+)\s*=\s*0x([0-9A-Fa-f]+);.*?type:func(?:.*?size:0x([0-9A-Fa-f]+))?",
    re.MULTILINE)

_FUNCTIONS: dict[str, Function] | None = None


def functions() -> dict[str, Function]:
    """Toutes les fonctions du binaire, par leur nom manglé.

    La table vient de l'ELF non strippé, que `make setup` écrit : c'est elle
    qui dit ce qui reste à faire, et elle ne dépend d'aucune construction.
    """
    global _FUNCTIONS
    if _FUNCTIONS is not None:
        return _FUNCTIONS

    table = require(CONFIG_DIR / "elf_symbol_addrs.txt", "lancez `make setup`")
    _FUNCTIONS = {
        name: Function(name, int(addr, 16), int(size, 16) if size else 0)
        for name, addr, size in _FUNC.findall(table.read_text(encoding="utf-8"))
    }
    return _FUNCTIONS


# Une ligne d'instruction : le commentaire d'adresse, puis le mnémonique. Les
# espaces se bornent à la ligne — `\s` franchirait le saut qui sépare l'en-tête
# du désassemblage, et rendrait le premier `nmlabel` pour une instruction.
_INSTRUCTION = re.compile(r"^[ \t]*/\*[^*]*\*/[ \t]+(\S+)", re.MULTILINE)
_PADDING: set[str] | None = None


def padding_symbols() -> set[str]:
    """Les « fonctions » que le désassembleur invente sur du remplissage.

    Quand la dernière fonction d'une unité est écrite en C++, MWCC ne produit
    plus l'alignement que l'assembleur posait derrière elle : il reste au
    désassemblage, sans que rien le borne, et spimdisasm en fait un
    `func_XXXXXXXX` de quatre octets qui ne porte qu'un `nop`.

    Ce n'est pas du code du jeu, et le compter en donnerait une part à
    reconstruire qui n'existe pas — c'est au contraire la trace d'une unité
    achevée. Six unités sont dans ce cas, vingt-quatre octets en tout.
    """
    global _PADDING
    if _PADDING is not None:
        return _PADDING

    found: set[str] = set()
    for path in (REF_DIR / "text").rglob("*.s"):
        text = path.read_text(encoding="utf-8", errors="replace")
        names = _GLABEL.findall(text)
        if len(names) != 1:
            continue
        opcodes = _INSTRUCTION.findall(text)
        if opcodes and all(op == "nop" for op in opcodes):
            found.update(names)

    _PADDING = found
    return found


_SYMBOL_SOURCES: dict[str, Path] | None = None


def symbol_sources(build: bool = True) -> dict[str, Path]:
    """La source qui définit chaque symbole de texte, par son nom manglé.

    La question se tranche sur les objets compilés, non sur le texte des
    sources : une source écrit `CGamePad::Close` et le binaire porte
    `Close__8CGamePadFv`. Seul le compilateur connaît la correspondance, et le
    mangling Metrowerks ne se devine pas assez sûrement pour s'en passer.

    La table est calculée une fois : l'établir par symbole relirait chaque objet
    autant de fois qu'il y a de fonctions.

    Les deux commandes portent sur tous les objets d'un coup. Les appeler par
    source coûtait 0,74 s de `make` chacune — le seul démarrage, l'objet étant
    à jour —, soit près de quatre minutes sur les 319 unités, et c'est ce que
    payait chaque `make diff`.
    """
    global _SYMBOL_SOURCES
    if _SYMBOL_SOURCES is not None:
        return _SYMBOL_SOURCES

    objects = {
        BUILD_DIR / path.relative_to(ROOT).with_suffix(".o"): path
        for path in sources()
    }

    # `make` décide seul si un objet est périmé : se contenter de le construire
    # quand il manque laisserait lire l'objet d'avant la dernière fonction
    # écrite, qui ne la porte donc pas.
    if build and objects:
        run(["make", *(str(o.relative_to(ROOT)) for o in objects)],
            stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)

    present = [obj for obj in objects if obj.exists()]
    table: dict[str, Path] = {}
    if not present:
        _SYMBOL_SOURCES = table
        return table

    listing = run(["mips-ps2-decompals-nm", "--defined-only",
                   *(str(o) for o in present)], capture_output=True, text=True)

    # Sur plusieurs fichiers, `nm` annonce chacun par une ligne « chemin: »
    # avant ses symboles ; c'est elle qui dit à quelle source rattacher ce qui
    # suit. Sur un seul, il n'annonce rien — d'où la valeur de départ.
    current: Path | None = objects[present[0]] if len(present) == 1 else None
    for line in listing.stdout.splitlines():
        if line.endswith(":") and " " not in line:
            current = objects.get(ROOT / line[:-1])
            continue
        parts = line.split()
        # « adresse type nom » ; `t`/`T` désigne le texte.
        if current is not None and len(parts) == 3 and parts[1] in "tT":
            table.setdefault(parts[2], current)

    _SYMBOL_SOURCES = table
    return table


def source_defining(symbol: str, build: bool = True) -> Path | None:
    """La source qui définit ce symbole, s'il en existe une."""
    return symbol_sources(build).get(symbol)


def declared_units() -> list[tuple[int, int, str]]:
    """Les unités que `config/units.txt` déclare : début, fin, nom.

    Une ligne porte trois champs, ou quatre quand une plage `rodata:`
    accompagne l'unité.
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


def unit_of(symbol: str) -> str | None:
    """L'unité qui couvre ce symbole, par son adresse.

    Le découpage dit tout : `config/units.txt` confie une plage à
    `src/<nom>.cpp`, et le désassemblage de référence de cette même unité vit
    en `ref/asm/text/<nom>.s`. Chercher plutôt que déduire coûtait sept
    secondes par essai — 1,8 s à relire les 414 fichiers de `ref/asm`, et cinq
    à passer `make` puis `nm` sur les 319 objets pour retrouver qui définit
    quoi. Rien de tout cela n'est nécessaire : l'adresse le dit.
    """
    fonction = functions().get(symbol)
    if fonction is None:
        return None
    for low, high, name in declared_units():
        if low <= fonction.address < high:
            return name
    return None


def find_symbol(symbol: str) -> Location:
    """Trouve le désassemblage de référence qui définit un symbole.

    La référence est `ref/asm`, le désassemblage complet : c'est le seul qui
    garde une fonction déjà reconstruite.

    Une fonction hors de toute unité déclarée n'a pas de source ; le balayage
    du contenu reste alors le seul recours, et il ne coûte que là.
    """
    if not REF_DIR.is_dir():
        raise SystemExit("ref/asm absent — lancez `make setup`")

    name = unit_of(symbol)
    if name is not None:
        asm_file = REF_DIR / "text" / f"{name}.s"
        if asm_file.exists():
            # Une source qui greffe encore le symbole ne le reconstruit pas :
            # la comparer au commerce rendrait 100 % sans qu'une ligne de C++
            # soit écrite.
            source = SRC_DIR / f"{name}.cpp"
            if not source.exists():
                source = SRC_DIR / f"{name}.c"
            grafted = grafted_by_source().get(source, set())
            return Location(symbol, asm_file,
                            source if source.exists() and symbol not in grafted
                            else None)

    matches = [
        path for path in sorted(REF_DIR.rglob("*.s"))
        if symbol in _GLABEL.findall(path.read_text(encoding="utf-8", errors="replace"))
    ]

    if not matches:
        raise SystemExit(f"{symbol} : aucun désassemblage ne le définit")
    if len(matches) > 1:
        names = ", ".join(str(p.relative_to(ROOT)) for p in matches)
        raise SystemExit(f"{symbol} défini dans plusieurs fichiers : {names}")

    return Location(symbol, matches[0], source_defining(symbol))


def run(command: list[str], **kwargs) -> subprocess.CompletedProcess:
    """Lance une commande depuis la racine du projet."""
    return subprocess.run(command, cwd=ROOT, **kwargs)


def require(path: Path, hint: str) -> Path:
    if not path.exists():
        print(f"{path.relative_to(ROOT) if path.is_relative_to(ROOT) else path}"
              f" absent — {hint}", file=sys.stderr)
        raise SystemExit(1)
    return path
