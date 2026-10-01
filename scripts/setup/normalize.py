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


# Ce qui définit un symbole dans le désassemblage : la macro d'étiquette que le
# découpage choisit, ou une étiquette nue — celle qu'un `type:label` fait poser
# au milieu d'une fonction, comme `_xlaunch` dans `_kTLBException`.
_DLABEL = re.compile(r"^\s*(?:(?:dlabel|glabel|jlabel)\s+(\S+)|(\w+):\s*$)",
                     re.MULTILINE)
_ASSIGNMENT = re.compile(r"^(\S+)\s*=\s*0x[0-9A-Fa-f]+;")


def drop_defined_undefined_syms() -> int:
    """Retire du script des symboles absolus ceux qu'une section définit.

    splat écrit dans `undefined_syms_auto.ld` tout symbole référencé que son
    attribut `defined` ne marque pas — c'est la règle de
    `write_undefined_syms_auto`. Or spimdisasm en écrit certains sans que splat
    l'enregistre : les dix `CHA_DEV_FONT_PIECE_*`, d'un octet chacun, reçoivent
    bien leur `dlabel` une fois typés, et l'affectation absolue qui subsiste les
    fixerait alors à une adresse que leur section dément.

    Le lien tranche : un symbole retiré à tort n'est plus défini nulle part, et
    l'éditeur de liens le dit.
    """
    script = ROOT / "linker_scripts" / "auto" / "undefined_syms_auto.ld"
    if not script.exists():
        return 0

    defined = set()
    for path in (ROOT / "asm").rglob("*.s"):
        text = path.read_text(encoding="utf-8", errors="replace")
        defined.update(name for pair in _DLABEL.findall(text)
                       for name in pair if name)

    kept, dropped = [], 0
    for line in script.read_text(encoding="utf-8").splitlines():
        match = _ASSIGNMENT.match(line.strip())
        if match and match.group(1) in defined:
            dropped += 1
            continue
        kept.append(line)

    if dropped:
        script.write_text("\n".join(kept) + "\n", encoding="utf-8")
    return dropped


_BIN_OBJECT = re.compile(r"^\s*build/bin/\w+/([0-9A-F]{8})\.o\(\.data\);")


def anchor_bin_symbols() -> int:
    """Fait suivre au symbole d'un bloc d'octets la place que le lien lui donne.

    Un microprogramme vectoriel est lié par `objcopy -I binary`, donc son objet
    ne définit aucun des noms que le binaire lui donne — `Vu_progmain`,
    `Vu_prog_wtr`, `My_dma_start0`. Le code qui les charge les recevait par leur
    adresse absolue, ce qui les figerait : un texte plus long ferait glisser le
    bloc sans eux.

    L'affectation `<nom> = .;` posée devant l'objet dans le script de lien les
    rattache à sa position. Le nom est celui que le désassembleur emploie, faute
    de quoi la référence resterait pendante.
    """
    script = ROOT / "linker_scripts" / "SCES_511.90.ld"
    undefined = ROOT / "linker_scripts" / "auto" / "undefined_syms_auto.ld"
    if not script.exists() or not undefined.exists():
        return 0

    # Ce que le lien reçoit encore par adresse absolue, et à quelle adresse.
    absolute = {}
    for line in undefined.read_text(encoding="utf-8").splitlines():
        match = _ASSIGNMENT.match(line.strip())
        if match:
            absolute[int(line.split("=", 1)[1].strip().rstrip(";"), 16)] = \
                match.group(1)

    anchored, lines = set(), []
    for line in script.read_text(encoding="utf-8").splitlines():
        block = _BIN_OBJECT.match(line)
        if block:
            address = int(block.group(1), 16)
            name = absolute.get(address)
            if name:
                indent = line[:len(line) - len(line.lstrip())]
                lines.append(f"{indent}{name} = .;")
                anchored.add(name)
        lines.append(line)

    if not anchored:
        return 0
    script.write_text("\n".join(lines) + "\n", encoding="utf-8")

    kept = [line for line in undefined.read_text(encoding="utf-8").splitlines()
            if not ((m := _ASSIGNMENT.match(line.strip())) and m.group(1) in anchored)]
    undefined.write_text("\n".join(kept) + "\n", encoding="utf-8")
    return len(anchored)


# `_gp` tel que splat l'écrit, depuis le `gp_value` du découpage.
_GP = re.compile(r"^(\s*)_gp = 0x([0-9A-Fa-f]+);\s*$", re.MULTILINE)
_BSS_START = "main_BSS_START = .;"


def relocate_gp() -> int:
    """Rend `_gp` relatif à la fin du contenu du fichier, au lieu de l'y figer.

    `.reginfo` fixe `gp_value = 0x003846F0` et 15 869 relocations `GPREL16` s'y
    rapportent ; l'assembleur doit recevoir cette valeur-là pour réencoder les
    mêmes octets, et elle reste donc dans le découpage. Mais le *symbole* que le
    lien définit n'a pas à être ce nombre : écrit en dur, il ne suivrait pas les
    petites données si celles-ci bougeaient, et chaque `%gp_rel` raterait sa
    cible d'autant.

    L'écart est mesuré, non supposé : `0x003846F0 - 0x0037CD80 = 0x7970`, la fin
    du contenu du fichier étant aussi le début du bss. Tant que rien ne bouge, la
    valeur est la même — c'est ce que `make build` vérifie ; et si le texte
    grossit, `_gp` suit.
    """
    script = ROOT / "linker_scripts" / "SCES_511.90.ld"
    if not script.exists():
        return 0

    text = script.read_text(encoding="utf-8")
    match = _GP.search(text)
    if not match or _BSS_START not in text:
        return 0

    gp = int(match.group(2), 16)
    # La valeur que le lien donnera au repère : la fin du contenu du fichier,
    # que le découpage connaît par la taille de la section chargée.
    image = ROOT / "rom" / "main.bin"
    if not image.exists():
        return 0
    bss_start = 0x00100000 + image.stat().st_size
    if not 0 <= gp - bss_start < 0x10000:
        # Hors de la fenêtre de `$gp`, l'écart ne serait pas celui qu'on croit.
        return 0

    text = _GP.sub("", text, count=1)
    text = text.replace(
        _BSS_START,
        f"{_BSS_START}\n        _gp = main_BSS_START + 0x{gp - bss_start:X};",
        1)
    script.write_text(text, encoding="utf-8")
    return gp - bss_start


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

    dropped = drop_defined_undefined_syms()
    if dropped:
        print(f"{dropped} symboles absolus retirés, leur section les définit")

    anchored = anchor_bin_symbols()
    if anchored:
        print(f"{anchored} symboles de bloc d'octets rattachés à leur objet")

    offset = relocate_gp()
    if offset:
        print(f"_gp rendu relatif : main_BSS_START + 0x{offset:X}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
