#!/usr/bin/env python3
"""Écrit à m2c un contexte dont chaque type est complet par construction.

    make contexte_prouve            # écrit build/ctx.c
    make contexte_prouve ARGS=--voir

**Le dépôt a mesuré qu'un contexte partiel rend m2c moins bon que pas de
contexte du tout** : sans contexte il infère un type entier et en émet la
déclaration ; avec une version incomplète — structure vide, structure
partielle, ou même un simple `typedef` opaque — il s'en sert *et* invente un
`unkXX` que plus rien ne définit. Trente fonctions mesurées, trois compilent
sans contexte, une avec. `build/ctx.c` n'est donc plus engendré par défaut.

**Ce module vise le cas que cette mesure n'a pas couvert.** Elle portait sur des
types incomplets, forcément, puisqu'ils venaient d'inférences. Ici on n'émet
qu'une classe dont **la taille est prouvée** à un site d'allocation : la
structure se ferme sur un remplissage explicite jusqu'à cette taille, et il n'y
a donc aucun champ que m2c puisse inventer sans que rien ne le définisse.

Le compte est petit et c'est voulu : quarante classes sur les deux cent
soixante-huit dont on connaît des champs. Une classe dont la taille n'est pas
prouvée n'entre pas, parce qu'elle retomberait exactement dans le cas que la
mesure a démenti.

Rien ici n'est une inférence. `progress/champs.json` vient du flot de `this`,
`progress/tailles.json` de l'argument d'`operator new`, et les deux concordent
sur les quarante classes qu'ils partagent.
"""

from __future__ import annotations

import argparse
import json
import re
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from lib.project import ROOT  # noqa: E402

if hasattr(sys.stdout, "reconfigure"):
    sys.stdout.reconfigure(encoding="utf-8", errors="replace")

SORTIE = ROOT / "build" / "ctx.c"
CHAMPS = ROOT / "progress" / "champs.json"
TAILLES = ROOT / "progress" / "tailles.json"

# m2c lit du C déjà passé au préprocesseur : les types du projet s'y écrivent
# en clair, sans `#include`.
ENTETE = """/* Engendré par `make contexte_prouve` — ne pas modifier à la main.
 *
 * Chaque type ci-dessous a une taille prouvée par un site d'allocation, donc
 * il est complet : m2c ne peut inventer aucun champ que rien ne définirait.
 * C'est ce qui le distingue du contexte que ce dépôt a mesuré puis écarté.
 */
typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;
typedef long long s64;
typedef unsigned long long u64;
typedef float f32;
typedef double f64;
"""

TYPES = {1: "u8", 2: "s16", 4: "s32", 8: "s64", 16: "u64"}


def structures() -> list[tuple[str, str]]:
    """Une déclaration par classe dont la taille est prouvée."""
    champs = json.loads(CHAMPS.read_text(encoding="utf-8"))
    tailles = json.loads(TAILLES.read_text(encoding="utf-8"))
    rendu = []
    for classe, fiche in sorted(champs.items()):
        taille = tailles.get(classe, {}).get("taille")
        if not taille:
            continue
        lignes, position, bon = ["struct %s {" % classe], 0, True
        for cle, champ in sorted(fiche["champs"].items(),
                                 key=lambda kv: int(kv[0], 16)):
            decalage, large = int(cle, 16), champ["largeur"]
            if decalage < position:
                continue        # deux accès se chevauchent : on garde le premier
            if decalage + large > taille:
                bon = False     # un champ hors de la taille : la classe est douteuse
                break
            if decalage > position:
                lignes.append("    u8 pad_%X[0x%X];"
                              % (position, decalage - position))
            type_c = "f32" if champ.get("flottant") else TYPES.get(large, "s32")
            lignes.append("    %s field_%X;" % (type_c, decalage))
            position = decalage + large
        if not bon:
            continue
        if taille > position:
            lignes.append("    u8 pad_%X[0x%X];" % (position, taille - position))
        lignes.append("};")
        rendu.append((classe, "\n".join(lignes)))
    return rendu


def prototypes(connues: set[str]) -> list[str]:
    """Les signatures manglées des méthodes des classes que le contexte porte.

    **Une structure seule n'apprend rien à m2c.** Le premier essai n'émettait
    que les types, et le taux de compilation n'a pas bougé d'un pouce : trente
    fonctions, zéro avant, zéro après. C'est logique après coup — rien ne disait
    à m2c que `$a0` était un `CCharacter2 *`, et une structure que personne ne
    nomme ne sert à rien.

    Le mangling, lui, porte la classe et le type de chaque paramètre. Le type de
    retour n'y est pas, et il ne se devine pas : on écrit `s32`, qui est déjà ce
    que m2c suppose faute de mieux, donc l'apport est entièrement dans les
    arguments.
    """
    sys.path.insert(0, str(ROOT / "scripts"))
    from lib.mangling import demangle  # noqa: PLC0415

    fichier = ROOT / "config" / "elf_symbol_addrs.txt"
    if not fichier.exists():
        return []
    rendu, vus = [], set()
    for ligne in fichier.read_text(encoding="utf-8",
                                   errors="replace").splitlines():
        nom = ligne.split("=")[0].strip()
        if not nom or nom in vus:
            continue
        fiche = demangle(nom)
        if not fiche or fiche.cls not in connues:
            continue
        vus.add(nom)
        args = ["struct %s *" % fiche.cls] + list(fiche.params)
        rendu.append("s32 %s(%s);" % (nom, ", ".join(args)))
    return rendu


def main(argv: list[str]) -> int:
    parseur = argparse.ArgumentParser(description=__doc__)
    parseur.add_argument("--voir", action="store_true",
                         help="montre le contexte sans l'écrire")
    options = parseur.parse_args(argv)

    if not (CHAMPS.exists() and TAILLES.exists()):
        print("relevés absents : `make champs ARGS=--json` et"
              " `make tailles ARGS=--json` les produisent.")
        return 1
    blocs = structures()
    connues = {classe for classe, _ in blocs}
    signatures = prototypes(connues)
    # Un type de paramètre que le contexte ne définit pas se déclare en avant :
    # un pointeur sur type incomplet est licite, et ne pas le déclarer ferait
    # rejeter le prototype entier.
    cites = set()
    for signature in signatures:
        cites.update(re.findall(r"struct (\w+)", signature))
    avants = "\n".join("struct %s;" % nom
                       for nom in sorted(cites - connues))
    texte = (ENTETE + "\n" + avants + "\n\n"
             + "\n\n".join(b for _, b in blocs) + "\n\n"
             + "\n".join(signatures) + "\n")

    if options.voir:
        print(texte[:2000])
        print("… %d classes, %d lignes" % (len(blocs), texte.count("\n")))
        return 0

    SORTIE.parent.mkdir(parents=True, exist_ok=True)
    SORTIE.write_text(texte, encoding="utf-8")
    print("%d classes complètes et %d prototypes écrits dans %s"
          % (len(blocs), len(signatures), SORTIE.relative_to(ROOT)))
    print("m2c le lira au prochain `make decompile` ; l'effacer le désarme.")
    return 0


if __name__ == "__main__":
    raise SystemExit(main(sys.argv[1:]))
