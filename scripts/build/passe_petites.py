#!/usr/bin/env python3
"""Applique un plan de petites fonctions, le mesure, et annule ce qui rate.

    scripts/host/dc2 python3 scripts/build/passe_petites.py
    scripts/host/dc2 python3 scripts/build/passe_petites.py --essai

Le plan que `scripts/diff/petites.py` propose n'est qu'une proposition : c'est
la construction qui tranche. Cette passe l'applique en bloc, construit, mesure
chaque fonction, puis réécrit les sources en ne gardant que celles qui rendent
les octets du disque. Rien n'est laissé à moitié : une fonction qui n'apparie
pas retrouve son `INCLUDE_ASM`.

L'état d'avant est copié sous `progress/passes/<horodatage>/` au premier pas, et
chaque réécriture repart de cette copie : annuler n'est jamais qu'appliquer un
sous-ensemble, ce qui évite d'avoir à retrouver dans le texte ce qu'on y a mis.

**L'instantané est propre à l'exécution**, et c'est essentiel : un dossier
partagé entre passes garderait l'état d'avant la *première*, si bien qu'une
seconde passe rendrait à l'assembleur les fonctions que la première avait
gagnées, sans le dire.
"""

from __future__ import annotations

import argparse
import json
import os
import re
import shutil
import subprocess
import sys
from datetime import datetime

RACINE = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
sys.path.insert(0, os.path.join(RACINE, "scripts"))
from lib.project import find_symbol  # noqa: E402
PASSES = os.path.join(RACINE, "progress", "passes")
GEN = os.path.join(RACINE, "include", "gen")

# L'instantané de cette exécution. Fixé au démarrage par `ouvre_instantane()`,
# jamais réemployé d'une passe à l'autre.
AVANT = ""

INCLUDE_ASM = 'INCLUDE_ASM("nonmatchings/%s", %s);'
ENTETE_ENGENDREE = "/* Déclaration engendrée par `scripts/diff/petites.py`."


def lance(commande: list[str], **kwargs) -> subprocess.CompletedProcess:
    return subprocess.run(commande, cwd=RACINE, **kwargs)


# -- déclarations ---------------------------------------------------------

def deja_declaree(classe: str) -> str | None:
    """Le fichier qui déclare déjà cette classe, hors des en-têtes engendrés.

    Une classe que le projet décrit à la main porte les vrais noms de ses
    champs : la compléter d'un `field_0x…` engendré ferait perdre ce travail,
    et deux déclarations d'une même classe ne se recollent pas.
    """
    motif = re.compile(r"\b(?:class|struct)\s+%s\s*(?::|\{)" % re.escape(classe))
    for dossier in ("include", "src"):
        for racine, _sous, fichiers in os.walk(os.path.join(RACINE, dossier)):
            if os.path.abspath(racine).startswith(os.path.abspath(GEN)):
                continue
            for fichier in fichiers:
                if not fichier.endswith((".h", ".hpp", ".cpp")):
                    continue
                chemin = os.path.join(racine, fichier)
                with open(chemin, encoding="utf-8", errors="replace") as source:
                    if motif.search(source.read()):
                        return os.path.relpath(chemin, RACINE)
    return None


