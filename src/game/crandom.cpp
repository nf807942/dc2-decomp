/* CRandom, CQuestManager, CQuestData, CMonsterBook, CVillagerPlace
 *
 * Unité découpée par `make carve` : 74 fonctions, 24312 octets, de
 * 0x0031FBA0 à 0x00325C60. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"
#include "gen/CQuestManager.hpp"
struct i;


struct CVillagerPlace;
extern "C" s32 memset(...);
extern "C" CVillagerPlace *__ct__14CVillagerPlaceFv(CVillagerPlace *objet) {
    memset(objet, 0, 8);
    return objet;
}
extern "C" s32 GetSaveData__Fv(void);
extern "C" s32 GetQuestData__Fv(void) {
    s32 temp_v0;

    temp_v0 = GetSaveData__Fv();
    if (temp_v0 != 0) {
        return (s32) ((u8 *) temp_v0 + 0x62A40);
    }
    return 0;
}
void CQuestManager::Initialize(void) {
    this->field_0x0 = 0;
    this->field_0x4 = 0;
}
INCLUDE_ASM("nonmatchings/game/crandom", GetQuestInfo__13CQuestManagerFi);
extern "C" u32 spi_quest_info;
typedef struct spi_questman_pointe {
    s32 unk0;
    s32 unk4;
} spi_questman_pointe;
extern "C" spi_questman_pointe *spi_questman;
struct spi_questman_pointe;
extern "C" u32 spi_queststack;
struct SPI_STACK {
    s32 field_0;
    s32 field_4;
};
extern "C" s32 Alloc__9mgCMemoryFi(...);
extern "C" s32 __nwa__FUiP1(...);
extern "C" s32 spiGetStackInt__FP9SPI_STACK(SPI_STACK *);
extern "C" s32 quest_NUM__FP9SPI_STACKi(SPI_STACK *arg0, s32 arg1) {
    s32 temp_v0;
    u32 temp_s0;
    u32 var_v0;

    temp_v0 = (s32) (spiGetStackInt__FP9SPI_STACK(arg0));
    spi_questman->unk0 = temp_v0;
    temp_s0 = temp_v0 * 0x3D0;
    if (temp_s0 & 0xF) {
        var_v0 = (temp_s0 >> 4) + 1;
    } else {
        var_v0 = temp_s0 >> 4;
    }
    spi_questman->unk4 = __nwa__FUiP1(temp_s0, Alloc__9mgCMemoryFi(spi_queststack, var_v0 + 2));
    spi_quest_info = spi_questman->unk4;
    return 1;
}
INCLUDE_ASM("nonmatchings/game/crandom", quest_NEW__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/crandom", quest_COMMENT__FP9SPI_STACKi);
extern "C" s32 quest_END__FP9SPI_STACKi(void *arg0, s32 arg1) {
    spi_quest_info += 0x3D0;
    return 1;
}
INCLUDE_ASM("nonmatchings/game/crandom", LoadCfg__13CQuestManagerFP9mgCMemoryPci);
extern "C" s32 memset(...);
extern "C" s32 Initialize__10CQuestDataFv(void *self) {
    return memset(self, 0, 0x480);
}
INCLUDE_ASM("nonmatchings/game/crandom", SetQuestFlag__10CQuestDataFii);
INCLUDE_ASM("nonmatchings/game/crandom", QuestClear__10CQuestDataFi);
extern "C" int GetPlayQuestData__10CQuestDataFi(void *, int);
extern "C" int GetPlayQuestData__10CQuestDataFi(void *p, int i) { if(i<0 || i>=0x40) return 0; return (int)p+(i<<4); }
extern "C" s32 GetQuestData__Fv(void);
struct CQuestData;
extern "C" s32 SetQuestFlag__10CQuestDataFii(void *, s32, s32);
extern "C" void QuestRequestSetFlag__Fii(s32 arg0, s32 arg1) {
    CQuestData *temp_v0;

    temp_v0 = (CQuestData *) (GetQuestData__Fv());
    if (temp_v0 != NULL) {
        SetQuestFlag__10CQuestDataFii(temp_v0, arg0, arg1);
    }
}
extern "C" s32 QuestClear__10CQuestDataFi(void *, s32);
extern "C" void QuestRequestClear__Fii(s32 arg0, s32 arg1) {
    CQuestData *temp_v0;

    temp_v0 = (CQuestData *) (GetQuestData__Fv());
    if (temp_v0 != NULL) {
        QuestClear__10CQuestDataFi(temp_v0, arg0);
    }
}
extern "C" s32 GetPlayQuestData__10CQuestDataFi(void *, s32);
struct temp_v0_champs {
    /* 0x0 */ s8 unk0;
    /* 0x1 */ s8 unk1;
};
extern "C" s32 GetQuestRequestStatus__Fi(s32 arg0) {
    CQuestData *temp_v0_2;
    struct temp_v0_champs *temp_v0;

    temp_v0_2 = (CQuestData *) (GetQuestData__Fv());
    if (temp_v0_2 == NULL) {
        return -1;
    }
    temp_v0 = (struct temp_v0_champs *) (GetPlayQuestData__10CQuestDataFi(temp_v0_2, arg0));
    if (temp_v0 == NULL) {
        return -1;
    }
    if (temp_v0->unk1 != 0) {
        return 2;
    }
    return temp_v0->unk0 != 0;
}
INCLUDE_ASM("nonmatchings/game/crandom", CountKill__12CMonsterBookFii);
INCLUDE_ASM("nonmatchings/game/crandom", FutureMapSelect__Fv);
extern "C" u32 AppInstall;
extern "C" u32 FreeSpace;
extern "C" u32 HddConnect;
extern "C" u32 error_code;
extern "C" u32 inst_work;
extern "C" u32 now_install;
extern "C" u32 sel_hdd;
extern "C" s32 CheckAppInstall__Fv(void);
extern "C" s32 CheckInstallSpace__Fv(void);
extern "C" s32 HddConectCheck__FPi(s32 *);
extern "C" void InitHDDMenu__FP1(s32 arg0) {
    s32 temp_v0;

    HddConnect = HddConectCheck__FPi(NULL);
    AppInstall = CheckAppInstall__Fv();
    temp_v0 = CheckInstallSpace__Fv();
    inst_work = arg0;
    sel_hdd = 1;
    FreeSpace = temp_v0;
    now_install = 0;
    error_code = 0;
}
INCLUDE_ASM("nonmatchings/game/crandom", HDDMenuLoop__Fv);
INCLUDE_ASM("nonmatchings/game/crandom", EmergencyMessage__Fi);
s32 HddConectCheck(s32 *state) {
    return 0;
}
s32 CheckAppInstall(void) {
    return 0;
}
s32 CheckInstallSpace(void) {
    return 0;
}
s32 MountHDDFileSystem(void) {
    return 0;
}
s32 UmountHDDFileSystem(void) {
    return 0;
}
s32 CreateInstallThread(i * arg0) {
    return 0;
}
void DeleteInstallThread(void) {
}
s32 StepInstallThread(void) {
    return 0;
}
s32 InstallPause(void) {
    return 0;
}
void InstallCancel(void) {
}
f32 GetInstallProgress(void) {
    return 0.0f;
}
s32 UninstallApp(void) {
    return 0;
}
INCLUDE_ASM("nonmatchings/game/crandom", search_txt__Fc);
INCLUDE_ASM("nonmatchings/game/crandom", ConvLongToTxt__FUlPc);
INCLUDE_ASM("nonmatchings/game/crandom", ConvTxtToLong__FPcPUl);
INCLUDE_ASM("nonmatchings/game/crandom", ConvertBinToTxt__FPUciPc);
INCLUDE_ASM("nonmatchings/game/crandom", ConvertTxtToBin__FPcPUc);
INCLUDE_ASM("nonmatchings/game/crandom", GetCRC__FPUci);
INCLUDE_ASM("nonmatchings/game/crandom", random__Fv);
INCLUDE_ASM("nonmatchings/game/crandom", EncodeBinData__FPUciPUci);
INCLUDE_ASM("nonmatchings/game/crandom", DecodeBinData__FPUciPUci);
INCLUDE_ASM("nonmatchings/game/crandom", EncodePassword__FPUciPUciPci);
INCLUDE_ASM("nonmatchings/game/crandom", DecodePassword__FPcPUciPUci);
INCLUDE_ASM("nonmatchings/game/crandom", nget__7CRandomFv);
extern "C" float abs__Ff(float arg0) {
    if (arg0 < 0.0f) return -arg0;
    return arg0;
}
INCLUDE_ASM("nonmatchings/game/crandom", grGyoRaceSimulate__FP11grRACE_INFO);
INCLUDE_ASM("nonmatchings/game/crandom", grGetFishProgress__FP11grRACE_INFOifP15grRACE_PROGRESS);
struct inferred;
typedef struct RACE_FISH_PARAM {
    /* 0x00 */ char pad0[0x50];
    /* 0x50 */ f32 unk50;                           /* inferred */
    /* 0x54 */ f32 unk54;                           /* inferred */
} RACE_FISH_PARAM;                                  /* size >= 0x58 */
extern "C" f32 FishDist__FP15RACE_FISH_PARAMP15RACE_FISH_PARAM(RACE_FISH_PARAM *arg0, RACE_FISH_PARAM *arg1) {
    return (arg0->unk54 + arg0->unk50) - (arg1->unk54 + arg1->unk50);
}
INCLUDE_ASM("nonmatchings/game/crandom", StepFish__FiP15RACE_FISH_PARAM);
INCLUDE_ASM("nonmatchings/game/crandom", LaneBattleStep__FP15RACE_FISH_PARAMi);
INCLUDE_ASM("nonmatchings/game/crandom", CollisionFish__FP15RACE_FISH_PARAMi);
INCLUDE_ASM("nonmatchings/game/crandom", StepGyoRace__FP15RACE_FISH_PARAMP11grRACE_INFO);
extern "C" s32 GetRaceDivision__Ff(f32 arg0) {
    s32 var_v0;

    if (arg0 < 2.0f) {
        return 0;
    }
    if (arg0 < 6.0f) {
        return 1;
    }
    if (arg0 < 10.0f) {
        return 2;
    }
    if (arg0 < 14.0f) {
        return 3;
    }
    var_v0 = -1;
    if (!(arg0 < 16.0f)) {
        return var_v0;
    }
    var_v0 = 4;

    return var_v0;
}
INCLUDE_ASM("nonmatchings/game/crandom", GetRaceDivisionLength__Fi);
INCLUDE_ASM("nonmatchings/game/crandom", GetCourseR__Fff);
INCLUDE_ASM("nonmatchings/game/crandom", FishModifyParam__FP12grFISH_PARAMPff);
INCLUDE_ASM("nonmatchings/game/crandom", CharacterBonus__FP12grFISH_PARAMP15RACE_FISH_PARAMi);
INCLUDE_ASM("nonmatchings/game/crandom", RndFishParam__FP15RACE_FISH_PARAM);
INCLUDE_ASM("nonmatchings/game/crandom", GetPaseRatio__FiPf);
INCLUDE_ASM("nonmatchings/game/crandom", SetRaceFishParam__FP15RACE_FISH_PARAMP11grRACE_INFO);
INCLUDE_ASM("nonmatchings/game/crandom", GetFishData__Fi);
INCLUDE_ASM("nonmatchings/game/crandom", irn55__Fv);
INCLUDE_ASM("nonmatchings/game/crandom", init_rnd__FUi);
INCLUDE_ASM("nonmatchings/game/crandom", irnd__Fv);
extern "C" s32 irnd__Fv(void);
extern "C" f32 rnd__Fv(void) {
    return (f32) irnd__Fv() / 1e9f;
}
INCLUDE_ASM("nonmatchings/game/crandom", nrnd__Fv);
INCLUDE_ASM("nonmatchings/game/crandom", GetRandomNumber__Fff);
INCLUDE_ASM("nonmatchings/game/crandom", rand_prob__Fi);
INCLUDE_ASM("nonmatchings/game/crandom", SVConvViewInit__F13INIT_LOOP_ARG);
extern "C" u8 GamePad_003FA5A0[1144];
extern "C" s32 AutoRepeatOff__8CGamePadFv(void *);
extern "C" s32 MenuModeOff__8CGamePadFv(void *);
extern "C" s32 mgCloseFont__Fv(void);
extern "C" s32 sceMcEnd(...);
extern "C" s32 sndSeAllStop__Fi(s32);
extern "C" void SVConvViewExit__Fv(void) {
    sceMcEnd();
    AutoRepeatOff__8CGamePadFv(&GamePad_003FA5A0);
    MenuModeOff__8CGamePadFv(&GamePad_003FA5A0);
    sndSeAllStop__Fi(-1);
    mgCloseFont__Fv();
}
INCLUDE_ASM("nonmatchings/game/crandom", SVConvViewLoop__Fv);
INCLUDE_ASM("nonmatchings/game/crandom", InitSaveFileInfoTablePtr__Fv);
INCLUDE_ASM("nonmatchings/game/crandom", SaveDataConvertLoop__Fv);
