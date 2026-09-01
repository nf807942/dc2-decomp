#!/usr/bin/env python3
"""Les fautes qu'une construction paierait cher, décelées en une demi-seconde.

    make controle          les vérifie toutes
    make ci                les vérifie, puis construit

Chacune correspond à une panne déjà vue, et chacune se lit dans le texte des
sources et de la configuration : aucune ne demande de compiler. C'est ce qui
en fait une barrière utile — huit minutes de construction pour apprendre qu'un
en-tête manque, c'est huit minutes perdues, et le message que MWCC rend alors
parle de `this` illégal, non du fichier absent.

Ce module ne remplace pas `make build`, qui reste le seul verdict sur les
octets. Il écarte ce qui n'aurait jamais dû l'atteindre.
"""

from __future__ import annotations

import re
import sys
from collections import defaultdict
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from lib.project import (ASM_DIR, INCLUDE_DIR, ROOT,  # noqa: E402
                         SRC_DIR, declared_units, functions,
                         grafted_by_source, sources)

_INCLUDE_GEN = re.compile(r'#\s*include\s+"(gen/[^"]+)"')


def entetes_manquants() -> list[str]:
    """Un en-tête engendré qu'une source inclut sans qu'il existe.

    `passe_petites.py` a laissé ce cas : les fonctions d'une classe restaient
    écrites, leur déclaration non. La construction échouait sur une erreur qui
    ne nommait pas le fichier absent.
    """
    fautes = []
    for source in sources():
        texte = source.read_text(encoding="utf-8", errors="replace")
        for nom in _INCLUDE_GEN.findall(texte):
            if not (INCLUDE_DIR / nom).exists():
                fautes.append(f"{source.relative_to(ROOT)} inclut {nom}, absent")
    return fautes


def greffes_sans_desassemblage() -> list[str]:
    """Un `INCLUDE_ASM` dont le fichier greffé n'existe pas.

    C'est la panne que laisse un découpage changé sans `make setup` : mwccgap
    s'arrête sur « File includes ASM … that does not exist », après avoir
    compilé. Le fichier se nomme d'après l'unité et le symbole, et vérifier son
    existence ne coûte rien.

    Le contrôle porte sur le désassemblage, non sur la table des symboles : le
    binaire laisse quelques adresses sans nom — `func_00100000` ouvre `crt0` —
    et ce sont bien des fonctions à greffer.
    """
    fautes = []
    for source, noms in grafted_by_source().items():
        unite = str(source.relative_to(SRC_DIR).with_suffix("")).replace("\\", "/")
        for nom in sorted(noms):
            if not (ASM_DIR / "nonmatchings" / unite / f"{nom}.s").exists():
                fautes.append(f"{unite} greffe {nom}, dont "
                              f"asm/nonmatchings/{unite}/{nom}.s n'existe pas")
    return fautes


def greffes_en_double() -> list[str]:
    """Une fonction greffée par deux sources.

    L'éditeur de liens la recevrait deux fois. C'est la panne qu'un découpage
    déplacé laissait derrière lui, et elle se compte en milliers de définitions
    multiples avant la faute de segmentation.
    """
    ou: dict[str, list[Path]] = defaultdict(list)
    for source, noms in grafted_by_source().items():
        for nom in noms:
            ou[nom].append(source)
    return [f"{nom} greffé par " + ", ".join(str(p.relative_to(ROOT)) for p in lieux)
            for nom, lieux in sorted(ou.items()) if len(lieux) > 1]


def greffes_hors_plage() -> list[str]:
    """Une fonction greffée par une unité qui ne la couvre pas.

    Le désassemblage qu'elle reprend vit sous le nom de l'autre unité : ce que
    mwccgap greffe alors n'est pas ce que le lien attend à cette adresse.
    """
    table = functions()
    plages = {nom: (bas, haut) for bas, haut, nom in declared_units()}
    fautes = []
    for source, noms in grafted_by_source().items():
        unite = str(source.relative_to(SRC_DIR).with_suffix("")).replace("\\", "/")
        borne = plages.get(unite)
        if borne is None:
            continue
        for nom in sorted(noms):
            fonction = table.get(nom)
            if fonction is not None and not borne[0] <= fonction.address < borne[1]:
                fautes.append(
                    f"{unite} greffe {nom} en 0x{fonction.address:08X}, "
                    f"hors de sa plage 0x{borne[0]:08X}-0x{borne[1]:08X}")
    return fautes


def plages_qui_se_chevauchent() -> list[str]:
    """Deux unités qui se disputent les mêmes octets."""
    plages = sorted(declared_units())
    return [f"{gauche[2]} (0x{gauche[0]:08X}-0x{gauche[1]:08X}) chevauche "
            f"{droite[2]} (0x{droite[0]:08X}-0x{droite[1]:08X})"
            for gauche, droite in zip(plages, plages[1:]) if droite[0] < gauche[1]]


def sources_absentes() -> list[str]:
    """Une unité déclarée dont la source n'existe pas, et l'inverse."""
    fautes = []
    declarees = set()
    for _bas, _haut, nom in declared_units():
        declarees.add(nom)
        if not ((SRC_DIR / f"{nom}.cpp").exists() or (SRC_DIR / f"{nom}.c").exists()):
            fautes.append(f"{nom} est déclarée dans config/units.txt, "
                          f"mais src/{nom}.cpp n'existe pas")
    for source in sources():
        nom = str(source.relative_to(SRC_DIR).with_suffix("")).replace("\\", "/")
        if nom not in declarees:
            fautes.append(f"src/{nom} n'est déclarée dans aucune ligne de "
                          f"config/units.txt : rien ne la construit")
    return fautes


CONTROLES = [
    ("en-têtes engendrés", entetes_manquants),
    ("greffes sans désassemblage", greffes_sans_desassemblage),
    ("greffes en double", greffes_en_double),
    ("greffes hors plage", greffes_hors_plage),
    ("plages qui se chevauchent", plages_qui_se_chevauchent),
    ("sources et unités", sources_absentes),
]


def main() -> int:
    total = 0
    for nom, controle in CONTROLES:
        fautes = controle()
        total += len(fautes)
        # Des marques en ASCII : la console Windows rend en cp1252, où une
        # coche n'existe pas, et le contrôle mourait sur son propre affichage.
        marque = "FAUTE" if fautes else "   ok"
        print(f"  {marque}  {nom}" + (f" ({len(fautes)})" if fautes else ""))
        for faute in fautes[:20]:
            print(f"      {faute}")
        if len(fautes) > 20:
            print(f"      … et {len(fautes) - 20} autres")

    if total:
        print(f"\n{total} fautes — la construction échouerait, ou pire, "
              f"passerait en divergeant.")
        return 1
    print("\nrien à signaler ; `make build` reste le verdict sur les octets.")
    return 0


if __name__ == "__main__":
    sys.exit(main())
