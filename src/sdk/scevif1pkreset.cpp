/* Fonctions libres — à décrire.
 *
 * Unité découpée par `make carve` : 1 fonctions, 16 octets, de
 * 0x00106968 à 0x00106978. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

typedef struct { unsigned *p; unsigned *base; unsigned n; unsigned *tag; } V1Pk;
void sceVif1PkReset(V1Pk *p)
{
    unsigned *b = p->base;
    p->n = 0;
    p->p = b;
}

