#!/usr/bin/env python3
"""Rend un exécutable bootable, et l'image disque qui le porte.

    make elf     build/SCES_511.90   — l'exécutable, pour « Boot ELF »
    make iso     build/dc2.iso       — l'image entière, pour un lancement normal

La construction du projet produit le contenu de la section chargée, non un
fichier que la console sait démarrer : l'éditeur de liens ne reçoit ni point
d'entrée, ni les en-têtes que le noyau lit. Plutôt que de les reconstruire,
cet outil reprend l'exécutable du disque et y remplace la seule section que le
projet reconstruit. Tout le reste — point d'entrée, table des symboles,
relocations — vient donc du commerce, inchangé.

La section fait toujours la même taille, puisque la construction est vérifiée
contre le disque : l'injection ne déplace rien, et l'image garde sa table de
fichiers intacte.
"""

from __future__ import annotations

import argparse
import shutil
import struct
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from lib.project import BUILD_DIR, ROOT  # noqa: E402

ROM_DIR = ROOT / "rom"
BOOT_NAME = "SCES_511.90"

# Le secteur d'un CD-ROM. Une entrée de répertoire ISO 9660 donne une adresse
# en secteurs, et c'est par là qu'on retrouve l'exécutable dans l'image.
SECTOR = 2048


def grow_section(elf: bytearray, name: str, payload: bytes) -> bytearray:
    """Remplace une section par un contenu plus long, et répare l'ELF autour.

    Tant que la construction rend les octets du disque, l'injection est un
    simple remplacement. Mais le jalon des tailles libres demande de porter un
    exécutable plus long jusqu'à la console, et il faut alors décaler ce qui
    suit la section dans le fichier : les autres sections, la table qui les
    décrit, et les en-têtes de programme.

    Ce qui se corrige tient en quatre champs — la taille de la section, les
    `filesz` et `memsz` du segment chargé, et chaque offset de fichier au-delà
    du point d'insertion. Le contenu de `.symtab` et `.relmain` désigne des
    adresses virtuelles, non des offsets, et n'a donc pas à bouger ; la console
    ne les lit pas davantage.

    Une cinquième correction est en mémoire, et c'est celle qu'on ne voit pas
    venir : le `heap` commence exactement où le bss finit — `0x01F64A00` —, si
    bien qu'un texte plus long l'y ferait recouvrir. Ce qui vit au-delà de la
    fin du segment chargé se décale donc d'autant.
    """
    offset, size = section_span(bytes(elf), name)
    delta = len(payload) - size
    if delta == 0:
        elf[offset:offset + size] = payload
        return elf

    end = offset + size
    grown = bytearray(elf[:offset]) + bytearray(payload) + bytearray(elf[end:])

    shoff = struct.unpack_from("<I", grown, 0x20)[0]
    shentsize = struct.unpack_from("<H", grown, 0x2E)[0]
    shnum = struct.unpack_from("<H", grown, 0x30)[0]
    phoff = struct.unpack_from("<I", grown, 0x1C)[0]
    phentsize = struct.unpack_from("<H", grown, 0x2A)[0]
    phnum = struct.unpack_from("<H", grown, 0x2C)[0]

    # Les tables elles-mêmes se déplacent si elles vivent après l'insertion.
    if shoff >= end:
        struct.pack_into("<I", grown, 0x20, shoff + delta)
        shoff += delta
    if phoff >= end:
        struct.pack_into("<I", grown, 0x1C, phoff + delta)
        phoff += delta

    # La fin mémoire du segment chargé, telle qu'elle était : c'est là que le
    # `heap` commence, et c'est cette frontière que l'agrandissement pousse.
    memory_end = 0
    for i in range(phnum):
        base = phoff + i * phentsize
        p_offset, p_vaddr, _paddr, _filesz, p_memsz = struct.unpack_from(
            "<5I", grown, base + 0x04)
        if p_offset == offset:
            memory_end = p_vaddr + p_memsz

    for i in range(shnum):
        base = shoff + i * shentsize
        sh_addr = struct.unpack_from("<I", grown, base + 0x0C)[0]
        sh_offset, sh_size = struct.unpack_from("<II", grown, base + 0x10)
        if sh_offset == offset and sh_size == size:
            struct.pack_into("<I", grown, base + 0x14, len(payload))
        elif sh_offset >= end:
            struct.pack_into("<I", grown, base + 0x10, sh_offset + delta)
        if sh_addr and sh_addr >= memory_end:
            struct.pack_into("<I", grown, base + 0x0C, sh_addr + delta)

    for i in range(phnum):
        base = phoff + i * phentsize
        p_offset, p_vaddr, p_paddr, p_filesz, p_memsz = struct.unpack_from(
            "<5I", grown, base + 0x04)
        if p_offset == offset:
            struct.pack_into("<II", grown, base + 0x10,
                             p_filesz + delta, p_memsz + delta)
            continue
        if p_offset >= end:
            struct.pack_into("<I", grown, base + 0x04, p_offset + delta)
        if p_vaddr >= memory_end:
            struct.pack_into("<II", grown, base + 0x08,
                             p_vaddr + delta, p_paddr + delta)

    return grown


