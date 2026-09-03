/* BattleEffectMan, CHitEffectImage, CDeadEffect, CMapEffect_Sprite, CThunder, CSWordAfterImage, CMapEffectsManeger, CHealingEffectMan, CPowerLine, CSparcEffect, CSwordLuminous, CFlushEffect, CAfterWire, CMiniEffPrim, CMiniEffPrimMan, CPalletAnime, CCharacter2
 *
 * Unité découpée par `make carve` : 61 fonctions, 22208 octets, de
 * 0x001C17C0 à 0x001C6FD0. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"
#include "gen/CAfterWire.hpp"
#include "gen/CThunder.hpp"
#include "gen/CHealingEffectMan.hpp"
#include "gen/CMiniEffPrim.hpp"
#include "gen/CPalletAnime.hpp"
#include "gen/CSparcEffect.hpp"

INCLUDE_ASM("nonmatchings/game/battleeffectman", SetPos__8CThunderFPfff);
INCLUDE_ASM("nonmatchings/game/battleeffectman", Draw__8CThunderFv);
INCLUDE_ASM("nonmatchings/game/battleeffectman", Step__8CThunderFv);
void CThunder::Initialize(void) {
    this->field_0xDB0 = 0;
    this->field_0xDB1 = 0;
    this->field_0xF4 = &this->field_0x110;
}
INCLUDE_ASM("nonmatchings/game/battleeffectman", Draw__12CSparcEffectFv);
INCLUDE_ASM("nonmatchings/game/battleeffectman", Step__12CSparcEffectFv);
void CSparcEffect::Initialize(void) {
    this->field_0xA9 = 0;
}
INCLUDE_ASM("nonmatchings/game/battleeffectman", SetPrim__12CMiniEffPrimFPfi);
INCLUDE_ASM("nonmatchings/game/battleeffectman", Draw__12CMiniEffPrimFP10CPreSprite);
INCLUDE_ASM("nonmatchings/game/battleeffectman", Step__12CMiniEffPrimFv);
void CMiniEffPrim::Initialize(void) {
    this->field_0x10 = 0;
}
INCLUDE_ASM("nonmatchings/game/battleeffectman", CreatPrim__15CMiniEffPrimManFPfi);
INCLUDE_ASM("nonmatchings/game/battleeffectman", Draw__15CMiniEffPrimManFv);
INCLUDE_ASM("nonmatchings/game/battleeffectman", Step__15CMiniEffPrimManFv);
INCLUDE_ASM("nonmatchings/game/battleeffectman", Initialize__15CMiniEffPrimManFv);
struct inferred;
typedef struct CPalletAnime_infere2 {
    /* 0x0 */ s16 unk0;                             /* inferred */
    /* 0x2 */ s16 unk2;                             /* inferred */
    /* 0x4 */ s16 unk4;                             /* inferred */
    /* 0x6 */ s16 unk6;                             /* inferred */
    /* 0x8 */ s16 unk8;                             /* inferred */
    /* 0xA */ s16 unkA;                             /* inferred */
    /* 0xC */ s16 unkC;                             /* inferred */
} CPalletAnime_infere2;                                     /* size >= 0xE */
extern "C" void SetAnim__12CPalletAnimeFssssss(CPalletAnime_infere2 *objet, s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5) {
    objet->unk0 = arg0;
    objet->unk2 = arg1;
    objet->unk4 = arg2;
    objet->unk6 = arg3;
    objet->unkA = arg4;
    objet->unk8 = 0;
    objet->unkC = arg5;
}
INCLUDE_ASM("nonmatchings/game/battleeffectman", CreatPallet__12CPalletAnimeFPfPf);
struct inferred;
typedef struct CPalletAnime_infere {
    /* 0x0 */ char pad0[8];
    /* 0x8 */ s16 unk8;                             /* inferred */
    /* 0xA */ s16 unkA;                             /* inferred */
    /* 0xC */ s16 unkC;                             /* inferred */
} CPalletAnime_infere;                                     /* size >= 0xE */
extern "C" void Step__12CPalletAnimeFv(CPalletAnime_infere *objet) {
    s16 temp_a1;

    if ((objet->unkA > 0) && (objet->unk8 += 1, ((objet->unk8 < objet->unkA) == 0))) {
        temp_a1 = objet->unkC;
        if (temp_a1 == -1) {
            objet->unk8 = 0;
            return;
        }
        if (temp_a1 > 0) {
            objet->unkC = temp_a1 - 1;
            objet->unk8 = 0;
            return;
        }
        objet->unkA = 0;
    }
}
void CPalletAnime::Initialize(void) {
    this->field_0xA = 0;
    this->field_0x8 = 0;
}
INCLUDE_ASM("nonmatchings/game/battleeffectman", Draw__17CHealingEffectManFP9mgCCamera);
INCLUDE_ASM("nonmatchings/game/battleeffectman", Step__17CHealingEffectManFv);
void CHealingEffectMan::SetMode(s32 arg0) {
    this->field_0x314 = arg0;
}
extern "C" s32 sceVu0CopyVector(...);
typedef struct CHealingEffectMan_infere {
    /* 0x000 */ s16 unk0;                           /* inferred */
    /* 0x002 */ char pad2[0x30E];                   /* maybe part of unk0[0x188]void */
    /* 0x310 */ s32 unk310;                         /* inferred */
    /* 0x314 */ s16 unk314;                         /* inferred */
    /* 0x316 */ char pad316[0xA];                   /* maybe part of unk314[6]void */
    /* 0x320 */ char unk320;                           /* inferred */
    /* 0x320 */ char pad320[1];
} CHealingEffectMan_infere;                                /* size >= 0x321 */
extern "C" void Set__17CHealingEffectManFPf(CHealingEffectMan_infere *objet, f32 *arg0) {
    sceVu0CopyVector(&objet->unk320);
    objet->unk0 = 1;
    objet->unk314 = 0;
    objet->unk310 = 0x3F800000;
}
INCLUDE_ASM("nonmatchings/game/battleeffectman", Initialize__17CHealingEffectManFv);
INCLUDE_ASM("nonmatchings/game/battleeffectman", Draw__14CSwordLuminousFv);
INCLUDE_ASM("nonmatchings/game/battleeffectman", Step__14CSwordLuminousFv);
INCLUDE_ASM("nonmatchings/game/battleeffectman", Draw__16CSWordAfterImageFv);
INCLUDE_ASM("nonmatchings/game/battleeffectman", CreatPointList__16CSWordAfterImageFv);
INCLUDE_ASM("nonmatchings/game/battleeffectman", AddPoint__16CSWordAfterImageFPfPff);
INCLUDE_ASM("nonmatchings/game/battleeffectman", Step__16CSWordAfterImageFv);
INCLUDE_ASM("nonmatchings/game/battleeffectman", Initialize__16CSWordAfterImageFP9mgCMemoryii);
void CAfterWire::SetMode(s32 arg0) {
    this->field_0x0 = arg0;
    this->field_0x116 = 0;
    this->field_0x118 = 0;
    this->field_0x112 = 0;
    this->field_0x114 = 0;
}
INCLUDE_ASM("nonmatchings/game/battleeffectman", SetPos__10CAfterWireFPf);
INCLUDE_ASM("nonmatchings/game/battleeffectman", DrawWire__10CAfterWireFPA4_f);
INCLUDE_ASM("nonmatchings/game/battleeffectman", StepWire__10CAfterWireFv);
INCLUDE_ASM("nonmatchings/game/battleeffectman", SethitEffect__15CHitEffectImageFPfPfffffii);
INCLUDE_ASM("nonmatchings/game/battleeffectman", Step__15CHitEffectImageFv);
struct inferred;
struct irregular;
typedef struct CHitEffectImage {
    /* 0x00 */ char pad0[0x28];
    /* 0x28 */ s32 unk28;                           /* inferred */
    /* 0x2C */ char pad2C[0x18];                    /* maybe part of unk28[7]void */
    /* 0x44 */ s32 unk44;                           /* inferred */
} CHitEffectImage;                                  /* size >= 0x48 */
extern "C" s32 DrawBord__15CHitEffectImageFv(void *);
extern "C" s32 DrawSpark__15CHitEffectImageFf(void *, f32);
extern "C" void Draw__15CHitEffectImageFv(CHitEffectImage *objet) {
    s32 temp_a1;

    if (objet->unk28 > 0) {
        temp_a1 = objet->unk44;
        switch (temp_a1) {                          /* irregular */
        case 0:
            DrawBord__15CHitEffectImageFv(objet);
            return;
        case 1:
            DrawSpark__15CHitEffectImageFf(objet, 3.0f);
            return;
        case 2:
            DrawSpark__15CHitEffectImageFf(objet, 9.0f);
            break;
        }
    }
}
INCLUDE_ASM("nonmatchings/game/battleeffectman", DrawBord__15CHitEffectImageFv);
INCLUDE_ASM("nonmatchings/game/battleeffectman", DrawSpark__15CHitEffectImageFf);
INCLUDE_ASM("nonmatchings/game/battleeffectman", Draw__12CFlushEffectFv);
INCLUDE_ASM("nonmatchings/game/battleeffectman", Step__12CFlushEffectFv);
INCLUDE_ASM("nonmatchings/game/battleeffectman", CreatPrim__10CPowerLineFv);
INCLUDE_ASM("nonmatchings/game/battleeffectman", Step__10CPowerLineFv);
INCLUDE_ASM("nonmatchings/game/battleeffectman", Draw__10CPowerLineFv);
typedef struct CDeadEffect {
    /* 0x00 */ char pad0[0x10];
    /* 0x10 */ f32 unk10;                           /* inferred */
    /* 0x14 */ f32 unk14;                           /* inferred */
    /* 0x18 */ f32 unk18;                           /* inferred */
    /* 0x1C */ s32 unk1C;                           /* inferred */
    /* 0x20 */ s32 unk20;                           /* inferred */
} CDeadEffect;                                      /* size >= 0x24 */
extern "C" s32 sceVu0CopyVector(...);
extern "C" void SetDeadEffect__11CDeadEffectFPffffi(CDeadEffect *objet, f32 *arg0, f32 arg1, f32 arg2, f32 arg3, s32 arg4) {
    sceVu0CopyVector(objet);
    objet->unk14 = arg1;
    objet->unk10 = arg2;
    objet->unk18 = arg3;
    objet->unk1C = arg4;
    objet->unk20 = 0;
}
INCLUDE_ASM("nonmatchings/game/battleeffectman", CreatPrim__11CDeadEffectFi);
INCLUDE_ASM("nonmatchings/game/battleeffectman", Step__11CDeadEffectFv);
INCLUDE_ASM("nonmatchings/game/battleeffectman", Draw__11CDeadEffectFv);
INCLUDE_ASM("nonmatchings/game/battleeffectman", Set__17CMapEffect_SpriteFPf);
INCLUDE_ASM("nonmatchings/game/battleeffectman", Step__17CMapEffect_SpriteFP9mgCCamera);
INCLUDE_ASM("nonmatchings/game/battleeffectman", Draw__17CMapEffect_SpriteFP9mgCCameraP10CPreSprite);
INCLUDE_ASM("nonmatchings/game/battleeffectman", Init_LightBoll__18CMapEffectsManegerFP9mgCMemoryi);
INCLUDE_ASM("nonmatchings/game/battleeffectman", Step__18CMapEffectsManegerFP9mgCCamera);
INCLUDE_ASM("nonmatchings/game/battleeffectman", Draw__18CMapEffectsManegerFP9mgCCamera);
INCLUDE_ASM("nonmatchings/game/battleeffectman", AllocEffect__15BattleEffectManFiP9mgCMemoryi);
INCLUDE_ASM("nonmatchings/game/battleeffectman", __ct__11CCharacter2Fv);
INCLUDE_ASM("nonmatchings/game/battleeffectman", __ct__10CPowerLineFv);
INCLUDE_ASM("nonmatchings/game/battleeffectman", __ct__15CHitEffectImageFv);
INCLUDE_ASM("nonmatchings/game/battleeffectman", Step__15BattleEffectManFv);
INCLUDE_ASM("nonmatchings/game/battleeffectman", Draw__15BattleEffectManFv);
