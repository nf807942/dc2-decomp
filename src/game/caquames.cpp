/* CAquaMes, CAquaFish, CBubble, CFishFood, CAquaFishEff, CAquaFishActionParam
 *
 * Unité découpée par `make carve` : 63 fonctions, 24504 octets, de
 * 0x0020E410 à 0x00214570. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"
#include "gen/CAquaFishEff.hpp"
#include "gen/CBubble.hpp"
#include "gen/CBubble.hpp"
struct mgCTexture;


INCLUDE_ASM("nonmatchings/game/caquames", MenuInventDraw__Fv);
extern "C" u32 aquarium_paul_table;
extern "C" s32 Get_aquarium_paul_table__Fi(s32 arg0) {
    s32 var_a0;

    var_a0 = arg0;
    if ((var_a0 < 0) || (var_a0 >= 0x3C)) {
        var_a0 = 0;
    }
    return aquarium_paul_table + (var_a0 * 8);
}
extern "C" s32 Get_aquarium_paul_table_xz__Fii(s32 arg0, s32 arg1) {
    return Get_aquarium_paul_table__Fi(arg0 + arg1 * 10);
}
INCLUDE_ASM("nonmatchings/game/caquames", local_aquarium_limmit_check__FPffif);
INCLUDE_ASM("nonmatchings/game/caquames", GetUseableEsaNo__FPi);
INCLUDE_ASM("nonmatchings/game/caquames", GetEsaInfo__Fi);
INCLUDE_ASM("nonmatchings/game/caquames", Generate__7CBubbleFi);
INCLUDE_ASM("nonmatchings/game/caquames", Generate__7CBubbleFPf);
void CBubble::SetTexture(mgCTexture * arg0, s32 arg1, s32 arg2) {
    this->field_0x28 = arg0;
    this->field_0x2C = arg1;
    this->field_0x2E = arg2;
}
INCLUDE_ASM("nonmatchings/game/caquames", Step__7CBubbleFv);
INCLUDE_ASM("nonmatchings/game/caquames", Draw__7CBubbleFv);
INCLUDE_ASM("nonmatchings/game/caquames", Initialize__7CBubbleFP9mgCMemoryPfif);
void CBubble::RunOff(void) {
    this->field_0x1 = 0;
    this->field_0x4 = 0;
}
INCLUDE_ASM("nonmatchings/game/caquames", GetChildFishNo__Fii);
extern "C" s32 GetBreedFishInfoData__Fi(s32);
extern "C" f32 SetFishAdjustScale__Fiiff(s32 arg0, s32 arg1, f32 arg2, f32 arg3) {
    f32 *temp_v0;
    f32 var_f0;
    f32 var_f20;

    var_f20 = arg2;
    temp_v0 = (f32 *) (GetBreedFishInfoData__Fi(arg1));
    if (temp_v0 != NULL) {
        var_f20 *= (f32) arg0 / *temp_v0;
    }
    var_f0 = var_f20;
    if (arg3 <= var_f20) {
        var_f0 = arg3;
    }
    return var_f0;
}
extern "C" void *memset(void *, int, unsigned);
extern "C" void Initialize__20CAquaFishActionParamFv(void *objet) {
    memset(objet, 0, 0x40);
}
INCLUDE_ASM("nonmatchings/game/caquames", __ct__9CAquaFishFv);
INCLUDE_ASM("nonmatchings/game/caquames", Initialize__9CAquaFishFv);
struct inferred;
struct CAquaFish;
struct CGameDataUsed;
typedef struct CAquaFish {
    /* 0x000 */ char pad0[0x92C];
    /* 0x92C */ s32 unk92C;                         /* inferred */
    /* 0x930 */ s32 unk930;                         /* inferred */
    /* 0x934 */ char pad934[4];
    /* 0x938 */ CGameDataUsed *unk938;              /* inferred */
} CAquaFish;                                        /* size >= 0x93C */
typedef struct CGameDataUsed {
    /* 0x00 */ char pad0[0x3C];
    /* 0x3C */ u16 unk3C;                           /* inferred */
} CGameDataUsed;                                    /* size >= 0x3E */
extern "C" s32 GetRandI__Fi(s32);
extern "C" void SetLiveParam__9CAquaFishFP13CGameDataUsed(CAquaFish *objet, CGameDataUsed *arg0) {
    CGameDataUsed *temp_v1;
    s32 temp_s1;

    objet->unk938 = arg0;
    temp_v1 = (CGameDataUsed *) (objet->unk938);
    temp_s1 = (s32) ((temp_v1->unk3C / 10) + ((u16) temp_v1->unk3C >> 0x1F));
    objet->unk930 = (temp_s1 + (GetRandI__Fi(0x14) + 0x1A)) * 0x14;
    objet->unk92C = 0;
}
INCLUDE_ASM("nonmatchings/game/caquames", SetAdjustScale__9CAquaFishFv);
INCLUDE_ASM("nonmatchings/game/caquames", AddFatigue__9CAquaFishFi);
INCLUDE_ASM("nonmatchings/game/caquames", GetPosition2D__9CAquaFishFPi);
INCLUDE_ASM("nonmatchings/game/caquames", GetDirVect__9CAquaFishFPf);
INCLUDE_ASM("nonmatchings/game/caquames", NormalGetNextVelo__9CAquaFishFf);
INCLUDE_ASM("nonmatchings/game/caquames", NormalGetNextRotY__9CAquaFishFv);
INCLUDE_ASM("nonmatchings/game/caquames", NormalGetNextRot__9CAquaFishFv);
INCLUDE_ASM("nonmatchings/game/caquames", CalcMoveSpeed__9CAquaFishFf);
INCLUDE_ASM("nonmatchings/game/caquames", NextRootNormal__9CAquaFishFv);
INCLUDE_ASM("nonmatchings/game/caquames", MoveActionRound__9CAquaFishFv);
INCLUDE_ASM("nonmatchings/game/caquames", MoveActionBattle__9CAquaFishFv);
INCLUDE_ASM("nonmatchings/game/caquames", NextThink__9CAquaFishFiP16NEXT_THINK_PARAM);
INCLUDE_ASM("nonmatchings/game/caquames", ParamStep__9CAquaFishFv);
INCLUDE_ASM("nonmatchings/game/caquames", FishDraw__9CAquaFishFv);
void CAquaFishEff::Initialize(void) {
    this->field_0x0 = 0;
    this->field_0x4 = 0;
    this->field_0x8 = 0;
    this->field_0xC = 0;
}
extern int max_tbl_1484[];
extern "C" void StartFishEffect__12CAquaFishEffFi(CAquaFishEff *p, int v) { p->field_0x8=(s16)v; p->field_0xC=max_tbl_1484[(u16)p->field_0x8]; }
struct inferred;
typedef struct CAquaFishEff_infere {
    /* 0x00 */ s32 unk0;                            /* inferred */
    /* 0x04 */ char pad4[4];
    /* 0x08 */ u16 unk8;                            /* inferred */
    /* 0x0A */ char padA[2];
    /* 0x0C */ s32 unkC;                            /* inferred */
} CAquaFishEff_infere;                                     /* size >= 0x10 */
extern "C" void Step__12CAquaFishEffFv(CAquaFishEff_infere *objet) {
    if ((objet->unk0 != 0) && (objet->unk8 != 0)) {
        objet->unkC -= 1;
        if (objet->unkC <= 0) {
            objet->unkC = 0;
            objet->unk8 = 0;
        }
    }
}
INCLUDE_ASM("nonmatchings/game/caquames", Draw__12CAquaFishEffFv);
INCLUDE_ASM("nonmatchings/game/caquames", __ct__9CFishFoodFv);
struct CFishFoodV {
    virtual void d0();
    virtual void d1();
    virtual void SetPos(void *p);
};
extern "C" void SetDropPosition__9CFishFoodFPf(CFishFoodV *self, f32 *pos) {
    *(u128 *)((u8 *)self + 0x670) = *(u128 *)pos;
    self->SetPos((u8 *)self + 0x670);
}
INCLUDE_ASM("nonmatchings/game/caquames", Drop__9CFishFoodFv);
INCLUDE_ASM("nonmatchings/game/caquames", Step__9CFishFoodFv);
INCLUDE_ASM("nonmatchings/game/caquames", DrawEsaDropRoot__FP9CFishFoodf);
INCLUDE_ASM("nonmatchings/game/caquames", AquaMesDispAdjustPos__FP6ClsMesPi);
struct CAquaMes_6b2193 {
    char pad_0[0x8];
    s32 field_8;
    u8 field_C;
    char pad_D[0x7];
    s32 field_14;
    u8 field_18;
    u8 field_19;
    u8 field_1A;
    char pad_1B[0x1];
    s32 field_1C;
    s32 field_20;
    f32 field_24;
    s32 field_28;
    char pad_2C[0x4];
    s32 field_30;
    u8 field_34;
    char pad_35[0x1];
    s16 field_36;
    char pad_38[0x4];
    s32 field_3C;
    u8 field_40;
    char pad_41[0x7];
    u8 field_48;
    char pad_49[0x7];
    u8 field_50;
    char pad_51[0x7];
    s32 field_58;
    s32 field_5C;
    s32 field_60;
};
#include "menu.hpp"
extern "C" s32 Initialize__8CAquaMesFP9mgCMemory(void *, mgCMemory *);
extern "C" CAquaMes_6b2193 *__ct__8CAquaMesFv(CAquaMes_6b2193 *objet) {
    Initialize__8CAquaMesFP9mgCMemory(objet, NULL);
    return objet;
}
INCLUDE_ASM("nonmatchings/game/caquames", Initialize__8CAquaMesFP9mgCMemory);
#include "gen/ClsMes.hpp"
struct inferred;
struct irregular;
typedef struct CAquaMes {
    /* 0x00 */ char pad0[0x10];
    /* 0x10 */ ClsMes *unk10;                       /* inferred */
} CAquaMes;                                         /* size >= 0x14 */
extern "C" s32 MakeMesWin__6ClsMesFi(void *, s32);
extern "C" s32 SetCtrlHelpId__8CAquaMesFi(void *, s32);
extern "C" s32 SetTitleId__8CAquaMesFi(void *, s32);
extern "C" void SettingAquaMes__8CAquaMesFi(CAquaMes *objet, s32 arg0) {
    switch (arg0) {                                 /* irregular */
    case 0:
        SetTitleId__8CAquaMesFi(objet, 0);
        MakeMesWin__6ClsMesFi(objet->unk10, 0xA);
        break;
    case 1:
        SetTitleId__8CAquaMesFi(objet, 1);
        MakeMesWin__6ClsMesFi(objet->unk10, 0xB);
        break;
    case 2:
        SetTitleId__8CAquaMesFi(objet, 2);
        MakeMesWin__6ClsMesFi(objet->unk10, 0xC);
        break;
    }
    SetCtrlHelpId__8CAquaMesFi(objet, 0x32);
}
INCLUDE_ASM("nonmatchings/game/caquames", SetTitleId__8CAquaMesFi);
INCLUDE_ASM("nonmatchings/game/caquames", AddMenuCursor__8CAquaMesFii);
INCLUDE_ASM("nonmatchings/game/caquames", SetQuestionId__8CAquaMesFiii);
INCLUDE_ASM("nonmatchings/game/caquames", AddQuestionCursor__8CAquaMesFv);
INCLUDE_ASM("nonmatchings/game/caquames", SetCtrlHelpId__8CAquaMesFi);
typedef struct CAquaMes_infere2 {
    /* 0x00 */ char pad0[0x4C];
    /* 0x4C */ struct unk4C_champs *unk4C;                       /* inferred */
} CAquaMes_infere2;                                         /* size >= 0x50 */
typedef struct ClsMes_infere {
    /* 0x0000 */ char pad0[0x1E3C];
    /* 0x1E3C */ s32 unk1E3C;                       /* inferred */
} ClsMes_infere;                                           /* size >= 0x1E40 */
struct unk4C_champs {
    char pad0[0x1E3C];
    /* 0x1E3C */ s32 unk1E3C;
};
extern "C" s32 Step__6ClsMesFv(void *);
extern "C" void SetInfoMsgID__8CAquaMesFi(CAquaMes_infere2 *objet, s32 arg0) {
    objet->unk4C->unk1E3C = -1;
    MakeMesWin__6ClsMesFi(objet->unk4C, arg0);
    Step__6ClsMesFv(objet->unk4C);
}
INCLUDE_ASM("nonmatchings/game/caquames", EatMessage__8CAquaMesFiP9CAquaFish);
INCLUDE_ASM("nonmatchings/game/caquames", ChangeManMessage__8CAquaMesFP9CAquaFish);
INCLUDE_ASM("nonmatchings/game/caquames", DeadMessage__8CAquaMesFP9CAquaFish);
INCLUDE_ASM("nonmatchings/game/caquames", Step__8CAquaMesFv);
INCLUDE_ASM("nonmatchings/game/caquames", Draw__8CAquaMesFv);
extern "C" u8 mgTexManager[540];
typedef struct MenuArg_champs {
    char pad0[52];
    s32 unk34;
    char pad38[96];
} MenuArg_champs;
extern "C" MenuArg_champs MenuArg;
struct sceVif1Packet;
typedef struct CAquaMes_infere {
    /* 0x0 */ char pad0[4];
    /* 0x4 */ ClsMes *unk4;                         /* inferred */
    /* 0x8 */ char pad8[4];
    /* 0xC */ u8 unkC;                              /* inferred */
} CAquaMes_infere;                                         /* size >= 0xD */
extern "C" s32 DrawMesWin__6ClsMesFv(void *);
extern "C" s32 ReloadTexture__17mgCTextureManagerFiP13sceVif1Packet(void *, s32, sceVif1Packet *);
extern "C" void DrawTitleMes__8CAquaMesFv(CAquaMes_infere *objet) {
    ClsMes *temp_a0;

    ReloadTexture__17mgCTextureManagerFiP13sceVif1Packet(&mgTexManager, MenuArg.unk34, NULL);
    temp_a0 = (ClsMes *) (objet->unk4);
    if ((temp_a0 != NULL) && (objet->unkC != 0)) {
        DrawMesWin__6ClsMesFv(temp_a0);
    }
}
extern "C" u8 _2377_0036F1E0[18];
extern "C" s32 GetItemFileName__Fii(s32, s32);
extern "C" s32 sprintf(...);
extern "C" s32 GetFishPath__FiPc(s32 arg0, s8 *arg1) {
    s32 temp_v0;

    temp_v0 = GetItemFileName__Fii(arg0, 1);
    if ((temp_v0 == 0) || (arg1 == NULL)) {
        return 1;
    }
    sprintf(arg1, &_2377_0036F1E0, temp_v0);
    return 0;
}
INCLUDE_ASM("nonmatchings/game/caquames", GetFishImgPath__FPciP14BREEDFISH_USED);
INCLUDE_ASM("nonmatchings/game/caquames", GetFishImageColor__Fii);
INCLUDE_ASM("nonmatchings/game/caquames", FishIMGReplace__FP1P11CCharacter2iP14BREEDFISH_USED);
INCLUDE_ASM("nonmatchings/game/caquames", DrawFishParam__FiiP10mgCTextureP13CGameDataUsed);
