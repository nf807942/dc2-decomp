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
extern "C" void *memset(void *destination, s32 value, u32 size);
struct MENUFORM_MAKEBRD_INFO;


INCLUDE_ASM("nonmatchings/game/cmenuitemuse", CheckRoboShieldKit__FP16CUserDataManagerP13CGameDataUsediPiPi);
INCLUDE_ASM("nonmatchings/game/cmenuitemuse", MenuUseItemCheckFunc__FP13CGameDataUsedP14CItemUseTargeti);
INCLUDE_ASM("nonmatchings/game/cmenuitemuse", CheckItemUseEnable__12CMenuItemUseFP13CGameDataUsediPv);
INCLUDE_ASM("nonmatchings/game/cmenuitemuse", UseItem__12CMenuItemUseFP13CGameDataUsediPv);
typedef struct MenuUsedTarget_champs {
    s32 unk0;
    s32 unk4;
} MenuUsedTarget_champs;
extern "C" MenuUsedTarget_champs MenuUsedTarget;
struct inferred;
typedef struct CGameDataUsed {
    /* 0x0 */ char pad0[2];
    /* 0x2 */ s16 unk2;                             /* inferred */
} CGameDataUsed;                                    /* size >= 0x4 */
typedef struct CItemUseTarget {
    /* 0x0 */ s32 unk0;                             /* inferred */
    /* 0x4 */ s32 unk4;                             /* inferred */
} CItemUseTarget;                                   /* size >= 0x8 */
typedef struct CMenuItemUse {
    /* 0x0 */ s32 unk0;                             /* inferred */
    /* 0x4 */ s32 unk4;                             /* inferred */
} CMenuItemUse;                                     /* size >= 0x8 */
extern "C" s32 MenuUseItemCheckFunc__FP13CGameDataUsedP14CItemUseTargeti(CGameDataUsed *, CItemUseTarget *, s32);
extern "C" s32 UseItem__12CMenuItemUseFP13CGameDataUsedP14CItemUseTarget(CMenuItemUse *objet, CGameDataUsed *arg0, CItemUseTarget *arg1) {
    if (arg0 == NULL) {
        return 0;
    }
    objet->unk0 = (s32) arg0->unk2;
    objet->unk4 = arg1->unk0;
    MenuUsedTarget.unk0 = (s32) arg1->unk0;
    MenuUsedTarget.unk4 = (s32) arg1->unk4;
    return MenuUseItemCheckFunc__FP13CGameDataUsedP14CItemUseTargeti(arg0, arg1, 1);
}
extern "C" void Initialize__12CMenuItemUseFv(CMenuItemUse *objet) {
    objet->unk0 = 0;
    objet->unk4 = 0;
    *(s32 *) ((u8 *) objet + 0x18) = 0;
}
extern "C" s32 CheckNowStateUseThisItem__FP13CGameDataUsedP14CItemUseTarget(CGameDataUsed *arg0, CItemUseTarget *arg1) {
    return MenuUseItemCheckFunc__FP13CGameDataUsedP14CItemUseTargeti(arg0, arg1, 0);
}
INCLUDE_ASM("nonmatchings/game/cmenuitemuse", AttachMessageForm__Fv);
void Init_MENUFORM_MAKEBRD_INFO(MENUFORM_MAKEBRD_INFO * arg0) {
    memset(arg0, 0, 44);
}
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
extern "C" s32 GetMenuPrim__Fv(void);
#include "gen/mgCDrawPrim.hpp"
extern "C" s32 Begin__11mgCDrawPrimFi(void *, s32);
extern "C" s32 Color__11mgCDrawPrimFiiii(void *, s32, s32, s32, s32);
extern "C" s32 DepthTestEnable__11mgCDrawPrimFi(void *, s32);
extern "C" s32 End__11mgCDrawPrimFv(void *);
extern "C" s32 Vertex__11mgCDrawPrimFfff(void *, f32, f32, f32);
extern "C" s32 SetSpriteEnv__FP11mgCDrawPrimi(mgCDrawPrim *, s32);
extern "C" void DrawMenuFillBox__Fffffiiii(f32 arg0, f32 arg1, f32 arg2, f32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    mgCDrawPrim *temp_v0;

    temp_v0 = (mgCDrawPrim *) (GetMenuPrim__Fv());
    SetSpriteEnv__FP11mgCDrawPrimi(temp_v0, 1);
    DepthTestEnable__11mgCDrawPrimFi(temp_v0, 0);
    Begin__11mgCDrawPrimFi(temp_v0, 6);
    Color__11mgCDrawPrimFiiii(temp_v0, arg5, arg6, arg7, arg4);
    Vertex__11mgCDrawPrimFfff(temp_v0, arg0, arg1, 0.0f);
    Vertex__11mgCDrawPrimFfff(temp_v0, arg0 + arg2, arg1 + arg3, 0.0f);
    End__11mgCDrawPrimFv(temp_v0);
}
extern "C" void DrawMenuFillBox__FP11mgCDrawPrimffffiiii(mgCDrawPrim *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8) {
    SetSpriteEnv__FP11mgCDrawPrimi(arg0, 1);
    DepthTestEnable__11mgCDrawPrimFi(arg0, 0);
    Begin__11mgCDrawPrimFi(arg0, 6);
    Color__11mgCDrawPrimFiiii(arg0, arg6, arg7, arg8, arg5);
    Vertex__11mgCDrawPrimFfff(arg0, arg1, arg2, 0.0f);
    Vertex__11mgCDrawPrimFfff(arg0, arg1 + arg3, arg2 + arg4, 0.0f);
    End__11mgCDrawPrimFv(arg0);
}
INCLUDE_ASM("nonmatchings/game/cmenuitemuse", GenarateRandamLine__FPiiiPiii);
INCLUDE_ASM("nonmatchings/game/cmenuitemuse", DrawRandamLine__FP11mgCDrawPrimPiiiPUc);
INCLUDE_ASM("nonmatchings/game/cmenuitemuse", GetMenuDlTexture__Fv);
extern "C" void *Tex_MenuDl;
extern "C" s32 MenuDl_TotalSize;
extern "C" s32 MenuDl_ProcessSize;
extern "C" void InitMenuDl__FP10mgCTexturei(void *arg0, s32 arg1) {
    Tex_MenuDl = arg0;
    MenuDl_TotalSize = arg1;
    MenuDl_ProcessSize = 0;
}
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
extern "C" s32 MenuMainFrame_LeftTop_Pos[2];
extern "C" void *GetMenuMainFrameLeftTopPos__Fi(s32 arg0) {
    return MenuMainFrame_LeftTop_Pos;
}
INCLUDE_ASM("nonmatchings/game/cmenuitemuse", GetMenuMainFrameCount__Fv);
INCLUDE_ASM("nonmatchings/game/cmenuitemuse", MenuMainFrameModeSet__Fii);
