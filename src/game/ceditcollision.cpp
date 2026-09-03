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


INCLUDE_ASM("nonmatchings/game/ceditcollision", GetBattleCharaInfo__Fv);
INCLUDE_ASM("nonmatchings/game/ceditcollision", ConvertItemAttrToCharaAttr__FiPiPi);
INCLUDE_ASM("nonmatchings/game/ceditcollision", CheckBadStatus__Fi);
INCLUDE_ASM("nonmatchings/game/ceditcollision", CheckWeaponAttribute__FUiUi);
INCLUDE_ASM("nonmatchings/game/ceditcollision", CheckBuildUpMonsterCondition__FP11CDataWeapon);
INCLUDE_ASM("nonmatchings/game/ceditcollision", KillMonsterCount__Fii);
INCLUDE_ASM("nonmatchings/game/ceditcollision", SearchEquipType__Fii);
INCLUDE_ASM("nonmatchings/game/ceditcollision", IsItemtypeWhoisEquip__FiPi);
INCLUDE_ASM("nonmatchings/game/ceditcollision", IsCheckParty__Fi);
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
INCLUDE_ASM("nonmatchings/game/ceditcollision", DeleteErekiFish__Fv);
extern "C" s32 GetItemBoardMaxNum__16CUserDataManagerFi(...);
extern "C" void GetNowBagMax__Fi(s32 arg0) {
    GetItemBoardMaxNum__16CUserDataManagerFi(GetUserDataMan__Fv(), arg0);
}
INCLUDE_ASM("nonmatchings/game/ceditcollision", LeaveMonicaItemCheck__Fv);
INCLUDE_ASM("nonmatchings/game/ceditcollision", AquaFishFatigueClear__Fv);
INCLUDE_ASM("nonmatchings/game/ceditcollision", DebugGetItem__FP16CUserDataManageri);
INCLUDE_ASM("nonmatchings/game/ceditcollision", InitCharaViewerMain__F13INIT_LOOP_ARG);
void FinishCharaVieweMain(void) {
}
s32 LoopCharaViewerMain(void) {
    return 1;
}
INCLUDE_ASM("nonmatchings/game/ceditcollision", InitTextuerViewerMain__F13INIT_LOOP_ARG);
void FinishTextuerVieweMain(void) {
}
s32 LoopTextuerViewerMain(void) {
    return 1;
}
INCLUDE_ASM("nonmatchings/game/ceditcollision", MapViewInit__F13INIT_LOOP_ARG);
void MapViewExit(void) {
}
s32 MapViewLoop(void) {
    return 1;
}
INCLUDE_ASM("nonmatchings/game/ceditcollision", __ct__10CWaveTableFv);
INCLUDE_ASM("nonmatchings/game/ceditcollision", __dt__10CWaveTableFv);
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
INCLUDE_ASM("nonmatchings/game/ceditcollision", GetUserData__Fv_001A54C0);
INCLUDE_ASM("nonmatchings/game/ceditcollision", EditOnGround__Fv);
INCLUDE_ASM("nonmatchings/game/ceditcollision", IsWalkMode__Fv);
INCLUDE_ASM("nonmatchings/game/ceditcollision", EditControlInit__FP6CScene);
INCLUDE_ASM("nonmatchings/game/ceditcollision", EditControlStatusInit__FP6CScene);
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
