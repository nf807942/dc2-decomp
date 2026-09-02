#!/usr/bin/env python3
"""La chaîne : traduire, mesurer, garder ce qui rend les octets du disque.

    make chaine                        la fenêtre par défaut, 128 à 512 octets
    make chaine ARGS="--mini 512 --maxi 2048"
    make chaine ARGS=--reprendre       repart de ce que l'état connaît déjà

Ce que `sonde_m2c.py` mesurait sans rien garder, cette chaîne le garde. Chaque
fonction suit le même chemin — m2c avec le contexte, normalisation, complétion
des déclarations, compilation, appariement — et seules celles qui rendent
**exactement** les octets du commerce restent en place. Le reste retrouve son
`INCLUDE_ASM` sans laisser de trace.

**Elle écrit dans les sources, elle ne bâtit pas de plan.** Une première version
mesurait chaque fonction isolément puis appliquait le tout en bloc ; deux choses
l'ont fait échouer, et toutes deux tiennent au même principe. Les déclarations
de deux fonctions d'une même unité se télescopaient, personne ne les ayant vues
ensemble. Et un fragment figé vieillit : le contexte change, m2c ne rend plus le
même corps, et ce qu'on applique n'est plus ce qu'on a mesuré. La source est le
seul état qui fasse foi — chaque fonction est donc éprouvée *par-dessus* celles
que son unité a déjà gagnées.

`make ci` reste le verdict d'ensemble : la chaîne n'affirme rien sur le binaire,
elle ne fait que ne garder que ce qu'objdiff donne pour identique.

**L'état est repris.** `progress/chaine.json` retient ce qui a été éprouvé et son
verdict ; une coupure ne coûte que la fonction en cours, et `--reprendre` ne
refait pas le chemin déjà parcouru.
"""

from __future__ import annotations

import argparse
import collections
import json
import signal
import sys
import time
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "diff"))
import affine  # noqa: E402
import sonde_m2c  # noqa: E402
from lib.project import (ROOT, functions, grafted_by_source,  # noqa: E402
                         run, unit_of)

ETAT = ROOT / "progress" / "chaine.json"


def charge(reprendre: bool) -> dict:
    if reprendre and ETAT.exists():
        return json.loads(ETAT.read_text(encoding="utf-8"))
    return {"eprouvees": {}}


def enregistre(etat: dict) -> None:
    ETAT.parent.mkdir(exist_ok=True)
    ETAT.write_text(json.dumps(etat, ensure_ascii=False, indent=1),
                    encoding="utf-8")


def par_unite(mini: int, maxi: int) -> dict[str, list[tuple[int, str]]]:
    """Les candidates de la fenêtre, groupées par unité et triées par poids.

    L'unité est l'échelle de travail : ses fonctions se compilent ensemble et
    partagent leurs déclarations. L'ordre suit le poids, car c'est lui que la
    cadence réclame — une fonction lourde qui apparie vaut vingt accesseurs.
    """
    table = functions()
    greffees = {nom for noms in grafted_by_source().values() for nom in noms}
    groupes: dict[str, list[tuple[int, str]]] = collections.defaultdict(list)
    for nom, fonction in table.items():
        if nom in greffees and mini <= fonction.size <= maxi:
            unite = unit_of(nom)
            if unite:
                groupes[unite].append((fonction.size, nom))
    for lot in groupes.values():
        lot.sort(key=lambda entree: -entree[0])
    return dict(sorted(groupes.items(),
                       key=lambda kv: -sum(t for t, _ in kv[1])))


def recompile_et_mesure(symbole: str, unite: str) -> float | None:
    """Reconstruit l'unité, puis rend l'appariement de la fonction.

    `score()` seul interrogerait objdiff sur l'objet d'avant : la variante que
    l'affinage vient d'écrire ne serait pas mesurée, et son score serait celui
    de la forme précédente. C'est la même erreur que le faux 100 % d'une
    fonction restée greffée, une couche plus loin.
    """
    objet = ROOT / "build" / "src" / (unite + ".o")
    if objet.exists():
        objet.unlink()
    bati = run(["make", str(objet.relative_to(ROOT))],
               capture_output=True, text=True)
    if bati.returncode != 0:
        return None
    return sonde_m2c.score(symbole, unite)