def section_span(elf: bytes, name: str) -> tuple[int, int]:
    """L'emplacement d'une section dans le fichier : offset et taille."""
    shoff = struct.unpack_from("<I", elf, 0x20)[0]
    shentsize = struct.unpack_from("<H", elf, 0x2E)[0]
    shnum = struct.unpack_from("<H", elf, 0x30)[0]
    shstrndx = struct.unpack_from("<H", elf, 0x32)[0]

    names_off = struct.unpack_from("<10I", elf, shoff + shstrndx * shentsize)[4]
    for i in range(shnum):
        fields = struct.unpack_from("<10I", elf, shoff + i * shentsize)
        end = elf.index(b"\x00", names_off + fields[0])
        if elf[names_off + fields[0]:end].decode("latin1") == name:
            return fields[4], fields[5]
    raise SystemExit(f"section {name} absente de l'exécutable du disque")


def find_disc() -> Path:
    candidates = sorted(
        p for p in ROM_DIR.iterdir()
        if p.suffix.lower() in (".iso", ".bin", ".img") and p.is_file()
    )
    if not candidates:
        raise SystemExit("aucune image disque dans rom/")
    return candidates[0]


def locate_in_iso(iso: Path, name: str) -> tuple[int, int]:
    """Où le fichier vit dans l'image : offset en octets, et taille."""
    with iso.open("rb") as f:
        f.seek(16 * SECTOR)
        pvd = f.read(SECTOR)
        if pvd[1:6] != b"CD001":
            raise SystemExit(f"{iso.name} n'est pas une image ISO 9660")

        root = pvd[156:190]
        lba = struct.unpack_from("<I", root, 2)[0]
        size = struct.unpack_from("<I", root, 10)[0]

        f.seek(lba * SECTOR)
        directory = f.read(size)

    offset = 0
    while offset < len(directory):
        length = directory[offset]
        if length == 0:
            offset = (offset // SECTOR + 1) * SECTOR
            continue
        entry = directory[offset:offset + length]
        entry_lba = struct.unpack_from("<I", entry, 2)[0]
        entry_size = struct.unpack_from("<I", entry, 10)[0]
        name_len = entry[32]
        if entry[33:33 + name_len].decode("latin1").split(";")[0] == name:
            return entry_lba * SECTOR, entry_size
        offset += length

    raise SystemExit(f"{name} introuvable dans {iso.name}")


def directory_entry(iso: Path, name: str) -> int:
    """L'offset, dans l'image, du champ de taille de l'entrée de répertoire.

    Un exécutable plus long tient dans les secteurs que l'image lui a déjà
    alloués — l'ISO arrondit —, mais la table des fichiers porte sa taille en
    octets, et le noyau ne lira que ce qu'elle annonce.
    """
    with iso.open("rb") as f:
        f.seek(16 * SECTOR)
        pvd = f.read(SECTOR)
        root = pvd[156:190]
        lba = struct.unpack_from("<I", root, 2)[0]
        size = struct.unpack_from("<I", root, 10)[0]
        f.seek(lba * SECTOR)
        directory = f.read(size)

    offset, base = 0, lba * SECTOR
    while offset < len(directory):
        length = directory[offset]
        if length == 0:
            offset = (offset // SECTOR + 1) * SECTOR
            continue
        entry = directory[offset:offset + length]
        name_len = entry[32]
        if entry[33:33 + name_len].decode("latin1").split(";")[0] == name:
            return base + offset + 10
        offset += length

    raise SystemExit(f"{name} introuvable dans {iso.name}")


def build_elf() -> Path:
    image = BUILD_DIR / "main.bin"
    if not image.exists():
        raise SystemExit("build/main.bin absent — lancez `make build`")

    retail = ROM_DIR / BOOT_NAME
    if not retail.exists():
        raise SystemExit(f"rom/{BOOT_NAME} absent — lancez `make setup`")

    elf = bytearray(retail.read_bytes())
    offset, size = section_span(bytes(elf), "main")

    payload = image.read_bytes()
    elf = grow_section(elf, "main", payload)

    output = BUILD_DIR / BOOT_NAME
    output.write_bytes(bytes(elf))
    grown = len(payload) - size
    note = f", {grown:+d} octets" if grown else ""
    print(f"{output.relative_to(ROOT)}  {len(elf)} octets"
          f"  (section main injectée à 0x{offset:X}{note})")
    return output


def build_iso(output: Path | None = None) -> Path:
    # Un exécutable plus récent que la construction a été retouché depuis :
    # le régénérer effacerait le mod, alors que c'est justement lui qu'on veut
    # porter dans l'image.
    existing = BUILD_DIR / BOOT_NAME
    image = BUILD_DIR / "main.bin"
    retouched = (existing.exists() and image.exists()
                 and existing.stat().st_mtime > image.stat().st_mtime)
    if retouched:
        executable = existing
        print(f"{executable.relative_to(ROOT)} conservé tel quel"
              f" (plus récent que la construction)")
    else:
        executable = build_elf()

    disc = find_disc()
    output = output or BUILD_DIR / "dc2.iso"
    offset, size = locate_in_iso(disc, BOOT_NAME)

    payload = executable.read_bytes()
    # L'image alloue des secteurs entiers : ce que l'exécutable peut gagner sans
    # que rien d'autre ait à bouger est ce que l'arrondi lui laisse.
    allotted = -(-size // SECTOR) * SECTOR
    if len(payload) > allotted:
        raise SystemExit(
            f"l'exécutable fait {len(payload)} octets et l'image ne lui en "
            f"alloue que {allotted} : la table des fichiers serait à refaire")

    # L'image est copiée puis retouchée en place : le disque de l'utilisateur
    # reste intact, et la table des fichiers ne demande qu'une taille à corriger
    # quand l'exécutable a grossi.
    print(f"copie de {disc.name} ({disc.stat().st_size // (1024 * 1024)} Mio)…")
    # Une image d'un tour précédent est encore là, et Windows refuse d'écrire
    # par-dessus tant qu'un lecteur la tient ouverte.
    output.unlink(missing_ok=True)
    shutil.copyfile(disc, output)

    with output.open("r+b") as f:
        f.seek(offset)
        f.write(payload)
        # Ce qui reste des secteurs alloués appartient encore au fichier.
        f.write(b"\x00" * (allotted - len(payload)))
        if len(payload) != size:
            # ISO 9660 écrit ses entiers deux fois, petit-boutiste puis
            # gros-boutiste ; le noyau lit l'un ou l'autre selon la machine.
            f.seek(directory_entry(disc, BOOT_NAME))
            f.write(struct.pack("<I", len(payload))
                    + struct.pack(">I", len(payload)))
            print(f"taille de {BOOT_NAME} portée à {len(payload)} octets "
                  f"dans la table des fichiers")

    shown = output.relative_to(ROOT) if output.is_absolute() else output
    print(f"{shown}  (exécutable remplacé à 0x{offset:X})")
    return output


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("target", choices=("elf", "iso"))
    # Une image déjà montée par un émulateur ne peut pas être réécrite ;
    # en produire une seconde évite d'avoir à le fermer.
    parser.add_argument("--output", help="nom de l'image à écrire")
    args = parser.parse_args()

    BUILD_DIR.mkdir(exist_ok=True)
    if args.target == "iso":
        build_iso(Path(args.output) if args.output else None)
    else:
        build_elf()
    return 0


if __name__ == "__main__":
    sys.exit(main())
