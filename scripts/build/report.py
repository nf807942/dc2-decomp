#!/usr/bin/env python3
"""Rapport d'avancement, en page web autonome.

    make report        puis ouvrir progress/index.html

Deux étapes : `objdiff-cli report` mesure chaque unité et chaque fonction en
comparant l'objet compilé à l'objet de référence, puis cette page rend la
mesure lisible — la même vue par secteur que decomp.dev, sans dépôt public
et sans service tiers. La page est autonome : aucune requête n'en sort, et
elle s'ouvre depuis le disque.
"""

from __future__ import annotations

import json
import subprocess
import sys
from datetime import datetime, timezone
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from lib.project import CONFIG_DIR, ROOT  # noqa: E402
from build.gen_objdiff import SECTORS, sector_of  # noqa: E402

PROGRESS_DIR = ROOT / "progress"
REPORT_JSON = PROGRESS_DIR / "report.json"
PAGE = PROGRESS_DIR / "index.html"
TEMPLATE = Path(__file__).resolve().parent / "report_template.html"


def generate_report() -> dict:
    """Lance objdiff sur le projet et lit le rapport qu'il écrit."""
    PROGRESS_DIR.mkdir(exist_ok=True)
    result = subprocess.run(
        ["objdiff-cli", "report", "generate", "-p", ".",
         "-o", str(REPORT_JSON.relative_to(ROOT)), "-f", "json"],
        cwd=ROOT, capture_output=True, text=True,
    )
    if result.returncode != 0:
        sys.stderr.write(result.stderr)
        raise SystemExit("objdiff-cli report a échoué")
    return json.loads(REPORT_JSON.read_text(encoding="utf-8"))


def measure(node: dict, key: str, default: float = 0.0) -> float:
    """Une mesure absente vaut zéro : objdiff omet ce qui n'a rien apparié."""
    value = node.get("measures", {}).get(key, default)
    return float(value) if value is not None else default


def as_int(node: dict, key: str) -> int:
    # Les tailles voyagent en chaînes : elles dépassent ce que JSON garantit.
    value = node.get("measures", {}).get(key, 0)
    return int(value) if value else 0


def compact(report: dict) -> dict:
    """Réduit le rapport à ce que la page affiche.

    Le rapport brut fait deux mégaoctets, dont l'essentiel est du détail par
    section que la vue n'emploie pas.

    Le budget par secteur se compte par fonction, non par unité : deux unités
    portent 91 % du code du binaire — 1,4 Mo et 628 Kio —, et leur attribuer un
    secteur unique effacerait toute provenance minoritaire. Le middleware de
    Level-5 est dans ce cas : dispersé dans des unités que le jeu domine.
    """
    sector_names = {ident: name for ident, name, _ in SECTORS}

    units = []
    functions_all = []
    sectors: dict[str, dict[str, float]] = {
        ident: {"code": 0, "done": 0, "functions": 0, "functions_done": 0}
        for ident, _n, _p in SECTORS
    }

    for unit in report.get("units", []):
        code = as_int(unit, "total_code")
        # `complete_code_percent` est la part appariée à l'octet ; le flou, lui,
        # récompense une ressemblance, ce qui n'est pas le critère du projet.
        done_share = measure(unit, "complete_code_percent")

        function_list = []
        for fn in unit.get("functions", []):
            name = fn.get("name", "?")
            size = int(fn.get("size") or 0)
            share = measure(fn, "complete_code_percent")
            sector = sector_of(name)
            done = round(size * share / 100)

            entry = sectors.setdefault(
                sector, {"code": 0, "done": 0, "functions": 0, "functions_done": 0})
            entry["code"] += size
            entry["done"] += done
            entry["functions"] += 1
            entry["functions_done"] += 1 if share >= 99.999 else 0

            function_list.append([name, size, round(share), sector])
            functions_all.append([name, size, round(share), sector])

        # De la plus grosse à la plus petite : c'est l'ordre dans lequel on
        # choisit la suivante à reconstruire.
        function_list.sort(key=lambda row: -row[1])

        units.append({
            "name": unit.get("name", "?"),
            "sector": (unit.get("metadata", {}).get("progress_categories")
                       or ["game"])[0],
            "code": code,
            "share": round(done_share, 2),
            "functions": len(function_list),
            "source": unit.get("metadata", {}).get("source_path"),
            "fns": function_list,
        })

    functions_all.sort(key=lambda row: -row[1])

    total_code = as_int(report, "total_code")
    total_done = sum(s["done"] for s in sectors.values())

    sha1 = ""
    fingerprint = CONFIG_DIR / "main.sha1"
    if fingerprint.exists():
        sha1 = fingerprint.read_text(encoding="utf-8").split()[0]

    return {
        "generated": datetime.now(timezone.utc).astimezone().strftime("%Y-%m-%d %H:%M"),
        "sha1": sha1,
        "total": {
            "code": total_code,
            "done": total_done,
            "data": as_int(report, "total_data"),
            "functions": int(measure(report, "total_functions")),
            "units": len(units),
        },
        "sectors": [
            {"id": ident, "name": sector_names.get(ident, ident), **sectors[ident]}
            for ident, _n, _p in SECTORS if sectors.get(ident, {}).get("code")
        ],
        "units": sorted(units, key=lambda u: -u["code"]),
        # La carte se dessine sur les fonctions : c'est la seule échelle où le
        # binaire se répartit, et l'unité de travail tant que les 49 unités de
        # traduction du jeu n'ont pas retrouvé leurs frontières.
        "functions": functions_all[:MAP_TILES],
        "functions_total": len(functions_all),
        "functions_shown_code": sum(row[1] for row in functions_all[:MAP_TILES]),
    }


# Le nombre de tuiles que la carte porte. Au-delà, une tuile ne fait plus un
# pixel et le poids de la page double sans rien montrer de plus.
MAP_TILES = 1200


def main() -> int:
    data = compact(generate_report())

    template = TEMPLATE.read_text(encoding="utf-8")
    payload = json.dumps(data, ensure_ascii=False, separators=(",", ":"))
    PAGE.write_text(template.replace("/*DATA*/null", payload), encoding="utf-8")

    total = data["total"]
    share = 100 * total["done"] / total["code"] if total["code"] else 0
    print(f"code reconstruit : {total['done']} octets sur {total['code']}"
          f" ({share:.3f} %)")
    for sector in data["sectors"]:
        part = 100 * sector["done"] / sector["code"] if sector["code"] else 0
        print(f"  {sector['name']:22s} {sector['done']:8d} / {sector['code']:8d}"
              f"  {part:6.2f} %")
    print(f"\npage : {PAGE.relative_to(ROOT)}"
          f"  ({PAGE.stat().st_size // 1024} Kio, autonome)")
    return 0


if __name__ == "__main__":
    sys.exit(main())