def entete(classe: str, champs: dict[int, str], membres: list[str],
           types: set[str] | None = None) -> str:
    """La déclaration provisoire d'une classe, champs connus et remplissage.

    Les types nommés qu'emploient les membres se déclarent ici, en avant : la
    source qui inclut cet en-tête les déclarait bien, mais *après* lui, et MWCC
    lisait alors `void SetTexture(mgCTexture *, …)` sans savoir ce qu'est un
    `mgCTexture` — « illegal function definition », puis la méthode redéclarée
    comme `void ()`. Dix-huit erreurs venaient de là.
    """
    largeur = {"s8": 1, "u8": 1, "s16": 2, "u16": 2, "s32": 4, "u32": 4,
               "f32": 4, "s64": 8, "u64": 8}
    lignes, position = [], 0
    for offset in sorted(champs):
        kind = champs[offset]
        if offset < position:
            # Deux accès se chevauchent : le champ étroit est déjà couvert.
            continue
        if offset > position:
            lignes.append("    u8 pad_0x%X[0x%X];" % (position, offset - position))
        lignes.append("    %s field_0x%X;" % (kind, offset))
        position = offset + largeur.get(kind, 4)

    garde = "GEN_%s_HPP" % classe.upper()
    # Un champ peut porter un type nommé — `mgCTexture *field_0x28` — sans
    # qu'aucune signature ne le mentionne : ce que la structure emploie doit se
    # déclarer ici, au même titre que ce que ses méthodes emploient.
    # Un type de base ne se déclare pas en avant : `struct s16;` vaut à MWCC un
    # « typename redefined », `s16` étant déjà un typedef de `common.h`.
    dans_les_champs = {
        kind.rstrip(" *") for kind in champs.values()
        if kind.endswith("*")
        and kind.rstrip(" *") not in set(largeur) | {"void", "char", "bool"}
    }
    avant = sorted(((types or set()) | dans_les_champs) - {classe})
    return "\n".join([
        "#ifndef %s" % garde,
        "#define %s" % garde,
        "",
        '#include "common.h"',
        "",
        *(["struct %s;" % nom for nom in avant] + [""] if avant else []),
        ENTETE_ENGENDREE,
        " * Seuls les champs qu'un accesseur touche sont connus ; leur nom dit",
        " * leur décalage, faute de mieux, et le reste est du remplissage. Ni",
        " * la taille de la classe ni ses méthodes virtuelles n'y paraissent :",
        " * déclarer une virtuelle ferait émettre une table que le disque",
        " * porte déjà. */",
        "struct %s {" % classe,
        *lignes,
        *(([""] + ["    " + membre for membre in sorted(membres)])
          if membres else []),
        "};",
        "",
        "#endif /* %s */" % garde,
        "",
    ])


def ecris_entetes(classes: set[str], fonctions: list[dict]) -> None:
    """Écrit l'en-tête de chaque classe, d'après les seules fonctions écrites.

    Champs et méthodes suivent ce que les sources définissent : une déclaration
    qu'aucune définition n'accompagne serait une affirmation gratuite sur la
    disposition de la classe.
    """
    for classe in sorted(classes):
        champs: dict[int, str] = {}
        membres: list[str] = []
        types: set[str] = set()
        for fonction in fonctions:
            # Les champs viennent de toute fonction qui en touche, méthode ou
            # non : `InitSplineKey(SPLINE_KEY *)` est une fonction libre, et
            # n'en retenir que les méthodes engendrait une structure vide, donc
            # autant d'« undefined identifier 'field_0x0' ».
            for offset, kind in (fonction.get("champs", {}).get(classe, {})).items():
                # Le pointeur l'emporte sur l'entier de même largeur : `lw` dit
                # la taille, un rangement de pointeur dit le contenu.
                ancien = champs.get(int(offset))
                if ancien is None or (kind.endswith("*") and not ancien.endswith("*")):
                    champs[int(offset)] = kind
            # Les méthodes, elles, n'appartiennent qu'à leur propre classe.
            if fonction.get("classe") != classe:
                continue
            if fonction.get("membre"):
                membres.append(fonction["membre"])
            types.update(fonction.get("types", []))
        with open(os.path.join(GEN, classe + ".hpp"), "w", encoding="utf-8") as sortie:
            sortie.write(entete(classe, champs, membres, types))


def types_a_declarer(fonctions: list[dict]) -> set[str]:
    """Les types dont ces fonctions réclament la disposition.

    La classe d'une méthode, et tout type nommé dont un corps touche les champs.
    Les deux se déclarent pareil : seul l'endroit d'où vient le besoin diffère.
    """
    besoin: set[str] = set()
    for fonction in fonctions:
        if fonction.get("classe"):
            besoin.add(fonction["classe"])
        besoin.update(fonction.get("champs", {}))
    return besoin


def inclus_ailleurs(classe: str) -> bool:
    """Dit si une source inclut encore l'en-tête engendré de cette classe.

    La question porte sur l'état du disque après réécriture, non sur le plan :
    une source que cette passe n'a pas touchée peut fort bien inclure l'en-tête
    d'une classe dont la passe vient de retirer toutes les fonctions.
    """
    besoin = '#include "gen/%s.hpp"' % classe
    for racine, _sous, fichiers in os.walk(os.path.join(RACINE, "src")):
        for fichier in fichiers:
            if not fichier.endswith((".c", ".cpp")):
                continue
            with open(os.path.join(racine, fichier),
                      encoding="utf-8", errors="replace") as source:
                if besoin in source.read():
                    return True
    return False


