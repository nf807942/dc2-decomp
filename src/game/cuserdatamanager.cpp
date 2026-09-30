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
extern "C" void AddPoint__11COMMON_GAGEFf(void *, float);
extern "C" float GetRate__11COMMON_GAGEFv(void *);
struct RoboGauge { char pad[0x20]; char gauge; };
extern "C" float AddPoint__9ROBO_DATAFf(RoboGauge *self, float x) { AddPoint__11COMMON_GAGEFf(&self->gauge,x); return GetRate__11COMMON_GAGEFv(&self->gauge); }
extern "C" s32 GetDefenceVol__9ROBO_DATAFv(void *objet) {
    return *(s16 *) ((u8 *) objet + 0xD0) + (*(u16 *) ((u8 *) objet + 0x1E8) << 2);
}
extern "C" void GetMonsterTable__Fi(s32);
extern "C" void GetMonsterBaseInfo__Fi(s32 arg0) {
    GetMonsterTable__Fi(arg0);
}
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetMonsterHengeParam__Fi);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetAttackVol__16MOS_CHANGE_PARAMFi);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetDefenceVol__16MOS_CHANGE_PARAMFi);
struct inferred;
struct MOS_CHANGE_PARAM;
typedef struct MOS_CHANGE_PARAM {
    /* 0x0 */ char pad0[2];
    /* 0x2 */ s16 unk2;                             /* inferred */
    /* 0x4 */ s16 unk4;                             /* inferred */
} MOS_CHANGE_PARAM;                                 /* size >= 0x6 */
extern "C" s32 CheckClassChange__16MOS_CHANGE_PARAMFv(MOS_CHANGE_PARAM *objet) {
    s16 temp_a1;

    temp_a1 = objet->unk4;
    if (temp_a1 >= 3) {
        return 0;
    }
    return temp_a1 < objet->unk2 / 25;
}
extern "C" s32 GetDegreeLevel__16MOS_CHANGE_PARAMFv(MOS_CHANGE_PARAM *objet) {
    s32 var_v0;

    var_v0 = objet->unk2 / 6;
    if (var_v0 > 0xF) {
        var_v0 = 0xF;
    }
    return var_v0;
}
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", LevelUp__16MOS_CHANGE_PARAMFv);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", Initialize__11CMonsterBoxFv);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetMonsterBajjiData__11CMonsterBoxFi);
struct CMonsterBox;
extern "C" s32 get_gajji_id_from_monster_progress_table__FiPi(s32 arg0, s32 *arg1);
extern "C" u8 *GetMonsterBajjiData__11CMonsterBoxFi(CMonsterBox *objet, s32 arg0);
extern "C" void GetMonsterBajjiDataByMonsterID__11CMonsterBoxFi(CMonsterBox *objet, s32 arg0) {
    GetMonsterBajjiData__11CMonsterBoxFi(objet, get_gajji_id_from_monster_progress_table__FiPi(arg0, NULL) + 1);
}
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", EnableChange__11CMonsterBoxFi);
extern "C" s32 IsChange__11CMonsterBoxFi(CMonsterBox *objet, s32 arg0) {
    u8 *p = GetMonsterBajjiData__11CMonsterBoxFi(objet, arg0);
    if (p != 0) return p[0xA];
    return 0;
}
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
struct calcul0_champs_46e4c1 {
    char pad0[0x20];
    /* 0x20 */ s16 unk20;
};
extern "C" s32 EntryRemain__18CFishingTournamentFv(CFishingTournament *objet) {
    s32 var_v1;
    s32 var_a1;
    s32 var_a2;

    var_v1 = 0;
    var_a1 = 0;
    var_a2 = 0;
    do {
        if (((struct calcul0_champs_46e4c1 *) ((u8 *) objet + var_a2))->unk20 > 0) {
            var_v1 += 1;
        }
        var_a1 += 1;
        var_a2 += 8;
    } while (var_a1 < 0xA);
    return 0xA - var_v1;
}
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetRecord__18CFishingTournamentFi);
struct inferred;
struct CFishingTournament_infere_7649ec;
typedef struct CFishingTournament_infere_7649ec {
    /* 0x0 */ char pad0[4];
    /* 0x4 */ s16 unk4;                             /* inferred */
} CFishingTournament_infere_7649ec;                               /* size >= 0x6 */
extern "C" void SetRank__18CFishingTournamentFi(CFishingTournament_infere_7649ec *objet, s32 arg0) {
    if (arg0 < 0) {
        arg0 = 0;
    }
    if (arg0 > 0x64) {
        arg0 = 0x64;
    }
    objet->unk4 = (s16) arg0;
}
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
extern "C" int GetCharaDataPtr__16CUserDataManagerFi(void *, int);
extern "C" int GetCharaDataPtr__16CUserDataManagerFi(void *p, int id) { if(id==0 || id==1) { int v=id*0x38C; v=(int)p+v; v+=0x3F48; return v; } return 0; }
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetCharaHpGage__16CUserDataManagerFi);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", AddHp__16CUserDataManagerFii);
struct COMMON_GAGE_hp { char pad0[4]; f32 unk4; };
extern "C" s32 fptosi(f32);
extern "C" COMMON_GAGE_hp *GetCharaHpGage__16CUserDataManagerFi(void *, s32);
extern "C" f32 GetHp__16CUserDataManagerFi(void *objet, s32 arg0) {
    COMMON_GAGE_hp *gage = GetCharaHpGage__16CUserDataManagerFi(objet, arg0);
    if (gage != NULL) {
        return (f32) fptosi(gage->unk4);
    }
    return 0.0f;
}
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", AddHp_Rate__16CUserDataManagerFif);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetWHpGage__16CUserDataManagerFii);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetAbsGage__16CUserDataManagerFii);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", AddWhp__16CUserDataManagerFiii);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetWhp__16CUserDataManagerFiiPi);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", AddAbs__16CUserDataManagerFiii);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetAbs__16CUserDataManagerFiiPi);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", JoinPartyMember__16CUserDataManagerFi);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", LeavePartyMember__16CUserDataManagerFi);
struct CUserDataManager_partybits { char pad0[0x44D90]; u16 unk44D90; };
extern "C" s32 SearchItemOnItemBrd__16CUserDataManagerFii(void *, s32, s32);
extern "C" s32 GetNowPartyMember__16CUserDataManagerFv(CUserDataManager_partybits *objet) {
    s32 temp_s0 = objet->unk44D90;
    s32 result = temp_s0;
    if (SearchItemOnItemBrd__16CUserDataManagerFii(objet, 0x134, 0) != 0) {
        result = temp_s0 | 8;
    }
    return result;
}
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
extern "C" s32 InitCharaChangeMask__16CUserDataManagerFv(void *arg0) {
    *((u8 *) arg0 + 0x44D94) = 15;
}
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetEnableCharaChangeFlag__16CUserDataManagerFv);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetCharaStatusAttirbutePtr__16CUserDataManagerFi);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", SetCharaStatusAttirbute__16CUserDataManagerFiUii);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", SetCharaStatusAttirbuteVol__16CUserDataManagerFiUii);
extern "C" unsigned short *GetCharaStatusAttirbutePtr__16CUserDataManagerFi(void *, int);
extern "C" int GetCharaStatusAttirbute__16CUserDataManagerFi(void *self, int i) { unsigned short *p=GetCharaStatusAttirbutePtr__16CUserDataManagerFi(self,i); if(p!=0) return *p; return 0; }
extern "C" u8 *GetMonsterBajjiData__11CMonsterBoxFi(CMonsterBox *objet, s32 arg0);
extern "C" void GetMonsterBajjiDataPtr__16CUserDataManagerFi(u8 *self, s32 id) {
    GetMonsterBajjiData__11CMonsterBoxFi((CMonsterBox *) (self + 0x4EB0), id);
}
extern "C" void GetMonsterBajjiDataByMonsterID__11CMonsterBoxFi(CMonsterBox *objet, s32 arg0);
extern "C" void GetMonsterBajjiDataPtrMosId__16CUserDataManagerFi(u8 *self, s32 id) {
    GetMonsterBajjiDataByMonsterID__11CMonsterBoxFi((CMonsterBox *) (self + 0x4EB0), id);
}
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
struct CUserDataManager_roboname { char pad0[0x4662]; s8 unk4662; };
extern "C" s8 *GetRoboName__16CUserDataManagerFv(CUserDataManager_roboname *objet) {
    return &objet->unk4662;
}
extern "C" u32 LanguageCode;
extern "C" char *robo_nametable_3330[];
extern "C" char *GetRoboNameDefault__16CUserDataManagerFv(void) {
    return robo_nametable_3330[LanguageCode];
}
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
struct CUserDataManager_voiceunit { char pad0[0x467C]; s8 unk467C; };
extern "C" s8 CheckVoiceUnit__16CUserDataManagerFv(CUserDataManager_voiceunit *objet) {
    return objet->unk467C;
}
extern "C" s32 SetRoboVoiceFlag__16CUserDataManagerFi(void *self, s32 a) {
    *(u8 *) ((u8 *) self + 0x467D) = a;
}
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
struct CUserDataManager_3e774a;
typedef struct CUserDataManager_3e774a {
    /* 0x0000 */ char pad0[0x468C];
    /* 0x468C */ f32 unk468C;                       /* inferred */
} CUserDataManager_3e774a;                                 /* size >= 0x4690 */
extern "C" f32 AddRoboAbs__16CUserDataManagerFf(CUserDataManager_3e774a *objet, f32 arg0) {
    f32 temp_f0;

    temp_f0 = (f32) (objet->unk468C + arg0);
    objet->unk468C = temp_f0;
    if (temp_f0 < 0.0f) {
        objet->unk468C = 0.0f;
    }
    if (99999.0f < objet->unk468C) {
        objet->unk468C = 99999.0f;
    }
    return objet->unk468C;
}
struct CUserDataManager_roboabs { char pad0[0x468C]; f32 unk468C; };
extern "C" f32 GetRoboAbs__16CUserDataManagerFv(CUserDataManager_roboabs *objet) {
    return objet->unk468C;
}
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
struct CUserDataManager;
extern "C" s32 GetFishingRodNo__16CUserDataManagerFv(struct CUserDataManager *objet) {
    return *(s16 *) ((u8 *) objet + 0x40BA);
}
#include "gamedataused.hpp"
struct CUserDataManager_2a7d53;
typedef struct CUserDataManager_2a7d53 {
    /* 0x0000 */ char pad0[0x40B8];
    /* 0x40B8 */ char pad40B8[1];
} CUserDataManager_2a7d53;                                 /* size >= 0x40B9 */
struct objet_champs_2a7d53 {
    char pad0[0x40B8];
    /* 0x40B8 */ s32 unk40B8;
};
extern "C" s32 IsFishingRod__13CGameDataUsedFv(void *);
extern "C" s32 NowFishingStyle__16CUserDataManagerFv(CUserDataManager_2a7d53 *objet) {
    CGameDataUsed *temp_a0;

    temp_a0 = (CGameDataUsed *) (&((struct objet_champs_2a7d53 *) objet)->unk40B8);
    if (temp_a0 != NULL) {
        return IsFishingRod__13CGameDataUsedFv(temp_a0);
    }
    return 0;
}
struct CUserDataManager;
extern "C" u8 *GetActiveEsa__16CUserDataManagerFi(CUserDataManager *objet, s32 arg0);
extern "C" s32 GetFishingRodNo__16CUserDataManagerFv(CUserDataManager *objet);
extern "C" void GetActiveEsa__16CUserDataManagerFv(CUserDataManager *objet) {
    GetActiveEsa__16CUserDataManagerFi(objet, GetFishingRodNo__16CUserDataManagerFv(objet));
}
extern "C" u8 *GetActiveEsa__16CUserDataManagerFi(CUserDataManager *self, s32 id) {
    if (id == 0x12E) {
        return (u8 *)self + 0x4880;
    }
    if (id == 0x12F) {
        return (u8 *)self + 0x48EC;
    }
    return 0;
}
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
extern "C" s32 SearchItemOnItemBrd__16CUserDataManagerFii(void *, s32, s32);
extern "C" s32 SearchEquip__16CUserDataManagerFii(void *, s32, s32);
extern "C" s32 SetChrEquip__16CUserDataManagerFiP13CGameDataUsed(void *, s32, CGameDataUsed *);
extern "C" s32 SetChrEquip__16CUserDataManagerFii(CUserDataManager *objet, s32 arg0, s32 arg1) {
    CGameDataUsed *temp_v0;

    if (arg1 <= 0) {
        return 0;
    }
    if ((arg0 < 0) || (arg0 > 2)) {
        return 0;
    }
    if (SearchEquip__16CUserDataManagerFii(objet, arg0, arg1) != 0) {
        return 0;
    }
    temp_v0 = (CGameDataUsed *) (SearchItemOnItemBrd__16CUserDataManagerFii(objet, arg1, 1));
    if (temp_v0 == NULL) {
        return 0;
    }
    SetChrEquip__16CUserDataManagerFiP13CGameDataUsed(objet, arg0, temp_v0);
    return 1;
}
extern "C" s32 __ct__13CGameDataUsedFv(void *);
extern "C" s32 CopyGameData__16CUserDataManagerFP13CGameDataUsedi(CUserDataManager *, CGameDataUsed *, s32);
extern "C" s32 SetChrEquipDirect__16CUserDataManagerFii(CUserDataManager *objet, s32 arg0, s32 arg1) {
    /* Le cadre du commerce réserve 0x70 octets à l'objet, là où l'en-tête n'en décrit que 0x3C. */
    struct { CGameDataUsed data; u8 rest[0x34]; } sp40;

    if (arg1 <= 0) {
        return 0;
    }
    if ((arg0 < 0) || (arg0 > 2)) {
        return 0;
    }
    if (SearchEquip__16CUserDataManagerFii(objet, arg0, arg1) != 0) {
        return 0;
    }
    __ct__13CGameDataUsedFv(&sp40.data);
    CopyGameData__16CUserDataManagerFP13CGameDataUsedi(objet, &sp40.data, arg1);
    SetChrEquip__16CUserDataManagerFiP13CGameDataUsed(objet, arg0, &sp40.data);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", SearchEquip__16CUserDataManagerFii);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetCharaEquipDataPath__16CUserDataManagerFii);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", AddFusionPoint__16CUserDataManagerFiii);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", SearchSpaceUsedData__16CUserDataManagerFv);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", SearchSpaceUsedData__16CUserDataManagerFi);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", SearchSpaceUsedDataPtr__16CUserDataManagerFv);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", SearchSpaceUsedDataPtr__16CUserDataManagerFi);
