/* CWater, CMapSky, dbgCJISFont, CFireRaster, CRunScript, CWaterFrame, CThunderEffect
 *
 * Unité découpée par `make carve` : 72 fonctions, 16636 octets, de
 * 0x001846F0 à 0x00188970. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"
#include "gen/CRunScript.hpp"
#include "gen/CThunderEffect.hpp"
#include "gen/CWater.hpp"
#include "gen/dbgCJISFont.hpp"
#include "gen/CWaterFrame.hpp"
#include "gen/dbgCJISFont.hpp"

struct inferred;
struct CMapSky;
typedef struct CMapSky {
    /* 0x00 */ char pad0[0x80];
    /* 0x80 */ s32 unk80;                           /* inferred */
    /* 0x84 */ s32 unk84;                           /* inferred */
} CMapSky;                                          /* size >= 0x88 */
struct temp_t0_champs_4de5e1 {
    /* 0x0 */ s32 unk0;
    char pad4[0xC];
    /* 0x10 */ s32 unk10;
    char pad14[0xC];
    /* 0x20 */ s32 unk20;
    char pad24[0xC];
    /* 0x30 */ s32 unk30;
    char pad34[0xC];
    /* 0x40 */ s32 unk40;
    char pad44[0xC];
    /* 0x50 */ s32 unk50;
    char pad54[0xC];
    /* 0x60 */ s32 unk60;
    char pad64[0xC];
    /* 0x70 */ s32 unk70;
};
struct temp_a3_champs_4de5e1 {
    char pad0[0x88];
    /* 0x88 */ s32 unk88;
    /* 0x8C */ s32 unk8C;
    /* 0x90 */ s32 unk90;
    /* 0x94 */ s32 unk94;
    /* 0x98 */ s32 unk98;
    /* 0x9C */ s32 unk9C;
    /* 0xA0 */ s32 unkA0;
    /* 0xA4 */ s32 unkA4;
    /* 0xA8 */ s32 unkA8;
    /* 0xAC */ s32 unkAC;
    /* 0xB0 */ s32 unkB0;
    /* 0xB4 */ s32 unkB4;
    /* 0xB8 */ s32 unkB8;
    /* 0xBC */ s32 unkBC;
    /* 0xC0 */ s32 unkC0;
    /* 0xC4 */ s32 unkC4;
};
struct objet_champs_4de5e1 {
    char pad0[0x80];
    /* 0x80 */ s32 unk80;
    /* 0x84 */ s32 unk84;
};
extern "C" void Initialize__7CMapSkyFv(CMapSky *objet) {
    s32 var_a1;
    s32 var_a2;
    s32 var_a2_2;
    s32 var_a3;
    struct temp_a3_champs_4de5e1 *temp_a3;
    struct temp_t0_champs_4de5e1 *temp_t0;

    var_a2 = 0;
    var_a3 = 0;
    do {
        /* La conversion en `u8 *` porte l'arithmetique en octets. Sans elle,
         * MWCC met le pas a l'echelle du type pointe et la constante emise
         * est multipliee d'autant. */
        temp_t0 = (struct temp_t0_champs_4de5e1 *) ((u8 *) objet + var_a3);
        var_a2 += 1;
        temp_t0->unk0 = 0;
        temp_t0->unk30 = 0;
        var_a3 += 4;
        temp_t0->unk60 = 0;
        temp_t0->unk40 = 0;
        temp_t0->unk10 = 0;
        temp_t0->unk50 = 0;
        temp_t0->unk20 = 0;
        temp_t0->unk70 = -1;
    } while (var_a2 < 4);
    var_a1 = 0;
    var_a2_2 = 0;
    do {
        temp_a3 = (struct temp_a3_champs_4de5e1 *) ((u8 *) objet + var_a2_2);
        var_a1 += 8;
        temp_a3->unk88 = 0;
        temp_a3->unk8C = 0;
        var_a2_2 += 0x40;
        temp_a3->unk90 = 0;
        temp_a3->unk94 = 0;
        temp_a3->unk98 = 0;
        temp_a3->unk9C = 0;
        temp_a3->unkA0 = 0;
        temp_a3->unkA4 = 0;
        temp_a3->unkA8 = 0;
        temp_a3->unkAC = 0;
        temp_a3->unkB0 = 0;
        temp_a3->unkB4 = 0;
        temp_a3->unkB8 = 0;
        temp_a3->unkBC = 0;
        temp_a3->unkC0 = 0;
        temp_a3->unkC4 = 0;
    } while (var_a1 < 0x10);
    ((struct objet_champs_4de5e1 *) objet)->unk80 = 0;
    ((struct objet_champs_4de5e1 *) objet)->unk84 = 0;
}

