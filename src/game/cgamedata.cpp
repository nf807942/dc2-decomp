/* CGameData, CUserDataManager, CEditData, CDataWeapon, CDataAttach, CDataBreedFish, CDataItem, CDataRoboPart
 *
 * Unité découpée par `make carve` : 120 fonctions, 21736 octets, de
 * 0x00191DF0 à 0x001975D0. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"
#include "gen/DebugInfoData.hpp"
#include "gen/CDataItem.hpp"
#include "gen/CDataRoboPart.hpp"

/* Les globales que ces accesseurs servent. Leur taille déclarée est celle que
 * le découpage leur donne, et c'est elle qui décide du `%gp_rel`. */
extern s32 ActiveSaveData;
extern s32 CaptureMode;
extern s32 LoopNo;
extern s32 PlayTimeCountFlag;
extern s32 SubGameSaveData;
extern s32 SystemSND_ID;
extern s32 event_view;
extern s32 future_sel;
extern s32 hdd_sel;
extern s32 menu_mode;

extern DebugInfoData DebugInfo;
struct SPI_STACK;


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
extern "C" s32 GetSaveData__Fv(void);
extern "C" s32 Initialize__9CSaveDataFv(...);
extern "C" void InitSaveData__Fv(void) {
    Initialize__9CSaveDataFv(GetSaveData__Fv());
}
extern "C" s32 mgGetTopVRAMAddress__Fv(void);
extern "C" s32 GetVramTopAddress__Fv(void) {
    return mgGetTopVRAMAddress__Fv() + 0x20;
}
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
extern "C" u8 mgTexManager[540];
#include "menu.hpp"
extern "C" s32 Initialize__17mgCTextureManagerFii(void *, s32, s32);
extern "C" s32 SetTableBuffer__17mgCTextureManagerFiiP9mgCMemory(void *, s32, s32, mgCMemory *);
extern "C" s32 GetVramTopAddress__Fv(void);
extern "C" void SetTextureTable__FiiP9mgCMemory(s32 arg0, s32 arg1, mgCMemory *arg2) {
    SetTableBuffer__17mgCTextureManagerFiiP9mgCMemory(&mgTexManager, arg1, arg0, arg2);
    Initialize__17mgCTextureManagerFii(&mgTexManager, GetVramTopAddress__Fv(), -1);
}
INCLUDE_ASM("nonmatchings/game/cgamedata", InitPadTable__Fi);
INCLUDE_ASM("nonmatchings/game/cgamedata", VSyncCallBack__Fi_00192150);
void PlayTimeCount(s32 value) {
    PlayTimeCountFlag = value;
}
s32 GetPlayTimeCountFlag(void) {
    return PlayTimeCountFlag;
}
extern "C" u8 GameItemDataManage[48];
typedef struct InfoStack_champs {
    char pad0[28];
    s32 unk1C;
    char pad20[4];
    s32 unk24;
    char pad28[8];
} InfoStack_champs;
extern "C" InfoStack_champs InfoStack;
extern "C" u32 LanguageCode;
extern "C" u32 read_buffer;
struct inferred;
typedef struct mgCMemory_infere {
    /* 0x00 */ char pad0[0x1C];
    /* 0x1C */ s32 unk1C;                           /* inferred */
    /* 0x20 */ char pad20[4];
    /* 0x24 */ s32 unk24;                           /* inferred */
} mgCMemory_infere;                                        /* size >= 0x28 */
extern "C" s32 InitPauseData__Fv(void);
extern "C" s32 LanguageEquipChange__Fv(void);
extern "C" s32 LoadEditAnalyzeData__FiP1(...);
extern "C" s32 LoadFilePictureName__Fv(void);
extern "C" s32 LoadFontTblBin__Fv(void);
extern "C" s32 LoadFontTex2Img__Fv(void);
extern "C" s32 LoadGaijiImg__Fv(void);
extern "C" s32 LoadGameInfo__FP9mgCMemory(...);
extern "C" s32 LoadHelpMes__FP1(...);
extern "C" s32 LoadMapName__FiP1(...);
extern "C" s32 LoadMonsterLanguage__Fi(s32);
extern "C" s32 LoadNPCCfg__Fv(void);
extern "C" s32 LoadSystemMes__Fv(void);
extern "C" s32 InitPadTable__Fi(s32);
extern "C" s32 LoadFontTexture__Fv(void);
extern "C" s32 LoadItemSystemMes__9CGameDataFi(void *, s32);
extern "C" void LanguageChange__FiP1(s32 arg0) {
    LanguageCode = arg0;
    LoadItemSystemMes__9CGameDataFi(&GameItemDataManage, arg0);
    LoadHelpMes__FP1(read_buffer);
    LoadMapName__FiP1(LanguageCode, read_buffer);
    LanguageEquipChange__Fv();
    LoadNPCCfg__Fv();
    LoadSystemMes__Fv();
    LoadFontTex2Img__Fv();
    LoadGaijiImg__Fv();
    LoadFontTexture__Fv();
    LoadFontTblBin__Fv();
    LoadEditAnalyzeData__FiP1(LanguageCode, read_buffer);
    LoadFilePictureName__Fv();
    LoadMonsterLanguage__Fi(LanguageCode);
    InfoStack.unk24 = 0;
    InfoStack.unk1C = 0;
    LoadGameInfo__FP9mgCMemory(&InfoStack);
    InitPauseData__Fv();
    InitPadTable__Fi(LanguageCode);
}
INCLUDE_ASM("nonmatchings/game/cgamedata", MainLoop__Fv);
INCLUDE_ASM("nonmatchings/game/cgamedata", MenuInit__F13INIT_LOOP_ARG);
INCLUDE_ASM("nonmatchings/game/cgamedata", MenuLoop__Fv);
extern "C" u8 GamePad_003FA5A0[1144];
extern "C" s32 AutoRepeatOff__8CGamePadFv(void *);
extern "C" s32 mgCloseFont__Fv(void);
extern "C" void MenuExit__Fv(void) {
    AutoRepeatOff__8CGamePadFv(&GamePad_003FA5A0);
    mgCloseFont__Fv();
}
void InitEventSelect(void) {
    event_view = 0;
    future_sel = 0;
    menu_mode = 2;
    hdd_sel = 0;
}
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
extern "C" u32 DefStartEventNo;
struct SPI_STACK {
    s32 field_0;
    s32 field_4;
};
extern "C" s32 spiGetStackInt__FP9SPI_STACK(SPI_STACK *);
extern "C" s32 gcSTART_EVENT__FP9SPI_STACKi(SPI_STACK *arg0, s32 arg1) {
    DefStartEventNo = spiGetStackInt__FP9SPI_STACK(arg0);
    return 0;
}
INCLUDE_ASM("nonmatchings/game/cgamedata", gcGEO_COMPLETE__FP9SPI_STACKi);
s32 gcGEO_DEBUG(SPI_STACK * arg0, s32 arg1) {
    DebugInfo.field_0x8 = 1;
    return 1;
}
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
CDataItem::CDataItem(void) {
    this->field_0x4 = 0;
    this->field_0x0 = 0;
    this->field_0xA = 0;
    this->field_0xC = 0;
    this->field_0xE = 0;
}
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
extern "C" s32 GetCommonData__9CGameDataFi(void *, s32);
struct CGameData {
    s32 field_0;
    char pad_4[0x1C];
    s16 field_20;
    s16 field_22;
    u16 field_24;
    u16 field_26;
    u16 field_28;
    u16 field_2A;
    u16 field_2C;
};
extern "C" u8 GetDataType__9CGameDataFi(CGameData *objet, s32 arg0) {
    u8 *temp_v0;

    temp_v0 = (u8 *) (GetCommonData__9CGameDataFi(objet, arg0));
    if (temp_v0 != NULL) {
        return *temp_v0;
    }
    return 0U;
}
INCLUDE_ASM("nonmatchings/game/cgamedata", GetDataTypeStartListNo__9CGameDataFi);
INCLUDE_ASM("nonmatchings/game/cgamedata", GetCommonItemData__Fi);
INCLUDE_ASM("nonmatchings/game/cgamedata", GetItemInfoData__Fi);
INCLUDE_ASM("nonmatchings/game/cgamedata", GetWeaponInfoData__Fi);
INCLUDE_ASM("nonmatchings/game/cgamedata", GetRoboPartInfoData__Fi);
INCLUDE_ASM("nonmatchings/game/cgamedata", GetBreedFishInfoData__Fi);
INCLUDE_ASM("nonmatchings/game/cgamedata", GetItemFileName__Fii);
INCLUDE_ASM("nonmatchings/game/cgamedata", GetItemFilePath__Fii);
INCLUDE_ASM("nonmatchings/game/cgamedata", GetItemDataType__Fi);
extern "C" u8 GameItemDataManage[48];
extern "C" s32 GetCommonData__9CGameDataFi(void *, s32);
struct temp_v0_champs {
    char pad0[0x24];
    /* 0x24 */ s32 unk24;
};
extern "C" s32 GetItemDataAttribute__Fi(s32 arg0) {
    struct temp_v0_champs *temp_v0;

    temp_v0 = (struct temp_v0_champs *) (GetCommonData__9CGameDataFi(&GameItemDataManage, arg0));
    if (temp_v0 != NULL) {
        return temp_v0->unk24;
    }
    return 0;
}
INCLUDE_ASM("nonmatchings/game/cgamedata", ConvertUsedItemType__Fi);
INCLUDE_ASM("nonmatchings/game/cgamedata", GetItemMessageNo__Fii);
INCLUDE_ASM("nonmatchings/game/cgamedata", GetItemMessage__Fi);
INCLUDE_ASM("nonmatchings/game/cgamedata", GetItemIconNo__Fi);
INCLUDE_ASM("nonmatchings/game/cgamedata", SetItemSpectolPoint__FiP11ATTACH_USEDi);
INCLUDE_ASM("nonmatchings/game/cgamedata", ItemCmdMsgSet__FiPi);
