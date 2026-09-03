/* CMenuEffect
 *
 * Unité découpée par `make carve` : 52 fonctions, 23484 octets, de
 * 0x00231DD0 à 0x00237AD0. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"
#include "gen/CMenuEffect.hpp"

/* Les globales que ces accesseurs servent. Leur taille déclarée est celle que
 * le découpage leur donne, et c'est elle qui décide du `%gp_rel`. */
extern s32 MenuEtcSpecialCode;
extern s8 MenuLoopType;
extern s32 MenuPrim;
extern s32 mgFrameRate;

void CMenuEffect::Initialize(void) {
    this->field_0x0 = 0;
    this->field_0x4 = 0;
    this->field_0x9 = -1;
    this->field_0xA = 0;
    this->field_0xC = 0;
    this->field_0x10 = 0;
    this->field_0x34 = 128;
}
INCLUDE_ASM("nonmatchings/game/cmenueffect", PresetEffect__11CMenuEffectFP9mgCMemoryP10mgCTextureiPi);
struct inferred;
#include "menu.hpp"
typedef struct CMenuEffect_infere {
    /* 0x00 */ char pad0[0xC];
    /* 0x0C */ s16 unkC;                            /* inferred */
    /* 0x0E */ char padE[2];
    /* 0x10 */ s32 unk10;                           /* inferred */
} CMenuEffect_infere;                                      /* size >= 0x14 */
extern "C" s32 Alloc__9mgCMemoryFi(void *, s32);
extern "C" void SetMemory__11CMenuEffectFP9mgCMemory(CMenuEffect_infere *objet, mgCMemory *arg0) {
    u32 temp_v1;
    u32 var_v0;

    temp_v1 = (u32) (objet->unkC << 6);
    if (temp_v1 & 0xF) {
        var_v0 = (temp_v1 >> 4) + 1;
    } else {
        var_v0 = temp_v1 >> 4;
    }
    objet->unk10 = Alloc__9mgCMemoryFi(arg0, var_v0);
}
INCLUDE_ASM("nonmatchings/game/cmenueffect", SetTexInfo__11CMenuEffectFP10mgCTexturePi);
INCLUDE_ASM("nonmatchings/game/cmenueffect", SetBaseInfo__11CMenuEffectFPiiii);
void CMenuEffect::EffectStart(void) {
    this->field_0xA = 1;
    this->field_0x36 = 0;
}
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
extern "C" s32 GetMainScene__Fv(void);
extern "C" s32 menu_GetBattleAreaScene__Fv(void) {
    s32 temp_v0;

    temp_v0 = GetMainScene__Fv();
    if (temp_v0 != 0) {
        return temp_v0 + 0x2F90;
    }
    return 0;
}
INCLUDE_ASM("nonmatchings/game/cmenueffect", GetMenuSysData__Fv);
extern "C" s32 GetSaveData__Fv(void);
#include "dngfloormanager.hpp"
extern "C" s32 GetBitFlag__9CSaveDataFi(void *, s32);
extern "C" s32 CheckBitFlagMenu__Fi(s32 arg0) {
    CSaveData *temp_v0;

    temp_v0 = (CSaveData *) (GetSaveData__Fv());
    if (temp_v0 != NULL) {
        return GetBitFlag__9CSaveDataFi(temp_v0, arg0);
    }
    return 0;
}
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
extern "C" s32 MenuMainDraw__Fv(void);
extern "C" s32 MenuMainKey__Fv(void);
extern "C" s32 MenuMainLoop__Fv(void) {
    s32 temp_s0;

    temp_s0 = MenuMainKey__Fv();
    MenuMainDraw__Fv();
    return temp_s0;
}
INCLUDE_ASM("nonmatchings/game/cmenueffect", MenuMainKey__Fv);
INCLUDE_ASM("nonmatchings/game/cmenueffect", MenuMainDraw__Fv);
INCLUDE_ASM("nonmatchings/game/cmenueffect", NextMenuInit__FiP9mgCMemoryPi);
INCLUDE_ASM("nonmatchings/game/cmenueffect", MenuCamInit__Ff);
INCLUDE_ASM("nonmatchings/game/cmenueffect", MenuWorldTrans__Fv);
extern "C" u32 MenuDrawEnv;
extern "C" s32 mgGetAmbient__FPf(...);
extern "C" s32 mgSetAmbient__FPf(...);
extern "C" void MenuPolygonSetEnv__Fv(void) {
    mgGetAmbient__FPf(MenuDrawEnv + 0xB0);
    mgSetAmbient__FPf(MenuDrawEnv + 0xC0);
}
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
