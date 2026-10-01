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


def bash_hote() -> str:
    """Sous Windows, choisir Git Bash avant le relais WSL nommé `bash`."""
    if os.name == "nt":
        git = shutil.which("git")
        if git:
            candidat = Path(git).parent.parent / "usr" / "bin" / "bash.exe"
            if candidat.exists():
                return str(candidat)
    return shutil.which("bash") or "bash"


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


GCC_UNITES = ROOT / "config" / "gcc_units.txt"


def nom_unite(source: Path) -> str:
    """`src/runtime/copysign.cpp` → `runtime/copysign`, le nom de `gcc_units.txt`."""
    return source.relative_to(ROOT / "src").with_suffix("").as_posix()


def fonction_mwcc(symbole: str) -> bool:
    """MWCC a-t-il compilé cette fonction ? `.mwcats` le dit, le dossier de l'unité non.

    Des fonctions du jeu (`csound.cpp`) et de l'exécution C++ (`std::exception::what`) sont
    rangées sous `src/sdk/` et `src/runtime/` : c'est le classement par dossier, une
    heuristique. Elles passent par MWCC comme tout le jeu ; seules celles que `.mwcats` ne
    liste pas relèvent d'`ee-gcc`.
    """
    sys.path.insert(0, str(Path(__file__).resolve().parent))
    import provenance
    from lib.project import functions
    f = functions().get(symbole)
    return f is not None and f.address in provenance.compilees()


def unites_gcc() -> set[str]:
    if not GCC_UNITES.exists():
        return set()
    return {l.strip() for l in GCC_UNITES.read_text(encoding="utf-8").splitlines()
            if l.strip() and not l.lstrip().startswith("#")}


def modifier_liste_gcc(unite: str, ajouter: bool) -> None:
    """Ajoute ou retire une unité de la liste, sous un verrou court.

    Plusieurs agents peuvent ajouter chacun la leur au même moment : lire, changer
    et réécrire le fichier sans verrou en perdrait.
    """
    VERROUS.mkdir(parents=True, exist_ok=True)
    verrou = VERROUS / "gcc_units.lock"
    debut = time.time()
    while True:
        try:
            os.close(os.open(verrou, os.O_CREAT | os.O_EXCL | os.O_WRONLY))
            break
        except FileExistsError:
            if time.time() - verrou.stat().st_mtime > 60 or time.time() - debut > 60:
                verrou.unlink(missing_ok=True)
            else:
                time.sleep(0.2)
    try:
        lignes = GCC_UNITES.read_text(encoding="utf-8").splitlines()
        lignes = [l for l in lignes if l.strip() != unite]
        if ajouter:
            lignes.append(unite)
        GCC_UNITES.write_text("\n".join(lignes) + "\n", encoding="utf-8", newline="\n")
    finally:
        verrou.unlink(missing_ok=True)


def _diff_court(sortie: str, contexte: int = 3, long: int = 50) -> str:
    """Le diff en entier s'il est court ; sinon l'en-tête et les seules lignes qui divergent.

    Une fonction de trois cents instructions rend un tableau de trois cents lignes dont une
    poignée seulement porte `≠`, `+` ou `-` : les agents le réduisaient à la main avec `grep`.
    """
    lignes = sortie.splitlines()
    if len(lignes) <= long:
        return sortie
    marque = [i for i, l in enumerate(lignes) if l[:1] in ("≠", "+", "-", "~")
              and not l.startswith("---")]
    if not marque:
        return _extrait(sortie)
    garder = set(range(0, min(8, len(lignes))))
    for i in marque:
        garder.update(range(max(0, i - contexte), min(len(lignes), i + contexte + 1)))
    sortie_c, precedent = [], -1
    for i in sorted(garder):
        if precedent != -1 and i != precedent + 1:
            sortie_c.append("    …")
        sortie_c.append(lignes[i])
        precedent = i
    return "\n".join(sortie_c) + f"\n({len(marque)} lignes divergent sur {len(lignes)})"


def _erreurs_gcc(sortie: str) -> str:
    """Les lignes d'erreur de GCC (`fichier:ligne: message`), sans la trace qui suit."""
    lignes = [l for l in sortie.splitlines() if re.match(r"^\S+:\d+: ", l)]
    return "\n".join(lignes[:12])


