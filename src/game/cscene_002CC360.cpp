/* CScene, CPot, CBPot, CFragment, CVillagerMngr, CVillagerPlaceInfo, CVillagerData, CVil
 *
 * Unité découpée par `make carve` : 84 fonctions, 22980 octets, de
 * 0x002CC360 à 0x002D1F20. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

INCLUDE_ASM("nonmatchings/game/cscene_002CC360", UpDateMapInfo__6CSceneFv);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", GetColPoly__6CSceneFP6CCPolyR9mgVu0FBOXi);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", GetCameraPoly__6CSceneFP6CCPolyR9mgVu0FBOXi);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", RunEvent__6CSceneFiP15CSceneEventData);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", GetMapEvent__6CSceneFPfiP15CSceneEventData);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", GetFixCameraPos__6CSceneFPfPf);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", FixCameraPartsOnOff__6CSceneFPf);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", EyeViewDrawOnOff__6CSceneFi);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", GetSunPosition__6CSceneFPf);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", GetMoonPosition__6CSceneFPf);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", DrawSky__6CSceneFi);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", DrawLensFlare__6CSceneFiPcPc);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", EffectStep__6CSceneFv);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", DrawEffect__6CSceneFi);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", GetChrFileSize__FPUii);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", CheckDrawChara__6CSceneFi);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", CheckDrawCharaShadow__6CSceneFi);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", StepChara__6CSceneFi);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", GetCharaLighting__6CSceneFPA4_fPf);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", DrawChara__6CSceneFii);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", DrawCharaShadow__6CSceneFi);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", DrawExclamationMark__6CSceneFP8mgCFrame);
#include "sphida.hpp"
extern "C" s32 GetCharaTexb__6CSceneFi(CScene *objet, s32 arg0);
extern "C" s32 SearchCharaTexb__6CSceneFi(CScene *objet, s32 arg0) {
    s32 texb;
    s32 autre;
    s32 i;
    s32 j;

    texb = GetCharaTexb__6CSceneFi(objet, arg0);
    i = 0;
    if (texb < 0) {
        return -1;
    }
    do {
        j = i + 8;
        if (j != arg0) {
            autre = GetCharaTexb__6CSceneFi(objet, j);
            if ((autre >= 0) && (autre == texb)) {
                return j;
            }
        }
        i += 1;
    } while (i < 0x18);
    return -1;
}
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", PreLoadVillager__6CSceneFiP1);
extern "C" void DeleteFileCache__Fv(void);
extern "C" void PreLoadVillagerEnd__6CSceneFv(void *) { DeleteFileCache__Fv(); }
extern "C" void DeleteCharaID__13CVillagerMngrFi(void *, s32);
extern "C" s32 DeleteVillager__6CSceneFi(void *objet, s32 arg0) {
    DeleteCharaID__13CVillagerMngrFi((u8 *)objet + 0x3050, arg0);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", DeleteSubVillager__6CSceneFv);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", DeleteVillager__6CSceneFv);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", SearchCharaID__6CSceneFi);
struct inferred;
typedef struct CScene_infere {
    /* 0x0000 */ char pad0[0x2F6C];
    /* 0x2F6C */ f32 unk2F6C;                       /* inferred */
} CScene_infere;                                           /* size >= 0x2F70 */
extern "C" s32 CheckTime__Ffff(f32, f32, f32);
extern "C" s32 GetNowVillagerTime__6CSceneFv(CScene_infere *objet) {
    s32 var_v0;

    var_v0 = 0;
    if (CheckTime__Ffff(objet->unk2F6C, 21.0f, 6.0f) != 0) {
        var_v0 = 1;
    }
    return var_v0;
}
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", GetLoadVillagerList__6CSceneFiPiPP18CVillagerPlaceInfo);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", SearchCopyModel__6CSceneFi);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", GetObjectNameList__FPcP11CCharacter2PP8mgCFramei);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", CharaObjectOnOff__6CSceneFiP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", LoadVillager__6CSceneFii);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", LoadSubVillager__6CSceneFii);
extern "C" s32 GetVlgrPlaceInfo__Fi(s32);
struct CVillagerPlaceInfo {
    char pad_0[0x20];
    s32 field_20;
};
extern "C" s32 RegisterVillager__6CSceneFiiP18CVillagerPlaceInfo(CScene *, s32, s32, s32);
extern "C" void RegisterVillager__6CSceneFiii(CScene *objet, s32 arg0, s32 arg1, s32 arg2) {
    RegisterVillager__6CSceneFiiP18CVillagerPlaceInfo(objet, arg0, arg1, GetVlgrPlaceInfo__Fi(arg2));
}
extern "C" s32 Register__13CVillagerMngrFiiP18CVillagerPlaceInfo(...);
extern "C" s32 RegisterVillager__6CSceneFiiP18CVillagerPlaceInfo(CScene *arg0, s32 arg1, s32 arg2, s32 arg3) {
    return Register__13CVillagerMngrFiiP18CVillagerPlaceInfo((u8 *) arg0 + 0x3050, arg2, arg1, arg3);
}
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", RegisterVillager__6CSceneFiiP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", GetTalkEvent__6CSceneFPfP15CSceneEventData);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", GetMotionName__Fi);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", GetMotionID__FPc);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", SetCharaMotion__FP11CCharacter2ii);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", StepVillager__6CSceneFv);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", StayNearVillager__6CSceneFPfPi);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", CancelStayVillager__6CSceneFPi);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", StayVillager__6CSceneFi);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", CancelStayVillager__6CSceneFi);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", ExModeVillager__6CSceneFi);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", SetActiveVillager__6CSceneFv);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", InScreenChara__6CSceneFPQ26CScene17InScreenCharaInfoPf);
extern "C" u8 GameObjInfo[2880];
extern "C" u8 _1842_00375BE0[21];
extern "C" u8 _1843_00375C00[16];
extern "C" u8 _1844_00375C10[23];
extern "C" u8 _1845_00375C30[23];
extern "C" u8 _1846_00375C50[24];
extern "C" u8 _1847_00375C70[24];
extern "C" u8 mgTexManager[540];
struct irregular;
#include "menu.hpp"
struct CScene_infere2;
typedef struct CScene_infere2 {
    /* 0x0000 */ char pad0[0x3C];
    /* 0x003C */ u32 *unk3C;                        /* inferred */
    /* 0x0040 */ char pad40[0x3000];                /* maybe part of unk3C[0xC01]void */
    /* 0x3040 */ void *unk3040;                     /* inferred */
} CScene_infere2;                                           /* size >= 0x3044 */
struct temp_v1_champs_775b33 {
    char pad0[0x1A08];
    /* 0x1A08 */ s32 unk1A08;
};
struct var_s0_champs_775b33 {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
};
extern "C" s32 DeleteBlock__17mgCTextureManagerFi(void *, s32);
extern "C" s32 DeleteChara__6CSceneFi(void *, s32);
extern "C" s32 GetGameChapter__Fi(s32);
extern "C" s32 LoadChara__6CSceneFiPUiPcP9mgCMemoryP9mgCMemoryP9mgCMemoryii(void *, s32, u32 *, char *, mgCMemory *, mgCMemory *, mgCMemory *, s32, s32);
extern "C" s32 LoadFile2__FPcPvPii(...);
extern "C" s32 SetActive__6CSceneFii(void *, s32, s32);
extern "C" void LoadGameObject__6CSceneFiiP9mgCMemory(CScene_infere2 *objet, s32 arg0, s32 arg1, mgCMemory *arg2) {
    void *var_s0;
    s32 temp_a0;
    s32 temp_v1_2;
    s32 var_s1;
    u32 *temp_s2;
    struct temp_v1_champs_775b33 *temp_v1;

    temp_s2 = (u32 *) (objet->unk3C);
    var_s0 = (void *) (&GameObjInfo);
    DeleteChara__6CSceneFi(objet, 0x78);
    DeleteChara__6CSceneFi(objet, 0x79);
    DeleteChara__6CSceneFi(objet, 0x7A);
    DeleteChara__6CSceneFi(objet, 0x7B);
    DeleteBlock__17mgCTextureManagerFi(&mgTexManager, arg1);
    temp_v1 = (struct temp_v1_champs_775b33 *) (objet->unk3040);
    var_s1 = 0;
    if ((temp_v1 != NULL) && (GetGameChapter__Fi(temp_v1->unk1A08) == 8)) {
        var_s1 = 1;
    }
loop_3:
    temp_v1_2 = (s32) (((struct var_s0_champs_775b33 *) var_s0)->unk0);
    if (temp_v1_2 >= 0) {
        if (temp_v1_2 == arg0) {
            temp_a0 = (s32) (((struct var_s0_champs_775b33 *) var_s0)->unk4);
            switch (temp_a0) {                      /* irregular */
            case 3:
                if (LoadFile2__FPcPvPii(&_1842_00375BE0, temp_s2, NULL, 0) != 0) {
                    LoadChara__6CSceneFiPUiPcP9mgCMemoryP9mgCMemoryP9mgCMemoryii(objet, 0x7A, temp_s2, NULL, arg2, arg2, arg2, arg1, (s32) 1);
                    SetActive__6CSceneFii(objet, 1, 0x7A);
                    if (LoadFile2__FPcPvPii(&_1843_00375C00, temp_s2, NULL, 0) != 0) {
                        LoadChara__6CSceneFiPUiPcP9mgCMemoryP9mgCMemoryP9mgCMemoryii(objet, 0x7B, temp_s2, NULL, arg2, arg2, arg2, arg1, (s32) 1);
                        SetActive__6CSceneFii(objet, 1, 0x7B);
                    }
                }
                break;
            case 1:
                if ((var_s1 == 0) && (LoadFile2__FPcPvPii(&_1844_00375C10, temp_s2, NULL, 0) != 0)) {
                    LoadChara__6CSceneFiPUiPcP9mgCMemoryP9mgCMemoryP9mgCMemoryii(objet, 0x78, temp_s2, NULL, arg2, arg2, arg2, arg1, (s32) 1);
                    SetActive__6CSceneFii(objet, 1, 0x78);
                    if (LoadFile2__FPcPvPii(&_1845_00375C30, temp_s2, NULL, 0) != 0) {
                        LoadChara__6CSceneFiPUiPcP9mgCMemoryP9mgCMemoryP9mgCMemoryii(objet, 0x79, temp_s2, NULL, arg2, arg2, arg2, arg1, (s32) 1);
                        SetActive__6CSceneFii(objet, 1, 0x79);
                    }
                }
                break;
            case 2:
                if ((var_s1 == 0) && (LoadFile2__FPcPvPii(&_1846_00375C50, temp_s2, NULL, 0) != 0)) {
                    LoadChara__6CSceneFiPUiPcP9mgCMemoryP9mgCMemoryP9mgCMemoryii(objet, 0x78, temp_s2, NULL, arg2, arg2, arg2, arg1, (s32) 1);
                    SetActive__6CSceneFii(objet, 1, 0x78);
                    if (LoadFile2__FPcPvPii(&_1847_00375C70, temp_s2, NULL, 0) != 0) {
                        LoadChara__6CSceneFiPUiPcP9mgCMemoryP9mgCMemoryP9mgCMemoryii(objet, 0x79, temp_s2, NULL, arg2, arg2, arg2, arg1, (s32) 1);
                        SetActive__6CSceneFii(objet, 1, 0x79);
                    }
                }
                break;
            }
        }
        ((u8 *) var_s0) += 0x50;
        goto loop_3;
    }
}
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", GetGameObjectEvent__6CSceneFPfP15CSceneEventData);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", DrawGameObject__6CSceneFi);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", CalcReflectionVector__FPfPfPf);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", Draw__9CFragmentFPff);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", Step__9CFragmentFP6CCPolyi);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", Set__9CFragmentFPfPf);
typedef struct CFragment {
    /* 0x00 */ s32 unk0;                            /* inferred */
    /* 0x04 */ s32 unk4;                            /* inferred */
    /* 0x08 */ char pad8[8];                        /* maybe part of unk4[3]? */
    /* 0x10 */ f32 unk10;                           /* inferred */
    /* 0x14 */ char pad14[0xC];                     /* maybe part of unk10[4]? */
    /* 0x20 */ f32 unk20;                           /* inferred */
    /* 0x24 */ char pad24[0xC];                     /* maybe part of unk20[4]? */
    /* 0x30 */ f32 unk30;                           /* inferred */
    /* 0x34 */ char pad34[0xC];                     /* maybe part of unk30[4]? */
    /* 0x40 */ f32 unk40;                           /* inferred */
    /* 0x44 */ char pad44[0xC];                     /* maybe part of unk40[4]? */
    /* 0x50 */ s32 unk50;                           /* inferred */
} CFragment;                                        /* size >= 0x54 */
extern "C" void InitVector__FPf(f32 *arg0);
extern "C" void Init__9CFragmentFv(CFragment *objet) {
    objet->unk0 = -1;
    objet->unk4 = 0;
    InitVector__FPf(&objet->unk10);
    InitVector__FPf(&objet->unk20);
    InitVector__FPf(&objet->unk30);
    InitVector__FPf(&objet->unk40);
    objet->unk50 = 0;
}
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", Clash__5CBPotFPfPfPf);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", Step__5CBPotFv);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", SetObject2__5CBPotFiP9CMapParts);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", Init__5CBPotFv);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", HoldStep__4CPotFv);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", FlyStep__4CPotFv);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", Clear__4CPotFv);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", Bakuhatsu__4CPotFPfPf);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", Step__4CPotFv);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", Throw__4CPotFv);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", Hold__4CPotFP9CMapParts);
typedef struct CPot {
    /* 0x00 */ s32 unk0;                            /* inferred */
    /* 0x04 */ s32 unk4;                            /* inferred */
    /* 0x08 */ char pad8[8];                        /* maybe part of unk4[3]? */
    /* 0x10 */ f32 unk10;                           /* inferred */
    /* 0x14 */ char pad14[0xC];                     /* maybe part of unk10[4]? */
    /* 0x20 */ f32 unk20;                           /* inferred */
    /* 0x24 */ char pad24[0xC];                     /* maybe part of unk20[4]? */
    /* 0x30 */ f32 unk30;                           /* inferred */
    /* 0x34 */ char pad34[0xC];                     /* maybe part of unk30[4]? */
    /* 0x40 */ f32 unk40;                           /* inferred */
    /* 0x44 */ char pad44[0xC];                     /* maybe part of unk40[4]? */
    /* 0x50 */ f32 unk50;                           /* inferred */
    /* 0x54 */ char pad54[0xC];                     /* maybe part of unk50[4]? */
    /* 0x60 */ f32 unk60;                           /* inferred */
    /* 0x64 */ char pad64[0xC];                     /* maybe part of unk60[4]? */
    /* 0x70 */ s32 unk70;                           /* inferred */
} CPot;                                             /* size >= 0x74 */
extern "C" void InitVector__FPf(f32 *arg0);
extern "C" void Init__4CPotFi(CPot *objet, s32 arg0) {
    objet->unk0 = 0;
    objet->unk4 = 0;
    InitVector__FPf(&objet->unk10);
    if (arg0 != 1) {
        InitVector__FPf(&objet->unk20);
    }
    InitVector__FPf(&objet->unk30);
    InitVector__FPf(&objet->unk40);
    InitVector__FPf(&objet->unk50);
    if (arg0 != 1) {
        InitVector__FPf(&objet->unk60);
    }
    objet->unk70 = 0;
}
struct ProgressInfoFields { s32 f0; s32 f4; s32 f8; s32 fC; s32 f10; s32 f14; s32 f18; s32 f1C; s32 f20; s32 f24; };
extern "C" void Init__Q214CVillagerPlace12ProgressInfoFv(ProgressInfoFields *objet) {
    objet->f0 = 0; objet->fC = 0; objet->f8 = 0; objet->f14 = 0; objet->f10 = 0;
    objet->f1C = 0; objet->f18 = 0; objet->f24 = 0; objet->f20 = 0;
}
typedef struct CVillagerData {
    /* 0x00 */ s32 unk0;                            /* inferred */
    /* 0x04 */ s32 unk4;                            /* inferred */
    /* 0x08 */ s32 unk8;                            /* inferred */
    /* 0x0C */ s32 unkC;                            /* inferred */
    /* 0x10 */ s32 unk10;                           /* inferred */
    /* 0x14 */ s32 unk14;                           /* inferred */
    /* 0x18 */ s32 unk18;                           /* inferred */
    /* 0x1C */ s32 unk1C;                           /* inferred */
    /* 0x20 */ s32 unk20;                           /* inferred */
    /* 0x24 */ s32 unk24;                           /* inferred */
    /* 0x28 */ s32 unk28;                           /* inferred */
    /* 0x2C */ s32 unk2C;                           /* inferred */
    /* 0x30 */ s32 unk30;                           /* inferred */
    /* 0x34 */ char pad34[4];
    /* 0x38 */ s32 unk38;                           /* inferred */
    /* 0x3C */ s32 unk3C;                           /* inferred */
    /* 0x40 */ s32 unk40;                           /* inferred */
    /* 0x44 */ char pad44[0xC];                     /* maybe part of unk40[4]? */
    /* 0x50 */ f32 unk50;                           /* inferred */
    /* 0x54 */ char pad54[0xC];                     /* maybe part of unk50[4]? */
    /* 0x60 */ f32 unk60;                           /* inferred */
} CVillagerData;                                    /* size >= 0x64 */
extern "C" void mgZeroVectorW__FPf(f32 *arg0);
extern "C" void mgZeroVector__FPf(f32 *arg0);
extern "C" void Initialize__13CVillagerDataFv(CVillagerData *objet) {
    objet->unk0 = -1;
    objet->unk4 = -1;
    objet->unkC = 0;
    objet->unk8 = -1;
    objet->unk2C = 0;
    objet->unk10 = 0;
    objet->unk14 = 0;
    objet->unk18 = 0;
    objet->unk1C = 0;
    objet->unk30 = 0;
    objet->unk20 = 0;
    objet->unk24 = 0;
    objet->unk28 = 0;
    objet->unk38 = 0;
    objet->unk3C = 0;
    objet->unk40 = 0;
    mgZeroVectorW__FPf(&objet->unk50);
    mgZeroVector__FPf(&objet->unk60);
}
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", Add__18CVillagerPlaceInfoFP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", Initialize__13CVillagerMngrFv);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", GetData__13CVillagerMngrFi);
extern "C" s32 GetData__13CVillagerMngrFi(void *, s32);
struct CVillagerMngr_681136 {
    s32 field_0;
    s32 field_4;
};
struct temp_v0_champs_681136 {
    char pad0[0x2C];
    /* 0x2C */ s32 unk2C;
};
extern "C" void Stay__13CVillagerMngrFi(CVillagerMngr_681136 *objet, s32 arg0) {
    struct temp_v0_champs_681136 *temp_v0;

    temp_v0 = (struct temp_v0_champs_681136 *) (GetData__13CVillagerMngrFi(objet, arg0));
    if (temp_v0 != NULL) {
        temp_v0->unk2C = (s32) (temp_v0->unk2C + 1);
    }
}
extern "C" s32 GetData__13CVillagerMngrFi(void *, s32);
struct CVillagerMngr_06bba5 {
    s32 field_0;
    s32 field_4;
};
struct temp_v0_champs_06bba5 {
    char pad0[0x2C];
    /* 0x2C */ s32 unk2C;
};
extern "C" void CancelStay__13CVillagerMngrFi(CVillagerMngr_06bba5 *objet, s32 arg0) {
    struct temp_v0_champs_06bba5 *temp_v0;

    temp_v0 = (struct temp_v0_champs_06bba5 *) (GetData__13CVillagerMngrFi(objet, arg0));
    if (temp_v0 != NULL) {
        temp_v0->unk2C = (s32) (temp_v0->unk2C - 1);
        if (temp_v0->unk2C < 0) {
            temp_v0->unk2C = 0;
        }
    }
}
struct CVillagerMngr_217bac {
    s32 field_0;
    s32 field_4;
};
struct temp_v0_champs_217bac {
    char pad0[0x20];
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ s32 unk28;
};
extern "C" void ExMode__13CVillagerMngrFi(CVillagerMngr_217bac *objet, s32 arg0) {
    struct temp_v0_champs_217bac *temp_v0;

    temp_v0 = (struct temp_v0_champs_217bac *) (GetData__13CVillagerMngrFi(objet, arg0));
    if (temp_v0 != NULL) {
        if (temp_v0->unk20 == 0) {
            temp_v0->unk20 = 1;
            temp_v0->unk24 = 1;
        }
        temp_v0->unk28 = 0;
    }
}
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", SearchDataIDatCharaID__13CVillagerMngrFi);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", Register__13CVillagerMngrFiiP18CVillagerPlaceInfo);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", DeleteCharaID__13CVillagerMngrFi);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", NewData__13CVillagerMngrFv);
extern "C" s32 GetData__13CVillagerMngrFi(void *, s32);
struct inferred;
typedef struct CVillagerMngr {
    /* 0x0 */ s32 unk0;                             /* inferred */
} CVillagerMngr;                                    /* size >= 0x4 */
struct temp_v0_champs {
    char pad0[0x20];
    /* 0x20 */ s32 unk20;
    char pad24[0x8];
    /* 0x2C */ s32 unk2C;
};
extern "C" s32 CheckStay__13CVillagerMngrFi(CVillagerMngr *objet, s32 arg0) {
    struct temp_v0_champs *temp_v0;

    temp_v0 = (struct temp_v0_champs *) (GetData__13CVillagerMngrFi(objet, arg0));
    if (temp_v0 == NULL) {
        return 0;
    }
    if (temp_v0->unk20 != 0) {
        return 0;
    }
    if (objet->unk0 != 0) {
        return 1;
    }
    return temp_v0->unk2C;
}
