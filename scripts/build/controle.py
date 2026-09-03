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

import argparse
import re
import sys
from collections import Counter, defaultdict
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


def greffes_repetees() -> list[str]:
    """Une même ligne de greffe écrite deux fois dans un fichier.

    `greffes_en_double` compare les sources entre elles ; elle ne voit pas la
    répétition à l'intérieur d'une seule. Or c'est la signature d'une écriture
    coupée en deux : un processus tué pendant que la chaîne réécrivait une
    source y a laissé un bloc dupliqué et une ligne tronquée, et l'unité ne
    compilait plus sans qu'aucun contrôle ne le dise.
    """
    fautes = []
    for chemin in sorted((ROOT / "src").rglob("*.cpp")):
        lignes = [l for l in chemin.read_text(encoding="utf-8",
                                              errors="replace").splitlines()
                  if l.startswith("INCLUDE_ASM")]
        for ligne, compte in Counter(lignes).items():
            if compte > 1:
                fautes.append("%s répète %d fois %s"
                              % (chemin.relative_to(ROOT).as_posix(), compte,
                                 ligne.strip()[:60]))
    return fautes


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


# Le troisième champ dit si le contrôle porte sur le désassemblage, donc s'il
# suppose `make setup` à jour. Une passe qui vient de rendre des fonctions à
# l'assembleur réclame un désassemblage que le `setup` précédent avait retiré :
# la contrôler avant de le refaire rendrait 122 fautes qui n'en sont pas.
def outils_corrompus() -> list[str]:
    """Les scripts qui portent un caractere de controle.

    Un `\b` ecrit dans un patch mal echappe devient l'octet 8, et le motif
    cherche alors un retour arriere que rien ne porte : la substitution ne fait
    plus rien, en silence. Trois lignes de `sonde_m2c.py` l'ont ete pendant
    toute une moisson, et c'est ce qui a laisse passer les redefinitions de tag
    — la logique etait juste, le motif ne l'etait plus.

    Le controle est trivial et le defaut invisible a la lecture : c'est
    exactement ce qu'une verification automatique doit prendre en charge.
    """
    fautes = []
    for chemin in sorted((ROOT / "scripts").rglob("*.py")):
        octets = chemin.read_bytes()
        suspects = {o for o in octets if o < 9 or o in (11, 12) or 14 <= o < 32}
        if suspects:
            fautes.append("%s porte %s"
                          % (chemin.relative_to(ROOT).as_posix(),
                             ", ".join("l'octet %d" % o for o in sorted(suspects))))
    return fautes


def sources_desequilibrees() -> list[str]:
    """Les unités où les accolades ne se referment pas.

    La chaîne réécrit ses sources, et une substitution trop large peut mordre
    sur un corps de fonction : elle laisse alors l'unité amputée, qui ne
    compile plus. Toute fonction posée ensuite dans cette unité échoue sans
    rapport avec elle-même — 330 des 586 échecs d'une moisson venaient de
    trois unités déséquilibrées, et rien ne le disait.

    Le compte ne prouve pas que le code est bien formé — une accolade dans une
    chaîne de caractères le fausse —, mais il attrape l'amputation, qui est la
    faute que la chaîne sait commettre.
    """
    fautes = []
    for chemin in sorted((ROOT / "src").rglob("*.cpp")):
        texte = chemin.read_text(encoding="utf-8", errors="replace")
        ecart = texte.count("{") - texte.count("}")
        if ecart:
            fautes.append("%s : %+d accolade%s"
                          % (chemin.relative_to(ROOT).as_posix(), ecart,
                             "s" if abs(ecart) > 1 else ""))
    return fautes


CONTROLES = [
    ("en-têtes engendrés", entetes_manquants, False),
    ("greffes sans désassemblage", greffes_sans_desassemblage, True),
    ("greffes en double", greffes_en_double, False),
    ("greffes répétées", greffes_repetees, False),
    ("greffes hors plage", greffes_hors_plage, False),
    ("plages qui se chevauchent", plages_qui_se_chevauchent, False),
    ("sources et unités", sources_absentes, False),
    ("outils corrompus", outils_corrompus, False),
    ("accolades des sources", sources_desequilibrees, False),
]


def main(argv: list[str] | None = None) -> int:
    parseur = argparse.ArgumentParser(description=__doc__)
    parseur.add_argument("--avant-setup", action="store_true",
                         help="écarte ce qui suppose le désassemblage à jour")
    options = parseur.parse_args(argv)

    total = 0
    for nom, controle, besoin_setup in CONTROLES:
        if besoin_setup and options.avant_setup:
            continue
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