def main(argv: list[str]) -> int:
    parseur = argparse.ArgumentParser(description=__doc__)
    # La fenetre utile, mesuree : 60,5 % de rendement entre 32 et 64 octets,
    # 24,5 % jusqu a 128, 9,8 % jusqu a 256, puis 1,5 %. Au-dela de 512, la
    # moisson ne gagne rien et coute trois quarts d heure par millier de
    # fonctions.
    parseur.add_argument("--mini", type=int, default=32)
    parseur.add_argument("--maxi", type=int, default=512)
    parseur.add_argument("--unites", type=int, default=0,
                         help="s'arrête après N unités")
    parseur.add_argument("--reprendre", action="store_true")
    options = parseur.parse_args(argv)

    # `docker stop` envoie SIGTERM, que Python termine sans dérouler les `finally`
    # — la fonction en cours reste alors posée dans sa source sans avoir été
    # mesurée, et `make build` s'écarte de 77 % pour seize octets manquants.
    # `sys.exit` lève `SystemExit`, qui les déroule : la sonde rend sa source.
    signal.signal(signal.SIGTERM, lambda *_: sys.exit(1))

    etat = charge(options.reprendre)
    groupes = par_unite(options.mini, options.maxi)
    if options.reprendre:
        groupes = {unite: [e for e in lot if e[1] not in etat["eprouvees"]]
                   for unite, lot in groupes.items()}
        groupes = {u: l for u, l in groupes.items() if l}
    if options.unites:
        groupes = dict(list(groupes.items())[:options.unites])

    total = sum(len(lot) for lot in groupes.values())
    octets = sum(t for lot in groupes.values() for t, _ in lot)
    print("chaîne : %d fonctions dans %d unités, %d octets en jeu, "
          "de %d à %d octets"
          % (total, len(groupes), octets, options.mini, options.maxi))

    gagnees, gagnes, faits, depart = 0, 0, 0, time.time()
    for unite, lot in groupes.items():
        print("\n%s — %d fonctions, %d octets"
              % (unite, len(lot), sum(t for t, _ in lot)), flush=True)
        for taille, symbole in lot:
            verdict = sonde_m2c.eprouve(symbole, unite, taille, garde=True)
            faits += 1
            part = verdict.get("part")

            # Une fonction qui compile sans apparier n'est pas perdue : les
            # idiomes mesurés valent d'être essayes avant de la rendre. La
            # sonde, elle, l'abandonnait a 93 %.
            if part is not None and 85.0 <= part < 99.999:
                part, gagnee_par_idiome = affine.affine(
                    symbole, unite, part, recompile_et_mesure)
                if gagnee_par_idiome:
                    verdict["part"] = part
                    verdict["idiome"] = True
            etat["eprouvees"][symbole] = {
                "issue": verdict["issue"], "part": part, "taille": taille,
                # La cause, et non la seule issue : c'est elle qui dit quelle
                # correction paierait le plus au tour suivant, et la relever
                # après coup demanderait de tout réexécuter.
                "cause": verdict.get("cause", ""), "unite": unite}

            if part is not None and part >= 99.999:
                gagnees += 1
                gagnes += taille
                print("  %5d o  %-46s  gagnée" % (taille, symbole[:46]),
                      flush=True)
            elif part is not None:
                print("  %5d o  %-46s  %5.1f %%"
                      % (taille, symbole[:46], part), flush=True)
        enregistre(etat)

    ecoule = time.time() - depart
    print("\n%d fonctions gagnées sur %d éprouvées — %d octets, %.1f s chacune"
          % (gagnees, faits, gagnes, ecoule / faits if faits else 0))
    compte: dict[str, int] = {}
    for decrit in etat["eprouvees"].values():
        compte[decrit["issue"]] = compte.get(decrit["issue"], 0) + 1
    for issue, combien in sorted(compte.items(), key=lambda kv: -kv[1]):
        print("  %-18s %4d" % (issue, combien))
    print("\nles sources portent ce qui a été gagné ; `make ci` tranche.")
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
