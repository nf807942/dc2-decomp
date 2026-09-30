/* Fonctions libres — à décrire.
 *
 * Unité découpée par `make carve` : 137 fonctions, 24568 octets, de
 * 0x001E2410 à 0x001E8790. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

#include "runscript.hpp"

INCLUDE_ASM("nonmatchings/game/text_001E2410", _SET_SCALE__FP12RS_STACKDATAi_001E2410);
INCLUDE_ASM("nonmatchings/game/text_001E2410", _SET_PALLET_ANIM__FP12RS_STACKDATAi);
struct muteki_monster;
extern muteki_monster *nowMonster;
extern "C" s32 _RESET_PALLET_ANIM__FP12RS_STACKDATAi(void *arg0, s32 arg1) {
    u8 *p = (u8 *) nowMonster;
    *(s16 *) (p + 0x686) = 0;
    *(s16 *) (p + 0x684) = 0;
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_001E2410", _CALC_IP_CIRCLE_LINE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_001E2410", _GET_POSREF_ANGLE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_001E2410", _NORMAL_VECTOR__FP12RS_STACKDATAi_001E2850);
INCLUDE_ASM("nonmatchings/game/text_001E2410", _COPY_VECTOR__FP12RS_STACKDATAi_001E28F0);
INCLUDE_ASM("nonmatchings/game/text_001E2410", _ADD_VECTOR__FP12RS_STACKDATAi_001E2970);
INCLUDE_ASM("nonmatchings/game/text_001E2410", _SUB_VECTOR__FP12RS_STACKDATAi_001E2A00);
INCLUDE_ASM("nonmatchings/game/text_001E2410", _SCALE_VECTOR__FP12RS_STACKDATAi_001E2A90);
INCLUDE_ASM("nonmatchings/game/text_001E2410", _DIV_VECTOR__FP12RS_STACKDATAi_001E2AF0);
INCLUDE_ASM("nonmatchings/game/text_001E2410", _ANGLE_CMP__FP12RS_STACKDATAi_001E2BA0);
INCLUDE_ASM("nonmatchings/game/text_001E2410", _ANGLE_LIMIT__FP12RS_STACKDATAi_001E2C00);
INCLUDE_ASM("nonmatchings/game/text_001E2410", _GET_TARGET_OLD_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_001E2410", _GET_TARGET_SPEED__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_001E2410", _CALC_MOVE_NEXT_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_001E2410", _GET_MONSTER_LIFE__FP12RS_STACKDATAi);
struct monster_stats {
    char pad0[0x6A];
    s8 unk6A;
};
struct muteki_monster {
    char pad0[0x768];
    s32 unk768;
    char pad76C[0x10];
    s32 unk77C;
    char pad780[0x114C - 0x780];
    struct monster_stats *unk114C;
    char pad1150[0x12F0 - 0x1150];
    s16 unk12F0;
    char pad12F2[0x131C - 0x12F2];
    f32 unk131C;
    char pad1320[0x1356 - 0x1320];
    s16 unk1356;
};
extern muteki_monster *nowMonster;
extern "C" s32 SetStack__FP12RS_STACKDATAi_001E1BE0(RS_STACKDATA *, s32);
extern "C" s32 _GET_NO_DAMAGE_CNT__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    SetStack__FP12RS_STACKDATAi_001E1BE0(arg0, nowMonster->unk1356);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_001E2410", _GET_ACTIVE_MONS_LIFEI__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_001E2410", _GET_ACTIVE_MONS_LIFEF__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_001E2410", _SET_ACTIVE_MONS_LIFEI__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_001E2410", _SET_ACTIVE_MONS_LIFEF__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_001E2410", _GET_ACTIVE_MONS_MAX_LIFE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_001E2410", _SET_DAMAGE_SCORE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_001E2410", _GET_MONS_GRADE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_001E2410", _SET_ESCAPE_RATE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_001E2410", _SET_GUARD_RATE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_001E2410", _SET_EXT_PARAM_RATE__FP12RS_STACKDATAi);
extern muteki_monster *nowMonster;
extern "C" s32 SetStack__FP12RS_STACKDATAi_001E1BE0(RS_STACKDATA *, s32);
extern "C" s32 _GET_BOSS_FLAG__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    if (arg1 != 1) {
        return 0;
    }
    SetStack__FP12RS_STACKDATAi_001E1BE0(arg0, nowMonster->unk114C->unk6A);
    return 1;
}
extern "C" u32 nowScene_0037D4E4;
struct temp_v0_champs {
    char pad0[0x10];
    /* 0x10 */ s32 unk10;
};
extern "C" s32 _RESET_TIMER__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    struct temp_v0_champs *temp_v0;

    temp_v0 = (struct temp_v0_champs *) (nowScene_0037D4E4 + 0x2F90);
    if (temp_v0 == NULL) {
        return 0;
    }
    temp_v0->unk10 = 0;
    return 1;
}
extern "C" s32 SetStack__FP12RS_STACKDATAi_001E1BE0(RS_STACKDATA *, s32);
extern "C" s32 _GET_TIMER__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    struct temp_v0_champs *temp_v0;

    temp_v0 = (struct temp_v0_champs *) (nowScene_0037D4E4 + 0x2F90);
    if (temp_v0 == NULL) {
        return 0;
    }
    SetStack__FP12RS_STACKDATAi_001E1BE0(arg0, temp_v0->unk10);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_001E2410", _GET_FRAME_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_001E2410", _MY_SE_PLAY__FP12RS_STACKDATAi);
