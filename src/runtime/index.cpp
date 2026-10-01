/* Fonctions libres — à décrire.
 *
 * Unité découpée par `make carve` : 1 fonctions, 28 octets, de
 * 0x00126020 à 0x00126040. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

char *strchr(const char *, int);
char *index(const char *s, int c) { return strchr(s, c); }

