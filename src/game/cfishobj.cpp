/* CFishObj
 *
 * Unité découpée par `make carve` : 56 fonctions, 24056 octets, de
 * 0x00313A40 à 0x00319990. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

/* Les globales que ces accesseurs servent. Leur taille déclarée est celle que
 * le découpage leur donne, et c'est elle qui décide du `%gp_rel`. */
extern s32 NowMode;
extern s32 ShowHari;
extern s32 ShowTakePhotoCnt;
extern f32 WaterLevel;
extern s32 ActionChanceCnt;
extern s32 ActionChanceNextCnt;
extern s32 AddLineSpeed;
extern s32 BattleFlag;
extern s32 CastingLureFlag;
extern s32 CastingLureTime;


extern "C" u32 TakePhotoMode;
extern "C" s32 NowTakePhoto__Fv(void) { return (s32) TakePhotoMode > 0; }

extern "C" s32 IsEnablePhotoMenu__Fv(void) {
    return TakePhotoMode == 2;
}

void HidePhoto(void) {
    ShowTakePhotoCnt = 0;
}
extern "C" u32 TakePhotoMode;
struct fallthrough;
struct irregular;
extern "C" s32 GhostPhotoTiming__Fv(void) {
    switch (TakePhotoMode) {                        /* irregular */
    case 3:
        /* fallthrough */
    case 5:
        return 1;
    default:
        return 0;
    }
}
INCLUDE_ASM("nonmatchings/game/cfishobj", LoopTakePhoto__FP11CPadControlP15CInventUserData);
INCLUDE_ASM("nonmatchings/game/cfishobj", DrawTakePhoto__FP17USER_PICTURE_INFOPf);
INCLUDE_ASM("nonmatchings/game/cfishobj", SetTookPhotoData__FP17USER_PICTURE_INFO);
INCLUDE_ASM("nonmatchings/game/cfishobj", DrawTakePhotoSystem__FiP15CInventUserData);
void SetFishingMode(s32 value) {
    NowMode = value;
}
s32 GetFishingMode(void) {
    return NowMode;
}
void SetWaterLevel(f32 value) {
    WaterLevel = value;
}
f32 GetWaterLevel(void) {
    return WaterLevel;
}
extern "C" u8 HariObj[976];
extern "C" u8 LureObj[976];
extern "C" void *GetActiveHariObj__Fv(void) {
    if (NowMode == 2) {
        return &LureObj;
    }
    return &HariObj;
}
extern "C" u8 UkiObj[976];
extern "C" void *GetActiveUkiObj__Fv(void) {
    if (NowMode == 2) {
        return NULL;
    }
    return &UkiObj;
}
INCLUDE_ASM("nonmatchings/game/cfishobj", ExtendLine__Ff);
INCLUDE_ASM("nonmatchings/game/cfishobj", GetNowLineLength__Fv);
extern "C" f32 GetMinLineLength__Fv(void) {
    return 25.0f;
}

INCLUDE_ASM("nonmatchings/game/cfishobj", InitRodPoint__FP8mgCFrameP8mgCFrame);
INCLUDE_ASM("nonmatchings/game/cfishobj", GetTriPose__FPA4_fPA4_fPi);
INCLUDE_ASM("nonmatchings/game/cfishobj", GetHariPos__FPfPf);
INCLUDE_ASM("nonmatchings/game/cfishobj", GetUkiPos__FPfPf);
struct LinePointT { u8 pad[0xBF4]; f32 x; u8 pad2[8]; };
extern "C" LinePointT LinePoint;
extern "C" void PullUki__Ff(f32 f) {
    LinePoint.x = LinePoint.x - f;
}

