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
# Le tableau compte pour une declaration : `u8 sp210[0x10];` n'etait pas vu,
# et `declare_les_piles` reposait alors un emplacement deja declare —
# « object 'sp210' redefined ».
_LOCALE = re.compile(
    r"^    ((?:struct |union |const )?[A-Za-z_]\w*)\s*(\**)\s*(\w+)\s*(?:\[[^\]]*\])?\s*;\s*$", re.M)
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
# Le decalage peut etre vide : m2c ecrit `&sp` tout court pour l'emplacement
# a zero, et `&sp10` pour celui a 0x10. Exiger un chiffre laissait 155
# fonctions sur « undefined identifier 'sp' », dont 83 du jeu, 49 780 octets.
_PILE = re.compile(r"\bsp([0-9A-Fa-f]*)\b")


# `CMenuFont sp210;` — un emplacement de pile que m2c type par une classe dont
# le projet n'a pas la définition.
_BASE_C = {'void', 'char', 'bool', 's8', 'u8', 's16', 'u16', 's32',
           'u32', 's64', 'u64', 'f32', 'f64', 'int', 'unsigned',
           'signed', 'long', 'short', 'float', 'double', 'struct'}

_PILE_TYPEE = re.compile(r"^(\s*)([A-Za-z_]\w*)\s+(sp[0-9A-Fa-f]+)\s*;\s*$", re.M)


def taille_les_piles_typees(corps: str, connus: set[str]) -> str:
    """Rend en octets un emplacement de pile d'un type incomplet.

    m2c ecrit `CMenuFont sp210;` : il a lu la signature d'un appel et en a tire
    le type. Mais une locale *par valeur* reclame une definition complete, et
    MWCC repond « illegal use of incomplete struct/union/class » — la fonction
    est perdue pour un objet dont elle ne lit aucun champ.

    Le decalage est dans le nom, et celui de l'emplacement suivant le borne :
    la meme regle que pour les emplacements que m2c ne declare pas du tout. Un
    tableau d'octets de la bonne taille tient la place, et l'adresse passee a
    l'appel est la meme.
    """
    decalages = sorted({int(o or "0", 16) for o in _PILE.findall(corps)})
    def borne(marque: re.Match) -> str:
        marge, type_, nom = marque.groups()
        if type_ in connus or type_ in _BASE_C:
            return marque.group(0)
        # Un emplacement dont le corps lit un champ a besoin de son type : le
        # rendre en octets ferait echouer l'acces. Ceux qu'on remplace ne sont
        # touches que par leur adresse — `&spF0` passe a un constructeur.
        if (nom + ".") in corps or (nom + "->") in corps:
            return marque.group(0)
        decalage = int(nom[2:], 16)
        suivants = [d for d in decalages if d > decalage]
        large = (suivants[0] - decalage) if suivants else 16
        return '%su8 %s[0x%X];' % (marge, nom, max(large, 1))
    return _PILE_TYPEE.sub(borne, corps)


# `(bitwise f32) sp180` — m2c reinterprete les bits d'une valeur d'un type dans
# un autre. Ce n'est pas un aveu d'echec : c'est ce que `mtc1` fait, et le C++
# l'ecrit `*(f32 *)&sp180`.
_BITWISE = re.compile(r"\(bitwise ([A-Za-z_]\w*)\s*(\**)\)\s*([A-Za-z_]\w*)\b")


