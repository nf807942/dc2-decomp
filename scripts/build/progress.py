#!/usr/bin/env python3
"""Part du binaire qui vient de source compilée plutôt que de désassemblage.

La mesure porte sur les octets de code, non sur le nombre de fonctions : une
fonction de dix instructions et une de mille ne pèsent pas pareil. Le compte
sert aussi de rapport à decomp.dev, qui en fait une courbe.
"""

from __future__ import annotations

import json
import re
import subprocess
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from lib.project import BUILD_DIR, CONFIG_DIR, ROOT, run, sources  # noqa: E402

# `INCLUDE_ASM("nonmatchings/<unite>", <symbole>);`
_INCLUDE_ASM = re.compile(r'INCLUDE_ASM\s*\(\s*"[^"]*"\s*,\s*(\S+?)\s*\)')

_SYMBOL = re.compile(r"^(\S+)\s*=\s*0x([0-9A-Fa-f]+);.*?type:func(?:.*?size:0x([0-9A-Fa-f]+))?",
                     re.MULTILINE)


def decompiled_symbols() -> set[str]:
    """Les symboles qu'une source du projet définit.

    La question se tranche sur les objets compilés : une source écrit
    `CGamePad::Close` et le binaire porte `Close__8CGamePadFv`. Chercher le
    symbole dans le texte rendrait zéro à tout coup.

    Une fonction compte pour reconstruite dès qu'une source la définit ;
    l'exactitude est le verdict de `make build`, qui compare tout le binaire,
    et `make report` la donne fonction par fonction.
    """
    names: set[str] = set()
    for path in sources():
        obj = BUILD_DIR / path.relative_to(ROOT).with_suffix(".o")
        if not obj.exists():
            run(["make", str(obj.relative_to(ROOT))],
                stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
        if not obj.exists():
            continue
        listing = run(["mips-ps2-decompals-nm", "--defined-only", str(obj)],
                      capture_output=True, text=True)
        if listing.returncode != 0:
            continue

        defined: set[str] = set()
        for line in listing.stdout.splitlines():
            parts = line.split()
            # « adresse type nom » ; `t`/`T` désigne le texte.
            if len(parts) == 3 and parts[1] in "tT":
                defined.add(parts[2])

        # Une fonction greffée est définie dans l'objet comme une fonction
        # compilée : c'est bien son but, et l'objet seul ne les distingue pas.
        # C'est la source qui tranche, puisqu'elle nomme ce qu'elle laisse en
        # assembleur — l'alias `.NON_MATCHING` y suffirait presque, mais les
        # fonctions les plus courtes n'en reçoivent pas.
        grafted = set(_INCLUDE_ASM.findall(
            path.read_text(encoding="utf-8", errors="replace")))
        names |= {n for n in defined
                  if not n.endswith(".NON_MATCHING") and n not in grafted}
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
