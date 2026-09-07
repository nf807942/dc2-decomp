#!/usr/bin/env python3
"""Range les divergences des quasi-succès par cause, et non par symptôme.

    make classes
    make classes ARGS="--classe disposition"
    make classes ARGS="--json"

`make ecarts` relève, pour chaque fonction qui compile sans apparier, les
instructions par lesquelles elle diverge, et les groupe par forme. Le compte
qui en sort mélange les causes et leurs conséquences : sur
`SetSprite__12CDamageScoreFPfiiii`, sept `sw` divergent tous de quatre octets
sur la même base — c'est *un* champ manquant dans la classe, non sept écarts.
De même, un `sd ra, 0x10(sp)` contre `sd ra, 0x30(sp)` ne dit rien de plus que
le `addiu sp, sp, K` qui le précède.

Ce module classe donc chaque fonction par la cause qui domine ses écarts, et
mesure chaque classe en octets de binaire. Une classe est une question posée au
compilateur ; ses témoins sont les fonctions sur lesquelles y répondre se
vérifie. C'est ce que la méthode du dépôt appelle changer de témoin, appliqué à
tout le corpus d'un coup.

Rien n'est compilé ici : la matière est le relevé que `make ecarts` a déjà
écrit dans `progress/chaine.json`. Le coût est d'une seconde.
"""

from __future__ import annotations

import argparse
import collections
import json
import re
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from lib.project import ROOT  # noqa: E402

# La sortie porte des accents et des flèches ; sur l'hôte Windows la console
# est en cp1252 et les refuserait. `make etat` tourne hors conteneur, celui-ci
# aussi, donc le flux se déclare ici plutôt qu'à l'appel.
if hasattr(sys.stdout, "reconfigure"):
    sys.stdout.reconfigure(encoding="utf-8", errors="replace")

ETAT = ROOT / "progress" / "chaine.json"
SORTIE = ROOT / "progress" / "classes.json"

# Un écart tel que `make ecarts` l'écrit : « GENRE <nous> | <commerce> », le
# côté absent rendu par un tiret cadratin.
_ECART = re.compile(r"^(\w+) (.*?) \| (.*)$")
# `lw a3, 0x4(a6)` — l'accès mémoire, dont le décalage porte la disposition.
_ACCES = re.compile(r"^(\w+)\s+(\S+),\s*(-?0x[0-9a-fA-F]+)\((\w+)\)$")
# `addiu sp, sp, -0x90` — le seul endroit où la taille du cadre s'écrit.
_CADRE = re.compile(r"^addiu\s+sp,\s*sp,\s*(-?0x[0-9a-fA-F]+)$")
_REGISTRE = re.compile(r"^\$?(?:[astvf]\d+|at|gp|sp|fp|ra|zero)$")
# Les branchements portent une cible que le désassemblage écrit en absolu d'un
# côté et en relatif de l'autre : leur constante ne se compare pas.
_BRANCHE = frozenset("b beq bne beqz bnez blez bgez bltz bgtz bc1t bc1f j jal "
                     "beql bnel".split())

# Les accès mémoire, par largeur et par banc de registres. Deux opcodes qui ne
# diffèrent que par là disent **un type**, non une forme de source : le champ
# que nous lisons sur seize bits, le commerce le lit sur trente-deux.
#
# Ce n'est pas pour autant la *déclaration* du champ. Mesuré sur quatorze
# témoins de la classe : treize portaient déjà la largeur du commerce dans leur
# structure, et la seule correction possible n'a pas bougé le score. La largeur
# vient donc du type de l'expression — la locale qui reçoit, le retour, ou le
# prototype de l'appelé —, et la classe reste à instruire.
_LARGEUR = {
    "lb": (1, "e"), "lbu": (1, "e"), "sb": (1, "e"),
    "lh": (2, "e"), "lhu": (2, "e"), "sh": (2, "e"),
    "lw": (4, "e"), "lwu": (4, "e"), "sw": (4, "e"),
    "ld": (8, "e"), "sd": (8, "e"),
    "lq": (16, "e"), "sq": (16, "e"),
    "lwc1": (4, "f"), "swc1": (4, "f"),
}


def _membres(texte: str) -> tuple[str, list[str]]:
    """L'opcode et ses opérandes, ou une chaîne vide pour un côté absent."""
    texte = texte.strip()
    if not texte or texte == "—":
        return "", []
    tete, _, reste = texte.partition(" ")
    return tete, [x.strip() for x in reste.split(",")] if reste else []


