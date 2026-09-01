/* CMenuEffect
 *
 * Unité découpée par `make carve` : 52 fonctions, 23484 octets, de
 * 0x00231DD0 à 0x00237AD0. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

/* Les globales que ces accesseurs servent. Leur taille déclarée est celle que
 * le découpage leur donne, et c'est elle qui décide du `%gp_rel`. */
extern s32 MenuEtcSpecialCode;
extern s8 MenuLoopType;
extern s32 MenuPrim;
extern s32 mgFrameRate;

INCLUDE_ASM("nonmatchings/game/cmenueffect", Initialize__11CMenuEffectFv);
INCLUDE_ASM("nonmatchings/game/cmenueffect", PresetEffect__11CMenuEffectFP9mgCMemoryP10mgCTextureiPi);
INCLUDE_ASM("nonmatchings/game/cmenueffect", SetMemory__11CMenuEffectFP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/cmenueffect", SetTexInfo__11CMenuEffectFP10mgCTexturePi);
INCLUDE_ASM("nonmatchings/game/cmenueffect", SetBaseInfo__11CMenuEffectFPiiii);
INCLUDE_ASM("nonmatchings/game/cmenueffect", EffectStart__11CMenuEffectFv);
INCLUDE_ASM("nonmatchings/game/cmenueffect", PresetInfoAll__11CMenuEffectFi);
INCLUDE_ASM("nonmatchings/game/cmenueffect", PresetInfo__11CMenuEffectFP16MENU_EFFECT_INFOii);
INCLUDE_ASM("nonmatchings/game/cmenueffect", Step__11CMenuEffectFv);
INCLUDE_ASM("nonmatchings/game/cmenueffect", Draw__11CMenuEffectFv);
INCLUDE_ASM("nonmatchings/game/cmenueffect", PrimQuad_f___FP11mgCDrawPrim9mgRect_f_9mgRect_i_);
INCLUDE_ASM("nonmatchings/game/cmenueffect", PrimQuad_i___FP11mgCDrawPrim9mgRect_i_9mgRect_i_);
void MenuScreenBlackBeltSet(s32 arg0) {
}
s32 GetMenuLoopType(void) {
    return MenuLoopType;
}
INCLUDE_ASM("nonmatchings/game/cmenueffect", CheckTrushMenu__Fv);
INCLUDE_ASM("nonmatchings/game/cmenueffect", menu_GetSaveDataDungeon__Fv);
INCLUDE_ASM("nonmatchings/game/cmenueffect", menu_GetBattleAreaScene__Fv);
INCLUDE_ASM("nonmatchings/game/cmenueffect", GetMenuSysData__Fv);
INCLUDE_ASM("nonmatchings/game/cmenueffect", CheckBitFlagMenu__Fi);
INCLUDE_ASM("nonmatchings/game/cmenueffect", CheckShortFlagMenu__Fi);
INCLUDE_ASM("nonmatchings/game/cmenueffect", CheckStartChapter8__FP9CSaveData);
void InitMenuEtcSpecialFlag(void) {
    MenuEtcSpecialCode = 0;
}
INCLUDE_ASM("nonmatchings/game/cmenueffect", SetMenuEtcFlag__Fi);
s32 GetMenuEtcFlag(void) {
    return MenuEtcSpecialCode;
}
s32 GetMenuPrim(void) {
    return MenuPrim;
}
INCLUDE_ASM("nonmatchings/game/cmenueffect", MenuMainImageDataEnter__Fi);
void SetMenuFrameRate(s32 value) {
    mgFrameRate = value;
}
INCLUDE_ASM("nonmatchings/game/cmenueffect", SetMenuKeyCtrlEnv__Fi);
INCLUDE_ASM("nonmatchings/game/cmenueffect", DisablePadReset__Fi);
INCLUDE_ASM("nonmatchings/game/cmenueffect", MenuMainInit__FP13MENU_INIT_ARG);
INCLUDE_ASM("nonmatchings/game/cmenueffect", MenuMainExit__Fv);
INCLUDE_ASM("nonmatchings/game/cmenueffect", MenuMainLoop__Fv);
INCLUDE_ASM("nonmatchings/game/cmenueffect", MenuMainKey__Fv);
INCLUDE_ASM("nonmatchings/game/cmenueffect", MenuMainDraw__Fv);
INCLUDE_ASM("nonmatchings/game/cmenueffect", NextMenuInit__FiP9mgCMemoryPi);
INCLUDE_ASM("nonmatchings/game/cmenueffect", MenuCamInit__Ff);
INCLUDE_ASM("nonmatchings/game/cmenueffect", MenuWorldTrans__Fv);
INCLUDE_ASM("nonmatchings/game/cmenueffect", MenuPolygonSetEnv__Fv);
INCLUDE_ASM("nonmatchings/game/cmenueffect", MenuPolygonEnvReset__Fv);
INCLUDE_ASM("nonmatchings/game/cmenueffect", GetMenuCfgFileName__Fii);
INCLUDE_ASM("nonmatchings/game/cmenueffect", GetMenuMainMessageBuffer__Fv);
INCLUDE_ASM("nonmatchings/game/cmenueffect", GetMenuMainIMGPtr__Fv);
INCLUDE_ASM("nonmatchings/game/cmenueffect", GetMenuMainPosCfgBuffer__FPi);
INCLUDE_ASM("nonmatchings/game/cmenueffect", SetCommonMenuModeID__Fv);
INCLUDE_ASM("nonmatchings/game/cmenueffect", GetCommonMenuModeID__Fv);
INCLUDE_ASM("nonmatchings/game/cmenueffect", CursorSaveOptionState__Fv);
INCLUDE_ASM("nonmatchings/game/cmenueffect", ReturnMenuIntern__Fi);
INCLUDE_ASM("nonmatchings/game/cmenueffect", MenuAreaBoardNameStep__Fv);
INCLUDE_ASM("nonmatchings/game/cmenueffect", CheckEventDay__FPi);
INCLUDE_ASM("nonmatchings/game/cmenueffect", MakeMenuTopic__Fv);
INCLUDE_ASM("nonmatchings/game/cmenueffect", DrawMenuTopic__Fv);
INCLUDE_ASM("nonmatchings/game/cmenueffect", MenuInternInit__FP9mgCMemoryii);
