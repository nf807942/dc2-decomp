/* CScene, CEditMap, CEditData, EditAnalyzeSrc, EditAnalyzeDataSrc
 *
 * Unité découpée par `make carve` : 125 fonctions, 23632 octets, de
 * 0x002A9FF0 à 0x002AFEE0. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"
#include "gen/EditAnalyzeDataSrc.hpp"
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
struct CScene;
extern "C" s32 GetActiveBgmInfo__6CSceneFv(void *);
struct temp_v0_champs {
    char pad0[0x8];
    /* 0x8 */ s32 unk8;
};
extern "C" s32 CheckLoadBGM__6CSceneFi(CScene *objet, s32 arg0) {
    struct temp_v0_champs *temp_v0;

    temp_v0 = (struct temp_v0_champs *) (GetActiveBgmInfo__6CSceneFv(objet));
    if (arg0 < 0) {
        return 0;
    }
    return arg0 != temp_v0->unk8;
}
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", CheckLoadSeSrc__6CSceneFi);
struct inferred;
typedef struct CScene_infere {
    /* 0x0000 */ char pad0[0xA044];
    /* 0xA044 */ s32 unkA044;                       /* inferred */
} CScene_infere;                                           /* size >= 0xA048 */
extern "C" s32 CheckLoadSeEnv__6CSceneFi(CScene_infere *objet, s32 arg0) {
    if (arg0 < 0) {
        return 0;
    }
    return objet->unkA044 != arg0;
}
typedef struct CScene_infere2 {
    /* 0x0000 */ char pad0[0xC4D4];
    /* 0xC4D4 */ s32 unkC4D4;                       /* inferred */
} CScene_infere2;                                           /* size >= 0xC4D8 */
extern "C" s32 CheckLoadSeBattle__6CSceneFi(CScene_infere2 *objet, s32 arg0) {
    if (arg0 < 0) {
        return 0;
    }
    return objet->unkC4D4 != arg0;
}
typedef struct CScene_infere3 {
    /* 0x0000 */ char pad0[0xA49C];
    /* 0xA49C */ s32 unkA49C;                       /* inferred */
} CScene_infere3;                                           /* size >= 0xA4A0 */
extern "C" s32 CheckLoadSeBase__6CSceneFi(CScene_infere3 *objet, s32 arg0) {
    if (arg0 < 0) {
        return 0;
    }
    return objet->unkA49C != arg0;
}
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
typedef struct CScene {
    /* 0x0000 */ char pad0[0x9E00];
    /* 0x9E00 */ s32 unk9E00;                       /* inferred */
    /* 0x9E04 */ s32 unk9E04;                       /* inferred */
    /* 0x9E08 */ char pad9E08[0x80];                /* maybe part of unk9E04[0x21]? */
    /* 0x9E88 */ s32 unk9E88;                       /* inferred */
    /* 0x9E8C */ s32 unk9E8C;                       /* inferred */
    /* 0x9E90 */ char pad9E90[0x80];                /* maybe part of unk9E8C[0x21]? */
    /* 0x9F10 */ s32 unk9F10;                       /* inferred */
    /* 0x9F14 */ s32 unk9F14;                       /* inferred */
    /* 0x9F18 */ char pad9F18[0x80];                /* maybe part of unk9F14[0x21]? */
    /* 0x9F98 */ s32 unk9F98;                       /* inferred */
    /* 0x9F9C */ s32 unk9F9C;                       /* inferred */
} CScene;                                           /* size >= 0x9FA0 */
extern "C" void PrePlaySeSrc__6CSceneFv(CScene *objet) {
    objet->unk9E00 = -1;
    objet->unk9E04 = 0;
    objet->unk9E88 = -1;
    objet->unk9E8C = 0;
    objet->unk9F10 = -1;
    objet->unk9F14 = 0;
    objet->unk9F98 = -1;
    objet->unk9F9C = 0;
}
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
void EditAnalyzeDataSrc::Init(void) {
    this->field_0x0 = 0;
    this->field_0x4 = 0;
    this->field_0x6 = 0;
    this->field_0x8 = -1;
    this->field_0x9 = -1;
    this->field_0xA = -1;
    this->field_0xB = -1;
    this->field_0xC = -1;
    this->field_0xD = -1;
    this->field_0xE = -1;
    this->field_0xF = -1;
    this->field_0x10 = -1;
    this->field_0x14 = 0;
    this->field_0x18 = 0;
}
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
struct irregular;
struct match;
extern "C" s32 GetMaxPolyn__Fi(s32 arg0) {
    s32 var_v0;

    var_v0 = 0xFA0;
    if (arg0 != 4) {
        var_v0 = 0x1770;
        switch (arg0) {                             /* irregular */
        case 0:
            return 0xFA0;
        case 1:
            return 0x1770;
        case 2:
            return 0x1770;
        case 3:
            /* Duplicate return node #10. Try simplifying control flow for better match */
            return var_v0;
        default:
            return 0;
        }
    } else {
        return var_v0;
    }
}
struct irregular;
struct match;
extern "C" s32 GetMaxDrawMem__Fi(s32 arg0) {
    s32 var_v0;

    var_v0 = 0xBB80;
    if (arg0 != 4) {
        var_v0 = 0xD2F0;
        switch (arg0) {                             /* irregular */
        case 0:
            return 0xBB80;
        case 1:
            return 0xC350;
        case 2:
            return 0xD2F0;
        case 3:
            /* Duplicate return node #10. Try simplifying control flow for better match */
            return var_v0;
        default:
            return 0;
        }
    } else {
        return var_v0;
    }
}
struct EditAnalyzeSrc;
extern "C" s32 Init__14EditAnalyzeSrcFv(void *);
extern "C" EditAnalyzeSrc *__ct__14EditAnalyzeSrcFv(EditAnalyzeSrc *objet) {
    Init__14EditAnalyzeSrcFv(objet);
    return objet;
}
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", MenuChapterInit__FP9mgCMemoryPiii);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", MenuChapterKey__Fv);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", MenuChapterDraw__Fv);
extern "C" u32 NpcBaseDataTotalNum;
struct SPI_STACK {
    s32 field_0;
    s32 field_4;
};
extern "C" s32 spiGetStackInt__FP9SPI_STACK(SPI_STACK *arg0);
extern "C" s32 _NPC_NUM__FP9SPI_STACKi(SPI_STACK *arg0, s32 arg1) {
    NpcBaseDataTotalNum = spiGetStackInt__FP9SPI_STACK(arg0);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", _NPC_INFO__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", LoadNPCCfg__Fv);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", GetPartyCharaMessage__Fiii);
extern "C" s32 GetPartyNPCData__Fi(s32 arg0);
extern "C" s32 GetNPCModelName__Fi(s32 arg0) {
    s32 temp_v0;

    temp_v0 = GetPartyNPCData__Fi(arg0);
    if (temp_v0 != 0) {
        return temp_v0 + 0x1F;
    }
    return 0;
}
extern "C" s32 GetPartyNPCData__Fi(s32 arg0);
extern "C" s32 GetNPCName__Fi(s32 arg0) {
    s32 temp_v0;

    temp_v0 = GetPartyNPCData__Fi(arg0);
    if (temp_v0 != 0) {
        return temp_v0 + 3;
    }
    return 0;
}
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", GetPartyCharaModelName__Fii);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", GetPartyNPCData__Fi);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", _WMAP_POSNUM__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", _WMAP_POS__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", _WMAP_AREANUM__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", _WMAP_AREA__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", worldmap_analyze__FP9mgCMemoryPci);
