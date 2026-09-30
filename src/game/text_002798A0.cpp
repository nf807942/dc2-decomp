/* Fonctions libres — à décrire.
 *
 * Unité découpée par `make carve` : 178 fonctions, 24580 octets, de
 * 0x002798A0 à 0x0027FCE0. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"
#include "gen/GeoStoneData.hpp"

#include "runscript.hpp"
extern s32 SwordEffect;
struct RS_STACKDATA;

extern GeoStoneData GeoStone;


struct Sphida_pointe;
extern "C" Sphida_pointe *Sphida;
struct Sphida_champs_7d6b3d {
    char pad0[0x2C];
    /* 0x2C */ s32 unk2C;
};
extern "C" s32 GetStackInt__FP12RS_STACKDATA_00262DA0(...);
extern "C" s32 _SPHIDA_SET_MINIMAP_FLAG__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    s32 temp_v0;

    temp_v0 = (s32) (GetStackInt__FP12RS_STACKDATA_00262DA0(arg0));
    if (Sphida == NULL) {
        return 0;
    }
    ((struct Sphida_champs_7d6b3d *) Sphida)->unk2C = temp_v0;
    return 1;
}
struct Sphida_champs_50b6cc {
    char pad0[0x30];
    /* 0x30 */ s32 unk30;
};
extern "C" s32 _SPHIDA_SET_MM_LINE_FLAG__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    s32 temp_v0;

    temp_v0 = (s32) (GetStackInt__FP12RS_STACKDATA_00262DA0(arg0));
    if (Sphida == NULL) {
        return 0;
    }
    ((struct Sphida_champs_50b6cc *) Sphida)->unk30 = temp_v0;
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_002798A0", _SPHIDA_SET_MM_LINE_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _SPHIDA_SET_PIN_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _SPHIDA_GET_PIN_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _SPHIDA_SET_BALL_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _SPHIDA_GET_BALL_POS__FP12RS_STACKDATAi);
struct Sphida_champs_7072c7 {
    char pad0[0xB0];
    /* 0xB0 */ s32 unkB0;
};
extern "C" s32 _SPHIDA_SET_PIN_COL__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    s32 temp_v0;

    temp_v0 = (s32) (GetStackInt__FP12RS_STACKDATA_00262DA0(arg0));
    if (Sphida == NULL) {
        return 0;
    }
    ((struct Sphida_champs_7072c7 *) Sphida)->unkB0 = temp_v0;
    return 1;
}
struct Sphida_champs_e514de {
    char pad0[0xB0];
    /* 0xB0 */ s32 unkB0;
};
extern "C" s32 SetStack__FP12RS_STACKDATAi_00262E70(...);
extern "C" s32 _SPHIDA_GET_PIN_COL__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    if (Sphida == NULL) {
        return 0;
    }
    SetStack__FP12RS_STACKDATAi_00262E70(arg0, ((struct Sphida_champs_e514de *) Sphida)->unkB0);
    return 1;
}
struct Sphida_champs_a984eb {
    char pad0[0xB4];
    /* 0xB4 */ s32 unkB4;
};
extern "C" s32 _SPHIDA_SET_BALL_COL__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    s32 temp_v0;

    temp_v0 = (s32) (GetStackInt__FP12RS_STACKDATA_00262DA0(arg0));
    if (Sphida == NULL) {
        return 0;
    }
    ((struct Sphida_champs_a984eb *) Sphida)->unkB4 = temp_v0;
    return 1;
}
struct Sphida_champs_be5f20 {
    char pad0[0xB4];
    /* 0xB4 */ s32 unkB4;
};
extern "C" s32 SetStack__FP12RS_STACKDATAi_00262E70(...);
extern "C" s32 _SPHIDA_GET_BALL_COL__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    if (Sphida == NULL) {
        return 0;
    }
    SetStack__FP12RS_STACKDATAi_00262E70(arg0, ((struct Sphida_champs_be5f20 *) Sphida)->unkB4);
    return 1;
}
extern "C" u32 DebugFlag;
typedef struct Sphida_pointe {
    char pad0[184];
    s32 unkB8;
} Sphida_pointe;
extern "C" Sphida_pointe *Sphida;
extern "C" s32 GetStackInt__FP12RS_STACKDATA_00262DA0(...);
extern "C" s32 _SPHIDA_SET_PAR_COUNT__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    s32 temp_v0;

    temp_v0 = (s32) (GetStackInt__FP12RS_STACKDATA_00262DA0(arg0));
    if (Sphida == NULL) {
        return 0;
    }
    if (DebugFlag == 0) {
        Sphida->unkB8 = temp_v0;
    }
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_002798A0", _SPHIDA_GET_PAR_COUNT__FP12RS_STACKDATAi);
struct Sphida_champs_87e485 {
    char pad0[0x1F0];
    /* 0x1F0 */ s32 unk1F0;
};
extern "C" s32 SetStack__FP12RS_STACKDATAi_00262E70(...);
extern "C" s32 _SPHIDA_GET_MINI_LEVEL__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    if (Sphida == NULL) {
        return 0;
    }
    SetStack__FP12RS_STACKDATAi_00262E70(arg0, ((struct Sphida_champs_87e485 *) Sphida)->unk1F0);
    return 1;
}
struct Sphida_champs_a9b3a2 {
    char pad0[0x24];
    /* 0x24 */ s32 unk24;
};
extern "C" s32 SetStack__FP12RS_STACKDATAi_00262E70(...);
extern "C" s32 _SPHIDA_GET_TEXB__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    if (Sphida == NULL) {
        return 0;
    }
    SetStack__FP12RS_STACKDATAi_00262E70(arg0, ((struct Sphida_champs_a9b3a2 *) Sphida)->unk24);
    return 1;
}
struct Sphida_champs_255774 {
    char pad0[0x34];
    /* 0x34 */ s32 unk34;
};
extern "C" s32 _SPHIDA_SET_STATUS_FLAG__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    s32 temp_v0;

    temp_v0 = (s32) (GetStackInt__FP12RS_STACKDATA_00262DA0(arg0));
    if (Sphida == NULL) {
        return 0;
    }
    ((struct Sphida_champs_255774 *) Sphida)->unk34 = temp_v0;
    return 1;
}
struct Sphida;
struct Sphida_fields { char pad0[0xC]; s32 unkC; char pad10[4]; s32 unk14; s32 unk18; s32 unk1C; s32 unk20; };
extern "C" s32 _SPHIDA_RESET_POWGAGE__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    if (Sphida == 0) return 0;
    Sphida_fields *p = (Sphida_fields *)Sphida;
    p->unk1C = -1; p->unk20 = 0; p->unk18 = 0; p->unkC = 0; p->unk14 = -10;
    return 1;
}
struct Sphida_champs_c93686 {
    char pad0[0x1C];
    /* 0x1C */ s32 unk1C;
};
extern "C" s32 _SPHIDA_START_POWGAGE__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    if (Sphida == NULL) {
        return 0;
    }
    ((struct Sphida_champs_c93686 *) Sphida)->unk1C = 0;
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_002798A0", _SPHIDA_TRIGGER_POWGAGE__FP12RS_STACKDATAi);
struct Sphida_champs_289de4 {
    char pad0[0xC];
    /* 0xC */ s32 unkC;
};
extern "C" s32 SetStack__FP12RS_STACKDATAf_00262E90(RS_STACKDATA *, f32);
extern "C" s32 _SPHIDA_GET_SHOT_POW__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    if (Sphida == NULL) {
        return 0;
    }
    SetStack__FP12RS_STACKDATAf_00262E90(arg0, *(f32 *) &((struct Sphida_champs_289de4 *) Sphida)->unkC);
    return 1;
}
struct Sphida_champs_4b628f {
    char pad0[0x14];
    /* 0x14 */ s32 unk14;
};
extern "C" s32 SetStack__FP12RS_STACKDATAi_00262E70(...);
extern "C" s32 _SPHIDA_GET_POWGAGE_CODE__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    if (Sphida == NULL) {
        return 0;
    }
    SetStack__FP12RS_STACKDATAi_00262E70(arg0, ((struct Sphida_champs_4b628f *) Sphida)->unk14);
    return 1;
}
struct Sphida_champs_59b7d2 {
    char pad0[0x10];
    /* 0x10 */ s32 unk10;
};
extern "C" s32 _SPHIDA_SET_POWGAGE_SAFE_LEVEL__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    s32 var_v0;

    var_v0 = (s32) (GetStackInt__FP12RS_STACKDATA_00262DA0(arg0));
    if (Sphida == NULL) {
        return 0;
    }
    if (var_v0 <= 0) {
        var_v0 = 1;
    }
    if (var_v0 > 6) {
        var_v0 = 6;
    }
    ((struct Sphida_champs_59b7d2 *) Sphida)->unk10 = var_v0;
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_002798A0", _SPHIDA_GET_CULB_DEF__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _SPHIDA_SET_SPIN_MARK_POS__FP12RS_STACKDATAi);
struct Sphida_champs_97f4b7 {
    char pad0[0x1FC];
    /* 0x1FC */ s32 unk1FC;
};
extern "C" s32 _SPHIDA_SET_CULB_NO__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    s32 temp_v0;

    temp_v0 = (s32) (GetStackInt__FP12RS_STACKDATA_00262DA0(arg0));
    if (Sphida == NULL) {
        return 0;
    }
    ((struct Sphida_champs_97f4b7 *) Sphida)->unk1FC = temp_v0;
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_002798A0", _SPHIDA_CALC_CARRY__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _SPHIDA_GET_PG_CURSOR_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _SPHIDA_SET_COL_MODEL__FP12RS_STACKDATAi);
extern "C" u32 EventScene;
#include "dngfloormanager.hpp"
extern "C" s32 GetSphedaPrize__16CDngFloorManagerFiPiPi(void *, s32, s32 *, s32 *);
extern "C" s32 SetStack__FP12RS_STACKDATAi_00262E70(...);
extern "C" s32 _SPHIDA_GET_PRIZE__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    s32 sp38;
    s32 sp3C;
    CDngFloorManager *temp_s0;
    RS_STACKDATA *temp_s1;
    s32 temp_v0;

    temp_v0 = EventScene + 0x2F90;
    temp_s0 = (CDngFloorManager *) (temp_v0 + 0x14);
    if (temp_v0 == 0) {
        return 0;
    }
    temp_s1 = arg0 + 1;
    if (temp_s0 == NULL) {
        return 0;
    }
    GetSphedaPrize__16CDngFloorManagerFiPiPi(temp_s0, GetStackInt__FP12RS_STACKDATA_00262DA0(arg0), &sp38, &sp3C);
    SetStack__FP12RS_STACKDATAi_00262E70(temp_s1++, sp38);
    SetStack__FP12RS_STACKDATAi_00262E70(temp_s1, sp3C);
    return 1;
}
struct Sphida_champs_c38fcd {
    char pad0[0x204];
    /* 0x204 */ s32 unk204;
};
extern "C" s32 _SPHIDA_SET_LAST_CHALLENGE__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    if (Sphida == NULL) {
        return 0;
    }
    ((struct Sphida_champs_c38fcd *) Sphida)->unk204 = GetStackInt__FP12RS_STACKDATA_00262DA0(arg0);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_002798A0", _SPHIDA_GET_LAST_CHALLENGE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _SPHIDA_GET_OMAKE_MODE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _SPHIDA_SET_NOW_HOLE__FP12RS_STACKDATAi);
