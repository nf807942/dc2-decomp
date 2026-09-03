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


# `    ? spDC;` — m2c déclare bien la variable, mais sans savoir son type. La
# ligne est seule de son espèce : un `?` en tête de déclaration ne peut pas être
# un ternaire, et c'est ce qui permet de le traduire ici sans risque.
_LOCALE_INCONNUE = re.compile(
    r"^(\s+)\?(\d*)\s*(\**)\s*(\w+)(\s*\[[^\]]*\])?\s*;\s*$", re.M)
_LARGEUR = {"": "s32", "8": "s8", "16": "s16", "32": "s32", "64": "s64"}


def nettoie_locales(corps: str) -> str:
    """Donne un type aux locales que m2c déclare sans en connaître un.

    Sans cela, MWCC répond « expression syntax error » sur la déclaration et
    perd la fonction. La largeur, quand m2c la donne, est sûre ; à défaut, celle
    d'un registre. Un pointeur reste un pointeur, c'est la seule chose certaine.
    """
    def pose(marque: re.Match) -> str:
        marge, largeur, etoiles, nom, tableau = marque.groups()
        type_ = "void" if etoiles else _LARGEUR.get(largeur, "s32")
        return "%s%s %s%s%s;" % (marge, type_, etoiles, nom, tableau or "")

    return _LOCALE_INCONNUE.sub(pose, corps)


# `&sp40[0]` — un emplacement de pile que m2c localise sans le typer, et qu'il
# n'introduit donc jamais. MWCC répond « undefined identifier 'sp40' ».
_PILE = re.compile(r"\bsp([0-9A-Fa-f]+)\b")


def declare_les_piles(corps: str) -> str:
    """Introduit les emplacements de pile que m2c emploie sans les déclarer.

    m2c sait où vit la variable — le décalage est dans son nom — mais pas sa
    taille ni son type ; il l'écrit alors `&sp40[0]` sans jamais l'annoncer. Le
    décalage, lui, est sûr, et deux décalages consécutifs bornent le premier :
    `sp40` suivi de `sp60` occupe trente-deux octets. Le dernier n'a pas de
    borne, et reçoit la taille d'un vecteur — seize octets, l'unité du R5900.

    La disposition ainsi devinée ne sera juste que par chance, et c'est assumé :
    une fonction qui compile entre dans la mesure, où l'écart se lit et se
    corrige, là où l'absence la laissait au rebut sans le moindre chiffre.
    """
    corps_seul = corps.split("{", 1)[-1]
    offsets = sorted({int(t, 16) for t in _PILE.findall(corps_seul)})
    if not offsets:
        return corps
    deja = set(types_locaux(corps))
    manquants = [o for o in offsets if ("sp%X" % o) not in deja
                 and ("sp%x" % o) not in deja]
    if not manquants:
        return corps

    lignes = []
    for rang, decalage in enumerate(manquants):
        suivant = (manquants[rang + 1] if rang + 1 < len(manquants)
                   else decalage + 16)
        nom = "sp%X" % decalage if ("sp%X" % decalage) in corps else "sp%x" % decalage
        lignes.append("    u8 %s[0x%X];" % (nom, max(suivant - decalage, 1)))

    # Les déclarations se posent en tête de corps, où m2c met les siennes.
    ouvre = corps.find("{")
    if ouvre < 0:
        return corps
    return corps[:ouvre + 1] + "\n" + "\n".join(lignes) + corps[ouvre + 1:]


# Ce qu'un bloc de déclaration nomme, et qui ne peut l'être qu'une fois.
_TYPEDEF = re.compile(r"^typedef struct (\w+)")
_AVANT = re.compile(r"^struct (\w+);")
_FONCTION = re.compile(r'^extern "C" .*?\b(\w+)\s*\(')
# `extern "C" EventScriptArg_champs EventScriptArg;` — une donnee, non une
# fonction : sans cette cle, deux fonctions d'une meme unite la reemettent et
# MWCC repond « redefined ».
_VARIABLE = re.compile(r'^extern "C" [\w ]+ \*?(\w+)(?:\[[^\]]*\])?;')


