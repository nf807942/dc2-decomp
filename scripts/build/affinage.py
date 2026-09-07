#!/usr/bin/env python3
"""La seconde passe : reprendre ce qui compile sans apparier.

    make affinage
    make affinage ARGS="--combien 40 --rendement"

**C'est ici que se joue le gros du binaire, non dans la moisson.** Le rendement
de la chaîne s'effondre avec la taille — 27 % de fonctions gagnées à 32 octets,
0,4 % à 256, rien au-delà de 512 — et 61 % des octets qui restent vivent dans
970 fonctions de plus de 512 octets. Aucun traducteur ne les rendra ; il les
amène à compiler, médiane 85 %, et s'arrête là.

Le rendement de l'affinage, lui, ne décroît pas avec la taille : une décision de
compilateur corrigée sur une fonction de 5 000 octets vaut 5 000 octets. C'est
la seule mécanique qui passe à l'échelle de deux mégaoctets.

La moisson dépose sous `build/proches/` le C++ de chaque fonction mesurée entre
85 et 100 %. Cette passe le repose et lui applique les idiomes de
`scripts/diff/idiomes.py`, chacun tiré d'un écart mesuré. `--rendement` ne garde
rien et rapporte ce que chaque idiome débloque : c'est la mesure qui dit si
l'outillage d'un idiome de plus vaut la peine.
"""

from __future__ import annotations

import argparse
import collections
import json
import random
import sys
import time
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
sys.path.insert(0, str(Path(__file__).resolve().parent / ".." / "diff"))
import affine  # noqa: E402
import sonde_m2c  # noqa: E402
from sonde_m2c import ecris  # noqa: E402
from idiomes import IDIOMES  # noqa: E402
from lib.project import ROOT, functions, run, unit_of  # noqa: E402

CORPUS = ROOT / "build" / "proches"
ETAT = ROOT / "progress" / "chaine.json"
INCLUDE_ASM = sonde_m2c.INCLUDE_ASM


def candidats(combien: int) -> list[tuple[int, str, str]]:
    """Les quasi-succès dont le corpus porte le C++, les plus proches d'abord.

    **L'ordre est celui de la proximité, non celui du poids.** Un idiome répare
    une divergence ; une fonction à 99,96 % en porte une, une fonction à 85 %
    en porte des dizaines, et l'essai coûte le même temps dans les deux cas.
    Le corpus compte 134 fonctions au-dessus de 99 % — dix au-dessus de 99,96 %,
    sur des fonctions de cent à trois cents octets. Trier par poids mettait les
    plus dures devant, et c'est sur elles que le rendement avait été mesuré à
    trois succès sur cent cinquante essais.

    Le poids départage à proximité égale : à divergence unique, la fonction la
    plus lourde rapporte davantage.
    """
    if not CORPUS.exists():
        return []
    etat = json.loads(ETAT.read_text(encoding="utf-8"))["eprouvees"]
    lot = []
    for chemin in CORPUS.glob("*.cpp"):
        symbole = chemin.stem
        fiche = etat.get(symbole) or {}
        unite = fiche.get("unite") or unit_of(symbole)
        if unite:
            lot.append((fiche.get("part") or 0.0,
                        fiche.get("taille") or 0, symbole, unite))
    lot.sort(reverse=True)
    rendu = [(taille, symbole, unite) for _, taille, symbole, unite in lot]
    return rendu[:combien] if combien else rendu


# Ce que MWCC a dit du dernier échec de compilation. Un `None` rendu par la
# mesure ne distingue pas un type inconnu d'un fragment périmé, et c'est ce
# silence qui fait prendre l'outillage pour une propriété du binaire.
derniere_erreur: str = ""


def _diagnostic(sortie: str) -> str:
    """La plainte du compilateur, réduite à ce qui nomme la cause.

    MWCC préfixe chaque diagnostic d'un dièse et rappelle au-dessus la ligne
    fautive ; `###` n'annonce que l'outil. Les douze dernières lignes suffisent :
    au-delà, c'est la même faute répétée sur d'autres sites.
    """
    lignes = [l.rstrip() for l in sortie.splitlines()
              if l.startswith("#") and not l.startswith("###")]
    return "\n".join(lignes[-12:])


def recompile_et_mesure(symbole: str, unite: str) -> float | None:
    """Reconstruit l'unité puis rend l'appariement — l'objet d'avant mentirait.

    Un échec laisse sa cause dans `derniere_erreur` : mwccgap écrit déjà la
    plainte de MWCC sur son flux d'erreur, et la jeter obligeait à recompiler à
    la main pour savoir ce qui n'allait pas.
    """
    global derniere_erreur
    derniere_erreur = ""
    objet = ROOT / "build" / "src" / (unite + ".o")
    if objet.exists():
        objet.unlink()
    fait = run(["make", str(objet.relative_to(ROOT))],
               capture_output=True, text=True)
    if fait.returncode != 0:
        derniere_erreur = _diagnostic((fait.stdout or "") + (fait.stderr or ""))
        return None
    return sonde_m2c.score(symbole, unite)


