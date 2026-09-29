/* CVillagerMngr
 *
 * Unité découpée par `make carve` : 33 fonctions, 4388 octets, de
 * 0x002D1F20 à 0x002D3110. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

INCLUDE_ASM("nonmatchings/game/cvillagermngr", Step__13CVillagerMngrFv);
INCLUDE_ASM("nonmatchings/game/cvillagermngr", GetAppearVlgr__13CVillagerMngrFiiiPiPP18CVillagerPlaceInfo);
extern "C" s32 GetData__13CVillagerMngrFi(void *, s32);
extern "C" s32 SearchDataIDatCharaID__13CVillagerMngrFi(void *, s32);
extern "C" f32 mgDistVector__FPf(f32 *);
extern "C" s32 GetTalkRect__13CVillagerMngrFiPf(void *objet, s32 arg0, f32 *arg1) {
    s32 temp_v0;
    u8 *temp_v0_2;
    u8 *temp_v0_3;
    s32 var_v0;

    *(s32 *) ((u8 *) arg1 + 0xC) = 0;
    temp_v0 = SearchDataIDatCharaID__13CVillagerMngrFi(objet, arg0);
    if (temp_v0 < 0) {
        return 0;
    }
    temp_v0_2 = (u8 *) GetData__13CVillagerMngrFi(objet, temp_v0);
    if (temp_v0_2 == NULL) {
        return 0;
    }
    temp_v0_3 = *(u8 **) (temp_v0_2 + 0x14);
    if (temp_v0_3 == NULL) {
        return 0;
    }
    *(u128 *) arg1 = *(u128 *) (temp_v0_3 + 0x10);
    if (mgDistVector__FPf(arg1) != 0.0f) {
        var_v0 = 0;
    } else {
        var_v0 = 1;
    }
    return var_v0 ^ 1;
}
INCLUDE_ASM("nonmatchings/game/cvillagermngr", ParabolicInitialVector__FPfPfPfff);
struct arg0_champs_61f0c0 {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
};
extern "C" s32 fptosi(f32);
extern "C" s32 GetStackInt__FP12RS_STACKDATA_002D27A0(void *arg0) {
    if (((struct arg0_champs_61f0c0 *) arg0)->unk0 == 1) {
        return fptosi(*(f32 *) &((struct arg0_champs_61f0c0 *) arg0)->unk4);
    }
    return ((struct arg0_champs_61f0c0 *) arg0)->unk4;
}
INCLUDE_ASM("nonmatchings/game/cvillagermngr", GetStackFloat__FP12RS_STACKDATA_002D27E0);
INCLUDE_ASM("nonmatchings/game/cvillagermngr", GetStackString__FP12RS_STACKDATA_002D2810);
INCLUDE_ASM("nonmatchings/game/cvillagermngr", SetStack__FP12RS_STACKDATAi_002D2820);
INCLUDE_ASM("nonmatchings/game/cvillagermngr", SetStack__FP12RS_STACKDATAf_002D2840);
extern "C" u32 action_info[4];
extern "C" s32 ResetScript__12CActionCharaFv(void *);
extern "C" s32 _INIT_SCRIPT__FP12RS_STACKDATAi(void *arg0, s32 arg1) {
    ResetScript__12CActionCharaFv((void *) action_info[0]);
    return 1;
}
struct action_info_champs_a4512e {
    char pad0[0x712];
    /* 0x712 */ s16 unk712;
};
extern "C" s32 _PROG_SET__FP12RS_STACKDATAi(void *arg0, s32 arg1) {
    if (arg1 != 1) {
        return 0;
    }
    ((struct action_info_champs_a4512e *) action_info[0])->unk712 = GetStackInt__FP12RS_STACKDATA_002D27A0(arg0);
    return 1;
}
extern "C" s32 SetStack__FP12RS_STACKDATAi_002D2820(...);
extern "C" s32 _PROG_GET__FP12RS_STACKDATAi(void *arg0, s32 arg1) {
    if (arg1 != 1) {
        return 0;
    }
    SetStack__FP12RS_STACKDATAi_002D2820(arg0, ((struct action_info_champs_a4512e *) action_info[0])->unk712);
    return 1;
}
struct action_info_champs_de4039 {
    char pad0[0x6A4];
    /* 0x6A4 */ s32 unk6A4;
    /* 0x6A8 */ s32 unk6A8;
};
extern "C" s32 _GET_ATTK_TYPE__FP12RS_STACKDATAi(void *arg0, s32 arg1) {
    if (arg1 != 1) {
        return 0;
    }
    SetStack__FP12RS_STACKDATAi_002D2820(arg0, ((struct action_info_champs_de4039 *) action_info[0])->unk6A4);
    return 1;
}
extern "C" s32 _GET_MOVE_TYPE__FP12RS_STACKDATAi(void *arg0, s32 arg1) {
    if (arg1 != 1) {
        return 0;
    }
    SetStack__FP12RS_STACKDATAi_002D2820(arg0, ((struct action_info_champs_de4039 *) action_info[0])->unk6A8);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/cvillagermngr", _SET_MOVE_SPEED__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/cvillagermngr", _SET_PALLET__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/cvillagermngr", _CHECK_EQUIP__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/cvillagermngr", _CAMERA_QUAKE__FP12RS_STACKDATAi_002D2B80);
