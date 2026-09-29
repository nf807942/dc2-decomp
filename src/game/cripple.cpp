/* CRipple, CRainDrop, CParticle, CObject
 *
 * Unité découpée par `make carve` : 75 fonctions, 24812 octets, de
 * 0x0027FCE0 à 0x00285F50. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

struct RS_STACKDATA;
extern "C" u8 EventScreenEffect[76];
extern "C" s32 CaptureSepiaScreen__13CScreenEffectFv(void *);
extern "C" s32 SetSepiaFlag__13CScreenEffectFi(void *, s32);
extern "C" s32 _START_SEPIA__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    CaptureSepiaScreen__13CScreenEffectFv(&EventScreenEffect);
    SetSepiaFlag__13CScreenEffectFi(&EventScreenEffect, 1);
    return 1;
}
extern "C" s32 _END_SEPIA__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    SetSepiaFlag__13CScreenEffectFi(&EventScreenEffect, 0);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/cripple", _COPY_MONS2SCNCHR__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/cripple", __ct__7CObjectFRC7CObject);
struct RS_STACKDATA;
struct CScene;
extern "C" CScene *EventScene;
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
extern "C" s32 GetStack__6CSceneFi(void *, s32);
struct temp_v0_champs {
    char pad0[0x1C];
    /* 0x1C */ s32 unk1C;
};
extern "C" s32 GetStackInt__FP12RS_STACKDATA_00262DA0(RS_STACKDATA *);
extern "C" s32 _UNLOCK_STACK__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    struct temp_v0_champs *temp_v0;

    temp_v0 = (struct temp_v0_champs *) (GetStack__6CSceneFi(EventScene, GetStackInt__FP12RS_STACKDATA_00262DA0(arg0)));
    if (temp_v0 == NULL) {
        return 0;
    }
    temp_v0->unk1C = 0;
    return 1;
}
INCLUDE_ASM("nonmatchings/game/cripple", _RESET_EVENT_TRG__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/cripple", _SET_CHARA_NO__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/cripple", _GET_CHARA_NO__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/cripple", _SEARCH_CHARA_NO__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/cripple", _GET_NEAR_RANDOM_STONE_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/cripple", _INIT_MONO_FLASH__FP12RS_STACKDATAi);
extern "C" u8 EventScreenEffect[76];
#include "runscript.hpp"
extern "C" s32 CaptureMonoFlashScreen__13CScreenEffectFv(void *);
extern "C" s32 GetStackInt__FP12RS_STACKDATA_00262DA0(RS_STACKDATA *);
extern "C" s32 SetMonoFlashFlag__13CScreenEffectFii(void *, s32, s32);
extern "C" s32 _START_MONO_FLASH__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    s32 temp_s0;

    temp_s0 = (s32) (GetStackInt__FP12RS_STACKDATA_00262DA0(arg0));
    CaptureMonoFlashScreen__13CScreenEffectFv(&EventScreenEffect);
    SetMonoFlashFlag__13CScreenEffectFii(&EventScreenEffect, 1, temp_s0);
    return 1;
}
extern "C" s32 _END_MONO_FLASH__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    SetMonoFlashFlag__13CScreenEffectFii(&EventScreenEffect, 0, 0);
    return 1;
}
extern "C" s32 DeleteVillager__6CSceneFi(void *, s32);
extern "C" s32 _DELETE_VILLAGER__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    DeleteVillager__6CSceneFi(EventScene, GetStackInt__FP12RS_STACKDATA_00262DA0(arg0));
    return 1;
}
INCLUDE_ASM("nonmatchings/game/cripple", _DNG_SET_WEATHER__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/cripple", _SET_CHARA_MAXHP__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/cripple", _SET_CHARA_DEFENCE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/cripple", _PLACE_PARTS_NAME_STRCMP__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/cripple", _GOTO_USE_ITEM2__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/cripple", _DBG_SET_ANALYZE_FLAG__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/cripple", _ATRAMIRIA_ON_OFF__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/cripple", _ADD_YARIKOMI_MEDAL__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/cripple", _SET_MAP_EFFECT_ID__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/cripple", _GET_MAP_EFFECT_ID__FP12RS_STACKDATAi);
extern "C" s32 DungeonFloorInit__Fv(void);
extern "C" s32 _DNG_FLOOR_INIT__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    DungeonFloorInit__Fv();
    return 1;
}
extern "C" s32 DungeonFloorFinish__Fv(void);
extern "C" s32 _DNG_FLOOR_FINISH__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    DungeonFloorFinish__Fv();
    return 1;
}
extern "C" u8 AutoMapGen[672];
extern "C" s32 ClearRandomStone__11CAutoMapGenFv(void *);
extern "C" s32 _CLEAR_RND_STONE__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    ClearRandomStone__11CAutoMapGenFv(&AutoMapGen);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/cripple", _GET_FLOOR_STATUS__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/cripple", _SET_FLOOR_STATUS__FP12RS_STACKDATAi);
extern "C" s32 GetAttrStatus__11CAutoMapGenFPf(void *, f32 *);
extern "C" s32 GetStackVector__FPfP12RS_STACKDATA_00262E10(f32 *, RS_STACKDATA *);
extern "C" s32 SetStack__FP12RS_STACKDATAi_00262E70(...);
extern "C" s32 _AMG_GET_ATTR_STATUS__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    f32 sp20[4];

    if (arg1 != 4) {
        return 0;
    }
    GetStackVector__FPfP12RS_STACKDATA_00262E10(sp20, arg0);
    arg0 = (RS_STACKDATA *) ((u8 *) arg0 + 0x18);
    SetStack__FP12RS_STACKDATAi_00262E70(arg0, GetAttrStatus__11CAutoMapGenFPf(&AutoMapGen, sp20));
    return 1;
}
INCLUDE_ASM("nonmatchings/game/cripple", _SET_NEAR_DIST__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/cripple", _SET_KEEP_TIME__FP12RS_STACKDATAi);
struct EdEventInfo_keep {
    char pad0[0x1290];
    f32 keepTime;
    char pad1294[12];
};
extern "C" EdEventInfo_keep EdEventInfo;
extern "C" s32 SetStack__FP12RS_STACKDATAf_00262E90(RS_STACKDATA *, f32);
extern "C" s32 _GET_KEEP_TIME__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    if (arg1 != 1) {
        return 0;
    }
    return SetStack__FP12RS_STACKDATAf_00262E90(arg0, EdEventInfo.keepTime);
}
INCLUDE_ASM("nonmatchings/game/cripple", _GET_DOOR_PARTS_ID__FP12RS_STACKDATAi);
extern "C" s32 CheckEquipChange__Fi(s32);
extern "C" s32 _CHECK_EQUEP_CHANGE__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    GetStackInt__FP12RS_STACKDATA_00262DA0(arg0);
    CheckEquipChange__Fi(1);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/cripple", _ADD_HP_RATE2__FP12RS_STACKDATAi);
