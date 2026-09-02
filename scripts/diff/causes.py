#!/usr/bin/env python3
"""Pourquoi la sortie de m2c ne compile pas — hors de `src/`, pendant la moisson.

    python3 scripts/diff/causes.py --combien 60

Deux tiers des fonctions que la chaîne éprouve s'arrêtent sur « ne compile
pas », et ce seul mot ne dit pas quoi réparer. La boucle de complétion de
`sonde_m2c` demande au compilateur ce qui manque, puis à `declaration()` quoi
écrire ; **quand `declaration()` rend `None`, la fonction est abandonnée**.
C'est donc l'identifiant sur lequel elle cale qu'il faut nommer.

Un tri par mots ne suffit pas — il attrape les commentaires de m2c et les
étiquettes de ses `goto`, et il l'a fait : `maybe`, `block_14`. Seul le
compilateur sait ce qu'il ne connaît pas. Cet outil l'appelle donc pour de bon,
mais sur un fichier d'essai sous `build/essai/`, sans `make` ni mwccgap : la
moisson peut écrire dans `src/` en même temps sans que les deux se gênent.

La boucle est celle de la sonde, à l'identique — cinq tours, les déclarations
que le binaire sait donner ajoutées à chaque coup. Ce qu'elle rapporte est donc
la vraie cause d'arrêt, non une supposition sur elle.
"""

from __future__ import annotations

import argparse
import collections
import json
import random
import re
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
sys.path.insert(0, str(Path(__file__).resolve().parent))
import sonde_m2c  # noqa: E402
from lib.project import ROOT, functions, run, unit_of  # noqa: E402

ETAT = ROOT / "progress" / "chaine.json"
ESSAI = ROOT / "build" / "essai"
MWCC = "tools/compilers/mwcps2-3.0-011126/mwccps2.exe"
DRAPEAUX = ("-c -O4,p -lang c++ -char unsigned -str readonly "
            "-Cpp_exceptions off -RTTI off -sym on -i include -i src").split()

_INCLUDE = re.compile(r'^#include\s+["<][^">]+[">]', re.MULTILINE)
# MWCC ecrit le soulignement sur la ligne `# Error:` et le message sur la
# suivante. Prendre la premiere rendait « ^ », ce qui ne diagnostique rien.
_ERREUR = re.compile(r"^#\s+Error:.*\n#\s+(.+)$", re.MULTILINE)


def famille(nom: str) -> str:
    """Le genre d'identifiant que m2c a laisse sans declaration.

    Les reparations ne sont pas les memes : un emplacement de pile demande une
    variable locale dont la taille se deduit de l'usage, un type manquant un
    typedef, un champ un elargissement de la structure inferee.
    """
    if re.fullmatch(r"sp[0-9A-Fa-f]+", nom):
        return "emplacement de pile (spNN)"
    if re.fullmatch(r"unk[0-9A-Fa-f]+", nom):
        return "champ hors structure inferee (unkNN)"
    if nom.startswith(("temp_", "var_", "phi_")):
        return "temporaire de m2c non declare"
    if re.fullmatch(r"[su]\d+|f\d+|vs?\d+", nom):
        return "type absent de nos en-tetes"
    return "autre"


def compile_essai(texte: str, jeton: str) -> str:
    """Compile un fragment isolé et rend la sortie brute de MWCC."""
    ESSAI.mkdir(parents=True, exist_ok=True)
    fichier = ESSAI / ("%s.c" % jeton)
    fichier.write_text(texte, encoding="utf-8", errors="replace")
    fait = run(["bash", "scripts/host/dc2", "wibo", MWCC, *DRAPEAUX,
                str(fichier.relative_to(ROOT)).replace("\\", "/"),
                "-o", "build/essai/%s.o" % jeton],
               capture_output=True, text=True)
    return fait.stdout + fait.stderr


def cause(symbole: str, unite: str, jeton: str) -> tuple[str, str]:
    """Le motif d'arrêt de cette fonction, et l'identifiant en cause."""
    texte = sonde_m2c.decompile(symbole)
    if texte is None:
        return "m2c refuse", ""
    rendu = sonde_m2c.normalise(texte, symbole, set())
    if rendu is None:
        return "sortie illisible", ""
    declarations, corps = rendu

    # Les mêmes en-têtes que l'unité : sans eux, tout type du projet manquerait
    # et le diagnostic ne parlerait que de cela.
    entetes = "\n".join(_INCLUDE.findall(
        (ROOT / "src" / (unite + ".cpp")).read_text(encoding="utf-8")))

    ajoutees: list[str] = []
    for _tour in range(5):
        sortie = compile_essai(
            "\n".join([entetes, *ajoutees, declarations, corps]), jeton)
        if "Errors caused tool to abort" not in sortie:
            return "compile pourtant", ""
        manquants = sorted(set(sonde_m2c._INCONNU.findall(sortie)))
        if not manquants:
            erreurs = _ERREUR.findall(sortie)
            return ("erreur sans identifiant",
                    erreurs[0][:60] if erreurs else "")
        neuves = [d for d in (sonde_m2c.declaration(nom, declarations + corps)
                              for nom in manquants) if d and d not in ajoutees]
        if not neuves:
            nom = manquants[0]
            if nom in functions():
                return "mangling illisible", nom
            return famille(nom), nom
        ajoutees.extend(neuves)
    return "déclarations sans fin", ""


def main(argv: list[str]) -> int:
    parseur = argparse.ArgumentParser(description=__doc__)
    parseur.add_argument("--combien", type=int, default=60)
    parseur.add_argument("--graine", type=int, default=1)
    options = parseur.parse_args(argv)

    etat = json.loads(ETAT.read_text(encoding="utf-8"))["eprouvees"]
    lot = [nom for nom, v in etat.items()
           if v["issue"] == "ne compile pas" and unit_of(nom)]
    total = len(lot)
    random.Random(options.graine).shuffle(lot)
    lot = lot[:options.combien]
    print("causes : %d fonctions tirees sur %d qui ne compilent pas\n"
          % (len(lot), total), flush=True)

    motifs: collections.Counter = collections.Counter()
    exemples: dict[str, collections.Counter] = collections.defaultdict(
        collections.Counter)
    for rang, symbole in enumerate(lot):
        motif, detail = cause(symbole, unit_of(symbole), "c%d" % rang)
        motifs[motif] += 1
        if detail:
            exemples[motif][detail] += 1
        print("  %-44s %-24s %s" % (symbole[:44], motif, detail[:28]),
              flush=True)

    print("\nresume :")
    for motif, compte in motifs.most_common():
        print("%5d  %-26s %4.0f %%" % (compte, motif, 100.0 * compte / len(lot)))
        for detail, combien in exemples[motif].most_common(6):
            print("         %3d  %s" % (combien, detail[:56]))
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
