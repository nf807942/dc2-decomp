/* CGameData, CUserDataManager, CEditData, CDataWeapon, CDataAttach, CDataBreedFish, CDataItem, CDataRoboPart
 *
 * Unité découpée par `make carve` : 120 fonctions, 21736 octets, de
 * 0x00191DF0 à 0x001975D0. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"
#include "gen/CDataRoboPart.hpp"

/* Les globales que ces accesseurs servent. Leur taille déclarée est celle que
 * le découpage leur donne, et c'est elle qui décide du `%gp_rel`. */
extern s32 ActiveSaveData;
extern s32 CaptureMode;
extern s32 LoopNo;
extern s32 PlayTimeCountFlag;
extern s32 SubGameSaveData;
extern s32 SystemSND_ID;

INCLUDE_ASM("nonmatchings/game/cgamedata", GetDebugFont__Fv);
s32 GetCaptureMode(void) {
    return CaptureMode;
}
s32 GetSystemSndID(void) {
    return SystemSND_ID;
}
INCLUDE_ASM("nonmatchings/game/cgamedata", GetMainScene__Fv);
s32 GetSaveData(void) {
    return ActiveSaveData;
}
s32 GetSubGameSaveData(void) {
    return SubGameSaveData;
}
INCLUDE_ASM("nonmatchings/game/cgamedata", InitSaveData__Fv);
INCLUDE_ASM("nonmatchings/game/cgamedata", GetVramTopAddress__Fv);
INCLUDE_ASM("nonmatchings/game/cgamedata", GetMainStack__Fv);
INCLUDE_ASM("nonmatchings/game/cgamedata", NextLoop__Fi13INIT_LOOP_ARG);
s32 GetNowLoopNo(void) {
    return LoopNo;
}
INCLUDE_ASM("nonmatchings/game/cgamedata", GetNowInitArg__Fv);
void cat_start(void) {
}
void cat_end(void) {
}
INCLUDE_ASM("nonmatchings/game/cgamedata", SetTextureTable__FiiP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/cgamedata", InitPadTable__Fi);
INCLUDE_ASM("nonmatchings/game/cgamedata", VSyncCallBack__Fi_00192150);
void PlayTimeCount(s32 value) {
    PlayTimeCountFlag = value;
}
s32 GetPlayTimeCountFlag(void) {
    return PlayTimeCountFlag;
}
INCLUDE_ASM("nonmatchings/game/cgamedata", LanguageChange__FiP1);
INCLUDE_ASM("nonmatchings/game/cgamedata", MainLoop__Fv);
INCLUDE_ASM("nonmatchings/game/cgamedata", MenuInit__F13INIT_LOOP_ARG);
INCLUDE_ASM("nonmatchings/game/cgamedata", MenuLoop__Fv);
INCLUDE_ASM("nonmatchings/game/cgamedata", MenuExit__Fv);
INCLUDE_ASM("nonmatchings/game/cgamedata", InitEventSelect__Fv);
INCLUDE_ASM("nonmatchings/game/cgamedata", EventSelect__Fv);
INCLUDE_ASM("nonmatchings/game/cgamedata", GetFontTexture__Fi);
INCLUDE_ASM("nonmatchings/game/cgamedata", LoadFontTexture__Fv);
INCLUDE_ASM("nonmatchings/game/cgamedata", ReLoadFontTexture__Fi);
void demQuit(void) {
}
void demoQuitTimeOut(void) {
}
void demoAttractInterrupted(void) {
}
void demoAttractComplete(void) {
}
void FadeOutForE3(void) {
}
s32 TimeLimitCheck(void) {
    return 0;
}
INCLUDE_ASM("nonmatchings/game/cgamedata", InitPauseMenu__Fi);
INCLUDE_ASM("nonmatchings/game/cgamedata", PauseMenu__Fv);
INCLUDE_ASM("nonmatchings/game/cgamedata", LoadGameConfig__FPc);
INCLUDE_ASM("nonmatchings/game/cgamedata", gcMAP_NO__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cgamedata", gcPROGRESS__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cgamedata", gcBIT_FLAG_ON__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cgamedata", gcBIT_FLAG_OFF__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cgamedata", gcSTART_EVENT__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cgamedata", gcGEO_COMPLETE__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cgamedata", gcGEO_DEBUG__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cgamedata", gcITEM_SET__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cgamedata", gcGET_ITEM__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cgamedata", gcGET_N_ITEM__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cgamedata", gcEQUIP__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cgamedata", gcDEFENSE__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cgamedata", gcHP__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cgamedata", gcALL_GEO_PARTS__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cgamedata", gcPARAM_DRAW__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cgamedata", gcOPTION__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cgamedata", gcMONICA__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cgamedata", gcSTEVE__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cgamedata", gcMONSTER__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cgamedata", gcPARTY__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cgamedata", gcACTIVE_CHARA__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cgamedata", __ct__16CUserDataManagerFv);
INCLUDE_ASM("nonmatchings/game/cgamedata", __ct__9CEditDataFv);
INCLUDE_ASM("nonmatchings/game/cgamedata", GetGameDataPt__Fv);
INCLUDE_ASM("nonmatchings/game/cgamedata", __ct__9CDataItemFv);
INCLUDE_ASM("nonmatchings/game/cgamedata", __ct__11CDataAttachFv);
INCLUDE_ASM("nonmatchings/game/cgamedata", __ct__11CDataWeaponFv);
u8 CDataRoboPart::GetOffsetNo(void) {
    return this->field_0x22;
}
INCLUDE_ASM("nonmatchings/game/cgamedata", __ct__14CDataBreedFishFv);
INCLUDE_ASM("nonmatchings/game/cgamedata", Initialize__9CGameDataFv);
INCLUDE_ASM("nonmatchings/game/cgamedata", _DATACOMINIT__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cgamedata", _DATACOM__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cgamedata", _MES_SYS__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cgamedata", _MES_SYS_SPECTOL__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cgamedata", _DATAWEPNUM__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cgamedata", _DATAWEP__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cgamedata", _DATAWEP_ST__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cgamedata", _DATAWEP_ST_L__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cgamedata", _DATAWEP2_ST__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cgamedata", _DATAWEP2_ST_L__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cgamedata", _DATAWEP_SPE__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cgamedata", _DATAWEP_BUILDUP__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cgamedata", _DATAITEMINIT__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cgamedata", _DATAITEM__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cgamedata", _DATAATTACHINIT__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cgamedata", _DATAATTACH_ST__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cgamedata", _DATAATTACH_ST2__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cgamedata", _DATAATTACH_ST_SP__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cgamedata", _DATAROBOINIT__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cgamedata", _DATAROBO_ANALYZE__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cgamedata", _DATAFISHINIT__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cgamedata", _DATAFISH__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cgamedata", _DATAGAURDNUM__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cgamedata", _DATAGAURD__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cgamedata", LoadGameDataAnalyze__FPc);
INCLUDE_ASM("nonmatchings/game/cgamedata", LoadData__9CGameDataFv);
INCLUDE_ASM("nonmatchings/game/cgamedata", LoadItemSystemMes__9CGameDataFi);
INCLUDE_ASM("nonmatchings/game/cgamedata", InitItemMes__9CGameDataFii);
INCLUDE_ASM("nonmatchings/game/cgamedata", GetCommonData__9CGameDataFi);
INCLUDE_ASM("nonmatchings/game/cgamedata", GetWeaponData__9CGameDataFi);
INCLUDE_ASM("nonmatchings/game/cgamedata", GetItemData__9CGameDataFi);
INCLUDE_ASM("nonmatchings/game/cgamedata", GetAttachData__9CGameDataFi);
INCLUDE_ASM("nonmatchings/game/cgamedata", GetRoboData__9CGameDataFi);
INCLUDE_ASM("nonmatchings/game/cgamedata", GetFishData__9CGameDataFi);
INCLUDE_ASM("nonmatchings/game/cgamedata", GetGuardData__9CGameDataFi);
INCLUDE_ASM("nonmatchings/game/cgamedata", GetDataType__9CGameDataFi);
INCLUDE_ASM("nonmatchings/game/cgamedata", GetDataTypeStartListNo__9CGameDataFi);
INCLUDE_ASM("nonmatchings/game/cgamedata", GetCommonItemData__Fi);
INCLUDE_ASM("nonmatchings/game/cgamedata", GetItemInfoData__Fi);
INCLUDE_ASM("nonmatchings/game/cgamedata", GetWeaponInfoData__Fi);
INCLUDE_ASM("nonmatchings/game/cgamedata", GetRoboPartInfoData__Fi);
INCLUDE_ASM("nonmatchings/game/cgamedata", GetBreedFishInfoData__Fi);
INCLUDE_ASM("nonmatchings/game/cgamedata", GetItemFileName__Fii);
INCLUDE_ASM("nonmatchings/game/cgamedata", GetItemFilePath__Fii);
INCLUDE_ASM("nonmatchings/game/cgamedata", GetItemDataType__Fi);
INCLUDE_ASM("nonmatchings/game/cgamedata", GetItemDataAttribute__Fi);
INCLUDE_ASM("nonmatchings/game/cgamedata", ConvertUsedItemType__Fi);
INCLUDE_ASM("nonmatchings/game/cgamedata", GetItemMessageNo__Fii);
INCLUDE_ASM("nonmatchings/game/cgamedata", GetItemMessage__Fi);
INCLUDE_ASM("nonmatchings/game/cgamedata", GetItemIconNo__Fi);
INCLUDE_ASM("nonmatchings/game/cgamedata", SetItemSpectolPoint__FiP11ATTACH_USEDi);
INCLUDE_ASM("nonmatchings/game/cgamedata", ItemCmdMsgSet__FiPi);