extern "C" s32 GetSphidaData__12CSubGameDataFv(void *);
extern "C" s32 GetSubGameSaveData__Fv(void);
#include "gen/CSphidaData.hpp"
#include "gen/CSubGameData.hpp"
extern "C" s32 GetNowHorl__11CSphidaDataFv(void *);
extern "C" s32 SetStack__FP12RS_STACKDATAi_00262E70(...);
extern "C" s32 _SPHIDA_GET_NOW_HOLE__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    CSphidaData *temp_v0_2;
    CSubGameData *temp_v0;

    if (arg1 != 1) {
        return 0;
    }
    temp_v0 = (CSubGameData *) (GetSubGameSaveData__Fv());
    if (temp_v0 == NULL) {
        return 0;
    }
    temp_v0_2 = (CSphidaData *) (GetSphidaData__12CSubGameDataFv(temp_v0));
    if (temp_v0_2 == NULL) {
        return 0;
    }
    SetStack__FP12RS_STACKDATAi_00262E70(arg0, GetNowHorl__11CSphidaDataFv(temp_v0_2));
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_002798A0", _SPHIDA_SET_SCORE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _SPHIDA_GET_SCORE__FP12RS_STACKDATAi);
s32 _TEST(RS_STACKDATA *stack, int argc) {
    return 1;
}
extern "C" void mt_test__FP12RS_STACKDATAi(RS_STACKDATA *, s32);
extern "C" void _MT_TEST__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    mt_test__FP12RS_STACKDATAi(arg0, arg1);
}
INCLUDE_ASM("nonmatchings/game/text_002798A0", _ZERO_VECTOR__FP12RS_STACKDATAi_0027A530);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _NORMAL_VECTOR__FP12RS_STACKDATAi_0027A570);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _COPY_VECTOR__FP12RS_STACKDATAi_0027A610);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _ADD_VECTOR__FP12RS_STACKDATAi_0027A670);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _SUB_VECTOR__FP12RS_STACKDATAi_0027A6E0);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _SCALE_VECTOR__FP12RS_STACKDATAi_0027A750);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _DIV_VECTOR__FP12RS_STACKDATAi_0027A7B0);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _DIST_VECTOR__FP12RS_STACKDATAi_0027A860);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _DIST_VECTOR2__FP12RS_STACKDATAi_0027A8B0);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _SQRT__FP12RS_STACKDATAi_0027A910);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _ATAN2F__FP12RS_STACKDATAi_0027A960);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _ANGLE_CMP__FP12RS_STACKDATAi_0027A9B0);
struct RS_STACKDATA;
struct angle_fields { char pad[4]; f32 unk4; };
struct stack_fields { char pad[4]; s32 unk4; };
extern "C" s32 SetStack__FP12RS_STACKDATAf_00262E90(RS_STACKDATA *, f32);
extern "C" f32 mgAngleLimit__Ff(f32);
extern "C" s32 _ANGLE_LIMIT__FP12RS_STACKDATAi_0027AA10(void *arg0, s32 arg1) {
    angle_fields *data = (angle_fields *) ((stack_fields *) arg0)->unk4;
    SetStack__FP12RS_STACKDATAf_00262E90((RS_STACKDATA *) arg0, mgAngleLimit__Ff(data->unk4));
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_002798A0", _GET_RAND__FP12RS_STACKDATAi_0027AA50);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _LINE_POINT_DIST__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _CREATE_SWORD_EFFECT__FP12RS_STACKDATAi);
s32 _DELETE_SWORD_EFFECT(RS_STACKDATA * arg0, s32 arg1) {
    SwordEffect = 0;
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_002798A0", _SWORD_EFFECT_COLOR__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _SWORD_EFFECT_ADD_POINT__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _ADD_CHARA_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _ADD_CHARA_ROT__FP12RS_STACKDATAi);
extern "C" u32 EventScene;
#include "sphida.hpp"
struct temp_v0_champs_4b375e {
    char pad0[0x7C];
    /* 0x7C */ s32 unk7C;
};
extern "C" f32 GetStackFloat__FP12RS_STACKDATA_00262DE0(RS_STACKDATA *);
extern "C" s32 GetStackVector__FPfP12RS_STACKDATA_00262E10(f32 *, RS_STACKDATA *);
extern "C" s32 PutTreasureBox__19CTreasureBoxManagerFiPffiiiii(void *, s32, f32 *, f32, s32, s32, s32, s32, s32);
extern "C" s32 _POST_TREASURE_BOX__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    f32 sp60[3];
    CTreasureBoxManager *temp_a0;
    f32 temp_f20;
    s32 temp_s0;
    s32 var_s1;
    struct temp_v0_champs_4b375e *temp_v0;

    var_s1 = 1;
    GetStackVector__FPfP12RS_STACKDATA_00262E10(sp60, arg0);
    arg0 += 3;
    temp_f20 = GetStackFloat__FP12RS_STACKDATA_00262DE0(arg0++);
    temp_s0 = (s32) (GetStackInt__FP12RS_STACKDATA_00262DA0(arg0++));
    if (arg1 >= 6) {
        var_s1 = (s32) (GetStackInt__FP12RS_STACKDATA_00262DA0(arg0));
    }
    temp_v0 = (struct temp_v0_champs_4b375e *) (EventScene + 0x2F90);
    if (temp_v0 == NULL) {
        return 0;
    }
    temp_a0 = (CTreasureBoxManager *) (temp_v0->unk7C);
    if (temp_a0 == NULL) {
        return 0;
    }
    PutTreasureBox__19CTreasureBoxManagerFiPffiiiii(temp_a0, -1, sp60, temp_f20, 0x41, temp_s0, var_s1, -1, 0);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_002798A0", _GET_PARTS_ORIGIN__FP12RS_STACKDATAi);
extern "C" s32 GetCamera__Fv(void);
struct CTRLC_Base { char pad[0x60]; };
struct CTRLC_Object : CTRLC_Base { virtual s32 fn(s32); };
extern "C" s32 _CTRLC_STEP__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    CTRLC_Object *p = (CTRLC_Object *)GetCamera__Fv();
    p->fn(1);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_002798A0", _CTRLC_SET_ROTATE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _CTRLC_ROT_BACK__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _CTRLC_MOVE_CAMERA__FP12RS_STACKDATAi);
extern "C" s32 GetCamera__Fv(void);
extern "C" s32 GetStackInt__FP12RS_STACKDATA_00262DA0(...);
extern "C" s32 SetRotCameraCancel__14CCameraControlFi(...);
extern "C" s32 _CTRLC_SET_ROT_CANCEL__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    s32 temp_s0;

    temp_s0 = (s32) (GetStackInt__FP12RS_STACKDATA_00262DA0(arg0));
    SetRotCameraCancel__14CCameraControlFi(GetCamera__Fv(), temp_s0);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_002798A0", _CTRLC_MOVE_RANGE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _GET_NEAR_TBOX_POS__FP12RS_STACKDATAi);
s32 _CONV_CHRNO_S2L(RS_STACKDATA *stack, int argc) {
    return 0;
}
INCLUDE_ASM("nonmatchings/game/text_002798A0", _SWE_INIT__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _SWE_SET_COLOR__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _SWE_SET_TEXTURE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _SWE_START_EFFECT__FP12RS_STACKDATAi);
extern "C" u32 EventScene;
extern "C" s32 GetStackInt__FP12RS_STACKDATA_00262DA0(...);
extern "C" s32 SetType__6CSceneFiii(...);
extern "C" s32 _SET_CHARA_TYPE__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    s32 temp_s0;

    temp_s0 = (s32) (GetStackInt__FP12RS_STACKDATA_00262DA0(arg0++));
    SetType__6CSceneFiii(EventScene, 1, temp_s0, GetStackInt__FP12RS_STACKDATA_00262DA0(arg0));
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_002798A0", _GET_EVENT_DATA__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _DNG_SET_PREV_FLOOR__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _DNG_GET_PREV_FLOOR__FP12RS_STACKDATAi);
s32 _DNG_SET_FAST_FLOOR(RS_STACKDATA *stack, int argc) {
    return 0;
}
INCLUDE_ASM("nonmatchings/game/text_002798A0", _SET_FLOOR_INFO__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _GET_FLOOR_INFO__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _GET_NEXT_FLOOR__FP12RS_STACKDATAi);
#include "gamepad.hpp"
extern "C" void AutoRepeatOff__8CGamePadFv(CGamePad *objet);
extern "C" s32 _PAD_AUTO_REPEAT_OFF__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    AutoRepeatOff__8CGamePadFv(&GamePad_003FA5A0);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_002798A0", _PAD_SET_AUTO_REPEAT__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _DNG_PAUSE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _DNG_CHECK_PAUSE__FP12RS_STACKDATAi);
extern "C" u32 EventScene;
struct temp_v0_champs {
    char pad0[0x10];
    /* 0x10 */ s32 unk10;
};
extern "C" s32 _DNG_RESET_TIMER__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    struct temp_v0_champs *temp_v0;

    temp_v0 = (struct temp_v0_champs *) (EventScene + 0x2F90);
    if (temp_v0 == NULL) {
        return 0;
    }
    temp_v0->unk10 = 0;
    return 1;
}
struct temp_v0_champs_a479b7 {
    char pad0[0x10];
    /* 0x10 */ s32 unk10;
};
extern "C" s32 _DNG_GET_TIMER__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    struct temp_v0_champs_a479b7 *temp_v0;

    temp_v0 = (struct temp_v0_champs_a479b7 *) (EventScene + 0x2F90);
    if (temp_v0 == NULL) {
        return 0;
    }
    SetStack__FP12RS_STACKDATAi_00262E70(arg0, temp_v0->unk10);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_002798A0", _LOAD_SKIN__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _CHK_CAMERA_COL__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _GET_PARTS_FUNC_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _RANDOM_CIRCLE_GET_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _RANDOM_CIRCLE_OFF__FP12RS_STACKDATAi);
extern "C" void XChgMapLighting__Fv();
extern "C" s32 _DNG_XCHG_MAP_LIGHT__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    XChgMapLighting__Fv();
    return 1;
}
s32 _GEOSTONE_ANIME_OFF(RS_STACKDATA * arg0, s32 arg1) {
    GeoStone.field_0x668 = 0;
    return 1;
}
extern "C" s32 GetStackInt__FP12RS_STACKDATA_00262DA0(...);
extern "C" s32 SetFlag__9CGeoStoneFi(void *, s32);
extern "C" s32 _GEOSTONE_SET_FLAG__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    SetFlag__9CGeoStoneFi(&GeoStone, GetStackInt__FP12RS_STACKDATA_00262DA0(arg0));
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_002798A0", _GEOSTONE_SET_REFERENCE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _GEOSTONE_DEL_REFERENCE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _GET_ROBO_MOVE_TYPE__FP12RS_STACKDATAi);
struct EventScene_champs_d974f8 {
    char pad0[0x2F64];
    /* 0x2F64 */ s32 unk2F64;
};
extern "C" s32 _SET_EXIT_FLAG__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    ((struct EventScene_champs_d974f8 *) EventScene)->unk2F64 = GetStackInt__FP12RS_STACKDATA_00262DA0(arg0);
    return 1;
}
struct EventScene_champs_1e1799 {
    char pad0[0x2F64];
    /* 0x2F64 */ s32 unk2F64;
};
extern "C" s32 _GET_EXIT_FLAG__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    SetStack__FP12RS_STACKDATAi_00262E70(arg0, ((struct EventScene_champs_1e1799 *) EventScene)->unk2F64);
    return 1;
}
extern "C" s32 _GET_E3_VERSION__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    SetStack__FP12RS_STACKDATAi_00262E70(arg0, 0);
    return 1;
}
extern "C" u8 PadCtrl[1296];
extern "C" s32 Btn__11CPadControlFi(void *, s32);
extern "C" s32 _CHK_PAD_CTRL__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    s32 temp_v0;
    if (arg1 != 2) {
        return 0;
    }
    temp_v0 = Btn__11CPadControlFi(&PadCtrl, GetStackInt__FP12RS_STACKDATA_00262DA0(arg0++));
    SetStack__FP12RS_STACKDATAi_00262E70(arg0, temp_v0);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_002798A0", _CTRLC_STAY__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _BSCN_SET_BLIGHT_RATE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _GET_RND_CIRCLE_TRAPID__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _SET_RND_CIRCLE_STATUS__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _SET_STATUSBAR_SHOW__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _SET_PULL_ITEM__FP12RS_STACKDATAi);