def _entier(texte: str) -> int | None:
    try:
        return int(texte, 0)
    except ValueError:
        return None


def cause(ecart: str) -> tuple[str, dict]:
    """La cause d'un écart, et ce qu'elle porte comme fait.

    Le classement va du plus spécifique au plus général : une divergence de
    disposition se reconnaît à son décalage mémoire, et il ne faut pas la
    laisser tomber dans le fourre-tout des constantes.
    """
    trouve = _ECART.match(ecart)
    if not trouve:
        return "illisible", {}
    genre, nous, eux = trouve.groups()
    op_n, arg_n = _membres(nous)
    op_e, arg_e = _membres(eux)

    if not op_n:
        return "manquante", {"opcode": op_e}
    if not op_e:
        return "en_trop", {"opcode": op_n}
    if op_n != op_e:
        if op_n in _LARGEUR and op_e in _LARGEUR:
            large_n, banc_n = _LARGEUR[op_n]
            large_e, banc_e = _LARGEUR[op_e]
            return "largeur", {"de": op_n, "vers": op_e,
                               "octets_nous": large_n, "octets_commerce": large_e,
                               "banc": "%s→%s" % (banc_n, banc_e)}
        return "opcode", {"de": op_n, "vers": op_e}
    if len(arg_n) != len(arg_e):
        return "arite", {"opcode": op_n}

    # La taille du cadre de pile : une seule instruction la porte, et tout ce
    # qui s'y range en dépend.
    cadre_n, cadre_e = _CADRE.match(nous), _CADRE.match(eux)
    if cadre_n and cadre_e:
        a, b = int(cadre_n.group(1), 16), int(cadre_e.group(1), 16)
        return "cadre", {"nous": a, "commerce": b, "delta": abs(b) - abs(a)}

    acces_n, acces_e = _ACCES.match(nous), _ACCES.match(eux)
    if acces_n and acces_e and acces_n.group(4) == acces_e.group(4):
        base = acces_n.group(4)
        a, b = int(acces_n.group(3), 16), int(acces_e.group(3), 16)
        if a != b:
            genre_acces = "pile" if base == "sp" else "disposition"
            return genre_acces, {"base": base, "nous": a, "commerce": b,
                                 "delta": b - a, "opcode": op_n}

    ecarts_arg = [(x, y) for x, y in zip(arg_n, arg_e) if x != y]
    if not ecarts_arg:
        return "identique", {}

    if op_n in _BRANCHE:
        return "branche", {"opcode": op_n}

    if all(_REGISTRE.match(x.lstrip("$")) and _REGISTRE.match(y.lstrip("$"))
           for x, y in ecarts_arg):
        return "registres", {"opcode": op_n}

    constantes = [(_entier(x), _entier(y)) for x, y in ecarts_arg]
    if all(a is not None and b is not None for a, b in constantes):
        a, b = constantes[0]
        rapport = None
        if a and b and b % a == 0:
            rapport = b // a
        return "constante", {"opcode": op_n, "nous": a, "commerce": b,
                             "rapport": rapport}

    return "mixte", {"opcode": op_n}


def dominante(causes: list[tuple[str, dict]]) -> tuple[str, dict]:
    """La cause à laquelle imputer la fonction entière.

    L'ordre n'est pas celui de la fréquence mais celui de la causalité : un
    cadre de pile faux déplace tout ce que la pile porte, et une disposition
    fausse déplace tous les accès à la structure. Créditer la conséquence ferait
    chercher au mauvais endroit.
    """
    par_genre = collections.Counter(g for g, _ in causes)

    if par_genre["cadre"]:
        fait = next(f for g, f in causes if g == "cadre")
        return "cadre", fait

    # Une disposition fausse se reconnaît à ce que plusieurs accès à la même
    # base divergent du même décalage. Un accès isolé ne le prouve pas : ce peut
    # être un champ voisin lu à tort.
    par_base: dict[tuple[str, int], int] = collections.Counter()
    for genre, fait in causes:
        if genre == "disposition":
            par_base[(fait["base"], fait["delta"])] += 1
    if par_base:
        (base, delta), compte = par_base.most_common(1)[0]
        if compte >= 2:
            return "disposition", {"base": base, "delta": delta,
                                   "accords": compte}

    for genre in ("largeur", "opcode", "disposition", "constante", "manquante",
                  "en_trop", "registres", "pile", "branche", "mixte"):
        if par_genre[genre]:
            return genre, next(f for g, f in causes if g == genre)
    return "indetermine", {}


