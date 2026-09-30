#!/usr/bin/env python3
"""Soumettre une fonction : la poser, la mesurer, la garder ou la rendre.

    make soumettre ARGS="Step__9CGamePadFv essai.cpp"
    make soumettre ARGS="Step__9CGamePadFv essai.cpp --seuil 99.5"

`essai.cpp` contient la définition de la fonction, précédée des déclarations
qu'elle réclame. Le script remplace le `INCLUDE_ASM` du symbole par ce texte,
mesure par `make diff`, puis :

- à `--seuil` (100 par défaut) ou au-delà, la source est gardée ;
- sinon la source revient octet pour octet à ce qu'elle était, et le score,
  avec le diff, est rendu à l'appelant.

**Pourquoi une porte.** Un agent qui édite les sources directement laisse, à la
première interruption, une unité qui ne compile plus — c'est arrivé avec seize
agents à la fois. Ici l'unité n'est jamais dans un état intermédiaire plus
longtemps que la mesure, et un échec de compilation la restitue intacte. C'est
le dispositif que les pipelines à agents publiés (Mizuchi) retiennent : l'agent
soumet, il ne modifie pas.

**Ce que la porte ne prouve pas.** Un 100 % de fonction ne dit rien de
l'image : une fonction de longueur juste mais d'adresse voisine changée déplace
ce qui suit. `make build` reste le verdict, et n'appartient qu'à l'orchestrateur.

Chaque essai s'inscrit dans `progress/essais.jsonl`; `--max-essais` (12 par
défaut) arrête un agent qui s'obstine : au-delà de trois échecs, la
probabilité d'un succès ultérieur tombe à un quart dans les retours publiés, et
cette mesure-ci dira ce qu'elle vaut sur MWCC.
"""

from __future__ import annotations

import argparse
import atexit
import os
import json
import re
import shutil
import subprocess
import sys
import time
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
sys.path.insert(0, str(Path(__file__).resolve().parent))
from declarations import (avant_la_greffe, etat_des_declarations,
                          references)  # noqa: E402
from lib.project import ROOT, grafted_by_source  # noqa: E402
from similaires import fichiers_asm  # noqa: E402

ESSAIS = ROOT / "progress" / "essais.jsonl"
DC2 = ROOT / "scripts" / "host" / "dc2"
_SCORE = re.compile(r"([0-9]+(?:\.[0-9]+)?) % appari")


def essais_de(symbole: str) -> int:
    if not ESSAIS.exists():
        return 0
    # Un essai sans mesure (l'unité ne compilait pas, ou rien n'a répondu)
    # n'use pas le plafond : il n'a rien appris à l'agent.
    lignes = [json.loads(l) for l in ESSAIS.read_text(encoding="utf-8").splitlines() if l]
    return sum(1 for e in lignes if e["symbole"] == symbole and e["score"] is not None)


def journalise(symbole: str, score: float | None, gardee: bool) -> None:
    with ESSAIS.open("a", encoding="utf-8") as f:
        f.write(json.dumps({"symbole": symbole, "score": score,
                            "gardee": gardee, "heure": int(time.time())}) + "\n")


def _extrait(sortie: str, limite: int = 12000) -> str:
    """Le diff en entier tant qu'il tient ; sinon son début, où sont les écarts."""
    return sortie if len(sortie) <= limite else (
        sortie[:limite] + f"\n… ({len(sortie) - limite} caractères de plus)")


VERROUS = ROOT / "progress" / "verrous"