def _cle(bloc: str) -> tuple[str, str] | None:
    """Ce que ce bloc déclare, sous une forme comparable."""
    tete = bloc.lstrip().split("\n", 1)[0]
    for motif, genre in ((_TYPEDEF, "type"), (_AVANT, "type"),
                         (_FONCTION, "fonction"),
                         (_VARIABLE, "variable")):
        marque = motif.match(tete)
        if marque:
            return genre, marque.group(1)
    return None


def _blocs(declarations: str) -> list[str]:
    """Découpe les déclarations en blocs, une structure comptant pour un."""
    rendu: list[str] = []
    courant: list[str] = []
    profondeur = 0
    for ligne in declarations.splitlines():
        courant.append(ligne)
        profondeur += ligne.count("{") - ligne.count("}")
        if profondeur <= 0 and ligne.rstrip().endswith(";"):
            rendu.append("\n".join(courant))
            courant, profondeur = [], 0
    if courant:
        rendu.append("\n".join(courant))
    return rendu


def assemble(ajoutees: list[str], declarations: str, corps: str,
             source: str, unite: str = "") -> str:
    """Le fragment à poser, sans ce que la source déclare déjà.

    **La chaîne cumule les fonctions d'une même unité**, et chacune apporte ses
    déclarations. La suivante redéclare alors les mêmes noms, souvent autrement :
    MWCC répond « illegal function overloading » — un nom `extern "C"` ne se
    surcharge pas — ou « tag redefined ». Mesuré sur les causes enregistrées :
    90 fonctions pour la première, 47 pour la seconde, soit 44 % des échecs de
    compilation restants.

    Le remède n'est pas de choisir la meilleure déclaration mais de n'en garder
    qu'une : la première posée a déjà servi à compiler ce qui l'entoure.
    """
    pris: set[tuple[str, str]] = set()
    for bloc in _blocs(source):
        cle = _cle(bloc)
        if cle:
            pris.add(cle)

    # **Une déclaration située plus bas dans l'unité reste invisible ici et
    # entre pourtant en collision.** `source` s'arrête au point de greffe, ce
    # qu'exige la question « ce nom est-il disponible pour le code au-dessus ? ».
    # Mais « ce nom est-il déjà pris ailleurs dans le fichier ? » est une autre
    # question, et c'est elle qui décide de « redeclared ». On adopte donc la
    # forme que l'unité porte en aval : une redéclaration identique est légale,
    # deux formes divergentes ne le sont pas.
    # Le relevé se fait ligne à ligne, non par blocs : une définition qui
    # précède la déclaration se referme sur une accolade, et `_blocs` les
    # agrège alors en un seul bloc dont la clé est celle de la définition.
    en_aval: dict[tuple[str, str], str] = {}
    for ligne in (unite[len(source):] if unite else "").splitlines():
        nette = ligne.strip()
        if "{" in nette or not nette.endswith(";"):
            continue
        cle = _cle(nette)
        if cle and cle not in pris:
            en_aval.setdefault(cle, nette)

    gardes = []
    for bloc in _blocs("\n".join([b for b in ajoutees + [declarations] if b])):
        cle = _cle(bloc)
        if cle is not None:
            if cle in pris:
                continue
            pris.add(cle)
            if cle in en_aval:
                gardes.append(en_aval[cle])
                continue
        gardes.append(bloc)
    return "\n".join(gardes + [corps])


# `extern "C" s32 f(RS_STACKDATA *, s32);` — ce que la déclaration attend.
_PROTO = re.compile(r'^extern "C" [^\n(]*?\b(\w+)\s*\(([^)]*)\)\s*;', re.M)
# `f()` — l'appel que m2c écrit quand il n'a vu passer aucun argument.
_APPEL_VIDE = re.compile(r"\b(\w+)\(\)")


