/* Fonctions libres — à décrire.
 *
 * Unité découpée par `make carve` : 1 fonctions, 48 octets, de
 * 0x0011E3A0 à 0x0011E3D0. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

#include "ieee754.h"

float copysignf(float x, float y)
{
    __uint32_t ix, iy;
    GET_FLOAT_WORD(ix, x);
    GET_FLOAT_WORD(iy, y);
    SET_FLOAT_WORD(x, (ix & 0x7fffffff) | (iy & 0x80000000));
    return x;
}

