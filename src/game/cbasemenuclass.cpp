/* CBaseMenuClass, CMenuInter, CMENU_USERPARAM, MENU_ASKMODE_PARA, MENU_SWAPITEM_INFO
 *
 * Unité découpée par `make carve` : 65 fonctions, 24484 octets, de
 * 0x00237AD0 à 0x0023DC00. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"
#include "gen/CMENU_USERPARAM.hpp"
#include "gen/CMenuInter.hpp"

void CMenuInter::Initialize(s32 arg0) {
    this->field_0x10 = 1;
    this->field_0x0 = 0;
    this->field_0x4 = 6;
    this->field_0xC = 0;
    this->field_0x12 = 0;
    this->field_0x13 = 30;
    this->field_0x14 = 1;
    this->field_0x8 = -1;
    this->field_0x15 = 0;
}
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
extern "C" u32 MenuMainScene;
#include "menu.hpp"
extern "C" s32 FadeIn__10CFadeInOutFi(...);
extern "C" s32 FadeStep__10CFadeInOutFv(...);
extern "C" void FadeInMenu__14CBaseMenuClassFif(CBaseMenuClass *objet, s32 arg0, f32 arg1) {
    FadeIn__10CFadeInOutFi(MenuMainScene + 0x2C70, arg0);
    FadeStep__10CFadeInOutFv(MenuMainScene + 0x2C70);
}
INCLUDE_ASM("nonmatchings/game/cbasemenuclass", FadeOutMenu__14CBaseMenuClassFif);
INCLUDE_ASM("nonmatchings/game/cbasemenuclass", FadeCheckMenu__14CBaseMenuClassFv);
INCLUDE_ASM("nonmatchings/game/cbasemenuclass", SetPreCmdTrush__FP14CBaseMenuClassiP13CGameDataUsedP16CMenuPosDataForm);
INCLUDE_ASM("nonmatchings/game/cbasemenuclass", SetPreCmdSpectolBreak__FP14CBaseMenuClassiP16CMenuPosDataFormP13CGameDataUsedP13CGameDataUsed);
INCLUDE_ASM("nonmatchings/game/cbasemenuclass", SetPreCmdGiftBoxSelect__FP14CBaseMenuClassP13CGameDataUsed);
INCLUDE_ASM("nonmatchings/game/cbasemenuclass", CheckFishCondition__Fv);
void CMENU_USERPARAM::Initialize(void) {
    this->field_0x4 = 0;
    this->field_0x0 = 0;
    this->field_0x8 = 0;
    this->field_0xC = 0;
    this->field_0x10 = 0;
    this->field_0x14 = 0;
}
INCLUDE_ASM("nonmatchings/game/cbasemenuclass", AttachInfo__15CMENU_USERPARAMFv);
INCLUDE_ASM("nonmatchings/game/cbasemenuclass", Initialize__17MENU_ASKMODE_PARAFv);
struct inferred;
typedef struct MENU_ASKMODE_PARA {
    /* 0x00 */ char pad0[0x8C];
    /* 0x8C */ s32 unk8C;                           /* inferred */
} MENU_ASKMODE_PARA;                                /* size >= 0x90 */
extern "C" s32 Initialize__17MENU_ASKMODE_PARAFv(void *);
extern "C" MENU_ASKMODE_PARA *__ct__17MENU_ASKMODE_PARAFv(MENU_ASKMODE_PARA *objet) {
    objet->unk8C = -1;
    Initialize__17MENU_ASKMODE_PARAFv(objet);
    return objet;
}
INCLUDE_ASM("nonmatchings/game/cbasemenuclass", Set__18MENU_SWAPITEM_INFOFiiii);
INCLUDE_ASM("nonmatchings/game/cbasemenuclass", IsEnableChangeRoboParts__FP13CGameDataUsed);
INCLUDE_ASM("nonmatchings/game/cbasemenuclass", SetSpectolInfo__FP13CGameDataUsedP13CGameDataUsed);
typedef struct SpectolInfo_champs {
    char pad0[4];
    s32 unk4;
} SpectolInfo_champs;
extern "C" SpectolInfo_champs SpectolInfo;
extern "C" s32 Init__13CGameDataUsedFv(...);
extern "C" void InitSpectol__Fv(void) {
    if (SpectolInfo.unk4 != NULL) {
        Init__13CGameDataUsedFv(SpectolInfo.unk4);
    }
}
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
