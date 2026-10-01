/* Fonctions libres — à décrire.
 *
 * Unité découpée par `make carve` : 1 fonctions, 20 octets, de
 * 0x00123D08 à 0x00123D20. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

int abs(int i) { return (i < 0) ? -i : i; }