def remplit_les_appels(declarations: str, corps: str) -> str:
    """Rend à un appel les arguments que m2c n'a pas vus passer.

    m2c écrit `GetStackInt__FP12RS_STACKDATA_00262DA0()` là où le mangling dit
    que la fonction prend un `RS_STACKDATA *`. Ce n'est pas une contradiction :
    **l'argument était déjà dans le registre**, transmis tel quel depuis
    l'appelant, et aucune instruction ne le pose au site d'appel. m2c n'a donc
    rien vu à nommer ; la source d'origine, elle, le nommait.

    MWCC répond « function call 'f()' does not match 'f(RS_STACKDATA *)' » et
    perd la fonction : première cause d'échec de compilation sur la fenêtre
    utile, 87 cas sur 278.

    Le remplissage prend les paramètres de l'appelant dans l'ordre, ce qui est
    exactement ce que le passage par registre signifie. Il ne touche qu'un appel
    *sans aucun* argument : dès qu'il en porte un, on ne sait plus lesquels
    manquent, et deviner serait changer le sens.
    """
    attendus = {nom: len([p for p in params.split(",") if p.strip()
                          and p.strip() != "void"])
                for nom, params in _PROTO.findall(declarations)}
    if not attendus:
        return corps

    entete = corps.split("\n", 1)[0]
    ouvre = entete.find("(")
    miens = []
    if ouvre > 0:
        for morceau in entete[ouvre + 1:].split(","):
            marque = re.match(r"\s*[A-Za-z_][\w ]*?\s*\**\s*(\w+)\s*\)?\s*$",
                              morceau)
            if marque:
                miens.append(marque.group(1))
    if not miens:
        return corps

    def pose(marque: re.Match) -> str:
        nom = marque.group(1)
        combien = attendus.get(nom, 0)
        if not combien or combien > len(miens):
            return marque.group(0)
        return "%s(%s)" % (nom, ", ".join(miens[:combien]))

    # La ligne d'en-tête reste hors du remplacement : elle porte la signature,
    # non un appel.
    tete, reste = corps.split("\n", 1)
    return tete + "\n" + _APPEL_VIDE.sub(pose, reste)


def renomme(texte: str, renommes: dict[str, str]) -> str:
    """Applique à un texte les renommages de structures inférées.

    Une déclaration tirée du mangling nomme le type du projet — `RS_STACKDATA *`
    —, mais le corps parle de la structure inférée que l'on a dû renommer pour
    éviter la collision. MWCC répond alors « function call 'f(RS_STACKDATA_infere
    *)' does not match 'f(RS_STACKDATA *)' ». Dans ce fragment, les deux noms
    désignent la même chose.

    **Les bornes de mot sont obligatoires** : le nom du type vit à l'intérieur du
    symbole manglé, entre le compte de caractères et les paramètres.
    """
    for ancien, neuf in renommes.items():
        texte = re.sub(r"\b%s\b" % re.escape(ancien), neuf, texte)
    return texte


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


def declarations_portees(source: str) -> dict[str, str]:
    """Les déclarations de fonction que cette unité porte déjà, par nom.

    La chaîne cumule les fonctions d'une même unité, et chacune forge ses
    déclarations pour son propre compte. Le même appelé s'y écrit alors de deux
    façons — `GetStackInt__FP12RS_STACKDATA_00262DA0()` là où la valeur était
    déjà dans le registre, `(RS_STACKDATA *, s32)` là où le mangling l'a dictée.
    Un nom `extern "C"` ne se surcharge pas : MWCC répond « illegal function
    overloading », et la fonction est perdue. Mesuré sur les causes que la
    chaîne enregistre : 45 cas sur 161 échecs de compilation, plus 20 « function
    call does not match » qui sont la même divergence vue du site d'appel.

    Écarter la nôtre quand la source en porte une ne suffisait pas : `assemble`
    ne comparait qu'à ce qui *précède* le point de greffe, une déclaration en
    aval restant invisible — et c'est bien elle qui entre en collision. On
    adopte donc la forme de la source où qu'elle soit dans le fichier : une
    redéclaration identique est légale, deux formes divergentes ne le sont pas.
    """
    portees: dict[str, str] = {}
    for bloc in _blocs(source):
        # `_blocs` referme un bloc sur un `;` : une *definition*, qui finit sur
        # une accolade, s'agrege alors a ce qui la suit. On ne retient donc que
        # ce qui est une declaration et rien d'autre — une seule ligne, aucune
        # accolade —, sans quoi l'adoption recopierait un corps de fonction.
        ligne = bloc.strip()
        cle = _cle(ligne)
        if not (cle and cle[0] == "fonction"):
            continue
        if "{" in ligne or chr(10) in ligne or not ligne.endswith(";"):
            continue
        portees.setdefault(cle[1], ligne)
    return portees
