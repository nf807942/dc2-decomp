/* Fonctions libres — à décrire.
 *
 * Unité découpée par `make carve` : 4 fonctions, 224 octets, de
 * 0x00126040 à 0x00126130. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

INCLUDE_ASM("nonmatchings/runtime/setlocale_r", _setlocale_r);
extern int lconv;
int *_localeconv_r(void) { return &lconv; }
INCLUDE_ASM("nonmatchings/runtime/setlocale_r", setlocale);
INCLUDE_ASM("nonmatchings/runtime/setlocale_r", localeconv);
