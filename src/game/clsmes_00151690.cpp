/* ClsMes
 *
 * Unité découpée par `make carve` : 29 fonctions, 8820 octets, de
 * 0x00151690 à 0x00153980. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"
#include "gen/ClsMes.hpp"

extern "C" s32 __ct__11mgCDrawPrimFv(void *);
extern "C" s32 AlphaBlendEnable__11mgCDrawPrimFi(void *, s32);
extern "C" s32 AlphaBlend__11mgCDrawPrimFi(void *, s32);
extern "C" s32 AlphaTestEnable__11mgCDrawPrimFi(void *, s32);
extern "C" s32 AlphaTest__11mgCDrawPrimFii(void *, s32, s32);
extern "C" s32 Begin__11mgCDrawPrimFi(void *, s32);
extern "C" s32 Bilinear__11mgCDrawPrimFi(void *, s32);
extern "C" s32 Color__11mgCDrawPrimFiiii(void *, s32, s32, s32, s32);
extern "C" s32 DepthTestEnable__11mgCDrawPrimFi(void *, s32);
extern "C" s32 End__11mgCDrawPrimFv(void *);
extern "C" s32 Initialize__11mgCDrawPrimFP9mgCMemoryP13sceVif1Packet(void *, void *, void *);
extern "C" s32 TextureMapEnable__11mgCDrawPrimFi(void *, s32);
extern "C" s32 Vertex__11mgCDrawPrimFiii(void *, s32, s32, s32);
extern "C" s32 ZMask__11mgCDrawPrimFi(void *, s32);
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
extern "C" s32 CalcIntersectionPointLineAndLine__FffffffffPfPf(f32, f32, f32, f32, f32, f32, f32, f32, f32 *, f32 *);
extern "C" s32 CheckPosInOutFor2P__Fffffff(f32, f32, f32, f32, f32, f32);
extern "C" s32 CalcIntersectionPoint2PAnd2P__FffffffffPfPf(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 *arg8, f32 *arg9) {
    if (CalcIntersectionPointLineAndLine__FffffffffPfPf(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9) == 0) {
        return 0;
    }
    if (CheckPosInOutFor2P__Fffffff(arg0, arg1, arg2, arg3, *arg8, *arg9) == 0) {
        return 0;
    }
    return CheckPosInOutFor2P__Fffffff(arg4, arg5, arg6, arg7, *arg8, *arg9) != 0;
}
INCLUDE_ASM("nonmatchings/game/clsmes_00151690", MySetPrim__FP11mgCDrawPrimii);
INCLUDE_ASM("nonmatchings/game/clsmes_00151690", set2DSpriteEasy__FP11mgCDrawPrim9mgRect_i_9mgRect_i_P10RGBAQ_TYPE);
INCLUDE_ASM("nonmatchings/game/clsmes_00151690", _set2DSprite__FPcP11mgCDrawPrim9mgRect_i_9mgRect_i_P10RGBAQ_TYPE);
INCLUDE_ASM("nonmatchings/game/clsmes_00151690", set2DSprite__FP11mgCDrawPrim9mgRect_i_9mgRect_i_P10RGBAQ_TYPE);
extern "C" void FillRect__Fiiiiiiii(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    /* 0x120 : le cadre du commerce fait 0x1b0, soit 0x110 de plus que le tampon
     * de 0x10 que m2c avait inféré. */
    u8 sp90[0x120];
    __ct__11mgCDrawPrimFv(&sp90);
    Initialize__11mgCDrawPrimFP9mgCMemoryP13sceVif1Packet(&sp90, NULL, NULL);
    AlphaBlendEnable__11mgCDrawPrimFi(&sp90, 1);
    AlphaBlend__11mgCDrawPrimFi(&sp90, 1);
    AlphaTestEnable__11mgCDrawPrimFi(&sp90, 1);
    AlphaTest__11mgCDrawPrimFii(&sp90, 1, 0);
    DepthTestEnable__11mgCDrawPrimFi(&sp90, 0);
    ZMask__11mgCDrawPrimFi(&sp90, -1);
    Bilinear__11mgCDrawPrimFi(&sp90, 0);
    TextureMapEnable__11mgCDrawPrimFi(&sp90, 0);
    Begin__11mgCDrawPrimFi(&sp90, 6);
    Color__11mgCDrawPrimFiiii(&sp90, arg4, arg5, arg6, arg7);
    Vertex__11mgCDrawPrimFiii(&sp90, arg0, arg1, 0);
    Vertex__11mgCDrawPrimFiii(&sp90, arg0 + arg2, arg1 + arg3, 0);
    End__11mgCDrawPrimFv(&sp90);
}
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
struct inferred;
typedef struct ClsMes_infere {
    /* 0x00 */ char pad0[0xD0];
    /* 0xD0 */ f32 unkD0;                           /* inferred */
} ClsMes_infere;                                           /* size >= 0xD4 */
extern "C" void SetHalfFontWPercent__6ClsMesFf(ClsMes_infere *objet, f32 arg0) {
    if (arg0 < 0.0f) {
        objet->unkD0 = 0.55f;
        return;
    }
    objet->unkD0 = arg0;
}
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
