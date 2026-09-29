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
extern "C" u32 FontTex;
extern "C" s32 GetFontTexture__Fi(s32 arg0) {
    if ((arg0 < 0) || (arg0 > 0)) {
        return 0;
    }
    return *(&FontTex + arg0);
}
INCLUDE_ASM("nonmatchings/game/cgamedata", LoadFontTexture__Fv);
extern "C" u32 FontDataAdr;
extern "C" u8 _1654_003699F0[15];
extern "C" u8 _1655_00369A00[16];
extern "C" u8 _1656_00369A10[16];
struct TM2_head {
    s64 field_0;
    s64 field_8;
    char pad_10[0x8];
    s32 field_18;
    u16 field_1C;
    char pad_1E[0x3];
    u8 field_21;
    char pad_22[0x1];
    u8 field_23;
    u16 field_24;
    u16 field_26;
    s32 field_28;
    s32 field_2C;
    s64 field_30;
    s64 field_38;
    char pad_40[0x10];
    s32 field_50;
};
extern "C" s32 EnterTexture__17mgCTextureManagerFiPcP8TM2_headii(...);
extern "C" s32 sprintf(...);
extern "C" void ReLoadFontTexture__Fi(s32 arg0) {
    s8 sp50[0x20];
    s32 var_s0;
    s32 var_s1;
    TM2_head **temp_s2;

    var_s1 = 0;
    var_s0 = 0;
    do {
        temp_s2 = (TM2_head **) ((u8 *) &FontDataAdr + var_s1);
        if (*temp_s2 != NULL) {
            if (LanguageCode == 0) {
                sprintf(sp50, &_1654_003699F0, var_s0);
            } else if (LanguageCode == 1) {
                if (var_s0 == 0) {
                    sprintf(sp50, &_1655_00369A00, var_s0);
                }
            } else if (var_s0 == 0) {
                sprintf(sp50, &_1656_00369A10);
            }
            if (mgTexManager == NULL) {
                return;
            }
            *(u32 *) ((u8 *) &FontTex + var_s1) = EnterTexture__17mgCTextureManagerFiPcP8TM2_headii(mgTexManager, arg0, sp50, *temp_s2, 0, 0);
        }
        var_s0 += 1;
        var_s1 += 4;
    } while (var_s0 <= 0);
}
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
extern "C" char _1296_003695B8[];
extern "C" char _1856[];
extern "C" s32 __ct__18CScriptInterpreterFv(void *);
extern "C" u8 tag_00339760[184];
struct SPI_TAG_PARAM;
extern "C" s32 LoadFile2__FPcPvPii(...);
extern "C" s32 Run__18CScriptInterpreterFv(void *);
extern "C" s32 SetCurrentDir__FPc(...);
extern "C" s32 SetScript__18CScriptInterpreterFPci(...);
extern "C" s32 SetTag__18CScriptInterpreterFP13SPI_TAG_PARAM(...);
extern "C" void LoadGameConfig__FPc(s8 *arg0) {
    u8 sp10[0x4000];
    u8 sp4010[0xEDC];
    s32 sp4EEC;

    if (arg0 == NULL) {
        SetCurrentDir__FPc(_1296_003695B8);
        if (LoadFile2__FPcPvPii(_1856, sp10, &sp4EEC, 0) == 0) {
            SetCurrentDir__FPc(NULL);
            return;
        }
        SetCurrentDir__FPc(NULL);
        goto block_5;
    }
    if (LoadFile2__FPcPvPii(arg0, sp10, &sp4EEC, 0) != 0) {
block_5:
        __ct__18CScriptInterpreterFv(&sp4010);
        SetTag__18CScriptInterpreterFP13SPI_TAG_PARAM(&sp4010, &tag_00339760);
        SetScript__18CScriptInterpreterFPci(&sp4010, (char *) sp10, sp4EEC);
        Run__18CScriptInterpreterFv(&sp4010);
    }
}
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
extern "C" s32 GetCharaDataPtr__16CUserDataManagerFi(...);
struct GcDefenseChara {
    char pad0[0xA];
    /* 0xA */ s16 unkA;
};
extern "C" s32 GetSaveData__Fv(void);
extern "C" s32 gcDEFENSE__FP9SPI_STACKi(SPI_STACK *arg0, s32 arg1) {
    s32 temp_s0;
    s32 temp_s1;
    struct GcDefenseChara *temp_v0;

    temp_s0 = (s32) (spiGetStackInt__FP9SPI_STACK(arg0++));
    temp_s1 = (s32) (spiGetStackInt__FP9SPI_STACK(arg0));
    temp_v0 = (struct GcDefenseChara *) (GetCharaDataPtr__16CUserDataManagerFi((u8 *) GetSaveData__Fv() + 0x1D2A0, temp_s0));
    if (temp_v0 != NULL) {
        temp_v0->unkA = (s16) temp_s1;
    }
    return 1;
}
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
typedef struct CEditData {
    char pad0[0xC];
    char unkC;
    char padC[0x2A2F];
    char unk2A3C;
    char pad2A3C[3];
    char unk2A40;
    char pad2A40[0x1FF];
    char unk2C40;
    char pad2C40[0x23FF];
    char unk5040;
    char pad5040[0xCF];
} CEditData;
extern "C" s32 Initialize__9CEditDataFv(void *);
extern "C" s32 memset(...);
extern "C" CEditData *__ct__9CEditDataFv(CEditData *objet) {
    char *var_a0;
    char *var_a0_2;
    char *var_s0;
    char *var_s0_2;
    var_s0 = &objet->unkC;
    var_a0 = var_s0;
    do {
        memset(var_a0, 0, 0x24);
        var_s0 += 0x24;
        var_a0 = var_s0;
    } while ((u32) var_s0 < (u32) &objet->unk2A3C);
    var_s0_2 = &objet->unk2A40;
    var_a0_2 = var_s0_2;
    do {
        memset(var_a0_2, 0, 0x10);
        var_s0_2 += 0x10;
        var_a0_2 = var_s0_2;
    } while ((u32) var_s0_2 < (u32) &objet->unk2C40);
    memset(&objet->unk5040, 0, 0xD0);
    Initialize__9CEditDataFv(objet);
    return objet;
}
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
extern "C" s32 GetCommonData__9CGameDataFi(void *, s32);
extern "C" u32 gamedata_build_stack;
extern "C" s32 spiGetStackString__FP9SPI_STACK(...);
struct MesSysDonnees {
    char pad0[0x28];
    /* 0x28 */ s32 unk28;
};
extern "C" s32 ConvertFontCode__FPcPc(...);
extern "C" s32 memset(...);
extern "C" s32 mgCopyString__FPcP9mgCMemory(...);
struct MesSysPile {
    s32 field_0;
    s32 field_4;
};
extern "C" s32 _MES_SYS__FP9SPI_STACKi(MesSysPile *arg0, s32 arg1) {
    u8 sp30[0x100];
    s32 temp_s0;
    s32 var_v0;
    s8 *temp_s0_2;
    struct MesSysDonnees *temp_v0;

    temp_s0 = (s32) (spiGetStackInt__FP9SPI_STACK((SPI_STACK *) arg0++));
    temp_s0_2 = (s8 *) (spiGetStackString__FP9SPI_STACK(arg0));
    temp_v0 = (struct MesSysDonnees *) (GetCommonData__9CGameDataFi(&GameItemDataManage, temp_s0));
    if (temp_v0 != NULL) {
        if (((s32) LanguageCode >= 2) && ((s32) LanguageCode < 6)) {
            memset(sp30, 0, 0x100);
            ConvertFontCode__FPcPc(temp_s0_2, sp30);
            var_v0 = mgCopyString__FPcP9mgCMemory(sp30, gamedata_build_stack);
        } else {
            var_v0 = (s32) (mgCopyString__FPcP9mgCMemory(temp_s0_2, gamedata_build_stack));
        }
        temp_v0->unk28 = var_v0;
    }
    return 1;
}
INCLUDE_ASM("nonmatchings/game/cgamedata", _MES_SYS_SPECTOL__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cgamedata", _DATAWEPNUM__FP9SPI_STACKi);
extern "C" u32 SpiWeaponPt;

/* Les six champs que les trois fonctions ci-dessous ecrivent. Le reste de
 * l'objet que `SpiWeaponPt` designe n'est pas connu. */
struct SpiWeapon_champs {
    /* 0x0 */ s16 unk0;
    /* 0x2 */ s16 unk2;
    /* 0x4 */ s16 unk4;
    /* 0x6 */ s16 unk6;
    /* 0x8 */ s16 unk8;
    /* 0xA */ s16 unkA;
};

/* L'adresse du second emplacement de pile se calcule *avant* la garde. MWCC la
 * range alors dans le creneau de delai du branchement — `addiu $s0, $a0, 0x8`
 * chez le commerce — la ou une affectation posee apres la garde lui fait garder
 * la base et calculer le decalage au site d'appel. Mesure sur cette fonction :
 * 94,29 % avec l'adresse calculee apres la garde, quelle que soit la forme de
 * l'expression, 100 % avec ce placement. */
extern "C" s32 _DATAWEP__FP9SPI_STACKi(SPI_STACK *arg0, s32 arg1) {
    SPI_STACK *suivant;

    suivant = arg0 + 1;
    if (SpiWeaponPt == NULL) {
        return 0;
    }
    ((struct SpiWeapon_champs *) SpiWeaponPt)->unk0 = spiGetStackInt__FP9SPI_STACK(arg0);
    ((struct SpiWeapon_champs *) SpiWeaponPt)->unk2 = spiGetStackInt__FP9SPI_STACK(suivant);
    return 1;
}
extern "C" s32 _DATAWEP_ST__FP9SPI_STACKi(SPI_STACK *arg0, s32 arg1) {
    SPI_STACK *suivant;

    suivant = arg0 + 1;
    if (SpiWeaponPt == NULL) {
        return 0;
    }
    ((struct SpiWeapon_champs *) SpiWeaponPt)->unk4 = spiGetStackInt__FP9SPI_STACK(arg0);
    ((struct SpiWeapon_champs *) SpiWeaponPt)->unk6 = spiGetStackInt__FP9SPI_STACK(suivant);
    return 1;
}
extern "C" s32 _DATAWEP_ST_L__FP9SPI_STACKi(SPI_STACK *arg0, s32 arg1) {
    SPI_STACK *suivant;

    suivant = arg0 + 1;
    if (SpiWeaponPt == NULL) {
        return 0;
    }
    ((struct SpiWeapon_champs *) SpiWeaponPt)->unk8 = spiGetStackInt__FP9SPI_STACK(arg0);
    ((struct SpiWeapon_champs *) SpiWeaponPt)->unkA = spiGetStackInt__FP9SPI_STACK(suivant);
    return 1;
}
struct SpiWeapon2__DATAWEP2_ST {
    char pad0[0xC];
    /* 0xC */ s16 unkC;
};
extern "C" s32 _DATAWEP2_ST__FP9SPI_STACKi(SPI_STACK *arg0, s32 arg1) {
    s32 var_s1;
    s32 var_s2;

    if (SpiWeaponPt == 0) {
        return 0;
    }
    var_s1 = 0;
    var_s2 = 0;
    do {
        ((struct SpiWeapon2__DATAWEP2_ST *) (SpiWeaponPt + var_s2))->unkC = spiGetStackInt__FP9SPI_STACK(arg0++);
        var_s1 += 1;
        var_s2 += 2;
    } while (var_s1 < 8);
    return 1;
}
struct SpiWeapon2__DATAWEP2_ST_L {
    char pad0[0x1C];
    /* 0x1C */ s16 unk1C;
};
extern "C" s32 _DATAWEP2_ST_L__FP9SPI_STACKi(SPI_STACK *arg0, s32 arg1) {
    s32 var_s1;
    s32 var_s2;

    if (SpiWeaponPt == 0) {
        return 0;
    }
    var_s1 = 0;
    var_s2 = 0;
    do {
        ((struct SpiWeapon2__DATAWEP2_ST_L *) (SpiWeaponPt + var_s2))->unk1C = spiGetStackInt__FP9SPI_STACK(arg0++);
        var_s1 += 1;
        var_s2 += 2;
    } while (var_s1 < 8);
    return 1;
}
struct SpiWeaponSpe {
    char pad0[0x2C];
    /* 0x2C */ s32 unk2C;
    char pad30[0x8];
    /* 0x38 */ s8 unk38;
    /* 0x39 */ s8 unk39;
    char pad3A[0xC];
    /* 0x46 */ s8 unk46;
    /* 0x47 */ s8 unk47;
    /* 0x48 */ s8 unk48;
    /* 0x49 */ s8 unk49;
};
extern "C" s32 fptoui(f32);
extern "C" f32 spiGetStackFloat__FP9SPI_STACK(SPI_STACK *);
extern "C" s32 _DATAWEP_SPE__FP9SPI_STACKi(SPI_STACK *arg0, s32 arg1) {
    if (SpiWeaponPt == NULL) {
        return 0;
    }
    ((struct SpiWeaponSpe *) SpiWeaponPt)->unk38 = fptoui(spiGetStackFloat__FP9SPI_STACK(arg0++));
    ((struct SpiWeaponSpe *) SpiWeaponPt)->unk46 = spiGetStackInt__FP9SPI_STACK(arg0++);
    ((struct SpiWeaponSpe *) SpiWeaponPt)->unk47 = spiGetStackInt__FP9SPI_STACK(arg0++);
    ((struct SpiWeaponSpe *) SpiWeaponPt)->unk39 = spiGetStackInt__FP9SPI_STACK(arg0++);
    ((struct SpiWeaponSpe *) SpiWeaponPt)->unk2C = spiGetStackInt__FP9SPI_STACK(arg0++);
    ((struct SpiWeaponSpe *) SpiWeaponPt)->unk48 = 0;
    if (arg1 >= 6) {
        ((struct SpiWeaponSpe *) SpiWeaponPt)->unk48 = spiGetStackInt__FP9SPI_STACK(arg0++);
    }
    ((struct SpiWeaponSpe *) SpiWeaponPt)->unk49 = 0;
    if (arg1 >= 7) {
        ((struct SpiWeaponSpe *) SpiWeaponPt)->unk49 = spiGetStackInt__FP9SPI_STACK(arg0);
    }
    return 1;
}
INCLUDE_ASM("nonmatchings/game/cgamedata", _DATAWEP_BUILDUP__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cgamedata", _DATAITEMINIT__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cgamedata", _DATAITEM__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cgamedata", _DATAATTACHINIT__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cgamedata", _DATAATTACH_ST__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cgamedata", _DATAATTACH_ST2__FP9SPI_STACKi);
extern "C" u32 SpiAttach;
struct SpiAttach_champs_25b384 {
    char pad0[0x14];
    /* 0x14 */ s32 unk14;
};
extern "C" s32 _DATAATTACH_ST_SP__FP9SPI_STACKi(SPI_STACK *arg0, s32 arg1) {
    if (SpiAttach == NULL) {
        return 1;
    }
    ((struct SpiAttach_champs_25b384 *) SpiAttach)->unk14 = spiGetStackInt__FP9SPI_STACK(arg0);
    SpiAttach += 0x18;
    return 1;
}
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
extern "C" s32 GetCommonData__9CGameDataFi(void *, s32);
struct CGameData_3f0e62 {
    char pad0[0x18];
    s32 unk18;
    char pad1C[0x10];
    u16 unk2C;
};
struct temp_v0_champs_3f0e62 {
    char pad0[0x4];
    s32 unk4;
};
extern "C" s32 GetRoboData__9CGameDataFi(CGameData_3f0e62 *objet, s32 arg0) {
    s16 temp_v1;
    s32 temp_a0;
    struct temp_v0_champs_3f0e62 *temp_v0;

    temp_v0 = (struct temp_v0_champs_3f0e62 *) (GetCommonData__9CGameDataFi(objet, arg0));
    if (temp_v0 == NULL) {
        return 0;
    }
    temp_v1 = (s16) (temp_v0->unk4);
    if ((s32) objet->unk2C <= temp_v1) {
        return 0;
    }
    temp_a0 = (s32) (objet->unk18);
    if (temp_a0 != 0) {
        return temp_a0 + (temp_v1 * 0x24);
    }
    return 0;
}
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
struct temp_v0_champs_2878ce {
    char pad0[0x28];
    /* 0x28 */ s32 unk28;
};
extern "C" s32 GetItemMessage__Fi(s32 arg0) {
    struct temp_v0_champs_2878ce *temp_v0;

    temp_v0 = (struct temp_v0_champs_2878ce *) (GetCommonData__9CGameDataFi(&GameItemDataManage, arg0));
    if (temp_v0 != NULL) {
        return temp_v0->unk28;
    }
    return 0;
}
struct temp_v0_champs_14f01f {
    char pad0[0x6];
    /* 0x6 */ s16 unk6;
};
extern "C" s16 GetItemIconNo__Fi(s32 arg0) {
    struct temp_v0_champs_14f01f *temp_v0;

    temp_v0 = (struct temp_v0_champs_14f01f *) (GetCommonData__9CGameDataFi(&GameItemDataManage, arg0));
    if (temp_v0 != NULL) {
        return temp_v0->unk6;
    }
    return -1;
}
INCLUDE_ASM("nonmatchings/game/cgamedata", SetItemSpectolPoint__FiP11ATTACH_USEDi);
INCLUDE_ASM("nonmatchings/game/cgamedata", ItemCmdMsgSet__FiPi);
