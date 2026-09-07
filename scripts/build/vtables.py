#!/usr/bin/env python3
"""Lit les tables virtuelles : le rang de chaque méthode, et qui hérite de qui.

    make vtables
    make vtables ARGS="--classe mgCObject"
    make vtables ARGS=--json

**Une table virtuelle est la seule déclaration de classe que le binaire porte en
clair.** Elle donne, dans l'ordre, les méthodes virtuelles ; et deux tables qui
partagent un préfixe de noms disent une relation d'héritage que rien d'autre ne
prouve.

Ce que cela sert, précisément. Le dépôt sait déjà que **MWCC réserve les deux
premières entrées** — la i-ième méthode déclarée est en `(i + 1) * 4` — et qu'une
classe inconnue se déclare « avec autant de virtuelles muettes qu'il faut pour
amener les siennes au bon rang ». Ce compte se lisait à la main, table par table.
Il se lit ici pour les soixante-quinze d'un coup.

L'héritage sort du même relevé, sans rien inférer : si toute méthode de la table
de A se retrouve au même rang dans celle de B, sous le même nom, alors B étend A.
Une redéfinition change le symbole mais garde le nom et le rang, ce qui est
justement la signature de l'héritage.

Rien n'est arbitré. Une classe sans base reconnue le déclare.
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

SORTIE = ROOT / "progress" / "vtables.json"

_OUVRE = re.compile(r"^dlabel (__vt__\w+)\s*$")
_FERME = re.compile(r"^enddlabel ")
_MOT = re.compile(r"^\s*/\*[^*]*\*/\s*\.word\s+(\S+)\s*$")


def _nom_de_classe(mangle: str) -> str:
    """`__vt__9mgCObject` -> `mgCObject`, la longueur du mangling retirée."""
    reste = mangle[len("__vt__"):]
    trouve = re.match(r"^(\d+)(.+)$", reste)
    if not trouve:
        return reste
    longueur, nom = int(trouve.group(1)), trouve.group(2)
    return nom[:longueur] if len(nom) >= longueur else nom


def _methode(symbole: str) -> str:
    """`SetPosition__9mgCObjectFPf` -> `SetPosition`.

    C'est le nom, non le symbole, qui se conserve d'une classe à sa dérivée :
    une redéfinition change la classe dans le mangling et garde le rang.
    """
    return symbole.split("__", 1)[0]


def relève() -> dict[str, list[str]]:
    """Chaque table, par classe, dans l'ordre de ses entrées."""
    tables: dict[str, list[str]] = {}
    for chemin in sorted((ROOT / "asm" / "data").rglob("*.s")):
        courante = None
        for ligne in chemin.read_text(encoding="utf-8",
                                      errors="replace").splitlines():
            ouvre = _OUVRE.match(ligne)
            if ouvre:
                courante = _nom_de_classe(ouvre.group(1))
                tables[courante] = []
                continue
            if courante is None:
                continue
            if _FERME.match(ligne):
                courante = None
                continue
            mot = _MOT.match(ligne)
            if mot:
                tables[courante].append(mot.group(1))
    return tables


def bases(tables):
    """Les bases candidates de chaque classe, par plus long prefixe partage.

    **Plusieurs soeurs peuvent porter le meme prefixe**, et alors rien ne
    designe laquelle est la base : cinq classes de soixante-deux entrees
    etendent `CMapPiece` sans qu'aucune n'herite des autres. Choisir la premiere
    venue serait une deduction que rien ne prouve ; on rend donc la liste, et
    seule une candidate unique vaut pour une base.
    """
    noms = {classe: [_methode(e) for e in entrees]
            for classe, entrees in tables.items()}
    rendu = {}
    for classe, suite in noms.items():
        candidates, longueur = [], 0
        for autre, prefixe in noms.items():
            if autre == classe or not prefixe or len(prefixe) >= len(suite):
                continue
            if suite[:len(prefixe)] != prefixe:
                continue
            if len(prefixe) > longueur:
                candidates, longueur = [autre], len(prefixe)
            elif len(prefixe) == longueur:
                candidates.append(autre)
        rendu[classe] = (sorted(candidates), longueur)
    return rendu


def fiches() -> dict[str, dict]:
    tables = relève()
    parents = bases(tables)
    rendu = {}
    for classe, entrees in tables.items():
        candidates, herites = parents.get(classe, ([], 0))
        parent = candidates[0] if len(candidates) == 1 else None
        # Les deux premières entrées sont réservées par MWCC : la i-ième méthode
        # déclarée est en `(i + 1) * 4`, la première en `0x08`.
        propres = [(rang, symbole) for rang, symbole in enumerate(entrees)
                   if rang >= max(herites, 2) and symbole != "0x00000000"]
        rendu[classe] = {
            "entrees": len(entrees),
            "base": parent,
            "bases_possibles": candidates if len(candidates) > 1 else [],
            "heritees": max(herites - 2, 0) if parent else 0,
            "muettes": max(herites, 2) - 2,
            "propres": [{"rang": rang, "decalage": "0x%X" % (rang * 4),
                         "symbole": symbole} for rang, symbole in propres],
        }
    return rendu


def main(argv: list[str]) -> int:
    parseur = argparse.ArgumentParser(description=__doc__)
    parseur.add_argument("--classe", help="le détail d'une seule classe")
    parseur.add_argument("--json", action="store_true")
    options = parseur.parse_args(argv)

    rendu = fiches()
    if options.json:
        SORTIE.write_text(json.dumps(rendu, ensure_ascii=False, indent=1),
                          encoding="utf-8")
        print("%d tables écrites dans %s"
              % (len(rendu), SORTIE.relative_to(ROOT)))
        return 0

    if options.classe:
        fiche = rendu.get(options.classe)
        if fiche is None:
            print("classe inconnue : %s" % options.classe)
            return 1
        print("%s — %d entrées, base %s, %d virtuelles muettes à déclarer\n"
              % (options.classe, fiche["entrees"], fiche["base"] or "aucune",
                 fiche["muettes"] + fiche["heritees"]))
        for propre in fiche["propres"]:
            print("  %2d  %-6s  %s" % (propre["rang"], propre["decalage"],
                                       propre["symbole"]))
        return 0

    avec = sum(1 for f in rendu.values() if f["base"])
    print("%d tables virtuelles, %d dont l'héritage se lit\n"
          % (len(rendu), avec))
    print("  %-26s %5s %6s  %s" % ("classe", "slots", "propres", "base"))
    for classe, fiche in sorted(rendu.items(),
                                key=lambda kv: -kv[1]["entrees"])[:28]:
        print("  %-26s %5d %6d  %s"
              % (classe, fiche["entrees"], len(fiche["propres"]),
                 fiche["base"] or ("%d candidates" % len(fiche["bases_possibles"])
                                   if fiche["bases_possibles"] else "—")))
    return 0


if __name__ == "__main__":
    raise SystemExit(main(sys.argv[1:]))
