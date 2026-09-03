/* CRunScript
 *
 * Unité découpée par `make carve` : 3 fonctions, 5304 octets, de
 * 0x00188970 à 0x00189E30. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

INCLUDE_ASM("nonmatchings/game/crunscript", exe__10CRunScriptFP8vmcode_t);
INCLUDE_ASM("nonmatchings/game/crunscript", rsGetStackInt__FP12RS_STACKDATA);
struct inferred;
typedef struct RS_STACKDATA {
    /* 0x0 */ s32 unk0;                             /* inferred */
    /* 0x4 */ struct unk4_champs *unk4;                           /* inferred */
} RS_STACKDATA;                                     /* size >= 0x8 */
struct unk4_champs {
    char pad0[0x4];
    /* 0x4 */ s32 unk4;
};
extern "C" void rsSetStack__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    if (arg0->unk0 == 3) {
        arg0->unk4->unk4 = arg1;
    }
}
