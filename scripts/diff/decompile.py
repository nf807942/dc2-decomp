#!/usr/bin/env python3
"""Premier jet de C++ pour une fonction, depuis son désassemblage.

    make decompile S=Step__9CGamePadFv

Ce que m2c rend n'est pas une réponse mais un point de départ : la structure
de contrôle est juste, les types sont à établir. Le verdict vient ensuite de
`make diff`.
"""

from __future__ import annotations

import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from lib.project import ROOT, find_symbol, run  # noqa: E402

# L'Emotion Engine avec le compilateur Metrowerks, en C++ : m2c en tient
# compte jusque dans les conventions d'appel et le nom des registres.
TARGET = "mipsee-mwcc-c++"

M2C = ROOT / "tools" / "m2c" / "m2c.py"


def main(argv: list[str]) -> int:
    if not argv:
        print("usage : decompile.py <symbole> [options m2c]", file=sys.stderr)
        return 2
    if not M2C.exists():
        print("tools/m2c absent — `git submodule update --init`", file=sys.stderr)
        return 1

    symbol, extra = argv[0], argv[1:]
    location = find_symbol(symbol)
    print(f"// {location.asm_file.relative_to(ROOT)}", file=sys.stderr)

    command = [sys.executable, str(M2C), "--target", TARGET, "-f", symbol]

    # Le contexte, quand il existe, donne à m2c les structures et prototypes
    # déjà reconstruits ; sans lui il invente des types plausibles.
    context = ROOT / "build" / "ctx.cpp"
    if context.exists():
        command += ["--context", str(context)]

    command += extra + [str(location.asm_file)]
    return run(command).returncode


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
