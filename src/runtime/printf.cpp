/* Fonctions libres — à décrire.
 *
 * Unité découpée par `make carve` : 2 fonctions, 140 octets, de
 * 0x00128148 à 0x001281D8. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

INCLUDE_ASM("nonmatchings/runtime/printf", _printf_r);
INCLUDE_ASM("nonmatchings/runtime/printf", printf);
