/* MapJumpMapInfo
 *
 * Unité découpée par `make carve` : 45 fonctions, 23152 octets, de
 * 0x002DF230 à 0x002E4DE0. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"
#include "gen/MainMapInfo_01F582A0Data.hpp"
#include "gen/MapJumpMapInfo.hpp"
#include "gen/SubMapInfoData.hpp"

struct mgCMemory;

/* Les globales que ces accesseurs servent. Leur taille déclarée est celle que
 * le découpage leur donne, et c'est elle qui décide du `%gp_rel`. */
extern s32 InteriorFlag;
extern s32 NowMainMapNo;
extern s32 NowSubMapNo;
extern mgCMemory *ScriptBuffer_0037E568;

#include "runscript.hpp"
extern MainMapInfo_01F582A0Data MainMapInfo_01F582A0;
extern SubMapInfoData SubMapInfo;


INCLUDE_ASM("nonmatchings/game/mapjumpmapinfo", PaintEditParts__FP8CEditMapiiPf);
INCLUDE_ASM("nonmatchings/game/mapjumpmapinfo", CheckPlaceAlt__FiP8CEditMapPfiPf);
INCLUDE_ASM("nonmatchings/game/mapjumpmapinfo", GetGeoMapLimitHeight__Fi);
INCLUDE_ASM("nonmatchings/game/mapjumpmapinfo", EditMode__FP6CScene);
INCLUDE_ASM("nonmatchings/game/mapjumpmapinfo", DrawEditCursorParts__FP6CScene);
INCLUDE_ASM("nonmatchings/game/mapjumpmapinfo", DrawEditCursor__FP6CScene);
INCLUDE_ASM("nonmatchings/game/mapjumpmapinfo", DrawEditHelpMes__Fv);
INCLUDE_ASM("nonmatchings/game/mapjumpmapinfo", CheckFocusBalanceParts__FP8CEditMapiPf);
INCLUDE_ASM("nonmatchings/game/mapjumpmapinfo", InitBalanceDraw__FP6CScene);
INCLUDE_ASM("nonmatchings/game/mapjumpmapinfo", GetBalanceHeight__FP6CScenePf);
INCLUDE_ASM("nonmatchings/game/mapjumpmapinfo", DrawEditSystem__FiP6CScenePfi);
INCLUDE_ASM("nonmatchings/game/mapjumpmapinfo", GetGeoCheckPts__FP4CMap);
INCLUDE_ASM("nonmatchings/game/mapjumpmapinfo", GetGeoCheckCol__FP4CMapR9mgVu0FBOXP6CCPolyi);
INCLUDE_ASM("nonmatchings/game/mapjumpmapinfo", GetGeoCheckCamCol__FP4CMapR9mgVu0FBOXP6CCPolyi);
INCLUDE_ASM("nonmatchings/game/mapjumpmapinfo", CheckWalkToEdit__FP6CScenePf);
INCLUDE_ASM("nonmatchings/game/mapjumpmapinfo", CheckEditToWalk__FP6CScenePf);
INCLUDE_ASM("nonmatchings/game/mapjumpmapinfo", IntersectionPipeYPoly3__FPfPA4_fPfPA4_f);
INCLUDE_ASM("nonmatchings/game/mapjumpmapinfo", IntersectionPipePoly3__FPfPfPA4_fPfPA4_f);
INCLUDE_ASM("nonmatchings/game/mapjumpmapinfo", IntersectionSpherePoly3__FPfPA4_fPfPf);
INCLUDE_ASM("nonmatchings/game/mapjumpmapinfo", IntersectionBox__FPfPfP9mgVu0FBOXPA4_f);
INCLUDE_ASM("nonmatchings/game/mapjumpmapinfo", IntersectionBox__FPfPfP9mgVu0FBOXPA4_fPA4_f);
s32 mt_test(RS_STACKDATA *stack, int argc) {
    return 1;
}
s32 GetMainMapNo(void) {
    return NowMainMapNo;
}
s32 GetSubMapNo(void) {
    return NowSubMapNo;
}
void ClearSubMapNo(void) {
    NowSubMapNo = -1;
}
INCLUDE_ASM("nonmatchings/game/mapjumpmapinfo", __ct__14MapJumpMapInfoFv);
void SetMainMapInfo(MapJumpMapInfo * arg0) {
    MainMapInfo_01F582A0.field_0x0 = arg0->field_0x0;
    MainMapInfo_01F582A0.field_0x4 = arg0->field_0x4;
    MainMapInfo_01F582A0.field_0x8 = arg0->field_0x8;
    MainMapInfo_01F582A0.field_0xC = arg0->field_0xC;
    MainMapInfo_01F582A0.field_0x10 = arg0->field_0x10;
    MainMapInfo_01F582A0.field_0x14 = arg0->field_0x14;
}
void SetSubMapInfo(MapJumpMapInfo * arg0) {
    SubMapInfo.field_0x0 = arg0->field_0x0;
    SubMapInfo.field_0x4 = arg0->field_0x4;
    SubMapInfo.field_0x8 = arg0->field_0x8;
    SubMapInfo.field_0xC = arg0->field_0xC;
    SubMapInfo.field_0x10 = arg0->field_0x10;
    SubMapInfo.field_0x14 = arg0->field_0x14;
}
void SetScriptBuffer(mgCMemory *buffer) {
    ScriptBuffer_0037E568 = buffer;
}
INCLUDE_ASM("nonmatchings/game/mapjumpmapinfo", PreLoadSync__Fv);
INCLUDE_ASM("nonmatchings/game/mapjumpmapinfo", MapJump__FP6CSceneP17SCN_LOADMAP_INFO2i);
INCLUDE_ASM("nonmatchings/game/mapjumpmapinfo", GetLoadMapInfo__FP17SCN_LOADMAP_INFO2i);
INCLUDE_ASM("nonmatchings/game/mapjumpmapinfo", LoadSubMap__FP6CSceneii);
INCLUDE_ASM("nonmatchings/game/mapjumpmapinfo", LoadMapScript__FPc);
INCLUDE_ASM("nonmatchings/game/mapjumpmapinfo", ReloadMapScript__Fv);
INCLUDE_ASM("nonmatchings/game/mapjumpmapinfo", LoadScript__FPc);
INCLUDE_ASM("nonmatchings/game/mapjumpmapinfo", GetOldInteriorMapNo__Fv);
INCLUDE_ASM("nonmatchings/game/mapjumpmapinfo", InitInterior__Fv);
s32 InInterior(void) {
    return InteriorFlag;
}
INCLUDE_ASM("nonmatchings/game/mapjumpmapinfo", SaveBeforeInterior__FP6CScene);
INCLUDE_ASM("nonmatchings/game/mapjumpmapinfo", SetInteriorDoorPos__FP6CScene);
INCLUDE_ASM("nonmatchings/game/mapjumpmapinfo", GotoInterior__FP6CScenei);
INCLUDE_ASM("nonmatchings/game/mapjumpmapinfo", DeleteInterior__FP6CScene);
INCLUDE_ASM("nonmatchings/game/mapjumpmapinfo", ExitInterior__FP6CScenePi);
INCLUDE_ASM("nonmatchings/game/mapjumpmapinfo", InteriorMapJump__FP6CScenei);
