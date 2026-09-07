/* CEohMother, CScreenEffect, CRaster, CEventScriptArg
 *
 * Unité découpée par `make carve` : 122 fonctions, 24576 octets, de
 * 0x00260B80 à 0x00266E10. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"
#include "gen/EdEventInfoData.hpp"
#include "gen/CRaster.hpp"
extern EdEventInfoData EdEventInfo;


INCLUDE_ASM("nonmatchings/game/ceohmother", CalcPosWorldCoordGyaku__FPf);
extern "C" u32 SetWorldCoordFlg;
struct mgCCamera_ac1778 {
    s32 field_0;
    f32 field_4;
    f32 field_8;
    f32 field_C;
    f32 field_10;
    f32 field_14;
    f32 field_18;
    f32 field_1C;
    f32 field_20;
    f32 field_24;
    f32 field_28;
    f32 field_2C;
    f32 field_30;
    f32 field_34;
    f32 field_38;
    f32 field_3C;
    f32 field_40;
    s32 field_44;
    f32 field_48;
    f32 field_4C;
    f32 field_50;
    f32 field_54;
    f32 field_58;
    s32 field_5C;
    char pad_60[0x14];
    f32 field_74;
    f32 field_78;
    f32 field_7C;
    f32 field_80;
    f32 field_84;
    f32 field_88;
    f32 field_8C;
    f32 field_90;
    f32 field_94;
    f32 field_98;
    f32 field_9C;
    s32 field_A0;
    f32 field_A4;
    f32 field_A8;
    char pad_AC[0x4];
    f32 field_B0;
    f32 field_B4;
    f32 field_B8;
    f32 field_BC;
    char pad_C0[0x24];
    f32 field_E4;
    f32 field_E8;
    f32 field_EC;
    char pad_F0[0xB4];
    f32 field_1A4;
    f32 field_1A8;
    f32 field_1AC;
    f32 field_1B0;
    f32 field_1B4;
    f32 field_1B8;
    f32 field_1BC;
    f32 field_1C0;
    f32 field_1C4;
    f32 field_1C8;
    s32 field_1CC;
    char pad_1D0[0x4];
    f32 field_1D4;
    f32 field_1D8;
    f32 field_1DC;
};
extern "C" s32 CalcPosWorldCoord__FPf(f32 *);
extern "C" s32 GetPos__9mgCCameraFPf(void *, f32 *);
extern "C" s32 GetRef__9mgCCameraFPf(void *, f32 *);
extern "C" s32 SetPos__9mgCCameraFPf(void *, f32 *);
extern "C" s32 SetRef__9mgCCameraFPf(void *, f32 *);
extern "C" void SetCamWorldCoord__FP9mgCCamera(mgCCamera_ac1778 *arg0) {
    f32 sp20[4];
    f32 sp30[4];
    if ((SetWorldCoordFlg != 0) && (arg0 != NULL)) {
        GetPos__9mgCCameraFPf(arg0, sp20);
        GetRef__9mgCCameraFPf(arg0, sp30);
        CalcPosWorldCoord__FPf(sp20);
        CalcPosWorldCoord__FPf(sp30);
        SetPos__9mgCCameraFPf(arg0, sp20);
        SetRef__9mgCCameraFPf(arg0, sp30);
    }
}
extern "C" u32 SetWorldCoordFlg;
struct mgCCamera {
    s32 field_0;
    f32 field_4;
    f32 field_8;
    f32 field_C;
    f32 field_10;
    f32 field_14;
    f32 field_18;
    f32 field_1C;
    f32 field_20;
    f32 field_24;
    f32 field_28;
    f32 field_2C;
    f32 field_30;
    f32 field_34;
    f32 field_38;
    f32 field_3C;
    f32 field_40;
    s32 field_44;
    f32 field_48;
    f32 field_4C;
    f32 field_50;
    f32 field_54;
    f32 field_58;
    s32 field_5C;
    char pad_60[0x14];
    f32 field_74;
    f32 field_78;
    f32 field_7C;
    f32 field_80;
    f32 field_84;
    f32 field_88;
    f32 field_8C;
    f32 field_90;
    f32 field_94;
    f32 field_98;
    f32 field_9C;
    s32 field_A0;
    f32 field_A4;
    f32 field_A8;
    char pad_AC[0x4];
    f32 field_B0;
    f32 field_B4;
    f32 field_B8;
    f32 field_BC;
    char pad_C0[0x24];
    f32 field_E4;
    f32 field_E8;
    f32 field_EC;
    char pad_F0[0xB4];
    f32 field_1A4;
    f32 field_1A8;
    f32 field_1AC;
    f32 field_1B0;
    f32 field_1B4;
    f32 field_1B8;
    f32 field_1BC;
    f32 field_1C0;
    f32 field_1C4;
    f32 field_1C8;
    s32 field_1CC;
    char pad_1D0[0x4];
    f32 field_1D4;
    f32 field_1D8;
    f32 field_1DC;
};
extern "C" s32 GetPos__9mgCCameraFPf(void *, f32 *);
extern "C" s32 GetRef__9mgCCameraFPf(void *, f32 *);
extern "C" s32 SetPos__9mgCCameraFPf(void *, f32 *);
extern "C" s32 SetRef__9mgCCameraFPf(void *, f32 *);
extern "C" s32 CalcPosWorldCoordGyaku__FPf(f32 *);
extern "C" void SetCamWorldCoordGyaku__FP9mgCCamera(mgCCamera *arg0) {
    /* Les emplacements de pile portent la taille que le commerce leur donne,
     * lue sur l'ecart entre deux adresses prises, et ils sont declares dans
     * l'ordre croissant de leur decalage : MWCC attribue la pile dans l'ordre
     * des declarations, m2c les ecrit a l'envers. Deux entiers a la place de
     * ces tableaux rendaient un cadre de la moitie, et l'ordre de m2c les
     * echangeait. */
    /* Les emplacements de pile portent la taille que le commerce leur donne,
     * lue sur l'ecart entre deux adresses prises, et ils sont declares dans
     * l'ordre croissant de leur decalage : MWCC attribue la pile dans
     * l'ordre des declarations, m2c les ecrit a l'envers. */
    f32 sp20[4];
    f32 sp30[4];
    if ((SetWorldCoordFlg != 0) && (arg0 != NULL)) {
        GetPos__9mgCCameraFPf(arg0, sp20);
        GetRef__9mgCCameraFPf(arg0, sp30);
        CalcPosWorldCoordGyaku__FPf(sp20);
        CalcPosWorldCoordGyaku__FPf(sp30);
        SetPos__9mgCCameraFPf(arg0, sp20);
        SetRef__9mgCCameraFPf(arg0, sp30);
    }
}
INCLUDE_ASM("nonmatchings/game/ceohmother", __ct__10CEohMotherFv);
INCLUDE_ASM("nonmatchings/game/ceohmother", Set__10CEohMotherFiiP7CObjecti);
INCLUDE_ASM("nonmatchings/game/ceohmother", Set__10CEohMotherFiiiP11CCharacter2);
INCLUDE_ASM("nonmatchings/game/ceohmother", Set__10CEohMotherFiiP13CEventSprite2);
INCLUDE_ASM("nonmatchings/game/ceohmother", Set__10CEohMotherFiiP8mgCFrame);
INCLUDE_ASM("nonmatchings/game/ceohmother", Set__10CEohMotherFiiP10CFuncPoint);
INCLUDE_ASM("nonmatchings/game/ceohmother", SetPos__10CEohMotherFifff);
INCLUDE_ASM("nonmatchings/game/ceohmother", SetRot__10CEohMotherFifff);
INCLUDE_ASM("nonmatchings/game/ceohmother", GetPos__10CEohMotherFiPf);
INCLUDE_ASM("nonmatchings/game/ceohmother", GetRot__10CEohMotherFiPf);
INCLUDE_ASM("nonmatchings/game/ceohmother", SetMotion__10CEohMotherFiPcif);
INCLUDE_ASM("nonmatchings/game/ceohmother", CheckMotionEnd__10CEohMotherFi);
INCLUDE_ASM("nonmatchings/game/ceohmother", SetMotionTrg__10CEohMotherFi);
INCLUDE_ASM("nonmatchings/game/ceohmother", GetSeqStatus__10CEohMotherFi);
INCLUDE_ASM("nonmatchings/game/ceohmother", SetStep__10CEohMotherFif);
INCLUDE_ASM("nonmatchings/game/ceohmother", SetChangeStep__10CEohMotherFif);
INCLUDE_ASM("nonmatchings/game/ceohmother", ResetMotion__10CEohMotherFi);
INCLUDE_ASM("nonmatchings/game/ceohmother", SetTexAnim__10CEohMotherFiiPc);
INCLUDE_ASM("nonmatchings/game/ceohmother", SetScale__10CEohMotherFifff);
INCLUDE_ASM("nonmatchings/game/ceohmother", GetScale__10CEohMotherFiPf);
INCLUDE_ASM("nonmatchings/game/ceohmother", SetShow__10CEohMotherFii);
INCLUDE_ASM("nonmatchings/game/ceohmother", GetShow__10CEohMotherFiPi);
INCLUDE_ASM("nonmatchings/game/ceohmother", SearchFrame__10CEohMotherFiPc);
INCLUDE_ASM("nonmatchings/game/ceohmother", SetFrameShow__10CEohMotherFiPci);
INCLUDE_ASM("nonmatchings/game/ceohmother", SetShadow__10CEohMotherFii);
INCLUDE_ASM("nonmatchings/game/ceohmother", SetShadowFrameShow__10CEohMotherFiPci);
INCLUDE_ASM("nonmatchings/game/ceohmother", SetTranslate__10CEohMotherFiPf);
INCLUDE_ASM("nonmatchings/game/ceohmother", SetColor__10CEohMotherFiPf);
INCLUDE_ASM("nonmatchings/game/ceohmother", GetColor__10CEohMotherFiPf);
INCLUDE_ASM("nonmatchings/game/ceohmother", GetNowMotionName__10CEohMotherFi);
INCLUDE_ASM("nonmatchings/game/ceohmother", GetNowMotionStatus__10CEohMotherFi);
INCLUDE_ASM("nonmatchings/game/ceohmother", SetMotionNowTime__10CEohMotherFif);
INCLUDE_ASM("nonmatchings/game/ceohmother", SetMotionWaitTime__10CEohMotherFif);
INCLUDE_ASM("nonmatchings/game/ceohmother", SetFootSoundID__10CEohMotherFii);
INCLUDE_ASM("nonmatchings/game/ceohmother", GetFramePos__10CEohMotherFiPcPf);
INCLUDE_ASM("nonmatchings/game/ceohmother", SetSoundID__10CEohMotherFiUi);
INCLUDE_ASM("nonmatchings/game/ceohmother", GetFrameShow__10CEohMotherFiPc);
INCLUDE_ASM("nonmatchings/game/ceohmother", SetFadeFlag__10CEohMotherFii);
INCLUDE_ASM("nonmatchings/game/ceohmother", ResetDAPosition__10CEohMotherFi);
INCLUDE_ASM("nonmatchings/game/ceohmother", NormalDrive__10CEohMotherFi);
INCLUDE_ASM("nonmatchings/game/ceohmother", UpdatePosition__10CEohMotherFi);
INCLUDE_ASM("nonmatchings/game/ceohmother", SetFrameObjAlpha__10CEohMotherFiPcf);
INCLUDE_ASM("nonmatchings/game/ceohmother", SetFootSeId__10CEohMotherFii);
INCLUDE_ASM("nonmatchings/game/ceohmother", FileNameConvLanguage__FPc);
INCLUDE_ASM("nonmatchings/game/ceohmother", GetStackInt__FP12RS_STACKDATA_00262DA0);
INCLUDE_ASM("nonmatchings/game/ceohmother", GetStackFloat__FP12RS_STACKDATA_00262DE0);
INCLUDE_ASM("nonmatchings/game/ceohmother", GetStackVector__FPfP12RS_STACKDATA_00262E10);
INCLUDE_ASM("nonmatchings/game/ceohmother", GetStackString__FP12RS_STACKDATA_00262E60);
INCLUDE_ASM("nonmatchings/game/ceohmother", SetStack__FP12RS_STACKDATAi_00262E70);
INCLUDE_ASM("nonmatchings/game/ceohmother", SetStack__FP12RS_STACKDATAf_00262E90);
INCLUDE_ASM("nonmatchings/game/ceohmother", BuildArgData__15CEventScriptArgFPUi);
INCLUDE_ASM("nonmatchings/game/ceohmother", _DATA__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/ceohmother", _ID_OFFSET__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/ceohmother", GetArgInt__FP8ARG_DATA);
INCLUDE_ASM("nonmatchings/game/ceohmother", GetArgFloat__FP8ARG_DATA);
extern "C" u8 _1357_00371B30[32];
struct inferred;
typedef struct ARG_DATA {
    /* 0x0 */ char pad0[4];
    /* 0x4 */ s32 unk4;                             /* inferred */
} ARG_DATA;                                         /* size >= 0x8 */
extern "C" s32 printf(...);
extern "C" s32 GetArgString__FP8ARG_DATA(ARG_DATA *arg0) {
    if (arg0 == NULL) {
        printf(&_1357_00371B30);
        return 0;
    }
    return arg0->unk4;
}
INCLUDE_ASM("nonmatchings/game/ceohmother", GetArgVector__FPfP8ARG_DATA);
void CRaster::Initialize(void) {
    this->field_0x0 = 0;
    this->field_0x8 = 0;
    this->field_0x4 = 0;
    this->field_0x10 = 0;
    this->field_0xC = 0;
    this->field_0x18 = 0;
    this->field_0x14 = 0;
    this->field_0x20 = 0;
    this->field_0x1C = 0;
    this->field_0x24 = -1;
    this->field_0x28 = 0;
}
INCLUDE_ASM("nonmatchings/game/ceohmother", SetParam__7CRasterFfff);
INCLUDE_ASM("nonmatchings/game/ceohmother", StartRaster__7CRasterFfffi);
typedef struct CRaster_infere {
    /* 0x00 */ s32 unk0;                            /* inferred */
    /* 0x04 */ f32 unk4;                            /* inferred */
    /* 0x08 */ f32 unk8;                            /* inferred */
    /* 0x0C */ f32 unkC;                            /* inferred */
    /* 0x10 */ f32 unk10;                           /* inferred */
    /* 0x14 */ f32 unk14;                           /* inferred */
    /* 0x18 */ f32 unk18;                           /* inferred */
    /* 0x1C */ char pad1C[8];                       /* maybe part of unk18[3]void */
    /* 0x24 */ s32 unk24;                           /* inferred */
    /* 0x28 */ s32 unk28;                           /* inferred */
} CRaster_infere;                                          /* size >= 0x2C */
extern "C" void StopRaster__7CRasterFfffi(CRaster_infere *objet, f32 arg0, f32 arg1, f32 arg2, s32 arg3) {
    objet->unk24 = arg3;
    objet->unk28 = 0;
    if (objet->unk24 > 1) {
        objet->unk0 = 3;
        if (arg0 != -1.0f) {
            objet->unk8 = (arg0 - objet->unk4) / (f32) objet->unk24;
        } else {
            objet->unk8 = 0.0f;
        }
        if (arg1 != -1.0f) {
            objet->unk10 = (arg1 - objet->unkC) / (f32) objet->unk24;
        } else {
            objet->unk10 = 0.0f;
        }
        if (arg2 != -1.0f) {
            objet->unk18 = (arg2 - objet->unk14) / (f32) objet->unk24;
            return;
        }
        objet->unk18 = 0.0f;
        return;
    }
    if (arg0 != -1.0f) {
        objet->unk4 = arg0;
    }
    if (arg1 != -1.0f) {
        objet->unkC = arg1;
    }
    if (arg2 != -1.0f) {
        objet->unk14 = arg2;
    }
    objet->unk0 = 0;
}
INCLUDE_ASM("nonmatchings/game/ceohmother", StepRaster__7CRasterFv);
INCLUDE_ASM("nonmatchings/game/ceohmother", DrawRaster__7CRasterFv);
struct inferred;
typedef struct CScreenEffect_infere {
    /* 0x00 */ char pad0[0x2C];
    /* 0x2C */ s32 unk2C;                           /* inferred */
    /* 0x30 */ s32 unk30;                           /* inferred */
    /* 0x34 */ s32 unk34;                           /* inferred */
    /* 0x38 */ s32 unk38;                           /* inferred */
    /* 0x3C */ s32 unk3C;                           /* inferred */
    /* 0x40 */ s32 unk40;                           /* inferred */
    /* 0x44 */ s32 unk44;                           /* inferred */
    /* 0x48 */ s32 unk48;                           /* inferred */
} CScreenEffect_infere;                                    /* size >= 0x4C */
extern "C" s32 Initialize__7CRasterFv(void *);
extern "C" void Initialize__13CScreenEffectFv(CScreenEffect_infere *objet) {
    Initialize__7CRasterFv((CRaster *) objet);
    objet->unk2C = 0;
    objet->unk30 = 0;
    objet->unk34 = 0;
    objet->unk38 = 0;
    objet->unk3C = 0;
    objet->unk40 = 0;
    objet->unk44 = 0;
    objet->unk48 = 0;
}
INCLUDE_ASM("nonmatchings/game/ceohmother", Step__13CScreenEffectFv);
INCLUDE_ASM("nonmatchings/game/ceohmother", Draw__13CScreenEffectFv);
struct CScreenEffect {
    char pad_0[0x30];
    s32 field_30;
    char pad_34[0x8];
    s32 field_3C;
    s32 field_40;
    s32 field_44;
    s32 field_48;
};
extern "C" s32 Initialize__7CRasterFv(void *);
extern "C" s32 SetParam__7CRasterFfff(void *, f32, f32, f32);
extern "C" void InitRaster__13CScreenEffectFfff(CScreenEffect *objet, f32 arg0, f32 arg1, f32 arg2) {
    Initialize__7CRasterFv((CRaster *) objet);
    SetParam__7CRasterFfff((CRaster *) objet, arg0, arg1, arg2);
}
INCLUDE_ASM("nonmatchings/game/ceohmother", StartRaster__13CScreenEffectFfffi);
INCLUDE_ASM("nonmatchings/game/ceohmother", StopRaster__13CScreenEffectFfffi);
INCLUDE_ASM("nonmatchings/game/ceohmother", SetSepiaTexture__13CScreenEffectFP10mgCTextureP1);
INCLUDE_ASM("nonmatchings/game/ceohmother", CaptureSepiaScreen__13CScreenEffectFv);
typedef struct CScreenEffect_infere3 {
    /* 0x00 */ char pad0[0x2C];
    /* 0x2C */ s32 unk2C;                           /* inferred */
    /* 0x30 */ s32 unk30;                           /* inferred */
} CScreenEffect_infere3;                                    /* size >= 0x34 */
extern "C" void SetSepiaFlag__13CScreenEffectFi(CScreenEffect_infere3 *objet, s32 arg0) {
    if (objet->unk2C != 0) {
        objet->unk30 = arg0;
        return;
    }
    objet->unk30 = 0;
}
INCLUDE_ASM("nonmatchings/game/ceohmother", SetMonoFlashTexture__13CScreenEffectFPP10mgCTexturePP1);
INCLUDE_ASM("nonmatchings/game/ceohmother", CaptureMonoFlashScreen__13CScreenEffectFv);
typedef struct CScreenEffect_infere2 {
    /* 0x00 */ char pad0[0x34];
    /* 0x34 */ s32 unk34;                           /* inferred */
    /* 0x38 */ s32 unk38;                           /* inferred */
    /* 0x3C */ s32 unk3C;                           /* inferred */
    /* 0x40 */ s32 unk40;                           /* inferred */
    /* 0x44 */ s32 unk44;                           /* inferred */
    /* 0x48 */ s32 unk48;                           /* inferred */
} CScreenEffect_infere2;                                    /* size >= 0x4C */
extern "C" void SetMonoFlashFlag__13CScreenEffectFii(CScreenEffect_infere2 *objet, s32 arg0, s32 arg1) {
    if ((objet->unk34 != 0) || (objet->unk38 != 0)) {
        objet->unk3C = arg0;
    } else {
        objet->unk3C = 0;
    }
    objet->unk40 = arg1;
    objet->unk44 = 0;
    objet->unk48 = 0;
}
INCLUDE_ASM("nonmatchings/game/ceohmother", InitWorldCoord__Fv);
INCLUDE_ASM("nonmatchings/game/ceohmother", GetLocalFlag__Fi);
INCLUDE_ASM("nonmatchings/game/ceohmother", SetLocalFlag__Fii);
INCLUDE_ASM("nonmatchings/game/ceohmother", GetLocalCnt__Fi);
INCLUDE_ASM("nonmatchings/game/ceohmother", SetLocalCnt__Fii);
INCLUDE_ASM("nonmatchings/game/ceohmother", GetLocalCnt2__Fi);
INCLUDE_ASM("nonmatchings/game/ceohmother", InitLocalCnt__Fv);
INCLUDE_ASM("nonmatchings/game/ceohmother", EdEventInfoCommandInitialize__Fv);
INCLUDE_ASM("nonmatchings/game/ceohmother", EventSeqInit__Fv);
INCLUDE_ASM("nonmatchings/game/ceohmother", EdEventInit__Fv);
INCLUDE_ASM("nonmatchings/game/ceohmother", EventTimeDraw__Fv);
INCLUDE_ASM("nonmatchings/game/ceohmother", EdEventDraw__Fv);
INCLUDE_ASM("nonmatchings/game/ceohmother", EdEventFirstDraw__Fv);
INCLUDE_ASM("nonmatchings/game/ceohmother", EdEventFinish__Fv);
INCLUDE_ASM("nonmatchings/game/ceohmother", EdEventStep__Fv);
void InitDramaScene(void) {
    EdEventInfo.field_0xE0 = 0;
    EdEventInfo.field_0xE4 = 0;
    EdEventInfo.field_0xD4 = 1;
    EdEventInfo.field_0xD8 = 15;
    EdEventInfo.field_0xE8 = 0;
    EdEventInfo.field_0xEC = 0;
}
void CancelDramaScene(void) {
    EdEventInfo.field_0xD4 = 0;
}
INCLUDE_ASM("nonmatchings/game/ceohmother", EdEventMenuExit__Fv);
INCLUDE_ASM("nonmatchings/game/ceohmother", EdEventLoopInit__Fv);
void EdSetBrokenObject(void) {
}
extern "C" s32 GetEventMessage__Fi(s32);
struct temp_v0_champs {
    char pad0[0x1E44];
    /* 0x1E44 */ s32 unk1E44;
    /* 0x1E48 */ s32 unk1E48;
};
extern "C" void ResetMesFileBuffAll__Fv(void) {
    s32 var_s0;
    struct temp_v0_champs *temp_v0;

    var_s0 = 0;
    do {
        temp_v0 = (struct temp_v0_champs *) (GetEventMessage__Fi(var_s0));
        if (temp_v0 != NULL) {
            temp_v0->unk1E44 = 0;
            temp_v0->unk1E48 = 0;
        }
        var_s0 += 1;
    } while (var_s0 < 8);
}
INCLUDE_ASM("nonmatchings/game/ceohmother", EdEventMapInit__Fv);
INCLUDE_ASM("nonmatchings/game/ceohmother", EdEventTermination__Fv);
extern "C" s32 EventSeqInit__Fv(void);
extern "C" void EdEventEnd__Fv(void) {
    ResetMesFileBuffAll__Fv();
    EventSeqInit__Fv();
}
INCLUDE_ASM("nonmatchings/game/ceohmother", GetObjSeq__Fi);
extern "C" u8 GamePad_003FA5A0[1144];
#include "runscript.hpp"
extern "C" s32 GetPadOn__8CGamePadFv(void *);
extern "C" s32 SetStack__FP12RS_STACKDATAi_00262E70(...);
extern "C" s32 _GET_PADON__FP12RS_STACKDATAi_00266260(s32 arg0, s32 arg1) {
    if (arg1 <= 0) {
        return 0;
    }
    SetStack__FP12RS_STACKDATAi_00262E70(arg0, GetPadOn__8CGamePadFv(&GamePad_003FA5A0));
    return 1;
}
extern "C" s32 GetPadDown__8CGamePadFv(void *);
extern "C" s32 _GET_PADDOWN__FP12RS_STACKDATAi_002662B0(s32 arg0, s32 arg1) {
    if (arg1 <= 0) {
        return 0;
    }
    SetStack__FP12RS_STACKDATAi_00262E70(arg0, GetPadDown__8CGamePadFv(&GamePad_003FA5A0));
    return 1;
}
extern "C" s32 GetPadUp__8CGamePadFv(void *);
extern "C" s32 _GET_PADUP__FP12RS_STACKDATAi_00266300(s32 arg0, s32 arg1) {
    if (arg1 <= 0) {
        return 0;
    }
    SetStack__FP12RS_STACKDATAi_00262E70(arg0, GetPadUp__8CGamePadFv(&GamePad_003FA5A0));
    return 1;
}
INCLUDE_ASM("nonmatchings/game/ceohmother", _GET_APAD__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/ceohmother", CheckLoadedBGFile__FPcPi);
INCLUDE_ASM("nonmatchings/game/ceohmother", GetLoadBGBuff__FPcPi);
INCLUDE_ASM("nonmatchings/game/ceohmother", _GOTO_INTERIOR__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/ceohmother", _GOTO_OUTSIDE__FP12RS_STACKDATAi);
extern "C" s32 GetActiveCamera__Fv(void);
struct mgCCameraFollow {
    char pad_0[0x48];
    f32 field_48;
    char pad_4C[0x4];
    f32 field_50;
    char pad_54[0x8];
    s32 field_5C;
    char pad_60[0x10];
    f32 field_70;
    f32 field_74;
    f32 field_78;
    f32 field_7C;
    f32 field_80;
    f32 field_84;
    f32 field_88;
    f32 field_8C;
    f32 field_90;
    f32 field_94;
    f32 field_98;
    f32 field_9C;
    s32 field_A0;
    char pad_A4[0xC];
    f32 field_B0;
    f32 field_B4;
    f32 field_B8;
    f32 field_BC;
    char pad_C0[0x4];
    s32 field_C4;
};
extern "C" s32 FollowOff__15mgCCameraFollowFv(void *);
extern "C" s32 EdEventInit__Fv(void);
extern "C" s32 _INITIALIZE__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    mgCCameraFollow *temp_v0;

    EdEventInit__Fv();
    temp_v0 = (mgCCameraFollow *) (GetActiveCamera__Fv());
    if (temp_v0 == NULL) {
        return 0;
    }
    FollowOff__15mgCCameraFollowFv(temp_v0);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/ceohmother", _LOAD_CHARA_sub__FiPPciPUii);
INCLUDE_ASM("nonmatchings/game/ceohmother", _LOAD_CHARA_sub__FiPPciPUi);
INCLUDE_ASM("nonmatchings/game/ceohmother", _LOAD_CHARA__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/ceohmother", _CHARA_ACTIVE__FP12RS_STACKDATAi);
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
extern "C" s32 ClearStack__6CSceneFi(void *, s32);
extern "C" s32 GetStackInt__FP12RS_STACKDATA_00262DA0(RS_STACKDATA *);
extern "C" s32 _CLEAR_STACK__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    ClearStack__6CSceneFi(EventScene, GetStackInt__FP12RS_STACKDATA_00262DA0(arg0));
    return 1;
}
extern "C" s32 AssignStack__6CSceneFi(void *, s32);
extern "C" s32 _ASSIGN_STACK__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    AssignStack__6CSceneFi(EventScene, GetStackInt__FP12RS_STACKDATA_00262DA0(arg0));
    return 1;
}
INCLUDE_ASM("nonmatchings/game/ceohmother", _SET_FLAG__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/ceohmother", _GET_FLAG__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/ceohmother", _SET_CNT__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/ceohmother", _GET_CNT__FP12RS_STACKDATAi);
