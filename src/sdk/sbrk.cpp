/* Fonctions libres — à décrire.
 *
 * Unité découpée par `make carve` : 16 fonctions, 952 octets, de
 * 0x001103A0 à 0x00110770. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

extern int ttyinit;
void sceResetttyinit(void) { ttyinit = 0; }
INCLUDE_ASM("nonmatchings/sdk/sbrk", VSync);
INCLUDE_ASM("nonmatchings/sdk/sbrk", VSync2);
INCLUDE_ASM("nonmatchings/sdk/sbrk", write);
INCLUDE_ASM("nonmatchings/sdk/sbrk", read);
INCLUDE_ASM("nonmatchings/sdk/sbrk", open);
int close(int fd) { return -1; }
int ioctl(int fd, int cmd, int arg) { return -1; }
int lseek(int fd, int off, int whence) { return -1; }
INCLUDE_ASM("nonmatchings/sdk/sbrk", sbrk);
int isatty(int fd) { return 1; }
int fstat(int fd, char *st) {
  *(long long *)(st + 0x48) = 0;
  *(int *)(st + 4) = 0x2000;
  return 0;
}
int getpid(void) { return 1; }
INCLUDE_ASM("nonmatchings/sdk/sbrk", kill);
INCLUDE_ASM("nonmatchings/sdk/sbrk", stat);
INCLUDE_ASM("nonmatchings/sdk/sbrk", unlink);
