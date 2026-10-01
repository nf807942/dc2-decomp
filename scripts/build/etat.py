#!/usr/bin/env python3
"""Où en est la reconstruction, et à quel rythme elle avance.

    make etat                l'état du jour, et la cadence
    make etat ARGS=--classes ce qui reste, classe par classe
    make etat ARGS=--cibles  les prochaines fonctions, par rendement

La mesure se prend des sources et de la table des symboles, sans rien
construire : une fonction est reconstruite quand une unité déclarée la couvre
et qu'aucune source ne la laisse en `INCLUDE_ASM`. Les deux conditions
comptent — hors des unités déclarées, une fonction n'est ni greffée ni écrite,
et n'en retenir qu'une donnait les 49 `__sinit_*` pour faites.

C'est vrai tant que `make build` passe — c'est lui le verdict, et le dépôt ne
garde pas une source qui diverge. En échange, le chiffre sort en une demi-
seconde sur l'hôte, sans conteneur, ce qui en fait un tableau de bord et non un
rapport de fin de journée. Il tombe sur le même compte que `make report`, qui
l'établit tout autrement — en comparant les objets un à un.

`make report` reste la mesure fine : il compare fonction par fonction et dit
les parts intermédiaires. Les deux ne mesurent pas la même chose et ne se
remplacent pas — celui-ci compte ce qui est écrit, celui-là ce qui apparie.

Chaque exécution inscrit une ligne dans `progress/journal.jsonl`, une par jour.
C'est de là que sort la cadence : sans historique, un chiffre d'avancement ne
dit pas si l'échéance tient.
"""

from __future__ import annotations

import argparse
import collections
import json
import re
import subprocess
import sys
from datetime import date, timedelta
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from lib.mangling import demangle  # noqa: E402
from lib.project import (ROOT, asm_origine, declared_units,  # noqa: E402
                         functions, grafted_by_source, sources)

JOURNAL = ROOT / "progress" / "journal.jsonl"

# Le symbole que porte un `INCLUDE_ASM`, dans le texte que `git grep` rend.
_GREFFE = re.compile(r'INCLUDE_ASM\("[^"]+",\s*([^)]+)\)')

# L'échéance que le plan vise. Elle ne se déduit d'aucune mesure : c'est une
# décision, et la cadence requise s'en déduit, non l'inverse.
ECHEANCE_ANS = 2


def etat() -> dict:
    """Ce qui est écrit, ce qui reste, et sous quelles coupes."""
    table = functions()
    greffe = grafted_by_source()
    greffees = {nom for noms in greffe.values() for nom in noms}

    # Une source greffe un symbole que la table ne connaît pas : c'est une
    # erreur de configuration, pas une fonction. La signaler plutôt que de la
    # compter au dénominateur.
    inconnues = sorted(greffees - set(table))

    par_provenance: dict[str, dict[str, int]] = {}
    for source, noms in greffe.items():
        # `src/game/cmap.cpp` → `game` : le dossier porte la provenance.
        relative = source.relative_to(ROOT).parts
        secteur = relative[1] if len(relative) > 2 else "src"
        seau = par_provenance.setdefault(secteur, {"fn": 0, "octets": 0})
        for nom in noms:
            fonction = table.get(nom)
            if fonction is None or nom in asm_origine():
                continue
            seau["fn"] += 1
            seau["octets"] += fonction.size

    # Une fonction hors de toute unité déclarée n'est ni écrite ni greffée :
    # rien ne la reconstruit et rien ne l'inclut. La compter comme écrite du
    # seul fait qu'aucune source ne la greffe rendait les 49 `__sinit_*` pour
    # faites, et le compte dépassait de 49 celui de `make report`.
    plages = declared_units()
    dedans = {nom for nom, f in table.items()
              if any(bas <= f.address < haut for bas, haut, _ in plages)}

    # Un appel système est de l'assembleur dans la source de Sony : `INCLUDE_ASM` y est
    # la source, non un reste. Il compte « terminé — assembleur d'origine », à part de ce
    # qu'on écrit en C ou en C++.
    origine = asm_origine() & greffees
    restantes = [f for nom, f in table.items() if nom in greffees and nom not in origine]
    d_origine = [f for nom, f in table.items() if nom in origine]
    ecrites = [f for nom, f in table.items()
               if nom in dedans and nom not in greffees]
    dehors = [f for nom, f in table.items() if nom not in dedans]
    total_octets = sum(f.size for f in table.values())

    return {
        "date": date.today().isoformat(),
        "fonctions": len(table),
        "octets": total_octets,
        "fonctions_ecrites": len(ecrites),
        "octets_ecrits": sum(f.size for f in ecrites),
        "fonctions_asm_origine": len(d_origine),
        "octets_asm_origine": sum(f.size for f in d_origine),
        "fonctions_restantes": len(restantes),
        "octets_restants": sum(f.size for f in restantes),
        "fonctions_dehors": len(dehors),
        "octets_dehors": sum(f.size for f in dehors),
        "unites": len(sources()),
        "provenances": par_provenance,
        "inconnues": inconnues,
    }