extern "C" u32 FxScriptMan;
extern "C" u8 LaserGun[4864];
struct MachineGunData {
    char pad0[0x380];
    s16 count;
    char pad382[0x10E];
};
extern "C" MachineGunData MachineGun;
extern "C" u8 RocketLauncher[9600];
struct MachineGunSlot {
    char pad0[0x300];
    s16 idle[8];
    char pad310[0x10];
    s16 none[8];
};
extern "C" s32 AllClearEffSpt__16CEffectScriptManFv(...);
extern "C" s32 Clear__12CLaserGunManFv(void *);
extern "C" s32 Clear__18CRocketLauncherManFv(void *);
extern "C" s32 _DNG_EFFECT_ALL_CLEAR__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    s32 var_a1;
    s32 var_a2;
    MachineGunSlot *slot;

    Clear__18CRocketLauncherManFv(&RocketLauncher);
    var_a1 = 0;
    var_a2 = 0;
    do {
        slot = (MachineGunSlot *) ((u8 *) &MachineGun + var_a2);
        var_a1 += 8;
        slot->idle[0] = 0;
        slot->none[0] = -1;
        var_a2 += 0x10;
        slot->idle[1] = 0;
        slot->none[1] = -1;
        slot->idle[2] = 0;
        slot->none[2] = -1;
        slot->idle[3] = 0;
        slot->none[3] = -1;
        slot->idle[4] = 0;
        slot->none[4] = -1;
        slot->idle[5] = 0;
        slot->none[5] = -1;
        slot->idle[6] = 0;
        slot->none[6] = -1;
        slot->idle[7] = 0;
        slot->none[7] = -1;
    } while (var_a1 < 0x10);
    MachineGun.count = 0;
    Clear__12CLaserGunManFv(&LaserGun);
    AllClearEffSpt__16CEffectScriptManFv(FxScriptMan);
    return 1;
}
extern "C" s32 AutoChangeBGMVol__6CSceneFi(void *, s32);
extern "C" s32 _AUTO_CHENGE_BGM_VOL__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    AutoChangeBGMVol__6CSceneFi(EventScene, GetStackInt__FP12RS_STACKDATA_00262DA0(arg0));
    return 1;
}
INCLUDE_ASM("nonmatchings/game/cripple", _UDATA_GET_WHP__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/cripple", _UDATA_ADD_WHP__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/cripple", _UDATA_GET_ABS__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/cripple", _UDATA_ADD_ABS__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/cripple", _DNG_CREATE_EFFECT__FP12RS_STACKDATAi);
extern "C" s32 LeaveMonicaItemCheck__Fv(void);
extern "C" s32 _LEAVE_MONICA_ITEM_CHECK__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    LeaveMonicaItemCheck__Fv();
    return 1;
}
extern "C" s32 PauseEnable__Fi(s32);
extern "C" s32 _PAUSE_ENABLE_FLAG__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    PauseEnable__Fi(GetStackInt__FP12RS_STACKDATA_00262DA0(arg0));
    return 1;
}
extern "C" s32 GetSaveData__Fv(void);
struct inferred;
typedef struct CSaveData {
    /* 0x0000 */ char pad0[0x1A14];
    /* 0x1A14 */ s32 unk1A14;                       /* inferred */
} CSaveData;                                        /* size >= 0x1A18 */
extern "C" s32 ForceBootTour__9CSaveDataFii(void *, s32, s32);
extern "C" s32 _FORCE_BOOT_TOUR__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    CSaveData *temp_v0;

    temp_v0 = (CSaveData *) (GetSaveData__Fv());
    if (temp_v0 == NULL) {
        return 0;
    }
    ForceBootTour__9CSaveDataFii(temp_v0, temp_v0->unk1A14, 1);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/cripple", SetEventFunc__FP10CRunScript);
