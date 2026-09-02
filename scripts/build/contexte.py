#!/usr/bin/env python3
"""Le contexte que m2c lit pour typer ce qu'il décompile.

    make contexte        écrit build/ctx.c

`scripts/diff/decompile.py` le passe à m2c dès qu'il existe. Sans lui, m2c
invente un nom de champ par décalage — `unk30` — et une signature par appel ;
la sonde a mesuré ce que cela coûte : sur vingt fonctions, une seule compilait,
les autres butant sur un champ ou un type que rien ne déclarait.

m2c lit du C par pycparser, non du C++ : les méthodes membres, les blocs
`extern "C"` et les gardes d'inclusion en sont donc retirés. Ce qui reste — les
champs d'une structure, les prototypes, les typedefs — est déjà du C valide, et
c'est tout ce dont m2c a besoin.

Le fichier est engendré, jamais tenu à la main : la vérité reste dans
`include/`, et une structure corrigée là se retrouve ici au prochain appel.
"""

from __future__ import annotations

import json
import re
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from lib.mangling import demangle  # noqa: E402
from lib.project import BUILD_DIR, INCLUDE_DIR, ROOT, functions  # noqa: E402

SORTIE = BUILD_DIR / "ctx.c"

# Les types de largeur fixe, réécrits plutôt que repris de `include/types.h` :
# celui-ci déclare `u128` avec un `__attribute__((mode(TI)))` que pycparser ne
# lit pas, et s'arrête dessus. La largeur exacte n'importe pas à m2c, qui ne
# s'en sert que pour typer ; elle importe au compilateur, qui lit l'autre.
BASES = """\
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef signed long long s64;
typedef float f32;
typedef double f64;
typedef unsigned long long u128;
typedef signed long long s128;
typedef int BOOL;
/* `bool` est un mot-clé en C++ mais pas en C : pycparser l'attend en type. */
typedef unsigned char bool;
"""

# Les noms que `BASES` définit : tout autre nom de type est un type du jeu.
_BASES_NOMMEES = {"u8", "u16", "u32", "u64", "s8", "s16", "s32", "s64",
                  "f32", "f64", "u128", "s128", "BOOL", "void", "char",
                  "bool", "int", "unsigned", "signed", "long", "short",
                  "float", "double"}

_GARDE = re.compile(r"^\s*#\s*(ifndef|define|endif|include|if|else|elif|pragma)\b")
_EXTERN_C = re.compile(r'^\s*extern\s+"C"\s*\{?\s*$')
# Une déclaration de méthode : indentée, elle porte une liste d'arguments et
# s'achève sur un point-virgule. `virtual void vf00() = 0;` en est une, et les
# énumérer par leur forme exacte revenait à courir après chaque variante ; un
# champ, lui, n'a de parenthèses que s'il est un pointeur de fonction, que
# `(*` distingue.
# Le dépôt annote souvent le créneau virtuel en fin de ligne — `; /* 0x14 */` —,
# et exiger le point-virgule en dernier laissait passer ces méthodes-là.
_METHODE = re.compile(
    r"^\s+.*\(.*\)\s*(?:const)?\s*(?:=\s*0\s*)?;(?:\s*/\*.*?\*/)?\s*$")
_POINTEUR_FONCTION = re.compile(r"\(\s*\*")
# Une *définition* seulement : `class CMap;` en avant ne dit rien des champs,
# et l'inscrire au contexte fait croire à m2c qu'il connaît le type — il cesse
# alors de l'inférer, et l'unité se retrouve sans structure du tout.
_STRUCT = re.compile(r"\b(?:struct|class|union)\s+(\w+)\s*(?::[^{;]*)?\{")
# Tout nom de type rencontré, définition ou simple déclaration en avant : il en
# faut un typedef pour chacun, sans quoi pycparser bute sur son premier emploi.
_NOMME = re.compile(r"\b(?:struct|class|union)\s+(\w+)")
# `class X : public Y {` ou `class X {` — le C ne connaît ni l'un ni l'autre.
_CLASSE = re.compile(r"\bclass\s+(\w+)\s*(?::[^{]*)?\{")
# `public:` et ses semblables n'ont pas d'équivalent en C.
_ACCES = re.compile(r"^\s*(?:public|private|protected)\s*:\s*$")


