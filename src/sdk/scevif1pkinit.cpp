/* Fonctions libres — à décrire.
 *
 * Unité découpée par `make carve` : 1 fonctions, 16 octets, de
 * 0x00106958 à 0x00106968. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

typedef struct { unsigned *p; unsigned *base; unsigned n; } K8I;
void sceVif1PkInit(K8I *p, unsigned *b)
{
    p->n = 0; p->base = b; p->p = b;
}
