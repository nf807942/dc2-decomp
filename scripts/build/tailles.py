#!/usr/bin/env python3
"""Relève la taille exacte de chaque classe, aux sites où le jeu l'alloue.

    make tailles
    make tailles ARGS=--json

**C'est un fait, non une inférence.** m2c écrit `/* size >= 0x67C */` au bas de
chaque structure qu'il forge : il ne connaît que les champs qu'une fonction
touche, donc il ne sait jamais où la classe s'arrête. Le binaire, lui, le dit
sans ambiguïté à chaque `new` :

```
addiu   $a0, $zero, 0x10        <- sizeof(la classe)
jal     __nw__FUiP1
 daddu  $a1, $v0, $zero
...
jal     __ct__9CEohMotherFv     <- la classe, par son mangling
```

L'opérande de `$a0` est l'argument de `operator new`, et le constructeur appelé
juste après nomme la classe. Aucune autre source ne donne cette taille : ni le
désassemblage d'une méthode, qui n'en voit que les champs employés, ni l'atlas,
qui fusionne des inférences contradictoires à 7,9 %.

**Pourquoi cela compte plus qu'un idiome.** 61 % des octets qui restent vivent
dans des fonctions de plus de 512 octets, et leur jet **ne compile pas** : une
seule structure mal fermée perd la fonction entière. Aucun banc rapide n'y peut
rien, parce que le problème n'est pas la recherche mais le typage. Ce relevé est
la première pierre prouvée de ce chantier.

Rien n'est déduit ici. Une classe dont deux sites donnent deux tailles est
signalée, non arbitrée.
"""

from __future__ import annotations

import argparse
import collections
import json
import re
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from lib.mangling import demangle  # noqa: E402
from lib.project import ROOT  # noqa: E402

if hasattr(sys.stdout, "reconfigure"):
    sys.stdout.reconfigure(encoding="utf-8", errors="replace")

SORTIE = ROOT / "progress" / "tailles.json"

# `    /* 163060 00263060 10000424 */  addiu       $a0, $zero, 0x10`
_LIGNE = re.compile(r"^\s*/\* \w+ (\w+) \w+ \*/\s+(\S+)\s*(.*?)\s*$")
# `operator new`, sous ses formes manglées.
_NEW = re.compile(r"^__nw__F")
# `__ct__9CEohMotherFv` — un constructeur, qui nomme sa classe.
_CT = re.compile(r"^__(?:ct)__")
# `%hi(__vt__9CEohMother)` — la table virtuelle, qui nomme la classe *concrete*.
_VTABLE = re.compile(r"%(?:hi|lo|gp_rel)\(__vt__(\w+)")

# Combien d'instructions regarder de part et d'autre. La taille est posée juste
# avant l'appel, le constructeur suit la garde de nullité : huit et vingt
# suffisent, et élargir n'apporte que du bruit.
AVANT, APRES = 8, 20


def instructions(chemin: Path) -> list[tuple[str, str, str]]:
    """(adresse, opcode, opérandes) de chaque instruction du fichier."""
    rendu = []
    for ligne in chemin.read_text(encoding="utf-8", errors="replace").splitlines():
        trouve = _LIGNE.match(ligne)
        if trouve:
            rendu.append(trouve.groups())
    return rendu


def _nom_de_table(mangle: str) -> str:
    """`14CMenuMosSelect` -> `CMenuMosSelect`.

    Le mangling prefixe un nom de classe de sa longueur, et `__vt__` le porte
    tel quel. Le laisser rend un nom qui ne correspond a rien d'autre dans le
    depot, et deux releves du meme type ne se rejoindraient jamais.
    """
    trouve = re.match(r"^(\d+)(.+)$", mangle)
    if not trouve:
        return mangle
    longueur, reste = int(trouve.group(1)), trouve.group(2)
    return reste[:longueur] if len(reste) >= longueur else reste


def _constante(operandes: str) -> int | None:
    """`$a0, $zero, 0x10` — la constante chargée dans `$a0`."""
    trouve = re.match(r"^\$a0,\s*\$zero,\s*(-?0x[0-9a-fA-F]+|-?\d+)$", operandes)
    return int(trouve.group(1), 0) if trouve else None


