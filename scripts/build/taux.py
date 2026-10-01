#!/usr/bin/env python3
"""Mesure combien de fonctions **compilent**, pour juger une règle de normalisation.

    make taux                       # sur l'échantillon par défaut
    make taux ARGS="--combien 300"
    make taux ARGS=--causes         # ce qui bloque, par famille

**C'est le chiffre qui décide du projet, et rien ne le mesurait.** Le banc et la
forge cherchent la bonne *forme de source* pour une fonction dont le jet compile
déjà ; or **67 % du binaire n'a aujourd'hui aucune source qui compile** — ni
juste, ni fausse. Sur les 601 236 octets de la tranche 512 o à 2 Ko qui échouent,
la question n'est pas de trouver la bonne forme parmi mille, c'est d'en obtenir
une seule.

Le goulot est donc la normalisation, `scripts/diff/sonde_m2c.py`, et non la
recherche. Chaque défaut qu'on y corrige débloque toute une famille de
fonctions ; mais jusqu'ici, savoir si un correctif payait demandait une passe de
moisson entière, des heures, avec écriture dans les sources.

Ce module fait la même mesure **sans rien écrire et en quelques minutes** :
m2c est appelé une fois par fonction et sa sortie mise en cache, puis seules la
normalisation et la compilation sont refaites. Un correctif de normalisation se
juge donc sur trois cents fonctions le temps d'un café, et l'on peut enfin
itérer sur la seule partie du problème qui porte les octets.

**Le harnais est validé contre la moisson**, qui écrit dans les sources et met
des heures : sur quarante fonctions, **trente-neuf verdicts identiques**. Le seul
désaccord porte sur `illegal function overloading`, un mécanisme que cette boucle
ne reproduit pas. Sans cette vérification, la mesure ne vaudrait rien : une
première version, qui oubliait la boucle de complétion, annonçait 17,5 % au lieu
de 30 % et faisait dominer `undefined identifier` — c'est-à-dire exactement ce
que la complétion existe pour régler.

Le cache vit sous `build/jets/`, hors de git : il est dérivé du jeu.
"""

from __future__ import annotations

import argparse
import collections
import json
import random
import re
import sys
import time
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
sys.path.insert(0, str(Path(__file__).resolve().parent / ".." / "diff"))
import lot  # noqa: E402
import sonde_m2c  # noqa: E402
from sonde_m2c import (INCLUDE_ASM, declarations_portees,  # noqa: E402
                       deja_declarees, deja_prototypees, deja_vues, normalise)
from lib.project import ROOT  # noqa: E402

if hasattr(sys.stdout, "reconfigure"):
    sys.stdout.reconfigure(encoding="utf-8", errors="replace")

CHAINE = ROOT / "progress" / "chaine.json"
# Le meme plafond que la chaine : une fonction qui touche trente types reclame
# trente tours, et la boucle s'arrete d'elle-meme des qu'un tour n'apprend rien.
TOURS = 24
# `function call 'f(int)' does not match 'f(void)'` — l'appele est le meme,
# la facon de l'appeler differe d'une fonction de l'unite a l'autre.
_ARITE = re.compile(r"function call '(\w+)\(")
JETS = ROOT / "build" / "jets"


def jet(symbole: str) -> str | None:
    """La sortie brute de m2c, mise en cache.

    m2c coûte environ une seconde par fonction et **il ne dépend pas de la
    normalisation** : le cacher rend une mesure de taux dix fois plus rapide, et
    c'est cette vitesse qui permet d'itérer sur les règles.
    """
    JETS.mkdir(parents=True, exist_ok=True)
    garde = JETS / (symbole + ".c")
    if garde.exists():
        texte = garde.read_text(encoding="utf-8")
        return texte or None
    texte = sonde_m2c.decompile(symbole)
    garde.write_text(texte or "", encoding="utf-8")
    return texte


