#!/usr/bin/env python3
"""Assemble les faits prouvés en déclarations de classe utilisables.

    make entetes
    make entetes ARGS="--classe CCharacter2"
    make entetes ARGS=--ecris          # écrit sous include/prouve/

Quatre relevés indépendants disent chacun une part de la vérité, et aucun ne
dit tout :

| relevé | ce qu'il prouve | source |
|---|---|---|
| `make tailles` | la taille de la classe | l'argument d'`operator new` |
| `make champs` | le décalage et la largeur d'un champ | le flot de `this` |
| `make vtables` | le rang des méthodes virtuelles | les 75 tables |
| `make vtables` | la chaîne d'héritage | ce qu'un constructeur écrit |

Ce module les joint. **Chaque champ porte le symbole qui le prouve**, parce
qu'une déclaration sans provenance se relit comme une supposition six mois plus
tard, et que ce dépôt en a déjà payé le prix.

**Ce qui n'est pas écrit ici, et pourquoi.** Aucune méthode virtuelle n'est
déclarée : déclarer une classe polymorphe fait émettre sa table par notre objet,
et le lien la voit alors deux fois tant que le disque la porte. Posséder les
tables est un chantier à part, et le forcer ici casserait la construction.

**La sortie va sous `include/prouve/`, non sous `include/gen/`.** Les
cent quatorze en-têtes engendrés par le traducteur déterministe sont employés
par des unités qui compilent ; les écraser mettrait en jeu ce qui marche pour
un gain non mesuré. Les deux jeux coexistent le temps de mesurer.
"""

from __future__ import annotations

import argparse
import json
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from lib.project import ROOT  # noqa: E402

if hasattr(sys.stdout, "reconfigure"):
    sys.stdout.reconfigure(encoding="utf-8", errors="replace")

SORTIE = ROOT / "include" / "prouve"
CHAMPS = ROOT / "progress" / "champs.json"
TAILLES = ROOT / "progress" / "tailles.json"
VTABLES = ROOT / "progress" / "vtables.json"

# La largeur observée, et le type C qui la rend. Un `char` pour un octet : le
# dépôt compile en `-char unsigned`, donc il ne signe rien par surprise.
TYPES = {1: "u8", 2: "s16", 4: "s32", 8: "s64", 16: "u128"}


def _charge(chemin: Path) -> dict:
    return json.loads(chemin.read_text(encoding="utf-8")) if chemin.exists() \
        else {}


def declaration(classe: str, champs: dict, taille: int | None,
                vtable: dict | None) -> tuple[str, list[str]]:
    """Le texte de la structure, et ce qu'on a dû écarter."""
    lignes, ecartes = [], []
    lignes.append("/* Engendré par `make entetes` — chaque champ porte le")
    lignes.append(" * symbole qui le prouve. Ni les méthodes virtuelles ni")
    lignes.append(" * l'héritage ne sont déclarés : voir le module. */")
    if vtable and vtable.get("base"):
        lignes.append("/* Le binaire fait dériver cette classe de %s"
                      % vtable["base"])
        lignes.append(" * (%s). La disposition ci-dessous est absolue, donc"
                      % vtable.get("preuve", "preuve inconnue"))
        lignes.append(" * elle inclut déjà les champs hérités. */")
    lignes.append("struct %s {" % classe)

    position = 0
    for cle, champ in sorted(champs.items(), key=lambda kv: int(kv[0], 16)):
        decalage, large = int(cle, 16), champ["largeur"]
        if decalage < position:
            # Deux accès qui se chevauchent : l'un des deux lit un sous-champ,
            # et rien ici ne dit lequel. On garde le premier et on le signale.
            ecartes.append("0x%X chevauche 0x%X" % (decalage, position))
            continue
        if decalage > position:
            lignes.append("    char pad_%X[0x%X];"
                          % (position, decalage - position))
        type_c = "f32" if champ.get("flottant") else TYPES.get(large, "s32")
        lignes.append("    /* 0x%X */ %s field_%X;   /* %s */"
                      % (decalage, type_c, decalage,
                         (champ["ou"] or ["?"])[0][:44]))
        position = decalage + large

    if taille and taille > position:
        lignes.append("    char pad_%X[0x%X];   /* jusqu'à la taille prouvée */"
                      % (position, taille - position))
        position = taille
    elif taille and taille < position:
        ecartes.append("les champs dépassent la taille prouvée 0x%X" % taille)
    lignes.append("};")
    if taille:
        lignes.append("/* taille prouvée : 0x%X */" % taille)
    else:
        lignes.append("/* taille inconnue : au moins 0x%X */" % position)
    return "\n".join(lignes) + "\n", ecartes


def fiches() -> dict[str, dict]:
    champs = _charge(CHAMPS)
    tailles = _charge(TAILLES)
    vtables = _charge(VTABLES)
    rendu = {}
    for classe, fiche in champs.items():
        taille = tailles.get(classe, {}).get("taille")
        texte, ecartes = declaration(classe, fiche["champs"], taille,
                                     vtables.get(classe))
        rendu[classe] = {"texte": texte, "ecartes": ecartes,
                         "champs": fiche["champs_connus"], "taille": taille,
                         "couverture": None}
        if taille:
            connus = sum(c["largeur"] for c in fiche["champs"].values())
            rendu[classe]["couverture"] = 100.0 * connus / taille
    return rendu


def main(argv: list[str]) -> int:
    parseur = argparse.ArgumentParser(description=__doc__)
    parseur.add_argument("--classe")
    parseur.add_argument("--ecris", action="store_true",
                         help="écrit un en-tête par classe sous include/prouve/")
    options = parseur.parse_args(argv)

    rendu = fiches()
    if not rendu:
        print("relevés absents : `make champs ARGS=--json` les produit.")
        return 1

    if options.classe:
        fiche = rendu.get(options.classe)
        if fiche is None:
            print("classe inconnue : %s" % options.classe)
            return 1
        print(fiche["texte"])
        for ecarte in fiche["ecartes"]:
            print("/* écarté : %s */" % ecarte)
        return 0

    if options.ecris:
        SORTIE.mkdir(parents=True, exist_ok=True)
        for classe, fiche in rendu.items():
            garde = "PROUVE_%s_HPP" % classe.upper()
            (SORTIE / ("%s.hpp" % classe)).write_text(
                "#ifndef %s\n#define %s\n\n#include \"common.h\"\n\n%s\n"
                "#endif /* %s */\n" % (garde, garde, fiche["texte"], garde),
                encoding="utf-8")
        print("%d en-têtes écrits sous %s"
              % (len(rendu), SORTIE.relative_to(ROOT)))
        return 0

    avec = [f for f in rendu.values() if f["couverture"] is not None]
    print("%d classes déclarables, %d dont la taille est prouvée\n"
          % (len(rendu), len(avec)))
    print("  %-28s %7s %9s %10s  %s"
          % ("classe", "champs", "taille", "couverture", "écarts"))
    for classe, fiche in sorted(rendu.items(),
                                key=lambda kv: -kv[1]["champs"])[:24]:
        print("  %-28s %7d %9s %9s  %d"
              % (classe, fiche["champs"],
                 "0x%X" % fiche["taille"] if fiche["taille"] else "—",
                 "%.0f %%" % fiche["couverture"]
                 if fiche["couverture"] is not None else "—",
                 len(fiche["ecartes"])))
    return 0


if __name__ == "__main__":
    raise SystemExit(main(sys.argv[1:]))