def journal(courant: dict) -> list[dict]:
    """Ajoute l'état du jour au journal et rend l'historique.

    Une seule ligne par jour : plusieurs mesures dans la même journée
    décriraient une cadence quotidienne à partir d'écarts d'une heure.
    """
    lignes: list[dict] = []
    if JOURNAL.exists():
        for ligne in JOURNAL.read_text(encoding="utf-8").splitlines():
            if ligne.strip():
                lignes.append(json.loads(ligne))

    retenu = {cle: courant[cle] for cle in (
        "date", "fonctions", "octets", "fonctions_ecrites", "octets_ecrits",
        "fonctions_asm_origine", "octets_asm_origine", "unites")}
    lignes = [l for l in lignes if l.get("date") != retenu["date"]]
    lignes.append(retenu)
    lignes.sort(key=lambda l: l["date"])

    JOURNAL.parent.mkdir(exist_ok=True)
    JOURNAL.write_text(
        "".join(json.dumps(l, ensure_ascii=False) + "\n" for l in lignes),
        encoding="utf-8")
    return lignes


def _plages(commit: str) -> list[tuple[int, int]]:
    """Les plages que `config/units.txt` déclarait à ce commit."""
    contenu = subprocess.run(
        ["git", "show", f"{commit}:config/units.txt"],
        cwd=ROOT, capture_output=True, text=True)
    plages = []
    for ligne in contenu.stdout.splitlines():
        ligne = ligne.split("#", 1)[0].split()
        if len(ligne) >= 3 and ligne[0].startswith("0x"):
            plages.append((int(ligne[0], 16), int(ligne[1], 16)))
    return plages


def reconstituer(courant: dict) -> list[dict]:
    """Refait le journal depuis l'historique git, un point par commit.

    Ce que chaque commit laissait greffé se lit dans ses sources, et les
    tailles ne bougent pas : la cadence passée se retrouve donc exactement,
    sans avoir eu à la mesurer sur le moment. Le journal du jour est écrasé par
    cette reconstitution — c'est la même définition, prise sur le même texte.
    """
    table = functions()
    total = sum(f.size for f in table.values())

    listing = subprocess.run(
        ["git", "log", "--reverse", "--format=%H %ad", "--date=short"],
        cwd=ROOT, capture_output=True, text=True, check=True).stdout.splitlines()

    par_jour: dict[str, dict] = {}
    for ligne in listing:
        commit, jour = ligne.split()
        greffe = subprocess.run(
            ["git", "grep", "-h", "-oE",
             r'INCLUDE_ASM\("[^"]+", *[^)]+\)', commit, "--", "src/*.cpp"],
            cwd=ROOT, capture_output=True, text=True)
        # `git grep` rend 1 quand rien ne correspond : avant la première unité
        # ouverte, aucune source ne porte de greffe, et c'est un état valide.
        greffees = {m.group(1) for m in _GREFFE.finditer(greffe.stdout)}

        # Ce qu'un commit avait *écrit* ne se déduit pas de ses greffes seules :
        # une fonction hors de toute unité n'est ni greffée ni écrite. Le
        # découpage de ce commit borne ce qui pouvait l'être, et l'écart entre
        # les deux est la reconstruction.
        plages = _plages(commit)
        if not plages:
            continue
        ouvertes = [f for f in table.values()
                    if any(bas <= f.address < haut for bas, haut in plages)]
        ecrites = [f for f in ouvertes if f.name not in greffees]
        # Les appels système ouverts à ce commit et encore en `INCLUDE_ASM` : leur source
        # d'origine est de l'assembleur, ils sont terminés dès que leur unité existe.
        d_origine = [f for f in ouvertes
                     if f.name in greffees and f.name in asm_origine()]
        par_jour[jour] = {
            "date": jour,
            "fonctions": len(table),
            "octets": total,
            "fonctions_ecrites": len(ecrites),
            "octets_ecrits": sum(f.size for f in ecrites),
            "fonctions_asm_origine": len(d_origine),
            "octets_asm_origine": sum(f.size for f in d_origine),
            "unites": len(plages),
        }

    lignes = sorted(par_jour.values(), key=lambda l: l["date"])
    # L'arbre de travail est le dernier point : ce qui n'est pas commité compte
    # comme fait, sans quoi une passe en cours n'apparaîtrait nulle part.
    lignes = [l for l in lignes if l["date"] != courant["date"]]
    lignes.append({cle: courant[cle] for cle in (
        "date", "fonctions", "octets", "fonctions_ecrites", "octets_ecrits",
        "fonctions_asm_origine", "octets_asm_origine", "unites")})

    JOURNAL.parent.mkdir(exist_ok=True)
    JOURNAL.write_text(
        "".join(json.dumps(l, ensure_ascii=False) + "\n" for l in lignes),
        encoding="utf-8")
    return lignes


