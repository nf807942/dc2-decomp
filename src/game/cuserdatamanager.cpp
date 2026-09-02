/* CUserDataManager, CBattleCharaInfo, CFishAquarium, MOS_CHANGE_PARAM, CMonsterBox, CFishingTournament, CFishingRecord, ROBO_DATA
 *
 * Unité découpée par `make carve` : 176 fonctions, 26552 octets, de
 * 0x0019B680 à 0x001A2280. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"
#include "gen/CBattleCharaInfo.hpp"
#include "gen/CFishingTournament.hpp"
#include "gen/CBattleCharaInfo.hpp"
extern "C" void *memset(void *destination, s32 value, u32 size);


INCLUDE_ASM("nonmatchings/game/cuserdatamanager", Initialize__13CFishAquariumFv);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetAquariumFishTop__13CFishAquariumFi);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", SearchAqua1NotUsed__13CFishAquariumFi);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", FishIntoAquarium__13CFishAquariumFiiP13CGameDataUsed);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetAquariumFishNum__13CFishAquariumFi);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", CheckHaigouTankSex__13CFishAquariumFP13CGameDataUsed);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", RefreshParam__13CFishAquariumFv);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetShiledKitLimmit__Fi);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", AddPoint__9ROBO_DATAFf);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetDefenceVol__9ROBO_DATAFv);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetMonsterBaseInfo__Fi);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetMonsterHengeParam__Fi);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetAttackVol__16MOS_CHANGE_PARAMFi);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetDefenceVol__16MOS_CHANGE_PARAMFi);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", CheckClassChange__16MOS_CHANGE_PARAMFv);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetDegreeLevel__16MOS_CHANGE_PARAMFv);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", LevelUp__16MOS_CHANGE_PARAMFv);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", Initialize__11CMonsterBoxFv);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetMonsterBajjiData__11CMonsterBoxFi);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetMonsterBajjiDataByMonsterID__11CMonsterBoxFi);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", EnableChange__11CMonsterBoxFi);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", IsChange__11CMonsterBoxFi);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", AllCure__11CMonsterBoxFv);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetConvertIndexFromFishNo__Fi);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", __ct__14CFishingRecordFv);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetFishRecord__14CFishingRecordFi);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", CheckRecordFish__14CFishingRecordFiff);
void CFishingTournament::Initialize(void) {
    memset(this, 0, 112);
}
void CFishingTournament::ResetRecord(void) {
    memset(&this->field_0x20, 0, 80);
}
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", EntryFish__18CFishingTournamentFiii);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", EntryRemain__18CFishingTournamentFv);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetRecord__18CFishingTournamentFi);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", SetRank__18CFishingTournamentFi);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", SortRecord__18CFishingTournamentFv);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", CalcTopWeight__18CFishingTournamentFv);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", Initialize__16CUserDataManagerFv);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", RefreshParam__16CUserDataManagerFv);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetUsedDataPtr__16CUserDataManagerFi);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetCharaDataPtr__16CUserDataManagerFi);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetCharaHpGage__16CUserDataManagerFi);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", AddHp__16CUserDataManagerFii);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetHp__16CUserDataManagerFi);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", AddHp_Rate__16CUserDataManagerFif);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetWHpGage__16CUserDataManagerFii);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetAbsGage__16CUserDataManagerFii);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", AddWhp__16CUserDataManagerFiii);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetWhp__16CUserDataManagerFiiPi);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", AddAbs__16CUserDataManagerFiii);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetAbs__16CUserDataManagerFiiPi);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", JoinPartyMember__16CUserDataManagerFi);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", LeavePartyMember__16CUserDataManagerFi);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetNowPartyMember__16CUserDataManagerFv);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", EnableCharaChange__16CUserDataManagerFi);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", DisableCharaChange__16CUserDataManagerFi);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", CheckEnableCharaChange__16CUserDataManagerFiPi);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", CheckQuickChange__16CUserDataManagerFiPi);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", EnableCharaChangeMask__16CUserDataManagerFi);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", DisableCharaChangeMask__16CUserDataManagerFi);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", InitCharaChangeMask__16CUserDataManagerFv);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetEnableCharaChangeFlag__16CUserDataManagerFv);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetCharaStatusAttirbutePtr__16CUserDataManagerFi);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", SetCharaStatusAttirbute__16CUserDataManagerFiUii);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", SetCharaStatusAttirbuteVol__16CUserDataManagerFiUii);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetCharaStatusAttirbute__16CUserDataManagerFi);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetMonsterBajjiDataPtr__16CUserDataManagerFi);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetMonsterBajjiDataPtrMosId__16CUserDataManagerFi);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetItemBoardOverNum__16CUserDataManagerFv);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetItemBoardMaxNum__16CUserDataManagerFi);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", SetActiveChrNo__16CUserDataManagerFi);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", SetRoboName__16CUserDataManagerFPc);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetRoboName__16CUserDataManagerFv);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetRoboNameDefault__16CUserDataManagerFv);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", SetVoiceUnit__16CUserDataManagerFi);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", CheckVoiceUnit__16CUserDataManagerFv);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", SetRoboVoiceFlag__16CUserDataManagerFi);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", CheckRoboVoiceFlag__16CUserDataManagerFv);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", AddRoboAbs__16CUserDataManagerFf);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetRoboAbs__16CUserDataManagerFv);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", CheckCapacity__16CUserDataManagerFv);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", CheckRobotCore__16CUserDataManagerFv);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetDefenceVol__16CUserDataManagerFi);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", JoinPartyChara__16CUserDataManagerFiii);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", SetPartyCharaStatus__16CUserDataManagerFii);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetPartyCharaStatus__16CUserDataManagerFi);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", NowPartyCharaID__16CUserDataManagerFv);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", LeaveHouse__16CUserDataManagerFi);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetPartyCharaInfo__16CUserDataManagerFi);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", UseNpcAbility__16CUserDataManagerFiii);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", AllWeaponRepair__16CUserDataManagerFv);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", RefreshNPCStatus__16CUserDataManagerFi);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetFishingRodNo__16CUserDataManagerFv);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", NowFishingStyle__16CUserDataManagerFv);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetActiveEsa__16CUserDataManagerFv);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetActiveEsa__16CUserDataManagerFi);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetFishBait__16CUserDataManagerFv);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", DeleteBait__16CUserDataManagerFv);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetFishInAquarium__16CUserDataManagerFiff);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", CheckFishRecordUpdate__16CUserDataManagerFiff);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetFishRecord__16CUserDataManagerFiPfPf);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetRodStatus__16CUserDataManagerFPi);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", AddFp__16CUserDataManagerFi);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", SetChrEquip__16CUserDataManagerFiP13CGameDataUsed);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", SetChrEquip__16CUserDataManagerFii);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", SetChrEquipDirect__16CUserDataManagerFii);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", SearchEquip__16CUserDataManagerFii);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetCharaEquipDataPath__16CUserDataManagerFii);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", AddFusionPoint__16CUserDataManagerFiii);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", SearchSpaceUsedData__16CUserDataManagerFv);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", SearchSpaceUsedData__16CUserDataManagerFi);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", SearchSpaceUsedDataPtr__16CUserDataManagerFv);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", SearchSpaceUsedDataPtr__16CUserDataManagerFi);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", SearchActiveItemTableSpace__16CUserDataManagerFii);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", SearchItemOnItemBrd__16CUserDataManagerFii);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetNumStackOverBoard__16CUserDataManagerFv);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", SearchAllHaveItem__16CUserDataManagerFi);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", FishInAquarium__16CUserDataManagerFP13CGameDataUsedi);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", CheckElectricFish__16CUserDataManagerFv);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetNumSameItem__16CUserDataManagerFi);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", AddYarikomiMedal__16CUserDataManagerFi);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetYarikomiMedal__16CUserDataManagerFv);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetItem__16CUserDataManagerFii);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetItemNotOver__16CUserDataManagerFii);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetOverItem__16CUserDataManagerFii);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", CheckItemLimmitOver__16CUserDataManagerFv);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", DeleteItem_Local__FP13CGameDataUsedii);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", DeleteItem__16CUserDataManagerFii);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", CopyGameData__16CUserDataManagerFP13CGameDataUsedi);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", AddMoney__16CUserDataManagerFi);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", SetCostumeBit__16CUserDataManagerFUl);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetCostumeBit__16CUserDataManagerFv);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetCostume__16CUserDataManagerFi);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", CountFish__16CUserDataManagerFv);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", SetEnvUserDataMan__Fi);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetCharaDefaultWeapon__FiPi);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", LanguageEquipChange__Fv);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", CheckEquipChange__Fi);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", Initialize__16CBattleCharaInfoFv);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetEquipTablePtr__16CBattleCharaInfoFi);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", SetChrNo__16CBattleCharaInfoFi);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetMonsterID__16CBattleCharaInfoFv);
s16 CBattleCharaInfo::GetNowNPC(void) {
    return this->field_0x4;
}
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", UseNPCPoint__16CBattleCharaInfoFi);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetActiveItemInfo__16CBattleCharaInfoFi);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", UseActiveItem__16CBattleCharaInfoFP13CGameDataUsed);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetSpecialStatus__16CBattleCharaInfoFi);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetPalletNo__16CBattleCharaInfoFi);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", RefreshParamater__16CBattleCharaInfoFv);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetNowAccessWHp__16CBattleCharaInfoFi);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetNowAccessAbs__16CBattleCharaInfoFi);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", AddWhp__16CBattleCharaInfoFif);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetNowWhp__16CBattleCharaInfoFiPi);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetWhpNowVol__16CBattleCharaInfoFi);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", SetMagicSwordPow__16CBattleCharaInfoFii);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetMagicSwordElem__16CBattleCharaInfoFv);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetMagicSwordPow__16CBattleCharaInfoFv);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetMagicSwordCounterNow__16CBattleCharaInfoFv);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetMagicSwordCounterMax__16CBattleCharaInfoFv);
void CBattleCharaInfo::ClearMagicSwordPow(void) {
    this->field_0x18 = -1;
    this->field_0x1A = 0;
    this->field_0x1C = 0;
    this->field_0x1E = 0;
    this->field_0x20 = 0;
    this->field_0x22 = 0;
    this->field_0x24 = 0;
    this->field_0x26 = 0;
    this->field_0x28 = 0;
}
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", AddAbs__16CBattleCharaInfoFifPi);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", AddAbsRate__16CBattleCharaInfoFifPi);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetNowAbs__16CBattleCharaInfoFiPi);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", LevelUpWeapon__16CBattleCharaInfoFP13CGameDataUsed);
s16 CBattleCharaInfo::GetDefenceVol(void) {
    return this->field_0x6C;
}
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", AddHp_Point__16CBattleCharaInfoFff);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", AddHp_Rate__16CBattleCharaInfoFfif);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", SetHpRate__16CBattleCharaInfoFf);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetMaxHp_i__16CBattleCharaInfoFv);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetNowHp_i__16CBattleCharaInfoFv);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", SetAttr__16CBattleCharaInfoFii);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", SetAttrVol__16CBattleCharaInfoFii);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetAttr__16CBattleCharaInfoFv);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", ForceSet__16CBattleCharaInfoFv);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetRandomCircleTrapID__Fi);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", SetRandamCircleStatus__FiRf);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", StatusParamStep__16CBattleCharaInfoFPi);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", Step__16CBattleCharaInfoFv);
