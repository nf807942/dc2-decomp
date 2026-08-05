/* CAquaMes, CAquaFish, CBubble, CFishFood, CAquaFishEff, CAquaFishActionParam
 *
 * Unité découpée par `make carve` : 63 fonctions, 24504 octets, de
 * 0x0020E410 à 0x00214570. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

INCLUDE_ASM("nonmatchings/caquames", MenuInventDraw__Fv);
INCLUDE_ASM("nonmatchings/caquames", Get_aquarium_paul_table__Fi);
INCLUDE_ASM("nonmatchings/caquames", Get_aquarium_paul_table_xz__Fii);
INCLUDE_ASM("nonmatchings/caquames", local_aquarium_limmit_check__FPffif);
INCLUDE_ASM("nonmatchings/caquames", GetUseableEsaNo__FPi);
INCLUDE_ASM("nonmatchings/caquames", GetEsaInfo__Fi);
INCLUDE_ASM("nonmatchings/caquames", Generate__7CBubbleFi);
INCLUDE_ASM("nonmatchings/caquames", Generate__7CBubbleFPf);
INCLUDE_ASM("nonmatchings/caquames", SetTexture__7CBubbleFP10mgCTextureii);
INCLUDE_ASM("nonmatchings/caquames", Step__7CBubbleFv);
INCLUDE_ASM("nonmatchings/caquames", Draw__7CBubbleFv);
INCLUDE_ASM("nonmatchings/caquames", Initialize__7CBubbleFP9mgCMemoryPfif);
INCLUDE_ASM("nonmatchings/caquames", RunOff__7CBubbleFv);
INCLUDE_ASM("nonmatchings/caquames", GetChildFishNo__Fii);
INCLUDE_ASM("nonmatchings/caquames", SetFishAdjustScale__Fiiff);
INCLUDE_ASM("nonmatchings/caquames", Initialize__20CAquaFishActionParamFv);
INCLUDE_ASM("nonmatchings/caquames", __ct__9CAquaFishFv);
INCLUDE_ASM("nonmatchings/caquames", Initialize__9CAquaFishFv);
INCLUDE_ASM("nonmatchings/caquames", SetLiveParam__9CAquaFishFP13CGameDataUsed);
INCLUDE_ASM("nonmatchings/caquames", SetAdjustScale__9CAquaFishFv);
INCLUDE_ASM("nonmatchings/caquames", AddFatigue__9CAquaFishFi);
INCLUDE_ASM("nonmatchings/caquames", GetPosition2D__9CAquaFishFPi);
INCLUDE_ASM("nonmatchings/caquames", GetDirVect__9CAquaFishFPf);
INCLUDE_ASM("nonmatchings/caquames", NormalGetNextVelo__9CAquaFishFf);
INCLUDE_ASM("nonmatchings/caquames", NormalGetNextRotY__9CAquaFishFv);
INCLUDE_ASM("nonmatchings/caquames", NormalGetNextRot__9CAquaFishFv);
INCLUDE_ASM("nonmatchings/caquames", CalcMoveSpeed__9CAquaFishFf);
INCLUDE_ASM("nonmatchings/caquames", NextRootNormal__9CAquaFishFv);
INCLUDE_ASM("nonmatchings/caquames", MoveActionRound__9CAquaFishFv);
INCLUDE_ASM("nonmatchings/caquames", MoveActionBattle__9CAquaFishFv);
INCLUDE_ASM("nonmatchings/caquames", NextThink__9CAquaFishFiP16NEXT_THINK_PARAM);
INCLUDE_ASM("nonmatchings/caquames", ParamStep__9CAquaFishFv);
INCLUDE_ASM("nonmatchings/caquames", FishDraw__9CAquaFishFv);
INCLUDE_ASM("nonmatchings/caquames", Initialize__12CAquaFishEffFv);
INCLUDE_ASM("nonmatchings/caquames", StartFishEffect__12CAquaFishEffFi);
INCLUDE_ASM("nonmatchings/caquames", Step__12CAquaFishEffFv);
INCLUDE_ASM("nonmatchings/caquames", Draw__12CAquaFishEffFv);
INCLUDE_ASM("nonmatchings/caquames", __ct__9CFishFoodFv);
INCLUDE_ASM("nonmatchings/caquames", SetDropPosition__9CFishFoodFPf);
INCLUDE_ASM("nonmatchings/caquames", Drop__9CFishFoodFv);
INCLUDE_ASM("nonmatchings/caquames", Step__9CFishFoodFv);
INCLUDE_ASM("nonmatchings/caquames", DrawEsaDropRoot__FP9CFishFoodf);
INCLUDE_ASM("nonmatchings/caquames", AquaMesDispAdjustPos__FP6ClsMesPi);
INCLUDE_ASM("nonmatchings/caquames", __ct__8CAquaMesFv);
INCLUDE_ASM("nonmatchings/caquames", Initialize__8CAquaMesFP9mgCMemory);
INCLUDE_ASM("nonmatchings/caquames", SettingAquaMes__8CAquaMesFi);
INCLUDE_ASM("nonmatchings/caquames", SetTitleId__8CAquaMesFi);
INCLUDE_ASM("nonmatchings/caquames", AddMenuCursor__8CAquaMesFii);
INCLUDE_ASM("nonmatchings/caquames", SetQuestionId__8CAquaMesFiii);
INCLUDE_ASM("nonmatchings/caquames", AddQuestionCursor__8CAquaMesFv);
INCLUDE_ASM("nonmatchings/caquames", SetCtrlHelpId__8CAquaMesFi);
INCLUDE_ASM("nonmatchings/caquames", SetInfoMsgID__8CAquaMesFi);
INCLUDE_ASM("nonmatchings/caquames", EatMessage__8CAquaMesFiP9CAquaFish);
INCLUDE_ASM("nonmatchings/caquames", ChangeManMessage__8CAquaMesFP9CAquaFish);
INCLUDE_ASM("nonmatchings/caquames", DeadMessage__8CAquaMesFP9CAquaFish);
INCLUDE_ASM("nonmatchings/caquames", Step__8CAquaMesFv);
INCLUDE_ASM("nonmatchings/caquames", Draw__8CAquaMesFv);
INCLUDE_ASM("nonmatchings/caquames", DrawTitleMes__8CAquaMesFv);
INCLUDE_ASM("nonmatchings/caquames", GetFishPath__FiPc);
INCLUDE_ASM("nonmatchings/caquames", GetFishImgPath__FPciP14BREEDFISH_USED);
INCLUDE_ASM("nonmatchings/caquames", GetFishImageColor__Fii);
INCLUDE_ASM("nonmatchings/caquames", FishIMGReplace__FP1P11CCharacter2iP14BREEDFISH_USED);
INCLUDE_ASM("nonmatchings/caquames", DrawFishParam__FiiP10mgCTextureP13CGameDataUsed);
