#!/usr/bin/env python3
"""Relève, sur chaque quasi-succès, les instructions par lesquelles il diverge.

    make ecarts
    make ecarts ARGS="--combien 60"

**`match_percent` dit de combien on s'écarte, jamais où.** C'est la limite que
l'affinage a rencontrée : sur les soixante fonctions les plus proches du but —
dix d'entre elles à une seule instruction près —, aucun des huit idiomes n'a
réussi. Ils étaient tirés à l'aveugle, faute de savoir ce qui divergeait.

objdiff aligne les deux suites d'instructions et marque chacune. Cette passe
repose le C++ gardé sous `build/proches/`, reconstruit l'unité, et écrit le
relevé dans le verdict. Le groupement par forme d'écart qui suit est la même
méthode qui a produit chaque gain de la journée — le message du compilateur
nomme le symptôme, la ligne qu'il souligne nomme la cause — appliquée un cran
plus bas, là où il n'y a plus de message du tout.

Rien n'est gardé : la source revient à sa greffe, quoi qu'il arrive.
"""

from __future__ import annotations

import argparse
import collections
import json
import re
import sys
import time
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
sys.path.insert(0, str(Path(__file__).resolve().parent))
sys.path.insert(0, str(Path(__file__).resolve().parent / ".." / "diff"))
import sonde_m2c  # noqa: E402
from sonde_m2c import ecris  # noqa: E402
from affinage import CORPUS, ETAT, candidats, pose, recompile_et_mesure  # noqa: E402
from lib.project import ROOT  # noqa: E402

# `addiu a0, s0, 0x10` → `addiu a0, s0, K` : deux écarts qui ne diffèrent que
# par une constante ou un registre sont le même écart, et c'est le groupement
# qui les fait apparaître.
_NOMBRE = re.compile(r"\b(?:0x)?[0-9A-Fa-f]+\b")
_REGISTRE = re.compile(r"\b(?:[astv][0-9]|[sv][0-9]|f[0-9]{1,2}|at|gp|sp|fp|ra|zero)\b")


def forme(ecart: str) -> str:
    """La forme d'un écart, constantes et registres effacés."""
    rendu = _REGISTRE.sub("r", ecart)
    return _NOMBRE.sub("K", rendu)


def releve(lot: list[tuple[int, str, str]]) -> dict[str, list[str]]:
    """Repose chaque fragment, mesure, et rend le relevé par symbole."""
    trouve: dict[str, list[str]] = {}
    depart = time.time()
    for taille, symbole, unite in lot:
        pris = pose(symbole, unite)
        if pris is None:
            continue
        source, avant = pris
        try:
            part = recompile_et_mesure(symbole, unite)
            if part is None:
                continue
            lignes = sonde_m2c.ecarts(symbole, unite, combien=12)
            trouve[symbole] = lignes
            print("  %6.2f %%  %5d o  %-42s %d écart(s)"
                  % (part, taille, symbole[:42], len(lignes)), flush=True)
        finally:
            ecris(source, avant)
    print("\n%d fonctions relevées, %.1f s chacune"
          % (len(trouve), (time.time() - depart) / max(len(trouve), 1)))
    return trouve


def enregistre(trouve: dict[str, list[str]]) -> None:
    """Écrit le relevé dans les verdicts, sans toucher au reste.

    L'état se relit du disque avant d'être réécrit : une moisson qui tournerait
    en parallèle y aurait ajouté des verdicts, et les écraser coûterait des
    heures de mesure.
    """
    etat = json.loads(ETAT.read_text(encoding="utf-8"))
    for symbole, lignes in trouve.items():
        fiche = etat["eprouvees"].get(symbole)
        if fiche is not None:
            fiche["ecarts"] = lignes
    ETAT.write_text(json.dumps(etat, ensure_ascii=False, indent=1),
                    encoding="utf-8")


def groupe(trouve: dict[str, list[str]]) -> None:
    """Range les écarts par forme, du plus fréquent au moins fréquent."""
    formes: dict[str, int] = collections.Counter()
    uniques = 0
    for lignes in trouve.values():
        if len(lignes) == 1:
            uniques += 1
        for ligne in lignes:
            formes[forme(ligne)] += 1
    print("\n%d fonctions ne divergent que d'une instruction." % uniques)
    print("\nformes d'écart, la plus fréquente d'abord :")
    for cle, compte in formes.most_common(25):
        print("  %4d  %s" % (compte, cle[:104]))


def main(argv: list[str]) -> int:
    parseur = argparse.ArgumentParser(description=__doc__)
    parseur.add_argument("--combien", type=int, default=0,
                         help="ne relève que les N plus proches du but")
    options = parseur.parse_args(argv)

    lot = candidats(options.combien)
    if not lot:
        print("corpus vide : `make chaine` le remplit en mesurant.")
        return 0
    print("écarts : %d fonctions, %d octets"
          % (len(lot), sum(t for t, _, _ in lot)))
    trouve = releve(lot)
    enregistre(trouve)
    groupe(trouve)
    return 0


if __name__ == "__main__":
    raise SystemExit(main(sys.argv[1:]))
