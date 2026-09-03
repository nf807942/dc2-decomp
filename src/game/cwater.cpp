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

INCLUDE_ASM("nonmatchings/game/cwater", Initialize__7CMapSkyFv);
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
INCLUDE_ASM("nonmatchings/game/cwater", Initialize__11CFireRasterFv);
void CThunderEffect::Init(void) {
    this->field_0x0 = 0;
    this->field_0x90 = 0;
    this->field_0x94 = 0;
    this->field_0x98 = 0;
}
INCLUDE_ASM("nonmatchings/game/cwater", Hamon__6CWaterFv);
INCLUDE_ASM("nonmatchings/game/cwater", SetVertex__6CWaterFPfPf);
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
INCLUDE_ASM("nonmatchings/game/cwater", Initialize__11CWaterFrameFv);
INCLUDE_ASM("nonmatchings/game/cwater", SjisToJis__FUl);
INCLUDE_ASM("nonmatchings/game/cwater", SjisToSerno__FUl);
INCLUDE_ASM("nonmatchings/game/cwater", ascii2serno__FUc);
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
INCLUDE_ASM("nonmatchings/game/cwater", InitTexture__11dbgCJISFontFiPciPciPc);
void dbgCJISFont::Clear(void) {
    this->field_0x88 = 0;
}
INCLUDE_ASM("nonmatchings/game/cwater", __putc__11dbgCJISFontFUl);
INCLUDE_ASM("nonmatchings/game/cwater", PrintDirect__11dbgCJISFontFiiPce);
INCLUDE_ASM("nonmatchings/game/cwater", runerror__FPCc);
INCLUDE_ASM("nonmatchings/game/cwater", stkoverflow__Fv);
INCLUDE_ASM("nonmatchings/game/cwater", chk_int__F12RS_STACKDATAP8funcdata);
INCLUDE_ASM("nonmatchings/game/cwater", is_true__F12RS_STACKDATA);
INCLUDE_ASM("nonmatchings/game/cwater", divby0error__Fv);
INCLUDE_ASM("nonmatchings/game/cwater", modby0error__Fv);
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
INCLUDE_ASM("nonmatchings/game/cwater", ext_func__10CRunScriptFPPFP12RS_STACKDATAi_ii);
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
INCLUDE_ASM("nonmatchings/game/cwater", skip__10CRunScriptFv);
