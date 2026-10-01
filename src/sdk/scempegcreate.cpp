/* Fonctions libres — à décrire.
 *
 * Unité découpée par `make carve` : 35 fonctions, 2808 octets, de
 * 0x0010DE88 à 0x0010E9D8. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

INCLUDE_ASM("nonmatchings/sdk/scempegcreate", sceMpegInit);
INCLUDE_ASM("nonmatchings/sdk/scempegcreate", sceMpegCreate);
int sceMpegDelete(void *m) { return 1; }
INCLUDE_ASM("nonmatchings/sdk/scempegcreate", sceMpegAddBs);
INCLUDE_ASM("nonmatchings/sdk/scempegcreate", sceMpegGetPicture);
INCLUDE_ASM("nonmatchings/sdk/scempegcreate", sceMpegGetPictureRAW8);
INCLUDE_ASM("nonmatchings/sdk/scempegcreate", sceMpegGetPictureRAW8xy);
typedef struct { char p[0x94]; int a; int b; int c; } D1;
void sceMpegSetDecodeMode(int *m, int a, int b, int c) { D1 *s = (D1 *)m[0x10]; s->a = a; s->b = b; s->c = c; }
INCLUDE_ASM("nonmatchings/sdk/scempegcreate", sceMpegGetDecodeMode);
typedef struct { char p[0x40]; char *w; } M;
#define W(t,o) (*(t *)(m->w + o))
int sceMpegIsEnd(M *m) { return W(int,0); }
#define W(t,o) (*(t *)(m[0x10] + o))
int sceMpegIsRefBuffEmpty(int *m) { return W(int,4) == 0; }
INCLUDE_ASM("nonmatchings/sdk/scempegcreate", sceMpegReset);
INCLUDE_ASM("nonmatchings/sdk/scempegcreate", sceMpegClearRefBuff);
INCLUDE_ASM("nonmatchings/sdk/scempegcreate", sceMpegAddCallback);
INCLUDE_ASM("nonmatchings/sdk/scempegcreate", _dispatchMpegCallback);
INCLUDE_ASM("nonmatchings/sdk/scempegcreate", _dispatchMpegCbNodata);
typedef struct { char p[0x70]; int a; int pad; long g; } S2;
void sceMpegSetDefaultPtsGap(int *m, long g) { S2 *s = (S2 *)m[0x10]; s->a = 1; s->g = g; }
typedef struct { char p[0x70]; int a; int pad; long g; } S;
void sceMpegResetDefaultPtsGap(int *m) { S *s = (S *)m[0x10]; s->a = 0; s->g = 0; }
#define W(t,o) (*(t *)(m[0x10] + o))
void sceMpegSetImageBuff(int *m, int b) { W(int,0xd8) = b; }
int sceMpegDispWidth(int *m) { return *(int *)(m[0x40/4] + 0xCC); }
int sceMpegDispHeight(int *m) { return *(int *)(m[0x40/4] + 0xD0); }
int sceMpegDispCenterOffX(int *m) { return m[0x40/4] + 0xB4; }
int sceMpegDispCenterOffY(int *m) { return m[0x40/4] + 0xB4; }
#define W(t,o) (*(t *)(m[0x10] + o))
int sceSetBrokenLink(int *m, int v) { int o = W(int,0xe8); W(int,0xe8) = v; return o; }
#define W(t,o) (*(t *)(m[0x10] + o))
void sceSetPtm(int *m, long p) { W(long,0xf0) = p; W(int,0xf8) = 1; }
void _alalcInit(int *p, int a, int b) { p[0]=a;p[1]=b;p[2]=a;p[3]=a; }
void _alalcSetDynamic(int *p) { p[3] = p[2]; }
void _alalcFree(int *p) { p[2] = p[3]; }
INCLUDE_ASM("nonmatchings/sdk/scempegcreate", _alalcAlloc);
int _alalcRest(int *p) { return p[0] + p[1] - p[2]; }
INCLUDE_ASM("nonmatchings/sdk/scempegcreate", _getpic);
INCLUDE_ASM("nonmatchings/sdk/scempegcreate", _decodeOrSkipFrame);
INCLUDE_ASM("nonmatchings/sdk/scempegcreate", _decodeOrSkip);
INCLUDE_ASM("nonmatchings/sdk/scempegcreate", _decodeOrSkipField);
INCLUDE_ASM("nonmatchings/sdk/scempegcreate", _sceMpegFlush);
