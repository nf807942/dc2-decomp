/* Fonctions libres — à décrire.
 *
 * Unité découpée par `make carve` : 5 fonctions, 268 octets, de
 * 0x00118D40 à 0x00118E50. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

extern void InitTLB(void);
void TerminateLibrary(void) { InitTLB(); }
INCLUDE_ASM("nonmatchings/sdk/execps2", ExecPS2);
INCLUDE_ASM("nonmatchings/sdk/execps2", LoadExecPS2);
INCLUDE_ASM("nonmatchings/sdk/execps2", Exit);
INCLUDE_ASM("nonmatchings/sdk/execps2", ExecOSD);