def nettoie(texte: str) -> str:
    """Rend d'un en-tête ce que pycparser sait lire.

    Trois retraits : les directives du préprocesseur, les blocs `extern "C"` —
    dont le contenu, lui, est du C — et les déclarations de méthodes, qu'une
    structure C n'admet pas.
    """
    lignes = []
    profondeur_extern = None
    accolades = 0
    for ligne in texte.splitlines():
        if _GARDE.match(ligne):
            continue
        if _EXTERN_C.match(ligne):
            # Le bloc s'ouvre : son accolade ne compte pas, et celle qui le
            # ferme se reconnaîtra au même niveau.
            profondeur_extern = accolades
            continue
        if profondeur_extern is not None and accolades == profondeur_extern \
                and ligne.strip() == "}":
            profondeur_extern = None
            continue
        if _ACCES.match(ligne) or (_METHODE.match(ligne)
                                   and not _POINTEUR_FONCTION.search(ligne)):
            continue
        # `class X : public Y {` n'est pas du C. La base disparaît avec le
        # mot-clé : m2c n'a besoin que des noms de champs, et la disposition
        # qu'un héritage décale reste à établir de toute façon.
        ligne = _CLASSE.sub(r"struct \1 {", ligne)
        # `class X;` en avant se rend de même : le mot-clé seul change.
        ligne = re.sub(r"^(\s*)class\s+(\w+)\s*;", r"\1struct \2;", ligne)
        accolades += ligne.count("{") - ligne.count("}")
        lignes.append(ligne)
    return "\n".join(lignes)


# Une ligne de champ : un identifiant suivi d'un point-virgule, à l'intérieur
# du bloc. Les méthodes en ont déjà été retirées par `nettoie`.
_CHAMP = re.compile(r"^\s+[A-Za-z_].*;", re.MULTILINE)
_OUVRE = re.compile(r"^\s*(?:typedef\s+)?(?:struct|class|union)\s+\w+\s*(?::[^{;]*)?\{")


def blocs_de_type(texte: str) -> list[str]:
    """Les définitions de type d'une source, sans le code qui les entoure.

    Une classe du jeu est souvent déclarée dans l'unité qui l'emploie plutôt
    que dans un en-tête — `CMap` vit dans `src/game/cmap.cpp`. Ne lire que
    `include/` laissait m2c inventer `unk32C` alors que les vrais noms de
    champs étaient là, à côté.
    """
    lignes = texte.splitlines()
    blocs, courant, profondeur = [], None, 0
    for ligne in lignes:
        if courant is None:
            if _OUVRE.match(ligne):
                courant = [ligne]
                profondeur = ligne.count("{") - ligne.count("}")
                if profondeur <= 0:
                    courant = None
            continue
        courant.append(ligne)
        profondeur += ligne.count("{") - ligne.count("}")
        if profondeur <= 0:
            blocs.append("\n".join(courant))
            courant = None
    return blocs


ATLAS = ROOT / "progress" / "atlas.json"

# La largeur de ce que l'atlas propose, pour poser le remplissage entre champs.
_LARGEUR = {"s8": 1, "u8": 1, "char": 1, "bool": 1, "s16": 2, "u16": 2,
            "s32": 4, "u32": 4, "f32": 4, "s64": 8, "u64": 8, "f64": 8,
            "s128": 16, "u128": 16}


