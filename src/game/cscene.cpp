/* CScene, CRain, CMap, SCN_LOADMAP_INFO2, CSceneMessage, CSceneCamera, CSceneSky, CSceneEffect, CSceneMap, CSceneCharacter, CSceneData, CSceneGameObj, mgCObjectStack_21CList_12EMAP_MESSAGE__
 *
 * Unité découpée par `make carve` : 94 fonctions, 15700 octets, de
 * 0x00285F50 à 0x00289E48. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"
#include "gen/CSceneData.hpp"
#include "gen/CRain.hpp"
#include "gen/mgCObjectStack_21CList_12EMAP_MESSAGE__.hpp"

INCLUDE_ASM("nonmatchings/game/cscene", SetCharNo__5CRainFi);
INCLUDE_ASM("nonmatchings/game/cscene", ParticleBirth__5CRainFPfi);
void CRain::Stop(void) {
    this->field_0x0 = 0;
}
INCLUDE_ASM("nonmatchings/game/cscene", Start__5CRainFv);
INCLUDE_ASM("nonmatchings/game/cscene", Step__5CRainFv);
INCLUDE_ASM("nonmatchings/game/cscene", Init__5CRainFv);
INCLUDE_ASM("nonmatchings/game/cscene", DrawScreenRain__Fv);
INCLUDE_ASM("nonmatchings/game/cscene", Draw__5CRainFv);
void CSceneData::Initialize(void) {
    this->field_0x0 = 0;
    this->field_0x8 = 0;
    this->field_0x30 = 0;
    this->field_0x28 = -1;
    this->field_0x2C = 0;
    this->field_0x4 = 0;
}
INCLUDE_ASM("nonmatchings/game/cscene", AssignData__15CSceneCharacterFP11CCharacter2Pc);
extern "C" s32 Initialize__10CSceneDataFv(void *);
extern "C" s32 Initialize__15CSceneCharacterFv(void *arg0) {
    *(s32 *) ((u8 *) arg0 + 0x34) = 0;
    *(s32 *) ((u8 *) arg0 + 0x38) = -1;
    *(s32 *) ((u8 *) arg0 + 0x3C) = -1;
    return Initialize__10CSceneDataFv(arg0);
}
extern "C" s32 Initialize__10CSceneDataFv(void *);
extern "C" s32 Initialize__9CSceneMapFv(void *self) {
    ((u32 *) self)[0x34 / 4] = 0;
    return Initialize__10CSceneDataFv(self);
}
struct CMap {
    char pad_0[0x98];
    s32 field_98;
    s32 field_9C;
    s32 field_A0;
    char pad_A4[0x1C];
    s32 field_C0;
    s32 field_C4;
    f32 field_C8;
    s32 field_CC;
    s32 field_D0;
    char pad_D4[0x4];
    s32 field_D8;
    f32 field_DC;
    f32 field_E0;
    s32 field_E4;
    s32 field_E8;
    s32 field_EC;
    f32 field_F0;
    f32 field_F4;
    f32 field_F8;
    char pad_FC[0xC];
    s32 field_108;
    char pad_10C[0x200];
    s32 field_30C;
    s32 field_310;
    s32 field_314;
    s32 field_318;
    s32 field_31C;
    s32 field_320;
    s32 field_324;
    s32 field_328;
    char pad_32C[0x4];
    s32 field_330;
    s32 field_334;
    char pad_338[0x8];
    f32 field_340;
    char pad_344[0xC];
    f32 field_350;
    char pad_354[0xC];
    s32 field_360;
    char pad_364[0x4];
    s32 field_368;
    char pad_36C[0x304];
    s32 field_670;
    char pad_674[0x60C];
    s32 field_C80;
    char pad_C84[0x4];
    f32 field_C88;
    s32 field_C8C;
    char pad_C90[0x4];
    s32 field_C94;
    s32 field_C98;
    char pad_C9C[0xC];
    s32 field_CA8;
    s32 field_CAC;
    char pad_CB0[0x34];
    f32 field_CE4;
    s32 field_CE8;
    s32 field_CEC;
    s32 field_CF0;
    s32 field_CF4;
};
struct inferred;
struct CSceneMap;
typedef struct CSceneMap {
    /* 0x00 */ s32 unk0;                            /* inferred */
    /* 0x04 */ char pad4[4];
    /* 0x08 */ char unk8;                              /* inferred */
    /* 0x08 */ char pad8[0x28];
    /* 0x34 */ CMap *unk34;                         /* inferred */
} CSceneMap;                                        /* size >= 0x38 */
extern "C" s32 strcpy(...);
extern "C" s32 Initialize__9CSceneMapFv(void *);
extern "C" s32 AssignData__9CSceneMapFP4CMapPc(CSceneMap *objet, CMap *arg0, s8 *arg1) {
    if ((arg1 == NULL) || (arg0 == NULL)) {
        return 0;
    }
    Initialize__9CSceneMapFv(objet);
    objet->unk0 = 0;
    objet->unk34 = arg0;
    strcpy(&objet->unk8, arg1);
    objet->unk0 |= 4;
    return 1;
}

