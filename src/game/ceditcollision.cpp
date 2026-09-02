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
INCLUDE_ASM("nonmatchings/game/ceditcollision", GetUserItemHaveNum__Fi);
INCLUDE_ASM("nonmatchings/game/ceditcollision", CheckItemOver__Fv);
INCLUDE_ASM("nonmatchings/game/ceditcollision", CheckItemLimmitOver__Fv);
INCLUDE_ASM("nonmatchings/game/ceditcollision", CheckGetItemLimmitOver__Fii);
INCLUDE_ASM("nonmatchings/game/ceditcollision", CheckGetItemRemainNum__Fi);
INCLUDE_ASM("nonmatchings/game/ceditcollision", CheckItemDngKey__Fv);
INCLUDE_ASM("nonmatchings/game/ceditcollision", PlayerPartyCure__Fv);
INCLUDE_ASM("nonmatchings/game/ceditcollision", UserDataRefresh__Fv);
INCLUDE_ASM("nonmatchings/game/ceditcollision", DeleteErekiFish__Fv);
INCLUDE_ASM("nonmatchings/game/ceditcollision", GetNowBagMax__Fi);
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
INCLUDE_ASM("nonmatchings/game/ceditcollision", EditControl__FP6CSceneP11CPadControl);
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
