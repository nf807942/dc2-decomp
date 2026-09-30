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
extern "C" void MenuDeleteTextureBlock__FPi(...);
extern "C" void DeleteTexBlock__14CBaseMenuClassFv(char *objet) {
    MenuDeleteTextureBlock__FPi(objet + 0x18);
}
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
struct CBMC_e { char pad0[8]; s8 *p; s32 n; };
extern "C" void MenuCommandAnalyze__FPciPc(s8 *arg0, s32 arg1, s8 *arg2);
extern "C" void ExeScript__14CBaseMenuClassFPc(CBMC_e *objet, s8 *s) {
    MenuCommandAnalyze__FPciPc(objet->p, objet->n, s);
}
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
extern "C" u32 MenuMainScene;
struct fade_obj_l1c;
extern "C" void FadeOut__10CFadeInOutFifff(fade_obj_l1c *, s32, f32, f32, f32);
extern "C" s32 FadeStep__10CFadeInOutFv(...);
extern "C" void FadeOutMenu__14CBaseMenuClassFif(CBaseMenuClass *objet, s32 arg0, f32 arg1) {
    FadeOut__10CFadeInOutFifff((fade_obj_l1c *) (MenuMainScene + 0x2C70), arg0, 0.0f, 0.0f, 0.0f);
    FadeStep__10CFadeInOutFv((fade_obj_l1c *) (MenuMainScene + 0x2C70));
}
extern "C" s32 FadeCheck__10CFadeInOutFv(...);
extern "C" s32 FadeCheckMenu__14CBaseMenuClassFv(void) {
    return FadeCheck__10CFadeInOutFv(MenuMainScene + 0x2C70);
}
INCLUDE_ASM("nonmatchings/game/cbasemenuclass", SetPreCmdTrush__FP14CBaseMenuClassiP13CGameDataUsedP16CMenuPosDataForm);
INCLUDE_ASM("nonmatchings/game/cbasemenuclass", SetPreCmdSpectolBreak__FP14CBaseMenuClassiP16CMenuPosDataFormP13CGameDataUsedP13CGameDataUsed);
INCLUDE_ASM("nonmatchings/game/cbasemenuclass", SetPreCmdGiftBoxSelect__FP14CBaseMenuClassP13CGameDataUsed);
extern "C" s32 GetMainScene__Fv(void);
extern "C" s32 menu_GetBattleAreaScene__Fv(void);
struct temp_s0_champs {
    char pad0[0x2E60];
    /* 0x2E60 */ s32 unk2E60;
};
struct temp_s1_champs {
    char pad0[0x5C];
    /* 0x5C */ s32 unk5C;
};
extern "C" s32 GetMenuLoopType__Fv(void);
extern "C" s32 CheckFishCondition__Fv(void) {
    s32 temp_v1;
    s32 var_s0;
    s32 var_v0;
    struct temp_s0_champs *temp_s0;
    struct temp_s1_champs *temp_s1;

    temp_s0 = (struct temp_s0_champs *) (GetMainScene__Fv());
    temp_s1 = (struct temp_s1_champs *) (menu_GetBattleAreaScene__Fv());
    temp_v1 = (s32) (temp_s0->unk2E60);
    var_s0 = 1;
    if (temp_v1 == 0x7D) {
        var_s0 = 0;
    }
    if ((temp_v1 == 0x63) || (temp_v1 == 0x5F)) {
        var_s0 = 0;
    }
    var_v0 = var_s0;
    if (GetMenuLoopType__Fv() == 1) {
        if (temp_s1->unk5C == 0) {
            var_s0 = 0;
        }
        var_v0 = var_s0;
    }
    return var_v0;
}
void CMENU_USERPARAM::Initialize(void) {
    this->field_0x4 = 0;
    this->field_0x0 = 0;
    this->field_0x8 = 0;
    this->field_0xC = 0;
    this->field_0x10 = 0;
    this->field_0x14 = 0;
}
INCLUDE_ASM("nonmatchings/game/cbasemenuclass", AttachInfo__15CMENU_USERPARAMFv);
extern "C" void *memset(void *, int, unsigned);
extern "C" s32 Initialize__17MENU_ASKMODE_PARAFv(void *objet) {
    return (s32)memset(objet, 0, 0x94);
}
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
extern "C" void Set__18MENU_SWAPITEM_INFOFiiii(void *arg0, s32 a, s32 b, s32 c, s32 d) {
    *(s16 *) ((u8 *) arg0 + 2) = a;
    *(s16 *) ((u8 *) arg0 + 4) = b;
    *(s16 *) ((u8 *) arg0 + 6) = c;
    *(s16 *) arg0 = d;
}
INCLUDE_ASM("nonmatchings/game/cbasemenuclass", IsEnableChangeRoboParts__FP13CGameDataUsed);
typedef struct SpectolInfo_champs {
    s32 unk0;
    s32 unk4;
} SpectolInfo_champs;
extern "C" SpectolInfo_champs SpectolInfo;
extern "C" void SetSpectolInfo__FP13CGameDataUsedP13CGameDataUsed(s32 a, s32 b) {
    SpectolInfo.unk0 = a;
    SpectolInfo.unk4 = b;
}
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
extern "C" s32 GetItemInfoData__Fi(s32);
typedef struct MenuUserParam_champs {
    char pad0[8];
    s32 unk8;
    char padC[12];
} MenuUserParam_champs;
extern "C" MenuUserParam_champs MenuUserParam;
struct ROBO_DATA {
    f32 field_0;
    f32 field_4;
    u16 field_8;
    u16 field_A;
    char pad_C[0x2];
    s16 field_E;
    s16 field_10;
    s16 field_12;
    char pad_14[0x4];
    s16 field_18;
    char pad_1A[0x2];
    s8 field_1C;
    s8 field_1D;
    char pad_1E[0x6];
    f32 field_24;
    char pad_28[0x3];
    s8 field_2B;
    f32 field_2C;
    char pad_30[0xC];
    s16 field_3C;
    s16 field_3E;
    char pad_40[0x90];
    s16 field_D0;
    char pad_D2[0x10E];
    s16 field_1E0;
    s16 field_1E2;
    char pad_1E4[0x4];
    u16 field_1E8;
};
struct MenuCommonInfo_champs_1ab1f1 {
    char pad0[0xC2];
    /* 0xC2 */ s16 unkC2;
};
struct temp_v0_champs_1ab1f1 {
    char pad0[0xA];
    /* 0xA */ s16 unkA;
};
extern "C" s32 CheckNowRoboUseCapacity__FP9ROBO_DATAPi(...);
extern "C" s32 CheckNowRoboUseCapacity__FPi(s32 *arg0) {
    s32 temp_s0;
    struct temp_v0_champs_1ab1f1 *temp_v0;

    temp_s0 = CheckNowRoboUseCapacity__FP9ROBO_DATAPi(MenuUserParam.unk8, arg0);
    if (*arg0 == 0) {
        temp_v0 = (struct temp_v0_champs_1ab1f1 *) (GetItemInfoData__Fi((s32) ((struct MenuCommonInfo_champs_1ab1f1 *) MenuCommonInfo)->unkC2));
        if (temp_v0 != NULL) {
            *arg0 = (s32) temp_v0->unkA;
        }
    }
    return temp_s0;
}
INCLUDE_ASM("nonmatchings/game/cbasemenuclass", ExchangeItemInfoMake__FP18MENU_SWAPITEM_INFOPA4_iii);
INCLUDE_ASM("nonmatchings/game/cbasemenuclass", MenuCheckLine__FPiii);
INCLUDE_ASM("nonmatchings/game/cbasemenuclass", MenuKeySelectCheck__FiPiPiiiii);
INCLUDE_ASM("nonmatchings/game/cbasemenuclass", MenuListKeyCheck__FiPiPiiiii);
INCLUDE_ASM("nonmatchings/game/cbasemenuclass", MenuGlidKeyCheck__FiPiPiPiPiPii);
INCLUDE_ASM("nonmatchings/game/cbasemenuclass", MenuListSelectKeyCheck__Fii);