typedef struct EdEventInfo_champs {
    char pad0[208];
    s32 unkD0;
    char padD4[0x124];
    s32 mapDraw;
    char pad1FC[0x10A4];
} EdEventInfo_champs;
extern "C" EdEventInfo_champs EdEventInfo;
typedef struct MenuArg_champs {
    char pad0[40];
    s32 unk28;
    char pad2C[108];
} MenuArg_champs;
extern "C" MenuArg_champs MenuArg;
extern "C" s32 _MENU_CHARA_CHENGE__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    GetStackInt__FP12RS_STACKDATA_00262DA0(arg0);
    MenuArg.unk28 = 0xE;
    EdEventInfo.unkD0 = 3;
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_002798A0", _GET_EVENT_INFO_SNDID__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _GET_PARTS_POS__FP12RS_STACKDATAi);
extern "C" void CancelDramaScene__Fv();
extern "C" s32 _CANCEL_DRAMA_SCENE__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    CancelDramaScene__Fv();
    return 1;
}
struct RandomCircle;
extern "C" s32 _GET_RNDC_MOT_NOWT__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    f32 weight = RandomCircle.motNowt;
    SetStack__FP12RS_STACKDATAf_00262E90(arg0, weight);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_002798A0", _SET_CHARA_MOT_NOWT__FP12RS_STACKDATAi);
