#!/usr/bin/env python3
"""Mesure ce que m2c fait seul : combien compile, et à quel point ça apparie.

    scripts/host/dc2 python3 scripts/diff/sonde_m2c.py --combien 20
    scripts/host/dc2 python3 scripts/diff/sonde_m2c.py --mini 400 --maxi 900

La question est chiffrée, et le plan de la chaîne en dépend : *quelle part du
chemin m2c fait-il seul ?* Si sa sortie ne compile pas neuf fois sur dix, une
chaîne qui l'enchaîne à un permuteur n'a pas de sens ; si elle apparie souvent
d'emblée, le permuteur n'est qu'un rattrapage.

La sonde n'écrit rien de durable : chaque unité est rendue telle qu'elle était.

**Le raccourci qu'elle prend, et sa réserve.** Une méthode est déclarée
`extern "C"` sous son nom manglé, `this` devenant un paramètre ordinaire. Le
symbole émis est alors exactement celui du disque, sans avoir à déclarer la
classe ni sa table virtuelle. C'est l'ABI d'une méthode non virtuelle, mais le
dépôt a déjà mesuré qu'un constructeur de classe polymorphe n'ordonne pas ses
constantes flottantes comme une fonction libre : ce que la sonde mesure est
donc un plancher, pas un plafond.
"""

from __future__ import annotations

import argparse
import json
import random
import re
import subprocess
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from lib.project import (ROOT, functions, grafted_by_source,  # noqa: E402
                         run, unit_of)
sys.path.insert(0, str(Path(__file__).resolve().parent))
from conversions import (cast_les_affectations,  # noqa: E402
                         assemble, declare_les_piles, nettoie_declarations,
                         declarations_portees, remplit_les_appels, renomme,
                         nettoie_locales)

# `typedef struct X {` … `} X;` — la structure que m2c infère d'un pointeur.
# m2c fait suivre l'accolade fermante d'un commentaire de taille — `} X;
# /* size >= 0x48 */` —, que la fin de ligne doit donc admettre.
_STRUCT = re.compile(r"^typedef struct .*?^\} \w+;[^\n]*$", re.MULTILINE | re.DOTALL)
# `? f(...); /* extern */` — un appel dont m2c ignore le type de retour.
_EXTERN = re.compile(
    r"^(\S+) ([A-Za-z_]\w*)\((.*?)\);\s*/\* (?:extern|static) \*/$", re.MULTILINE)
# L'en-tête de la fonction rendue, dont le nom est le symbole manglé.
# `\S+ ` ne voyait pas un retour pointeur : m2c ecrit `void *Nom(`, l'asterisque
# collee au nom, et le motif cherchait alors un symbole commencant par `*`. Les
# 134 « sortie illisible » de la moisson etaient exactement les fonctions a
# retour pointeur, jamais tentees une seule fois.
_ENTETE = re.compile(r"^([A-Za-z_]\w*\s*\**)\s*(%s)\((.*?)\) \{$", re.MULTILINE)

INCLUDE_ASM = 'INCLUDE_ASM("nonmatchings/%s", %s);'

# Ce que m2c dit d'un champ qu'il ne type pas : rien, ou sa largeur.
_LARGEUR_INCONNUE = {"": "char", "8": "s8", "16": "s16",
                     "32": "s32", "64": "s64"}

# `typedef struct CColPrim {` — le nom que la structure inférée porte.
_NOM_STRUCT = re.compile(r"^typedef struct (\w+)")
# Ce qui n'est pas un type nommé du jeu, et ne se déclare donc pas en avant.
_BASE = {"void", "char", "bool", "s8", "u8", "s16", "u16", "s32", "u32",
         "s64", "u64", "f32", "f64", "int", "unsigned", "signed", "long",
         "short", "float", "double", "struct", "const", "static", "extern",
         "return", "sizeof", "typedef"}
_DECLARE = re.compile(r"\b(?:class|struct)\s+(\w+)\s*(?::|\{)")
_INCLUDE = re.compile(r'^#\s*include\s+"([^"]+)"', re.MULTILINE)


def deja_vues(unite: str) -> set[str]:
    """Les types que cette unité voit déjà déclarés.

    La question porte sur ce que l'unité inclut, non sur le dépôt entier : un
    type déclaré dans un en-tête qu'elle n'inclut pas lui reste inconnu, et
    écarter la structure que m2c en donne la laisserait sans rien — c'est ce
    qui avait fait retomber à zéro la seule fonction qui appariait.
    """
    return _parcourt(unite, _avec_champs)


def deja_declarees(unite: str) -> set[str]:
    """Tout tag que cette unité voit, qu'il porte des champs ou non.

    `deja_vues` répond à « faut-il poser ce type ? » et écarte pour cela les
    coquilles vides, qui n'apprennent rien. Mais MWCC, lui, refuse la
    redéfinition d'une coquille vide comme celle d'une classe pleine :
    « struct/union/enum/class tag 'CMap' redefined ». Ce sont deux questions
    différentes, et les confondre laissait m2c poser un `typedef struct CMap`
    par-dessus la classe que l'unité déclare déjà.

    Mesuré sur les premières causes que la chaîne a enregistrées : 23 des 24
    échecs de compilation diagnostiqués portaient ce message.
    """
    return _parcourt(unite, lambda texte: set(_DECLARE.findall(texte)))