def engendrable(classe: str) -> bool:
    """Un en-tête engendré se réécrit ; un en-tête tenu à la main, jamais."""
    chemin = os.path.join(GEN, classe + ".hpp")
    if not os.path.exists(chemin):
        return True
    with open(chemin, encoding="utf-8") as source:
        return ENTETE_ENGENDREE in source.read()


# -- application ----------------------------------------------------------

def ouvre_instantane() -> str:
    """Ouvre le dossier d'instantané de cette exécution, et le rend.

    Les passes anciennes sont gardées : elles disent ce qu'une source portait
    avant chaque tentative, et c'est la seule trace qui survive à une annulation.
    """
    global AVANT
    AVANT = os.path.join(PASSES, datetime.now().strftime("%Y%m%d-%H%M%S"))
    return AVANT


def original(source: str) -> str:
    """Le texte d'avant la passe, copié une fois pour cette exécution.

    Le dossier ne naît qu'à la première copie : un essai à blanc ne laisse
    ainsi pas de trace vide derrière lui.
    """
    copie = os.path.join(AVANT, source.replace("/", "__"))
    if not os.path.exists(copie):
        os.makedirs(AVANT, exist_ok=True)
        shutil.copyfile(os.path.join(RACINE, source), copie)
    with open(copie, encoding="utf-8") as fichier:
        return fichier.read()


def applique(source: str, fonctions: list[dict]) -> None:
    """Réécrit une source depuis son état d'avant, avec ce sous-ensemble."""
    texte = origine = original(source)

    # Une fonction que l'instantané porte déjà écrite n'a rien à recevoir : son
    # corps, son include et ses déclarations y sont. Le plan la garde pour que
    # l'en-tête de sa classe la connaisse, non pour la réécrire — et l'y
    # chercher sous forme d'`INCLUDE_ASM` ferait échouer la passe.
    a_poser = []
    for fonction in fonctions:
        ligne = INCLUDE_ASM % (fonction["chemin_asm"], fonction["symbole"])
        if ligne in texte:
            texte = texte.replace(ligne, fonction["cpp"])
            a_poser.append(fonction)

    fonctions = a_poser

    # Les en-têtes des types dont un corps touche les champs — la classe d'une
    # méthode comme le paramètre d'une fonction libre —, puis les types nommés
    # que les seules signatures emploient, qu'une déclaration en avant suffit à
    # satisfaire.
    declares = types_a_declarer(fonctions)
    includes = sorted('#include "gen/%s.hpp"' % nom for nom in declares)
    avant = [nom for fonction in fonctions for nom in fonction.get("types", [])]
    declarations = sorted({
        "struct %s;" % nom for nom in avant
        if not re.search(r"\b(?:class|struct)\s+%s\b" % re.escape(nom), origine)
        and nom not in declares
    })
    # Une globale ou une fonction C que l'unité connaît déjà ne se redéclare
    # pas : deux déclarations d'un même nom se contrediraient sur son type.
    for fonction in fonctions:
        for ligne in fonction.get("declarations", []):
            nom = re.search(r"(\w+)\s*[;(]", ligne)
            if nom and not re.search(r"\b%s\b" % re.escape(nom.group(1)), origine):
                declarations.append(ligne)
    declarations = sorted(set(declarations))

    ancre = '#include "common.h"'
    if includes and ancre in texte:
        texte = texte.replace(ancre, ancre + "\n" + "\n".join(includes), 1)
    if declarations:
        premier = texte.find("INCLUDE_ASM(")
        coupe = texte.rfind("\n\n", 0, premier) + 1 if premier > 0 else len(texte)
        texte = texte[:coupe] + "\n".join(declarations) + "\n\n" + texte[coupe:]

    with open(os.path.join(RACINE, source), "w", encoding="utf-8") as fichier:
        fichier.write(texte)


# -- mesure ---------------------------------------------------------------

