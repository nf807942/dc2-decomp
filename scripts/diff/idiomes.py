#!/usr/bin/env python3
"""Les transformations que le permuteur tire d'idiomes mesurés.

`permute.py` cherche à l'aveugle : ses transformations ne prétendent rien du
compilateur, seul le score les départage. Celles d'ici sont d'une autre nature —
chacune vient d'une forme dont on a *mesuré* qu'elle change les octets, sur une
fonction nommée et avec son chiffre. Elles vivent à part pour cette raison :
quand l'une d'elles paie, elle confirme un idiome ; quand une transformation
aveugle paie, elle ne dit rien.

Chacune rend la liste des variantes qu'elle sait tirer d'un texte, comme les
autres, et `permute.py` les prend en premier — une correction d'idiome a plus de
chances qu'un tirage au sort.
"""

from __future__ import annotations

import random
import re

# Une accolade fermante au même niveau que celle qui ouvre : `permute.py` a la
# même fonction, mais l'importer d'ici créerait un cycle.
def brace_fermante(text: str, ouvrant: int) -> int | None:
    profondeur = 0
    for index in range(ouvrant, len(text)):
        if text[index] == "{":
            profondeur += 1
        elif text[index] == "}":
            profondeur -= 1
            if profondeur == 0:
                return index
    return None


def compose_assignment(text: str, _rng: random.Random) -> list[str]:
    """`x = f();` devient `x += f();` quand `x` vient d'être mis à zéro.

    Les deux formes calculent la même chose, et MWCC ne les rend pas pareil :
    `s += f()` donne `addu s0, s0, v0`, `s = f()` donne `daddu s0, v0, zero`.
    Mesuré sur `CGameDataUsed::DeleteItem_Local` : 92,76 % contre 93,98 %.
    """
    out = []
    for match in re.finditer(r"^(\s*)(\w+) = ([^;=][^;]*);$", text, re.MULTILINE):
        indent, cible, expression = match.groups()
        # La règle ne vaut que si la cible est nulle à cet endroit : sans quoi
        # les deux formes cesseraient de calculer la même chose.
        if not re.search(r"\b%s = 0;" % re.escape(cible), text[:match.start()]):
            continue
        out.append(text[:match.start()]
                   + "%s%s += %s;" % (indent, cible, expression)
                   + text[match.end():])
    for match in re.finditer(r"^(\s*)(\w+) \+= ([^;]*);$", text, re.MULTILINE):
        indent, cible, expression = match.groups()
        out.append(text[:match.start()]
                   + "%s%s = %s;" % (indent, cible, expression)
                   + text[match.end():])
    return out


def early_return_from_guard(text: str, _rng: random.Random) -> list[str]:
    """Sort le corps d'un `if` en inversant sa garde, et redouble la sortie.

    `if (c) { corps }` suivi d'un `return X;` final devient
    `if (!(c)) { return X; } corps`. Le commerce écrit alors un `b` vers la fin
    de fonction avec sa valeur dans le créneau de délai, là où une sortie unique
    donne un branchement direct. Mesuré sur `CScene::SearchCharaTexb` : 93,33 %
    avec une seule sortie, 100 % avec deux.
    """
    fin = re.search(r"\n(\s*)(return [^;]+;)\s*\n\}\s*$", text)
    if fin is None:
        return []
    sortie = fin.group(2)

    out = []
    for garde in re.finditer(r"^(\s*)if \(([^\n]+)\) \{$", text, re.MULTILINE):
        ouvrant = text.index("{", garde.start())
        fermant = brace_fermante(text, ouvrant)
        if fermant is None or fermant > fin.start():
            continue
        indent, condition = garde.group(1), garde.group(2)
        corps = text[ouvrant + 1:fermant].strip("\n")
        # Le corps remonte d'un niveau : ce qui vivait dans le `if` devient la
        # suite de la fonction.
        remonte = "\n".join(ligne[4:] if ligne.startswith("    ") else ligne
                            for ligne in corps.splitlines())
        out.append(
            text[:garde.start()]
            + "%sif (!(%s)) {\n%s    %s\n%s}\n%s"
            % (indent, condition, indent, sortie, indent, remonte)
            + text[fermant + 1:])
    return out


def rotate_loop_body(text: str, _rng: random.Random) -> list[str]:
    """Passe la dernière instruction d'un corps de boucle en tête, et l'inverse.

    m2c sort volontiers d'une boucle le calcul qui l'ouvre : il pose `j = 8;`
    avant, puis `j = i + 8;` en queue de corps. Le commerce rend `addiu s2, s1,
    0x8` à chaque tour, ce qui est la forme où le calcul vit en tête. Mesuré sur
    `CScene::SearchCharaTexb`.
    """
    out = []
    entetes = re.finditer(
        r"^(\s*)(?:do|while \([^\n]*\)|for \([^\n]*\)) \{$", text, re.MULTILINE)
    for tete in entetes:
        ouvrant = text.index("{", tete.start())
        fermant = brace_fermante(text, ouvrant)
        if fermant is None:
            continue
        # L'indentation de l'accolade fermante se garde à part : la compter
        # comme une ligne du corps laisserait une ligne blanche à sa place.
        contenu = text[ouvrant + 1:fermant].strip("\n")
        queue = re.search(r"\n([ \t]*)$", contenu)
        marge = queue.group(1) if queue else ""
        lignes = contenu[:queue.start()].splitlines() if queue \
            else contenu.splitlines()

        # Une instruction simple seulement : déplacer un bloc changerait le sens.
        simples = [rang for rang, ligne in enumerate(lignes)
                   if ligne.strip().endswith(";")
                   and "{" not in ligne and "}" not in ligne]
        if len(lignes) < 2 or not simples:
            continue
        for depart, arrivee in ((simples[-1], 0), (simples[0], len(lignes) - 1)):
            if depart == arrivee:
                continue
            bouge = list(lignes)
            bouge.insert(arrivee, bouge.pop(depart))
            out.append(text[:ouvrant + 1] + "\n" + "\n".join(bouge) + "\n"
                       + marge + text[fermant:])
    return out


# Les transformations d'idiome passent avant les aveugles : une correction dont
# on connaît la raison a plus de chances qu'un tirage au sort, et son succès
# apprend quelque chose.
IDIOMES = [
    compose_assignment,
    early_return_from_guard,
    rotate_loop_body,
]