# Ce que chaque classe demande comme geste, quand le dépôt le sait déjà.
CONSEIL = {
    "cadre": "la pile diverge : un registre sauvegardé de trop ou de moins."
             " `x += c` en épargne un et seize octets (IDIOMES_MWCC).",
    "largeur": "le commerce lit le champ sur une autre taille, ou dans l'autre"
               " banc de registres. **Ce n'est pas la déclaration du champ** :"
               " sur quatorze témoins, treize la portaient déjà juste. La"
               " largeur vient du type de l'expression — locale, retour, ou"
               " prototype de l'appelé.",
    "disposition": "un champ manque ou est de trop dans la classe, avant le"
                   " décalage cité. C'est un fait pour l'atlas, pas un idiome.",
    "opcode": "deux formes de source rendent deux opcodes : `s = f()` rend"
              " `daddu`, `s += f()` rend `addu`.",
    "constante": "une constante à l'échelle du type pointé : m2c compte en"
                 " octets, MWCC en éléments.",
    "registres": "allocation de registres — le domaine du permuteur, non celui"
                 " d'un idiome.",
    "manquante": "le commerce fait une chose que la source ne dit pas.",
    "en_trop": "la source dit une chose que le commerce ne fait pas.",
    "branche": "un branchement ne vise pas la même cible : graphe de contrôle.",
    "pile": "un emplacement de pile diffère sans que le cadre change.",
}


def classe_tout(etat: dict) -> dict[str, dict]:
    """Impute chaque fonction relevée à une cause, avec son poids en octets."""
    rendu: dict[str, dict] = {}
    for symbole, fiche in etat["eprouvees"].items():
        lignes = fiche.get("ecarts")
        if not lignes:
            continue
        causes = [cause(l) for l in lignes]
        genre, fait = dominante(causes)
        rendu[symbole] = {
            "classe": genre,
            "fait": fait,
            "part": fiche.get("part"),
            "taille": fiche.get("taille", 0),
            "unite": fiche.get("unite", ""),
            "ecarts": len(lignes),
            "detail": collections.Counter(g for g, _ in causes),
        }
    return rendu


def signature(genre: str, fait: dict) -> str:
    """Le trait qui distingue deux fonctions d'une même classe.

    Une classe dit où chercher ; sa signature dit quelle question poser. Les
    quarante-deux fonctions dont un `addiu` devient `daddu` posent la même
    question une seule fois, et une réponse les prend toutes.
    """
    if genre in ("opcode", "largeur"):
        return "%s → %s" % (fait.get("de", "?"), fait.get("vers", "?"))
    if genre == "cadre":
        return "%+d octets" % fait.get("delta", 0)
    if genre == "disposition":
        return "%+d octets" % fait.get("delta", 0)
    if genre == "constante":
        rapport = fait.get("rapport")
        return "rapport ×%d" % rapport if rapport else "sans rapport entier"
    return fait.get("opcode", "—")


def sous_classes(fiches: dict[str, dict], genre: str, combien: int) -> int:
    """Range une classe par signature, la plus lourde d'abord."""
    membres = {s: f for s, f in fiches.items() if f["classe"] == genre}
    if not membres:
        print("classe inconnue : %s" % genre)
        return 1
    poids: dict[str, int] = collections.Counter()
    compte: dict[str, int] = collections.Counter()
    temoins: dict[str, list] = collections.defaultdict(list)
    for symbole, fiche in membres.items():
        cle = signature(genre, fiche["fait"])
        poids[cle] += fiche["taille"]
        compte[cle] += 1
        temoins[cle].append((fiche["taille"], symbole, fiche["part"]))
    print("%s — %d fonctions, %d octets" % (genre, len(membres),
                                            sum(poids.values())))
    print(CONSEIL.get(genre, ""))
    print()
    print("  %-20s %4s %8s   témoins, le plus petit d'abord"
          % ("signature", "fn", "octets"))
    for cle, o in poids.most_common():
        print("  %-20s %4d %8d" % (cle[:20], compte[cle], o))
        for taille, symbole, part in sorted(temoins[cle])[:combien]:
            print("       %6.2f%% %5d o  %s" % (part or 0, taille, symbole))
    return 0


