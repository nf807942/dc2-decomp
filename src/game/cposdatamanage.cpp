/* CPosDataManage, CMenuPosDataManage, CRepairManager, CLevelUpEffect, CEffVerticalLine, CRepairEffect, CLevelUpEffectManager, CStarDust
 *
 * Unité découpée par `make carve` : 93 fonctions, 21036 octets, de
 * 0x0022C990 à 0x00231DD0. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"
#include "gen/CLevelUpEffect.hpp"
#include "gen/CRepairEffect.hpp"
#include "gen/CLevelUpEffect.hpp"

struct inferred;
typedef struct CPosDataManage_infere {
    /* 0x00 */ s32 unk0;                            /* inferred */
    /* 0x04 */ s16 unk4;                            /* inferred */
    /* 0x06 */ char pad6[0xA];                      /* maybe part of unk4[6]void */
    /* 0x10 */ s32 unk10;                           /* inferred */
    /* 0x14 */ s16 unk14;                           /* inferred */
    /* 0x16 */ char pad16[2];
    /* 0x18 */ s32 unk18;                           /* inferred */
    /* 0x1C */ s16 unk1C;                           /* inferred */
    /* 0x1E */ s8 unk1E;                            /* inferred */
} CPosDataManage_infere;                                   /* size >= 0x1F */
/* Pose par `make forge`, qui a compose les reparations connues et verifie l'image entiere. Voir docs/IDIOMES_MWCC.md pour le detail de chacune. */
extern "C" void Initialize__14CPosDataManageFv(CPosDataManage_infere *objet) {
    objet->unk0 = 0;
    objet->unk4 = 0;
    objet->unk10 = 0;
    objet->unk14 = 0;
    objet->unk18 = 0;
    objet->unk1C = 0;
    objet->unk1E = 0;
}
INCLUDE_ASM("nonmatchings/game/cposdatamanage", GetTexGetInfo__14CPosDataManageFi);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", GetTexGetInfo__14CPosDataManageFPc);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", GetTexGetInfoTblNo__14CPosDataManageFPc);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", TexGetInfoClear__14CPosDataManageFii);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", ResetTextureBlockNo__14CPosDataManageFPci);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", ResetTextureInfoAll__14CPosDataManageFv);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", EtcTblClear__14CPosDataManageFii);
struct CEtcTblEntry {
    s8 *name;
    s32 pad4[2];
};
struct CPosDataManageEtcView {
    CEtcTblEntry *tbl;
    u16 count;
};
extern "C" s32 strcmp(...);
extern "C" CEtcTblEntry *GetEtcTbl__14CPosDataManageFPc(CPosDataManageEtcView *objet, s8 *arg0) {
    CEtcTblEntry *p;
    u16 n;
    s32 i;

    if (arg0 == NULL) {
        return NULL;
    }
    n = objet->count;
    p = objet->tbl;
    i = 0;
    if (0 < n) {
        do {
            if (p->name != 0 && strcmp(p->name, arg0) == 0) {
                return p;
            }
            i++;
            p++;
        } while (i < n);
    }
    return NULL;
}
INCLUDE_ASM("nonmatchings/game/cposdatamanage", GetEtcTblValue__14CPosDataManageFPcRiRi);
struct CEtcTbl2Entry {
    s8 *name;
    s32 pad4[4];
};
struct CPosDataManageEtc2View {
    u8 pad0[8];
    CEtcTbl2Entry *tbl;
    u16 count;
};
extern "C" CEtcTbl2Entry *GetEtcTbl2__14CPosDataManageFPc(CPosDataManageEtc2View *objet, s8 *arg0) {
    CEtcTbl2Entry *p;
    u16 n;
    s32 i;

    if (arg0 == NULL) {
        return NULL;
    }
    n = objet->count;
    p = objet->tbl;
    i = 0;
    if (0 < n) {
        do {
            if (p->name != 0 && strcmp(p->name, arg0) == 0) {
                return p;
            }
            i++;
            p++;
        } while (i < n);
    }
    return NULL;
}
INCLUDE_ASM("nonmatchings/game/cposdatamanage", GetEtcTbl2Value__14CPosDataManageFPcPfi);
extern "C" void EtcTbl2Clear__14CPosDataManageFii(CPosDataManageEtc2View *objet, s32 arg0, s32 arg1) {
    CEtcTbl2Entry *p;
    s32 end;
    s32 count;
    s32 i;

    end = arg1;
    if (objet->count < end) {
        end = objet->count;
    }
    count = end - arg0;
    i = 0;
    p = objet->tbl + arg0;
    if (0 < count) {
        do {
            i++;
            p->name = 0;
            p++;
        } while (i < count);
    }
}
extern "C" u8 temp_3925[32];
extern "C" u8 _3927[];
extern "C" s32 sprintf(...);
extern "C" void *GetMenuMainIconChar__Fi(s32 arg0) {
    sprintf(&temp_3925, &_3927, arg0 - 2);
    return &temp_3925;
}

