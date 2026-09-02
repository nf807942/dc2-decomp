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
INCLUDE_ASM("nonmatchings/game/citemusetarget", SearchItemByName__FPc);
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
INCLUDE_ASM("nonmatchings/game/citemusetarget", SetPtr__14CItemUseTargetFiPv);
INCLUDE_ASM("nonmatchings/game/citemusetarget", GetSystemMessage__Fv);
INCLUDE_ASM("nonmatchings/game/citemusetarget", GetSystemMessage__Fi);
