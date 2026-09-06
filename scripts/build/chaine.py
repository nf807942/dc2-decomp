#!/usr/bin/env python3
"""La chaîne : traduire, mesurer, garder ce qui rend les octets du disque.

    make chaine                        la fenêtre par défaut, 128 à 512 octets
    make chaine ARGS="--mini 512 --maxi 2048"
    make chaine ARGS=--reprendre       repart de ce que l'état connaît déjà

Ce que `sonde_m2c.py` mesurait sans rien garder, cette chaîne le garde. Chaque
fonction suit le même chemin — m2c avec le contexte, normalisation, complétion
des déclarations, compilation, appariement — et seules celles qui rendent
**exactement** les octets du commerce restent en place. Le reste retrouve son
`INCLUDE_ASM` sans laisser de trace.

**Elle écrit dans les sources, elle ne bâtit pas de plan.** Une première version
mesurait chaque fonction isolément puis appliquait le tout en bloc ; deux choses
l'ont fait échouer, et toutes deux tiennent au même principe. Les déclarations
de deux fonctions d'une même unité se télescopaient, personne ne les ayant vues
ensemble. Et un fragment figé vieillit : le contexte change, m2c ne rend plus le
même corps, et ce qu'on applique n'est plus ce qu'on a mesuré. La source est le
seul état qui fasse foi — chaque fonction est donc éprouvée *par-dessus* celles
que son unité a déjà gagnées.

`make ci` reste le verdict d'ensemble : la chaîne n'affirme rien sur le binaire,
elle ne fait que ne garder que ce qu'objdiff donne pour identique.

**L'état est repris.** `progress/chaine.json` retient ce qui a été éprouvé et son
verdict ; une coupure ne coûte que la fonction en cours, et `--reprendre` ne
refait pas le chemin déjà parcouru.
"""

from __future__ import annotations

import argparse
import collections
import json
import signal
import sys
import time
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "diff"))
import affine  # noqa: E402
import sonde_m2c  # noqa: E402
from lib.project import (ROOT, functions, grafted_by_source,  # noqa: E402
                         run, unit_of)

ETAT = ROOT / "progress" / "chaine.json"


def charge(reprendre: bool) -> dict:
    if reprendre and ETAT.exists():
        return json.loads(ETAT.read_text(encoding="utf-8"))
    return {"eprouvees": {}}


# Les verdicts que *cette* execution a rendus. Le reste de l'etat appartient au
# disque, qu'une purge peut avoir allege entre-temps.
_juges: dict = {}


def enregistre(etat: dict) -> None:
    """Écrit l'état en laissant au disque le dernier mot sur les suppressions.

    La chaîne garde l'état en mémoire et le réécrit après chaque unité. Une
    purge lancée pendant qu'elle tourne était donc annulée à l'unité suivante :
    43 verdicts rendus caducs par un correctif sont ainsi revenus, et la
    moisson les a crus.

    L'écriture repart donc de ce que le disque porte, et n'y applique que les
    verdicts de cette exécution. Une purge faite pendant la passe tient ; le
    travail de la passe aussi.
    """
    ETAT.parent.mkdir(exist_ok=True)
    fond = {}
    if ETAT.exists():
        try:
            fond = json.loads(ETAT.read_text(encoding="utf-8")).get("eprouvees", {})
        except json.JSONDecodeError:
            fond = {}
    fond.update(_juges)
    etat["eprouvees"] = fond
    ETAT.write_text(json.dumps(etat, ensure_ascii=False, indent=1),
                    encoding="utf-8")

