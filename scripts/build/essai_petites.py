#!/usr/bin/env python3
"""Éprouve un plan sans le mesurer : applique, compile, dit ce qui casse.

    scripts/host/dc2 python3 scripts/build/essai_petites.py
    scripts/host/dc2 python3 scripts/build/essai_petites.py --garde

La passe complète coûte vingt minutes, dont l'essentiel en `make setup` et en
lien, pour apprendre parfois qu'une seule unité ne compile pas. Cet essai ne
répond qu'à cette question-là, en deux minutes : *le plan compile-t-il ?* Il
n'établit rien sur les octets — c'est `passe_petites.py` qui mesure et
`make build` qui tranche.

L'état est rendu tel qu'il était, sauf `--garde`. Le désassemblage n'est pas
régénéré : une fonction retirée de son `INCLUDE_ASM` laisse son `.s` en place,
que plus rien ne cite, et cela ne gêne pas la compilation d'une unité.
"""

from __future__ import annotations

import argparse
import importlib.util
import json
import os
import re
import shutil
import subprocess
import sys

RACINE = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
GEN = os.path.join(RACINE, "include", "gen")


def module(chemin: str, nom: str):
    spec = importlib.util.spec_from_file_location(nom, os.path.join(RACINE, chemin))
    charge = importlib.util.module_from_spec(spec)
    sys.modules[nom] = charge
    spec.loader.exec_module(charge)
    return charge


def compile(objets: list[str]) -> tuple[str, list[str]]:
    """Construit ces objets et rend la sortie, avec les unités qui ont échoué."""
    for objet in objets:
        chemin = os.path.join(RACINE, objet)
        if os.path.exists(chemin):
            os.remove(chemin)
    resultat = subprocess.run(["make", "-k", *objets], cwd=RACINE,
                              capture_output=True, text=True)
    sortie = resultat.stdout + resultat.stderr
    fautives = sorted({ligne.split("build/")[1].split(".o")[0]
                       for ligne in sortie.splitlines()
                       if ligne.startswith("make: ***") and "build/" in ligne})
    return sortie, fautives


# `#     140: this->field_0x1C = …` — MWCC numérote la ligne fautive.
_LIGNE = re.compile(r"^#\s+(\d+):")
# `#    File: src\game\cmenuitemuse.cpp` — et il dit de quelle source.
_FICHIER = re.compile(r"^#\s+(?:File|From):\s+(\S+)")


def designees(sortie: str, source: str, lot: list[dict], passe) -> list[dict]:
    """Les fonctions du lot que le compilateur met en cause.

    MWCC donne un numéro de ligne ; la source appliquée dit quelle fonction
    l'occupe. Le corps posé est celui du plan, donc ses lignes se comptent.
    """
    attendu = source.replace("/", os.sep).replace("\\", os.sep)
    lignes: set[int] = set()
    courant = None
    for ligne in sortie.splitlines():
        fichier = _FICHIER.match(ligne)
        if fichier:
            courant = fichier.group(1).replace("\\", os.sep).replace("/", os.sep)
            continue
        numero = _LIGNE.match(ligne)
        if numero and courant and courant.endswith(attendu):
            lignes.add(int(numero.group(1)))
    if not lignes:
        return []

    with open(os.path.join(RACINE, source), encoding="utf-8") as fichier:
        texte = fichier.read()

    coupables = []
    for fonction in lot:
        debut = texte.find(fonction["cpp"])
        if debut < 0:
            continue
        premiere = texte.count("\n", 0, debut) + 1
        derniere = premiere + fonction["cpp"].count("\n")
        if any(premiere <= numero <= derniere for numero in lignes):
            coupables.append(fonction)
    return coupables


