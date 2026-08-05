/* CRandom, CQuestManager, CQuestData, CMonsterBook, CVillagerPlace
 *
 * Unité découpée par `make carve` : 74 fonctions, 24312 octets, de
 * 0x0031FBA0 à 0x00325C60. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

INCLUDE_ASM("nonmatchings/crandom", __ct__14CVillagerPlaceFv);
INCLUDE_ASM("nonmatchings/crandom", GetQuestData__Fv);
INCLUDE_ASM("nonmatchings/crandom", Initialize__13CQuestManagerFv);
INCLUDE_ASM("nonmatchings/crandom", GetQuestInfo__13CQuestManagerFi);
INCLUDE_ASM("nonmatchings/crandom", quest_NUM__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/crandom", quest_NEW__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/crandom", quest_COMMENT__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/crandom", quest_END__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/crandom", LoadCfg__13CQuestManagerFP9mgCMemoryPci);
INCLUDE_ASM("nonmatchings/crandom", Initialize__10CQuestDataFv);
INCLUDE_ASM("nonmatchings/crandom", SetQuestFlag__10CQuestDataFii);
INCLUDE_ASM("nonmatchings/crandom", QuestClear__10CQuestDataFi);
INCLUDE_ASM("nonmatchings/crandom", GetPlayQuestData__10CQuestDataFi);
INCLUDE_ASM("nonmatchings/crandom", QuestRequestSetFlag__Fii);
INCLUDE_ASM("nonmatchings/crandom", QuestRequestClear__Fii);
INCLUDE_ASM("nonmatchings/crandom", GetQuestRequestStatus__Fi);
INCLUDE_ASM("nonmatchings/crandom", CountKill__12CMonsterBookFii);
INCLUDE_ASM("nonmatchings/crandom", FutureMapSelect__Fv);
INCLUDE_ASM("nonmatchings/crandom", InitHDDMenu__FP1);
INCLUDE_ASM("nonmatchings/crandom", HDDMenuLoop__Fv);
INCLUDE_ASM("nonmatchings/crandom", EmergencyMessage__Fi);
INCLUDE_ASM("nonmatchings/crandom", HddConectCheck__FPi);
INCLUDE_ASM("nonmatchings/crandom", CheckAppInstall__Fv);
INCLUDE_ASM("nonmatchings/crandom", CheckInstallSpace__Fv);
INCLUDE_ASM("nonmatchings/crandom", MountHDDFileSystem__Fv);
INCLUDE_ASM("nonmatchings/crandom", UmountHDDFileSystem__Fv);
INCLUDE_ASM("nonmatchings/crandom", CreateInstallThread__FP1i);
INCLUDE_ASM("nonmatchings/crandom", DeleteInstallThread__Fv);
INCLUDE_ASM("nonmatchings/crandom", StepInstallThread__Fv);
INCLUDE_ASM("nonmatchings/crandom", InstallPause__Fv);
INCLUDE_ASM("nonmatchings/crandom", InstallCancel__Fv);
INCLUDE_ASM("nonmatchings/crandom", GetInstallProgress__Fv);
INCLUDE_ASM("nonmatchings/crandom", UninstallApp__Fv);
INCLUDE_ASM("nonmatchings/crandom", search_txt__Fc);
INCLUDE_ASM("nonmatchings/crandom", ConvLongToTxt__FUlPc);
INCLUDE_ASM("nonmatchings/crandom", ConvTxtToLong__FPcPUl);
INCLUDE_ASM("nonmatchings/crandom", ConvertBinToTxt__FPUciPc);
INCLUDE_ASM("nonmatchings/crandom", ConvertTxtToBin__FPcPUc);
INCLUDE_ASM("nonmatchings/crandom", GetCRC__FPUci);
INCLUDE_ASM("nonmatchings/crandom", random__Fv);
INCLUDE_ASM("nonmatchings/crandom", EncodeBinData__FPUciPUci);
INCLUDE_ASM("nonmatchings/crandom", DecodeBinData__FPUciPUci);
INCLUDE_ASM("nonmatchings/crandom", EncodePassword__FPUciPUciPci);
INCLUDE_ASM("nonmatchings/crandom", DecodePassword__FPcPUciPUci);
INCLUDE_ASM("nonmatchings/crandom", nget__7CRandomFv);
INCLUDE_ASM("nonmatchings/crandom", abs__Ff);
INCLUDE_ASM("nonmatchings/crandom", grGyoRaceSimulate__FP11grRACE_INFO);
INCLUDE_ASM("nonmatchings/crandom", grGetFishProgress__FP11grRACE_INFOifP15grRACE_PROGRESS);
INCLUDE_ASM("nonmatchings/crandom", FishDist__FP15RACE_FISH_PARAMP15RACE_FISH_PARAM);
INCLUDE_ASM("nonmatchings/crandom", StepFish__FiP15RACE_FISH_PARAM);
INCLUDE_ASM("nonmatchings/crandom", LaneBattleStep__FP15RACE_FISH_PARAMi);
INCLUDE_ASM("nonmatchings/crandom", CollisionFish__FP15RACE_FISH_PARAMi);
INCLUDE_ASM("nonmatchings/crandom", StepGyoRace__FP15RACE_FISH_PARAMP11grRACE_INFO);
INCLUDE_ASM("nonmatchings/crandom", GetRaceDivision__Ff);
INCLUDE_ASM("nonmatchings/crandom", GetRaceDivisionLength__Fi);
INCLUDE_ASM("nonmatchings/crandom", GetCourseR__Fff);
INCLUDE_ASM("nonmatchings/crandom", FishModifyParam__FP12grFISH_PARAMPff);
INCLUDE_ASM("nonmatchings/crandom", CharacterBonus__FP12grFISH_PARAMP15RACE_FISH_PARAMi);
INCLUDE_ASM("nonmatchings/crandom", RndFishParam__FP15RACE_FISH_PARAM);
INCLUDE_ASM("nonmatchings/crandom", GetPaseRatio__FiPf);
INCLUDE_ASM("nonmatchings/crandom", SetRaceFishParam__FP15RACE_FISH_PARAMP11grRACE_INFO);
INCLUDE_ASM("nonmatchings/crandom", GetFishData__Fi);
INCLUDE_ASM("nonmatchings/crandom", irn55__Fv);
INCLUDE_ASM("nonmatchings/crandom", init_rnd__FUi);
INCLUDE_ASM("nonmatchings/crandom", irnd__Fv);
INCLUDE_ASM("nonmatchings/crandom", rnd__Fv);
INCLUDE_ASM("nonmatchings/crandom", nrnd__Fv);
INCLUDE_ASM("nonmatchings/crandom", GetRandomNumber__Fff);
INCLUDE_ASM("nonmatchings/crandom", rand_prob__Fi);
INCLUDE_ASM("nonmatchings/crandom", SVConvViewInit__F13INIT_LOOP_ARG);
INCLUDE_ASM("nonmatchings/crandom", SVConvViewExit__Fv);
INCLUDE_ASM("nonmatchings/crandom", SVConvViewLoop__Fv);
INCLUDE_ASM("nonmatchings/crandom", InitSaveFileInfoTablePtr__Fv);
INCLUDE_ASM("nonmatchings/crandom", SaveDataConvertLoop__Fv);
