/* CScene, CEditMap, CEditData, EditAnalyzeSrc, EditAnalyzeDataSrc
 *
 * Unité découpée par `make carve` : 125 fonctions, 23632 octets, de
 * 0x002A9FF0 à 0x002AFEE0. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"
extern s32 eaAnaData;
extern s32 eaAnaSrc;
struct SPI_STACK;


INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", Init__Q26CScene8BGM_INFOFv);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", InitSnd__6CSceneFv);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", InitBGM__6CSceneFv);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", InitSeSrc__6CSceneFv);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", InitSeEnv__6CSceneFv);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", InitSeBattle__6CSceneFv);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", InitSeBas__6CSceneFv);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", SeAllStop__6CSceneFv);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", SoundAllStop__6CSceneFv);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", InitLooSeMngr__6CSceneFv);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", GetActiveBgmInfo__6CSceneFv);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", PlayBGM__6CSceneFiif);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", PauseBGM__6CSceneFv);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", RePlayBGM__6CSceneFv);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", StopBGM__6CSceneFi);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", SetVolBGM__6CSceneFi);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", GetVolBGM__6CSceneFv);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", GetBGMState__6CSceneFv);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", SetVolfBGM__6CSceneFf);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", GetVolfBGM__6CSceneFv);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", FadeOutBGM__6CSceneFi);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", FadeInBGM__6CSceneFi);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", AutoChangeBGMVol__6CSceneFi);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", GetActiveBgmStatus__6CSceneFPQ26CScene10BGM_STATUS);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", SetActiveBgmStatus__6CSceneFPQ26CScene10BGM_STATUS);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", PlayEnvBGM__6CSceneFif);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", SetEnvBGMVol__6CSceneFf);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", GetEnvBGMVol__6CSceneFv);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", StopEnvBGM__6CSceneFv);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", AutoChangeEnvBGM__6CSceneFi);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", AutoChangeEnvOffset__6CSceneFi);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", PlayEnvBgm__6CSceneFv);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", GetSeSrcID__6CSceneFi);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", GetNumber3__FPci);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", GetBgmFile__6CSceneFPci);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", GetSeSrcFile__6CSceneFPci);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", GetSeEnvFile__6CSceneFPci);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", GetSeBaseFile__6CSceneFPci);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", GetSeBattleFile__6CSceneFPci);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", CheckLoadBGM__6CSceneFi);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", CheckLoadSeSrc__6CSceneFi);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", CheckLoadSeEnv__6CSceneFi);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", CheckLoadSeBattle__6CSceneFi);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", CheckLoadSeBase__6CSceneFi);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", SearchSndDataID__6CSceneFi);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", GetDefBgmNo__6CSceneFi);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", GetDefEventSeFile__6CSceneFiPc);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", LoadSound__6CSceneFiP1);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", LoadBGM__6CSceneFiP1);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", LoadSeSrc__6CSceneFiP1);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", LoadSeEnv__6CSceneFiP1);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", LoadSeBattle__6CSceneFiP1);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", LoadSeBase__6CSceneFiP1);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", LoadBGMPack__6CSceneFiPUi);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", LoadSeSrcPack__6CSceneFiPUi);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", LoadSeEnvPack__6CSceneFiPUi);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", LoadSeBattlePack__6CSceneFiPUi);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", LoadSeBasePack__6CSceneFiPUi);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", PrePlaySeSrc__6CSceneFv);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", PlaySeSrc__6CSceneFiff);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", check_se_play__6CSceneFi);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", GetTimeBgmVolf__6CSceneFv);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", StepSnd__6CSceneFv);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", StopSeSrc__6CSceneFv);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", PlayMapSeSrc__6CSceneFv);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", SePlayOpenDoor__6CSceneFiPf);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", SePlayCloseDoor__6CSceneFiPf);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", SePlayFoot__6CSceneFiiPf);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", GetLine__FPPcPcPc_002AC650);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", LoadSndRevInfo__6CSceneFPci);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", LoadSndFileInfo__6CSceneFPci);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", Init__18EditAnalyzeDataSrcFv);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", Init__14EditAnalyzeSrcFv);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", GetAnalyzeDataSrc__Fii);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", Initialize__9CEditDataFv);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", InitPlaceData__9CEditDataFv);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", SaveData__8CEditMapFP9CEditData);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", LoadData__8CEditMapFP9CEditData);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", GetCulturePoint__FP10CEditPartsi);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", CultureAnalyzeParts__8CEditMapFii);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", CultureAnalyze__8CEditMapFi);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", GetOnOffParts__8CEditMapFPcPP9CMapPartsPP9CMapPiecei);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", PartsOnOff__8CEditMapFiP9CEditData);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", GetPartsNumID__9CEditDataFi);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", Analyze__9CEditDataFiiPii);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", Analize__9CEditDataFiPiPi);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", GetAnalyzeData__9CEditDataFii);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", GetAnalyzeSrc__9CEditDataFi);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", GetAnalyzePercent__9CEditDataFi);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", GetAnalyzeFlag__9CEditDataFiiPiPi);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", GetAnalyzeFlag__9CEditDataFii);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", dbgSetContintionFlag__9CEditDataFiii);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", dbgSetAnalyzeFlag__9CEditDataFiii);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", dbgSetAllContintionFlag__9CEditDataFii);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", dbgGetContintionFlag__9CEditDataFiiPc);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", LoadEditAnalyzeData__FiP1);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", LoadEditAnalyzeData__FPciP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", eaGEO_ANALYZE__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", eaCONDITION__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", eaANALYZE__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", eaCON_NO__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", eaON_PARTS__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", eaOFF_PARTS__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", eaPERCENT__FP9SPI_STACKi);
s32 eaEND_ANALYZE(SPI_STACK * arg0, s32 arg1) {
    eaAnaData = 0;
    return 1;
}
s32 eaEND_GEO_ANALYZE(SPI_STACK * arg0, s32 arg1) {
    eaAnaSrc = 0;
    return 1;
}
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", GetMaxPolyn__Fi);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", GetMaxDrawMem__Fi);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", __ct__14EditAnalyzeSrcFv);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", MenuChapterInit__FP9mgCMemoryPiii);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", MenuChapterKey__Fv);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", MenuChapterDraw__Fv);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", _NPC_NUM__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", _NPC_INFO__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", LoadNPCCfg__Fv);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", GetPartyCharaMessage__Fiii);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", GetNPCModelName__Fi);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", GetNPCName__Fi);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", GetPartyCharaModelName__Fii);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", GetPartyNPCData__Fi);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", _WMAP_POSNUM__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", _WMAP_POS__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", _WMAP_AREANUM__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", _WMAP_AREA__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", worldmap_analyze__FP9mgCMemoryPci);
