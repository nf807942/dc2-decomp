/* CItemUseTarget
 *
 * Unité découpée par `make carve` : 9 fonctions, 1524 octets, de
 * 0x001975D0 à 0x00197BF0. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"
#include "gen/USEITEM_EFFECT.hpp"

INCLUDE_ASM("nonmatchings/game/citemusetarget", GetMenuCommandMsg__FiPi);
INCLUDE_ASM("nonmatchings/game/citemusetarget", CheckItemEquip__Fii);
extern "C" s32 GetCommonItemData__Fi(s32);
struct temp_v0_champs {
    char pad0[0x28];
    /* 0x28 */ s32 unk28;
};
extern "C" s32 strcmp(...);
extern "C" s32 SearchItemByName__FPc(s8 *arg0) {
    s32 temp_a0;
    s32 var_s0;
    struct temp_v0_champs *temp_v0;

    var_s0 = 1;
loop_1:
    temp_v0 = (struct temp_v0_champs *) (GetCommonItemData__Fi(var_s0));
    if (temp_v0 != NULL) {
        temp_a0 = (s32) (temp_v0->unk28);
        if ((temp_a0 != 0) && (strcmp(temp_a0, arg0) == 0)) {
            return var_s0;
        }
    }
    var_s0 += 1;
    if (var_s0 >= 0x200) {
        return -1;
    }
    goto loop_1;
}
INCLUDE_ASM("nonmatchings/game/citemusetarget", GetRidePodCore__Fi);
void Init_USEITEM_EFFECT(USEITEM_EFFECT * arg0) {
    arg0->field_0x8 = 0;
    arg0->field_0x0 = 0;
    arg0->field_0x4 = 0;
    arg0->field_0x18 = 0;
    arg0->field_0x14 = 0;
    arg0->field_0x10 = 0;
    arg0->field_0xC = 0;
}
INCLUDE_ASM("nonmatchings/game/citemusetarget", GetUsedItemAfterEffect__FiP14USEITEM_EFFECT);
struct inferred;
typedef struct CItemUseTarget {
    /* 0x0 */ s32 unk0;                             /* inferred */
    /* 0x4 */ void *unk4;                           /* inferred */
} CItemUseTarget;                                   /* size >= 0x8 */
extern "C" void SetPtr__14CItemUseTargetFiPv(CItemUseTarget *objet, s32 arg0, void *arg1) {
    objet->unk0 = arg0;
    if (objet->unk0 == 0) {
        objet->unk4 = arg1;
    }
    if (objet->unk0 == 1) {
        objet->unk4 = arg1;
    }
    if (objet->unk0 == 2) {
        objet->unk4 = arg1;
    }
    if (objet->unk0 == 3) {
        objet->unk4 = arg1;
    }
}
extern "C" void GetSystemMessage__Fi(s32);
extern "C" void GetSystemMessage__Fv(void) {
    GetSystemMessage__Fi(0);
}
INCLUDE_ASM("nonmatchings/game/citemusetarget", GetSystemMessage__Fi);
