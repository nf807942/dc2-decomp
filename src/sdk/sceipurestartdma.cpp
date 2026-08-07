/* Fonctions libres — à décrire.
 *
 * Unité découpée par `make carve` : 5 fonctions, 868 octets, de
 * 0x0010F4E0 à 0x0010F850. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

INCLUDE_ASM("nonmatchings/sdk/sceipurestartdma", setD3_CHCR);
INCLUDE_ASM("nonmatchings/sdk/sceipurestartdma", setD4_CHCR_0010F548);
INCLUDE_ASM("nonmatchings/sdk/sceipurestartdma", sceIpuStopDMA);
INCLUDE_ASM("nonmatchings/sdk/sceipurestartdma", sceIpuRestartDMA);
INCLUDE_ASM("nonmatchings/sdk/sceipurestartdma", sceIpuSync);
