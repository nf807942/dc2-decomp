/* Fonctions libres — à décrire.
 *
 * Unité découpée par `make carve` : 2 fonctions, 96 octets, de
 * 0x00118A20 à 0x00118A80. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

INCLUDE_ASM("nonmatchings/sdk/dintr", DIntr);
int EIntr(void) {
  unsigned int s, r;
  __asm__ volatile("mfc0 %0, $12" : "=r"(s));
  r = s & 0x10000;
  __asm__ volatile("ei");
  return r != 0;
}

