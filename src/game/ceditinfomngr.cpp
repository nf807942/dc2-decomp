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
extern "C" u8 GamePad_003FA5A0[1144];
extern "C" u8 _2723[22];
extern "C" u8 _2724[12];
extern "C" u32 lang_tex;
extern "C" u32 mgFrameRate;
extern "C" u32 title_lang_cursor_cnt;
typedef struct title_lang_curxy_champs {
    s32 unk0;
    s32 unk4;
} title_lang_curxy_champs;
extern "C" title_lang_curxy_champs title_lang_curxy;
extern "C" s32 title_lang_fadealpha;
extern "C" s32 title_lang_phase;
extern "C" s32 title_lang_select;
struct mgCEnterIMGInfo;
struct mgCMemory;
struct TitleLangSelMemoire {
    char pad0[0x20];
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
};
extern "C" s32 Alloc__9mgCMemoryFi(...);
extern "C" s32 EnterIMGFile__17mgCTextureManagerFPUciP9mgCMemoryP15mgCEnterIMGInfo(void *, u8 *, s32, mgCMemory *, mgCEnterIMGInfo *);
extern "C" s32 GetTexture__17mgCTextureManagerFPci(...);
extern "C" s32 LoadFile2__FPcPvPii(...);
extern "C" s32 MenuModeOn__8CGamePadFi(void *, s32);
extern "C" s32 SetAutoRepeat__8CGamePadFiii(void *, s32, s32, s32);
extern "C" void TitleLangSelInit__FP9mgCMemory(mgCMemory *arg0) {
    s32 sp3C;
    s32 var_v0;
    u8 *temp_s1;

    SetAutoRepeat__8CGamePadFiii(&GamePad_003FA5A0, 0x5000, 0xF, 4);
    MenuModeOn__8CGamePadFi(&GamePad_003FA5A0, 0x78);
    title_lang_select = 0;
    mgFrameRate = 1;
    temp_s1 = (u8 *) (((struct TitleLangSelMemoire *) arg0)->unk20 + (((struct TitleLangSelMemoire *) arg0)->unk24 * 0x10));
    LoadFile2__FPcPvPii(&_2723, temp_s1, &sp3C, 0);
    var_v0 = sp3C >> 4;
    if (sp3C < 0) {
        var_v0 = (s32) (sp3C + 0xF) >> 4;
    }
    Alloc__9mgCMemoryFi(arg0, var_v0 + 1);
    EnterIMGFile__17mgCTextureManagerFPUciP9mgCMemoryP15mgCEnterIMGInfo(&mgTexManager, temp_s1, 1, NULL, NULL);
    lang_tex = GetTexture__17mgCTextureManagerFPci(&mgTexManager, &_2724, -1);
    title_lang_phase = 0;
    title_lang_curxy.unk0 = 0x42C80000;
    title_lang_fadealpha = 0x80;
    title_lang_curxy.unk4 = 0x42C80000;
    title_lang_cursor_cnt = 0;
}
extern "C" s32 AutoRepeatOff__8CGamePadFv(void *);
extern "C" s32 DeleteBlock__17mgCTextureManagerFi(void *, s32);
extern "C" s32 Down__8CGamePadFi(void *, s32);
extern "C" s32 MenuModeOff__8CGamePadFv(void *);
extern "C" s32 TitleLangSelKey__Fv(void) {
    switch (title_lang_phase) {
    case 0:
        title_lang_fadealpha -= 6;
        if (title_lang_fadealpha <= 0) {
            title_lang_fadealpha = 0;
            title_lang_phase += 1;
        }
        break;
    case 1:
        if (Down__8CGamePadFi(&GamePad_003FA5A0, 0x1000) != 0) {
            title_lang_select -= 1;
        }
        if (Down__8CGamePadFi(&GamePad_003FA5A0, 0x4000) != 0) {
            title_lang_select += 1;
        }
        if (title_lang_select < 0) {
            title_lang_select = 4;
        }
        if (title_lang_select > 4) {
            title_lang_select = 0;
        }
        if (Down__8CGamePadFi(&GamePad_003FA5A0, 0x40) != 0) {
            title_lang_phase += 1;
        }
        break;
    case 2:
        title_lang_fadealpha += 6;
        if (title_lang_fadealpha >= 0x80) {
            title_lang_fadealpha = 0x80;
            DeleteBlock__17mgCTextureManagerFi(&mgTexManager, 0);
            mgFrameRate = 2;
            lang_tex = 0;
            AutoRepeatOff__8CGamePadFv(&GamePad_003FA5A0);
            MenuModeOff__8CGamePadFv(&GamePad_003FA5A0);
            return title_lang_select + 1;
        }
        break;
    }
    return 0;
}
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
extern "C" u32 emapNowInfo_0037E114;
extern "C" u32 emapStack_0037E108;
struct SPI_STACK_chaine {
    s32 field_0;
    s32 field_4;
};
extern "C" s32 spiGetStackString__FP9SPI_STACK(SPI_STACK_chaine *);
extern "C" s32 strcpy(...);
extern "C" s32 strlen(...);
static inline u32 Align16Blocks(u32 n) {
    if (n & 0xF) {
        return (n >> 4) + 1;
    }
    return n >> 4;
}
struct emapNowInfo_parts_name {
    char pad0[0x40];
    /* 0x40 */ s32 unk40;
};
extern "C" s32 emapPARTS_NAME__FP9SPI_STACKi(SPI_STACK_chaine *arg0, s32 arg1) {
    s32 temp_v0;
    s32 temp_s1;

    if (emapNowInfo_0037E114 == NULL) {
        return 0;
    }
    temp_v0 = (s32) (spiGetStackString__FP9SPI_STACK(arg0));
    temp_s1 = Alloc__9mgCMemoryFi(emapStack_0037E108, Align16Blocks(strlen(temp_v0) + 1));
    if (temp_v0 != 0) {
        if (temp_s1 != 0) {
            strcpy(temp_s1, temp_v0);
            ((struct emapNowInfo_parts_name *) emapNowInfo_0037E114)->unk40 = temp_s1;
        }
    }
    return 1;
}
INCLUDE_ASM("nonmatchings/game/ceditinfomngr", emapPARTS_ATR__FP9SPI_STACKi);
extern "C" u32 emapMatID;
extern "C" u32 emapNowInfo_0037E114;
extern "C" s32 GetMaterial__14CEditPartsInfoFi(...);
struct SPI_STACK_ebfb5e;
typedef struct SPI_STACK_ebfb5e {
    /* 0x0 */ char pad0[8];
} SPI_STACK_ebfb5e;
struct temp_v0_champs_ebfb5e {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
};
extern "C" s32 spiGetStackInt__FP9SPI_STACK(...);
extern "C" s32 emapPARTS_MATERIAL__FP9SPI_STACKi(SPI_STACK_ebfb5e *arg0, s32 arg1) {
    s32 temp_a1;
    struct temp_v0_champs_ebfb5e *temp_v0;

    if ((emapNowInfo_0037E114 == NULL) || (arg1 < 2)) {
        return 0;
    }
    temp_a1 = emapMatID;
    emapMatID = temp_a1 + 1;
    temp_v0 = (struct temp_v0_champs_ebfb5e *) (GetMaterial__14CEditPartsInfoFi(emapNowInfo_0037E114, temp_a1));
    if (temp_v0 == NULL) {
        return 0;
    }
    temp_v0->unk0 = spiGetStackInt__FP9SPI_STACK(arg0++);
    temp_v0->unk4 = spiGetStackInt__FP9SPI_STACK(arg0);
    return 1;
}
struct emapNowInfo_parts_comment {
    char pad0[0x48];
    /* 0x48 */ s32 unk48;
};
extern "C" s32 emapPARTS_COMMENT__FP9SPI_STACKi(SPI_STACK_chaine *arg0, s32 arg1) {
    s32 temp_v0;
    s32 temp_s1;

    if (emapNowInfo_0037E114 == NULL) {
        return 0;
    }
    temp_v0 = (s32) (spiGetStackString__FP9SPI_STACK(arg0));
    temp_s1 = Alloc__9mgCMemoryFi(emapStack_0037E108, Align16Blocks(strlen(temp_v0) + 1));
    if (temp_v0 != 0) {
        if (temp_s1 != 0) {
            strcpy(temp_s1, temp_v0);
            ((struct emapNowInfo_parts_comment *) emapNowInfo_0037E114)->unk48 = temp_s1;
        }
    }
    return 1;
}
extern "C" u32 emapNowInfo_0037E114;
struct SPI_STACK_94ad22;
typedef struct SPI_STACK_94ad22 {
    /* 0x0 */ char pad0[8];
    /* 0x8 */ char unk8;                               /* inferred */
    /* 0x8 */ char pad8[1];
} SPI_STACK_94ad22;                                        /* size >= 0x9 */
struct emapNowInfo_0037E114_champs_94ad22 {
    char pad0[0x8];
    /* 0x8 */ s32 unk8;
    /* 0xC */ s32 unkC;
};
extern "C" s32 spiGetStackInt__FP9SPI_STACK(...);
extern "C" s32 emapCPOINT__FP9SPI_STACKi(SPI_STACK_94ad22 *arg0, s32 arg1) {
    char *next_slot;

    /* L'adresse du second emplacement de pile se calcule avant la garde : MWCC
     * la range alors dans le creneau de delai du branchement, ce que le
     * commerce fait. Posee apres la garde, elle rend 94 % — la forme de
     * l'expression n'y change rien, sa place seule decide. */
    next_slot = &arg0->unk8;
    if (emapNowInfo_0037E114 == NULL) {
        return 0;
    }
    ((struct emapNowInfo_0037E114_champs_94ad22 *) emapNowInfo_0037E114)->unk8 = spiGetStackInt__FP9SPI_STACK(arg0);
    ((struct emapNowInfo_0037E114_champs_94ad22 *) emapNowInfo_0037E114)->unkC = spiGetStackInt__FP9SPI_STACK((SPI_STACK_94ad22 *) next_slot);
    return 1;
}
extern "C" u32 emapNowInfo_0037E114;
struct SPI_STACK_523170 {
    s32 field_0;
    s32 field_4;
};
struct emapNowInfo_0037E114_champs_523170 {
    char pad0[0x10];
    /* 0x10 */ s32 unk10;
};
extern "C" s32 spiGetStackInt__FP9SPI_STACK(...);
extern "C" s32 emapWEIGHT__FP9SPI_STACKi(SPI_STACK_523170 *arg0, s32 arg1) {
    if (emapNowInfo_0037E114 == NULL) {
        return 0;
    }
    ((struct emapNowInfo_0037E114_champs_523170 *) emapNowInfo_0037E114)->unk10 = spiGetStackInt__FP9SPI_STACK(arg0);
    return 1;
}
struct SPI_STACK_0772dc {
    s32 field_0;
    s32 field_4;
};
struct emapNowInfo_0037E114_champs_0772dc {
    char pad0[0x18];
    /* 0x18 */ s32 unk18;
};
extern "C" s32 emapGEO_STONE__FP9SPI_STACKi(SPI_STACK_0772dc *arg0, s32 arg1) {
    if (emapNowInfo_0037E114 == NULL) {
        return 0;
    }
    ((struct emapNowInfo_0037E114_champs_0772dc *) emapNowInfo_0037E114)->unk18 = spiGetStackInt__FP9SPI_STACK(arg0);
    return 1;
}
struct SPI_STACK_e0ddfb {
    s32 field_0;
    s32 field_4;
};
struct emapNowInfo_0037E114_champs_e0ddfb {
    char pad0[0x14];
    /* 0x14 */ s32 unk14;
};
extern "C" s32 emapMAX_NUM__FP9SPI_STACKi(SPI_STACK_e0ddfb *arg0, s32 arg1) {
    if (emapNowInfo_0037E114 == NULL) {
        return 0;
    }
    ((struct emapNowInfo_0037E114_champs_e0ddfb *) emapNowInfo_0037E114)->unk14 = spiGetStackInt__FP9SPI_STACK(arg0);
    return 1;
}
struct SPI_STACK_bb866f {
    s32 field_0;
    s32 field_4;
};
struct emapNowInfo_0037E114_champs_bb866f {
    char pad0[0x1C];
    /* 0x1C */ s32 unk1C;
};
extern "C" s32 emapPAINT_NUM__FP9SPI_STACKi(SPI_STACK_bb866f *arg0, s32 arg1) {
    if (emapNowInfo_0037E114 == NULL) {
        return 0;
    }
    ((struct emapNowInfo_0037E114_champs_bb866f *) emapNowInfo_0037E114)->unk1C = spiGetStackInt__FP9SPI_STACK(arg0);
    return 1;
}
struct SPI_STACK_16ef7d {
    s32 field_0;
    s32 field_4;
};
struct emapNowInfo_0037E114_champs_16ef7d {
    char pad0[0x20];
    /* 0x20 */ s32 unk20;
};
extern "C" s32 emapPAINT_USED__FP9SPI_STACKi(SPI_STACK_16ef7d *arg0, s32 arg1) {
    if (emapNowInfo_0037E114 == NULL) {
        return 0;
    }
    ((struct emapNowInfo_0037E114_champs_16ef7d *) emapNowInfo_0037E114)->unk20 = spiGetStackInt__FP9SPI_STACK(arg0);
    return 1;
}
struct SPI_STACK_d30a97 {
    s32 field_0;
    s32 field_4;
};
struct emapNowInfo_0037E114_champs_d30a97 {
    char pad0[0x24];
    /* 0x24 */ s32 unk24;
};
extern "C" s32 emapPARTS_TYPE__FP9SPI_STACKi(SPI_STACK_d30a97 *arg0, s32 arg1) {
    if (emapNowInfo_0037E114 == NULL) {
        return 0;
    }
    ((struct emapNowInfo_0037E114_champs_d30a97 *) emapNowInfo_0037E114)->unk24 = spiGetStackInt__FP9SPI_STACK(arg0);
    return 1;
}
struct emapNowInfo_place_eps {
    char pad0[0x28];
    /* 0x28 */ f32 unk28;
};
extern "C" f32 spiGetStackFloat__FP9SPI_STACK(SPI_STACK_chaine *);
extern "C" s32 emapPLACE_EPS__FP9SPI_STACKi(SPI_STACK_chaine *arg0, s32 arg1) {
    if (emapNowInfo_0037E114 == NULL) {
        return 0;
    }
    ((struct emapNowInfo_place_eps *) emapNowInfo_0037E114)->unk28 = spiGetStackFloat__FP9SPI_STACK(arg0);
    return 1;
}
struct SPI_STACK_2b558e {
    s32 field_0;
    s32 field_4;
};
struct emapNowInfo_0037E114_champs_2b558e {
    char pad0[0x2C];
    /* 0x2C */ s32 unk2C;
};
extern "C" s32 emapMAP_NO__FP9SPI_STACKi(SPI_STACK_2b558e *arg0, s32 arg1) {
    if (emapNowInfo_0037E114 == NULL) {
        return 0;
    }
    ((struct emapNowInfo_0037E114_champs_2b558e *) emapNowInfo_0037E114)->unk2C = spiGetStackInt__FP9SPI_STACK(arg0);
    return 1;
}
struct emapNowInfo_polyn {
    char pad0[0x30];
    /* 0x30 */ s32 unk30;
    /* 0x34 */ s32 unk34;
    /* 0x38 */ s32 unk38;
};
extern "C" s32 emapPOLYN__FP9SPI_STACKi(SPI_STACK_ebfb5e *arg0, s32 arg1) {
    if (emapNowInfo_0037E114 == NULL) {
        return 0;
    }
    ((struct emapNowInfo_polyn *) emapNowInfo_0037E114)->unk30 = spiGetStackInt__FP9SPI_STACK(arg0++);
    if (arg1 >= 2) {
        ((struct emapNowInfo_polyn *) emapNowInfo_0037E114)->unk34 = spiGetStackInt__FP9SPI_STACK(arg0++);
    }
    if (arg1 >= 3) {
        ((struct emapNowInfo_polyn *) emapNowInfo_0037E114)->unk38 = spiGetStackInt__FP9SPI_STACK(arg0);
    }
    return 1;
}
struct SPI_STACK_bc7cb3 {
    s32 field_0;
    s32 field_4;
};
struct emapNowInfo_0037E114_champs_bc7cb3 {
    char pad0[0x4];
    /* 0x4 */ s32 unk4;
};
extern "C" s32 emapGROUND_PARTS__FP9SPI_STACKi(SPI_STACK_bc7cb3 *arg0, s32 arg1) {
    if (emapNowInfo_0037E114 == NULL) {
        return 0;
    }
    ((struct emapNowInfo_0037E114_champs_bc7cb3 *) emapNowInfo_0037E114)->unk4 = (s32) (((struct emapNowInfo_0037E114_champs_bc7cb3 *) emapNowInfo_0037E114)->unk4 | 7);
    return 1;
}
struct SPI_STACK_a8cf42 {
    s32 field_0;
    s32 field_4;
};
struct emapNowInfo_0037E114_champs_a8cf42 {
    char pad0[0x4];
    /* 0x4 */ s32 unk4;
};
extern "C" s32 emapBLOCK_PARTS__FP9SPI_STACKi(SPI_STACK_a8cf42 *arg0, s32 arg1) {
    if (emapNowInfo_0037E114 == NULL) {
        return 0;
    }
    ((struct emapNowInfo_0037E114_champs_a8cf42 *) emapNowInfo_0037E114)->unk4 = (s32) (((struct emapNowInfo_0037E114_champs_a8cf42 *) emapNowInfo_0037E114)->unk4 | 0x30);
    return 1;
}
struct SPI_STACK_1afb84 {
    s32 field_0;
    s32 field_4;
};
struct emapNowInfo_0037E114_champs_1afb84 {
    char pad0[0x4];
    /* 0x4 */ s32 unk4;
};
extern "C" s32 emapRIVER_PARTS__FP9SPI_STACKi(SPI_STACK_1afb84 *arg0, s32 arg1) {
    if (emapNowInfo_0037E114 == NULL) {
        return 0;
    }
    ((struct emapNowInfo_0037E114_champs_1afb84 *) emapNowInfo_0037E114)->unk4 = (s32) (((struct emapNowInfo_0037E114_champs_1afb84 *) emapNowInfo_0037E114)->unk4 | 0x80);
    return 1;
}
struct SPI_STACK_2c3eb3 {
    s32 field_0;
    s32 field_4;
};
struct emapNowInfo_0037E114_champs_2c3eb3 {
    char pad0[0x4];
    /* 0x4 */ s32 unk4;
};
extern "C" s32 emapFENCE_PARTS__FP9SPI_STACKi(SPI_STACK_2c3eb3 *arg0, s32 arg1) {
    if (emapNowInfo_0037E114 == NULL) {
        return 0;
    }
    ((struct emapNowInfo_0037E114_champs_2c3eb3 *) emapNowInfo_0037E114)->unk4 = (s32) (((struct emapNowInfo_0037E114_champs_2c3eb3 *) emapNowInfo_0037E114)->unk4 | 0x130);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/ceditinfomngr", emapRECT__FP9SPI_STACKi);
extern "C" u32 emapNowInfo_0037E114;
extern "C" u32 emapRectIdx_0037E124;
extern "C" u32 emapRectNum_0037E120;
struct SPI_STACK {
    s32 field_0;
    s32 field_4;
};
extern "C" s32 spiGetStackInt__FP9SPI_STACK(...);
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