def main(argv: list[str]) -> int:
    parseur = argparse.ArgumentParser(description=__doc__)
    parseur.add_argument("--plan", default="progress/petites.json")
    parseur.add_argument("--garde", action="store_true",
                         help="laisse l'état appliqué au lieu de le rendre")
    options = parseur.parse_args(argv)

    sys.path.insert(0, os.path.join(RACINE, "scripts"))
    passe = module("scripts/build/passe_petites.py", "passe_petites")

    with open(os.path.join(RACINE, options.plan), encoding="utf-8") as fichier:
        plan = json.load(fichier)

    # Le même tri que la passe : une classe déclarée à la main est hors
    # d'atteinte, et une fonction dont un type manque ne se pose pas.
    tenues = {classe for classe in plan["champs"]
              if not passe.deja_declaree(classe) and passe.engendrable(classe)}

    def connus(fonction: dict) -> bool:
        besoin = set(fonction.get("champs", {}))
        if fonction.get("classe"):
            besoin.add(fonction["classe"])
        return besoin <= tenues

    fonctions = [f for f in plan["fonctions"] if connus(f)]

    textes: dict[str, str] = {}
    for fonction in fonctions:
        chemin = fonction["source"]
        if chemin not in textes:
            with open(os.path.join(RACINE, chemin), encoding="utf-8") as source:
                textes[chemin] = source.read()
        fonction["greffee"] = (
            passe.INCLUDE_ASM % (fonction["chemin_asm"], fonction["symbole"])
        ) in textes[chemin]

    # L'état d'avant, y compris les en-têtes engendrés : ceux-ci se réécrivent
    # tous, et sans copie l'essai laisserait derrière lui la version du plan.
    passe.ouvre_instantane()
    garde_gen = os.path.join(passe.AVANT, "gen")
    os.makedirs(passe.AVANT, exist_ok=True)
    shutil.copytree(GEN, garde_gen, dirs_exist_ok=True)

    par_source: dict[str, list[dict]] = {}
    for fonction in fonctions:
        par_source.setdefault(fonction["source"], []).append(fonction)

    passe.ecris_entetes(passe.types_a_declarer(fonctions), fonctions)
    for source, lot in par_source.items():
        passe.applique(source, lot)

    neuves = sum(1 for f in fonctions if f["greffee"])
    print("appliqué : %d fonctions sur %d unités, dont %d neuves"
          % (len(fonctions), len(par_source), neuves))

    objets = [os.path.join("build", os.path.splitext(s)[0] + ".o")
              for s in sorted(par_source)]

    sortie, fautives = compile(objets)
    journal = os.path.join(RACINE, "progress", "essai_build.log")
    with open(journal, "w", encoding="utf-8") as fichier:
        fichier.write(sortie)

    # Une unité qui ne compile pas ne se rejette pas en bloc : le compilateur
    # nomme la ligne, la ligne nomme la fonction, et il suffit de la retirer.
    # Sans cela une seule surprise annule les vingt gains de son unité — c'est
    # ce qui avait coûté 122 fonctions sur la première passe.
    ecartees: list[tuple[str, str]] = []
    for unite in fautives:
        source = unite + ".cpp"
        lot = list(par_source.get(source, []))
        while lot:
            coupables = designees(sortie, source, lot, passe)
            if not coupables:
                # Le compilateur met en cause une ligne qu'aucune fonction du
                # lot n'occupe : on rend l'unité entière, faute de savoir qui
                # accuser. Sans ce `applique`, la source gardait le dernier état
                # posé et l'unité échouait encore, lot vide.
                ecartees.extend((source, f["symbole"]) for f in lot
                                if f.get("greffee"))
                lot = []
                passe.applique(source, lot)
                break
            lot = [f for f in lot if f not in coupables]
            ecartees.extend((source, f["symbole"]) for f in coupables)
            passe.applique(source, lot)
            sortie, encore = compile([os.path.join(
                "build", os.path.splitext(source)[0] + ".o")])
            if not encore:
                break
        par_source[source] = lot

    if ecartees:
        print("\n%d fonctions écartées, unité par unité :" % len(ecartees))
        for source, symbole in ecartees[:20]:
            print("   %-34s %s" % (source.replace("src/", ""), symbole))
        if len(ecartees) > 20:
            print("   … et %d autres" % (len(ecartees) - 20))

    if ecartees:
        # Les en-têtes suivent ce qui reste posé : garder ceux du plan entier
        # déclarerait des méthodes que plus aucune source ne définit, et des
        # champs qu'aucun corps ne justifie.
        restantes = [f for lot in par_source.values() for f in lot]
        passe.ecris_entetes(passe.types_a_declarer(restantes), restantes)

    sortie, reste = compile(objets)
    with open(journal, "w", encoding="utf-8") as fichier:
        fichier.write(sortie)
    if reste:
        print("\n%d unités résistent encore : %s" % (len(reste), ", ".join(reste)))
        print("journal : progress/essai_build.log")
    else:
        print("\ntoutes les unités compilent ; `passe_petites.py` peut mesurer.")
        fautives = []

    if not options.garde:
        for source in par_source:
            passe.applique(source, [])
        shutil.rmtree(GEN)
        shutil.copytree(garde_gen, GEN)
        print("état rendu.")

    return 1 if fautives else 0


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
