/* CActionChara, CMapPiece, CMdsListSet, CObject, CMdsList, CObjectFrame, CIMGList, CCharacter2, CMdsInfo
 *
 * Unité découpée par `make carve` : 111 fonctions, 25492 octets, de
 * 0x00169820 à 0x0016FE00. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"
#include "gen/CActionChara.hpp"
#include "gen/CMapPiece.hpp"

INCLUDE_ASM("nonmatchings/game/cactionchara", GetMotionStatus__11CCharacter2Fv);
struct inferred;
typedef struct CCharacter2_infere5 {
    /* 0x000 */ char pad0[0x374];
    /* 0x374 */ s32 unk374;                         /* inferred */
} CCharacter2_infere5;                                      /* size >= 0x378 */
extern "C" s32 GetNowMotionName__11CCharacter2Fv(CCharacter2_infere5 *objet) {
    s32 temp_v0;

    temp_v0 = objet->unk374;
    if (temp_v0 != 0) {
        return temp_v0;
    }
    return 0;
}
INCLUDE_ASM("nonmatchings/game/cactionchara", GetNowFrameWait__11CCharacter2Fv);
INCLUDE_ASM("nonmatchings/game/cactionchara", SetNowFrame__11CCharacter2Ff);
INCLUDE_ASM("nonmatchings/game/cactionchara", GetNowFrame__11CCharacter2Fv);
INCLUDE_ASM("nonmatchings/game/cactionchara", GetStep__11CCharacter2Fv);
INCLUDE_ASM("nonmatchings/game/cactionchara", SetFadeFlag__11CCharacter2Fi);
INCLUDE_ASM("nonmatchings/game/cactionchara", GetFadeFlag__11CCharacter2Fv);
typedef struct CCharacter2 {
    /* 0x000 */ char pad0[0x118];
    /* 0x118 */ s32 unk118;                         /* inferred */
    /* 0x11C */ s32 unk11C;                         /* inferred */
} CCharacter2;                                      /* size >= 0x120 */
extern "C" s32 GetCopySize__11CCharacter2Fv(CCharacter2 *objet) {
    s32 temp_v0;

    temp_v0 = objet->unk11C;
    if (temp_v0 > 0) {
        return temp_v0;
    }
    return objet->unk118;
}
INCLUDE_ASM("nonmatchings/game/cactionchara", SetPosition__11CCharacter2Ffff);
struct inferred;
typedef struct CMapPiece_infere {
    /* 0x00 */ char pad0[0x50];
    /* 0x50 */ f32 unk50;                           /* inferred */
    /* 0x54 */ s32 unk54;                           /* inferred */
    /* 0x58 */ char pad58[0x18];                    /* maybe part of unk54[7]void */
    /* 0x70 */ s32 unk70;                           /* inferred */
    /* 0x74 */ char pad74[0xC];                     /* maybe part of unk70[4]void */
    /* 0x80 */ s32 unk80;                           /* inferred */
    /* 0x84 */ s32 unk84;                           /* inferred */
    /* 0x88 */ char pad88[0x14];                    /* maybe part of unk84[6]void */
    /* 0x9C */ s32 unk9C;                           /* inferred */
} CMapPiece_infere;                                        /* size >= 0xA0 */
typedef struct CMdsInfo_infere {
    /* 0x00 */ s32 unk0;                            /* inferred */
    /* 0x04 */ s32 unk4;                            /* inferred */
    /* 0x08 */ s32 unk8;                            /* inferred */
    /* 0x0C */ s32 unkC;                            /* inferred */
    /* 0x10 */ f32 unk10;                           /* inferred */
    /* 0x14 */ s32 unk14;                           /* inferred */
} CMdsInfo_infere;                                         /* size >= 0x18 */
extern "C" s32 AssignMds__9CMapPieceFP8CMdsInfo(CMapPiece_infere *objet, CMdsInfo_infere *arg0) {
    if (arg0 == NULL) {
        return 0;
    }
    objet->unk80 = arg0->unk0;
    objet->unk9C = arg0->unkC;
    objet->unk84 = arg0->unk4;
    objet->unk70 = arg0->unk8;
    objet->unk50 = arg0->unk10;
    objet->unk54 = arg0->unk14;
    return 1;
}
INCLUDE_ASM("nonmatchings/game/cactionchara", GetPoly__9CMapPieceFiP6CCPolyR9mgVu0FBOXi);
void CMapPiece::SetTimeBand(f32 arg0, f32 arg1) {
    this->field_0x94 = arg0;
    this->field_0x98 = arg1;
}
INCLUDE_ASM("nonmatchings/game/cactionchara", GetMaterial__9CMapPieceFi);
INCLUDE_ASM("nonmatchings/game/cactionchara", Step__9CMapPieceFv);
INCLUDE_ASM("nonmatchings/game/cactionchara", GetBoundBox__9CMapPieceFP9mgVu0FBOX);
INCLUDE_ASM("nonmatchings/game/cactionchara", DrawSub__9CMapPieceFi);
INCLUDE_ASM("nonmatchings/game/cactionchara", Copy__9CMapPieceFR9CMapPieceP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/cactionchara", Initialize__9CMapPieceFv);
typedef struct CMdsInfo {
    /* 0x00 */ s32 unk0;                            /* inferred */
    /* 0x04 */ s32 unk4;                            /* inferred */
    /* 0x08 */ s32 unk8;                            /* inferred */
    /* 0x0C */ s32 unkC;                            /* inferred */
    /* 0x10 */ s32 unk10;                           /* inferred */
    /* 0x14 */ s32 unk14;                           /* inferred */
} CMdsInfo;                                         /* size >= 0x18 */
extern "C" void Initialize__8CMdsInfoFv(CMdsInfo *objet) {
    objet->unk0 = 0;
    objet->unk4 = 0;
    objet->unk8 = 0;
    objet->unkC = 0;
    objet->unk10 = 0xBF800000;
    objet->unk14 = 0;
}
INCLUDE_ASM("nonmatchings/game/cactionchara", SearchMdsList__11CMdsListSetFPc);
INCLUDE_ASM("nonmatchings/game/cactionchara", GetMdsList__11CMdsListSetFi);
INCLUDE_ASM("nonmatchings/game/cactionchara", SearchMDS__11CMdsListSetFPc);
INCLUDE_ASM("nonmatchings/game/cactionchara", LoadPCPFile__11CMdsListSetFPcPUiP9mgCMemoryi);
extern "C" s32 SearchMdsList__11CMdsListSetFPc(...);
struct CMdsListSet {
    s32 field_0;
    char pad_4[0x8C];
    s32 field_90;
};
struct temp_v0_champs {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ s32 unk8;
};
extern "C" s32 DeleteMdsList__11CMdsListSetFPc(CMdsListSet *objet, s8 *arg0) {
    struct temp_v0_champs *temp_v0;

    temp_v0 = (struct temp_v0_champs *) (SearchMdsList__11CMdsListSetFPc(objet, arg0));
    if (temp_v0 == NULL) {
        return 0;
    }
    temp_v0->unk0 = 0;
    temp_v0->unk4 = 0;
    temp_v0->unk8 = 0;
    return 1;
}
INCLUDE_ASM("nonmatchings/game/cactionchara", LoadIMGFile__11CMdsListSetFPcP15mgCEnterIMGInfoP9mgCMemory);
extern "C" s32 SearchIMGList__11CMdsListSetFPc(...);
struct temp_v0_champs_05c0e1 {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
};
extern "C" void DeleteIMG__11CMdsListSetFPc(CMdsListSet *objet, s8 *arg0) {
    struct temp_v0_champs_05c0e1 *temp_v0;

    temp_v0 = (struct temp_v0_champs_05c0e1 *) (SearchIMGList__11CMdsListSetFPc(objet, arg0));
    if (temp_v0 != NULL) {
        temp_v0->unk0 = 0;
        temp_v0->unk4 = 0;
    }
}
INCLUDE_ASM("nonmatchings/game/cactionchara", SearchIMGList__11CMdsListSetFPc);
INCLUDE_ASM("nonmatchings/game/cactionchara", GetTextureBlockNo__11CMdsListSetFiPii);
INCLUDE_ASM("nonmatchings/game/cactionchara", Initialize__11CMdsListSetFv);
INCLUDE_ASM("nonmatchings/game/cactionchara", GetList__8CMdsListFi);
INCLUDE_ASM("nonmatchings/game/cactionchara", GetListID__8CMdsListFPc);
struct CMdsList {
    s32 field_0;
    s32 field_4;
};
extern "C" s32 GetListID__8CMdsListFPc(CMdsList *objet, s8 *arg0);
extern "C" s32 GetList__8CMdsListFi(CMdsList *objet, s32 arg0);
extern "C" s32 GetList__8CMdsListFPc(CMdsList *objet, s8 *arg0) {
    s32 temp_v0;

    temp_v0 = GetListID__8CMdsListFPc(objet, arg0);
    if (temp_v0 < 0) {
        return 0;
    }
    return GetList__8CMdsListFi(objet, temp_v0);
}
INCLUDE_ASM("nonmatchings/game/cactionchara", LoadIMGFile__8CIMGListFPcP15mgCEnterIMGInfoP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/cactionchara", pcpMDS__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cactionchara", pcpTYPE__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cactionchara", pcpFAR_CLIP__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cactionchara", pcpMDS_END__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cactionchara", LoadPCPFile__8CMdsListFPcPUiP9mgCMemoryi);
INCLUDE_ASM("nonmatchings/game/cactionchara", __ct__8CMdsInfoFv);
INCLUDE_ASM("nonmatchings/game/cactionchara", CreateChara__FPUiPcP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/cactionchara", GetMatrix__7CObjectFPA4_f);
INCLUDE_ASM("nonmatchings/game/cactionchara", FarClip__7CObjectFfPf);
INCLUDE_ASM("nonmatchings/game/cactionchara", GetCameraDist__7CObjectFv);
INCLUDE_ASM("nonmatchings/game/cactionchara", CheckDraw__7CObjectFv);
INCLUDE_ASM("nonmatchings/game/cactionchara", DrawStep__7CObjectFv);
INCLUDE_ASM("nonmatchings/game/cactionchara", GetAlpha__7CObjectFv);
INCLUDE_ASM("nonmatchings/game/cactionchara", PreDraw__7CObjectFv);
INCLUDE_ASM("nonmatchings/game/cactionchara", Initialize__7CObjectFv);
INCLUDE_ASM("nonmatchings/game/cactionchara", UpDatePosition__12CObjectFrameFv);
INCLUDE_ASM("nonmatchings/game/cactionchara", DrawStep__12CObjectFrameFv);
INCLUDE_ASM("nonmatchings/game/cactionchara", GetCameraDist__12CObjectFrameFv);
INCLUDE_ASM("nonmatchings/game/cactionchara", PreDraw__12CObjectFrameFv);
#include "gen/mgCFrame.hpp"
typedef struct CObjectFrame {
    /* 0x00 */ char pad0[0x70];
    /* 0x70 */ mgCFrame *unk70;                     /* inferred */
} CObjectFrame;                                     /* size >= 0x74 */
extern "C" void mgDraw__FP8mgCFrame(mgCFrame *arg0);
extern "C" s32 PreDraw__12CObjectFrameFv(...);
extern "C" s32 Draw__12CObjectFrameFv(CObjectFrame *objet) {
    if (PreDraw__12CObjectFrameFv(objet) == 0) {
        return 0;
    }
    mgDraw__FP8mgCFrame(objet->unk70);
    return 0;
}
typedef struct CObjectFrame_infere {
    /* 0x00 */ char pad0[0x70];
    /* 0x70 */ mgCFrame *unk70;                     /* inferred */
} CObjectFrame_infere;                                     /* size >= 0x74 */
extern "C" s32 mgDrawDirect__FP8mgCFrame(mgCFrame *);
extern "C" s32 DrawDirect__12CObjectFrameFv(CObjectFrame_infere *objet) {
    if (PreDraw__12CObjectFrameFv(objet) == 0) {
        return 0;
    }
    mgDrawDirect__FP8mgCFrame(objet->unk70);
    return 0;
}
INCLUDE_ASM("nonmatchings/game/cactionchara", Copy__12CObjectFrameFR12CObjectFrameP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/cactionchara", Initialize__12CObjectFrameFv);
void CActionChara::ResetAccele(void) {
    this->field_0x788 = 0;
    this->field_0x784 = 0;
    this->field_0x780 = 0;
    this->field_0x790 = 0;
}
INCLUDE_ASM("nonmatchings/game/cactionchara", ResetAction__12CActionCharaFv);
INCLUDE_ASM("nonmatchings/game/cactionchara", ResetScript__12CActionCharaFv);
INCLUDE_ASM("nonmatchings/game/cactionchara", CheckRunEvent__12CActionCharaFv);
INCLUDE_ASM("nonmatchings/game/cactionchara", SetMaskFlag__12CActionCharaFii);
INCLUDE_ASM("nonmatchings/game/cactionchara", EntryObject__12CActionCharaFPci);
struct CActionChara_infere_2070c5;
typedef struct CActionChara_infere_2070c5 {
    /* 0x000 */ char pad0[0xC00];
    /* 0xC00 */ mgCFrame *unkC00;                   /* inferred */
} CActionChara_infere_2070c5;                                     /* size >= 0xC04 */
struct objet_champs_2070c5 {
    char pad0[0xC00];
    /* 0xC00 */ s32 unkC00;
};
extern "C" s32 GetWorldPosition0__8mgCFrameFPf(void *, f32 *);
extern "C" void CalcCollision__12CActionCharaFv(CActionChara_infere_2070c5 *objet) {
    mgCFrame **var_s0;
    mgCFrame *temp_a0;
    s32 var_s1;

    var_s1 = 0;
    var_s0 = (mgCFrame **) (&((struct objet_champs_2070c5 *) objet)->unkC00);
    do {
        temp_a0 = (mgCFrame *) (*var_s0);
        if (temp_a0 != NULL) {
            GetWorldPosition0__8mgCFrameFPf(temp_a0, (f32 *) (((mgCFrame **) ((u8 *) var_s0 + 0x10))));
        }
        var_s1 += 1;
        /* m2c compte les pas de pointeur en octets ; MWCC les met a
        * l'echelle du type pointe. Le pas est donc ecrit en elements,
        * et le commerce rend la meme constante. */
        var_s0 += 8;
    } while (var_s1 < 8);
}

INCLUDE_ASM("nonmatchings/game/cactionchara", EntryBodyCol__12CActionCharaFif);
INCLUDE_ASM("nonmatchings/game/cactionchara", EntryDamage2__12CActionCharaFPcPcPcfPcffPc);
INCLUDE_ASM("nonmatchings/game/cactionchara", EntryDamage2__12CActionCharaFP8mgCFrameP8mgCFramePcfPcffPc);
INCLUDE_ASM("nonmatchings/game/cactionchara", AllDeleteDamage__12CActionCharaFv);
struct CActionChara_infere_4bcc74;
typedef struct CActionChara_infere_4bcc74 {
    /* 0x000 */ char pad0[0x7E4];
    /* 0x7E4 */ char unk7E4;                           /* inferred */
    /* 0x7E4 */ char pad7E4[1];
} CActionChara_infere_4bcc74;                                     /* size >= 0x7E5 */
struct objet_champs_4bcc74 {
    char pad0[0x7E4];
    /* 0x7E4 */ s32 unk7E4;
};
struct var_v0_champs_4bcc74 {
    char pad0[0x8];
    /* 0x8 */ s32 unk8;
};
extern "C" void *GetSwEffectPtr__12CActionCharaFv(CActionChara_infere_4bcc74 *objet) {
    void *var_v0;
    s32 var_a0;

    var_v0 = (void *) (&((struct objet_champs_4bcc74 *) objet)->unk7E4);
    var_a0 = 0;
loop_1:
    if (((struct var_v0_champs_4bcc74 *) var_v0)->unk8 == 0) {
        return var_v0;
    }
    var_a0 += 1;
    ((u8 *) var_v0) += 0x20;
    if (var_a0 >= 9) {
        return NULL;
    }
    goto loop_1;
}
INCLUDE_ASM("nonmatchings/game/cactionchara", SetSoundInfoCopy__12CActionCharaFv);
typedef struct CActionChara_infere10 {
    /* 0x000 */ char pad0[0x54];
    /* 0x054 */ s32 unk54;                          /* inferred */
    /* 0x058 */ char pad58[0x620];                  /* maybe part of unk54[0x189]void */
    /* 0x678 */ CActionChara_infere10 *unk678;               /* inferred */
} CActionChara_infere10;                                     /* size >= 0x67C */
extern "C" void SetFadeFlag__12CActionCharaFi(CActionChara_infere10 *objet, s32 arg0) {
    CActionChara_infere10 *var_a0;

    var_a0 = (CActionChara_infere10 *) (objet);
    if (var_a0 != NULL) {
        do {
            var_a0->unk54 = arg0;
            var_a0 = (CActionChara_infere10 *) (var_a0->unk678);
        } while (var_a0 != NULL);
    }
}
typedef struct CActionChara_infere11 {
    /* 0x000 */ char pad0[0x50];
    /* 0x050 */ f32 unk50;                          /* inferred */
    /* 0x054 */ char pad54[0x624];                  /* maybe part of unk50[0x18A]void */
    /* 0x678 */ CActionChara_infere11 *unk678;               /* inferred */
} CActionChara_infere11;                                     /* size >= 0x67C */
extern "C" void SetFarDist__12CActionCharaFf(CActionChara_infere11 *objet, f32 arg0) {
    CActionChara_infere11 *var_a0;

    var_a0 = (CActionChara_infere11 *) (objet);
    if (var_a0 != NULL) {
        do {
            var_a0->unk50 = arg0;
            var_a0 = (CActionChara_infere11 *) (var_a0->unk678);
        } while (var_a0 != NULL);
    }
}
typedef struct CActionChara_infere12 {
    /* 0x000 */ char pad0[0x60];
    /* 0x060 */ f32 unk60;                          /* inferred */
    /* 0x064 */ char pad64[0x614];                  /* maybe part of unk60[0x186]void */
    /* 0x678 */ CActionChara_infere12 *unk678;               /* inferred */
} CActionChara_infere12;                                     /* size >= 0x67C */
extern "C" void SetNearDist__12CActionCharaFf(CActionChara_infere12 *objet, f32 arg0) {
    CActionChara_infere12 *var_a0;

    var_a0 = (CActionChara_infere12 *) (objet);
    if (var_a0 != NULL) {
        do {
            var_a0->unk60 = arg0;
            var_a0 = (CActionChara_infere12 *) (var_a0->unk678);
        } while (var_a0 != NULL);
    }
}
typedef struct CActionChara_infere8 {
    /* 0x000 */ char pad0[0x674];
    /* 0x674 */ CCharacter2 *unk674;                /* inferred */
} CActionChara_infere8;                                     /* size >= 0x678 */
extern "C" s32 GetCameraDist__11CCharacter2Fv(void *);
extern "C" void GetCameraDist__12CActionCharaFv(CActionChara_infere8 *objet) {
    CCharacter2 *temp_v0;

    temp_v0 = (CCharacter2 *) (objet->unk674);
    if (temp_v0 != NULL) {
        GetCameraDist__11CCharacter2Fv(temp_v0);
        return;
    }
    GetCameraDist__11CCharacter2Fv((CCharacter2 *) objet);
}
typedef struct CActionChara_infere7 {
    /* 0x000 */ char pad0[0x64];
    /* 0x064 */ s32 unk64;                          /* inferred */
    /* 0x068 */ char pad68[0x610];                  /* maybe part of unk64[0x185]void */
    /* 0x678 */ CActionChara_infere7 *unk678;               /* inferred */
} CActionChara_infere7;                                     /* size >= 0x67C */
extern "C" void Show__12CActionCharaFii(CActionChara_infere7 *objet, s32 arg0, s32 arg1) {
    CActionChara_infere7 *var_a0;

    var_a0 = (CActionChara_infere7 *) (objet);
    if (arg1 == 0) {
        var_a0->unk64 = arg0;
        return;
    }
    if (var_a0 != NULL) {
        do {
            var_a0->unk64 = arg0;
            var_a0 = (CActionChara_infere7 *) (var_a0->unk678);
        } while (var_a0 != NULL);
    }
}
INCLUDE_ASM("nonmatchings/game/cactionchara", GetShow__12CActionCharaFPc);
INCLUDE_ASM("nonmatchings/game/cactionchara", CheckKeri__12CActionCharaFPci);
INCLUDE_ASM("nonmatchings/game/cactionchara", CheckEnemyCatch__12CActionCharaFPc);
INCLUDE_ASM("nonmatchings/game/cactionchara", ThrowItemObject__12CActionCharaFv);
INCLUDE_ASM("nonmatchings/game/cactionchara", UsedItemAction__12CActionCharaFv);
INCLUDE_ASM("nonmatchings/game/cactionchara", EntryThrowItem__12CActionCharaFv);
struct CEffectScriptMan {
    char pad_0[0xC];
    s32 field_C;
    s32 field_10;
    s32 field_14;
    s32 field_18;
    s32 field_1C;
    s32 field_20;
    s32 field_24;
    s32 field_28;
    char pad_2C[0x154];
    s32 field_180;
    char pad_184[0x1D8];
    s32 field_35C;
    s32 field_360;
    s32 field_364;
};
struct inferred;
typedef struct CActionChara_infere4 {
    /* 0x000 */ char pad0[0x71C];
    /* 0x71C */ s16 unk71C;                         /* inferred */
    /* 0x71E */ char pad71E[0xBE];                  /* maybe part of unk71C[0x60]void */
    /* 0x7DC */ CEffectScriptMan *unk7DC;           /* inferred */
    /* 0x7E0 */ s8 unk7E0;                          /* inferred */
} CActionChara_infere4;                                     /* size >= 0x7E1 */
extern "C" s32 DeleteEffSpt__16CEffectScriptManFii(void *, s32, s32);
extern "C" s32 GetBattleCharaInfo__Fv(void);
extern "C" void RemoveThrowItem__12CActionCharaFv(CActionChara_infere4 *objet) {
    s8 temp_a2;

    if (objet->unk71C != 0) {
        GetBattleCharaInfo__Fv();
        if (objet->unk71C == 1) {
            temp_a2 = objet->unk7E0;
            if (temp_a2 >= 0) {
                DeleteEffSpt__16CEffectScriptManFii(objet->unk7DC, 0, (s32) temp_a2);
            }
            objet->unk71C = 0;
        }
    }
}
INCLUDE_ASM("nonmatchings/game/cactionchara", GetNowFrameWait__12CActionCharaFPc);
INCLUDE_ASM("nonmatchings/game/cactionchara", GetNowFrame__12CActionCharaFPc);
INCLUDE_ASM("nonmatchings/game/cactionchara", CheckMotionEnd__12CActionCharaFPc);
INCLUDE_ASM("nonmatchings/game/cactionchara", GetMotionStatus__12CActionCharaFPc);
INCLUDE_ASM("nonmatchings/game/cactionchara", GetWaitToFrame__12CActionCharaFPcfPc);
struct inferred;
typedef struct CActionChara_infere3 {
    /* 0x000 */ char pad0[0x678];
    /* 0x678 */ CActionChara_infere3 *unk678;               /* inferred */
} CActionChara_infere3;                                     /* size >= 0x67C */
typedef struct CCharacter2_infere2 {
    /* 0x000 */ char pad0[0x678];
    /* 0x678 */ CCharacter2_infere2 *unk678;                /* inferred */
} CCharacter2_infere2;                                      /* size >= 0x67C */
extern "C" s32 SetMotion__11CCharacter2Fii(void *, s32, s32);
extern "C" void SetMotion__12CActionCharaFii(CActionChara_infere3 *objet, s32 arg0, s32 arg1) {
    CActionChara_infere3 *var_s0;

    var_s0 = (CActionChara_infere3 *) (objet);
    if (objet != NULL) {
        do {
            SetMotion__11CCharacter2Fii((CCharacter2_infere2 *) var_s0, arg0, arg1);
            var_s0 = (CActionChara_infere3 *) (var_s0->unk678);
        } while (var_s0 != NULL);
    }
}
struct inferred;
typedef struct CActionChara_infere {
    /* 0x000 */ char pad0[0x678];
    /* 0x678 */ CActionChara_infere *unk678;               /* inferred */
} CActionChara_infere;                                     /* size >= 0x67C */
typedef struct CCharacter2_infere {
    /* 0x000 */ char pad0[0x678];
    /* 0x678 */ CCharacter2_infere *unk678;                /* inferred */
} CCharacter2_infere;                                      /* size >= 0x67C */
extern "C" s32 SetMotion__11CCharacter2FPci(...);
extern "C" void SetMotion__12CActionCharaFPcii(CActionChara_infere *objet, s8 *arg0, s32 arg1, s32 arg2) {
    CActionChara_infere *var_s0;

    var_s0 = (CActionChara_infere *) (objet);
    if (arg2 == 0) {
        SetMotion__11CCharacter2FPci((CCharacter2_infere *) objet, arg0, arg1);
        return;
    }
    if (objet != NULL) {
        do {
            SetMotion__11CCharacter2FPci((CCharacter2_infere *) var_s0, arg0, arg1);
            var_s0 = (CActionChara_infere *) (var_s0->unk678);
        } while (var_s0 != NULL);
    }
}
typedef struct CActionChara_infere5 {
    /* 0x000 */ char pad0[0x678];
    /* 0x678 */ CActionChara_infere5 *unk678;               /* inferred */
} CActionChara_infere5;                                     /* size >= 0x67C */
typedef struct CCharacter2_infere3 {
    /* 0x000 */ char pad0[0x678];
    /* 0x678 */ CCharacter2_infere3 *unk678;                /* inferred */
} CCharacter2_infere3;                                      /* size >= 0x67C */
extern "C" s32 ResetMotion__11CCharacter2Fv(void *);
extern "C" void ResetMotion__12CActionCharaFv(CActionChara_infere5 *objet) {
    CActionChara_infere5 *var_s0;

    var_s0 = (CActionChara_infere5 *) (objet);
    if (objet != NULL) {
        do {
            ResetMotion__11CCharacter2Fv((CCharacter2_infere3 *) var_s0);
            var_s0 = (CActionChara_infere5 *) (var_s0->unk678);
        } while (var_s0 != NULL);
    }
}
INCLUDE_ASM("nonmatchings/game/cactionchara", Draw__12CActionCharaFv);
INCLUDE_ASM("nonmatchings/game/cactionchara", DrawDirect__12CActionCharaFv);
typedef struct CActionChara_infere6 {
    /* 0x000 */ char pad0[0x678];
    /* 0x678 */ CActionChara_infere6 *unk678;               /* inferred */
} CActionChara_infere6;                                     /* size >= 0x67C */
typedef struct CCharacter2_infere4 {
    /* 0x000 */ char pad0[0x678];
    /* 0x678 */ CCharacter2_infere4 *unk678;                /* inferred */
} CCharacter2_infere4;                                      /* size >= 0x67C */
extern "C" s32 DrawShadowDirect__11CCharacter2Fv(void *);
extern "C" void DrawShadowDirect__12CActionCharaFv(CActionChara_infere6 *objet) {
    CActionChara_infere6 *var_s0;

    var_s0 = (CActionChara_infere6 *) (objet);
    if (objet != NULL) {
        do {
            DrawShadowDirect__11CCharacter2Fv((CCharacter2_infere4 *) var_s0);
            var_s0 = (CActionChara_infere6 *) (var_s0->unk678);
        } while (var_s0 != NULL);
    }
}
typedef struct CActionChara_infere9 {
    /* 0x000 */ char pad0[0x7DC];
    /* 0x7DC */ CEffectScriptMan *unk7DC;           /* inferred */
} CActionChara_infere9;                                     /* size >= 0x7E0 */
extern "C" s32 DrawEffect__11CCharacter2Fv(void *);
extern "C" s32 Draw__16CEffectScriptManFv(void *);
extern "C" void DrawEffect__12CActionCharaFv(CActionChara_infere9 *objet) {
    CEffectScriptMan *temp_a0;

    DrawEffect__11CCharacter2Fv((CCharacter2 *) objet);
    temp_a0 = (CEffectScriptMan *) (objet->unk7DC);
    if (temp_a0 != NULL) {
        Draw__16CEffectScriptManFv(temp_a0);
    }
}
INCLUDE_ASM("nonmatchings/game/cactionchara", StepEffect__12CActionCharaFv);
INCLUDE_ASM("nonmatchings/game/cactionchara", SearchChara__12CActionCharaFPc);
typedef struct CActionChara_infere2 {
    /* 0x000 */ char pad0[0x70];
    /* 0x070 */ mgCFrame *unk70;                    /* inferred */
    /* 0x074 */ char pad74[0x604];                  /* maybe part of unk70[0x182]void */
    /* 0x678 */ CActionChara_infere2 *unk678;               /* inferred */
} CActionChara_infere2;                                     /* size >= 0x67C */
extern "C" s32 SearchFrame__8mgCFrameFPc(...);
extern "C" s32 SearchObject__12CActionCharaFPc(CActionChara_infere2 *objet, s8 *arg0) {
    CActionChara_infere2 *var_s0;
    mgCFrame *temp_a0;
    s32 temp_v0;

    var_s0 = (CActionChara_infere2 *) (objet);
    if (objet != NULL) {
loop_1:
        temp_a0 = (mgCFrame *) (var_s0->unk70);
        if (temp_a0 == NULL) {
            var_s0 = (CActionChara_infere2 *) (var_s0->unk678);
            goto block_6;
        }
        temp_v0 = (s32) (SearchFrame__8mgCFrameFPc(temp_a0, arg0));
        if (temp_v0 != 0) {
            return temp_v0;
        }
        var_s0 = (CActionChara_infere2 *) (var_s0->unk678);
block_6:
        if (var_s0 == NULL) {
            goto block_7;
        }
        goto loop_1;
    }
block_7:
    return 0;
}
typedef struct CActionChara_infere13 {
    /* 0x000 */ char pad0[0x70];
    /* 0x070 */ mgCFrame *unk70;                    /* inferred */
    /* 0x074 */ char pad74[0x604];                  /* maybe part of unk70[0x182]void */
    /* 0x678 */ s32 unk678;                         /* inferred */
} CActionChara_infere13;                                     /* size >= 0x67C */
extern "C" s32 DeleteReference__8mgCFrameFv(void *);
extern "C" void ResetParent__12CActionCharaFv(CActionChara_infere13 *objet) {
    mgCFrame *temp_a0;

    objet->unk678 = 0;
    temp_a0 = (mgCFrame *) (objet->unk70);
    if (temp_a0 != NULL) {
        DeleteReference__8mgCFrameFv(temp_a0);
    }
}
INCLUDE_ASM("nonmatchings/game/cactionchara", SetRef__12CActionCharaFP12CActionCharaPc);
INCLUDE_ASM("nonmatchings/game/cactionchara", GetTargetDist__12CActionCharaFP6CScene);
INCLUDE_ASM("nonmatchings/game/cactionchara", RockOn_TargetSel__FP6CScenei);
INCLUDE_ASM("nonmatchings/game/cactionchara", DistCheck_Action2__FP6CSceneffPfiPi);
INCLUDE_ASM("nonmatchings/game/cactionchara", Check_LockOn__FP6CScenefi);
INCLUDE_ASM("nonmatchings/game/cactionchara", CollisionCheck__12CActionCharaFPfPfPf);
INCLUDE_ASM("nonmatchings/game/cactionchara", RockOn__12CActionCharaFv);
INCLUDE_ASM("nonmatchings/game/cactionchara", HumanMoveIF__12CActionCharaFv);
INCLUDE_ASM("nonmatchings/game/cactionchara", HumanShrowMoveIF__12CActionCharaFv);
INCLUDE_ASM("nonmatchings/game/cactionchara", HumanTameMoveIF__12CActionCharaFv);
INCLUDE_ASM("nonmatchings/game/cactionchara", HumanGunMoveIF__12CActionCharaFPcPc);
INCLUDE_ASM("nonmatchings/game/cactionchara", RoboWalkMoveIF__12CActionCharaFi);
INCLUDE_ASM("nonmatchings/game/cactionchara", RoboTankMoveIF__12CActionCharaFi);
