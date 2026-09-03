/* CEditInfoMngr, CEditMap
 *
 * Unité découpée par `make carve` : 61 fonctions, 17280 octets, de
 * 0x002A5B10 à 0x002A9FF0. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"
#include "gen/CEditInfoMngr.hpp"
struct CEditPartsInfo;
struct ePlaceData;


INCLUDE_ASM("nonmatchings/game/ceditinfomngr", TitleModeDraw__Fv);
INCLUDE_ASM("nonmatchings/game/ceditinfomngr", TitleMapDraw__Fv);
INCLUDE_ASM("nonmatchings/game/ceditinfomngr", CalcPushAlpha__FiPf);
INCLUDE_ASM("nonmatchings/game/ceditinfomngr", TitleMCCheckInit__Fi);
INCLUDE_ASM("nonmatchings/game/ceditinfomngr", TitleMCCheckKey__Fv);
struct ClsMes;
extern "C" ClsMes *TitleMCCheckMes;
extern "C" u8 mgTexManager[540];
struct ClsMes {
    s64 field_0;
    char pad_8[0x88];
    s32 field_90;
    char pad_94[0x14];
    s32 field_A8;
    char pad_AC[0x4];
    s32 field_B0;
    s32 field_B4;
    s32 field_B8;
    s32 field_BC;
    s32 field_C0;
    s32 field_C4;
    s32 field_C8;
    s32 field_CC;
    f32 field_D0;
    s32 field_D4;
    s32 field_D8;
    s32 field_DC;
    s32 field_E0;
    s32 field_E4;
    s32 field_E8;
    s32 field_EC;
    char pad_F0[0x40];
    s32 field_130;
    s32 field_134;
    s32 field_138;
    s32 field_13C;
    s32 field_140;
    s32 field_144;
    s32 field_148;
    s32 field_14C;
    s32 field_150;
    s32 field_154;
    s32 field_158;
    s32 field_15C;
    s32 field_160;
    s32 field_164;
    s32 field_168;
    s32 field_16C;
    s32 field_170;
    s32 field_174;
    s32 field_178;
    s32 field_17C;
    s32 field_180;
    s32 field_184;
    s32 field_188;
    s32 field_18C;
    s32 field_190;
    s32 field_194;
    s32 field_198;
    s32 field_19C;
    s32 field_1A0;
    s32 field_1A4;
    s32 field_1A8;
    s32 field_1AC;
    s32 field_1B0;
    f32 field_1B4;
    f32 field_1B8;
    s32 field_1BC;
    s32 field_1C0;
    char pad_1C4[0x4];
    s8 field_1C8;
    s8 field_1C9;
    s8 field_1CA;
    s8 field_1CB;
    char pad_1CC[0x4];
    f32 field_1D0;
    s32 field_1D4;
    s32 field_1D8;
    s32 field_1DC;
    s32 field_1E0;
    s32 field_1E4;
    s32 field_1E8;
    s32 field_1EC;
    s32 field_1F0;
    s32 field_1F4;
    char pad_1F8[0x1C20];
    s32 field_1E18;
    s32 field_1E1C;
    s32 field_1E20;
    s32 field_1E24;
    s32 field_1E28;
    s32 field_1E2C;
    s32 field_1E30;
    s32 field_1E34;
    s32 field_1E38;
    s32 field_1E3C;
    s32 field_1E40;
    s32 field_1E44;
    s32 field_1E48;
    s32 field_1E4C;
    s32 field_1E50;
    s32 field_1E54;
    s8 field_1E58;
    s8 field_1E59;
    char pad_1E5A[0x31];
    s8 field_1E8B;
    char pad_1E8C[0x31];
    s8 field_1EBD;
    char pad_1EBE[0x2BE];
    s32 field_217C;
    s32 field_2180;
    s32 field_2184;
    s32 field_2188;
    s32 field_218C;
    s32 field_2190;
    s32 field_2194;
    s32 field_2198;
    s32 field_219C;
    s32 field_21A0;
    s32 field_21A4;
    s32 field_21A8;
    s32 field_21AC;
    s32 field_21B0;
    s32 field_21B4;
    s32 field_21B8;
    s32 field_21BC;
    s32 field_21C0;
    char pad_21C4[0x38];
    s32 field_21FC;
    s32 field_2200;
    char pad_2204[0x38];
    s32 field_223C;
    s32 field_2240;
    s32 field_2244;
    s32 field_2248;
    s32 field_224C;
    s32 field_2250;
    s32 field_2254;
    s32 field_2258;
    s32 field_225C;
    s32 field_2260;
    s32 field_2264;
    s32 field_2268;
    s32 field_226C;
    s32 field_2270;
    s32 field_2274;
    s32 field_2278;
    s32 field_227C;
    s32 field_2280;
    s32 field_2284;
    s32 field_2288;
    s32 field_228C;
    s32 field_2290;
    s32 field_2294;
    s32 field_2298;
    s32 field_229C;
    s32 field_22A0;
    s32 field_22A4;
    s32 field_22A8;
    s32 field_22AC;
    s32 field_22B0;
    s32 field_22B4;
    s32 field_22B8;
    char pad_22BC[0x50];
    s32 field_230C;
    s32 field_2310;
    s32 field_2314;
    s32 field_2318;
    char pad_231C[0x30];
    s32 field_234C;
    char pad_2350[0x4];
    s32 field_2354;
    s32 field_2358;
    s32 field_235C;
    s32 field_2360;
    char pad_2364[0x48];
    s32 field_23AC;
    s32 field_23B0;
    char pad_23B4[0x18];
    s32 field_23CC;
    s32 field_23D0;
    s32 field_23D4;
    char pad_23D8[0x1B4];
    s32 field_258C;
    s32 field_2590;
    char pad_2594[0x3B8];
    s32 field_294C;
};
struct sceVif1Packet;
extern "C" s32 DrawMesWin__6ClsMesFv(void *);
extern "C" s32 ReloadTexture__17mgCTextureManagerFiP13sceVif1Packet(void *, s32, sceVif1Packet *);
extern "C" s32 Step__6ClsMesFv(void *);
extern "C" void TitleMCCheckDraw__Fv(void) {
    if (TitleMCCheckMes != NULL) {
        ReloadTexture__17mgCTextureManagerFiP13sceVif1Packet(&mgTexManager, 0x46, NULL);
        Step__6ClsMesFv(TitleMCCheckMes);
        DrawMesWin__6ClsMesFv(TitleMCCheckMes);
    }
}
s32 DCTitleStep(s32 phase) {
    return 0;
}
INCLUDE_ASM("nonmatchings/game/ceditinfomngr", TitleCopyRightInit__Fv);
INCLUDE_ASM("nonmatchings/game/ceditinfomngr", TitleCopyRightStep__Fv);
INCLUDE_ASM("nonmatchings/game/ceditinfomngr", TitleCopyRightDraw__Fv);
INCLUDE_ASM("nonmatchings/game/ceditinfomngr", TitleHDDInstallInit__Fv);
INCLUDE_ASM("nonmatchings/game/ceditinfomngr", TitleHDDInstallKey__Fv);
INCLUDE_ASM("nonmatchings/game/ceditinfomngr", DrawMenuDl__Fiiiif);
INCLUDE_ASM("nonmatchings/game/ceditinfomngr", TitleHDDInstallDraw__Fv);
extern "C" s32 CheckAppInstall__Fv(void);
extern "C" s32 GetMainFileDev__Fv(void);
extern "C" s32 CheckAppInstallForTitle__Fv(void) {
    if (GetMainFileDev__Fv() == 3) {
        return 1;
    }
    return CheckAppInstall__Fv();
}
INCLUDE_ASM("nonmatchings/game/ceditinfomngr", CheckHDDInstall__Fv);
INCLUDE_ASM("nonmatchings/game/ceditinfomngr", TitleLangSelInit__FP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/ceditinfomngr", TitleLangSelKey__Fv);
INCLUDE_ASM("nonmatchings/game/ceditinfomngr", GetSelectLanguageNo__Fv);
INCLUDE_ASM("nonmatchings/game/ceditinfomngr", TitleLangSelDraw__Fv);
INCLUDE_ASM("nonmatchings/game/ceditinfomngr", InitSoundViewerMain__F13INIT_LOOP_ARG);
void FinishSoundVieweMain(void) {
}
s32 LoopSoundViewerMain(void) {
    return 1;
}
void CEditInfoMngr::Initialize(void) {
    this->field_0x0 = 0;
    this->field_0x4 = 0;
    this->field_0x8 = 0;
    this->field_0xC = 0;
    this->field_0x10 = 0;
    this->field_0x14 = 0;
}
void CEditInfoMngr::SetePartsInfoTable(CEditPartsInfo * arg0, s32 arg1) {
    this->field_0x0 = arg1;
    this->field_0x4 = arg0;
}
void CEditInfoMngr::SeteFixPartsTable(ePlaceData * arg0, s32 arg1) {
    this->field_0x8 = arg1;
    this->field_0xC = arg0;
}
INCLUDE_ASM("nonmatchings/game/ceditinfomngr", GetePartsInfo__13CEditInfoMngrFi);
INCLUDE_ASM("nonmatchings/game/ceditinfomngr", GetePartsInfo__13CEditInfoMngrFPc);
INCLUDE_ASM("nonmatchings/game/ceditinfomngr", GetePartsInfoAtID__13CEditInfoMngrFi);
INCLUDE_ASM("nonmatchings/game/ceditinfomngr", GetePartsInfoAtType__13CEditInfoMngrFi);
INCLUDE_ASM("nonmatchings/game/ceditinfomngr", emapEDIT_PARTS_NUM__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceditinfomngr", emapEDIT_PARTS__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceditinfomngr", emapID__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceditinfomngr", emapPARTS_NAME__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceditinfomngr", emapPARTS_ATR__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceditinfomngr", emapPARTS_MATERIAL__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceditinfomngr", emapPARTS_COMMENT__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceditinfomngr", emapCPOINT__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceditinfomngr", emapWEIGHT__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceditinfomngr", emapGEO_STONE__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceditinfomngr", emapMAX_NUM__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceditinfomngr", emapPAINT_NUM__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceditinfomngr", emapPAINT_USED__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceditinfomngr", emapPARTS_TYPE__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceditinfomngr", emapPLACE_EPS__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceditinfomngr", emapMAP_NO__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceditinfomngr", emapPOLYN__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceditinfomngr", emapGROUND_PARTS__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceditinfomngr", emapBLOCK_PARTS__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceditinfomngr", emapRIVER_PARTS__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceditinfomngr", emapFENCE_PARTS__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceditinfomngr", emapRECT__FP9SPI_STACKi);
extern "C" u32 emapNowInfo_0037E114;
extern "C" u32 emapRectIdx_0037E124;
extern "C" u32 emapRectNum_0037E120;
struct SPI_STACK {
    s32 field_0;
    s32 field_4;
};
extern "C" s32 spiGetStackInt__FP9SPI_STACK(SPI_STACK *);
extern "C" s32 emapPLACE_RECT__FP9SPI_STACKi(SPI_STACK *arg0, s32 arg1) {
    if (emapNowInfo_0037E114 == 0) {
        return 0;
    }
    emapRectNum_0037E120 = spiGetStackInt__FP9SPI_STACK(arg0);
    emapRectIdx_0037E124 = 0;
    return 1;
}
INCLUDE_ASM("nonmatchings/game/ceditinfomngr", emapPLACE_RECT_END__FP9SPI_STACKi);
extern "C" s32 emapPARTS_RECT__FP9SPI_STACKi(SPI_STACK *arg0, s32 arg1) {
    if (emapNowInfo_0037E114 == 0) {
        return 0;
    }
    emapRectNum_0037E120 = spiGetStackInt__FP9SPI_STACK(arg0);
    emapRectIdx_0037E124 = 0;
    return 1;
}
INCLUDE_ASM("nonmatchings/game/ceditinfomngr", emapPARTS_RECT_END__FP9SPI_STACKi);
extern "C" s32 emapPUT_RECT__FP9SPI_STACKi(SPI_STACK *arg0, s32 arg1) {
    if (emapNowInfo_0037E114 == 0) {
        return 0;
    }
    emapRectNum_0037E120 = spiGetStackInt__FP9SPI_STACK(arg0);
    emapRectIdx_0037E124 = 0;
    return 1;
}
INCLUDE_ASM("nonmatchings/game/ceditinfomngr", emapPUT_RECT_END__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceditinfomngr", emapEDIT_PARTS_END__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceditinfomngr", LoadEditInfo__13CEditInfoMngrFPciP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/ceditinfomngr", GetEvent__8CEditMapFPfiP12MapEventInfo);
