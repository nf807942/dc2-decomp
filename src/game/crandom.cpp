/* CRandom, CQuestManager, CQuestData, CMonsterBook, CVillagerPlace
 *
 * Unité découpée par `make carve` : 74 fonctions, 24312 octets, de
 * 0x0031FBA0 à 0x00325C60. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

INCLUDE_ASM("nonmatchings/game/crandom", __ct__14CVillagerPlaceFv);
INCLUDE_ASM("nonmatchings/game/crandom", GetQuestData__Fv);
INCLUDE_ASM("nonmatchings/game/crandom", Initialize__13CQuestManagerFv);
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
INCLUDE_ASM("nonmatchings/game/crandom", QuestRequestSetFlag__Fii);
INCLUDE_ASM("nonmatchings/game/crandom", QuestRequestClear__Fii);
INCLUDE_ASM("nonmatchings/game/crandom", GetQuestRequestStatus__Fi);
INCLUDE_ASM("nonmatchings/game/crandom", CountKill__12CMonsterBookFii);
INCLUDE_ASM("nonmatchings/game/crandom", FutureMapSelect__Fv);
INCLUDE_ASM("nonmatchings/game/crandom", InitHDDMenu__FP1);
INCLUDE_ASM("nonmatchings/game/crandom", HDDMenuLoop__Fv);
INCLUDE_ASM("nonmatchings/game/crandom", EmergencyMessage__Fi);
INCLUDE_ASM("nonmatchings/game/crandom", HddConectCheck__FPi);
INCLUDE_ASM("nonmatchings/game/crandom", CheckAppInstall__Fv);
INCLUDE_ASM("nonmatchings/game/crandom", CheckInstallSpace__Fv);
INCLUDE_ASM("nonmatchings/game/crandom", MountHDDFileSystem__Fv);
INCLUDE_ASM("nonmatchings/game/crandom", UmountHDDFileSystem__Fv);
INCLUDE_ASM("nonmatchings/game/crandom", CreateInstallThread__FP1i);
INCLUDE_ASM("nonmatchings/game/crandom", DeleteInstallThread__Fv);
INCLUDE_ASM("nonmatchings/game/crandom", StepInstallThread__Fv);
INCLUDE_ASM("nonmatchings/game/crandom", InstallPause__Fv);
INCLUDE_ASM("nonmatchings/game/crandom", InstallCancel__Fv);
INCLUDE_ASM("nonmatchings/game/crandom", GetInstallProgress__Fv);
INCLUDE_ASM("nonmatchings/game/crandom", UninstallApp__Fv);
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
INCLUDE_ASM("nonmatchings/game/crandom", FishDist__FP15RACE_FISH_PARAMP15RACE_FISH_PARAM);
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
INCLUDE_ASM("nonmatchings/game/crandom", rnd__Fv);
INCLUDE_ASM("nonmatchings/game/crandom", nrnd__Fv);
INCLUDE_ASM("nonmatchings/game/crandom", GetRandomNumber__Fff);
INCLUDE_ASM("nonmatchings/game/crandom", rand_prob__Fi);
INCLUDE_ASM("nonmatchings/game/crandom", SVConvViewInit__F13INIT_LOOP_ARG);
INCLUDE_ASM("nonmatchings/game/crandom", SVConvViewExit__Fv);
INCLUDE_ASM("nonmatchings/game/crandom", SVConvViewLoop__Fv);
INCLUDE_ASM("nonmatchings/game/crandom", InitSaveFileInfoTablePtr__Fv);
INCLUDE_ASM("nonmatchings/game/crandom", SaveDataConvertLoop__Fv);
