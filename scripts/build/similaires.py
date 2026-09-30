#!/usr/bin/env python3
"""Pour chaque fonction qui reste, la fonction déjà écrite qui lui ressemble le plus.

    make similaires                          # relève tout, écrit progress/similaires.json
    make similaires ARGS="Close__8CGamePadFv"    # les voisins d'une fonction, sources à l'appui
    make similaires ARGS="--seuil 0.8"       # combien de fonctions ont un voisin assez proche

**Pourquoi.** Les projets de décompilation qui ont mis des agents au travail
(Snowboard Kids 2, Mizuchi) classent la file par ressemblance avec ce qui est
déjà apparié, non par taille ni par difficulté supposée : une fonction dont une
sœur est écrite se réécrit en suivant la sœur, idiomes de MWCC compris. Le
voisin écrit est le meilleur exemple qu'on puisse mettre sous les yeux d'un
agent, parce qu'il a *déjà* passé le compilateur.

**Mesure.** Les instructions sont réduites à leur mnémonique — registres,
immédiats et cibles d'appel n'entrent pas —, puis découpées en trigrammes. La
ressemblance est le Jaccard des deux ensembles, pondéré par le rapport des
longueurs pour qu'une fonction de quatre instructions ne soit pas jugée sœur
d'une de quatre cents qui la contient. Un mnémonique seul ignore ce que la
fonction manipule ; ce qu'il garde, c'est la forme du code, qui est ce que
MWCC a décidé.
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
from lib.project import (ROOT, functions, grafted_symbols,  # noqa: E402
                         sources)

ASM_DIR = ROOT / "asm" / "nonmatchings"
SORTIE = ROOT / "progress" / "similaires.json"

_INSTRUCTION = re.compile(r"^[ \t]*/\*[^*]*\*/[ \t]+(?:\.\w+\s+)?(\S+)",
                          re.MULTILINE)

# Les mnémoniques que le désassembleur écrit avec un suffixe de délai ou de
# probabilité de branchement : ils désignent la même opération.
_PROBABLE = re.compile(r"l$")


def mnemoniques(chemin: Path) -> list[str]:
    texte = chemin.read_text(encoding="utf-8", errors="replace")
    return [m for m in _INSTRUCTION.findall(texte)]


def trigrammes(suite: list[str]) -> set[tuple[str, str, str]]:
    if len(suite) < 3:
        return {(*suite, *([""] * (3 - len(suite))))} if suite else set()
    return {tuple(suite[i:i + 3]) for i in range(len(suite) - 2)}


def ressemblance(a: set, b: set, la: int, lb: int) -> float:
    if not a or not b:
        return 0.0
    jaccard = len(a & b) / len(a | b)
    return jaccard * (min(la, lb) / max(la, lb))


def fichiers_asm() -> dict[str, Path]:
    return {p.stem: p for p in ASM_DIR.rglob("*.s")}


def releve() -> dict:
    table = functions()
    restantes = grafted_symbols()
    asm = fichiers_asm()

    suites: dict[str, list[str]] = {}
    for nom in table:
        if nom in asm:
            suites[nom] = mnemoniques(asm[nom])

    formes = {n: trigrammes(s) for n, s in suites.items()}
    ecrites = [n for n in suites if n not in restantes and suites[n]]

    # Index inversé : trigramme → fonctions écrites qui le portent. Une
    # requête ne compare qu'à celles qui partagent au moins un trigramme.
    index: dict[tuple, list[str]] = collections.defaultdict(list)
    for n in ecrites:
        for g in formes[n]:
            index[g].append(n)

    resultat: dict[str, list] = {}
    for nom in restantes:
        if nom not in suites or not suites[nom]:
            continue
        compte: collections.Counter = collections.Counter()
        for g in formes[nom]:
            # Un trigramme porté par plus de 400 fonctions (prologue, épilogue)
            # ne distingue rien et coûte cher.
            if len(index[g]) <= 400:
                compte.update(index[g])
        candidats = [n for n, _ in compte.most_common(30)]
        notes = sorted(
            ((ressemblance(formes[nom], formes[c], len(suites[nom]),
                           len(suites[c])), c) for c in candidats),
            reverse=True)[:3]
        resultat[nom] = [{"voisin": c, "score": round(s, 3),
                          "instr": len(suites[c])}
                         for s, c in notes if s > 0.3]
    return {"fonctions": len(restantes), "ecrites": len(ecrites),
            "voisins": resultat}


# ----------------------------------------------------------------- sources --

def corps_ecrit(nom: str) -> str | None:
    """Le texte C++ d'une fonction écrite, par son nom manglé ou déclaré."""
    sym = demangle(nom)
    motifs = [re.compile(rf"^[^\n;]*\b{re.escape(nom)}\s*\(", re.MULTILINE)]
    if sym is not None and sym.cls:
        motifs.append(re.compile(
            rf"^[^\n;]*\b{re.escape(sym.cls)}::{re.escape(sym.name)}\s*\(",
            re.MULTILINE))
    for chemin in sources():
        texte = chemin.read_text(encoding="utf-8", errors="replace")
        for motif in motifs:
            m = motif.search(texte)
            if not m:
                continue
            debut = m.start()
            fin = texte.find("{", m.end())
            if fin < 0:
                continue
            profondeur = 0
            for i in range(fin, len(texte)):
                if texte[i] == "{":
                    profondeur += 1
                elif texte[i] == "}":
                    profondeur -= 1
                    if profondeur == 0:
                        return texte[debut:i + 1]
    return None


def voisins_de(nom: str, donnees: dict) -> list[dict]:
    return donnees["voisins"].get(nom, [])


def main() -> int:
    sys.stdout.reconfigure(encoding="utf-8")
    p = argparse.ArgumentParser(description=__doc__.split("\n\n")[0])
    p.add_argument("symbole", nargs="?")
    p.add_argument("--seuil", type=float, default=0.0,
                   help="compte les fonctions dont le meilleur voisin l'atteint")
    p.add_argument("--recalcule", action="store_true")
    args = p.parse_args()

    if args.recalcule or not SORTIE.exists() or not args.symbole:
        donnees = releve()
        SORTIE.write_text(json.dumps(donnees, indent=0), encoding="utf-8")
    else:
        donnees = json.loads(SORTIE.read_text(encoding="utf-8"))

    if args.symbole:
        for v in voisins_de(args.symbole, donnees):
            print(f"== {v['voisin']}  ressemblance {v['score']}  "
                  f"({v['instr']} instructions)")
            corps = corps_ecrit(v["voisin"])
            print(corps if corps else "(source introuvable)")
        return 0

    table = functions()
    meilleurs = {n: (v[0]["score"] if v else 0.0)
                 for n, v in donnees["voisins"].items()}
    print(f"{donnees['fonctions']} fonctions restantes, "
          f"{donnees['ecrites']} écrites servant de témoins")
    for seuil in (0.5, 0.7, 0.8, 0.9, 0.99):
        sel = [n for n, s in meilleurs.items() if s >= seuil]
        octets = sum(table[n].size for n in sel if n in table)
        print(f"  voisin ≥ {seuil:<4} : {len(sel):5d} fonctions, "
              f"{octets:8d} octets")
    return 0


if __name__ == "__main__":
    sys.exit(main())
