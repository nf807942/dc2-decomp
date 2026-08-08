/* L'amorçage : le point d'entrée que l'en-tête ELF désigne, et ses voisins.
 *
 * Le binaire ne les déclare qu'en `NOTYPE`, sans taille — `ENTRYPOINT` et
 * `_start` nomment la même adresse, `0x00100008`, et le premier mot de la
 * section n'a aucun nom. C'est l'emplacement qui dit que c'est du code, et
 * c'est pourquoi `configure.py` les reprend malgré leur type manquant.
 *
 * Les 192 octets étaient jusqu'ici la seule part de `.text` qu'aucune unité ne
 * couvrait, le découpage partant de la première fonction *connue*.
 */

#include "common.h"

INCLUDE_ASM("nonmatchings/sdk/crt0", func_00100000);
INCLUDE_ASM("nonmatchings/sdk/crt0", ENTRYPOINT);
INCLUDE_ASM("nonmatchings/sdk/crt0", _exit);
INCLUDE_ASM("nonmatchings/sdk/crt0", _root);