def construit(sources: list[str]) -> bool:
    """Le désassemblage suit le greffage, puis les objets suivent les sources.

    Les objets des unités touchées sont effacés d'abord : une unité qui ne
    compile plus garderait sinon l'objet de la passe précédente, où ses
    fonctions sont encore greffées — donc appariées à 100 % sans qu'une ligne
    tienne. La construction continue malgré une erreur, pour que l'échec d'une
    unité n'emporte pas la mesure des autres.
    """
    # Les contrôles qui ne dépendent pas du désassemblage passent d'abord : ils
    # lisent le texte en une demi-seconde et écartent ce qu'une construction
    # mettrait une minute à découvrir, souvent en nommant autre chose que la
    # vraie cause. Ceux qui portent sur le désassemblage attendent `make setup`,
    # sans quoi une fonction qu'on vient de rendre à l'assembleur paraîtrait
    # orpheline — c'est précisément ce que ce `setup` va réparer.
    if lance(["python3", "scripts/build/controle.py",
              "--avant-setup"]).returncode != 0:
        print("les contrôles échouent sur l'état appliqué")
        return False

    for source in sources:
        objet = os.path.join(RACINE, "build", os.path.splitext(source)[0] + ".o")
        if os.path.exists(objet):
            os.remove(objet)

    if lance(["make", "setup"], stdout=subprocess.DEVNULL).returncode != 0:
        return False

    # Le désassemblage est à jour : ce qui manque désormais manque pour de bon.
    if lance(["python3", "scripts/build/controle.py"]).returncode != 0:
        print("les contrôles échouent après le découpage")
        return False

    journal = os.path.join(RACINE, "progress", "passe_build.log")
    with open(journal, "w", encoding="utf-8") as sortie:
        lance(["make", "-k", "objects"], stdout=sortie, stderr=subprocess.STDOUT)
    return lance(["make", "objdiff.json"], stdout=subprocess.DEVNULL).returncode == 0


def mesure() -> dict[str, float]:
    """La part appariée de chaque fonction, par un seul rapport objdiff."""
    rapport = os.path.join("progress", "passe.json")
    resultat = lance(["objdiff-cli", "report", "generate", "-p", ".",
                      "-o", rapport, "-f", "json"],
                     capture_output=True, text=True)
    if resultat.returncode != 0:
        sys.stderr.write(resultat.stderr[-2000:])
        raise SystemExit("objdiff-cli a échoué")

    with open(os.path.join(RACINE, rapport), encoding="utf-8") as fichier:
        donnees = json.load(fichier)
    parts = {}
    for unite in donnees.get("units", []):
        for fonction in unite.get("functions", []):
            mesures = fonction.get("measures") or fonction
            valeur = mesures.get("fuzzy_match_percent")
            parts[fonction.get("name")] = float(valeur or 0)
    return parts


def seulement_du_bourrage(symbole: str) -> bool:
    """Vrai quand tout l'écart tient au remplissage qui suit la fonction.

    Le désassembleur arrête une fonction à `endlabel` et laisse les `nop`
    d'alignement dehors ; MWCC, lui, les émet dans le symbole qu'il produit.
    objdiff compare alors huit octets à seize et rend zéro pour cent, alors que
    les octets sont ceux du disque. Le verdict revient donc à `make build` —
    ici on ne fait que reconnaître ce cas, sans conclure.
    """
    emplacement = find_symbol(symbole)
    if emplacement.base_object is None:
        return False
    resultat = lance(["objdiff-cli", "diff",
                      "-1", str(emplacement.target_object),
                      "-2", str(emplacement.base_object),
                      "-o", "-", "--format", "json", symbole],
                     capture_output=True, text=True)
    if resultat.returncode != 0:
        return False

    charge = json.loads(resultat.stdout)
    vu = False
    for cote in ("left", "right"):
        for entree in charge.get(cote, {}).get("symbols", []):
            if entree.get("name") != symbole:
                continue
            vu = True
            for ligne in entree.get("instructions", []):
                genre = ligne.get("diff_kind", "DIFF_NONE")
                if genre == "DIFF_NONE":
                    continue
                texte = ligne.get("instruction", {}).get("formatted", "").strip()
                # Un `nop` que nous seuls portons est du remplissage ; tout le
                # reste est une vraie divergence.
                if genre == "DIFF_INSERT" and texte in ("nop", ""):
                    continue
                return False
    return vu


