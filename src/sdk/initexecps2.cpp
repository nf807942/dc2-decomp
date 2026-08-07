/* Fonctions libres — à décrire.
 *
 * Unité découpée par `make carve` : 6 fonctions, 380 octets, de
 * 0x00118BC0 à 0x00118D40. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

INCLUDE_ASM("nonmatchings/sdk/initexecps2", setup_00118BC0);
INCLUDE_ASM("nonmatchings/sdk/initexecps2", Copy_00118BD0);
INCLUDE_ASM("nonmatchings/sdk/initexecps2", kCopy_00118BE0);
INCLUDE_ASM("nonmatchings/sdk/initexecps2", GetEntryAddress_00118C18);
INCLUDE_ASM("nonmatchings/sdk/initexecps2", PatchIsNeeded);
INCLUDE_ASM("nonmatchings/sdk/initexecps2", InitExecPS2);