def depuis_atlas(deja: set[str]) -> tuple[set[str], list[str]]:
    """Les structures que l'atlas décrit, rendues en C.

    L'arbitrage tient en une règle, et elle se voit dans le fichier : au
    décalage contredit, **la proposition la plus attestée l'emporte**. Un type
    proposé par douze unités et un autre par une seule ne se valent pas. Ce que
    m2c n'a pas su typer — le `?` — est écarté plutôt que deviné : le champ
    disparaît dans le remplissage, ce qui n'affirme rien.

    Une structure que le dépôt tient déjà à la main n'est pas remplacée : elle
    porte de vrais noms de champs, et c'est un acquis.
    """
    if not ATLAS.exists():
        return set(), []
    atlas = json.loads(ATLAS.read_text(encoding="utf-8"))["types"]

    noms, blocs = set(), []
    for nom, decrit in sorted(atlas.items()):
        if nom in deja or nom in _BASES_NOMMEES:
            continue
        lignes, position = [], 0
        for decalage, propositions in decrit["champs"].items():
            kind = next(iter(propositions))
            # m2c rend « ? » ce qu'il ne type pas, et « ?32 » quand il n'en
            # connaît que la largeur : ni l'un ni l'autre n'est un type C.
            # m2c rend « ? » ce qu'il ne type pas, « ?32 » quand il n'en connaît
            # que la largeur, et parfois un nom de type imbriqué à la C++ —
            # `CScene::BGM_STATUS` — que le C ne sait pas lire. Aucun des trois
            # n'est un type C, et deviner à leur place n'apprendrait rien.
            if "?" in kind or "::" in kind or kind.endswith("]"):
                continue
            # Un type nommé employé *par valeur* demande sa définition, que
            # l'atlas n'a pas toujours : m2c répond « Tried to use struct
            # CMapLightingInfo before it is defined ». Un pointeur, lui, se
            # contente du nom. Le champ écarté devient du remplissage, ce qui
            # n'affirme rien.
            if not kind.endswith("*") and kind.rstrip(" *") not in _BASES_NOMMEES:
                continue
            offset = int(decalage, 16)
            if offset < position:
                continue
            largeur = _LARGEUR.get(kind.rstrip(" *"), 4) if not kind.endswith("*") else 4
            if offset > position:
                lignes.append("    char pad_%X[0x%X];" % (position, offset - position))
            lignes.append("    %s field_%X;" % (kind, offset))
            position = offset + largeur
        if not lignes:
            continue
        noms.add(nom)
        blocs.append("struct %s {\n%s\n};" % (nom, "\n".join(lignes)))
    return noms, blocs


def prototypes(definis: set[str]) -> tuple[set[str], list[str]]:
    """Les signatures que le mangling donne, sous le nom que le binaire porte.

    m2c apparie un appel à son prototype par le nom du symbole : c'est donc le
    nom manglé qu'il faut déclarer, et `this` y devient un premier paramètre
    ordinaire — le contexte décrit une convention d'appel, pas une classe.
    """
    lignes, types = [], set()
    for nom in sorted(functions()):
        symbole = demangle(nom)
        if symbole is None:
            continue
        # Une référence n'existe pas en C, et l'ABI n'en fait de toute façon
        # qu'un pointeur. Le remplacement vient avant tout le reste : opéré
        # plus tard, il laissait `CCollisionMDT &` échapper au relevé des types
        # à déclarer, et le nom manquait au contexte.
        # `this` prend le type de sa classe, non `void *` : m2c s'appuie sur
        # lui pour inférer les champs, et un `void *` lui interdisait d'écrire
        # `arg0->unk32C` — la méthode devenait illisible alors même que le
        # contexte avait réglé tout le reste.
        params = [p.replace("&", "*") for p in
                  ([symbole.cls + " *"] if symbole.cls else [])
                  + list(symbole.params)]
        if any("..." in p for p in params):
            continue
        # `AddPacket__14mgCDrawManagerFiP1P1i` rend un type nommé « P » d'un
        # seul caractère : le démangleur a lu une compression du mangling comme
        # une longueur. Aucun type du jeu ne porte un nom d'une lettre, et une
        # signature fausse dans le contexte vaut moins que pas de signature.
        if any(len(p.rstrip(" *")) < 2 and not p.rstrip(" *").isdigit()
               for p in params):
            continue
        # Un prototype qui nomme un type dont le contexte n'a pas la définition
        # nuit plus qu'il ne sert : m2c cesse d'inférer la structure, et le
        # compilateur reçoit un type incomplet. Mieux vaut alors n'en donner
        # aucun et laisser m2c faire ce qu'il faisait bien.
        nommes = set()
        for param in params:
            # `CMap **` compte autant que `CMap *` : une étoile de plus ne
            # change pas le type qu'il faut déclarer.
            trouve = re.match(r"^(?:const\s+)?(\w+)[\s*]*$", param)
            # Le nom d'un type ne dit pas sa casse : `tagMOTION_TYPE` en est un
            # comme `CDC2Mes`. Seule la liste des types de base tranche.
            if trouve and trouve.group(1) not in _BASES_NOMMEES:
                nommes.add(trouve.group(1))
        if nommes - definis:
            continue
        types |= nommes
        # Le type de retour n'est pas manglé : `void` n'engage rien de plus que
        # ce que le binaire dit, et m2c le corrigera de lui-même s'il voit la
        # valeur employée.
        lignes.append("void %s(%s);" % (nom, ", ".join(params) or "void"))
    return types, lignes


