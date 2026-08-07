/* Fonctions libres — à décrire.
 *
 * Unité découpée par `make carve` : 2 fonctions, 56 octets, de
 * 0x001262E0 à 0x00126318. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

INCLUDE_ASM("nonmatchings/runtime/malloc", malloc);
INCLUDE_ASM("nonmatchings/runtime/malloc", free);
