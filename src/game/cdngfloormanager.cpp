/* CDngFloorManager, CStarEffect, CPlaceAnime, CPaintEffect
 *
 * Unité découpée par `make carve` : 68 fonctions, 24440 octets, de
 * 0x002FEED0 à 0x00304FC0. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"
#include "gen/PlaceAnimeData.hpp"

/* Les globales que ces accesseurs servent. Leur taille déclarée est celle que
 * le découpage leur donne, et c'est elle qui décide du `%gp_rel`. */
extern s32 NextCharaMode;
extern s32 RetCode;
struct CScene;

extern PlaceAnimeData PlaceAnime;


INCLUDE_ASM("nonmatchings/game/cdngfloormanager", GetActiveFloorInfo__16CDngFloorManagerFv);
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", RelationGlid__16CDngFloorManagerFv);
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", CheckDrawGlidInfo__16CDngFloorManagerFv);
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", GetNextGlid__16CDngFloorManagerFP9GLID_INFOPi);
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", GetNextRoom__16CDngFloorManagerFiiP9GLID_INFOiPi);
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", GetKeyNextRoom__16CDngFloorManagerFiiP9GLID_INFO);
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", GetDngMapNextFloorID__16CDngFloorManagerFii);
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", GetFloorTitle__16CDngFloorManagerFi);
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", GetDngMapNextRoot__16CDngFloorManagerFi);
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", GetCountSphedaClear__Fv);
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", CheckFishingRecord__Ff);
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", EditSetEffectBuffer__FP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", __ct__12CPaintEffectFv);
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", EditInitPlaceEffect__Fv);
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", EditPlaceEffect__FP10CEditPartsPf);
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", EditPaintEffect__FP10CEditPartsPfPfi);
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", EditPEffectStep__Fv);
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", EditPEffectDraw__Fi);
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", EditGetPEffectState__Fv);
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", EditPEffectEndCheck__Fv);
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", ParamInit__11CStarEffectFPfi);
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", Step__11CStarEffectFv);
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", Draw__11CStarEffectFv);
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", ParamInit__12CPaintEffectFf);
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", Step__12CPaintEffectFv);
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", Draw__12CPaintEffectFv);
void EditInitPlaceAnime(void) {
    PlaceAnime.field_0x0 = 0;
    PlaceAnime.field_0x4 = 0;
    PlaceAnime.field_0x8 = 0;
    PlaceAnime.field_0x90 = 0;
    PlaceAnime.field_0x94 = 0;
    PlaceAnime.field_0x98 = 0;
    PlaceAnime.field_0x120 = 0;
    PlaceAnime.field_0x124 = 0;
    PlaceAnime.field_0x128 = 0;
}
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", EditNowPlaceAnime__Fv);
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", EditSetPlaceAnime__FiP9CMapParts);
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", EditPlaceAnime__Fv);
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", EditPlaceAnime2__Fv);
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", EditPlaceAnimeDraw__Fv);
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", Step__11CPlaceAnimeFv);
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", Step2__11CPlaceAnimeFv);
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", Draw__11CPlaceAnimeFv);
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", EditGetPlaceAnimeState__Fv);
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", EditPlaceAnimeEndCheck__Fv);
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", __ct__11CStarEffectFv);
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", GetFishParam__Fi);
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", EsaInit__Fv);
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", ReplayPrevBGM__FP6CScene);
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", LoadExMotionBG__FP11SubGameInfoP1);
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", LoadExMotionStep__FP11SubGameInfoP9mgCMemory);
void SetNextMode(s32 value) {
    NextCharaMode = value;
}
void ExitFishing(CScene * arg0) {
    RetCode = 1;
}
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", sgInitFishing__FP11SubGameInfo);
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", sgRestartFishing__FP11SubGameInfo);
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", InitDataLoading__Fv);
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", switch_thread__Fv);
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", CreateLoadThread__FP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", StepLoadThread__Fv);
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", DeleteLoadThread__Fv);
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", StepDataLoading__FPv);
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", sgBreakFishing__Fv);
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", sgExitFishing__FP11SubGameInfo);
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", sgLoopFishing__FP11SubGameInfo);
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", sgLoopFishing2__FP11SubGameInfo);
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", sgDrawFishing__FP11SubGameInfo);
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", DrawNumber__FP11mgCDrawPrimiii);
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", sgSystemDrawFishing__FP11SubGameInfo);
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", CharaControl__FP6CSceneP11CPadControl_00303FC0);
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", InitSelectCastingPoint__FP6CScene);
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", EndSelectCastingPoint__FP6CScene);
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", SelectCastingPoint__FP6CSceneP11CPadControl);
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", DrawHamon__FPff);
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", DrawSplash__FPff);
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", GetMotionCount__FP11CCharacter2Pciii);
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", InitCasting__FP6CScene);
