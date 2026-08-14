#!/usr/bin/env bash
# Compile un fragment isolé avec les drapeaux du projet et le désassemble.
#
#   scripts/host/dc2 bash scripts/diff/probe.sh mon_essai.cpp
#   scripts/host/dc2 bash scripts/diff/probe.sh mon_essai.cpp 'lui|mtc1'
#
# Quand un écart tient à quelques instructions, `make diff` coûte quatre-vingt-
# dix secondes par forme : mwccgap regreffe l'unité entière, puis objdiff la
# compare. Un fragment qui reproduit le motif se compile en une seconde, et
# c'est ce qui rend une centaine de formes abordable.
#
# La reproduction est à faire d'abord : recopier le voisinage jusqu'à retrouver
# les mêmes registres. Un fragment qui n'a pas la même pression sur les
# registres répond à une autre question que celle qu'on pose.
set -euo pipefail

SOURCE="${1:?usage : probe.sh <fichier.cpp> [motif]}"
MOTIF="${2:-}"

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/../.." && pwd)"
MWCC="$ROOT/tools/compilers/mwcps2-3.0-011126/mwccps2.exe"
OBJET="$(mktemp -d)/probe.o"

# Les mêmes drapeaux que le Makefile donne à chaque unité : un fragment compilé
# autrement ne dit rien de la reconstruction.
MWCIncludes="$ROOT/include" wibo "$MWCC" -c -o "$OBJET" "$SOURCE" \
    -O4,p -lang c++ -char unsigned -str readonly -Cpp_exceptions off -sym on \
    -i "$ROOT/include" -i "$ROOT/src"

if [ -n "$MOTIF" ]; then
    mips-ps2-decompals-objdump -d "$OBJET" | grep -E "$MOTIF"
else
    mips-ps2-decompals-objdump -d "$OBJET"
fi
