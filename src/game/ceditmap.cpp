/* CEditMap, CRocketLauncher, CEditParts, CEditPartsInfo, CEditHouse
 *
 * Unité découpée par `make carve` : 100 fonctions, 25496 octets, de
 * 0x001B16D0 à 0x001B7C50. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"
#include "gen/CRocketLauncher.hpp"

class CEditMap {
public:
    char pad_0[0xC88];
    f32 field_C88;
    char pad_C8C[0xA8];
    s32 field_D34;
    s32 field_D38;
    char pad_D3C[0x4];
    s32 field_D40;
    s32 field_D44;
    char pad_D48[0x200];
    s32 field_F48;
    s32 field_F4C;
    s32 field_F50;
    char pad_F54[0x10];
    s32 field_F64;
    s32 field_F68;
    char pad_F6C[0x14];
    s32 field_F80;
    s32 field_F84;
    s32 field_F88;
    s32 field_F8C;
    s32 field_F90;
    char pad_F94[0x4];
    s32 field_F98;
    s32 field_F9C;
    s32 field_FA0;
    s32 field_FA4;
    s32 field_FA8;
    s32 field_FAC;
    s32 field_FB0;
    s32 field_FB4;
    s32 field_FB8;
    s32 field_FBC;
    s32 field_FC0;
    s32 field_FC4;
    s32 field_FC8;
    s32 field_FCC;
    s32 field_FD0;
    s32 field_FD4;
    s32 field_FD8;
    s32 field_FDC;
    s32 field_FE0;
    s32 field_FE4;
    s32 field_FE8;
    s32 field_FEC;
    s32 field_FF0;
    s32 field_FF4;
    s32 field_FF8;
    s32 field_FFC;
    char pad_1000[0x20];
    s32 field_1020;
    char pad_1024[0x2C];
    s32 field_1050;
    char pad_1054[0x20];
    f32 field_1074;
    char pad_1078[0xC];
    f32 field_1084;
    char pad_1088[0xC];
    f32 field_1094;
    char pad_1098[0xC];
    f32 field_10A4;

    s32 Iam();
};

/* Les globales que ces accesseurs servent. Leur taille déclarée est celle que
 * le découpage leur donne, et c'est elle qui décide du `%gp_rel`. */
extern s32 CEditMapName;

/* La pile de l'interpréteur de script d'objet. Les commandes qui ne rendent
 * qu'un code de retour ne la déréférencent pas : sa disposition reste à
 * établir. */
struct SPI_STACK;
extern s32 emapInit;
extern s32 emapInitIdx;
extern s32 emapInitNum;