extern "C" s32 GetCharacter__Fi(s32);
struct temp_v0_champs_6e3565 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
};
extern "C" s32 _CHARA_NORMAL_DRIVE__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    struct temp_v0_champs_6e3565 *temp_v0;
    temp_v0 = (struct temp_v0_champs_6e3565 *) (GetCharacter__Fi(GetStackInt__FP12RS_STACKDATA_00262DA0(arg0)));
    if (temp_v0 == NULL) {
        return 0;
    }
    temp_v0->v50();
    return 1;
}
extern "C" s32 GetCharacter__Fi(s32);
#include "sphida.hpp"
extern "C" s32 GetStackInt__FP12RS_STACKDATA_00262DA0(...);
extern "C" s32 ResetDAPosition__11CCharacter2Fv(void *);
extern "C" s32 StepDA__11CCharacter2Fi(void *, s32);
extern "C" s32 _CHARA_RESET_DA__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    CCharacter2 *temp_v0;

    if ((temp_v0 = (CCharacter2 *) (GetCharacter__Fi(GetStackInt__FP12RS_STACKDATA_00262DA0(arg0)))) == NULL) {
        return 0;
    }
    ResetDAPosition__11CCharacter2Fv(temp_v0);
    StepDA__11CCharacter2Fi(temp_v0, 0xA);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_002798A0", _DNG_SETUP_MAIN_UNIT__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _JOIN_PARTY_MEMBER__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _SET_CHARA_CHANGE_FLAG__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _SET_CHARA_CHANGE_MASK__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _SET_CHARA_EQUIP__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _LOAD_PACK_FILE__FP12RS_STACKDATAi);
