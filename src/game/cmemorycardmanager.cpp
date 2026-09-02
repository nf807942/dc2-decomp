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


INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", __ct__18CMemoryCardManagerFv);
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
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", SetFuncNo__18CMemoryCardManagerFi);
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
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", GetCosInfo__Fi);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", CreatSmoothPassSW__FPA4_fPA4_fiiii);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", Draw__17CSWordAfterEffectFv);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", CreatPointList__17CSWordAfterEffectFv);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", SetTexture__17CSWordAfterEffectFiP10mgCTextureiiii);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", SetTexture__17CSWordAfterEffectFiiii);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", StartEffect__17CSWordAfterEffectFP8mgCFrameP8mgCFrameiii);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", AddPoint__17CSWordAfterEffectFPfPf);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", Step__17CSWordAfterEffectFv);
void CSWordAfterEffect::Clear(void) {
    this->field_0x88 = 0;
    this->field_0x4 = 0;
    this->field_0x0 = 0;
}
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", Initialize__17CSWordAfterEffectFP9mgCMemoryii);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", Copy__17CSWordAfterEffectFR17CSWordAfterEffectP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", InitSV_CONFIG_OPTION__FP16SV_CONFIG_OPTION);
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
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", ResetBitCtrl__9CSaveDataFi);
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
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", CheckEventDay__9CSaveDataFi);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", CheckTourBoot__9CSaveDataFi);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", CheckNowTourEvent__9CSaveDataFv);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", CheckNowTourType__9CSaveDataFv);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", AddTourCountEtc__9CSaveDataFi);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", GetTourCountEtc__9CSaveDataFv);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", FinishTour__9CSaveDataFv);
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
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", StepGeyserEffect__FP6CScene);
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
