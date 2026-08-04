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

    # Le nom final se déduit en deux temps : assainissement, puis levée des
    # collisions par l'adresse. Compter les homonymes avant l'assainissement
    # manquerait ceux que celui-ci confond.
    candidate = {addr: sanitize(sym.name) for addr, sym in chosen.items()}
    counts: dict[str, int] = {}
    for name in candidate.values():
        counts[name] = counts.get(name, 0) + 1

    lines: list[str] = []
    renamed = 0
    for addr in sorted(chosen):
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
        entry = f"{name} = 0x{sym.value:08X};"
        if sym.kind == SYM_FUNC:
            entry += " // type:func"
            if sym.size:
                entry += f" size:0x{sym.size:X}"
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


def build_segments(elf: Elf, main: Section) -> list[tuple[int, str, str]]:
    """Découpe la section chargée en sous-segments splat.

    Un sous-segment par contribution d'objet : c'est la granularité à laquelle
    le projet remplacera plus tard un `.s` par un `.cpp`.
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

    boundaries.sort()

    file_end = main.addr + main.size
    segments = []
    for addr, section_name in boundaries:
        if addr >= file_end:
            # Au-delà du contenu du fichier, c'est du bss : splat le décrit
            # par une taille, pas par des octets.
            continue
        kind = splat_type.get(section_name, "data")
        rom_off = addr - main.addr
        segments.append((rom_off, kind, f"{section_name.lstrip('.')}/{addr:08X}"))

    return segments


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
               bss_end: int, segments: list[tuple[int, str, str]]) -> None:
    order = "\n".join(f"    - {name}" for name in SECTION_ORDER)
    body = YAML_HEADER.format(
        basename=basename, sha1=sha1, gp=GP_VALUE, vram=main.addr,
        bss_size=bss_end - (main.addr + main.size), section_order=order,
    )
    lines = [f"      - [0x{off:X}, {kind}, {name}]" for off, kind, name in segments]
    # Le marqueur de fin se pose au niveau des segments : c'est de là que splat
    # tire la borne haute du dernier, et son absence lui fait chercher une
    # adresse suivante qui n'existe pas.
    lines.append("")
    lines.append(f"  - [0x{main.size:X}]")
    path.write_text(body + "\n".join(lines) + "\n", encoding="utf-8")


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

    segments = build_segments(elf, main_section)
    write_yaml(CONFIG_DIR / "splat.yaml", BOOT_NAME, image_sha1,
               main_section, bss_end, segments)
    print(f"découpage {len(segments)} sous-segments dans config/splat.yaml")

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
