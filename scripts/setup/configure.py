#!/usr/bin/env python3
"""Prépare le projet depuis l'image disque : exécutable, symboles, découpage.

Tout ce que ce script écrit est dérivé du disque, donc hors de git. Il se
rejoue à volonté : `make setup`.

Le binaire PAL n'est pas strippé, et c'est ce qui rend le découpage exact
plutôt que deviné. Trois choses s'y lisent directement :

  * 7 837 symboles de fonction et 8 201 d'objet, avec adresse et taille ;
  * 316 symboles de section, un par contribution d'objet — 192 pour `.text`,
    ce qui donne les frontières de fichiers que splat devrait autrement
    chercher à tâtons ;
  * 99 876 relocations, qui disent quel mot est une adresse et laquelle.
"""

from __future__ import annotations

import argparse
import hashlib
import struct
import sys
from dataclasses import dataclass
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
ROM_DIR = ROOT / "rom"
CONFIG_DIR = ROOT / "config"

# L'exécutable que SYSTEM.CNF désigne sur le disque PAL.
BOOT_NAME = "SCES_511.90"

# Le segment chargeable unique, tel que l'en-tête de programme le déclare.
LOAD_VADDR = 0x00100000

# `.reginfo` fixe la base des accès aux globales par $gp. Les 15 869
# relocations GPREL16 s'y rapportent, et l'assembleur doit recevoir la même
# valeur pour réencoder les mêmes octets.
GP_VALUE = 0x003846F0

SYM_NOTYPE, SYM_OBJECT, SYM_FUNC, SYM_SECTION, SYM_FILE = range(5)


# --------------------------------------------------------------------------
# Image disque
# --------------------------------------------------------------------------

def find_disc() -> Path:
    """Trouve l'image disque dans rom/, quel que soit son nom."""
    if not ROM_DIR.is_dir():
        raise SystemExit(f"rom/ absent — créez-le et posez-y l'image disque")
    candidates = sorted(
        p for p in ROM_DIR.iterdir()
        if p.suffix.lower() in (".iso", ".bin", ".img") and p.is_file()
    )
    if not candidates:
        raise SystemExit(
            "aucune image disque dans rom/.\n"
            "Posez-y le disque PAL de Dark Chronicle (SCES-51190)."
        )
    if len(candidates) > 1:
        names = ", ".join(p.name for p in candidates)
        raise SystemExit(f"plusieurs images dans rom/ : {names}")
    return candidates[0]


