/* CMenuItemInfo
 *
 * Unité découpée par `make carve` : 14 fonctions, 8928 octets, de
 * 0x002421A0 à 0x002444C0. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

INCLUDE_ASM("nonmatchings/game/cmenuiteminfo", Initialize__13CMenuItemInfoFv);
INCLUDE_ASM("nonmatchings/game/cmenuiteminfo", SetEquipListNo__13CMenuItemInfoFi);
INCLUDE_ASM("nonmatchings/game/cmenuiteminfo", CheckEquipListNo__13CMenuItemInfoFi);
INCLUDE_ASM("nonmatchings/game/cmenuiteminfo", CheckSoundLoad__13CMenuItemInfoFv);
INCLUDE_ASM("nonmatchings/game/cmenuiteminfo", SearchNowPosItemExist__13CMenuItemInfoFv);
INCLUDE_ASM("nonmatchings/game/cmenuiteminfo", IsCancelNoneLoadItem__13CMenuItemInfoFv);
INCLUDE_ASM("nonmatchings/game/cmenuiteminfo", IsCancelLoadItem__13CMenuItemInfoFv);
extern "C" u32 MenuCommonInfo;
extern "C" u32 NewViewWep;
extern "C" u32 OldViewWep;
extern "C" u8 view_weapon_flag;
struct inferred;
typedef struct CMenuItemInfo {
    /* 0x000 */ char pad0[0x14];
    /* 0x014 */ s16 unk14;                          /* inferred */
    /* 0x016 */ char pad16[0xFA];                   /* maybe part of unk14[0x7E]void */
    /* 0x110 */ s16 unk110;                         /* inferred */
    /* 0x112 */ char pad112[0x6A];                  /* maybe part of unk110[0x36]void */
    /* 0x17C */ s32 unk17C;                         /* inferred */
} CMenuItemInfo;                                    /* size >= 0x180 */
extern "C" s32 SearchNowPosItemExist__13CMenuItemInfoFv(void *);
extern "C" void SaveViewWeaponStatus__13CMenuItemInfoFv(CMenuItemInfo *objet) {
    s16 temp_a0;
    s32 temp_a0_2;
    s32 temp_v0;

    view_weapon_flag = 0;
    temp_a0 = objet->unk110;
    if ((temp_a0 == 2) || (temp_a0 == 5)) {
        temp_v0 = SearchNowPosItemExist__13CMenuItemInfoFv(objet);
        if (temp_v0 == objet->unk17C) {
            OldViewWep = temp_v0;
            NewViewWep = MenuCommonInfo + 0xC0;
            if (objet->unk14 == 4) {
                NewViewWep = objet->unk17C;
            }
            view_weapon_flag = 1;
        }
        temp_a0_2 = MenuCommonInfo + 0xC0;
        if (temp_a0_2 == objet->unk17C) {
            OldViewWep = temp_a0_2;
            view_weapon_flag = 1;
            NewViewWep = temp_v0;
        }
    }
}
struct MENU_SWAPITEM_INFO {
    s16 field_0;
    s16 field_2;
    s16 field_4;
    s16 field_6;
};
typedef struct CMenuItemInfo_infere {
    /* 0x000 */ char pad0[0x17C];
    /* 0x17C */ s32 unk17C;                         /* inferred */
} CMenuItemInfo_infere;                                    /* size >= 0x180 */
extern "C" s32 GetGameDataUsedForSWAPINFO__FP18MENU_SWAPITEM_INFO(...);
extern "C" void CheckViewWeaponStatus__13CMenuItemInfoFi(CMenuItemInfo_infere *objet, s32 arg0) {
    if (view_weapon_flag != 0) {
        if (arg0 == 0) {
            objet->unk17C = NewViewWep;
            return;
        }
        if ((MenuCommonInfo + 0xC0) == objet->unk17C) {
            objet->unk17C = GetGameDataUsedForSWAPINFO__FP18MENU_SWAPITEM_INFO(MenuCommonInfo + 0x12C);
        }
    }
}
INCLUDE_ASM("nonmatchings/game/cmenuiteminfo", ReturnActiveCharaViewMode__13CMenuItemInfoFi);
INCLUDE_ASM("nonmatchings/game/cmenuiteminfo", NextModeBuildUpInfo__13CMenuItemInfoFP13CGameDataUsed);
INCLUDE_ASM("nonmatchings/game/cmenuiteminfo", EquipDirect__13CMenuItemInfoFiP13CGameDataUsedRi);
INCLUDE_ASM("nonmatchings/game/cmenuiteminfo", CheckLoadInfo__13CMenuItemInfoFi);
INCLUDE_ASM("nonmatchings/game/cmenuiteminfo", ItemCmdAfter__13CMenuItemInfoFiP16ITEMCMD_RET_PARA);
