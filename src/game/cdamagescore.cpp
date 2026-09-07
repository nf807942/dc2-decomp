/* CDamageScore, CLockOnModel, CWarningGage2, CDamageScore2, mgCCamera, CActiveMonster, CRedMarkModel, MoveCheckInfo
 *
 * Unité découpée par `make carve` : 27 fonctions, 23716 octets, de
 * 0x001CBDA0 à 0x001D1AF0. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"
#include "gen/CDamageScore.hpp"
#include "gen/CLockOnModel.hpp"
#include "gen/CRedMarkModel.hpp"
struct CScene;


INCLUDE_ASM("nonmatchings/game/cdamagescore", SetValue__12CDamageScoreFPfi);
void CDamageScore::SetColor(s16 arg0, s16 arg1, s16 arg2) {
    this->field_0x48 = arg0;
    this->field_0x4A = arg1;
    this->field_0x4C = arg2;
}
struct inferred;
struct CDamageScore_infere;
typedef struct CDamageScore_infere {
    /* 0x00 */ char pad0[0x10];
    /* 0x10 */ char unk10;                             /* inferred */
    /* 0x10 */ char pad10[0x14];
    /* 0x28 */ s32 unk28;                           /* inferred */
    /* 0x2C */ char pad2C[0x22];                    /* maybe part of unk28[9]void */
    /* 0x4E */ s16 unk4E;                           /* inferred */
    /* 0x50 */ s16 unk50;                           /* inferred */
    /* 0x52 */ char pad52[0x22];                    /* maybe part of unk50[0x12]void */
    /* 0x74 */ s32 unk74;                           /* inferred */
    /* 0x78 */ s32 unk78;                           /* inferred */
    /* 0x7C */ s32 unk7C;                           /* inferred */
    /* 0x80 */ s32 unk80;                           /* inferred */
    /* 0x84 */ s32 unk84;                           /* inferred */
    /* 0x88 */ s32 unk88;                           /* inferred */
} CDamageScore_infere;                                     /* size >= 0x8C */
extern "C" s32 sceVu0CopyVector(...);
extern "C" void SetSprite__12CDamageScoreFPfiiii(CDamageScore_infere *objet, f32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    sceVu0CopyVector(&objet->unk10);
    objet->unk4E = 0;
    objet->unk50 = 0;
    objet->unk88 = 1;
    objet->unk84 = 1;
    objet->unk28 = 0x40490FDB;
    objet->unk74 = arg3;
    objet->unk78 = arg4;
    objet->unk7C = arg1;
    objet->unk80 = arg2;
}

INCLUDE_ASM("nonmatchings/game/cdamagescore", Draw__12CDamageScoreFv);
INCLUDE_ASM("nonmatchings/game/cdamagescore", Step__12CDamageScoreFv);
INCLUDE_ASM("nonmatchings/game/cdamagescore", SetValue__13CDamageScore2Fiif);
INCLUDE_ASM("nonmatchings/game/cdamagescore", Draw__13CDamageScore2FP6CScene);
INCLUDE_ASM("nonmatchings/game/cdamagescore", Step__13CDamageScore2Fv);
INCLUDE_ASM("nonmatchings/game/cdamagescore", Draw__12CLockOnModelFv);
INCLUDE_ASM("nonmatchings/game/cdamagescore", DrawMess__12CLockOnModelFi);
INCLUDE_ASM("nonmatchings/game/cdamagescore", Step__12CLockOnModelFv);
struct inferred;
typedef struct CWarningGage2 {
    /* 0x00 */ char pad0[0xC];
    /* 0x0C */ s32 unkC;                            /* inferred */
} CWarningGage2;                                    /* size >= 0x10 */
extern "C" void Step__13CWarningGage2Fv(CWarningGage2 *objet) {
    objet->unkC += 1;
    if (objet->unkC >= 0x28) {
        objet->unkC = 0;
    }
}
INCLUDE_ASM("nonmatchings/game/cdamagescore", Draw__13CWarningGage2Fv);
void CLockOnModel::Initialize(CScene * arg0) {
    this->field_0x80 = arg0;
    this->field_0x8C = 0;
}
INCLUDE_ASM("nonmatchings/game/cdamagescore", GetWeaponEffect__Fv);
INCLUDE_ASM("nonmatchings/game/cdamagescore", memoryInit__Fv);
INCLUDE_ASM("nonmatchings/game/cdamagescore", InitDungeonMain__F13INIT_LOOP_ARG);
INCLUDE_ASM("nonmatchings/game/cdamagescore", Initialize__13MoveCheckInfoFv);
void CRedMarkModel::Initialize(void) {
    this->field_0x80 = 0;
    this->field_0x84 = 0;
    this->field_0x70 = 0;
}
INCLUDE_ASM("nonmatchings/game/cdamagescore", __as__9mgCCameraFRC9mgCCamera);
INCLUDE_ASM("nonmatchings/game/cdamagescore", __ct__14CActiveMonsterFv);
INCLUDE_ASM("nonmatchings/game/cdamagescore", CommonStageClassInit__Fv);
INCLUDE_ASM("nonmatchings/game/cdamagescore", CommonClassInit__Fv);
INCLUDE_ASM("nonmatchings/game/cdamagescore", EntryEventScript__Fi);
void FinishDungeonMain(void) {
}
INCLUDE_ASM("nonmatchings/game/cdamagescore", LoopDungeonMain__Fv);
INCLUDE_ASM("nonmatchings/game/cdamagescore", DngMainDraw__Fv);