def compile_ou_non(symbole: str, unite: str) -> tuple[bool, str]:
    """La fonction compile-t-elle, telle que la normalisation la rend ?

    Rien n'est posé dans les sources : le fragment normalisé est compilé dans
    l'unité privée de ses greffes, comme le fait `make lot`.
    """
    texte = jet(symbole)
    if texte is None:
        return False, "m2c refuse"
    source = ROOT / "src" / (unite + ".cpp")
    if not source.exists():
        return False, "unité absente"
    avant = source.read_text(encoding="utf-8", errors="replace")
    amont = avant.split(INCLUDE_ASM % (unite, symbole))[0]
    rendu = normalise(texte, symbole, deja_vues(unite, amont),
                      deja_declarees(unite, amont),
                      declarations_portees(avant),
                      deja_prototypees(unite, amont))
    if rendu is None:
        return False, "normalisation illisible"
    declarations, corps = rendu

    # **La boucle de complétion vit dans `eprouve`, pas dans `normalise`.**
    # L'oublier faisait mesurer un taux de 17,5 % où `undefined identifier`
    # dominait — c'est-à-dire exactement ce que la complétion existe pour
    # régler. On la reproduit donc, en réemployant les deux fonctions du dépôt
    # qui la portent : `declaration` dit ce qu'il faut écrire pour qu'un nom
    # existe, `assemble` retire ce que l'unité déclare déjà.
    ajoutees: list[str] = []
    vus: set[str] = set()
    ellipses: set[str] = set()
    plainte = ""
    for _ in range(TOURS):
        fragment = sonde_m2c.assemble(ajoutees, declarations, corps, amont,
                                      unite, sonde_m2c._marque(symbole),
                                      deja_declarees(unite, amont))
        (part, plainte), = lot.formes(symbole, unite, [fragment])
        if part is not None:
            return True, ""
        # **Un appelé ne s'appelle pas partout de la même façon.** Deux
        # fonctions d'une unité passent au même symbole des arguments
        # différents, et un nom `extern "C"` ne se surcharge pas. `(...)` les
        # accepte l'une et l'autre, et le dépôt a mesuré que l'ellipse ne coûte
        # aucun octet. Omettre ce traitement expliquait quatre des cinq
        # désaccords entre ce harnais et la moisson.
        conflits = set(_ARITE.findall(plainte)) - ellipses
        if conflits:
            ellipses |= conflits
            for appele in conflits:
                motif = re.compile(
                    r'^extern "C" ([^;(]*?)\b%s\s*\([^;{}\n]*\);$'
                    % re.escape(appele), re.MULTILINE)
                remplacement = 'extern "C" \\1%s(...);' % appele
                declarations = motif.sub(remplacement, declarations)
                ajoutees = [motif.sub(remplacement, d) for d in ajoutees]
            continue

        manquants = set(sonde_m2c._INCONNU.findall(plainte)) - vus
        if not manquants:
            return False, _famille(plainte)
        vus |= manquants
        neuves = [d for d in (sonde_m2c.declaration(nom, declarations + corps)
                              for nom in sorted(manquants))
                  if d and d not in ajoutees]
        if not neuves:
            return False, _famille(plainte)
        ajoutees += neuves
    return False, "déclarations sans fin"


# Les familles de plaintes, pour que le compte dise où porter l'effort.
_FAMILLES = ("redefined", "does not match", "illegal function overloading",
             "expression syntax error", "declaration syntax error",
             "pointer/array required", "illegal operand", "illegal type",
             "undefined identifier", "incomplete", "expected",
             "illegal implicit conversion", "illegal explicit conversion")


def _famille(plainte: str) -> str:
    for famille in _FAMILLES:
        if famille in plainte:
            return famille
    return "autre"


def echantillon(combien: int, graine: int, mini: int, maxi: int):
    """Un tirage stable : deux mesures doivent porter sur les mêmes fonctions."""
    juges = json.loads(CHAINE.read_text(encoding="utf-8"))["eprouvees"]
    lot_a_juger = [(s, v) for s, v in juges.items()
                   if v.get("unite") and mini <= v.get("taille", 0) < maxi]
    lot_a_juger.sort()
    random.Random(graine).shuffle(lot_a_juger)
    return lot_a_juger[:combien]


def main(argv: list[str]) -> int:
    parseur = argparse.ArgumentParser(description=__doc__)
    parseur.add_argument("--combien", type=int, default=200)
    parseur.add_argument("--graine", type=int, default=0,
                         help="le tirage doit être stable d'une mesure à l'autre")
    parseur.add_argument("--mini", type=int, default=128)
    parseur.add_argument("--maxi", type=int, default=2048)
    parseur.add_argument("--causes", action="store_true",
                         help="range les échecs par famille de plainte")
    options = parseur.parse_args(argv)

    tirage = echantillon(options.combien, options.graine,
                         options.mini, options.maxi)
    print("%d fonctions de %d à %d octets, tirage %d"
          % (len(tirage), options.mini, options.maxi, options.graine))
    depart, compilent = time.time(), 0
    causes = collections.Counter()
    octets = collections.Counter()
    for rang, (symbole, fiche) in enumerate(tirage, 1):
        bon, cause = compile_ou_non(symbole, fiche["unite"])
        compilent += bon
        if not bon:
            causes[cause] += 1
            octets[cause] += fiche.get("taille", 0)
        if rang % 50 == 0:
            print("  %d/%d, %d compilent (%.0f %%), %.0f s"
                  % (rang, len(tirage), compilent, 100.0 * compilent / rang,
                     time.time() - depart), flush=True)
    print()
    print("**%d sur %d compilent, soit %.1f %%** en %.0f s"
          % (compilent, len(tirage), 100.0 * compilent / max(len(tirage), 1),
             time.time() - depart))
    if options.causes:
        print("\nce qui bloque, par famille :")
        for cause, combien in causes.most_common():
            print("  %4d fn  %8d o  %s" % (combien, octets[cause], cause))
    return 0


if __name__ == "__main__":
    raise SystemExit(main(sys.argv[1:]))
