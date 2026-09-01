/* CMap, CMapParts, CMapWater, CPartsGroup, CFuncPoint, CObjAnime, CList_14PartsGroupData_, CList_P9CMapParts_, CObject
 *
 * Unité découpée par `make carve` : 67 fonctions, 15988 octets, de
 * 0x0015D920 à 0x00161970. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"
#include "gen/CList_14PartsGroupData_.hpp"
#include "gen/CList_P9CMapParts_.hpp"

class CMap {
public:
    s32 Iam();
};

/* Les globales que ces accesseurs servent. Leur taille déclarée est celle que
 * le découpage leur donne, et c'est elle qui décide du `%gp_rel`. */
extern s32 CMapName;

s32 CMap::Iam(void) {
    return CMapName;
}
INCLUDE_ASM("nonmatchings/game/cmap", Initialize__11CPartsGroupFv);
INCLUDE_ASM("nonmatchings/game/cmap", Add__11CPartsGroupFP23CList_14PartsGroupData_);
INCLUDE_ASM("nonmatchings/game/cmap", Initialize__9CMapWaterFv);
INCLUDE_ASM("nonmatchings/game/cmap", Clear__9CMapWaterFv);
INCLUDE_ASM("nonmatchings/game/cmap", GetPartsGroup__4CMapFi);
INCLUDE_ASM("nonmatchings/game/cmap", AddPartsGroup__4CMapFPcP9CMapPartsP9mgCMemory);
void CList_14PartsGroupData_::Initialize(void) {
    this->field_0x4 = 0;
    this->field_0x0 = 0;
}
INCLUDE_ASM("nonmatchings/game/cmap", SearchPartsGroup__4CMapFPc);
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
INCLUDE_ASM("nonmatchings/game/cmap", GetBBox__4CMapFP9mgVu0FBOX);
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
INCLUDE_ASM("nonmatchings/game/cmap", GetShow__7CObjectFv);
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
INCLUDE_ASM("nonmatchings/game/cmap", CreateMap__4CMapFP11CMdsListSetP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/cmap", AssignFuncPoint__4CMapFP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/cmap", __ct__9CObjAnimeFv);
INCLUDE_ASM("nonmatchings/game/cmap", CreateTrBox__4CMapFP15CMapTreasureBoxiP9mgCMemory);
