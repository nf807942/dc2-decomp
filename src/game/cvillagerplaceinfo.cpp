/* CVillagerPlaceInfo, CVillagerInfo
 *
 * Unité découpée par `make carve` : 69 fonctions, 24488 octets, de
 * 0x00319990 à 0x0031FB20. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"
#include "gen/CVillagerInfo.hpp"

/* La pile de l'interpréteur de script d'objet. Les commandes qui ne rendent
 * qu'un code de retour ne la déréférencent pas : sa disposition reste à
 * établir. */
struct SPI_STACK;
extern s32 ShowOffOnce;
extern s32 niVlgr;
extern s32 vpiInfo;


INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", sgSystemDrawBuggy__FP11SubGameInfo);
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", CharaControl__FP6CSceneP11CPadControl_00319DB0);
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", InitBuggy__FP6CScene);
extern "C" u32 BombHitObj;
extern "C" u32 BuggyActCount;
extern "C" u32 BuggyDamageMotion;
extern "C" u32 BuggyHP;
extern "C" u32 BuggyStatus;
extern "C" u32 BuggyStatusStep;
extern "C" void BuggyDamage__Fi(s32 arg0) {
    if (BuggyStatus != 1) {
        BuggyDamageMotion = arg0;
        BuggyStatus = 2;
        BuggyStatusStep = 0;
        BuggyActCount = 1;
        BombHitObj = 1;
        BuggyHP -= 1;
    }
}
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", PlayBuggyLoopSe__FP6CScenei);
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", BuggyControl__FP6CScene);
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", InitBomb__FP6CScene);
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", TakeBombCheck__Fv);
extern "C" u32 BombStatus;
extern "C" s32 TakeBombCheck__Fv(void);
extern "C" s32 TakeBomb__Fv(void) {
    if (TakeBombCheck__Fv() == 0) {
        return 0;
    }
    BombStatus = 4;
    return 1;
}
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", ThrowBomb__FPf);
extern "C" u32 BombCount;
extern "C" u8 BombVelo[16];
extern "C" s32 mgZeroVector__FPf(...);
extern "C" s32 BombBomb__Fv(void) {
    if (BombStatus == 6) {
        mgZeroVector__FPf(&BombVelo);
        BombCount = 0;
        BombHitObj = 1;
        return 1;
    }
    return 0;
}
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", NowPutBomb__Fv);
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", BombControl__FP6CScene);
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", BombCheck__FP6CScene);
extern "C" s32 GetSaveData__Fv(void);
extern "C" s32 GetEditData__9CSaveDataFi(...);
struct CEditData {
    s32 field_0;
    s32 field_4;
    s32 field_8;
    s32 field_C;
    char pad_10[0x2A30];
    s32 field_2A40;
    char pad_2A44[0x21FC];
    u8 field_4C40;
    char pad_4C41[0x3FF];
    s32 field_5040;
};
struct CEditMap {
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
};
extern "C" s32 AnalyzeBenietio__FP9CEditDataP8CEditMap(CEditData *, CEditMap *);
extern "C" s32 AnalyzeHeim__FP9CEditDataP8CEditMap(CEditData *, CEditMap *);
extern "C" s32 AnalyzeMoonFlower__FP9CEditDataP8CEditMap(CEditData *, CEditMap *);
extern "C" s32 AnalyzeSharlot__FP9CEditDataP8CEditMap(CEditData *, CEditMap *);
extern "C" s32 AnalyzeStera__FP9CEditDataP8CEditMap(CEditData *, CEditMap *);
extern "C" void AnalyzeEditMap__FiP8CEditMap(s32 arg0, CEditMap *arg1) {
    CEditData *temp_v0;

    if (arg1 != NULL) {
        temp_v0 = (CEditData *) (GetEditData__9CSaveDataFi(GetSaveData__Fv(), arg0));
        if (temp_v0 != NULL) {
            if (arg0 == 0) {
                AnalyzeSharlot__FP9CEditDataP8CEditMap(temp_v0, arg1);
            }
            if (arg0 == 1) {
                AnalyzeStera__FP9CEditDataP8CEditMap(temp_v0, arg1);
            }
            if (arg0 == 2) {
                AnalyzeBenietio__FP9CEditDataP8CEditMap(temp_v0, arg1);
            }
            if (arg0 == 3) {
                AnalyzeHeim__FP9CEditDataP8CEditMap(temp_v0, arg1);
            }
            if (arg0 == 4) {
                AnalyzeMoonFlower__FP9CEditDataP8CEditMap(temp_v0, arg1);
            }
        }
    }
}
extern "C" s32 GetePlaceParts__8CEditMapFi(void *, s32);
extern "C" s32 GetPartsType__10CEditPartsFv(void *);
extern "C" s32 CountPartsType__FiP8CEditMapPii(s32 arg0, CEditMap *arg1, s32 *arg2, s32 arg3) {
    void *temp_v0;
    s32 var_s0;
    s32 var_s1;
    s32 var_s2;

    var_s1 = 0;
    var_s0 = 0;
    if (0 < arg3) {
        var_s2 = 0;
        do {
            temp_v0 = (void *) (GetePlaceParts__8CEditMapFi(arg1, *(((s32 *) ((u8 *) arg2 + var_s2)))));
            if ((temp_v0 != NULL) && (arg0 == GetPartsType__10CEditPartsFv(temp_v0))) {
                var_s0 += 1;
            }
            var_s1 += 1;
            var_s2 += 4;
        } while (var_s1 < arg3);
    }
    return var_s0;
}
extern "C" s32 GetInfoID__10CEditPartsFv(void *);
extern "C" s32 CountPartsInfoID__FiP8CEditMapPii(s32 arg0, CEditMap *arg1, s32 *arg2, s32 arg3) {
    void *temp_v0;
    s32 var_s0;
    s32 var_s1;
    s32 var_s2;

    var_s1 = 0;
    var_s0 = 0;
    if (0 < arg3) {
        var_s2 = 0;
        do {
            temp_v0 = (void *) (GetePlaceParts__8CEditMapFi(arg1, *(((s32 *) ((u8 *) arg2 + var_s2)))));
            if ((temp_v0 != NULL) && (arg0 == GetInfoID__10CEditPartsFv(temp_v0))) {
                var_s0 += 1;
            }
            var_s1 += 1;
            var_s2 += 4;
        } while (var_s1 < arg3);
    }
    return var_s0;
}
struct CEditParts;
extern "C" s32 GetePlaceParts__8CEditMapFi(void *, s32);
extern "C" s32 GetPartsType__10CEditPartsFv(void *);
extern "C" s32 CheckSaku__FP8CEditMapi(CEditMap *arg0, s32 arg1) {
    CEditParts *temp_v0;

    temp_v0 = (CEditParts *) (GetePlaceParts__8CEditMapFi(arg0, arg1));
    if (temp_v0 == NULL) {
        return 0;
    }
    return GetPartsType__10CEditPartsFv(temp_v0) == 8;
}
extern "C" s32 GetePlacePartsAtInfoID__8CEditMapFiPii(void *, s32, s32 *, s32);
extern "C" s32 GetTreeNum__FP8CEditMap(CEditMap *arg0) {
    s32 n;

    n = GetePlacePartsAtInfoID__8CEditMapFiPii(arg0, 7, NULL, 0);
    n += GetePlacePartsAtInfoID__8CEditMapFiPii(arg0, 0x13, NULL, 0);
    n += GetePlacePartsAtInfoID__8CEditMapFiPii(arg0, 0x1D, NULL, 0);
    n += GetePlacePartsAtInfoID__8CEditMapFiPii(arg0, 0x23, NULL, 0);
    n += GetePlacePartsAtInfoID__8CEditMapFiPii(arg0, 0x28, NULL, 0);
    n += GetePlacePartsAtInfoID__8CEditMapFiPii(arg0, 0x29, NULL, 0);
    n += GetePlacePartsAtInfoID__8CEditMapFiPii(arg0, 0x2A, NULL, 0);
    return n;
}
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", GetHouseParts__FP8CEditMapPii);
extern "C" s32 GetePlaceParts__8CEditMapFi(void *, s32);
struct CEditParts {
    char pad_0[0x40];
    s32 field_40;
    char pad_44[0x2C];
    s8 field_70;
    char pad_71[0x16F];
    f32 field_1E0;
    char pad_1E4[0x4C];
    s32 field_230;
    char pad_234[0xBC];
    s32 field_2F0;
    char pad_2F4[0x8];
    s32 field_2FC;
    char pad_300[0x10];
    s32 field_310;
    s32 field_314;
    s32 field_318;
    char pad_31C[0x4];
    s32 field_320;
    char pad_324[0x4];
    s32 field_328;
};
extern "C" s32 GetInfoID__10CEditPartsFv(void *);
extern "C" s32 CheckInfoID__FP8CEditMapii(CEditMap *arg0, s32 arg1, s32 arg2) {
    CEditParts *temp_v0;

    temp_v0 = (CEditParts *) (GetePlaceParts__8CEditMapFi(arg0, arg1));
    if (temp_v0 == NULL) {
        return 0;
    }
    return arg2 == GetInfoID__10CEditPartsFv(temp_v0);
}
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", GetPartsPos__FP8CEditMapiPf);
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", AnalyzeSharlot__FP9CEditDataP8CEditMap);
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", AnalyzeStera__FP9CEditDataP8CEditMap);
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", AnalyzeBenietio__FP9CEditDataP8CEditMap);
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", GetColorType__FP10CEditPartsi);
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", AnalyzeHeim__FP9CEditDataP8CEditMap);
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", AnalyzeMoonFlower__FP9CEditDataP8CEditMap);
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", CheckLiveChara__FiP8CEditMapii);
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", EditMapInitEvent__FiP8CEditMap);
extern "C" u8 HelpMesBuff[4096];
extern "C" u32 InitFlag_0037E9CC;
extern "C" u8 _799_00378F50[15];
extern "C" u8 _800_00378F60[30];
extern "C" u32 LanguageCode;
extern "C" s32 LoadFile2__FPcPvPii(...);
extern "C" s32 memcpy(...);
extern "C" s32 printf(...);
extern "C" s32 sprintf(...);
extern "C" void LoadHelpMes__FP1(void *arg0) {
    char sp20[0x4C];
    s32 sp6C;

    sprintf(sp20, &_799_00378F50, LanguageCode);
    if (LoadFile2__FPcPvPii(sp20, arg0, &sp6C, 0) != 0) {
        if (sp6C > 0x1000) {
            printf(&_800_00378F60, sp6C, 0x1000);
            return;
        }
        memcpy(&HelpMesBuff, arg0, sp6C);
        InitFlag_0037E9CC = 1;
    }
}
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", GetHepMesInfo__Fv);
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", CreateHelpMes__Fi);
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", StepHelpMes__Fv);
void ShowOffOnceHelpMes(void) {
    ShowOffOnce = 1;
}
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", DrawHelpMes__Fv);
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", ShowHelpMes__Fii);
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", ShowErrorHelpMes__Fii);
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", GetVlgrPlaceInfo__Fi);
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", GetVlgrPlaceTable__FPi);
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", GetVillagerInfo__Fi);
extern "C" s32 GetVillagerInfo__Fi(s32);
extern "C" u8 _214[13];
struct temp_v0_champs {
    char pad0[0x4];
    /* 0x4 */ s32 unk4;
};
extern "C" s32 sprintf(...);
extern "C" s32 GetVillagerModelName__FiPc(s32 arg0, s8 *arg1) {
    struct temp_v0_champs *temp_v0;

    temp_v0 = (struct temp_v0_champs *) (GetVillagerInfo__Fi(arg0));
    *arg1 = 0;
    if (temp_v0 == NULL) {
        return 0;
    }
    sprintf(arg1, &_214, temp_v0->unk4);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", niNPC__FP9SPI_STACKi);
s32 niNPC_END(SPI_STACK * arg0, s32 arg1) {
    niVlgr = 0;
    return 1;
}
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", niPROGRESS__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", niPROGRESS_END__FP9SPI_STACKi);
s32 niPLACE(SPI_STACK *stack, int argc) {
    return 1;
}
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", niNOON_PLACE__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", niNIGHT_PLACE__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", niNPC_INFO_NUM__FP9SPI_STACKi);
CVillagerInfo::CVillagerInfo(void) {
    this->field_0x0 = -1;
    this->field_0x4 = 0;
    this->field_0x8 = 0;
    this->field_0x10 = 0;
    this->field_0xC = 0;
    this->field_0x18 = -1;
    this->field_0x14 = -1;
}
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", niNPC_INFO__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", LoadNPCInfo__FPciP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", LoadPlaceInfo__FPciP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", vpiNPC_PLACE_NUM__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", __ct__18CVillagerPlaceInfoFv);
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", vpiNPC_PLACE__FP9SPI_STACKi);
s32 vpiNPC_PLACE_END(SPI_STACK * arg0, s32 arg1) {
    vpiInfo = 0;
    return 1;
}
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", vpiPLACE_POS__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", vpiMOVE_TO__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", vpiWAIT__FP9SPI_STACKi);
extern "C" u8 _450_003790A8[];
extern "C" char *spiGetStackString__FP9SPI_STACK(SPI_STACK *);
extern "C" s32 strcmp(...);
extern "C" s32 vpiMOTION__FP9SPI_STACKi(SPI_STACK *arg0, s32 arg1) {
    char *name;

    if (vpiInfo == 0) {
        return 0;
    }
    name = spiGetStackString__FP9SPI_STACK(arg0);
    if (name == NULL) {
        return 1;
    }
    if (strcmp(name, &_450_003790A8) == 0) {
        *(s32 *) (vpiInfo + 0x24) = 4;
    }
    return 1;
}
struct SPI_STACK {
    s32 field_0;
    s32 field_4;
};
extern "C" s32 spiGetStackVector__FPfP9SPI_STACK(...);
extern "C" s32 vpiTALK_OFFSET__FP9SPI_STACKi(SPI_STACK *arg0, s32 arg1) {
    if (vpiInfo == 0) {
        return 0;
    }
    spiGetStackVector__FPfP9SPI_STACK(vpiInfo + 0x10, arg0);
    return 1;
}
extern "C" s32 vpiGetMotionID__FPc(...);
extern "C" s32 vpiMOVE_MOTION__FP9SPI_STACKi(SPI_STACK *arg0, s32 arg1) {
    char *name;

    if (vpiInfo == 0) {
        return 0;
    }
    name = spiGetStackString__FP9SPI_STACK(arg0);
    if (name == NULL) {
        return 1;
    }
    *(s32 *) (vpiInfo + 0x28) = vpiGetMotionID__FPc(name);
    return 1;
}
extern "C" f32 spiGetStackFloat__FP9SPI_STACK(SPI_STACK *);
extern "C" s32 vpiMOVE_SPEED__FP9SPI_STACKi(SPI_STACK *arg0, s32 arg1) {
    if (vpiInfo == 0) {
        return 0;
    }
    *(f32 *) (vpiInfo + 0x2C) = spiGetStackFloat__FP9SPI_STACK(arg0);
    return 1;
}
extern "C" s32 spiGetStackInt__FP9SPI_STACK(SPI_STACK *);
extern "C" s32 vpiSHADOW__FP9SPI_STACKi(SPI_STACK *arg0, s32 arg1) {
    if (vpiInfo == 0) {
        return 0;
    }
    *(s32 *) (vpiInfo + 0x30) = (s32) (((spiGetStackInt__FP9SPI_STACK(arg0) != 0) ^ 1) & 0xFF);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", vpiGetMotionID__FPc);
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", giPROG_INFO__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cvillagerplaceinfo", LoadGameInfo__FP9mgCMemory);
