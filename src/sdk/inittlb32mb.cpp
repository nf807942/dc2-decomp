/* Fonctions libres — à décrire.
 *
 * Unité découpée par `make carve` : 19 fonctions, 1268 octets, de
 * 0x00118188 à 0x001186C0. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

INCLUDE_ASM("nonmatchings/sdk/inittlb32mb", SetTLBHandler);
INCLUDE_ASM("nonmatchings/sdk/inittlb32mb", SetDebugHandler);
INCLUDE_ASM("nonmatchings/sdk/inittlb32mb", Copy_00118270);
INCLUDE_ASM("nonmatchings/sdk/inittlb32mb", kCopy_00118280);
INCLUDE_ASM("nonmatchings/sdk/inittlb32mb", GetEntryAddress_001182B8);
INCLUDE_ASM("nonmatchings/sdk/inittlb32mb", setup_001182C8);
INCLUDE_ASM("nonmatchings/sdk/inittlb32mb", InitTLBFunctions);
INCLUDE_ASM("nonmatchings/sdk/inittlb32mb", PutTLBEntry);
INCLUDE_ASM("nonmatchings/sdk/inittlb32mb", iPutTLBEntry);
INCLUDE_ASM("nonmatchings/sdk/inittlb32mb", _SetTLBEntry);
INCLUDE_ASM("nonmatchings/sdk/inittlb32mb", SetTLBEntry);
INCLUDE_ASM("nonmatchings/sdk/inittlb32mb", iSetTLBEntry);
INCLUDE_ASM("nonmatchings/sdk/inittlb32mb", GetTLBEntry);
INCLUDE_ASM("nonmatchings/sdk/inittlb32mb", iGetTLBEntry);
INCLUDE_ASM("nonmatchings/sdk/inittlb32mb", ProbeTLBEntry);
INCLUDE_ASM("nonmatchings/sdk/inittlb32mb", iProbeTLBEntry);
INCLUDE_ASM("nonmatchings/sdk/inittlb32mb", ExpandScratchPad);
INCLUDE_ASM("nonmatchings/sdk/inittlb32mb", InitTLB);
INCLUDE_ASM("nonmatchings/sdk/inittlb32mb", InitTLB32MB);