def par_unite(mini: int, maxi: int) -> dict[str, list[tuple[int, str]]]:
    """Les candidates de la fenêtre, groupées par unité et triées par poids.

    L'unité est l'échelle de travail : ses fonctions se compilent ensemble et
    partagent leurs déclarations. L'ordre suit le poids, car c'est lui que la
    cadence réclame — une fonction lourde qui apparie vaut vingt accesseurs.
    """
    table = functions()
    greffees = {nom for noms in grafted_by_source().values() for nom in noms}
    groupes: dict[str, list[tuple[int, str]]] = collections.defaultdict(list)
    for nom, fonction in table.items():
        if nom in greffees and mini <= fonction.size <= maxi:
            unite = unit_of(nom)
            if unite:
                groupes[unite].append((fonction.size, nom))
    for lot in groupes.values():
        lot.sort(key=lambda entree: -entree[0])
    return dict(sorted(groupes.items(),
                       key=lambda kv: -sum(t for t, _ in kv[1])))


def recompile_et_mesure(symbole: str, unite: str) -> float | None:
    """Reconstruit l'unité, puis rend l'appariement de la fonction.

    `score()` seul interrogerait objdiff sur l'objet d'avant : la variante que
    l'affinage vient d'écrire ne serait pas mesurée, et son score serait celui
    de la forme précédente. C'est la même erreur que le faux 100 % d'une
    fonction restée greffée, une couche plus loin.
    """
    objet = ROOT / "build" / "src" / (unite + ".o")
    if objet.exists():
        objet.unlink()
    bati = run(["make", str(objet.relative_to(ROOT))],
               capture_output=True, text=True)
    if bati.returncode != 0:
        return None
    return sonde_m2c.score(symbole, unite)


def image_identique() -> bool:
    """L'image liee rend-elle les octets du disque ?

    objdiff compare un objet a un objet : il ne voit ni le lien, ni le
    remplissage qu'une unite porte en queue, ni le decalage qu'un changement
    de taille inflige a tout ce qui suit. C'est la seule mesure qui porte sur
    ce que le projet promet, et la chaine ne peut pas s'en passer.
    """
    bati = run(["make", "build"], capture_output=True, text=True)
    if bati.returncode != 0:
        return False
    image = ROOT / "build" / "main.bin"
    reference = ROOT / "rom" / "main.bin"
    if not (image.exists() and reference.exists()):
        return False
    return image.read_bytes() == reference.read_bytes()


def profil(etat: dict) -> int:
    """Ce que la moisson a rencontré, par cause puis par extrait.

    Le message de MWCC ne suffit plus à décider quoi réparer : les deux
    premières causes recouvrent des fautes sans rapport, et douze témoins sur
    douze compilent hors de leur unité. C'est la ligne que le compilateur
    désigne, chevron compris, qui range.
    """
    eprouvees = etat["eprouvees"]
    issues = collections.Counter(v.get("issue") for v in eprouvees.values())
    print("%d fonctions éprouvées" % len(eprouvees))
    for nom, compte in issues.most_common():
        octets = sum(v.get("taille") or 0 for v in eprouvees.values()
                     if v.get("issue") == nom)
        print("  %5d  %8d o  %s" % (compte, octets, nom))

    for cause, _ in collections.Counter(
            v.get("cause") for v in eprouvees.values()
            if v.get("issue") == "ne compile pas").most_common(6):
        extraits = collections.Counter(
            (v.get("extrait") or "sans extrait")[:64]
            for v in eprouvees.values() if v.get("cause") == cause)
        print("\n%s — %d cas" % (cause, sum(extraits.values())))
        for extrait, compte in extraits.most_common(5):
            print("  %4d  %s" % (compte, extrait))
    return 0