def verrouille(source: Path, attente: int = 300) -> None:
    """Un seul `soumettre` à la fois par unité, libéré à la sortie.

    La source est réécrite entière, et un retour arrière rend les octets qu'elle
    avait à la lecture : deux soumissions concurrentes dans la même unité feraient
    disparaître la fonction que l'une vient de garder. Un verrou vieux de plus de
    dix minutes est celui d'un processus mort.
    """
    VERROUS.mkdir(parents=True, exist_ok=True)
    verrou = VERROUS / (source.stem + ".lock")
    debut = time.time()
    while True:
        try:
            os.close(os.open(verrou, os.O_CREAT | os.O_EXCL | os.O_WRONLY))
            break
        except FileExistsError:
            if time.time() - verrou.stat().st_mtime > 600:
                verrou.unlink(missing_ok=True)
            elif time.time() - debut > attente:
                raise SystemExit(f"{source.name} verrouillée depuis {attente} s "
                                 "par une autre soumission.")
            else:
                time.sleep(1)
    atexit.register(lambda: verrou.unlink(missing_ok=True))


def _erreurs_mwcc(sortie: str) -> str:
    """Les blocs d'erreur de MWCC seuls, sans la trace Python qui les entoure.

    Une compilation qui échoue fait afficher au script de diff une pile d'appels
    de plusieurs dizaines de lignes, au bout de laquelle l'erreur du compilateur
    se perd : les agents la relançaient avec un `grep`.
    """
    lignes = sortie.splitlines()
    blocs = ["\n".join(lignes[i:i + 8])
             for i, ligne in enumerate(lignes) if "Compiler:" in ligne]
    return "\n---\n".join(blocs[:6]) if blocs else _extrait(sortie)


