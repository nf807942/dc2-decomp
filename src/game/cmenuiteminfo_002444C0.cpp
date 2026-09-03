/* CMenuItemInfo
 *
 * Unité découpée par `make carve` : 9 fonctions, 7540 octets, de
 * 0x002444C0 à 0x00246280. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

INCLUDE_ASM("nonmatchings/game/cmenuiteminfo_002444C0", IsAskExtend__13CMenuItemInfoFii);
INCLUDE_ASM("nonmatchings/game/cmenuiteminfo_002444C0", MenuMoveItemPos__FPiPii);
INCLUDE_ASM("nonmatchings/game/cmenuiteminfo_002444C0", CommonSetMoveItemClass__FPA4_i);
INCLUDE_ASM("nonmatchings/game/cmenuiteminfo_002444C0", EnterDataMenu__13CMenuItemInfoFPUi);
INCLUDE_ASM("nonmatchings/game/cmenuiteminfo_002444C0", GetActiveCharaIDForItemCmd__13CMenuItemInfoFv);
extern "C" u32 MenuCommonInfo;
struct inferred;
typedef struct CMenuItemInfo {
    /* 0x000 */ char pad0[0x114];
    /* 0x114 */ s16 unk114;                         /* inferred */
} CMenuItemInfo;                                    /* size >= 0x116 */
extern "C" s32 GetActiveCharaNo__12CMenuKeyFuncFv(...);
extern "C" s32 GetActiveCharaNo__13CMenuItemInfoFv(CMenuItemInfo *objet) {
    s32 var_v0;

    var_v0 = GetActiveCharaNo__12CMenuKeyFuncFv(MenuCommonInfo);
    if ((var_v0 == 3) && (objet->unk114 == 1)) {
        objet->unk114 = 0;
        var_v0 = 3;
    }
    return var_v0;
}
INCLUDE_ASM("nonmatchings/game/cmenuiteminfo_002444C0", ExitEnd__13CMenuItemInfoFv);
INCLUDE_ASM("nonmatchings/game/cmenuiteminfo_002444C0", AttachFormInfo__13CMenuItemInfoFv);
INCLUDE_ASM("nonmatchings/game/cmenuiteminfo_002444C0", MenuModeMalloc__13CMenuItemInfoFP9mgCMemory);
