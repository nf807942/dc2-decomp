/* Fonctions libres — à décrire.
 *
 * Unité découpée par `make carve` : 2 fonctions, 120 octets, de
 * 0x00128628 à 0x001286A8. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

INCLUDE_ASM("nonmatchings/runtime/kill_r", _kill_r);
INCLUDE_ASM("nonmatchings/runtime/kill_r", _getpid_r);
