/* CMemoryCardManager, CSWordAfterEffect, CSaveData, CGeyserEffect, CSphidaData, CSaveDataDungeon, CDngFloorManager, CGyoRaceData, CSubGameData, GYORACE_DATA, CGeyserEffectPoint
 *
 * Unité découpée par `make carve` : 135 fonctions, 32036 octets, de
 * 0x002F6690 à 0x002FE6C0. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"
#include "gen/CSWordAfterEffect.hpp"
#include "gen/CGeyserEffectPoint.hpp"
#include "gen/CSphidaData.hpp"
#include "gen/CSubGameData.hpp"

/* Le corps ne rend qu'un code : ni la classe ni les arguments ne sont
 * déréférencés, donc leur disposition reste à établir. */
class CMemoryCardManager {
public:
    u8 field_0;
    char pad_1[0x3];
    s32 field_4;
    s16 field_8;
    char pad_A[0x6];
    u8 field_10;
    char pad_11[0x1F];
    u8 field_30;
    char pad_31[0x1F];
    s32 field_50;
    char pad_54[0x4];
    s32 field_58;
    s32 field_5C;
    char pad_60[0x30];
    u32 field_90;
    char pad_94[0x17C];
    u32 field_210;
    char pad_214[0x148];
    s32 field_35C;
    s32 field_360;
    s32 field_364;
    char pad_368[0x158];
    s32 field_4C0;
    s32 field_4C4;
    s32 field_4C8;
    s32 field_4CC;
    s32 field_4D0;
    s32 field_4D4;
    s32 field_4D8;
    s32 field_4DC;
    s32 field_4E0;
    char pad_4E4[0x8];
    u8 field_4EC;
    char pad_4ED[0x40B];
    s32 field_8F8;
    s32 field_8FC;
    s32 field_900;
    s32 field_904;
    s32 field_908;
    s32 field_90C;
    char pad_910[0x4];
    s32 field_914;
    s32 field_918;
    s32 field_91C;
    u8 field_920;
    char pad_921[0x23];
    s32 field_944;
    u8 field_948;
    char pad_949[0x23];
    s32 field_96C;
    u8 field_970;
    char pad_971[0x23];
    s32 field_994;
    u8 field_998;
    char pad_999[0x5];
    u16 field_99E;
    char pad_9A0[0x4];
    s32 field_9A4;
    u8 field_9A8;
    char pad_9A9[0x3F];
    u8 field_9E8;
    char pad_9E9[0x2F];
    u8 field_A18;
    char pad_A19[0x2F];
    u8 field_A48;
    char pad_A49[0xF];
    s8 field_A58;
    char pad_A59[0x43];
    u8 field_A9C;
    char pad_A9D[0x3F];
    u8 field_ADC;
    char pad_ADD[0x3F];
    u8 field_B1C;
    char pad_B1D[0x5C3];
    s32 field_10E0;
    s32 field_10E4;

    s32 Convert();
};
extern "C" void *memset(void *destination, s32 value, u32 size);

extern s32 fade_cnt;
extern s32 next_thunder_cnt;
extern s32 rea_chara_id;
extern s32 rea_mtn_step;
extern s32 sound_cnt;
extern s32 sound_flag;
extern s32 start_thunder;
extern s32 thunder_count;


