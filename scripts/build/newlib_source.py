#!/usr/bin/env python3
"""Va chercher une source de newlib et l'aplatit en un fichier C que ee-gcc compile seul.

    python scripts/build/newlib_source.py copysign libm/common/s_copysign.c
    python scripts/build/newlib_source.py strcat libc/string/strcat.c --tag newlib-1_10_0

Écrit `progress/newlib/<symbole>.c` (non versionné), à passer à
`scripts/build/gcc_essai.py`. Les sources viennent du miroir `mirror/newlib-cygwin`, qui
garde les étiquettes des anciennes versions (`newlib-1_9_0`, `newlib-1_10_0`…) : celle de
la bibliothèque C du SDK Sony est de cette époque.

**Pourquoi aplatir.** Les sources de newlib incluent `<math.h>`, `<machine/ieeefp.h>` et
`fdlibm.h`, dont les chaînes d'inclusion réclament un arbre de compilation croisée. On
remplace ces inclusions par quelques définitions (types 32 bits, petit boutiste, macros
`_DEFUN`) et on garde `fdlibm.h` de la même version, pour les macros `GET_HIGH_WORD` et
consorts. Sans cela, `ee-gcc` échoue sur un en-tête manquant avant de compiler une ligne.

Première mesure (MWCC ne compile pas ces fonctions, `ee-gcc` 2.9 si) : `copysign`,
`copysignf`, `finite`, `isnan` et `__kernel_cosf` rendent 100 % depuis la source de newlib
1.9.0 inchangée, `floor` 99,75 %.
"""

from __future__ import annotations

import argparse
import re
import sys
import urllib.request
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
BASE = "https://raw.githubusercontent.com/mirror/newlib-cygwin/{tag}/newlib/{path}"

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


def fetch(tag: str, path: str) -> str:
    with urllib.request.urlopen(BASE.format(tag=tag, path=path)) as r:
        return r.read().decode("latin-1").replace("\r", "")


def sans_inclusions(texte: str) -> str:
    return re.sub(r"^\s*#\s*include.*$", "", texte, flags=re.M)


def main() -> int:
    p = argparse.ArgumentParser(description=__doc__.split("\n\n")[0])
    p.add_argument("symbole")
    p.add_argument("chemin", help="chemin sous newlib/, par exemple libm/common/s_floor.c")
    p.add_argument("--tag", default="newlib-1_9_0")
    a = p.parse_args()

    source = sans_inclusions(fetch(a.tag, a.chemin))
    morceaux = [STUB]
    if "fdlibm.h" in fetch(a.tag, a.chemin) or a.chemin.startswith("libm"):
        for candidat in ("libm/common/fdlibm.h", "libm/math/fdlibm.h"):
            try:
                entete = fetch(a.tag, candidat)
            except Exception:  # noqa: BLE001 — l'autre emplacement, le cas échéant
                continue
            morceaux.append(sans_inclusions(entete).replace(
                "#error Must define endianness", ""))
            break
    morceaux.append(source)

    sortie = ROOT / "progress" / "newlib" / f"{a.symbole}.c"
    sortie.parent.mkdir(parents=True, exist_ok=True)
    sortie.write_text("\n".join(morceaux), encoding="latin-1", newline="\n")
    print(sortie.relative_to(ROOT))
    return 0


if __name__ == "__main__":
    sys.exit(main())
