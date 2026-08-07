/* Fonctions libres — à décrire.
 *
 * Unité découpée par `make carve` : 8 fonctions, 2420 octets, de
 * 0x001117C0 à 0x00112138. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

INCLUDE_ASM("nonmatchings/sdk/printf", kputchar);
INCLUDE_ASM("nonmatchings/sdk/printf", deci2Putchar);
INCLUDE_ASM("nonmatchings/sdk/printf", serialPutchar);
INCLUDE_ASM("nonmatchings/sdk/printf", ftoi);
INCLUDE_ASM("nonmatchings/sdk/printf", printfloat);
INCLUDE_ASM("nonmatchings/sdk/printf", _printf);
INCLUDE_ASM("nonmatchings/sdk/printf", kprintf);
INCLUDE_ASM("nonmatchings/sdk/printf", scePrintf);
