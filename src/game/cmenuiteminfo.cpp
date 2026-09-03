/* CMenuItemInfo
 *
 * Unité découpée par `make carve` : 14 fonctions, 8928 octets, de
 * 0x002421A0 à 0x002444C0. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

typedef struct MenuUserDataManPtr_pointe {
    char pad0[282008];
    s32 unk44D98;
} MenuUserDataManPtr_pointe;
extern "C" MenuUserDataManPtr_pointe *MenuUserDataManPtr;
struct inferred;
typedef struct CMenuItemInfo_infere2 {
    /* 0x000 */ s16 unk0;                           /* inferred */
    /* 0x002 */ s16 unk2;                           /* inferred */
    /* 0x004 */ s8 unk4;                            /* inferred */
    /* 0x005 */ char pad5[0xF3];                    /* maybe part of unk4[0xF4]void */
    /* 0x0F8 */ s32 unkF8;                          /* inferred */
    /* 0x0FC */ char padFC[0x14];                   /* maybe part of unkF8[6]void */
    /* 0x110 */ s16 unk110;                         /* inferred */
    /* 0x112 */ s16 unk112;                         /* inferred */
    /* 0x114 */ s16 unk114;                         /* inferred */
    /* 0x116 */ s16 unk116;                         /* inferred */
    /* 0x118 */ s16 unk118;                         /* inferred */
    /* 0x11A */ s16 unk11A;                         /* inferred */
    /* 0x11C */ char pad11C[4];                     /* maybe part of unk11A[3]void */
    /* 0x120 */ s16 unk120;                         /* inferred */
    /* 0x122 */ s16 unk122;                         /* inferred */
    /* 0x124 */ s16 unk124;                         /* inferred */
    /* 0x126 */ s16 unk126;                         /* inferred */
    /* 0x128 */ s16 unk128;                         /* inferred */
    /* 0x12A */ s16 unk12A;                         /* inferred */
    /* 0x12C */ s16 unk12C;                         /* inferred */
    /* 0x12E */ s16 unk12E;                         /* inferred */
    /* 0x130 */ s8 unk130;                          /* inferred */
    /* 0x131 */ s8 unk131;                          /* inferred */
    /* 0x132 */ s8 unk132;                          /* inferred */
    /* 0x133 */ s8 unk133;                          /* inferred */
    /* 0x134 */ s8 unk134;                          /* inferred */
    /* 0x135 */ s8 unk135;                          /* inferred */
    /* 0x136 */ s8 unk136;                          /* inferred */
    /* 0x137 */ s8 unk137;                          /* inferred */
    /* 0x138 */ s16 unk138;                         /* inferred */
    /* 0x13A */ s8 unk13A;                          /* inferred */
    /* 0x13B */ char pad13B[0x25];                  /* maybe part of unk13A[0x26]void */
    /* 0x160 */ s8 unk160;                          /* inferred */
    /* 0x161 */ char pad161[0xB];                   /* maybe part of unk160[0xC]void */
    /* 0x16C */ s8 unk16C;                          /* inferred */
    /* 0x16D */ s8 unk16D;                          /* inferred */
    /* 0x16E */ s8 unk16E;                          /* inferred */
    /* 0x16F */ s8 unk16F;                          /* inferred */
    /* 0x170 */ s8 unk170;                          /* inferred */
    /* 0x171 */ char pad171[1];
    /* 0x172 */ s16 unk172;                         /* inferred */
    /* 0x174 */ s16 unk174;                         /* inferred */
    /* 0x176 */ s16 unk176;                         /* inferred */
    /* 0x178 */ s16 unk178;                         /* inferred */
    /* 0x17A */ char pad17A[2];
    /* 0x17C */ s32 unk17C;                         /* inferred */
    /* 0x180 */ char pad180[0x174];                 /* maybe part of unk17C[0x5E]void */
    /* 0x2F4 */ s32 unk2F4;                         /* inferred */
    /* 0x2F8 */ s32 unk2F8;                         /* inferred */
} CMenuItemInfo_infere2;                                    /* size >= 0x2FC */
extern "C" s32 SetEquipListNo__13CMenuItemInfoFi(void *, s32);
extern "C" void Initialize__13CMenuItemInfoFv(CMenuItemInfo_infere2 *objet) {
    objet->unk110 = 0;
    objet->unk112 = 0;
    objet->unk114 = 0;
    objet->unk116 = 0;
    objet->unk118 = 0;
    objet->unk118 = 2;
    objet->unk11A = MenuUserDataManPtr->unk44D98;
    objet->unk17C = 0;
    objet->unkF8 = 0;
    SetEquipListNo__13CMenuItemInfoFi(objet, 4);
    objet->unk138 = 0;
    objet->unk16C = 0;
    objet->unk16D = 0;
    objet->unk176 = -1;
    objet->unk178 = -1;
    objet->unk2F4 = 0;
    objet->unk2F8 = 0;
    objet->unk13A = 0;
    objet->unk16F = 0;
    objet->unk4 = 0;
    objet->unk0 = 1;
    objet->unk2 = 0;
    objet->unk170 = 0;
    objet->unk172 = -1;
    objet->unk174 = 0;
    objet->unk16E = 0;
    objet->unk130 = 0;
    objet->unk120 = 0;
    objet->unk131 = 0;
    objet->unk122 = 0;
    objet->unk132 = 0;
    objet->unk124 = 0;
    objet->unk133 = 0;
    objet->unk126 = 0;
    objet->unk134 = 0;
    objet->unk128 = 0;
    objet->unk135 = 0;
    objet->unk12A = 0;
    objet->unk136 = 0;
    objet->unk12C = 0;
    objet->unk137 = 0;
    objet->unk12E = 0;
    objet->unk160 = 0;
}
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