extern "C" s32 GetStackInt__FP12RS_STACKDATA_001E1B60(RS_STACKDATA *);
extern "C" s32 sndSeStop__FUiii(u32, s32, s32);
extern "C" s32 _MY_SE_STOP__FP12RS_STACKDATAi(RS_STACKDATA *stack,s32 unused) { s32 id=GetStackInt__FP12RS_STACKDATA_001E1B60(stack); sndSeStop__FUiii(*(u32*)((char*)nowMonster+0x588),id,0); return 1; }
INCLUDE_ASM("nonmatchings/game/text_001E2410", _GET_EVENT_INFO__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_001E2410", _ESM_ALL_CLEAR__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_001E2410", _GET_ANGLE_INNER__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_001E2410", _CAMERA_QUAKE__FP12RS_STACKDATAi_001E3A90);
struct temp_v1_champs_99cdcc {
    char pad0[0x54];
    /* 0x54 */ s32 unk54;
};
extern "C" s32 GetStackInt__FP12RS_STACKDATA_001E1B60(RS_STACKDATA *);
extern "C" s32 _SET_CAMERA_MODE__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    s32 temp_v0;
    struct temp_v1_champs_99cdcc *temp_v1;

    temp_v0 = (s32) (GetStackInt__FP12RS_STACKDATA_001E1B60(arg0));
    temp_v1 = (struct temp_v1_champs_99cdcc *) (nowScene_0037D4E4 + 0x2F90);
    if (temp_v1 == NULL) {
        return 0;
    }
    temp_v1->unk54 = temp_v0;
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_001E2410", _SET_CAMERA_SPEED__FP12RS_STACKDATAi_001E3B40);
INCLUDE_ASM("nonmatchings/game/text_001E2410", _SET_CAMERA_CTRL_PARAM1__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_001E2410", _SET_CAMERA_CTRL_PARAM2__FP12RS_STACKDATAi);
extern "C" s32 GetCamera__6CSceneFi(...);
extern "C" s32 GetActiveParam__14CCameraControlFv(...);
struct inferred;
struct CScene;
typedef struct CScene {
    /* 0x0000 */ char pad0[0x2E54];
    /* 0x2E54 */ s32 unk2E54;                       /* inferred */
} CScene;                                           /* size >= 0x2E58 */
struct nowScene_0037D4E4_champs_18dd10 {
    char pad0[0x2E54];
    /* 0x2E54 */ s32 unk2E54;
};
struct temp_v0_champs_18dd10 {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ s32 unk8;
    /* 0xC */ s32 unkC;
    /* 0x10 */ s32 unk10;
    /* 0x14 */ s32 unk14;
    /* 0x18 */ s32 unk18;
    /* 0x1C */ s32 unk1C;
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
};
extern "C" s32 _RESET_CAMERA_CTRL_PARAM__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    struct temp_v0_champs_18dd10 *temp_v0;

    temp_v0 = (struct temp_v0_champs_18dd10 *) (GetActiveParam__14CCameraControlFv(GetCamera__6CSceneFi(nowScene_0037D4E4, ((struct nowScene_0037D4E4_champs_18dd10 *) nowScene_0037D4E4)->unk2E54)));
    temp_v0->unk0 = 0x42C80000;
    temp_v0->unk4 = 0x43200000;
    temp_v0->unk8 = 0x41900000;
    temp_v0->unkC = 0x41200000;
    temp_v0->unk14 = 0x42200000;
    temp_v0->unk18 = 0xC1700000;
    temp_v0->unk1C = 0x41A00000;
    temp_v0->unk20 = 0xC1700000;
    temp_v0->unk10 = 0xC1700000;
    temp_v0->unk24 = 0x41C80000;
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_001E2410", _GET_RND__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_001E2410", _GET_RNDF__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_001E2410", _V_PUSH__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_001E2410", _V_POP__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_001E2410", _V_PUSH2__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_001E2410", _V_POP2__FP12RS_STACKDATAi);
extern "C" s32 GetStackInt__FP12RS_STACKDATA_001E1B60(RS_STACKDATA *);
extern "C" s32 _SET_LOCKON_MODE__FP12RS_STACKDATAi(RS_STACKDATA *s,int mode) { if(mode!=1) return 0; s16 v=(s16)GetStackInt__FP12RS_STACKDATA_001E1B60(s); *(s16*)((char*)nowScene_0037D4E4+0x302E)=v; return 1; }
INCLUDE_ASM("nonmatchings/game/text_001E2410", _GET_MONSTER_NUM__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_001E2410", _GET_DIST__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_001E2410", _SET_OBJ__FP12RS_STACKDATAi_001E4730);
extern "C" u8 _1728_0036D340[23];
extern "C" void printf(void *);
extern "C" s32 _SET_BODY__FP12RS_STACKDATAi_001E4780(void) {
    printf(&_1728_0036D340);
    return 1;
}
extern "C" u8 _1733_0036D360[22];
extern "C" void printf(void *);
extern "C" s32 _SET_DMG__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    printf(&_1733_0036D360);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_001E2410", _SET_DMG2__FP12RS_STACKDATAi_001E47E0);
INCLUDE_ASM("nonmatchings/game/text_001E2410", _GET_OBJ_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_001E2410", _GET_MAPOBJ_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_001E2410", _LINK_MAP_TO_OBJECT__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_001E2410", _LINK_OBJECT_TO_PIECE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_001E2410", _SET_SCOOP__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_001E2410", _LOAD_RESERV_IMG__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_001E2410", _SET_PRIORITY_LIMMIT__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_001E2410", _GET_PLACE_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_001E2410", _SET_PLACE_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_001E2410", _SEARCH_AREA__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_001E2410", _SEARCH_AREA2__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_001E2410", _SET_MODEL_LIGHT_SWITCH__FP12RS_STACKDATAi_001E5160);
INCLUDE_ASM("nonmatchings/game/text_001E2410", _SET_MODEL_LIGHT_COLOR__FP12RS_STACKDATAi_001E5240);
INCLUDE_ASM("nonmatchings/game/text_001E2410", _SET_DEF_RATE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_001E2410", _GET_POS__FP12RS_STACKDATAi_001E53B0);
INCLUDE_ASM("nonmatchings/game/text_001E2410", _SET_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_001E2410", _GET_ROT__FP12RS_STACKDATAi_001E5490);
INCLUDE_ASM("nonmatchings/game/text_001E2410", _SET_ROT__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_001E2410", _SET_NEXT_ROT__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_001E2410", _SET_NEXT_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_001E2410", _CHK_MOVE_END__FP12RS_STACKDATAi);
extern "C" s32 _RESET_MOVE__FP12RS_STACKDATAi(RS_STACKDATA *a, s32 b) {
    *(s32 *) ((u8 *) nowMonster + 0x1480) = 0;
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_001E2410", _GET_TARGET_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_001E2410", _GET_TARGET_DIST__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_001E2410", _GET_TARGET_ANGLE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_001E2410", _GET_TARGET_REF_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_001E2410", _GET_REF_DIR__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_001E2410", _GET_REFANGLE_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_001E2410", _GET_REF_ANGLE__FP12RS_STACKDATAi_001E5E90);
INCLUDE_ASM("nonmatchings/game/text_001E2410", _GET_HIGH__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_001E2410", _GET_ACTIVE_MONS_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_001E2410", _GET_ACTIVE_MONS_ROT__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_001E2410", _GET_ACTIVE_MONS_DIST__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_001E2410", _GET_ACTIVE_MONS_ANGLE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_001E2410", _GET_REF_ROT__FP12RS_STACKDATAi_001E6260);
INCLUDE_ASM("nonmatchings/game/text_001E2410", _GET_REF_ROT2__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_001E2410", _FLYING_SEARCH_AREA__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_001E2410", _GET_HIGH2__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_001E2410", _GET_RANGE_MONS_ID__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_001E2410", _GET_ENTRY_OBJ_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_001E2410", _BLOW_START__FP12RS_STACKDATAi_001E6940);
extern muteki_monster *nowMonster;
extern "C" s32 _SET_ACT_STATUS__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    if (arg1 != 1) {
        return 0;
    }
    nowMonster->unk77C = GetStackInt__FP12RS_STACKDATA_001E1B60(arg0);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_001E2410", _SET_INT_FLAG__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_001E2410", _SET_DEAD_START__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_001E2410", _SET_DEAD_OFF__FP12RS_STACKDATAi);
extern "C" s32 _SET_SHROW_END__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    if (arg1 != 0) return 0;
    *(s16 *)((u8 *)nowMonster + 0x730) = 0;
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_001E2410", _SET_MOS__FP12RS_STACKDATAi_001E7410);
INCLUDE_ASM("nonmatchings/game/text_001E2410", _CHECK_MOS_END__FP12RS_STACKDATAi_001E7500);
INCLUDE_ASM("nonmatchings/game/text_001E2410", _NOW_MOS_WAIT__FP12RS_STACKDATAi_001E75A0);
INCLUDE_ASM("nonmatchings/game/text_001E2410", _GET_MOS_STATUS__FP12RS_STACKDATAi_001E7630);
extern muteki_monster *nowMonster;
extern "C" s32 _SET_MUTEKI__FP12RS_STACKDATAi_001E76D0(RS_STACKDATA *arg0, s32 arg1) {
    if (arg1 != 1) {
        return 1;
    }
    nowMonster->unk768 = GetStackInt__FP12RS_STACKDATA_001E1B60(arg0);
    return 1;
}
extern "C" s32 SetStack__FP12RS_STACKDATAf_001E1C00(RS_STACKDATA *, f32);
extern "C" s32 _GET_GEKIRIN__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    if (arg1 != 1) {
        return 0;
    }
    SetStack__FP12RS_STACKDATAf_001E1C00(arg0, nowMonster->unk131C);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_001E2410", _GET_USER_MONS_ID__FP12RS_STACKDATAi);
extern "C" s32 _GET_PRIORITY__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    if (arg1 != 1) {
        return 0;
    }
    SetStack__FP12RS_STACKDATAi_001E1BE0(arg0, nowMonster->unk12F0);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_001E2410", _CREATE_MONSTER__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_001E2410", _SET_CLIP_DIST__FP12RS_STACKDATAi);
s32 _SET_COLLISION(RS_STACKDATA *stack, int argc) {
    return 0;
}
s32 _SET_GRAVITY(RS_STACKDATA *stack, int argc) {
    return 0;
}
INCLUDE_ASM("nonmatchings/game/text_001E2410", _SET_ATTRIB__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_001E2410", _GET_SCALE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_001E2410", _GET_MONS_WIDTH__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_001E2410", _ESM_CREATE__FP12RS_STACKDATAi_001E7B10);
INCLUDE_ASM("nonmatchings/game/text_001E2410", _ESM_FINISH__FP12RS_STACKDATAi_001E7BC0);
INCLUDE_ASM("nonmatchings/game/text_001E2410", _ESM_DELETE__FP12RS_STACKDATAi_001E7C10);
INCLUDE_ASM("nonmatchings/game/text_001E2410", _ESM_SET_VECT1__FP12RS_STACKDATAi_001E7C60);
INCLUDE_ASM("nonmatchings/game/text_001E2410", _ESM_GET_VECT1__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_001E2410", _ESM_SET_VECT2__FP12RS_STACKDATAi_001E7D70);
INCLUDE_ASM("nonmatchings/game/text_001E2410", _ESM_GET_VECT2__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_001E2410", _ESM_SET_TARGET_ID__FP12RS_STACKDATAi_001E7E90);
INCLUDE_ASM("nonmatchings/game/text_001E2410", _ESM_GET_TARGET_ID__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_001E2410", _ESM_SET_USER_ID__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_001E2410", _ESM_GET_USER_ID__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_001E2410", _ESM_SET_VALUE__FP12RS_STACKDATAi_001E8010);
INCLUDE_ASM("nonmatchings/game/text_001E2410", _LOAD_EFFECT_SCRIPT__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_001E2410", _SW_EFFECT__FP12RS_STACKDATAi_001E8250);
struct ActiveMonster_pointe;
extern "C" ActiveMonster_pointe *ActiveMonster;
struct ActiveMonster_champs_f346d5 {
    char pad0[0xFFF0];
    /* 0xFFF0 */ s32 unkFFF0;
};
extern "C" s32 GetNotUsedTexb__16CEffectScriptManFv(...);
extern "C" s32 SetStack__FP12RS_STACKDATAi_001E1BE0(RS_STACKDATA *, s32);
extern "C" s32 _ESM_GET_NOTUESD_TEXB__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    if (arg1 != 1) {
        return 0;
    }
    SetStack__FP12RS_STACKDATAi_001E1BE0(arg0, GetNotUsedTexb__16CEffectScriptManFv(((struct ActiveMonster_champs_f346d5 *) ActiveMonster)->unkFFF0));
    return 1;
}
typedef struct ActiveMonster_pointe {
    char pad0[65520];
    s32 unkFFF0;
} ActiveMonster_pointe;
extern "C" ActiveMonster_pointe *ActiveMonster;
extern "C" s32 AddTexb__16CEffectScriptManFv(...);
extern "C" s32 _ESM_ADD_TEXB__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    AddTexb__16CEffectScriptManFv(ActiveMonster->unkFFF0);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_001E2410", _SHOT_ROCKET_LAUNCHER__FP12RS_STACKDATAi);
extern "C" s32 GetStackInt__FP12RS_STACKDATA_001E1B60(RS_STACKDATA *);
extern "C" s32 _RUN_EVENT_SCRIPT__FP12RS_STACKDATAi(RS_STACKDATA *s,int mode) { if(mode!=1) return 0; s16 v=(s16)GetStackInt__FP12RS_STACKDATA_001E1B60(s); *(s16*)((char*)nowMonster+0x12E0)=v; return 1; }
INCLUDE_ASM("nonmatchings/game/text_001E2410", _SET_STATUS__FP12RS_STACKDATAi_001E8680);
INCLUDE_ASM("nonmatchings/game/text_001E2410", _SET_PAUSE__FP12RS_STACKDATAi);
