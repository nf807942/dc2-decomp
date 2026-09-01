#!/usr/bin/env python3
"""Applique un plan de petites fonctions, le mesure, et annule ce qui rate.

    scripts/host/dc2 python3 scripts/build/passe_petites.py
    scripts/host/dc2 python3 scripts/build/passe_petites.py --essai

Le plan que `scripts/diff/petites.py` propose n'est qu'une proposition : c'est
la construction qui tranche. Cette passe l'applique en bloc, construit, mesure
chaque fonction, puis réécrit les sources en ne gardant que celles qui rendent
les octets du disque. Rien n'est laissé à moitié : une fonction qui n'apparie
pas retrouve son `INCLUDE_ASM`.

L'état d'avant est copié dans `progress/petites_avant/` au premier pas, et
chaque réécriture repart de cette copie : annuler n'est jamais qu'appliquer un
sous-ensemble, ce qui évite d'avoir à retrouver dans le texte ce qu'on y a mis.
"""

from __future__ import annotations

import argparse
import json
import os
import re
import shutil
import subprocess
import sys

RACINE = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
sys.path.insert(0, os.path.join(RACINE, "scripts"))
from lib.project import find_symbol  # noqa: E402
AVANT = os.path.join(RACINE, "progress", "petites_avant")
GEN = os.path.join(RACINE, "include", "gen")

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


def entete(classe: str, champs: dict[int, str], membres: list[str]) -> str:
    """La déclaration provisoire d'une classe, champs connus et remplissage."""
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
    return "\n".join([
        "#ifndef %s" % garde,
        "#define %s" % garde,
        "",
        '#include "common.h"',
        "",
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
        membres = []
        for fonction in fonctions:
            if fonction.get("classe") != classe:
                continue
            if fonction.get("membre"):
                membres.append(fonction["membre"])
            for offset, kind in (fonction.get("champs", {}).get(classe, {})).items():
                champs.setdefault(int(offset), kind)
        with open(os.path.join(GEN, classe + ".hpp"), "w", encoding="utf-8") as sortie:
            sortie.write(entete(classe, champs, membres))


def engendrable(classe: str) -> bool:
    """Un en-tête engendré se réécrit ; un en-tête tenu à la main, jamais."""
    chemin = os.path.join(GEN, classe + ".hpp")
    if not os.path.exists(chemin):
        return True
    with open(chemin, encoding="utf-8") as source:
        return ENTETE_ENGENDREE in source.read()


# -- application ----------------------------------------------------------

def original(source: str) -> str:
    """Le texte d'avant la passe, copié une fois pour toutes."""
    copie = os.path.join(AVANT, source.replace("/", "__"))
    if not os.path.exists(copie):
        os.makedirs(AVANT, exist_ok=True)
        shutil.copyfile(os.path.join(RACINE, source), copie)
    with open(copie, encoding="utf-8") as fichier:
        return fichier.read()


def applique(source: str, fonctions: list[dict]) -> None:
    """Réécrit une source depuis son état d'avant, avec ce sous-ensemble."""
    texte = origine = original(source)

    for fonction in fonctions:
        ligne = INCLUDE_ASM % (fonction["chemin_asm"], fonction["symbole"])
        if ligne not in texte:
            raise SystemExit("%s : %s introuvable" % (source, fonction["symbole"]))
        texte = texte.replace(ligne, fonction["cpp"])

    # Les en-têtes des classes touchées, et les types nommés que les signatures
    # emploient sans que l'unité les connaisse.
    includes = sorted({'#include "gen/%s.hpp"' % f["classe"]
                       for f in fonctions if f.get("classe")})
    avant = [nom for fonction in fonctions for nom in fonction.get("types", [])]
    declarations = sorted({
        "struct %s;" % nom for nom in avant
        if not re.search(r"\b(?:class|struct)\s+%s\b" % re.escape(nom), origine)
        and not any(nom == f.get("classe") for f in fonctions)
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
    for source in sources:
        objet = os.path.join(RACINE, "build", os.path.splitext(source)[0] + ".o")
        if os.path.exists(objet):
            os.remove(objet)

    if lance(["make", "setup"], stdout=subprocess.DEVNULL).returncode != 0:
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

    # Une classe que le projet déclare déjà à la main est hors d'atteinte : ses
    # champs portent de vrais noms, et l'accesseur devra les employer.
    tenues, ecartees = {}, {}
    for classe in plan["champs"]:
        ailleurs = deja_declaree(classe)
        if ailleurs or not engendrable(classe):
            ecartees[classe] = ailleurs or "include/gen/%s.hpp tenu à la main" % classe
        else:
            tenues[classe] = {int(k): v for k, v in plan["champs"][classe].items()}

    fonctions = [f for f in plan["fonctions"]
                 if not f.get("classe") or f["classe"] in tenues]
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

    os.makedirs(GEN, exist_ok=True)
    besoins = {f["classe"] for f in fonctions if f.get("classe")}
    ecris_entetes(besoins, fonctions)

    for source, lot in par_source.items():
        applique(source, lot)

    if not construit(list(par_source)):
        print("la construction a échoué : tout est annulé")
        for source in par_source:
            applique(source, [])
        return 1

    parts = mesure()
    gardees = [f for f in fonctions if parts.get(f["symbole"], 0) >= 99.999]
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
        restantes = {f["classe"] for f in ensemble if f.get("classe")}
        for classe in sorted(besoins - restantes):
            chemin = os.path.join(GEN, classe + ".hpp")
            if os.path.exists(chemin):
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