extern "C" s32 GetSaveData__Fv(void);
#include "dngfloormanager.hpp"
extern "C" s32 GetStackInt__FP12RS_STACKDATA_00262DA0(...);
extern "C" s32 ResetBitCtrl__9CSaveDataFi(void *, s32);
extern "C" s32 SetBitCtrl__9CSaveDataFi(void *, s32);
extern "C" s32 _SET_BIT_CTRL__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    CSaveData *temp_v0;
    s32 temp_s1;

    if ((temp_v0 = (CSaveData *) (GetSaveData__Fv())) == NULL) {
        return 0;
    }
    temp_s1 = (s32) (GetStackInt__FP12RS_STACKDATA_00262DA0(arg0++));
    if (GetStackInt__FP12RS_STACKDATA_00262DA0(arg0) == 1) {
        SetBitCtrl__9CSaveDataFi(temp_v0, temp_s1);
    } else {
        ResetBitCtrl__9CSaveDataFi(temp_v0, temp_s1);
    }
    return 1;
}
extern "C" s32 GetSaveData__Fv(void);
#include "dngfloormanager.hpp"
extern "C" s32 GetBitCtrl__9CSaveDataFv(void *);
extern "C" s32 _GET_BIT_CTRL__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    s32 save;
    CSaveData *temp_v0;
    s32 temp_s0;
    s32 temp_v1;

    if ((temp_v0 = (CSaveData *) GetSaveData__Fv()) == NULL) {
        return 0;
    }
    temp_s0 = (s32) (GetStackInt__FP12RS_STACKDATA_00262DA0(arg0++));
    temp_v1 = GetBitCtrl__9CSaveDataFv(temp_v0);
    SetStack__FP12RS_STACKDATAi_00262E70(arg0, (temp_v1 & temp_s0) ? 1 : 0);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_002798A0", _LOAD_ARG__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _GET_ITEM_HAVE_NUM__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _SET_SKIP_BOTTON__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _SET_SKIP_FCOL__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _GET_DEBUG_MODE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _GET_MAP_TYPE__FP12RS_STACKDATAi);
