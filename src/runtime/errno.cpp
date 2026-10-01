/* Fonctions libres — à décrire.
 *
 * Unité découpée par `make carve` : 1 fonctions, 12 octets, de
 * 0x00125268 à 0x00125278. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

extern int *_impure_ptr;
int *__errno(void) { return _impure_ptr; }

