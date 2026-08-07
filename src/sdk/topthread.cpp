/* Fonctions libres — à décrire.
 *
 * Unité découpée par `make carve` : 5 fonctions, 852 octets, de
 * 0x00110D60 à 0x001110C0. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

INCLUDE_ASM("nonmatchings/sdk/topthread", topThread);
INCLUDE_ASM("nonmatchings/sdk/topthread", InitThread);
INCLUDE_ASM("nonmatchings/sdk/topthread", iWakeupThread);
INCLUDE_ASM("nonmatchings/sdk/topthread", iRotateThreadReadyQueue);
INCLUDE_ASM("nonmatchings/sdk/topthread", iSuspendThread);
