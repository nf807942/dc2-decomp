/* CMenuTreeMap, ClsMes, CBaseMenuClass, mgRect_f_
 *
 * Unité découpée par `make carve` : 29 fonctions, 24696 octets, de
 * 0x001F0E00 à 0x001F6F40. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"
#include "gen/mgRect_f_.hpp"

/* Le corps ne rend qu'un code : ni la classe ni les arguments ne sont
 * déréférencés, donc leur disposition reste à établir. */
struct ITEMCMD_RET_PARA;

class CBaseMenuClass {
public:
    s16 field_0;
    s16 field_2;
    s8 field_4;
    char pad_5[0x1];
    s16 field_6;
    s32 field_8;
    s32 field_C;
    s32 field_10;
    s16 field_14;
    char pad_16[0x2];
    s32 field_18;
    s32 field_1C;
    f32 field_20;
    f32 field_24;
    f32 field_28;
    char pad_2C[0x2E];
    s16 field_5A;
    s16 field_5C;
    char pad_5E[0x62];
    s16 field_C0;
    s16 field_C2;
    s16 field_C4;
    s16 field_C6;
    s16 field_C8;
    char pad_CA[0x2];
    s32 field_CC;
    char pad_D0[0xC];
    s32 field_DC;
    s32 field_E0;
    char pad_E4[0xA];
    s16 field_EE;
    s16 field_F0;
    s16 field_F2;
    s16 field_F4;
    char pad_F6[0x2];
    s32 field_F8;
    char pad_FC[0x4];
    s32 field_100;
    char pad_104[0x4];
    s8 field_108;
    char pad_109[0x1];
    s16 field_10A;
    char pad_10C[0x4];
    s32 field_110;
    s32 field_114;
    s32 field_118;
    s32 field_11C;
    s32 field_120;
    s32 field_124;
    s32 field_128;
    s32 field_12C;
    s32 field_130;
    s32 field_134;
    s32 field_138;
    s32 field_13C;
    s32 field_140;
    s32 field_144;
    s32 field_148;
    s8 field_14C;
    char pad_14D[0x3];
    s32 field_150;
    s32 field_154;
    char pad_158[0x4];
    s32 field_15C;
    s32 field_160;
    char pad_164[0x8];
    s32 field_16C;
    char pad_170[0x4];
    s32 field_174;
    s32 field_178;
    s32 field_17C;
    char pad_180[0x4];
    s8 field_184;
    char pad_185[0x3];
    s32 field_188;
    s8 field_18C;
    s8 field_18D;
    char pad_18E[0x2];
    s32 field_190;
    s32 field_194;
    s32 field_198;
    s32 field_19C;
    s32 field_1A0;
    s32 field_1A4;
    s32 field_1A8;
    s32 field_1AC;
    char pad_1B0[0x4];
    s32 field_1B4;
    s32 field_1B8;
    s32 field_1BC;
    s32 field_1C0;
    s32 field_1C4;
    s16 field_1C8;
    s16 field_1CA;
    s16 field_1CC;
    char pad_1CE[0x2];
    s32 field_1D0;
    s32 field_1D4;
    s32 field_1D8;
    s32 field_1DC;
    s16 field_1E0;
    s16 field_1E2;
    s16 field_1E4;
    s16 field_1E6;
    s16 field_1E8;
    s16 field_1EA;
    char pad_1EC[0x1C];
    s32 field_208;
    s8 field_20C;
    char pad_20D[0x23];
    s32 field_230;
    s32 field_234;
    s32 field_238;
    s32 field_23C;
    s8 field_240;
    char pad_241[0x60];
    s8 field_2A1;
    char pad_2A2[0x62];
    s32 field_304;
    char pad_308[0x6C];
    s32 field_374;
    s32 field_378;
    s32 field_37C;
    char pad_380[0x44];
    s32 field_3C4;
    s8 field_3C8;
    char pad_3C9[0x39];
    s16 field_402;
    s32 field_404;
    s32 field_408;
    char pad_40C[0x8];
    f32 field_414;
    s32 field_418;
    char pad_41C[0x14];
    s32 field_430;
    s32 field_434;
    s32 field_438;
    s32 field_43C;
    s32 field_440;
    s32 field_444;
    s32 field_448;
    s32 field_44C;
    s32 field_450;
    char pad_454[0xC];
    s32 field_460;
    s32 field_464;
    s32 field_468;
    char pad_46C[0x19C];
    s32 field_608;
    char pad_60C[0x1A8];
    s32 field_7B4;
    char pad_7B8[0x2B0];
    s32 field_A68;
    s32 field_A6C;
    s32 field_A70;
    s32 field_A74;
    s32 field_A78;
    s32 field_A7C;
    s32 field_A80;
    char pad_A84[0x4];
    s32 field_A88;
    char pad_A8C[0x104];
    s8 field_B90;
    s8 field_B91;
    s8 field_B92;
    char pad_B93[0x1];
    s16 field_B94;
    s16 field_B96;
    s16 field_B98;
    s16 field_B9A;
    s16 field_B9C;
    s16 field_B9E;
    s16 field_BA0;
    s16 field_BA2;
    char pad_BA4[0x1DC];
    s8 field_D80;
    char pad_D81[0x71F];
    s32 field_14A0;
    char pad_14A4[0x8];
    s32 field_14AC;
    s32 field_14B0;
    s32 field_14B4;
    s32 field_14B8;
    s32 field_14BC;
    s32 field_14C0;
    char pad_14C4[0x28];
    s32 field_14EC;
    s32 field_14F0;
    s32 field_14F4;
    s32 field_14F8;
    s32 field_14FC;
    char pad_1500[0x94C];
    s32 field_1E4C;
    char pad_1E50[0x3F4];
    s32 field_2244;
    char pad_2248[0x4];
    s32 field_224C;
    char pad_2250[0x54];
    s32 field_22A4;
    char pad_22A8[0x14C];
    s32 field_23F4;
    char pad_23F8[0x554];
    s32 field_294C;
    char pad_2950[0x250];
    s32 field_2BA0;
    char pad_2BA4[0xBC];
    s32 field_2C60;
    char pad_2C64[0x9C];
    s32 field_2D00;
    char pad_2D04[0x34];
    s32 field_2D38;
    char pad_2D3C[0x1CB8];
    s32 field_49F4;
    char pad_49F8[0x8];
    s8 field_4A00;
    char pad_4A01[0x44B];
    s32 field_4E4C;
    char pad_4E50[0x6B0];
    s32 field_5500;
    s32 field_5504;
    s32 field_5508;
    char pad_550C[0x44];
    s32 field_5550;
    s32 field_5554;
    s32 field_5558;
    s32 field_555C;
    s32 field_5560;
    s8 field_5564;
    char pad_5565[0x3];
    s32 field_5568;
    s32 field_556C;
    s32 field_5570;
    char pad_5574[0x1244];
    s32 field_67B8;
    char pad_67BC[0xE94];
    s32 field_7650;
    s32 field_7654;
    s16 field_7658;
    s16 field_765A;
    s32 field_765C;
    s16 field_7660;
    s16 field_7662;
    char pad_7664[0x4554];
    s32 field_BBB8;
    s32 field_BBBC;
    char pad_BBC0[0x53FC];
    s32 field_10FBC;
    s32 field_10FC0;
    char pad_10FC4[0x43F4];
    s32 field_153B8;
    s32 field_153BC;
    s32 field_153C0;
    s8 field_153C4;
    char pad_153C5[0xFFB];
    s32 field_163C0;
    s32 field_163C4;
    char pad_163C8[0x5428];
    s32 field_1B7F0;
    s32 field_1B7F4;
    s32 field_1B7F8;
    s32 field_1B7FC;
    s32 field_1B800;
    char pad_1B804[0x10];
    s32 field_1B814;
    char pad_1B818[0x14];
    s32 field_1B82C;
    s32 field_1B830;
    s32 field_1B834;
    s32 field_1B838;
    s32 field_1B83C;
    s32 field_1B840;
    s32 field_1B844;
    s32 field_1B848;
    s32 field_1B84C;
    s32 field_1B850;
    s32 field_1B854;
    s32 field_1B858;
    s32 field_1B85C;
    s32 field_1B860;
    s32 field_1B864;
    s32 field_1B868;
    s32 field_1B86C;
    s32 field_1B870;
    s32 field_1B874;
    char pad_1B878[0x1C];
    s32 field_1B894;
    s32 field_1B898;
    s32 field_1B89C;
    s32 field_1B8A0;
    s32 field_1B8A4;
    s32 field_1B8A8;
    s32 field_1B8AC;
    s32 field_1B8B0;
    s32 field_1B8B4;
    s32 field_1B8B8;
    f32 field_1B8BC;
    f32 field_1B8C0;
    s32 field_1B8C4;
    s32 field_1B8C8;
    s32 field_1B8CC;
    s32 field_1B8D0;
    s32 field_1B8D4;
    s32 field_1B8D8;
    s32 field_1B8DC;
    s32 field_1B8E0;
    s32 field_1B8E4;
    s32 field_1B8E8;
    s32 field_1B8EC;
    s32 field_1B8F0;
    s32 field_1B8F4;

