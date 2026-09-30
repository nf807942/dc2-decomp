#!/usr/bin/env python3
"""Quelle version de GCC, avec quelles options, rend une fonction du SDK ou de la libc ?

    scripts/host/dc2 python3 scripts/build/gcc_essai.py sceGifPkInit essai.c
    scripts/host/dc2 python3 scripts/build/gcc_essai.py _free_r essai.c --versions ee-gcc2.96
    scripts/host/dc2 python3 scripts/build/gcc_essai.py sceGifPkInit essai.c --opts "-O2 -G0;-O1 -G0"

**Pourquoi.** Le SDK Sony et la bibliothèque C du jeu ne sont pas dans `.mwcats` : MWCC
ne les a pas compilés, GCC 2.x si (marqueurs `gcc2_compiled.` dans l'ELF). Les builds
d'`ee-gcc` de `decompme/compilers` (`make tools TOOLS_ARGS=--gcc`) sont une dizaine, et
la version comme les options qui ont produit une bibliothèque se départagent comme on a
départagé les 21 versions de MWCC : en compilant une même fonction sous chacune et en
lisant `match_percent`.

Le script tourne dans le conteneur. Les compilateurs sont des binaires i386 32 bits, ou
des `.exe` (les 2.95.x de SN Systems) lancés par wibo. Ils sont copiés dans `/tmp` avec
la source : sur le montage Windows, le `stat` 32 bits échoue sur les numéros d'inode
(« Value too large for defined data type »).
"""

from __future__ import annotations

import argparse
import json
import shutil
import subprocess
import sys
import tempfile
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from lib.project import ROOT, find_symbol  # noqa: E402

COMPILERS = ROOT / "tools" / "compilers"

# Les options du SDK de l'époque : -O2 en tête, le seuil des petites données à
# 0, 8 ou 128 octets (le jeu en règle un autre que MWCC : `-G0` dans `CLAUDE.md`).
OPTIONS = ["-O2 -G0", "-O2 -G8", "-O2 -G128", "-O1 -G0", "-O3 -G0"]


def compilateurs(filtre: list[str]) -> list[Path]:
    trouves = sorted(p for p in COMPILERS.glob("ee-gcc*")
                     if (p / "bin" / "ee-gcc").exists()
                     or (p / "bin" / "ee-gcc.exe").exists())
    return [p for p in trouves if not filtre or p.name in filtre]


def commande(racine: Path, options: list[str], source: Path, sortie: Path) -> list[str]:
    """La ligne de compilation d'un build, avec ses répertoires de travail."""
    dirs = sorted((racine / "lib" / "gcc-lib" / "ee").glob("*"))
    libdir = dirs[0] if dirs else racine / "lib"
    if (racine / "bin" / "ee-gcc").exists():
        base = [str(racine / "bin" / "ee-gcc"), f"-B{libdir}/", f"-B{racine}/ee/bin/"]
    else:
        base = ["wibo", str(racine / "bin" / "ee-gcc.exe"), f"-B{libdir}/"]
    return [*base, *options, "-c", "-o", str(sortie), str(source)]


def appariement(cible: Path, objet: Path, symbole: str) -> float | None:
    r = subprocess.run(
        ["objdiff-cli", "diff", "-1", str(cible), "-2", str(objet),
         "-o", "-", "--format", "json", symbole],
        capture_output=True, text=True)
    if r.returncode != 0:
        return None
    for entree in json.loads(r.stdout).get("right", {}).get("symbols", []):
        if entree.get("name") == symbole:
            return entree.get("match_percent", 0.0)
    return None


def montre(cible: Path, objet: Path, symbole: str) -> None:
    """Les instructions qui diffèrent, côte à côte (le jeu à gauche, GCC à droite)."""
    r = subprocess.run(
        ["objdiff-cli", "diff", "-1", str(cible), "-2", str(objet),
         "-o", "-", "--format", "json", symbole],
        capture_output=True, text=True)
    if r.returncode != 0:
        print("objdiff n'a rien rendu")
        return
    d = json.loads(r.stdout)

    def lignes(cote: str) -> list[str]:
        for e in d.get(cote, {}).get("symbols", []):
            if e.get("name") == symbole:
                return [(i.get("instruction") or {}).get("formatted", "")
                        for i in e.get("instructions", [])]
        return []

    gauche, droite = lignes("left"), lignes("right")
    for k in range(max(len(gauche), len(droite))):
        g = gauche[k] if k < len(gauche) else ""
        x = droite[k] if k < len(droite) else ""
        if g != x:
            print(f"{k:4}  jeu : {g:44} | gcc : {x}")


