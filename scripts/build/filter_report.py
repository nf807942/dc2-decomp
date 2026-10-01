#!/usr/bin/env python3
"""Make the objdiff report count only what is really rebuilt.

    python3 scripts/build/filter_report.py progress/report.json

A function still under INCLUDE_ASM is grafted by mwccgap: the compiled object holds
the disc's own bytes, so objdiff matches it at 100 % without a line of C++ written.
Left as is, the report that decomp.dev publishes would overstate progress. This
script zeroes those functions and recomputes the measures of their units, of the
whole report and of its categories.

Functions that are original hand-written assembly (syscall stubs) cannot be
decompiled and `INCLUDE_ASM` is their faithful source: they stay counted as matched.
"""

from __future__ import annotations

import json
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from lib.project import asm_origine, grafted_symbols  # noqa: E402

# Measures that are plain sums over functions, units or categories.
COUNTS = ("matched_code", "matched_functions", "complete_code", "complete_units")


def num(measures: dict, key: str) -> float:
    # objdiff omits a zero, and writes 64-bit integers as strings.
    return float(measures.get(key) or 0)


def refresh_percents(m: dict, weighted_fuzzy: float) -> None:
    """Derive the percentages from the sums, the way objdiff does."""
    code, functions = num(m, "total_code"), num(m, "total_functions")
    m["fuzzy_match_percent"] = 100 * weighted_fuzzy / code if code else 100.0
    m["matched_code_percent"] = 100 * num(m, "matched_code") / code if code else 100.0
    m["matched_functions_percent"] = (100 * num(m, "matched_functions") / functions
                                      if functions else 100.0)
    m["complete_code_percent"] = (100 * num(m, "complete_code") / code
                                  if code else 100.0)


def retotal(unit: dict, zeroed: set[str]) -> tuple[dict, float] | None:
    """New measures of a unit, or None when none of its functions changes."""
    functions = unit.get("functions") or []
    changed = False
    for fn in functions:
        if fn.get("name") in zeroed and num(fn, "fuzzy_match_percent") > 0:
            fn["fuzzy_match_percent"] = 0.0
            changed = True
    if not changed:
        return None

    old = dict(unit.get("measures") or {})
    new = dict(old)
    weighted = matched = exact = 0.0
    for fn in functions:
        size, share = num(fn, "size"), num(fn, "fuzzy_match_percent")
        weighted += size * share / 100
        if share >= 100:
            matched += size
            exact += 1
    code = num(old, "total_code")
    new["matched_code"] = str(int(matched))
    new["matched_functions"] = int(exact)
    complete = code > 0 and matched >= code
    new["complete_code"] = str(int(code)) if complete else "0"
    new["complete_units"] = 1 if complete else 0
    refresh_percents(new, weighted)
    return new, weighted


def filter_report(report: dict, zeroed: set[str]) -> int:
    """Rewrite `report` in place; return how many functions were zeroed."""
    totals = report.setdefault("measures", {})
    categories = {c.get("id"): c for c in report.get("categories") or []}
    weighted_total = num(totals, "fuzzy_match_percent") * num(totals, "total_code") / 100
    category_weight = {i: num(c.get("measures") or {}, "fuzzy_match_percent")
                       * num((c.get("measures") or {}), "total_code") / 100
                       for i, c in categories.items()}
    before = sum(num(fn, "fuzzy_match_percent") > 0 and fn.get("name") in zeroed
                 for u in report.get("units", []) for fn in u.get("functions") or [])

    for unit in report.get("units", []):
        old = dict(unit.get("measures") or {})
        old_weight = num(old, "fuzzy_match_percent") * num(old, "total_code") / 100
        result = retotal(unit, zeroed)
        if result is None:
            continue
        new, new_weight = result
        unit["measures"] = new
        owners = [categories[i] for i in (unit.get("metadata") or {}).get(
            "progress_categories") or [] if i in categories]
        for holder in [{"measures": totals}] + owners:
            m = holder.setdefault("measures", {})
            for key in COUNTS:
                delta = num(new, key) - num(old, key)
                m[key] = str(int(num(m, key) + delta)) if key.endswith("code") \
                    else int(num(m, key) + delta)
            if holder["measures"] is totals:
                weighted_total += new_weight - old_weight
            else:
                category_weight[holder["id"]] += new_weight - old_weight

    refresh_percents(totals, weighted_total)
    for ident, category in categories.items():
        refresh_percents(category["measures"], category_weight[ident])
    return before


def main() -> int:
    path = Path(sys.argv[1] if len(sys.argv) > 1 else "progress/report.json")
    report = json.loads(path.read_text(encoding="utf-8"))
    zeroed = grafted_symbols() - asm_origine()
    count = filter_report(report, zeroed)
    path.write_text(json.dumps(report, indent=2), encoding="utf-8")
    m = report["measures"]
    print(f"{count} grafted functions no longer counted; "
          f"matched code {num(m, 'matched_code_percent'):.3f} %, "
          f"fuzzy {num(m, 'fuzzy_match_percent'):.3f} %")
    return 0


if __name__ == "__main__":
    sys.exit(main())