INCLUDE_ASM("nonmatchings/game/cwater", DrawSkyBack__7CMapSkyFPfPfPf);
INCLUDE_ASM("nonmatchings/game/cwater", DrawSky__7CMapSkyFPfPfPfiPfPf);
INCLUDE_ASM("nonmatchings/game/cwater", LoadPack__7CMapSkyFPUiiP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/cwater", LoadSkyPack__FP12MAP_SKY_INFOPci);
INCLUDE_ASM("nonmatchings/game/cwater", CheckSkyID__Fi);
INCLUDE_ASM("nonmatchings/game/cwater", _SKY_IMG__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cwater", _SKY_MDS__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cwater", _SUN_MDS__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cwater", _SKYB_MDS__FP9SPI_STACKi);
extern "C" u32 skyInfo;
struct SPI_STACK {
    s32 field_0;
    s32 field_4;
};
extern "C" s32 spiGetStackString__FP9SPI_STACK(SPI_STACK *);
extern "C" s32 strcpy(...);
extern "C" s32 _SKY_BG__FP9SPI_STACKi(SPI_STACK *arg0, s32 arg1) {
    s32 temp_v0;

    temp_v0 = (s32) (spiGetStackString__FP9SPI_STACK(arg0));
    if (temp_v0 != 0) {
        strcpy(skyInfo + 0x220, temp_v0);
    }
    return 1;
}
INCLUDE_ASM("nonmatchings/game/cwater", _SKY_ANIME__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cwater", _SKYB_ANIME__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cwater", Step__11CFireRasterFv);
INCLUDE_ASM("nonmatchings/game/cwater", SetTexture__11CFireRasterFP10mgCTexture);
INCLUDE_ASM("nonmatchings/game/cwater", Draw__11CFireRasterFPfPf);
struct CFireRaster {
    char pad_0[0x70];
    char field_70[0x28 * 0x20];
};
extern "C" s32 memset(...);
extern "C" void Initialize__11CFireRasterFv(CFireRaster *objet) {
    s32 var_s0;
    s32 var_s1;

    var_s1 = 0;
    var_s0 = 0;
    do {
        memset((u8 *) objet + var_s1 + 0x70, 0, 0x20);
        var_s0 += 1;
        var_s1 += 0x20;
    } while (var_s0 < 0x14);
}
void CThunderEffect::Init(void) {
    this->field_0x0 = 0;
    this->field_0x90 = 0;
    this->field_0x94 = 0;
    this->field_0x98 = 0;
}
INCLUDE_ASM("nonmatchings/game/cwater", Hamon__6CWaterFv);
struct CWater_vtx { u8 pad[0x60]; f32 lo[4]; f32 hi[4]; };
extern "C" s32 mgVectorMaxMin__FPfPfPfPf(f32 *, f32 *, f32 *, f32 *);
extern "C" s32 SetVertex__6CWaterFPfPf(CWater_vtx *self, f32 *arg0, f32 *arg1) {
    return mgVectorMaxMin__FPfPfPfPf(self->hi, self->lo, arg0, arg1);
}
INCLUDE_ASM("nonmatchings/game/cwater", Shake__6CWaterFiif);
INCLUDE_ASM("nonmatchings/game/cwater", Shake__11CWaterFrameFfff);
s32 CWaterFrame::GetWater(void) {
    return this->field_0xF8;
}
INCLUDE_ASM("nonmatchings/game/cwater", SetSize__6CWaterFiiP9mgCMemory);
void CWater::SetParam(f32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    this->field_0x40 = arg0;
    this->field_0x44 = arg1;
    this->field_0x48 = arg2;
    this->field_0x4C = arg3;
}
struct inferred;
typedef struct CWater_infere {
    /* 0x00 */ char pad0[0x30];
    /* 0x30 */ s32 unk30;                           /* inferred */
    /* 0x34 */ s32 unk34;                           /* inferred */
    /* 0x38 */ s32 unk38;                           /* inferred */
    /* 0x3C */ s32 unk3C;                           /* inferred */
} CWater_infere;                                           /* size >= 0x40 */
extern "C" void SetColor__6CWaterFUcUcUcUc(CWater_infere *objet, u8 arg0, u8 arg1, u8 arg2, u8 arg3) {
    objet->unk30 = arg0 & 0xFF;
    objet->unk34 = arg1 & 0xFF;
    objet->unk38 = arg2 & 0xFF;
    objet->unk3C = arg3 & 0xFF;
}
INCLUDE_ASM("nonmatchings/game/cwater", __ct__6CWaterFv);
INCLUDE_ASM("nonmatchings/game/cwater", CreateRenderInfoPacket__6CWaterFPUiPA4_fP13mgRENDER_INFO);
INCLUDE_ASM("nonmatchings/game/cwater", Draw__6CWaterFPUiPA4_fP14mgCDrawManager);
INCLUDE_ASM("nonmatchings/game/cwater", CreatePacket__6CWaterFP14mgCDrawManager);
INCLUDE_ASM("nonmatchings/game/cwater", SetTexture__11CWaterFrameFP10mgCTexture);
INCLUDE_ASM("nonmatchings/game/cwater", Step__11CWaterFrameFv);
INCLUDE_ASM("nonmatchings/game/cwater", SetParam__11CWaterFrameFffff);
INCLUDE_ASM("nonmatchings/game/cwater", SetColor__11CWaterFrameFUcUcUcUc);
INCLUDE_ASM("nonmatchings/game/cwater", Shake__11CWaterFrameFiif);
INCLUDE_ASM("nonmatchings/game/cwater", CreatePacket__11CWaterFrameFv);
INCLUDE_ASM("nonmatchings/game/cwater", CreateWaterFrame__FiiPfPfP9mgCMemory);
extern "C" void Initialize__8mgCFrameFv(void *);
extern "C" void Initialize__11CWaterFrameFv(void *objet) {
    *(s32 *) ((u8 *) objet + 0x110) = 0;
    *(s32 *) ((u8 *) objet + 0x114) = 0;
    Initialize__8mgCFrameFv(objet);
}
INCLUDE_ASM("nonmatchings/game/cwater", SjisToJis__FUl);
INCLUDE_ASM("nonmatchings/game/cwater", SjisToSerno__FUl);
extern "C" s32 ascii2serno__FUc(u8 arg0) {
    s32 temp_v0;

    temp_v0 = arg0 & 0xFF;
    switch (temp_v0) {
    case 0xA1:
        return 0x212C;
    case 0xA2:
        return 0x215F;
    case 0xA3:
        return 0x2160;
    case 0xA4:
        return 0x212B;
    case 0xA5:
        return 0x212F;
    case 0xDE:
        return 0x2134;
    case 0xDF:
        return 0x2135;
    case 0xA7:
        return 0x21E6;
    case 0xA8:
        return 0x21E8;
    case 0xA9:
        return 0x21EA;
    case 0xAA:
        return 0x21EC;
    case 0xAB:
        return 0x21EE;
    case 0xAC:
        return 0x2228;
    case 0xAD:
        return 0x222A;
    case 0xAE:
        return 0x222C;
    case 0xAF:
        return 0x2208;
    case 0xB1:
        return 0x21E7;
    case 0xB2:
        return 0x21E9;
    case 0xB3:
        return 0x21EB;
    case 0xB4:
        return 0x21ED;
    case 0xB5:
        return 0x21EF;
    case 0xB6:
        return 0x21F0;
    case 0xB7:
        return 0x21F2;
    case 0xB8:
        return 0x21F4;
    case 0xB9:
        return 0x21F6;
    case 0xBA:
        return 0x21F8;
    case 0xBB:
        return 0x21FA;
    case 0xBC:
        return 0x21FC;
    case 0xBD:
        return 0x21FE;
    case 0xBE:
        return 0x2200;
    case 0xBF:
        return 0x2202;
    case 0xC0:
        return 0x2204;
    case 0xC1:
        return 0x2206;
    case 0xC2:
        return 0x2209;
    case 0xC3:
        return 0x220B;
    case 0xC4:
        return 0x220D;
    case 0xC5:
        return 0x220F;
    case 0xC6:
        return 0x2210;
    case 0xC7:
        return 0x2211;
    case 0xC8:
        return 0x2212;
    case 0xC9:
        return 0x2213;
    case 0xCA:
        return 0x2214;
    case 0xCB:
        return 0x2217;
    case 0xCC:
        return 0x221A;
    case 0xCD:
        return 0x221D;
    case 0xCE:
        return 0x2220;
    case 0xCF:
        return 0x2223;
    case 0xD0:
        return 0x2224;
    case 0xD1:
        return 0x2225;
    case 0xD2:
        return 0x2226;
    case 0xD3:
        return 0x2227;
    case 0xD4:
        return 0x2229;
    case 0xD5:
        return 0x222B;
    case 0xD6:
        return 0x222D;
    case 0xD7:
        return 0x222E;
    case 0xD8:
        return 0x222F;
    case 0xD9:
        return 0x2230;
    case 0xDA:
        return 0x2231;
    case 0xDB:
        return 0x2232;
    case 0xDC:
        return 0x2234;
    case 0xA6:
        return 0x2237;
    case 0xDD:
        return 0x2238;
    case 0xA0:
    default:
        return 0x227E;
    }
}
extern "C" s32 Initialize__11dbgCJISFontFv(void *);
extern "C" dbgCJISFont *__ct__11dbgCJISFontFv(dbgCJISFont *objet) {
    Initialize__11dbgCJISFontFv(objet);
    return objet;
}
void dbgCJISFont::Initialize(void) {
    this->field_0xC = -1;
    this->field_0x8 = -1;
    this->field_0x4 = -1;
    this->field_0x0 = -1;
    this->field_0x50 = 0;
    this->field_0x30 = 0;
    this->field_0x10 = 0;
    this->field_0x74 = 0;
    this->field_0x70 = 0;
    this->field_0x7C = 16;
    this->field_0x78 = 16;
    this->field_0x88 = 0;
    this->field_0x894 = 128;
    this->field_0x890 = 128;
    this->field_0x88C = 128;
    this->field_0x888 = 128;
    this->field_0x898 = 0;
    this->field_0x8A4 = 0;
    this->field_0x8A0 = 0;
    this->field_0x89C = 0;
    this->field_0x8A8 = 64;
    this->field_0x8AC = 0;
}
extern "C" s32 strcpy(...);
extern "C" void InitTexture__11dbgCJISFontFiPciPciPc(dbgCJISFont *objet, s32 arg0, s8 *arg1, s32 arg2, s8 *arg3, s32 arg4, s8 *arg5) {
    objet->field_0x0 = arg0;
    objet->field_0x4 = arg2;
    objet->field_0x8 = arg4;
    strcpy(&objet->field_0x10, arg1);
    strcpy(&objet->field_0x30, arg3);
    strcpy(&objet->field_0x50, arg5);
}
void dbgCJISFont::Clear(void) {
    this->field_0x88 = 0;
}
INCLUDE_ASM("nonmatchings/game/cwater", __putc__11dbgCJISFontFUl);
INCLUDE_ASM("nonmatchings/game/cwater", PrintDirect__11dbgCJISFontFiiPce);
struct runerror_impure_global { u32 ptr; char pad[12]; };
extern "C" runerror_impure_global _impure_ptr;
extern "C" u8 _168[19];
struct runerror_impure_ptr {
    char pad0[0xC];
    s32 stream;
};
extern "C" s32 exit(...);
extern "C" s32 fprintf(...);
extern "C" void runerror__FPCc(const char *arg0) {
    fprintf(((runerror_impure_ptr *)_impure_ptr.ptr)->stream, &_168, arg0);
    exit(-1);
}
extern "C" void runerror__FPCc(const char *);
extern char _173[];
extern "C" s32 stkoverflow__Fv(void) {
    runerror__FPCc(_173);
}
INCLUDE_ASM("nonmatchings/game/cwater", chk_int__F12RS_STACKDATAP8funcdata);
INCLUDE_ASM("nonmatchings/game/cwater", is_true__F12RS_STACKDATA);
extern "C" void runerror__FPCc(const char *);
extern char _197[];
extern "C" void divby0error__Fv(void) {
    runerror__FPCc(_197);
}
extern "C" void runerror__FPCc(const char *);
extern char _202[];
extern "C" void modby0error__Fv(void) {
    runerror__FPCc(_202);
}
INCLUDE_ASM("nonmatchings/game/cwater", print__FP12RS_STACKDATAi);
struct inferred;
typedef struct CRunScript_infere {
    /* 0x00 */ s32 unk0;                            /* inferred */
    /* 0x04 */ s32 unk4;                            /* inferred */
    /* 0x08 */ char pad8[4];
    /* 0x0C */ s32 unkC;                            /* inferred */
    /* 0x10 */ s32 unk10;                           /* inferred */
    /* 0x14 */ s32 unk14;                           /* inferred */
    /* 0x18 */ s32 unk18;                           /* inferred */
    /* 0x1C */ char pad1C[4];
    /* 0x20 */ s32 unk20;                           /* inferred */
    /* 0x24 */ s32 unk24;                           /* inferred */
    /* 0x28 */ s32 unk28;                           /* inferred */
    /* 0x2C */ s32 unk2C;                           /* inferred */
    /* 0x30 */ char pad30[8];                       /* maybe part of unk2C[3]void */
    /* 0x38 */ s32 unk38;                           /* inferred */
    /* 0x3C */ char pad3C[4];
    /* 0x40 */ s32 unk40;                           /* inferred */
} CRunScript_infere;                                       /* size >= 0x44 */
extern "C" s32 DeleteProgram__10CRunScriptFv(void *);
extern "C" CRunScript_infere *__ct__10CRunScriptFv(CRunScript_infere *objet) {
    objet->unk14 = objet->unk10;
    objet->unk18 = objet->unk10;
    objet->unk28 = objet->unk24;
    objet->unk2C = objet->unk24;
    objet->unk38 = 0;
    objet->unk4 = 0;
    objet->unkC = 0;
    objet->unk20 = 0;
    objet->unk40 = 0;
    objet->unk0 = 1;
    DeleteProgram__10CRunScriptFv(objet);
    return objet;
}
void CRunScript::DeleteProgram(void) {
    this->field_0x3C = 0;
    this->field_0x40 = 0;
    this->field_0x44 = 0;
}
typedef struct CRunScript_infere2 {
    /* 0x00 */ char pad0[0x14];
    /* 0x14 */ u32 unk14;                           /* inferred */
    /* 0x18 */ u32 unk18;                           /* inferred */
} CRunScript_infere2;                                       /* size >= 0x1C */
extern "C" s32 stkoverflow__Fv(void);
extern "C" void check_stack__10CRunScriptFv(CRunScript_infere2 *objet) {
    if ((u32) objet->unk14 >= (u32) objet->unk18) {
        stkoverflow__Fv();
    }
}
INCLUDE_ASM("nonmatchings/game/cwater", push__10CRunScriptF12RS_STACKDATA);
INCLUDE_ASM("nonmatchings/game/cwater", push_int__10CRunScriptFi);
INCLUDE_ASM("nonmatchings/game/cwater", push_str__10CRunScriptFPc);
INCLUDE_ASM("nonmatchings/game/cwater", push_ptr__10CRunScriptFP12RS_STACKDATA);
INCLUDE_ASM("nonmatchings/game/cwater", push_float__10CRunScriptFf);
INCLUDE_ASM("nonmatchings/game/cwater", pop__10CRunScriptFv);
INCLUDE_ASM("nonmatchings/game/cwater", call_func__10CRunScriptFP8funcdataP8vmcode_t);
INCLUDE_ASM("nonmatchings/game/cwater", ret_func__10CRunScriptFv);
INCLUDE_ASM("nonmatchings/game/cwater", ext__10CRunScriptFP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/cwater", load__10CRunScriptFP14RS_PROG_HEADERP12RS_STACKDATAiP11RS_CALLDATAi);
struct CRunScript_ef { char pad0[4]; s32 unk4; s32 unk8; };
extern "C" void ext_func__10CRunScriptFPPFP12RS_STACKDATAi_ii(CRunScript_ef *objet, s32 arg0, s32 arg1) {
    objet->unk8 = arg0;
    objet->unk4 = arg1;
}
struct vmcode_t;
typedef struct CRunScript_infere3 {
    /* 0x00 */ char pad0[0x38];
    /* 0x38 */ vmcode_t *unk38;                     /* inferred */
} CRunScript_infere3;                                       /* size >= 0x3C */
extern "C" s32 exe__10CRunScriptFP8vmcode_t(void *, vmcode_t *);
extern "C" void resume__10CRunScriptFv(CRunScript_infere3 *objet) {
    vmcode_t *temp_a1;

    temp_a1 = (vmcode_t *) (objet->unk38);
    if (temp_a1 != NULL) {
        exe__10CRunScriptFP8vmcode_t(objet, temp_a1);
    }
}
INCLUDE_ASM("nonmatchings/game/cwater", run__10CRunScriptFi);
INCLUDE_ASM("nonmatchings/game/cwater", check_program__10CRunScriptFi);
extern "C" void skip__10CRunScriptFv(CRunScript_infere3 *objet) {
    *(s32 *) ((u8 *) objet + 0x40) = 1;
    resume__10CRunScriptFv(objet);
}
