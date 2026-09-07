#!/usr/bin/env python3
"""Les réparations qu'on sait appliquer à un jet de m2c, et rien d'autre.

Chaque réparation est une fonction `(fragment, ecarts) -> [formes]`. Elle ne
mesure rien, ne garde rien, ne sait pas si elle a raison : elle propose. C'est
le banc qui tranche, et `make forge` qui compose.

**La séparation est le point.** Tant qu'une réparation vivait dans sa sonde, elle
n'était essayée que sur la classe qui l'avait fait naître, et par la main qui
l'avait écrite. Mesuré : le pas de pointeur a rendu trois fonctions dans sa
classe et **neuf de plus hors d'elle**. Une réparation n'appartient pas à sa
classe ; la classe dit seulement où la chercher.

Chacune vient d'un écart mesuré, et `docs/IDIOMES_MWCC.md` en porte la preuve et
le chiffre.
"""

from __future__ import annotations

import itertools
import re
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
sys.path.insert(0, str(Path(__file__).resolve().parent))
import affine  # noqa: E402

# --------------------------------------------------------------------------
# La lecture des écarts. **La colonne de gauche est le commerce** : objdiff
# reçoit la référence en `-1`. L'avoir lue à l'envers a retourné deux verdicts.
# --------------------------------------------------------------------------
_ACCES = re.compile(r"^ARG_MISMATCH (\w+) (\S+), (-?0x[0-9a-fA-F]+)\((\w+)\) \|"
                    r" \1 \2, (-?0x[0-9a-fA-F]+)\(\4\)$")
_CADRE = re.compile(r"^ARG_MISMATCH addiu sp, sp, -(0x[0-9a-f]+) \|")
_PRISE = re.compile(r"^ARG_MISMATCH addiu (?!sp,)\w+, sp, (0x[0-9a-f]+) \|")
_CONST = re.compile(r"^ARG_MISMATCH addiu (\w+), (\w+), (-?0x[0-9a-f]+) \|"
                    r" addiu \1, \2, (-?0x[0-9a-f]+)$")

# Les formes que m2c écrit, et qu'il faut reconnaître telles qu'il les écrit.
_BOURRE = re.compile(r"^([ \t]*(?:/\*[^*]*\*/\s*)?)char (pad[0-9A-Fa-f]+)"
                     r"\[(0x[0-9A-Fa-f]+)\];[ \t]*$", re.MULTILINE)
_DECL_PILE = re.compile(r"^([ \t]*)([A-Za-z_]\w*)\s+sp([0-9A-Fa-f]+);[ \t]*$",
                        re.MULTILINE)
_ELARGIE = re.compile(r"^[ \t]*[A-Za-z_]\w*\s+sp[0-9A-Fa-f]+\[\d+\];[ \t]*$",
                      re.MULTILINE)
_ADRESSE = re.compile(r"&(\w+)->(\w+)\b")
_TYPEE = re.compile(r"\(([A-Za-z_][\w ]*\*)\)\s*\((\w+)\s*\+\s*(\w+)\)")
_PAS = re.compile(r"^(\s*)(\w+)\s*\+=\s*(\d+|0x[0-9A-Fa-f]+);\s*$", re.MULTILINE)
_LOCALE = re.compile(r"^[ \t]*[A-Za-z_]\w*(?:\s+\w+)*\s+\**\w+"
                     r"(?:\[[^\]]*\])?;[ \t]*$", re.MULTILINE)
_GP = re.compile(r"%gp_rel\((\w+)")
_ABS = re.compile(r"%(?:hi|lo)\((\w+)")
_SYMBOLE = re.compile(r'extern "C" [^\n(]*?\b(\w+)\s*\(')


def _symbole(fragment: str) -> str:
    trouve = _SYMBOLE.search(fragment)
    return trouve.group(1) if trouve else ""


def _corps(fragment: str):
    """Les bornes de la définition, ou None. Les fragments n'ont pas de fin de ligne."""
    return affine.definition(fragment, _symbole(fragment))


# --------------------------------------------------------------------------
# Les réparations
# --------------------------------------------------------------------------

