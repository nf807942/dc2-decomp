/* mgCVisualMotionMDT, CTreasureBoxManager, CStartupEpisodeTitle, CRandomCircle, MessageTaskManager, CGeoStone, CTreasureBox, CRedMarkModel, mgVertexWeight, CSound
 *
 * Unité découpée par `make carve` : 98 fonctions, 24196 octets, de
 * 0x0028D160 à 0x002931B0. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"
#include "gen/CStartupEpisodeTitle.hpp"
#include "gen/MessageTaskManager.hpp"

/* Le corps ne rend qu'un code : ni la classe ni les arguments ne sont
 * déréférencés, donc leur disposition reste à établir. */
class mgCVisualMotionMDT {
public:
    char pad_0[0x8];
    s32 field_8;
    char pad_C[0x4];
    s32 field_10;
    s32 field_14;
    char pad_18[0x8];
    s32 field_20;
    char pad_24[0xC];
    s32 field_30;
    s32 field_34;
    s32 field_38;
    s32 field_3C;
    s32 field_40;
    s32 field_44;
    s32 field_48;
    char pad_4C[0x8];
    s32 field_54;
    char pad_58[0xA8];
    s32 field_100;
    s32 field_104;

    s32 Iam();
};
extern s32 FLS_FLOOR_ID;
struct SPI_STACK;


