/* CFishObj
 *
 * Unité découpée par `make carve` : 56 fonctions, 24056 octets, de
 * 0x00313A40 à 0x00319990. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

INCLUDE_ASM("nonmatchings/cfishobj", NowTakePhoto__Fv);
INCLUDE_ASM("nonmatchings/cfishobj", IsEnablePhotoMenu__Fv);
INCLUDE_ASM("nonmatchings/cfishobj", HidePhoto__Fv);
INCLUDE_ASM("nonmatchings/cfishobj", GhostPhotoTiming__Fv);
INCLUDE_ASM("nonmatchings/cfishobj", LoopTakePhoto__FP11CPadControlP15CInventUserData);
INCLUDE_ASM("nonmatchings/cfishobj", DrawTakePhoto__FP17USER_PICTURE_INFOPf);
INCLUDE_ASM("nonmatchings/cfishobj", SetTookPhotoData__FP17USER_PICTURE_INFO);
INCLUDE_ASM("nonmatchings/cfishobj", DrawTakePhotoSystem__FiP15CInventUserData);
INCLUDE_ASM("nonmatchings/cfishobj", SetFishingMode__Fi);
INCLUDE_ASM("nonmatchings/cfishobj", GetFishingMode__Fv);
INCLUDE_ASM("nonmatchings/cfishobj", SetWaterLevel__Ff);
INCLUDE_ASM("nonmatchings/cfishobj", GetWaterLevel__Fv);
INCLUDE_ASM("nonmatchings/cfishobj", GetActiveHariObj__Fv);
INCLUDE_ASM("nonmatchings/cfishobj", GetActiveUkiObj__Fv);
INCLUDE_ASM("nonmatchings/cfishobj", ExtendLine__Ff);
INCLUDE_ASM("nonmatchings/cfishobj", GetNowLineLength__Fv);
INCLUDE_ASM("nonmatchings/cfishobj", GetMinLineLength__Fv);
INCLUDE_ASM("nonmatchings/cfishobj", InitRodPoint__FP8mgCFrameP8mgCFrame);
INCLUDE_ASM("nonmatchings/cfishobj", GetTriPose__FPA4_fPA4_fPi);
INCLUDE_ASM("nonmatchings/cfishobj", GetHariPos__FPfPf);
INCLUDE_ASM("nonmatchings/cfishobj", GetUkiPos__FPfPf);
INCLUDE_ASM("nonmatchings/cfishobj", PullUki__Ff);
INCLUDE_ASM("nonmatchings/cfishobj", SetShowHari__Fi);
INCLUDE_ASM("nonmatchings/cfishobj", GetShowHari__Fv);
INCLUDE_ASM("nonmatchings/cfishobj", SetLurePose__FP8mgCFrame);
INCLUDE_ASM("nonmatchings/cfishobj", SetUkiPose__FP8mgCFrameP8mgCFrame);
INCLUDE_ASM("nonmatchings/cfishobj", CastingLure__FPf);
INCLUDE_ASM("nonmatchings/cfishobj", EndCastingLure__Fv);
INCLUDE_ASM("nonmatchings/cfishobj", CatchLine__FPff);
INCLUDE_ASM("nonmatchings/cfishobj", SlowLineVelo__Ff);
INCLUDE_ASM("nonmatchings/cfishobj", ResetLineVelo__Fv);
INCLUDE_ASM("nonmatchings/cfishobj", ResetLine__FPf);
INCLUDE_ASM("nonmatchings/cfishobj", GetNextChanceCnt__Fv);
INCLUDE_ASM("nonmatchings/cfishobj", InitFishBattle__Fv);
INCLUDE_ASM("nonmatchings/cfishobj", EndFishBattle__Fv);
INCLUDE_ASM("nonmatchings/cfishobj", CheckRodActionChance__FiPi);
INCLUDE_ASM("nonmatchings/cfishobj", FishBattle__FP6CSceneP6CCPolyi);
INCLUDE_ASM("nonmatchings/cfishobj", GetFishPosVelo__FPfPf);
INCLUDE_ASM("nonmatchings/cfishobj", BindFishObj__Fv);
INCLUDE_ASM("nonmatchings/cfishobj", RodStep__FP6CSceneP1);
INCLUDE_ASM("nonmatchings/cfishobj", BindPosition__FPfPfff_00317600);
INCLUDE_ASM("nonmatchings/cfishobj", DrawFishingLine__Fv);
INCLUDE_ASM("nonmatchings/cfishobj", DrawFishingActionChance__Fv);
INCLUDE_ASM("nonmatchings/cfishobj", InitLureObj__FiP8mgCFrame);
INCLUDE_ASM("nonmatchings/cfishobj", InitUkiObj__FiP8mgCFrameP8mgCFrame);
INCLUDE_ASM("nonmatchings/cfishobj", MovePoint__8CFishObjFv);
INCLUDE_ASM("nonmatchings/cfishobj", FloatPoint__8CFishObjFf);
INCLUDE_ASM("nonmatchings/cfishobj", BindStep__8CFishObjFv);
INCLUDE_ASM("nonmatchings/cfishobj", Correct__8CFishObjFP6CCPolyif);
INCLUDE_ASM("nonmatchings/cfishobj", ParaBlend__FPffPA4_fi);
INCLUDE_ASM("nonmatchings/cfishobj", sgInitBuggy__FP11SubGameInfo);
INCLUDE_ASM("nonmatchings/cfishobj", sgExitBuggy__FP11SubGameInfo);
INCLUDE_ASM("nonmatchings/cfishobj", sgLoopBuggy__FP11SubGameInfo);
INCLUDE_ASM("nonmatchings/cfishobj", sgDrawBuggy__FP11SubGameInfo);
INCLUDE_ASM("nonmatchings/cfishobj", sgEffectDrawBuggy__FP11SubGameInfo);
INCLUDE_ASM("nonmatchings/cfishobj", sgDrawShadowBuggy__FP11SubGameInfo);
