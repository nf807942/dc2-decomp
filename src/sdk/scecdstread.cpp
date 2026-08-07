/* Fonctions libres — à décrire.
 *
 * Unité découpée par `make carve` : 10 fonctions, 1228 octets, de
 * 0x00120970 à 0x00120E50. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

INCLUDE_ASM("nonmatchings/sdk/scecdstread", sceCdStInit);
INCLUDE_ASM("nonmatchings/sdk/scecdstread", sceCdStStart);
INCLUDE_ASM("nonmatchings/sdk/scecdstread", sceCdStSeekF);
INCLUDE_ASM("nonmatchings/sdk/scecdstread", sceCdStSeek);
INCLUDE_ASM("nonmatchings/sdk/scecdstread", sceCdStStop);
INCLUDE_ASM("nonmatchings/sdk/scecdstread", sceCdStRead);
INCLUDE_ASM("nonmatchings/sdk/scecdstread", sceCdStPause);
INCLUDE_ASM("nonmatchings/sdk/scecdstread", sceCdStResume);
INCLUDE_ASM("nonmatchings/sdk/scecdstread", sceCdStStat);
INCLUDE_ASM("nonmatchings/sdk/scecdstread", sceCdStream);
