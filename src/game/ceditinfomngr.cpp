/* CEditInfoMngr, CEditMap
 *
 * Unité découpée par `make carve` : 61 fonctions, 17280 octets, de
 * 0x002A5B10 à 0x002A9FF0. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"
#include "gen/CEditInfoMngr.hpp"
struct CEditPartsInfo;
struct ePlaceData;


INCLUDE_ASM("nonmatchings/game/ceditinfomngr", TitleModeDraw__Fv);
INCLUDE_ASM("nonmatchings/game/ceditinfomngr", TitleMapDraw__Fv);
INCLUDE_ASM("nonmatchings/game/ceditinfomngr", CalcPushAlpha__FiPf);
INCLUDE_ASM("nonmatchings/game/ceditinfomngr", TitleMCCheckInit__Fi);
INCLUDE_ASM("nonmatchings/game/ceditinfomngr", TitleMCCheckKey__Fv);
INCLUDE_ASM("nonmatchings/game/ceditinfomngr", TitleMCCheckDraw__Fv);
s32 DCTitleStep(s32 phase) {
    return 0;
}
INCLUDE_ASM("nonmatchings/game/ceditinfomngr", TitleCopyRightInit__Fv);
INCLUDE_ASM("nonmatchings/game/ceditinfomngr", TitleCopyRightStep__Fv);
INCLUDE_ASM("nonmatchings/game/ceditinfomngr", TitleCopyRightDraw__Fv);
INCLUDE_ASM("nonmatchings/game/ceditinfomngr", TitleHDDInstallInit__Fv);
INCLUDE_ASM("nonmatchings/game/ceditinfomngr", TitleHDDInstallKey__Fv);
INCLUDE_ASM("nonmatchings/game/ceditinfomngr", DrawMenuDl__Fiiiif);
INCLUDE_ASM("nonmatchings/game/ceditinfomngr", TitleHDDInstallDraw__Fv);
INCLUDE_ASM("nonmatchings/game/ceditinfomngr", CheckAppInstallForTitle__Fv);
INCLUDE_ASM("nonmatchings/game/ceditinfomngr", CheckHDDInstall__Fv);
INCLUDE_ASM("nonmatchings/game/ceditinfomngr", TitleLangSelInit__FP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/ceditinfomngr", TitleLangSelKey__Fv);
INCLUDE_ASM("nonmatchings/game/ceditinfomngr", GetSelectLanguageNo__Fv);
INCLUDE_ASM("nonmatchings/game/ceditinfomngr", TitleLangSelDraw__Fv);
INCLUDE_ASM("nonmatchings/game/ceditinfomngr", InitSoundViewerMain__F13INIT_LOOP_ARG);
void FinishSoundVieweMain(void) {
}
s32 LoopSoundViewerMain(void) {
    return 1;
}
void CEditInfoMngr::Initialize(void) {
    this->field_0x0 = 0;
    this->field_0x4 = 0;
    this->field_0x8 = 0;
    this->field_0xC = 0;
    this->field_0x10 = 0;
    this->field_0x14 = 0;
}
void CEditInfoMngr::SetePartsInfoTable(CEditPartsInfo * arg0, s32 arg1) {
    this->field_0x0 = arg1;
    this->field_0x4 = arg0;
}
void CEditInfoMngr::SeteFixPartsTable(ePlaceData * arg0, s32 arg1) {
    this->field_0x8 = arg1;
    this->field_0xC = arg0;
}
INCLUDE_ASM("nonmatchings/game/ceditinfomngr", GetePartsInfo__13CEditInfoMngrFi);
INCLUDE_ASM("nonmatchings/game/ceditinfomngr", GetePartsInfo__13CEditInfoMngrFPc);
INCLUDE_ASM("nonmatchings/game/ceditinfomngr", GetePartsInfoAtID__13CEditInfoMngrFi);
INCLUDE_ASM("nonmatchings/game/ceditinfomngr", GetePartsInfoAtType__13CEditInfoMngrFi);
INCLUDE_ASM("nonmatchings/game/ceditinfomngr", emapEDIT_PARTS_NUM__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceditinfomngr", emapEDIT_PARTS__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceditinfomngr", emapID__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceditinfomngr", emapPARTS_NAME__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceditinfomngr", emapPARTS_ATR__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceditinfomngr", emapPARTS_MATERIAL__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceditinfomngr", emapPARTS_COMMENT__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceditinfomngr", emapCPOINT__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceditinfomngr", emapWEIGHT__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceditinfomngr", emapGEO_STONE__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceditinfomngr", emapMAX_NUM__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceditinfomngr", emapPAINT_NUM__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceditinfomngr", emapPAINT_USED__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceditinfomngr", emapPARTS_TYPE__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceditinfomngr", emapPLACE_EPS__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceditinfomngr", emapMAP_NO__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceditinfomngr", emapPOLYN__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceditinfomngr", emapGROUND_PARTS__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceditinfomngr", emapBLOCK_PARTS__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceditinfomngr", emapRIVER_PARTS__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceditinfomngr", emapFENCE_PARTS__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceditinfomngr", emapRECT__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceditinfomngr", emapPLACE_RECT__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceditinfomngr", emapPLACE_RECT_END__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceditinfomngr", emapPARTS_RECT__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceditinfomngr", emapPARTS_RECT_END__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceditinfomngr", emapPUT_RECT__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceditinfomngr", emapPUT_RECT_END__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceditinfomngr", emapEDIT_PARTS_END__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceditinfomngr", LoadEditInfo__13CEditInfoMngrFPciP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/ceditinfomngr", GetEvent__8CEditMapFPfiP12MapEventInfo);
