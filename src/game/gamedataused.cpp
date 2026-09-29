/* CGameDataUsed — un objet que le joueur porte : arme, poisson, pièce de
 * robot, boîte-cadeau. La jauge COMMON_GAGE et les aides libres qui la
 * précèdent appartiennent à la même unité.
 */

#include "common.h"

#include "gamedataused.hpp"

/* La globale que l'accesseur sert. Sa taille déclarée est celle que le découpage
 * lui donne, et c'est elle qui décide du `%gp_rel`. */
extern CGameDataUsed *FishGamePreEquip;

struct inferred;
typedef struct COMMON_GAGE_infere2 {
    /* 0x0 */ f32 unk0;                             /* inferred */
    /* 0x4 */ f32 unk4;                             /* inferred */
} COMMON_GAGE_infere2;                                      /* size >= 0x8 */
extern "C" s32 CheckFill__11COMMON_GAGEFv(COMMON_GAGE_infere2 *objet) {
    s32 var_v0;

    var_v0 = 1;
    if (objet->unk0 != objet->unk4) {
        var_v0 = 0;
    }
    return var_v0;
}
INCLUDE_ASM("nonmatchings/game/gamedataused", GetRate__11COMMON_GAGEFv);
INCLUDE_ASM("nonmatchings/game/gamedataused", SetFillRate__11COMMON_GAGEFf);
struct inferred;
typedef struct COMMON_GAGE_infere {
    /* 0x0 */ f32 unk0;                             /* inferred */
    /* 0x4 */ f32 unk4;                             /* inferred */
} COMMON_GAGE_infere;                                      /* size >= 0x8 */
extern "C" void AddPoint__11COMMON_GAGEFf(COMMON_GAGE_infere *objet, f32 arg0) {
    f32 temp_f0;
    f32 temp_f1;

    temp_f0 = (f32) (objet->unk4 + arg0);
    objet->unk4 = temp_f0;
    if (temp_f0 <= 0.0f) {
        objet->unk4 = 0.0f;
    }
    temp_f1 = (f32) (objet->unk0);
    if (temp_f1 <= objet->unk4) {
        objet->unk4 = temp_f1;
    }
}
INCLUDE_ASM("nonmatchings/game/gamedataused", AddRate__11COMMON_GAGEFf);
INCLUDE_ASM("nonmatchings/game/gamedataused", GetCommonGageRate__FP11COMMON_GAGE);
INCLUDE_ASM("nonmatchings/game/gamedataused", CalcBreedFishParam__FP14BREEDFISH_USED);
void SetFishingGamePreEquip(CGameDataUsed *data) {
    FishGamePreEquip = data;
}
INCLUDE_ASM("nonmatchings/game/gamedataused", ReEquipFishingGameWeapon__Fv);
INCLUDE_ASM("nonmatchings/game/gamedataused", CheckFishingWeapon__FP13CGameDataUsed);
INCLUDE_ASM("nonmatchings/game/gamedataused", GameDataSwap__FP13CGameDataUsedP13CGameDataUsedi);
struct ROBO_DATA;
extern "C" s32 GetUserDataMan__Fv(void);
extern "C" s32 CheckCapacity__16CUserDataManagerFv(...);
extern "C" s32 GetUseCapacity__13CGameDataUsedFv(void *);
extern "C" s32 CheckNowRoboUseCapacity__FP9ROBO_DATAPi(ROBO_DATA *arg0, s32 *arg1) {
    s32 var_s0;
    s32 var_s1;
    s32 var_s2;

    var_s2 = 0;
    var_s1 = 0;
    var_s0 = 0;
    do {
        var_s0 += GetUseCapacity__13CGameDataUsedFv((u8 *) arg0 + var_s2 + 0x30);
        var_s1 += 1;
        var_s2 += 0x6C;
    } while (var_s1 < 4);
    if (arg1 != NULL) {
        *arg1 = CheckCapacity__16CUserDataManagerFv(GetUserDataMan__Fv());
    }
    return var_s0;
}
extern "C" s32 Init__13CGameDataUsedFv(void *);
extern "C" CGameDataUsed *__ct__13CGameDataUsedFv(CGameDataUsed *objet) {
    Init__13CGameDataUsedFv(objet);
    return objet;
}
INCLUDE_ASM("nonmatchings/game/gamedataused", Init__13CGameDataUsedFv);
INCLUDE_ASM("nonmatchings/game/gamedataused", CheckTypeEnableStack__13CGameDataUsedFv);
INCLUDE_ASM("nonmatchings/game/gamedataused", GetDataPath__13CGameDataUsedFv);
INCLUDE_ASM("nonmatchings/game/gamedataused", IsWhoEquip__13CGameDataUsedFv);
INCLUDE_ASM("nonmatchings/game/gamedataused", GetLevel__13CGameDataUsedFv);
INCLUDE_ASM("nonmatchings/game/gamedataused", GetPalletColor__13CGameDataUsedFv);
INCLUDE_ASM("nonmatchings/game/gamedataused", GetSpectolNo__13CGameDataUsedFv);
INCLUDE_ASM("nonmatchings/game/gamedataused", CheckStackRemain__13CGameDataUsedFv);
INCLUDE_ASM("nonmatchings/game/gamedataused", GetNum__13CGameDataUsedFv);
INCLUDE_ASM("nonmatchings/game/gamedataused", GetActiveSetNum__13CGameDataUsedFv);
INCLUDE_ASM("nonmatchings/game/gamedataused", AddNum__13CGameDataUsedFii);
INCLUDE_ASM("nonmatchings/game/gamedataused", GetUseCapacity__13CGameDataUsedFv);
INCLUDE_ASM("nonmatchings/game/gamedataused", AddFishHp__13CGameDataUsedFi);
INCLUDE_ASM("nonmatchings/game/gamedataused", Boiled__13CGameDataUsedFv);
extern "C" s32 GetCommonItemData__Fi(s32);
struct CGameDataUsed_infere_3a34f9;
typedef struct CGameDataUsed_infere_3a34f9 {
    /* 0x0 */ char pad0[2];
    /* 0x2 */ s16 unk2;                             /* inferred */
} CGameDataUsed_infere_3a34f9;                                    /* size >= 0x4 */
struct objet_champs_3a34f9 {
    char pad0[0x2];
    /* 0x2 */ s16 unk2;
};
struct temp_v0_champs_3a34f9 {
    char pad0[0x1C];
    /* 0x1C */ s32 unk1C;
};
extern "C" u8 IsActiveSet__13CGameDataUsedFv(CGameDataUsed_infere_3a34f9 *objet) {
    struct temp_v0_champs_3a34f9 *temp_v0;

    temp_v0 = (struct temp_v0_champs_3a34f9 *) (GetCommonItemData__Fi((s32) ((struct objet_champs_3a34f9 *) objet)->unk2));
    if (temp_v0 != NULL) {
        return temp_v0->unk1C;
    }
    return 0U;
}
INCLUDE_ASM("nonmatchings/game/gamedataused", SetName__13CGameDataUsedFPc);
INCLUDE_ASM("nonmatchings/game/gamedataused", GetName__13CGameDataUsedFi);
INCLUDE_ASM("nonmatchings/game/gamedataused", TransToPassword__13CGameDataUsedFPci);
INCLUDE_ASM("nonmatchings/game/gamedataused", TransToData__13CGameDataUsedFPci);
INCLUDE_ASM("nonmatchings/game/gamedataused", DeleteNum__13CGameDataUsedFi);
INCLUDE_ASM("nonmatchings/game/gamedataused", RemainFusion__13CGameDataUsedFv);
INCLUDE_ASM("nonmatchings/game/gamedataused", AddFusionPoint__13CGameDataUsedFi);
INCLUDE_ASM("nonmatchings/game/gamedataused", GetEffectReadType__13CGameDataUsedFPPcPPcPi);
INCLUDE_ASM("nonmatchings/game/gamedataused", GetMsgAddInfo__13CGameDataUsedFPPcPPcPi);
INCLUDE_ASM("nonmatchings/game/gamedataused", GetWHp__13CGameDataUsedFPi);
INCLUDE_ASM("nonmatchings/game/gamedataused", IsRepair__13CGameDataUsedFv);
INCLUDE_ASM("nonmatchings/game/gamedataused", Repair__13CGameDataUsedFi);
INCLUDE_ASM("nonmatchings/game/gamedataused", GetEnableRepairItemNo__13CGameDataUsedFv);
extern "C" s32 GetEnableRepairItemNo__13CGameDataUsedFv(void *);
extern "C" s32 IsEnableUseRepair__13CGameDataUsedFi(CGameDataUsed *objet, s32 arg0) {
    return arg0 == GetEnableRepairItemNo__13CGameDataUsedFv(objet);
}
INCLUDE_ASM("nonmatchings/game/gamedataused", GetRoboInfoType__13CGameDataUsedFv);
INCLUDE_ASM("nonmatchings/game/gamedataused", GetRoboJointName__13CGameDataUsedFPc);
INCLUDE_ASM("nonmatchings/game/gamedataused", GetRoboSoundFileName__13CGameDataUsedFPc);
INCLUDE_ASM("nonmatchings/game/gamedataused", IsBroken__13CGameDataUsedFv);
/* L'objet est-il prêt à monter d'un niveau ? Seul le genre 3 en porte un, et il
 * plafonne à 99. La montée tient quand l'expérience acquise, arrondie comme
 * l'affichage la montre, atteint ce que la jauge réclame — c'est `CheckFill` à
 * la tolérance de l'affichage près. */
