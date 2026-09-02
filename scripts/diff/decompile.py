#!/usr/bin/env python3
"""Premier jet de C++ pour une fonction, depuis son désassemblage.

    make decompile S=Step__9CGamePadFv

Ce que m2c rend n'est pas une réponse mais un point de départ : la structure
de contrôle est juste, les types sont à établir. Le verdict vient ensuite de
`make diff`.

Le désassemblage de référence n'est pas donné tel quel à m2c. Deux
préparations sont nécessaires, et toutes deux se font dans une copie
temporaire : le fichier versionné ne bouge pas.
"""

from __future__ import annotations

import re
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from lib.project import ROOT, find_symbol, run  # noqa: E402

# L'Emotion Engine avec le compilateur Metrowerks, en C++ : m2c en tient
# compte jusque dans les conventions d'appel et le nom des registres.
TARGET = "mipsee-mwcc-c++"

M2C = ROOT / "tools" / "m2c" / "m2c.py"
REF_DATA = ROOT / "ref" / "asm" / "data"

# Le marqueur que le désassembleur pose devant chaque symbole non apparié.
# C'est une macro pour l'assembleur, mais m2c y voit une instruction hors
# fonction et s'arrête dessus.
NMLABEL = re.compile(r"^\s*nmlabel\b")

# Les préfixes sous lesquels m2c accepte de reconnaître une table de saut,
# faute de quoi il refuse la fonction (« Unable to determine jump table »).
JTBL_PREFIXES = ("jtbl", "jpt_", "lbl_", "jumptable_")


def strip_nmlabel(text: str) -> str:
    return "".join(line for line in text.splitlines(keepends=True)
                   if not NMLABEL.match(line))


def rodata_blocks() -> dict[str, str]:
    """Les blocs `dlabel`…`enddlabel` de la lecture seule, par nom."""
    blocks: dict[str, str] = {}
    for path in sorted(REF_DATA.rglob("*.rodata.s")):
        name, lines = None, []
        for line in path.read_text(encoding="utf-8").splitlines(keepends=True):
            head = line.split()
            if head and head[0] == "dlabel":
                name, lines = head[1], [line]
            elif head and head[0] == "enddlabel" and name:
                blocks[name] = "".join(lines + [line])
                name = None
            elif name:
                lines.append(line)
    return blocks


def jump_tables(text: str, blocks: dict[str, str]) -> dict[str, str]:
    """Les symboles que le texte charge et qui portent des étiquettes.

    Une table de saut se reconnaît à son contenu — des `.word` désignant des
    étiquettes — et non à son nom : celui que Metrowerks lui donne est un
    numéro (`_6424`), que rien ne distingue d'un littéral.
    """
    wanted = set(re.findall(r"%hi\((\w+)\)", text))
    return {name: block for name, block in blocks.items()
            if name in wanted and ".word .L" in block}


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

    text = strip_nmlabel(location.asm_file.read_text(encoding="utf-8"))
    tables = jump_tables(text, rodata_blocks())

    # m2c ne reconnaît une table qu'à son nom. Le renommage ne vit que dans la
    # copie qu'il reçoit ; `config/symbol_addrs.txt` reste l'endroit où l'on
    # corrige un nom pour de bon, et le binaire garde le sien.
    rodata = ""
    for name, block in tables.items():
        alias = name if name.startswith(JTBL_PREFIXES) else f"jtbl{name}"
        text = text.replace(name, alias)
        rodata += block.replace(name, alias)
        print(f"// table de saut {name} → {alias}", file=sys.stderr)

    work = ROOT / "build" / "decompile"
    work.mkdir(parents=True, exist_ok=True)
    text_file = work / f"{symbol}.s"
    text_file.write_text(text, encoding="utf-8")

    command = [sys.executable, str(M2C), "--target", TARGET, "-f", symbol]

    # Le contexte, quand il existe, donne à m2c les structures et prototypes
    # déjà reconstruits ; sans lui il invente des types plausibles.
    # `ctx.c` et non `.cpp` : m2c lit du C par pycparser, et
    # `scripts/build/contexte.py` engendre exactement cette vue-là.
    context = ROOT / "build" / "ctx.c"
    if context.exists():
        command += ["--context", str(context)]

    command += extra + [str(text_file)]
    if rodata:
        rodata_file = work / f"{symbol}.rodata.s"
        rodata_file.write_text(
            '.include "macro.inc"\n\n.section .rodata\n\n' + rodata,
            encoding="utf-8")
        command.append(str(rodata_file))

    return run(command).returncode


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
