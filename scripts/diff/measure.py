#!/usr/bin/env python3
"""Mesure d'un lot de formes pour un même fragment de source.

    make measure S=<symbole> V=<fichier de variantes>

Le permuteur cherche seul, par transformations aveugles ; ce banc-ci compare
des formes qu'on lui donne. Il sert quand on sait quelle question poser — quel
type, quel ordre de déclaration, quelle structure de boucle — et qu'on veut la
réponse en une passe plutôt qu'en autant d'allers-retours.

La source encadre le fragment que le lot remplace :

    /* @@boucle */
    for (i = 0; i < 7; i++) {
    }
    /* @@fin */

Le fichier de variantes est un module Python qui déclare le nom du marqueur et
les formes à éprouver :

    MARQUEUR = "boucle"
    VARIANTES = {
        "vide":     "    for (i = 0; i < 7; i++) {\\n    }\\n",
        "tableau":  "    for (i = 0; i < 7; i++) {\\n        check[i] = 0;\\n    }\\n",
    }

La source est rendue à son état d'origine à la fin, quel que soit le résultat.
"""

from __future__ import annotations

import argparse
import importlib.util
import re
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from lib.project import ROOT  # noqa: E402
from permute import Scorer  # noqa: E402


def load_variants(path: Path) -> tuple[str, dict[str, str]]:
    spec = importlib.util.spec_from_file_location("variantes", path)
    if spec is None or spec.loader is None:
        raise SystemExit(f"{path} : illisible")
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    try:
        return module.MARQUEUR, module.VARIANTES
    except AttributeError:
        raise SystemExit(f"{path} doit déclarer MARQUEUR et VARIANTES")


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("symbol")
    parser.add_argument("variants", type=Path)
    args = parser.parse_args()

    marker, variants = load_variants(args.variants)
    scorer = Scorer(args.symbol)
    whole = scorer.source.read_text(encoding="utf-8")

    marks = re.compile(r"/\* @@" + re.escape(marker) + r" \*/\n(.*?)[ \t]*/\* @@fin \*/",
                       re.DOTALL)
    found = marks.search(whole)
    if not found:
        raise SystemExit(
            f"{scorer.source.relative_to(ROOT)} n'encadre pas « {marker} ».\n"
            f"Entourez le fragment de /* @@{marker} */ et /* @@fin */.")

    origin = found.group(1)
    results: list[tuple[float, str]] = []
    try:
        for name, body in variants.items():
            scorer.source.write_text(
                whole[:found.start(1)] + body + whole[found.end(1):],
                encoding="utf-8")
            score = scorer.score()
            results.append((score, name))
            print(f"{name:24s} {score:7.2f} %", flush=True)
    finally:
        # La source repart telle qu'elle est arrivée : une mesure interrompue
        # ne doit pas laisser derrière elle la dernière forme éprouvée.
        scorer.source.write_text(
            whole[:found.start(1)] + origin + whole[found.end(1):],
            encoding="utf-8")

    if results:
        best, name = max(results)
        print(f"\nmeilleure : {name}  {best:.2f} %")
    return 0


if __name__ == "__main__":
    sys.exit(main())
