#!/usr/bin/env python3
"""Relève le décalage et la largeur de chaque champ, en suivant `this`.

    make champs
    make champs ARGS="--classe CCharacter2"
    make champs ARGS=--json

**Le mangling donne le type de `$a0`, et le désassemblage donne ce qu'on en
lit.** Pour une méthode `Foo__11CCharacter2Fi`, `$a0` est le `this` d'un
`CCharacter2 *` : tout `lw`, `lh`, `sb` ou `lwc1` à `décalage($a0)` prouve un
champ de cette classe, à ce décalage, de cette largeur, dans ce banc de
registres. Rien n'est infére : la classe vient du nom manglé, le décalage et la
largeur de l'instruction.

C'est la source que l'atlas n'a pas. `make atlas` relève ce que m2c *devine* de
chaque fonction et fusionne 369 types avec **7,9 % de contradictions** ; ici les
contradictions sont impossibles sur la largeur d'un accès, puisque l'opcode la
porte. Ce qui reste incertain est signalé, non arbitré.

**La fenêtre de suivi est conservatrice.** `this` vit dans `$a0` à l'entrée ;
un appel écrase les registres d'argument, donc on s'arrête au premier `jal` —
sauf si `this` a été recopié dans un registre sauvegardé, `daddu $s0, $a0, zero`,
ce que MWCC fait dès qu'une méthode appelle quoi que ce soit. On suit donc un
*ensemble* de registres, et l'on retire de cet ensemble tout registre qu'une
instruction réécrit. Un accès douteux n'est pas compté.
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

SORTIE = ROOT / "progress" / "champs.json"

_LIGNE = re.compile(r"^\s*/\* \w+ (\w+) \w+ \*/\s+(\S+)\s+(.*?)\s*$")
_OUVRE = re.compile(r"^glabel (\w+)\s*$")
_FERME = re.compile(r"^(?:endlabel|glabel|nmlabel) ")
# `$a0, 0x10($s0)` — un accès mémoire indexé sur un registre.
_ACCES = re.compile(r"^\$\w+,\s*(-?0x[0-9a-fA-F]+|-?\d+)\(\$(\w+)\)$")
# `$s0, $a0, $zero` — la recopie que MWCC fait de `this`.
_COPIE = re.compile(r"^\$(\w+),\s*\$(\w+),\s*\$zero$")

# La largeur et le banc que chaque opcode suppose du champ.
LARGEUR = {
    "lb": (1, "s"), "lbu": (1, "u"), "sb": (1, "?"),
    "lh": (2, "s"), "lhu": (2, "u"), "sh": (2, "?"),
    "lw": (4, "s"), "lwu": (4, "u"), "sw": (4, "?"),
    "ld": (8, "s"), "sd": (8, "?"),
    "lq": (16, "?"), "sq": (16, "?"),
    "lwc1": (4, "f"), "swc1": (4, "f"),
}
# Ce qui écrit un registre, et le retire donc de l'ensemble qui porte `this`.
ECRIT = re.compile(r"^\$(\w+),")
# Les opcodes qui n'écrivent pas leur premier opérande.
SANS_ECRITURE = frozenset("sb sh sw sd sq swc1 beq bne beqz bnez blez bgez "
                          "bltz bgtz jr jalr j jal b".split())


def _classe(symbole: str) -> str | None:
    fiche = demangle(symbole)
    return getattr(fiche, "cls", None) if fiche else None


def champs_du_fichier(chemin: Path):
    """Les (classe, décalage, largeur, banc, symbole) que ce fichier prouve."""
    rendu = []
    courant, classe, porteurs = None, None, set()
    for ligne in chemin.read_text(encoding="utf-8",
                                  errors="replace").splitlines():
        ouvre = _OUVRE.match(ligne)
        if ouvre:
            courant = ouvre.group(1)
            classe = _classe(courant)
            # `this` arrive dans `$a0`, et lui seul au premier instant.
            porteurs = {"a0"} if classe else set()
            continue
        if courant and _FERME.match(ligne):
            courant, classe, porteurs = None, None, set()
            continue
        if not classe or not porteurs:
            continue
        trouve = _LIGNE.match(ligne)
        if not trouve:
            continue
        _, opcode, operandes = trouve.groups()

        acces = _ACCES.match(operandes)
        if acces and acces.group(2) in porteurs and opcode in LARGEUR:
            decalage = int(acces.group(1), 0)
            if decalage >= 0:
                large, banc = LARGEUR[opcode]
                rendu.append((classe, decalage, large, banc, courant))

        copie = _COPIE.match(operandes)
        if copie and opcode in ("daddu", "addu", "move", "or"):
            if copie.group(2) in porteurs:
                porteurs.add(copie.group(1))
                continue
            porteurs.discard(copie.group(1))
            continue

        # Toute autre écriture retire le registre de l'ensemble : au-delà, on ne
        # sait plus ce qu'il porte, et un accès douteux ne se compte pas.
        if opcode not in SANS_ECRITURE:
            ecrit = ECRIT.match(operandes)
            if ecrit:
                porteurs.discard(ecrit.group(1))
        if opcode in ("jal", "jalr"):
            porteurs -= {"a0", "a1", "a2", "a3", "v0", "v1", "t0", "t1",
                         "t2", "t3", "t4", "t5", "t6", "t7", "t8", "t9"}
    return rendu


def releve() -> dict[str, dict]:
    par_classe: dict[str, dict[int, dict]] = collections.defaultdict(dict)
    for chemin in sorted((ROOT / "ref" / "asm" / "text").rglob("*.s")):
        for classe, decalage, large, banc, symbole in champs_du_fichier(chemin):
            champ = par_classe[classe].setdefault(
                decalage, {"largeurs": collections.Counter(),
                           "bancs": collections.Counter(), "vus": 0,
                           "ou": []})
            champ["largeurs"][large] += 1
            champ["bancs"][banc] += 1
            champ["vus"] += 1
            if len(champ["ou"]) < 3 and symbole not in champ["ou"]:
                champ["ou"].append(symbole)
    rendu = {}
    for classe, champs in par_classe.items():
        rendu[classe] = {
            "champs": {
                "0x%X" % decalage: {
                    # La plus large observée : une lecture tronquée ne dit pas
                    # la taille du champ, celle qui le lit entier si.
                    "largeur": max(fiche["largeurs"]),
                    "largeurs": {str(l): n for l, n in
                                 sorted(fiche["largeurs"].items())},
                    "flottant": fiche["bancs"].get("f", 0) > 0,
                    "vus": fiche["vus"], "ou": fiche["ou"],
                }
                for decalage, fiche in sorted(champs.items())},
            "champs_connus": len(champs),
            "dernier": "0x%X" % max(champs) if champs else None,
        }
    return rendu


def controle(rendu):
    """Le dernier champ tient-il dans la taille que l'allocation prouve ?

    **Deux derivations independantes doivent concorder.** `make tailles` lit la
    taille a l'argument d'`operator new` ; ce module lit les champs dans le flot
    de `this`. Aucune ne connait l'autre, donc leur accord vaut verification, et
    leur desaccord signale une faute a instruire — jamais a arbitrer.
    """
    fichier = ROOT / "progress" / "tailles.json"
    if not fichier.exists():
        print("lancez d'abord `make tailles ARGS=--json`")
        return 1
    tailles = json.loads(fichier.read_text(encoding="utf-8"))
    tenus, brises, absents = 0, [], 0
    for classe, fiche in rendu.items():
        prouve = tailles.get(classe, {}).get("taille")
        if not prouve or not fiche["dernier"]:
            absents += 1
            continue
        dernier = int(fiche["dernier"], 16)
        large = fiche["champs"][fiche["dernier"]]["largeur"]
        if dernier + large <= prouve:
            tenus += 1
        else:
            brises.append((classe, fiche["dernier"], large, prouve))
    print("%d classes ou les deux relevés concordent, %d en conflit,"
          " %d sans taille prouvée" % (tenus, len(brises), absents))
    for classe, dernier, large, prouve in brises:
        print("  %-28s dernier champ %s sur %d o, taille prouvée 0x%X"
              % (classe, dernier, large, prouve))
    return 0


def main(argv: list[str]) -> int:
    parseur = argparse.ArgumentParser(description=__doc__)
    parseur.add_argument("--classe")
    parseur.add_argument("--json", action="store_true")
    parseur.add_argument("--controle", action="store_true",
                         help="recoupe avec les tailles prouvées à l'allocation")
    options = parseur.parse_args(argv)

    rendu = releve()
    if options.controle:
        return controle(rendu)
    if options.json:
        SORTIE.write_text(json.dumps(rendu, ensure_ascii=False, indent=1),
                          encoding="utf-8")
        print("%d classes écrites dans %s"
              % (len(rendu), SORTIE.relative_to(ROOT)))
        return 0

    if options.classe:
        fiche = rendu.get(options.classe)
        if fiche is None:
            print("classe inconnue : %s" % options.classe)
            return 1
        print("%s — %d champs prouvés, le dernier à %s\n"
              % (options.classe, fiche["champs_connus"], fiche["dernier"]))
        for decalage, champ in list(fiche["champs"].items())[:40]:
            print("  %-8s %2d o%s  vu %3d fois   %s"
                  % (decalage, champ["largeur"],
                     " flottant" if champ["flottant"] else "         ",
                     champ["vus"], champ["ou"][0][:44]))
        return 0

    total = sum(f["champs_connus"] for f in rendu.values())
    print("%d classes, %d champs prouvés par le désassemblage\n"
          % (len(rendu), total))
    print("  %-30s %7s  %s" % ("classe", "champs", "dernier décalage"))
    for classe, fiche in sorted(rendu.items(),
                                key=lambda kv: -kv[1]["champs_connus"])[:26]:
        print("  %-30s %7d  %s"
              % (classe, fiche["champs_connus"], fiche["dernier"]))
    return 0


if __name__ == "__main__":
    raise SystemExit(main(sys.argv[1:]))
