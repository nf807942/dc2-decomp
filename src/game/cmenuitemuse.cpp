/* CMenuItemUse
 *
 * Unité découpée par `make carve` : 59 fonctions, 23324 octets, de
 * 0x00220740 à 0x002263C0. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

/* Les globales que ces accesseurs servent. Leur taille déclarée est celle que
 * le découpage leur donne, et c'est elle qui décide du `%gp_rel`. */
extern s8 MenuDrawNumberKeta;
extern u8 MenuMainFrame_ActionEndFlag;

INCLUDE_ASM("nonmatchings/game/cmenuitemuse", CheckRoboShieldKit__FP16CUserDataManagerP13CGameDataUsediPiPi);
INCLUDE_ASM("nonmatchings/game/cmenuitemuse", MenuUseItemCheckFunc__FP13CGameDataUsedP14CItemUseTargeti);
INCLUDE_ASM("nonmatchings/game/cmenuitemuse", CheckItemUseEnable__12CMenuItemUseFP13CGameDataUsediPv);
INCLUDE_ASM("nonmatchings/game/cmenuitemuse", UseItem__12CMenuItemUseFP13CGameDataUsediPv);
INCLUDE_ASM("nonmatchings/game/cmenuitemuse", UseItem__12CMenuItemUseFP13CGameDataUsedP14CItemUseTarget);
INCLUDE_ASM("nonmatchings/game/cmenuitemuse", Initialize__12CMenuItemUseFv);
INCLUDE_ASM("nonmatchings/game/cmenuitemuse", CheckNowStateUseThisItem__FP13CGameDataUsedP14CItemUseTarget);
INCLUDE_ASM("nonmatchings/game/cmenuitemuse", AttachMessageForm__Fv);
INCLUDE_ASM("nonmatchings/game/cmenuitemuse", Init_MENUFORM_MAKEBRD_INFO__FP21MENUFORM_MAKEBRD_INFO);
INCLUDE_ASM("nonmatchings/game/cmenuitemuse", GetMenuItemIconTexGetXY__FiR9mgRect_i_);
INCLUDE_ASM("nonmatchings/game/cmenuitemuse", GetMenuItemIconTexInfo__Fii);
INCLUDE_ASM("nonmatchings/game/cmenuitemuse", ConvMGIRECTtoINTtbl__F9mgRect_i_Pi);
INCLUDE_ASM("nonmatchings/game/cmenuitemuse", ConvMGFRECTtoFLOATtbl__F9mgRect_f_Pf);
INCLUDE_ASM("nonmatchings/game/cmenuitemuse", SetPartEffectInfoRandFunc__FP25MENU_PARTS_EFFECT_STRUCT1);
INCLUDE_ASM("nonmatchings/game/cmenuitemuse", SetPartEffectInfoRandFunc__FP25MENU_PARTS_EFFECT_STRUCT1Psi);
INCLUDE_ASM("nonmatchings/game/cmenuitemuse", SetSpriteEnv__FP11mgCDrawPrimi);
INCLUDE_ASM("nonmatchings/game/cmenuitemuse", PushPrimRepeat__FP11mgCDrawPrimPfPii);
INCLUDE_ASM("nonmatchings/game/cmenuitemuse", PrimQuad__FP11mgCDrawPrimff9mgRect_i_);
INCLUDE_ASM("nonmatchings/game/cmenuitemuse", PrimQuad__FP10mgCTextureff9mgRect_i_iiii);
INCLUDE_ASM("nonmatchings/game/cmenuitemuse", PrimQuad__FP11mgCDrawPrimP10mgCTextureff9mgRect_i_iiii);
INCLUDE_ASM("nonmatchings/game/cmenuitemuse", PrimQuad__FP10mgCTexture9mgRect_i_9mgRect_i_iiii);
INCLUDE_ASM("nonmatchings/game/cmenuitemuse", PrimQuad__FP11mgCDrawPrimP10mgCTexture9mgRect_i_9mgRect_i_iiii);
INCLUDE_ASM("nonmatchings/game/cmenuitemuse", MenuClipRectCheck__FR9mgRect_i_);
INCLUDE_ASM("nonmatchings/game/cmenuitemuse", SetMenuScissor__F9mgRect_i_);
INCLUDE_ASM("nonmatchings/game/cmenuitemuse", ResetMenuScissor__Fv);
INCLUDE_ASM("nonmatchings/game/cmenuitemuse", SetModeMenuDrawItemBoard__Fi);
INCLUDE_ASM("nonmatchings/game/cmenuitemuse", EnableUseItemAlphaStep__Fv);
INCLUDE_ASM("nonmatchings/game/cmenuitemuse", InitSpectolRasterTable__FP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/cmenuitemuse", DrawOneItem__FP11mgCDrawPrim9mgRect_f_iiP25MENU_PARTS_EFFECT_STRUCT1PUci);
INCLUDE_ASM("nonmatchings/game/cmenuitemuse", MenuWindowHelp__FP11mgCDrawPrimP10mgCTextureffffPs);
INCLUDE_ASM("nonmatchings/game/cmenuitemuse", MenuPresentBoxView__FiiRiP10mgCTextureP10mgCTexture);
void SetMenuDrawNumberKeta(char value) {
    MenuDrawNumberKeta = value;
}
INCLUDE_ASM("nonmatchings/game/cmenuitemuse", DrawMenuNumber__FP11mgCDrawPrimii9mgRect_i_9mgRect_i_ii);
INCLUDE_ASM("nonmatchings/game/cmenuitemuse", PrimDrawNumber__FP11mgCDrawPrimiiii9mgRect_i_ii);
INCLUDE_ASM("nonmatchings/game/cmenuitemuse", PrimDrawNumber2__FP11mgCDrawPrimiiii9mgRect_i_ii);
INCLUDE_ASM("nonmatchings/game/cmenuitemuse", PrimFillRect4__FP11mgCDrawPrim9mgRect_f_PfPfPfPf);
INCLUDE_ASM("nonmatchings/game/cmenuitemuse", MenuReloadTexture__FRii);
INCLUDE_ASM("nonmatchings/game/cmenuitemuse", MenuReloadCLUT__Fi);
INCLUDE_ASM("nonmatchings/game/cmenuitemuse", DrawMenuFillBox__Fiiii);
INCLUDE_ASM("nonmatchings/game/cmenuitemuse", DrawMenuFillBox__Fffffiiii);
INCLUDE_ASM("nonmatchings/game/cmenuitemuse", DrawMenuFillBox__FP11mgCDrawPrimffffiiii);
INCLUDE_ASM("nonmatchings/game/cmenuitemuse", GenarateRandamLine__FPiiiPiii);
INCLUDE_ASM("nonmatchings/game/cmenuitemuse", DrawRandamLine__FP11mgCDrawPrimPiiiPUc);
INCLUDE_ASM("nonmatchings/game/cmenuitemuse", GetMenuDlTexture__Fv);
INCLUDE_ASM("nonmatchings/game/cmenuitemuse", InitMenuDl__FP10mgCTexturei);
INCLUDE_ASM("nonmatchings/game/cmenuitemuse", StepMenuDl__Fi);
INCLUDE_ASM("nonmatchings/game/cmenuitemuse", StepMenuDl2__Fi);
INCLUDE_ASM("nonmatchings/game/cmenuitemuse", DrawMenuDl__FRiiiii);
INCLUDE_ASM("nonmatchings/game/cmenuitemuse", DrawMenuDl__Fi);
INCLUDE_ASM("nonmatchings/game/cmenuitemuse", CalcCommonBrdDrawInfo__FPfP21MENUFORM_MAKEBRD_INFOP6ClsMes);
INCLUDE_ASM("nonmatchings/game/cmenuitemuse", CommonBoardDraw__FPfRi);
INCLUDE_ASM("nonmatchings/game/cmenuitemuse", MenuCursorDraw__FP10mgCTexturePffiif);
INCLUDE_ASM("nonmatchings/game/cmenuitemuse", MenuCursorDraw__FP10mgCTexturePffi);
INCLUDE_ASM("nonmatchings/game/cmenuitemuse", DrawMenuTilePattern__FP11mgCDrawPrimP10mgCTextureff9mgRect_i_iPUc);
INCLUDE_ASM("nonmatchings/game/cmenuitemuse", DrawMenuMainFrmImg__FRi9mgRect_i_9mgRect_i_iiiii);
s32 GetMenuMainFrameEndFlag(void) {
    return MenuMainFrame_ActionEndFlag;
}
INCLUDE_ASM("nonmatchings/game/cmenuitemuse", GetMenuMainFrameLeftTopPos__Fi);
INCLUDE_ASM("nonmatchings/game/cmenuitemuse", GetMenuMainFrameCount__Fv);
INCLUDE_ASM("nonmatchings/game/cmenuitemuse", MenuMainFrameModeSet__Fii);
