/* CEffectCtrl, CEffect, CEffectManager, CFadeInOut, COutLineDraw, CEffectList, mgC3DSprite
 *
 * Unité découpée par `make carve` : 106 fonctions, 28064 octets, de
 * 0x0017D680 à 0x001846F0. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"
#include "gen/CEffectCtrl.hpp"
#include "gen/CEffectManager.hpp"
#include "gen/CFadeInOut.hpp"
#include "gen/COutLineDraw.hpp"
struct mgCFrame;


struct inferred;
struct SPI_STACK {
    s32 field_0;
    s32 field_4;
};
struct g_tmp_effc_pointe;
extern "C" g_tmp_effc_pointe *g_tmp_effc;
extern "C" f32 spiGetStackFloat__FP9SPI_STACK(SPI_STACK *);
extern "C" s32 spiGetStackInt__FP9SPI_STACK(SPI_STACK *);
extern "C" u32 g_tmp_effm;
typedef struct COutLineDraw_infere {
    /* 0x00 */ s32 unk0;                            /* inferred */
    /* 0x04 */ char pad4[0xC];                      /* maybe part of unk0[4]void */
    /* 0x10 */ f32 unk10;                           /* inferred */
    /* 0x14 */ char pad14[0xC];                     /* maybe part of unk10[4]void */
    /* 0x20 */ f32 unk20;                           /* inferred */
    /* 0x24 */ char pad24[0xC];                     /* maybe part of unk20[4]void */
    /* 0x30 */ s32 unk30;                           /* inferred */
    /* 0x34 */ s32 unk34;                           /* inferred */
    /* 0x38 */ s32 unk38;                           /* inferred */
    /* 0x3C */ s32 unk3C;                           /* inferred */
    /* 0x40 */ char pad40[0x10];                    /* maybe part of unk3C[5]void */
    /* 0x50 */ s32 unk50;                           /* inferred */
    /* 0x54 */ s32 unk54;                           /* inferred */
    /* 0x58 */ s32 unk58;                           /* inferred */
    /* 0x5C */ s32 unk5C;                           /* inferred */
    /* 0x60 */ s32 unk60;                           /* inferred */
    /* 0x64 */ s32 unk64;                           /* inferred */
} COutLineDraw_infere;                                     /* size >= 0x68 */
extern "C" s32 mgZeroVector__FPf(f32 *);
extern "C" void Initialize__12COutLineDrawFv(COutLineDraw_infere *objet) {
    mgZeroVector__FPf(&objet->unk10);
    mgZeroVector__FPf(&objet->unk20);
    objet->unk34 = 0;
    objet->unk30 = 0;
    objet->unk38 = 0;
    objet->unk3C = 0;
    objet->unk50 = 0x42A00000;
    objet->unk54 = 0x42700000;
    objet->unk58 = 0;
    objet->unk5C = 0x43000000;
    objet->unk60 = 1;
    objet->unk64 = 0;
    objet->unk0 = 0;
}
void COutLineDraw::SetFrame(mgCFrame * arg0) {
    this->field_0x34 = arg0;
}
INCLUDE_ASM("nonmatchings/game/ceffectctrl", Draw__12COutLineDrawFPfff);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", Draw__12COutLineDrawFff);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", DrawDivSprite__FP11mgCDrawPrim9mgRect_i_P10mgCTexturePiiiii);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", DrawDivSprite4__FP11mgCDrawPrim9mgRect_i_P10mgCTexturePiii);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", LoadEFPFile__11CEffectListFPcPUiiP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", __ct__11mgC3DSpriteFv);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", SaerchEffectIndex__11CEffectListFPc);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", GetEffectVisual__11CEffectListFi);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", Step__11CEffectListFv);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", CreatePacket__11CEffectListFv);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", CreatePacket__14CEffectManagerFP11mgC3DSprite);
void CFadeInOut::Initialize(void) {
    this->field_0xC = 0;
    this->field_0x8 = 0;
    this->field_0x4 = 0;
    this->field_0x0 = 0;
    this->field_0x10 = 0;
    this->field_0x18 = 0;
    this->field_0x14 = 0;
    this->field_0x20 = 0;
    this->field_0x28 = 0;
    this->field_0x2C = 0;
}
void CFadeInOut::ResetFade(void) {
    this->field_0x10 = 0;
    this->field_0xC = 0;
    this->field_0x20 = 0;
}
typedef struct CFadeInOut_infere {
    /* 0x00 */ f32 unk0;                            /* inferred */
    /* 0x04 */ f32 unk4;                            /* inferred */
    /* 0x08 */ f32 unk8;                            /* inferred */
    /* 0x0C */ s32 unkC;                            /* inferred */
    /* 0x10 */ s32 unk10;                           /* inferred */
    /* 0x14 */ s32 unk14;                           /* inferred */
    /* 0x18 */ f32 unk18;                           /* inferred */
    /* 0x1C */ char pad1C[4];
    /* 0x20 */ s32 unk20;                           /* inferred */
} CFadeInOut_infere;                                       /* size >= 0x24 */
extern "C" void FadeIn__10CFadeInOutFifff(CFadeInOut_infere *objet, s32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    if ((objet->unk10 == 0) || (arg0 < 0)) {
        objet->unkC = 0x43000000;
    }
    objet->unk10 = 1;
    objet->unk14 = 0;
    if (arg0 < 0) {
        objet->unk18 = 0.0f;
    } else {
        objet->unk18 = 128.0f / (f32) arg0;
    }
    objet->unk0 = arg1;
    objet->unk4 = arg2;
    objet->unk8 = arg3;
    objet->unk20 = 0;
}
INCLUDE_ASM("nonmatchings/game/ceffectctrl", FadeIn__10CFadeInOutFi);
typedef struct CFadeInOut_infere2 {
    /* 0x00 */ f32 unk0;                            /* inferred */
    /* 0x04 */ f32 unk4;                            /* inferred */
    /* 0x08 */ f32 unk8;                            /* inferred */
    /* 0x0C */ s32 unkC;                            /* inferred */
    /* 0x10 */ s32 unk10;                           /* inferred */
    /* 0x14 */ s32 unk14;                           /* inferred */
    /* 0x18 */ f32 unk18;                           /* inferred */
    /* 0x1C */ char pad1C[4];
    /* 0x20 */ s32 unk20;                           /* inferred */
} CFadeInOut_infere2;                                       /* size >= 0x24 */
extern "C" void FadeOut__10CFadeInOutFifff(CFadeInOut_infere2 *objet, s32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    if ((objet->unk10 == 0) || (arg0 < 0)) {
        objet->unkC = 0;
    }
    objet->unk10 = -1;
    objet->unk14 = 0;
    if (arg0 < 0) {
        objet->unk18 = 0.0f;
    } else {
        objet->unk18 = 128.0f / (f32) arg0;
    }
    objet->unk0 = arg1;
    objet->unk4 = arg2;
    objet->unk8 = arg3;
    objet->unk20 = 0;
}
INCLUDE_ASM("nonmatchings/game/ceffectctrl", CrossFade__10CFadeInOutFif);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", CrossFadeIn__10CFadeInOutFiif);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", CrossFadeOut__10CFadeInOutFiif);
s32 CFadeInOut::FadeCheck(void) {
    return this->field_0x14;
}
INCLUDE_ASM("nonmatchings/game/ceffectctrl", NowFade__10CFadeInOutFv);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", FadeStep__10CFadeInOutFv);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", SetCrossTexture__10CFadeInOutFP10mgCTextureP1);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", CaptureScreen__10CFadeInOutFv);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", DivSpriteScreen__FR11mgCDrawPrim_0017EF10);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", DivSpriteScreen__FR11mgCDrawPrimiii);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", Draw__10CFadeInOutFv);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", DepthOfField__FiPfP10mgCTexturef);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", LensFlare__FPiPfiPcPc);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", UniformityRand__Fff);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", RegularityRand__Fffi);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", InitEffectParam__FP12EFFECT_PARAM);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", __ct__7CEffectFv);
struct EFFECT_PARAM {
    s32 field_0;
    s32 field_4;
    s32 field_8;
    s32 field_C;
    s32 field_10;
    s32 field_14;
    s32 field_18;
    s32 field_1C;
    s32 field_20;
    s32 field_24;
    s32 field_28;
    s32 field_2C;
    s32 field_30;
    s32 field_34;
    s32 field_38;
    s32 field_3C;
    s32 field_40;
    s32 field_44;
    s32 field_48;
    s32 field_4C;
    s32 field_50;
    s32 field_54;
    s32 field_58;
    s32 field_5C;
    s32 field_60;
    s32 field_64;
    s32 field_68;
    char pad_6C[0x4];
    s32 field_70;
    s32 field_74;
    s32 field_78;
    s32 field_7C;
    s32 field_80;
    s32 field_84;
    s32 field_88;
    s32 field_8C;
    s32 field_90;
    s32 field_94;
    s32 field_98;
    char pad_9C[0x4];
    s32 field_A0;
    s32 field_A4;
    s32 field_A8;
    s32 field_AC;
    s32 field_B0;
    s32 field_B4;
    s32 field_B8;
    s32 field_BC;
    s32 field_C0;
    s32 field_C4;
    s32 field_C8;
    s32 field_CC;
    s32 field_D0;
    s32 field_D4;
    s32 field_D8;
    s32 field_DC;
    s32 field_E0;
    s32 field_E4;
    s32 field_E8;
    s32 field_EC;
    s32 field_F0;
    char pad_F4[0x84];
    s32 field_178;
    s32 field_17C;
    s32 field_180;
    char pad_184[0xC];
    s32 field_190;
    s32 field_194;
    s32 field_198;
    s32 field_19C;
    s32 field_1A0;
    s32 field_1A4;
};
typedef struct CEffect {
    /* 0x00 */ s32 unk0;                            /* inferred */
    /* 0x04 */ s32 unk4;                            /* inferred */
    /* 0x08 */ s32 unk8;                            /* inferred */
    /* 0x0C */ char padC[4];
    /* 0x10 */ s32 unk10;                           /* inferred */
    /* 0x14 */ s32 unk14;                           /* inferred */
    /* 0x18 */ s32 unk18;                           /* inferred */
    /* 0x1C */ s32 unk1C;                           /* inferred */
    /* 0x20 */ s32 unk20;                           /* inferred */
    /* 0x24 */ s32 unk24;                           /* inferred */
    /* 0x28 */ s32 unk28;                           /* inferred */
    /* 0x2C */ s32 unk2C;                           /* inferred */
    /* 0x30 */ s32 unk30;                           /* inferred */
    /* 0x34 */ s32 unk34;                           /* inferred */
    /* 0x38 */ s32 unk38;                           /* inferred */
    /* 0x3C */ s32 unk3C;                           /* inferred */
    /* 0x40 */ s32 unk40;                           /* inferred */
    /* 0x44 */ s32 unk44;                           /* inferred */
    /* 0x48 */ char pad48[8];                       /* maybe part of unk44[3]void */
    /* 0x50 */ EFFECT_PARAM unk50;                  /* inferred */
    /* 0x50 */ char pad50[1];
} CEffect;                                          /* size >= 0x51 */
extern "C" s32 InitEffectParam__FP12EFFECT_PARAM(EFFECT_PARAM *);
extern "C" void Initialize__7CEffectFv(CEffect *objet) {
    objet->unk0 = 0;
    objet->unk4 = 0;
    InitEffectParam__FP12EFFECT_PARAM(&objet->unk50);
    objet->unk10 = 0;
    objet->unk14 = 0;
    objet->unk18 = 0;
    objet->unk1C = 0;
    objet->unk20 = 0;
    objet->unk24 = 0;
    objet->unk28 = 0;
    objet->unk2C = 0;
    objet->unk8 = 0;
    objet->unk30 = 0;
    objet->unk34 = 0;
    objet->unk38 = 0;
    objet->unk3C = 0;
    objet->unk44 = 0;
    objet->unk40 = 0;
}
extern "C" s32 memcpy(...);
extern "C" void SetEffect__7CEffectFP12EFFECT_PARAM(CEffect *objet, EFFECT_PARAM *arg0) {
    objet->unk0 = 1;
    objet->unk10 = 0;
    objet->unk14 = 0;
    objet->unk18 = 0;
    objet->unk20 = 0;
    objet->unk24 = 0;
    objet->unk28 = 0;
    objet->unk8 = 0;
    objet->unk30 = 0;
    objet->unk34 = 0;
    objet->unk38 = 0;
    objet->unk3C = 0;
    objet->unk44 = 0;
    objet->unk40 = 0;
    memcpy(&objet->unk50, arg0, 0x1B0);
}
INCLUDE_ASM("nonmatchings/game/ceffectctrl", Step__7CEffectFi);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", Draw__7CEffectFv);
extern "C" s32 Initialize__11CEffectCtrlFv(void *);
extern "C" CEffectCtrl *__ct__11CEffectCtrlFv(CEffectCtrl *objet) {
    Initialize__11CEffectCtrlFv(objet);
    return objet;
}
extern "C" s32 __dl__FPv(void *);
extern "C" CEffectCtrl *__dt__11CEffectCtrlFv(CEffectCtrl *objet, s16 destroyFlag) {
    if (objet != NULL) {
        if (destroyFlag > 0) {
            __dl__FPv(objet);
        }
    }
    return objet;
}
INCLUDE_ASM("nonmatchings/game/ceffectctrl", Ctrl__11CEffectCtrlFP7CEffecti);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", Initialize__11CEffectCtrlFv);
void CEffectCtrl::Run(void) {
    this->field_0x10 = 1;
    this->field_0x50 = 0;
    this->field_0x64 = 0;
}
INCLUDE_ASM("nonmatchings/game/ceffectctrl", SetOrigin__11CEffectCtrlFPf);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", __as__11CEffectCtrlFRC11CEffectCtrl);
extern "C" s32 __BUFFER_SIZE__FP9SPI_STACKi(SPI_STACK *arg0, s32 arg1) {
    s32 temp = spiGetStackInt__FP9SPI_STACK(arg0++);
    ((CEffectManager *) g_tmp_effm)->SetEffectNums(temp, spiGetStackInt__FP9SPI_STACK(arg0));
    return 1;
}
INCLUDE_ASM("nonmatchings/game/ceffectctrl", __EFFECT_START__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", __EFFECT_END__FP9SPI_STACKi);
extern "C" s32 spiGetStackInt__FP9SPI_STACK(SPI_STACK *);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", __WAIT_FRAME__FP9SPI_STACKi);
extern "C" s32 spiGetStackString__FP9SPI_STACK(SPI_STACK *);
extern "C" s32 strcpy(...);
extern "C" s32 __IMG_NAME__FP9SPI_STACKi(SPI_STACK *arg0, s32 arg1) {
    strcpy(g_tmp_effm + 0x164, spiGetStackString__FP9SPI_STACK(arg0));
    return 1;
}
extern "C" s32 __SIZE__FP9SPI_STACKi(SPI_STACK *arg0, s32 arg1) {
    *(f32 *) ((u8 *) g_tmp_effc + 0x18) = spiGetStackFloat__FP9SPI_STACK(arg0++);
    *(f32 *) ((u8 *) g_tmp_effc + 0x1C) = spiGetStackFloat__FP9SPI_STACK(arg0);
    return 1;
}
typedef struct g_tmp_effc_pointe {
    char pad0[32];
    s32 unk20;
} g_tmp_effc_pointe;
extern "C" g_tmp_effc_pointe *g_tmp_effc;
extern "C" s32 __DIR__FP9SPI_STACKi(SPI_STACK *arg0, s32 arg1) {
    g_tmp_effc->unk20 = spiGetStackInt__FP9SPI_STACK(arg0);
    return 1;
}
struct g_tmp_effc_champs_ccf519 {
    char pad0[0x24];
    /* 0x24 */ s32 unk24;
};
extern "C" s32 __NUM__FP9SPI_STACKi(SPI_STACK *arg0, s32 arg1) {
    ((struct g_tmp_effc_champs_ccf519 *) g_tmp_effc)->unk24 = spiGetStackInt__FP9SPI_STACK(arg0);
    return 1;
}
extern "C" f32 spiGetStackFloat__FP9SPI_STACK(SPI_STACK *);
extern "C" s32 __NUM_RAND__FP9SPI_STACKi(SPI_STACK *arg0, s32 arg1) {
    *(s32 *) ((u8 *) g_tmp_effc + 0x28) = spiGetStackInt__FP9SPI_STACK(arg0++);
    *(f32 *) ((u8 *) g_tmp_effc + 0x2C) = spiGetStackFloat__FP9SPI_STACK(arg0++);
    *(s32 *) ((u8 *) g_tmp_effc + 0x30) = spiGetStackInt__FP9SPI_STACK(arg0);
    return 1;
}
struct g_tmp_effc_champs_dc8039 {
    char pad0[0x34];
    /* 0x34 */ s32 unk34;
};
extern "C" s32 __COUNT__FP9SPI_STACKi(SPI_STACK *arg0, s32 arg1) {
    ((struct g_tmp_effc_champs_dc8039 *) g_tmp_effc)->unk34 = spiGetStackInt__FP9SPI_STACK(arg0);
    return 1;
}
extern "C" s32 __CNT_RAND__FP9SPI_STACKi(SPI_STACK *arg0, s32 arg1) {
    *(s32 *) ((u8 *) g_tmp_effc + 0x38) = spiGetStackInt__FP9SPI_STACK(arg0++);
    *(f32 *) ((u8 *) g_tmp_effc + 0x3C) = spiGetStackFloat__FP9SPI_STACK(arg0++);
    *(s32 *) ((u8 *) g_tmp_effc + 0x40) = spiGetStackInt__FP9SPI_STACK(arg0);
    return 1;
}
extern "C" s32 __REPEAT__FP9SPI_STACKi(SPI_STACK *arg0, s32 arg1) {
    *(s32 *) ((u8 *) g_tmp_effc + 0x44) = spiGetStackInt__FP9SPI_STACK(arg0++);
    *(s32 *) ((u8 *) g_tmp_effc + 0x4C) = spiGetStackInt__FP9SPI_STACK(arg0);
    *(s32 *) ((u8 *) g_tmp_effc + 0x48) = spiGetStackInt__FP9SPI_STACK(arg0++);
    *(s32 *) ((u8 *) g_tmp_effc + 0x60) = spiGetStackInt__FP9SPI_STACK(arg0);
    return 1;
}
extern "C" s32 __REP_RAND__FP9SPI_STACKi(SPI_STACK *arg0, s32 arg1) {
    *(s32 *) ((u8 *) g_tmp_effc + 0x54) = spiGetStackInt__FP9SPI_STACK(arg0++);
    *(f32 *) ((u8 *) g_tmp_effc + 0x58) = spiGetStackFloat__FP9SPI_STACK(arg0++);
    *(s32 *) ((u8 *) g_tmp_effc + 0x5C) = spiGetStackInt__FP9SPI_STACK(arg0);
    return 1;
}
extern "C" s32 __POS__FP9SPI_STACKi(SPI_STACK *arg0, s32 arg1) {
    *(f32 *) ((u8 *) g_tmp_effc + 0x70) = spiGetStackFloat__FP9SPI_STACK(arg0++);
    *(f32 *) ((u8 *) g_tmp_effc + 0x74) = spiGetStackFloat__FP9SPI_STACK(arg0++);
    *(f32 *) ((u8 *) g_tmp_effc + 0x78) = spiGetStackFloat__FP9SPI_STACK(arg0);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/ceffectctrl", __POS_RAND__FP9SPI_STACKi);
extern "C" s32 __VELO__FP9SPI_STACKi(SPI_STACK *arg0, s32 arg1) {
    *(f32 *) ((u8 *) g_tmp_effc + 0xB0) = spiGetStackFloat__FP9SPI_STACK(arg0++);
    *(f32 *) ((u8 *) g_tmp_effc + 0xB4) = spiGetStackFloat__FP9SPI_STACK(arg0++);
    *(f32 *) ((u8 *) g_tmp_effc + 0xB8) = spiGetStackFloat__FP9SPI_STACK(arg0);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/ceffectctrl", __VELO_RAND__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", __VELO_MUL__FP9SPI_STACKi);
extern "C" s32 __ACC__FP9SPI_STACKi(SPI_STACK *arg0, s32 arg1) {
    *(f32 *) ((u8 *) g_tmp_effc + 0xC0) = spiGetStackFloat__FP9SPI_STACK(arg0++);
    *(f32 *) ((u8 *) g_tmp_effc + 0xC4) = spiGetStackFloat__FP9SPI_STACK(arg0++);
    *(f32 *) ((u8 *) g_tmp_effc + 0xC8) = spiGetStackFloat__FP9SPI_STACK(arg0);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/ceffectctrl", __ACC_RAND__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", __ACC_MUL__FP9SPI_STACKi);
extern "C" s32 __MOVE_TYPE__FP9SPI_STACKi(SPI_STACK *arg0, s32 arg1) {
    *(s32 *) ((u8 *) g_tmp_effc + 0xA4) = spiGetStackInt__FP9SPI_STACK(arg0++);
    *(s32 *) ((u8 *) g_tmp_effc + 0xA8) = spiGetStackInt__FP9SPI_STACK(arg0++);
    *(s32 *) ((u8 *) g_tmp_effc + 0xAC) = spiGetStackInt__FP9SPI_STACK(arg0);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/ceffectctrl", __MOVE_P1__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", __MOVE_P1_RAND__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", __MOVE_P2__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", __MOVE_P2_RAND__FP9SPI_STACKi);
extern "C" s32 __SCALE_TYPE__FP9SPI_STACKi(SPI_STACK *arg0, s32 arg1) {
    *(s32 *) ((u8 *) g_tmp_effc + 0x170) = spiGetStackInt__FP9SPI_STACK(arg0++);
    *(s32 *) ((u8 *) g_tmp_effc + 0x174) = spiGetStackInt__FP9SPI_STACK(arg0);
    return 1;
}
extern "C" s32 __SCALE__FP9SPI_STACKi(SPI_STACK *arg0, s32 arg1) {
    *(f32 *) ((u8 *) g_tmp_effc + 0x180) = spiGetStackFloat__FP9SPI_STACK(arg0++);
    *(f32 *) ((u8 *) g_tmp_effc + 0x184) = spiGetStackFloat__FP9SPI_STACK(arg0);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/ceffectctrl", __SCALE_RAND__FP9SPI_STACKi);
extern "C" s32 __SVELO__FP9SPI_STACKi(SPI_STACK *arg0, s32 arg1) {
    *(f32 *) ((u8 *) g_tmp_effc + 0x190) = spiGetStackFloat__FP9SPI_STACK(arg0++);
    *(f32 *) ((u8 *) g_tmp_effc + 0x194) = spiGetStackFloat__FP9SPI_STACK(arg0);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/ceffectctrl", __SVELO_RAND__FP9SPI_STACKi);
extern "C" s32 __SCALE_P1__FP9SPI_STACKi(SPI_STACK *arg0, s32 arg1) {
    *(f32 *) ((u8 *) g_tmp_effc + 0x1A0) = spiGetStackFloat__FP9SPI_STACK(arg0++);
    *(f32 *) ((u8 *) g_tmp_effc + 0x1A4) = spiGetStackFloat__FP9SPI_STACK(arg0);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/ceffectctrl", __SCALE_P1_RAND__FP9SPI_STACKi);
extern "C" s32 __SCALE_P2__FP9SPI_STACKi(SPI_STACK *arg0, s32 arg1) {
    *(f32 *) ((u8 *) g_tmp_effc + 0x1B0) = spiGetStackFloat__FP9SPI_STACK(arg0++);
    *(f32 *) ((u8 *) g_tmp_effc + 0x1B4) = spiGetStackFloat__FP9SPI_STACK(arg0);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/ceffectctrl", __SCALE_P2_RAND__FP9SPI_STACKi);
struct g_tmp_effc_champs_2a1b0c {
    char pad0[0x220];
    /* 0x220 */ s32 unk220;
};
extern "C" s32 __ALPHA_BLEND__FP9SPI_STACKi(SPI_STACK *arg0, s32 arg1) {
    ((struct g_tmp_effc_champs_2a1b0c *) g_tmp_effc)->unk220 = spiGetStackInt__FP9SPI_STACK(arg0);
    return 1;
}
struct g_tmp_effc_champs_495a0c {
    char pad0[0x224];
    /* 0x224 */ s32 unk224;
};
extern "C" s32 __ALPHA_TYPE__FP9SPI_STACKi(SPI_STACK *arg0, s32 arg1) {
    ((struct g_tmp_effc_champs_495a0c *) g_tmp_effc)->unk224 = spiGetStackInt__FP9SPI_STACK(arg0);
    return 1;
}
extern "C" s32 __ALPHA__FP9SPI_STACKi(SPI_STACK *arg0, s32 arg1) {
    *(f32 *) ((u8 *) g_tmp_effc + 0x228) = spiGetStackFloat__FP9SPI_STACK(arg0);
    return 1;
}
extern "C" s32 __ALPHA_RAND__FP9SPI_STACKi(SPI_STACK *arg0, s32 arg1) {
    *(s32 *) ((u8 *) g_tmp_effc + 0x234) = spiGetStackInt__FP9SPI_STACK(arg0++);
    *(f32 *) ((u8 *) g_tmp_effc + 0x240) = spiGetStackFloat__FP9SPI_STACK(arg0++);
    *(s32 *) ((u8 *) g_tmp_effc + 0x24C) = spiGetStackInt__FP9SPI_STACK(arg0);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/ceffectctrl", __ALPHA_P1__FP9SPI_STACKi);
extern "C" s32 __ALPHA_P1_RAND__FP9SPI_STACKi(SPI_STACK *arg0, s32 arg1) {
    *(s32 *) ((u8 *) g_tmp_effc + 0x238) = spiGetStackInt__FP9SPI_STACK(arg0++);
    *(f32 *) ((u8 *) g_tmp_effc + 0x244) = spiGetStackFloat__FP9SPI_STACK(arg0++);
    *(s32 *) ((u8 *) g_tmp_effc + 0x250) = spiGetStackInt__FP9SPI_STACK(arg0);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/ceffectctrl", __ALPHA_P2__FP9SPI_STACKi);
extern "C" s32 __ALPHA_P2_RAND__FP9SPI_STACKi(SPI_STACK *arg0, s32 arg1) {
    *(s32 *) ((u8 *) g_tmp_effc + 0x23C) = spiGetStackInt__FP9SPI_STACK(arg0++);
    *(f32 *) ((u8 *) g_tmp_effc + 0x248) = spiGetStackFloat__FP9SPI_STACK(arg0++);
    *(s32 *) ((u8 *) g_tmp_effc + 0x254) = spiGetStackInt__FP9SPI_STACK(arg0);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/ceffectctrl", __TEX_GET_RECT__FP9SPI_STACKi);
struct g_tmp_effc_champs_d1f959 {
    char pad0[0x2E0];
    /* 0x2E0 */ s32 unk2E0;
};
extern "C" s32 __TEX_GET_TYPE__FP9SPI_STACKi(SPI_STACK *arg0, s32 arg1) {
    ((struct g_tmp_effc_champs_d1f959 *) g_tmp_effc)->unk2E0 = spiGetStackInt__FP9SPI_STACK(arg0);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/ceffectctrl", __TEX_NAME__FP9SPI_STACKi);
extern "C" s32 __GRAVITY__FP9SPI_STACKi(SPI_STACK *arg0, s32 arg1) {
    *(f32 *) ((u8 *) g_tmp_effc + 0x2F0) = spiGetStackFloat__FP9SPI_STACK(arg0++);
    *(f32 *) ((u8 *) g_tmp_effc + 0x2F4) = spiGetStackFloat__FP9SPI_STACK(arg0++);
    *(f32 *) ((u8 *) g_tmp_effc + 0x2F8) = spiGetStackFloat__FP9SPI_STACK(arg0++);
    *(f32 *) ((u8 *) g_tmp_effc + 0x300) = spiGetStackFloat__FP9SPI_STACK(arg0++);
    *(f32 *) ((u8 *) g_tmp_effc + 0x304) = spiGetStackFloat__FP9SPI_STACK(arg0);
    *(s32 *) ((u8 *) g_tmp_effc + 0x2E4) = 1;
    return 1;
}
typedef struct CEffectManager_infere {
    /* 0x0 */ s8 unk0;                              /* inferred */
} CEffectManager_infere;                                   /* size >= 0x1 */
extern "C" s32 EntryEffCtrls__14CEffectManagerFP7CEffectiP11CEffectCtrli(void *, CEffect *, s32, CEffectCtrl *, s32);
extern "C" s32 Initialize__14CEffectManagerFv(void *);
extern "C" CEffectManager_infere *__ct__14CEffectManagerFv(CEffectManager_infere *objet) {
    EntryEffCtrls__14CEffectManagerFP7CEffectiP11CEffectCtrli(objet, NULL, 0, NULL, 0);
    Initialize__14CEffectManagerFv(objet);
    objet->unk0 = 0;
    return objet;
}
INCLUDE_ASM("nonmatchings/game/ceffectctrl", Initialize__14CEffectManagerFv);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", EntryEffCtrls__14CEffectManagerFP7CEffectiP11CEffectCtrli);
void CEffectManager::SetEffectNums(s32 arg0, s32 arg1) {
    this->field_0x24 = arg0;
    this->field_0x2C = arg1;
}
INCLUDE_ASM("nonmatchings/game/ceffectctrl", Ctrl__14CEffectManagerFv);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", Step__14CEffectManagerFi);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", Draw__14CEffectManagerFv);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", Run__14CEffectManagerFv);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", Stop__14CEffectManagerFv);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", EnterEffectCtrl__14CEffectManagerF11CEffectCtrlPc);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", GetBufferNums__14CEffectManagerFPciPiPi);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", Load__14CEffectManagerFPci);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", SetOrigin__14CEffectManagerFPf);
