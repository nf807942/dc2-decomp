#!/usr/bin/env python3
"""Part du binaire qui vient de source compilée plutôt que de désassemblage.

La mesure porte sur les octets de code, non sur le nombre de fonctions : une
fonction de dix instructions et une de mille ne pèsent pas pareil. Le compte
sert aussi de rapport à decomp.dev, qui en fait une courbe.
"""

from __future__ import annotations

import json
import re
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from lib.project import ASM_DIR, CONFIG_DIR, ROOT, SRC_DIR  # noqa: E402

_SYMBOL = re.compile(r"^(\S+)\s*=\s*0x([0-9A-Fa-f]+);.*?type:func(?:.*?size:0x([0-9A-Fa-f]+))?",
                     re.MULTILINE)


def decompiled_symbols() -> set[str]:
    """Les symboles qu'une source du projet définit.

    Une fonction compte pour reconstruite dès qu'une source la nomme :
    l'exactitude, elle, est le verdict de `make build`, qui compare tout le
    binaire.
    """
    names: set[str] = set()
    if not SRC_DIR.is_dir():
        return names
    for path in list(SRC_DIR.rglob("*.cpp")) + list(SRC_DIR.rglob("*.c")):
        text = path.read_text(encoding="utf-8", errors="replace")
        names.update(re.findall(r"\b([A-Za-z_]\w*__\w+)\s*\(", text))
    return names


def main() -> int:
    table = CONFIG_DIR / "elf_symbol_addrs.txt"
    if not table.exists():
        print("config/elf_symbol_addrs.txt absent — lancez `make setup`",
              file=sys.stderr)
        return 1

    functions = [
        (name, int(addr, 16), int(size, 16) if size else 0)
        for name, addr, size in _SYMBOL.findall(table.read_text(encoding="utf-8"))
    ]
    done = decompiled_symbols()

    total_bytes = sum(size for _, _, size in functions)
    done_bytes = sum(size for name, _, size in functions if name in done)
    total_count = len(functions)
    done_count = sum(1 for name, _, _ in functions if name in done)

    share = 100 * done_bytes / total_bytes if total_bytes else 0.0
    print(f"code reconstruit : {done_bytes} octets sur {total_bytes} ({share:.3f} %)")
    print(f"fonctions        : {done_count} sur {total_count}")

    # Le format que decomp.dev consomme.
    report = {
        "measures": {
            "code": done_bytes, "code/total": total_bytes,
            "code/percent": share,
            "functions": done_count, "functions/total": total_count,
        }
    }
    out = ROOT / "progress" / "report.json"
    out.parent.mkdir(exist_ok=True)
    out.write_text(json.dumps(report, indent=2), encoding="utf-8")
    return 0


if __name__ == "__main__":
    sys.exit(main())
