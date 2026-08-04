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


def find_symbol(symbol: str) -> Location:
    """Trouve le fichier de désassemblage qui définit un symbole.

    La recherche passe par le contenu plutôt que par la table : un fichier
    porte le nom de son adresse de départ, et c'est l'étiquette qui dit ce
    qu'il contient.
    """
    if not ASM_DIR.is_dir():
        raise SystemExit("asm/ absent — lancez `make setup`")

    matches = [
        path for path in sorted(ASM_DIR.rglob("*.s"))
        if symbol in _GLABEL.findall(path.read_text(encoding="utf-8", errors="replace"))
    ]

    if not matches:
        raise SystemExit(f"{symbol} : aucun désassemblage ne le définit")
    if len(matches) > 1:
        names = ", ".join(str(p.relative_to(ROOT)) for p in matches)
        raise SystemExit(f"{symbol} défini dans plusieurs fichiers : {names}")

    asm_file = matches[0]

    # Une source porte le nom de l'unité de traduction qu'elle reconstruit ;
    # tant qu'aucune ne couvre cette fonction, seul le désassemblage existe.
    source = None
    for candidate in (SRC_DIR.rglob("*.cpp"), SRC_DIR.rglob("*.c")):
        for path in candidate:
            if symbol in path.read_text(encoding="utf-8", errors="replace"):
                source = path
                break
        if source:
            break

    return Location(symbol, asm_file, source)


def run(command: list[str], **kwargs) -> subprocess.CompletedProcess:
    """Lance une commande depuis la racine du projet."""
    return subprocess.run(command, cwd=ROOT, **kwargs)


def require(path: Path, hint: str) -> Path:
    if not path.exists():
        print(f"{path.relative_to(ROOT) if path.is_relative_to(ROOT) else path}"
              f" absent — {hint}", file=sys.stderr)
        raise SystemExit(1)
    return path
