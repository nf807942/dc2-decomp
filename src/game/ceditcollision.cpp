/* CEditCollision, CWaveTable
 *
 * Unité découpée par `make carve` : 64 fonctions, 23228 octets, de
 * 0x001A2280 à 0x001A7EA0. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

/* Les globales que ces accesseurs servent. Leur taille déclarée est celle que
 * le découpage leur donne, et c'est elle qui décide du `%gp_rel`. */
extern s32 LadderMode;
extern s32 EyeViewCancelOnce;


extern "C" u8 BattleParamater[];
extern "C" void *GetBattleCharaInfo__Fv(void) {
    return BattleParamater;
}
extern "C" void ConvertItemAttrToCharaAttr__FiPiPi(s32 arg0, s32 *arg1, s32 *arg2) {
    s32 var_v1;
    s32 var_a3;

    var_v1 = 0;
    var_a3 = 0;
    if (arg0 & 0x10000) {
        var_v1 |= 1;
    }
    if (arg0 & 0x100000) {
        var_v1 |= 2;
    }
    if (arg0 & 0x40000) {
        var_v1 |= 4;
    }
    if (arg0 & 0x4000) {
        var_v1 |= 8;
    }
    if (arg0 & 0x400000) {
        var_v1 |= 0x10;
    }
    if (arg0 & 0x02000000) {
        var_v1 |= 0x20;
    }
    if (arg0 & 0x08000000) {
        var_v1 |= 0x40;
    }
    if (arg0 & 0x20000) {
        var_a3 |= 1;
    }
    if (arg0 & 0x200000) {
        var_a3 |= 2;
    }
    if (arg0 & 0x80000) {
        var_a3 |= 4;
    }
    if (arg0 & 0x8000) {
        var_a3 |= 8;
    }
    if (arg0 & 0x04000000) {
        var_a3 |= 0x20;
    }
    if (arg0 & 0x10000000) {
        var_a3 |= 0x40;
    }
    if (arg1 != NULL) {
        *arg1 = var_v1;
    }
    if (arg2 != NULL) {
        *arg2 = var_a3;
    }
}
extern "C" s32 CheckBadStatus__Fi(s32 arg0) {
    if ((arg0 & 1) || (arg0 & 2) || (arg0 & 4) || (arg0 & 8) || (arg0 & 0x20) || (arg0 & 0x40)) {
        return 1;
    }
    return 0;
}
INCLUDE_ASM("nonmatchings/game/ceditcollision", CheckWeaponAttribute__FUiUi);
INCLUDE_ASM("nonmatchings/game/ceditcollision", CheckBuildUpMonsterCondition__FP11CDataWeapon);
INCLUDE_ASM("nonmatchings/game/ceditcollision", KillMonsterCount__Fii);
INCLUDE_ASM("nonmatchings/game/ceditcollision", SearchEquipType__Fii);
INCLUDE_ASM("nonmatchings/game/ceditcollision", IsItemtypeWhoisEquip__FiPi);
extern "C" s32 GetUserDataMan__Fv(void);
extern "C" s32 GetNowPartyMember__16CUserDataManagerFv(...);
extern "C" s32 IsCheckParty__Fi(s32 arg0) {
    s32 party = GetNowPartyMember__16CUserDataManagerFv(GetUserDataMan__Fv());
    return (party & (1 << arg0)) != 0;
}
INCLUDE_ASM("nonmatchings/game/ceditcollision", GetAquariumFish0__Fi);
extern "C" s32 GetUserDataMan__Fv(void);
#include "dngfloormanager.hpp"
extern "C" s32 GetNumSameItem__16CUserDataManagerFi(void *, s32);
extern "C" s32 GetUserItemHaveNum__Fi(s32 arg0) {
    CUserDataManager *temp_v0;

    temp_v0 = (CUserDataManager *) (GetUserDataMan__Fv());
    if (temp_v0 != NULL) {
        return GetNumSameItem__16CUserDataManagerFi(temp_v0, arg0);
    }
    return 0;
}
INCLUDE_ASM("nonmatchings/game/ceditcollision", CheckItemOver__Fv);
extern "C" s32 CheckItemLimmitOver__16CUserDataManagerFv(void *);
extern "C" s32 CheckItemLimmitOver__Fv(void) {
    CUserDataManager *temp_v0;

    temp_v0 = (CUserDataManager *) (GetUserDataMan__Fv());
    if (temp_v0 != NULL) {
        return CheckItemLimmitOver__16CUserDataManagerFv(temp_v0);
    }
    return 0;
}
INCLUDE_ASM("nonmatchings/game/ceditcollision", CheckGetItemLimmitOver__Fii);
INCLUDE_ASM("nonmatchings/game/ceditcollision", CheckGetItemRemainNum__Fi);
INCLUDE_ASM("nonmatchings/game/ceditcollision", CheckItemDngKey__Fv);
INCLUDE_ASM("nonmatchings/game/ceditcollision", PlayerPartyCure__Fv);
extern "C" s32 RefreshParam__16CUserDataManagerFv(void *);
extern "C" void UserDataRefresh__Fv(void) {
    CUserDataManager *temp_v0;

    temp_v0 = (CUserDataManager *) (GetUserDataMan__Fv());
    if (temp_v0 != NULL) {
        RefreshParam__16CUserDataManagerFv(temp_v0);
    }
}
extern "C" s32 GetAquariumData__Fv(void);
struct FishEntry {
    char pad0[0x2];
    /* 0x2 */ s16 unk2;
    char pad4[0x44];
    /* 0x48 */ u16 unk48;
};
extern "C" s32 GetAquariumFishTop__13CFishAquariumFi(void *, s32);
extern "C" s32 Init__13CGameDataUsedFv(...);
extern "C" void DeleteErekiFish__Fv(void) {
    void *aquarium;
    s32 fish_top;
    s32 i;
    s32 off;
    struct FishEntry *entry;

    aquarium = (void *) (GetAquariumData__Fv());
    if (aquarium == NULL) {
        return;
    }
    fish_top = (s32) (GetAquariumFishTop__13CFishAquariumFi(aquarium, 0));
    i = 0;
    off = 0;
    do {
        entry = (struct FishEntry *) (fish_top + off);
        if ((entry->unk2 > 0) && (entry->unk48 & 2)) {
            Init__13CGameDataUsedFv(fish_top + (i * 0x6C));
            return;
        }
        i += 1;
        off += 0x6C;
    } while (i < 6);
}
extern "C" s32 GetItemBoardMaxNum__16CUserDataManagerFi(...);
extern "C" void GetNowBagMax__Fi(s32 arg0) {
    GetItemBoardMaxNum__16CUserDataManagerFi(GetUserDataMan__Fv(), arg0);
}
extern "C" s32 SearchItemOnItemBrd__16CUserDataManagerFii(void *, s32, s32);
extern "C" s32 SearchSpaceUsedDataPtr__16CUserDataManagerFv(void *);
#include "gamedataused.hpp"
struct temp_v0_3_champs_83b64c {
    char pad0[0x2E];
    /* 0x2E */ s16 unk2E;
};
extern "C" s32 AddNum__13CGameDataUsedFii(void *, s32, s32);
extern "C" s32 CheckTypeEnableStack__13CGameDataUsedFv(void *);
extern "C" s32 CopyGameData__13CGameDataUsedFP13CGameDataUsed(void *, CGameDataUsed *);
extern "C" s32 GetCharaDataPtr__16CUserDataManagerFi(void *, s32);
extern "C" s32 GetNum__13CGameDataUsedFv(void *);
extern "C" void LeaveMonicaItemCheck__Fv(void) {
    CUserDataManager *temp_v0;
    s32 temp_s1;
    s32 var_s2;
    s32 temp_s3;
    CGameDataUsed *temp_s3_2;
    CGameDataUsed *temp_s4;
    s32 var_s5;
    CGameDataUsed *temp_s6;
    s32 temp_v0_2;
    struct temp_v0_3_champs_83b64c *temp_v0_3;

    temp_v0 = (CUserDataManager *) (GetUserDataMan__Fv());
    if (temp_v0 != NULL) {
        temp_v0_2 = (s32) (GetCharaDataPtr__16CUserDataManagerFi(temp_v0, 1));
        var_s2 = 0;
        if (temp_v0_2 != 0) {
            var_s5 = 0;
            do {
                temp_v0_3 = (struct temp_v0_3_champs_83b64c *) (temp_v0_2 + var_s5);
                temp_s3 = (s16) (temp_v0_3->unk2E);
                temp_s6 = (CGameDataUsed *) (((struct temp_v0_3_champs_83b64c *) ((u8 *) temp_v0_3 + 0x2C)));
                temp_s1 = (s32) (GetNum__13CGameDataUsedFv(temp_s6));
                if ((temp_s3 > 0) && (temp_s1 > 0)) {
                    temp_s3_2 = (CGameDataUsed *) (SearchItemOnItemBrd__16CUserDataManagerFii(temp_v0, (s32) temp_s3, 0));
                    temp_s4 = (CGameDataUsed *) (SearchSpaceUsedDataPtr__16CUserDataManagerFv(temp_v0));
                    if (temp_s3_2 != NULL) {
                        if (CheckTypeEnableStack__13CGameDataUsedFv(temp_s3_2) == 0) {
                            if (temp_s4 != NULL) {
                                CopyGameData__13CGameDataUsedFP13CGameDataUsed(temp_s4, temp_s6);
                                Init__13CGameDataUsedFv(temp_s6);
                            }
                        } else {
                            AddNum__13CGameDataUsedFii(temp_s3_2, temp_s1, 1);
                            Init__13CGameDataUsedFv(temp_s6);
                        }
                    } else if (temp_s4 != NULL) {
                        CopyGameData__13CGameDataUsedFP13CGameDataUsed(temp_s4, temp_s6);
                        Init__13CGameDataUsedFv(temp_s6);
                    }
                }
                var_s2 += 1;
                var_s5 += 0x6C;
            } while (var_s2 < 3);
        }
    }
}
INCLUDE_ASM("nonmatchings/game/ceditcollision", AquaFishFatigueClear__Fv);
INCLUDE_ASM("nonmatchings/game/ceditcollision", DebugGetItem__FP16CUserDataManageri);
extern "C" void InitCharaViewerMain__F13INIT_LOOP_ARG(s32 arg0) {
}
void FinishCharaVieweMain(void) {
}
s32 LoopCharaViewerMain(void) {
    return 1;
}
extern "C" void InitTextuerViewerMain__F13INIT_LOOP_ARG(s32 arg0) {
}
void FinishTextuerVieweMain(void) {
}
s32 LoopTextuerViewerMain(void) {
    return 1;
}
extern "C" void MapViewInit__F13INIT_LOOP_ARG(s32 arg0) {
}
void MapViewExit(void) {
}
s32 MapViewLoop(void) {
    return 1;
}
INCLUDE_ASM("nonmatchings/game/ceditcollision", __ct__10CWaveTableFv);
extern "C" u8 __vt__10CWaveTable[12];
struct CWaveTableDt {
    /* 0x0000 */ char pad0[0x1204];
    /* 0x1204 */ void *unk1204;
};
extern "C" s32 __dl__FPv(void *);
extern "C" CWaveTableDt *__dt__10CWaveTableFv(CWaveTableDt *objet, s16 destroyFlag) {
    if (objet != NULL) {
        objet->unk1204 = &__vt__10CWaveTable;
        if (destroyFlag > 0) {
            __dl__FPv(objet);
        }
    }
    return objet;
}
INCLUDE_ASM("nonmatchings/game/ceditcollision", CreateTexture__10CWaveTableFP10mgCTexture);
INCLUDE_ASM("nonmatchings/game/ceditcollision", GetEffect__10CWaveTableFv);
INCLUDE_ASM("nonmatchings/game/ceditcollision", Effect__10CWaveTableFv);
INCLUDE_ASM("nonmatchings/game/ceditcollision", ClipBoxXZ__FPfPfPfPf);
INCLUDE_ASM("nonmatchings/game/ceditcollision", OverlapPoly3AreaXZ__FPA4_fPA4_fP9mgVu0FBOX);
INCLUDE_ASM("nonmatchings/game/ceditcollision", Copy__14CEditCollisionFR14CEditCollisioniP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/ceditcollision", AreaXZ__14CEditCollisionFv);
INCLUDE_ASM("nonmatchings/game/ceditcollision", OverlapPoly3XZ__14CEditCollisionFPA4_fPfP9mgVu0FBOX);
INCLUDE_ASM("nonmatchings/game/ceditcollision", OverlapXZ__14CEditCollisionFR14CEditCollisionPA4_fP9mgVu0FBOX);
INCLUDE_ASM("nonmatchings/game/ceditcollision", OverlapPoly3XZ__14CEditCollisionFPA4_fPA4_fPf);
INCLUDE_ASM("nonmatchings/game/ceditcollision", ApplyMatrix__14CEditCollisionFPA4_f);
INCLUDE_ASM("nonmatchings/game/ceditcollision", DeleteVerticalPoly__14CEditCollisionFv);
INCLUDE_ASM("nonmatchings/game/ceditcollision", PickupVerticalPoly__14CEditCollisionFv);
extern "C" s32 GetSaveData__Fv(void);
extern "C" s32 GetUserData__Fv_001A54C0(void) {
    s32 temp_v0;

    temp_v0 = GetSaveData__Fv();
    if (temp_v0 != 0) {
        return (s32) ((u8 *) temp_v0 + 0x1D2A0);
    }
    return 0;
}
extern "C" s32 CharaFallFlag;
extern "C" u32 CharaMotionMode;
extern "C" s32 EditOnGround__Fv(void) {
    if (CharaFallFlag > 0) {
        return 0;
    }
    if (CharaMotionMode != 0) {
        return 0;
    }
    return (LadderMode != 0) ^ 1;
}
extern "C" s32 ViewMode;
extern "C" s32 IsWalkMode__Fv(void) {
    return ViewMode == 0;
}
INCLUDE_ASM("nonmatchings/game/ceditcollision", EditControlInit__FP6CScene);
extern "C" u32 CharaMotionModeCnt;
extern "C" u32 FixCameraChgCnt;
extern "C" s32 GetCharacter__6CSceneFi(void *, s32);
extern "C" char _962_0036A400[];
struct CSceneStatusInit {
    /* 0x0000 */ char pad0[0x2E50];
    /* 0x2E50 */ s32 unk2E50;
};
/* Les virtuelles muettes amènent SetMotion et Idle aux rangs 43 (0xB0) et 52
 * (0xD4) de la table ; l'appel passe alors par $t9. */
class StatusInitChara {
public:
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void SetMotion(char *name, s32 arg);
    virtual void w45();
    virtual void w46();
    virtual void w47();
    virtual void w48();
    virtual void w49();
    virtual void w50();
    virtual void w51();
    virtual void w52();
    virtual void Idle();
    char pad4[0x80];
    s32 unk84;
};
extern "C" void EditControlStatusInit__FP6CScene(CSceneStatusInit *arg0) {
    StatusInitChara *temp_v0;

    LadderMode = 0;
    CharaMotionMode = 0;
    CharaMotionModeCnt = 0;
    CharaFallFlag = 0;
    FixCameraChgCnt = 0;
    temp_v0 = (StatusInitChara *) (GetCharacter__6CSceneFi(arg0, arg0->unk2E50));
    if (temp_v0 != NULL) {
        temp_v0->SetMotion(_962_0036A400, 4);
        temp_v0->unk84 = 0;
        temp_v0->Idle();
    }
}
struct CPadControl {
    f32 field_0;
    f32 field_4;
    f32 field_8;
    f32 field_C;
};
struct inferred;
typedef struct CScene {
    /* 0x0000 */ char pad0[0x2E88];
    /* 0x2E88 */ s32 unk2E88;                       /* inferred */
} CScene;                                           /* size >= 0x2E8C */
extern "C" s32 LadderControl__FP6CSceneP11CPadControl(CScene *, CPadControl *);
extern "C" s32 CameraControl__FP6CSceneP11CPadControl(CScene *, CPadControl *);
extern "C" s32 CharaControl__FP6CSceneP11CPadControl_001A6B90(...);
extern "C" s32 EditControl__FP6CSceneP11CPadControl(CScene *arg0, CPadControl *arg1) {
    CPadControl *var_s0;

    var_s0 = (CPadControl *) (arg1);
    if (LadderMode != 0) {
        LadderControl__FP6CSceneP11CPadControl(arg0, arg1);
    } else {
        CharaControl__FP6CSceneP11CPadControl_001A6B90();
        if (arg0->unk2E88 != 0) {
            var_s0 = (CPadControl *) (NULL);
        }
        CameraControl__FP6CSceneP11CPadControl(arg0, var_s0);
    }
    return 0;
}
INCLUDE_ASM("nonmatchings/game/ceditcollision", GetFootEffName__Fi);
INCLUDE_ASM("nonmatchings/game/ceditcollision", EditMoveChara__FP6CScenePfP17EditMoveCharaInfo);
INCLUDE_ASM("nonmatchings/game/ceditcollision", EditCameraControl__FP6CSceneP11CPadControlPA4_f);
INCLUDE_ASM("nonmatchings/game/ceditcollision", CharaControl__FP6CSceneP11CPadControl_001A6B90);
void CancelEyeViewMode(void) {
    EyeViewCancelOnce = 1;
}
INCLUDE_ASM("nonmatchings/game/ceditcollision", CameraControl__FP6CSceneP11CPadControl);
INCLUDE_ASM("nonmatchings/game/ceditcollision", InitEyeCamera__FP11CCharacter2P14CCameraControl);
INCLUDE_ASM("nonmatchings/game/ceditcollision", ResetViewMode__FP6CScene);
INCLUDE_ASM("nonmatchings/game/ceditcollision", EyeCamera__FP9mgCCameraP11CCharacter2i_001A77D0);
INCLUDE_ASM("nonmatchings/game/ceditcollision", InitLadder__FiP6CSceneP15CSceneEventData);
void EndLadder(void) {
    LadderMode = 0;
}
