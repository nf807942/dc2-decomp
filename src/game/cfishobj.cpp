/* CFishObj
 *
 * Unité découpée par `make carve` : 56 fonctions, 24056 octets, de
 * 0x00313A40 à 0x00319990. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

INCLUDE_ASM("nonmatchings/game/cfishobj", NowTakePhoto__Fv);
INCLUDE_ASM("nonmatchings/game/cfishobj", IsEnablePhotoMenu__Fv);
INCLUDE_ASM("nonmatchings/game/cfishobj", HidePhoto__Fv);
INCLUDE_ASM("nonmatchings/game/cfishobj", GhostPhotoTiming__Fv);
INCLUDE_ASM("nonmatchings/game/cfishobj", LoopTakePhoto__FP11CPadControlP15CInventUserData);
INCLUDE_ASM("nonmatchings/game/cfishobj", DrawTakePhoto__FP17USER_PICTURE_INFOPf);
INCLUDE_ASM("nonmatchings/game/cfishobj", SetTookPhotoData__FP17USER_PICTURE_INFO);
INCLUDE_ASM("nonmatchings/game/cfishobj", DrawTakePhotoSystem__FiP15CInventUserData);
INCLUDE_ASM("nonmatchings/game/cfishobj", SetFishingMode__Fi);
INCLUDE_ASM("nonmatchings/game/cfishobj", GetFishingMode__Fv);
INCLUDE_ASM("nonmatchings/game/cfishobj", SetWaterLevel__Ff);
INCLUDE_ASM("nonmatchings/game/cfishobj", GetWaterLevel__Fv);
INCLUDE_ASM("nonmatchings/game/cfishobj", GetActiveHariObj__Fv);
INCLUDE_ASM("nonmatchings/game/cfishobj", GetActiveUkiObj__Fv);
INCLUDE_ASM("nonmatchings/game/cfishobj", ExtendLine__Ff);
INCLUDE_ASM("nonmatchings/game/cfishobj", GetNowLineLength__Fv);
INCLUDE_ASM("nonmatchings/game/cfishobj", GetMinLineLength__Fv);
INCLUDE_ASM("nonmatchings/game/cfishobj", InitRodPoint__FP8mgCFrameP8mgCFrame);
INCLUDE_ASM("nonmatchings/game/cfishobj", GetTriPose__FPA4_fPA4_fPi);
INCLUDE_ASM("nonmatchings/game/cfishobj", GetHariPos__FPfPf);
INCLUDE_ASM("nonmatchings/game/cfishobj", GetUkiPos__FPfPf);
INCLUDE_ASM("nonmatchings/game/cfishobj", PullUki__Ff);
INCLUDE_ASM("nonmatchings/game/cfishobj", SetShowHari__Fi);
INCLUDE_ASM("nonmatchings/game/cfishobj", GetShowHari__Fv);
INCLUDE_ASM("nonmatchings/game/cfishobj", SetLurePose__FP8mgCFrame);
INCLUDE_ASM("nonmatchings/game/cfishobj", SetUkiPose__FP8mgCFrameP8mgCFrame);
INCLUDE_ASM("nonmatchings/game/cfishobj", CastingLure__FPf);
INCLUDE_ASM("nonmatchings/game/cfishobj", EndCastingLure__Fv);
INCLUDE_ASM("nonmatchings/game/cfishobj", CatchLine__FPff);
INCLUDE_ASM("nonmatchings/game/cfishobj", SlowLineVelo__Ff);
INCLUDE_ASM("nonmatchings/game/cfishobj", ResetLineVelo__Fv);
INCLUDE_ASM("nonmatchings/game/cfishobj", ResetLine__FPf);
INCLUDE_ASM("nonmatchings/game/cfishobj", GetNextChanceCnt__Fv);
INCLUDE_ASM("nonmatchings/game/cfishobj", InitFishBattle__Fv);
INCLUDE_ASM("nonmatchings/game/cfishobj", EndFishBattle__Fv);
INCLUDE_ASM("nonmatchings/game/cfishobj", CheckRodActionChance__FiPi);
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
INCLUDE_ASM("nonmatchings/game/cfishobj", sgDrawBuggy__FP11SubGameInfo);
INCLUDE_ASM("nonmatchings/game/cfishobj", sgEffectDrawBuggy__FP11SubGameInfo);
INCLUDE_ASM("nonmatchings/game/cfishobj", sgDrawShadowBuggy__FP11SubGameInfo);