extern "C" u8 ColPrimMan[17424];
#include "sphida.hpp"
extern "C" s32 Initialize__11CColPrimManFP6CScene(void *, CScene *);
extern "C" s32 _DNG_COLLISION_ALL_CLR__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    Initialize__11CColPrimManFP6CScene(&ColPrimMan, DngMainScene);
    return 1;
}
struct EdEventInfo;
extern "C" s32 _SET_MAP_DRAW__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    EdEventInfo.mapDraw = GetStackInt__FP12RS_STACKDATA_00262DA0(arg0);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_002798A0", _CHECK_MC_LOAD__FP12RS_STACKDATAi);
extern "C" s32 SetNowMapNo__6CSceneFi(...);
extern "C" s32 _SET_NOW_MAP_NO__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    SetNowMapNo__6CSceneFi(EventScene, GetStackInt__FP12RS_STACKDATA_00262DA0(arg0));
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_002798A0", _GET_TBOX_PARAM__FP12RS_STACKDATAi);
extern "C" s32 _CANCEL_LOAD_VILLAGER__FP12RS_STACKDATAi(void *arg0, s32 arg1) {
    u8 *p = (u8 *) EventScene;
    *(s32 *) (p + 0x303C) = 1;
    *(s32 *) (p + 0x3038) = 1;
    return 1;
}
extern "C" void CancelNowLoading__Fv();
extern "C" s32 _CANCEL_NOW_LOADING__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    CancelNowLoading__Fv();
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_002798A0", _ESM_INITIALIZE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _ESM_INIT_FIX__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _ESM_CLEAR__FP12RS_STACKDATAi);
extern "C" u32 EventEffectScript;
extern "C" s32 GetStackString__FP12RS_STACKDATA_00262E60(...);
#include "menu.hpp"
extern "C" s32 GetStackInt__FP12RS_STACKDATA_00262DA0(...);
extern "C" s32 LoadBaseEffSpt__16CEffectScriptManFPcP9mgCMemoryi(...);
extern "C" s32 LoadBaseEffSpt__16CEffectScriptManFiP9mgCMemoryi(...);
extern "C" s32 _ESM_LOAD_BASE__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    s32 ret;

    if (EventEffectScript == NULL) {
        return 0;
    }
    switch (arg0->type) {
    case 0:
        ret = LoadBaseEffSpt__16CEffectScriptManFiP9mgCMemoryi(EventEffectScript, GetStackInt__FP12RS_STACKDATA_00262DA0(arg0), NULL, -1);
        break;
    case 2:
        ret = LoadBaseEffSpt__16CEffectScriptManFPcP9mgCMemoryi(EventEffectScript, GetStackString__FP12RS_STACKDATA_00262E60(arg0), NULL, -1);
        break;
    default:
        ret = 0;
        break;
    }
    return ret;
}
INCLUDE_ASM("nonmatchings/game/text_002798A0", _ESM_CREATE__FP12RS_STACKDATAi_0027E3C0);
extern "C" u32 EventEffectScript;
extern "C" s32 SetScriptProgNo__16CEffectScriptManFiii(...);
extern "C" s32 _ESM_FINISH__FP12RS_STACKDATAi_0027E4C0(RS_STACKDATA *arg0, s32 arg1) {
    s32 temp_s0;
    RS_STACKDATA *next = (RS_STACKDATA *) ((u8 *) arg0 + 8);

    if (EventEffectScript == NULL) {
        return 0;
    }
    temp_s0 = GetStackInt__FP12RS_STACKDATA_00262DA0(arg0);
    SetScriptProgNo__16CEffectScriptManFiii(EventEffectScript, 0x12C, temp_s0, GetStackInt__FP12RS_STACKDATA_00262DA0(next));
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_002798A0", _ESM_DELETE__FP12RS_STACKDATAi_0027E520);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _ESM_SET_VECT1__FP12RS_STACKDATAi_0027E580);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _ESM_SET_VECT2__FP12RS_STACKDATAi_0027E640);
extern "C" u32 EventEffectScript;
extern "C" s32 SetScriptTargetId__16CEffectScriptManFiii(...);
extern "C" s32 _ESM_SET_TARGET_ID__FP12RS_STACKDATAi_0027E700(RS_STACKDATA *arg0, s32 arg1) {
    s32 temp_s0;
    s32 temp_s1_2;
    s32 ret;

    if (EventEffectScript == NULL) {
        return 0;
    }
    switch (arg1) {
    case 1:
        ret = SetScriptTargetId__16CEffectScriptManFiii(EventEffectScript, GetStackInt__FP12RS_STACKDATA_00262DA0(arg0), -1, -1);
        break;
    case 3:
        temp_s0 = GetStackInt__FP12RS_STACKDATA_00262DA0(arg0++);
        temp_s1_2 = GetStackInt__FP12RS_STACKDATA_00262DA0(arg0++);
        ret = SetScriptTargetId__16CEffectScriptManFiii(EventEffectScript, GetStackInt__FP12RS_STACKDATA_00262DA0(arg0), temp_s0, temp_s1_2);
        break;
    default:
        ret = 0;
        break;
    }
    return ret;
}
INCLUDE_ASM("nonmatchings/game/text_002798A0", _ESM_LOAD_BASE_PACK__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _ESM_SET_VALUE__FP12RS_STACKDATAi_0027E840);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _SET_CHARA_CONDITION__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _ADD_WHP__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _ADD_HP_RATE__FP12RS_STACKDATAi);
struct EventScene_champs_bcd459 {
    char pad0[0x2F6C];
    /* 0x2F6C */ s32 unk2F6C;
};
extern "C" s32 _GET_TIME__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    SetStack__FP12RS_STACKDATAf_00262E90(arg0, *(f32 *) &((struct EventScene_champs_bcd459 *) EventScene)->unk2F6C);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_002798A0", _CHECK_GET_ITEM_LIMIT__FP12RS_STACKDATAi);
extern "C" s32 CheckItemOver__Fv(void);
extern "C" s32 _CHECK_ITEM_OVER__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    arg1 = CheckItemOver__Fv();
    SetStack__FP12RS_STACKDATAi_00262E70(arg0, arg1);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_002798A0", _GET_NOW_LOOP_NO__FP12RS_STACKDATAi);
