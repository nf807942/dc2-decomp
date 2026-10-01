/* Fonctions libres — à décrire.
 *
 * Unité découpée par `make carve` : 1 fonctions, 20 octets, de
 * 0x00106C38 à 0x00106C50. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

typedef struct { unsigned *p; unsigned *base; unsigned n; unsigned *tag; } Pk;
unsigned *sceVif1PkReserve(Pk *p, int n){ unsigned *q = p->p; p->p = q + n; return q; }

