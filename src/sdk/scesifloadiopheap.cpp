/* Fonctions libres — à décrire.
 *
 * Unité découpée par `make carve` : 6 fonctions, 764 octets, de
 * 0x00116E78 à 0x00117178. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

INCLUDE_ASM("nonmatchings/sdk/scesifloadiopheap", sceSifInitIopHeap);
INCLUDE_ASM("nonmatchings/sdk/scesifloadiopheap", sceSifAllocIopHeap);
INCLUDE_ASM("nonmatchings/sdk/scesifloadiopheap", sceSifAllocSysMemory);
INCLUDE_ASM("nonmatchings/sdk/scesifloadiopheap", sceSifFreeSysMemory);
extern int sceSifFreeSysMemory(void *);
int sceSifFreeIopHeap(void *a)
{
    return sceSifFreeSysMemory(a);
}
INCLUDE_ASM("nonmatchings/sdk/scesifloadiopheap", sceSifLoadIopHeap);
