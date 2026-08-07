/* Fonctions libres — à décrire.
 *
 * Unité découpée par `make carve` : 2 fonctions, 1160 octets, de
 * 0x001256C0 à 0x00125B50. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

INCLUDE_ASM("nonmatchings/runtime/free_r", _free_r);
INCLUDE_ASM("nonmatchings/runtime/free_r", _malloc_trim_r);
