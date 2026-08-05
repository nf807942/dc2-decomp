/* CEditInfoMngr, CEditMap
 *
 * Unité découpée par `make carve` : 61 fonctions, 17280 octets, de
 * 0x002A5B10 à 0x002A9FF0. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

INCLUDE_ASM("nonmatchings/ceditinfomngr", TitleModeDraw__Fv);
INCLUDE_ASM("nonmatchings/ceditinfomngr", TitleMapDraw__Fv);
INCLUDE_ASM("nonmatchings/ceditinfomngr", CalcPushAlpha__FiPf);
INCLUDE_ASM("nonmatchings/ceditinfomngr", TitleMCCheckInit__Fi);
INCLUDE_ASM("nonmatchings/ceditinfomngr", TitleMCCheckKey__Fv);
INCLUDE_ASM("nonmatchings/ceditinfomngr", TitleMCCheckDraw__Fv);
INCLUDE_ASM("nonmatchings/ceditinfomngr", DCTitleStep__Fi);
INCLUDE_ASM("nonmatchings/ceditinfomngr", TitleCopyRightInit__Fv);
INCLUDE_ASM("nonmatchings/ceditinfomngr", TitleCopyRightStep__Fv);
INCLUDE_ASM("nonmatchings/ceditinfomngr", TitleCopyRightDraw__Fv);
INCLUDE_ASM("nonmatchings/ceditinfomngr", TitleHDDInstallInit__Fv);
INCLUDE_ASM("nonmatchings/ceditinfomngr", TitleHDDInstallKey__Fv);
INCLUDE_ASM("nonmatchings/ceditinfomngr", DrawMenuDl__Fiiiif);
INCLUDE_ASM("nonmatchings/ceditinfomngr", TitleHDDInstallDraw__Fv);
INCLUDE_ASM("nonmatchings/ceditinfomngr", CheckAppInstallForTitle__Fv);
INCLUDE_ASM("nonmatchings/ceditinfomngr", CheckHDDInstall__Fv);
INCLUDE_ASM("nonmatchings/ceditinfomngr", TitleLangSelInit__FP9mgCMemory);
INCLUDE_ASM("nonmatchings/ceditinfomngr", TitleLangSelKey__Fv);
INCLUDE_ASM("nonmatchings/ceditinfomngr", GetSelectLanguageNo__Fv);
INCLUDE_ASM("nonmatchings/ceditinfomngr", TitleLangSelDraw__Fv);
INCLUDE_ASM("nonmatchings/ceditinfomngr", InitSoundViewerMain__F13INIT_LOOP_ARG);
INCLUDE_ASM("nonmatchings/ceditinfomngr", FinishSoundVieweMain__Fv);
INCLUDE_ASM("nonmatchings/ceditinfomngr", LoopSoundViewerMain__Fv);
INCLUDE_ASM("nonmatchings/ceditinfomngr", Initialize__13CEditInfoMngrFv);
INCLUDE_ASM("nonmatchings/ceditinfomngr", SetePartsInfoTable__13CEditInfoMngrFP14CEditPartsInfoi);
INCLUDE_ASM("nonmatchings/ceditinfomngr", SeteFixPartsTable__13CEditInfoMngrFP10ePlaceDatai);
INCLUDE_ASM("nonmatchings/ceditinfomngr", GetePartsInfo__13CEditInfoMngrFi);
INCLUDE_ASM("nonmatchings/ceditinfomngr", GetePartsInfo__13CEditInfoMngrFPc);
INCLUDE_ASM("nonmatchings/ceditinfomngr", GetePartsInfoAtID__13CEditInfoMngrFi);
INCLUDE_ASM("nonmatchings/ceditinfomngr", GetePartsInfoAtType__13CEditInfoMngrFi);
INCLUDE_ASM("nonmatchings/ceditinfomngr", emapEDIT_PARTS_NUM__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/ceditinfomngr", emapEDIT_PARTS__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/ceditinfomngr", emapID__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/ceditinfomngr", emapPARTS_NAME__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/ceditinfomngr", emapPARTS_ATR__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/ceditinfomngr", emapPARTS_MATERIAL__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/ceditinfomngr", emapPARTS_COMMENT__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/ceditinfomngr", emapCPOINT__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/ceditinfomngr", emapWEIGHT__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/ceditinfomngr", emapGEO_STONE__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/ceditinfomngr", emapMAX_NUM__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/ceditinfomngr", emapPAINT_NUM__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/ceditinfomngr", emapPAINT_USED__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/ceditinfomngr", emapPARTS_TYPE__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/ceditinfomngr", emapPLACE_EPS__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/ceditinfomngr", emapMAP_NO__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/ceditinfomngr", emapPOLYN__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/ceditinfomngr", emapGROUND_PARTS__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/ceditinfomngr", emapBLOCK_PARTS__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/ceditinfomngr", emapRIVER_PARTS__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/ceditinfomngr", emapFENCE_PARTS__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/ceditinfomngr", emapRECT__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/ceditinfomngr", emapPLACE_RECT__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/ceditinfomngr", emapPLACE_RECT_END__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/ceditinfomngr", emapPARTS_RECT__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/ceditinfomngr", emapPARTS_RECT_END__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/ceditinfomngr", emapPUT_RECT__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/ceditinfomngr", emapPUT_RECT_END__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/ceditinfomngr", emapEDIT_PARTS_END__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/ceditinfomngr", LoadEditInfo__13CEditInfoMngrFPciP9mgCMemory);
INCLUDE_ASM("nonmatchings/ceditinfomngr", GetEvent__8CEditMapFPfiP12MapEventInfo);
