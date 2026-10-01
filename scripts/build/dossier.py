#!/usr/bin/env python3
"""Le dossier d'une fonction, et la file d'où les agents la tirent.

    make dossier ARGS="Step__9CGamePadFv"      # tout ce qu'il faut pour l'écrire
    make dossier ARGS="--suivant 8 --agent a1" # réserve les 8 prochaines fonctions
    make dossier ARGS="--libere a1"            # rend les réservations d'un agent
    make dossier ARGS="--file"                 # la file, sans réserver

**Pourquoi.** Un agent qui démarre à froid dépense l'essentiel de ses jetons à
chercher : le désassemblage, les signatures des appelés, une fonction sœur déjà
écrite, la disposition de la classe. Les retours publiés des projets qui
décompilent avec des agents disent la même chose — le contexte utile est celui
qu'on lui met sous les yeux *pour cette fonction*, non celui qu'il rassemble
seul. Ce module l'assemble une fois, en quelques millisecondes.

**La file** range les fonctions par ce qui promet le mieux, et se le dit :

1. un jet sous `build/proches/` (85–100 % mesurés) passe devant tout — c'est le
   rendement de l'affinage, le plus élevé du dépôt ;
2. viennent celles qui ont une sœur écrite (`make similaires`), parce que
   l'exemple a déjà passé le compilateur ;
3. puis les courtes, dont le coût par octet gagné est le plus bas.

Les réservations tiennent dans `progress/reservations.json`, avec une heure
d'expiration : plusieurs agents peuvent tirer dans la même file sans se marcher
dessus, et une réservation abandonnée se libère seule.
"""

from __future__ import annotations

import argparse
import json
import re
import sys
import time
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
sys.path.insert(0, str(Path(__file__).resolve().parent))
from lib.mangling import demangle  # noqa: E402
from lib.project import (ROOT, functions, grafted_by_source,  # noqa: E402
                         grafted_symbols)
from declarations import (avant_la_greffe, etat_des_declarations,
                          references, types_non_declares)  # noqa: E402
from similaires import ASM_DIR, corps_ecrit, fichiers_asm  # noqa: E402

RESERVATIONS = ROOT / "progress" / "reservations.json"
SIMILAIRES = ROOT / "progress" / "similaires.json"
PROCHES = ROOT / "build" / "proches"
EXPIRATION = 6 * 3600

_INSTR = re.compile(r"^[ \t]*/\*[^*]*\*/[ \t]+(.*\S)", re.MULTILINE)
_JAL = re.compile(r"\bj(?:al)?\s+([A-Za-z_]\w*)")


def asm_lisible(chemin: Path) -> str:
    texte = chemin.read_text(encoding="utf-8", errors="replace")
    return "\n".join(re.sub(r"\s+", " ", m) for m in _INSTR.findall(texte))


def appeles(chemin: Path) -> list[str]:
    vus: list[str] = []
    for c in _JAL.findall(chemin.read_text(encoding="utf-8", errors="replace")):
        if c not in vus:
            vus.append(c)
    return vus


def source_de(nom: str) -> Path | None:
    for src, noms in grafted_by_source().items():
        if nom in noms:
            return src
    return None


def signature(nom: str) -> str:
    s = demangle(nom)
    if s is None:
        return nom
    args = ", ".join(s.params) if s.params else "void"
    tete = f"{s.cls}::{s.name}" if s.cls else s.name
    return f"{tete}({args})"


_MMI = re.compile(r"\b(pcpy\w+|padd\w+|psub\w+|pand|por|pnor|pxor|pext\w+|pmul\w+|pdiv\w+|pmax\w+|pmin\w+|pcgt\w+|pceq\w+|psll\w+|psrl\w+|psra\w+|ppac\w+|qmtc2|qmfc2|lqc2|sqc2|mfhi1|mflo1|mult1|madd1)\b")


