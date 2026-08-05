/* CEditCollision, CWaveTable
 *
 * Unité découpée par `make carve` : 64 fonctions, 23228 octets, de
 * 0x001A2280 à 0x001A7EA0. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

INCLUDE_ASM("nonmatchings/ceditcollision", GetBattleCharaInfo__Fv);
INCLUDE_ASM("nonmatchings/ceditcollision", ConvertItemAttrToCharaAttr__FiPiPi);
INCLUDE_ASM("nonmatchings/ceditcollision", CheckBadStatus__Fi);
INCLUDE_ASM("nonmatchings/ceditcollision", CheckWeaponAttribute__FUiUi);
INCLUDE_ASM("nonmatchings/ceditcollision", CheckBuildUpMonsterCondition__FP11CDataWeapon);
INCLUDE_ASM("nonmatchings/ceditcollision", KillMonsterCount__Fii);
INCLUDE_ASM("nonmatchings/ceditcollision", SearchEquipType__Fii);
INCLUDE_ASM("nonmatchings/ceditcollision", IsItemtypeWhoisEquip__FiPi);
INCLUDE_ASM("nonmatchings/ceditcollision", IsCheckParty__Fi);
INCLUDE_ASM("nonmatchings/ceditcollision", GetAquariumFish0__Fi);
INCLUDE_ASM("nonmatchings/ceditcollision", GetUserItemHaveNum__Fi);
INCLUDE_ASM("nonmatchings/ceditcollision", CheckItemOver__Fv);
INCLUDE_ASM("nonmatchings/ceditcollision", CheckItemLimmitOver__Fv);
INCLUDE_ASM("nonmatchings/ceditcollision", CheckGetItemLimmitOver__Fii);
INCLUDE_ASM("nonmatchings/ceditcollision", CheckGetItemRemainNum__Fi);
INCLUDE_ASM("nonmatchings/ceditcollision", CheckItemDngKey__Fv);
INCLUDE_ASM("nonmatchings/ceditcollision", PlayerPartyCure__Fv);
INCLUDE_ASM("nonmatchings/ceditcollision", UserDataRefresh__Fv);
INCLUDE_ASM("nonmatchings/ceditcollision", DeleteErekiFish__Fv);
INCLUDE_ASM("nonmatchings/ceditcollision", GetNowBagMax__Fi);
INCLUDE_ASM("nonmatchings/ceditcollision", LeaveMonicaItemCheck__Fv);
INCLUDE_ASM("nonmatchings/ceditcollision", AquaFishFatigueClear__Fv);
INCLUDE_ASM("nonmatchings/ceditcollision", DebugGetItem__FP16CUserDataManageri);
INCLUDE_ASM("nonmatchings/ceditcollision", InitCharaViewerMain__F13INIT_LOOP_ARG);
INCLUDE_ASM("nonmatchings/ceditcollision", FinishCharaVieweMain__Fv);
INCLUDE_ASM("nonmatchings/ceditcollision", LoopCharaViewerMain__Fv);
INCLUDE_ASM("nonmatchings/ceditcollision", InitTextuerViewerMain__F13INIT_LOOP_ARG);
INCLUDE_ASM("nonmatchings/ceditcollision", FinishTextuerVieweMain__Fv);
INCLUDE_ASM("nonmatchings/ceditcollision", LoopTextuerViewerMain__Fv);
INCLUDE_ASM("nonmatchings/ceditcollision", MapViewInit__F13INIT_LOOP_ARG);
INCLUDE_ASM("nonmatchings/ceditcollision", MapViewExit__Fv);
INCLUDE_ASM("nonmatchings/ceditcollision", MapViewLoop__Fv);
INCLUDE_ASM("nonmatchings/ceditcollision", __ct__10CWaveTableFv);
INCLUDE_ASM("nonmatchings/ceditcollision", __dt__10CWaveTableFv);
INCLUDE_ASM("nonmatchings/ceditcollision", CreateTexture__10CWaveTableFP10mgCTexture);
INCLUDE_ASM("nonmatchings/ceditcollision", GetEffect__10CWaveTableFv);
INCLUDE_ASM("nonmatchings/ceditcollision", Effect__10CWaveTableFv);
INCLUDE_ASM("nonmatchings/ceditcollision", ClipBoxXZ__FPfPfPfPf);
INCLUDE_ASM("nonmatchings/ceditcollision", OverlapPoly3AreaXZ__FPA4_fPA4_fP9mgVu0FBOX);
INCLUDE_ASM("nonmatchings/ceditcollision", Copy__14CEditCollisionFR14CEditCollisioniP9mgCMemory);
INCLUDE_ASM("nonmatchings/ceditcollision", AreaXZ__14CEditCollisionFv);
INCLUDE_ASM("nonmatchings/ceditcollision", OverlapPoly3XZ__14CEditCollisionFPA4_fPfP9mgVu0FBOX);
INCLUDE_ASM("nonmatchings/ceditcollision", OverlapXZ__14CEditCollisionFR14CEditCollisionPA4_fP9mgVu0FBOX);
INCLUDE_ASM("nonmatchings/ceditcollision", OverlapPoly3XZ__14CEditCollisionFPA4_fPA4_fPf);
INCLUDE_ASM("nonmatchings/ceditcollision", ApplyMatrix__14CEditCollisionFPA4_f);
INCLUDE_ASM("nonmatchings/ceditcollision", DeleteVerticalPoly__14CEditCollisionFv);
INCLUDE_ASM("nonmatchings/ceditcollision", PickupVerticalPoly__14CEditCollisionFv);
INCLUDE_ASM("nonmatchings/ceditcollision", GetUserData__Fv_001A54C0);
INCLUDE_ASM("nonmatchings/ceditcollision", EditOnGround__Fv);
INCLUDE_ASM("nonmatchings/ceditcollision", IsWalkMode__Fv);
INCLUDE_ASM("nonmatchings/ceditcollision", EditControlInit__FP6CScene);
INCLUDE_ASM("nonmatchings/ceditcollision", EditControlStatusInit__FP6CScene);
INCLUDE_ASM("nonmatchings/ceditcollision", EditControl__FP6CSceneP11CPadControl);
INCLUDE_ASM("nonmatchings/ceditcollision", GetFootEffName__Fi);
INCLUDE_ASM("nonmatchings/ceditcollision", EditMoveChara__FP6CScenePfP17EditMoveCharaInfo);
INCLUDE_ASM("nonmatchings/ceditcollision", EditCameraControl__FP6CSceneP11CPadControlPA4_f);
INCLUDE_ASM("nonmatchings/ceditcollision", CharaControl__FP6CSceneP11CPadControl_001A6B90);
INCLUDE_ASM("nonmatchings/ceditcollision", CancelEyeViewMode__Fv);
INCLUDE_ASM("nonmatchings/ceditcollision", CameraControl__FP6CSceneP11CPadControl);
INCLUDE_ASM("nonmatchings/ceditcollision", InitEyeCamera__FP11CCharacter2P14CCameraControl);
INCLUDE_ASM("nonmatchings/ceditcollision", ResetViewMode__FP6CScene);
INCLUDE_ASM("nonmatchings/ceditcollision", EyeCamera__FP9mgCCameraP11CCharacter2i_001A77D0);
INCLUDE_ASM("nonmatchings/ceditcollision", InitLadder__FiP6CSceneP15CSceneEventData);
INCLUDE_ASM("nonmatchings/ceditcollision", EndLadder__Fv);
