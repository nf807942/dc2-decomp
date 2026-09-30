/* CMap, CMapParts, CMapWater, CPartsGroup, CFuncPoint, CObjAnime, CList_14PartsGroupData_, CList_P9CMapParts_, CObject
 *
 * Unité découpée par `make carve` : 67 fonctions, 15988 octets, de
 * 0x0015D920 à 0x00161970. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"
#include "gen/CObjAnime.hpp"
#include "gen/CPartsGroup.hpp"
#include "gen/CList_14PartsGroupData_.hpp"
#include "gen/CList_P9CMapParts_.hpp"

class CMap {
public:
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

    s32 Iam();
};

/* Les globales que ces accesseurs servent. Leur taille déclarée est celle que
 * le découpage leur donne, et c'est elle qui décide du `%gp_rel`. */
extern s32 CMapName;

s32 CMap::Iam(void) {
    return CMapName;
}
void CPartsGroup::Initialize(void) {
    this->field_0x0 = 0;
    this->field_0x8 = 0;
    this->field_0x4 = 0;
    this->field_0xC = 0;
}
INCLUDE_ASM("nonmatchings/game/cmap", Add__11CPartsGroupFP23CList_14PartsGroupData_);
INCLUDE_ASM("nonmatchings/game/cmap", Initialize__9CMapWaterFv);
INCLUDE_ASM("nonmatchings/game/cmap", Clear__9CMapWaterFv);
INCLUDE_ASM("nonmatchings/game/cmap", GetPartsGroup__4CMapFi);
INCLUDE_ASM("nonmatchings/game/cmap", AddPartsGroup__4CMapFPcP9CMapPartsP9mgCMemory);
void CList_14PartsGroupData_::Initialize(void) {
    this->field_0x4 = 0;
    this->field_0x0 = 0;
}
extern "C" s32 GetPartsGroup__4CMapFi(void *, s32);
extern "C" s32 SearchPartsGroupNo__4CMapFPc(...);
extern "C" void SearchPartsGroup__4CMapFPc(CMap *objet, s8 *arg0) {
    GetPartsGroup__4CMapFi(objet, SearchPartsGroupNo__4CMapFPc(objet, arg0));
}
INCLUDE_ASM("nonmatchings/game/cmap", SearchPartsGroupNo__4CMapFPc);
INCLUDE_ASM("nonmatchings/game/cmap", SerachEmptyPartsGroupNo__4CMapFv);
INCLUDE_ASM("nonmatchings/game/cmap", Initialize__4CMapFv);
INCLUDE_ASM("nonmatchings/game/cmap", SetPlacePartsBuff__4CMapFP9mgCMemoryi);
INCLUDE_ASM("nonmatchings/game/cmap", __ct__9CMapPartsFv);
INCLUDE_ASM("nonmatchings/game/cmap", GetPlacPartsTable__4CMapFPi);
INCLUDE_ASM("nonmatchings/game/cmap", SetCameraInfoTable__4CMapFP11CCameraInfoi);
INCLUDE_ASM("nonmatchings/game/cmap", GetCameraInfo__4CMapFi);
INCLUDE_ASM("nonmatchings/game/cmap", NewPlaceParts__4CMapFv);
INCLUDE_ASM("nonmatchings/game/cmap", SearchMDS__4CMapFPc);
INCLUDE_ASM("nonmatchings/game/cmap", CreateEffect__4CMapFPUiiP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/cmap", SaerchEffectIndex__4CMapFPc);
INCLUDE_ASM("nonmatchings/game/cmap", AddParts__4CMapFP17CList_9CMapParts_);
INCLUDE_ASM("nonmatchings/game/cmap", GetParts__4CMapFPc);
INCLUDE_ASM("nonmatchings/game/cmap", CreateDrawRect__4CMapFP9mgCMemoryP9mgVu0FBOXP9mgVu0FBOXi);
void CList_P9CMapParts_::Initialize(void) {
    this->field_0x4 = 0;
    this->field_0x0 = 0;
}
INCLUDE_ASM("nonmatchings/game/cmap", CreateOcclusion__4CMapFPA4_f);
INCLUDE_ASM("nonmatchings/game/cmap", PlaceParts__4CMapFPcPfPfPfP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/cmap", PlacePartsEnd__4CMapFv);
INCLUDE_ASM("nonmatchings/game/cmap", ClearPlaceParts__4CMapFv);
INCLUDE_ASM("nonmatchings/game/cmap", GetPlaceParts__4CMapFPc);
INCLUDE_ASM("nonmatchings/game/cmap", GetPlaceParts__4CMapFi);
INCLUDE_ASM("nonmatchings/game/cmap", ConvertParts__4CMapFP9CMapParts);
INCLUDE_ASM("nonmatchings/game/cmap", GetPlaceParts__4CMapFP9mgVu0FBOXPP9CMapPartsi);
INCLUDE_ASM("nonmatchings/game/cmap", GetPlaceColParts__4CMapFP9mgVu0FBOXPP9CMapPartsi);
INCLUDE_ASM("nonmatchings/game/cmap", CreateFuncCheck__4CMapFP15CFuncPointCheck);
struct inferred;
#include "sphida.hpp"
typedef struct CMap_infere {
    /* 0x000 */ char pad0[0x334];
    /* 0x334 */ s32 unk334;                         /* inferred */
    /* 0x338 */ char pad338[8];                     /* maybe part of unk334[3]void */
    /* 0x340 */ mgVu0FBOX unk340;                   /* inferred */
    /* 0x340 */ char pad340[1];
} CMap_infere;                                             /* size >= 0x341 */
extern "C" s32 __as__9mgVu0FBOXFR9mgVu0FBOX(...);
extern "C" s32 GetBBox__4CMapFP9mgVu0FBOX(CMap_infere *objet, mgVu0FBOX *arg0) {
    __as__9mgVu0FBOXFR9mgVu0FBOX(arg0, &objet->unk340);
    return objet->unk334;
}
INCLUDE_ASM("nonmatchings/game/cmap", PreDraw__4CMapFPf);
INCLUDE_ASM("nonmatchings/game/cmap", GetCharaLight__4CMapFP9mgCObjectP10CFuncPointii);
INCLUDE_ASM("nonmatchings/game/cmap", SetFuncPLight__4CMapFPfP15CFuncPointCheck);
INCLUDE_ASM("nonmatchings/game/cmap", __ct__10CFuncPointFv);
INCLUDE_ASM("nonmatchings/game/cmap", ResetFuncPLight__4CMapFi);
INCLUDE_ASM("nonmatchings/game/cmap", DrawSub__4CMapFi);
INCLUDE_ASM("nonmatchings/game/cmap", Draw__9CMapPartsFv);
INCLUDE_ASM("nonmatchings/game/cmap", DrawDirect__9CMapPartsFv);
INCLUDE_ASM("nonmatchings/game/cmap", DrawEffect__4CMapFv);
INCLUDE_ASM("nonmatchings/game/cmap", DrawFireEffect__4CMapFi);
INCLUDE_ASM("nonmatchings/game/cmap", DrawFireRaster__4CMapFv);
INCLUDE_ASM("nonmatchings/game/cmap", DrawWater__4CMapFP9mgCCameraP10mgCTextureP10mgCTexture);
INCLUDE_ASM("nonmatchings/game/cmap", DrawTrBox__4CMapFv);
extern "C" s32 GetShow__7CObjectFv(void *objet) {
    return *(s32 *) ((u8 *) objet + 0x64);
}
INCLUDE_ASM("nonmatchings/game/cmap", GetPoly__4CMapFiP6CCPolyR9mgVu0FBOXi);
INCLUDE_ASM("nonmatchings/game/cmap", GetColPoly__4CMapFP6CCPolyR9mgVu0FBOXi);
INCLUDE_ASM("nonmatchings/game/cmap", GetCameraPoly__4CMapFP6CCPolyR9mgVu0FBOXi);
INCLUDE_ASM("nonmatchings/game/cmap", GetTrBoxColPoly__4CMapFP6CCPolyPfi);
INCLUDE_ASM("nonmatchings/game/cmap", GetFixCameraPos__4CMapFPfPf);
INCLUDE_ASM("nonmatchings/game/cmap", FixCameraPartsOnOff__4CMapFPf);
INCLUDE_ASM("nonmatchings/game/cmap", GetEvent__4CMapFPfiP12MapEventInfo);
INCLUDE_ASM("nonmatchings/game/cmap", InScreenFunc__4CMapFP16InScreenFuncInfo);
INCLUDE_ASM("nonmatchings/game/cmap", DrawScreenFunc__4CMapFP8mgCFrame);
INCLUDE_ASM("nonmatchings/game/cmap", EffectStep__4CMapFv);
INCLUDE_ASM("nonmatchings/game/cmap", AnimeStep__4CMapFP12CObjAnimeEnv);
INCLUDE_ASM("nonmatchings/game/cmap", Step__4CMapFv);
INCLUDE_ASM("nonmatchings/game/cmap", GetSeSrcVolPan__4CMapFPiPfPfi);
extern "C" s32 GetAddMapFile__8CMapInfoFPi(void *, s32 *);
extern "C" s32 GetMapFile__8CMapInfoFPi(void *, s32 *);
#include "gen/CMapInfo.hpp"
struct CMdsListSet {
    s32 field_0;
    char pad_4[0x8C];
    s32 field_90;
};
#include "menu.hpp"
extern "C" s32 LoadMapFile__4CMapFPciP9mgCMemoryi(...);
extern "C" void CreateMap__4CMapFP11CMdsListSetP9mgCMemory(CMap *objet, CMdsListSet *arg0, mgCMemory *arg1) {
    s32 sp3C;
    s8 *temp_v0;

    temp_v0 = (s8 *) (GetAddMapFile__8CMapInfoFPi((CMapInfo *) objet, &sp3C));
    if (temp_v0 != NULL) {
        if (sp3C > 0) {
            LoadMapFile__4CMapFPciP9mgCMemoryi(objet, temp_v0, sp3C, arg1, 1);
        }
    }
    LoadMapFile__4CMapFPciP9mgCMemoryi(objet, GetMapFile__8CMapInfoFPi((CMapInfo *) objet, &sp3C), sp3C, arg1, 0);
}
INCLUDE_ASM("nonmatchings/game/cmap", AssignFuncPoint__4CMapFP9mgCMemory);
CObjAnime::CObjAnime(void) {
    this->field_0x4 = 0;
    this->field_0x8 = 0;
    this->field_0xC = 0;
    this->field_0x0 = 0;
    this->field_0x14 = 0;
    this->field_0x10 = 0;
}
INCLUDE_ASM("nonmatchings/game/cmap", CreateTrBox__4CMapFP15CMapTreasureBoxiP9mgCMemory);