def iso_extract(iso: Path, name: str) -> bytes:
    """Lit un fichier du répertoire racine d'une image ISO 9660.

    Le format suffit à lui seul ici : l'exécutable est à la racine, et la
    racine tient dans un descripteur de volume primaire au secteur 16.
    """
    with iso.open("rb") as f:
        f.seek(16 * 2048)
        pvd = f.read(2048)
        if pvd[1:6] != b"CD001":
            raise SystemExit(f"{iso.name} n'est pas une image ISO 9660")

        root = pvd[156:190]
        lba, size = struct.unpack_from("<I", root, 2)[0], struct.unpack_from("<I", root, 10)[0]

        f.seek(lba * 2048)
        directory = f.read(size)

        offset = 0
        while offset < len(directory):
            length = directory[offset]
            if length == 0:
                # Une entrée ne franchit pas une frontière de secteur : le
                # reste du secteur est un remplissage.
                offset = (offset // 2048 + 1) * 2048
                continue
            entry = directory[offset:offset + length]
            entry_lba = struct.unpack_from("<I", entry, 2)[0]
            entry_size = struct.unpack_from("<I", entry, 10)[0]
            name_len = entry[32]
            entry_name = entry[33:33 + name_len].decode("latin1")
            # Le suffixe « ;1 » est le numéro de version ISO 9660.
            if entry_name.split(";")[0] == name:
                f.seek(entry_lba * 2048)
                return f.read(entry_size)
            offset += length

    raise SystemExit(f"{name} introuvable dans {iso.name}")


# --------------------------------------------------------------------------
# ELF
# --------------------------------------------------------------------------

@dataclass
class Section:
    name: str
    kind: int
    addr: int
    offset: int
    size: int
    link: int
    entsize: int


@dataclass
class Symbol:
    name: str
    value: int
    size: int
    kind: int
    shndx: int


@dataclass
class Elf:
    data: bytes
    sections: list[Section]
    symbols: list[Symbol]

    def section(self, name: str) -> Section:
        for s in self.sections:
            if s.name == name:
                return s
        raise SystemExit(f"section {name} absente du binaire")


def read_elf(data: bytes) -> Elf:
    if data[:4] != b"\x7fELF":
        raise SystemExit("l'exécutable extrait n'est pas un ELF")

    shoff = struct.unpack_from("<I", data, 0x20)[0]
    shentsize = struct.unpack_from("<H", data, 0x2E)[0]
    shnum = struct.unpack_from("<H", data, 0x30)[0]
    shstrndx = struct.unpack_from("<H", data, 0x32)[0]

    raw = []
    for i in range(shnum):
        fields = struct.unpack_from("<10I", data, shoff + i * shentsize)
        raw.append(fields)

    strtab_off = raw[shstrndx][4]

    def string_at(base: int, index: int) -> str:
        end = data.index(b"\x00", base + index)
        return data[base + index:end].decode("latin1")

    sections = [
        Section(
            name=string_at(strtab_off, f[0]), kind=f[1], addr=f[3],
            offset=f[4], size=f[5], link=f[6], entsize=f[9],
        )
        for f in raw
    ]

    symbols: list[Symbol] = []
    for s in sections:
        if s.kind != 2:  # SHT_SYMTAB
            continue
        names_off = sections[s.link].offset
        for i in range(s.size // 16):
            name_idx, value, size, info, _other, shndx = struct.unpack_from(
                "<IIIBBH", data, s.offset + i * 16
            )
            symbols.append(
                Symbol(string_at(names_off, name_idx), value, size, info & 0xF, shndx)
            )

    return Elf(data, sections, symbols)


# --------------------------------------------------------------------------
# Carte du binaire
# --------------------------------------------------------------------------

# L'ordre dans lequel l'éditeur de liens Metrowerks dispose les sections d'un
# objet. Chaque contribution d'objet est marquée par un symbole de section, et
# leur suite donne les frontières.
SECTION_ORDER = [".text", ".vutext", ".data", ".vudata", ".rodata", ".sdata",
                 ".sbss", ".bss", ".vubss"]


def section_starts(elf: Elf) -> dict[str, list[int]]:
    """Adresses de début de chaque contribution d'objet, par nom de section."""
    starts: dict[str, list[int]] = {}
    for sym in elf.symbols:
        if sym.kind == SYM_SECTION and sym.name.startswith("."):
            starts.setdefault(sym.name, []).append(sym.value)
    for name in starts:
        starts[name] = sorted(set(starts[name]))
    return starts


def write_sections(starts: dict[str, list[int]], path: Path) -> None:
    """Écrit les frontières de contribution, pour ce qui décide un découpage.

    Le désassembleur en fait un sous-segment chacune : une unité déclarée à
    cheval sur l'une d'elles se voit tronquée sans un mot, et les fonctions
    qu'elle perd ne sont écrites nulle part. `make carve` a besoin de les
    connaître pour n'en proposer aucune.
    """
    lines = [f"{name} 0x{addr:08X}"
             for name in sorted(starts) for addr in starts[name]]
    path.write_text("\n".join(lines) + "\n", encoding="utf-8")


_ILLEGAL = str.maketrans({c: "_" for c in "@$<>.,:;\"'/\\|?*()[]{} +-!#%^&=~`"})


def sanitize(name: str) -> str:
    """Rend un nom Metrowerks utilisable par toute la chaîne.

    Le compilateur numérote ses littéraux `@497` et suffixe ses statiques
    `conv_work$1306` ; le mangling met les paramètres de patron entre chevrons.
    L'éditeur de liens GNU refuse ces caractères dans un script — « ignoring
    invalid character `@' » —, `$` introduit un registre pour l'assembleur, et
    aucun système de fichiers ne veut des chevrons. Le nom d'origine reste en
    commentaire dans la table, qui est la seule pièce à en avoir besoin.
    """
    cleaned = name.translate(_ILLEGAL)
    # Un identifiant ne commence pas par un chiffre.
    return cleaned if not cleaned[:1].isdigit() else "_" + cleaned


def write_symbol_addrs(elf: Elf, path: Path) -> tuple[int, int]:
    """Écrit la table des symboles au format que splat attend.

    Mille deux cent quatre-vingt-treize noms désignent plusieurs adresses :
    des fonctions `static` homonymes d'une unité de traduction à l'autre, les
    littéraux anonymes que Metrowerks numérote et les descripteurs RTTI. Tous
    sont à liaison locale, donc l'éditeur de liens n'en a jamais vu de
    conflit ; le désassembleur, lui, nomme un endroit et exige l'unicité.
    L'assainissement en confond d'autres encore, d'où l'ordre : nettoyer, puis
    départager par l'adresse.

    Les symboles de taille nulle portent quand même une information : les
    microprogrammes VU s'y nomment (`_$MAIN_PROG`, `Vu_prog_3dsp`), et c'est
    par eux que le désassemblage retrouve leurs points d'entrée.
    """
    # Un symbole par adresse : plusieurs noms au même endroit sont des alias,
    # et le premier suffit à le nommer.
    chosen: dict[int, Symbol] = {}
    for sym in sorted(elf.symbols, key=lambda s: (s.value, s.name)):
        if sym.kind not in (SYM_FUNC, SYM_OBJECT) or not sym.name or sym.value == 0:
            continue
        chosen.setdefault(sym.value, sym)

    for sym in boot_symbols(elf):
        chosen.setdefault(sym.value, sym)

    # Le nom final se déduit en deux temps : assainissement, puis levée des
    # collisions par l'adresse. Compter les homonymes avant l'assainissement
    # manquerait ceux que celui-ci confond.
    candidate = {addr: sanitize(sym.name) for addr, sym in chosen.items()}
    counts: dict[str, int] = {}
    for name in candidate.values():
        counts[name] = counts.get(name, 0) + 1

    # Les objets qu'il faut typer pour que le désassembleur les nomme : ceux
    # d'un ou deux octets qu'aucun multiple de quatre ne porte, et ceux qui
    # partagent leur mot — mêler l'octet et le mot dans un même mot laisserait
    # le désassembleur devant deux découpages inconciliables.
    small = {addr: sym.size for addr, sym in chosen.items()
             if sym.kind == SYM_OBJECT and sym.size in (1, 2)}
    words = {addr & ~3 for addr, size in small.items() if addr % 4}
    byte_sized = {addr for addr in small if (addr & ~3) in words}

    # Ce que la table écrite à la main renomme, cette table-ci n'a pas à le
    # nommer aussi : deux noms pour une adresse en laissent un référencé que
    # rien ne définit, et le lien le reçoit alors par son adresse absolue.
    # `jtbl_00377F10` est le seul cas — m2c exige ce nom-là, et `@1200`, que le
    # binaire porte, n'en est pas un.
    overridden = read_manual_addresses()

    lines: list[str] = []
    renamed = 0
    for addr in sorted(chosen):
        if addr in overridden:
            continue
        sym = chosen[addr]
        name, comment = candidate[addr], ""
        if counts[name] > 1:
            name = f"{name}_{addr:08X}"
            renamed += 1
        if name != sym.name:
            # Les attributs se lisent dans ce même commentaire : le nom
            # d'origine y va sans les deux-points qui les séparent.
            comment = " // " + sym.name.replace(":", "_")

        # Seules les fonctions se déclarent typées : le désassembleur n'admet
        # pour une donnée qu'un type précis — `u32`, `asciz`… — que le binaire
        # ne porte pas. La taille suffit à en borner l'étendue, et ce que
        # chaque objet contient se décidera à mesure qu'on le décompilera.
        #
        # Une exception, que le binaire fonde : un objet d'un ou deux octets
        # posé hors d'un multiple de quatre ne peut pas être étiqueté dans une
        # section que le désassembleur rend en mots, et le lien le reçoit alors
        # par son adresse absolue. Sa taille dit son type, et les dix
        # `CHA_DEV_FONT_PIECE_*` sont les seuls du binaire dans ce cas.
        entry = f"{name} = 0x{sym.value:08X};"
        if sym.kind == SYM_FUNC:
            entry += " // type:func"
            if sym.size:
                entry += f" size:0x{sym.size:X}"
        elif sym.value in byte_sized:
            entry += (f" // type:{'u8' if sym.size == 1 else 'u16'}"
                      f" size:0x{sym.size:X}")
        elif sym.size:
            entry += f" // size:0x{sym.size:X}"

        # Le désassembleur écrit un fichier par symbole et lui donne son nom.
        # Une signature manglée dépasse volontiers la limite de 255 octets que
        # les systèmes de fichiers imposent ; l'adresse nomme alors le fichier,
        # le symbole gardant le sien.
        if len(name.encode()) > 200:
            entry += f" filename:{'func' if sym.kind == SYM_FUNC else 'D'}_{sym.value:08X}"

        lines.append(entry + comment)

    path.write_text("\n".join(lines) + "\n", encoding="utf-8")
    return len(lines), renamed


def boot_symbols(elf: Elf) -> list[Symbol]:
    """Les fonctions d'amorçage, que le binaire ne déclare qu'en `NOTYPE`.

    Les 192 premiers octets de `.text` portent le point d'entrée et ses voisins
    — `_start` en `0x00100008`, `_exit`, `_root` —, et le binaire les nomme sans
    leur donner de type ni de taille. Écartés de la table, ils laissaient le
    désassembleur inventer `func_00100008` et le découpage ne pas voir cette
    zone du tout : elle commençait avant la première fonction connue.

    Le filtre est étroit à dessein, et le binaire le rend exact : un `NOTYPE`
    nommé, dans `.text`, qu'aucun `FUNC` ni `OBJECT` ne nomme et qu'aucune
    fonction dimensionnée ne couvre. Trois symboles y répondent, et ce sont
    ceux-là ; les marqueurs du compilateur — `gcc2_compiled.`, `__gnu_compiled_c`
    — tombent tous à des adresses déjà couvertes.
    """
    text_low = LOAD_VADDR
    text_high = min(section_starts(elf).get(".vutext", [text_low]))

    spans = sorted((s.value, s.value + s.size) for s in elf.symbols
                   if s.kind in (SYM_FUNC, SYM_OBJECT) and s.size and s.value)
    named = {s.value for s in elf.symbols
             if s.kind in (SYM_FUNC, SYM_OBJECT) and s.name and s.value}

    found: dict[int, Symbol] = {}
    for sym in sorted(elf.symbols, key=lambda s: (s.value, s.name)):
        if (sym.kind != SYM_NOTYPE or not sym.name or sym.name.startswith(".")
                or not text_low <= sym.value < text_high
                or sym.value in named
                or any(low <= sym.value < high for low, high in spans)):
            continue
        # Le type manque au binaire, mais l'emplacement le dit : dans `.text`,
        # ce qu'on nomme est du code.
        found.setdefault(sym.value,
                         Symbol(sym.name, sym.value, 0, SYM_FUNC, sym.shndx))
    return list(found.values())


def read_manual_addresses() -> set[int]:
    """Les adresses que `config/symbol_addrs.txt` nomme à la main.

    C'est la table que le projet écrit et que le désassembleur lit après
    celle-ci ; ce qu'elle nomme prime, et redonner ici un second nom à la même
    adresse laisserait celui-ci référencé sans que rien le définisse.
    """
    path = CONFIG_DIR / "symbol_addrs.txt"
    if not path.exists():
        return set()
    found = set()
    for line in path.read_text(encoding="utf-8").splitlines():
        line = line.split("//", 1)[0].strip()
        if "=" in line and line.endswith(";"):
            try:
                found.add(int(line.split("=", 1)[1].rstrip(";").strip(), 16))
            except ValueError:
                continue
    return found


def read_units() -> list[tuple[int, int, str, tuple[int, int] | None]]:
    """Les unités que le projet reconstruit, telles que `config/units.txt` les
    déclare : début, fin, nom, et la plage `.rodata` qui les accompagne.

    C'est la seule pièce du découpage qui s'écrit à la main, et la seule qui se
    versionne : les frontières des 49 unités d'origine ne sont pas dans le
    binaire, donc elles se décident.

    La plage `.rodata` est facultative et s'écrit `rodata:<début>-<fin>`. Elle
    sert aux unités dont une fonction saute par table : celle-ci vit en lecture
    seule mais désigne des étiquettes du corps, et les deux doivent finir dans
    le même objet.
    """
    path = CONFIG_DIR / "units.txt"
    if not path.exists():
        return []

    units = []
    for number, line in enumerate(path.read_text(encoding="utf-8").splitlines(), 1):
        line = line.split("#", 1)[0].strip()
        if not line:
            continue
        fields = line.split()
        if len(fields) not in (3, 4):
            raise SystemExit(f"config/units.txt ligne {number} : "
                             f"attendu « début fin nom [rodata:début-fin] »")
        start, end, name = int(fields[0], 16), int(fields[1], 16), fields[2]
        if end <= start:
            raise SystemExit(f"config/units.txt ligne {number} : "
                             f"{name} finit avant de commencer")

        rodata = None
        if len(fields) == 4:
            if not fields[3].startswith("rodata:") or "-" not in fields[3]:
                raise SystemExit(f"config/units.txt ligne {number} : "
                                 f"attendu « rodata:début-fin », lu « {fields[3]} »")
            low, high = fields[3][len("rodata:"):].split("-", 1)
            rodata = (int(low, 16), int(high, 16))
            if rodata[1] <= rodata[0]:
                raise SystemExit(f"config/units.txt ligne {number} : "
                                 f"la plage rodata de {name} finit avant de commencer")
        units.append((start, end, name, rodata))

    units.sort()
    for (a_start, a_end, a_name, _a), (b_start, _b_end, b_name, _b) in zip(units, units[1:]):
        if b_start < a_end:
            raise SystemExit(f"config/units.txt : {a_name} et {b_name} se recouvrent")
    return units


def vu_tails(elf: Elf, boundaries: list[tuple[int, str]]) -> list[tuple[int, str]]:
    """Les frontières qui rendent aux données ce qu'un bloc VU avale.

    Un microprogramme vectoriel n'a pas de symbole dimensionné — seulement un
    nom d'entrée, de taille nulle —, donc rien ne borne son sous-segment, qui
    court jusqu'à la contribution suivante. Or celle-ci arrive après les
    descripteurs RTTI et les littéraux que la section d'à côté porte : trente
    symboles se retrouvaient ainsi dans un bloc d'octets, qui n'en définit
    aucun, et le lien les recevait par leur adresse absolue.

    La borne est le premier symbole dimensionné qui suit le début du bloc, et ce
    qui reste prend le type de la section d'après — `.data` pour la queue de
    `.vutext`, `.rodata` pour celle de `.vudata`, comme le binaire les range.
    """
    sized = sorted(s.value for s in elf.symbols
                   if s.kind in (SYM_OBJECT, SYM_FUNC) and s.size and s.value)

    order = {name: index for index, name in enumerate(SECTION_ORDER)}
    added: list[tuple[int, str]] = []
    for (start, section), (stop, _next) in zip(boundaries, boundaries[1:]):
        if section not in (".vutext", ".vudata"):
            continue
        inside = [addr for addr in sized if start < addr < stop]
        if not inside:
            continue
        # Le type de la queue est celui de la première section qui suit le bloc
        # dans l'ordre où l'éditeur de liens les dispose.
        following = next((name for name in SECTION_ORDER
                          if order[name] > order[section]
                          and name in (".data", ".rodata")), ".rodata")
        added.append((min(inside), following))
    return added


def build_segments(elf: Elf, main: Section) -> tuple[list[tuple[int, str, str]], int]:
    """Découpe la section chargée en sous-segments splat.

    Un sous-segment par contribution d'objet, plus les plages que
    `config/units.txt` réclame. Une plage déclarée devient un sous-segment de
    type `c` : le désassembleur en écrit alors une fonction par fichier, sous
    `asm/nonmatchings/`, et l'éditeur de liens y attend l'objet compilé depuis
    `src/` à la place de l'assemblé.
    """
    starts = section_starts(elf)

    # Le type splat de chaque section d'origine. Les sections VU portent des
    # instructions vectorielles, que le désassembleur MIPS ne doit pas lire ;
    # elles restent des octets jusqu'à ce qu'un outil dédié les prenne.
    splat_type = {
        ".text": "asm", ".vutext": "bin", ".data": "data", ".vudata": "bin",
        ".rodata": "rodata", ".sdata": "data",
    }

    boundaries: list[tuple[int, str]] = []
    for section_name in SECTION_ORDER:
        for addr in starts.get(section_name, []):
            boundaries.append((addr, section_name))

    # L'amorçage précède le premier symbole de section nommé et n'est couvert
    # par aucun : le fichier commence à l'adresse de chargement.
    if not boundaries or boundaries[0][0] != LOAD_VADDR:
        boundaries.insert(0, (LOAD_VADDR, ".text"))

    boundaries += vu_tails(elf, sorted(boundaries))

    # Une unité déclarée coupe la contribution qui la contient : sa borne de
    # début lui appartient, et la borne de fin rouvre du désassemblage.
    units = read_units()
    named: dict[int, str] = {}
    # Les plages `.rodata` qu'une unité réclame, et les frontières que leur
    # ouverture crée. Le désassemblage de référence les ignore : il garde tout
    # en assembleur, et une table de saut y reste avec le corps qu'elle
    # désigne.
    named_rodata: dict[int, str] = {}
    unit_rodata: set[int] = set()
    for start, end, name, rodata in units:
        boundaries.append((start, ".text"))
        boundaries.append((end, ".text"))
        named[start] = name
        if rodata is not None:
            low, high = rodata
            boundaries.append((low, ".rodata"))
            boundaries.append((high, ".rodata"))
            named_rodata[low] = name
            unit_rodata.update((low, high))

    boundaries.sort()
    # Deux frontières à la même adresse — une contribution d'objet qui commence
    # là où une unité déclarée commence — ne font qu'un sous-segment.
    unique: list[tuple[int, str]] = []
    for entry in boundaries:
        if not unique or unique[-1][0] != entry[0]:
            unique.append(entry)

    file_end = main.addr + main.size
    segments = []
    for addr, section_name in unique:
        if addr >= file_end:
            # Au-delà du contenu du fichier, c'est du bss : splat le décrit
            # par une taille, pas par des octets.
            continue
        rom_off = addr - main.addr
        if addr in named:
            # Le type `cpp` de splat, non `c` : le jeu est en C++, et son
            # mangling le dit. Le type `c` écrirait un `src/<nom>.c` à côté
            # du `.cpp`, et le lien recevrait deux fois la même unité.
            segments.append((rom_off, "cpp", named[addr]))
        elif addr in named_rodata:
            # Le point devant `rodata` est ce que splat exige pour rattacher la
            # plage au fichier de même nom : sans lui il en écrirait un second
            # désassemblage, et le lien recevrait deux fois les mêmes symboles.
            segments.append((rom_off, ".rodata", named_rodata[addr]))
        else:
            kind = splat_type.get(section_name, "data")
            segments.append((rom_off, kind, f"{section_name.lstrip('.')}/{addr:08X}"))

    dropped = {addr - main.addr for addr in unit_rodata}
    return segments, len(units), dropped


def bss_segments(main: Section, bss_end: int) -> list[tuple[int, str, str, int]]:
    """Le bss, en sous-segments qui le couvrent de bout en bout.

    Sans eux, les 2 457 symboles du bss arrivent au lien par leur adresse
    absolue, et aucune donnée ne peut alors bouger. Le type `bss` de splat les
    fait définir par une section.

    La couverture doit être entière, et c'est le fait qui décide de la forme :
    le script de lien range les `.bss` à la suite les uns des autres, sans
    adresse, donc un segment déclaré seul n'atterrit pas où le binaire l'avait.
    Ce n'est qu'en couvrant tout, dans l'ordre, que la concaténation retombe
    juste.

    L'offset ROM est celui de la fin du fichier : le bss n'occupe pas d'octets
    sur le disque, et c'est le `vram` qui dit où il vit.
    """
    file_end = main.addr + main.size
    return [(file_end - main.addr, "bss", f"bss/{file_end:08X}", file_end)]


YAML_HEADER = """\
# Découpage de {basename}, engendré par scripts/setup/configure.py.
#
# Les frontières viennent des 316 symboles de section du binaire : chacune
# marque le début de la contribution d'un objet. Elles ne sont pas devinées.
name: Dark Chronicle (PAL)
sha1: {sha1}
options:
  platform: ps2
  compiler: MWCCPS2
  basename: {basename}
  # Les chemins se résolvent depuis le fichier de découpage, qui est dans
  # config/ ; la racine du projet est donc un cran au-dessus.
  base_path: ..
  target_path: rom/main.bin
  elf_path: build/{basename}.elf
  ld_script_path: linker_scripts/{basename}.ld
  asm_path: asm
  src_path: src
  build_path: build
  asset_path: bin
  symbol_addrs_path:
    - config/elf_symbol_addrs.txt
    - config/symbol_addrs.txt
  undefined_syms_auto_path: linker_scripts/auto/undefined_syms_auto.ld
  undefined_funcs_auto_path: linker_scripts/auto/undefined_funcs_auto.ld

  # $gp adresse les globales : 15 869 relocations en dépendent, et
  # l'assembleur doit recevoir la même base pour réencoder les mêmes octets.
  gp_value: 0x{gp:08X}

  # Les frontières étant connues, chercher les fichiers à tâtons ne ferait
  # qu'introduire des coupures que le binaire dément.
  find_file_boundaries: False

  o_as_suffix: True
  create_asm_dependencies: True
  ld_dependencies: True
  asm_function_macro: glabel
  asm_jtbl_label_macro: jlabel
  asm_data_macro: dlabel
  # Le marqueur qui précède un symbole encore en assembleur. mwccgap le
  # rencontre dans la section `.rodata` d'une fonction greffée — une table de
  # saut migrée avec son corps — et n'y reconnaît que ce nom-là ; sous celui
  # que splat emploie par défaut, il s'arrête sur « Unexpected entry in
  # .rodata section ».
  asm_nonmatching_label_macro: nmlabel

  # L'en-tête des fichiers qu'une source inclut. Le profil MWCCPS2 le laisse
  # vide là où celui de GCC le renseigne : sans lui, l'assembleur réordonne et
  # remplit les créneaux de délai, ce qui glisse un `nop` de plus dans chaque
  # fonction greffée et décale toutes les cibles de branchement d'un mot.
  #
  # `macro.inc` y est aussi pour que chaque fichier s'assemble seul, ce dont
  # `make diff` a besoin ; son garde interne le rend inoffensif quand mwccgap
  # le préfixe déjà.
  asm_inc_header: |
    .include "macro.inc"
    .set noat
    .set noreorder
  mnemonic_ljust: 12
  rom_address_padding: True
  dump_symbols: True
  string_encoding: ASCII
  data_string_encoding: ASCII

  section_order:
{section_order}

segments:
  - name: main
    type: code
    start: 0x0
    vram: 0x{vram:08X}
    bss_size: 0x{bss_size:X}
    # L'alignement borne la fin de chaque groupe — texte, données, lecture
    # seule. Le binaire les enchaîne sur huit octets : `.rodata` y commence en
    # 0x00363808, que tout alignement plus large repousserait. À 128, les
    # données partaient 0x78 trop loin et chaque référence à une globale
    # ratait sa cible d'autant.
    align: 8
    subalign: null
    subsegments:
"""


def write_yaml(path: Path, basename: str, sha1: str, main: Section,
               bss_end: int, segments: list[tuple[int, str, str]],
               reference: bool = False) -> None:
    order = "\n".join(f"    - {name}" for name in SECTION_ORDER)
    body = YAML_HEADER.format(
        basename=basename, sha1=sha1, gp=GP_VALUE, vram=main.addr,
        bss_size=bss_end - (main.addr + main.size), section_order=order,
    )
    if reference:
        # Le désassemblage de référence sort ailleurs et ne touche ni les
        # sources ni le script de lien du projet : il n'est là que pour donner
        # à objdiff l'objet contre lequel comparer.
        body = (body
                .replace("asm_path: asm", "asm_path: ref/asm")
                .replace("build_path: build", "build_path: build/ref")
                .replace(f"ld_script_path: linker_scripts/{basename}.ld",
                         f"ld_script_path: linker_scripts/ref/{basename}.ld")
                .replace("undefined_syms_auto_path: linker_scripts/auto/",
                         "undefined_syms_auto_path: linker_scripts/ref/auto/")
                .replace("undefined_funcs_auto_path: linker_scripts/auto/",
                         "undefined_funcs_auto_path: linker_scripts/ref/auto/"))

    # Un sous-segment du bss porte un quatrième champ, son adresse : n'occupant
    # aucun octet du fichier, il partage l'offset ROM de la fin de celui-ci, et
    # seule la forme longue permet de dire où il vit.
    lines = [
        (f"      - {{ start: 0x{entry[0]:X}, type: {entry[1]}, "
         f"name: {entry[2]}, vram: 0x{entry[3]:08X} }}")
        if len(entry) == 4 else
        f"      - [0x{entry[0]:X}, {entry[1]}, {entry[2]}]"
        for entry in segments
    ]
    # Le marqueur de fin se pose au niveau des segments : c'est de là que splat
    # tire la borne haute du dernier, et son absence lui fait chercher une
    # adresse suivante qui n'existe pas.
    lines.append("")
    lines.append(f"  - [0x{main.size:X}]")
    path.write_text(body + "\n".join(lines) + "\n", encoding="utf-8")


def as_reference(segments: list[tuple[int, str, str]],
                 dropped: set[int]) -> list[tuple[int, str, str]]:
    """Le même découpage, mais entièrement désassemblé.

    Une unité passée en C++ n'est plus extraite : le désassembleur n'écrit
    alors que les fonctions qu'un `INCLUDE_ASM` réclame, et la fonction
    reconstruite perd la référence contre laquelle on la mesure. Ce second
    découpage la garde — c'est la même voie que DCDecomp, dont le CMakeLists
    assemble chaque dump « whether or not the link ends up using it ».

    Les coupures que la plage `.rodata` d'une unité ouvre n'y sont pas
    reportées : une table de saut désigne des étiquettes du corps qu'elle sert,
    et les séparer laisserait l'assembleur devant un symbole qu'aucun fichier
    ne définit.
    """
    return [
        entry if len(entry) == 4 else
        (entry[0], "asm" if entry[1] == "cpp" else entry[1],
         f"text/{entry[2]}" if entry[1] == "cpp" else entry[2])
        for entry in segments
        if entry[0] not in dropped or len(entry) == 4
    ]


# --------------------------------------------------------------------------

def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--force", action="store_true",
                        help="réextrait l'exécutable même s'il est déjà là")
    args = parser.parse_args()

    CONFIG_DIR.mkdir(exist_ok=True)

    executable = ROM_DIR / BOOT_NAME
    if args.force or not executable.exists():
        disc = find_disc()
        print(f"disque   {disc.name}")
        payload = iso_extract(disc, BOOT_NAME)
        executable.write_bytes(payload)
    else:
        payload = executable.read_bytes()

    sha1 = hashlib.sha1(payload).hexdigest()
    print(f"exécutable {BOOT_NAME}  {len(payload)} octets  sha1 {sha1}")

    elf = read_elf(payload)
    main_section = elf.section("main")

    # La fin de la mémoire du segment : le tas commence là où le bss s'arrête.
    heap = elf.section("heap")
    bss_end = heap.addr

    image = payload[main_section.offset:main_section.offset + main_section.size]
    (ROM_DIR / "main.bin").write_bytes(image)
    image_sha1 = hashlib.sha1(image).hexdigest()

    (CONFIG_DIR / "main.sha1").write_text(f"{image_sha1}  main.bin\n", encoding="utf-8")
    print(f"section  main     0x{main_section.addr:08X} + {main_section.size} octets"
          f"  sha1 {image_sha1}")
    print(f"bss               0x{main_section.addr + main_section.size:08X}"
          f" .. 0x{bss_end:08X}  ({bss_end - main_section.addr - main_section.size} octets)")

    count, renamed = write_symbol_addrs(elf, CONFIG_DIR / "elf_symbol_addrs.txt")
    print(f"symboles {count} écrits dans config/elf_symbol_addrs.txt"
          f" ({renamed} homonymes suffixés de leur adresse)")

    starts = section_starts(elf)
    summary = ", ".join(f"{n} ×{len(v)}" for n, v in sorted(starts.items()))
    print(f"sections d'origine : {summary}")

    write_sections(starts, CONFIG_DIR / "elf_sections.txt")

    segments, unit_count, dropped = build_segments(elf, main_section)
    segments += bss_segments(main_section, bss_end)
    write_yaml(CONFIG_DIR / "splat.yaml", BOOT_NAME, image_sha1,
               main_section, bss_end, segments)
    print(f"découpage {len(segments)} sous-segments dans config/splat.yaml,"
          f" dont {unit_count} reconstruits depuis src/")

    write_yaml(CONFIG_DIR / "splat.ref.yaml", BOOT_NAME, image_sha1,
               main_section, bss_end, as_reference(segments, dropped),
               reference=True)
    print("référence complète dans config/splat.ref.yaml")

    # Une table écrite à la main, où les corrections de nommage se posent.
    manual = CONFIG_DIR / "symbol_addrs.txt"
    if not manual.exists():
        manual.write_text(
            "// Symboles nommés à la main. Ce fichier est lu après\n"
            "// elf_symbol_addrs.txt et le corrige.\n", encoding="utf-8"
        )

    return 0


if __name__ == "__main__":
    sys.exit(main())