def section_gcc(nom: str, src: Path, asm: Path | None) -> str:
    """Ce qu'il faut savoir pour écrire une fonction du SDK ou de la libc : la voie GCC."""
    l = ["\n## voie GCC (ee-gcc 2.9-ee, du C — non du C++ de MWCC)",
         "Cette unité ne sort pas de MWCC : `soumettre` la compile avec `ee-gcc` (`-O2 -G0`),",
         "en C, avec les en-têtes de newlib (`<stdio.h>`, `\"local.h\"`…) et `include/gcc/` "
         "(`ieee754.h` pour les mots d'un flottant). Voir docs/METHODE_GCC.md."]
    if asm is not None:
        mmi = sorted(set(_MMI.findall(asm.read_text(encoding="utf-8", errors="replace"))))
        if mmi:
            l.append("ATTENTION : instructions MMI/COP2 (" + ", ".join(mmi[:6]) + ") — "
                     "probablement de l'assembleur écrit à la main par Sony (comme `strlen`), "
                     "que le C de newlib ne rendra pas. Mesurez d'abord ; sinon elle reste en "
                     "assembleur de référence.")
    try:
        from newlib_source import cherche, INDEX
        if INDEX.exists():
            trouves = cherche(nom, "newlib-1_9_0")
            if trouves:
                l.append("Sources de newlib 1.9.0 candidates (`newlib_source.py " + nom
                         + " [chemin]` les aplatit pour `gcc_essai.py`) :")
                l += [f"  - {rel}   ({pourquoi})" for rel, pourquoi in trouves[:5]]
            else:
                l.append("Aucune source de newlib trouvée pour ce nom : code de Sony (SDK) ou "
                         "alias du préprocesseur. Écrivez-la d'après le désassemblage ; "
                         "`ps2sdk` donne les prototypes.")
    except Exception:  # noqa: BLE001 — l'index manque ou la recherche échoue : on s'en passe
        l.append("(index de newlib absent : `make tools TOOLS_ARGS=--gcc`)")
    deja = sorted(u.strip() for u in (ROOT / "config" / "gcc_units.txt")
                  .read_text(encoding="utf-8").splitlines()
                  if u.strip() and not u.lstrip().startswith("#"))[:6]
    if deja:
        l.append("Unités déjà écrites par cette voie, pour modèle : " + ", ".join(deja))
    l += ["Mesurer une forme sur toutes les versions d'ee-gcc : "
          f"`scripts/host/dc2 python3 scripts/build/gcc_essai.py {nom} essai.c --montre`",
          "Une différence d'une instruction tient souvent à la version de newlib (ex. `std` de "
          "findfp.c n'a pas `_bf._size = 0;` dans le jeu) : retirez ou ajoutez la ligne."]
    return "\n".join(l)