def cadence(lignes: list[dict], courant: dict) -> list[str]:
    """Le rythme observé, celui qu'il faudrait, et l'écart entre les deux."""
    sortie: list[str] = []
    reste_fn = courant["fonctions_restantes"]
    reste_o = courant["octets_restants"]

    jours_cible = ECHEANCE_ANS * 365
    sortie.append(
        f"  pour finir en {ECHEANCE_ANS} ans : "
        f"{reste_fn / jours_cible:6.1f} fn/jour   {reste_o / jours_cible:7.0f} o/jour")

    if len(lignes) < 2:
        sortie.append("  rythme observé   : le journal n'a qu'un point ; "
                      "il en faut deux jours différents.")
        return sortie

    debut, fin = lignes[0], lignes[-1]
    jours = (date.fromisoformat(fin["date"]) - date.fromisoformat(debut["date"])).days
    if jours <= 0:
        return sortie

    dfn = fin["fonctions_ecrites"] - debut["fonctions_ecrites"]
    do = fin["octets_ecrits"] - debut["octets_ecrits"]
    sortie.append(
        f"  rythme observé   : {dfn / jours:6.1f} fn/jour   {do / jours:7.0f} o/jour"
        f"   (sur {jours} jours, depuis le {debut['date']})")

    if do > 0:
        # La fin se projette sur les octets : c'est eux que le binaire compte,
        # et le nombre de fonctions surestime l'avancement tant que les petites
        # passent en premier.
        fin_projetee = date.today() + timedelta(days=round(reste_o * jours / do))
        facteur = (reste_o / jours_cible) / (do / jours)
        sortie.append(f"  fin projetée     : {fin_projetee.isoformat()}"
                      f"   — il faut aller {facteur:.1f} fois plus vite")
    else:
        sortie.append("  fin projetée     : jamais, au rythme observé")
    return sortie


def classes(courant: dict) -> list[str]:
    """Ce qui reste, rangé par classe : l'unité de travail du jalon 4."""
    table = functions()
    greffees = {nom for noms in grafted_by_source().values() for nom in noms}

    octets: collections.Counter = collections.Counter()
    compte: collections.Counter = collections.Counter()
    for nom in greffees - asm_origine():
        fonction = table.get(nom)
        if fonction is None:
            continue
        symbole = demangle(nom)
        cle = (symbole.cls if symbole and symbole.cls else "(hors classe)")
        octets[cle] += fonction.size
        compte[cle] += 1

    total = sum(octets.values())
    lignes = [f"  {'classe':28s} {'fn':>5s} {'octets':>9s}  {'part':>6s}  {'cumul':>6s}"]
    cumul = 0
    for nom, poids in octets.most_common(40):
        cumul += poids
        lignes.append(f"  {nom:28s} {compte[nom]:5d} {poids:9d}  "
                      f"{100 * poids / total:5.1f} %  {100 * cumul / total:5.1f} %")
    return lignes