int CGameDataUsed::IsLevelUp() {
    /* Le genre se teste par un aiguillage à un seul cas, non par un `if` : la
     * différence est dans le graphe de contrôle. Un `if` fond le retour du
     * mauvais genre avec celui du niveau plafonné — MWCC hisse alors la mise à
     * zéro dans le créneau de délai et saute par-dessus le bloc nul. Le `break`
     * de l'aiguillage les garde distincts, et c'est ce que le commerce porte.
     * Mesuré sur cinquante-six formes ; seule celle-ci apparie. */
    switch (this->kind) {
    case 3:
        if (this->level < 99) {
            if (this->experience.max <= (float)GetDispVolumeForFloat(this->experience.point)) {
                return 1;
            }
        }
        break;
    }
    return 0;
}
INCLUDE_ASM("nonmatchings/game/gamedataused", LevelUp__13CGameDataUsedFv);
extern "C" s32 GetCommonItemData__Fi(s32);
struct inferred;
typedef struct CGameDataUsed_infere {
    /* 0x00 */ s16 unk0;                            /* inferred */
    /* 0x02 */ s16 unk2;                            /* inferred */
    /* 0x04 */ char pad4[0x44];                     /* maybe part of unk2[0x23]void */
    /* 0x48 */ u16 unk48;                           /* inferred */
} CGameDataUsed_infere;                                    /* size >= 0x4A */
struct temp_v0_champs {
    char pad0[0x24];
    /* 0x24 */ s32 unk24;
};
extern "C" s32 IsTrush__13CGameDataUsedFv(CGameDataUsed_infere *objet) {
    s32 var_s0;
    s32 var_v0;
    struct temp_v0_champs *temp_v0;

    var_s0 = 0;
    temp_v0 = (struct temp_v0_champs *) (GetCommonItemData__Fi((s32) objet->unk2));
    if ((temp_v0 != NULL) && (temp_v0->unk24 & 1)) {
        var_s0 = 1;
    }
    var_v0 = var_s0;
    if (objet->unk0 == 6) {
        if (objet->unk48 & 2) {
            var_s0 = 0;
        }
        var_v0 = var_s0;
    }
    return var_v0;
}
INCLUDE_ASM("nonmatchings/game/gamedataused", IsSpectolTrans__13CGameDataUsedFv);
INCLUDE_ASM("nonmatchings/game/gamedataused", ToSpectolTrans__13CGameDataUsedFP13CGameDataUsedi);
INCLUDE_ASM("nonmatchings/game/gamedataused", GetStatusParam__13CGameDataUsedFPs);
INCLUDE_ASM("nonmatchings/game/gamedataused", GetStatusParam__13CGameDataUsedFPsf);
INCLUDE_ASM("nonmatchings/game/gamedataused", IsBuildUp__13CGameDataUsedFPiPiPi);
INCLUDE_ASM("nonmatchings/game/gamedataused", IsFishingRod__13CGameDataUsedFv);
INCLUDE_ASM("nonmatchings/game/gamedataused", GetActiveElem__13CGameDataUsedFv);
INCLUDE_ASM("nonmatchings/game/gamedataused", GetAttackType__13CGameDataUsedFv);
extern "C" s32 GetWeaponInfoData__Fi(s32);
struct match;
struct CGameDataUsed_infere2_54f1f6;
typedef struct CGameDataUsed_infere2_54f1f6 {
    /* 0x0 */ s16 unk0;                             /* inferred */
    /* 0x2 */ s16 unk2;                             /* inferred */
} CGameDataUsed_infere2_54f1f6;                                    /* size >= 0x4 */
struct objet_champs_54f1f6 {
    /* 0x0 */ s16 unk0;
    /* 0x2 */ s16 unk2;
};
struct temp_v0_champs_54f1f6 {
    char pad0[0x49];
    /* 0x49 */ s8 unk49;
};
extern "C" s8 GetModelNo__13CGameDataUsedFv(CGameDataUsed_infere2_54f1f6 *objet) {
    struct temp_v0_champs_54f1f6 *temp_v0;

    if (((struct objet_champs_54f1f6 *) objet)->unk0 == 3) {
        temp_v0 = (struct temp_v0_champs_54f1f6 *) (GetWeaponInfoData__Fi((s32) ((struct objet_champs_54f1f6 *) objet)->unk2));
        if (temp_v0 != NULL) {
            return temp_v0->unk49;
        }
        /* Duplicate return node #4. Try simplifying control flow for better match */
        return -1;
    }
    return -1;
}
INCLUDE_ASM("nonmatchings/game/gamedataused", GetMainCharaModelName__FiPci);
INCLUDE_ASM("nonmatchings/game/gamedataused", CheckParamLimmit__13CGameDataUsedFv);
typedef struct CGameDataUsed_infere3 {
    /* 0x00 */ s16 unk0;                            /* inferred */
    /* 0x02 */ char pad2[0x3E];                     /* maybe part of unk0[0x20]void */
    /* 0x40 */ u16 unk40;                           /* inferred */
} CGameDataUsed_infere3;                                    /* size >= 0x42 */
extern "C" void TimeCheck__13CGameDataUsedFi(CGameDataUsed_infere3 *objet, s32 arg0) {
    s32 var_v1;

    if (objet->unk0 == 6) {
        var_v1 = (s32) (objet->unk40 - arg0);
        if (var_v1 < 0) {
            var_v1 = 0;
        }
        objet->unk40 = (u16) var_v1;
    }
}
INCLUDE_ASM("nonmatchings/game/gamedataused", GetGiftBoxItemNum__13CGameDataUsedFv);
INCLUDE_ASM("nonmatchings/game/gamedataused", SetGiftBoxItem__13CGameDataUsedFii);
INCLUDE_ASM("nonmatchings/game/gamedataused", GetGiftBoxItemNo__13CGameDataUsedFi);
INCLUDE_ASM("nonmatchings/game/gamedataused", GetGiftBoxSameItemNum__13CGameDataUsedFi);
INCLUDE_ASM("nonmatchings/game/gamedataused", CopyGameData__13CGameDataUsedFP13CGameDataUsed);
INCLUDE_ASM("nonmatchings/game/gamedataused", CopyDataWeapon__13CGameDataUsedFi);
extern "C" u8 GameItemDataManage[48];
extern "C" s32 GetAttachData__9CGameDataFi(void *, s32);
struct CGameDataUsed_infere2_9617c4;
typedef struct CGameDataUsed_infere2_9617c4 {
    /* 0x00 */ s16 unk0;                            /* inferred */
    /* 0x02 */ s16 unk2;                            /* inferred */
    /* 0x04 */ s8 unk4;                             /* inferred */
    /* 0x05 */ char pad5[0xD];                      /* maybe part of unk4[0xE]void */
    /* 0x12 */ s16 unk12;                           /* inferred */
    /* 0x14 */ s16 unk14;                           /* inferred */
    /* 0x16 */ s16 unk16;                           /* inferred */
    /* 0x18 */ s16 unk18;                           /* inferred */
    /* 0x1A */ s16 unk1A;                           /* inferred */
    /* 0x1C */ s16 unk1C;                           /* inferred */
    /* 0x1E */ s16 unk1E;                           /* inferred */
    /* 0x20 */ s16 unk20;                           /* inferred */
    /* 0x22 */ s16 unk22;                           /* inferred */
    /* 0x24 */ s16 unk24;                           /* inferred */
    /* 0x26 */ char pad26[6];                       /* maybe part of unk24[4]void */
    /* 0x2C */ s32 unk2C;                           /* inferred */
    /* 0x30 */ char pad30[0x1A];                    /* maybe part of unk2C[7]void */
    /* 0x4A */ s16 unk4A;                           /* inferred */
} CGameDataUsed_infere2_9617c4;                                    /* size >= 0x4C */
struct temp_v0_champs_9617c4 {
    /* 0x0 */ s16 unk0;
    /* 0x2 */ s16 unk2;
    /* 0x4 */ s16 unk4;
    /* 0x6 */ s16 unk6;
    /* 0x8 */ s16 unk8;
    /* 0xA */ s16 unkA;
    /* 0xC */ s16 unkC;
    /* 0xE */ s16 unkE;
    /* 0x10 */ s16 unk10;
    /* 0x12 */ s16 unk12;
    /* 0x14 */ s32 unk14;
};
extern "C" s32 GetItemDataType__Fi(s32);
extern "C" s32 AddNum__13CGameDataUsedFii(void *, s32, s32);
extern "C" s32 CheckTypeEnableStack__13CGameDataUsedFv(void *);
extern "C" s32 CopyDataAttach__13CGameDataUsedFi(CGameDataUsed_infere2_9617c4 *objet, s32 arg0) {
    struct temp_v0_champs_9617c4 *temp_v0;

    temp_v0 = (struct temp_v0_champs_9617c4 *) (GetAttachData__9CGameDataFi(&GameItemDataManage, arg0));
    if (temp_v0 == NULL) {
        return 0;
    }
    if (arg0 == objet->unk2) {
        if (CheckTypeEnableStack__13CGameDataUsedFv(objet) != 0) {
            AddNum__13CGameDataUsedFii(objet, 1, 1);
            return 1;
        }
        goto block_6;
    }
block_6:
    objet->unk0 = 2;
    objet->unk2 = (s16) arg0;
    objet->unk4 = GetItemDataType__Fi(arg0);
    objet->unk12 = temp_v0->unk0;
    objet->unk14 = temp_v0->unk2;
    objet->unk16 = temp_v0->unk4;
    objet->unk18 = temp_v0->unk6;
    objet->unk1A = temp_v0->unk8;
    objet->unk1C = temp_v0->unkA;
    objet->unk1E = temp_v0->unkC;
    objet->unk20 = temp_v0->unkE;
    objet->unk22 = temp_v0->unk10;
    objet->unk24 = temp_v0->unk12;
    objet->unk2C = 0;
    objet->unk2C |= temp_v0->unk14;
    objet->unk4A = 1;
    return 1;
}
INCLUDE_ASM("nonmatchings/game/gamedataused", CopyDataItem__13CGameDataUsedFi);
INCLUDE_ASM("nonmatchings/game/gamedataused", CopyDataFish__13CGameDataUsedFi);
typedef struct CGameDataUsed_infere2 {
    /* 0x00 */ s16 unk0;                            /* inferred */
    /* 0x02 */ s16 unk2;                            /* inferred */
    /* 0x04 */ s8 unk4;                             /* inferred */
    /* 0x05 */ char pad5[0xB];                      /* maybe part of unk4[0xC]void */
    /* 0x10 */ s16 unk10;                           /* inferred */
    /* 0x12 */ s16 unk12;                           /* inferred */
    /* 0x14 */ s16 unk14;                           /* inferred */
} CGameDataUsed_infere2;                                    /* size >= 0x16 */
extern "C" s32 GetItemDataType__Fi(s32);
extern "C" s32 GetItemInfoData__Fi(s32);
extern "C" s32 CopyDataGiftBox__13CGameDataUsedFi(CGameDataUsed_infere2 *objet, s32 arg0) {
    if (GetItemInfoData__Fi(arg0) == 0) {
        return 0;
    }
    objet->unk0 = 7;
    objet->unk2 = (s16) arg0;
    objet->unk4 = GetItemDataType__Fi(arg0);
    objet->unk14 = 0;
    objet->unk12 = 0;
    objet->unk10 = 0;
    return 1;
}
INCLUDE_ASM("nonmatchings/game/gamedataused", CopyDataItem__13CGameDataUsedFP13CGameDataUsed);
INCLUDE_ASM("nonmatchings/game/gamedataused", CopyDataRoboPart__13CGameDataUsedFi);