s32 CEditMap::Iam(void) {
    return CEditMapName;
}
INCLUDE_ASM("nonmatchings/game/ceditmap", Initialize__8CEditMapFv);
INCLUDE_ASM("nonmatchings/game/ceditmap", ClearGrid__8CEditMapFv);
INCLUDE_ASM("nonmatchings/game/ceditmap", ClearHouse__8CEditMapFv);
INCLUDE_ASM("nonmatchings/game/ceditmap", ClearAllParts__8CEditMapFv);
INCLUDE_ASM("nonmatchings/game/ceditmap", InitialPlaceParts__8CEditMapFP9CEditData);
INCLUDE_ASM("nonmatchings/game/ceditmap", GetPoly__8CEditMapFiP6CCPolyR9mgVu0FBOXi);
INCLUDE_ASM("nonmatchings/game/ceditmap", CreateTable__8CEditMapFP9mgCMemoryii);
INCLUDE_ASM("nonmatchings/game/ceditmap", __ct__10CEditPartsFv);
INCLUDE_ASM("nonmatchings/game/ceditmap", GetePartsInfo__8CEditMapFi);
INCLUDE_ASM("nonmatchings/game/ceditmap", GetePartsInfo__8CEditMapFPc);
INCLUDE_ASM("nonmatchings/game/ceditmap", GetePartsInfoAtID__8CEditMapFi);
INCLUDE_ASM("nonmatchings/game/ceditmap", GetePartsInfoAtType__8CEditMapFi);
extern "C" s32 GetePlaceParts__8CEditMapFi(void *, s32);
struct temp_v0_champs_fd5b88 {
    char pad0[0x324];
    /* 0x324 */ s32 unk324;
};
/* Pose par `make forge`, qui a compose les reparations connues et verifie l'image entiere. Voir docs/IDIOMES_MWCC.md pour le detail de chacune. */
extern "C" s32 GetePartsInfoAtPlaceID__8CEditMapFi(CEditMap *objet, s32 arg0) {
    struct temp_v0_champs_fd5b88 *temp_v0;

    temp_v0 = (struct temp_v0_champs_fd5b88 *) (GetePlaceParts__8CEditMapFi(objet, arg0));
    if (temp_v0 != NULL) {
        return temp_v0->unk324;
    }
    return 0;
}
INCLUDE_ASM("nonmatchings/game/ceditmap", eNewPlaceParts__8CEditMapFv);
INCLUDE_ASM("nonmatchings/game/ceditmap", eNewHouseInfo__8CEditMapFv);
INCLUDE_ASM("nonmatchings/game/ceditmap", GetePlaceParts__8CEditMapFi);
INCLUDE_ASM("nonmatchings/game/ceditmap", GetePlaceParts__8CEditMapFPc);
INCLUDE_ASM("nonmatchings/game/ceditmap", GetePlaceIDList__8CEditMapFPii);
INCLUDE_ASM("nonmatchings/game/ceditmap", GetRotMatrix__8CEditMapFPA4_fi);
INCLUDE_ASM("nonmatchings/game/ceditmap", GetEditAngle90__8CEditMapFi);
INCLUDE_ASM("nonmatchings/game/ceditmap", GetEditAngle__8CEditMapFi);
INCLUDE_ASM("nonmatchings/game/ceditmap", ConvEditAngle__8CEditMapFf);
INCLUDE_ASM("nonmatchings/game/ceditmap", AngleLimit__8CEditMapFi);
INCLUDE_ASM("nonmatchings/game/ceditmap", GetEditPos__8CEditMapFPfPf);
extern "C" s32 CmpEditAlt__8CEditMapFff(CEditMap *objet, f32 arg0, f32 arg1) {
    f32 temp_f1;
    s32 var_v0;

    temp_f1 = arg0 - arg1;
    if (!(temp_f1 <= 0.5f)) {
        return -1;
    }
    var_v0 = 1;
    if (!(temp_f1 < -0.5f)) {
        var_v0 = 0;
    }
    return var_v0;
}
INCLUDE_ASM("nonmatchings/game/ceditmap", GetEditAlt__8CEditMapFf);
INCLUDE_ASM("nonmatchings/game/ceditmap", GetGridPos__8CEditMapFPfPfPf);
INCLUDE_ASM("nonmatchings/game/ceditmap", GetMatrix__8CEditMapFPA4_fPfi);
INCLUDE_ASM("nonmatchings/game/ceditmap", GetInversMatrix__8CEditMapFPA4_fPA4_f);
INCLUDE_ASM("nonmatchings/game/ceditmap", ConvertParts__8CEditMapFP10CEditParts);
INCLUDE_ASM("nonmatchings/game/ceditmap", GetSameParts__8CEditMapFi);
extern "C" s32 GetePartsInfoAtID__8CEditMapFi(void *, s32);
struct temp_v0_champs {
    char pad0[0x3C];
    /* 0x3C */ s32 unk3C;
};
extern "C" s32 BuildEditParts__8CEditMapFPc(...);
extern "C" s32 BuildEditParts__8CEditMapFi(CEditMap *objet, s32 arg0) {
    struct temp_v0_champs *temp_v0;

    temp_v0 = (struct temp_v0_champs *) (GetePartsInfoAtID__8CEditMapFi(objet, arg0));
    if (temp_v0 != NULL) {
        return BuildEditParts__8CEditMapFPc(objet, temp_v0->unk3C);
    }
    return -1;
}
INCLUDE_ASM("nonmatchings/game/ceditmap", GetTotalPolyn__8CEditMapFPiPi);
INCLUDE_ASM("nonmatchings/game/ceditmap", BuildEditParts__8CEditMapFPc);
INCLUDE_ASM("nonmatchings/game/ceditmap", DeleteEditParts__8CEditMapFi);
INCLUDE_ASM("nonmatchings/game/ceditmap", RemoveEditParts__8CEditMapFiPfPQ28CEditMap10RemoveInfo);
INCLUDE_ASM("nonmatchings/game/ceditmap", PlaceBurnParts__8CEditMapFv);
INCLUDE_ASM("nonmatchings/game/ceditmap", BurnEditParts__8CEditMapFPQ28CEditMap10RemoveInfo);
INCLUDE_ASM("nonmatchings/game/ceditmap", PlaceEditParts__8CEditMapFPcPfPf);
INCLUDE_ASM("nonmatchings/game/ceditmap", PlaceEditParts__8CEditMapFiP13EP_PLACE_INFOPfPfPi);
INCLUDE_ASM("nonmatchings/game/ceditmap", PlaceRiverParts__8CEditMapFPf);
INCLUDE_ASM("nonmatchings/game/ceditmap", CreatePlaceLog__8CEditMapFiP13EP_PLACE_INFO);
INCLUDE_ASM("nonmatchings/game/ceditmap", GetNearParts__8CEditMapFP14CEditPartsInfoPffPP10CEditPartsi);
INCLUDE_ASM("nonmatchings/game/ceditmap", GetNearParts__8CEditMapFR9mgVu0FBOXPP10CEditPartsi);
INCLUDE_ASM("nonmatchings/game/ceditmap", GetePlaceParts__8CEditMapFPf);
INCLUDE_ASM("nonmatchings/game/ceditmap", GetePlaceParts__8CEditMapFPfPP10CEditPartsi);
INCLUDE_ASM("nonmatchings/game/ceditmap", CheckEditParts__8CEditMapFP14CEditPartsInfoPffP13EP_PLACE_INFO);
INCLUDE_ASM("nonmatchings/game/ceditmap", GetEditPartsAlt__8CEditMapFP14CEditPartsInfoPff);
INCLUDE_ASM("nonmatchings/game/ceditmap", MagnetParts__8CEditMapFP14CEditPartsInfoPfPfPP10CEditPartsi);
INCLUDE_ASM("nonmatchings/game/ceditmap", MagnetParts__8CEditMapFP14CEditPartsInfoPfPf);
INCLUDE_ASM("nonmatchings/game/ceditmap", CheckWallEditParts__8CEditMapFP14CEditPartsInfoPfiiP13EP_PLACE_INFO);
INCLUDE_ASM("nonmatchings/game/ceditmap", Step__8CEditMapFv);
INCLUDE_ASM("nonmatchings/game/ceditmap", PreDraw__8CEditMapFPf);
INCLUDE_ASM("nonmatchings/game/ceditmap", DrawSub__8CEditMapFi);
s32 emapEDIT_RIVER(SPI_STACK *stack, int argc) {
    return 1;
}
INCLUDE_ASM("nonmatchings/game/ceditmap", emapRIVER_PARTS_NAME__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceditmap", emapMASK_PARTS_NAME__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceditmap", emapWATER_PARTS_NAME__FP9SPI_STACKi);
s32 emapEDIT_RIVER_END(SPI_STACK *stack, int argc) {
    return 1;
}
INCLUDE_ASM("nonmatchings/game/ceditmap", emapFIX_EPARTS_START__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceditmap", emapFIX_EPARTS__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceditmap", emapFIX_EPARTS_END__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceditmap", emapINIT_EPARTS_START__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceditmap", emapINIT_EPARTS__FP9SPI_STACKi);
s32 emapINIT_EPARTS_END(SPI_STACK * arg0, s32 arg1) {
    emapInitNum = 0;
    emapInitIdx = 0;
    emapInit = 0;
    return 1;
}
INCLUDE_ASM("nonmatchings/game/ceditmap", LoadEditInfo__8CEditMapFPciP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/ceditmap", __ct__14CEditPartsInfoFv);
INCLUDE_ASM("nonmatchings/game/ceditmap", Initialize__14CEditPartsInfoFv);
struct inferred;
typedef struct CEditPartsInfo {
    /* 0x00 */ char pad0[4];
    /* 0x04 */ s32 unk4;                            /* inferred */
    /* 0x08 */ char pad8[0x1C];                     /* maybe part of unk4[8]void */
    /* 0x24 */ s32 unk24;                           /* inferred */
} CEditPartsInfo;                                   /* size >= 0x28 */
extern "C" s32 GetPartsType__14CEditPartsInfoFv(CEditPartsInfo *objet) {
    s32 temp_v1;

    temp_v1 = objet->unk4;
    if (temp_v1 & 0x40) {
        return 1;
    }
    if (temp_v1 & 0x80) {
        return 0xB;
    }
    return objet->unk24;
}
INCLUDE_ASM("nonmatchings/game/ceditmap", CreateBox__14CEditPartsInfoFv);
INCLUDE_ASM("nonmatchings/game/ceditmap", GetPartsHeight__14CEditPartsInfoFv);
INCLUDE_ASM("nonmatchings/game/ceditmap", GetPartsMaxWidth__14CEditPartsInfoFv);
INCLUDE_ASM("nonmatchings/game/ceditmap", GetMaterial__14CEditPartsInfoFi);
#include "gen/CMapParts.hpp"
struct inferred;
typedef struct CEditPartsInfo_infere {
    /* 0x00 */ char pad0[0x44];
    /* 0x44 */ CMapParts *unk44;                    /* inferred */
} CEditPartsInfo_infere;                                   /* size >= 0x48 */
extern "C" s32 GetDefColor__9CMapPartsFiPf(void *, s32, f32 *);
extern "C" s32 GetDefColor__14CEditPartsInfoFiPf(CEditPartsInfo_infere *objet, s32 arg0, f32 *arg1) {
    CMapParts *temp_a0;

    temp_a0 = (CMapParts *) (objet->unk44);
    if (temp_a0 == NULL) {
        return 0;
    }
    return GetDefColor__9CMapPartsFiPf(temp_a0, arg0, arg1);
}
struct CEditHouse {
    char pad_0[0x4];
    s32 field_4;
};
struct calcul0_champs_e79c5e {
    char pad0[0x4];
    /* 0x4 */ s32 unk4;
};
extern "C" s32 LiveChara__10CEditHouseFv(CEditHouse *objet) {
    s32 var_v1;
    s32 var_a1;

    var_v1 = 0;
    var_a1 = 0;
loop_1:
    if (((struct calcul0_champs_e79c5e *) ((u8 *) objet + var_a1))->unk4 > 0) {
        return 1;
    }
    var_v1 += 1;
    var_a1 += 4;
    if (var_v1 >= 3) {
        return 0;
    }
    goto loop_1;
}

INCLUDE_ASM("nonmatchings/game/ceditmap", Initialize__10CEditPartsFv);
INCLUDE_ASM("nonmatchings/game/ceditmap", StandardPos__Ff);
INCLUDE_ASM("nonmatchings/game/ceditmap", SetPosition__10CEditPartsFPf);
INCLUDE_ASM("nonmatchings/game/ceditmap", SetPosition__10CEditPartsFfff);
INCLUDE_ASM("nonmatchings/game/ceditmap", GetPosition__10CEditPartsFPf);
INCLUDE_ASM("nonmatchings/game/ceditmap", GetLocalPos__10CEditPartsFPf);
INCLUDE_ASM("nonmatchings/game/ceditmap", UpDatePosition__10CEditPartsFv);
typedef struct CEditParts {
    /* 0x000 */ char pad0[0x324];
    /* 0x324 */ s32 *unk324;                        /* inferred */
} CEditParts;                                       /* size >= 0x328 */
extern "C" s32 GetInfoID__10CEditPartsFv(CEditParts *objet) {
    s32 *temp_v0;

    temp_v0 = (s32 *) (objet->unk324);
    if (temp_v0 != NULL) {
        return *temp_v0;
    }
    return -1;
}
struct CEditParts_infere_2c6891;
typedef struct CEditParts_infere_2c6891 {
    /* 0x000 */ char pad0[0x328];
    /* 0x328 */ void *unk328;                       /* inferred */
} CEditParts_infere_2c6891;                                       /* size >= 0x32C */
struct objet_champs_2c6891 {
    char pad0[0x328];
    /* 0x328 */ s32 unk328;
};
struct temp_v0_champs_2c6891 {
    char pad0[0x4];
    /* 0x4 */ s32 unk4;
};
extern "C" s32 GetLiveNPC__10CEditPartsFv(CEditParts_infere_2c6891 *objet) {
    struct temp_v0_champs_2c6891 *temp_v0;

    temp_v0 = (struct temp_v0_champs_2c6891 *) (((struct objet_champs_2c6891 *) objet)->unk328);
    if (temp_v0 != NULL) {
        return temp_v0->unk4;
    }
    return -1;
}
INCLUDE_ASM("nonmatchings/game/ceditmap", IsWallParts__10CEditPartsFv);
struct CEditParts_infere;
typedef struct CEditParts_infere {
    /* 0x000 */ char pad0[0x324];
    /* 0x324 */ void *unk324;                       /* inferred */
} CEditParts_infere;                                       /* size >= 0x328 */
struct temp_v0_champs_c56d0f {
    char pad0[0x4];
    /* 0x4 */ s32 unk4;
};
extern "C" s32 IsFence__10CEditPartsFv(CEditParts_infere *objet) {
    struct temp_v0_champs_c56d0f *temp_v0;

    temp_v0 = (struct temp_v0_champs_c56d0f *) (objet->unk324);
    if (temp_v0 == NULL) {
        return 0;
    }
    return (temp_v0->unk4 & 0x130) == 0x130;
}
struct CEditParts_infere2;
typedef struct CEditParts_infere2 {
    /* 0x000 */ char pad0[0x324];
    /* 0x324 */ void *unk324;                       /* inferred */
} CEditParts_infere2;                                       /* size >= 0x328 */
struct temp_v0_champs_0949e2 {
    char pad0[0x4];
    /* 0x4 */ s32 unk4;
};
extern "C" s32 IsBurn__10CEditPartsFv(CEditParts_infere2 *objet) {
    struct temp_v0_champs_0949e2 *temp_v0;

    temp_v0 = (struct temp_v0_champs_0949e2 *) (objet->unk324);
    if (temp_v0 == NULL) {
        return 0;
    }
    return (temp_v0->unk4 & 0x1000) != 0;
}
INCLUDE_ASM("nonmatchings/game/ceditmap", GetFenceSide__10CEditPartsFPfPf);
INCLUDE_ASM("nonmatchings/game/ceditmap", GetWallPlane__10CEditPartsFiPQ210CEditParts8WallInfo);
struct CEditParts_infere3;
typedef struct CEditParts_infere3 {
    /* 0x000 */ char pad0[0x324];
    /* 0x324 */ void *unk324;                       /* inferred */
} CEditParts_infere3;                                       /* size >= 0x328 */
struct temp_v0_champs_b5a85f {
    char pad0[0x254];
    /* 0x254 */ s32 unk254;
};
extern "C" s32 GetWallGroupNum__10CEditPartsFv(CEditParts_infere3 *objet) {
    struct temp_v0_champs_b5a85f *temp_v0;

    temp_v0 = (struct temp_v0_champs_b5a85f *) (objet->unk324);
    if (temp_v0 != NULL) {
        return temp_v0->unk254;
    }
    return 0;
}
INCLUDE_ASM("nonmatchings/game/ceditmap", GetPartsType__10CEditPartsFv);
INCLUDE_ASM("nonmatchings/game/ceditmap", Copy__10CEditPartsFR9CMapPartsP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/ceditmap", CheckTerritory__10CEditPartsFP10CEditParts);
INCLUDE_ASM("nonmatchings/game/ceditmap", CheckColorUpdate__10CEditPartsFv);
INCLUDE_ASM("nonmatchings/game/ceditmap", EditPartsCmpColor__FPfPf);
INCLUDE_ASM("nonmatchings/game/ceditmap", SetPos__15CRocketLauncherFPfPfPf);
INCLUDE_ASM("nonmatchings/game/ceditmap", Step__15CRocketLauncherFv);
INCLUDE_ASM("nonmatchings/game/ceditmap", Draw__15CRocketLauncherFv);
void CRocketLauncher::Initialize(void) {
    this->field_0x0 = -1;
    this->field_0x150 = 0;
    this->field_0x154 = 0;
    this->field_0x174 = 0;
    this->field_0x160 = -1;
    this->field_0x164 = 0;
}
