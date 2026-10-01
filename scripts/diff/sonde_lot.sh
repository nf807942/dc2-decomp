#!/usr/bin/env bash
# Compile un dossier de variantes en une seule invocation du conteneur, et
# résume chacune par les instructions qui portent le motif cherché.
#
#   scripts/host/dc2 bash scripts/diff/sonde_lot.sh perm/variantes 'lui|mtc1'
#
# `probe.sh` répond en une seconde sur une forme ; ce script répond en une
# seconde sur cent, parce que le coût qui reste est celui du démarrage du
# conteneur, non celui de MWCC. C'est ce qui a rendu bissectable la forme des
# constantes de `__ct__14CCameraControlFv` : sept positions de la temporaire,
# quatre découpes d'arguments par défaut et six formes de construction, mesurées
# d'un trait au lieu de dix minutes de `make diff` chacune.
#
# La signature tient sur une ligne par variante, ce qui rend l'écart visible à
# l'œil : c'est le résumé qu'on compare, non le désassemblage entier.
set -u

DOSSIER="${1:?usage : sonde_lot.sh <dossier> [motif]}"
MOTIF="${2:-lui|mtc1}"

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/../.." && pwd)"

# `MWCC_VERSION=…` sert une autre version comme instrument : quand une version
# rend la forme du commerce sur un fragment et la nôtre sur la fonction entière,
# c'est qu'elle est sensible à un écart de source, et elle le détecte.
MWCC="$ROOT/tools/compilers/${MWCC_VERSION:-mwcps2-3.0-011126}/mwccps2.exe"
TRAVAIL="$(mktemp -d)"

for source in "$DOSSIER"/*.cpp; do
    [ -e "$source" ] || { echo "aucun .cpp dans $DOSSIER" >&2; exit 1; }
    nom="$(basename "$source" .cpp)"
    objet="$TRAVAIL/$nom.o"

    # Les mêmes drapeaux que le Makefile donne à chaque unité.
    if ! MWCIncludes="$ROOT/include" wibo "$MWCC" -c -o "$objet" "$source" \
        -O4,p -lang c++ -char unsigned -str readonly -Cpp_exceptions off \
        -RTTI off -sym on -i "$ROOT/include" -i "$ROOT/src" >/dev/null 2>&1
    then
        printf '%-24s COMPILATION ÉCHOUÉE\n' "$nom"
        continue
    fi

    printf '%-24s ' "$nom"
    mips-ps2-decompals-objdump -d --section=.text "$objet" \
        | grep -E "$MOTIF" \
        | awk '{printf "%s %s | ", $3, $4} END {print ""}'
done
