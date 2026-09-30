#!/usr/bin/env python3
"""Les sources de newlib : les indexer, y trouver une fonction, l'aplatir pour ee-gcc.

    python scripts/build/newlib_source.py --indexe                 # une fois : ~1 000 fichiers
    python scripts/build/newlib_source.py --cherche copysignf      # quels fichiers la définissent
    python scripts/build/newlib_source.py copysignf                # écrit progress/newlib/copysignf.c
    python scripts/build/newlib_source.py copysignf libm/common/sf_copysign.c --tag newlib-1_10_0

**Pourquoi.** La libc et la libm du jeu sont du newlib 1.9.0 compilé par ee-gcc 2.9-ee
(`docs/BINAIRE_ET_CHAINE.md`, section 8) : pour une fonction comme `copysignf`, la source
écrite existe déjà, publique, et rend 100 %. Un agent qui l'écrit de mémoire perd des
essais sur des détails qu'une copie de la source ne perd pas. Les sources viennent du
miroir `mirror/newlib-cygwin`, qui garde les étiquettes des anciennes versions
(`newlib-1_9_0`, `newlib-1_10_0`…).

**L'index** (`tools/newlib/<étiquette>/`, non versionné) contient tous les `.c` de
`libc/` et `libm/`. `--cherche` y lit les définitions : `_DEFUN (nom, …)` à l'ancienne,
`nom (args)` en début de ligne, ou le nom d'un fichier proche (`sf_` pour les `float`,
`e_` pour `__ieee754_*`, `k_`/`kf_` pour `__kernel_*`). Les alias du préprocesseur de
newlib (`fREe` pour `_free_r` dans `mallocr.c`) n'apparaissent pas dans le nom de la
fonction : la recherche par nom de fichier les rattrape.

**Aplatir.** Les sources de newlib incluent `<math.h>`, `<machine/ieeefp.h>` et
`fdlibm.h`, dont les chaînes réclament un arbre de compilation croisée. On remplace ces
inclusions par quelques définitions (types 32 bits, petit boutiste, macros `_DEFUN`) et on
garde `fdlibm.h` de la même version, pour `GET_HIGH_WORD` et consorts. Le résultat se passe
à `scripts/build/gcc_essai.py`. Pour écrire dans le dépôt, on reprend le corps de la
fonction et on inclut `include/gcc/ieee754.h`, qui porte ces macros.
"""

from __future__ import annotations

import argparse
import json
import re
import sys
import urllib.request
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
BASE = "https://raw.githubusercontent.com/mirror/newlib-cygwin/{tag}/newlib/{path}"
ARBRE = "https://api.github.com/repos/mirror/newlib-cygwin/git/trees/{tag}?recursive=1"
INDEX = ROOT / "tools" / "newlib"

STUB = """typedef int __int32_t;
typedef unsigned int __uint32_t;
typedef unsigned int u_int32_t;
typedef unsigned int size_t;
#define __IEEE_LITTLE_ENDIAN
#define __STDC__ 1
#define _CONST const
#define _DEFUN(name, arglist, args) name(args)
#define _AND ,
#define _PTR void *
#define _EXFUN(name, proto) name proto
#define NULL ((void *) 0)
#define LONG_MAX 9223372036854775807L
#define CHAR_BIT 8
"""


def lire(url: str) -> str:
    with urllib.request.urlopen(url) as r:
        return r.read().decode("latin-1").replace("\r", "")


def fetch(tag: str, path: str) -> str:
    return lire(BASE.format(tag=tag, path=path))


def sans_inclusions(texte: str) -> str:
    return re.sub(r"^\s*#\s*include.*$", "", texte, flags=re.M)


# --------------------------------------------------------------------- index --

def indexe(tag: str) -> int:
    arbre = json.loads(lire(ARBRE.format(tag=tag)))
    chemins = [e["path"] for e in arbre["tree"]
               if e["type"] == "blob" and e["path"].startswith("newlib/")
               and re.match(r"newlib/(libc|libm)/.*\.(c|h)$", e["path"])]
    dest = INDEX / tag
    dest.mkdir(parents=True, exist_ok=True)

    def un(chemin: str) -> None:
        cible = dest / chemin.removeprefix("newlib/")
        if cible.exists():
            return
        cible.parent.mkdir(parents=True, exist_ok=True)
        cible.write_text(fetch(tag, chemin.removeprefix("newlib/")),
                         encoding="latin-1", newline="\n")

    with ThreadPoolExecutor(12) as pool:
        list(pool.map(un, chemins))
    print(f"{len(chemins)} fichiers sous {dest.relative_to(ROOT)}")
    return 0