struct calcul0_champs_14ed4c {
    char pad0[0x2E];
    /* 0x2E */ s16 unk2E;
};
extern "C" s32 CheckStackRemain__13CGameDataUsedFv(void *);
extern "C" s32 GetCharaDataPtr__16CUserDataManagerFi(void *, s32);
struct CGameDataUsed_infere_14ed4c {
    char pad0[0x2];
    s16 unk2;
};
extern "C" s32 SearchActiveItemTableSpace__16CUserDataManagerFii(CUserDataManager *objet, s32 arg0, s32 arg1) {
    s32 temp_v0;
    s32 var_s1;
    s32 var_s2;
    s32 var_v0;
    s32 var_a0;
    struct CGameDataUsed_infere_14ed4c *temp_v0_2;

    temp_v0 = (s32) (GetCharaDataPtr__16CUserDataManagerFi(objet, arg0));
    var_s1 = 0;
    if (temp_v0 == 0) {
        return -1;
    }
    var_s2 = 0;
    for (; var_s1 < 3; var_s1++) {
        temp_v0_2 = (struct CGameDataUsed_infere_14ed4c *) (temp_v0 + var_s2 + 0x2C);
        if ((temp_v0_2->unk2 == arg1) && (CheckStackRemain__13CGameDataUsedFv(temp_v0_2) > 0)) {
            return var_s1;
        }
        var_s2 += 0x6C;
    }
    var_v0 = 0;
    var_a0 = 0;
    for (; var_v0 < 3; var_v0++) {
        if (((struct calcul0_champs_14ed4c *) (temp_v0 + var_a0))->unk2E <= 0) {
            return var_v0;
        }
        var_a0 += 0x6C;
    }
    return -1;
}
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", SearchItemOnItemBrd__16CUserDataManagerFii);
extern "C" s32 GetUsedDataPtr__16CUserDataManagerFi(void *, s32);
struct var_s1_champs_c79195 {
    char pad0[0x2];
    /* 0x2 */ s16 unk2;
};
extern "C" s32 GetNowBagMax__Fi(s32);
extern "C" s32 GetItemBoardOverNum__16CUserDataManagerFv(void *);
extern "C" s32 GetNumStackOverBoard__16CUserDataManagerFv(CUserDataManager *objet) {
    s32 var_s0;
    u8 *var_s1;
    s32 var_s2;

    var_s0 = 0;
    var_s1 = (u8 *) (GetUsedDataPtr__16CUserDataManagerFi(objet, GetNowBagMax__Fi(0)));
    for (var_s2 = 0; var_s2 < GetItemBoardOverNum__16CUserDataManagerFv(objet); var_s2++, var_s1 += 0x6C) {
        if (((struct var_s1_champs_c79195 *) var_s1)->unk2 > 1) {
            var_s0 += 1;
        }
    }
    return var_s0;
}
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", SearchAllHaveItem__16CUserDataManagerFi);
struct CFishAquarium {
    s16 field_0;
    s16 field_2;
    char pad_4[0x514];
    s64 field_518;
    s64 field_520;
    s32 field_528;
    f32 field_52C;
};
typedef struct CUserDataManager_infere7 {
    /* 0x0000 */ char pad0[0x4958];
    /* 0x4958 */ CFishAquarium unk4958;             /* inferred */
    /* 0x4958 */ char pad4958[1];
} CUserDataManager_infere7;                                 /* size >= 0x4959 */
extern "C" s32 Init__13CGameDataUsedFv(void *);
extern "C" s32 FishIntoAquarium__13CFishAquariumFiiP13CGameDataUsed(void *, s32, s32, CGameDataUsed *);
extern "C" s32 SearchAqua1NotUsed__13CFishAquariumFi(void *, s32);
extern "C" s32 FishInAquarium__16CUserDataManagerFP13CGameDataUsedi(CUserDataManager_infere7 *objet, CGameDataUsed *arg0, s32 arg1) {
    CFishAquarium *temp_s0;
    s32 temp_v0;

    temp_s0 = (CFishAquarium *) (&objet->unk4958);
    if ((arg1 < 0) || (arg1 > 2)) {
        return 0;
    }
    temp_v0 = (s32) (SearchAqua1NotUsed__13CFishAquariumFi(temp_s0, 0));
    if ((temp_v0 < 0) || (arg0 == NULL)) {
        return 0;
    }
    FishIntoAquarium__13CFishAquariumFiiP13CGameDataUsed(temp_s0, arg1, temp_v0, arg0);
    Init__13CGameDataUsedFv(arg0);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", CheckElectricFish__16CUserDataManagerFv);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetNumSameItem__16CUserDataManagerFi);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", AddYarikomiMedal__16CUserDataManagerFi);
