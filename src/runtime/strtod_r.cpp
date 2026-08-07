/* Fonctions libres — à décrire.
 *
 * Unité découpée par `make carve` : 3 fonctions, 3920 octets, de
 * 0x001295E8 à 0x0012A540. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

INCLUDE_ASM("nonmatchings/runtime/strtod_r", _strtod_r);
INCLUDE_ASM("nonmatchings/runtime/strtod_r", strtod);
INCLUDE_ASM("nonmatchings/runtime/strtod_r", strtodf);
