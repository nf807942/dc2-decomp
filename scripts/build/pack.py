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
    if len(payload) != size:
        raise SystemExit(
            f"la section construite fait {len(payload)} octets, "
            f"le disque en attend {size} — `make build` doit passer d'abord"
        )

    elf[offset:offset + size] = payload

    output = BUILD_DIR / BOOT_NAME
    output.write_bytes(bytes(elf))
    print(f"{output.relative_to(ROOT)}  {len(elf)} octets"
          f"  (section main injectée à 0x{offset:X})")
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
    if len(payload) > size:
        raise SystemExit("l'exécutable a grossi : l'image ne peut plus le loger")

    # L'image est copiée puis retouchée en place : le disque de l'utilisateur
    # reste intact, et la table des fichiers n'a pas à être refaite puisque
    # l'exécutable garde sa taille.
    print(f"copie de {disc.name} ({disc.stat().st_size // (1024 * 1024)} Mio)…")
    # Une image d'un tour précédent est encore là, et Windows refuse d'écrire
    # par-dessus tant qu'un lecteur la tient ouverte.
    output.unlink(missing_ok=True)
    shutil.copyfile(disc, output)

    with output.open("r+b") as f:
        f.seek(offset)
        f.write(payload)
        # Ce qui reste du dernier secteur appartient encore au fichier.
        f.write(b"\x00" * (size - len(payload)))

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
