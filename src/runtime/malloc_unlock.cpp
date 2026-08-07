/* Fonctions libres — à décrire.
 *
 * Unité découpée par `make carve` : 2 fonctions, 16 octets, de
 * 0x00127118 à 0x00127128. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

INCLUDE_ASM("nonmatchings/runtime/malloc_unlock", __malloc_lock);
INCLUDE_ASM("nonmatchings/runtime/malloc_unlock", __malloc_unlock);
