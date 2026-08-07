/* Fonctions libres — à décrire.
 *
 * Unité découpée par `make carve` : 7 fonctions, 304 octets, de
 * 0x00118A80 à 0x00118BC0. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

INCLUDE_ASM("nonmatchings/sdk/supplement_crt0", supplement_crt0);
INCLUDE_ASM("nonmatchings/sdk/supplement_crt0", kFindAddress);
INCLUDE_ASM("nonmatchings/sdk/supplement_crt0", FindAddress);
INCLUDE_ASM("nonmatchings/sdk/supplement_crt0", GetSystemCallTableEntry);
INCLUDE_ASM("nonmatchings/sdk/supplement_crt0", setup_00118B50);
INCLUDE_ASM("nonmatchings/sdk/supplement_crt0", _setup);
INCLUDE_ASM("nonmatchings/sdk/supplement_crt0", _InitSys);
