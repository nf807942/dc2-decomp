/* Fonctions libres — à décrire.
 *
 * Unité découpée par `make carve` : 17 fonctions, 4100 octets, de
 * 0x00127128 à 0x00128148. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

INCLUDE_ASM("nonmatchings/runtime/multiply", _Balloc);
INCLUDE_ASM("nonmatchings/runtime/multiply", _Bfree);
INCLUDE_ASM("nonmatchings/runtime/multiply", _multadd);
INCLUDE_ASM("nonmatchings/runtime/multiply", _s2b);
INCLUDE_ASM("nonmatchings/runtime/multiply", _hi0bits);
INCLUDE_ASM("nonmatchings/runtime/multiply", _lo0bits);
INCLUDE_ASM("nonmatchings/runtime/multiply", _i2b);
INCLUDE_ASM("nonmatchings/runtime/multiply", _multiply);
INCLUDE_ASM("nonmatchings/runtime/multiply", _pow5mult);
INCLUDE_ASM("nonmatchings/runtime/multiply", _lshift);
INCLUDE_ASM("nonmatchings/runtime/multiply", __mcmp);
INCLUDE_ASM("nonmatchings/runtime/multiply", __mdiff);
INCLUDE_ASM("nonmatchings/runtime/multiply", _ulp);
INCLUDE_ASM("nonmatchings/runtime/multiply", _b2d);
INCLUDE_ASM("nonmatchings/runtime/multiply", _d2b);
INCLUDE_ASM("nonmatchings/runtime/multiply", _ratio);
INCLUDE_ASM("nonmatchings/runtime/multiply", _mprec_log10);
