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
extern "C" s32 AntiAliasing__11mgCDrawPrimFi(void *, s32);
extern "C" s32 Shading__11mgCDrawPrimFi(void *, s32);
extern "C" void MySetPrim__FP11mgCDrawPrimii(void *arg0, s32 arg1, s32 arg2) {
    Initialize__11mgCDrawPrimFP9mgCMemoryP13sceVif1Packet(arg0, NULL, NULL);
    switch (arg1) {
    case 1:
        AlphaBlendEnable__11mgCDrawPrimFi(arg0, 1);
        AlphaBlend__11mgCDrawPrimFi(arg0, 1);
        AlphaTestEnable__11mgCDrawPrimFi(arg0, 1);
        AlphaTest__11mgCDrawPrimFii(arg0, 1, 0);
        DepthTestEnable__11mgCDrawPrimFi(arg0, 0);
        ZMask__11mgCDrawPrimFi(arg0, -1);
        Shading__11mgCDrawPrimFi(arg0, 0);
        TextureMapEnable__11mgCDrawPrimFi(arg0, 1);
        Bilinear__11mgCDrawPrimFi(arg0, 0);
        AntiAliasing__11mgCDrawPrimFi(arg0, 1);
        break;
    case 3:
        Shading__11mgCDrawPrimFi(arg0, 1);
        TextureMapEnable__11mgCDrawPrimFi(arg0, 1);
        AlphaBlendEnable__11mgCDrawPrimFi(arg0, 1);
        DepthTestEnable__11mgCDrawPrimFi(arg0, 0);
        if (arg2 != 0) {
            Bilinear__11mgCDrawPrimFi(arg0, 1);
        } else {
            Bilinear__11mgCDrawPrimFi(arg0, 0);
        }
        break;
    case 4:
        Shading__11mgCDrawPrimFi(arg0, 1);
        TextureMapEnable__11mgCDrawPrimFi(arg0, 1);
        AlphaBlendEnable__11mgCDrawPrimFi(arg0, 1);
        DepthTestEnable__11mgCDrawPrimFi(arg0, 0);
        if (arg2 != 0) {
            Bilinear__11mgCDrawPrimFi(arg0, 1);
        } else {
            Bilinear__11mgCDrawPrimFi(arg0, 0);
        }
        break;
    case 7:
        AlphaTestEnable__11mgCDrawPrimFi(arg0, 0);
        DepthTestEnable__11mgCDrawPrimFi(arg0, 0);
        ZMask__11mgCDrawPrimFi(arg0, -1);
        TextureMapEnable__11mgCDrawPrimFi(arg0, 0);
        AlphaBlendEnable__11mgCDrawPrimFi(arg0, 1);
        AntiAliasing__11mgCDrawPrimFi(arg0, 1);
        break;
    }
}
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
extern "C" s32 AntiAliasing__11mgCDrawPrimFi(void *, s32);
extern "C" s32 DAlphaTest__11mgCDrawPrimFii(void *, s32, s32);
extern "C" s32 DepthTest__11mgCDrawPrimFi(void *, s32);
extern "C" s32 DrawFukidashi_sub__6ClsMesFP11mgCDrawPrimiii(...);
extern "C" void DrawFukidashi__6ClsMesFiii(ClsMes *objet, s32 arg0, s32 arg1, s32 arg2) {
    u8 sp50[0x120]; /* le cadre du commerce est de 0x170, soit 0x110 de plus que l inféré */
    __ct__11mgCDrawPrimFv(&sp50);
    Initialize__11mgCDrawPrimFP9mgCMemoryP13sceVif1Packet(&sp50, NULL, NULL);
    ZMask__11mgCDrawPrimFi(&sp50, -1);
    AlphaTestEnable__11mgCDrawPrimFi(&sp50, 0);
    AlphaBlendEnable__11mgCDrawPrimFi(&sp50, 1);
    DAlphaTest__11mgCDrawPrimFii(&sp50, 0, 0);
    DepthTestEnable__11mgCDrawPrimFi(&sp50, 0);
    DepthTest__11mgCDrawPrimFi(&sp50, -1);
    TextureMapEnable__11mgCDrawPrimFi(&sp50, 0);
    Bilinear__11mgCDrawPrimFi(&sp50, 1);
    AntiAliasing__11mgCDrawPrimFi(&sp50, 1);
    DrawFukidashi_sub__6ClsMesFP11mgCDrawPrimiii(objet, &sp50, arg0, arg1, arg2);
    AntiAliasing__11mgCDrawPrimFi(&sp50, 0);
    DrawFukidashi_sub__6ClsMesFP11mgCDrawPrimiii(objet, &sp50, arg0, arg1, arg2);
}
INCLUDE_ASM("nonmatchings/game/clsmes_00151690", SetDrawSpeed__6ClsMesFv);
extern "C" s32 GetSaveData__Fv(void);
extern "C" f32 GetDrawSpeedDef__6ClsMesFv(void *objet) {
    u8 *save = (u8 *) GetSaveData__Fv();
    if (save != NULL) {
        s32 *p = (s32 *) (save + 0x1C574);
        if (p != NULL && p[2] == 1) {
            return 0.0f;
        }
    }
    return *(f32 *) ((u8 *) objet + 0x1D4);
}
INCLUDE_ASM("nonmatchings/game/clsmes_00151690", GetCaptionOff__6ClsMesFv);
s32 ClsMes::GetPageAutoFlg(void) {
    return this->field_0x1DC;
}
INCLUDE_ASM("nonmatchings/game/clsmes_00151690", GetScrPosFromChar__FP11CCharacter2Pi);
INCLUDE_ASM("nonmatchings/game/clsmes_00151690", GetStrWidth__6ClsMesFPc);
INCLUDE_ASM("nonmatchings/game/clsmes_00151690", GetStrWidth__6ClsMesFi);
extern "C" s32 GetScrPosFromChar__FP11CCharacter2Pi(void *, s32 *);
extern "C" void AutoSetSub__6ClsMesFP11CCharacter2P11CCharacter2Pi(ClsMes *objet, void *arg0, void *arg1, s32 *arg2) {
    GetScrPosFromChar__FP11CCharacter2Pi(arg0, arg2);
    GetScrPosFromChar__FP11CCharacter2Pi(arg1, arg2 + 2);
}
INCLUDE_ASM("nonmatchings/game/clsmes_00151690", CalcAutoPosSetData__FiiiiP4RECT);
INCLUDE_ASM("nonmatchings/game/clsmes_00151690", CalcMesWinXYFromFukidashiXY__6ClsMesFv);
INCLUDE_ASM("nonmatchings/game/clsmes_00151690", CalcFukidashiXY__6ClsMesFPi);
struct ClsMes_infere_238bbe;
typedef struct ClsMes_infere_238bbe {
    /* 0x000 */ char pad0[0x140];
    /* 0x140 */ s32 unk140;                         /* inferred */
    /* 0x144 */ s32 unk144;                         /* inferred */
    /* 0x148 */ s32 unk148;                         /* inferred */
    /* 0x14C */ s32 unk14C;                         /* inferred */
    /* 0x150 */ s32 unk150;                         /* inferred */
    /* 0x154 */ s32 unk154;                         /* inferred */
    /* 0x158 */ char pad158[4];
    /* 0x15C */ s32 unk15C;                         /* inferred */
    /* 0x160 */ s32 unk160;                         /* inferred */
    /* 0x164 */ s32 unk164;                         /* inferred */
    /* 0x168 */ s32 unk168;                         /* inferred */
    /* 0x16C */ s32 unk16C;                         /* inferred */
} ClsMes_infere_238bbe;                                           /* size >= 0x170 */
struct arg0_champs_238bbe {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
};
extern "C" s32 CalcFukidashiXY__6ClsMesFPi(void *, s32 *);
extern "C" s32 CalcMesWinXYFromFukidashiXY__6ClsMesFv(void *);
extern "C" void AutoSet__6ClsMesFPi(ClsMes_infere_238bbe *objet, s32 *arg0) {
    CalcFukidashiXY__6ClsMesFPi(objet, arg0);
    objet->unk140 = objet->unk148 + objet->unk150 / 2;
    objet->unk144 = objet->unk14C + objet->unk154 / 2;
    s32 px = arg0[0];
    s32 py = arg0[1];
    if (objet->unk15C != 0) {
        objet->unk160 = px;
        objet->unk164 = py;
        if (objet->unk160 <= objet->unk148 + objet->unk150 / 4) {
            objet->unk168 = objet->unk148 + objet->unk150 / 4;
        } else if (objet->unk148 + objet->unk150 * 3 / 4 <= objet->unk160) {
            objet->unk168 = objet->unk148 + objet->unk150 * 3 / 4;
        } else {
            objet->unk168 = objet->unk160;
        }
        if (objet->unk164 <= objet->unk14C + objet->unk154 / 4) {
            objet->unk16C = objet->unk14C + objet->unk154 / 4;
        } else if (objet->unk14C + objet->unk154 * 3 / 4 <= objet->unk164) {
            objet->unk16C = objet->unk14C + objet->unk154 * 3 / 4;
        } else {
            objet->unk16C = objet->unk164;
        }
    }
    CalcMesWinXYFromFukidashiXY__6ClsMesFv(objet);
}
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
struct ClsMes_infere2;
typedef struct ClsMes_infere2 {
    /* 0x0000 */ char pad0[0xB8];
    /* 0x00B8 */ s32 unkB8;                         /* inferred */
    /* 0x00BC */ s32 unkBC;                         /* inferred */
    /* 0x00C0 */ char padC0[8];                     /* maybe part of unkBC[3]void */
    /* 0x00C8 */ s32 unkC8;                         /* inferred */
    /* 0x00CC */ s32 unkCC;                         /* inferred */
    /* 0x00D0 */ char padD0[4];
    /* 0x00D4 */ s32 unkD4;                         /* inferred */
    /* 0x00D8 */ s32 unkD8;                         /* inferred */
    /* 0x00DC */ s32 unkDC;                         /* inferred */
    /* 0x00E0 */ s32 unkE0;                         /* inferred */
    /* 0x00E4 */ s32 unkE4;                         /* inferred */
    /* 0x00E8 */ s32 unkE8;                         /* inferred */
    /* 0x00EC */ s32 unkEC;                         /* inferred */
    /* 0x00F0 */ char padF0[0x40];                  /* maybe part of unkEC[0x11]void */
    /* 0x0130 */ s32 unk130;                        /* inferred */
    /* 0x0134 */ s32 unk134;                        /* inferred */
    /* 0x0138 */ s32 unk138;                        /* inferred */
    /* 0x013C */ char pad13C[0x54];                 /* maybe part of unk138[0x16]void */
    /* 0x0190 */ s32 unk190;                        /* inferred */
    /* 0x0194 */ s32 unk194;                        /* inferred */
    /* 0x0198 */ s32 unk198;                        /* inferred */
    /* 0x019C */ s32 unk19C;                        /* inferred */
    /* 0x01A0 */ s32 unk1A0;                        /* inferred */
    /* 0x01A4 */ s32 unk1A4;                        /* inferred */
    /* 0x01A8 */ s32 unk1A8;                        /* inferred */
    /* 0x01AC */ char pad1AC[0x24];                 /* maybe part of unk1A8[0xA]void */
    /* 0x01D0 */ f32 unk1D0;                        /* inferred */
    /* 0x01D4 */ s32 unk1D4;                        /* inferred */
    /* 0x01D8 */ s32 unk1D8;                        /* inferred */
    /* 0x01DC */ char pad1DC[8];                    /* maybe part of unk1D8[3]void */
    /* 0x01E4 */ s32 unk1E4;                        /* inferred */
    /* 0x01E8 */ s32 unk1E8;                        /* inferred */
    /* 0x01EC */ s32 unk1EC;                        /* inferred */
    /* 0x01F0 */ s32 unk1F0;                        /* inferred */
    /* 0x01F4 */ s32 unk1F4;                        /* inferred */
    /* 0x01F8 */ char pad1F8[0x1C30];               /* maybe part of unk1F4[0x70D]void */
    /* 0x1E28 */ s32 unk1E28;                       /* inferred */
    /* 0x1E2C */ s32 unk1E2C;                       /* inferred */
    /* 0x1E30 */ s32 unk1E30;                       /* inferred */
    /* 0x1E34 */ s32 unk1E34;                       /* inferred */
    /* 0x1E38 */ s32 unk1E38;                       /* inferred */
    /* 0x1E3C */ s32 unk1E3C;                       /* inferred */
    /* 0x1E40 */ s32 unk1E40;                       /* inferred */
    /* 0x1E44 */ char pad1E44[8];                   /* maybe part of unk1E40[3]void */
    /* 0x1E4C */ s32 unk1E4C;                       /* inferred */
    /* 0x1E50 */ s32 unk1E50;                       /* inferred */
    /* 0x1E54 */ s32 unk1E54;                       /* inferred */
    /* 0x1E58 */ u8 unk1E58;                        /* inferred */
    /* 0x1E59 */ char pad1E59[0x3E3];               /* maybe part of unk1E58[0x3E4]void */
    /* 0x223C */ s32 unk223C;                       /* inferred */
    /* 0x2240 */ s32 unk2240;                       /* inferred */
    /* 0x2244 */ s32 unk2244;                       /* inferred */
    /* 0x2248 */ s32 unk2248;                       /* inferred */
    /* 0x224C */ s32 unk224C;                       /* inferred */
    /* 0x2250 */ s32 unk2250;                       /* inferred */
    /* 0x2254 */ s32 unk2254;                       /* inferred */
    /* 0x2258 */ s32 unk2258;                       /* inferred */
    /* 0x225C */ s32 unk225C;                       /* inferred */
    /* 0x2260 */ s32 unk2260;                       /* inferred */
    /* 0x2264 */ s32 unk2264;                       /* inferred */
    /* 0x2268 */ s32 unk2268;                       /* inferred */
    /* 0x226C */ s32 unk226C;                       /* inferred */
    /* 0x2270 */ s32 unk2270;                       /* inferred */
    /* 0x2274 */ s32 unk2274;                       /* inferred */
    /* 0x2278 */ s32 unk2278;                       /* inferred */
    /* 0x227C */ s32 unk227C;                       /* inferred */
    /* 0x2280 */ s32 unk2280;                       /* inferred */
    /* 0x2284 */ s32 unk2284;                       /* inferred */
    /* 0x2288 */ s32 unk2288;                       /* inferred */
    /* 0x228C */ s32 unk228C;                       /* inferred */
    /* 0x2290 */ s32 unk2290;                       /* inferred */
    /* 0x2294 */ s32 unk2294;                       /* inferred */
    /* 0x2298 */ s32 unk2298;                       /* inferred */
    /* 0x229C */ s32 unk229C;                       /* inferred */
    /* 0x22A0 */ s32 unk22A0;                       /* inferred */
    /* 0x22A4 */ char pad22A4[4];
    /* 0x22A8 */ s32 unk22A8;                       /* inferred */
    /* 0x22AC */ s32 unk22AC;                       /* inferred */
    /* 0x22B0 */ s32 unk22B0;                       /* inferred */
    /* 0x22B4 */ s32 unk22B4;                       /* inferred */
    /* 0x22B8 */ s32 unk22B8;                       /* inferred */
} ClsMes_infere2;                                           /* size >= 0x22BC */
struct temp_a0_champs_a2296d {
    char pad0[0xF0];
    /* 0xF0 */ s32 unkF0;
    /* 0xF4 */ s32 unkF4;
    /* 0xF8 */ s32 unkF8;
    /* 0xFC */ s32 unkFC;
    /* 0x100 */ s32 unk100;
    /* 0x104 */ s32 unk104;
    /* 0x108 */ s32 unk108;
    /* 0x10C */ s32 unk10C;
};
struct temp_a3_champs_a2296d {
    char pad0[0x217C];
    /* 0x217C */ s32 unk217C;
    /* 0x2180 */ s32 unk2180;
    /* 0x2184 */ s32 unk2184;
    /* 0x2188 */ s32 unk2188;
    /* 0x218C */ s32 unk218C;
    /* 0x2190 */ s32 unk2190;
    /* 0x2194 */ s32 unk2194;
    /* 0x2198 */ s32 unk2198;
};
struct temp_a2_champs_a2296d {
    char pad0[0x21BC];
    /* 0x21BC */ s32 unk21BC;
    /* 0x21C0 */ s32 unk21C0;
    /* 0x21C4 */ s32 unk21C4;
    /* 0x21C8 */ s32 unk21C8;
    /* 0x21CC */ s32 unk21CC;
    /* 0x21D0 */ s32 unk21D0;
    /* 0x21D4 */ s32 unk21D4;
    /* 0x21D8 */ s32 unk21D8;
    char pad21DC[0x20];
    /* 0x21FC */ s32 unk21FC;
    /* 0x2200 */ s32 unk2200;
    /* 0x2204 */ s32 unk2204;
    /* 0x2208 */ s32 unk2208;
    /* 0x220C */ s32 unk220C;
    /* 0x2210 */ s32 unk2210;
    /* 0x2214 */ s32 unk2214;
    /* 0x2218 */ s32 unk2218;
};
struct temp_t0_champs_a2296d {
    char pad0[0x22BC];
    /* 0x22BC */ s32 unk22BC;
    char pad22C0[0xEC];
    /* 0x23AC */ s32 unk23AC;
    char pad23B0[0x4C];
    /* 0x23FC */ s32 unk23FC;
    char pad2400[0x4C];
    /* 0x244C */ s32 unk244C;
    char pad2450[0x4C];
    /* 0x249C */ s32 unk249C;
    char pad24A0[0x4C];
    /* 0x24EC */ s32 unk24EC;
    char pad24F0[0x4C];
    /* 0x253C */ s32 unk253C;
    char pad2540[0x4C];
    /* 0x258C */ s32 unk258C;
    char pad2590[0x4C];
    /* 0x25DC */ s32 unk25DC;
    char pad25E0[0x4C];
    /* 0x262C */ s32 unk262C;
    char pad2630[0x4C];
    /* 0x267C */ s32 unk267C;
    char pad2680[0x4C];
    /* 0x26CC */ s32 unk26CC;
    char pad26D0[0x4C];
    /* 0x271C */ s32 unk271C;
    char pad2720[0x4C];
    /* 0x276C */ s32 unk276C;
    char pad2770[0x4C];
    /* 0x27BC */ s32 unk27BC;
    char pad27C0[0x4C];
    /* 0x280C */ s32 unk280C;
    char pad2810[0x4C];
    /* 0x285C */ s32 unk285C;
    char pad2860[0x4C];
    /* 0x28AC */ s32 unk28AC;
    char pad28B0[0x4C];
    /* 0x28FC */ s32 unk28FC;
};
struct temp_v1_champs_a2296d {
    char pad0[0x230C];
    /* 0x230C */ s32 unk230C;
    /* 0x2310 */ s32 unk2310;
};
extern "C" s32 InitMesWinTbl__6ClsMesFv(void *);
extern "C" s32 SetWindowMode__6ClsMesFi(void *, s32);
extern "C" s32 memset(...);
extern "C" s32 SetDefColor__6ClsMesFUi(void *, u32);
extern "C" s32 SetDrawSpeed__6ClsMesFv(void *);
extern "C" void Preset__6ClsMesFi(ClsMes_infere2 *objet, u32 arg0) {
    s32 var_v1;
    s32 var_a0;
    s32 var_a1;
    s32 var_a1_2;
    s32 var_a1_3;
    s32 var_a1_4;
    s32 var_a2;
    s32 var_a2_2;
    s32 var_a3;
    s32 var_s0;
    s32 var_s1;
    struct temp_a0_champs_a2296d *temp_a0;
    struct temp_a2_champs_a2296d *temp_a2;
    struct temp_a3_champs_a2296d *temp_a3;
    struct temp_t0_champs_a2296d *temp_t0;
    struct temp_v1_champs_a2296d *temp_v1;

    var_v1 = 0;
    var_a1 = 0;
    objet->unkBC = 0;
    objet->unkDC = 0;
    objet->unkE0 = 0;
    objet->unkE4 = 0;
    objet->unkE8 = 0;
    objet->unkEC = 0;
    do {
        temp_a0 = (struct temp_a0_champs_a2296d *) (((ClsMes_infere2 *) ((u8 *) objet + var_a1)));
        var_v1 += 8;
        temp_a0->unkF0 = 0;
        temp_a0->unkF4 = 0;
        var_a1 += 0x20;
        temp_a0->unkF8 = 0;
        temp_a0->unkFC = 0;
        temp_a0->unk100 = 0;
        temp_a0->unk104 = 0;
        temp_a0->unk108 = 0;
        temp_a0->unk10C = 0;
    } while (var_v1 < 0x10);
    objet->unk130 = 0;
    objet->unk134 = 0;
    objet->unk194 = 0;
    objet->unk198 = 1;
    objet->unk1D0 = GetDrawSpeedDef__6ClsMesFv(objet);
    objet->unk1D8 = 0;
    objet->unk1E4 = 0;
    objet->unk1E8 = 0;
    objet->unk1EC = 0;
    objet->unk1F0 = 0;
    objet->unk1F4 = 0;
    InitMesWinTbl__6ClsMesFv(objet);
    var_s0 = 0;
    var_s1 = 0;
    objet->unk1E2C = objet->unk1E28;
    objet->unk1E30 = 0;
    objet->unk1E34 = 0;
    objet->unk1E38 = 0x1E;
    objet->unk1E3C = -1;
    objet->unk1E40 = 0;
    objet->unk1E58 = 0x80;
    do {
        memset((u8 *) objet + var_s1 + 0x1E59, 0, 0x32);
        var_s0 += 1;
        var_s1 += 0x32;
    } while (var_s0 < 0x10);
    var_a1_2 = 0;
    var_a2 = 0;
    do {
        temp_a3 = (struct temp_a3_champs_a2296d *) (((ClsMes_infere2 *) ((u8 *) objet + var_a2)));
        var_a1_2 += 8;
        temp_a3->unk217C = -1;
        temp_a3->unk2180 = -1;
        var_a2 += 0x20;
        temp_a3->unk2184 = -1;
        temp_a3->unk2188 = -1;
        temp_a3->unk218C = -1;
        temp_a3->unk2190 = -1;
        temp_a3->unk2194 = -1;
        temp_a3->unk2198 = -1;
    } while (var_a1_2 < 0x10);
    var_a0 = 0;
    var_a1_3 = 0;
    do {
        temp_a2 = (struct temp_a2_champs_a2296d *) (((ClsMes_infere2 *) ((u8 *) objet + var_a1_3)));
        var_a0 += 8;
        temp_a2->unk21BC = 0;
        temp_a2->unk21FC = 0;
        var_a1_3 += 0x20;
        temp_a2->unk21C0 = 0;
        temp_a2->unk2200 = 0;
        temp_a2->unk21C4 = 0;
        temp_a2->unk2204 = 0;
        temp_a2->unk21C8 = 0;
        temp_a2->unk2208 = 0;
        temp_a2->unk21CC = 0;
        temp_a2->unk220C = 0;
        temp_a2->unk21D0 = 0;
        temp_a2->unk2210 = 0;
        temp_a2->unk21D4 = 0;
        temp_a2->unk2214 = 0;
        temp_a2->unk21D8 = 0;
        temp_a2->unk2218 = 0;
    } while (var_a0 < 0x10);
    objet->unk223C = 0;
    objet->unk2240 = 0;
    objet->unk2244 = 1;
    var_a1_4 = 0;
    objet->unk2248 = 0;
    var_a2_2 = 0;
    objet->unk224C = 0;
    var_a3 = 0;
    objet->unk2250 = 0;
    objet->unk2254 = -1;
    objet->unk2258 = -1;
    objet->unk225C = -1;
    objet->unk2260 = 0;
    objet->unk2264 = 0;
    objet->unk2268 = 0;
    objet->unk226C = 0;
    objet->unk2270 = 0;
    objet->unk2274 = 0;
    objet->unk2278 = 0;
    objet->unk227C = -1;
    objet->unk2280 = -1;
    objet->unk2284 = -1;
    objet->unk2288 = -1;
    objet->unk228C = 0;
    objet->unk2290 = 0;
    objet->unk2294 = 0;
    objet->unk2298 = 0;
    objet->unk229C = 0;
    objet->unk22A0 = 0;
    objet->unk22A8 = 0;
    objet->unk22AC = 0;
    objet->unk22B4 = 0;
    objet->unk22B0 = 0;
    objet->unk22B8 = 0;
    do {
        temp_t0 = (struct temp_t0_champs_a2296d *) (((ClsMes_infere2 *) ((u8 *) objet + var_a2_2)));
        temp_v1 = (struct temp_v1_champs_a2296d *) (((ClsMes_infere2 *) ((u8 *) objet + var_a3)));
        temp_t0->unk22BC = 0;
        var_a1_4 += 1;
        temp_v1->unk230C = 0;
        var_a2_2 += 4;
        temp_v1->unk2310 = 0;
        var_a3 += 8;
        temp_t0->unk23AC = 0;
        temp_t0->unk23FC = -1;
        temp_t0->unk244C = 0;
        temp_t0->unk249C = 0;
        temp_t0->unk24EC = 0;
        temp_t0->unk253C = 0;
        temp_t0->unk258C = 0;
        temp_t0->unk25DC = -1;
        temp_t0->unk262C = 0;
        temp_t0->unk267C = 0;
        temp_t0->unk26CC = 0;
        temp_t0->unk271C = -1;
        temp_t0->unk276C = -1;
        temp_t0->unk27BC = 0;
        temp_t0->unk280C = 0;
        temp_t0->unk285C = 0;
        temp_t0->unk28AC = 0;
        temp_t0->unk28FC = 0;
    } while (var_a1_4 < 0x14);
    switch (arg0) {
    case 6:
        SetDefColor__6ClsMesFUi(objet, 0x80686A6BU);
        objet->unk2290 = 0;
        objet->unkB8 = 5;
        objet->unk1E4C = 0;
        objet->unk2270 = 0;
        objet->unk19C = -1;
        objet->unk1A0 = -1;
        objet->unk1A4 = -1;
        objet->unk1A8 = -1;
        objet->unk1D0 = 1.0f;
        return;
    case 5:
        objet->unk138 = 1;
        SetDefColor__6ClsMesFUi(objet, 0x80202020U);
        objet->unkC8 = 0xF;
        objet->unkCC = 0x14;
        objet->unkD4 = 0x15;
        objet->unkD8 = 4;
        objet->unk1D0 = 0.0f;
        objet->unk1D4 = 0;
        objet->unkB8 = 0;
        objet->unk1E4C = 1;
        objet->unk1E50 = 0;
        objet->unk1E54 = 0;
        objet->unk190 = 0x3E4CCCCD;
        return;
    case 0:
        SetDrawSpeed__6ClsMesFv(objet);
        objet->unk138 = 1;
        SetDefColor__6ClsMesFUi(objet, 0x80202020U);
        objet->unkB8 = 1;
        objet->unk1E4C = 1;
        return;
    case 1:
        objet->unk138 = 0;
        objet->unk1D0 = 0.0f;
        objet->unk1D4 = 0;
        SetDefColor__6ClsMesFUi(objet, 0x80202020U);
        objet->unkB8 = 2;
        objet->unk1E4C = 0;
        return;
    case 2:
        SetWindowMode__6ClsMesFi(objet, 0);
        objet->unk1E4C = 0;
        objet->unk1D0 = 0.0f;
        objet->unk1D4 = 0;
        objet->unk1E50 = 0;
        objet->unk19C = -1;
        objet->unk1A0 = -1;
        objet->unk1A4 = -1;
        objet->unk1A8 = -1;
        return;
    case 3:
        SetWindowMode__6ClsMesFi(objet, 0);
        objet->unk1E4C = 0;
        objet->unk1D0 = 0.0f;
        objet->unk1D4 = 0;
        objet->unk1E50 = 0;
        objet->unk19C = -1;
        objet->unk1A0 = -1;
        objet->unk1A4 = 0;
        objet->unk1A8 = 0;
        objet->unkBC = 1;
        return;
    case 4:
        SetWindowMode__6ClsMesFi(objet, 2);
        objet->unk1E4C = 0;
        objet->unk1D0 = 0.0f;
        objet->unk1D4 = 0;
        objet->unkB8 = 5;
        objet->unk19C = -1;
        objet->unk1A0 = -1;
        objet->unk1A4 = -1;
        objet->unk1A8 = -1;
    }
}
