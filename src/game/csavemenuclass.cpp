/* CSaveMenuClass
 *
 * Unité découpée par `make carve` : 23 fonctions, 21660 octets, de
 * 0x002C6E30 à 0x002CC360. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

INCLUDE_ASM("nonmatchings/game/csavemenuclass", MenuOptionInit__FP9mgCMemoryPii);
INCLUDE_ASM("nonmatchings/game/csavemenuclass", MenuOptionKey__Fv);
INCLUDE_ASM("nonmatchings/game/csavemenuclass", MenuOptionDraw__Fv);
INCLUDE_ASM("nonmatchings/game/csavemenuclass", LocalFunc_AdjustScrlBar__FPP18MENUFORMPARTS_TYPEPiPiiffi);
INCLUDE_ASM("nonmatchings/game/csavemenuclass", SetDlInfoMsg__14CSaveMenuClassFii);
extern "C" u32 LanguageCode;
typedef struct MemoryCardPtr_pointe {
    char pad0[1228];
    s32 unk4CC;
} MemoryCardPtr_pointe;
extern "C" MemoryCardPtr_pointe *MemoryCardPtr;
typedef struct MenuDCMsg_champs {
    char pad0[8];
    s32 unk8;
    char padC[24];
} MenuDCMsg_champs;
extern "C" MenuDCMsg_champs MenuDCMsg;
struct inferred;
struct mgCTexture {
    s16 field_0;
    s16 field_2;
    s16 field_4;
    s16 field_6;
    char pad_8[0x4];
    s32 field_C;
    s32 field_10;
    s16 field_14;
    char pad_16[0x2];
    s32 field_18;
    s32 field_1C;
    char pad_20[0x8];
    s32 field_28;
    s32 field_2C;
    s32 field_30;
    char pad_34[0x4];
    s64 field_38;
    s64 field_40;
    s64 field_48;
    s32 field_50;
    f32 field_54;
    f32 field_58;
    f32 field_5C;
    s32 field_60;
    s32 field_64;
    s32 field_68;
    char pad_6C[0xA4];
    s32 field_110;
    s32 field_114;
    s32 field_118;
    s16 field_11C;
    s8 field_11E;
    s8 field_11F;
    s16 field_120;
    s16 field_122;
    s32 field_124;
    s32 field_128;
    s8 field_12C;
    s8 field_12D;
    char pad_12E[0x2];
    s32 field_130;
    s32 field_134;
    s32 field_138;
    s32 field_13C;
    char pad_140[0x4];
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
    char pad_194[0x60];
    s32 field_1F4;
    s32 field_1F8;
    s32 field_1FC;
    s8 field_200;
    s8 field_201;
    s16 field_202;
    s32 field_204;
    s8 field_208;
    s8 field_209;
    char pad_20A[0x2];
    s32 field_20C;
    s32 field_210;
    s32 field_214;
    s32 field_218;
    s32 field_21C;
    char pad_220[0xC];
    s32 field_22C;
    s32 field_230;
    s32 field_234;
    s32 field_238;
    s32 field_23C;
    s32 field_240;
    char pad_244[0x4];
    s32 field_248;
    s16 field_24C;
    s16 field_24E;
    char pad_250[0x6];
    s16 field_256;
    f32 field_258;
    f32 field_25C;
    char pad_260[0x4];
    f32 field_264;
    f32 field_268;
    f32 field_26C;
    char pad_270[0x4];
    f32 field_274;
    f32 field_278;
    char pad_27C[0x68];
    s32 field_2E4;
    char pad_2E8[0x74];
    s32 field_35C;
    s32 field_360;
    s32 field_364;
};
typedef struct CDC2Mes {
    /* 0x0000 */ char pad0[0x1E4C];
    /* 0x1E4C */ s32 unk1E4C;                       /* inferred */
} CDC2Mes;                                          /* size >= 0x1E50 */
typedef struct CMemoryCardManager {
    /* 0x000 */ char pad0[0x4CC];
    /* 0x4CC */ s32 unk4CC;                         /* inferred */
} CMemoryCardManager;                               /* size >= 0x4D0 */
typedef struct CSaveMenuClass {
    /* 0x000 */ char pad0[0x114];
    /* 0x114 */ s32 unk114;                         /* inferred */
    /* 0x118 */ char pad118[8];                     /* maybe part of unk114[3]void */
    /* 0x120 */ s32 unk120;                         /* inferred */
    /* 0x124 */ char pad124[8];                     /* maybe part of unk120[3]void */
    /* 0x12C */ s32 unk12C;                         /* inferred */
    /* 0x130 */ char pad130[4];
    /* 0x134 */ s32 unk134;                         /* inferred */
    /* 0x138 */ char pad138[0x3C];                  /* maybe part of unk134[0x10]void */
    /* 0x174 */ mgCTexture *unk174;                 /* inferred */
    /* 0x178 */ char pad178[0xC];                   /* maybe part of unk174[4]void */
    /* 0x184 */ void *unk184;                       /* inferred */
} CSaveMenuClass;                                   /* size >= 0x188 */
struct temp_v0_champs {
    char pad0[0x1];
    /* 0x1 */ s8 unk1;
};
extern "C" s32 GetSaveDataSize__18CMemoryCardManagerFi(void *, s32);
extern "C" s32 InitMenuDl__FP10mgCTexturei(mgCTexture *, s32);
extern "C" s32 MakeMsg__7CDC2MesFi(void *, s32);
extern "C" s32 MsgPreset__7CDC2MesFii(void *, s32, s32);
extern "C" s32 SetAbsPos__7CDC2MesFi(void *, s32);
extern "C" s32 SetFuncNo__18CMemoryCardManagerFi(void *, s32);
extern "C" s32 SetMsgVolumeNoOne__7CDC2MesFi(void *, s32);
extern "C" s32 SetDlInfoMsg__14CSaveMenuClassFii(void *, s32, s32);
extern "C" void EnvSetSave__14CSaveMenuClassFi(CSaveMenuClass *objet, s32 arg0) {
    CDC2Mes *temp_s0;
    s32 var_a1;
    s32 var_s2;
    s32 var_s2_2;
    struct temp_v0_champs *temp_v0;

    objet->unk134 = 0;
    if (arg0 == 0) {
        var_a1 = 6;
        objet->unk12C = 2;
        var_s2 = 1;
    } else {
        var_a1 = 3;
        objet->unk12C = 0xA;
        var_s2 = 0;
    }
    MemoryCardPtr->unk4CC = objet->unk114;
    SetFuncNo__18CMemoryCardManagerFi(MemoryCardPtr, var_a1);
    var_s2_2 = GetSaveDataSize__18CMemoryCardManagerFi(MemoryCardPtr, var_s2);
    if (arg0 == 1) {
        var_s2_2 -= 0x1000;
    }
    temp_s0 = (CDC2Mes *) (MenuDCMsg.unk8);
    MsgPreset__7CDC2MesFii(temp_s0, 0xA, LanguageCode);
    temp_s0->unk1E4C = 0;
    SetAbsPos__7CDC2MesFi(temp_s0, 8);
    MakeMsg__7CDC2MesFi(temp_s0, 0xBBF);
    SetMsgVolumeNoOne__7CDC2MesFi(temp_s0, objet->unk120 + 1);
    temp_v0 = (struct temp_v0_champs *) (objet->unk184);
    if (temp_v0 != NULL) {
        temp_v0->unk1 = 0;
    }
    InitMenuDl__FP10mgCTexturei(objet->unk174, var_s2_2);
    SetDlInfoMsg__14CSaveMenuClassFii(objet, 0, 1);
}
INCLUDE_ASM("nonmatchings/game/csavemenuclass", KeyStep__14CSaveMenuClassFv);
INCLUDE_ASM("nonmatchings/game/csavemenuclass", SaveFileListDraw__FRiPfi);
INCLUDE_ASM("nonmatchings/game/csavemenuclass", SetMCIconData__FPUii);
INCLUDE_ASM("nonmatchings/game/csavemenuclass", GetDngMapNo__Fi);
INCLUDE_ASM("nonmatchings/game/csavemenuclass", SaveMapInfo__Fi);
INCLUDE_ASM("nonmatchings/game/csavemenuclass", ResetMapInfo__Fv);
INCLUDE_ASM("nonmatchings/game/csavemenuclass", MenuSaveInit__FP9mgCMemoryPii);
INCLUDE_ASM("nonmatchings/game/csavemenuclass", MenuSaveKey__Fv);
INCLUDE_ASM("nonmatchings/game/csavemenuclass", MenuSaveDraw__Fv);
INCLUDE_ASM("nonmatchings/game/csavemenuclass", SubGameCFGAnalyze__FPc);
INCLUDE_ASM("nonmatchings/game/csavemenuclass", SubGameSaveInit__FP9mgCMemoryPii);
INCLUDE_ASM("nonmatchings/game/csavemenuclass", SubGameSaveKey__Fv);
INCLUDE_ASM("nonmatchings/game/csavemenuclass", SubGameSaveDraw__Fv);
INCLUDE_ASM("nonmatchings/game/csavemenuclass", _MOVIE__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/csavemenuclass", MovieViewInit__F13INIT_LOOP_ARG);
extern "C" u32 performance_meter_flag;
extern "C" s32 mgCloseFont__Fv(void);
extern "C" s32 mgPerformanceMeter__Fi(s32);
extern "C" s32 sndSeAllStop__Fi(s32);
extern "C" void MovieViewExit__Fv(void) {
    sndSeAllStop__Fi(-1);
    mgCloseFont__Fv();
    mgPerformanceMeter__Fi(performance_meter_flag);
}
INCLUDE_ASM("nonmatchings/game/csavemenuclass", MovieViewLoop__Fv);