void SetShowHari(s32 value) {
    ShowHari = value;
}
INCLUDE_ASM("nonmatchings/game/cfishobj", GetShowHari__Fv);
INCLUDE_ASM("nonmatchings/game/cfishobj", SetLurePose__FP8mgCFrame);
INCLUDE_ASM("nonmatchings/game/cfishobj", SetUkiPose__FP8mgCFrameP8mgCFrame);
INCLUDE_ASM("nonmatchings/game/cfishobj", CastingLure__FPf);
void EndCastingLure(void) {
    CastingLureFlag = 0;
    CastingLureTime = 0;
    AddLineSpeed = 0;
}
INCLUDE_ASM("nonmatchings/game/cfishobj", CatchLine__FPff);
INCLUDE_ASM("nonmatchings/game/cfishobj", SlowLineVelo__Ff);
INCLUDE_ASM("nonmatchings/game/cfishobj", ResetLineVelo__Fv);
INCLUDE_ASM("nonmatchings/game/cfishobj", ResetLine__FPf);
extern "C" s32 rand(...);
extern "C" s32 GetNextChanceCnt__Fv(void) {
    return (rand() % 80) + 0x3C;
}
INCLUDE_ASM("nonmatchings/game/cfishobj", InitFishBattle__Fv);
s32 EndFishBattle(void) {
    BattleFlag = 0;
    ActionChanceNextCnt = 0;
    ActionChanceCnt = 0;
    return 1;
}
extern "C" u32 ActionChanceDir;
extern "C" s32 CheckRodActionChance__FiPi(s32 arg0, s32 *arg1) {
    s32 temp_v0;

    *arg1 = 0;
    if ((BattleFlag == 0) || (ActionChanceCnt <= 0)) {
        return 0;
    }
    temp_v0 = arg0 * ActionChanceDir;
    if (temp_v0 > 0) {
        return 1;
    }
    if (temp_v0 < 0) {
        return -1;
    }
    *arg1 = ActionChanceCnt == 0x1C;
    return 0;
}
INCLUDE_ASM("nonmatchings/game/cfishobj", FishBattle__FP6CSceneP6CCPolyi);
INCLUDE_ASM("nonmatchings/game/cfishobj", GetFishPosVelo__FPfPf);
INCLUDE_ASM("nonmatchings/game/cfishobj", BindFishObj__Fv);
INCLUDE_ASM("nonmatchings/game/cfishobj", RodStep__FP6CSceneP1);
INCLUDE_ASM("nonmatchings/game/cfishobj", BindPosition__FPfPfff_00317600);
INCLUDE_ASM("nonmatchings/game/cfishobj", DrawFishingLine__Fv);
INCLUDE_ASM("nonmatchings/game/cfishobj", DrawFishingActionChance__Fv);
INCLUDE_ASM("nonmatchings/game/cfishobj", InitLureObj__FiP8mgCFrame);
INCLUDE_ASM("nonmatchings/game/cfishobj", InitUkiObj__FiP8mgCFrameP8mgCFrame);
INCLUDE_ASM("nonmatchings/game/cfishobj", MovePoint__8CFishObjFv);
INCLUDE_ASM("nonmatchings/game/cfishobj", FloatPoint__8CFishObjFf);
INCLUDE_ASM("nonmatchings/game/cfishobj", BindStep__8CFishObjFv);
INCLUDE_ASM("nonmatchings/game/cfishobj", Correct__8CFishObjFP6CCPolyif);
INCLUDE_ASM("nonmatchings/game/cfishobj", ParaBlend__FPffPA4_fi);
INCLUDE_ASM("nonmatchings/game/cfishobj", sgInitBuggy__FP11SubGameInfo);
INCLUDE_ASM("nonmatchings/game/cfishobj", sgExitBuggy__FP11SubGameInfo);
INCLUDE_ASM("nonmatchings/game/cfishobj", sgLoopBuggy__FP11SubGameInfo);
#include "sphida.hpp"
struct inferred;
typedef struct SubGameInfo {
    /* 0x0 */ CScene *unk0;                         /* inferred */
} SubGameInfo;                                      /* size >= 0x4 */
extern "C" s32 DrawChara__6CSceneFii(void *, s32, s32);
extern "C" s32 sgDrawBuggy__FP11SubGameInfo(SubGameInfo *arg0) {
    CScene *temp_s0;

    temp_s0 = (CScene *) (arg0->unk0);
    DrawChara__6CSceneFii(temp_s0, 0x40, 1);
    DrawChara__6CSceneFii(temp_s0, 0x41, 1);
    DrawChara__6CSceneFii(temp_s0, 0x42, 1);
    DrawChara__6CSceneFii(temp_s0, 0x44, 1);
    DrawChara__6CSceneFii(temp_s0, 0x43, 1);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/cfishobj", sgEffectDrawBuggy__FP11SubGameInfo);
struct inferred;
typedef struct SubGameInfo_infere {
    /* 0x0 */ CScene *unk0;                         /* inferred */
} SubGameInfo_infere;                                      /* size >= 0x4 */
extern "C" s32 DrawCharaShadow__6CSceneFi(void *, s32);
extern "C" s32 sgDrawShadowBuggy__FP11SubGameInfo(SubGameInfo_infere *arg0) {
    CScene *temp_s0;

    temp_s0 = (CScene *) (arg0->unk0);
    DrawCharaShadow__6CSceneFi(temp_s0, 0x40);
    DrawCharaShadow__6CSceneFi(temp_s0, 0x44);
    DrawCharaShadow__6CSceneFi(temp_s0, 0x41);
    DrawCharaShadow__6CSceneFi(temp_s0, 0x42);
    return 1;
}
