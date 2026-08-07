/* Fonctions libres — à décrire.
 *
 * Unité découpée par `make carve` : 16 fonctions, 952 octets, de
 * 0x001103A0 à 0x00110770. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

INCLUDE_ASM("nonmatchings/sdk/sbrk", sceResetttyinit);
INCLUDE_ASM("nonmatchings/sdk/sbrk", VSync);
INCLUDE_ASM("nonmatchings/sdk/sbrk", VSync2);
INCLUDE_ASM("nonmatchings/sdk/sbrk", write);
INCLUDE_ASM("nonmatchings/sdk/sbrk", read);
INCLUDE_ASM("nonmatchings/sdk/sbrk", open);
INCLUDE_ASM("nonmatchings/sdk/sbrk", close);
INCLUDE_ASM("nonmatchings/sdk/sbrk", ioctl);
INCLUDE_ASM("nonmatchings/sdk/sbrk", lseek);
INCLUDE_ASM("nonmatchings/sdk/sbrk", sbrk);
INCLUDE_ASM("nonmatchings/sdk/sbrk", isatty);
INCLUDE_ASM("nonmatchings/sdk/sbrk", fstat);
INCLUDE_ASM("nonmatchings/sdk/sbrk", getpid);
INCLUDE_ASM("nonmatchings/sdk/sbrk", kill);
INCLUDE_ASM("nonmatchings/sdk/sbrk", stat);
INCLUDE_ASM("nonmatchings/sdk/sbrk", unlink);
