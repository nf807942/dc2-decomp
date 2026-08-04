#!/usr/bin/env python3
"""Compare une fonction reconstruite à celle du commerce.

    make diff S=Close__8CGamePadFv

Deux objets entrent : celui qu'assemble le désassemblage de référence, et
celui que compile la source. Le premier est le commerce, au bit près ; le
second est ce que le projet en a fait. objdiff les apparie instruction par
instruction, et ce script rend son verdict lisible au terminal.
"""

from __future__ import annotations

import json
import shutil
import subprocess
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from lib.project import ROOT, find_symbol, run  # noqa: E402

# Ce qu'objdiff dit d'une ligne, et le signe qui le porte au terminal.
MARK = {
    "DIFF_NONE": " ",
    "DIFF_OP_MISMATCH": "~",     # même place, autre instruction
    "DIFF_ARG_MISMATCH": "≠",    # même instruction, autre opérande
    "DIFF_REPLACE": "≠",
    "DIFF_DELETE": "-",          # le commerce l'a, nous pas
    "DIFF_INSERT": "+",          # nous l'avons, le commerce pas
}

RESET, DIM, RED, GREEN, YELLOW = "\033[0m", "\033[2m", "\033[31m", "\033[32m", "\033[33m"

COLOUR = {
    "DIFF_NONE": "", "DIFF_OP_MISMATCH": RED, "DIFF_ARG_MISMATCH": YELLOW,
    "DIFF_REPLACE": RED, "DIFF_DELETE": RED, "DIFF_INSERT": GREEN,
}


def build_objects(location) -> bool:
    """Construit les deux objets à comparer. Rend faux si la source manque."""
    targets = [str(location.target_object.relative_to(ROOT))]
    if location.base_object is not None:
        targets.append(str(location.base_object.relative_to(ROOT)))

    result = run(["make", *targets], stdout=subprocess.DEVNULL)
    if result.returncode != 0:
        raise SystemExit("la construction des objets a échoué")

    return location.base_object is not None and location.base_object.exists()


def render(payload: dict, symbol: str, colour: bool) -> int:
    """Affiche le diff côte à côte. Rend le nombre de lignes qui divergent."""
    def find(side: str) -> dict | None:
        for entry in payload.get(side, {}).get("symbols", []):
            if entry.get("name") == symbol:
                return entry
        return None

    base = find("right")
    if base is None:
        print(f"{symbol} : objdiff ne l'a pas trouvé dans l'objet compilé.")
        return 1

    rows = base.get("instructions", [])
    target = find("left")
    target_rows = target.get("instructions", []) if target else []

    share = base.get("match_percent", 0.0)
    name = base.get("demangled_name") or symbol
    print(f"{name}   {share:.2f} % apparié   {base.get('size', '?')} octets\n")

    def text(row: dict) -> str:
        return row.get("instruction", {}).get("formatted", "")

    def kind_of(row: dict) -> str:
        return row.get("diff_kind", "DIFF_NONE")

    # Les deux suites n'avancent pas du même pas : ce que le commerce a en
    # propre est marqué `DELETE` chez lui, ce que nous avons en trop est
    # `INSERT` chez nous. Les apparier par indice décalerait tout après le
    # premier écart de longueur, et montrerait des divergences imaginaires.
    divergent = 0
    width = 42
    left_index = right_index = 0
    print(f"  {'commerce':<{width}}   {'reconstruit':<{width}}")
    print(f"  {'-' * width}   {'-' * width}")

    while left_index < len(target_rows) or right_index < len(rows):
        left_row = target_rows[left_index] if left_index < len(target_rows) else None
        right_row = rows[right_index] if right_index < len(rows) else None

        if left_row is not None and kind_of(left_row) == "DIFF_DELETE":
            kind, left, right = "DIFF_DELETE", text(left_row), ""
            left_index += 1
        elif right_row is not None and kind_of(right_row) == "DIFF_INSERT":
            kind, left, right = "DIFF_INSERT", "", text(right_row)
            right_index += 1
        else:
            kind = kind_of(right_row) if right_row is not None else kind_of(left_row)
            left = text(left_row) if left_row is not None else ""
            right = text(right_row) if right_row is not None else ""
            left_index += 1
            right_index += 1

        if kind != "DIFF_NONE":
            divergent += 1
        tint = COLOUR.get(kind, "") if colour else ""
        end = RESET if tint else ""
        print(f"{MARK.get(kind, '?')} {tint}{left:<{width}}   {right:<{width}}{end}")

    print()
    if divergent == 0:
        print(f"identique — {len(rows)} instructions")
    else:
        print(f"{divergent} instructions sur {len(rows)} divergent")
    return divergent


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

    print(f"référence {location.asm_file.relative_to(ROOT)}"
          f"   source {location.source_file.relative_to(ROOT)}\n")

    # Le mode interactif d'objdiff demande un terminal ; le mode « un coup »
    # rend le même appariement en JSON, que ce script met en forme.
    command = [
        "objdiff-cli", "diff",
        "-1", str(location.target_object),
        "-2", str(location.base_object),
        "-o", "-", "--format", "json",
        *extra, symbol,
    ]
    result = run(command, capture_output=True, text=True)
    if result.returncode != 0:
        sys.stderr.write(result.stderr)
        return result.returncode

    render(json.loads(result.stdout), symbol, colour=sys.stdout.isatty())
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
