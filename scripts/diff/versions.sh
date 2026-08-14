#!/usr/bin/env bash
# Compile un fragment avec chacune des versions publiées et rapporte l'ordre
# dans lequel les `mtc1` servent $f12..$f15.
#
#   scripts/host/dc2 bash perm/versions.sh perm/cam_pile.cpp
#
# Le commerce sert cet ordre-là : 12 14 13 15, le zéro intercalé. Une version
# qui le rend se reconnaît d'un coup d'œil dans la colonne de droite.
set -uo pipefail

SOURCE="${1:?usage : versions.sh <fichier.cpp>}"
ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/../.." && pwd)"

for dir in "$ROOT"/tools/compilers/*/; do
    version="$(basename "$dir")"
    exe="$dir/mwccps2.exe"
    [ -f "$exe" ] || continue
    objet="$(mktemp -d)/probe.o"
    if ! MWCIncludes="$ROOT/include" wibo "$exe" -c -o "$objet" "$SOURCE" \
        -O4,p -lang c++ -char unsigned -str readonly -Cpp_exceptions off -sym on \
        -i "$ROOT/include" >/dev/null 2>&1; then
        printf '%-26s  (refus)\n' "$version"
        continue
    fi
    ordre="$(mips-ps2-decompals-objdump -d "$objet" \
        | sed -n 's/.*mtc1[[:space:]]*\([a-z0-9]*\),\$f1\([2345\]*\).*/\2/p' | tr '\n' ' ')"
    regs="$(mips-ps2-decompals-objdump -d "$objet" \
        | sed -n 's/.*mtc1[[:space:]]*\([a-z0-9]*\),\$f1[2345].*/\1/p' \
        | grep -v zero | sort -u | tr '\n' '+' | sed 's/+$//')"
    printf '%-26s  ordre=%-14s registres=%s\n' "$version" "$ordre" "$regs"
done
