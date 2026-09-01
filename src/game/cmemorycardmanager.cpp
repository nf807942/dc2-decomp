/* CMemoryCardManager, CSWordAfterEffect, CSaveData, CGeyserEffect, CSphidaData, CSaveDataDungeon, CDngFloorManager, CGyoRaceData, CSubGameData, GYORACE_DATA, CGeyserEffectPoint
 *
 * Unité découpée par `make carve` : 135 fonctions, 32036 octets, de
 * 0x002F6690 à 0x002FE6C0. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"
#include "gen/CGeyserEffectPoint.hpp"
#include "gen/CSphidaData.hpp"
#include "gen/CSubGameData.hpp"

/* Le corps ne rend qu'un code : ni la classe ni les arguments ne sont
 * déréférencés, donc leur disposition reste à établir. */
class CMemoryCardManager {
public:
    s32 Convert();
};
extern "C" void *memset(void *destination, s32 value, u32 size);


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
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", GetSaveDataSize__18CMemoryCardManagerFi);
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
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", Clear__17CSWordAfterEffectFv);
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
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", ForceBootTour__9CSaveDataFii);
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
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", InitNpcCameraReaction__Fv);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", InitS51Thunder__Fv);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", S51Thunder__FP6CScene);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", InitFirePowder__FiP6CSceneiP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", StepFirePowder__FP6CScene);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", DrawFirePowder__FP6CScene);
INCLUDE_ASM("nonmatchings/game/cmemorycardmanager", Create__13CGeyserEffectFv);
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