INCLUDE_ASM("nonmatchings/game/cposdatamanage", GetFormInfo__14CPosDataManageFPc);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", GetFormInfo__14CPosDataManageFi);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", FormInfoClear__14CPosDataManageFii);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", SetFormPos__14CPosDataManageFPcPi);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", InitDrawList__14CPosDataManageFv);
struct CPosDataManage;
extern "C" s32 GetFormInfo__14CPosDataManageFi(void *, s32);
struct var_v0_champs {
    char pad0[0x70];
    /* 0x70 */ s32 unk70;
};
extern "C" void *GetDrawTopList__14CPosDataManageFv(CPosDataManage *objet) {
    /* L'ordre des declarations decide de l'attribution des registres chez
     * MWCC. Celui-ci n'est pas celui de m2c : il a ete trouve en enumerant
     * les ordres possibles, et c'est le seul qui rende les octets du disque.
     * */
    void *temp_v1;
    struct var_v0_champs *var_v0;

    var_v0 = (struct var_v0_champs *) (GetFormInfo__14CPosDataManageFi(objet, 0));
    if (var_v0 != NULL) {
loop_1:
        temp_v1 = (void *) (var_v0->unk70);
        if (temp_v1 == NULL) {
            return var_v0;
        }
        var_v0 = (struct var_v0_champs *) (temp_v1);
        if (temp_v1 == NULL) {
            goto block_4;
        }
        goto loop_1;
    }
block_4:
    return NULL;
}
INCLUDE_ASM("nonmatchings/game/cposdatamanage", FormReLink__14CPosDataManageFPcPc);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", FormReLink2__14CPosDataManageFPcPcPcPc);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", FormStep__14CPosDataManageFv);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", MenuDrawParamStep__Fv);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", FormDraw__14CPosDataManageFv);
struct inferred;
typedef struct CPosDataManage {
    /* 0x00 */ char pad0[4];
    /* 0x04 */ u16 unk4;                            /* inferred */
    /* 0x06 */ char pad6[0xE];                      /* maybe part of unk4[8]void */
    /* 0x14 */ u16 unk14;                           /* inferred */
    /* 0x16 */ char pad16[6];                       /* maybe part of unk14[4]void */
    /* 0x1C */ u16 unk1C;                           /* inferred */
} CPosDataManage;                                   /* size >= 0x1E */
extern "C" s32 EtcTblClear__14CPosDataManageFii(void *, s32, s32);
extern "C" s32 FormInfoClear__14CPosDataManageFii(void *, s32, s32);
extern "C" s32 TexGetInfoClear__14CPosDataManageFii(void *, s32, s32);
extern "C" void ClearPos__14CPosDataManageFv(CPosDataManage *objet) {
    EtcTblClear__14CPosDataManageFii(objet, 0, (s32) objet->unk4);
    TexGetInfoClear__14CPosDataManageFii(objet, 0, (s32) objet->unk14);
    FormInfoClear__14CPosDataManageFii(objet, 0, (s32) objet->unk1C);
}
extern "C" u8 mgTexManager[540];
extern "C" u8 _4182[];
extern "C" u8 _4183[];
extern "C" u8 _4184[];
extern "C" u8 _4185_0036FB28[];
extern "C" u8 _4186_0036FB30[];
struct CMenuPosDataManageView {
    char pad0[0x3C];
    s32 unk3C;
    s32 unk40;
    char pad44[8];
    s32 unk4C;
    s32 unk50;
    s32 unk54;
    s32 unk58;
};
extern "C" s32 GetTexture__17mgCTextureManagerFPci(...);
extern "C" void AttachCommonTexInfo__18CMenuPosDataManageFv(CMenuPosDataManageView *objet) {
    objet->unk3C = GetTexture__17mgCTextureManagerFPci(&mgTexManager, _4182, -1);
    objet->unk40 = 0;
    objet->unk4C = GetTexture__17mgCTextureManagerFPci(&mgTexManager, _4183, -1);
    objet->unk50 = GetTexture__17mgCTextureManagerFPci(&mgTexManager, _4184, -1);
    objet->unk54 = GetTexture__17mgCTextureManagerFPci(&mgTexManager, _4185_0036FB28, -1);
    objet->unk58 = GetTexture__17mgCTextureManagerFPci(&mgTexManager, _4186_0036FB30, -1);
}
INCLUDE_ASM("nonmatchings/game/cposdatamanage", StepMainMenuIconMove__18CMenuPosDataManageFPiii);
#include "gamedataused.hpp"
struct inferred;
typedef struct CItemUseTarget {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ CGameDataUsed *unk4;                  /* inferred */
} CItemUseTarget;                                   /* size >= 0x8 */
extern "C" s32 CheckBuildUp__FP13CGameDataUsedPiPiPi(CGameDataUsed *, s32 *, s32 *, s32 *);
extern "C" s32 CheckNowStateUseThisItem__FP13CGameDataUsedP14CItemUseTarget(CGameDataUsed *, CItemUseTarget *);
extern "C" s32 CheckItemUseVariable__FP13CGameDataUsedP14CItemUseTarget(CGameDataUsed *arg0, CItemUseTarget *arg1) {
    s32 temp_s0;
    s32 var_v0;

    if ((arg0 == NULL) || (arg1 == NULL)) {
        return 0;
    }
    temp_s0 = (s32) (CheckNowStateUseThisItem__FP13CGameDataUsedP14CItemUseTarget(arg0, arg1));
    var_v0 = temp_s0;
    if (CheckBuildUp__FP13CGameDataUsedPiPiPi(arg1->unk4, NULL, NULL, NULL) != 0) {
        var_v0 = temp_s0 | 2;
    }
    return var_v0;
}
struct MENUFORMPARTS_TYPE {
    char pad0[0x45];
    s8 unk45;
    char pad46[2];
};
extern "C" s32 GetNowBagMax__Fi(s32);
extern "C" s32 SetPtr__14CItemUseTargetFiPv(CItemUseTarget *, s32, CGameDataUsed *);
extern "C" void Func_MenuItemBrdPrepare__FP18MENUFORMPARTS_TYPEP13CGameDataUsedP13CGameDataUsedi(MENUFORMPARTS_TYPE *arg0, CGameDataUsed *arg1, CGameDataUsed *arg2, s32 arg3) {
    CItemUseTarget target;
    CGameDataUsed *item;
    s32 n;
    s32 i;

    if (arg0 != NULL) {
        target.unk0 = -1;
        n = GetNowBagMax__Fi(1);
        i = 0;
        if (0 < n) {
            do {
                item = (CGameDataUsed *) ((u8 *) arg1 + i * 0x6C);
                SetPtr__14CItemUseTargetFiPv(&target, arg3, item);
                arg0->unk45 = CheckItemUseVariable__FP13CGameDataUsedP14CItemUseTarget(arg2, &target);
                i++;
                arg0++;
            } while (i < n);
        }
    }
}
INCLUDE_ASM("nonmatchings/game/cposdatamanage", Func_MenuItemBrdPrepare2__FP18MENUFORMPARTS_TYPEP13CGameDataUsedP13CGameDataUsed);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", NowUseNeedItemCheck__FP16CUserDataManager);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", Func_MenuIconDrawPrepare__FP18MENUFORMPARTS_TYPEP13CGameDataUsedi);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", CheckItemBoardFunc_MenuIconDrawPrepare__FP16CUserDataManagerP18MENUFORMPARTS_TYPE);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", MenuItemBrdScrlBarStep__Fiii);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", Func_MenuItemBrdPosStep__Fi);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", GetPosMenuItemBrdKoma__18CMenuPosDataManageFPiii);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", GetPosMenuItemOnItemBrd__18CMenuPosDataManageFPiii);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", GetPosMenuItemBrdForEffect__18CMenuPosDataManageFPiii);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", Func_MenuItemIconSetEffectOne__FP18MENUFORMPARTS_TYPE);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", MenuItemBrdItemIconEffectMalloc__FP9mgCMemoryP18MENUFORMPARTS_TYPEi);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", MallocPallet__18CMenuPosDataManageFP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", SearchTransPalletNo__18CMenuPosDataManageFv);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", InitializeCMenuPosDataManage__18CMenuPosDataManageFv);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", MenuCapture__FiP9mgCMemoryi);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", SetBGFrameForMenu__FiPc);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", MenuFrameImageDraw__FP11mgCDrawPrimP10mgCTexture9mgRect_f_9mgRect_i_iii);
void CRepairEffect::Initialize(void) {
    this->field_0x0 = 0;
    this->field_0x18 = 0;
    this->field_0x1C = 0;
    this->field_0x20 = 0;
    this->field_0x4 = 0;
}
INCLUDE_ASM("nonmatchings/game/cposdatamanage", Generate__13CRepairEffectFP9mgCMemoryi);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", Step__13CRepairEffectFv);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", Draw__13CRepairEffectFv);
struct CRepairSlot {
    u8 body[0x30];
};
struct CRepairManagerView {
    u8 pad0;
    s8 unk1;
    s16 unk2;
    s32 flag[8];
    CRepairSlot slot[8];
    s32 unk1A4;
    s32 unk1A8;
    s32 unk1AC;
    s32 unk1B0;
    u8 pad1B4[0x34];
    s8 unk1E8;
};
extern "C" s32 stSetBuffer__9mgCMemoryFP1i(...);
extern "C" void Initialize__14CRepairManagerFv(CRepairManagerView *objet) {
    s32 i;

    objet->unk1 = 0;
    objet->unk2 = -1;
    objet->unk1A4 = 0;
    objet->unk1A8 = 0;
    objet->unk1B0 = 0;
    objet->unk1AC = 0;
    for (i = 0; i < 8; i++) {
        objet->flag[i] = 0;
        stSetBuffer__9mgCMemoryFP1i(&objet->slot[i], 0, 0);
    }
    objet->unk1E8 = 0;
}
INCLUDE_ASM("nonmatchings/game/cposdatamanage", SetStack__14CRepairManagerFP9mgCMemoryi);
extern "C" void Clear__14CRepairManagerFv(CRepairManagerView *objet) {
    Initialize__14CRepairManagerFv(objet);
}
INCLUDE_ASM("nonmatchings/game/cposdatamanage", LoadDataBG__14CRepairManagerFP9mgCMemory);
extern "C" u8 _4888[20];
extern "C" u8 mgTexManager[540];
extern "C" s32 GetPackFile__FPUiPcPi(...);
extern "C" u8 _4890[11];
extern "C" u8 _4889[];
struct CRepairManager;
typedef struct CRepairManager {
    /* 0x000 */ s8 unk0;                            /* inferred */
    /* 0x001 */ u8 unk1;                            /* inferred */
    /* 0x002 */ s16 unk2;                           /* inferred */
    /* 0x004 */ char pad4[0x1A4];                   /* maybe part of unk2[0xD3]void */
    /* 0x1A8 */ s32 unk1A8;                         /* inferred */
    /* 0x1AC */ u32 *unk1AC;                        /* inferred */
} CRepairManager;                                   /* size >= 0x1B0 */
extern "C" s32 DeleteBlock__17mgCTextureManagerFi(void *, s32);
extern "C" s32 GetTexture__17mgCTextureManagerFPci(...);
extern "C" s32 MenuEnterIMG__FiPUcPc(...);
extern "C" void CheckDataBG__14CRepairManagerFi(CRepairManager *objet, s32 arg0) {
    s32 sp3C;

    if (objet->unk1 == 0) {
        DeleteBlock__17mgCTextureManagerFi(&mgTexManager, arg0);
        objet->unk2 = (s16) arg0;
        MenuEnterIMG__FiPUcPc(arg0, GetPackFile__FPUiPcPi(objet->unk1AC, &_4888, &sp3C), &_4889);
        objet->unk1A8 = GetTexture__17mgCTextureManagerFPci(&mgTexManager, &_4890, -1);
        objet->unk1 = 1;
        objet->unk0 = 0;
    }
}

