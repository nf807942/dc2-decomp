#!/usr/bin/env python3
"""Reprend une fonction qui compile sans apparier, et lui applique les idiomes.

La chaîne mesure une fonction à 93 % puis l'abandonne : c'est le geste qu'un
humain fait ensuite qui lui manquait. Les transformations de
`scripts/diff/idiomes.py` viennent d'écarts mesurés, et ce module les essaie une
à une — compilation et appariement à chaque coup, la meilleure forme gardée.

Ce n'est pas le permuteur. Celui-ci cherche à l'aveugle sur des centaines
d'essais ; ici on en tente une dizaine, chacune motivée, et l'on s'arrête au
premier 100 %. Quand une réussit, elle confirme l'idiome dont elle vient — c'est
ce qui distingue une correction d'un coup de chance.

**La descente n'est pas gloutonne par accident.** Une transformation qui fait
reculer le score est rejetée, mais une qui le laisse égal est gardée : deux
idiomes se composent souvent sans que le premier paie seul, et `SearchCharaTexb`
en est l'exemple — le calcul rentré dans la boucle ne valait rien avant que la
sortie ne soit redoublée.
"""

from __future__ import annotations

import random
import re
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
sys.path.insert(0, str(Path(__file__).resolve().parent))
from idiomes import IDIOMES  # noqa: E402
from sonde_m2c import ecris  # noqa: E402
from lib.project import ROOT  # noqa: E402

# `extern "C" <type> <symbole>(…) {` … `}` — la définition que la chaîne a posée.
_CORPS = 'extern "C" '


def definition(texte: str, symbole: str) -> tuple[int, int] | None:
    """Les bornes de la définition d'une fonction dans une source posée."""
    marque = re.search(r'extern "C" [^\n(]*\b%s\s*\(' % re.escape(symbole), texte)
    if marque is None:
        return None
    fin = texte.find("\n}\n", marque.start())
    if fin < 0:
        return None
    return marque.start(), fin + 3


def affine(symbole: str, unite: str, depart: float,
           mesure, tours: int = 2) -> tuple[float, bool]:
    """Applique les idiomes tant qu'ils gagnent. Rend (meilleur score, gardé).

    `mesure` recompile l'unité et rend l'appariement de la fonction ; c'est la
    sonde qui la fournit, pour que ce module n'ait à connaître ni le compilateur
    ni objdiff.
    """
    source = ROOT / "src" / (unite + ".cpp")
    meilleur = depart
    texte = source.read_text(encoding="utf-8")
    bornes = definition(texte, symbole)
    if bornes is None:
        return depart, False

    rng = random.Random(0)
    for _tour in range(tours):
        texte = source.read_text(encoding="utf-8")
        bornes = definition(texte, symbole)
        if bornes is None:
            break
        debut, fin = bornes
        corps = texte[debut:fin]
        garde = texte

        progres = False
        for transformation in IDIOMES:
            for variante in transformation(corps, rng):
                if variante == corps:
                    continue
                ecris(source, texte[:debut] + variante + texte[fin:])
                part = mesure(symbole, unite)
                if part is None or part < meilleur:
                    ecris(source, garde)
                    continue
                # Égalité gardée : deux idiomes se composent souvent sans que le
                # premier paie seul.
                meilleur = part
                progres = True
                if part >= 99.999:
                    return part, True
                break
            if progres:
                break
        if not progres:
            ecris(source, garde)
            break

    return meilleur, meilleur >= 99.999