extern "C" u32 EventScene;
#include "dngfloormanager.hpp"
extern "C" s32 IsClearMostFastDestroy__16CDngFloorManagerFv(void *);
extern "C" s32 _IS_CLEAR_DESTROY__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    CDngFloorManager *temp_a0;
    s32 temp_v0;

    temp_v0 = EventScene + 0x2F90;
    if (temp_v0 == 0) {
        return 0;
    }
    temp_a0 = (CDngFloorManager *) (temp_v0 + 0x14);
    if (temp_a0 == NULL) {
        return 0;
    }
    SetStack__FP12RS_STACKDATAi_00262E70(arg0, IsClearMostFastDestroy__16CDngFloorManagerFv(temp_a0));
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_002798A0", _IS_CLEAR_PRACTICE__FP12RS_STACKDATAi);
extern "C" s32 IsPlaySubGame__16CDngFloorManagerFv(void *);
extern "C" s32 _IS_PLAY_SUB_GAME__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    CDngFloorManager *temp_a0;
    s32 temp_v0;

    temp_v0 = EventScene + 0x2F90;
    if (temp_v0 == 0) {
        return 0;
    }
    temp_a0 = (CDngFloorManager *) (temp_v0 + 0x14);
    if (temp_a0 == NULL) {
        return 0;
    }
    SetStack__FP12RS_STACKDATAi_00262E70(arg0, IsPlaySubGame__16CDngFloorManagerFv(temp_a0));
    return 1;
}
extern "C" s32 GetSaveData__Fv(void);
struct temp_s0_champs_eb8f9c {
    char pad0[0x90];
    /* 0x90 */ s64 unk90;
};
struct temp_v0_champs_eb8f9c {
    char pad0[0x1A00];
    /* 0x1A00 */ u32 unk1A00;
};
extern "C" s32 _RESET_SUBJECT_COUNTER__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    struct temp_s0_champs_eb8f9c *temp_s0;
    struct temp_v0_champs_eb8f9c *temp_v0;

    temp_s0 = (struct temp_s0_champs_eb8f9c *) (EventScene + 0x2F90);
    if (temp_s0 == NULL) {
        return 0;
    }
    temp_v0 = (struct temp_v0_champs_eb8f9c *) (GetSaveData__Fv());
    if (temp_v0 == NULL) {
        return 0;
    }
    temp_s0->unk90 = temp_v0->unk1A00;
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_002798A0", _SCR_EFF_INIT_RASTER__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _SCR_EFF_START_RASTER__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _SCR_EFF_STOP_RASTER__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _SET_MPCHARA_MOTION__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _FUNC_POINT_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _PARTS_NAME_STRCMP__FP12RS_STACKDATAi);
extern "C" s32 _GET_TRIAL_VERSION__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    SetStack__FP12RS_STACKDATAi_00262E70(arg0, 0);
    return 1;
}
extern "C" u8 StartupEpisodeTitle[24];
extern "C" s32 GetStackInt__FP12RS_STACKDATA_00262DA0(...);
extern "C" s32 Switch__20CStartupEpisodeTitleFi(void *, s32);
extern "C" s32 _SET_FLOOR_EPISODE__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    Switch__20CStartupEpisodeTitleFi(&StartupEpisodeTitle, GetStackInt__FP12RS_STACKDATA_00262DA0(arg0));
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_002798A0", _FUNC_POINT_GET_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _FUNC_POINT_GET_ROT__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _ACTCHR_SET_DEF_MOTION__FP12RS_STACKDATAi);
struct SaveData_champs_ce {
    char pad0[0x1D2A0];
    char manager;
};
extern "C" s32 AddFusionPoint__16CUserDataManagerFiii(void *, s32, s32, s32);
extern "C" s32 GetSaveData__Fv(void);
extern "C" s32 _ADD_FUSION_POINT__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    s32 temp_s0;
    s32 temp_s1_2;
    s32 temp_s2;
    CUserDataManager *var_s3;
    struct SaveData_champs_ce *temp_v0;

    temp_s0 = (s32) (GetStackInt__FP12RS_STACKDATA_00262DA0(arg0++));
    temp_s1_2 = (s32) (GetStackInt__FP12RS_STACKDATA_00262DA0(arg0++));
    temp_s2 = (s32) (GetStackInt__FP12RS_STACKDATA_00262DA0(arg0));
    if ((temp_s0 < 0) || (temp_s0 > 1)) {
        return 0;
    }
    if ((temp_s1_2 < 0) || (var_s3 = NULL, (temp_s1_2 > 1))) {
        return 0;
    }
    temp_v0 = (struct SaveData_champs_ce *) GetSaveData__Fv();
    if (temp_v0 != 0) {
        var_s3 = (CUserDataManager *) &temp_v0->manager;
    }
    if (var_s3 == NULL) {
        return 0;
    }
    AddFusionPoint__16CUserDataManagerFiii(var_s3, temp_s0, temp_s1_2, temp_s2);
    return 1;
}
extern "C" s32 _GET_DEBUG_FLAG__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    if (arg1 != 1) return 0;
    return SetStack__FP12RS_STACKDATAi_00262E70(arg0, DebugFlag);
}
INCLUDE_ASM("nonmatchings/game/text_002798A0", _MINIMAP_DOOR_ENABLE__FP12RS_STACKDATAi);
struct temp_v0_champs_afc0bc {
    char pad0[0x58];
    /* 0x58 */ s32 unk58;
};
extern "C" s32 _DNG_CHECK_BOSS_MAP__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    struct temp_v0_champs_afc0bc *temp_v0;

    if (arg1 != 1) {
        return 0;
    }
    temp_v0 = (struct temp_v0_champs_afc0bc *) (EventScene + 0x2F90);
    if (temp_v0 == NULL) {
        return 0;
    }
    SetStack__FP12RS_STACKDATAi_00262E70(arg0, temp_v0->unk58);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_002798A0", _DNG_RUN_EVENT__FP12RS_STACKDATAi);
