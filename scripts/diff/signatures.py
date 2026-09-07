#!/usr/bin/env python3
"""Rend au `?` d'une signature le type que le mangling porte.

m2c écrit `?` pour ce dont il ignore le type. Le dépôt traite déjà ce cas
**dans une structure** — le champ devient un remplissage de la largeur connue —
mais pas **dans une liste de paramètres** :

    extern "C" void PrimDrawNumber__FP11mgCDrawPrimiiii9mgRect_i_ii(
        mgCDrawPrim *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4,
        ? arg5, s32 arg6, s32 arg7)

Ce n'est pas du C, et MWCC le signale sur l'accolade fermante, loin de la cause.
Les vingt `declaration syntax error` du tirage de référence désignent toutes une
accolade seule ; neuf fragments sur cent quarante-neuf portent ce `?`.

**Le type ne se devine pas, il se lit.** Le nom manglé donne la liste exacte des
paramètres, et `lib/mangling` la rend déjà. Pour une méthode, `this` occupe la
première place et le reste suit. On ne substitue donc que ce qui est prouvé, et
l'on s'abstient si le compte ne tombe pas juste — un décalage d'un rang mettrait
un type faux à la place d'un type absent, ce qui est pire.

**Mesuré, et cela ne fait compiler personne.** Sur les dix fragments du tirage
qui portent un `?`, la substitution a lieu — `? arg5` devient bien
`mgRect_i_ arg5` — et **zéro compile avant comme après**. La raison se lit sur
la plainte suivante : `mgRect_i_` n'est défini nulle part, et il est passé *par
valeur*, donc une déclaration en avant ne suffit pas.

Le `?` n'était donc pas la cause mais son masque. La vraie cause est un type que
m2c ne sait pas nommer parce qu'il n'existe dans aucun en-tête, et le dépôt la
connaît déjà sous un autre jour : « un champ par valeur d'un type absent perd la
structure entière ». Ce module reste, parce qu'il rend le diagnostic lisible et
qu'il sera utile le jour où ces types seront posés ; il ne rend rien seul.
"""

from __future__ import annotations

import re
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from lib.mangling import demangle  # noqa: E402

# `extern "C" void NOM(a, b, c)` — une déclaration ou une définition, dont la
# liste de paramètres tient sur une ligne, comme m2c les écrit.
_SIGNATURE = re.compile(
    r'^(extern "C" [^\n(]*?\b(\w+)\s*\()([^;{)]*)(\)[^\n]*)$', re.MULTILINE)


def _remplace(liste: str, params: list[str], methode: bool) -> str | None:
    """Substitue chaque `?` par le type que le mangling donne à ce rang."""
    membres = [m.strip() for m in liste.split(",")]
    if not any(m.startswith("?") for m in membres):
        return None
    # Une méthode porte `this` en tête, que le mangling ne liste pas.
    attendus = (["void *"] if methode else []) + list(params)
    if len(attendus) != len(membres):
        return None          # le compte ne tombe pas juste : on s'abstient
    rendu = []
    for membre, type_prouve in zip(membres, attendus):
        if membre.startswith("?"):
            nom = membre.split(None, 1)[1] if " " in membre else ""
            rendu.append(("%s %s" % (type_prouve.strip(), nom)).strip())
        else:
            rendu.append(membre)
    return ", ".join(rendu)


def types_prouves(texte: str) -> str:
    """Rend le texte, chaque `?` de signature remplacé par son type manglé."""
    def une(trouve):
        fiche = demangle(trouve.group(2))
        if not fiche:
            return trouve.group(0)
        neuf = _remplace(trouve.group(3), fiche.params,
                         bool(getattr(fiche, "cls", None)))
        if neuf is None:
            return trouve.group(0)
        return trouve.group(1) + neuf + trouve.group(4)

    return _SIGNATURE.sub(une, texte)
