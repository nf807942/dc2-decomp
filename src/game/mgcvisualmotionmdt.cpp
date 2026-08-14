/* mgCVisualMotionMDT, CTreasureBoxManager, CStartupEpisodeTitle, CRandomCircle, MessageTaskManager, CGeoStone, CTreasureBox, CRedMarkModel, mgVertexWeight, CSound
 *
 * Unité découpée par `make carve` : 98 fonctions, 24196 octets, de
 * 0x0028D160 à 0x002931B0. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

/* Le corps ne rend qu'un code : ni la classe ni les arguments ne sont
 * déréférencés, donc leur disposition reste à établir. */
class mgCVisualMotionMDT {
public:
    s32 Iam();
};

s32 LoadFileSocket(char *path, u32 *size) {
    return 0;
}
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", WriteFileSocket__FPcPUii);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", Initialize__18mgCVisualMotionMDTFv);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", CreateVertexWeight__18mgCVisualMotionMDTFPUiiP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", __ct__14mgVertexWeightFv);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", ChangeWeight__18mgCVisualMotionMDTFPP8mgCFramePA4_A4_fi);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", DataAssignMotionMDT__18mgCVisualMotionMDTFP10MDT_HEADERP14mgCVMotionDataP9mgCMemoryP9mgCMemoryP17mgCTextureManager);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", SetData0__FiiPPiP1P1P1P1P1P14mgVertexWeight);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", SetData1__FiiPPiP1P1P1P1P1P14mgVertexWeight);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", SetData2__FiiPPiP1P1P1P1P1P14mgVertexWeight);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", SetData3__FiiPPiP1P1P1P1P1P14mgVertexWeight);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", SetData4__FiiPPiP1P1P1P1P1P14mgVertexWeight);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", SetData5__FiiPPiP1P1P1P1P1P14mgVertexWeight);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", SetData6__FiiPPiP1P1P1P1P1P14mgVertexWeight);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", SetData7__FiiPPiP1P1P1P1P1P14mgVertexWeight);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", CreateFaceMotionPacket__18mgCVisualMotionMDTFPUiP7mgCFaceP14mgCVMotionData);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", CreateRenderInfoPacket__18mgCVisualMotionMDTFPUiPA4_fP13mgRENDER_INFO);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", CreateExtRenderInfoPacket__18mgCVisualMotionMDTFPUiPA4_fP13mgRENDER_INFO);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", SetBaseBox__18mgCVisualMotionMDTFPfPf);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", CreateBBox__18mgCVisualMotionMDTFPfPfPA4_f);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", Copy__18mgCVisualMotionMDTFP9mgCMemory);
s32 mgCVisualMotionMDT::Iam(void) {
    return 3;
}
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", ezBgmInit__Fv);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", ezBgm__Fii);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", StreamOpenState__6CSoundFv);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", DrawEpisode__20CStartupEpisodeTitleFii);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", Switch__20CStartupEpisodeTitleFi);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", Step__20CStartupEpisodeTitleFv);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", Initialize__20CStartupEpisodeTitleFv);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", Draw__18MessageTaskManagerFv);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", Step__18MessageTaskManagerFv);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", Print__18MessageTaskManagerFPciii);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", Clear__18MessageTaskManagerFv);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", Initialize__18MessageTaskManagerFv);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", Draw__13CRedMarkModelFv);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", Step__13CRedMarkModelFv);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", GeoDraw__9CGeoStoneFPf);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", DrawMiniMapSymbol__9CGeoStoneFP14CMiniMapSymbol);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", SetFlag__9CGeoStoneFi);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", GeoStep__9CGeoStoneFv);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", CheckEvent__9CGeoStoneFPf);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", Initialize__9CGeoStoneFv);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", Draw__13CRandomCircleFPf);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", Step__13CRandomCircleFv);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", DrawSymbol__13CRandomCircleFP14CMiniMapSymbol);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", CheckArea__13CRandomCircleFPff);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", GetPosition__13CRandomCircleFPfi);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", CheckEvent__13CRandomCircleFPf);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", SetCircle__13CRandomCircleFPf);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", Clear__13CRandomCircleFv);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", Initialize__13CRandomCircleFv);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", Draw__12CTreasureBoxFPf);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", DrawShadow__12CTreasureBoxFPfPf);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", SetLargeModel__19CTreasureBoxManagerFP11CCharacter2i);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", SetCollisionModel__19CTreasureBoxManagerFPUiP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", PutTreasureBox__19CTreasureBoxManagerFiPffiiiii);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", CheckArea__19CTreasureBoxManagerFPff);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", DrawMiniMapSymbol__19CTreasureBoxManagerFP14CMiniMapSymbol);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", Draw__19CTreasureBoxManagerFPf);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", DrawShadow__19CTreasureBoxManagerFPf);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", PickupCollision__19CTreasureBoxManagerFPfP6CCPoly9mgVu0FBOXi);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", MimicCount__19CTreasureBoxManagerFv);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", CheckEvent__19CTreasureBoxManagerFPff);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", GetGateKeyIndex__Fii);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", GetKeyDoorIndex__Fii);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", Lamb2WolfManager__Fv);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", LoopSoundManager__Fi);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", BattleSoundManager__Fv);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", StatusWarningSnd__Fv);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", BattleAreaBGMCtrl__Fv);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", ScriptDebugCommand__Fi);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", XChgMapLighting__Fv);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", XChgMapRotation__Fi);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", SearchMapEventParts__FiPP9CMapPartsPfi);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", SearchMapFlatPosition__FPfP11CAutoMapGen);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", GetDungeonEventPoint__FPfPfi);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", _GROUP_START__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", _GROUP__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", _ITEM__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", _FLOOR_START__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", _FLOOR__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", CreatTresuarBoxInfo__FP22TRESURE_BOX_FLOOR_INFOPci);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", PickupRandomItemCheckMax__FP22TRESURE_BOX_FLOOR_INFOi);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", PickupRandomItem__FP22TRESURE_BOX_FLOOR_INFOii);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", CheckObjectPutArea__FPf);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", ScanEyePoint__FPf);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", AutoSetTreasureBox__FiPff);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", AutoSetTreasureBox__Fv);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", _FLS__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", _FL__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", _FLE__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", CreatMonsterFloorInfo__FPci);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", AutoSetMonster__Fv);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", AutoSetMonster__FiPfPfi);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", DungeonFloorInit__Fv);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", DungeonFloorFinish__Fv);