    s32 IsAskExtend(s32 a, s32 b);
    s32 IsCreateObject(s32 a, s32 b);
    s32 IsMakeObject(s32 a, s32 b);
    s32 ItemCmdAfter(s32 command, ITEMCMD_RET_PARA *para);
};

INCLUDE_ASM("nonmatchings/game/cmenutreemap", CheckDngTreeMapFuncType__Fv);
extern "C" s32 GetMainScene__Fv(void);
extern "C" u8 _2739[];
extern "C" u8 _2740[];
extern "C" u8 _2741[];
extern "C" u8 _2742_0036DB80[];
extern "C" char *name_tbl_2728[7];
extern "C" s32 CheckBitFlagMenu__Fi(s32);
extern "C" s32 SearchMapNo__FPc(...);
extern "C" s32 SetNowMapNo__6CSceneFi(void *, s32);
extern "C" void MakeDngTreeMapJumpNo__FiiPiPi(s32 arg0, s32 arg1, s32 *arg2, s32 *arg3) {
    s32 scene;

    if (arg0 == 0) {
        if (arg1 == 8) {
            *arg2 = 1;
            *arg3 = SearchMapNo__FPc(_2739);
        }
    }
    if (arg0 == 1) {
        if (arg1 == 6) {
            *arg2 = 1;
            *arg3 = SearchMapNo__FPc(_2740);
        }
    }
    if ((arg0 == 3) && (arg1 == 0x14)) {
        *arg2 = 1;
        *arg3 = SearchMapNo__FPc(_2741);
        if ((CheckBitFlagMenu__Fi(0x1B6) != 0) && (CheckBitFlagMenu__Fi(0x1BC) == 0)) {
            *arg2 = 2;
            *arg3 = arg0;
        }
    }
    if (arg1 == 0) {
        *arg2 = 1;
        *arg3 = SearchMapNo__FPc(name_tbl_2728[arg0]);
        if (arg0 == 6) {
            scene = GetMainScene__Fv();
            SetNowMapNo__6CSceneFi((void *) scene, SearchMapNo__FPc(_2742_0036DB80));
        }
    }
}
INCLUDE_ASM("nonmatchings/game/cmenutreemap", InitEnd__12CMenuTreeMapFv);
INCLUDE_ASM("nonmatchings/game/cmenutreemap", MsgInit__12CMenuTreeMapFv);
INCLUDE_ASM("nonmatchings/game/cmenutreemap", Step__12CMenuTreeMapFv);
INCLUDE_ASM("nonmatchings/game/cmenutreemap", Draw__12CMenuTreeMapFv);
struct inferred;
struct irregular;
typedef struct CMenuTreeMap {
    /* 0x000 */ s16 unk0;                           /* inferred */
    /* 0x002 */ char pad2[0x118];                   /* maybe part of unk0[0x8D]void */
    /* 0x11A */ s16 unk11A;                         /* inferred */
} CMenuTreeMap;                                     /* size >= 0x11C */
extern "C" s32 FadeCheckMenu__14CBaseMenuClassFv(void *);
extern "C" s32 FadeOutMenu__14CBaseMenuClassFif(void *, s32, f32);
extern "C" s32 FadeInOutMenu__12CMenuTreeMapFv(CMenuTreeMap *objet) {
    s16 temp_v1;
    s32 var_s0;

    temp_v1 = objet->unk0;
    var_s0 = 0;
    switch (temp_v1) {                              /* irregular */
    case 1:
        var_s0 = FadeCheckMenu__14CBaseMenuClassFv((CBaseMenuClass *) objet);
        if (var_s0 != 0) {
            FadeOutMenu__14CBaseMenuClassFif((CBaseMenuClass *) objet, 0x28, 0.0f);
        }
        break;
    case 2:
        if (objet->unk11A == 0) {
            var_s0 = FadeCheckMenu__14CBaseMenuClassFv((CBaseMenuClass *) objet);
        }
        break;
    }
    return var_s0;
}
INCLUDE_ASM("nonmatchings/game/cmenutreemap", DngTreeMapInit__FP9mgCMemoryPiii);
struct ClsMesTreeView {
    char pad0[0xBC];
    s32 uBC;
    char padC0[0x1C];
    s32 uDC;
    s32 uE0;
    s32 uE4;
    s32 uE8;
    s32 uEC;
    s32 uF0[16];
    s32 u130;
    s32 u134;
    char pad138[0x5C];
    s32 u194;
    s32 u198;
    char pad19C[0x34];
    f32 u1D0;
    char pad1D4[0x4];
    s32 u1D8;
    char pad1DC[0x8];
    s32 u1E4;
    s32 u1E8;
    s32 u1EC;
    s32 u1F0;
    s32 u1F4;
    char pad1F8[0x1C30];
    s32 u1E28;
    s32 u1E2C;
    s32 u1E30;
    s32 u1E34;
    s32 u1E38;
    s32 u1E3C;
    s32 u1E40;
    char pad1E44[0x14];
    u8 u1E58;
    s8 u1E59[16][0x32];
    char pad2179[0x3];
    s32 u217C[16];
    s32 u21BC[16];
    s32 u21FC[16];
    s32 u223C;
    s32 u2240;
    s32 u2244;
    s32 u2248;
    s32 u224C;
    s32 u2250;
    s32 u2254;
    s32 u2258;
    s32 u225C;
    s32 u2260;
    s32 u2264;
    s32 u2268;
    s32 u226C;
    s32 u2270;
    s32 u2274;
    s32 u2278;
    s32 u227C;
    s32 u2280;
    s32 u2284;
    s32 u2288;
    s32 u228C;
    s32 u2290;
    s32 u2294;
    s32 u2298;
    s32 u229C;
    s32 u22A0;
    char pad22A4[0x4];
    s32 u22A8;
    s32 u22AC;
    s32 u22B0;
    s32 u22B4;
    s32 u22B8;
    s32 u22BC[20];
    s32 u230C[20][2];
    s32 u23AC[20];
    s32 u23FC[20];
    s32 u244C[20];
    s32 u249C[20];
    s32 u24EC[20];
    s32 u253C[20];
    s32 u258C[20];
    s32 u25DC[20];
    s32 u262C[20];
    s32 u267C[20];
    s32 u26CC[20];
    s32 u271C[20];
    s32 u276C[20];
    s32 u27BC[20];
    s32 u280C[20];
    s32 u285C[20];
    s32 u28AC[20];
    s32 u28FC[20];
};
extern "C" f32 GetDrawSpeedDef__6ClsMesFv(void *);
extern "C" s32 InitMesWinTbl__6ClsMesFv(void *);
extern "C" s32 memset(...);
extern "C" void Init__6ClsMesFv(ClsMesTreeView *objet) {
    s32 i;
    s32 j;
    s32 k;
    s32 m;
    s32 n;

    objet->uBC = 0;
    objet->uDC = 0;
    objet->uE0 = 0;
    objet->uE4 = 0;
    objet->uE8 = 0;
    objet->uEC = 0;
    for (i = 0; i < 16; i++) {
        objet->uF0[i] = 0;
    }
    objet->u130 = 0;
    objet->u134 = 0;
    objet->u194 = 0;
    objet->u198 = 1;
    objet->u1D0 = GetDrawSpeedDef__6ClsMesFv(objet);
    objet->u1D8 = 0;
    objet->u1E4 = 0;
    objet->u1E8 = 0;
    objet->u1EC = 0;
    objet->u1F0 = 0;
    objet->u1F4 = 0;
    InitMesWinTbl__6ClsMesFv(objet);
    objet->u1E2C = objet->u1E28;
    objet->u1E30 = 0;
    objet->u1E34 = 0;
    objet->u1E38 = 0x1E;
    objet->u1E3C = -1;
    objet->u1E40 = 0;
    objet->u1E58 = 0x80;
    for (j = 0; j < 16; j++) {
        memset(objet->u1E59[j], 0, 0x32);
    }
    for (k = 0; k < 16; k++) {
        objet->u217C[k] = -1;
    }
    for (m = 0; m < 16; m++) {
        objet->u21BC[m] = 0;
        objet->u21FC[m] = 0;
    }
    objet->u223C = 0;
    objet->u2240 = 0;
    objet->u2244 = 1;
    objet->u2248 = 0;
    objet->u224C = 0;
    objet->u2250 = 0;
    objet->u2254 = -1;
    objet->u2258 = -1;
    objet->u225C = -1;
    objet->u2260 = 0;
    objet->u2264 = 0;
    objet->u2268 = 0;
    objet->u226C = 0;
    objet->u2270 = 0;
    objet->u2274 = 0;
    objet->u2278 = 0;
    objet->u227C = -1;
    objet->u2280 = -1;
    objet->u2284 = -1;
    objet->u2288 = -1;
    objet->u228C = 0;
    objet->u2290 = 0;
    objet->u2294 = 0;
    objet->u2298 = 0;
    objet->u229C = 0;
    objet->u22A0 = 0;
    objet->u22A8 = 0;
    objet->u22AC = 0;
    objet->u22B4 = 0;
    objet->u22B0 = 0;
    objet->u22B8 = 0;
    for (n = 0; n < 20; n++) {
        objet->u22BC[n] = 0;
        objet->u230C[n][0] = 0;
        objet->u230C[n][1] = 0;
        objet->u23AC[n] = 0;
        objet->u23FC[n] = -1;
        objet->u244C[n] = 0;
        objet->u249C[n] = 0;
        objet->u24EC[n] = 0;
        objet->u253C[n] = 0;
        objet->u258C[n] = 0;
        objet->u25DC[n] = -1;
        objet->u262C[n] = 0;
        objet->u267C[n] = 0;
        objet->u26CC[n] = 0;
        objet->u271C[n] = -1;
        objet->u276C[n] = -1;
        objet->u27BC[n] = 0;
        objet->u280C[n] = 0;
        objet->u285C[n] = 0;
        objet->u28AC[n] = 0;
        objet->u28FC[n] = 0;
    }
}
INCLUDE_ASM("nonmatchings/game/cmenutreemap", DngTreeMapKey__Fv);
INCLUDE_ASM("nonmatchings/game/cmenutreemap", DngTreeMapDraw__Fv);
s32 CBaseMenuClass::IsCreateObject(s32 a, s32 b) {
    return 1;
}
s32 CBaseMenuClass::IsMakeObject(s32 a, s32 b) {
    return 0;
}
s32 CBaseMenuClass::IsAskExtend(s32 a, s32 b) {
    return 0;
}
s32 CBaseMenuClass::ItemCmdAfter(s32 command, ITEMCMD_RET_PARA *para) {
    return 0;
}
extern "C" void ExitEnd__14CBaseMenuClassFv(void) {
}
void mgRect_f_::Set(f32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    this->field_0x0 = arg0;
    this->field_0x4 = arg1;
    this->field_0x8 = arg2;
    this->field_0xC = arg3;
}
INCLUDE_ASM("nonmatchings/game/cmenutreemap", GetPenkiColor__FiPf);
extern "C" s16 tbl_957[];
extern "C" s32 ConvGeoramaDataNo__Fi(s32 arg0) {
    return tbl_957[arg0];
}
INCLUDE_ASM("nonmatchings/game/cmenutreemap", CheckMenuLine__FPiPiii);
struct CPosDataManage;
extern "C" CPosDataManage *MenuPosData;
struct CPosDataManage {
    char pad_0[0x4];
    u16 field_4;
    char pad_6[0x6];
    u16 field_C;
    char pad_E[0x2];
    s32 field_10;
    u16 field_14;
    char pad_16[0x2];
    s32 field_18;
    u16 field_1C;
    u8 field_1E;
    char pad_1F[0x39];
    s32 field_58;
};
extern "C" u8 _990_0036DC80[14];
extern "C" s32 GetFormInfo__14CPosDataManageFPc(...);
typedef struct CMenuPosDataForm {
    /* 0x00 */ char pad0[1];
    /* 0x01 */ s8 unk1;                             /* inferred */
    /* 0x02 */ char pad2[0xA];                      /* maybe part of unk1[0xB]void */
    /* 0x0C */ s32 unkC;                            /* inferred */
    /* 0x10 */ s32 unk10;                           /* inferred */
} CMenuPosDataForm;                                 /* size >= 0x14 */
extern "C" s32 SetRGBACalcParam__16CMenuPosDataFormFiii(void *, s32, s32, s32);
extern "C" void SetEditMenuEnv__Fv(void) {
    CMenuPosDataForm *temp_v0;

    temp_v0 = (CMenuPosDataForm *) (GetFormInfo__14CPosDataManageFPc(MenuPosData, &_990_0036DC80));
    if (temp_v0 != NULL) {
        temp_v0->unk1 = 1;
        SetRGBACalcParam__16CMenuPosDataFormFiii(temp_v0, 0, -3, 0x40);
        SetRGBACalcParam__16CMenuPosDataFormFiii(temp_v0, 1, -3, 0x40);
        SetRGBACalcParam__16CMenuPosDataFormFiii(temp_v0, 2, -3, 0x40);
        temp_v0->unkC = 0;
        temp_v0->unk10 = 0;
    }
}
INCLUDE_ASM("nonmatchings/game/cmenutreemap", MenuGeoramaInit__FP9mgCMemoryi);
INCLUDE_ASM("nonmatchings/game/cmenutreemap", MenuGeoDebugKey__Fv);
INCLUDE_ASM("nonmatchings/game/cmenutreemap", MenuGeoramaKey__Fv);
INCLUDE_ASM("nonmatchings/game/cmenutreemap", MenuGeoramaDraw__Fv);
INCLUDE_ASM("nonmatchings/game/cmenutreemap", MenuGeoramaTitleDraw__FRiPfi);
INCLUDE_ASM("nonmatchings/game/cmenutreemap", MenuGeoramaListDraw__FRiPfii);
INCLUDE_ASM("nonmatchings/game/cmenutreemap", MenuGeoramaAnalyzeDraw__FRiPfi);
INCLUDE_ASM("nonmatchings/game/cmenutreemap", InitDownLoadAnaunce__FP9mgCMemory);
