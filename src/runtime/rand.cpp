/* Fonctions libres — à décrire.
 *
 * Unité découpée par `make carve` : 2 fonctions, 64 octets, de
 * 0x001281D8 à 0x00128218. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

INCLUDE_ASM("nonmatchings/runtime/rand", srand);
INCLUDE_ASM("nonmatchings/runtime/rand", rand);