struct CUserDataManager_medal { char pad0[0x44DA0]; s16 unk44DA0; };
extern "C" s16 GetYarikomiMedal__16CUserDataManagerFv(CUserDataManager_medal *objet) {
    return objet->unk44DA0;
}
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetItem__16CUserDataManagerFii);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetItemNotOver__16CUserDataManagerFii);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetOverItem__16CUserDataManagerFii);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", CheckItemLimmitOver__16CUserDataManagerFv);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", DeleteItem_Local__FP13CGameDataUsedii);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", DeleteItem__16CUserDataManagerFii);
extern "C" s32 GetCommonItemData__Fi(s32);
extern "C" s32 ConvertUsedItemType__Fi(s32);
extern "C" s32 CopyDataAttach__13CGameDataUsedFi(CGameDataUsed *, s32);
extern "C" s32 CopyDataFish__13CGameDataUsedFi(CGameDataUsed *, s32);
extern "C" s32 CopyDataGiftBox__13CGameDataUsedFi(CGameDataUsed *, s32);
extern "C" s32 CopyDataItem__13CGameDataUsedFi(CGameDataUsed *, s32);
extern "C" s32 CopyDataRoboPart__13CGameDataUsedFi(CGameDataUsed *, s32);
extern "C" s32 CopyDataWeapon__13CGameDataUsedFi(CGameDataUsed *, s32);
extern "C" s32 CopyGameData__16CUserDataManagerFP13CGameDataUsedi(CUserDataManager *objet, CGameDataUsed *arg0, s32 arg1) {
    u32 temp_v0_2;
    u8 *temp_v0;

    if (arg0 == NULL) {
        return 0;
    }
    temp_v0 = (u8 *) (GetCommonItemData__Fi(arg1));
    if (temp_v0 == NULL) {
        return 0;
    }
    temp_v0_2 = (u32) (ConvertUsedItemType__Fi((s32) *temp_v0));
    switch (temp_v0_2) {
    case 1:
    case 4:
        CopyDataItem__13CGameDataUsedFi(arg0, arg1);
        break;
    case 2:
        CopyDataAttach__13CGameDataUsedFi(arg0, arg1);
        break;
    case 3:
        CopyDataWeapon__13CGameDataUsedFi(arg0, arg1);
        break;
    case 5:
        CopyDataRoboPart__13CGameDataUsedFi(arg0, arg1);
        break;
    case 7:
        CopyDataGiftBox__13CGameDataUsedFi(arg0, arg1);
        break;
    case 6:
        CopyDataFish__13CGameDataUsedFi(arg0, arg1);
        break;
    }
    return 1;
}
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", AddMoney__16CUserDataManagerFi);
struct CUserDataManager_costumebit2 { char pad0[0x45598]; s64 unk45598; };
extern "C" void SetCostumeBit__16CUserDataManagerFUl(CUserDataManager_costumebit2 *objet, s64 a) {
    objet->unk45598 = a;
}
struct CUserDataManager_costumebit { char pad0[0x45598]; s64 unk45598; };
extern "C" s64 GetCostumeBit__16CUserDataManagerFv(CUserDataManager_costumebit *objet) {
    return objet->unk45598;
}
extern "C" s32 GetCosInfo__Fi(s32);
struct CUserDataManager_infere8;
typedef struct CUserDataManager_infere8 {
    /* 0x00000 */ char pad0[0x45598];
    /* 0x45598 */ s64 unk45598;                     /* inferred */
} CUserDataManager_infere8;                                 /* size >= 0x455A0 */
struct temp_v0_champs_60b981 {
    char pad0[0x2];
    /* 0x2 */ s8 unk2;
};
extern "C" void GetCostume__16CUserDataManagerFi(CUserDataManager_infere8 *objet, s32 arg0) {
    struct temp_v0_champs_60b981 *temp_v0;

    temp_v0 = (struct temp_v0_champs_60b981 *) (GetCosInfo__Fi(arg0));
    if (temp_v0 != NULL) {
        objet->unk45598 |= (s64) 1 << temp_v0->unk2;
    }
}
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
struct CBattleCharaInfo_infere_777866;
typedef struct CBattleCharaInfo_infere_777866 {
    /* 0x00 */ char pad0[8];
    /* 0x08 */ void *unk8;                          /* inferred */
    /* 0x0C */ char padC[0x24];
    /* 0x30 */ s32 unk30;                           /* inferred */
} CBattleCharaInfo_infere_777866;                                 /* size >= 0x34 */
extern "C" s32 GetEquipTablePtr__16CBattleCharaInfoFi(CBattleCharaInfo_infere_777866 *objet, s32 arg0) {
    if ((arg0 < 0) || (arg0 > 3)) {
        return 0;
    }
    return objet->unk30 + (arg0 * 0x6C);
}
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
struct CItemUseTarget {
    s32 field_0;
};
struct CGameDataUsed_infere;
typedef struct CGameDataUsed_infere {
    /* 0x0 */ char pad0[2];
    /* 0x2 */ s16 unk2;                             /* inferred */
} CGameDataUsed_infere;                                    /* size >= 0x4 */
struct arg0_champs_003804 {
    char pad0[0x2];
    /* 0x2 */ s16 unk2;
};
extern "C" s32 MenuUseItemCheckFunc__FP13CGameDataUsedP14CItemUseTargeti(CGameDataUsed_infere *, CItemUseTarget *, s32);
extern "C" s32 SetPtr__14CItemUseTargetFiPv(...);
extern "C" s32 UseActiveItem__16CBattleCharaInfoFP13CGameDataUsed(CBattleCharaInfo_infere_777866 *objet, CGameDataUsed_infere *arg0) {
    s32 sp48[2];
    s32 temp_s0;

    if (arg0 == NULL) {
        return 0;
    }
    temp_s0 = ((struct arg0_champs_003804 *) arg0)->unk2;
    sp48[0] = -1;
    SetPtr__14CItemUseTargetFiPv((CItemUseTarget *) sp48, 0, objet->unk8);
    if (temp_s0 == 0x126) {
        SetPtr__14CItemUseTargetFiPv((CItemUseTarget *) sp48, 1, GetEquipTablePtr__16CBattleCharaInfoFi(objet, 0));
    }
    if ((temp_s0 == 0x12A) || (temp_s0 == 0x160)) {
        SetPtr__14CItemUseTargetFiPv((CItemUseTarget *) sp48, 1, GetEquipTablePtr__16CBattleCharaInfoFi(objet, 1));
    }
    return MenuUseItemCheckFunc__FP13CGameDataUsedP14CItemUseTargeti(arg0, (CItemUseTarget *) sp48, 1);
}
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetSpecialStatus__16CBattleCharaInfoFi);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetPalletNo__16CBattleCharaInfoFi);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", RefreshParamater__16CBattleCharaInfoFv);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetNowAccessWHp__16CBattleCharaInfoFi);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetNowAccessAbs__16CBattleCharaInfoFi);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", AddWhp__16CBattleCharaInfoFif);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetNowWhp__16CBattleCharaInfoFiPi);
struct temp_v0_champs_2fdd3a { char pad0[4]; f32 unk4; };
extern "C" s32 GetNowAccessWHp__16CBattleCharaInfoFi(void *, s32);
extern "C" s32 GetDispVolumeForFloat__Ff(f32);
extern "C" s32 GetWhpNowVol__16CBattleCharaInfoFi(void *objet, s32 arg0) {
    temp_v0_champs_2fdd3a *p = (temp_v0_champs_2fdd3a *) GetNowAccessWHp__16CBattleCharaInfoFi(objet, arg0);
    if (p != 0) return GetDispVolumeForFloat__Ff(p->unk4);
    return 0;
}
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", SetMagicSwordPow__16CBattleCharaInfoFii);
typedef struct CBattleCharaInfo_infere6 {
    /* 0x00 */ s16 unk0;                            /* inferred */
    /* 0x02 */ char pad2[0x16];                     /* maybe part of unk0[0xC]void */
    /* 0x18 */ s16 unk18;                           /* inferred */
} CBattleCharaInfo_infere6;                                 /* size >= 0x1A */
extern "C" s16 GetMagicSwordElem__16CBattleCharaInfoFv(CBattleCharaInfo_infere6 *objet) {
    s16 var_v0;

    var_v0 = -1;
    if (!(objet->unk0 == 1)) {
        return var_v0;
    }
    var_v0 = objet->unk18;

    return var_v0;
}
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
struct CBattleCharaInfo_infere_334560;
typedef struct CBattleCharaInfo_infere_334560 {
    /* 0x00 */ s16 unk0;                            /* inferred */
    /* 0x02 */ char pad2[0x2E];                     /* maybe part of unk0[0x18]void */
    /* 0x30 */ void *unk30;                         /* inferred */
} CBattleCharaInfo_infere_334560;                                 /* size >= 0x34 */
struct objet_champs_334560 {
    /* 0x0 */ s32 unk0;
    char pad4[0x2C];
    /* 0x30 */ s32 unk30;
};
struct temp_a1_champs_334560 {
    char pad0[0x24];
    /* 0x24 */ s32 unk24;
};
extern "C" s32 GetMagicSwordCounterMax__16CBattleCharaInfoFv(CBattleCharaInfo_infere_334560 *objet) {
    s16 temp_v0;
    s32 temp_v1;
    s32 var_v0;
    s32 var_v0_2;
    struct temp_a1_champs_334560 *temp_a1;

    temp_a1 = (struct temp_a1_champs_334560 *) (((struct objet_champs_334560 *) objet)->unk30);
    if (temp_a1 == NULL) {
        return 0;
    }
    if (objet->unk0 != 1) {
        return 0;
    }
    if (temp_a1 == NULL) {
        return 0;
    }
    temp_v0 = (s16) (temp_a1->unk24);
    temp_v1 = temp_v0 - 0x20;
    if (temp_v0 < 0x20) {
        return 0;
    }
    var_v0_2 = temp_v1 >> 4;
    if (temp_v1 < 0) {
        var_v0_2 = (s32) (temp_v1 + 0xF) >> 4;
    }
    var_v0 = var_v0_2 + 3;
    if (var_v0 > 7) {
        var_v0 = 7;
    }
    return var_v0;
}
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
struct CBattleCharaInfo_nowhp { char pad0[0x74]; COMMON_GAGE *unk74; };
extern "C" s32 GetDispVolumeForFloat__Ff(f32);
extern "C" s32 GetNowHp_i__16CBattleCharaInfoFv(CBattleCharaInfo_nowhp *objet) {
    COMMON_GAGE *gage = objet->unk74;
    if (gage != NULL) {
        return GetDispVolumeForFloat__Ff(((COMMON_GAGE_hp *) gage)->unk4);
    }
    return 0;
}
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
struct Force_nested { char pad[4]; f32 unk4; };
struct Force_fields { char pad0[0x74]; Force_nested *unk74; char pad78[4]; s32 unk7C; char pad80[4]; f32 unk84; char pad88[4]; s32 unk8C; };
extern "C" void ForceSet__16CBattleCharaInfoFv(Force_fields *objet) {
    Force_nested *p = objet->unk74;
    if (p != 0) {
        f32 v = p->unk4;
        if (objet->unk84 != v) {
            objet->unk84 = v;
            objet->unk8C = (s32)0xBF800000;
            objet->unk7C = 0;
        }
    }
}
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", GetRandomCircleTrapID__Fi);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", SetRandamCircleStatus__FiRf);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", StatusParamStep__16CBattleCharaInfoFPi);
INCLUDE_ASM("nonmatchings/game/cuserdatamanager", Step__16CBattleCharaInfoFv);
