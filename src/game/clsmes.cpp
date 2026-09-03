/* ClsMes, CMapFlagData
 *
 * Unité découpée par `make carve` : 52 fonctions, 24632 octets, de
 * 0x00157790 à 0x0015D920. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

INCLUDE_ASM("nonmatchings/game/clsmes", AddYokoHaba__6ClsMesFii);
INCLUDE_ASM("nonmatchings/game/clsmes", SetYokoHaba__6ClsMesFii);
INCLUDE_ASM("nonmatchings/game/clsmes", AddPage__6ClsMesFii);
INCLUDE_ASM("nonmatchings/game/clsmes", NeedMesWinWH__6ClsMesFi);
INCLUDE_ASM("nonmatchings/game/clsmes", NeedMesWinWH__6ClsMesFPc);
INCLUDE_ASM("nonmatchings/game/clsmes", MakeMesWin_init__6ClsMesFi);
INCLUDE_ASM("nonmatchings/game/clsmes", MakeMesWin__6ClsMesFi);
INCLUDE_ASM("nonmatchings/game/clsmes", PreMesMake__FPcPc);
INCLUDE_ASM("nonmatchings/game/clsmes", MakeMesWin__6ClsMesFPcii);
INCLUDE_ASM("nonmatchings/game/clsmes", MakeAnd3DPosSet__6ClsMesFPcPfii);
INCLUDE_ASM("nonmatchings/game/clsmes", DrawFukidashiShadow__6ClsMesFv);
INCLUDE_ASM("nonmatchings/game/clsmes", CalcRectScale__F4RECTfP4RECT);
INCLUDE_ASM("nonmatchings/game/clsmes", SetSelectCursorPos__6ClsMesF4RECT);
INCLUDE_ASM("nonmatchings/game/clsmes", DrawYesNo__FP11mgCDrawPrimiiiiP10RGBAQ_TYPE);
INCLUDE_ASM("nonmatchings/game/clsmes", GetPos_AbsPosSet__F4RECTiiiPiPi);
INCLUDE_ASM("nonmatchings/game/clsmes", CalcAutoPosSet__Fffff);
INCLUDE_ASM("nonmatchings/game/clsmes", RgbqToUint__FUi);
INCLUDE_ASM("nonmatchings/game/clsmes", GetFontColor__6ClsMesFiPi);
INCLUDE_ASM("nonmatchings/game/clsmes", GetGyouAlpha__6ClsMesFi);
INCLUDE_ASM("nonmatchings/game/clsmes", DrawFont__6ClsMesFv);
INCLUDE_ASM("nonmatchings/game/clsmes", SetGoalCursorXY__6ClsMesFv);
INCLUDE_ASM("nonmatchings/game/clsmes", StepSelectCursor__6ClsMesFi);
INCLUDE_ASM("nonmatchings/game/clsmes", DrawSelectCursor__6ClsMesFP11mgCDrawPrim);
INCLUDE_ASM("nonmatchings/game/clsmes", DrawEquipment__6ClsMesFP11mgCDrawPrim);
INCLUDE_ASM("nonmatchings/game/clsmes", DrawCross__6ClsMesFP11mgCDrawPrim);
INCLUDE_ASM("nonmatchings/game/clsmes", DrawRightDelta__6ClsMesFP11mgCDrawPrim);
INCLUDE_ASM("nonmatchings/game/clsmes", DrawDigit__6ClsMesFP11mgCDrawPrimiiiiP10RGBAQ_TYPE);
INCLUDE_ASM("nonmatchings/game/clsmes", DrawPushButton__6ClsMesFP11mgCDrawPrimii);
INCLUDE_ASM("nonmatchings/game/clsmes", CalcCenteringXY__6ClsMesFPiPi);
INCLUDE_ASM("nonmatchings/game/clsmes", SetAbsWinData__6ClsMesFP4RECT);
INCLUDE_ASM("nonmatchings/game/clsmes", SetOuterRectXYFromFukidashiPos__6ClsMesFP4RECT);
INCLUDE_ASM("nonmatchings/game/clsmes", CalcWindowOutRectFromInRect__Fi4RECTP4RECT);
INCLUDE_ASM("nonmatchings/game/clsmes", CalcWindowInRectFromOutRect__Fi4RECTP4RECT);
INCLUDE_ASM("nonmatchings/game/clsmes", DrawMesWin__6ClsMesFv);
INCLUDE_ASM("nonmatchings/game/clsmes", Parametric__FPfPfPf);
INCLUDE_ASM("nonmatchings/game/clsmes", Quadratic__FfffPfPf);
INCLUDE_ASM("nonmatchings/game/clsmes", CalcIntersectionPointSphereAndLine__FPffPfPfPfPf);
INCLUDE_ASM("nonmatchings/game/clsmes", CheckPosInOutForArea__FPfPfPf);
INCLUDE_ASM("nonmatchings/game/clsmes", CalcMoveNextPos__FPfPffPf);
INCLUDE_ASM("nonmatchings/game/clsmes", InitMovieCC__Fv);
INCLUDE_ASM("nonmatchings/game/clsmes", MyStrCpyLineFeed__FPcPc);
extern "C" void GetNextLineTop__FPPc(s8 **arg0) {
    s8 *var_a2;

    var_a2 = (s8 *) (*arg0);
loop_1:
    if (*var_a2 != 0xA) {
        var_a2 += 1;
        goto loop_1;
    }
    *arg0 = var_a2 + 1;
}
INCLUDE_ASM("nonmatchings/game/clsmes", GetTopAddress__FPcii);
INCLUDE_ASM("nonmatchings/game/clsmes", MovieCCAnalyze__FPcii);
INCLUDE_ASM("nonmatchings/game/clsmes", MovieCCDraw__Fv);
extern "C" u32 LanguageCode;
extern "C" u32 MovieCCCnt;
typedef struct MovieCCFont_champs {
    char pad0[156];
    s32 unk9C;
    s32 unkA0;
    char padA4[20];
} MovieCCFont_champs;
extern "C" MovieCCFont_champs MovieCCFont;
extern "C" u32 MovieCCH;
extern "C" u32 MovieCCW;
struct inferred;
typedef struct CFont {
    /* 0x00 */ char pad0[0x9C];
    /* 0x9C */ char unk9C;                             /* inferred */
    /* 0x9C */ char pad9C[4];
    /* 0xA0 */ char unkA0;                             /* inferred */
    /* 0xA0 */ char padA0[1];
} CFont;                                            /* size >= 0xA1 */
extern "C" s32 Init__5CFontFv(void *);
extern "C" s32 SetClearance__5CFontFii(void *, s32, s32);
extern "C" s32 SetFuchi__5CFontFi(void *, s32);
extern "C" s32 MovieCCAnalyze__FPcii(...);
extern "C" void MovieCCInit__FPcii(s8 *arg0, s32 arg1, s32 arg2) {
    if (LanguageCode != 1) {
        Init__5CFontFv(&MovieCCFont);
        SetFuchi__5CFontFi(&MovieCCFont, 8);
        SetClearance__5CFontFii(&MovieCCFont, MovieCCFont.unk9C + 2, MovieCCFont.unkA0 - 6);
        MovieCCCnt = 0;
        MovieCCW = 0;
        MovieCCH = 0;
        MovieCCAnalyze__FPcii(arg0, arg1, arg2);
    }
}
INCLUDE_ASM("nonmatchings/game/clsmes", VSyncCallBack__Fi_0015D470);
INCLUDE_ASM("nonmatchings/game/clsmes", ClearScreen__Fiii);
INCLUDE_ASM("nonmatchings/game/clsmes", init__Fv);
extern "C" u32 MainThreadPriority;
extern "C" u8 _847_00367490[26];
extern "C" u32 vcount_0037CF84;
extern "C" s32 ChangeThreadPriority(...);
extern "C" s32 GetThreadId(...);
extern "C" s32 MainLoop__Fv(void);
extern "C" s32 printf(...);
extern "C" s32 sceCdInit(...);
extern "C" s32 sceGsSyncPath(...);
extern "C" s32 sceGsSyncV(...);
extern "C" s32 sceGsSyncVCallback(...);
extern "C" s32 sceSifExitCmd(...);
extern "C" s32 init__Fv(void);
extern "C" s32 main(void) {
    MainThreadPriority = 0xA;
    ChangeThreadPriority(GetThreadId(), MainThreadPriority);
    init__Fv();
    printf(&_847_00367490, vcount_0037CF84);
    MainLoop__Fv();
    sceGsSyncPath(0, 0);
    sceGsSyncVCallback(0);
    sceGsSyncV(0);
    sceCdInit(5);
    sceSifExitCmd();
    return 0;
}
INCLUDE_ASM("nonmatchings/game/clsmes", SetFlag__12CMapFlagDataFii);
INCLUDE_ASM("nonmatchings/game/clsmes", GetFlag__12CMapFlagDataFi);
