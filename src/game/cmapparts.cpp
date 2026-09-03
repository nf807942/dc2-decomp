/* CMapParts, CMap, CMapInfo, CMapTreasureBox, CCameraInfo, CMapLightingInfo, CObject, CMapPiece, CList_9CMapParts_, CList_9CMapPiece_, CFuncPoint, CObjectFrame, mgCObject, mgCFrame, CCameraDrawInfo, PieceMaterial, CCollision, CMapWater, CList_9CObjAnime_, CColFrame
 *
 * Unité découpée par `make carve` : 210 fonctions, 30988 octets, de
 * 0x00161970 à 0x00169820. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"
#include "gen/CCameraDrawInfo.hpp"
#include "gen/CList_9CMapParts_.hpp"
#include "gen/CList_9CMapPiece_.hpp"
#include "gen/CList_9CObjAnime_.hpp"
#include "gen/CMapInfo.hpp"
#include "gen/CMapParts.hpp"
#include "gen/CMapPiece.hpp"
#include "gen/CObjectFrame.hpp"

/* Les globales que ces accesseurs servent. Leur taille déclarée est celle que
 * le découpage leur donne, et c'est elle qui décide du `%gp_rel`. */
extern s32 mapAddMode;

/* Le corps ne rend qu'un code : ni la classe ni les arguments ne sont
 * déréférencés, donc leur disposition reste à établir. */
class CObject {
public:
    f32 field_0;
    char pad_4[0xC];
    f32 field_10;
    f32 field_14;
    f32 field_18;
    f32 field_1C;
    f32 field_20;
    f32 field_24;
    f32 field_28;
    f32 field_2C;
    f32 field_30;
    f32 field_34;
    f32 field_38;
    f32 field_3C;
    s32 field_40;
    s32 field_44;
    char pad_48[0x8];
    f32 field_50;
    s32 field_54;
    f32 field_58;
    f32 field_5C;
    f32 field_60;
    s32 field_64;
    s32 field_68;
    char pad_6C[0x4];
    s32 field_70;
    char pad_74[0xC];
    f32 field_80;
    f32 field_84;
    f32 field_88;
    s32 field_8C;
    s32 field_90;
    s32 field_94;
    f32 field_98;
    f32 field_9C;
    f32 field_A0;
    char pad_A4[0x5C];
    f32 field_100;
    s32 field_104;
    s32 field_108;
    f32 field_10C;
    f32 field_110;
    f32 field_114;
    s32 field_118;
    s32 field_11C;
    s16 field_120;
    char pad_122[0x2];
    s32 field_124;
    s32 field_128;
    s32 field_12C;
    s32 field_130;
    s32 field_134;
    f32 field_138;
    f32 field_13C;
    char pad_140[0x180];
    s32 field_2C0;
    f32 field_2C4;
    f32 field_2C8;
    f32 field_2CC;
    f32 field_2D0;
    f32 field_2D4;
    f32 field_2D8;
    s32 field_2DC;
    s32 field_2E0;
    s32 field_2E4;
    char pad_2E8[0x60];
    s32 field_348;
    s32 field_34C;
    s32 field_350;
    s32 field_354;
    s32 field_358;
    s32 field_35C;
    s32 field_360;
    s32 field_364;
    s32 field_368;
    s32 field_36C;
    s32 field_370;
    s32 field_374;
    s32 field_378;
    s32 field_37C;
    s32 field_380;
    s32 field_384;
    f32 field_388;
    f32 field_38C;
    f32 field_390;
    s32 field_394;
    s32 field_398;
    s32 field_39C;
    f32 field_3A0;
    s32 field_3A4;
    s32 field_3A8;
    s32 field_3AC;
    s32 field_3B0;
    s32 field_3B4;
    s32 field_3B8;
    s32 field_3BC;
    char pad_3C0[0x140];
    s32 field_500;
    s32 field_504;
    f32 field_508;
    f32 field_50C;
    f32 field_510;
    f32 field_514;
    f32 field_518;
    f32 field_51C;
    f32 field_520;
    f32 field_524;
    f32 field_528;
    f32 field_52C;
    f32 field_530;
    f32 field_534;
    f32 field_538;
    f32 field_53C;
    f32 field_540;
    f32 field_544;
    f32 field_548;
    f32 field_54C;
    f32 field_550;
    f32 field_554;
    f32 field_558;
    f32 field_55C;
    f32 field_560;
    f32 field_564;
    f32 field_568;
    f32 field_56C;
    f32 field_570;
    f32 field_574;
    f32 field_578;
    f32 field_57C;
    f32 field_580;
    f32 field_584;
    f32 field_588;
    f32 field_58C;
    f32 field_590;
    f32 field_594;
    f32 field_598;
    f32 field_59C;
    f32 field_5A0;
    f32 field_5A4;
    f32 field_5A8;
    f32 field_5AC;
    f32 field_5B0;
    f32 field_5B4;
    f32 field_5B8;
    f32 field_5BC;
    f32 field_5C0;
    f32 field_5C4;
    f32 field_5C8;
    f32 field_5CC;
    f32 field_5D0;
    f32 field_5D4;
    f32 field_5D8;
    f32 field_5DC;
    f32 field_5E0;
    s32 field_5E4;
    s32 field_5E8;
    char pad_5EC[0x60];
    s32 field_64C;
    s32 field_650;

