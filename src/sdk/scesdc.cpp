/* Fonctions libres — à décrire.
 *
 * Unité découpée par `make carve` : 6 fonctions, 616 octets, de
 * 0x00110770 à 0x001109F0. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

INCLUDE_ASM("nonmatchings/sdk/scesdc", _sceSDC);
INCLUDE_ASM("nonmatchings/sdk/scesdc", SyncDCache);
INCLUDE_ASM("nonmatchings/sdk/scesdc", iSyncDCache);
INCLUDE_ASM("nonmatchings/sdk/scesdc", _sceIDC);
INCLUDE_ASM("nonmatchings/sdk/scesdc", InvalidDCache);
INCLUDE_ASM("nonmatchings/sdk/scesdc", iInvalidDCache);
