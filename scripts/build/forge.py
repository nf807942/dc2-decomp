#!/usr/bin/env python3
"""Cherche, compose et garde — sans surveillance, et sans qu'on lui dise où.

    make forge                      # mesure seule, ne garde rien
    make forge ARGS="--garde"       # pose et vérifie l'image à chaque 100 %
    make forge ARGS="--rendement"   # ce que chaque réparation rapporte

**Ce module existe parce que le coût d'un essai a changé de trois ordres de
grandeur.** Chaque idiome du dépôt a été trouvé en écrivant une sonde, en la
lançant sur la classe qui l'avait inspiré, et en lisant sa sortie. C'était la
seule méthode possible à cinq secondes l'essai. À **trois millisecondes**, la
question n'est plus « quelle transformation essayer ? » mais « lesquelles, dans
quel ordre, et combien à la fois ? » — et cela, une machine le fait mieux.

La recherche est un faisceau. Au premier tour, toutes les réparations de
`scripts/diff/reparations.py` s'appliquent au jet ; le banc les mesure d'un
coup. Les meilleures survivent, et le tour suivant leur applique de nouveau
toutes les réparations. **Deux divergences indépendantes ne se corrigent souvent
qu'ensemble**, et aucune des deux ne paie seule : c'est ce que la profondeur
achète, et ce qu'un essai à cinq secondes interdisait.

Ce que la forge ne fait pas : inventer une réparation. Elle applique ce que le
dépôt sait, exhaustivement, et **mesure ce que chaque réparation rapporte** —
c'est ce compte qui dit laquelle outiller ensuite, et il remplace l'intuition.

Rien n'est gardé sans que la reconstruction complète rende le sha1 du disque.
`match_percent` départage des formes ; il ne prouve pas un gain.
"""

from __future__ import annotations

import argparse
import collections
import json
import sys
import time
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
sys.path.insert(0, str(Path(__file__).resolve().parent / ".." / "diff"))
import banc  # noqa: E402
import lot  # noqa: E402
import affinage  # noqa: E402
import sonde_m2c  # noqa: E402
from reparations import REPARATIONS  # noqa: E402
from sonde_m2c import ecris  # noqa: E402
from lib.project import ROOT  # noqa: E402

if hasattr(sys.stdout, "reconfigure"):
    sys.stdout.reconfigure(encoding="utf-8", errors="replace")

CLASSES = ROOT / "progress" / "classes.json"
CHAINE = ROOT / "progress" / "chaine.json"
ETAT = ROOT / "progress" / "forge.json"


def file_de_travail(combien: int) -> list[tuple[str, dict]]:
    """Les quasi-succès, les plus proches du but d'abord.

    Une réparation corrige une divergence : une fonction à 99,9 % en porte une,
    une fonction à 85 % en porte des dizaines, et l'essai coûte le même temps.
    """
    fiches = json.loads(CLASSES.read_text(encoding="utf-8"))
    ordre = sorted(fiches.items(),
                   key=lambda kv: (-(kv[1]["part"] or 0), -kv[1]["taille"]))
    # Une fonction déjà écrite n'a plus de greffe à remplacer : la mesurer
    # encore ferait retrouver chaque jour les gains de la veille, et gonflerait
    # le compte de rendement d'autant.
    sources = {}
    rendu = []
    for symbole, fiche in ordre:
        if not (lot.CORPUS / (symbole + ".cpp")).exists():
            continue
        unite = fiche["unite"]
        if unite not in sources:
            chemin = ROOT / "src" / (unite + ".cpp")
            sources[unite] = chemin.read_text(encoding="utf-8") \
                if chemin.exists() else ""
        if affinage.INCLUDE_ASM % (unite, symbole) not in sources[unite]:
            continue
        rendu.append((symbole, fiche))
    return rendu[:combien] if combien else rendu


def descend(symbole: str, unite: str, jet: str, ecarts: list[str],
            profondeur: int, largeur: int) -> tuple[float | None, str, list[str]]:
    """Le faisceau. Rend (meilleur score, meilleure forme, réparations employées)."""
    front = [(None, jet, [])]          # (score, texte, chemin)
    meilleur = (None, jet, [])
    for _ in range(profondeur):
        formes, tracas = [], []
        for _, texte, chemin in front:
            for reparation in REPARATIONS:
                for variante in reparation(texte, ecarts):
                    if variante == texte:
                        continue
                    formes.append(variante)
                    tracas.append(chemin + [reparation.__name__])
        if not formes:
            break
        # Le jet lui-même sert de repère au premier tour.
        if meilleur[0] is None:
            formes.insert(0, jet)
            tracas.insert(0, [])
        scores = banc.banc(symbole, unite, formes)
        classe = sorted(
            ((s, t, c) for s, t, c in zip(scores, formes, tracas)
             if s is not None), key=lambda x: -x[0])
        if not classe:
            break
        if meilleur[0] is None or classe[0][0] > meilleur[0]:
            meilleur = classe[0]
        if meilleur[0] is not None and meilleur[0] >= 100.0:
            break
        front = classe[:largeur]
    return meilleur


