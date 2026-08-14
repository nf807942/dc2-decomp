/* CVillagerPlaceInfo, CVillagerInfo
 *
 * Unité découpée par `make carve` : 69 fonctions, 24488 octets, de
 * 0x00319990 à 0x0031FB20. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

/* La pile de l'interpréteur de script d'objet. Les commandes qui ne rendent
 * qu'un code de retour ne la déréférencent pas : sa disposition reste à
 * établir. */
struct SPI_STACK;

INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", sgSystemDrawBuggy__FP11SubGameInfo);
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", CharaControl__FP6CSceneP11CPadControl_00319DB0);
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", InitBuggy__FP6CScene);
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", BuggyDamage__Fi);
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", PlayBuggyLoopSe__FP6CScenei);
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", BuggyControl__FP6CScene);
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", InitBomb__FP6CScene);
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", TakeBombCheck__Fv);
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", TakeBomb__Fv);
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", ThrowBomb__FPf);
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", BombBomb__Fv);
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", NowPutBomb__Fv);
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", BombControl__FP6CScene);
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", BombCheck__FP6CScene);
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", AnalyzeEditMap__FiP8CEditMap);
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", CountPartsType__FiP8CEditMapPii);
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", CountPartsInfoID__FiP8CEditMapPii);
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", CheckSaku__FP8CEditMapi);
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", GetTreeNum__FP8CEditMap);
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", GetHouseParts__FP8CEditMapPii);
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", CheckInfoID__FP8CEditMapii);
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", GetPartsPos__FP8CEditMapiPf);
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", AnalyzeSharlot__FP9CEditDataP8CEditMap);
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", AnalyzeStera__FP9CEditDataP8CEditMap);
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", AnalyzeBenietio__FP9CEditDataP8CEditMap);
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", GetColorType__FP10CEditPartsi);
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", AnalyzeHeim__FP9CEditDataP8CEditMap);
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", AnalyzeMoonFlower__FP9CEditDataP8CEditMap);
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", CheckLiveChara__FiP8CEditMapii);
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", EditMapInitEvent__FiP8CEditMap);
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", LoadHelpMes__FP1);
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", GetHepMesInfo__Fv);
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", CreateHelpMes__Fi);
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", StepHelpMes__Fv);
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", ShowOffOnceHelpMes__Fv);
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", DrawHelpMes__Fv);
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", ShowHelpMes__Fii);
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", ShowErrorHelpMes__Fii);
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", GetVlgrPlaceInfo__Fi);
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", GetVlgrPlaceTable__FPi);
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", GetVillagerInfo__Fi);
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", GetVillagerModelName__FiPc);
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", niNPC__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", niNPC_END__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", niPROGRESS__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", niPROGRESS_END__FP9SPI_STACKi);
s32 niPLACE(SPI_STACK *stack, int argc) {
    return 1;
}
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", niNOON_PLACE__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", niNIGHT_PLACE__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", niNPC_INFO_NUM__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", __ct__13CVillagerInfoFv);
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", niNPC_INFO__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", LoadNPCInfo__FPciP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", LoadPlaceInfo__FPciP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", vpiNPC_PLACE_NUM__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", __ct__18CVillagerPlaceInfoFv);
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", vpiNPC_PLACE__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", vpiNPC_PLACE_END__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", vpiPLACE_POS__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", vpiMOVE_TO__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", vpiWAIT__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", vpiMOTION__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", vpiTALK_OFFSET__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", vpiMOVE_MOTION__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", vpiMOVE_SPEED__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", vpiSHADOW__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", vpiGetMotionID__FPc);
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", giPROG_INFO__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", LoadGameInfo__FP9mgCMemory);