def _parcourt(unite: str, extrait) -> set[str]:
    """Applique `extrait` à l'unité et aux en-têtes qu'elle atteint.

    Le parcours est transitif : `cmap.cpp` n'inclut pas `gen/CMap.hpp`
    directement mais par un en-tête intermédiaire, et s'arrêter au premier rang
    laissait la collision passer.
    """
    source = ROOT / "src" / (unite + ".cpp")
    if not source.exists():
        return set()
    texte = source.read_text(encoding="utf-8", errors="replace")
    trouve, a_voir, vus = extrait(texte), list(_INCLUDE.findall(texte)), set()
    while a_voir:
        inclus = a_voir.pop()
        if inclus in vus:
            continue
        vus.add(inclus)
        chemin = ROOT / "include" / inclus
        if not chemin.exists():
            continue
        contenu = chemin.read_text(encoding="utf-8", errors="replace")
        trouve |= extrait(contenu)
        a_voir.extend(_INCLUDE.findall(contenu))
    return trouve


# Un type déclaré sans le moindre champ n'apprend rien : le tenir pour « vu »
# empêche de poser la structure que m2c infère, et le corps parle alors d'un
# `unk904` que rien ne définit. C'est la même règle que pour le contexte.
_OUVRE_TYPE = re.compile(r"^\s*(?:typedef\s+)?(?:struct|class|union)\s+(\w+)")


def _avec_champs(texte: str) -> set[str]:
    """Les types que ce texte déclare *avec* au moins un champ de donnée.

    Le parcours se fait ligne à ligne plutôt que par une expression sur
    plusieurs lignes : celle-ci rendait le bon résultat à l'essai et rien du
    tout depuis le module, sans que la différence se laisse voir.
    """
    trouve, nom, champs, profondeur = set(), None, 0, 0
    for ligne in texte.splitlines():
        if nom is None:
            entete = _OUVRE_TYPE.match(ligne)
            if entete and "{" in ligne:
                nom, champs, profondeur = entete.group(1), 0, 1
            continue
        profondeur += ligne.count("{") - ligne.count("}")
        depouillee = ligne.split("/*")[0].split("//")[0].rstrip()
        if depouillee.endswith(";") and "(" not in depouillee                 and depouillee.strip():
            champs += 1
        if profondeur <= 0:
            if champs:
                trouve.add(nom)
            nom = None
    return trouve


_PORTEURS: dict[str, str] | None = None


def entete_du_type(nom: str) -> str | None:
    """L'en-tête d'`include/` qui déclare ce type, s'il y en a un.

    C'est celui que m2c a lu dans le contexte : ses champs portent les noms du
    projet, et l'unité doit voir la même déclaration, sans quoi le corps parle
    d'un `unknown_20` que rien ne définit chez elle.
    """
    global _PORTEURS
    if _PORTEURS is None:
        _PORTEURS = {}
        include = ROOT / "include"
        for chemin in sorted(include.rglob("*.h")) + sorted(include.rglob("*.hpp")):
            relatif = chemin.relative_to(include).as_posix()
            for trouve in _DECLARE.findall(
                    chemin.read_text(encoding="utf-8", errors="replace")):
                _PORTEURS.setdefault(trouve, relatif)
    return _PORTEURS.get(nom)


_ATLAS: dict | None = None


def definition_atlas(nom: str) -> str | None:
    """La disposition que l'atlas donne de ce type, rendue en C++.

    Même arbitrage que le contexte, et pour la même raison : la proposition la
    plus attestée l'emporte, et ce que m2c n'a pas su typer devient du
    remplissage plutôt qu'une invention.
    """
    global _ATLAS
    if _ATLAS is None:
        chemin = ROOT / "progress" / "atlas.json"
        _ATLAS = (json.loads(chemin.read_text(encoding="utf-8"))["types"]
                  if chemin.exists() else {})
    decrit = _ATLAS.get(nom)
    if decrit is None:
        return None

    largeurs = {"s8": 1, "u8": 1, "char": 1, "bool": 1, "s16": 2, "u16": 2,
                "s32": 4, "u32": 4, "f32": 4, "s64": 8, "u64": 8, "f64": 8}
    lignes, position = [], 0
    for decalage, propositions in decrit["champs"].items():
        kind = next(iter(propositions))
        if "?" in kind or "::" in kind or kind.endswith("]"):
            continue
        if not kind.endswith("*") and kind.rstrip(" *") not in largeurs:
            continue
        offset = int(decalage, 16)
        if offset < position:
            continue
        if offset > position:
            lignes.append("    char pad_%X[0x%X];" % (position, offset - position))
        lignes.append("    %s field_%X;" % (kind, offset))
        position = offset + (4 if kind.endswith("*")
                             else largeurs.get(kind.rstrip(" *"), 4))
    if not lignes:
        return None
    return "struct %s {\n%s\n};" % (nom, "\n".join(lignes))


