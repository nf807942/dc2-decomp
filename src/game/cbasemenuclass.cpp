/* CBaseMenuClass, CMenuInter, CMENU_USERPARAM, MENU_ASKMODE_PARA, MENU_SWAPITEM_INFO
 *
 * Unité découpée par `make carve` : 65 fonctions, 24484 octets, de
 * 0x00237AD0 à 0x0023DC00. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

INCLUDE_ASM("nonmatchings/game/cbasemenuclass", Initialize__10CMenuInterFi);
INCLUDE_ASM("nonmatchings/game/cbasemenuclass", MenuCommonBaseDataEnter__FP9mgCMemoryPUiii);
INCLUDE_ASM("nonmatchings/game/cbasemenuclass", MenuBaseTextureReEnter__Fv);
INCLUDE_ASM("nonmatchings/game/cbasemenuclass", InitEnd__10CMenuInterFv);
INCLUDE_ASM("nonmatchings/game/cbasemenuclass", PushOk__10CMenuInterFv);
INCLUDE_ASM("nonmatchings/game/cbasemenuclass", ReadBGTexture__10CMenuInterFii);
INCLUDE_ASM("nonmatchings/game/cbasemenuclass", MenuInternSelectKey__Fv);
INCLUDE_ASM("nonmatchings/game/cbasemenuclass", MenuInternSelectDraw__Fv);
INCLUDE_ASM("nonmatchings/game/cbasemenuclass", CopyActiveItemAndWeapon__Fii);
INCLUDE_ASM("nonmatchings/game/cbasemenuclass", CopyActiveIconTexture__FPP10mgCTextureiPUi);
INCLUDE_ASM("nonmatchings/game/cbasemenuclass", MenuDebugModeDraw__Fv);
INCLUDE_ASM("nonmatchings/game/cbasemenuclass", BookshelfMessageMake__FP6ClsMesiii);
INCLUDE_ASM("nonmatchings/game/cbasemenuclass", DrawTrushMenuMessage__Fv);
INCLUDE_ASM("nonmatchings/game/cbasemenuclass", __ct__14CBaseMenuClassFv);
INCLUDE_ASM("nonmatchings/game/cbasemenuclass", SetTexBlock__14CBaseMenuClassFPi);
INCLUDE_ASM("nonmatchings/game/cbasemenuclass", DeleteTexBlock__14CBaseMenuClassFv);
INCLUDE_ASM("nonmatchings/game/cbasemenuclass", MenuItemCommnadSelectPrepare__14CBaseMenuClassFP13CGameDataUsedii);
INCLUDE_ASM("nonmatchings/game/cbasemenuclass", MenuItemMoveItemCommand__14CBaseMenuClassFP13CGameDataUsediiP16CMenuPosDataFormi);
INCLUDE_ASM("nonmatchings/game/cbasemenuclass", MenuItemCommandSelect__14CBaseMenuClassFii);
INCLUDE_ASM("nonmatchings/game/cbasemenuclass", SetItemCmdMsgPos__14CBaseMenuClassFPi);
INCLUDE_ASM("nonmatchings/game/cbasemenuclass", MenuHowMuchNumSelect__FiP13CGameDataUsedi);
INCLUDE_ASM("nonmatchings/game/cbasemenuclass", MenuItemAskMode_HowMuch__14CBaseMenuClassFii);
INCLUDE_ASM("nonmatchings/game/cbasemenuclass", CheckTrushWeapon__FP13CGameDataUsed);
INCLUDE_ASM("nonmatchings/game/cbasemenuclass", CheckSpectolFusion__14CBaseMenuClassFP13CGameDataUsediP16CMenuPosDataForm);
INCLUDE_ASM("nonmatchings/game/cbasemenuclass", UpdataInfoSpectolBreakItem__FP7CDC2MesP13CGameDataUsedi);
INCLUDE_ASM("nonmatchings/game/cbasemenuclass", CheckEquipFishRod__FP13CGameDataUsed);
INCLUDE_ASM("nonmatchings/game/cbasemenuclass", IsSpectolTrans__14CBaseMenuClassFii);
INCLUDE_ASM("nonmatchings/game/cbasemenuclass", IsSpectolFusion__14CBaseMenuClassFii);
INCLUDE_ASM("nonmatchings/game/cbasemenuclass", IsDispTrushCommand__FP13CGameDataUsed);
INCLUDE_ASM("nonmatchings/game/cbasemenuclass", IsTrush__14CBaseMenuClassFii);
INCLUDE_ASM("nonmatchings/game/cbasemenuclass", IsItemUseNum__14CBaseMenuClassFiiiP13CGameDataUsedP14CItemUseTarget);
INCLUDE_ASM("nonmatchings/game/cbasemenuclass", SelectInGiftBox__14CBaseMenuClassFii);
INCLUDE_ASM("nonmatchings/game/cbasemenuclass", SetConditionHowMuchBoard__Fv);
INCLUDE_ASM("nonmatchings/game/cbasemenuclass", SetAskHowMuchItemNum__14CBaseMenuClassFP18MENU_SWAPITEM_INFOP13CGameDataUsed);
INCLUDE_ASM("nonmatchings/game/cbasemenuclass", SetAskParam__14CBaseMenuClassFP17MENU_ASKMODE_PARA);
INCLUDE_ASM("nonmatchings/game/cbasemenuclass", ExeScript__14CBaseMenuClassFPc);
INCLUDE_ASM("nonmatchings/game/cbasemenuclass", ExtendCommand__14CBaseMenuClassFii);
INCLUDE_ASM("nonmatchings/game/cbasemenuclass", SelectMakeObject__14CBaseMenuClassFi);
INCLUDE_ASM("nonmatchings/game/cbasemenuclass", IsAskEnd__14CBaseMenuClassFiP16CMenuPosDataForm);
INCLUDE_ASM("nonmatchings/game/cbasemenuclass", FadeInMenu__14CBaseMenuClassFif);
INCLUDE_ASM("nonmatchings/game/cbasemenuclass", FadeOutMenu__14CBaseMenuClassFif);
INCLUDE_ASM("nonmatchings/game/cbasemenuclass", FadeCheckMenu__14CBaseMenuClassFv);
INCLUDE_ASM("nonmatchings/game/cbasemenuclass", SetPreCmdTrush__FP14CBaseMenuClassiP13CGameDataUsedP16CMenuPosDataForm);
INCLUDE_ASM("nonmatchings/game/cbasemenuclass", SetPreCmdSpectolBreak__FP14CBaseMenuClassiP16CMenuPosDataFormP13CGameDataUsedP13CGameDataUsed);
INCLUDE_ASM("nonmatchings/game/cbasemenuclass", SetPreCmdGiftBoxSelect__FP14CBaseMenuClassP13CGameDataUsed);
INCLUDE_ASM("nonmatchings/game/cbasemenuclass", CheckFishCondition__Fv);
INCLUDE_ASM("nonmatchings/game/cbasemenuclass", Initialize__15CMENU_USERPARAMFv);
INCLUDE_ASM("nonmatchings/game/cbasemenuclass", AttachInfo__15CMENU_USERPARAMFv);
INCLUDE_ASM("nonmatchings/game/cbasemenuclass", Initialize__17MENU_ASKMODE_PARAFv);
INCLUDE_ASM("nonmatchings/game/cbasemenuclass", __ct__17MENU_ASKMODE_PARAFv);
INCLUDE_ASM("nonmatchings/game/cbasemenuclass", Set__18MENU_SWAPITEM_INFOFiiii);
INCLUDE_ASM("nonmatchings/game/cbasemenuclass", IsEnableChangeRoboParts__FP13CGameDataUsed);
INCLUDE_ASM("nonmatchings/game/cbasemenuclass", SetSpectolInfo__FP13CGameDataUsedP13CGameDataUsed);
INCLUDE_ASM("nonmatchings/game/cbasemenuclass", InitSpectol__Fv);
INCLUDE_ASM("nonmatchings/game/cbasemenuclass", AfterSpectolFusion__FP13CGameDataUsedP13CGameDataUsed);
INCLUDE_ASM("nonmatchings/game/cbasemenuclass", FusionColor__FiiPf);
INCLUDE_ASM("nonmatchings/game/cbasemenuclass", SpectolFrameCalc__FP12CActionCharai);
INCLUDE_ASM("nonmatchings/game/cbasemenuclass", TransSpectolDataSave__FP13CGameDataUsedi);
INCLUDE_ASM("nonmatchings/game/cbasemenuclass", CheckNowRoboUseCapacity__FPi);
INCLUDE_ASM("nonmatchings/game/cbasemenuclass", ExchangeItemInfoMake__FP18MENU_SWAPITEM_INFOPA4_iii);
INCLUDE_ASM("nonmatchings/game/cbasemenuclass", MenuCheckLine__FPiii);
INCLUDE_ASM("nonmatchings/game/cbasemenuclass", MenuKeySelectCheck__FiPiPiiiii);
INCLUDE_ASM("nonmatchings/game/cbasemenuclass", MenuListKeyCheck__FiPiPiiiii);
INCLUDE_ASM("nonmatchings/game/cbasemenuclass", MenuGlidKeyCheck__FiPiPiPiPiPii);
INCLUDE_ASM("nonmatchings/game/cbasemenuclass", MenuListSelectKeyCheck__Fii);
