/* Fonctions libres — à décrire.
 *
 * Unité découpée par `make carve` : 7 fonctions, 504 octets, de
 * 0x0010CE70 à 0x0010D080. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

INCLUDE_ASM("nonmatchings/sdk/sysbitflush", _sysbitInit);
int _sysbitNext(unsigned long long *p, int n)
{
    return (int)(*p >> (64 - n));
}
INCLUDE_ASM("nonmatchings/sdk/sysbitflush", _sysbitFlush);
INCLUDE_ASM("nonmatchings/sdk/sysbitflush", _sysbitGet);
INCLUDE_ASM("nonmatchings/sdk/sysbitflush", _sysbitMarker);
INCLUDE_ASM("nonmatchings/sdk/sysbitflush", _sysbitJump);
INCLUDE_ASM("nonmatchings/sdk/sysbitflush", _sysbitPtr);