def dossier(nom: str) -> str:
    table = functions()
    if nom not in table:
        return f"symbole inconnu : {nom}\n"
    f = table[nom]
    asm = fichiers_asm().get(nom)
    sortie: list[str] = []
    src = source_de(nom)
    sortie.append(f"# {nom}\n{signature(nom)}\n"
                  f"adresse 0x{f.address:08X}, {f.size} octets"
                  + (f", unité {src.relative_to(ROOT)}" if src else ""))
    sym = demangle(nom)
    if sym and sym.cls:
        for cand in (ROOT / "include" / "gen" / f"{sym.cls}.hpp",):
            if cand.exists():
                sortie.append(f"classe : {cand.relative_to(ROOT)}")

    draft = PROCHES / f"{nom}.cpp"
    if draft.exists():
        sortie.append("\n## jet existant (85–100 %), à corriger plutôt qu'à réécrire\n"
                      + draft.read_text(encoding="utf-8", errors="replace"))

    if SIMILAIRES.exists():
        v = json.loads(SIMILAIRES.read_text(encoding="utf-8"))["voisins"].get(nom, [])
        for voisin in v[:2]:
            corps = corps_ecrit(voisin["voisin"])
            if corps:
                sortie.append(f"\n## sœur écrite : {voisin['voisin']} "
                              f"(ressemblance {voisin['score']})\n{corps}")

    if asm:
        sortie.append("\n## appelés")
        restantes = grafted_symbols()
        for c in appeles(asm):
            etat = "à écrire" if c in restantes else "écrit"
            sortie.append(f"- {c} — {signature(c)} [{etat}]")
        if src is not None:
            appeles_, donnees_ = references(asm)
            # La fonction elle-même d'abord : une déclaration existante dans l'unité
            # impose sa signature à la définition (« illegal function overloading »).
            etat = etat_des_declarations(src, [nom] + appeles_ + donnees_,
                                         limite=avant_la_greffe(src, nom))
            sortie.append(f"\n## déclarations visibles depuis {src.relative_to(ROOT)}")
            for n, e in etat.items():
                if n == nom:
                    if e["ok"] or e.get("plus_loin"):
                        sortie.append(f"- {n} (la fonction elle-même) : déjà déclarée dans "
                                      f"l'unité — la définition doit reprendre cette signature "
                                      f"et ce retour : {e.get('ligne') or e['plus_loin']}")
                        if "(...)" in (e.get("ligne") or e["plus_loin"]):
                            sortie.append("    ATTENTION : déclarée en (...) — une définition à "
                                          "paramètres typés est refusée (« illegal function "
                                          "overloading »). Signalez-le à l'orchestrateur : il type "
                                          "cette ligne de l'unité (neutre en octets), puis "
                                          "soumettez l'essai.")
                    continue
                if e["ok"]:
                    imposee = ("signature imposée : la recopier, convertir au site d'appel"
                               if "(" in e["ligne"] else
                               "type imposé : un essai ne le redéfinit pas ; un champ "
                               "manquant s'ajoute dans l'unité (taille inchangée)")
                    sortie.append(f"- {n} : {e['ou']} — {e['ligne']}  [{imposee}]")
                    if "(" not in e["ligne"]:
                        inconnus = types_non_declares(src, e["ligne"],
                                                      avant_la_greffe(src, nom))
                        if inconnus:
                            sortie.append("    types à déclarer en avant dans l'essai (définis "
                                          "plus loin ou ailleurs) : "
                                          + ", ".join(f"struct {t};" for t in inconnus))
                elif e.get("plus_loin"):
                    sortie.append(f"- {n} : déclarée PLUS LOIN dans l'unité, donc pas "
                                  f"visible de la fonction — la recopier telle quelle "
                                  f"dans l'essai (une autre forme est refusée) : {e['plus_loin']}")
                elif e["modele"]:
                    sortie.append(f"- {n} : NON DÉCLARÉ ici — à déclarer dans "
                                  f"l'essai, modèle ({e['modele'][0]}) : {e['modele'][1]}")
                else:
                    sortie.append(f"- {n} : non trouvé ici ni ailleurs — "
                                  "sa nature (fonction, u32, tableau) se lit au désassemblage")
        sortie.append("\n## désassemblage\n" + asm_lisible(asm))

    if src is not None and src.parent.name in ("sdk", "runtime"):
        sortie.append(section_gcc(nom, src, asm))

    sortie.append(
        "\n## vérifier\n"
        f"  make decompile S={nom}     # jet m2c\n"
        f"  make diff S={nom}          # match_percent, verdict\n"
        "  idiomes MWCC : docs/IDIOMES_MWCC.md — chaque écart de registre "
        "ou d'ordre y a une entrée.")
    return "\n".join(sortie) + "\n"


# ----------------------------------------------------------------- la file --

def charge_reservations() -> dict[str, dict]:
    if not RESERVATIONS.exists():
        return {}
    brut = json.loads(RESERVATIONS.read_text(encoding="utf-8"))
    now = time.time()
    return {n: r for n, r in brut.items() if now - r["heure"] < EXPIRATION}


