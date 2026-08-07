/* Fonctions libres — à décrire.
 *
 * Unité découpée par `make carve` : 2 fonctions, 620 octets, de
 * 0x0012A540 à 0x0012A7B0. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

INCLUDE_ASM("nonmatchings/runtime/strtol_r", _strtol_r);
INCLUDE_ASM("nonmatchings/runtime/strtol_r", strtol);