def main(argv: list[str]) -> int:
    parseur = argparse.ArgumentParser(description=__doc__)
    # La fenetre utile, mesuree : 60,5 % de rendement entre 32 et 64 octets,
    # 24,5 % jusqu a 128, 9,8 % jusqu a 256, puis 1,5 %. Au-dela de 512, la
    # moisson ne gagne rien et coute trois quarts d heure par millier de
    # fonctions.
    parseur.add_argument("--mini", type=int, default=32)
    parseur.add_argument("--maxi", type=int, default=512)
    parseur.add_argument("--unites", type=int, default=0,
                         help="s'arrête après N unités")
    parseur.add_argument("--reprendre", action="store_true")
    parseur.add_argument("--profil", action="store_true",
                         help="lit l'état et sort, sans rien éprouver")
    # Une comparaison avant/apres ne vaut que sur la meme population :
    # la moisson reecrit `chaine.json` en mesurant, et deux tirages du
    # meme rang y puisent alors des fonctions differentes. La liste fige
    # les temoins.
    parseur.add_argument("--liste", type=Path, default=None,
                         help="ne traite que les symboles de ce fichier")
    options = parseur.parse_args(argv)

    # `docker stop` envoie SIGTERM, que Python termine sans dérouler les `finally`
    # — la fonction en cours reste alors posée dans sa source sans avoir été
    # mesurée, et `make build` s'écarte de 77 % pour seize octets manquants.
    # `sys.exit` lève `SystemExit`, qui les déroule : la sonde rend sa source.
    signal.signal(signal.SIGTERM, lambda *_: sys.exit(1))

    # Une coupure laisse un objet tronque : `docker stop` interrompt Python,
    # qui rend sa source et supprime l'objet, mais le `make` petit-fils ecrit
    # encore et le recree, partiel. `make` le croit alors a jour et la
    # construction diverge sans qu'aucune source ait change — 76 octets sur
    # deux plages, dans une fonction restee greffee. Les retirer au demarrage
    # coute une reconstruction, soit 1 min 10 s pour une moisson qui dure des
    # heures.
    for objet in (ROOT / "build" / "src").rglob("*.o"):
        objet.unlink()

    etat = charge(options.reprendre)
    if options.profil:
        return profil(etat)

    groupes = par_unite(options.mini, options.maxi)
    if options.reprendre:
        groupes = {unite: [e for e in lot if e[1] not in etat["eprouvees"]]
                   for unite, lot in groupes.items()}
        groupes = {u: l for u, l in groupes.items() if l}
    if options.liste:
        voulus = {ligne.strip() for ligne
                  in options.liste.read_text(encoding="utf-8").splitlines()
                  if ligne.strip()}
        groupes = {u: [e for e in lot if e[1] in voulus]
                   for u, lot in groupes.items()}
        groupes = {u: l for u, l in groupes.items() if l}

    if options.unites:
        groupes = dict(list(groupes.items())[:options.unites])

    total = sum(len(lot) for lot in groupes.values())
    octets = sum(t for lot in groupes.values() for t, _ in lot)
    print("chaîne : %d fonctions dans %d unités, %d octets en jeu, "
          "de %d à %d octets"
          % (total, len(groupes), octets, options.mini, options.maxi))

    gagnees, gagnes, faits, depart = 0, 0, 0, time.time()
    for unite, lot in groupes.items():
        print("\n%s — %d fonctions, %d octets"
              % (unite, len(lot), sum(t for t, _ in lot)), flush=True)
        depart_unite = (ROOT / "src" / (unite + ".cpp")).read_text(
            encoding="utf-8")
        avant_unite, octets_avant_unite = gagnees, gagnes
        for taille, symbole in lot:
            verdict = sonde_m2c.eprouve(symbole, unite, taille, garde=True)
            faits += 1
            part = verdict.get("part")

            # Une fonction qui compile sans apparier n'est pas perdue : les
            # idiomes mesurés valent d'être essayes avant de la rendre. La
            # sonde, elle, l'abandonnait a 93 %.
            if part is not None and 85.0 <= part < 99.999:
                part, gagnee_par_idiome = affine.affine(
                    symbole, unite, part, recompile_et_mesure)
                if gagnee_par_idiome:
                    verdict["part"] = part
                    verdict["idiome"] = True
            # Le verdict va dans les deux : la memoire sert au tri de la
            # passe, `_juges` a l'ecriture, qui repart du disque.
            _juges[symbole] = etat["eprouvees"][symbole] = {
                "issue": verdict["issue"], "part": part, "taille": taille,
                # La cause, et non la seule issue : c'est elle qui dit quelle
                # correction paierait le plus au tour suivant, et la relever
                # après coup demanderait de tout réexécuter.
                "cause": verdict.get("cause", ""),
                # Et la ligne que MWCC désigne : le message seul ne dit pas
                # quoi réparer — 256 « declaration syntax error » ne venaient
                # que de trois unités amputées, ce que le chevron sous une
                # accolade seule a nommé du premier coup.
                "extrait": verdict.get("extrait", ""), "unite": unite,
                # Les instructions qui divergent, sur un quasi-succès. C'est
                # ce qui permet de grouper les échecs par *forme d'écart*
                # plutôt que par message du compilateur — la même méthode, un
                # cran plus bas.
                "ecarts": verdict.get("ecarts", [])}

            # **Le quasi-succes est le vrai produit de la moisson.** 657
            # fonctions compilent entre 85 et 100 % — 87 236 octets de binaire
            # dont 5 708 seulement divergent —, et la chaine les rendait a leur
            # greffe en jetant leur C++. L'affinage n'avait donc qu'une seule
            # chance, immediate, et repartir de zero demandait de retraduire.
            #
            # Le fragment se garde sous `build/`, hors de git : il est derive du
            # jeu. C'est le corpus sur lequel un idiome se mesure sans que rien
            # ne recompile m2c.
            if (part is not None and 85.0 <= part < 99.999
                    and verdict.get("fragment")):
                garde = ROOT / "build" / "proches"
                garde.mkdir(parents=True, exist_ok=True)
                (garde / (symbole + ".cpp")).write_text(
                    verdict["fragment"], encoding="utf-8")

            if part is not None and part >= 99.999:
                gagnees += 1
                gagnes += taille
                print("  %5d o  %-46s  gagnée" % (taille, symbole[:46]),
                      flush=True)
            elif part is not None:
                print("  %5d o  %-46s  %5.1f %%"
                      % (taille, symbole[:46], part), flush=True)
        # **objdiff ne voit qu'un objet, jamais le binaire lie.** Une fonction
        # peut y apparier a 100 % et changer pourtant l'image : degreffer la
        # derniere fonction d'une unite en retire le remplissage de queue, et
        # tout ce qui suit se decale. Mesure au prix fort : 546 fonctions
        # annoncees gagnees, 53 % des octets divergents, et une bissection
        # pour trouver l'unite en cause.
        if gagnees > avant_unite and not image_identique():
            print("  l'image diverge : %s revient a son etat d'entree"
                  % unite, flush=True)
            (ROOT / "src" / (unite + ".cpp")).write_text(
                depart_unite, encoding="utf-8")
            for _, symbole in lot:
                fiche = etat["eprouvees"].get(symbole)
                if fiche and (fiche.get("part") or 0) >= 99.999:
                    fiche["issue"] = "image divergente"
                    fiche["part"] = None
            gagnees, gagnes = avant_unite, octets_avant_unite
        elif gagnees == avant_unite:
            # **Une unite qui n'a rien gagne doit sortir comme elle est
            # entree.** Le controle ci-dessus ne s'arme que sur un gain ; une
            # source qu'un affinage sans succes aurait laissee modifiee ne
            # serait donc relue par personne. Comparer les textes coute un
            # `read`, la ou verifier l'image couterait un lien complet.
            source = ROOT / "src" / (unite + ".cpp")
            if source.read_text(encoding="utf-8") != depart_unite:
                print("  %s a change sans gagner : retour a son etat d'entree"
                      % unite, flush=True)
                source.write_text(depart_unite, encoding="utf-8")
        enregistre(etat)

    ecoule = time.time() - depart
    print("\n%d fonctions gagnées sur %d éprouvées — %d octets, %.1f s chacune"
          % (gagnees, faits, gagnes, ecoule / faits if faits else 0))
    compte: dict[str, int] = {}
    for decrit in etat["eprouvees"].values():
        compte[decrit["issue"]] = compte.get(decrit["issue"], 0) + 1
    for issue, combien in sorted(compte.items(), key=lambda kv: -kv[1]):
        print("  %-18s %4d" % (issue, combien))
    print("\nles sources portent ce qui a été gagné ; `make ci` tranche.")
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