def decompile(symbole: str) -> str | None:
    """La sortie de m2c pour cette fonction, ou rien s'il refuse."""
    resultat = run([sys.executable, "scripts/diff/decompile.py", symbole],
                   capture_output=True, text=True)
    if resultat.returncode != 0 or not resultat.stdout.strip():
        return None
    return resultat.stdout


_FLECHE = re.compile(r"\b([A-Za-z_]\w*)\s*->\s*(unk[0-9A-Fa-f]+)\b")
_CHAMP_M2C = re.compile(
    r"/\*\s*0x([0-9A-Fa-f]+)\s*\*/\s*(.+?)\s*(\w+)\s*(\[[^\]]*\])?\s*;")


def _type_pointe(variable: str, corps: str) -> str | None:
    """Le type que le corps donne à `variable`, quand c'est un pointeur."""
    trouve = re.search(r"\b([A-Za-z_]\w*)\s*\*\s*%s\b" % re.escape(variable),
                       corps)
    return trouve.group(1) if trouve else None


def _struct_par_offsets(nom: str, offsets: dict[int, str]) -> str:
    """Une structure bâtie sur les seuls décalages que le corps réclame.

    m2c écrit `arg1->unk74` sans avoir inféré de structure pour `arg1` : le
    mangling disait `Pi`, il l'a cru, et MWCC répond « expression syntax error »
    parce qu'un `s32 *` n'a pas de champ. Le décalage, lui, est sûr — il est
    dans le nom. La largeur ne l'est pas : quatre octets est le cas courant, et
    c'est `make diff` qui dira si la lecture était plus étroite.

    Une structure fausse vaut mieux qu'une absente : elle fait entrer la
    fonction dans la mesure, où l'affinage peut la reprendre, là où l'absence
    la laissait au rebut sans le moindre chiffre.
    """
    lignes, curseur = [], 0
    for decalage in sorted(offsets):
        if decalage < curseur:
            continue
        if decalage > curseur:
            lignes.append("    char pad%X[0x%X];" % (curseur, decalage - curseur))
        lignes.append("    /* 0x%X */ s32 %s;" % (decalage, offsets[decalage]))
        curseur = decalage + 4
    return "struct %s {\n%s\n};" % (nom, "\n".join(lignes))


def _elargit(bloc: str, manquants: dict[int, str]) -> str:
    """Ajoute à une structure inférée par m2c les champs qu'elle ne porte pas.

    Ses propres champs se gardent tels quels : m2c a inféré leurs types en
    lisant les instructions, et les remplacer par des `s32` perdrait ce qu'il
    savait. Seuls les trous se comblent.
    """
    connus = {int(d, 16) for d, _, _, _ in _CHAMP_M2C.findall(bloc)}
    ajouts = {d: n for d, n in manquants.items() if d not in connus}
    if not ajouts:
        return bloc
    # Le remplissage se pose en queue : insérer au bon décalage demanderait de
    # recalculer toute la disposition, et m2c a déjà rempli ses trous.
    fin = bloc.rindex("}")
    queue = "\n".join("    /* 0x%X */ s32 %s;" % (d, n)
                      for d, n in sorted(ajouts.items()))
    return bloc[:fin] + queue + "\n" + bloc[fin:]


def complete_structures(structs: list[str], corps: str) -> tuple[list[str], str]:
    """Donne un type aux pointeurs que le corps déréférence sans déclaration.

    C'est la moitié des échecs de compilation de la chaîne, mesurée par
    `scripts/diff/causes.py` : 27 % de « undefined identifier `unkNN` » quand la
    structure existe sans le champ, 24 % d'« expression syntax error » quand
    elle n'existe pas du tout. Le même défaut, vu des deux côtés.
    """
    demandes: dict[str, dict[int, str]] = {}
    for variable, champ in _FLECHE.findall(corps):
        demandes.setdefault(variable, {})[int(champ[3:], 16)] = champ
    if not demandes:
        return structs, corps

    par_nom = {}
    for rang, bloc in enumerate(structs):
        trouve = _NOM_STRUCT.search(bloc)
        if trouve:
            par_nom[trouve.group(1)] = rang

    neuves = []
    for variable, offsets in demandes.items():
        type_ = _type_pointe(variable, corps)
        if type_ is None:
            continue
        if type_ in par_nom:
            rang = par_nom[type_]
            structs[rang] = _elargit(structs[rang], offsets)
            continue
        # Ni structure de m2c, ni type qui porte ces champs : on en bâtit une,
        # nommée d'après la variable pour que deux paramètres du même type de
        # base ne se disputent pas le nom.
        forge = "%s_champs" % variable
        neuves.append(_struct_par_offsets(forge, offsets))
        corps = re.sub(r"\b%s\s*\*\s*%s\b" % (re.escape(type_),
                                              re.escape(variable)),
                       "struct %s *%s" % (forge, variable), corps)
    return structs + neuves, corps


