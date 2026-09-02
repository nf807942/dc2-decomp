/* CActionChara, CMapPiece, CMdsListSet, CObject, CMdsList, CObjectFrame, CIMGList, CCharacter2, CMdsInfo
 *
 * Unité découpée par `make carve` : 111 fonctions, 25492 octets, de
 * 0x00169820 à 0x0016FE00. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"
#include "gen/CActionChara.hpp"
#include "gen/CMapPiece.hpp"

INCLUDE_ASM("nonmatchings/game/cactionchara", GetMotionStatus__11CCharacter2Fv);
INCLUDE_ASM("nonmatchings/game/cactionchara", GetNowMotionName__11CCharacter2Fv);
INCLUDE_ASM("nonmatchings/game/cactionchara", GetNowFrameWait__11CCharacter2Fv);
INCLUDE_ASM("nonmatchings/game/cactionchara", SetNowFrame__11CCharacter2Ff);
INCLUDE_ASM("nonmatchings/game/cactionchara", GetNowFrame__11CCharacter2Fv);
INCLUDE_ASM("nonmatchings/game/cactionchara", GetStep__11CCharacter2Fv);
INCLUDE_ASM("nonmatchings/game/cactionchara", SetFadeFlag__11CCharacter2Fi);
INCLUDE_ASM("nonmatchings/game/cactionchara", GetFadeFlag__11CCharacter2Fv);
typedef struct CCharacter2 {
    /* 0x000 */ char pad0[0x118];
    /* 0x118 */ s32 unk118;                         /* inferred */
    /* 0x11C */ s32 unk11C;                         /* inferred */
} CCharacter2;                                      /* size >= 0x120 */
extern "C" s32 GetCopySize__11CCharacter2Fv(CCharacter2 *objet) {
    s32 temp_v0;

    temp_v0 = objet->unk11C;
    if (temp_v0 > 0) {
        return temp_v0;
    }
    return objet->unk118;
}
INCLUDE_ASM("nonmatchings/game/cactionchara", SetPosition__11CCharacter2Ffff);
INCLUDE_ASM("nonmatchings/game/cactionchara", AssignMds__9CMapPieceFP8CMdsInfo);
INCLUDE_ASM("nonmatchings/game/cactionchara", GetPoly__9CMapPieceFiP6CCPolyR9mgVu0FBOXi);
void CMapPiece::SetTimeBand(f32 arg0, f32 arg1) {
    this->field_0x94 = arg0;
    this->field_0x98 = arg1;
}
INCLUDE_ASM("nonmatchings/game/cactionchara", GetMaterial__9CMapPieceFi);
INCLUDE_ASM("nonmatchings/game/cactionchara", Step__9CMapPieceFv);
INCLUDE_ASM("nonmatchings/game/cactionchara", GetBoundBox__9CMapPieceFP9mgVu0FBOX);
INCLUDE_ASM("nonmatchings/game/cactionchara", DrawSub__9CMapPieceFi);
INCLUDE_ASM("nonmatchings/game/cactionchara", Copy__9CMapPieceFR9CMapPieceP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/cactionchara", Initialize__9CMapPieceFv);
typedef struct CMdsInfo {
    /* 0x00 */ s32 unk0;                            /* inferred */
    /* 0x04 */ s32 unk4;                            /* inferred */
    /* 0x08 */ s32 unk8;                            /* inferred */
    /* 0x0C */ s32 unkC;                            /* inferred */
    /* 0x10 */ s32 unk10;                           /* inferred */
    /* 0x14 */ s32 unk14;                           /* inferred */
} CMdsInfo;                                         /* size >= 0x18 */
extern "C" void Initialize__8CMdsInfoFv(CMdsInfo *objet) {
    objet->unk0 = 0;
    objet->unk4 = 0;
    objet->unk8 = 0;
    objet->unkC = 0;
    objet->unk10 = 0xBF800000;
    objet->unk14 = 0;
}
INCLUDE_ASM("nonmatchings/game/cactionchara", SearchMdsList__11CMdsListSetFPc);
INCLUDE_ASM("nonmatchings/game/cactionchara", GetMdsList__11CMdsListSetFi);
INCLUDE_ASM("nonmatchings/game/cactionchara", SearchMDS__11CMdsListSetFPc);
INCLUDE_ASM("nonmatchings/game/cactionchara", LoadPCPFile__11CMdsListSetFPcPUiP9mgCMemoryi);
INCLUDE_ASM("nonmatchings/game/cactionchara", DeleteMdsList__11CMdsListSetFPc);
INCLUDE_ASM("nonmatchings/game/cactionchara", LoadIMGFile__11CMdsListSetFPcP15mgCEnterIMGInfoP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/cactionchara", DeleteIMG__11CMdsListSetFPc);
INCLUDE_ASM("nonmatchings/game/cactionchara", SearchIMGList__11CMdsListSetFPc);
INCLUDE_ASM("nonmatchings/game/cactionchara", GetTextureBlockNo__11CMdsListSetFiPii);
INCLUDE_ASM("nonmatchings/game/cactionchara", Initialize__11CMdsListSetFv);
INCLUDE_ASM("nonmatchings/game/cactionchara", GetList__8CMdsListFi);
INCLUDE_ASM("nonmatchings/game/cactionchara", GetListID__8CMdsListFPc);
struct CMdsList {
    s32 field_0;
    s32 field_4;
};
extern "C" s32 GetListID__8CMdsListFPc(CMdsList *objet, s8 *arg0);
extern "C" s32 GetList__8CMdsListFi(CMdsList *objet, s32 arg0);
extern "C" s32 GetList__8CMdsListFPc(CMdsList *objet, s8 *arg0) {
    s32 temp_v0;

    temp_v0 = GetListID__8CMdsListFPc(objet, arg0);
    if (temp_v0 < 0) {
        return 0;
    }
    return GetList__8CMdsListFi(objet, temp_v0);
}
INCLUDE_ASM("nonmatchings/game/cactionchara", LoadIMGFile__8CIMGListFPcP15mgCEnterIMGInfoP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/cactionchara", pcpMDS__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cactionchara", pcpTYPE__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cactionchara", pcpFAR_CLIP__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cactionchara", pcpMDS_END__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cactionchara", LoadPCPFile__8CMdsListFPcPUiP9mgCMemoryi);
INCLUDE_ASM("nonmatchings/game/cactionchara", __ct__8CMdsInfoFv);
INCLUDE_ASM("nonmatchings/game/cactionchara", CreateChara__FPUiPcP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/cactionchara", GetMatrix__7CObjectFPA4_f);
INCLUDE_ASM("nonmatchings/game/cactionchara", FarClip__7CObjectFfPf);
INCLUDE_ASM("nonmatchings/game/cactionchara", GetCameraDist__7CObjectFv);
INCLUDE_ASM("nonmatchings/game/cactionchara", CheckDraw__7CObjectFv);
INCLUDE_ASM("nonmatchings/game/cactionchara", DrawStep__7CObjectFv);
INCLUDE_ASM("nonmatchings/game/cactionchara", GetAlpha__7CObjectFv);
INCLUDE_ASM("nonmatchings/game/cactionchara", PreDraw__7CObjectFv);
INCLUDE_ASM("nonmatchings/game/cactionchara", Initialize__7CObjectFv);
INCLUDE_ASM("nonmatchings/game/cactionchara", UpDatePosition__12CObjectFrameFv);
INCLUDE_ASM("nonmatchings/game/cactionchara", DrawStep__12CObjectFrameFv);
INCLUDE_ASM("nonmatchings/game/cactionchara", GetCameraDist__12CObjectFrameFv);
INCLUDE_ASM("nonmatchings/game/cactionchara", PreDraw__12CObjectFrameFv);
#include "gen/mgCFrame.hpp"
typedef struct CObjectFrame {
    /* 0x00 */ char pad0[0x70];
    /* 0x70 */ mgCFrame *unk70;                     /* inferred */
} CObjectFrame;                                     /* size >= 0x74 */
extern "C" void mgDraw__FP8mgCFrame(mgCFrame *arg0);
extern "C" s32 PreDraw__12CObjectFrameFv(CObjectFrame *objet);
extern "C" s32 Draw__12CObjectFrameFv(CObjectFrame *objet) {
    if (PreDraw__12CObjectFrameFv(objet) == 0) {
        return 0;
    }
    mgDraw__FP8mgCFrame(objet->unk70);
    return 0;
}
INCLUDE_ASM("nonmatchings/game/cactionchara", DrawDirect__12CObjectFrameFv);
INCLUDE_ASM("nonmatchings/game/cactionchara", Copy__12CObjectFrameFR12CObjectFrameP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/cactionchara", Initialize__12CObjectFrameFv);
void CActionChara::ResetAccele(void) {
    this->field_0x788 = 0;
    this->field_0x784 = 0;
    this->field_0x780 = 0;
    this->field_0x790 = 0;
}
INCLUDE_ASM("nonmatchings/game/cactionchara", ResetAction__12CActionCharaFv);
INCLUDE_ASM("nonmatchings/game/cactionchara", ResetScript__12CActionCharaFv);
INCLUDE_ASM("nonmatchings/game/cactionchara", CheckRunEvent__12CActionCharaFv);
INCLUDE_ASM("nonmatchings/game/cactionchara", SetMaskFlag__12CActionCharaFii);
INCLUDE_ASM("nonmatchings/game/cactionchara", EntryObject__12CActionCharaFPci);
INCLUDE_ASM("nonmatchings/game/cactionchara", CalcCollision__12CActionCharaFv);
INCLUDE_ASM("nonmatchings/game/cactionchara", EntryBodyCol__12CActionCharaFif);
INCLUDE_ASM("nonmatchings/game/cactionchara", EntryDamage2__12CActionCharaFPcPcPcfPcffPc);
INCLUDE_ASM("nonmatchings/game/cactionchara", EntryDamage2__12CActionCharaFP8mgCFrameP8mgCFramePcfPcffPc);
INCLUDE_ASM("nonmatchings/game/cactionchara", AllDeleteDamage__12CActionCharaFv);
INCLUDE_ASM("nonmatchings/game/cactionchara", GetSwEffectPtr__12CActionCharaFv);
INCLUDE_ASM("nonmatchings/game/cactionchara", SetSoundInfoCopy__12CActionCharaFv);
INCLUDE_ASM("nonmatchings/game/cactionchara", SetFadeFlag__12CActionCharaFi);
INCLUDE_ASM("nonmatchings/game/cactionchara", SetFarDist__12CActionCharaFf);
INCLUDE_ASM("nonmatchings/game/cactionchara", SetNearDist__12CActionCharaFf);
INCLUDE_ASM("nonmatchings/game/cactionchara", GetCameraDist__12CActionCharaFv);
INCLUDE_ASM("nonmatchings/game/cactionchara", Show__12CActionCharaFii);
INCLUDE_ASM("nonmatchings/game/cactionchara", GetShow__12CActionCharaFPc);
INCLUDE_ASM("nonmatchings/game/cactionchara", CheckKeri__12CActionCharaFPci);
INCLUDE_ASM("nonmatchings/game/cactionchara", CheckEnemyCatch__12CActionCharaFPc);
INCLUDE_ASM("nonmatchings/game/cactionchara", ThrowItemObject__12CActionCharaFv);
INCLUDE_ASM("nonmatchings/game/cactionchara", UsedItemAction__12CActionCharaFv);
INCLUDE_ASM("nonmatchings/game/cactionchara", EntryThrowItem__12CActionCharaFv);
INCLUDE_ASM("nonmatchings/game/cactionchara", RemoveThrowItem__12CActionCharaFv);
INCLUDE_ASM("nonmatchings/game/cactionchara", GetNowFrameWait__12CActionCharaFPc);
INCLUDE_ASM("nonmatchings/game/cactionchara", GetNowFrame__12CActionCharaFPc);
INCLUDE_ASM("nonmatchings/game/cactionchara", CheckMotionEnd__12CActionCharaFPc);
INCLUDE_ASM("nonmatchings/game/cactionchara", GetMotionStatus__12CActionCharaFPc);
INCLUDE_ASM("nonmatchings/game/cactionchara", GetWaitToFrame__12CActionCharaFPcfPc);
INCLUDE_ASM("nonmatchings/game/cactionchara", SetMotion__12CActionCharaFii);
INCLUDE_ASM("nonmatchings/game/cactionchara", SetMotion__12CActionCharaFPcii);
INCLUDE_ASM("nonmatchings/game/cactionchara", ResetMotion__12CActionCharaFv);
INCLUDE_ASM("nonmatchings/game/cactionchara", Draw__12CActionCharaFv);
INCLUDE_ASM("nonmatchings/game/cactionchara", DrawDirect__12CActionCharaFv);
INCLUDE_ASM("nonmatchings/game/cactionchara", DrawShadowDirect__12CActionCharaFv);
INCLUDE_ASM("nonmatchings/game/cactionchara", DrawEffect__12CActionCharaFv);
INCLUDE_ASM("nonmatchings/game/cactionchara", StepEffect__12CActionCharaFv);
INCLUDE_ASM("nonmatchings/game/cactionchara", SearchChara__12CActionCharaFPc);
INCLUDE_ASM("nonmatchings/game/cactionchara", SearchObject__12CActionCharaFPc);
INCLUDE_ASM("nonmatchings/game/cactionchara", ResetParent__12CActionCharaFv);
INCLUDE_ASM("nonmatchings/game/cactionchara", SetRef__12CActionCharaFP12CActionCharaPc);
INCLUDE_ASM("nonmatchings/game/cactionchara", GetTargetDist__12CActionCharaFP6CScene);
INCLUDE_ASM("nonmatchings/game/cactionchara", RockOn_TargetSel__FP6CScenei);
INCLUDE_ASM("nonmatchings/game/cactionchara", DistCheck_Action2__FP6CSceneffPfiPi);
INCLUDE_ASM("nonmatchings/game/cactionchara", Check_LockOn__FP6CScenefi);
INCLUDE_ASM("nonmatchings/game/cactionchara", CollisionCheck__12CActionCharaFPfPfPf);
INCLUDE_ASM("nonmatchings/game/cactionchara", RockOn__12CActionCharaFv);
INCLUDE_ASM("nonmatchings/game/cactionchara", HumanMoveIF__12CActionCharaFv);
INCLUDE_ASM("nonmatchings/game/cactionchara", HumanShrowMoveIF__12CActionCharaFv);
INCLUDE_ASM("nonmatchings/game/cactionchara", HumanTameMoveIF__12CActionCharaFv);
INCLUDE_ASM("nonmatchings/game/cactionchara", HumanGunMoveIF__12CActionCharaFPcPc);
INCLUDE_ASM("nonmatchings/game/cactionchara", RoboWalkMoveIF__12CActionCharaFi);
INCLUDE_ASM("nonmatchings/game/cactionchara", RoboTankMoveIF__12CActionCharaFi);
