/* Fonctions libres — à décrire.
 *
 * Unité découpée par `make carve` : 6 fonctions, 6424 octets, de
 * 0x0012A7D0 à 0x0012C0F0. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

INCLUDE_ASM("nonmatchings/runtime/vfprintf_r", __sprint);
INCLUDE_ASM("nonmatchings/runtime/vfprintf_r", __sbprintf);
INCLUDE_ASM("nonmatchings/runtime/vfprintf_r", vfprintf);
INCLUDE_ASM("nonmatchings/runtime/vfprintf_r", _vfprintf_r);
INCLUDE_ASM("nonmatchings/runtime/vfprintf_r", cvt);
INCLUDE_ASM("nonmatchings/runtime/vfprintf_r", exponent);