def normalise(texte: str, symbole: str, vues: set[str],
              declarees: set[str] | None = None,
              portees: dict[str, str] | None = None) -> tuple[str, str] | None:
    """Rend (déclarations, définition) prêtes à compiler, ou rien.

    Trois retouches, et pas une de plus : les structures inférées se gardent
    telles quelles, les externes reçoivent un type de retour et le nom manglé
    devient le symbole émis par `extern "C"`.
    """
    # Une structure que le projet déclare déjà ne se redéclare pas : MWCC
    # répond « struct/union/enum/class tag 'CColPrim' redefined », et celle du
    # projet porte de vrais noms de champs qu'il vaut mieux employer.
    # Une structure que l'unité déclare déjà ne peut pas être redéclarée — MWCC
    # répond « tag 'X' redefined ». Mais l'écarter ne marche pas davantage : sans
    # contexte, m2c a inventé ses propres noms de champs, et le corps parle d'un
    # `unk30` que la déclaration de l'unité ignore. On renomme donc la structure
    # inférée, dans sa définition comme dans le corps : les deux coexistent, et
    # ce sont les octets qui trancheront.
    structs, renommes = [], {}
    for bloc in _STRUCT.findall(texte):
        # m2c écrit `?` le champ dont il ignore le type, et `?32` celui dont il
        # ne connaît que la largeur. Ni l'un ni l'autre n'est du C : MWCC répond
        # « declaration syntax error » et perd la structure entière. La largeur,
        # elle, est sûre — c'est la seule chose qu'on garde.
        bloc = re.sub(r"(/\*[^*]*\*/\s*)\?(\d*)(\s+\w+;)",
                      lambda m: "%s%s%s" % (m.group(1),
                                            _LARGEUR_INCONNUE.get(m.group(2),
                                                                  "char"),
                                            m.group(3)),
                      bloc)
        nom = _NOM_STRUCT.search(bloc).group(1)
        occupes = vues if declarees is None else declarees
        if nom in occupes:
            # Le nom se cherche libre, non fixe : la chaine cumule les
            # fonctions d une unite, chacune infere ses propres champs, et
            # deux `X_infere` de contenus differents ne peuvent pas
            # coexister. Garder la premiere laisserait la seconde parler
            # de champs que rien ne declare.
            neuf, rang = nom + "_infere", 2
            while neuf in occupes:
                neuf, rang = "%s_infere%d" % (nom, rang), rang + 1
            renommes[nom] = neuf
            bloc = re.sub(r"\b%s\b" % re.escape(nom), neuf, bloc)
        structs.append(bloc)
    reste = _STRUCT.sub("", texte)
    for ancien, neuf in renommes.items():
        reste = re.sub(r"\b%s\b" % re.escape(ancien), neuf, reste)

    externes = []
    for retour, nom, params in _EXTERN.findall(reste):
        # `?` dit que m2c n'a pas tranché le type de retour ; un saut de queue
        # ne le dit pas davantage, et `void` n'engage que la déclaration.
        # Le prototype d'une méthode nomme `this` son premier paramètre, ce
        # qu'un prototype `extern "C"` ne peut pas davantage qu'une définition.
        # `? *` en paramètre est le même aveu que dans une structure : m2c
        # ne sait pas le type. `void *` en garde la seule chose sûre — que
        # c'est un pointeur. On vise `? *`, jamais un `?` isolé, qui serait
        # un opérateur ternaire.
        params = re.sub(r"\?\s*\*", "void *", params)
        # Le retour se rend `s32`, non `void` : m2c ecrit `?` quand il n'a pas
        # tranche, et c'est le plus souvent parce que la valeur *sert*. `void`
        # fait alors echouer tout appel qui l'emploie — « illegal implicit
        # conversion from 'void' » —, la ou `s32` est la largeur de $v0 et se
        # laisse ignorer quand la valeur ne sert pas. Le type declare d'un
        # retour entier ne change pas l'appel : les octets n'en dependent pas.
        # La declaration que le mangling donne passe avant celle que m2c
        # infere : elle est deterministe, donc identique dans toutes les
        # fonctions de l unite. Deux formes divergentes du meme nom
        # `extern "C"` font repondre « illegal function overloading », et
        # la chaine cumule les fonctions d une meme unite.
        # L'unite a peut-etre deja declare cet appele, et sa forme fait loi :
        # un nom `extern "C"` ne se surcharge pas. La reprendre mot pour mot
        # rend la redeclaration legale et donne a `remplit_les_appels` l'arite
        # que le reste du fichier suppose.
        if portees and nom in portees:
            externes.append(portees[nom])
            continue
        depuis_mangling = declaration(nom) if nom in functions() else None
        if depuis_mangling:
            # Le renommage vaut aussi pour elle : le corps parle de la
            # structure inferee, la declaration du type du projet, et les
            # deux designent la meme chose dans ce fragment.
            externes.append(renomme(depuis_mangling, renommes))
            continue
        externes.append('extern "C" %s %s(%s);'
                        % ("s32" if retour == "?" else retour, nom,
                           re.sub(r"\bthis\b", "objet", params)))
    reste = _EXTERN.sub("", reste)

    entete = re.search(_ENTETE.pattern % re.escape(symbole), reste, re.MULTILINE)
    if entete is None:
        return None
    corps = reste[entete.start():].rstrip()
    # m2c nomme `this` le premier paramètre d'une méthode, ce qu'une fonction
    # `extern "C"` ne peut pas faire : `this` est réservé, et MWCC répond
    # « ')' expected » suivi d'une erreur par ligne du corps.
    corps = re.sub(r"\bthis\b", "objet", corps)
    corps = 'extern "C" ' + corps

    # Tout type employé en pointeur doit exister avant qu'on l'emploie. Les
    # attendre un par un ne marche pas : MWCC ne nomme que le *premier*
    # identifiant inconnu, les suivants devenant des « declaration syntax
    # error » anonymes, et cinq tours n'en déclaraient donc que cinq.
    definis = {_NOM_STRUCT.search(bloc).group(1) for bloc in structs}
    employes = set(re.findall(r"\b([A-Za-z_]\w*)\s*\*", "\n".join(externes + structs) + corps))
    # `arg0 * 5` est une multiplication, non une déclaration : le motif ci-dessus
    # ne les distingue pas, et faisait émettre un `struct arg0;` que rien
    # n'emploie. Ce que le corps déclare comme variable n'est jamais un type.
    locales = set(re.findall(r"^\s*(?:struct\s+)?[A-Za-z_]\w*\s*\**\s*"
                             r"([A-Za-z_]\w*)\s*(?:\[[^\]]*\])?;\s*$",
                             corps, re.MULTILINE))
    locales |= set(re.findall(r"[A-Za-z_]\w*\s*\**\s*([A-Za-z_]\w*)\s*[,)]",
                              corps.split("\n", 1)[0]))
    avant = sorted(nom for nom in employes - definis - vues - locales
                   if nom not in _BASE and not nom.startswith("un"))

    # Le contexte a donné les types à m2c ; l'unité, elle, ne les voit pas, et
    # MWCC répond « illegal use of incomplete struct 'mgCMemory' ». L'atlas
    # porte la disposition : autant la poser, plutôt qu'une déclaration en avant
    # qui ne suffit qu'à passer un pointeur.
    en_tete = []
    for nom in avant:
        # L'en-tête du projet passe avant l'atlas : c'est lui que m2c a lu dans
        # le contexte, et ses champs portent d'autres noms — `unknown_20` là où
        # l'atlas dit `field_20`. Poser l'atlas ici ferait diverger le corps de
        # sa propre déclaration.
        porteur = entete_du_type(nom)
        if porteur:
            en_tete.append('#include "%s"' % porteur)
            continue
        bloc = definition_atlas(nom)
        en_tete.append(bloc if bloc else "struct %s;" % nom)

    structs, corps = complete_structures(structs, corps)
    # MWCC, en C++, refuse la conversion implicite que le C tolere : c'est la
    # premiere cause d'echec de compilation de la chaine.
    corps = nettoie_locales(corps)
    # Un appel sans argument que sa declaration attend n est pas une
    # contradiction : la valeur etait deja dans le registre.
    corps = remplit_les_appels(
        nettoie_declarations(chr(10).join(en_tete + structs + externes)),
        corps)
    corps = declare_les_piles(corps)
    corps = cast_les_affectations(corps)

    declarations = "\n".join(en_tete + structs + externes)
    return nettoie_declarations(declarations), corps


