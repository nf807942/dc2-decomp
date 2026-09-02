#!/usr/bin/env python3
"""Rendre explicites les conversions que m2c laisse implicites.

m2c déclare `s32 temp_t4;` puis écrit `temp_t4 = objet + var_t3;`, où `objet`
est un pointeur. Le C l'accepte ; MWCC, en C++, répond « illegal implicit
conversion from 'CSphidaData *' to » et perd la fonction entière.

**C'est la première cause d'échec de compilation de la chaîne** : 222 fonctions
sur les 817 diagnostiquées, 35 448 octets.

Ce n'est pas une faute de m2c. Un registre du R5900 tient une adresse ou un
entier sans les distinguer, et l'assembleur ne dit pas lequel : m2c tranche par
fonction, et se contredit d'une ligne à l'autre. La conversion se pose donc vers
le type qu'il a *lui-même* déclaré — quand les deux s'accordent déjà, le cast ne
change rien ; quand ils divergent, il dit tout haut ce que le matériel fait.

**Elle ne se pose que si un pointeur est en jeu**, d'un côté ou de l'autre.
Entre deux entiers, ou sur des flottants, un cast ne réparerait rien et pourrait
tronquer une valeur que le binaire garde entière.

Ce module vit à part de `sonde_m2c` pour une raison prosaïque : son texte est
plein de contre-obliques, et deux correctifs appliqués par heredoc les ont
transformées en octets de contrôle avant que `make controle` ne les attrape.
"""

from __future__ import annotations

import re

# `    s32 temp_t4;` ou `    struct X *temp_t4;` — une locale que m2c déclare en
# tête de fonction. L'étoile se capture à part : elle colle au nom, non au type,
# et c'est pourtant elle qui décide si la conversion se pose.
_LOCALE = re.compile(
    r"^    ((?:struct |union |const )?[A-Za-z_]\w*)\s*(\**)\s*(\w+)\s*;\s*$", re.M)
# `CSphidaData *objet, s32 arg0)` — les paramètres, lus sur la ligne d'en-tête.
_PARAM = re.compile(r"([A-Za-z_][\w ]*?[\w*])\s*\*?\s*(\w+)\s*(?:,|\))")
# `    temp_t4 = objet + var_t3;` — une affectation simple, seule sur sa ligne.
_AFFECTE = re.compile(r"^(\s+)(\w+) = ([^;]+);\s*$", re.M)


def types_locaux(corps: str) -> dict[str, str]:
    """Le type que m2c donne à chaque variable, paramètres compris.

    Les paramètres se lisent sur la première ligne, qui porte la signature ; les
    locales sur les lignes de déclaration qui la suivent. L'étoile reste
    attachée au type, car c'est elle qui décide si la conversion se pose.
    """
    trouve: dict[str, str] = {}
    for base, etoiles, nom in _LOCALE.findall(corps):
        trouve[nom] = (base + " " + etoiles).strip() if etoiles else base.strip()

    entete = corps.split("\n", 1)[0]
    ouvre = entete.find("(")
    if ouvre > 0:
        for morceau in entete[ouvre + 1:].split(","):
            marque = re.match(r"\s*([A-Za-z_][\w ]*?)\s*(\**)\s*(\w+)\s*\)?\s*$",
                              morceau)
            if marque:
                base, etoiles, nom = marque.groups()
                trouve.setdefault(nom, (base + " " + etoiles).strip())
    return trouve


# `? *unk4E4;` dans un champ, `f(s32, ?, void *)` dans un prototype : ce que m2c
# écrit quand il n'a pas tranché le type. MWCC répond « declaration syntax
# error » et perd la structure ou le prototype entier — deuxième cause d'échec
# de compilation de la chaîne, et la première en octets : 103 fonctions, 45 048.
_INTERRO_POINTEUR = re.compile(r"\?\s*\*")
_INTERRO_SEULE = re.compile(r"(?<![\w?])\?(?![\w?*])")


def nettoie_declarations(declarations: str) -> str:
    """Ôte des déclarations les `?` que m2c y laisse.

    Le remplacement ne vaut que pour les *déclarations*. Dans un corps, un `?`
    isolé est un opérateur ternaire, et le confondre avec un type inconnu
    changerait le sens du code ; ici, aucune expression ne peut apparaître.

    `? *` devient `void *` : la seule chose sûre est que c'est un pointeur. Un
    `?` seul devient `s32`, la largeur d'un registre — c'est une supposition,
    elle est dite comme telle, et `make diff` la tranche.
    """
    rendu = _INTERRO_POINTEUR.sub("void *", declarations)
    return _INTERRO_SEULE.sub("s32", rendu)


def cast_les_affectations(corps: str) -> str:
    """Pose un cast vers le type déclaré, quand un pointeur est en jeu."""
    types = types_locaux(corps)
    if not types:
        return corps
    pointeurs = {nom for nom, type_ in types.items() if "*" in type_}

    def pose(marque: re.Match) -> str:
        marge, cible, expression = marque.groups()
        vise = types.get(cible)
        if vise is None:
            return marque.group(0)
        # Un cast n'est utile que si un pointeur est en jeu : soit la cible en
        # est un, soit l'expression en nomme un.
        nommes = set(re.findall(r"[A-Za-z_]\w*", expression))
        if "*" not in vise and not (nommes & pointeurs):
            return marque.group(0)
        if expression.lstrip().startswith("(" + vise):
            return marque.group(0)
        return "%s%s = (%s) (%s);" % (marge, cible, vise, expression)

    return _AFFECTE.sub(pose, corps)
