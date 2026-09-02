#!/usr/bin/env python3
"""Verse les champs de l'atlas dans les classes que le dépôt déclare vides.

    make injecte              écrit, puis `make build` tranche
    make injecte ARGS=--essai montre ce qui serait posé, sans rien écrire

Une classe reconstruite méthode par méthode ne porte longtemps que ses
méthodes : `class CMap { s32 Iam(); };`. Le contexte de m2c écarte alors ce type
— une structure sans champ fait cesser l'inférence sans rien apprendre —, et le
corps qu'il rend parle d'un `unk32C` que l'unité ne connaît pas.

Les champs de `progress/atlas.json` comblent ce vide. **Ils ne changent pas les
octets** : mesuré sur `CMap`, quarante-cinq champs posés et `Iam__4CMapFv`
toujours à 100 %. Une disposition n'est du code que si on l'emploie.

Ce que cet outil pose est ce que m2c a inféré, pas ce que le jeu déclarait : les
noms sont `field_<décalage>` et la dette est assumée. Une classe dont on établit
les vrais noms n'est plus une coquille et sort d'elle-même du champ de l'outil.

**Une classe de base fait exception, et c'est mesuré.** Élargir `mgCCamera` a
décalé tout ce qui en hérite — `CCameraControl`, déjà reconstruite — et la
construction a divergé sur 132 octets de `ceditmap_002F0E80`. L'outil ne sait pas
encore reconnaître ce cas ; `make build` le dit, et il suffit alors de rendre son
état à l'unité fautive. C'est la règle du dépôt : le disque tranche.
"""

from __future__ import annotations

import argparse
import json
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from build.contexte import _CHAMP, _STRUCT, blocs_de_type, nettoie  # noqa: E402
from lib.project import ROOT, sources  # noqa: E402

ATLAS = ROOT / "progress" / "atlas.json"

_LARGEUR = {"s8": 1, "u8": 1, "char": 1, "bool": 1, "s16": 2, "u16": 2,
            "s32": 4, "u32": 4, "f32": 4, "s64": 8, "u64": 8, "f64": 8}


def champs(decrit: dict) -> list[str]:
    """Les lignes de champ d'un type, remplissage compris.

    Même arbitrage que partout ailleurs : la proposition la plus attestée
    l'emporte, et ce que m2c n'a pas su typer devient du remplissage — écrire
    un type qu'on ne sait pas serait une affirmation gratuite.
    """
    lignes, position = [], 0
    for decalage, propositions in decrit["champs"].items():
        kind = next(iter(propositions))
        if "?" in kind or "::" in kind or kind.endswith("]"):
            continue
        if not kind.endswith("*") and kind.rstrip(" *") not in _LARGEUR:
            continue
        offset = int(decalage, 16)
        if offset < position:
            continue
        if offset > position:
            lignes.append("    char pad_%X[0x%X];" % (position, offset - position))
        lignes.append("    %s field_%X;" % (kind, offset))
        position = offset + (4 if kind.endswith("*")
                             else _LARGEUR.get(kind.rstrip(" *"), 4))
    return lignes


def coquilles() -> list[tuple[Path, str, str]]:
    """Les déclarations sans un seul champ : (source, nom du type, bloc)."""
    trouve = []
    for source in sources():
        texte = source.read_text(encoding="utf-8", errors="replace")
        for bloc in blocs_de_type(texte):
            nom = _STRUCT.search(bloc)
            if nom and not _CHAMP.search(nettoie(bloc)):
                trouve.append((source, nom.group(1), bloc))
    return trouve


def pose(bloc: str, lignes: list[str]) -> str:
    """Insère les champs au début du corps, après un `public:` s'il y en a un.

    La place importe : en C++ les membres suivent l'ordre de déclaration, et
    poser les champs après les méthodes laisserait la disposition intacte mais
    la déclaration illisible.
    """
    entrelignes = bloc.splitlines()
    for rang, ligne in enumerate(entrelignes):
        if "{" in ligne:
            depart = rang + 1
            if depart < len(entrelignes) and \
                    entrelignes[depart].strip() in ("public:", "private:", "protected:"):
                depart += 1
            return "\n".join(entrelignes[:depart] + lignes + [""]
                             + entrelignes[depart:])
    return bloc


def main(argv: list[str]) -> int:
    parseur = argparse.ArgumentParser(description=__doc__)
    parseur.add_argument("--essai", action="store_true")
    options = parseur.parse_args(argv)

    if not ATLAS.exists():
        raise SystemExit("progress/atlas.json absent — lancez `make atlas`")
    atlas = json.loads(ATLAS.read_text(encoding="utf-8"))["types"]

    par_source: dict[Path, list[tuple[str, str, list[str]]]] = {}
    for source, nom, bloc in coquilles():
        decrit = atlas.get(nom)
        if decrit is None:
            continue
        lignes = champs(decrit)
        if lignes:
            par_source.setdefault(source, []).append((nom, bloc, lignes))

    total = 0
    for source, lot in sorted(par_source.items()):
        texte = source.read_text(encoding="utf-8", errors="replace")
        for nom, bloc, lignes in lot:
            poses = sum(1 for ligne in lignes if "field_" in ligne)
            total += poses
            print("  %-28s %4d champs   %s"
                  % (nom, poses, source.relative_to(ROOT).as_posix()))
            texte = texte.replace(bloc, pose(bloc, lignes), 1)
        if not options.essai:
            source.write_text(texte, encoding="utf-8")

    print("\n%d champs dans %d classes, %d sources%s"
          % (total, sum(len(l) for l in par_source.values()), len(par_source),
             " (essai, rien écrit)" if options.essai else ""))
    if not options.essai:
        print("`make build` tranche : une disposition ne change les octets que "
              "si le code l'emploie.")
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
