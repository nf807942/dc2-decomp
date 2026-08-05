#!/usr/bin/env python3
"""Rend assemblables et greffables les fonctions qu'une unité laisse en
assembleur, sous `asm/nonmatchings/`.

Deux écarts s'y corrigent, tous deux propres à ce chemin-là : le désassembleur
n'écrit pas ces fonctions comme celles qu'il laisse en assembleur pur, et
mwccgap n'y attend pas tout à fait ce que splat y met.

  * L'accumulateur vectoriel du R5900 y est rendu nu. Le même code sous
    `ref/asm/text/` porte `vopmula.xyz $ACC, $vf10, $vf11` ; ici, `ACC` sans
    dollar, et l'assembleur le refuse — « invalid operands ». L'écart ne tient
    pas à `named_regs_for_c_funcs` : mis à `False`, celui-ci rend les registres
    généraux par leur numéro et laisse l'accumulateur nu tout de même.

  * mwccgap ne reconnaît pas le même marqueur de symbole non apparié dans les
    deux sections d'un fichier : `nmlabel` en lecture seule, un autre nom dans
    le texte. Le nom est celui que le découpage choisit, et dans le texte la
    ligne est alors comptée pour une instruction — la fonction reçoit un `nop`
    de trop et la greffe échoue sur « Not enough assembly to fill ». La ligne
    n'y sert qu'à marquer, et rien du projet ne la lit : mwccgap ne la reporte
    déjà pas dans l'objet compilé.
"""

from __future__ import annotations

import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
ASM_DIR = ROOT / "asm" / "nonmatchings"

# Une ligne de désassemblage d'instruction vectorielle : le commentaire
# d'adresse, le mnémonique, puis les opérandes. La forme de la ligne borne la
# substitution — ailleurs, ces noms peuvent être ceux d'un symbole.
_VECTOR = re.compile(r"^(\s*/\*[^*]*\*/\s+v\w+(?:\.\w+)?\s+)(\S.*)$")

# Les registres propres à l'unité vectorielle : l'accumulateur, le quotient de
# la division, l'entier, la racine et le produit. Ils n'ont pas de numéro, et
# c'est là que les deux écritures du désassembleur divergent.
_SPECIAL = {"ACC", "Q", "I", "R", "P"}


def prefix_specials(line: str) -> str:
    match = _VECTOR.match(line)
    if not match:
        return line
    operands = [
        o.replace(o.strip(), "$" + o.strip(), 1) if o.strip() in _SPECIAL else o
        for o in match.group(2).split(",")
    ]
    return match.group(1) + ",".join(operands)


def normalize(text: str) -> str:
    out: list[str] = []
    in_rodata = False
    for line in text.splitlines():
        stripped = line.strip()
        if stripped.startswith(".section"):
            in_rodata = stripped.endswith(".rodata")
        elif stripped.startswith("nmlabel") and not in_rodata:
            continue
        elif in_rodata and stripped.startswith("/*") and stripped.endswith("*/"):
            # La valeur d'une chaîne, que le désassembleur redonne en
            # hexadécimal sous elle. mwccgap écarte ces commentaires dans le
            # texte et s'arrête dessus en lecture seule.
            continue
        out.append(prefix_specials(line))
    return "\n".join(out) + "\n"


def main() -> int:
    if not ASM_DIR.is_dir():
        return 0

    touched = 0
    for path in ASM_DIR.rglob("*.s"):
        text = path.read_text(encoding="utf-8")
        fixed = normalize(text)
        if fixed != text:
            path.write_text(fixed, encoding="utf-8")
            touched += 1

    if touched:
        print(f"{touched} fonctions greffées normalisées")
    return 0


if __name__ == "__main__":
    sys.exit(main())