#include "runscript.hpp"
extern "C" u32 nowScene_0037E44C;
struct temp_s0_champs_6efa9a {
    char pad0[0x8];
    /* 0x8 */ s32 unk8;
};
extern "C" s32 _CHECK_PAUSE__FP12RS_STACKDATAi_002D2BF0(RS_STACKDATA *arg0, s32 arg1) {
    struct temp_s0_champs_6efa9a *temp_s0;

    if (arg1 != 2) {
        return 0;
    }
    temp_s0 = (struct temp_s0_champs_6efa9a *) (nowScene_0037E44C + 0x2F90);
    if (temp_s0 == NULL) {
        return 0;
    }
    SetStack__FP12RS_STACKDATAi_002D2820(arg0, temp_s0->unk8 & GetStackInt__FP12RS_STACKDATA_002D27A0(arg0++));
    return 1;
}
INCLUDE_ASM("nonmatchings/game/cvillagermngr", _GET_STATUS_ATTR__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/cvillagermngr", _SE_PLAY__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/cvillagermngr", _SE_LOOP_PLAY__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/cvillagermngr", _GET_SHOT_TYPE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/cvillagermngr", _GET_MONS_ID__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/cvillagermngr", _GET_FRONT_VEC__FP12RS_STACKDATAi);
extern "C" u8 GamePad_003FA5A0[1144];
#include "runscript.hpp"
extern "C" s32 GetPadOn__8CGamePadFv(void *);
extern "C" s32 SetStack__FP12RS_STACKDATAi_002D2820(...);
extern "C" s32 _GET_PADON__FP12RS_STACKDATAi_002D2F20(s32 arg0, s32 arg1) {
    if (arg1 <= 0) {
        return 0;
    }
    SetStack__FP12RS_STACKDATAi_002D2820(arg0, GetPadOn__8CGamePadFv(&GamePad_003FA5A0));
    return 1;
}
extern "C" s32 GetPadDown__8CGamePadFv(void *);
extern "C" s32 _GET_PADDOWN__FP12RS_STACKDATAi_002D2F70(s32 arg0, s32 arg1) {
    if (arg1 <= 0) {
        return 0;
    }
    SetStack__FP12RS_STACKDATAi_002D2820(arg0, GetPadDown__8CGamePadFv(&GamePad_003FA5A0));
    return 1;
}
extern "C" s32 GetPadUp__8CGamePadFv(void *);
extern "C" s32 _GET_PADUP__FP12RS_STACKDATAi_002D2FC0(s32 arg0, s32 arg1) {
    if (arg1 <= 0) {
        return 0;
    }
    SetStack__FP12RS_STACKDATAi_002D2820(arg0, GetPadUp__8CGamePadFv(&GamePad_003FA5A0));
    return 1;
}
extern "C" u8 PadCtrl[1296];
extern "C" s32 Btn__11CPadControlFi(void *, s32);
extern "C" s32 _GET_BTN__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    if (arg1 <= 0) {
        return 0;
    }
    SetStack__FP12RS_STACKDATAi_002D2820(arg0, Btn__11CPadControlFi(&PadCtrl, GetStackInt__FP12RS_STACKDATA_002D27A0(arg0++)));
    return 1;
}
struct action_info_champs_f0160b {
    char pad0[0x714];
    /* 0x714 */ s32 unk714;
    char pad718[0xC0];
    /* 0x7D8 */ s32 unk7D8;
};
extern "C" s32 _GET_PAD_HISTORY__FP12RS_STACKDATAi(void *arg0, s32 arg1) {
    if (arg1 <= 0) {
        return 0;
    }
    SetStack__FP12RS_STACKDATAi_002D2820(arg0, ((struct action_info_champs_f0160b *) action_info[0])->unk714);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/cvillagermngr", _RESET_PAD_HISTORY__FP12RS_STACKDATAi);
extern "C" s32 _GET_ACUMU_PAD__FP12RS_STACKDATAi(void *arg0, s32 arg1) {
    SetStack__FP12RS_STACKDATAi_002D2820(arg0, ((struct action_info_champs_f0160b *) action_info[0])->unk7D8);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/cvillagermngr", _RESET_ACUMU_PAD__FP12RS_STACKDATAi);