def file_priorite() -> list[str]:
    table = functions()
    # Le SDK Sony et le runtime Metrowerks sont livrés compilés (absents de
    # `.mwcats`) : MWCC n'en rend pas les octets, et une fonction « à 100 % »
    # peut allonger l'unité de huit octets et décaler tout ce qui suit.
    hors_chaine = {n for src, ns in grafted_by_source().items()
                   if src.parent.name in ("sdk", "runtime") for n in ns}
    # Les appels système sont de l'assembleur dans la source de Sony : terminés (`asm_origine`).
    from lib.project import asm_origine
    restantes = [n for n in grafted_symbols()
                 if n in table and table[n].size and n not in hors_chaine
                 and n not in asm_origine()]
    voisins = {}
    if SIMILAIRES.exists():
        voisins = json.loads(SIMILAIRES.read_text(encoding="utf-8"))["voisins"]

    def cle(n: str):
        proche = (PROCHES / f"{n}.cpp").exists()
        s = voisins.get(n)
        soeur = s[0]["score"] if s else 0.0
        # Jet d'abord ; puis sœur ≥ 0,7 ; puis la taille croissante. Le tri
        # est stable sur le nom pour que deux agents lisent la même file.
        return (not proche, soeur < 0.7, table[n].size, n)

    return sorted(restantes, key=cle)


def main() -> int:
    sys.stdout.reconfigure(encoding="utf-8")
    p = argparse.ArgumentParser(description=__doc__.split("\n\n")[0])
    p.add_argument("symbole", nargs="?")
    p.add_argument("--suivant", type=int, metavar="N")
    p.add_argument("--agent", default="anonyme")
    p.add_argument("--libere", metavar="AGENT")
    p.add_argument("--file", action="store_true")
    p.add_argument("--sante", action="store_true",
                   help="dit si le conteneur répond (code 4 sinon), avant d'écrire des essais")
    p.add_argument("--jeu", action="store_true", help="ne retenir que les fonctions de src/game")
    p.add_argument("--min", type=int, default=0, dest="mini", help="taille minimale en octets")
    p.add_argument("--max", type=int, default=10**9, dest="maxi", help="taille maximale en octets")
    a = p.parse_args()

    if a.sante:
        import shutil, subprocess
        moteur = shutil.which("docker") or shutil.which("podman")
        ok = moteur is not None and subprocess.run(
            [moteur, "info"], capture_output=True).returncode == 0
        print("conteneur : disponible" if ok else
              "conteneur : INDISPONIBLE — ne rédigez pas d'essais, signalez-le")
        return 0 if ok else 4

    res = charge_reservations()
    if a.libere:
        res = {n: r for n, r in res.items() if r["agent"] != a.libere}
        RESERVATIONS.write_text(json.dumps(res, indent=0), encoding="utf-8")
        print(f"réservations de {a.libere} rendues ; {len(res)} restent")
        return 0

    if a.suivant or a.file:
        table = functions()
        choisies = []
        # Deux agents ne travaillent jamais dans la même unité : `soumettre`
        # réécrit la source entière, et l'un défairait ce que l'autre garde.
        unite_de = {n: src for src, ns in grafted_by_source().items() for n in ns}
        prises = {unite_de.get(n) for n, r in res.items()
                  if r["agent"] not in (a.agent, "garde")}
        for n in file_priorite():
            if n in res or not a.mini <= table[n].size < a.maxi:
                continue
            if a.jeu and unite_de.get(n).parent != ROOT / "src" / "game":
                continue
            if unite_de.get(n) in prises:
                continue
            choisies.append(n)
            if a.suivant and len(choisies) >= a.suivant:
                break
            if a.file and len(choisies) >= 40:
                break
        if a.suivant:
            now = time.time()
            for n in choisies:
                res[n] = {"agent": a.agent, "heure": now}
            RESERVATIONS.write_text(json.dumps(res, indent=0), encoding="utf-8")
        for n in choisies:
            marque = "jet" if (PROCHES / f"{n}.cpp").exists() else "   "
            print(f"{marque} {table[n].size:6d} {n}")
        return 0

    if not a.symbole:
        p.error("un symbole, --suivant N ou --file")
    print(dossier(a.symbole))
    return 0


if __name__ == "__main__":
    sys.exit(main())
