/* Fonctions libres — à décrire.
 *
 * Unité découpée par `make carve` : 14 fonctions, 876 octets, de
 * 0x001109F0 à 0x00110D60. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

INCLUDE_ASM("nonmatchings/sdk/initalarm", QueryIntrContext);
INCLUDE_ASM("nonmatchings/sdk/initalarm", DisableIntc);
INCLUDE_ASM("nonmatchings/sdk/initalarm", EnableIntc);
INCLUDE_ASM("nonmatchings/sdk/initalarm", DisableDmac);
INCLUDE_ASM("nonmatchings/sdk/initalarm", EnableDmac);
INCLUDE_ASM("nonmatchings/sdk/initalarm", iEnableIntc);
INCLUDE_ASM("nonmatchings/sdk/initalarm", iDisableIntc);
INCLUDE_ASM("nonmatchings/sdk/initalarm", iEnableDmac);
INCLUDE_ASM("nonmatchings/sdk/initalarm", iDisableDmac);
INCLUDE_ASM("nonmatchings/sdk/initalarm", setup_00110C20);
INCLUDE_ASM("nonmatchings/sdk/initalarm", Copy_00110C30);
INCLUDE_ASM("nonmatchings/sdk/initalarm", kCopy_00110C40);
INCLUDE_ASM("nonmatchings/sdk/initalarm", GetEntryAddress_00110C78);
INCLUDE_ASM("nonmatchings/sdk/initalarm", InitAlarm);