INCLUDE_ASM("nonmatchings/game/cripple", OutPutFile__Fv);
INCLUDE_ASM("nonmatchings/game/cripple", DrawBox__FPfPfiii);
INCLUDE_ASM("nonmatchings/game/cripple", DrawBox__FPA4_fiii);
INCLUDE_ASM("nonmatchings/game/cripple", VectMatMul__FPfPfPA4_f_00282610);
INCLUDE_ASM("nonmatchings/game/cripple", evLoadDebugFont__FiP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/cripple", MoveCamera__FPfPf);
INCLUDE_ASM("nonmatchings/game/cripple", MoveCameraRef__FPfPf);
INCLUDE_ASM("nonmatchings/game/cripple", MoveChara__FP11CCharacter2P9mgCCameraP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/cripple", InitEventEdit__FiP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/cripple", ChkEventEditStart__Fv);
INCLUDE_ASM("nonmatchings/game/cripple", EventEdit__FP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/cripple", DrawEventEdit__Fv);
extern "C" s32 rand(void);
extern "C" s32 fptosi(f32);
extern "C" f32 f_rand__Fff(f32 arg0, f32 arg1) {
    return arg0 + (((arg1 - arg0) * (f32) rand()) / 2147483648.0f);
}
extern "C" s32 i_rand__Fii(s32 arg0, s32 arg1) {
    return fptosi(f_rand__Fff((f32) arg0, (f32) arg1));
}
INCLUDE_ASM("nonmatchings/game/cripple", InitVector__FPf);
INCLUDE_ASM("nonmatchings/game/cripple", RandXYinViewArea__FfffPfPf);
INCLUDE_ASM("nonmatchings/game/cripple", Birth__7CRippleFPf);
struct CRipple_step {
    s32 unk0;
    char pad4[0x20];
    s32 unk24;
    s32 unk28;
};
extern "C" s32 Step__7CRippleFv(CRipple_step *objet) {
    if (objet->unk0 == 0) {
        return 0;
    }
    objet->unk24 += 1;
    if (objet->unk24 >= objet->unk28) {
        objet->unk0 = 0;
        return -1;
    }
    return 1;
}
INCLUDE_ASM("nonmatchings/game/cripple", Draw__7CRippleFv);
extern "C" s32 InitVector__FPf(f32 *);
typedef struct CRipple {
    /* 0x00 */ s32 unk0;                            /* inferred */
    /* 0x04 */ char pad4[0xC];                      /* maybe part of unk0[4]void */
    /* 0x10 */ f32 unk10;                           /* inferred */
    /* 0x14 */ char pad14[0xC];                     /* maybe part of unk10[4]void */
    /* 0x20 */ s32 unk20;                           /* inferred */
    /* 0x24 */ s32 unk24;                           /* inferred */
    /* 0x28 */ s32 unk28;                           /* inferred */
} CRipple;                                          /* size >= 0x2C */
extern "C" void Init__7CRippleFv(CRipple *objet) {
    objet->unk0 = 0;
    InitVector__FPf(&objet->unk10);
    objet->unk20 = 0;
    objet->unk24 = 0;
    objet->unk28 = 0;
}
INCLUDE_ASM("nonmatchings/game/cripple", Birth__9CParticleFPfPf);
struct inferred;
typedef struct CParticle {
    /* 0x00 */ s32 unk0;                            /* inferred */
    /* 0x04 */ char pad4[0xC];                      /* maybe part of unk0[4]void */
    /* 0x10 */ f32 unk10;                           /* inferred */
    /* 0x14 */ f32 unk14;                           /* inferred */
    /* 0x18 */ f32 unk18;                           /* inferred */
    /* 0x1C */ char pad1C[4];
    /* 0x20 */ f32 unk20;                           /* inferred */
    /* 0x24 */ f32 unk24;                           /* inferred */
    /* 0x28 */ f32 unk28;                           /* inferred */
    /* 0x2C */ char pad2C[4];
    /* 0x30 */ f32 unk30;                           /* inferred */
    /* 0x34 */ f32 unk34;                           /* inferred */
    /* 0x38 */ f32 unk38;                           /* inferred */
    /* 0x3C */ char pad3C[4];
    /* 0x40 */ f32 unk40;                           /* inferred */
} CParticle;                                        /* size >= 0x44 */
extern "C" s32 Step__9CParticleFv(CParticle *objet) {
    if (objet->unk0 == 0) {
        return 0;
    }
    if (objet->unk14 < objet->unk40) {
        objet->unk0 = 0;
        return -1;
    }
    objet->unk20 += objet->unk30;
    objet->unk24 += objet->unk34;
    objet->unk28 += objet->unk38;
    objet->unk10 += objet->unk20;
    objet->unk14 += objet->unk24;
    objet->unk18 += objet->unk28;
    return 1;
}
INCLUDE_ASM("nonmatchings/game/cripple", Draw__9CParticleFv);
typedef struct CParticle_infere {
    /* 0x00 */ s32 unk0;                            /* inferred */
    /* 0x04 */ char pad4[0xC];                      /* maybe part of unk0[4]void */
    /* 0x10 */ f32 unk10;                           /* inferred */
    /* 0x14 */ char pad14[0xC];                     /* maybe part of unk10[4]void */
    /* 0x20 */ f32 unk20;                           /* inferred */
    /* 0x24 */ char pad24[0xC];                     /* maybe part of unk20[4]void */
    /* 0x30 */ f32 unk30;                           /* inferred */
    /* 0x34 */ char pad34[0xC];                     /* maybe part of unk30[4]void */
    /* 0x40 */ s32 unk40;                           /* inferred */
} CParticle_infere;                                        /* size >= 0x44 */
extern "C" s32 InitVector__FPf(f32 *);
extern "C" void Init__9CParticleFv(CParticle_infere *objet) {
    objet->unk0 = 0;
    InitVector__FPf(&objet->unk10);
    InitVector__FPf(&objet->unk20);
    InitVector__FPf(&objet->unk30);
    objet->unk40 = 0;
}
INCLUDE_ASM("nonmatchings/game/cripple", Birth__9CRainDropFi);
INCLUDE_ASM("nonmatchings/game/cripple", Step__9CRainDropFv);
INCLUDE_ASM("nonmatchings/game/cripple", Draw__9CRainDropFv);
struct CRainDrop_init {
    s32 unk0;
    s32 unk4;
    char pad8[0x88];
    f32 unk90;
    char pad94[0xC];
    s32 unkA0;
    s32 unkA4;
    s32 unkA8;
    s32 unkAC;
};
extern "C" void Init__9CRainDropFv(CRainDrop_init *objet) {
    s32 var_s0;
    s32 var_s1;

    var_s1 = 0;
    objet->unk0 = 0;
    var_s0 = 0;
    objet->unk4 = 0;
    do {
        InitVector__FPf((f32 *) ((u8 *) objet + var_s1 + 0x10));
        var_s0 += 1;
        var_s1 += 0x10;
    } while (var_s0 < 8);
    InitVector__FPf(&objet->unk90);
    objet->unkA0 = 0x80;
    objet->unkA4 = 0x80;
    objet->unkA8 = 0x80;
    objet->unkAC = 0x80;
}