def main() -> int:
    p = argparse.ArgumentParser(description=__doc__.split("\n\n")[0])
    p.add_argument("symbole")
    p.add_argument("source", type=Path)
    p.add_argument("--versions", default="", help="noms de builds, séparés par des virgules")
    p.add_argument("--opts", default="", help="jeux d'options séparés par « ; »")
    p.add_argument("--inc", action="append", default=[], metavar="DOSSIER",
                   help="dossier d'en-têtes (relatif au dépôt), répétable ; ex. "
                        "progress/newlib/src/newlib-1_9_0/libc/include")
    p.add_argument("--define", action="append", default=[], metavar="NOM[=VALEUR]")
    p.add_argument("--montre", action="store_true",
                   help="affiche les instructions qui diffèrent (avec --versions et --opts d'une seule valeur)")
    a = p.parse_args()

    emplacement = find_symbol(a.symbole)
    cible = emplacement.target_object
    if not cible.exists():
        subprocess.run(["make", str(cible.relative_to(ROOT))], cwd=ROOT, check=True,
                       stdout=subprocess.DEVNULL)

    jeux = [o.split() for o in a.opts.split(";")] if a.opts else [o.split() for o in OPTIONS]
    filtre = [v for v in a.versions.split(",") if v]
    resultats: list[tuple[float, str, str]] = []
    with tempfile.TemporaryDirectory() as tmp:
        tmp = Path(tmp)
        source = tmp / "essai.c"
        shutil.copy(a.source, source)
        # Les petits en-têtes de GCC que le paquet ne porte pas (`stddef.h`, `stdarg.h`,
        # `limits.h`) : ceux du projet, derrière les dossiers demandés.
        extras: list[str] = []
        shutil.copytree(ROOT / "include" / "gcc", tmp / "inc_gcc")
        for i, dossier in enumerate(a.inc):
            copie_inc = tmp / f"inc{i}"
            shutil.copytree(ROOT / dossier, copie_inc)
            extras.append(f"-I{copie_inc}")
        extras.append(f"-I{tmp / 'inc_gcc'}")
        # Les en-têtes et les sources voisines de newlib, quand l'index existe : c'est ce que
        # la voie GCC du Makefile donne aussi (`scripts/build/ee_gcc_cc`).
        nl = ROOT / "tools" / "newlib" / "newlib-1_9_0"
        for d in ("libc/include", "libc/stdio", "libc/stdlib", "libc/string", "libc/reent",
                  "libc/locale", "libc/time", "libm/common", "libm/math"):
            if (nl / d).exists():
                shutil.copytree(nl / d, tmp / ("nl_" + d.replace("/", "_")))
                extras.append(f"-I{tmp / ('nl_' + d.replace('/', '_'))}")
        extras += [f"-D{d}" for d in a.define]
        for racine in compilateurs(filtre):
            copie = tmp / racine.name
            shutil.copytree(racine, copie)
            for options in jeux:
                sortie = tmp / "sortie.o"
                sortie.unlink(missing_ok=True)
                r = subprocess.run(commande(copie, [*options, *extras], source, sortie),
                                   capture_output=True, text=True, cwd=tmp)
                if not sortie.exists():
                    resultats.append((-1.0, racine.name, " ".join(options)
                                      + "  (échec : " + next((l for l in r.stderr.splitlines() if "error" in l.lower()), (r.stderr.strip().splitlines() or ["?"])[-1])[:110] + ")"))
                    continue
                score = appariement(cible, sortie, a.symbole)
                if a.montre:
                    montre(cible, sortie, a.symbole)
                resultats.append((score if score is not None else -1.0,
                                  racine.name, " ".join(options)))
            shutil.rmtree(copie)

    resultats.sort(key=lambda r: (-r[0], r[1]))
    print(f"{a.symbole} contre {cible.relative_to(ROOT)}\n")
    for score, nom, options in resultats:
        marque = "  " if score < 100 else "=>"
        texte = f"{score:6.2f} %" if score >= 0 else "   —    "
        print(f"{marque} {texte}  {nom:22} {options}")
    meilleurs = [r for r in resultats if r[0] >= 100]
    print(f"\n{len(meilleurs)} combinaison(s) à 100 % sur {len(resultats)}")
    return 0 if meilleurs else 1


if __name__ == "__main__":
    sys.exit(main())
