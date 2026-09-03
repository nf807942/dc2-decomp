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
struct CMonsterBox;
extern "C" s32 get_gajji_id_from_monster_progress_table__FiPi(s32 arg0, s32 *arg1);
extern "C" void GetMonsterBajjiData__11CMonsterBoxFi(CMonsterBox *objet, s32 arg0);
extern "C" void GetMonsterBajjiDataByMonsterID__11CMonsterBoxFi(CMonsterBox *objet, s32 arg0) {
    GetMonsterBajjiData__11CMonsterBoxFi(objet, get_gajji_id_from_monster_progress_table__FiPi(arg0, NULL) + 1);
}
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
typedef struct CFishingTournament_infere {
    /* 0x00 */ char pad0[0x24];
    /* 0x24 */ s16 unk24;                           /* inferred */
    /* 0x26 */ char pad26[6];                       /* maybe part of unk24[4]? */
    /* 0x2C */ s16 unk2C;                           /* inferred */
    /* 0x2E */ char pad2E[6];                       /* maybe part of unk2C[4]? */
    /* 0x34 */ s16 unk34;                           /* inferred */
} CFishingTournament_infere;                               /* size >= 0x36 */
extern "C" s32 SortRecord__18CFishingTournamentFv(CFishingTournament_infere *objet);
extern "C" s32 CalcTopWeight__18CFishingTournamentFv(CFishingTournament_infere *objet) {
    SortRecord__18CFishingTournamentFv(objet);
    return objet->unk34 + (objet->unk24 + objet->unk2C);
}
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
typedef struct CUserDataManager_infere3 {
    /* 0x00000 */ char pad0[0x44D94];
    /* 0x44D94 */ u8 unk44D94;                      /* inferred */
} CUserDataManager_infere3;                                 /* size >= 0x44D95 */
extern "C" void EnableCharaChangeMask__16CUserDataManagerFi(CUserDataManager_infere3 *objet, s32 arg0) {
    objet->unk44D94 |= (1 << arg0) & 0xFF;
}
typedef struct CUserDataManager_infere {
    /* 0x00000 */ char pad0[0x44D94];
    /* 0x44D94 */ u8 unk44D94;                      /* inferred */
} CUserDataManager_infere;                                 /* size >= 0x44D95 */
extern "C" void DisableCharaChangeMask__16CUserDataManagerFi(CUserDataManager_infere *objet, s32 arg0) {
    objet->unk44D94 &= ~(1 << arg0) & 0xFF;
}
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", InitCharaChangeMask__16CUserDataManagerFv);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetEnableCharaChangeFlag__16CUserDataManagerFv);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetCharaStatusAttirbutePtr__16CUserDataManagerFi);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", SetCharaStatusAttirbute__16CUserDataManagerFiUii);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", SetCharaStatusAttirbuteVol__16CUserDataManagerFiUii);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetCharaStatusAttirbute__16CUserDataManagerFi);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetMonsterBajjiDataPtr__16CUserDataManagerFi);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetMonsterBajjiDataPtrMosId__16CUserDataManagerFi);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetItemBoardOverNum__16CUserDataManagerFv);
struct CUserDataManager;
extern "C" s32 GetSaveData__Fv(void);
extern "C" s32 GetBitFlag__9CSaveDataFi(...);
extern "C" s32 GetItemBoardMaxNum__16CUserDataManagerFi(CUserDataManager *objet, s32 arg0) {
    s32 var_s0;
    s32 var_v0;

    var_s0 = 0;
    if (arg0 == 0) {
        var_s0 = 0x8A;
    }
    if (GetBitFlag__9CSaveDataFi(GetSaveData__Fv(), 0xFE) == 1) {
        if (arg0 == 0) {
            var_s0 = 0x90;
        }
    }
    var_v0 = var_s0;
    if (arg0 == 1) {
        var_v0 = 0x96;
    }
    return var_v0;
}
extern "C" s32 GetBattleCharaInfo__Fv(void);
struct inferred;
typedef struct CUserDataManager_infere2 {
    /* 0x00000 */ char pad0[0x44D96];
    /* 0x44D96 */ s16 unk44D96;                     /* inferred */
} CUserDataManager_infere2;                                 /* size >= 0x44D98 */
extern "C" s32 SetChrNo__16CBattleCharaInfoFi(void *, s32);
extern "C" void SetActiveChrNo__16CUserDataManagerFi(CUserDataManager_infere2 *objet, s32 arg0) {
    CBattleCharaInfo *temp_v0;

    objet->unk44D96 = (s16) arg0;
    temp_v0 = (CBattleCharaInfo *) (GetBattleCharaInfo__Fv());
    if (temp_v0 != NULL) {
        SetChrNo__16CBattleCharaInfoFi(temp_v0, arg0);
    }
}
typedef struct CUserDataManager_infere5 {
    /* 0x0000 */ char pad0[0x4662];
    /* 0x4662 */ char unk4662;                         /* inferred */
    /* 0x4662 */ char pad4662[1];
} CUserDataManager_infere5;                                 /* size >= 0x4663 */
extern "C" s32 strcpy(void *);
extern "C" void SetRoboName__16CUserDataManagerFPc(CUserDataManager_infere5 *objet, s8 *arg0) {
    if (arg0 != NULL) {
        strcpy(&objet->unk4662);
    }
}
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetRoboName__16CUserDataManagerFv);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetRoboNameDefault__16CUserDataManagerFv);
typedef struct CUserDataManager_infere4 {
    /* 0x0000 */ char pad0[0x467C];
    /* 0x467C */ s8 unk467C;                        /* inferred */
} CUserDataManager_infere4;                                 /* size >= 0x467D */
extern "C" s32 SetRoboVoiceFlag__16CUserDataManagerFi(void *, s32);
extern "C" void SetVoiceUnit__16CUserDataManagerFi(CUserDataManager_infere4 *objet, s32 arg0) {
    objet->unk467C = (s8) arg0;
    if (arg0 != 0) {
        SetRoboVoiceFlag__16CUserDataManagerFi(objet, 1);
    }
}
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", CheckVoiceUnit__16CUserDataManagerFv);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", SetRoboVoiceFlag__16CUserDataManagerFi);
typedef struct CUserDataManager_infere6 {
    /* 0x0000 */ char pad0[0x467C];
    /* 0x467C */ s8 unk467C;                        /* inferred */
    /* 0x467D */ s8 unk467D;                        /* inferred */
} CUserDataManager_infere6;                                 /* size >= 0x467E */
extern "C" s32 CheckRoboVoiceFlag__16CUserDataManagerFv(CUserDataManager_infere6 *objet) {
    s32 var_v0;

    var_v0 = objet->unk467C != 0;
    if (var_v0 != 0) {
        var_v0 = objet->unk467D != 0;
    }
    return var_v0 & 0xFF;
}
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
struct CUserDataManager;
extern "C" void GetActiveEsa__16CUserDataManagerFi(CUserDataManager *objet, s32 arg0);
extern "C" s32 GetFishingRodNo__16CUserDataManagerFv(CUserDataManager *objet);
extern "C" void GetActiveEsa__16CUserDataManagerFv(CUserDataManager *objet) {
    GetActiveEsa__16CUserDataManagerFi(objet, GetFishingRodNo__16CUserDataManagerFv(objet));
}
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetActiveEsa__16CUserDataManagerFi);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetFishBait__16CUserDataManagerFv);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", DeleteBait__16CUserDataManagerFv);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetFishInAquarium__16CUserDataManagerFiff);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", CheckFishRecordUpdate__16CUserDataManagerFiff);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetFishRecord__16CUserDataManagerFiPfPf);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetRodStatus__16CUserDataManagerFPi);
#include "gamedataused.hpp"
typedef struct CUserDataManager {
    /* 0x0000 */ char pad0[0x40B8];
    /* 0x40B8 */ CGameDataUsed unk40B8;             /* inferred */
    /* 0x40B8 */ char pad40B8[1];
} CUserDataManager;                                 /* size >= 0x40B9 */
extern "C" s32 AddFusionPoint__13CGameDataUsedFi(CGameDataUsed *objet, s32 arg0);
extern "C" s32 GetFishingRodNo__16CUserDataManagerFv(CUserDataManager *objet);
extern "C" s32 AddFp__16CUserDataManagerFi(CUserDataManager *objet, s32 arg0) {
    if (GetFishingRodNo__16CUserDataManagerFv(objet) <= 0) {
        return 0;
    }
    return AddFusionPoint__13CGameDataUsedFi(&objet->unk40B8, arg0);
}
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
extern "C" s32 GetUserDataMan__Fv(void);
extern "C" s32 DisableCharaChange__16CUserDataManagerFi(void *, s32);
extern "C" s32 EnableCharaChange__16CUserDataManagerFi(void *, s32);
extern "C" s32 InitCharaChangeMask__16CUserDataManagerFv(void *);
extern "C" void SetEnvUserDataMan__Fi(s32 arg0) {
    CUserDataManager *temp_s0;

    temp_s0 = (CUserDataManager *) (GetUserDataMan__Fv());
    if (arg0 == 0) {
        InitCharaChangeMask__16CUserDataManagerFv(temp_s0);
        DisableCharaChange__16CUserDataManagerFi(temp_s0, 2);
        DisableCharaChange__16CUserDataManagerFi(temp_s0, 3);
    }
    if (arg0 == 1) {
        InitCharaChangeMask__16CUserDataManagerFv(temp_s0);
        EnableCharaChange__16CUserDataManagerFi(temp_s0, 2);
        EnableCharaChange__16CUserDataManagerFi(temp_s0, 3);
    }
}
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetCharaDefaultWeapon__FiPi);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", LanguageEquipChange__Fv);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", CheckEquipChange__Fi);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", Initialize__16CBattleCharaInfoFv);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetEquipTablePtr__16CBattleCharaInfoFi);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", SetChrNo__16CBattleCharaInfoFi);
struct temp_v0_champs {
    char pad0[0x44D98];
    /* 0x44D98 */ s32 unk44D98;
};
extern "C" s16 GetMonsterID__16CBattleCharaInfoFv(CBattleCharaInfo *objet) {
    struct temp_v0_champs *temp_v0;

    temp_v0 = (struct temp_v0_champs *) (GetUserDataMan__Fv());
    if (temp_v0 != NULL) {
        return temp_v0->unk44D98;
    }
    return 0;
}
s16 CBattleCharaInfo::GetNowNPC(void) {
    return this->field_0x4;
}
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", UseNPCPoint__16CBattleCharaInfoFi);
typedef struct CBattleCharaInfo_infere3 {
    /* 0x00 */ char pad0[0x2C];
    /* 0x2C */ s32 unk2C;                           /* inferred */
} CBattleCharaInfo_infere3;                                 /* size >= 0x30 */
extern "C" s32 GetActiveItemInfo__16CBattleCharaInfoFi(CBattleCharaInfo_infere3 *objet, s32 arg0) {
    s32 temp_a0;
    s32 var_v0;

    temp_a0 = (s32) (objet->unk2C);
    var_v0 = 0;
    if (temp_a0 != 0) {
        var_v0 = temp_a0 + (arg0 * 0x6C);
    }
    return var_v0;
}
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
typedef struct CBattleCharaInfo_infere4 {
    /* 0x00 */ s16 unk0;                            /* inferred */
    /* 0x02 */ char pad2[0x18];                     /* maybe part of unk0[0xD]void */
    /* 0x1A */ s16 unk1A;                           /* inferred */
} CBattleCharaInfo_infere4;                                 /* size >= 0x1C */
extern "C" s16 GetMagicSwordCounterNow__16CBattleCharaInfoFv(CBattleCharaInfo_infere4 *objet) {
    if (objet->unk0 != 1) {
        return 0;
    }
    return objet->unk1A;
}
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
typedef struct CBattleCharaInfo_infere5 {
    /* 0x00 */ char pad0[0x74];
    /* 0x74 */ COMMON_GAGE *unk74;                  /* inferred */
} CBattleCharaInfo_infere5;                                 /* size >= 0x78 */
extern "C" s32 SetFillRate__11COMMON_GAGEFf(void *, f32);
extern "C" void SetHpRate__16CBattleCharaInfoFf(CBattleCharaInfo_infere5 *objet, f32 arg0) {
    COMMON_GAGE *temp_a0;

    temp_a0 = (COMMON_GAGE *) (objet->unk74);
    if (temp_a0 != NULL) {
        SetFillRate__11COMMON_GAGEFf(temp_a0, arg0);
    }
}
typedef struct CBattleCharaInfo_infere {
    /* 0x00 */ char pad0[0x74];
    /* 0x74 */ f32 *unk74;                          /* inferred */
} CBattleCharaInfo_infere;                                 /* size >= 0x78 */
extern "C" s32 fptosi(f32);
extern "C" s32 GetMaxHp_i__16CBattleCharaInfoFv(CBattleCharaInfo_infere *objet) {
    f32 *temp_v0;

    temp_v0 = objet->unk74;
    if (temp_v0 != NULL) {
        return fptosi(*temp_v0);
    }
    return 0;
}
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetNowHp_i__16CBattleCharaInfoFv);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", SetAttr__16CBattleCharaInfoFii);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", SetAttrVol__16CBattleCharaInfoFii);
typedef struct CBattleCharaInfo_infere2 {
    /* 0x0 */ s16 unk0;                             /* inferred */
} CBattleCharaInfo_infere2;                                 /* size >= 0x2 */
extern "C" s32 GetCharaStatusAttirbute__16CUserDataManagerFi(void *, s32);
extern "C" s32 GetAttr__16CBattleCharaInfoFv(CBattleCharaInfo_infere2 *objet) {
    CUserDataManager *temp_v0;

    temp_v0 = (CUserDataManager *) (GetUserDataMan__Fv());
    if (temp_v0 != NULL) {
        return GetCharaStatusAttirbute__16CUserDataManagerFi(temp_v0, (s32) objet->unk0);
    }
    return 0;
}
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", ForceSet__16CBattleCharaInfoFv);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetRandomCircleTrapID__Fi);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", SetRandamCircleStatus__FiRf);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", StatusParamStep__16CBattleCharaInfoFPi);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", Step__16CBattleCharaInfoFv);