def adresse_avant_garde(fragment: str, ecarts: list[str]) -> list[str]:
    """L'adresse décalée calculée avant la garde, pour le créneau de délai.

    Neuf formes de l'expression ont été mesurées à 94,29 % au centième près sur
    `_DATAWEP__FP9SPI_STACKi` ; seule sa *place* change le résultat.
    """
    bornes = _corps(fragment)
    if bornes is None:
        return []
    debut, fin = bornes
    corps = fragment[debut:fin]
    ouvrant = corps.index("{") + 1
    tete, reste = corps[:ouvrant], corps[ouvrant:]
    garde = reste.find("if (")
    if garde < 0:
        return []
    trouve = _ADRESSE.search(reste, garde)
    if trouve is None:
        return []
    type_champ = re.search(
        r"/\*\s*0x[0-9A-Fa-f]+\s*\*/\s+([A-Za-z_]\w*)\s+%s;"
        % re.escape(trouve.group(2)), fragment)
    if type_champ is None:
        return []
    return [fragment[:debut] + tete
            + "\n    %s *next_slot;\n" % type_champ.group(1)
            + "\n    next_slot = %s;\n" % trouve.group(0)
            + reste.replace(trouve.group(0), "next_slot") + fragment[fin:]]


def pile_taille_et_ordre(fragment: str, ecarts: list[str]) -> list[str]:
    """Les emplacements de pile à la taille du commerce, dans tous les ordres.

    La taille se lit sur l'écart entre deux adresses prises, la dernière bornée
    par le cadre ; MWCC attribue la pile dans l'ordre des déclarations, et m2c
    les écrit à l'envers.
    """
    cadre, prises = None, []
    for ligne in ecarts:
        trouve = _CADRE.match(ligne)
        if trouve:
            cadre = int(trouve.group(1), 16)
        trouve = _PRISE.match(ligne)
        if trouve:
            prises.append(int(trouve.group(1), 16))
    if cadre is None or not prises:
        return []
    prises = sorted({p for p in prises if p < cadre})
    mesures = {d: (prises[i + 1] if i + 1 < len(prises) else cadre) - d
               for i, d in enumerate(prises)}
    bornes = _corps(fragment)
    if bornes is None:
        return []
    debut, fin = bornes
    corps, change = fragment[debut:fin], False
    for trouve in list(_DECL_PILE.finditer(corps)):
        taille = mesures.get(int(trouve.group(3), 16))
        if not taille or taille <= 4:
            continue
        nom = "sp" + trouve.group(3)
        corps = corps.replace(trouve.group(0), "%s%s %s[%d];"
                              % (trouve.group(1), trouve.group(2), nom,
                                 taille // 4))
        corps = re.sub(r"&%s\b" % nom, nom, corps)
        change = True
    if not change:
        return []
    large = fragment[:debut] + corps + fragment[fin:]
    blocs = list(_ELARGIE.finditer(large))
    if len(blocs) < 2:
        return [large]
    tete, queue = blocs[0].start(), blocs[-1].end()
    lignes = [b.group(0) for b in blocs]
    ordres = itertools.permutations(lignes) if len(lignes) <= 4 else \
        [tuple(lignes), tuple(reversed(lignes))]
    return [large[:tete] + "\n".join(ordre) + large[queue:] for ordre in ordres]


def pas_en_octets(fragment: str, ecarts: list[str]) -> list[str]:
    """L'arithmétique de pointeur portée en octets, `(T *) ((u8 *) p + i)`.

    m2c compte en octets et MWCC met à l'échelle du type pointé. Tous les sites
    se corrigent d'abord ensemble, puis un par un.
    """
    sites = list(_TYPEE.finditer(fragment))
    if not sites:
        return []

    def neuf(trouve):
        return "(%s) ((u8 *) %s + %s)" % (trouve.group(1).strip(),
                                          trouve.group(2), trouve.group(3))

    formes = []
    if len(sites) > 1:
        ensemble = fragment
        for trouve in sites:
            ensemble = ensemble.replace(trouve.group(0), neuf(trouve))
        formes.append(ensemble)
    for trouve in sites:
        forme = fragment.replace(trouve.group(0), neuf(trouve))
        if forme != fragment:
            formes.append(forme)
    return formes


def pas_en_elements(fragment: str, ecarts: list[str]) -> list[str]:
    """Le pas divisé par le rapport que la divergence mesure."""
    facteurs = set()
    for ligne in ecarts:
        trouve = _CONST.match(ligne)
        if not trouve:
            continue
        commerce, nous = int(trouve.group(3), 16), int(trouve.group(4), 16)
        if commerce and nous and nous % commerce == 0 and nous // commerce > 1:
            facteurs.add(nous // commerce)
    formes = []
    for facteur in sorted(facteurs):
        for trouve in _PAS.finditer(fragment):
            valeur = int(trouve.group(3), 0)
            if valeur % facteur:
                continue
            forme = fragment.replace(
                trouve.group(0), "%s%s += %d;" % (trouve.group(1),
                                                  trouve.group(2),
                                                  valeur // facteur))
            if forme != fragment:
                formes.append(forme)
    return formes


def remplissage(fragment: str, ecarts: list[str]) -> list[str]:
    """Le remplissage inféré corrigé du décalage que le diff mesure.

    m2c compte ses remplissages sans aligner : `0xF0 + 1 + 0x588` fait `0x679`,
    et le pointeur qui suit s'aligne un mot plus loin que le commerce.
    """
    couples = [(int(t.group(5), 16), int(t.group(3), 16))
               for t in (_ACCES.match(l) for l in ecarts) if t]
    if not couples:
        return []
    deltas = {commerce - nous for nous, commerce in couples}
    if len(deltas) != 1:
        return []
    delta = deltas.pop()
    if not delta:
        return []
    formes = []
    for bourre in _BOURRE.finditer(fragment):
        neuve = int(bourre.group(3), 16) + delta
        if neuve <= 0:
            continue
        forme = (fragment[:bourre.start()]
                 + "%schar %s[0x%X];" % (bourre.group(1), bourre.group(2), neuve)
                 + fragment[bourre.end():])
        if forme != fragment:
            formes.append(forme)
    return formes


def adressage(fragment: str, ecarts: list[str]) -> list[str]:
    """La taille déclarée d'une globale, qui décide de `%gp_rel` contre `%hi`.

    Une donnée hors de la fenêtre de `$gp` ne peut s'atteindre qu'en absolu ; un
    tableau de taille inconnue ne peut pas aller en `sdata`, ce qui l'y force.
    """
    sens = {}
    for ligne in ecarts:
        if " | " not in ligne:
            continue
        commerce, nous = ligne.split(" | ", 1)
        for nom in _ABS.findall(commerce):
            if "%gp_rel" in nous:
                sens[nom] = "absolu"
        for nom in _GP.findall(commerce):
            if "%hi" in nous or "%lo" in nous:
                sens[nom] = "relatif"
    formes = []
    for nom, quoi in sens.items():
        motif = re.compile(r'^(extern "C" [A-Za-z_][\w ]*\**\s*%s)\[(\d*)\];'
                           % re.escape(nom), re.MULTILINE)
        trouve = motif.search(fragment)
        if trouve is None:
            continue
        if quoi == "absolu" and trouve.group(2):
            taille = "[]"
        elif quoi == "relatif" and not trouve.group(2):
            taille = "[4]"
        else:
            continue
        formes.append(fragment[:trouve.start()] + trouve.group(1) + taille
                      + ";" + fragment[trouve.end():])
    return formes


def ordre_declarations(fragment: str, ecarts: list[str]) -> list[str]:
    """Tous les ordres du bloc de déclarations locales.

    MWCC attribue ses registres dans l'ordre où les variables lui viennent.
    C'est le domaine du permuteur, et le dépôt l'avait écarté sur 121 essais à
    4,8 secondes pièce ; à trois millisecondes, il rend.
    """
    bornes = _corps(fragment)
    if bornes is None:
        return []
    debut, fin = bornes
    corps = fragment[debut:fin]
    ouvrant = corps.index("{") + 1
    blocs = [t for t in _LOCALE.finditer(corps) if t.start() >= ouvrant]
    if len(blocs) < 2:
        return []
    contigus = [blocs[0]]
    for suivant in blocs[1:]:
        if corps[contigus[-1].end():suivant.start()].strip():
            break
        contigus.append(suivant)
    if len(contigus) < 2:
        return []
    tete, queue = contigus[0].start(), contigus[-1].end()
    lignes = [t.group(0) for t in contigus]
    # **Le plafond se paie en fonctions perdues.** Coupé à vingt-quatre ordres,
    # il laissait `CalcCenteringXY__6ClsMesFPiPi` à 98 % : ses cinq déclarations
    # font cent vingt ordres, et c'est un des quatre-vingt-seize écartés qui
    # rend 100 %. Le banc mesure une forme en trois millisecondes, donc cent
    # vingt ordres coûtent moins d'une demi-seconde ; il n'y a plus de raison de
    # couper avant que le nombre lui-même ne devienne le problème.
    #
    # **Et l'espace des sorties est bien plus petit que celui des sources** :
    # ces cent vingt ordres ne rendent que *trois* assembleurs distincts. C'est
    # ce qui rend l'énumération exhaustive praticable là où le compte des
    # permutations la ferait croire hors de portée.
    formes = []
    for ordre in itertools.permutations(lignes):
        if list(ordre) == lignes:
            continue
        formes.append(fragment[:debut] + corps[:tete] + "\n".join(ordre)
                      + corps[queue:] + fragment[fin:])
        if len(formes) >= 5039:       # sept déclarations, sept secondes au banc
            break
    return formes


# L'ordre n'a pas d'importance : le banc les mesure toutes.
REPARATIONS = [
    adresse_avant_garde,
    pile_taille_et_ordre,
    pas_en_octets,
    pas_en_elements,
    remplissage,
    adressage,
    ordre_declarations,
]
