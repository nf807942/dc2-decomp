#!/usr/bin/env python3
"""Essaie le pas en octets à *tous* les sites, et non aux seuls qu'un motif voit.

Deux réparations traitent déjà le pas d'un pointeur : `pas_en_octets` réécrit
`(T *) (p + i)` en `(T *) ((u8 *) p + i)`, et `pas_en_elements` divise une
constante par le rapport que la divergence mesure. Toutes deux exigent une
syntaxe précise, et c'est leur limite.

**La mesure le dit sans détour.** Sur les quarante-sept fonctions que la forge a
laissées entre 99 et 100 %, la forme d'écart dominante est
`addiu r, r, K | addiu r, r, K` — vingt-neuf occurrences, toutes avec un rapport
entier entre les deux constantes, donc toutes de cette famille. Les réparations
ne s'y déclenchent pas parce que m2c y écrit l'arithmétique autrement.

C'est le même défaut que `adressage` avait avant qu'on ne l'élargisse : l'idée
était juste, le motif trop étroit. La leçon vaut d'être écrite une fois pour
toutes — **une réparation se borne par sa syntaxe, jamais par son idée**, et
c'est la syntaxe qu'il faut relâcher.

Ici on relâche jusqu'au bout : chaque addition entre un identifiant et un autre
terme devient un site candidat, et chacun donne une forme. Le banc en mesure une
en trois millisecondes ; vingt sites coûtent donc moins d'un dixième de seconde,
et il n'y a plus de raison de choisir.
"""

from __future__ import annotations

import re

# `p + i`, `p + 8`, `objet + var_a1` — une addition dont le gauche est un nom.
# Le contexte immédiat sert à éviter les faux sites : on ne touche qu'à ce qui
# est déjà entre parenthèses, donc à une sous-expression close.
_SITE = re.compile(r"\((\s*)([A-Za-z_]\w*)(\s*\+\s*)([A-Za-z_]\w*|0x[0-9A-Fa-f]+|\d+)(\s*)\)")
# `var_v0 += 4;` — le pas que m2c écrit en octets, sous toutes ses marges.
_PAS = re.compile(r"(\+=\s*)(0x[0-9A-Fa-f]+|\d+)(\s*;)")
_CONST = re.compile(r"^ARG_MISMATCH (\w+) (\w+), (\w+), (-?0x[0-9a-f]+) \|"
                    r" \1 \2, \3, (-?0x[0-9a-f]+)$")


def rapports(ecarts: list[str]) -> list[int]:
    """Les rapports entiers entre notre constante et celle du commerce."""
    rendu = []
    for ligne in ecarts:
        trouve = _CONST.match(ligne)
        if not trouve:
            continue
        commerce, nous = int(trouve.group(4), 16), int(trouve.group(5), 16)
        if commerce and nous and nous % commerce == 0 and nous // commerce > 1:
            rendu.append(nous // commerce)
    return sorted(set(rendu))


def octets_partout(fragment: str, ecarts: list[str]) -> list[str]:
    """Une forme par site d'addition, l'arithmétique portée en octets.

    La conversion se pose sur le terme de gauche et non sur l'expression
    entière : `(u8 *) p + i` garde le type du résultat là où la parenthèse
    extérieure le rend, ce que le dépôt a mesuré sur `__ct__10CEohMotherFv`.
    """
    formes = []
    sites = list(_SITE.finditer(fragment))
    for trouve in sites:
        neuf = "(%s(u8 *) %s%s%s%s)" % (trouve.group(1), trouve.group(2),
                                        trouve.group(3), trouve.group(4),
                                        trouve.group(5))
        forme = fragment[:trouve.start()] + neuf + fragment[trouve.end():]
        if forme != fragment:
            formes.append(forme)
    # Et la forme qui les corrige tous : une fonction qui parcourt deux tableaux
    # porte deux fois la même faute, et n'en corriger qu'une laisse l'autre.
    if len(sites) > 1:
        ensemble, decalage = fragment, 0
        for trouve in sites:
            neuf = "(%s(u8 *) %s%s%s%s)" % (trouve.group(1), trouve.group(2),
                                            trouve.group(3), trouve.group(4),
                                            trouve.group(5))
            debut, fin = trouve.start() + decalage, trouve.end() + decalage
            ensemble = ensemble[:debut] + neuf + ensemble[fin:]
            decalage += len(neuf) - (trouve.end() - trouve.start())
        if ensemble != fragment:
            formes.append(ensemble)
    return formes


# `    CEohMother *var_s1;` — une locale pointeur, telle que m2c la déclare.
_LOCALE_PTR = re.compile(r"^([ \t]*)([A-Za-z_][\w ]*?)\s*\*\s*(\w+);[ \t]*$",
                         re.MULTILINE)


def pointeur_en_octets(fragment: str, ecarts: list[str]) -> list[str]:
    """Retype en `u8 *` une locale que la source avance en octets.

    **C'est le type du pointeur qui multiplie, pas l'expression.**
    `__ct__10CEohMotherFv` déclare `CEohMother *var_s1` et écrit
    `var_s1 += 0x10;` — soit exactement ce que le commerce émet,
    `addiu s1, s1, 0x10`. MWCC, lui, met le pas à l'échelle du type pointé et
    sort `0x2020`, cinq cent quatorze fois plus.

    Aucune réécriture de l'expression ne peut corriger cela : le pas de la
    source est déjà juste. Il faut que le pointeur mesure un octet. Les emplois
    n'en souffrent pas, m2c les ayant déjà convertis — `(CEoh *) var_s1` et
    `(u32) var_s1` restent licites.
    """
    formes = []
    avancees = {trouve.group(1) for trouve in
                re.finditer(r"^\s*(\w+)\s*\+=\s*(?:0x[0-9A-Fa-f]+|\d+);\s*$",
                            fragment, re.MULTILINE)}
    if not avancees:
        return []
    candidates = [trouve for trouve in _LOCALE_PTR.finditer(fragment)
                  if trouve.group(3) in avancees
                  and trouve.group(2).strip() not in ("u8", "s8", "char",
                                                      "void")]
    for trouve in candidates:
        neuf = "%su8 *%s;" % (trouve.group(1), trouve.group(3))
        forme = fragment[:trouve.start()] + neuf + fragment[trouve.end():]
        if forme != fragment:
            formes.append(forme)
    if len(candidates) > 1:
        ensemble, decalage = fragment, 0
        for trouve in candidates:
            neuf = "%su8 *%s;" % (trouve.group(1), trouve.group(3))
            debut, fin = trouve.start() + decalage, trouve.end() + decalage
            ensemble = ensemble[:debut] + neuf + ensemble[fin:]
            decalage += len(neuf) - (trouve.end() - trouve.start())
        if ensemble != fragment:
            formes.append(ensemble)
    return formes


def elements_partout(fragment: str, ecarts: list[str]) -> list[str]:
    """Une forme par pas divisible, pour chaque rapport que la mesure donne."""
    formes = []
    for facteur in rapports(ecarts):
        for trouve in _PAS.finditer(fragment):
            valeur = int(trouve.group(2), 0)
            if valeur % facteur or valeur == 0:
                continue
            neuf = "%s%d%s" % (trouve.group(1), valeur // facteur,
                               trouve.group(3))
            forme = fragment[:trouve.start()] + neuf + fragment[trouve.end():]
            if forme != fragment:
                formes.append(forme)
    return formes