def score(symbole: str, unite: str) -> float | None:
    """La part appariée de cette fonction, ou rien si la mesure échoue."""
    cible = "build/ref/asm/text/%s.o" % unite
    base = "build/src/%s.o" % unite
    resultat = run(["objdiff-cli", "diff", "-1", cible, "-2", base,
                    "-o", "-", "--format", "json", symbole],
                   capture_output=True, text=True)
    if resultat.returncode != 0:
        return None
    try:
        charge = json.loads(resultat.stdout)
    except json.JSONDecodeError:
        return None
    for entree in charge.get("left", {}).get("symbols", []):
        if entree.get("name") == symbole:
            return float(entree.get("match_percent") or 0.0)
    return None


def eprouve(symbole: str, unite: str, taille: int,
            garde: bool = False) -> dict:
    """Traduit, pose, compile et mesure une fonction. Rend le compte rendu."""
    verdict = {"symbole": symbole, "unite": unite, "taille": taille}

    texte = decompile(symbole)
    if texte is None:
        return {**verdict, "issue": "m2c refuse"}

    # m2c signale lui-même ce qu'il n'a pas su traduire : `M2C_ERROR` pour une
    # instruction, `bitwise` pour une conversion qu'il ne sait pas rendre, un
    # registre sauvegardé laissé nu. Aucune de ces fonctions n'appariera par
    # cette voie, et les compter parmi les échecs de plomberie fausse le
    # diagnostic : elles relèvent du permuteur ou de la main.
    for aveu in ("M2C_ERROR", "M2C_UNK", "bitwise", "saved_reg_"):
        if aveu in texte:
            return {**verdict, "issue": "m2c ne sait pas traduire",
                    "cause": aveu}

    source = ROOT / "src" / (unite + ".cpp")
    avant = source.read_text(encoding="utf-8")

    rendu = normalise(texte, symbole, deja_vues(unite),
                      deja_declarees(unite),
                      declarations_portees(avant))
    if rendu is None:
        return {**verdict, "issue": "sortie illisible"}
    declarations, corps = rendu
    ligne = INCLUDE_ASM % (unite, symbole)
    if ligne not in avant:
        return {**verdict, "issue": "non greffée"}

    objet = ROOT / "build" / "src" / (unite + ".o")
    ajoutees: list[str] = []
    vus_types: set[str] = set()
    ellipses: set[str] = set()
    try:
        # Le compilateur dit ce qui manque, la table des symboles dit quoi
        # écrire, et l'on recommence. Cinq tours suffisent : chacun déclare
        # tout ce que le tour précédent a signalé.
        for _tour in range(5):
            # Les déclarations trouvées en chemin passent devant : un type que
            # m2c emploie dans une structure inférée doit exister avant elle.
            # La source porte deja les declarations des fonctions que
            # cette unite a gagnees avant celle-ci : les reposer ferait
            # surcharger un nom `extern "C"`, ce que MWCC refuse.
            # Seul ce qui precede le point de greffe compte : une
            # declaration posee plus bas dans le fichier ne vaut pas ici,
            # et l ecarter laissait cinq fonctions sans leur appele.
            fragment = assemble(ajoutees, declarations, corps,
                                avant.split(ligne)[0])
            source.write_text(avant.replace(ligne, fragment), encoding="utf-8")
            if objet.exists():
                objet.unlink()
            bati = run(["make", str(objet.relative_to(ROOT))],
                       capture_output=True, text=True)
            sortie = bati.stdout + bati.stderr
            if bati.returncode == 0:
                break
            # Deux fonctions d'une meme unite n'appellent pas toujours un
            # appele de la meme facon : l'une lui passe ses arguments, l'autre
            # les laisse dans les registres ou ils sont deja. Le nom
            # `extern "C"` ne se surcharge pas, et la declaration adoptee ne
            # peut donc convenir aux deux. `(...)` les accepte l'une et l'autre,
            # et c'est mesure : les neuf declarations sans parametre de
            # `text_002734D0` et le prototype typé de `SetStack__…` passes a
            # `(...)`, l'unite rend toujours les octets du disque — un appel a
            # deux arguments compris.
            #
            # La reserve tient a la promotion par defaut : sous `(...)`, un
            # `float` deviendrait un `double` et la conversion se verrait. On
            # n'y recourt donc qu'en reponse a un conflit constate, jamais par
            # defaut : la forme typee que le mangling donne reste la premiere.
            conflits = set(_ARITE.findall(sortie)) - ellipses
            if conflits:
                ellipses |= conflits
                for appele in conflits:
                    motif = re.compile(
                        '^extern "C" ([^;(]*?)' + _MOT + re.escape(appele)
                        + r'\s*\([^;]*\);$', re.M)
                    remplacement = 'extern "C" ' + chr(92) + "1" + appele + "(...);"
                    declarations = motif.sub(remplacement, declarations)
                    ajoutees = [motif.sub(remplacement, d) for d in ajoutees]
                    avant = motif.sub(remplacement, avant)
                continue

            manquants = {nom for nom in _INCONNU.findall(sortie)}
            neuves = [d for d in (declaration(nom, declarations + corps)
                                  for nom in sorted(manquants))
                      if d and d not in ajoutees]
            # Une déclaration ajoutée cite ses propres types — `extern "C" void
            # f(void *, CFuncPointCheck *)` —, et l'unité ne les connaît pas
            # davantage. Le contexte les a donnés à m2c, qui a cessé de les
            # réémettre : c'est ici qu'il faut les rattraper.
            # La variable de boucle ne s'appelle pas `ligne` : ce nom porte
            # l'`INCLUDE_ASM` à remplacer, et l'écraser faisait que la pose du
            # tour suivant ne trouvait plus rien. La source redevenait alors
            # greffée, la compilation réussissait forcément, et le score rendait
            # un 100 % qui était celui du code d'origine.
            for declaree in list(neuves):
                for kind in re.findall(r"\b([A-Za-z_]\w*)\s*\*", declaree):
                    if kind in _BASE or kind in vus_types:
                        continue
                    vus_types.add(kind)
                    bloc = definition_atlas(kind)
                    neuves.append(bloc if bloc else "struct %s;" % kind)
            if not neuves:
                message, extrait = erreur_detaillee(sortie)
                return {**verdict, "issue": "ne compile pas",
                        "cause": message, "extrait": extrait}
            ajoutees.extend(neuves)
        else:
            return {**verdict, "issue": "ne compile pas",
                    "cause": "déclarations sans fin"}
        # Avant de mesurer, prouver que la fonction n'est plus greffée. Sans
        # cette garde, toute erreur de pose rend un 100 % qui est celui du
        # disque : l'unité compile son propre assembleur, et objdiff compare le
        # commerce à lui-même. C'est le faux appariement contre lequel tout le
        # dépôt met en garde, revenu par la porte de la mesure individuelle.
        if ligne in source.read_text(encoding="utf-8"):
            verdict["issue"] = "pose sans effet"
            return verdict

        part = score(symbole, unite)
        if part is None:
            verdict["issue"] = "mesure impossible"
            return verdict
        # Le fragment retenu voyage avec le verdict : `chaine.py` le garde tel
        # quel quand la fonction apparie, sans refaire le chemin.
        verdict.update({"issue": "mesurée", "part": part,
                        "fragment": fragment, "declarations": ajoutees})
        return verdict
    finally:
        # `garde` laisse en place ce qui apparie : la chaîne cumule les
        # fonctions d'une même unité, et chacune doit compiler *avec* les
        # précédentes. Mesurer isolément puis appliquer en bloc laissait les
        # déclarations se télescoper, et un fragment figé vieillissait dès que
        # le contexte changeait.
        if not (garde and verdict.get("issue") == "mesurée"
                and (verdict.get("part") or 0) >= 99.999):
            source.write_text(avant, encoding="utf-8")

        # L objet part avec la source. Un SIGTERM tombe le plus souvent
        # pendant `make`, qui laisse alors un `.o` tronque : `make` le
        # croit a jour puisqu il est plus recent que sa source, et la
        # construction suivante s ecarte du disque sur 73 % des octets
        # sans qu aucune source ait change. Deux diagnostics ont ete
        # perdus a chercher la faute dans `src/`.
        if objet.exists():
            objet.unlink()


