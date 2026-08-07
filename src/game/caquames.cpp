/* CAquaMes, CAquaFish, CBubble, CFishFood, CAquaFishEff, CAquaFishActionParam
 *
 * Unité découpée par `make carve` : 63 fonctions, 24504 octets, de
 * 0x0020E410 à 0x00214570. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

INCLUDE_ASM("nonmatchings/game/caquames", MenuInventDraw__Fv);
INCLUDE_ASM("nonmatchings/game/caquames", Get_aquarium_paul_table__Fi);
INCLUDE_ASM("nonmatchings/game/caquames", Get_aquarium_paul_table_xz__Fii);
INCLUDE_ASM("nonmatchings/game/caquames", local_aquarium_limmit_check__FPffif);
INCLUDE_ASM("nonmatchings/game/caquames", GetUseableEsaNo__FPi);
INCLUDE_ASM("nonmatchings/game/caquames", GetEsaInfo__Fi);
INCLUDE_ASM("nonmatchings/game/caquames", Generate__7CBubbleFi);
INCLUDE_ASM("nonmatchings/game/caquames", Generate__7CBubbleFPf);
INCLUDE_ASM("nonmatchings/game/caquames", SetTexture__7CBubbleFP10mgCTextureii);
INCLUDE_ASM("nonmatchings/game/caquames", Step__7CBubbleFv);
INCLUDE_ASM("nonmatchings/game/caquames", Draw__7CBubbleFv);
INCLUDE_ASM("nonmatchings/game/caquames", Initialize__7CBubbleFP9mgCMemoryPfif);
INCLUDE_ASM("nonmatchings/game/caquames", RunOff__7CBubbleFv);
INCLUDE_ASM("nonmatchings/game/caquames", GetChildFishNo__Fii);
INCLUDE_ASM("nonmatchings/game/caquames", SetFishAdjustScale__Fiiff);
INCLUDE_ASM("nonmatchings/game/caquames", Initialize__20CAquaFishActionParamFv);
INCLUDE_ASM("nonmatchings/game/caquames", __ct__9CAquaFishFv);
INCLUDE_ASM("nonmatchings/game/caquames", Initialize__9CAquaFishFv);
INCLUDE_ASM("nonmatchings/game/caquames", SetLiveParam__9CAquaFishFP13CGameDataUsed);
INCLUDE_ASM("nonmatchings/game/caquames", SetAdjustScale__9CAquaFishFv);
INCLUDE_ASM("nonmatchings/game/caquames", AddFatigue__9CAquaFishFi);
INCLUDE_ASM("nonmatchings/game/caquames", GetPosition2D__9CAquaFishFPi);
INCLUDE_ASM("nonmatchings/game/caquames", GetDirVect__9CAquaFishFPf);
INCLUDE_ASM("nonmatchings/game/caquames", NormalGetNextVelo__9CAquaFishFf);
INCLUDE_ASM("nonmatchings/game/caquames", NormalGetNextRotY__9CAquaFishFv);
INCLUDE_ASM("nonmatchings/game/caquames", NormalGetNextRot__9CAquaFishFv);
INCLUDE_ASM("nonmatchings/game/caquames", CalcMoveSpeed__9CAquaFishFf);
INCLUDE_ASM("nonmatchings/game/caquames", NextRootNormal__9CAquaFishFv);
INCLUDE_ASM("nonmatchings/game/caquames", MoveActionRound__9CAquaFishFv);
INCLUDE_ASM("nonmatchings/game/caquames", MoveActionBattle__9CAquaFishFv);
INCLUDE_ASM("nonmatchings/game/caquames", NextThink__9CAquaFishFiP16NEXT_THINK_PARAM);
INCLUDE_ASM("nonmatchings/game/caquames", ParamStep__9CAquaFishFv);
INCLUDE_ASM("nonmatchings/game/caquames", FishDraw__9CAquaFishFv);
INCLUDE_ASM("nonmatchings/game/caquames", Initialize__12CAquaFishEffFv);
INCLUDE_ASM("nonmatchings/game/caquames", StartFishEffect__12CAquaFishEffFi);
INCLUDE_ASM("nonmatchings/game/caquames", Step__12CAquaFishEffFv);
INCLUDE_ASM("nonmatchings/game/caquames", Draw__12CAquaFishEffFv);
INCLUDE_ASM("nonmatchings/game/caquames", __ct__9CFishFoodFv);
INCLUDE_ASM("nonmatchings/game/caquames", SetDropPosition__9CFishFoodFPf);
INCLUDE_ASM("nonmatchings/game/caquames", Drop__9CFishFoodFv);
INCLUDE_ASM("nonmatchings/game/caquames", Step__9CFishFoodFv);
INCLUDE_ASM("nonmatchings/game/caquames", DrawEsaDropRoot__FP9CFishFoodf);
INCLUDE_ASM("nonmatchings/game/caquames", AquaMesDispAdjustPos__FP6ClsMesPi);
INCLUDE_ASM("nonmatchings/game/caquames", __ct__8CAquaMesFv);
INCLUDE_ASM("nonmatchings/game/caquames", Initialize__8CAquaMesFP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/caquames", SettingAquaMes__8CAquaMesFi);
INCLUDE_ASM("nonmatchings/game/caquames", SetTitleId__8CAquaMesFi);
INCLUDE_ASM("nonmatchings/game/caquames", AddMenuCursor__8CAquaMesFii);
INCLUDE_ASM("nonmatchings/game/caquames", SetQuestionId__8CAquaMesFiii);
INCLUDE_ASM("nonmatchings/game/caquames", AddQuestionCursor__8CAquaMesFv);
INCLUDE_ASM("nonmatchings/game/caquames", SetCtrlHelpId__8CAquaMesFi);
INCLUDE_ASM("nonmatchings/game/caquames", SetInfoMsgID__8CAquaMesFi);
INCLUDE_ASM("nonmatchings/game/caquames", EatMessage__8CAquaMesFiP9CAquaFish);
INCLUDE_ASM("nonmatchings/game/caquames", ChangeManMessage__8CAquaMesFP9CAquaFish);
INCLUDE_ASM("nonmatchings/game/caquames", DeadMessage__8CAquaMesFP9CAquaFish);
INCLUDE_ASM("nonmatchings/game/caquames", Step__8CAquaMesFv);
INCLUDE_ASM("nonmatchings/game/caquames", Draw__8CAquaMesFv);
INCLUDE_ASM("nonmatchings/game/caquames", DrawTitleMes__8CAquaMesFv);
INCLUDE_ASM("nonmatchings/game/caquames", GetFishPath__FiPc);
INCLUDE_ASM("nonmatchings/game/caquames", GetFishImgPath__FPciP14BREEDFISH_USED);
INCLUDE_ASM("nonmatchings/game/caquames", GetFishImageColor__Fii);
INCLUDE_ASM("nonmatchings/game/caquames", FishIMGReplace__FP1P11CCharacter2iP14BREEDFISH_USED);
INCLUDE_ASM("nonmatchings/game/caquames", DrawFishParam__FiiP10mgCTextureP13CGameDataUsed);
