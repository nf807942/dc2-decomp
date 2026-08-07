/* CEditMap, CCameraControl, CEditEvent, CPadControl, CMenuSystemData
 *
 * Unité découpée par `make carve` : 70 fonctions, 22128 octets, de
 * 0x002F0E80 à 0x002F6690. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", __ct__14CCameraControlFv);
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", GetActiveParam__14CCameraControlFv);
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", SetRotCameraCancel__14CCameraControlFi);
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", BitSetRotCameraCancel__14CCameraControlFi);
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", BitResetRotCameraCancel__14CCameraControlFi);
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", InitStatus__14CCameraControlFv);
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", ControlOn__14CCameraControlFv);
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", ControlOff__14CCameraControlFv);
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", Stay__14CCameraControlFv);
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", Step__14CCameraControlFi);
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", MoveCamera__14CCameraControlFP11CPadControlPfP6CCPolyi);
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", MoveCamera__14CCameraControlFPQ214CCameraControl7ControlPfP6CCPolyi);
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", Rotate__14CCameraControlFf);
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", SetRotate__14CCameraControlFf);
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", SetHeight__14CCameraControlFf);
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", RotBack__14CCameraControlFf);
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", CancelRotBack__14CCameraControlFv);
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", SetCheckRef__14CCameraControlFPf);
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", SetCheckRef__14CCameraControlFfff);
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", CheckCollision__14CCameraControlFP6CCPolyi);
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", AutoMove__14CCameraControlFP6CCPolyi);
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", CheckGround__14CCameraControlFP6CCPolyi);
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", GetCameraMatrix__14CCameraControlFPA4_f);
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", CopyParam__14CCameraControlFR14CCameraControl);
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", Iam__14CCameraControlFv);
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", Initialize__11CPadControlFv);
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", RegisterBtn__11CPadControlFiii);
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", RegisterAnalog__11CPadControlFii);
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", Btn__11CPadControlFi);
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", Analog__11CPadControlFi);
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", Update__11CPadControlFP8CGamePad);
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", PlaneNormalXZ__FPfPfPfPf);
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", GetEditPartsAlt__8CEditMapFP14CEditPartsInfoPffPP10CEditPartsi);
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", CheckEditParts__8CEditMapFP14CEditPartsInfoPffP13EP_PLACE_INFOPP10CEditPartsi);
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", CheckEditPartsOnRiver__8CEditMapFP14CEditPartsInfoPff);
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", CheckRiverParts__8CEditMapFPf);
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", CheckNormalPlaceParts__8CEditMapFi);
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", CheckNormalPlaceParts__8CEditMapFP10CEditParts);
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", CheckLiveNPC__8CEditMapFii);
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", GetePlacePartsAtInfoID__8CEditMapFiPii);
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", GetTerritoryParts__8CEditMapFiPii);
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", GetChildParts__8CEditMapFiPii);
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", RePaintNum__8CEditMapFi);
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", PaintFence__8CEditMapFiPfi);
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", CheckFenceChain__FP10CEditPartsP10CEditParts);
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", PaintFence__8CEditMapFP10CEditParts);
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", UpdateHouse__8CEditMapFv);
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", GroundBalance__8CEditMapFi);
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", BalanceCheck__8CEditMapFv);
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", InScreenFunc__8CEditMapFP16InScreenFuncInfo);
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", DrawScreenFunc__8CEditMapFP8mgCFrame);
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", GetSeSrcVolPan__8CEditMapFPiPfPfi);
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", Reset__10CEditEventFv);
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", StartEvent__10CEditEventFP15CSceneEventData);
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", Step__10CEditEventFP6CScene);
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", Draw__10CEditEventFP6CScene);
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", GeoramaFunc__FP12GeoFuncParamP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", CheckPlaceBurnParts__FP12GeoFuncParamP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", LoadIntNPC__FP12GeoFuncParamP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", LoadGeoNPC__FP12GeoFuncParami);
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", GeoUpdateNpcPos__FP6CScene);
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", __ct__15CMenuSystemDataFv);
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", MenuSystemDataInit__15CMenuSystemDataFv);
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", CheckGetAlready__15CMenuSystemDataFi);
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", GetGhobi__15CMenuSystemDataFi);
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", CopyMCBrowserName__FiPcPUs);
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", SetDngTreeFlag__Fi);
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", MakeMemoryCardFileName__FiPc);
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", MakeMemoryCardAlbumName__FPci);
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", MakeCheckDigit__FiPci);