s32 LoadFileSocket(char *path, u32 *size) {
    return 0;
}
void WriteFileSocket(char * arg0, u32 * arg1, s32 arg2) {
}
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
struct inferred;
#include "gen/mgCVisualMDT.hpp"
typedef struct mgRENDER_INFO {
    /* 0x0000 */ char pad0[0x1010];
    /* 0x1010 */ s32 unk1010;                       /* inferred */
} mgRENDER_INFO;                                    /* size >= 0x1014 */
extern "C" s32 CreateRenderInfoPacket__12mgCVisualMDTFPUiPA4_fP13mgRENDER_INFO(...);
extern "C" void CreateRenderInfoPacket__18mgCVisualMotionMDTFPUiPA4_fP13mgRENDER_INFO(mgCVisualMotionMDT *objet, u32 *arg0, f32 (*arg1)[4], mgRENDER_INFO *arg2) {
    arg2->unk1010 = 1;
    CreateRenderInfoPacket__12mgCVisualMDTFPUiPA4_fP13mgRENDER_INFO((mgCVisualMDT *) objet, arg0, arg1, arg2);
    arg2->unk1010 = 0;
}
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", CreateExtRenderInfoPacket__18mgCVisualMotionMDTFPUiPA4_fP13mgRENDER_INFO);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", SetBaseBox__18mgCVisualMotionMDTFPfPf);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", CreateBBox__18mgCVisualMotionMDTFPfPfPA4_f);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", Copy__18mgCVisualMotionMDTFP9mgCMemory);
s32 mgCVisualMotionMDT::Iam(void) {
    return 3;
}
extern "C" u8 _32[19];
extern "C" u8 _33_00372D00[23];
typedef struct gCd2_champs {
    char pad0[36];
    s32 unk24;
} gCd2_champs;
extern "C" gCd2_champs gCd2;
extern "C" s32 printf(...);
extern "C" s32 sceSifBindRpc(...);
extern "C" s32 sceSifInitRpc(...);
extern "C" s32 ezBgmInit__Fv(void) {
    s32 temp_v0;
    s32 var_v1;

    printf(&_32);
    sceSifInitRpc(0);
loop_1:
    if (sceSifBindRpc(&gCd2, 0x12345, 0) < 0) {
        printf(&_33_00372D00);
loop_3:
        goto loop_3;
    }
    var_v1 = 0x2710;
    do {
        temp_v0 = var_v1;
        var_v1 -= 1;
    } while (temp_v0 != 0);
    if (gCd2.unk24 != 0) {
        return 1;
    }
    goto loop_1;
}
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", ezBgm__Fii);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", StreamOpenState__6CSoundFv);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", DrawEpisode__20CStartupEpisodeTitleFii);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", Switch__20CStartupEpisodeTitleFi);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", Step__20CStartupEpisodeTitleFv);
void CStartupEpisodeTitle::Initialize(void) {
    this->field_0x14 = 0;
    this->field_0x0 = 0;
    this->field_0x2 = 0;
}
#include "gen/ClsMes.hpp"
struct inferred;
typedef struct MessageTaskManager_infere {
    /* 0x0 */ char pad0[4];
    /* 0x4 */ ClsMes *unk4;                         /* inferred */
} MessageTaskManager_infere;                               /* size >= 0x8 */
extern "C" s32 DrawMesWin__6ClsMesFv(void *);
extern "C" void Draw__18MessageTaskManagerFv(MessageTaskManager_infere *objet) {
    ClsMes *temp_a0;

    temp_a0 = (ClsMes *) (objet->unk4);
    if (temp_a0 != NULL) {
        DrawMesWin__6ClsMesFv(temp_a0);
    }
}
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", Step__18MessageTaskManagerFv);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", Print__18MessageTaskManagerFPciii);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", Clear__18MessageTaskManagerFv);
void MessageTaskManager::Initialize(void) {
    this->field_0x4 = 0;
    this->field_0x368 = 0;
    this->field_0x0 = 0;
    this->field_0x8 = 0;
    this->field_0x8C = 0;
    this->field_0x8E = 0;
    this->field_0x92 = 8;
    this->field_0x94 = 0;
    this->field_0x98 = 0;
    this->field_0x11C = 0;
    this->field_0x11E = 0;
    this->field_0x122 = 8;
    this->field_0x124 = 0;
    this->field_0x128 = 0;
    this->field_0x1AC = 0;
    this->field_0x1AE = 0;
    this->field_0x1B2 = 8;
    this->field_0x1B4 = 0;
    this->field_0x1B8 = 0;
    this->field_0x23C = 0;
    this->field_0x23E = 0;
    this->field_0x242 = 8;
    this->field_0x244 = 0;
    this->field_0x248 = 0;
    this->field_0x2CC = 0;
    this->field_0x2CE = 0;
    this->field_0x2D2 = 8;
    this->field_0x2D4 = 0;
    this->field_0x2D8 = 0;
    this->field_0x35C = 0;
    this->field_0x35E = 0;
    this->field_0x362 = 8;
    this->field_0x364 = 0;
}
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
extern "C" u8 _1279_00372D88[11];
extern "C" s32 GetPackFile__FPUiPcPi(...);
struct MDS_HEADER {
    u32 field_0;
    char pad_4[0x4];
    u32 field_8;
};
struct inferred;
#include "menu.hpp"
typedef struct CTreasureBoxManager {
    /* 0x000 */ char pad0[0xA98];
    /* 0xA98 */ s32 unkA98;                         /* inferred */
} CTreasureBoxManager;                              /* size >= 0xA9C */
extern "C" s32 LoadCollisionFile__FP10MDS_HEADERP9mgCMemory(...);
extern "C" void SetCollisionModel__19CTreasureBoxManagerFPUiP9mgCMemory(CTreasureBoxManager *objet, u32 *arg0, mgCMemory *arg1) {
    objet->unkA98 = LoadCollisionFile__FP10MDS_HEADERP9mgCMemory(GetPackFile__FPUiPcPi(arg0, &_1279_00372D88, NULL), arg1);
}
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
void LoopSoundManager(s32 arg0) {
}
extern "C" s32 BattleAreaBGMCtrl__Fv(void);
extern "C" s32 StatusWarningSnd__Fv(void);
extern "C" void BattleSoundManager__Fv(void) {
    BattleAreaBGMCtrl__Fv();
    StatusWarningSnd__Fv();
}
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", StatusWarningSnd__Fv);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", BattleAreaBGMCtrl__Fv);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", ScriptDebugCommand__Fi);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", XChgMapLighting__Fv);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", XChgMapRotation__Fi);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", SearchMapEventParts__FiPP9CMapPartsPfi);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", SearchMapFlatPosition__FPfP11CAutoMapGen);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", GetDungeonEventPoint__FPfPfi);
typedef struct nowTbFloor_pointe {
    char pad0[74244];
    s32 unk12204;
} nowTbFloor_pointe;
extern "C" nowTbFloor_pointe *nowTbFloor;
struct SPI_STACK {
    s32 field_0;
    s32 field_4;
};
extern "C" s32 spiGetStackInt__FP9SPI_STACK(SPI_STACK *);
extern "C" s32 _GROUP_START__FP9SPI_STACKi(SPI_STACK *arg0, s32 arg1) {
    spiGetStackInt__FP9SPI_STACK(arg0);
    nowTbFloor->unk12204 = -1;
    return 1;
}
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
s32 _FLE(SPI_STACK * arg0, s32 arg1) {
    FLS_FLOOR_ID = -1;
    return 1;
}
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", CreatMonsterFloorInfo__FPci);
INCLUDE_ASM("nonmatchings/game/mgcvisualmotionmdt", AutoSetMonster__Fv);
extern "C" u32 ActiveMonster;
typedef struct DngMainScene_pointe {
    char pad0[12268];
    s32 unk2FEC;
} DngMainScene_pointe;
extern "C" DngMainScene_pointe *DngMainScene;
extern "C" s32 SetActiveMonster__11CMonsterManFiPfPfi(...);
struct temp_v0_2_champs {
    char pad0[0x1350];
    /* 0x1350 */ s32 unk1350;
};
extern "C" s32 SearchBaseIndex__11CMonsterManFi(...);
extern "C" void AutoSetMonster__FiPfPfi(s32 arg0, f32 *arg1, f32 *arg2, s32 arg3) {
    s32 temp_v0;
    struct temp_v0_2_champs *temp_v0_2;

    if (ActiveMonster != NULL) {
        DngMainScene->unk2FEC = 0;
        temp_v0 = SearchBaseIndex__11CMonsterManFi(ActiveMonster, arg0);
        if (temp_v0 != -1) {
            temp_v0_2 = (struct temp_v0_2_champs *) (SetActiveMonster__11CMonsterManFiPfPfi(ActiveMonster, temp_v0, arg1, arg2, -1));
            if (temp_v0_2 != NULL) {
                temp_v0_2->unk1350 = arg3;
            }
        }
    }
}
void DungeonFloorInit(void) {
}
void DungeonFloorFinish(void) {
}
