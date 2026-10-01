/* Fonctions libres — à décrire.
 *
 * Unité découpée par `make carve` : 1 fonctions, 28 octets, de
 * 0x0011E4B8 à 0x0011E4D8. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

#include "ieee754.h"
float fabsf(float x)
{
	__uint32_t ix;
	GET_FLOAT_WORD(ix,x);
	SET_FLOAT_WORD(x,ix&0x7fffffff);
	return x;
}

