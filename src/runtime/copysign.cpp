/* copysign — sign of y, magnitude of x.
 *
 * Unité de la voie GCC (`config/gcc_units.txt`) : newlib 1.9.0, `s_copysign.c`,
 * compilé par ee-gcc 2.9-991111 en -O2 -G0. Le binaire porte la fonction telle que
 * la source de newlib la donne, sans modification (mesuré : 100 %). */

#include "common.h"
#include "ieee754.h"

double copysign(double x, double y)
{
    __uint32_t hx, hy;
    GET_HIGH_WORD(hx, x);
    GET_HIGH_WORD(hy, y);
    SET_HIGH_WORD(x, (hx & 0x7fffffff) | (hy & 0x80000000));
    return x;
}
