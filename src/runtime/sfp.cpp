/* Fonctions libres — à décrire.
 *
 * Unité découpée par `make carve` : 6 fonctions, 588 octets, de
 * 0x00125430 à 0x00125688. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

INCLUDE_ASM("nonmatchings/runtime/sfp", std);
INCLUDE_ASM("nonmatchings/runtime/sfp", __sfmoreglue);
INCLUDE_ASM("nonmatchings/runtime/sfp", __sfp);
INCLUDE_ASM("nonmatchings/runtime/sfp", _cleanup_r);
INCLUDE_ASM("nonmatchings/runtime/sfp", _cleanup);
INCLUDE_ASM("nonmatchings/runtime/sfp", __sinit);
