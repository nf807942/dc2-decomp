/* Fonctions libres — à décrire.
 *
 * Unité découpée par `make carve` : 1 fonctions, 16 octets, de
 * 0x00106630 à 0x00106640. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

typedef struct { unsigned *p; unsigned *base; unsigned n; unsigned *tag; } Pk;
void sceGifPkInit(Pk *p, unsigned *b)
{
 p->n = 0; p->base = b; p->p = b;
}
