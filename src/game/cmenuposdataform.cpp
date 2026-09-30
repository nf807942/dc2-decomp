/* CMenuPosDataForm
 *
 * Unité découpée par `make carve` : 39 fonctions, 23988 octets, de
 * 0x00226B40 à 0x0022C990. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

INCLUDE_ASM("nonmatchings/game/cmenuposdataform", MenuMainFrameDraw__FRii);
INCLUDE_ASM("nonmatchings/game/cmenuposdataform", MenuMainFrameImgDraw__FRi);
INCLUDE_ASM("nonmatchings/game/cmenuposdataform", DrawMenuWakuStep__Fv);
INCLUDE_ASM("nonmatchings/game/cmenuposdataform", DrawMenuWakuRect__FP10mgCTexture9mgRect_f_9mgRect_i_iiii);
INCLUDE_ASM("nonmatchings/game/cmenuposdataform", DrawWakuCircle__FP11mgCDrawPrimP10mgCTexture9mgRect_f_9mgRect_i_ffiiii);
struct inferred;
struct mgRect_i_ {
    s32 field_0;
    s32 field_4;
    s32 field_8;
    s32 field_C;
    char pad_10[0x8];
    s8 field_18;
    char pad_19[0x1];
    s16 field_1A;
};
typedef struct MENU_BASETEXINFO {
    /* 0x00 */ char pad0[0x10];
    /* 0x10 */ s32 unk10;                           /* inferred */
    /* 0x14 */ s32 unk14;                           /* inferred */
    /* 0x18 */ s8 unk18;                            /* inferred */
} MENU_BASETEXINFO;                                 /* size >= 0x19 */
extern "C" s32 Set__9mgRect_i_Fiiii(void *, s32, s32, s32, s32);
extern "C" void MENU_BASETEXINFO_Init__FP16MENU_BASETEXINFO(MENU_BASETEXINFO *arg0) {
    arg0->unk10 = 0;
    arg0->unk14 = 0;
    Set__9mgRect_i_Fiiii((mgRect_i_ *) arg0, 0, 0, 0, 0);
    arg0->unk18 = 0;
}
INCLUDE_ASM("nonmatchings/game/cmenuposdataform", MenuPosDataTypeInit__FP18MENUFORMPARTS_TYPE);
typedef struct MENUFORMPARTS_TYPE_infere {
    /* 0x00 */ char pad0[5];
    /* 0x05 */ s8 unk5;                             /* inferred */
    /* 0x06 */ char pad6[0x2A];                     /* maybe part of unk5[0x2B]void */
    /* 0x30 */ s32 unk30;                           /* inferred */
    /* 0x34 */ s32 unk34;                           /* inferred */
    /* 0x38 */ s32 unk38;                           /* inferred */
} MENUFORMPARTS_TYPE_infere;                               /* size >= 0x3C */
extern "C" s32 Func_MenuItemIconSetEffectOne__FP18MENUFORMPARTS_TYPE(MENUFORMPARTS_TYPE_infere *);
extern "C" void MenuFormPartsPresetItem__FP18MENUFORMPARTS_TYPEiii(MENUFORMPARTS_TYPE_infere *arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (arg0 != NULL) {
        arg0->unk5 = arg1 != 0;
        arg0->unk30 = 0;
        arg0->unk34 = arg2;
        arg0->unk38 = arg3;
        Func_MenuItemIconSetEffectOne__FP18MENUFORMPARTS_TYPE(arg0);
    }
}
INCLUDE_ASM("nonmatchings/game/cmenuposdataform", Initialize__16CMenuPosDataFormFv);
INCLUDE_ASM("nonmatchings/game/cmenuposdataform", GetPartInfo__16CMenuPosDataFormFPc);
extern "C" s32 GetPartInfo__16CMenuPosDataFormFPc(...);
#include "menu.hpp"
struct temp_v0_champs_d7f217 {
    char pad0[0x5];
    /* 0x5 */ s8 unk5;
};
extern "C" void SetPartDrawFlag__16CMenuPosDataFormFPcb(CMenuPosDataForm *objet, s8 *arg0, s8 arg1) {
    struct temp_v0_champs_d7f217 *temp_v0;

    temp_v0 = (struct temp_v0_champs_d7f217 *) (GetPartInfo__16CMenuPosDataFormFPc(objet, arg0));
    if (temp_v0 != NULL) {
        temp_v0->unk5 = arg1;
    }
}
struct inferred;
#include "menu.hpp"
typedef struct MENUFORMPARTS_TYPE {
    /* 0x00 */ char pad0[0x40];
    /* 0x40 */ s32 unk40;                           /* inferred */
    /* 0x44 */ s8 unk44;                            /* inferred */
} MENUFORMPARTS_TYPE;                               /* size >= 0x45 */
extern "C" s32 Alloc__9mgCMemoryFi(void *, s32);
extern "C" void Func_MallocPartEffectInfo__FP18MENUFORMPARTS_TYPEP9mgCMemoryi(MENUFORMPARTS_TYPE *arg0, mgCMemory *arg1, s32 arg2) {
    u32 temp_v1;
    u32 var_v0;

    if (arg0 != NULL) {
        temp_v1 = arg2 * 0x24;
        arg0->unk44 = (s8) arg2;
        if (temp_v1 & 0xF) {
            var_v0 = (temp_v1 >> 4) + 1;
        } else {
            var_v0 = temp_v1 >> 4;
        }
        arg0->unk40 = Alloc__9mgCMemoryFi(arg1, var_v0);
    }
}
INCLUDE_ASM("nonmatchings/game/cmenuposdataform", Func_SetPartEffectInfo__FP25MENU_PARTS_EFFECT_STRUCT1UiPs);
struct CActionChara;
extern "C" void SetActionCharaPtr__16CMenuPosDataFormFP12CActionCharaii(CMenuPosDataForm *objet, CActionChara *a, s32 b, s32 c) {
    *(CActionChara **) ((u8 *) objet + 0x38) = a;
    *(s16 *) ((u8 *) objet + 0x34) = b;
    *(s16 *) ((u8 *) objet + 0x36) = c;
}
INCLUDE_ASM("nonmatchings/game/cmenuposdataform", SetRGBACalcParam__16CMenuPosDataFormFiii);
INCLUDE_ASM("nonmatchings/game/cmenuposdataform", FormFadeIn__16CMenuPosDataFormFii);
INCLUDE_ASM("nonmatchings/game/cmenuposdataform", FormFadeOut__16CMenuPosDataFormFii);
extern "C" s32 GetPartInfo__16CMenuPosDataFormFPc(...);
struct temp_v0_champs {
    char pad0[0x34];
    /* 0x34 */ s32 unk34;
};
extern "C" void SetNumber__16CMenuPosDataFormFPci(CMenuPosDataForm *objet, s8 *arg0, s32 arg1) {
    struct temp_v0_champs *temp_v0;

    temp_v0 = (struct temp_v0_champs *) (GetPartInfo__16CMenuPosDataFormFPc(objet, arg0));
    if (temp_v0 != NULL) {
        temp_v0->unk34 = arg1;
    }
}
INCLUDE_ASM("nonmatchings/game/cmenuposdataform", SetPartRGBA__16CMenuPosDataFormFPciiii);
INCLUDE_ASM("nonmatchings/game/cmenuposdataform", GetPutPosXY__16CMenuPosDataFormFPcRiRi);
INCLUDE_ASM("nonmatchings/game/cmenuposdataform", GetPutPosXY__16CMenuPosDataFormFPcRfRf);
INCLUDE_ASM("nonmatchings/game/cmenuposdataform", GetEnableEnterPart__16CMenuPosDataFormFv);
INCLUDE_ASM("nonmatchings/game/cmenuposdataform", GetNowPosRGBA__16CMenuPosDataFormFP18MENUFORMPARTS_TYPEP16MENU_BASETEXINFOPfPUc);
INCLUDE_ASM("nonmatchings/game/cmenuposdataform", MenuPartsStep__16CMenuPosDataFormFv);
INCLUDE_ASM("nonmatchings/game/cmenuposdataform", DrawItemIconEffect2__FP11mgCDrawPrimP10mgCTextureP18MENUFORMPARTS_TYPE9mgRect_f_);
INCLUDE_ASM("nonmatchings/game/cmenuposdataform", MenuItemBrdSetInfo__Fiiii);
INCLUDE_ASM("nonmatchings/game/cmenuposdataform", MenuItemBrdFrameDraw__FiiRiiiii);
INCLUDE_ASM("nonmatchings/game/cmenuposdataform", MenuItemBrdDraw__FPf9mgRect_i_Riiiii);
INCLUDE_ASM("nonmatchings/game/cmenuposdataform", MenuItemModeItemDraw__FRi9mgRect_i_PfP18MENUFORMPARTS_TYPEP10mgCTexture9mgRect_i_i);
INCLUDE_ASM("nonmatchings/game/cmenuposdataform", MenuFormStep__16CMenuPosDataFormFv);
typedef struct CMenuPosDataForm_infere {
    /* 0x00 */ char pad0[0xC];
    /* 0x0C */ f32 unkC;                            /* inferred */
    /* 0x10 */ f32 unk10;                           /* inferred */
} CMenuPosDataForm_infere;                                 /* size >= 0x14 */
extern "C" s32 CheckMoveEnd__16CMenuPosDataFormFii(CMenuPosDataForm_infere *objet, s32 arg0, s32 arg1) {
    s32 var_v0;

    var_v0 = 0;
    if (objet->unkC == (f32) arg0) {
        var_v0 = 1;
        if (objet->unk10 != (f32) arg1) {
            var_v0 = 0;
        }
    }
    return var_v0;
}
INCLUDE_ASM("nonmatchings/game/cmenuposdataform", CheckMoveEnd__16CMenuPosDataFormFv);
INCLUDE_ASM("nonmatchings/game/cmenuposdataform", SetAction__16CMenuPosDataFormFPc);
extern "C" void SetNextMovePos__16CMenuPosDataFormFPii(void *self, s32 *arg0, s32 arg1) {
    *(s8 *) ((u8 *) self + 0x20) = arg1;
    *(s32 *) ((u8 *) self + 0x24) = arg0[0];
    *(s32 *) ((u8 *) self + 0x28) = arg0[1];
}
INCLUDE_ASM("nonmatchings/game/cmenuposdataform", GetNextMovePos__16CMenuPosDataFormFPi);
INCLUDE_ASM("nonmatchings/game/cmenuposdataform", Menu3DivideTextureDraw__FP11mgCDrawPrim9mgRect_i_Psi);
INCLUDE_ASM("nonmatchings/game/cmenuposdataform", MenuFormDrawNormal__16CMenuPosDataFormFiiffRi);
INCLUDE_ASM("nonmatchings/game/cmenuposdataform", MenuFormDraw__16CMenuPosDataFormFiiRi);
INCLUDE_ASM("nonmatchings/game/cmenuposdataform", MenuFormDraw__16CMenuPosDataFormFRi);
