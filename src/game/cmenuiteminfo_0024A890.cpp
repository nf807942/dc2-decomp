/* CMenuItemInfo
 *
 * Unité découpée par `make carve` : 10 fonctions, 15412 octets, de
 * 0x0024A890 à 0x0024E500. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

INCLUDE_ASM("nonmatchings/game/cmenuiteminfo_0024A890", PushKey__13CMenuItemInfoFii);
struct inferred;
typedef struct CGameDataUsed_infere {
    /* 0x0 */ char pad0[2];
    /* 0x2 */ s16 unk2;                             /* inferred */
} CGameDataUsed_infere;                                    /* size >= 0x4 */
typedef struct MENUFORMPARTS_TYPE {
    /* 0x00 */ char pad0[5];
    /* 0x05 */ s8 unk5;                             /* inferred */
    /* 0x06 */ char pad6[0x2A];                     /* maybe part of unk5[0x2B]void */
    /* 0x30 */ s32 unk30;                           /* inferred */
    /* 0x34 */ s32 unk34;                           /* inferred */
} MENUFORMPARTS_TYPE;                               /* size >= 0x38 */
extern "C" void local_item_infoview_set__FP18MENUFORMPARTS_TYPEP13CGameDataUsed(MENUFORMPARTS_TYPE *arg0, CGameDataUsed_infere *arg1) {
    if (arg0 != NULL) {
        arg0->unk30 = 0;
        arg0->unk34 = (s32) arg1->unk2;
        arg0->unk5 = 1;
    }
}
INCLUDE_ASM("nonmatchings/game/cmenuiteminfo_0024A890", MenuItemCharaActWepInfoDraw__FP16CMenuPosDataFormP13CGameDataUsedii);
INCLUDE_ASM("nonmatchings/game/cmenuiteminfo_0024A890", MenuItemCharaViewCheck__FP10CHARA_DATAii);
INCLUDE_ASM("nonmatchings/game/cmenuiteminfo_0024A890", MenuPosFormValueSetCharaRobo__FP9ROBO_DATAi);
INCLUDE_ASM("nonmatchings/game/cmenuiteminfo_0024A890", MenuPosFormValueSetMonster__FP16MOS_CHANGE_PARAMP10CHARA_DATA);
#include "gamedataused.hpp"
extern "C" s32 IsBuildUp__13CGameDataUsedFPiPiPi(void *, s32 *, s32 *, s32 *);
extern "C" s32 CheckBuildUp__FP13CGameDataUsedPiPiPi(CGameDataUsed *arg0, s32 *arg1, s32 *arg2, s32 *arg3) {
    if (arg0 != NULL) {
        return IsBuildUp__13CGameDataUsedFPiPiPi(arg0, arg1, arg2, arg3);
    }
    return 0;
}
INCLUDE_ASM("nonmatchings/game/cmenuiteminfo_0024A890", BuildUpWeaponTrans__FP13CGameDataUsedi);
INCLUDE_ASM("nonmatchings/game/cmenuiteminfo_0024A890", BuildUpWeaponNameBoardDraw__FP11mgCDrawPrimffi);
INCLUDE_ASM("nonmatchings/game/cmenuiteminfo_0024A890", MenuWeaponBuildUpDraw__FRi);
