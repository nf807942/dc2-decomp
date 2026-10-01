/* Fonctions libres — à décrire.
 *
 * Unité découpée par `make carve` : 2 fonctions, 64 octets, de
 * 0x001281D8 à 0x00128218. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

/* Le _reent du jeu range la graine en 0x58, sur 32 bits ; le _reent de newlib 1.9.0 la met en 0xA8 sur 64 bits. */
extern char *_impure_ptr;
void srand(unsigned int seed) { *(unsigned int *)(_impure_ptr + 0x58) = seed; }
INCLUDE_ASM("nonmatchings/runtime/rand", rand);