# La contre-oblique se pose par `chr(92)` : ecrite en clair, un correctif
# mal echappe la transforme en l'octet 8, et le motif cherche alors un
# retour arriere que rien ne porte — la substitution ne fait plus rien,
# en silence. Le controle `outils corrompus` guette la meme faute.
_MOT = chr(92) + 'b'

_INCONNU = re.compile(r"undefined identifier '(\w+)'")

# « function call 'f(int)' does not match 'f(void)' » — l'appele est le
# meme, la facon de l'appeler differe d'une fonction de l'unite a l'autre.
_ARITE = re.compile(r"function call '(\w+)\(")
_OBJET = re.compile(r"^(\w+) = 0x[0-9A-Fa-f]+; // size:0x([0-9A-Fa-f]+)",
                    re.MULTILINE)
_TAILLES: dict[str, int] | None = None


def objets() -> dict[str, int]:
    """La taille de chaque donnée du binaire, qui décide de sa déclaration."""
    global _TAILLES
    if _TAILLES is None:
        table = (ROOT / "config" / "elf_symbol_addrs.txt").read_text(encoding="utf-8")
        _TAILLES = {nom: int(taille, 16) for nom, taille in _OBJET.findall(table)
                    if "type:func" not in nom}
    return _TAILLES


def declaration(nom: str, corps: str = "") -> str | None:
    """Ce qu'il faut écrire pour que ce symbole existe, d'après le binaire.

    m2c ne déclare que ce que son contexte lui donne, et le nôtre est vide : les
    globales et les fonctions de l'unité lui manquent. Le binaire, lui, les
    nomme toutes — c'est la table des symboles qui répond, non une supposition.

    `extern "C"` est indispensable : le nom est déjà manglé, et le remangler
    viserait un symbole que rien ne définit.
    """
    from lib.mangling import demangle  # noqa: PLC0415

    fonction = functions().get(nom)
    if fonction is not None:
        symbole = demangle(nom)
        if symbole is None:
            # Un nom C pur — `printf`, `memcpy` — ne porte pas de
            # mangling, donc pas de signature. La liste variadique dit
            # ce que nous savons : la fonction existe, ses parametres
            # nous echappent. Sept fonctions de la moisson butaient sur
            # « undefined identifier 'printf' » faute de cette ligne.
            return 'extern "C" s32 %s(...);' % nom
        # `this` d'abord quand c'en est une méthode : sous `extern "C"`, il
        # n'est qu'un paramètre de plus, et son type importe peu à l'appel.
        # Le type du pointeur se garde. Le declarer `void *` rendait la
        # forme independante du renommage, mais entrait en conflit avec
        # les prototypes typees que les unites portent deja et avec les
        # definitions voisines : surcharge a 25 % des echecs contre 17 %,
        # et la reecriture des sources ne compile pas.
        params = (["void *"] if symbole.cls else []) + list(symbole.params)
        # Le retour se rend `s32`, non `void` : le mangling C++ n'encode pas le
        # type de retour, et `void` fait echouer tout appel dont la valeur sert
        # — « illegal explicit conversion from 'void' to ». `s32` est la largeur
        # de $v0, et se laisse ignorer quand la valeur ne sert pas. Le type
        # declare d'un retour entier ne change pas les octets de l'appel.
        return 'extern "C" s32 %s(%s);' % (nom, ", ".join(params) or "void")

    taille = objets().get(nom)
    if taille is None:
        # Ni fonction ni donnée : c'est un type que m2c nomme sans le définir.
        # Tant qu'il n'apparaît qu'en pointeur, la déclaration en avant suffit
        # — et si le corps le déréférence, MWCC le dira au tour suivant.
        if corps and re.search(r"\b%s\s*\*" % re.escape(nom), corps):
            return "struct %s;" % nom
        # Employe sans etoile — `sizeof(CSaveData)`, une locale par
        # valeur — il lui faut un type complet, non une declaration en
        # avant. L en-tete du projet le donne, l atlas a defaut.
        porteur = entete_du_type(nom)
        if porteur:
            return '#include "%s"' % porteur
        return definition_atlas(nom)
    largeur = {1: "u8", 2: "u16", 4: "u32", 8: "u64"}.get(taille)
    if largeur is None:
        return 'extern "C" u8 %s[%d];' % (nom, taille)
    return 'extern "C" %s %s;' % (largeur, nom)


