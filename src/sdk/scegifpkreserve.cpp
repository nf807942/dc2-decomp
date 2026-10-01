/* Fonctions libres — à décrire.
 *
 * Unité découpée par `make carve` : 1 fonctions, 20 octets, de
 * 0x00106830 à 0x00106848. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

typedef struct { unsigned *p; unsigned *base; unsigned n; unsigned *tag; } Pk;
unsigned *sceGifPkReserve(Pk *p, int n){ unsigned *q = p->p; p->p = q + n; return q; }

