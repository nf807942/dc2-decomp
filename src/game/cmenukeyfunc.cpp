/* CMenuKeyFunc
 *
 * Unité découpée par `make carve` : 48 fonctions, 17548 octets, de
 * 0x0023DC00 à 0x002421A0. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

INCLUDE_ASM("nonmatchings/game/cmenukeyfunc", MenuItemBrdKey__FiPiPii);
INCLUDE_ASM("nonmatchings/game/cmenukeyfunc", MenuDataSwap__FP13CGameDataUsedP13CGameDataUsedi);
INCLUDE_ASM("nonmatchings/game/cmenukeyfunc", Initialize__12CMenuKeyFuncFv);
INCLUDE_ASM("nonmatchings/game/cmenukeyfunc", AttachFuncData__12CMenuKeyFuncFv);
INCLUDE_ASM("nonmatchings/game/cmenukeyfunc", GetActiveCharaNo__12CMenuKeyFuncFv);
INCLUDE_ASM("nonmatchings/game/cmenukeyfunc", MenuPosStep__12CMenuKeyFuncFPiPi);
INCLUDE_ASM("nonmatchings/game/cmenukeyfunc", MenuSetPos__12CMenuKeyFuncFii);
INCLUDE_ASM("nonmatchings/game/cmenukeyfunc", MenuPosStop__12CMenuKeyFuncFv);
INCLUDE_ASM("nonmatchings/game/cmenukeyfunc", MenuPosPlay__12CMenuKeyFuncFv);
INCLUDE_ASM("nonmatchings/game/cmenukeyfunc", SetMoveMethod__12CMenuKeyFuncFi);
INCLUDE_ASM("nonmatchings/game/cmenukeyfunc", SetWakuMoveMethod__12CMenuKeyFuncFi);
INCLUDE_ASM("nonmatchings/game/cmenukeyfunc", GetItemPos__12CMenuKeyFuncFPi);
INCLUDE_ASM("nonmatchings/game/cmenukeyfunc", SetWakuType__12CMenuKeyFuncFi);
INCLUDE_ASM("nonmatchings/game/cmenukeyfunc", SetWakuWH__12CMenuKeyFuncFiii);
INCLUDE_ASM("nonmatchings/game/cmenukeyfunc", SetVibeCnt__12CMenuKeyFuncFii);
INCLUDE_ASM("nonmatchings/game/cmenukeyfunc", SetVibeR__12CMenuKeyFuncFii);
INCLUDE_ASM("nonmatchings/game/cmenukeyfunc", GetCursorPos__12CMenuKeyFuncFPi);
INCLUDE_ASM("nonmatchings/game/cmenukeyfunc", CursorFadeIn__12CMenuKeyFuncFfi);
INCLUDE_ASM("nonmatchings/game/cmenukeyfunc", CursorFadeOut__12CMenuKeyFuncFfi);
INCLUDE_ASM("nonmatchings/game/cmenukeyfunc", EnableSwapNowPos__12CMenuKeyFuncFP18MENU_SWAPITEM_INFO);
INCLUDE_ASM("nonmatchings/game/cmenukeyfunc", GetItemAll__12CMenuKeyFuncFP13CGameDataUsedP18MENU_SWAPITEM_INFO);
INCLUDE_ASM("nonmatchings/game/cmenukeyfunc", GetItemCommandMsg__FP13CGameDataUsedP17MENU_ASKMODE_PARAii);
INCLUDE_ASM("nonmatchings/game/cmenukeyfunc", GetItemCommandMsg__FP13CGameDataUsedPiPUiPsPsii);
struct inferred;
typedef struct CMenuKeyFunc_infere3 {
    /* 0x00 */ char pad0[2];
    /* 0x02 */ s8 unk2;                             /* inferred */
    /* 0x03 */ char pad3[1];
    /* 0x04 */ s32 unk4;                            /* inferred */
    /* 0x08 */ s32 unk8;                            /* inferred */
    /* 0x0C */ char padC[0x64];                     /* maybe part of unk8[0x1A]void */
    /* 0x70 */ s32 unk70;                           /* inferred */
    /* 0x74 */ s32 unk74;                           /* inferred */
    /* 0x78 */ s32 unk78;                           /* inferred */
    /* 0x7C */ s32 unk7C;                           /* inferred */
} CMenuKeyFunc_infere3;                                     /* size >= 0x80 */
extern "C" void SelDataInit__12CMenuKeyFuncFv(CMenuKeyFunc_infere3 *objet) {
    objet->unk4 = 0;
    objet->unk8 = 0;
    objet->unk78 = objet->unk70;
    objet->unk7C = objet->unk74;
    objet->unk2 = 0;
}
INCLUDE_ASM("nonmatchings/game/cmenukeyfunc", CheckSelectKey__12CMenuKeyFuncFv);
INCLUDE_ASM("nonmatchings/game/cmenukeyfunc", CheckLRKey__12CMenuKeyFuncFv);
INCLUDE_ASM("nonmatchings/game/cmenukeyfunc", MenuCheckPushButton__Fv);
INCLUDE_ASM("nonmatchings/game/cmenukeyfunc", ConvertCheckPushButton__Fi);
struct inferred;
typedef struct CMenuKeyFunc_infere {
    /* 0x0 */ char pad0[1];
    /* 0x1 */ u8 unk1;                              /* inferred */
    /* 0x2 */ char pad2[6];                         /* maybe part of unk1[7]void */
    /* 0x8 */ s32 unk8;                             /* inferred */
} CMenuKeyFunc_infere;                                     /* size >= 0xC */
extern "C" s32 MenuCheckPushButton__Fv(void);
extern "C" s32 CheckPushButton__12CMenuKeyFuncFv(CMenuKeyFunc_infere *objet) {
    objet->unk8 = MenuCheckPushButton__Fv();
    if (objet->unk1 == 0) {
        objet->unk8 = 0;
    }
    return objet->unk8;
}
INCLUDE_ASM("nonmatchings/game/cmenukeyfunc", CheckAnalogKey__12CMenuKeyFuncFiPf);
typedef struct CMenuKeyFunc_infere2 {
    /* 0x0 */ char pad0[1];
    /* 0x1 */ u8 unk1;                              /* inferred */
    /* 0x2 */ u8 unk2;                              /* inferred */
    /* 0x3 */ char pad3[1];
    /* 0x4 */ s32 unk4;                             /* inferred */
    /* 0x8 */ s32 unk8;                             /* inferred */
} CMenuKeyFunc_infere2;                                     /* size >= 0xC */
extern "C" u8 CheckKeyInput__12CMenuKeyFuncFv(CMenuKeyFunc_infere2 *objet) {
    if (objet->unk1 == 0) {
        objet->unk4 = 0;
        objet->unk8 = 0;
    }
    if (objet->unk4 != 0) {
        objet->unk2 = 1;
    }
    return objet->unk2;
}
INCLUDE_ASM("nonmatchings/game/cmenukeyfunc", GetDebugInputKey__12CMenuKeyFuncFRiRi);
INCLUDE_ASM("nonmatchings/game/cmenukeyfunc", MenuSwapItem__12CMenuKeyFuncFP13CGameDataUsedP18MENU_SWAPITEM_INFOib);
INCLUDE_ASM("nonmatchings/game/cmenukeyfunc", GetGameDataUsedForSWAPINFO__FP18MENU_SWAPITEM_INFO);
INCLUDE_ASM("nonmatchings/game/cmenukeyfunc", ReturnItemMenu__12CMenuKeyFuncFi);
struct CMenuKeyFunc_190b82;
typedef struct CMenuKeyFunc_190b82 {
    /* 0x000 */ char pad0[0xC0];
    /* 0x0C0 */ char padC0[0x6C];
    /* 0x12C */ char pad12C[1];
} CMenuKeyFunc_190b82;                                     /* size >= 0x12D */
struct objet_champs_190b82 {
    char pad0[0xC0];
    /* 0xC0 */ s32 unkC0;
    char padC4[0x68];
    /* 0x12C */ s32 unk12C;
};
extern "C" s32 Init__13CGameDataUsedFv(void *);
extern "C" s32 Set__18MENU_SWAPITEM_INFOFiiii(void *, s32, s32, s32, s32);
extern "C" s32 SetHaveItemInfo__12CMenuKeyFuncFii(void *, s32, s32);
extern "C" void InitHaveData__12CMenuKeyFuncFv(CMenuKeyFunc_190b82 *objet) {
    Init__13CGameDataUsedFv(&((struct objet_champs_190b82 *) objet)->unkC0);
    Set__18MENU_SWAPITEM_INFOFiiii(&((struct objet_champs_190b82 *) objet)->unk12C, -1, 0, -1, 0);
    SetHaveItemInfo__12CMenuKeyFuncFii(objet, 0, 1);
}
INCLUDE_ASM("nonmatchings/game/cmenukeyfunc", SetHaveItemInfo__12CMenuKeyFuncFii);
INCLUDE_ASM("nonmatchings/game/cmenukeyfunc", menu_inputkey_limmit_check_line__12CMenuKeyFuncFi);
INCLUDE_ASM("nonmatchings/game/cmenukeyfunc", menu_inputkey_limmit_check_glid__12CMenuKeyFuncFi);
INCLUDE_ASM("nonmatchings/game/cmenukeyfunc", CheckMoveSelect__12CMenuKeyFuncFi);
struct CScene;
extern "C" CScene *MenuMainScene;
struct CScene {
    s32 field_0;
    s32 field_4;
    char pad_8[0x30];
    s32 field_38;
    s32 field_3C;
    s32 field_40;
    char pad_44[0x2000];
    s32 field_2044;
    char pad_2048[0x1C0];
    s32 field_2208;
    char pad_220C[0x5D4];
    s32 field_27E0;
    char pad_27E4[0xE0];
    s32 field_28C4;
    char pad_28C8[0xE0];
    s32 field_29A8;
    char pad_29AC[0x100];
    s32 field_2AAC;
    char pad_2AB0[0x1EC];
    s32 field_2C9C;
    s32 field_2CA0;
    char pad_2CA4[0x1A0];
    s32 field_2E44;
    s32 field_2E48;
    char pad_2E4C[0x4];
    s32 field_2E50;
    s32 field_2E54;
    s32 field_2E58;
    s32 field_2E5C;
    s32 field_2E60;
    s32 field_2E64;
    s32 field_2E68;
    s32 field_2E6C;
    s32 field_2E70;
    s32 field_2E74;
    s32 field_2E78;
    s32 field_2E7C;
    s32 field_2E80;
    s32 field_2E84;
    s32 field_2E88;
    s32 field_2E8C;
    char pad_2E90[0x8];
    s32 field_2E98;
    char pad_2E9C[0x8];
    s32 field_2EA4;
    f32 field_2EA8;
    f32 field_2EAC;
    f32 field_2EB0;
    f32 field_2EB4;
    char pad_2EB8[0x8];
    f32 field_2EC0;
    f32 field_2EC4;
    f32 field_2EC8;
    f32 field_2ECC;
    f32 field_2ED0;
    f32 field_2ED4;
    f32 field_2ED8;
    f32 field_2EDC;
    f32 field_2EE0;
    f32 field_2EE4;
    f32 field_2EE8;
    f32 field_2EEC;
    char pad_2EF0[0x38];
    f32 field_2F28;
    char pad_2F2C[0x8];
    f32 field_2F34;
    f32 field_2F38;
    char pad_2F3C[0x14];
    s32 field_2F50;
    s32 field_2F54;
    s32 field_2F58;
    s32 field_2F5C;
    s32 field_2F60;
    s32 field_2F64;
    s32 field_2F68;
    f32 field_2F6C;
    f32 field_2F70;
    s32 field_2F74;
    f32 field_2F78;
    char pad_2F7C[0x4];
    f32 field_2F80;
    char pad_2F84[0x10];
    s32 field_2F94;
    s32 field_2F98;
    s16 field_2F9C;
    char pad_2F9E[0x2];
    s32 field_2FA0;
    char pad_2FA4[0x10];
    s8 field_2FB4;
    char pad_2FB5[0x1F];
    s16 field_2FD4;
    s16 field_2FD6;
    s8 field_2FD8;
    s8 field_2FD9;
    char pad_2FDA[0x6];
    f32 field_2FE0;
    s32 field_2FE4;
    s32 field_2FE8;
    s32 field_2FEC;
    char pad_2FF0[0x4];
    s32 field_2FF4;
    char pad_2FF8[0x4];
    s32 field_2FFC;
    char pad_3000[0x8];
    s16 field_3008;
    char pad_300A[0x2];
    s32 field_300C;
    s32 field_3010;
    s32 field_3014;
    s32 field_3018;
    s8 field_301C;
    char pad_301D[0x3];
    s64 field_3020;
    s32 field_3028;
    s8 field_302C;
    char pad_302D[0x1];
    s16 field_302E;
    s32 field_3030;
    char pad_3034[0x4];
    s32 field_3038;
    s32 field_303C;
    char pad_3040[0x14];
    s32 field_3054;
    char pad_3058[0xE08];
    s32 field_3E60;
    s32 field_3E64;
    s32 field_3E68;
    s32 field_3E6C;
    char pad_3E70[0x1F0];
    s32 field_4060;
    char pad_4064[0x4800];
    u32 field_8864;
    char pad_8868[0x800];
    s32 field_9068;
    char pad_906C[0x4];
    s32 field_9070;
    s32 field_9074;
    char pad_9078[0x8];
    s32 field_9080;
    char pad_9084[0x45C];
    s32 field_94E0;
    char pad_94E4[0x45C];
    s32 field_9940;
    char pad_9944[0x4BC];
    s32 field_9E00;
    s32 field_9E04;
    char pad_9E08[0x80];
    s32 field_9E88;
    s32 field_9E8C;
    char pad_9E90[0x80];
    s32 field_9F10;
    s32 field_9F14;
    char pad_9F18[0x80];
    s32 field_9F98;
    s32 field_9F9C;
    char pad_9FA0[0x80];
    s32 field_A020;
    s32 field_A024;
    s32 field_A028;
    s32 field_A02C;
    s32 field_A030;
    s32 field_A034;
    s32 field_A038;
    s32 field_A03C;
    u32 field_A040;
    s32 field_A044;
    char pad_A048[0x424];
    s32 field_A46C;
    char pad_A470[0x4];
    s32 field_A474;
    char pad_A478[0x8];
    s32 field_A480;
    s32 field_A484;
    f32 field_A488;
    f32 field_A48C;
    s32 field_A490;
    s32 field_A494;
    s32 field_A498;
    s32 field_A49C;
    char pad_A4A0[0x2030];
    u32 field_C4D0;
    s32 field_C4D4;
};
struct inferred;
typedef struct CMenuKeyFunc {
    /* 0x000 */ char pad0[0x150];
    /* 0x150 */ s32 unk150;                         /* inferred */
    /* 0x154 */ s32 unk154;                         /* inferred */
    /* 0x158 */ s16 unk158;                         /* inferred */
    /* 0x15A */ s16 unk15A;                         /* inferred */
} CMenuKeyFunc;                                     /* size >= 0x15C */
extern "C" s32 GetVolBGM__6CSceneFv(void *);
extern "C" void FadeOutMenuBGMVol__12CMenuKeyFuncFii(CMenuKeyFunc *objet, s32 arg0, s32 arg1) {
    if (objet->unk15A == 0) {
        objet->unk150 = GetVolBGM__6CSceneFv(MenuMainScene);
    }
    objet->unk154 = arg0;
    objet->unk158 = (s16) arg1;
    if (objet->unk158 < 0) {
        objet->unk158 = 0;
    }
    objet->unk15A = 1;
}
INCLUDE_ASM("nonmatchings/game/cmenukeyfunc", FadeInMenuBGMVol__12CMenuKeyFuncFi);
INCLUDE_ASM("nonmatchings/game/cmenukeyfunc", StepMenuBGM__12CMenuKeyFuncFv);
INCLUDE_ASM("nonmatchings/game/cmenukeyfunc", CheckEnableHaveItemNum__Fv);
INCLUDE_ASM("nonmatchings/game/cmenukeyfunc", MenuEquipCameraSetEnv__FP12CActionCharaP9mgCCameraii);
INCLUDE_ASM("nonmatchings/game/cmenukeyfunc", MenuPosFormValueSetWeapon__FP13CGameDataUsed);
INCLUDE_ASM("nonmatchings/game/cmenukeyfunc", MenuFormUpdataAttachInfo__FP16CMenuPosDataFormP13CGameDataUsediiPs);
INCLUDE_ASM("nonmatchings/game/cmenukeyfunc", MenuPosFormValueSetFishingRod__FP13CGameDataUsed);