def image_identique() -> bool:
    """L'image liée rend-elle les octets du disque ?"""
    if run(["make", "build"], capture_output=True, text=True).returncode != 0:
        return False
    image, reference = ROOT / "build" / "main.bin", ROOT / "rom" / "main.bin"
    if not (image.exists() and reference.exists()):
        return False
    return image.read_bytes() == reference.read_bytes()


def pose(symbole: str, unite: str) -> tuple[Path, str] | None:
    """Remet le fragment gardé à la place de sa greffe. Rend (source, avant)."""
    source = ROOT / "src" / (unite + ".cpp")
    avant = source.read_text(encoding="utf-8")
    ligne = INCLUDE_ASM % (unite, symbole)
    if ligne not in avant:
        return None
    fragment = (CORPUS / (symbole + ".cpp")).read_text(encoding="utf-8")
    ecris(source, avant.replace(ligne, fragment))
    return source, avant


def rendement(lot: list[tuple[int, str, str]]) -> int:
    """Ce que chaque idiome débloque, sans rien garder.

    La question n'est pas « cette fonction apparie-t-elle ? » mais « cet idiome
    vaut-il d'être outillé ? ». On applique donc chaque transformation seule, et
    l'on compte les fonctions qu'elle mène à 100 %.
    """
    graine = random.Random(0)
    compte: dict[str, int] = collections.Counter()
    essais: dict[str, int] = collections.Counter()
    for taille, symbole, unite in lot:
        pris = pose(symbole, unite)
        if pris is None:
            continue
        source, avant = pris
        try:
            depart = recompile_et_mesure(symbole, unite)
            if depart is None:
                continue
            texte = source.read_text(encoding="utf-8")
            bornes = affine.definition(texte, symbole)
            if bornes is None:
                continue
            debut, fin = bornes
            corps = texte[debut:fin]
            for transformation in IDIOMES:
                nom = transformation.__name__
                for variante in transformation(corps, graine):
                    if variante == corps:
                        continue
                    essais[nom] += 1
                    ecris(source, texte[:debut] + variante + texte[fin:])
                    part = recompile_et_mesure(symbole, unite)
                    if part is not None and part >= 99.999:
                        compte[nom] += 1
                        break
                ecris(source, texte)
        finally:
            ecris(source, avant)

    print("\nrendement par idiome, sur %d fonctions :" % len(lot))
    for transformation in IDIOMES:
        nom = transformation.__name__
        print("  %-24s %4d essais, %3d menees a 100 %%"
              % (nom, essais[nom], compte[nom]))
    return 0


def main(argv: list[str]) -> int:
    parseur = argparse.ArgumentParser(description=__doc__)
    parseur.add_argument("--combien", type=int, default=0,
                         help="ne traite que les N plus proches du but")
    # La tête de file est la plus facile : mesurer le rendement sur elle seule
    # le surestime, comme le trier par poids le sous-estimait. Le tirage porte
    # sur toute la file.
    parseur.add_argument("--tirage", type=int, default=0,
                         help="tire N fonctions au hasard dans la file")
    parseur.add_argument("--rendement", action="store_true",
                         help="mesure ce que chaque idiome débloque, sans garder")
    options = parseur.parse_args(argv)

    lot = candidats(options.combien)
    if options.tirage:
        lot = random.Random(1).sample(lot, min(options.tirage, len(lot)))
    if not lot:
        print("corpus vide : `make chaine` le remplit en mesurant.")
        return 0
    print("affinage : %d fonctions, %d octets"
          % (len(lot), sum(t for t, _, _ in lot)))
    if options.rendement:
        return rendement(lot)

    gagnees, depart = 0, time.time()
    for taille, symbole, unite in lot:
        pris = pose(symbole, unite)
        if pris is None:
            continue
        source, avant = pris
        garde = False
        try:
            part = recompile_et_mesure(symbole, unite)
            if part is None:
                continue
            part, garde = affine.affine(symbole, unite, part,
                                        recompile_et_mesure)
            # **objdiff ne voit qu'un objet, jamais le binaire lié.** Une
            # fonction peut y apparier a 100 % et changer pourtant l'image :
            # degreffer la derniere fonction d'une unite en retire le
            # remplissage de queue, et tout ce qui suit se decale. La moisson
            # verifie l'image depuis qu'elle a produit 546 gains faux ; cette
            # passe garde de la meme facon, elle doit la meme preuve.
            if garde and not image_identique():
                print("  l'image diverge : %s est rendue a sa greffe"
                      % symbole[:46], flush=True)
                garde = False
            if garde:
                gagnees += 1
                print("  %5d o  %-46s  gagnée" % (taille, symbole[:46]),
                      flush=True)
        finally:
            if not garde:
                ecris(source, avant)
    print("\n%d fonctions gagnées sur %d, %.1f s chacune"
          % (gagnees, len(lot), (time.time() - depart) / max(len(lot), 1)))
    print("`make ci` tranche.")
    return 0


if __name__ == "__main__":
    raise SystemExit(main(sys.argv[1:]))
