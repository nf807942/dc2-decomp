/* CEditMap, CRocketLauncher, CEditParts, CEditPartsInfo, CEditHouse
 *
 * Unité découpée par `make carve` : 100 fonctions, 25496 octets, de
 * 0x001B16D0 à 0x001B7C50. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"
#include "gen/CRocketLauncher.hpp"

class CEditMap {
public:
    s32 Iam();
};

/* Les globales que ces accesseurs servent. Leur taille déclarée est celle que
 * le découpage leur donne, et c'est elle qui décide du `%gp_rel`. */
extern s32 CEditMapName;

/* La pile de l'interpréteur de script d'objet. Les commandes qui ne rendent
 * qu'un code de retour ne la déréférencent pas : sa disposition reste à
 * établir. */
struct SPI_STACK;
extern s32 emapInit;
extern s32 emapInitIdx;
extern s32 emapInitNum;


s32 CEditMap::Iam(void) {
    return CEditMapName;
}
INCLUDE_ASM("nonmatchings/game/ceditmap", Initialize__8CEditMapFv);
INCLUDE_ASM("nonmatchings/game/ceditmap", ClearGrid__8CEditMapFv);
INCLUDE_ASM("nonmatchings/game/ceditmap", ClearHouse__8CEditMapFv);
INCLUDE_ASM("nonmatchings/game/ceditmap", ClearAllParts__8CEditMapFv);
INCLUDE_ASM("nonmatchings/game/ceditmap", InitialPlaceParts__8CEditMapFP9CEditData);
INCLUDE_ASM("nonmatchings/game/ceditmap", GetPoly__8CEditMapFiP6CCPolyR9mgVu0FBOXi);
INCLUDE_ASM("nonmatchings/game/ceditmap", CreateTable__8CEditMapFP9mgCMemoryii);
INCLUDE_ASM("nonmatchings/game/ceditmap", __ct__10CEditPartsFv);
INCLUDE_ASM("nonmatchings/game/ceditmap", GetePartsInfo__8CEditMapFi);
INCLUDE_ASM("nonmatchings/game/ceditmap", GetePartsInfo__8CEditMapFPc);
INCLUDE_ASM("nonmatchings/game/ceditmap", GetePartsInfoAtID__8CEditMapFi);
INCLUDE_ASM("nonmatchings/game/ceditmap", GetePartsInfoAtType__8CEditMapFi);
INCLUDE_ASM("nonmatchings/game/ceditmap", GetePartsInfoAtPlaceID__8CEditMapFi);
INCLUDE_ASM("nonmatchings/game/ceditmap", eNewPlaceParts__8CEditMapFv);
INCLUDE_ASM("nonmatchings/game/ceditmap", eNewHouseInfo__8CEditMapFv);
INCLUDE_ASM("nonmatchings/game/ceditmap", GetePlaceParts__8CEditMapFi);
INCLUDE_ASM("nonmatchings/game/ceditmap", GetePlaceParts__8CEditMapFPc);
INCLUDE_ASM("nonmatchings/game/ceditmap", GetePlaceIDList__8CEditMapFPii);
INCLUDE_ASM("nonmatchings/game/ceditmap", GetRotMatrix__8CEditMapFPA4_fi);
INCLUDE_ASM("nonmatchings/game/ceditmap", GetEditAngle90__8CEditMapFi);
INCLUDE_ASM("nonmatchings/game/ceditmap", GetEditAngle__8CEditMapFi);
INCLUDE_ASM("nonmatchings/game/ceditmap", ConvEditAngle__8CEditMapFf);
INCLUDE_ASM("nonmatchings/game/ceditmap", AngleLimit__8CEditMapFi);
INCLUDE_ASM("nonmatchings/game/ceditmap", GetEditPos__8CEditMapFPfPf);
INCLUDE_ASM("nonmatchings/game/ceditmap", CmpEditAlt__8CEditMapFff);
INCLUDE_ASM("nonmatchings/game/ceditmap", GetEditAlt__8CEditMapFf);
INCLUDE_ASM("nonmatchings/game/ceditmap", GetGridPos__8CEditMapFPfPfPf);
INCLUDE_ASM("nonmatchings/game/ceditmap", GetMatrix__8CEditMapFPA4_fPfi);
INCLUDE_ASM("nonmatchings/game/ceditmap", GetInversMatrix__8CEditMapFPA4_fPA4_f);
INCLUDE_ASM("nonmatchings/game/ceditmap", ConvertParts__8CEditMapFP10CEditParts);
INCLUDE_ASM("nonmatchings/game/ceditmap", GetSameParts__8CEditMapFi);
INCLUDE_ASM("nonmatchings/game/ceditmap", BuildEditParts__8CEditMapFi);
INCLUDE_ASM("nonmatchings/game/ceditmap", GetTotalPolyn__8CEditMapFPiPi);
INCLUDE_ASM("nonmatchings/game/ceditmap", BuildEditParts__8CEditMapFPc);
INCLUDE_ASM("nonmatchings/game/ceditmap", DeleteEditParts__8CEditMapFi);
INCLUDE_ASM("nonmatchings/game/ceditmap", RemoveEditParts__8CEditMapFiPfPQ28CEditMap10RemoveInfo);
INCLUDE_ASM("nonmatchings/game/ceditmap", PlaceBurnParts__8CEditMapFv);
INCLUDE_ASM("nonmatchings/game/ceditmap", BurnEditParts__8CEditMapFPQ28CEditMap10RemoveInfo);
INCLUDE_ASM("nonmatchings/game/ceditmap", PlaceEditParts__8CEditMapFPcPfPf);
INCLUDE_ASM("nonmatchings/game/ceditmap", PlaceEditParts__8CEditMapFiP13EP_PLACE_INFOPfPfPi);
INCLUDE_ASM("nonmatchings/game/ceditmap", PlaceRiverParts__8CEditMapFPf);
INCLUDE_ASM("nonmatchings/game/ceditmap", CreatePlaceLog__8CEditMapFiP13EP_PLACE_INFO);
INCLUDE_ASM("nonmatchings/game/ceditmap", GetNearParts__8CEditMapFP14CEditPartsInfoPffPP10CEditPartsi);
INCLUDE_ASM("nonmatchings/game/ceditmap", GetNearParts__8CEditMapFR9mgVu0FBOXPP10CEditPartsi);
INCLUDE_ASM("nonmatchings/game/ceditmap", GetePlaceParts__8CEditMapFPf);
INCLUDE_ASM("nonmatchings/game/ceditmap", GetePlaceParts__8CEditMapFPfPP10CEditPartsi);
INCLUDE_ASM("nonmatchings/game/ceditmap", CheckEditParts__8CEditMapFP14CEditPartsInfoPffP13EP_PLACE_INFO);
INCLUDE_ASM("nonmatchings/game/ceditmap", GetEditPartsAlt__8CEditMapFP14CEditPartsInfoPff);
INCLUDE_ASM("nonmatchings/game/ceditmap", MagnetParts__8CEditMapFP14CEditPartsInfoPfPfPP10CEditPartsi);
INCLUDE_ASM("nonmatchings/game/ceditmap", MagnetParts__8CEditMapFP14CEditPartsInfoPfPf);
INCLUDE_ASM("nonmatchings/game/ceditmap", CheckWallEditParts__8CEditMapFP14CEditPartsInfoPfiiP13EP_PLACE_INFO);
INCLUDE_ASM("nonmatchings/game/ceditmap", Step__8CEditMapFv);
INCLUDE_ASM("nonmatchings/game/ceditmap", PreDraw__8CEditMapFPf);
INCLUDE_ASM("nonmatchings/game/ceditmap", DrawSub__8CEditMapFi);
s32 emapEDIT_RIVER(SPI_STACK *stack, int argc) {
    return 1;
}
INCLUDE_ASM("nonmatchings/game/ceditmap", emapRIVER_PARTS_NAME__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceditmap", emapMASK_PARTS_NAME__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceditmap", emapWATER_PARTS_NAME__FP9SPI_STACKi);
s32 emapEDIT_RIVER_END(SPI_STACK *stack, int argc) {
    return 1;
}
INCLUDE_ASM("nonmatchings/game/ceditmap", emapFIX_EPARTS_START__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceditmap", emapFIX_EPARTS__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceditmap", emapFIX_EPARTS_END__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceditmap", emapINIT_EPARTS_START__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceditmap", emapINIT_EPARTS__FP9SPI_STACKi);
s32 emapINIT_EPARTS_END(SPI_STACK * arg0, s32 arg1) {
    emapInitNum = 0;
    emapInitIdx = 0;
    emapInit = 0;
    return 1;
}
INCLUDE_ASM("nonmatchings/game/ceditmap", LoadEditInfo__8CEditMapFPciP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/ceditmap", __ct__14CEditPartsInfoFv);
INCLUDE_ASM("nonmatchings/game/ceditmap", Initialize__14CEditPartsInfoFv);
INCLUDE_ASM("nonmatchings/game/ceditmap", GetPartsType__14CEditPartsInfoFv);
INCLUDE_ASM("nonmatchings/game/ceditmap", CreateBox__14CEditPartsInfoFv);
INCLUDE_ASM("nonmatchings/game/ceditmap", GetPartsHeight__14CEditPartsInfoFv);
INCLUDE_ASM("nonmatchings/game/ceditmap", GetPartsMaxWidth__14CEditPartsInfoFv);
INCLUDE_ASM("nonmatchings/game/ceditmap", GetMaterial__14CEditPartsInfoFi);
INCLUDE_ASM("nonmatchings/game/ceditmap", GetDefColor__14CEditPartsInfoFiPf);
INCLUDE_ASM("nonmatchings/game/ceditmap", LiveChara__10CEditHouseFv);
INCLUDE_ASM("nonmatchings/game/ceditmap", Initialize__10CEditPartsFv);
INCLUDE_ASM("nonmatchings/game/ceditmap", StandardPos__Ff);
INCLUDE_ASM("nonmatchings/game/ceditmap", SetPosition__10CEditPartsFPf);
INCLUDE_ASM("nonmatchings/game/ceditmap", SetPosition__10CEditPartsFfff);
INCLUDE_ASM("nonmatchings/game/ceditmap", GetPosition__10CEditPartsFPf);
INCLUDE_ASM("nonmatchings/game/ceditmap", GetLocalPos__10CEditPartsFPf);
INCLUDE_ASM("nonmatchings/game/ceditmap", UpDatePosition__10CEditPartsFv);
INCLUDE_ASM("nonmatchings/game/ceditmap", GetInfoID__10CEditPartsFv);
INCLUDE_ASM("nonmatchings/game/ceditmap", GetLiveNPC__10CEditPartsFv);
INCLUDE_ASM("nonmatchings/game/ceditmap", IsWallParts__10CEditPartsFv);
INCLUDE_ASM("nonmatchings/game/ceditmap", IsFence__10CEditPartsFv);
INCLUDE_ASM("nonmatchings/game/ceditmap", IsBurn__10CEditPartsFv);
INCLUDE_ASM("nonmatchings/game/ceditmap", GetFenceSide__10CEditPartsFPfPf);
INCLUDE_ASM("nonmatchings/game/ceditmap", GetWallPlane__10CEditPartsFiPQ210CEditParts8WallInfo);
INCLUDE_ASM("nonmatchings/game/ceditmap", GetWallGroupNum__10CEditPartsFv);
INCLUDE_ASM("nonmatchings/game/ceditmap", GetPartsType__10CEditPartsFv);
INCLUDE_ASM("nonmatchings/game/ceditmap", Copy__10CEditPartsFR9CMapPartsP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/ceditmap", CheckTerritory__10CEditPartsFP10CEditParts);
INCLUDE_ASM("nonmatchings/game/ceditmap", CheckColorUpdate__10CEditPartsFv);
INCLUDE_ASM("nonmatchings/game/ceditmap", EditPartsCmpColor__FPfPf);
INCLUDE_ASM("nonmatchings/game/ceditmap", SetPos__15CRocketLauncherFPfPfPf);
INCLUDE_ASM("nonmatchings/game/ceditmap", Step__15CRocketLauncherFv);
INCLUDE_ASM("nonmatchings/game/ceditmap", Draw__15CRocketLauncherFv);
void CRocketLauncher::Initialize(void) {
    this->field_0x0 = -1;
    this->field_0x150 = 0;
    this->field_0x154 = 0;
    this->field_0x174 = 0;
    this->field_0x160 = -1;
    this->field_0x164 = 0;
}
