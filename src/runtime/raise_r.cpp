/* Fonctions libres — à décrire.
 *
 * Unité découpée par `make carve` : 8 fonctions, 836 octets, de
 * 0x001282D8 à 0x00128628. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

INCLUDE_ASM("nonmatchings/runtime/raise_r", _init_signal_r);
INCLUDE_ASM("nonmatchings/runtime/raise_r", _signal_r);
INCLUDE_ASM("nonmatchings/runtime/raise_r", _raise_r);
INCLUDE_ASM("nonmatchings/runtime/raise_r", __sigtramp_r);
INCLUDE_ASM("nonmatchings/runtime/raise_r", raise);
INCLUDE_ASM("nonmatchings/runtime/raise_r", signal);
INCLUDE_ASM("nonmatchings/runtime/raise_r", _init_signal);
INCLUDE_ASM("nonmatchings/runtime/raise_r", __sigtramp);
