/* CDngFloorManager, CStarEffect, CPlaceAnime, CPaintEffect
 *
 * Unité découpée par `make carve` : 68 fonctions, 24440 octets, de
 * 0x002FEED0 à 0x00304FC0. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

INCLUDE_ASM("nonmatchings/cdngfloormanager", GetActiveFloorInfo__16CDngFloorManagerFv);
INCLUDE_ASM("nonmatchings/cdngfloormanager", RelationGlid__16CDngFloorManagerFv);
INCLUDE_ASM("nonmatchings/cdngfloormanager", CheckDrawGlidInfo__16CDngFloorManagerFv);
INCLUDE_ASM("nonmatchings/cdngfloormanager", GetNextGlid__16CDngFloorManagerFP9GLID_INFOPi);
INCLUDE_ASM("nonmatchings/cdngfloormanager", GetNextRoom__16CDngFloorManagerFiiP9GLID_INFOiPi);
INCLUDE_ASM("nonmatchings/cdngfloormanager", GetKeyNextRoom__16CDngFloorManagerFiiP9GLID_INFO);
INCLUDE_ASM("nonmatchings/cdngfloormanager", GetDngMapNextFloorID__16CDngFloorManagerFii);
INCLUDE_ASM("nonmatchings/cdngfloormanager", GetFloorTitle__16CDngFloorManagerFi);
INCLUDE_ASM("nonmatchings/cdngfloormanager", GetDngMapNextRoot__16CDngFloorManagerFi);
INCLUDE_ASM("nonmatchings/cdngfloormanager", GetCountSphedaClear__Fv);
INCLUDE_ASM("nonmatchings/cdngfloormanager", CheckFishingRecord__Ff);
INCLUDE_ASM("nonmatchings/cdngfloormanager", EditSetEffectBuffer__FP9mgCMemory);
INCLUDE_ASM("nonmatchings/cdngfloormanager", __ct__12CPaintEffectFv);
INCLUDE_ASM("nonmatchings/cdngfloormanager", EditInitPlaceEffect__Fv);
INCLUDE_ASM("nonmatchings/cdngfloormanager", EditPlaceEffect__FP10CEditPartsPf);
INCLUDE_ASM("nonmatchings/cdngfloormanager", EditPaintEffect__FP10CEditPartsPfPfi);
INCLUDE_ASM("nonmatchings/cdngfloormanager", EditPEffectStep__Fv);
INCLUDE_ASM("nonmatchings/cdngfloormanager", EditPEffectDraw__Fi);
INCLUDE_ASM("nonmatchings/cdngfloormanager", EditGetPEffectState__Fv);
INCLUDE_ASM("nonmatchings/cdngfloormanager", EditPEffectEndCheck__Fv);
INCLUDE_ASM("nonmatchings/cdngfloormanager", ParamInit__11CStarEffectFPfi);
INCLUDE_ASM("nonmatchings/cdngfloormanager", Step__11CStarEffectFv);
INCLUDE_ASM("nonmatchings/cdngfloormanager", Draw__11CStarEffectFv);
INCLUDE_ASM("nonmatchings/cdngfloormanager", ParamInit__12CPaintEffectFf);
INCLUDE_ASM("nonmatchings/cdngfloormanager", Step__12CPaintEffectFv);
INCLUDE_ASM("nonmatchings/cdngfloormanager", Draw__12CPaintEffectFv);
INCLUDE_ASM("nonmatchings/cdngfloormanager", EditInitPlaceAnime__Fv);
INCLUDE_ASM("nonmatchings/cdngfloormanager", EditNowPlaceAnime__Fv);
INCLUDE_ASM("nonmatchings/cdngfloormanager", EditSetPlaceAnime__FiP9CMapParts);
INCLUDE_ASM("nonmatchings/cdngfloormanager", EditPlaceAnime__Fv);
INCLUDE_ASM("nonmatchings/cdngfloormanager", EditPlaceAnime2__Fv);
INCLUDE_ASM("nonmatchings/cdngfloormanager", EditPlaceAnimeDraw__Fv);
INCLUDE_ASM("nonmatchings/cdngfloormanager", Step__11CPlaceAnimeFv);
INCLUDE_ASM("nonmatchings/cdngfloormanager", Step2__11CPlaceAnimeFv);
INCLUDE_ASM("nonmatchings/cdngfloormanager", Draw__11CPlaceAnimeFv);
INCLUDE_ASM("nonmatchings/cdngfloormanager", EditGetPlaceAnimeState__Fv);
INCLUDE_ASM("nonmatchings/cdngfloormanager", EditPlaceAnimeEndCheck__Fv);
INCLUDE_ASM("nonmatchings/cdngfloormanager", __ct__11CStarEffectFv);
INCLUDE_ASM("nonmatchings/cdngfloormanager", GetFishParam__Fi);
INCLUDE_ASM("nonmatchings/cdngfloormanager", EsaInit__Fv);
INCLUDE_ASM("nonmatchings/cdngfloormanager", ReplayPrevBGM__FP6CScene);
INCLUDE_ASM("nonmatchings/cdngfloormanager", LoadExMotionBG__FP11SubGameInfoP1);
INCLUDE_ASM("nonmatchings/cdngfloormanager", LoadExMotionStep__FP11SubGameInfoP9mgCMemory);
INCLUDE_ASM("nonmatchings/cdngfloormanager", SetNextMode__Fi);
INCLUDE_ASM("nonmatchings/cdngfloormanager", ExitFishing__FP6CScene);
INCLUDE_ASM("nonmatchings/cdngfloormanager", sgInitFishing__FP11SubGameInfo);
INCLUDE_ASM("nonmatchings/cdngfloormanager", sgRestartFishing__FP11SubGameInfo);
INCLUDE_ASM("nonmatchings/cdngfloormanager", InitDataLoading__Fv);
INCLUDE_ASM("nonmatchings/cdngfloormanager", switch_thread__Fv);
INCLUDE_ASM("nonmatchings/cdngfloormanager", CreateLoadThread__FP9mgCMemory);
INCLUDE_ASM("nonmatchings/cdngfloormanager", StepLoadThread__Fv);
INCLUDE_ASM("nonmatchings/cdngfloormanager", DeleteLoadThread__Fv);
INCLUDE_ASM("nonmatchings/cdngfloormanager", StepDataLoading__FPv);
INCLUDE_ASM("nonmatchings/cdngfloormanager", sgBreakFishing__Fv);
INCLUDE_ASM("nonmatchings/cdngfloormanager", sgExitFishing__FP11SubGameInfo);
INCLUDE_ASM("nonmatchings/cdngfloormanager", sgLoopFishing__FP11SubGameInfo);
INCLUDE_ASM("nonmatchings/cdngfloormanager", sgLoopFishing2__FP11SubGameInfo);
INCLUDE_ASM("nonmatchings/cdngfloormanager", sgDrawFishing__FP11SubGameInfo);
INCLUDE_ASM("nonmatchings/cdngfloormanager", DrawNumber__FP11mgCDrawPrimiii);
INCLUDE_ASM("nonmatchings/cdngfloormanager", sgSystemDrawFishing__FP11SubGameInfo);
INCLUDE_ASM("nonmatchings/cdngfloormanager", CharaControl__FP6CSceneP11CPadControl_00303FC0);
INCLUDE_ASM("nonmatchings/cdngfloormanager", InitSelectCastingPoint__FP6CScene);
INCLUDE_ASM("nonmatchings/cdngfloormanager", EndSelectCastingPoint__FP6CScene);
INCLUDE_ASM("nonmatchings/cdngfloormanager", SelectCastingPoint__FP6CSceneP11CPadControl);
INCLUDE_ASM("nonmatchings/cdngfloormanager", DrawHamon__FPff);
INCLUDE_ASM("nonmatchings/cdngfloormanager", DrawSplash__FPff);
INCLUDE_ASM("nonmatchings/cdngfloormanager", GetMotionCount__FP11CCharacter2Pciii);
INCLUDE_ASM("nonmatchings/cdngfloormanager", InitCasting__FP6CScene);
