/* Fonctions libres — à décrire.
 *
 * Unité découpée par `make carve` : 1 fonctions, 24 octets, de
 * 0x00106848 à 0x00106860. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

typedef int u128 __attribute__((mode(TI)));
typedef struct { u128 *p; unsigned *base; unsigned n; u128 *tag; } Pk;
void sceGifPkOpenGifTag(Pk *p, u128 t)
{
    p->tag = p->p;
    *p->p++ = t;
}