_ERREUR = re.compile(r"^#\s+([a-z'].*)$", re.MULTILINE)


# La contre-oblique se pose par `chr(92)`, comme partout ici : ecrite en clair
# dans un correctif mal echappe, elle devient l'octet 8 et le motif ne trouve
# plus rien, en silence.
_LIGNE_FAUTIVE = re.compile(r"^#\s+(\d+): ?(.*)$", re.M)
_CURSEUR = re.compile(r"^#\s+Error:( *)\^", re.M)


def premiere_erreur(sortie: str) -> str:
    trouve = _ERREUR.findall(sortie)
    return trouve[0][:70] if trouve else "inconnue"


def erreur_detaillee(sortie: str) -> tuple[str, str]:
    """Le message de MWCC, et le morceau de source qu'il désigne.

    Le message seul ne dit pas quoi réparer : 93 « declaration syntax error »
    se ressemblent et recouvrent des fautes sans rapport. MWCC, lui, pointe une
    colonne — il imprime la ligne fautive, puis un curseur sous le caractère en
    cause. C'est ce voisinage qui classe.

    Le fragment ne se diagnostique plus hors de son unité : sur douze témoins
    tirés des deux premières causes, douze compilent seuls. Les échecs qui
    restent naissent de la rencontre avec l'unité, et seule la chaîne les voit.
    """
    message = premiere_erreur(sortie)
    ligne = _LIGNE_FAUTIVE.search(sortie)
    curseur = _CURSEUR.search(sortie)
    if not (ligne and curseur):
        return message, ""
    brut = ligne.group(0)
    colonne = len(curseur.group(0)) - 1
    if not 0 <= colonne < len(brut):
        return message, ligne.group(2).strip()[:70]
    # Le curseur est le seul repere qui distingue deux lignes identiques
    # fautives en des points differents : on le garde, marque par un chevron.
    marque = brut[:colonne] + chr(187) + brut[colonne:]
    return message, marque[max(0, colonne - 24):colonne + 25].strip()