def rend_les_reinterpretations(texte: str) -> str:
    """Rend en C++ les réinterprétations de bits que m2c note à sa façon.

    Sur le R5900, passer un registre entier dans un registre flottant est une
    seule instruction, `mtc1`, et elle ne convertit rien : elle recopie les
    bits. m2c le note `(bitwise f32) x`, ce qui n'est pas du C — et la chaîne
    rejetait la fonction entière pour cela, 65 fois.

    **Seul un nom se réécrit**, jamais une expression : `&` réclame une valeur
    qui a une adresse. Une réinterprétation portant sur un calcul reste donc
    telle quelle, et la fonction reste écartée — ce qu'elle était déjà.
    """
    return _BITWISE.sub(
        lambda m: '(*(%s %s*) &%s)' % (m.group(1), m.group(2), m.group(3)),
        texte)


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
    offsets = sorted({int(t or "0", 16) for t in _PILE.findall(corps_seul)})
    if not offsets:
        return corps
    deja = set(types_locaux(corps))
    # L'emplacement a zero s'appelle `sp`, non `sp0` : c'est le nom que m2c
    # emploie, et celui que la declaration doit porter.
    def nomme(decalage: int) -> str:
        return "sp" if decalage == 0 else "sp%X" % decalage

    manquants = [o for o in offsets if nomme(o) not in deja
                 and ("sp%x" % o) not in deja]
    if not manquants:
        return corps

    lignes = []
    for rang, decalage in enumerate(manquants):
        suivant = (manquants[rang + 1] if rang + 1 < len(manquants)
                   else decalage + 16)
        nom = nomme(decalage) if nomme(decalage) in corps else "sp%x" % decalage
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
    # **Une déclaration en avant n'est pas une définition.** Les ranger sous
    # la même clé faisait écarter notre `typedef struct CMenuFont { … }` parce
    # que l'unité portait un `struct CMenuFont;` : le type restait nommé et
    # incomplet, et MWCC répondait « illegal use of incomplete struct » sur la
    # première locale qui en lit un champ. C'est la même distinction que
    # `deja_vues` contre `deja_declarees`, vue du côté du rejet.
    for motif, genre in ((_TYPEDEF, "type"), (_AVANT, "avant"),
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


def _types_absents(ligne: str, amont: str) -> list[str]:
    """Les types que cette déclaration cite et que l'amont ne porte pas.

    **Mesuré et rendu.** Une greffe posée plus bas dans l'unité écrit
    `typedef struct Sphida_pointe { … }` puis `extern "C" Sphida_pointe
    *Sphida;`. Seule la seconde tient sur une ligne, donc seule elle s'adopte,
    et le fragment cite alors un type que rien ne définit encore —
    « declaration syntax error », 215 fonctions.

    Poser `struct Sphida_pointe;` devant réparait la citation et cassait
    ailleurs : **MWCC tient une coquille vide pour une déclaration que la
    définition d'en bas redéfinit**, et répond « struct/union/enum/class tag
    redefined ». Mesuré au rejugement des 711 quasi-succès : 90 d'entre eux ont
    cessé de compiler, dont 40 sur ce seul message. La déclaration en avant a
    donc été retirée.

    La fonction reste, elle nomme le manque sans prétendre le combler : c'est
    par elle qu'une réponse se mesurera, et l'énoncé du problème vaut mieux
    qu'une réparation qui coûte plus qu'elle ne rend.
    """
    tete = ligne.split("(", 1)[0]
    mots = re.findall(r"[A-Za-z_]\w*", ligne)
    declare = re.findall(r"[A-Za-z_]\w*", tete)[-1:]
    absents: list[str] = []
    for mot in mots:
        if mot in _BASE_C or mot in {"extern", "C", "const", "typedef"}:
            continue
        if mot in declare or mot in absents:
            continue
        if re.search(r"\b(?:struct|class|union)\s+%s\b" % re.escape(mot), amont):
            continue
        if re.search(r"\b%s\s*[;(]" % re.escape(mot), amont):
            continue
        absents.append(mot)
    return absents


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


# `void *temp_v0;` puis `temp_v0 + 8` : m2c compte en octets sur un pointeur
# sans type, ce que le C tolere par extension et que MWCC refuse en C++ —
# « illegal type », curseur sur la parenthese fermante. 396 fonctions,
# 106 944 octets, premiere forme de la cause.
#
# La contre-oblique se pose par `chr(92)` : ecrite en clair dans un correctif,
# elle devient l'octet 8 et le motif ne trouve plus rien, en silence.
_DECLARE_VOID = re.compile(r"\bvoid\s*\*\s*(\w+)\b")


def arithmetique_sur_void(corps: str) -> str:
    """Rend explicite le pas d'octet d'un calcul sur un pointeur sans type.

    **La conversion se pose sur l'emploi, jamais sur la declaration.** Changer
    `void *temp_v0;` en `u8 *temp_v0;` rendrait bien l'addition legale, mais
    l'affectation qui la remplit vient d'un appel qui rend `void *` — et le C++
    refuse cette conversion-la sans ecriture explicite. On deplacerait donc
    l'echec d'un message a l'autre.

    Le pas reste celui de l'octet, qui est ce que m2c veut dire : `(u8 *)` ne
    met rien a l'echelle.
    """
    noms = set(_DECLARE_VOID.findall(corps))
    for nom in sorted(noms):
        corps = re.sub(
            r"\b%s\s*([+-])(?!>)" % re.escape(nom),
            lambda trouve, nom=nom: "((u8 *) %s) %s" % (nom, trouve.group(1)),
            corps)
    return corps


def arithmetique_en_octets(corps: str) -> str:
    """Ramène au pas de l'octet un calcul sur un pointeur typé.

    **m2c compte toujours en octets** : il lit `addiu $a0, $s0, 0x40` et écrit
    `p + 0x40`. Quand il a su typer `p`, MWCC met ce 0x40 à l'échelle du type
    pointé et émet `0x2000` — le pas de la structure, cent vingt-huit fois
    l'octet. Mesuré par `make ecarts` sur les six fonctions les plus proches du
    but : **cinq divergences sur neuf sont exactement ce facteur**, et trois de
    ces fonctions ne divergent que par là. Les rapports observés sont 128, 184
    et 4 — le premier sur `SetLight`, le deuxième sur `DrawMiniMapSymbol`, le
    troisième sur un `f32 *`.

    La conversion se pose sur l'expression entière et rend le type d'origine :
    `((f32 *) ((u8 *) p + 4))`. Rendre `u8 *` tout court ferait échouer
    l'affectation qui reçoit la valeur — le C++ ne convertit pas un `u8 *` en
    `f32 *` sans qu'on l'écrive.

    L'opérande de droite se borne à un nombre ou à un nom : `p - q` entre deux
    pointeurs est une différence, déjà comptée en éléments des deux côtés, et
    la toucher changerait un calcul juste.
    """
    types = types_locaux(corps)
    pointeurs = {nom: t for nom, t in types.items() if "*" in t}
    for nom in sorted(pointeurs, key=len, reverse=True):
        type_ = " ".join(pointeurs[nom].split())
        autres = {a for a in pointeurs if a != nom}

        def pose(trouve: re.Match, nom=nom, type_=type_, autres=autres) -> str:
            signe, droite = trouve.group(1), trouve.group(2)
            if droite in autres:
                return trouve.group(0)
            return "((%s) ((u8 *) %s %s %s))" % (type_, nom, signe, droite)

        corps = re.sub(
            r"\b%s\s*([+-])(?!>)\s*(0[xX][0-9A-Fa-f]+|\d+|[A-Za-z_]\w*)\b"
            % re.escape(nom), pose, corps)
    return corps
