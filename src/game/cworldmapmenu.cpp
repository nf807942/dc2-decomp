/* CWorldMapMenu
 *
 * Unité découpée par `make carve` : 25 fonctions, 18828 octets, de
 * 0x002AFEE0 à 0x002B4920. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"
#include "gen/MENU_BGREAD_INFO2.hpp"

INCLUDE_ASM("nonmatchings/game/cworldmapmenu", SetMsgBuffer__13CWorldMapMenuFv);
INCLUDE_ASM("nonmatchings/game/cworldmapmenu", KeyStep__13CWorldMapMenuFv);
INCLUDE_ASM("nonmatchings/game/cworldmapmenu", Draw__13CWorldMapMenuFv);
INCLUDE_ASM("nonmatchings/game/cworldmapmenu", WorldMoveInit__FP9mgCMemoryPii);
INCLUDE_ASM("nonmatchings/game/cworldmapmenu", WorldMoveKey__Fv);
INCLUDE_ASM("nonmatchings/game/cworldmapmenu", WorldMoveDraw__Fv);
INCLUDE_ASM("nonmatchings/game/cworldmapmenu", SphidaScreListUpdate__FP7CDC2Mesi);
INCLUDE_ASM("nonmatchings/game/cworldmapmenu", SphidaMenuInit__FP9mgCMemoryPii);
INCLUDE_ASM("nonmatchings/game/cworldmapmenu", OmakeSfidaSelect__Fi);
INCLUDE_ASM("nonmatchings/game/cworldmapmenu", SphidaMenuKey__Fv);
INCLUDE_ASM("nonmatchings/game/cworldmapmenu", SphidaMenuDraw__Fv);
INCLUDE_ASM("nonmatchings/game/cworldmapmenu", SphidaScoreViewInit__FP9mgCMemoryPii);
INCLUDE_ASM("nonmatchings/game/cworldmapmenu", SphidaScoreViewKey__Fv);
INCLUDE_ASM("nonmatchings/game/cworldmapmenu", SphidaScoreViewDraw__Fv);
void InitMenuBGReadInfo2(MENU_BGREAD_INFO2 * arg0) {
    arg0->field_0x70 = 0;
    arg0->field_0x74 = 0;
    arg0->field_0x0 = 0;
    arg0->field_0x20 = 0;
}
INCLUDE_ASM("nonmatchings/game/cworldmapmenu", MenuLoadFileCheck__FPP17MENU_BGREAD_INFO2);
INCLUDE_ASM("nonmatchings/game/cworldmapmenu", MenuBGReadInfo2Malloc__FP9mgCMemoryPi);
INCLUDE_ASM("nonmatchings/game/cworldmapmenu", ConvertCharaLoadDataPhase__Fii);
INCLUDE_ASM("nonmatchings/game/cworldmapmenu", CheckBattleLoop__Fv);
INCLUDE_ASM("nonmatchings/game/cworldmapmenu", SetMenuLoadItemNo__Fi);
INCLUDE_ASM("nonmatchings/game/cworldmapmenu", MenuMemoryDivide__FP9mgCMemoryPP9mgCMemoryi);
INCLUDE_ASM("nonmatchings/game/cworldmapmenu", MenuMemoryAdjust__FP9mgCMemoryP9mgCMemoryP9mgCMemoryi);
typedef struct FxScriptMan_pointe {
    char pad0[12];
    s32 unkC;
} FxScriptMan_pointe;
extern "C" FxScriptMan_pointe *FxScriptMan;
extern "C" u8 mgTexManager[540];
struct inferred;
typedef struct CEffectScriptMan {
    /* 0x00 */ char pad0[0xC];
    /* 0x0C */ s32 unkC;                            /* inferred */
} CEffectScriptMan;                                 /* size >= 0x10 */
extern "C" s32 ClearBaseFromLevel__16CEffectScriptManFiPii(void *, s32, s32 *, s32);
extern "C" s32 ClearEffectFromChrid__16CEffectScriptManFi(void *, s32);
extern "C" s32 DeleteBlock__17mgCTextureManagerFi(void *, s32);
extern "C" void DeleteMonsterEffect__Fv(void) {
    if (FxScriptMan != NULL) {
        ClearEffectFromChrid__16CEffectScriptManFi(FxScriptMan, 0);
        FxScriptMan->unkC = 2;
        ClearBaseFromLevel__16CEffectScriptManFiPii(FxScriptMan, 2, NULL, -1);
    }
    DeleteBlock__17mgCTextureManagerFi(&mgTexManager, 0xAA);
}
INCLUDE_ASM("nonmatchings/game/cworldmapmenu", SetMessagePositionNPCForm__FP16CMenuPosDataFormP7CDC2Mes);
INCLUDE_ASM("nonmatchings/game/cworldmapmenu", AdjustNPCTalk__FP7CDC2MesP11CCharacter2);