#include "menu.hpp"
extern "C" s32 Initialize__18CMemoryCardManagerFP9mgCMemory(CMemoryCardManager *objet, mgCMemory *arg0);
extern "C" CMemoryCardManager *__ct__18CMemoryCardManagerFv(CMemoryCardManager *objet) {
    Initialize__18CMemoryCardManagerFP9mgCMemory(objet, NULL);
    return objet;
}
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", Initialize__18CMemoryCardManagerFP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", InitSaveFileInfoTable__18CMemoryCardManagerFv);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", GetOpenAttribute__18CMemoryCardManagerFPc);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", InitError__18CMemoryCardManagerFv);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", InitForMC__18CMemoryCardManagerFv);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", FinishForMC__18CMemoryCardManagerFv);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", SetBuff_Album__18CMemoryCardManagerFPc);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", SetIconData__18CMemoryCardManagerFP12MC_ICON_DATAi);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", GetIconDataSize__18CMemoryCardManagerFv);
extern "C" s32 GetIconDataSize__18CMemoryCardManagerFv(CMemoryCardManager *objet);
extern "C" s32 GetSaveDataSize__18CMemoryCardManagerFi(CMemoryCardManager *objet, s32 arg0) {
    s32 var_v0;

    var_v0 = 0;
    if (arg0 == 0) {
        var_v0 = (GetIconDataSize__18CMemoryCardManagerFv(objet) + 0x19A) << 0xA;
    }
    if (arg0 == 1) {
        var_v0 = 0x659C0;
    }
    if (arg0 == 2) {
        var_v0 = 0x64CB0;
    }
    if (arg0 == 3) {
        var_v0 = GetIconDataSize__18CMemoryCardManagerFv(objet) << 0xA;
    }
    if (arg0 == 4) {
        var_v0 = (GetIconDataSize__18CMemoryCardManagerFv(objet) << 0xA) + 0x654B0;
    }
    if (arg0 == 5) {
        var_v0 = GetIconDataSize__18CMemoryCardManagerFv(objet) + 0x199;
    }
    if (arg0 == 6) {
        var_v0 = 0x20800;
    }
    if (arg0 == 7) {
        var_v0 = 0x5470;
    }
    if (arg0 == 8) {
        var_v0 = (GetIconDataSize__18CMemoryCardManagerFv(objet) << 0xA) + 0x5C70;
    }
    if (arg0 == 9) {
        var_v0 = GetIconDataSize__18CMemoryCardManagerFv(objet) + 0x1B;
    }
    return var_v0;
}
typedef struct CMemoryCardManager_infere {
    /* 0x000 */ char pad0[0x50];
    /* 0x050 */ s32 unk50;                          /* inferred */
    /* 0x054 */ char pad54[4];
    /* 0x058 */ s32 unk58;                          /* inferred */
    /* 0x05C */ char pad5C[0x8B0];                  /* maybe part of unk58[0x22D]? */
    /* 0x90C */ s32 unk90C;                         /* inferred */
} CMemoryCardManager_infere;                               /* size >= 0x910 */
extern "C" void SetFuncNo__18CMemoryCardManagerFi(CMemoryCardManager_infere *objet, s32 arg0) {
    objet->unk50 = arg0;
    objet->unk58 = 0;
    if (arg0 == 1) {
        objet->unk90C = 0xB;
    }
}
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", GetFuncNo__18CMemoryCardManagerFv);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", CheckMaxUniqueCounter__18CMemoryCardManagerFv);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", GetUpdateFile__18CMemoryCardManagerFv);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", CheckDataFileNum__18CMemoryCardManagerFv);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", CheckOmake__18CMemoryCardManagerFPUl);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", CheckDebugCode__18CMemoryCardManagerFv);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", InitPlayDataInfo__18CMemoryCardManagerFv);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", UpDateViewInfo__18CMemoryCardManagerFP13SAVEDATA_INFOP15SAVEDATA_FORMAT);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", Step__18CMemoryCardManagerFv);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", GetVersion__18CMemoryCardManagerFv);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", SearchMcType__18CMemoryCardManagerFv);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", Write__18CMemoryCardManagerFv);
s32 CMemoryCardManager::Convert(void) {
    return 1;
}
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", MakeDir__18CMemoryCardManagerFi);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", GetCostumeList__FUliPs);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", SaveToMc__18CMemoryCardManagerFi);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", LoadFromMc__18CMemoryCardManagerFi);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", SaveAlbum__18CMemoryCardManagerFv);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", LoadAlbum__18CMemoryCardManagerFv);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", CheckAlbum__18CMemoryCardManagerFv);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", SaveOamkeFile__18CMemoryCardManagerFv);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", LoadOmakeFile__18CMemoryCardManagerFv);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", CheckOmakeFile__18CMemoryCardManagerFv);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", Format__18CMemoryCardManagerFv);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", DeleteFile__18CMemoryCardManagerFi);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", McError__18CMemoryCardManagerFi);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", UnFormat__18CMemoryCardManagerFv);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", GetSaveFileInfoFromMc__18CMemoryCardManagerFiPi);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", GetAllSaveFileInfo__18CMemoryCardManagerFv);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", McCheckMCPs2__FP12MC_CARD_INFO);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", McCheckMCPs2Boot__FP12MC_CARD_INFOi);
extern "C" u8 cosbit_table[136];
extern "C" s16 *GetCosInfo__Fi(s32 arg0) {
    s16 *var_v0;
    s32 var_a1;

    var_a1 = 0;
    var_v0 = (s16 *) (&cosbit_table);
loop_1:
    if (*var_v0 == arg0) {
        return var_v0;
    }
    var_a1 += 1;
    /* m2c compte les pas de pointeur en octets ; MWCC les met a
    * l'echelle du type pointe. Le pas est donc ecrit en elements,
    * et le commerce rend la meme constante. */
    var_v0 += 2;
    if (var_a1 >= 0x22) {
        return NULL;
    }
    goto loop_1;
}

INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", CreatSmoothPassSW__FPA4_fPA4_fiiii);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", Draw__17CSWordAfterEffectFv);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", CreatPointList__17CSWordAfterEffectFv);
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
typedef struct CSWordAfterEffect_infere2 {
    /* 0x00 */ char pad0[0x20];
    /* 0x20 */ s32 unk20;                           /* inferred */
    /* 0x24 */ s32 unk24;                           /* inferred */
    /* 0x28 */ s32 unk28;                           /* inferred */
    /* 0x2C */ s32 unk2C;                           /* inferred */
    /* 0x30 */ s32 unk30;                           /* inferred */
    /* 0x34 */ s32 unk34;                           /* inferred */
    /* 0x38 */ s32 unk38;                           /* inferred */
    /* 0x3C */ s32 unk3C;                           /* inferred */
    /* 0x40 */ char pad40[0x20];                    /* maybe part of unk3C[9]void */
    /* 0x60 */ s32 unk60;                           /* inferred */
    /* 0x64 */ mgCTexture *unk64;                   /* inferred */
    /* 0x68 */ s32 unk68;                           /* inferred */
    /* 0x6C */ s32 unk6C;                           /* inferred */
    /* 0x70 */ s32 unk70;                           /* inferred */
    /* 0x74 */ s32 unk74;                           /* inferred */
} CSWordAfterEffect_infere2;                                /* size >= 0x78 */
extern "C" void SetTexture__17CSWordAfterEffectFiP10mgCTextureiiii(CSWordAfterEffect_infere2 *objet, s32 arg0, mgCTexture *arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    objet->unk60 = arg0;
    objet->unk64 = arg1;
    objet->unk68 = arg2;
    objet->unk6C = arg3;
    objet->unk70 = arg4;
    objet->unk74 = arg5;
    objet->unk2C = 0x80;
    objet->unk28 = 0x80;
    objet->unk24 = 0x80;
    objet->unk20 = 0x80;
    objet->unk3C = 0x80;
    objet->unk38 = 0x80;
    objet->unk34 = 0x80;
    objet->unk30 = 0x80;
}
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", SetTexture__17CSWordAfterEffectFiiii);
extern "C" u8 _356_00377D08[10];
struct inferred;
#include "gen/mgCFrame.hpp"
typedef struct CSWordAfterEffect_infere {
    /* 0x00 */ mgCFrame *unk0;                      /* inferred */
    /* 0x04 */ mgCFrame *unk4;                      /* inferred */
    /* 0x08 */ char pad8[0x54];                     /* maybe part of unk4[0x16]void */
    /* 0x5C */ s32 unk5C;                           /* inferred */
    /* 0x60 */ char pad60[0x18];                    /* maybe part of unk5C[7]void */
    /* 0x78 */ s32 unk78;                           /* inferred */
    /* 0x7C */ s32 unk7C;                           /* inferred */
    /* 0x80 */ s32 unk80;                           /* inferred */
    /* 0x84 */ s32 unk84;                           /* inferred */
    /* 0x88 */ s32 unk88;                           /* inferred */
    /* 0x8C */ s32 unk8C;                           /* inferred */
    /* 0x90 */ s32 unk90;                           /* inferred */
    /* 0x94 */ s32 unk94;                           /* inferred */
    /* 0x98 */ f32 unk98;                           /* inferred */
} CSWordAfterEffect_infere;                                /* size >= 0x9C */
extern "C" s32 printf(void *);
extern "C" void StartEffect__17CSWordAfterEffectFP8mgCFrameP8mgCFrameiii(CSWordAfterEffect_infere *objet, mgCFrame *arg0, mgCFrame *arg1, s32 arg2, s32 arg3, s32 arg4) {
    objet->unk0 = arg0;
    objet->unk4 = arg1;
    objet->unk8C = arg2;
    objet->unk90 = arg4;
    objet->unk88 = 1;
    objet->unk94 = 0x3F800000;
    objet->unk98 = 1.0f / (f32) arg3;
    objet->unk5C = 0;
    objet->unk7C = 0;
    objet->unk80 = objet->unk78 - 1;
    objet->unk84 = objet->unk78 - 1;
    printf(&_356_00377D08);
}
typedef struct CSWordAfterEffect_infere3 {
    /* 0x00 */ char pad0[8];
    /* 0x08 */ s32 unk8;                            /* inferred */
    /* 0x0C */ s32 unkC;                            /* inferred */
    /* 0x10 */ char pad10[0x68];                    /* maybe part of unkC[0x1B]void */
    /* 0x78 */ s32 unk78;                           /* inferred */
    /* 0x7C */ s32 unk7C;                           /* inferred */
    /* 0x80 */ s32 unk80;                           /* inferred */
    /* 0x84 */ s32 unk84;                           /* inferred */
} CSWordAfterEffect_infere3;                                /* size >= 0x88 */
extern "C" s32 sceVu0CopyVector(...);
extern "C" void AddPoint__17CSWordAfterEffectFPfPf(CSWordAfterEffect_infere3 *objet, f32 *arg0, f32 *arg1) {
    s32 temp_a0;

    sceVu0CopyVector(objet->unk8 + (objet->unk80 * 0x10));
    sceVu0CopyVector(objet->unkC + (objet->unk80 * 0x10), arg1);
    objet->unk84 = objet->unk80;
    temp_a0 = (s32) (objet->unk7C);
    if (temp_a0 < objet->unk78) {
        objet->unk7C = temp_a0 + 1;
    }
    objet->unk80 -= 1;
    if (objet->unk80 < 0) {
        objet->unk80 = objet->unk78 - 1;
    }
}
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", Step__17CSWordAfterEffectFv);
void CSWordAfterEffect::Clear(void) {
    this->field_0x88 = 0;
    this->field_0x4 = 0;
    this->field_0x0 = 0;
}
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", Initialize__17CSWordAfterEffectFP9mgCMemoryii);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", Copy__17CSWordAfterEffectFR17CSWordAfterEffectP9mgCMemory);
extern "C" void InitSV_CONFIG_OPTION__FP16SV_CONFIG_OPTION(void *option) {
    if (option != NULL) {
        memset(option, 0, 0x40);
        ((s32 *) option)[5] = 1;
    }
}
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", Initialize__9CSaveDataFv);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", CheckBitFlagNo__9CSaveDataFi);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", SetBitFlag__9CSaveDataFii);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", GetBitFlag__9CSaveDataFi);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", SetShortFlag__9CSaveDataFis);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", GetShortFlag__9CSaveDataFi);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", SetBuildPartsNum__9CSaveDataFii);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", GetBuildPartsNum__9CSaveDataFi);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", AddBuildPartsNum__9CSaveDataFii);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", GetEditData__9CSaveDataFi);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", GetPlaceEditPartsNum__9CSaveDataFi);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", GetMapFlag__9CSaveDataFi);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", InitBitCtrl__9CSaveDataFv);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", SetBitCtrl__9CSaveDataFi);
typedef struct CSaveData_infere2 {
    /* 0x00000 */ char pad0[0x643C8];
    /* 0x643C8 */ u8 unk643C8;                      /* inferred */
} CSaveData_infere2;                                        /* size >= 0x643C9 */
extern "C" void ResetBitCtrl__9CSaveDataFi(CSaveData_infere2 *objet, s32 arg0) {
    objet->unk643C8 &= ~arg0 & 0xFF;
}
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", GetBitCtrl__9CSaveDataFv);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", GetItem__9CSaveDataFii);
typedef struct CSaveData {
    /* 0x00000 */ char pad0[0x643D0];
    /* 0x643D0 */ s32 unk643D0;                     /* inferred */
    /* 0x643D4 */ s32 unk643D4;                     /* inferred */
    /* 0x643D8 */ s16 unk643D8;                     /* inferred */
    /* 0x643DA */ s8 unk643DA;                      /* inferred */
    /* 0x643DB */ s8 unk643DB;                      /* inferred */
    /* 0x643DC */ s32 unk643DC;                     /* inferred */
} CSaveData;                                        /* size >= 0x643E0 */
extern "C" void ForceBootTour__9CSaveDataFii(CSaveData *objet, s32 arg0, s32 arg1) {
    objet->unk643DC = arg0;
    objet->unk643D0 = arg0;
    objet->unk643D4 = arg0 - 0xA;
    objet->unk643D8 = 1;
    objet->unk643DA = (s8) arg1;
    objet->unk643DB = 0;
}
typedef struct CSaveData_infere3 {
    /* 0x00000 */ char pad0[0x643DC];
    /* 0x643DC */ s32 unk643DC;                     /* inferred */
} CSaveData_infere3;                                        /* size >= 0x643E0 */
extern "C" s32 CheckEventDay__9CSaveDataFi(CSaveData_infere3 *objet, s32 arg0) {
    s32 temp_v0;

    temp_v0 = (s32) (objet->unk643DC);
    if (temp_v0 < 0) {
        return -1;
    }
    return arg0 - temp_v0;
}
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", CheckTourBoot__9CSaveDataFi);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", CheckNowTourEvent__9CSaveDataFv);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", CheckNowTourType__9CSaveDataFv);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", AddTourCountEtc__9CSaveDataFi);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", GetTourCountEtc__9CSaveDataFv);
typedef struct CSaveData_infere {
    /* 0x00000 */ char pad0[0x1A14];
    /* 0x01A14 */ s32 unk1A14;                      /* inferred */
    /* 0x01A18 */ char pad1A18[0x629BC];            /* maybe part of unk1A14[0x18A70]? */
    /* 0x643D4 */ s32 unk643D4;                     /* inferred */
    /* 0x643D8 */ s16 unk643D8;                     /* inferred */
    /* 0x643DA */ char pad643DA[1];
    /* 0x643DB */ s8 unk643DB;                      /* inferred */
    /* 0x643DC */ s32 unk643DC;                     /* inferred */
} CSaveData_infere;                                        /* size >= 0x643E0 */
extern "C" void FinishTour__9CSaveDataFv(CSaveData_infere *objet) {
    objet->unk643D4 = objet->unk1A14 - objet->unk643DC;
    objet->unk643D8 = 0;
    objet->unk643DB = 0;
}
void CSphidaData::Initialize(void) {
    memset(this, 0, 6216);
}
void CSphidaData::SetHorl(s32 arg0) {
    this->field_0x1478 = arg0;
}
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", SetHorlScore__11CSphidaDataFii);
s16 CSphidaData::GetNowHorl(void) {
    return this->field_0x1478;
}
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", GetHorlScore__11CSphidaDataFi);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", ClearPlayerScore__11CSphidaDataFi);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", EnterScore__11CSphidaDataFv);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", GetPlayerData__11CSphidaDataFi);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", InitPlay__11CSphidaDataFv);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", IsUsed__12GYORACE_DATAFv);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", Init__12GYORACE_DATAFv);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", Initialize__12CGyoRaceDataFv);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", SearchSpace__12CGyoRaceDataFv);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", SearchSpaceData__12CGyoRaceDataFPi);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", GetData__12CGyoRaceDataFi);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", __ct__12CSubGameDataFv);
void CSubGameData::Initialize(void) {
    memset(this, 0, 21616);
}
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", PlayEnable__12CSubGameDataFii);
void * CSubGameData::GetSphidaData(void) {
    return &this->field_0x100;
}
void * CSubGameData::GetGyoRaceData(void) {
    return &this->field_0x1948;
}
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", GetFloorInfoPtr__16CSaveDataDungeonFii);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", Initialize__16CSaveDataDungeonFv);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", SetFloorID__16CSaveDataDungeonFi);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", EditExceptionStep__FiP6CScene);
void InitNpcCameraReaction(void) {
    rea_mtn_step = 0;
    rea_chara_id = -1;
}
void InitS51Thunder(void) {
    thunder_count = 0;
    start_thunder = 0;
    next_thunder_cnt = 60;
    fade_cnt = 0;
    sound_cnt = 0;
    sound_flag = 0;
}
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", S51Thunder__FP6CScene);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", InitFirePowder__FiP6CSceneiP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", StepFirePowder__FP6CScene);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", DrawFirePowder__FP6CScene);
typedef struct CGeyserEffect {
    /* 0x00 */ s32 unk0;                            /* inferred */
    /* 0x04 */ s32 unk4;                            /* inferred */
    /* 0x08 */ s32 unk8;                            /* inferred */
    /* 0x0C */ s32 unkC;                            /* inferred */
} CGeyserEffect;                                    /* size >= 0x10 */
extern "C" s32 fptosi(f32);
extern "C" f32 mgRnd__Fv();
extern "C" void CreatePoint__13CGeyserEffectFv(CGeyserEffect *objet);
extern "C" void Create__13CGeyserEffectFv(CGeyserEffect *objet) {
    s32 temp_v1;

    temp_v1 = objet->unk0;
    if (temp_v1 <= 0) {
        if (temp_v1 == 0) {
            objet->unk4 = 1;
        }
        objet->unk0 = fptosi(150.0f * mgRnd__Fv()) + 0x64;
        objet->unk8 = 0;
        objet->unkC = fptosi(32.0f * mgRnd__Fv()) + 0x30;
    }
    objet->unk0 -= 1;
    if (objet->unk4 != 0) {
        if (((s32) objet->unk8 % 12) != 0) {
            objet->unkC -= 1;
            CreatePoint__13CGeyserEffectFv(objet);
        }
        objet->unk8 += 1;
        if (objet->unkC <= 0) {
            objet->unk4 = 0;
        }
    }
}
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", Step__13CGeyserEffectFv);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", GetEmpty__13CGeyserEffectFv);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", CreatePoint__13CGeyserEffectFv);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", CreatePacket__13CGeyserEffectFv);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", InitGeyserEffect__FiP6CSceneiP9mgCMemory);
CGeyserEffectPoint::CGeyserEffectPoint(void) {
    this->field_0x28 = 0;
}
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", __ct__13CGeyserEffectFv);
extern "C" u32 GeyserEffect;
extern "C" u32 GeyserEffectFlag;
#include "sphida.hpp"
extern "C" s32 Step__13CGeyserEffectFv(...);
extern "C" void StepGeyserEffect__FP6CScene(CScene *arg0) {
    s32 var_s0;
    s32 var_s1;

    var_s0 = 0;
    if (GeyserEffectFlag != 0) {
        var_s1 = 0;
        do {
            Step__13CGeyserEffectFv(GeyserEffect + var_s1);
            var_s0 += 1;
            var_s1 += 0x80;
        } while (var_s0 < 4);
    }
}
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", DrawGeyserEffect__FP6CScene);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", Initialize__16CDngFloorManagerFv);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", _TREE_MAPINFO__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", _GLID_INFO__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", _ROOT_INFO__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", _ROOM_INFO__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", _ROOM_LINK__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", _ROOM_OPTION__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", _ROOM_KEYROOM__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", _ROOM_TEXNO__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", _ROOM_FLOOR_INFO__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", _ROOM_FLOOR_INFO2__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", _ROOM_TITLE__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", AnalyzeFile__16CDngFloorManagerFPciP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", LoadDataTable__16CDngFloorManagerFiP9mgCMemory);