def candidats_de_fichier(symbole: str) -> list[str]:
    """Les noms de fichiers que newlib donne à la fonction d'un symbole."""
    nu = symbole.lstrip("_")
    racines = {nu, nu.removesuffix("_r")}
    if nu.startswith("ieee754_"):
        racines.add("e_" + nu.removeprefix("ieee754_"))
        racines.add("ef_" + nu.removeprefix("ieee754_").removesuffix("f"))
    if nu.startswith("kernel_"):
        racines |= {"k_" + nu.removeprefix("kernel_"), "kf_" + nu.removeprefix("kernel_").removesuffix("f")}
    if nu.endswith("f"):
        racines |= {"sf_" + nu[:-1], "wf_" + nu[:-1], "ef_" + nu[:-1]}
    racines |= {"s_" + nu, "w_" + nu, "e_" + nu}
    return sorted(racines)


def cherche(symbole: str, tag: str) -> list[tuple[str, str]]:
    base = INDEX / tag
    if not base.exists():
        print("index absent : lancez d'abord --indexe", file=sys.stderr)
        return []
    trouves: list[tuple[str, str]] = []
    sym = re.escape(symbole)
    definition = re.compile(
        rf"(?:_DEFUN\s*\(\s*{sym}\b|^[A-Za-z_][\w \t\*]*\b{sym}\s*\(|^{sym}\s*\(|\b{sym}\s*\[)",
        re.M)
    alias = re.compile(rf"^\s*#\s*define\s+(\w+)\s+{sym}\b", re.M)
    noms = set(candidats_de_fichier(symbole))
    # Les alias de newlib vont dans les deux sens : `#define Balloc _Balloc` (mprec.h) fait
    # définir `_Balloc` sous le nom `Balloc`, `#define fREe _free_r` (mallocr.c) l'inverse.
    # On cherche donc aussi la définition de chaque nom que le symbole porte en alias.
    alias_de = re.compile(rf"^\s*#\s*define\s+(\w+)\s+{sym}", re.M)
    autres = {m.group(1) for f in base.rglob("*.h") for m in
              alias_de.finditer(f.read_text(encoding="latin-1"))}
    definitions_autres = [re.compile(
        rf"(?:_DEFUN\s*\(\s*{re.escape(n)}|^[A-Za-z_][\w 	\*]*{re.escape(n)}\s*\(|^{re.escape(n)}\s*\()",
        re.M) for n in autres]
    for f in sorted(base.rglob("*.c")):
        texte = f.read_text(encoding="latin-1")
        rel = f.relative_to(base).as_posix()
        if definition.search(texte):
            trouves.append((rel, "définition"))
        elif (m := alias.search(texte)):
            trouves.append((rel, f"alias du préprocesseur : {m.group(1)}"))
        elif any(d.search(texte) for d in definitions_autres):
            trouves.append((rel, "définie sous un alias d'en-tête : " + ", ".join(sorted(autres)[:2])))
        elif f.stem in noms:
            trouves.append((rel, "nom de fichier"))
    return trouves


# ------------------------------------------------------------------- aplatir --

def aplati(symbole: str, chemin: str, tag: str) -> Path:
    source = sans_inclusions(fetch(tag, chemin))
    morceaux = [STUB]
    if chemin.startswith("libm"):
        for candidat in ("libm/common/fdlibm.h", "libm/math/fdlibm.h"):
            try:
                entete = fetch(tag, candidat)
            except Exception:  # noqa: BLE001 — l'autre emplacement, le cas échéant
                continue
            morceaux.append(sans_inclusions(entete).replace(
                "#error Must define endianness", ""))
            break
    morceaux.append(source)
    sortie = ROOT / "progress" / "newlib" / f"{symbole}.c"
    sortie.parent.mkdir(parents=True, exist_ok=True)
    sortie.write_text("\n".join(morceaux), encoding="latin-1", newline="\n")
    return sortie


