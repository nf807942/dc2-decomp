/* CBaseMenuClass, CMenuInter, CMENU_USERPARAM, MENU_ASKMODE_PARA, MENU_SWAPITEM_INFO
 *
 * Unité découpée par `make carve` : 65 fonctions, 24484 octets, de
 * 0x00237AD0 à 0x0023DC00. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

INCLUDE_ASM("nonmatchings/cbasemenuclass", Initialize__10CMenuInterFi);
INCLUDE_ASM("nonmatchings/cbasemenuclass", MenuCommonBaseDataEnter__FP9mgCMemoryPUiii);
INCLUDE_ASM("nonmatchings/cbasemenuclass", MenuBaseTextureReEnter__Fv);
INCLUDE_ASM("nonmatchings/cbasemenuclass", InitEnd__10CMenuInterFv);
INCLUDE_ASM("nonmatchings/cbasemenuclass", PushOk__10CMenuInterFv);
INCLUDE_ASM("nonmatchings/cbasemenuclass", ReadBGTexture__10CMenuInterFii);
INCLUDE_ASM("nonmatchings/cbasemenuclass", MenuInternSelectKey__Fv);
INCLUDE_ASM("nonmatchings/cbasemenuclass", MenuInternSelectDraw__Fv);
INCLUDE_ASM("nonmatchings/cbasemenuclass", CopyActiveItemAndWeapon__Fii);
INCLUDE_ASM("nonmatchings/cbasemenuclass", CopyActiveIconTexture__FPP10mgCTextureiPUi);
INCLUDE_ASM("nonmatchings/cbasemenuclass", MenuDebugModeDraw__Fv);
INCLUDE_ASM("nonmatchings/cbasemenuclass", BookshelfMessageMake__FP6ClsMesiii);
INCLUDE_ASM("nonmatchings/cbasemenuclass", DrawTrushMenuMessage__Fv);
INCLUDE_ASM("nonmatchings/cbasemenuclass", __ct__14CBaseMenuClassFv);
INCLUDE_ASM("nonmatchings/cbasemenuclass", SetTexBlock__14CBaseMenuClassFPi);
INCLUDE_ASM("nonmatchings/cbasemenuclass", DeleteTexBlock__14CBaseMenuClassFv);
INCLUDE_ASM("nonmatchings/cbasemenuclass", MenuItemCommnadSelectPrepare__14CBaseMenuClassFP13CGameDataUsedii);
INCLUDE_ASM("nonmatchings/cbasemenuclass", MenuItemMoveItemCommand__14CBaseMenuClassFP13CGameDataUsediiP16CMenuPosDataFormi);
INCLUDE_ASM("nonmatchings/cbasemenuclass", MenuItemCommandSelect__14CBaseMenuClassFii);
INCLUDE_ASM("nonmatchings/cbasemenuclass", SetItemCmdMsgPos__14CBaseMenuClassFPi);
INCLUDE_ASM("nonmatchings/cbasemenuclass", MenuHowMuchNumSelect__FiP13CGameDataUsedi);
INCLUDE_ASM("nonmatchings/cbasemenuclass", MenuItemAskMode_HowMuch__14CBaseMenuClassFii);
INCLUDE_ASM("nonmatchings/cbasemenuclass", CheckTrushWeapon__FP13CGameDataUsed);
INCLUDE_ASM("nonmatchings/cbasemenuclass", CheckSpectolFusion__14CBaseMenuClassFP13CGameDataUsediP16CMenuPosDataForm);
INCLUDE_ASM("nonmatchings/cbasemenuclass", UpdataInfoSpectolBreakItem__FP7CDC2MesP13CGameDataUsedi);
INCLUDE_ASM("nonmatchings/cbasemenuclass", CheckEquipFishRod__FP13CGameDataUsed);
INCLUDE_ASM("nonmatchings/cbasemenuclass", IsSpectolTrans__14CBaseMenuClassFii);
INCLUDE_ASM("nonmatchings/cbasemenuclass", IsSpectolFusion__14CBaseMenuClassFii);
INCLUDE_ASM("nonmatchings/cbasemenuclass", IsDispTrushCommand__FP13CGameDataUsed);
INCLUDE_ASM("nonmatchings/cbasemenuclass", IsTrush__14CBaseMenuClassFii);
INCLUDE_ASM("nonmatchings/cbasemenuclass", IsItemUseNum__14CBaseMenuClassFiiiP13CGameDataUsedP14CItemUseTarget);
INCLUDE_ASM("nonmatchings/cbasemenuclass", SelectInGiftBox__14CBaseMenuClassFii);
INCLUDE_ASM("nonmatchings/cbasemenuclass", SetConditionHowMuchBoard__Fv);
INCLUDE_ASM("nonmatchings/cbasemenuclass", SetAskHowMuchItemNum__14CBaseMenuClassFP18MENU_SWAPITEM_INFOP13CGameDataUsed);
INCLUDE_ASM("nonmatchings/cbasemenuclass", SetAskParam__14CBaseMenuClassFP17MENU_ASKMODE_PARA);
INCLUDE_ASM("nonmatchings/cbasemenuclass", ExeScript__14CBaseMenuClassFPc);
INCLUDE_ASM("nonmatchings/cbasemenuclass", ExtendCommand__14CBaseMenuClassFii);
INCLUDE_ASM("nonmatchings/cbasemenuclass", SelectMakeObject__14CBaseMenuClassFi);
INCLUDE_ASM("nonmatchings/cbasemenuclass", IsAskEnd__14CBaseMenuClassFiP16CMenuPosDataForm);
INCLUDE_ASM("nonmatchings/cbasemenuclass", FadeInMenu__14CBaseMenuClassFif);
INCLUDE_ASM("nonmatchings/cbasemenuclass", FadeOutMenu__14CBaseMenuClassFif);
INCLUDE_ASM("nonmatchings/cbasemenuclass", FadeCheckMenu__14CBaseMenuClassFv);
INCLUDE_ASM("nonmatchings/cbasemenuclass", SetPreCmdTrush__FP14CBaseMenuClassiP13CGameDataUsedP16CMenuPosDataForm);
INCLUDE_ASM("nonmatchings/cbasemenuclass", SetPreCmdSpectolBreak__FP14CBaseMenuClassiP16CMenuPosDataFormP13CGameDataUsedP13CGameDataUsed);
INCLUDE_ASM("nonmatchings/cbasemenuclass", SetPreCmdGiftBoxSelect__FP14CBaseMenuClassP13CGameDataUsed);
INCLUDE_ASM("nonmatchings/cbasemenuclass", CheckFishCondition__Fv);
INCLUDE_ASM("nonmatchings/cbasemenuclass", Initialize__15CMENU_USERPARAMFv);
INCLUDE_ASM("nonmatchings/cbasemenuclass", AttachInfo__15CMENU_USERPARAMFv);
INCLUDE_ASM("nonmatchings/cbasemenuclass", Initialize__17MENU_ASKMODE_PARAFv);
INCLUDE_ASM("nonmatchings/cbasemenuclass", __ct__17MENU_ASKMODE_PARAFv);
INCLUDE_ASM("nonmatchings/cbasemenuclass", Set__18MENU_SWAPITEM_INFOFiiii);
INCLUDE_ASM("nonmatchings/cbasemenuclass", IsEnableChangeRoboParts__FP13CGameDataUsed);
INCLUDE_ASM("nonmatchings/cbasemenuclass", SetSpectolInfo__FP13CGameDataUsedP13CGameDataUsed);
INCLUDE_ASM("nonmatchings/cbasemenuclass", InitSpectol__Fv);
INCLUDE_ASM("nonmatchings/cbasemenuclass", AfterSpectolFusion__FP13CGameDataUsedP13CGameDataUsed);
INCLUDE_ASM("nonmatchings/cbasemenuclass", FusionColor__FiiPf);
INCLUDE_ASM("nonmatchings/cbasemenuclass", SpectolFrameCalc__FP12CActionCharai);
INCLUDE_ASM("nonmatchings/cbasemenuclass", TransSpectolDataSave__FP13CGameDataUsedi);
INCLUDE_ASM("nonmatchings/cbasemenuclass", CheckNowRoboUseCapacity__FPi);
INCLUDE_ASM("nonmatchings/cbasemenuclass", ExchangeItemInfoMake__FP18MENU_SWAPITEM_INFOPA4_iii);
INCLUDE_ASM("nonmatchings/cbasemenuclass", MenuCheckLine__FPiii);
INCLUDE_ASM("nonmatchings/cbasemenuclass", MenuKeySelectCheck__FiPiPiiiii);
INCLUDE_ASM("nonmatchings/cbasemenuclass", MenuListKeyCheck__FiPiPiiiii);
INCLUDE_ASM("nonmatchings/cbasemenuclass", MenuGlidKeyCheck__FiPiPiPiPiPii);
INCLUDE_ASM("nonmatchings/cbasemenuclass", MenuListSelectKeyCheck__Fii);