def main() -> int:
    sys.stdout.reconfigure(encoding="utf-8")
    p = argparse.ArgumentParser(description=__doc__.split("\n\n")[0])
    p.add_argument("symbole")
    p.add_argument("essai", type=Path)
    p.add_argument("--seuil", type=float, default=100.0)
    p.add_argument("--max-essais", type=int, default=12)
    p.add_argument("--sdk", action="store_true",
                   help="tente une fonction du SDK ou du runtime (livrés compilés)")
    p.add_argument("--table", action="store_true",
                   help="fonction à table de saut : le nom de la table (@N contre "
                        "_288_…) ne s'apparie jamais, garde à partir de 99,9 %% "
                        "et laisse `make build` trancher")
    p.add_argument("--sans-controle", action="store_true",
                   help="ne vérifie pas les déclarations avant de mesurer")
    a = p.parse_args()

    if a.table:
        a.seuil = min(a.seuil, 99.9)

    if essais_de(a.symbole) >= a.max_essais:
        print(f"{a.symbole} : {a.max_essais} essais déjà faits — laissez-la "
              "et passez à la suivante (make dossier --suivant).")
        return 3

    # Un conteneur indisponible n'est pas une unité qui ne compile pas : le
    # confondre fait dépenser des essais à un agent qui n'y peut rien.
    if not shutil.which("objdiff-cli"):
        moteur = shutil.which("docker") or shutil.which("podman")
        if moteur is None or subprocess.run(
                [moteur, "info"], capture_output=True).returncode != 0:
            print("conteneur indisponible (docker/podman ne répond pas) : "
                  "aucun essai décompté, rien à retenter avant son retour.")
            return 4

    source = next((s for s, noms in grafted_by_source().items()
                   if a.symbole in noms), None)
    if source is None:
        print(f"{a.symbole} : aucune source ne la greffe (déjà écrite ?).")
        return 2

    if source.parent.name in ("sdk", "runtime") and not a.sdk:
        print(f"{a.symbole} : {source.parent.name} est livré compilé (hors de la "
              "chaîne MWCC). Un score de 100 % sur la fonction y cache une "
              "longueur différente : trois fonctions l'ont montré (+8 octets "
              "chacune, toute l'image décalée). --sdk pour tenter quand même.")
        return 6

    verrouille(source)
    original = source.read_bytes()
    texte = original.decode("utf-8")
    ligne = re.compile(
        rf'^[ \t]*INCLUDE_ASM\s*\(\s*"[^"]*"\s*,\s*{re.escape(a.symbole)}\s*\)\s*;[ \t]*\n?',
        re.MULTILINE)
    if not ligne.search(texte):
        print(f"{a.symbole} : INCLUDE_ASM introuvable dans {source}.")
        return 2

    corps = a.essai.read_text(encoding="utf-8").rstrip() + "\n"
    if a.symbole not in corps:
        print("l'essai ne mentionne pas le symbole : il doit le définir.")
        return 2

    # Ce que le désassemblage nomme et que l'essai emploie doit être déclaré,
    # dans l'essai ou dans l'unité : on le sait sans lancer le conteneur, et
    # l'essai n'est pas décompté.
    asm = fichiers_asm().get(a.symbole)
    if asm is not None and not a.sans_controle:
        appeles, donnees = references(asm)
        employes = [n for n in appeles + donnees
                    if n != a.symbole and re.search(rf"\b{re.escape(n)}\b", corps)]
        manque = {n: e for n, e in
                  etat_des_declarations(source, employes, corps,
                                limite=avant_la_greffe(source, a.symbole)).items()
                  if not e["ok"]}
        if manque:
            print("déclarations manquantes — ajoutez-les à l'essai (rien n'a "
                  "été mesuré ni décompté) :")
            for n, e in manque.items():
                if e.get("plus_loin"):
                    print(f"  {n}  déclarée plus loin dans l'unité : recopiez-la "
                          f"telle quelle : {e['plus_loin']}")
                    continue
                print(f"  {n}" + (f"  modèle ({e['modele'][0]}) : {e['modele'][1]}"
                                  if e["modele"] else
                                  "  (aucun modèle : lisez le désassemblage)"))
            return 5

    nouveau = ligne.sub(lambda _: corps, texte, count=1)
    source.write_bytes(nouveau.encode("utf-8"))
    score = None
    try:
        # Dans le conteneur `make` existe déjà ; sur l'hôte on y entre par dc2.
        commande = (["make"] if shutil.which("objdiff-cli")
                    else ["bash", str(DC2), "make"])
        r = subprocess.run([*commande, "diff", f"S={a.symbole}"],
                           capture_output=True, text=True, cwd=ROOT,
                           encoding="utf-8", errors="replace")
        sortie = r.stdout + r.stderr
        m = _SCORE.search(re.sub(r"\x1b\[[0-9;]*m", "", sortie))
        # Une mesure ne vaut que si la greffe a disparu : sans elle, l'unité
        # compilerait son propre assembleur et rendrait 100 % à tout coup.
        greffe_restante = re.search(
            rf'INCLUDE_ASM\s*\([^)]*{re.escape(a.symbole)}\s*\)',
            source.read_text(encoding="utf-8"))
        if m and not greffe_restante:
            score = float(m.group(1))
    except BaseException:
        source.write_bytes(original)
        raise

    gardee = score is not None and score >= a.seuil
    if not gardee:
        source.write_bytes(original)
    journalise(a.symbole, score, gardee)

    if score is None:
        print("aucune mesure : l'unité ne compile pas, ou le diff n'a rien "
              "rendu. Source rétablie.\n" + _erreurs_mwcc(sortie))
        # « undefined identifier 'X' » alors que X existe plus loin dans l'unité :
        # c'est l'ordre des définitions, et les erreurs qui suivent en découlent.
        suite = texte[ligne.search(texte).end():]
        for ident in dict.fromkeys(re.findall(r"undefined identifier '(\w+)'", sortie)):
            m = re.search(rf"\b(?:struct|class|typedef|enum)\b[^;{{]*\b{re.escape(ident)}\b", suite)
            if m:
                print(f"indice : `{ident}` est défini plus loin dans l'unité ; "
                      f"posez `struct {ident};` (déclaration avancée) ou recopiez "
                      "ce dont l'essai a besoin. Les erreurs suivantes en découlent.")
        return 1
    print(f"{a.symbole} : {score:.2f} %  "
          + ("GARDÉE" + (" SOUS RÉSERVE (écart toléré : nom de table)"
                         if score < 100 else "")
             + " — il reste `make build` à l'orchestrateur"
             if gardee else "rendue, source rétablie"))
    if not gardee:
        print(_extrait(sortie))
    return 0 if gardee else 1


if __name__ == "__main__":
    sys.exit(main())
