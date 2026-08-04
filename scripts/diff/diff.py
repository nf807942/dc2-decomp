#!/usr/bin/env python3
"""Compare une fonction reconstruite à celle du commerce.

    make diff S=Close__8CGamePadFv

Deux objets entrent : celui qu'assemble le désassemblage de référence, et
celui que compile la source. Le premier est le commerce, au bit près ; le
second est ce que le projet en a fait. objdiff les met côte à côte, appariés
instruction par instruction.
"""

from __future__ import annotations

import shutil
import subprocess
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from lib.project import ROOT, find_symbol, run  # noqa: E402


def build_objects(location) -> bool:
    """Construit les deux objets à comparer. Rend faux si la source manque."""
    targets = [str(location.target_object.relative_to(ROOT))]
    if location.base_object is not None:
        targets.append(str(location.base_object.relative_to(ROOT)))

    result = run(["make", *targets], stdout=subprocess.DEVNULL)
    if result.returncode != 0:
        raise SystemExit("la construction des objets a échoué")

    return location.base_object is not None and location.base_object.exists()


def main(argv: list[str]) -> int:
    if not argv:
        print("usage : diff.py <symbole> [options objdiff]", file=sys.stderr)
        return 2
    if shutil.which("objdiff-cli") is None:
        print("objdiff-cli introuvable — lancez la commande dans le conteneur",
              file=sys.stderr)
        return 1

    symbol, extra = argv[0], argv[1:]
    location = find_symbol(symbol)

    if not build_objects(location):
        # Sans source, la comparaison n'aurait qu'un côté. Le désassemblage
        # reste consultable, et c'est de lui que part la décompilation.
        print(f"{symbol} : aucune source ne le reconstruit encore.")
        print(f"  référence : {location.asm_file.relative_to(ROOT)}")
        print(f"  départ    : make decompile S={symbol}")
        return 0

    command = [
        "objdiff-cli", "diff",
        "-1", str(location.target_object),
        "-2", str(location.base_object),
        *extra, symbol,
    ]
    return run(command).returncode


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
