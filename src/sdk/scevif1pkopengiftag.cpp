/* Fonctions libres — à décrire.
 *
 * Unité découpée par `make carve` : 1 fonctions, 24 octets, de
 * 0x00106B78 à 0x00106B90. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

typedef int k8u128 __attribute__((mode(TI)));
typedef struct { k8u128 *p; unsigned *base; unsigned n; unsigned k8x; unsigned k8y; k8u128 *tag; } K8O;
void sceVif1PkOpenGifTag(K8O *p, k8u128 t)
{
    p->tag = p->p;
    *p->p++ = t;
}

