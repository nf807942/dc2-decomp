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
extern "C" s32 GetMap__6CSceneFi(void *, s32);
extern "C" u8 now_balance_h[16];
struct CEditMap {
    char pad_0[0xC88];
    f32 field_C88;
    char pad_C8C[0xA8];
    s32 field_D34;
    s32 field_D38;
    char pad_D3C[0x4];
    s32 field_D40;
    s32 field_D44;
    char pad_D48[0x200];
    s32 field_F48;
    s32 field_F4C;
    s32 field_F50;
    char pad_F54[0x10];
    s32 field_F64;
    s32 field_F68;
    char pad_F6C[0x14];
    s32 field_F80;
    s32 field_F84;
    s32 field_F88;
    s32 field_F8C;
    s32 field_F90;
    char pad_F94[0x4];
    s32 field_F98;
    s32 field_F9C;
    s32 field_FA0;
    s32 field_FA4;
    s32 field_FA8;
    s32 field_FAC;
    s32 field_FB0;
    s32 field_FB4;
    s32 field_FB8;
    s32 field_FBC;
    s32 field_FC0;
    s32 field_FC4;
    s32 field_FC8;
    s32 field_FCC;
    s32 field_FD0;
    s32 field_FD4;
    s32 field_FD8;
    s32 field_FDC;
    s32 field_FE0;
    s32 field_FE4;
    s32 field_FE8;
    s32 field_FEC;
    s32 field_FF0;
    s32 field_FF4;
    s32 field_FF8;
    s32 field_FFC;
    char pad_1000[0x20];
    s32 field_1020;
    char pad_1024[0x2C];
    s32 field_1050;
    char pad_1054[0x20];
    f32 field_1074;
    char pad_1078[0xC];
    f32 field_1084;
    char pad_1088[0xC];
    f32 field_1094;
    char pad_1098[0xC];
    f32 field_10A4;
};
struct inferred;
typedef struct CScene {
    /* 0x0000 */ char pad0[0x2E5C];
    /* 0x2E5C */ s32 unk2E5C;                       /* inferred */
} CScene;                                           /* size >= 0x2E60 */
extern "C" s32 GroundBalance__8CEditMapFi(void *, s32);
extern "C" s32 GetBalanceHeight__FP6CScenePf(...);
extern "C" void InitBalanceDraw__FP6CScene(CScene *arg0) {
    CEditMap *temp_v0;

    temp_v0 = (CEditMap *) (GetMap__6CSceneFi(arg0, arg0->unk2E5C));
    if (temp_v0 != NULL) {
        GroundBalance__8CEditMapFi(temp_v0, 0);
    }
    GetBalanceHeight__FP6CScenePf(arg0, &now_balance_h);
}
INCLUDE_ASM("nonmatchings/game/mapjumpmapinfo", GetBalanceHeight__FP6CScenePf);
INCLUDE_ASM("nonmatchings/game/mapjumpmapinfo", DrawEditSystem__FiP6CScenePfi);
extern "C" u8 _2213_00377130[10];
struct CMap {
    char pad_0[0x98];
    s32 field_98;
    s32 field_9C;
    s32 field_A0;
    char pad_A4[0x1C];
    s32 field_C0;
    s32 field_C4;
    f32 field_C8;
    s32 field_CC;
    s32 field_D0;
    char pad_D4[0x4];
    s32 field_D8;
    f32 field_DC;
    f32 field_E0;
    s32 field_E4;
    s32 field_E8;
    s32 field_EC;
    f32 field_F0;
    f32 field_F4;
    f32 field_F8;
    char pad_FC[0xC];
    s32 field_108;
    char pad_10C[0x200];
    s32 field_30C;
    s32 field_310;
    s32 field_314;
    s32 field_318;
    s32 field_31C;
    s32 field_320;
    s32 field_324;
    s32 field_328;
    char pad_32C[0x4];
    s32 field_330;
    s32 field_334;
    char pad_338[0x8];
    f32 field_340;
    char pad_344[0xC];
    f32 field_350;
    char pad_354[0xC];
    s32 field_360;
    char pad_364[0x4];
    s32 field_368;
    char pad_36C[0x304];
    s32 field_670;
    char pad_674[0x60C];
    s32 field_C80;
    char pad_C84[0x4];
    f32 field_C88;
    s32 field_C8C;
    char pad_C90[0x4];
    s32 field_C94;
    s32 field_C98;
    char pad_C9C[0xC];
    s32 field_CA8;
    s32 field_CAC;
    char pad_CB0[0x34];
    f32 field_CE4;
    s32 field_CE8;
    s32 field_CEC;
    s32 field_CF0;
    s32 field_CF4;
};
extern "C" s32 GetPlaceParts__4CMapFPc(...);
extern "C" s32 GetGeoCheckPts__FP4CMap(CMap *arg0) {
    if (arg0 != NULL) {
        return GetPlaceParts__4CMapFPc(arg0, &_2213_00377130);
    }
    return 0;
}
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
extern "C" s32 ReadBGSync__Fv(void);
extern "C" s32 ReadBG__Fv(void);
extern "C" void PreLoadSync__Fv(void) {
    ReadBG__Fv();
    ReadBGSync__Fv();
}
INCLUDE_ASM("nonmatchings/game/mapjumpmapinfo", MapJump__FP6CSceneP17SCN_LOADMAP_INFO2i);
INCLUDE_ASM("nonmatchings/game/mapjumpmapinfo", GetLoadMapInfo__FP17SCN_LOADMAP_INFO2i);
INCLUDE_ASM("nonmatchings/game/mapjumpmapinfo", LoadSubMap__FP6CSceneii);
INCLUDE_ASM("nonmatchings/game/mapjumpmapinfo", LoadMapScript__FPc);
INCLUDE_ASM("nonmatchings/game/mapjumpmapinfo", ReloadMapScript__Fv);
INCLUDE_ASM("nonmatchings/game/mapjumpmapinfo", LoadScript__FPc);
extern "C" u32 OldInteriorMapNo;
extern "C" s32 InInterior__Fv(void);
extern "C" s32 GetOldInteriorMapNo__Fv(void) {
    if (InInterior__Fv() != 0) {
        return -1;
    }
    return OldInteriorMapNo;
}
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
