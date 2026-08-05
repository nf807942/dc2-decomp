#!/usr/bin/env python3
"""Installe le compilateur Metrowerks sous `tools/compilers/`.

    make tools

Les paquets viennent de `decompme/compilers`, le dépôt qui alimente
decomp.me : ils portent le gestionnaire de licence qui laisse `mwccps2.exe`
démarrer, ce que l'installateur d'origine ne fait pas. Rien de tout cela
n'entre dans git.

Quelle version a compilé le jeu reste à établir. `MW MIPS C Compiler
(2.4.1.01)` est écrit par l'éditeur de liens, non par le compilateur, et trois
versions au moins l'écrivent à l'identique ; d'où plusieurs candidates
installées côte à côte, et `make diff` pour trancher.
"""

from __future__ import annotations

import argparse
import io
import sys
import tarfile
import urllib.request
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
COMPILERS_DIR = ROOT / "tools" / "compilers"

BASE_URL = ("https://github.com/decompme/compilers/releases/download/compilers/"
            "{name}.tar.gz")

# Les candidates, dans l'ordre de vraisemblance. Le jeu est sorti en 2002 sur un
# compilateur que MWLD numérote 2.4.1.01, et les versions 2.4 comme 3.0.x
# portent ce numéro.
CANDIDATES = [
    "mwcps2-3.0.1-020123",
    "mwcps2-2.4-001213",
    "mwcps2-3.0-011126",
    "mwcps2-3.0.3-020716",
    "mwcps2-2.3.3-000906",
    "mwcps2-3.0b38-030307",
    "mwcps2-3.0b50-030527",
    "mwcps2-3.0b52-030722",
    "mwcps2-3.0.1b44-030325",
    "mwcps2-3.0.1b51-030512",
    "mwcps2-3.0.1b74-030811",
    "mwcps2-3.0.1b75-030916",
    "mwcps2-3.0.1b87-031208",
    "mwcps2-3.0.1b95-040309",
    "mwcps2-3.0.1b103-040528",
    "mwcps2-3.0.1b119-040914",
    "mwcps2-3.0.1b145-050209",
    "mwcps2-3.0.1b151-050317",
    "mwcps2-3.0.1b198-051011",
    "mwcps2-3.0.1b205-051227",
    "mwcps2-3.0.1b210-060308",
]


def fetch(name: str, destination: Path) -> None:
    url = BASE_URL.format(name=name)
    with urllib.request.urlopen(url) as response:
        payload = response.read()
    destination.mkdir(parents=True, exist_ok=True)
    with tarfile.open(fileobj=io.BytesIO(payload), mode="r:gz") as archive:
        # Les paquets rangent leur contenu sous un répertoire éponyme ; on le
        # retire pour que le chemin du compilateur ne le répète pas.
        for member in archive.getmembers():
            if not member.isfile():
                continue
            parts = Path(member.name).parts
            member.name = str(Path(*parts[1:])) if len(parts) > 1 else member.name
            # `data` refuse les chemins absolus et les liens qui sortiraient du
            # répertoire ; ces paquets ne contiennent que des fichiers ordinaires.
            archive.extract(member, destination, filter="data")
    for path in destination.iterdir():
        path.chmod(0o755)


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--all", action="store_true",
                        help="installe toutes les candidates, non la première")
    args = parser.parse_args()

    wanted = CANDIDATES if args.all else CANDIDATES[:1]
    for name in wanted:
        destination = COMPILERS_DIR / name
        if (destination / "mwccps2.exe").exists():
            print(f"{name} déjà installé")
            continue
        print(f"{name} …", end=" ", flush=True)
        try:
            fetch(name, destination)
        except Exception as error:  # réseau, archive, droits
            print(f"échec : {error}")
            continue
        print(f"→ {destination.relative_to(ROOT)}")

    default = COMPILERS_DIR / CANDIDATES[0] / "mwccps2.exe"
    if not default.exists():
        print("\nLe compilateur par défaut manque ; la partie C++ ne construira pas.",
              file=sys.stderr)
        return 1
    return 0


if __name__ == "__main__":
    sys.exit(main())