    s32 Draw();
    s32 DrawDirect();
};

/* La pile de l'interpréteur de script d'objet. Les commandes qui ne rendent
 * qu'un code de retour ne la déréférencent pas : sa disposition reste à
 * établir. */
struct SPI_STACK;
extern s32 LightingInfo;
extern s32 mapNowFuncPoint;
struct PieceMaterial;


INCLUDE_ASM("nonmatchings/game/cmapparts", __ct__15CMapTreasureBoxFv);
INCLUDE_ASM("nonmatchings/game/cmapparts", GetTrBox__4CMapFi);
INCLUDE_ASM("nonmatchings/game/cmapparts", DeleteTrBox__4CMapFiP12CMapFlagData);
INCLUDE_ASM("nonmatchings/game/cmapparts", UpdateTrBoxFlag__4CMapFP12CMapFlagData);
INCLUDE_ASM("nonmatchings/game/cmapparts", LoadData__4CMapFPUiPUiPiP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/cmapparts", CheckFuncEvent__FP10CFuncPointPfiP12MapEventInfoPf);
INCLUDE_ASM("nonmatchings/game/cmapparts", Draw__4CMapFv);
INCLUDE_ASM("nonmatchings/game/cmapparts", DrawDirect__4CMapFv);
s32 CObject::Draw(void) {
    return 0;
}
s32 CObject::DrawDirect(void) {
    return 0;
}
INCLUDE_ASM("nonmatchings/game/cmapparts", Show__7CObjectFi);
INCLUDE_ASM("nonmatchings/game/cmapparts", SetFarDist__7CObjectFf);
INCLUDE_ASM("nonmatchings/game/cmapparts", GetFarDist__7CObjectFv);
INCLUDE_ASM("nonmatchings/game/cmapparts", SetNearDist__7CObjectFf);
INCLUDE_ASM("nonmatchings/game/cmapparts", GetNearDist__7CObjectFv);
INCLUDE_ASM("nonmatchings/game/cmapparts", Copy__7CObjectFR7CObjectP9mgCMemory);
extern "C" s32 GetTimeBand__Ff(f32 arg0) {
    s32 var_v0;

    var_v0 = 2;
    if (!(arg0 < 6.0f)) {
        if (arg0 < 9.0f) {
            var_v0 = 3;
        }
    }
    if (!(arg0 < 9.0f)) {
        if (arg0 < 17.0f) {
            var_v0 = 0;
        }
    }
    if (!(arg0 < 17.0f) && (arg0 < 21.0f)) {
        var_v0 = 1;
    }
    return var_v0;
}
typedef struct CMap {
    /* 0x000 */ char pad0[0xC0];
    /* 0x0C0 */ s32 unkC0;                          /* inferred */
    /* 0x0C4 */ char padC4[4];
    /* 0x0C8 */ f32 unkC8;                          /* inferred */
    /* 0x0CC */ s32 unkCC;                          /* inferred */
    /* 0x0D0 */ char padD0[0xBB8];                  /* maybe part of unkCC[0x2EF]? */
    /* 0xC88 */ f32 unkC88;                         /* inferred */
} CMap;                                             /* size >= 0xC8C */
extern "C" f32 GetNowTime__4CMapFv(CMap *objet) {
    if (objet->unkC0 != 0) {
        return objet->unkC88;
    }
    if (objet->unkCC != 0) {
        return objet->unkC8;
    }
    return 12.0f;
}
extern "C" f32 GetNowTime__4CMapFv(CMap *objet);
extern "C" s32 GetTimeBand__Ff(f32 arg0);
extern "C" void GetNowTimeBand__4CMapFv(CMap *objet) {
    GetTimeBand__Ff(GetNowTime__4CMapFv(objet));
}
INCLUDE_ASM("nonmatchings/game/cmapparts", GetNowTimeLightBand__4CMapFv);
INCLUDE_ASM("nonmatchings/game/cmapparts", GetLightingRatio__4CMapFPf);
struct arg0_champs {
    char pad0[0x8];
    /* 0x8 */ s32 unk8;
};
extern "C" s32 GetLightingRatio__4CMapFPf(...);
extern "C" void GetLightingFlareRatio__4CMapFPf(CMap *objet, struct arg0_champs *arg0) {
    GetLightingRatio__4CMapFPf(objet, arg0);
    arg0->unk8 = 0;
}
INCLUDE_ASM("nonmatchings/game/cmapparts", GetLightingSunRatio__4CMapFPf);
INCLUDE_ASM("nonmatchings/game/cmapparts", GetTimeLightingRatio__4CMapFPf);
INCLUDE_ASM("nonmatchings/game/cmapparts", GetSunPoint__4CMapFPf);
INCLUDE_ASM("nonmatchings/game/cmapparts", GetLightNoTime__4CMapFi);
INCLUDE_ASM("nonmatchings/game/cmapparts", GetTimeEnable__4CMapFv);
INCLUDE_ASM("nonmatchings/game/cmapparts", GetLightInfo__4CMapFP16CMapLightingInfo);
INCLUDE_ASM("nonmatchings/game/cmapparts", __as__16CMapLightingInfoFRC16CMapLightingInfo);
INCLUDE_ASM("nonmatchings/game/cmapparts", GetLightingInfo__4CMapFi);
INCLUDE_ASM("nonmatchings/game/cmapparts", GetActiveLightNo__4CMapFv);
s32 CMapInfo::GetActiveLightNo(void) {
    return this->field_0x98;
}
INCLUDE_ASM("nonmatchings/game/cmapparts", GetLightInfo__4CMapFP16CMapLightingInfoPfi);
INCLUDE_ASM("nonmatchings/game/cmapparts", mgAbs__Ff);
s32 mapDummy(SPI_STACK *stack, int argc) {
    return 1;
}
s32 IsAddMode(void) {
    return mapAddMode;
}
INCLUDE_ASM("nonmatchings/game/cmapparts", mapPARTS__FP9SPI_STACKi);
void * CList_9CMapParts_::pGetData(void) {
    return &this->field_0x10;
}
INCLUDE_ASM("nonmatchings/game/cmapparts", __ct__17CList_9CMapParts_Fv);
void CList_9CMapParts_::Initialize(void) {
    this->field_0x4 = 0;
    this->field_0x0 = 0;
}
INCLUDE_ASM("nonmatchings/game/cmapparts", __ct__7CObjectFv);
INCLUDE_ASM("nonmatchings/game/cmapparts", __ct__9mgCObjectFv);
INCLUDE_ASM("nonmatchings/game/cmapparts", algn16_size__FUi);
INCLUDE_ASM("nonmatchings/game/cmapparts", mapFAR_CLIP__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cmapparts", mapLIGHT_FLAG__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cmapparts", mapMOVE_FLAG__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cmapparts", mapLOD_START__FP9SPI_STACKi);
void CMapParts::SetLODDist(f32 * arg0, s32 arg1) {
    this->field_0x1D0 = arg1;
    this->field_0x1D8 = arg0;
}
INCLUDE_ASM("nonmatchings/game/cmapparts", mapLOD_BLEND__FP9SPI_STACKi);
void CMapParts::SetLODBlend(s32 arg0) {
    this->field_0x1D4 = arg0;
}
INCLUDE_ASM("nonmatchings/game/cmapparts", mapLOD_PIECE__FP9SPI_STACKi);
s32 CMapParts::GetLODBlend(void) {
    return this->field_0x1D4;
}
INCLUDE_ASM("nonmatchings/game/cmapparts", mapLOD_END__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cmapparts", mapPIECE__FP9SPI_STACKi);
void CMapPiece::SetName(char * arg0) {
    this->field_0x80 = arg0;
}
void * CList_9CMapPiece_::pGetData(void) {
    return &this->field_0x10;
}
INCLUDE_ASM("nonmatchings/game/cmapparts", __ct__17CList_9CMapPiece_Fv);
void CList_9CMapPiece_::Initialize(void) {
    this->field_0x4 = 0;
    this->field_0x0 = 0;
}
INCLUDE_ASM("nonmatchings/game/cmapparts", __ct__9CMapPieceFv);
INCLUDE_ASM("nonmatchings/game/cmapparts", __ct__12CObjectFrameFv);
extern "C" u32 mapNowMapPiece;
extern "C" u32 mapStack;
extern "C" s32 Alloc__9mgCMemoryFi(...);
extern "C" s32 pGetData__17CList_9CMapPiece_Fv(...);
extern "C" s32 spiGetStackString__FP9SPI_STACK(SPI_STACK *arg0);
extern "C" void strcpy(void *, s32);
extern "C" s32 strlen(...);
extern "C" s32 SetName__9CMapPieceFPc(...);
extern "C" s32 algn16_size__FUi(u32);
extern "C" s32 mapPIECE_NAME__FP9SPI_STACKi(SPI_STACK *arg0, s32 arg1) {
    CMapPiece *temp_s0;
    s32 temp_v0;
    s8 *temp_v0_2;

    if (mapNowMapPiece == NULL) {
        return 0;
    }
    temp_s0 = (CMapPiece *) (pGetData__17CList_9CMapPiece_Fv(mapNowMapPiece));
    temp_v0 = (s32) (spiGetStackString__FP9SPI_STACK(arg0));
    if (temp_v0 != 0) {
        temp_v0_2 = (s8 *) (Alloc__9mgCMemoryFi(mapStack, algn16_size__FUi(strlen(temp_v0) + 1)));
        strcpy(temp_v0_2, temp_v0);
        SetName__9CMapPieceFPc(temp_s0, temp_v0_2);
    }
    return 1;
}
INCLUDE_ASM("nonmatchings/game/cmapparts", mapPIECE_POS__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cmapparts", mapPIECE_ROT__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cmapparts", mapPIECE_SCALE__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cmapparts", mapPIECE_MATERIAL_START__FP9SPI_STACKi);
void CMapPiece::SetMaterial(PieceMaterial * arg0, s32 arg1) {
    this->field_0x90 = arg0;
    this->field_0x8C = arg1;
}
struct PieceMaterial;
extern "C" s32 Initialize__13PieceMaterialFv(PieceMaterial *objet);
extern "C" PieceMaterial *__ct__13PieceMaterialFv(PieceMaterial *objet) {
    Initialize__13PieceMaterialFv(objet);
    return objet;
}
INCLUDE_ASM("nonmatchings/game/cmapparts", Initialize__13PieceMaterialFv);
INCLUDE_ASM("nonmatchings/game/cmapparts", mapPIECE_MATERIAL__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cmapparts", GetMaterial__8mgCFrameFi);
s32 CObjectFrame::GetFrame(void) {
    return this->field_0x70;
}
s32 mapPIECE_MATERIAL_END(SPI_STACK *stack, int argc) {
    return 1;
}
INCLUDE_ASM("nonmatchings/game/cmapparts", mapPIECE_COL_TYPE__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cmapparts", mapPIECE_TIME__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cmapparts", mapPIECE_END__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cmapparts", mapPARTS_END__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cmapparts", mapMAP_PARTS__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cmapparts", mapMAP_FAR_CLIP__FP9SPI_STACKi);
extern "C" u8 mapMapPartsName[256];
struct SPI_STACK {
    s32 field_0;
    s32 field_4;
};
extern "C" s32 spiGetStackString__FP9SPI_STACK(SPI_STACK *arg0);
extern "C" void strcpy(void *, s32);
extern "C" s32 mapPARTS_NAME__FP9SPI_STACKi(SPI_STACK *arg0, s32 arg1) {
    s32 temp_v0;

    temp_v0 = spiGetStackString__FP9SPI_STACK(arg0);
    if (temp_v0 == 0) {
        return 0;
    }
    strcpy(&mapMapPartsName, temp_v0);
    return 1;
}
extern "C" u8 mapMapPartsGroupName[256];
extern "C" s32 spiGetStackString__FP9SPI_STACK(SPI_STACK *arg0);
extern "C" void strcpy(void *, s32);
extern "C" s32 mapPARTS_GROUP__FP9SPI_STACKi(SPI_STACK *arg0, s32 arg1) {
    s32 temp_v0;

    temp_v0 = spiGetStackString__FP9SPI_STACK(arg0);
    if (temp_v0 == 0) {
        return 0;
    }
    strcpy(&mapMapPartsGroupName, temp_v0);
    return 1;
}
extern "C" u8 mapPos[16];
extern "C" s32 spiGetStackVector__FPfP9SPI_STACK(...);
extern "C" s32 mapPARTS_POS__FP9SPI_STACKi(SPI_STACK *arg0, s32 arg1) {
    spiGetStackVector__FPfP9SPI_STACK(&mapPos, arg0);
    return 1;
}
extern "C" u8 mapRot[16];
extern "C" s32 mapPARTS_ROT__FP9SPI_STACKi(SPI_STACK *arg0, s32 arg1) {
    spiGetStackVector__FPfP9SPI_STACK(&mapRot, arg0);
    return 1;
}
extern "C" u8 mapScale[16];
extern "C" s32 mapPARTS_SCALE__FP9SPI_STACKi(SPI_STACK *arg0, s32 arg1) {
    spiGetStackVector__FPfP9SPI_STACK(&mapScale, arg0);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/cmapparts", mapMAP_PARTS_END__FP9SPI_STACKi);
s32 map_MAP_INFO_TOP(SPI_STACK *stack, int argc) {
    return 1;
}
INCLUDE_ASM("nonmatchings/game/cmapparts", mapCAMERA_INFO__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cmapparts", __ct__11CCameraInfoFv);
extern "C" s32 Initialize__15CCameraDrawInfoFv(CCameraDrawInfo *objet);
extern "C" CCameraDrawInfo *__ct__15CCameraDrawInfoFv(CCameraDrawInfo *objet) {
    Initialize__15CCameraDrawInfoFv(objet);
    return objet;
}
void CCameraDrawInfo::Initialize(void) {
    this->field_0x4 = 0;
    this->field_0x0 = -1;
}
extern "C" u32 mapCameraRectIdx;
extern "C" s32 IsAddMode__Fv();
extern "C" s32 mapFIX_CAMERA__FP9SPI_STACKi(SPI_STACK *arg0, s32 arg1) {
    if (IsAddMode__Fv() != 0) {
        return 1;
    }
    mapCameraRectIdx = 0;
    return 1;
}
extern "C" u32 mapMap;
extern "C" u32 mapCameraInfoIdx;
extern "C" s32 GetCameraInfo__4CMapFi(...);
extern "C" s32 spiGetStackVector__FPfP9SPI_STACK(...);
extern "C" s32 mapFIX_CAMERA_POS__FP9SPI_STACKi(SPI_STACK *arg0, s32 arg1) {
    s32 temp_v0;

    if (IsAddMode__Fv() != 0) {
        return 1;
    }
    temp_v0 = GetCameraInfo__4CMapFi(mapMap, mapCameraInfoIdx);
    if (temp_v0 == 0) {
        return 0;
    }
    spiGetStackVector__FPfP9SPI_STACK(temp_v0 + 0x10, arg0);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/cmapparts", mapFIX_CAMERA_POS2__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cmapparts", mapFIX_CAMERA_OFF_GROUP__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cmapparts", mapFIX_CAMERA_RECT__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cmapparts", SetCollision__9CColFrameFP10CCollision);
extern "C" u8 __vt__10CCollision[36];
struct inferred;
typedef struct CCollision {
    /* 0x00 */ char pad0[0x30];
    /* 0x30 */ void *unk30;                            /* inferred */
} CCollision;                                       /* size >= 0x34 */
extern "C" s32 Initialize__10CCollisionFv(CCollision *objet);
extern "C" CCollision *__ct__10CCollisionFv(CCollision *objet) {
    objet->unk30 = &__vt__10CCollision;
    Initialize__10CCollisionFv(objet);
    return objet;
}
extern "C" u32 mapCameraInfoIdx;
extern "C" s32 IsAddMode__Fv();
extern "C" s32 mapFIX_CAMERA_END__FP9SPI_STACKi(SPI_STACK *arg0, s32 arg1) {
    if (IsAddMode__Fv() != 0) {
        return 1;
    }
    mapCameraInfoIdx += 1;
    return 1;
}
INCLUDE_ASM("nonmatchings/game/cmapparts", mapCAMERA_INFO_END__FP9SPI_STACKi);
extern "C" u32 mapFuncPointIdx;
extern "C" void spiGetStackInt__FP9SPI_STACK(SPI_STACK *arg0);
extern "C" s32 mapFUNC_POINT__FP9SPI_STACKi(SPI_STACK *arg0, s32 arg1) {
    spiGetStackInt__FP9SPI_STACK(arg0);
    mapFuncPointIdx = 0;
    return 1;
}
INCLUDE_ASM("nonmatchings/game/cmapparts", mapFUNC_DATA__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cmapparts", mapFUNC_NAME__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cmapparts", mapFUNC_FLAG__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cmapparts", mapFUNC_FIRE_DATA__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cmapparts", mapFUNC_PLIGHT_DATA__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cmapparts", mapFUNC_ANIME_DATA__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cmapparts", mapFUNC_INVENT_DATA__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cmapparts", mapFUNC_EVENT_DATA__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cmapparts", mapFUNC_SOUND_DATA__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cmapparts", mapFUNC_EFFECT_NAME__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cmapparts", SetBound__8mgCFrameFPQ28mgCFrame9BoundInfo);
INCLUDE_ASM("nonmatchings/game/cmapparts", mapFUNC_POS__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cmapparts", SetScale__10CFuncPointFPf);
INCLUDE_ASM("nonmatchings/game/cmapparts", SetRotation__10CFuncPointFPf);
INCLUDE_ASM("nonmatchings/game/cmapparts", SetPosition__10CFuncPointFPf);
INCLUDE_ASM("nonmatchings/game/cmapparts", mapFUNC_DATA_END__FP9SPI_STACKi);
extern "C" u32 mapNowMapParts;
extern "C" u32 mapPtsFunc;
#include "gen/CFuncPointMngr.hpp"
extern "C" s32 UpdateStatus__14CFuncPointMngrFv(void *);
extern "C" s32 pGetData__17CList_9CMapParts_Fv(...);
extern "C" s32 mapFUNC_POINT_END__FP9SPI_STACKi(SPI_STACK *arg0, s32 arg1) {
    CFuncPointMngr *var_a0;

    if (mapPtsFunc != 0) {
        if (mapNowMapParts == NULL) {
            return 0;
        }
        var_a0 = (CFuncPointMngr *) (pGetData__17CList_9CMapParts_Fv(mapNowMapParts) + 0x2B0);
        goto block_5;
    }
    var_a0 = (CFuncPointMngr *) (mapMap + 0xCB0);
block_5:
    UpdateStatus__14CFuncPointMngrFv(var_a0);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/cmapparts", LoadMapFile__4CMapFPciP9mgCMemoryi);
INCLUDE_ASM("nonmatchings/game/cmapparts", SetPieceLoadSkip__4CMapFi);
INCLUDE_ASM("nonmatchings/game/cmapparts", cfgDRAW_OFF_RECT__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cmapparts", cfgOCCLUSION_PLANE__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cmapparts", cfgFUNC_DATA__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cmapparts", cfgFUNC_EVENT_DATA__FP9SPI_STACKi);
s32 cfgFUNC_DATA_END(SPI_STACK * arg0, s32 arg1) {
    mapNowFuncPoint = 0;
    return 1;
}
INCLUDE_ASM("nonmatchings/game/cmapparts", cfgWATER_SURFACE_NUM__FP9SPI_STACKi);
s32 cfgWATER_SURFACE_START(SPI_STACK *stack, int argc) {
    return 1;
}
INCLUDE_ASM("nonmatchings/game/cmapparts", cfgWATER_VERTEX__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cmapparts", cfgWATER_POS__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cmapparts", cfgWATER_PARAM__FP9SPI_STACKi);
s32 cfgWATER_SHAKE(SPI_STACK *stack, int argc) {
    return 1;
}
INCLUDE_ASM("nonmatchings/game/cmapparts", cfgWATER_SURFACE_END__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cmapparts", cfgWATER_DRAW_NUM__FP9SPI_STACKi);
extern "C" s32 __ct__7CObjectFv(void *);
extern "C" u8 __vt__9CMapWater[116];
struct inferred;
typedef struct CMapWater {
    /* 0x0 */ void *unk0;                              /* inferred */
} CMapWater;                                        /* size >= 0x4 */
extern "C" CMapWater *__ct__9CMapWaterFv(CMapWater *objet) {
    __ct__7CObjectFv((CObject *) objet);
    objet->unk0 = &__vt__9CMapWater;
    return objet;
}
INCLUDE_ASM("nonmatchings/game/cmapparts", cfgWATER_DRAW__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cmapparts", LoadCfgFile__4CMapFPciP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/cmapparts", Initialize__11CCameraInfoFv);
INCLUDE_ASM("nonmatchings/game/cmapparts", GetDrawInfo__11CCameraInfoFi);
INCLUDE_ASM("nonmatchings/game/cmapparts", Initialize__8CMapInfoFv);
INCLUDE_ASM("nonmatchings/game/cmapparts", GetImgName__8CMapInfoFi);
INCLUDE_ASM("nonmatchings/game/cmapparts", GetPCPName__8CMapInfoFi);
INCLUDE_ASM("nonmatchings/game/cmapparts", GetMapFile__8CMapInfoFPi);
INCLUDE_ASM("nonmatchings/game/cmapparts", GetAddMapFile__8CMapInfoFPi);
INCLUDE_ASM("nonmatchings/game/cmapparts", GetLightingInfo__8CMapInfoFi);
INCLUDE_ASM("nonmatchings/game/cmapparts", mapIMG__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cmapparts", mapPCP__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cmapparts", mapACTIVE_LIGHT_SET__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cmapparts", mapLIGHT_SET__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cmapparts", mapFOV__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cmapparts", mapBGCOLOR__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cmapparts", mapBGCOLOR2__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cmapparts", mapAMBIENT__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cmapparts", mapLIGHT__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cmapparts", mapPLIGHT__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cmapparts", mapFOG_ENABLE__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cmapparts", mapFOG__FP9SPI_STACKi);
s32 mapLIGHT_SET_END(SPI_STACK * arg0, s32 arg1) {
    LightingInfo = 0;
    return 1;
}
INCLUDE_ASM("nonmatchings/game/cmapparts", mapFLOOR__FP9SPI_STACKi);
extern "C" u32 MapInfo;
extern "C" s32 mapCHARA_POS__FP9SPI_STACKi(SPI_STACK *arg0, s32 arg1) {
    spiGetStackVector__FPfP9SPI_STACK(MapInfo + 0xB0, arg0);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/cmapparts", mapTIME_FLAG__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cmapparts", mapTIME_LIGHT_NUM__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cmapparts", mapDEF_FOOT__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cmapparts", mapSKY_INFO__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cmapparts", mapLENS_FLARE__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cmapparts", mapTIME_CFADE__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cmapparts", mapALL_SCISSOR__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cmapparts", mapCHARA_LIGHT_ADJUST__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cmapparts", LoadMapInfo__8CMapInfoFPciP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/cmapparts", __ct__16CMapLightingInfoFv);
INCLUDE_ASM("nonmatchings/game/cmapparts", amapIMG__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cmapparts", amapPCP__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cmapparts", AddMapInfo__8CMapInfoFPciP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/cmapparts", OutputLightData__8CMapInfoFPc);
INCLUDE_ASM("nonmatchings/game/cmapparts", Initialize__9CMapPartsFv);
INCLUDE_ASM("nonmatchings/game/cmapparts", SetName__9CMapPartsFPc);
INCLUDE_ASM("nonmatchings/game/cmapparts", SetPartsName__9CMapPartsFPc);
INCLUDE_ASM("nonmatchings/game/cmapparts", AddPiece__9CMapPartsFP17CList_9CMapPiece_);
INCLUDE_ASM("nonmatchings/game/cmapparts", SearchPiece__9CMapPartsFPc);
INCLUDE_ASM("nonmatchings/game/cmapparts", SearchPieceColType__9CMapPartsFi);
INCLUDE_ASM("nonmatchings/game/cmapparts", GetPoly__9CMapPartsFiP6CCPolyR9mgVu0FBOXi);
INCLUDE_ASM("nonmatchings/game/cmapparts", GetColPoly__9CMapPartsFP6CCPolyR9mgVu0FBOXi);
INCLUDE_ASM("nonmatchings/game/cmapparts", GetCameraPoly__9CMapPartsFP6CCPolyR9mgVu0FBOXi);
INCLUDE_ASM("nonmatchings/game/cmapparts", UpDatePosition__9CMapPartsFv);
INCLUDE_ASM("nonmatchings/game/cmapparts", SetColor__9CMapPartsFiPf);
INCLUDE_ASM("nonmatchings/game/cmapparts", GetColor__9CMapPartsFiPf);
INCLUDE_ASM("nonmatchings/game/cmapparts", GetDefColor__9CMapPartsFiPf);
INCLUDE_ASM("nonmatchings/game/cmapparts", UpdateColor__9CMapPartsFv);
INCLUDE_ASM("nonmatchings/game/cmapparts", PreDraw__9CMapPartsFv);
INCLUDE_ASM("nonmatchings/game/cmapparts", DrawSub__9CMapPartsFi);
INCLUDE_ASM("nonmatchings/game/cmapparts", DrawDirect__9CMapPieceFv);
INCLUDE_ASM("nonmatchings/game/cmapparts", Draw__9CMapPieceFv);
INCLUDE_ASM("nonmatchings/game/cmapparts", DrawStep__9CMapPartsFv);
INCLUDE_ASM("nonmatchings/game/cmapparts", CreateBoundBox__9CMapPartsFv);
INCLUDE_ASM("nonmatchings/game/cmapparts", CheckColBox__9CMapPartsFP9mgVu0FBOX);
#include "sphida.hpp"
typedef struct CMapParts_infere {
    /* 0x000 */ char pad0[0x230];
    /* 0x230 */ s32 unk230;                         /* inferred */
    /* 0x234 */ char pad234[0xC];                   /* maybe part of unk230[4]? */
    /* 0x240 */ mgVu0FBOX unk240;                   /* inferred */
    /* 0x240 */ char pad240[1];
} CMapParts_infere;                                        /* size >= 0x241 */
extern "C" s32 __as__9mgVu0FBOXFR9mgVu0FBOX(mgVu0FBOX *objet, mgVu0FBOX *arg0);
extern "C" s32 GetBBox__9CMapPartsFP9mgVu0FBOX(CMapParts_infere *objet, mgVu0FBOX *arg0) {
    s32 temp_v0;

    temp_v0 = objet->unk230;
    if (temp_v0 == 0) {
        return temp_v0;
    }
    __as__9mgVu0FBOXFR9mgVu0FBOX(arg0, &objet->unk240);
    return objet->unk230;
}
INCLUDE_ASM("nonmatchings/game/cmapparts", GetBoundBox__9CMapPartsFP9mgVu0FBOX);
INCLUDE_ASM("nonmatchings/game/cmapparts", GetBoundSphere__9CMapPartsFPf);
INCLUDE_ASM("nonmatchings/game/cmapparts", GetLWMatrix__9CMapPartsFPA4_f);
INCLUDE_ASM("nonmatchings/game/cmapparts", InsideScreen__9CMapPartsFv);
INCLUDE_ASM("nonmatchings/game/cmapparts", InsideScreen__9CMapPartsFP10COcclusioni);
INCLUDE_ASM("nonmatchings/game/cmapparts", InScreenFunc__9CMapPartsFP16InScreenFuncInfo);
INCLUDE_ASM("nonmatchings/game/cmapparts", DrawScreenFunc__9CMapPartsFP8mgCFrame);
INCLUDE_ASM("nonmatchings/game/cmapparts", Step__9CMapPartsFv);
INCLUDE_ASM("nonmatchings/game/cmapparts", AnimeStep__9CMapPartsFP15CFuncPointCheckP12CObjAnimeEnv);
INCLUDE_ASM("nonmatchings/game/cmapparts", StepFuncPoint__9CMapPartsFR15CFuncPointCheck);
typedef struct CFuncPointCheck {
    /* 0x0 */ f32 unk0;                             /* inferred */
    /* 0x4 */ s32 unk4;                             /* inferred */
} CFuncPointCheck;                                  /* size >= 0x8 */
typedef struct CMapParts_infere2 {
    /* 0x000 */ char pad0[0x1E0];
    /* 0x1E0 */ f32 unk1E0;                         /* inferred */
    /* 0x1E4 */ char pad1E4[0x118];                 /* maybe part of unk1E0[0x47]void */
    /* 0x2FC */ f32 unk2FC;                         /* inferred */
    /* 0x300 */ s32 unk300;                         /* inferred */
} CMapParts_infere2;                                        /* size >= 0x304 */
extern "C" void CopyFuncPointCheck__9CMapPartsFR15CFuncPointCheck(CMapParts_infere2 *objet, CFuncPointCheck *arg0) {
    f32 temp_f1;

    objet->unk2FC = arg0->unk0;
    objet->unk300 = arg0->unk4;
    temp_f1 = (f32) (objet->unk1E0);
    if (!(temp_f1 < 0.0f)) {
        objet->unk2FC = temp_f1;
    }
}
INCLUDE_ASM("nonmatchings/game/cmapparts", Copy__9CMapPartsFR9CMapPartsP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/cmapparts", AssignFuncAnime__9CMapPartsFP9mgCMemory);
void CList_9CObjAnime_::Initialize(void) {
    this->field_0x4 = 0;
    this->field_0x0 = 0;
}
typedef struct CMapTreasureBox_infere {
    /* 0x000 */ char pad0[0x660];
    /* 0x660 */ s32 unk660;                         /* inferred */
    /* 0x664 */ s32 unk664;                         /* inferred */
    /* 0x668 */ s32 unk668;                         /* inferred */
    /* 0x66C */ s32 unk66C;                         /* inferred */
    /* 0x670 */ s32 unk670;                         /* inferred */
    /* 0x674 */ s32 unk674;                         /* inferred */
    /* 0x678 */ s32 unk678;                         /* inferred */
} CMapTreasureBox_infere;                                  /* size >= 0x67C */
extern "C" s32 Initialize__11CCharacter2Fv(CCharacter2 *objet);
extern "C" void Initialize__15CMapTreasureBoxFv(CMapTreasureBox_infere *objet) {
    Initialize__11CCharacter2Fv((CCharacter2 *) objet);
    objet->unk660 = 0;
    objet->unk664 = 0;
    objet->unk668 = -1;
    objet->unk66C = 0;
    objet->unk670 = -1;
    objet->unk674 = 0;
    objet->unk678 = 0;
}
INCLUDE_ASM("nonmatchings/game/cmapparts", AssignFuncPoint__15CMapTreasureBoxFP10CFuncPointP9CMapParts);
#include "gen/mgCFrame.hpp"
typedef struct CMapTreasureBox {
    /* 0x00 */ char pad0[0x70];
    /* 0x70 */ mgCFrame *unk70;                     /* inferred */
} CMapTreasureBox;                                  /* size >= 0x74 */
extern "C" void GetWorldPosition0__8mgCFrameFPf(mgCFrame *objet, f32 *arg0);
extern "C" void mgZeroVectorW__FPf(f32 *arg0);
extern "C" void GetWorldPosition__15CMapTreasureBoxFPf(CMapTreasureBox *objet, f32 *arg0) {
    mgCFrame *temp_a0;

    mgZeroVectorW__FPf(arg0);
    temp_a0 = objet->unk70;
    if (temp_a0 != NULL) {
        GetWorldPosition0__8mgCFrameFPf(temp_a0, arg0);
    }
}