struct inferred;
struct RS_STACKDATA_infere;
typedef struct RS_STACKDATA_infere {
    /* 0x0 */ char pad0[8];
    /* 0x8 */ char unk8;                               /* inferred */
    /* 0x8 */ char pad8[1];
} RS_STACKDATA_infere;                                     /* size >= 0x9 */
extern "C" s32 CheckEnableCharaChange__16CUserDataManagerFiPi(void *, s32, s32 *);
extern "C" s32 GetSaveData__Fv(void);
extern "C" s32 _CHECK_ENABLE_CHARA_CHANGE__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    CUserDataManager *temp_a0;
    s32 temp_s0;
    struct SaveData_champs_ce *temp_v0;
    RS_STACKDATA *next;

    if (arg1 != 2) {
        return 0;
    }
    next = (RS_STACKDATA *) ((u8 *) arg0 + 8);
    temp_s0 = (s32) (GetStackInt__FP12RS_STACKDATA_00262DA0(arg0));
    temp_v0 = (struct SaveData_champs_ce *) GetSaveData__Fv();
    if (temp_v0 == 0) {
        return 0;
    }
    temp_a0 = (CUserDataManager *) &temp_v0->manager;
    if (temp_a0 == NULL) {
        return 0;
    }
    SetStack__FP12RS_STACKDATAi_00262E70(next, CheckEnableCharaChange__16CUserDataManagerFiPi(temp_a0, temp_s0, NULL));
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_002798A0", _INIT_SEPIA__FP12RS_STACKDATAi);
