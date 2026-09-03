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


INCLUDE_ASM("nonmatchings/game/crandom", __ct__14CVillagerPlaceFv);
INCLUDE_ASM("nonmatchings/game/crandom", GetQuestData__Fv);
void CQuestManager::Initialize(void) {
    this->field_0x0 = 0;
    this->field_0x4 = 0;
}
INCLUDE_ASM("nonmatchings/game/crandom", GetQuestInfo__13CQuestManagerFi);
INCLUDE_ASM("nonmatchings/game/crandom", quest_NUM__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/crandom", quest_NEW__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/crandom", quest_COMMENT__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/crandom", quest_END__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/crandom", LoadCfg__13CQuestManagerFP9mgCMemoryPci);
INCLUDE_ASM("nonmatchings/game/crandom", Initialize__10CQuestDataFv);
INCLUDE_ASM("nonmatchings/game/crandom", SetQuestFlag__10CQuestDataFii);
INCLUDE_ASM("nonmatchings/game/crandom", QuestClear__10CQuestDataFi);
INCLUDE_ASM("nonmatchings/game/crandom", GetPlayQuestData__10CQuestDataFi);
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
INCLUDE_ASM("nonmatchings/game/crandom", GetQuestRequestStatus__Fi);
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
INCLUDE_ASM("nonmatchings/game/crandom", abs__Ff);
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
INCLUDE_ASM("nonmatchings/game/crandom", GetRaceDivision__Ff);
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