def _erreurs_mwcc(sortie: str) -> str:
    """Les blocs d'erreur de MWCC seuls, sans la trace Python qui les entoure.

    Une compilation qui échoue fait afficher au script de diff une pile d'appels
    de plusieurs dizaines de lignes, au bout de laquelle l'erreur du compilateur
    se perd : les agents la relançaient avec un `grep`.
    """
    lignes = sortie.splitlines()
    blocs = ["\n".join(lignes[i:i + 8])
             for i, ligne in enumerate(lignes) if "Compiler:" in ligne]
    if blocs:
        return "\n---\n".join(blocs[:6])
    return _erreurs_gcc(sortie) or _extrait(sortie)


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

    # Le SDK Sony et la bibliothèque C du jeu ne sortent pas de MWCC : leurs
    # unités passent par la voie GCC (`config/gcc_units.txt`, ee-gcc 2.9). Une
    # unité de ces dossiers y entre pour la durée de la mesure et n'y reste que
    # si la fonction est gardée. Elle est refusée si elle contient déjà du code
    # que MWCC a compilé : le compiler autrement changerait ce qui est déjà écrit.
    unite = nom_unite(source)
    ajoutee_a_la_liste = False

    verrouille(source)
    # Décidé SOUS le verrou de l'unité : deux soumissions de la même unité peuvent attendre
    # ensemble, et celle qui calculait avant le verrou retirait de la liste une unité que
    # l'autre venait de garder (la fonction gardée aurait alors été compilée par MWCC).
    if (source.parent.name in ("sdk", "runtime") and not fonction_mwcc(a.symbole)
            and unite not in unites_gcc()):
        code = re.sub(r'INCLUDE_ASM\s*\([^)]*\)', "", source.read_text(encoding="utf-8"))
        if re.search(r"\)\s*\{", code) and not a.sdk:
            print(f"{a.symbole} : l'unité {unite} contient déjà du code compilé par MWCC ; "
                  "la passer en GCC le changerait. --sdk pour forcer.")
            return 6
        ajoutee_a_la_liste = True

    original = source.read_bytes()
    texte = original.decode("utf-8")
    ligne = re.compile(
        rf'^[ \t]*INCLUDE_ASM\s*\(\s*"[^"]*"\s*,\s*{re.escape(a.symbole)}\s*\)\s*;[ \t]*\n?',
        re.MULTILINE)
    if not ligne.search(texte):
        print(f"{a.symbole} : INCLUDE_ASM introuvable dans {source}.")
        return 2

    brut = a.essai.read_bytes()
    try:
        texte_essai = brut.decode("utf-8")
    except UnicodeDecodeError:
        # Un script qui a écrit l'essai sous Windows l'a écrit en cp1252 : on le lit tel quel
        # et on le réécrit en UTF-8 dans la source, sans jeter l'essai pour si peu.
        texte_essai = brut.decode("cp1252", errors="replace")
        print("l'essai n'est pas en UTF-8 : lu en cp1252.")
    corps = texte_essai.rstrip() + "\n"
    # Dans une unité GCC, newlib définit souvent la fonction sous un alias d'en-tête
    # (`Balloc` pour `_Balloc`) : le symbole n'y figure pas toujours tel quel, et le
    # compilateur, puis la mesure, disent si la bonne fonction est définie.
    if a.symbole not in corps and source.parent.name not in ("sdk", "runtime"):
        print("l'essai ne mentionne pas le symbole : il doit le définir.")
        return 2

    # Ce que le désassemblage nomme et que l'essai emploie doit être déclaré,
    # dans l'essai ou dans l'unité : on le sait sans lancer le conteneur, et
    # l'essai n'est pas décompté.
    asm = fichiers_asm().get(a.symbole)
    # Les unités de la voie GCC incluent les vrais en-têtes de newlib : le compilateur
    # dit ce qui manque, mieux que ce contrôle qui lit les déclarations MWCC de l'unité.
    if asm is not None and not a.sans_controle and source.parent.name not in ("sdk", "runtime"):
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
    if ajoutee_a_la_liste:
        modifier_liste_gcc(unite, ajouter=True)
    score = None
    try:
        # Dans le conteneur `make` existe déjà ; sur l'hôte on y entre par dc2.
        dans_conteneur = not shutil.which("objdiff-cli")
        commande = ([bash_hote(), str(DC2), "make"] if dans_conteneur
                    else ["make"])
        environnement = None
        if os.name == "nt" and dans_conteneur:
            # Git Bash lance le script depuis Python sans préparer son PATH.
            # Ses utilitaires (dirname, env, sh) doivent précéder le relais WSL.
            git_bin = Path(commande[0]).parent
            environnement = os.environ.copy()
            environnement["PATH"] = (str(git_bin) + os.pathsep +
                                     str(git_bin.parent.parent / "mingw64" / "bin") +
                                     os.pathsep + environnement.get("PATH", ""))
        r = subprocess.run([*commande, "diff", f"S={a.symbole}"],
                           capture_output=True, text=True, cwd=ROOT,
                           encoding="utf-8", errors="replace",
                           env=environnement)
        sortie = r.stdout + r.stderr
        m = _SCORE.search(re.sub(r"\x1b\[[0-9;]*m", "", sortie))
        # Une mesure ne vaut que si la greffe a disparu : sans elle, l'unité
        # compilerait son propre assembleur et rendrait 100 % à tout coup.
        greffe_restante = re.search(
            rf'INCLUDE_ASM\s*\(\s*"[^"]*"\s*,\s*{re.escape(a.symbole)}\s*\)',
            source.read_text(encoding="utf-8"))
        if m and not greffe_restante:
            score = float(m.group(1))
    except BaseException:
        source.write_bytes(original)
        if ajoutee_a_la_liste:
            modifier_liste_gcc(unite, ajouter=False)
        raise

    gardee = score is not None and score >= a.seuil
    if not gardee:
        source.write_bytes(original)
        if ajoutee_a_la_liste:
            modifier_liste_gcc(unite, ajouter=False)
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
        print(_diff_court(sortie))
    return 0 if gardee else 1


if __name__ == "__main__":
    sys.exit(main())