def rapporte(fiches: dict[str, dict], combien: int) -> None:
    poids: dict[str, int] = collections.Counter()
    compte: dict[str, int] = collections.Counter()
    ecarts: dict[str, int] = collections.Counter()
    for fiche in fiches.values():
        poids[fiche["classe"]] += fiche["taille"]
        compte[fiche["classe"]] += 1
        ecarts[fiche["classe"]] += fiche["ecarts"]

    total = sum(poids.values())
    print("%d fonctions classées, %d octets\n" % (len(fiches), total))
    print("  %-14s %5s %9s %6s %7s" % ("classe", "fn", "octets", "part", "écarts"))
    for genre, o in poids.most_common():
        print("  %-14s %5d %9d %5.1f%% %7d"
              % (genre, compte[genre], o, 100.0 * o / max(total, 1), ecarts[genre]))

    print("\ntémoins par classe — les plus petits d'abord, à corriger en premier :")
    for genre, _ in poids.most_common():
        membres = sorted(((f["taille"], s, f) for s, f in fiches.items()
                          if f["classe"] == genre))
        print("\n  %s — %s" % (genre, CONSEIL.get(genre, "")))
        for taille, symbole, fiche in membres[:combien]:
            detail = ""
            fait = fiche["fait"]
            if genre == "cadre":
                detail = "nous %d, commerce %d" % (fait["nous"], fait["commerce"])
            elif genre == "disposition":
                detail = "%s décalé de %+d%s" % (
                    fait.get("base", "?"), fait.get("delta", 0),
                    ", %d accords" % fait["accords"]
                    if "accords" in fait else " (accès isolé)")
            elif genre in ("opcode", "largeur"):
                detail = "%s → %s" % (fait["de"], fait["vers"])
                if genre == "largeur":
                    detail += "  (%d o → %d o)" % (fait["octets_nous"],
                                                   fait["octets_commerce"])
            elif genre == "constante" and fait.get("rapport"):
                detail = "rapport ×%d" % fait["rapport"]
            print("    %6.2f%% %5d o  %-44s %s"
                  % (fiche["part"] or 0, taille, symbole[:44], detail))


def main(argv: list[str]) -> int:
    parseur = argparse.ArgumentParser(description=__doc__)
    parseur.add_argument("--classe", help="n'affiche que cette classe, entière")
    parseur.add_argument("--sous", help="range une classe par signature")
    parseur.add_argument("--temoins", type=int, default=4,
                         help="témoins montrés par classe (défaut 4)")
    parseur.add_argument("--json", action="store_true",
                         help="écrit progress/classes.json et se tait")
    options = parseur.parse_args(argv)

    if not ETAT.exists():
        print("aucun relevé : `make ecarts` le produit.")
        return 1
    etat = json.loads(ETAT.read_text(encoding="utf-8"))
    fiches = classe_tout(etat)
    if not fiches:
        print("aucune fonction ne porte de relevé d'écarts ; `make ecarts`"
              " en produit.")
        return 1

    if options.json:
        SORTIE.write_text(
            json.dumps({s: {**f, "detail": dict(f["detail"])}
                        for s, f in fiches.items()},
                       ensure_ascii=False, indent=1), encoding="utf-8")
        print("%d fonctions écrites dans %s"
              % (len(fiches), SORTIE.relative_to(ROOT)))
        return 0

    if options.sous:
        return sous_classes(fiches, options.sous, options.temoins)

    if options.classe:
        membres = sorted(((f["taille"], s, f) for s, f in fiches.items()
                          if f["classe"] == options.classe))
        if not membres:
            print("classe inconnue : %s" % options.classe)
            return 1
        print("%s — %d fonctions, %d octets\n%s\n"
              % (options.classe, len(membres), sum(t for t, _, _ in membres),
                 CONSEIL.get(options.classe, "")))
        for taille, symbole, fiche in membres:
            print("  %6.2f%% %5d o  %-46s %-22s %s"
                  % (fiche["part"] or 0, taille, symbole[:46],
                     fiche["unite"][:22], fiche["fait"]))
        return 0

    rapporte(fiches, options.temoins)
    return 0


if __name__ == "__main__":
    raise SystemExit(main(sys.argv[1:]))
