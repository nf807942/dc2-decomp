/* Fonctions libres — à décrire.
 *
 * Unité découpée par `make carve` : 16 fonctions, 1828 octets, de
 * 0x00112138 à 0x00112880. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

typedef struct { int a[4]; int idx; int val; } K7SA;
typedef struct { int a[7]; int *tab; } K7SB;
void _set_sreg(K7SA *s, K7SB *d) { d->tab[s->idx] = s->val; }
typedef struct { int a[4]; int v; } K7CA;
typedef struct { int a[2]; int v; } K7CB;
void _change_addr(K7CA *s, K7CB *d) { d->v = s->v; }
extern int D_0037FE40[];
int sceSifGetSreg(int n) { return D_0037FE40[n]; }
extern int D_0037FE40[];
int sceSifSetSreg(int n, int v) { D_0037FE40[n] = v; return v; }
extern char D_0037FD18[];
void *sceSifGetDataTable(void) { return D_0037FD18; }
INCLUDE_ASM("nonmatchings/sdk/scesifinitcmd", sceSifInitCmd);
INCLUDE_ASM("nonmatchings/sdk/scesifinitcmd", sceSifExitCmd);
extern char D_0037FD18[];
void *sceSifSetCmdBuffer(void *b, int n) { char *s = D_0037FD18; void *o; __asm__("" : "+r"(s)); o = *(void **)(s + 0x14); *(void **)(s + 0x14) = b; *(int *)(s + 0x18) = n; return o; }
extern char D_0037FD18[];
void *sceSifSetSysCmdBuffer(void *b, int n)
{
    char *s = D_0037FD18;
    void *o = *(void **)(s + 0xC);
    *(void **)(s + 0xC) = b;
    *(int *)(s + 0x10) = n;
    return o;
}
INCLUDE_ASM("nonmatchings/sdk/scesifinitcmd", sceSifAddCmdHandler);
INCLUDE_ASM("nonmatchings/sdk/scesifinitcmd", sceSifRemoveCmdHandler);
INCLUDE_ASM("nonmatchings/sdk/scesifinitcmd", _sceSifSendCmd);
INCLUDE_ASM("nonmatchings/sdk/scesifinitcmd", sceSifSendCmd);
INCLUDE_ASM("nonmatchings/sdk/scesifinitcmd", isceSifSendCmd);
INCLUDE_ASM("nonmatchings/sdk/scesifinitcmd", _sceSifCmdIntrHdlr);
INCLUDE_ASM("nonmatchings/sdk/scesifinitcmd", sceSifWriteBackDCache);
