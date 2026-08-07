/* Fonctions libres — à décrire.
 *
 * Unité découpée par `make carve` : 15 fonctions, 3288 octets, de
 * 0x0028B8F8 à 0x0028C5F0. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

INCLUDE_ASM("nonmatchings/runtime/dpmul", __pack_d);
INCLUDE_ASM("nonmatchings/runtime/dpmul", __unpack_d);
INCLUDE_ASM("nonmatchings/runtime/dpmul", _fpadd_parts_0028BAC8);
INCLUDE_ASM("nonmatchings/runtime/dpmul", dpadd);
INCLUDE_ASM("nonmatchings/runtime/dpmul", dpsub);
INCLUDE_ASM("nonmatchings/runtime/dpmul", dpmul);
INCLUDE_ASM("nonmatchings/runtime/dpmul", dpdiv);
INCLUDE_ASM("nonmatchings/runtime/dpmul", __fpcmp_parts_d);
INCLUDE_ASM("nonmatchings/runtime/dpmul", dpcmp);
INCLUDE_ASM("nonmatchings/runtime/dpmul", litodp);
INCLUDE_ASM("nonmatchings/runtime/dpmul", dptoli);
INCLUDE_ASM("nonmatchings/runtime/dpmul", dptoul);
INCLUDE_ASM("nonmatchings/runtime/dpmul", __negdf2);
INCLUDE_ASM("nonmatchings/runtime/dpmul", __make_dp);
INCLUDE_ASM("nonmatchings/runtime/dpmul", dptofp);
