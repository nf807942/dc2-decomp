/* Fonctions libres — à décrire.
 *
 * Unité découpée par `make carve` : 4 fonctions, 364 octets, de
 * 0x00128780 à 0x001288F0. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

INCLUDE_ASM("nonmatchings/runtime/swrite", __sread);
INCLUDE_ASM("nonmatchings/runtime/swrite", __swrite);
INCLUDE_ASM("nonmatchings/runtime/swrite", __sseek);
INCLUDE_ASM("nonmatchings/runtime/swrite", __sclose);
