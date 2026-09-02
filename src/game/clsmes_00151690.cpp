/* ClsMes
 *
 * Unité découpée par `make carve` : 29 fonctions, 8820 octets, de
 * 0x00151690 à 0x00153980. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"
#include "gen/ClsMes.hpp"

extern "C" s32 CheckPosInOutFor2P__Fffffff(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5) {
    f32 var_f0;
    f32 var_f14;
    f32 var_f15;
    f32 var_f1;
    s32 var_v0;

    var_f14 = arg2;
    var_f15 = arg3;
    var_f0 = var_f14;
    if (arg0 < var_f14) {
        var_f0 = arg0;
    } else {
        var_f14 = arg0;
    }
    var_f1 = var_f15;
    if (arg1 < var_f15) {
        var_f1 = arg1;
    } else {
        var_f15 = arg1;
    }
    if (arg4 < var_f0) {
        return 0;
    }
    if (var_f14 < arg4) {
        return 0;
    }
    if (arg5 < var_f1) {
        return 0;
    }
    var_v0 = 1;
    if (!(var_f15 < arg5)) {
        var_v0 = 0;
    }
    return var_v0 ^ 1;
}
INCLUDE_ASM("nonmatchings/game/clsmes_00151690", CalcIntersectionPointLineAndLine__FffffffffPfPf);
INCLUDE_ASM("nonmatchings/game/clsmes_00151690", CalcIntersectionPoint2PAnd2P__FffffffffPfPf);
INCLUDE_ASM("nonmatchings/game/clsmes_00151690", MySetPrim__FP11mgCDrawPrimii);
INCLUDE_ASM("nonmatchings/game/clsmes_00151690", set2DSpriteEasy__FP11mgCDrawPrim9mgRect_i_9mgRect_i_P10RGBAQ_TYPE);
INCLUDE_ASM("nonmatchings/game/clsmes_00151690", _set2DSprite__FPcP11mgCDrawPrim9mgRect_i_9mgRect_i_P10RGBAQ_TYPE);
INCLUDE_ASM("nonmatchings/game/clsmes_00151690", set2DSprite__FP11mgCDrawPrim9mgRect_i_9mgRect_i_P10RGBAQ_TYPE);
INCLUDE_ASM("nonmatchings/game/clsmes_00151690", FillRect__Fiiiiiiii);
INCLUDE_ASM("nonmatchings/game/clsmes_00151690", DrawFukidashi_sub__6ClsMesFP11mgCDrawPrimiii);
INCLUDE_ASM("nonmatchings/game/clsmes_00151690", DrawFukidashi__6ClsMesFiii);
INCLUDE_ASM("nonmatchings/game/clsmes_00151690", SetDrawSpeed__6ClsMesFv);
INCLUDE_ASM("nonmatchings/game/clsmes_00151690", GetDrawSpeedDef__6ClsMesFv);
INCLUDE_ASM("nonmatchings/game/clsmes_00151690", GetCaptionOff__6ClsMesFv);
s32 ClsMes::GetPageAutoFlg(void) {
    return this->field_0x1DC;
}
INCLUDE_ASM("nonmatchings/game/clsmes_00151690", GetScrPosFromChar__FP11CCharacter2Pi);
INCLUDE_ASM("nonmatchings/game/clsmes_00151690", GetStrWidth__6ClsMesFPc);
INCLUDE_ASM("nonmatchings/game/clsmes_00151690", GetStrWidth__6ClsMesFi);
INCLUDE_ASM("nonmatchings/game/clsmes_00151690", AutoSetSub__6ClsMesFP11CCharacter2P11CCharacter2Pi);
INCLUDE_ASM("nonmatchings/game/clsmes_00151690", CalcAutoPosSetData__FiiiiP4RECT);
INCLUDE_ASM("nonmatchings/game/clsmes_00151690", CalcMesWinXYFromFukidashiXY__6ClsMesFv);
INCLUDE_ASM("nonmatchings/game/clsmes_00151690", CalcFukidashiXY__6ClsMesFPi);
INCLUDE_ASM("nonmatchings/game/clsmes_00151690", AutoSet__6ClsMesFPi);
INCLUDE_ASM("nonmatchings/game/clsmes_00151690", GetBuffMesIdPtr__FPcii);
INCLUDE_ASM("nonmatchings/game/clsmes_00151690", SetHalfFontWPercent__6ClsMesFf);
INCLUDE_ASM("nonmatchings/game/clsmes_00151690", __ct__6ClsMesFv);
void ClsMes::SetBuff(s16 * arg0) {
    this->field_0x294C = arg0;
}
void ClsMes::SetBuff_system(s16 * arg0) {
    this->field_0x2950 = arg0;
}
void ClsMes::SetDefColor(u32 arg0) {
    this->field_0x1E28 = arg0;
    this->field_0x1E2C = this->field_0x1E28;
}
INCLUDE_ASM("nonmatchings/game/clsmes_00151690", Preset__6ClsMesFi);