def garde(symbole: str, unite: str, texte: str) -> bool:
    """Pose pour de bon, et n'accepte que si l'image rend le sha1 du disque."""
    source = ROOT / "src" / (unite + ".cpp")
    avant = source.read_text(encoding="utf-8")
    ligne = affinage.INCLUDE_ASM % (unite, symbole)
    if ligne not in avant:
        return False
    pose = affinage._sans_collision(texte, symbole, avant, unite)
    ecris(source, avant.replace(ligne, pose))
    tenu = False
    try:
        part = affinage.recompile_et_mesure(symbole, unite)
        tenu = part is not None and part >= 100.0 and affinage.image_identique()
    finally:
        if not tenu:
            ecris(source, avant)
    return tenu


def main(argv: list[str]) -> int:
    parseur = argparse.ArgumentParser(description=__doc__)
    parseur.add_argument("--combien", type=int, default=0,
                         help="ne traite que les N premières de la file")
    parseur.add_argument("--profondeur", type=int, default=2,
                         help="tours de faisceau (défaut 2)")
    parseur.add_argument("--largeur", type=int, default=4,
                         help="formes gardées d'un tour à l'autre (défaut 4)")
    parseur.add_argument("--garde", action="store_true",
                         help="pose et vérifie l'image à chaque 100 %%")
    parseur.add_argument("--rendement", action="store_true",
                         help="n'affiche que ce que chaque réparation rapporte")
    options = parseur.parse_args(argv)

    ecarts_par_symbole = {
        s: (f.get("ecarts") or [])
        for s, f in json.loads(CHAINE.read_text(encoding="utf-8"))["eprouvees"]
        .items()}
    file = file_de_travail(options.combien)
    etat = json.loads(ETAT.read_text(encoding="utf-8")) if ETAT.exists() else {}

    depart = time.time()
    essais = 0
    gains = collections.Counter()
    octets = collections.Counter()
    tenues, poids = 0, 0
    for symbole, fiche in file:
        jet = (lot.CORPUS / (symbole + ".cpp")).read_text(
            encoding="utf-8").rstrip() + chr(10)
        ecarts = ecarts_par_symbole.get(symbole, [])
        score, texte, chemin = descend(symbole, fiche["unite"], jet, ecarts,
                                       options.profondeur, options.largeur)
        essais += 1
        fiche_etat = {"part": score, "chemin": chemin,
                      "depart": fiche["part"], "taille": fiche["taille"]}
        if score is not None and score >= 100.0:
            for nom in chemin:
                gains[nom] += 1
                octets[nom] += fiche["taille"]
            if options.garde and garde(symbole, fiche["unite"], texte):
                tenues += 1
                poids += fiche["taille"]
                fiche_etat["gardee"] = True
            if not options.rendement:
                print("  *** %-42s %6.2f%% -> 100 %%  par %s%s"
                      % (symbole[:42], fiche["part"], " + ".join(chemin),
                         "  (gardée)" if fiche_etat.get("gardee") else ""),
                      flush=True)
        elif not options.rendement and score is not None \
                and score > (fiche["part"] or 0) + 0.5:
            print("      %-42s %6.2f%% -> %6.2f%%  par %s"
                  % (symbole[:42], fiche["part"], score, " + ".join(chemin)),
                  flush=True)
        etat[symbole] = fiche_etat
        if essais % 25 == 0:
            ETAT.write_text(json.dumps(etat, ensure_ascii=False, indent=1),
                            encoding="utf-8")

    ETAT.write_text(json.dumps(etat, ensure_ascii=False, indent=1),
                    encoding="utf-8")
    print()
    print("%d fonctions traitées en %.0f s" % (essais, time.time() - depart))
    print("\nce que chaque réparation a rapporté :")
    for reparation in REPARATIONS:
        nom = reparation.__name__
        print("  %-24s %3d fonctions, %6d octets" % (nom, gains[nom],
                                                     octets[nom]))
    if options.garde:
        print("\n%d fonctions gardées, %d octets" % (tenues, poids))
    return 0


if __name__ == "__main__":
    raise SystemExit(main(sys.argv[1:]))