def cibles(courant: dict, combien: int = 30) -> list[str]:
    """Les fonctions restantes les plus lourdes, avec leur source."""
    table = functions()
    rangs = [
        (fonction.size, source, nom)
        for source, noms in grafted_by_source().items()
        for nom in noms
        if nom not in asm_origine() and (fonction := table.get(nom)) is not None
    ]
    rangs.sort(key=lambda r: -r[0])
    return [f"  {'octets':>7s}  {'unité':32s} fonction"] + [
        f"  {taille:7d}  {str(source.relative_to(ROOT).with_suffix('')):32s} {nom}"
        for taille, source, nom in rangs[:combien]]


def main(argv: list[str]) -> int:
    parseur = argparse.ArgumentParser(description=__doc__)
    parseur.add_argument("--classes", action="store_true",
                         help="ce qui reste, classe par classe")
    parseur.add_argument("--cibles", action="store_true",
                         help="les fonctions restantes les plus lourdes")
    parseur.add_argument("--reconstituer", action="store_true",
                         help="refait le journal depuis l'historique git")
    parseur.add_argument("--json", action="store_true",
                         help="l'état brut, pour un autre outil")
    options = parseur.parse_args(argv)

    courant = etat()
    lignes = reconstituer(courant) if options.reconstituer else journal(courant)

    if options.json:
        print(json.dumps(courant, ensure_ascii=False, indent=2))
        return 0

    part_fn = 100 * courant["fonctions_ecrites"] / courant["fonctions"]
    part_o = 100 * courant["octets_ecrits"] / courant["octets"]
    print(f"état au {courant['date']} — ce que les sources écrivent, "
          f"sans construction\n")
    print(f"  écrit    {courant['fonctions_ecrites']:6d} fn "
          f"{courant['octets_ecrits']:10d} o   {part_fn:6.2f} % / {part_o:6.3f} %")
    print(f"  assembleur d'origine {courant['fonctions_asm_origine']:4d} fn "
          f"{courant['octets_asm_origine']:10d} o   terminé : la source de Sony est de l'asm")
    fait_fn = courant["fonctions_ecrites"] + courant["fonctions_asm_origine"]
    fait_o = courant["octets_ecrits"] + courant["octets_asm_origine"]
    print(f"  terminé  {fait_fn:6d} fn {fait_o:10d} o   "
          f"{100 * fait_fn / courant['fonctions']:6.2f} % / {100 * fait_o / courant['octets']:6.3f} %"
          f"   (écrit + assembleur d'origine)")
    print(f"  reste    {courant['fonctions_restantes']:6d} fn "
          f"{courant['octets_restants']:10d} o")
    print(f"  dehors   {courant['fonctions_dehors']:6d} fn "
          f"{courant['octets_dehors']:10d} o   hors de toute unité déclarée")
    print(f"  sur      {courant['fonctions']:6d} fn "
          f"{courant['octets']:10d} o   dans {courant['unites']} unités")

    print("\nce qui reste, par provenance")
    for secteur, seau in sorted(courant["provenances"].items(),
                                key=lambda kv: -kv[1]["octets"]):
        part = 100 * seau["octets"] / courant["octets_restants"]
        print(f"  {secteur:10s} {seau['fn']:6d} fn {seau['octets']:10d} o   {part:5.1f} %")

    print("\ncadence")
    for ligne in cadence(lignes, courant):
        print(ligne)

    if courant["inconnues"]:
        # Le binaire laisse quelques adresses sans nom — `func_00100000` ouvre
        # `crt0`. Ce sont des fonctions à greffer comme les autres, mais faute
        # de taille déclarée elles ne pèsent nulle part.
        print(f"\n{len(courant['inconnues'])} greffes hors du compte, que la "
              f"table ne dimensionne pas : {', '.join(courant['inconnues'][:5])}")

    if options.classes:
        print("\nce qui reste, par classe")
        print("\n".join(classes(courant)))
    if options.cibles:
        print("\nles plus lourdes")
        print("\n".join(cibles(courant)))
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