def main(argv: list[str]) -> int:
    parseur = argparse.ArgumentParser(description=__doc__)
    parseur.add_argument("--plan", default="progress/petites.json")
    parseur.add_argument("--essai", action="store_true",
                         help="montre ce qui serait écrit, sans rien construire")
    parseur.add_argument("--limite", type=int, default=0,
                         help="n'applique que les N premières fonctions")
    parseur.add_argument("--source", default="",
                         help="ne travaille que cette unité")
    parseur.add_argument("--garde", action="store_true",
                         help="laisse l'état appliqué, pour l'examiner")
    parseur.add_argument("--diffs", type=int, default=0,
                         help="écrit le diff des N premiers échecs avant d'annuler")
    parseur.add_argument("--sans-reserve", action="store_true",
                         help="s'en tient à la mesure, sans juger le remplissage")
    options = parseur.parse_args(argv)

    with open(os.path.join(RACINE, options.plan), encoding="utf-8") as fichier:
        plan = json.load(fichier)

    # Le drapeau `greffee` du plan vieillit dès qu'une passe écrit : une
    # fonction gagnée depuis n'a plus d'`INCLUDE_ASM`, et la chercher arrêtait
    # la passe en plein milieu, sources à moitié réécrites. La source est le
    # seul état qui fasse foi ; le plan n'en est qu'une vue d'un instant.
    textes: dict[str, str] = {}
    for fonction in plan["fonctions"]:
        chemin = fonction["source"]
        if chemin not in textes:
            with open(os.path.join(RACINE, chemin), encoding="utf-8") as source:
                textes[chemin] = source.read()
        fonction["greffee"] = (
            INCLUDE_ASM % (fonction["chemin_asm"], fonction["symbole"])
        ) in textes[chemin]

    instantane = ouvre_instantane()

    # Une classe que le projet déclare déjà à la main est hors d'atteinte : ses
    # champs portent de vrais noms, et l'accesseur devra les employer.
    tenues, ecartees = {}, {}
    for classe in plan["champs"]:
        ailleurs = deja_declaree(classe)
        if ailleurs or not engendrable(classe):
            ecartees[classe] = ailleurs or "include/gen/%s.hpp tenu à la main" % classe
        else:
            tenues[classe] = {int(k): v for k, v in plan["champs"][classe].items()}

    # Un type dont la fonction touche les champs demande sa disposition, qu'il
    # soit la classe d'une méthode ou le paramètre d'une fonction libre. Une
    # déclaration en avant suffit à passer un pointeur, pas à le déréférencer :
    # `InitSplineKey(SPLINE_KEY *)` échouait sur « illegal use of incomplete
    # struct », et avec elle toute son unité.
    def connus(fonction: dict) -> bool:
        besoin = set(fonction.get("champs", {}))
        if fonction.get("classe"):
            besoin.add(fonction["classe"])
        return besoin <= set(tenues)

    fonctions = [f for f in plan["fonctions"] if connus(f)]
    if options.source:
        fonctions = [f for f in fonctions if options.source in f["source"]]
    if options.limite:
        fonctions = fonctions[:options.limite]

    print("plan : %d fonctions, %d retenues, %d classes déjà déclarées ailleurs"
          % (len(plan["fonctions"]), len(fonctions), len(ecartees)))
    for classe, ou in sorted(ecartees.items())[:8]:
        print("   %-28s déjà dans %s" % (classe, ou))

    par_source: dict[str, list[dict]] = {}
    for fonction in fonctions:
        par_source.setdefault(fonction["source"], []).append(fonction)

    if options.essai:
        for source, lot in sorted(par_source.items()):
            print("  %-34s %3d fonctions" % (source, len(lot)))
        return 0

    # Le plan voyage avec l'instantané : sans lui, l'état d'avant ne dit pas ce
    # qu'on avait tenté d'y poser, et une passe ancienne devient illisible.
    os.makedirs(instantane, exist_ok=True)
    shutil.copyfile(os.path.join(RACINE, options.plan),
                    os.path.join(instantane, "plan.json"))
    print("instantané : %s" % os.path.relpath(instantane, RACINE))

    os.makedirs(GEN, exist_ok=True)
    besoins = types_a_declarer(fonctions)
    ecris_entetes(besoins, fonctions)

    for source, lot in par_source.items():
        applique(source, lot)

    if not construit(list(par_source)):
        print("la construction a échoué : tout est annulé")
        for source in par_source:
            applique(source, [])
        return 1

    parts = mesure()
    # Une fonction que la source portait déjà écrite est acquise : elle n'a pas
    # été posée par cette passe et rien ici ne peut la retirer. La compter parmi
    # les gardées est ce qui maintient sa déclaration dans l'en-tête de sa
    # classe — l'en oublier laissait la source définir une méthode que plus rien
    # ne déclarait, et l'unité ne compilait plus.
    acquises = [f for f in fonctions if not f.get("greffee", True)]
    gardees = [f for f in fonctions
               if f in acquises or parts.get(f["symbole"], 0) >= 99.999]
    perdues = [f for f in fonctions if f not in gardees]

    # Une fonction que seul son remplissage sépare du commerce ne se juge pas à
    # la mesure : on la garde et c'est `make build` qui tranche pour le lot.
    reserve = []
    if not options.sans_reserve:
        reserve = [f for f in perdues if seulement_du_bourrage(f["symbole"])]
        perdues = [f for f in perdues if f not in reserve]
        if reserve:
            print("%d fonctions n'ont que du remplissage en écart"
                  % len(reserve))

    if options.garde:
        print("\n%d appariées sur %d — l'état est laissé en place"
              % (len(gardees), len(fonctions)))
        for fonction in fonctions:
            print("   %-46s %6.2f %%"
                  % (fonction["symbole"][:46], parts.get(fonction["symbole"], 0)))
        return 0

    # Le diff se prend avant d'annuler : après, les objets ne portent plus ce
    # qu'on cherche à comprendre. C'est la seule trace qui survive à la passe.
    if options.diffs and perdues:
        journal = os.path.join(RACINE, "progress", "passe_diffs.txt")
        with open(journal, "w", encoding="utf-8") as sortie:
            for fonction in perdues[:options.diffs]:
                sortie.write("\n%s  %s  %.2f %%\n%s\n"
                             % ("=" * 60, fonction["symbole"],
                                parts.get(fonction["symbole"], 0), fonction["cpp"]))
                sortie.flush()
                lance(["python3", "scripts/diff/diff.py", fonction["symbole"]],
                      stdout=sortie, stderr=subprocess.STDOUT)
        print("diffs : progress/passe_diffs.txt")

    # Ce qui n'apparie pas retrouve son désassemblage, et les classes qui n'ont
    # plus d'accesseur perdent leur en-tête : une déclaration sans emploi est
    # une affirmation gratuite sur la disposition d'une classe.
    def reecris(ensemble: list[dict]) -> None:
        retenues: dict[str, list[dict]] = {}
        for fonction in ensemble:
            retenues.setdefault(fonction["source"], []).append(fonction)
        for source in par_source:
            applique(source, retenues.get(source, []))
        restantes = types_a_declarer(ensemble)
        for classe in sorted(besoins - restantes):
            chemin = os.path.join(GEN, classe + ".hpp")
            # Un en-tête qu'une source inclut encore ne se supprime pas, quoi
            # que la passe ait décidé de ses fonctions. C'est ce retrait qui a
            # laissé `clsmes_00153980.cpp` inclure un `gen/ClsMes.hpp` absent,
            # et la construction échouait sur un message parlant de `this`.
            if os.path.exists(chemin) and not inclus_ailleurs(classe):
                os.remove(chemin)
        # Les champs et les méthodes d'une classe suivent ce qui reste défini :
        # un membre déclaré sans définition ne gêne pas le compilateur, mais il
        # affirmerait une méthode que rien n'a éprouvée.
        ecris_entetes(restantes, ensemble)

    reecris(gardees + reserve)
    print("\n%d fonctions appariées et %d sous réserve, sur %d"
          % (len(gardees), len(reserve), len(fonctions)))
    if perdues:
        print("écartées :")
        for fonction in perdues[:20]:
            print("   %-46s %6.2f %%"
                  % (fonction["symbole"][:46], parts.get(fonction["symbole"], 0)))
        if len(perdues) > 20:
            print("   … et %d autres" % (len(perdues) - 20))

    if not construit(list(par_source)):
        print("la reconstruction a échoué")
        return 1

    # Le verdict du projet, et le seul qui vaille pour les fonctions que la
    # mesure ne sait pas juger : les octets du disque, ou rien.
    if reserve:
        identique = lance(["make", "check"], capture_output=True,
                          text=True).returncode == 0
        print("build après réserve : %s"
              % ("identique au disque" if identique else "divergent"))
        if not identique:
            reecris(gardees)
            if not construit(list(par_source)):
                print("la reconstruction après retrait de la réserve a échoué")
                return 1
            print("réserve retirée : %d fonctions gardées" % len(gardees))
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
