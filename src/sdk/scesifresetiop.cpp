/* Fonctions libres — à décrire.
 *
 * Unité découpée par `make carve` : 4 fonctions, 684 octets, de
 * 0x00117ED8 à 0x00118188. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

INCLUDE_ASM("nonmatchings/sdk/scesifresetiop", sceSifResetIop);
INCLUDE_ASM("nonmatchings/sdk/scesifresetiop", sceSifIsAliveIop);
INCLUDE_ASM("nonmatchings/sdk/scesifresetiop", sceSifSyncIop);
INCLUDE_ASM("nonmatchings/sdk/scesifresetiop", sceSifRebootIop);