def isole(symbole: str, chemin: str, tag: str) -> Path:
    """La seule fonction du symbole, avec la licence de son fichier, sans ses voisines.

    La fonction commence à sa définition (la ligne du type de retour qui la précède
    comprise) et finit à la première accolade fermante en colonne 0. Le nom cherché est celui
    du symbole ou, à défaut, l'alias que les en-têtes de newlib lui donnent (`Balloc` pour
    `_Balloc`) : dans le fichier il s'écrit sous cet alias, et le binaire le porte sous le
    symbole — `_DEFUN (_Balloc, …)` rend le même code que `_DEFUN (Balloc, …)` après la macro.
    """
    texte = (INDEX / tag / chemin).read_text(encoding="latin-1")
    base = INDEX / tag
    noms = [symbole]
    alias = re.compile(rf"^\s*#\s*define\s+(\w+)\s+{re.escape(symbole)}", re.M)
    for f in base.rglob("*.h"):
        noms += [m.group(1) for m in alias.finditer(f.read_text(encoding="latin-1"))]
    noms += [m.group(1) for m in alias.finditer(texte)]   # alias posés dans le fichier lui-même
    lignes = texte.splitlines()
    debut = None
    for nom in noms:
        motif = re.compile(rf"(?:_DEFUN\s*\(\s*{re.escape(nom)}\b|^[ \t]*(?:[A-Za-z_][\w \t\*]*)?\b{re.escape(nom)}\s*\()")
        for i, l in enumerate(lignes):
            if motif.search(l):
                debut = i
                break
        if debut is not None:
            break
    if debut is None:
        raise SystemExit(f"{symbole} : définition introuvable dans {chemin}")
    # la ligne du type de retour, si la définition est au style `type\nnom (…)`
    if debut > 0 and lignes[debut - 1].strip() and not lignes[debut - 1].rstrip().endswith((";", "*/", "}")):
        debut -= 1
    fin = next((j for j in range(debut, len(lignes)) if lignes[j].startswith("}")), len(lignes) - 1)
    licence = []
    for l in lignes:
        licence.append(l)
        if "*/" in l:
            break
    sortie = ROOT / "progress" / "newlib" / f"{symbole}.fn.c"
    sortie.parent.mkdir(parents=True, exist_ok=True)
    sortie.write_text("\n".join(licence) + f"\n/* {chemin}, newlib 1.9.0 */\n\n"
                      + "\n".join(lignes[debut:fin + 1]) + "\n", encoding="latin-1", newline="\n")
    return sortie


def main() -> int:
    p = argparse.ArgumentParser(description=__doc__.split("\n\n")[0])
    p.add_argument("symbole", nargs="?")
    p.add_argument("chemin", nargs="?", help="chemin sous newlib/, par exemple libm/common/s_floor.c")
    p.add_argument("--tag", default="newlib-1_9_0")
    p.add_argument("--indexe", action="store_true")
    p.add_argument("--cherche", metavar="SYMBOLE")
    p.add_argument("--fonction", action="store_true",
                   help="n'écrit que la fonction du symbole, avec la licence du fichier")
    a = p.parse_args()

    if a.indexe:
        return indexe(a.tag)
    if a.cherche:
        trouves = cherche(a.cherche, a.tag)
        for rel, pourquoi in trouves:
            print(f"{rel}   ({pourquoi})")
        return 0 if trouves else 1
    if not a.symbole:
        p.error("un symbole, --indexe ou --cherche")
    chemin = a.chemin
    if not chemin:
        trouves = cherche(a.symbole, a.tag)
        if not trouves:
            print(f"{a.symbole} : introuvable dans l'index {a.tag}", file=sys.stderr)
            return 1
        chemin = trouves[0][0]
        print(f"source retenue : {chemin}")
    if a.fonction:
        print(isole(a.symbole, chemin, a.tag).relative_to(ROOT))
        return 0
    print(aplati(a.symbole, chemin, a.tag).relative_to(ROOT))
    return 0


if __name__ == "__main__":
    sys.exit(main())