extern "C" s32 Initialize__10CSceneDataFv(void *);
extern "C" s32 Initialize__13CSceneMessageFv(void *self) {
    ((u32 *) self)[0x34 / 4] = 0;
    return Initialize__10CSceneDataFv(self);
}
#include "gen/ClsMes.hpp"
struct inferred;
typedef struct CSceneMessage {
    /* 0x00 */ s32 unk0;                            /* inferred */
    /* 0x04 */ char pad4[4];
    /* 0x08 */ s8 unk8;                             /* inferred */
    /* 0x09 */ char pad9[0x2B];                     /* maybe part of unk8[0x2C]void */
    /* 0x34 */ ClsMes *unk34;                       /* inferred */
} CSceneMessage;                                    /* size >= 0x38 */
extern "C" s32 strcpy(...);
extern "C" s32 Initialize__13CSceneMessageFv(void *);
extern "C" s32 AssignData__13CSceneMessageFP6ClsMesPc(CSceneMessage *objet, ClsMes *arg0, s8 *arg1) {
    if (arg0 == NULL) {
        return 0;
    }
    Initialize__13CSceneMessageFv(objet);
    objet->unk0 = 0;
    objet->unk34 = arg0;
    if (arg1 == NULL) {
        objet->unk8 = 0;
    } else {
        strcpy(&objet->unk8, arg1);
    }
    objet->unk0 |= 4;
    return 1;
}
struct inferred;
struct mgCCamera {
    s32 field_0;
    f32 field_4;
    f32 field_8;
    f32 field_C;
    f32 field_10;
    f32 field_14;
    f32 field_18;
    f32 field_1C;
    f32 field_20;
    f32 field_24;
    f32 field_28;
    f32 field_2C;
    f32 field_30;
    f32 field_34;
    f32 field_38;
    f32 field_3C;
    f32 field_40;
    s32 field_44;
    f32 field_48;
    f32 field_4C;
    f32 field_50;
    f32 field_54;
    f32 field_58;
    s32 field_5C;
    char pad_60[0x14];
    f32 field_74;
    f32 field_78;
    f32 field_7C;
    f32 field_80;
    f32 field_84;
    f32 field_88;
    f32 field_8C;
    f32 field_90;
    f32 field_94;
    f32 field_98;
    f32 field_9C;
    s32 field_A0;
    f32 field_A4;
    f32 field_A8;
    char pad_AC[0x4];
    f32 field_B0;
    f32 field_B4;
    f32 field_B8;
    f32 field_BC;
    char pad_C0[0x24];
    f32 field_E4;
    f32 field_E8;
    f32 field_EC;
    char pad_F0[0xB4];
    f32 field_1A4;
    f32 field_1A8;
    f32 field_1AC;
    f32 field_1B0;
    f32 field_1B4;
    f32 field_1B8;
    f32 field_1BC;
    f32 field_1C0;
    f32 field_1C4;
    f32 field_1C8;
    s32 field_1CC;
    char pad_1D0[0x4];
    f32 field_1D4;
    f32 field_1D8;
    f32 field_1DC;
};
typedef struct CSceneCamera {
    /* 0x00 */ s32 unk0;                            /* inferred */
    /* 0x04 */ char pad4[4];
    /* 0x08 */ s8 unk8;                             /* inferred */
    /* 0x09 */ char pad9[0x2B];                     /* maybe part of unk8[0x2C]void */
    /* 0x34 */ mgCCamera *unk34;                    /* inferred */
} CSceneCamera;                                     /* size >= 0x38 */
extern "C" s32 Initialize__12CSceneCameraFv(void *);
extern "C" s32 AssignData__12CSceneCameraFP9mgCCameraPc(CSceneCamera *objet, mgCCamera *arg0, s8 *arg1) {
    if (arg0 == NULL) {
        return 0;
    }
    Initialize__12CSceneCameraFv(objet);
    objet->unk0 = 0;
    objet->unk34 = arg0;
    if (arg1 == NULL) {
        objet->unk8 = 0;
    } else {
        strcpy(&objet->unk8, arg1);
    }
    objet->unk0 |= 4;
    return 1;
}
extern "C" s32 Initialize__10CSceneDataFv(void *);
extern "C" s32 Initialize__12CSceneCameraFv(void *self) {
    ((u32 *) self)[0x34 / 4] = 0;
    return Initialize__10CSceneDataFv(self);
}
struct CMapSky;
struct inferred;
typedef struct CSceneSky {
    /* 0x00 */ s32 unk0;                            /* inferred */
    /* 0x04 */ char pad4[4];
    /* 0x08 */ s8 unk8;                             /* inferred */
    /* 0x09 */ char pad9[0x2B];                     /* maybe part of unk8[0x2C]void */
    /* 0x34 */ CMapSky *unk34;                      /* inferred */
} CSceneSky;                                        /* size >= 0x38 */
extern "C" s32 Initialize__9CSceneSkyFv(void *);
extern "C" s32 AssignData__9CSceneSkyFP7CMapSkyPc(CSceneSky *objet, CMapSky *arg0, s8 *arg1) {
    if (arg0 == NULL) {
        return 0;
    }
    Initialize__9CSceneSkyFv(objet);
    objet->unk0 = 0;
    objet->unk34 = arg0;
    if (arg1 == NULL) {
        objet->unk8 = 0;
    } else {
        strcpy(&objet->unk8, arg1);
    }
    objet->unk0 |= 4;
    return 1;
}
extern "C" s32 Initialize__10CSceneDataFv(void *);
extern "C" s32 Initialize__9CSceneSkyFv(void *self) {
    ((u32 *) self)[0x34 / 4] = 0;
    return Initialize__10CSceneDataFv(self);
}
extern "C" s32 Initialize__15CSceneCharacterFv(void *);
extern "C" s32 Initialize__13CSceneGameObjFv(void *self) {
    return Initialize__15CSceneCharacterFv(self);
}
extern "C" s32 Initialize__10CSceneDataFv(void *);
extern "C" s32 Initialize__12CSceneEffectFv(void *self) {
    ((u32 *) self)[0x34 / 4] = 0;
    return Initialize__10CSceneDataFv(self);
}
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
typedef struct CSceneEffect {
    /* 0x00 */ s32 unk0;                            /* inferred */
    /* 0x04 */ char pad4[4];
    /* 0x08 */ s8 unk8;                             /* inferred */
    /* 0x09 */ char pad9[0x2B];                     /* maybe part of unk8[0x2C]void */
    /* 0x34 */ CEffectScriptMan *unk34;             /* inferred */
} CSceneEffect;                                     /* size >= 0x38 */
extern "C" s32 Initialize__12CSceneEffectFv(void *);
extern "C" s32 AssignData__12CSceneEffectFP16CEffectScriptManPc(CSceneEffect *objet, CEffectScriptMan *arg0, s8 *arg1) {
    if (arg0 == NULL) {
        return 0;
    }
    Initialize__12CSceneEffectFv(objet);
    objet->unk0 = 0;
    objet->unk34 = arg0;
    if (arg1 == NULL) {
        objet->unk8 = 0;
    } else {
        strcpy(&objet->unk8, arg1);
    }
    objet->unk0 |= 4;
    return 1;
}
INCLUDE_ASM("nonmatchings/game/cscene", InitAllData__6CSceneFv);
INCLUDE_ASM("nonmatchings/game/cscene", Initialize__6CSceneFv);
INCLUDE_ASM("nonmatchings/game/cscene", SetStack__6CSceneFiP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/cscene", GetStack__6CSceneFi);
INCLUDE_ASM("nonmatchings/game/cscene", ClearStack__6CSceneFi);
INCLUDE_ASM("nonmatchings/game/cscene", AssignStack__6CSceneFi);
INCLUDE_ASM("nonmatchings/game/cscene", GetSceneCharacter__6CSceneFi);
INCLUDE_ASM("nonmatchings/game/cscene", GetSceneMap__6CSceneFi);
INCLUDE_ASM("nonmatchings/game/cscene", GetSceneMessage__6CSceneFi);
INCLUDE_ASM("nonmatchings/game/cscene", GetSceneCamera__6CSceneFi);
INCLUDE_ASM("nonmatchings/game/cscene", GetSceneSky__6CSceneFi);
INCLUDE_ASM("nonmatchings/game/cscene", GetSceneGameObj__6CSceneFi);
INCLUDE_ASM("nonmatchings/game/cscene", GetSceneEffect__6CSceneFi);
INCLUDE_ASM("nonmatchings/game/cscene", CheckIMGName__6CSceneFiPc);
INCLUDE_ASM("nonmatchings/game/cscene", CheckMDSName__6CSceneFiPc);
INCLUDE_ASM("nonmatchings/game/cscene", GetData__6CSceneFii);
INCLUDE_ASM("nonmatchings/game/cscene", AssignCamera__6CSceneFiP9mgCCameraPc);
INCLUDE_ASM("nonmatchings/game/cscene", GetCameraID__6CSceneFPc);
INCLUDE_ASM("nonmatchings/game/cscene", GetCamera__6CSceneFi);
INCLUDE_ASM("nonmatchings/game/cscene", AssignMessage__6CSceneFiP6ClsMesPc);
INCLUDE_ASM("nonmatchings/game/cscene", GetMessage__6CSceneFi);
INCLUDE_ASM("nonmatchings/game/cscene", AssignChara__6CSceneFiP11CCharacter2Pc);
INCLUDE_ASM("nonmatchings/game/cscene", SetCharaNo__6CSceneFii);
struct CScene;
extern "C" s32 GetSceneCharacter__6CSceneFi(void *, s32);
struct temp_v0_champs {
    /* Le remplissage est reduit de quatre octets par rapport a ce que m2c a
     * infere : l'alignement du champ suivant reportait celui-ci d'un mot, et
     * le commerce le lit un mot plus bas. */
    char pad0[0x3C];
    /* 0x3C */ s32 unk3C;
};
extern "C" s32 GetCharaNo__6CSceneFi(CScene *objet, s32 arg0) {
    struct temp_v0_champs *temp_v0;

    temp_v0 = (struct temp_v0_champs *) (GetSceneCharacter__6CSceneFi(objet, arg0));
    if (temp_v0 != NULL) {
        return temp_v0->unk3C;
    }
    return -1;
}
INCLUDE_ASM("nonmatchings/game/cscene", GetCharacter__6CSceneFi);
INCLUDE_ASM("nonmatchings/game/cscene", AssignMap__6CSceneFiP4CMapPc);
extern "C" s32 GetSceneMap__6CSceneFi(void *, s32);
extern "C" s32 GetMapName__6CSceneFi(CScene *objet, s32 arg0) {
    s32 temp_v0;

    temp_v0 = (s32) (GetSceneMap__6CSceneFi(objet, arg0));
    if (temp_v0 != 0) {
        return temp_v0 + 8;
    }
    return 0;
}
INCLUDE_ASM("nonmatchings/game/cscene", GetMapID__6CSceneFPc);
INCLUDE_ASM("nonmatchings/game/cscene", GetMap__6CSceneFi);
INCLUDE_ASM("nonmatchings/game/cscene", GetSky__6CSceneFi);
typedef struct CScene_infere2 {
    /* 0x0000 */ char pad0[0x2E5C];
    /* 0x2E5C */ s32 unk2E5C;                       /* inferred */
    /* 0x2E60 */ s32 unk2E60;                       /* inferred */
    /* 0x2E64 */ s32 unk2E64;                       /* inferred */
} CScene_infere2;                                           /* size >= 0x2E68 */
extern "C" s32 GetMainMapNo__6CSceneFv(CScene_infere2 *objet) {
    if (objet->unk2E5C == 0) {
        return objet->unk2E60;
    }
    return objet->unk2E64;
}
INCLUDE_ASM("nonmatchings/game/cscene", InScreenFunc__6CSceneFP16InScreenFuncInfo);
INCLUDE_ASM("nonmatchings/game/cscene", DrawScreenFunc__6CSceneFP8mgCFrame);
INCLUDE_ASM("nonmatchings/game/cscene", AssignSky__6CSceneFiP7CMapSkyPc);
struct CScene;
extern "C" s32 GetSceneSky__6CSceneFi(void *, s32);
extern "C" s32 DeleteSky__6CSceneFi(CScene *objet, s32 arg0) {
    CSceneSky *temp_v0;

    temp_v0 = (CSceneSky *) (GetSceneSky__6CSceneFi(objet, arg0));
    if (temp_v0 == NULL) {
        return 0;
    }
    Initialize__9CSceneSkyFv(temp_v0);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/cscene", AssignEffect__6CSceneFiP16CEffectScriptManPc);
extern "C" s32 GetSceneEffect__6CSceneFi(void *, s32);
extern "C" void DeleteEffect__6CSceneFi(CScene *objet, s32 arg0) {
    CSceneEffect *temp_v0;

    temp_v0 = (CSceneEffect *) (GetSceneEffect__6CSceneFi(objet, arg0));
    if (temp_v0 != NULL) {
        Initialize__12CSceneEffectFv(temp_v0);
    }
}
INCLUDE_ASM("nonmatchings/game/cscene", GetEffect__6CSceneFi);
INCLUDE_ASM("nonmatchings/game/cscene", StepEffectScript__6CSceneFi);
INCLUDE_ASM("nonmatchings/game/cscene", DrawEffectScript__6CSceneFi);
struct CScene;
extern "C" s32 GetData__6CSceneFii(void *, s32, s32);
extern "C" s32 IsActive__6CSceneFii(CScene *objet, s32 arg0, s32 arg1) {
    s32 *temp_v0;

    temp_v0 = (s32 *) (GetData__6CSceneFii(objet, arg0, arg1));
    if (temp_v0 != NULL) {
        return (*temp_v0 & 6) == 6;
    }
    return 0;
}
extern "C" void SetActive__6CSceneFii(CScene *objet, s32 arg0, s32 arg1) {
    s32 *temp_v0;

    temp_v0 = (s32 *) (GetData__6CSceneFii(objet, arg0, arg1));
    if (temp_v0 != NULL) {
        *temp_v0 |= 2;
    }
}
extern "C" void ResetActive__6CSceneFii(CScene *objet, s32 arg0, s32 arg1) {
    s32 *temp_v0;

    temp_v0 = (s32 *) (GetData__6CSceneFii(objet, arg0, arg1));
    if (temp_v0 != NULL) {
        *temp_v0 &= ~2;
    }
}
extern "C" void SetStatus__6CSceneFiii(CScene *objet, s32 arg0, s32 arg1, s32 arg2) {
    s32 *temp_v0;

    temp_v0 = (s32 *) (GetData__6CSceneFii(objet, arg0, arg1));
    if (temp_v0 != NULL) {
        *temp_v0 |= arg2;
    }
}
extern "C" void ResetStatus__6CSceneFiii(CScene *objet, s32 arg0, s32 arg1, s32 arg2) {
    s32 *temp_v0;

    temp_v0 = (s32 *) (GetData__6CSceneFii(objet, arg0, arg1));
    if (temp_v0 != NULL) {
        *temp_v0 &= ~arg2;
    }
}
extern "C" s32 GetStatus__6CSceneFii(CScene *objet, s32 arg0, s32 arg1) {
    s32 *temp_v0;

    temp_v0 = (s32 *) (GetData__6CSceneFii(objet, arg0, arg1));
    if (temp_v0 != NULL) {
        return *temp_v0;
    }
    return 0;
}
INCLUDE_ASM("nonmatchings/game/cscene", SetType__6CSceneFiii);
INCLUDE_ASM("nonmatchings/game/cscene", GetType__6CSceneFii);
INCLUDE_ASM("nonmatchings/game/cscene", GetActiveMap__6CSceneFPP4CMapi);
extern "C" s32 GetSceneCharacter__6CSceneFi(void *, s32);
struct inferred;
typedef struct CScene_infere {
    /* 0x0000 */ char pad0[0x2E70];
    /* 0x2E70 */ s32 unk2E70;                       /* inferred */
    /* 0x2E74 */ s32 unk2E74;                       /* inferred */
    /* 0x2E78 */ s32 unk2E78;                       /* inferred */
} CScene_infere;                                           /* size >= 0x2E7C */
struct temp_v0_2_champs {
    char pad0[0x38];
    /* 0x38 */ s32 unk38;
};
extern "C" s32 GetCharaTexb__6CSceneFi(CScene_infere *objet, s32 arg0) {
    s32 temp_v0;
    struct temp_v0_2_champs *temp_v0_2;

    temp_v0_2 = (struct temp_v0_2_champs *) (GetSceneCharacter__6CSceneFi(objet, arg0));
    if (temp_v0_2 == NULL) {
        return -1;
    }
    temp_v0 = (s32) (temp_v0_2->unk38);
    if (temp_v0 >= 0) {
        return temp_v0;
    }
    if (arg0 < 8) {
        return objet->unk2E70;
    }
    if ((arg0 - 8) >= objet->unk2E78) {
        return -1;
    }
    return (objet->unk2E74 + arg0) - 8;
}
INCLUDE_ASM("nonmatchings/game/cscene", SetCharaTexb__6CSceneFii);
INCLUDE_ASM("nonmatchings/game/cscene", SetTime__6CSceneFf);
extern "C" void SetTime__6CSceneFf(void *, f32);
extern "C" void AddTime__6CSceneFf(void *objet, f32 arg0) {
    SetTime__6CSceneFf(objet, arg0 + *(f32 *) ((u8 *) objet + 0x2F6C));
}
struct inferred;
typedef struct CSaveData {
    /* 0x0000 */ char pad0[0x1A14];
    /* 0x1A14 */ s32 unk1A14;                       /* inferred */
} CSaveData;                                        /* size >= 0x1A18 */
typedef struct CScene {
    /* 0x0000 */ char pad0[0x2F68];
    /* 0x2F68 */ s32 unk2F68;                       /* inferred */
    /* 0x2F6C */ f32 unk2F6C;                       /* inferred */
    /* 0x2F70 */ f32 unk2F70;                       /* inferred */
    /* 0x2F74 */ s32 unk2F74;                       /* inferred */
    /* 0x2F78 */ char pad2F78[0xC8];                /* maybe part of unk2F74[0x33]void */
    /* 0x3040 */ CSaveData *unk3040;                /* inferred */
} CScene;                                           /* size >= 0x3044 */
extern "C" s32 CheckTourBoot__9CSaveDataFi(void *, s32);
extern "C" void AddTime__6CSceneFf(void *, f32);
extern "C" void TimeStep__6CSceneFf(CScene *objet, f32 arg0) {
    CSaveData *temp_v1;
    f32 temp_f20;
    f32 temp_f21;

    if (objet->unk2F74 != 0) {
        temp_f20 = (f32) (objet->unk2F6C);
        temp_f21 = (f32) (objet->unk2F70 * arg0);
        AddTime__6CSceneFf(objet, temp_f21);
        if (!(temp_f20 <= ((24.0f - temp_f21) - 0.1f)) && (objet->unk2F6C < (0.1f + temp_f21))) {
            objet->unk2F68 += 1;
        }
        temp_v1 = (CSaveData *) (objet->unk3040);
        if (temp_v1 != NULL) {
            temp_v1->unk1A14 = objet->unk2F68;
            CheckTourBoot__9CSaveDataFi(objet->unk3040, objet->unk2F68);
        }
    }
}
extern "C" void sceVu0Normalize(void *, void *);
extern "C" void SetWind__6CSceneFfPf(void *objet, f32 arg0, f32 *arg1) {
    *(f32 *) ((u8 *) objet + 0x2F78) = arg0;
    sceVu0Normalize((u8 *) objet + 0x2F80, arg1);
}
extern "C" void ResetWind__6CSceneFv(void *objet) {
    *(s32 *) ((u8 *) objet + 0x2F78) = 0;
}
extern "C" f32 GetWind__6CSceneFPf(void *objet, f32 *arg0) {
    *(u128 *) arg0 = *(u128 *) ((u8 *) objet + 0x2F80);
    return *(f32 *) ((u8 *) objet + 0x2F78);
}
struct CSceneMapNo {
    char pad0[0x2E60];
    s32 now;
    s32 sub;
    s32 previous;
    s32 previousSub;
};
extern "C" void SetNowMapNo__6CSceneFi(CSceneMapNo *objet, s32 arg0) {
    s32 old = objet->now;
    if (old != arg0) {
        objet->previous = old;
    }
    objet->now = arg0;
}
extern "C" void SetNowSubMapNo__6CSceneFi(CSceneMapNo *objet, s32 arg0) {
    s32 old = objet->sub;
    if (old != arg0) {
        objet->previousSub = old;
    }
    objet->sub = arg0;
}
INCLUDE_ASM("nonmatchings/game/cscene", LoadMapData__FR17SCN_LOADMAP_INFO2i);
extern "C" void *memset(void *, s32, u32);
extern "C" void Initialize__17SCN_LOADMAP_INFO2Fv(void *objet) {
    memset(objet, 0, 0x1A8);
}
INCLUDE_ASM("nonmatchings/game/cscene", LoadChara__6CSceneFiPUiPcP9mgCMemoryP9mgCMemoryP9mgCMemoryii);
struct CSceneCharacter {
    s32 field_0;
    char pad_4[0x4];
    s8 field_8;
    char pad_9[0x2F];
    s32 field_38;
    s32 field_3C;
};
extern "C" s32 Initialize__15CSceneCharacterFv(void *);
extern "C" void DeleteChara__6CSceneFi(CScene *objet, s32 arg0) {
    CSceneCharacter *temp_v0;

    temp_v0 = (CSceneCharacter *) (GetSceneCharacter__6CSceneFi(objet, arg0));
    if (temp_v0 != NULL) {
        Initialize__15CSceneCharacterFv(temp_v0);
    }
}
INCLUDE_ASM("nonmatchings/game/cscene", CopyChara__6CSceneFiiP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/cscene", LoadMapFromMemory__6CSceneFiP17SCN_LOADMAP_INFO2);
INCLUDE_ASM("nonmatchings/game/cscene", LoadMapFromMemory__6CSceneFiiP17SCN_LOADMAP_INFO2);
void mgCObjectStack_21CList_12EMAP_MESSAGE__::Initialize(void) {
    this->field_0x8 = 0;
}
INCLUDE_ASM("nonmatchings/game/cscene", __ct__4CMapFv);
INCLUDE_ASM("nonmatchings/game/cscene", LoadMapBGStep__6CSceneFP17SCN_LOADMAP_INFO2);
INCLUDE_ASM("nonmatchings/game/cscene", LoadMap__6CSceneFiP17SCN_LOADMAP_INFO2i);
INCLUDE_ASM("nonmatchings/game/cscene", __as__17SCN_LOADMAP_INFO2FRC17SCN_LOADMAP_INFO2);
INCLUDE_ASM("nonmatchings/game/cscene", DeleteMap__6CSceneFii);