INCLUDE_ASM("nonmatchings/game/cposdatamanage", SetRepairData__14CRepairManagerFP9mgCMemoryiPUi);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", GeneratePoly__14CRepairManagerFPfi);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", Generate__14CRepairManagerFii);
extern "C" s32 IsRunModel__14CRepairManagerFv(void *objet) { return *(s32 *) ((u8 *) objet + 0x1B0) != 0; }
extern "C" s32 IsRunModel__14CRepairManagerFv(void *);
extern "C" s32 IsRun__14CRepairManagerFv(CRepairManager *objet) {
    s32 i;
    s32 running;

    running = 0;
    for (i = 0; i < 8; i++) {
        if (*(s32 *) ((u8 *) objet + i * 4 + 4) != 0) {
            running = 1;
        }
    }
    if (IsRunModel__14CRepairManagerFv(objet) != 0) {
        running = 1;
    }
    return running;
}
INCLUDE_ASM("nonmatchings/game/cposdatamanage", Step__14CRepairManagerFv);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", Draw__14CRepairManagerFv);
void CLevelUpEffect::Initialize(void) {
    this->field_0x0 = 0;
    this->field_0x24 = 0;
    this->field_0x20 = 0;
}
struct mgCTexture {
    s16 field_0;
    s16 field_2;
    s16 field_4;
    s16 field_6;
    char pad_8[0x4];
    s32 field_C;
    s32 field_10;
    s16 field_14;
    char pad_16[0x2];
    s32 field_18;
    s32 field_1C;
    char pad_20[0x8];
    s32 field_28;
    s32 field_2C;
    s32 field_30;
    char pad_34[0x4];
    s64 field_38;
    s64 field_40;
    s64 field_48;
    s32 field_50;
    f32 field_54;
    f32 field_58;
    f32 field_5C;
    s32 field_60;
    s32 field_64;
    s32 field_68;
    char pad_6C[0xA4];
    s32 field_110;
    s32 field_114;
    s32 field_118;
    s16 field_11C;
    s8 field_11E;
    s8 field_11F;
    s16 field_120;
    s16 field_122;
    s32 field_124;
    s32 field_128;
    s8 field_12C;
    s8 field_12D;
    char pad_12E[0x2];
    s32 field_130;
    s32 field_134;
    s32 field_138;
    s32 field_13C;
    char pad_140[0x4];
    s32 field_144;
    s32 field_148;
    s32 field_14C;
    s32 field_150;
    s32 field_154;
    s32 field_158;
    s32 field_15C;
    s32 field_160;
    s32 field_164;
    s32 field_168;
    s32 field_16C;
    s32 field_170;
    s32 field_174;
    s32 field_178;
    s32 field_17C;
    s32 field_180;
    s32 field_184;
    s32 field_188;
    s32 field_18C;
    s32 field_190;
    char pad_194[0x60];
    s32 field_1F4;
    s32 field_1F8;
    s32 field_1FC;
    s8 field_200;
    s8 field_201;
    s16 field_202;
    s32 field_204;
    s8 field_208;
    s8 field_209;
    char pad_20A[0x2];
    s32 field_20C;
    s32 field_210;
    s32 field_214;
    s32 field_218;
    s32 field_21C;
    char pad_220[0xC];
    s32 field_22C;
    s32 field_230;
    s32 field_234;
    s32 field_238;
    s32 field_23C;
    s32 field_240;
    char pad_244[0x4];
    s32 field_248;
    s16 field_24C;
    s16 field_24E;
    char pad_250[0x6];
    s16 field_256;
    f32 field_258;
    f32 field_25C;
    char pad_260[0x4];
    f32 field_264;
    f32 field_268;
    f32 field_26C;
    char pad_270[0x4];
    f32 field_274;
    f32 field_278;
    char pad_27C[0x68];
    s32 field_2E4;
    char pad_2E8[0x74];
    s32 field_35C;
    s32 field_360;
    s32 field_364;
};
typedef struct CLevelUpEffect_infere {
    /* 0x00 */ s8 unk0;                             /* inferred */
    /* 0x01 */ char pad1[3];                        /* maybe part of unk0[4]void */
    /* 0x04 */ s32 unk4;                            /* inferred */
    /* 0x08 */ s32 unk8;                            /* inferred */
    /* 0x0C */ char padC[4];
    /* 0x10 */ f32 unk10;                           /* inferred */
    /* 0x14 */ f32 unk14;                           /* inferred */
    /* 0x18 */ char pad18[8];                       /* maybe part of unk14[3]void */
    /* 0x20 */ mgCTexture *unk20;                   /* inferred */
    /* 0x24 */ s32 unk24;                           /* inferred */
} CLevelUpEffect_infere;                                   /* size >= 0x28 */
extern "C" void Generate__14CLevelUpEffectFP10mgCTextureiii(CLevelUpEffect_infere *objet, mgCTexture *arg0, s32 arg1, s32 arg2, s32 arg3) {
    objet->unk20 = arg0;
    objet->unk8 = arg1;
    objet->unk10 = (f32) (arg2 - 0x10);
    objet->unk14 = (f32) arg3;
    objet->unk4 = 0;
    objet->unk24 = 0;
    objet->unk0 = 1;
}
INCLUDE_ASM("nonmatchings/game/cposdatamanage", Generate__14CLevelUpEffectFP10mgCTextureiP11CCharacter2);
u8 CLevelUpEffect::IsRun(void) {
    return this->field_0x0;
}
INCLUDE_ASM("nonmatchings/game/cposdatamanage", Step__14CLevelUpEffectFv);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", Draw__14CLevelUpEffectFv);
struct CLevelUpEffectSlot {
    u8 body[0x30];
};
struct CLevelUpEffectManagerView {
    s32 field_0;
    void *texture;
    u8 pad8[8];
    CLevelUpEffectSlot slot[8];
};
extern "C" s32 Initialize__14CLevelUpEffectFv(void *);
extern "C" void Initialize__21CLevelUpEffectManagerFv(CLevelUpEffectManagerView *objet) {
    s32 i;

    for (i = 0; i < 8; i++) {
        Initialize__14CLevelUpEffectFv(&objet->slot[i]);
    }
    objet->field_0 = 0;
}
INCLUDE_ASM("nonmatchings/game/cposdatamanage", IsRun__21CLevelUpEffectManagerFv);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", Generate__21CLevelUpEffectManagerFiii);
extern "C" s32 Generate__14CLevelUpEffectFP10mgCTextureiP11CCharacter2(void *, void *, s32, void *);
extern "C" s32 IsRun__14CLevelUpEffectFv(void *);
extern "C" void Generate__21CLevelUpEffectManagerFiP11CCharacter2(CLevelUpEffectManagerView *objet, s32 arg0, void *arg1) {
    s32 i;

    for (i = 0; i < 8; i++) {
        if (IsRun__14CLevelUpEffectFv(&objet->slot[i]) == 0) {
            Generate__14CLevelUpEffectFP10mgCTextureiP11CCharacter2(&objet->slot[i], objet->texture, arg0, arg1);
            break;
        }
    }
}
INCLUDE_ASM("nonmatchings/game/cposdatamanage", Step__21CLevelUpEffectManagerFv);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", Draw__21CLevelUpEffectManagerFv);
struct inferred;
typedef struct CStarDust {
    /* 0x0 */ f32 unk0;                             /* inferred */
    /* 0x4 */ f32 unk4;                             /* inferred */
    /* 0x8 */ s16 unk8;                             /* inferred */
    /* 0xA */ s8 unkA;                              /* inferred */
} CStarDust;                                        /* size >= 0xB */
extern "C" s32 GetRandI__Fi(s32);
extern "C" void Generate__9CStarDustFiiii(CStarDust *objet, s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    objet->unk0 = (f32) arg0;
    objet->unk4 = (f32) arg1;
    objet->unk8 = arg2 + GetRandI__Fi(arg3);
    objet->unkA = 1;
}
typedef struct CStarDust_infere {
    /* 0x0 */ char pad0[8];
    /* 0x8 */ s16 unk8;                             /* inferred */
    /* 0xA */ u8 unkA;                              /* inferred */
} CStarDust_infere;                                        /* size >= 0xB */
extern "C" void Step__9CStarDustFv(CStarDust_infere *objet) {
    if (objet->unkA != 0) {
        objet->unk8 -= 1;
        if (objet->unk8 < 0) {
            objet->unkA = 0;
        }
    }
}
extern "C" s32 GetMenuPrim__Fv(void);
#include "gen/mgCDrawPrim.hpp"
struct CStarDust_infere2;
typedef struct CStarDust_infere2 {
    /* 0x0 */ f32 unk0;                             /* inferred */
    /* 0x4 */ f32 unk4;                             /* inferred */
    /* 0x8 */ s16 unk8;                             /* inferred */
    /* 0xA */ u8 unkA;                              /* inferred */
} CStarDust_infere2;                                        /* size >= 0xB */
extern "C" s32 Begin__11mgCDrawPrimFi(void *, s32);
extern "C" s32 Color__11mgCDrawPrimFiiii(void *, s32, s32, s32, s32);
extern "C" s32 End__11mgCDrawPrimFv(void *);
extern "C" s32 SetSpriteEnv__FP11mgCDrawPrimi(mgCDrawPrim *, s32);
extern "C" s32 TextureCrd__11mgCDrawPrimFii(void *, s32, s32);
extern "C" s32 Texture__11mgCDrawPrimFP10mgCTexture(void *, mgCTexture *);
extern "C" s32 Vertex__11mgCDrawPrimFfff(void *, f32, f32, f32);
extern "C" void Draw__9CStarDustFP10mgCTextureii(CStarDust_infere2 *objet, mgCTexture *arg0, s32 arg1, s32 arg2) {
    s16 temp_v0;
    s32 var_s4;
    mgCDrawPrim *temp_v0_2;

    if ((objet->unkA != 0) && (arg0 != NULL)) {
        temp_v0 = (s16) (objet->unk8);
        var_s4 = 0x80;
        if (temp_v0 < 8) {
            var_s4 = temp_v0 * 0x10;
        }
        temp_v0_2 = (mgCDrawPrim *) (GetMenuPrim__Fv());
        SetSpriteEnv__FP11mgCDrawPrimi(temp_v0_2, 4);
        Begin__11mgCDrawPrimFi(temp_v0_2, 6);
        Texture__11mgCDrawPrimFP10mgCTexture(temp_v0_2, arg0);
        Color__11mgCDrawPrimFiiii(temp_v0_2, 0x80, 0x80, 0x80, var_s4);
        TextureCrd__11mgCDrawPrimFii(temp_v0_2, arg1, arg2);
        Vertex__11mgCDrawPrimFfff(temp_v0_2, objet->unk0, objet->unk4, 0.0f);
        TextureCrd__11mgCDrawPrimFii(temp_v0_2, arg1 + 8, arg2 + 8);
        Vertex__11mgCDrawPrimFfff(temp_v0_2, 8.0f + objet->unk0, 8.0f + objet->unk4, 0.0f);
        End__11mgCDrawPrimFv(temp_v0_2);
    }
}

INCLUDE_ASM("nonmatchings/game/cposdatamanage", CheckNotRunStarDust__FP9CStarDusti);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", CheckRunStarDust__FP9CStarDusti);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", Generate__16CEffVerticalLineFPfff);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", Step__16CEffVerticalLineFv);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", Draw__16CEffVerticalLineFv);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", InitInitBuildUpInfoEffectPos__Fv);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", InitBuildUpInfoEffect__FP9mgCMemoryP10mgCTextureif);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", SetBuildUpInfoChara__FP11CCharacter2f);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", StepBuildUpInfoEffect__Fv);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", DrawBuildUpInfoEffect__Fv);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", InitFishBoiledEffect__FPiP10mgCTexture);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", StepFishBoiledEffect__Fv);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", DrawFishBoiledEffect__Fv);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", SetEffectSpectolBreak__FP9mgCMemoryP11CMenuEffecti);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", SetEffectSpectolFusion__FP9mgCMemoryPP11CMenuEffectP13CGameDataUsedi);
