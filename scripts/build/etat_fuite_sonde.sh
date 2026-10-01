#!/usr/bin/env bash
# Sonde : MWCC 3.0 garde-t-il un état d'une unité à l'autre d'une même
# invocation ? Compile chaque unité seule, puis toutes ensemble, et compare
# les objets. Une différence dans le .text prouve un état porté.
set -u
OUT=${OUT:-/tmp/fuite}
rm -rf "$OUT"; mkdir -p "$OUT/seul" "$OUT/lot"
CF="-O4,p -lang c++ -char unsigned -str readonly -Cpp_exceptions off -RTTI off -sym on -i include -i src"
export MWCIncludes=include
MW=tools/compilers/mwcps2-3.0-011126/mwccps2.exe
FILES=$(ls "$@")
for f in $FILES; do
  b=$(basename "$f" .cpp)
  cp "$f" "$OUT/$b.c"                      # même extension que mwccgap
  wibo $MW -c $CF -o "$OUT/seul/$b.o" "$OUT/$b.c" >/dev/null 2>&1 || echo "échec seul: $b"
done
wibo $MW -c $CF -o "$OUT/lot" $(for f in $FILES; do echo "$OUT/$(basename $f .cpp).c"; done) >"$OUT/lot.log" 2>&1
ls "$OUT/lot" | head -3
for f in $FILES; do
  b=$(basename "$f" .cpp)
  s="$OUT/seul/$b.o"; l="$OUT/lot/$b.o"
  [ -f "$s" ] && [ -f "$l" ] || { echo "manque: $b"; continue; }
  cmp -s "$s" "$l" && echo "= $b" || echo "≠ $b"
done
