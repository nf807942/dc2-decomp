/* Fonctions libres — à décrire.
 *
 * Unité découpée par `make carve` : 2 fonctions, 412 octets, de
 * 0x00102630 à 0x001027D0. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

INCLUDE_ASM("nonmatchings/sdk/scegsresetgraph", sceGsResetGraph);
extern char gp_6[];
void *sceGsGetGParam(void) { return gp_6; }
