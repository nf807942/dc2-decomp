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
    names: set[str] = set()
    for path in sources():
        names |= set(_INCLUDE_ASM.findall(
            path.read_text(encoding="utf-8", errors="replace")))
    return names


_SYMBOL_SOURCES: dict[str, Path] | None = None


def symbol_sources(build: bool = True) -> dict[str, Path]:
    """La source qui définit chaque symbole de texte, par son nom manglé.

    La question se tranche sur les objets compilés, non sur le texte des
    sources : une source écrit `CGamePad::Close` et le binaire porte
    `Close__8CGamePadFv`. Seul le compilateur connaît la correspondance, et le
    mangling Metrowerks ne se devine pas assez sûrement pour s'en passer.

    La table est calculée une fois : l'établir par symbole relirait chaque objet
    autant de fois qu'il y a de fonctions.
    """
    global _SYMBOL_SOURCES
    if _SYMBOL_SOURCES is not None:
        return _SYMBOL_SOURCES

    table: dict[str, Path] = {}
    for path in sources():
        obj = BUILD_DIR / path.relative_to(ROOT).with_suffix(".o")
        # `make` décide seul si l'objet est périmé : se contenter de le
        # construire quand il manque laisserait lire l'objet d'avant la
        # dernière fonction écrite, qui ne la porte donc pas.
        if build:
            run(["make", str(obj.relative_to(ROOT))],
                stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
        if not obj.exists():
            continue
        listing = run(["mips-ps2-decompals-nm", "--defined-only", str(obj)],
                      capture_output=True, text=True)
        if listing.returncode != 0:
            continue
        for line in listing.stdout.splitlines():
            parts = line.split()
            # « adresse type nom » ; `t`/`T` désigne le texte.
            if len(parts) == 3 and parts[1] in "tT":
                table.setdefault(parts[2], path)

    _SYMBOL_SOURCES = table
    return table


def source_defining(symbol: str, build: bool = True) -> Path | None:
    """La source qui définit ce symbole, s'il en existe une."""
    return symbol_sources(build).get(symbol)


def find_symbol(symbol: str) -> Location:
    """Trouve le désassemblage de référence qui définit un symbole.

    La recherche passe par le contenu plutôt que par la table : un fichier
    porte le nom de son adresse de départ, et c'est l'étiquette qui dit ce
    qu'il contient. Elle porte sur `ref/asm`, le désassemblage complet : c'est
    le seul qui garde une fonction déjà reconstruite.
    """
    if not REF_DIR.is_dir():
        raise SystemExit("ref/asm absent — lancez `make setup`")

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