def sites(chemin: Path) -> list[tuple[str, int, str]]:
    """Les (classe, taille, adresse) que ce fichier prouve."""
    suite = instructions(chemin)
    rendu = []
    for rang, (adresse, opcode, operandes) in enumerate(suite):
        if opcode != "jal" or not _NEW.match(operandes.strip()):
            continue
        taille = None
        for recul in range(rang - 1, max(rang - AVANT, -1), -1):
            if suite[recul][1] == "addiu":
                valeur = _constante(suite[recul][2])
                if valeur is not None:
                    taille = valeur
                    break
            if suite[recul][1] == "jal":
                break        # un autre appel : la constante ne nous vise plus
        if taille is None or taille <= 0:
            continue
        # **La table virtuelle nomme la classe concrète, le constructeur non.**
        # MWCC appelle d'abord le constructeur de la base, ou l'incorpore ; s'y
        # fier attribuait quatorze tailles différentes à `CBaseMenuClass`, qui
        # sont en réalité celles de quatorze dérivées. Le `%hi(__vt__X)` qui
        # suit l'allocation, lui, désigne l'objet qu'on est en train de bâtir.
        classe = None
        for avance in range(rang + 1, min(rang + APRES, len(suite))):
            trouve = _VTABLE.search(suite[avance][2])
            if trouve:
                classe = _nom_de_table(trouve.group(1))
                break
            if suite[avance][1] == "jal" and _CT.match(suite[avance][2].strip()):
                symbole = demangle(suite[avance][2].strip())
                classe = classe or (getattr(symbole, "cls", None)
                                    if symbole else None)
        if classe:
            rendu.append((classe, taille, adresse))
    return rendu


def releve() -> dict[str, dict]:
    """Tout ce que le désassemblage de référence prouve, par classe."""
    par_classe: dict[str, collections.Counter] = collections.defaultdict(
        collections.Counter)
    ou: dict[str, list[str]] = collections.defaultdict(list)
    racine = ROOT / "ref" / "asm" / "text"
    for chemin in sorted(racine.rglob("*.s")):
        for classe, taille, adresse in sites(chemin):
            par_classe[classe][taille] += 1
            ou[classe].append(adresse)
    rendu = {}
    for classe, comptes in par_classe.items():
        tailles = sorted(comptes)
        rendu[classe] = {
            "taille": tailles[0] if len(tailles) == 1 else None,
            "candidates": {hex(t): comptes[t] for t in tailles},
            "sites": len(ou[classe]),
            "ou": ou[classe][:4],
        }
    return rendu


def main(argv: list[str]) -> int:
    parseur = argparse.ArgumentParser(description=__doc__)
    parseur.add_argument("--json", action="store_true",
                         help="écrit progress/tailles.json et se tait")
    options = parseur.parse_args(argv)

    rendu = releve()
    surs = {c: f for c, f in rendu.items() if f["taille"]}
    doutes = {c: f for c, f in rendu.items() if not f["taille"]}

    if options.json:
        SORTIE.write_text(json.dumps(rendu, ensure_ascii=False, indent=1),
                          encoding="utf-8")
        print("%d classes écrites dans %s"
              % (len(rendu), SORTIE.relative_to(ROOT)))
        return 0

    print("%d classes dont le binaire prouve la taille, %d en doute\n"
          % (len(surs), len(doutes)))
    for classe, fiche in sorted(surs.items(),
                                key=lambda kv: -kv[1]["taille"])[:30]:
        print("  %-34s %7s o   %d site(s)"
              % (classe, "0x%X" % fiche["taille"], fiche["sites"]))
    if doutes:
        print("\nplusieurs tailles au même nom — à instruire, non à arbitrer :")
        for classe, fiche in sorted(doutes.items()):
            print("  %-34s %s" % (classe, fiche["candidates"]))
    return 0


if __name__ == "__main__":
    raise SystemExit(main(sys.argv[1:]))