def main() -> int:
    morceaux = [
        "/* Engendré par scripts/build/contexte.py — ne pas modifier à la main.",
        " * La vérité est dans include/ ; ce fichier n'en est que la vue que",
        " * pycparser sait lire, pour que m2c type ce qu'il décompile. */",
        "",
        BASES,
    ]

    entetes = sorted(INCLUDE_DIR.glob("*.h")) + sorted(INCLUDE_DIR.glob("*.hpp")) \
        + sorted((INCLUDE_DIR / "gen").glob("*.hpp"))
    connus: set[str] = set()
    nommes: set[str] = set()
    corps: list[str] = []
    for chemin in entetes:
        if chemin.name in ("types.h", "include_asm.h"):
            continue
        texte = nettoie(chemin.read_text(encoding="utf-8", errors="replace"))
        if not texte.strip():
            continue
        connus.update(_STRUCT.findall(texte))
        nommes.update(_NOMME.findall(texte))
        corps.append("/* %s */" % chemin.relative_to(ROOT).as_posix())
        corps.append(texte)

    # Les types que les unités déclarent chez elles, extraits bloc par bloc :
    # le reste d'un `.cpp` est du code, que pycparser n'a pas à lire.
    for chemin in sorted((ROOT / "src").rglob("*.cpp")):
        for bloc in blocs_de_type(chemin.read_text(encoding="utf-8",
                                                   errors="replace")):
            nom = _STRUCT.search(bloc)
            if nom is None or nom.group(1) in connus:
                continue
            propre = nettoie(bloc)
            # Une structure sans champ n'apprend rien et fait du mal : m2c la
            # tient pour connue et cesse d'inférer, si bien qu'il écrit
            # `this->unk32C` sans pouvoir dire ce qu'est cette structure. Les
            # classes du dépôt sont souvent dans ce cas — `class CMap` ne porte
            # aujourd'hui qu'une méthode.
            if not _CHAMP.search(propre):
                continue
            connus.add(nom.group(1))
            nommes.update(_NOMME.findall(propre))
            corps.append("/* %s */" % chemin.relative_to(ROOT).as_posix())
            corps.append(propre)

    # pycparser est un analyseur, non un compilateur : il lui suffit de savoir
    # qu'un identifiant *est* un nom de type pour lire `DngMapFloorInfo info;`.
    # Les en-têtes étant en C++, ils emploient ce nom sans `struct` et souvent
    # avant sa définition ; sans ces typedefs, m2c s'arrête sur le premier.
    # L'atlas vient après les en-têtes tenus à la main, jamais devant : ceux-ci
    # portent de vrais noms de champs, et c'est un acquis qu'on ne remplace pas.
    depuis, blocs = depuis_atlas(connus)
    if blocs:
        corps.append("/* progress/atlas.json — ce que m2c infère du binaire. */")
        corps.extend(blocs)
        connus |= depuis
        nommes |= depuis
        # Un champ peut porter un type que l'atlas ne décrit pas — `VoTag *` —,
        # et il lui faut son typedef comme à n'importe quel autre.
        for bloc in blocs:
            for kind in re.findall(r"^    ([A-Za-z_]\w*)[\s*]", bloc, re.MULTILINE):
                if kind not in _BASES_NOMMEES:
                    nommes.add(kind)

    cites, signatures = prototypes(connus)
    morceaux.append("/* Les noms de type, avant tout emploi. */")
    morceaux += ["typedef struct %s %s;" % (nom, nom)
                 for nom in sorted(nommes | cites)]
    morceaux.append("")
    morceaux += corps
    morceaux.append("")
    morceaux.append("/* Les signatures que le mangling donne. */")
    morceaux += signatures

    SORTIE.parent.mkdir(parents=True, exist_ok=True)
    SORTIE.write_text("\n".join(morceaux) + "\n", encoding="utf-8")
    print("contexte : %s  (%d structures, %d Kio)"
          % (SORTIE.relative_to(ROOT), len(connus),
             SORTIE.stat().st_size // 1024))
    return 0


if __name__ == "__main__":
    sys.exit(main())
