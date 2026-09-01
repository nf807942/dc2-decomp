/* FISH_PLACE_MAP, sgCPlayVoice
 *
 * Unité découpée par `make carve` : 55 fonctions, 23272 octets, de
 * 0x00304FC0 à 0x0030AC00. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"
#include "gen/sgCPlayVoice.hpp"

/* Les globales que ces accesseurs servent. Leur taille déclarée est celle que
 * le découpage leur donne, et c'est elle qui décide du `%gp_rel`. */
extern s32 ItemOver;
extern s32 MenuOpenFlag;
extern s32 SubGame;
struct FISH_DATA;


INCLUDE_ASM("nonmatchings/game/fish_place_map", CastingLoop__FP6CSceneP11CPadControl);
INCLUDE_ASM("nonmatchings/game/fish_place_map", InitUkiWait__FP6CScene);
INCLUDE_ASM("nonmatchings/game/fish_place_map", ResetUkiCamera__FP14CCameraControl);
INCLUDE_ASM("nonmatchings/game/fish_place_map", UkiWaitLoop__FP6CSceneP11CPadControl);
INCLUDE_ASM("nonmatchings/game/fish_place_map", InitBattle__FP6CScene);
INCLUDE_ASM("nonmatchings/game/fish_place_map", BattleLoop__FP6CSceneP11CPadControl);
INCLUDE_ASM("nonmatchings/game/fish_place_map", GetFishDist__FP6CScene);
INCLUDE_ASM("nonmatchings/game/fish_place_map", DeleteEsa__Fv);
INCLUDE_ASM("nonmatchings/game/fish_place_map", InitFalse__FP6CScene);
INCLUDE_ASM("nonmatchings/game/fish_place_map", FalseLoop__FP6CSceneP11CPadControl);
INCLUDE_ASM("nonmatchings/game/fish_place_map", InitSuccess__FP6CScene);
INCLUDE_ASM("nonmatchings/game/fish_place_map", SuccessLoop__FP6CSceneP11CPadControl);
INCLUDE_ASM("nonmatchings/game/fish_place_map", CheckFishing__FPfP6CCPolyi);
INCLUDE_ASM("nonmatchings/game/fish_place_map", CheckCasting__FP6CScenePfPf);
INCLUDE_ASM("nonmatchings/game/fish_place_map", GetRandamNumber__Ffff);
INCLUDE_ASM("nonmatchings/game/fish_place_map", GetUkiWaitTime__FP9FISH_DATAP6CScenePfii);
INCLUDE_ASM("nonmatchings/game/fish_place_map", GetUkiPokeTime__FP9FISH_DATA);
s32 GetUkiPullTime(FISH_DATA * arg0) {
    return 30;
}
INCLUDE_ASM("nonmatchings/game/fish_place_map", FishLoadBG__FP9FISH_DATAP1);
INCLUDE_ASM("nonmatchings/game/fish_place_map", LineTensionStep__FP9FISH_DATAi);
INCLUDE_ASM("nonmatchings/game/fish_place_map", GetAppearFish__FiPfP10FISH_PLACEi);
INCLUDE_ASM("nonmatchings/game/fish_place_map", SetFishPlace__14FISH_PLACE_MAPFP10FISH_PLACEii);
INCLUDE_ASM("nonmatchings/game/fish_place_map", CheckFishPlace__14FISH_PLACE_MAPFPf);
INCLUDE_ASM("nonmatchings/game/fish_place_map", fpFISH_MAP_NUM__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/fish_place_map", fpFISH_MAP__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/fish_place_map", fpFISH_PLACE__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/fish_place_map", fpFISH__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/fish_place_map", fpFISH_MAP_END__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/fish_place_map", LoadFishPlaceData__FPciP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/fish_place_map", InitSubGame__FP6CScene);
INCLUDE_ASM("nonmatchings/game/fish_place_map", SubGameRunning__Fv);
s32 GetSubGameNo(void) {
    return SubGame;
}
INCLUDE_ASM("nonmatchings/game/fish_place_map", GetNowSubGameInfo__Fv);
INCLUDE_ASM("nonmatchings/game/fish_place_map", sgMenuOpenEnable__Fv);
void sgSetMenuOpenEnableFlag(s32 value) {
    MenuOpenFlag = value;
}
s32 sgGetItemOver(void) {
    return ItemOver;
}
void sgGetItemOverReset(void) {
    ItemOver = 0;
}
void sgGetItemOverFlagOn(void) {
    ItemOver = 1;
}
INCLUDE_ASM("nonmatchings/game/fish_place_map", sgInitSubGame__FiP11SubGameInfo);
INCLUDE_ASM("nonmatchings/game/fish_place_map", sgLoopSubGame__Fv);
INCLUDE_ASM("nonmatchings/game/fish_place_map", sgLoopSubGame2__Fv);
INCLUDE_ASM("nonmatchings/game/fish_place_map", sgExitSubGame__Fv);
INCLUDE_ASM("nonmatchings/game/fish_place_map", sgRestartSubGame__FP11SubGameInfo);
INCLUDE_ASM("nonmatchings/game/fish_place_map", sgBreakSubGame__Fv);
INCLUDE_ASM("nonmatchings/game/fish_place_map", sgDrawSubGameMap__Fv);
INCLUDE_ASM("nonmatchings/game/fish_place_map", sgDrawSubGameCharaShadow__Fv);
INCLUDE_ASM("nonmatchings/game/fish_place_map", sgDrawSubGameChara__Fv);
INCLUDE_ASM("nonmatchings/game/fish_place_map", sgDrawSubGameEffect__Fv);
INCLUDE_ASM("nonmatchings/game/fish_place_map", sgDrawSubGameSystem__Fv);
INCLUDE_ASM("nonmatchings/game/fish_place_map", Open__12sgCPlayVoiceFi);
INCLUDE_ASM("nonmatchings/game/fish_place_map", SetVol__12sgCPlayVoiceFff);
void sgCPlayVoice::Play(void) {
    this->field_0x8 = 1;
}
INCLUDE_ASM("nonmatchings/game/fish_place_map", Step__12sgCPlayVoiceFv);
INCLUDE_ASM("nonmatchings/game/fish_place_map", Close__12sgCPlayVoiceFv);
INCLUDE_ASM("nonmatchings/game/fish_place_map", sgInitGyoRace__FP11SubGameInfo);