def main(argv: list[str]) -> int:
    parseur = argparse.ArgumentParser(description=__doc__)
    parseur.add_argument("--combien", type=int, default=20)
    parseur.add_argument("--mini", type=int, default=150)
    parseur.add_argument("--maxi", type=int, default=400)
    parseur.add_argument("--graine", type=int, default=1)
    options = parseur.parse_args(argv)

    table = functions()
    greffees = {nom for noms in grafted_by_source().values() for nom in noms}
    lot = [(f.size, nom, unit_of(nom)) for nom, f in table.items()
           if nom in greffees and options.mini <= f.size <= options.maxi
           and unit_of(nom)]
    random.Random(options.graine).shuffle(lot)
    lot = lot[:options.combien]

    print("sonde m2c : %d fonctions de %d à %d octets\n"
          % (len(lot), options.mini, options.maxi))
    comptes: dict[str, int] = {}
    parts: list[float] = []
    for taille, symbole, unite in lot:
        verdict = eprouve(symbole, unite, taille)
        comptes[verdict["issue"]] = comptes.get(verdict["issue"], 0) + 1
        if "part" in verdict:
            parts.append(verdict["part"])
            detail = "%6.2f %%" % verdict["part"]
        else:
            detail = verdict.get("cause", "")
        print("  %5d  %-46s %-16s %s"
              % (taille, symbole[:46], verdict["issue"], detail))

    print("\nrésumé")
    for issue, compte in sorted(comptes.items(), key=lambda kv: -kv[1]):
        print("  %-18s %3d  (%.0f %%)"
              % (issue, compte, 100 * compte / len(lot)))
    if parts:
        parts.sort()
        print("\n  appariement des %d mesurées : médiane %.1f %%, "
              "meilleure %.1f %%, à 100 %% : %d"
              % (len(parts), parts[len(parts) // 2], parts[-1],
                 sum(1 for p in parts if p >= 99.999)))
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
