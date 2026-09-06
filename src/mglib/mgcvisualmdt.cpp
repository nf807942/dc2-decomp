/* mgCVisualMDT, mgCTextureAnime, mgRENDER_INFO, mgCShadowMDT, mgC3DSprite, mgCVisualFixMDT, mgCMemory, mgCSprite, mgCVisual, mgCDrawEnv, mgCVisualPrim, mgCTexAnimeData, mgCTextureManager, mgCVisualAttr, mgVu0FBOX, mgRect_i_, CList_15mgCTexAnimeData_
 *
 * Unité découpée par `make carve` : 142 fonctions, 34396 octets, de
 * 0x00138EE0 à 0x00141850. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"
#include "gen/mgC3DSprite.hpp"
#include "gen/mgCVisualMDT.hpp"
#include "gen/mgRENDER_INFO.hpp"

struct mgCDrawEnv {
    s64 field_0;
    s64 field_8;
};
extern "C" s32 Initialize__10mgCDrawEnvFi(...);
extern "C" mgCDrawEnv *__ct__10mgCDrawEnvFv(mgCDrawEnv *objet) {
    Initialize__10mgCDrawEnvFi(objet, 0);
    return objet;
}
typedef struct mgCDrawEnv_infere {
    /* 0x00 */ s128 unk0;                           /* inferred */
    /* 0x10 */ s128 unk10;                          /* inferred */
    /* 0x20 */ s128 unk20;                          /* inferred */
    /* 0x30 */ s128 unk30;                          /* inferred */
} mgCDrawEnv_infere;                                       /* size >= 0x40 */
extern "C" mgCDrawEnv_infere *__as__10mgCDrawEnvFR10mgCDrawEnv(mgCDrawEnv_infere *objet, mgCDrawEnv_infere *arg0) {
    objet->unk0 = arg0->unk0;
    objet->unk10 = arg0->unk10;
    objet->unk20 = arg0->unk20;
    objet->unk30 = arg0->unk30;
    return objet;
}
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", Initialize__10mgCDrawEnvFi);
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", SetAlpha__10mgCDrawEnvFi);
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", GetAlphaMacroID__10mgCDrawEnvFv);
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", SetZBuf__10mgCDrawEnvFi);
struct inferred;
struct mgRENDER_INFO_infere_b5eb30;
typedef struct mgRENDER_INFO_infere_b5eb30 {
    /* 0x0000 */ char pad0[0x3F0];
    /* 0x03F0 */ s32 unk3F0;                        /* inferred */
    /* 0x03F4 */ char pad3F4[0xB2C];                /* maybe part of unk3F0[0x2CC]void */
    /* 0x0F20 */ mgCDrawEnv unkF20;                 /* inferred */
    /* 0x0F20 */ char padF20[0x40];
    /* 0x0F60 */ mgCDrawEnv unkF60;                 /* inferred */
    /* 0x0F60 */ char padF60[0x40];
    /* 0x0FA0 */ s32 unkFA0;                        /* inferred */
    /* 0x0FA4 */ s32 unkFA4;                        /* inferred */
    /* 0x0FA8 */ s32 unkFA8;                        /* inferred */
    /* 0x0FAC */ s32 unkFAC;                        /* inferred */
    /* 0x0FB0 */ char padFB0[0x60];                 /* maybe part of unkFAC[0x19]void */
    /* 0x1010 */ s32 unk1010;                       /* inferred */
} mgRENDER_INFO_infere_b5eb30;                                    /* size >= 0x1014 */
struct objet_champs_b5eb30 {
    char pad0[0x3F0];
    /* 0x3F0 */ s32 unk3F0;
    char pad3F4[0xB2C];
    /* 0xF20 */ s32 unkF20;
    char padF24[0x3C];
    /* 0xF60 */ s32 unkF60;
    char padF64[0x3C];
    /* 0xFA0 */ s32 unkFA0;
    /* 0xFA4 */ s32 unkFA4;
    /* 0xFA8 */ s32 unkFA8;
    /* 0xFAC */ s32 unkFAC;
    char padFB0[0x60];
    /* 0x1010 */ s32 unk1010;
};
extern "C" void Initialize__13mgRENDER_INFOFv(mgRENDER_INFO_infere_b5eb30 *objet) {
    Initialize__10mgCDrawEnvFi(&((struct objet_champs_b5eb30 *) objet)->unkF20, 0);
    Initialize__10mgCDrawEnvFi(&((struct objet_champs_b5eb30 *) objet)->unkF60, 1);
    ((struct objet_champs_b5eb30 *) objet)->unkFA4 = 0;
    ((struct objet_champs_b5eb30 *) objet)->unkFA8 = 0;
    ((struct objet_champs_b5eb30 *) objet)->unkFAC = 1;
    ((struct objet_champs_b5eb30 *) objet)->unk1010 = 0;
    ((struct objet_champs_b5eb30 *) objet)->unkFA0 = 0;
    ((struct objet_champs_b5eb30 *) objet)->unk3F0 = 1;
}
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", SetRenderInfo__13mgRENDER_INFOFfiiffif);
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", SetViewMatrix__13mgRENDER_INFOFPA4_fPf);
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", SetDropShadowMatrix__13mgRENDER_INFOFPfPfPf);
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", ActiveLighting__13mgRENDER_INFOFii);
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", GetpLightInfo__13mgRENDER_INFOFv);
struct inferred;
typedef struct mgRENDER_INFO_infere {
    /* 0x000 */ char pad0[0x3F0];
    /* 0x3F0 */ s32 unk3F0;                         /* inferred */
} mgRENDER_INFO_infere;                                    /* size >= 0x3F4 */
extern "C" s32 memset(...);
extern "C" s32 GetpLightInfo__13mgRENDER_INFOFv(...);
extern "C" void InitActiveLighting__13mgRENDER_INFOFv(mgRENDER_INFO_infere *objet) {
    objet->unk3F0 = 1;
    memset(GetpLightInfo__13mgRENDER_INFOFv(objet), 0, 0x150);
}
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", InitLighting__13mgRENDER_INFOFv);
struct mgRENDER_INFO_infere2;
typedef struct mgRENDER_INFO_infere2 {
    /* 0x000 */ char pad0[0x3F0];
    /* 0x3F0 */ s32 unk3F0;                         /* inferred */
} mgRENDER_INFO_infere2;                                    /* size >= 0x3F4 */
struct temp_v0_champs_171dca {
    char pad0[0x30];
    /* 0x30 */ s32 unk30;
    /* 0x34 */ s32 unk34;
    /* 0x38 */ s32 unk38;
    /* 0x3C */ s32 unk3C;
    char pad40[0xC];
    /* 0x4C */ s32 unk4C;
    char pad50[0xC];
    /* 0x5C */ s32 unk5C;
    char pad60[0xC];
    /* 0x6C */ s32 unk6C;
    char pad70[0xC];
    /* 0x7C */ s32 unk7C;
};
extern "C" s32 sceVu0CopyMatrix(...);
extern "C" void SetLight__13mgRENDER_INFOFPA4_fPA4_f(mgRENDER_INFO_infere2 *objet, f32 (*arg0)[4], f32 (*arg1)[4]) {
    struct temp_v0_champs_171dca *temp_v0;

    objet->unk3F0 = 1;
    temp_v0 = (struct temp_v0_champs_171dca *) (GetpLightInfo__13mgRENDER_INFOFv(objet));
    sceVu0CopyMatrix(temp_v0, arg0);
    sceVu0CopyMatrix(((struct temp_v0_champs_171dca *) ((u8 *) temp_v0 + 0x40)), arg1);
    temp_v0->unk4C = 0;
    temp_v0->unk5C = 0;
    temp_v0->unk6C = 0;
    temp_v0->unk7C = 0;
    temp_v0->unk30 = 0;
    temp_v0->unk34 = 0;
    temp_v0->unk38 = 0;
    temp_v0->unk3C = 0;
}
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", GetLight__13mgRENDER_INFOFPA4_fPA4_f);
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", SetLight__13mgRENDER_INFOFiPfPf);
extern "C" void sceVu0CopyVector(...);
extern "C" s32 GetpLightInfo__13mgRENDER_INFOFv(...);
extern "C" void SetAmbient__13mgRENDER_INFOFPf(mgRENDER_INFO *objet, f32 *arg0) {
    sceVu0CopyVector(GetpLightInfo__13mgRENDER_INFOFv(objet) + 0x80, arg0);
}
extern "C" void GetAmbient__13mgRENDER_INFOFPf(mgRENDER_INFO *objet, f32 *arg0) {
    sceVu0CopyVector(arg0, GetpLightInfo__13mgRENDER_INFOFv(objet) + 0x80);
}
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", SetPlight__13mgRENDER_INFOFiPfPfff);
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", SetPlight__13mgRENDER_INFOFiP13mgPOINT_LIGHT);
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", GetPlight__13mgRENDER_INFOFiP13mgPOINT_LIGHT);
void mgRENDER_INFO::FogEnable(s32 arg0) {
    this->field_0xFA4 = arg0;
}
s32 mgRENDER_INFO::GetFogEnable(void) {
    return this->field_0xFA4;
}
void mgRENDER_INFO::PlightEnable(s32 arg0) {
    this->field_0xFA8 = arg0;
}
s32 mgRENDER_INFO::GetPlightEnable(void) {
    return this->field_0xFA8;
}
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", SetFogParam__13mgRENDER_INFOFffUcUcUcff);
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", __as__9mgVu0FBOXFR9mgVu0FBOX);
extern "C" u8 _166[18];
extern "C" void printf(...);
extern "C" void *MG_ADDRESS_CHECK__FPvPc(void *arg0, s8 *arg1) {
    if (arg0 == NULL) {
        printf(&_166);
        return NULL;
    }
    return arg0;
}
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", __nw__FUiP1);
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", __nwa__FUiP1);
typedef struct mgCMemory_infere {
    /* 0x00 */ s8 unk0;                             /* inferred */
    /* 0x01 */ char pad1[0xF];                      /* maybe part of unk0[0x10]? */
    /* 0x10 */ s32 unk10;                           /* inferred */
    /* 0x14 */ s32 unk14;                           /* inferred */
    /* 0x18 */ s32 unk18;                           /* inferred */
    /* 0x1C */ s32 unk1C;                           /* inferred */
    /* 0x20 */ s32 unk20;                           /* inferred */
    /* 0x24 */ s32 unk24;                           /* inferred */
    /* 0x28 */ s32 unk28;                           /* inferred */
} mgCMemory_infere;                                        /* size >= 0x2C */
extern "C" void Init__9mgCMemoryFv(mgCMemory_infere *objet) {
    objet->unk10 = 0;
    objet->unk14 = 0;
    objet->unk18 = 0;
    objet->unk0 = 0;
    objet->unk20 = 0;
    objet->unk24 = 0;
    objet->unk28 = 0;
    objet->unk1C = 0;
}
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", SetHeapMem__9mgCMemoryFP1i);
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", ClearHeapMem__9mgCMemoryFv);
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", Free__9mgCMemoryFP1);
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", StartStackMode__9mgCMemoryFii);
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", EndStackMode__9mgCMemoryFv);
struct mgCMemory;
extern "C" s32 stAlign64__9mgCMemoryFv(mgCMemory *objet);
extern "C" s32 stAlloc__9mgCMemoryFi(mgCMemory *objet, s32 arg0);
extern "C" void stAlloc64__9mgCMemoryFi(mgCMemory *objet, s32 arg0) {
    stAlign64__9mgCMemoryFv(objet);
    stAlloc__9mgCMemoryFi(objet, arg0);
}
extern "C" u8 _288_00366DC0[24];
struct temp_v1;
typedef struct mgCMemory {
    /* 0x00 */ char pad0[0x1C];
    /* 0x1C */ s32 unk1C;                           /* inferred */
    /* 0x20 */ s32 unk20;                           /* inferred */
    /* 0x24 */ s32 unk24;                           /* inferred */
    /* 0x28 */ s32 unk28;                           /* inferred */
} mgCMemory;                                        /* size >= 0x2C */
extern "C" void printf(...);
extern "C" s32 stAllocTest__9mgCMemoryFi(mgCMemory *objet, s32 arg0) {
    s32 temp_a1;
    s32 temp_a2;
    s32 temp_v1;

    if (objet->unk1C != 0) {
        return 0;
    }
    temp_v1 = objet->unk24;
    temp_a2 = objet->unk28;
    temp_a1 = temp_v1 + arg0;
    if (temp_a1 >= temp_a2) {
        printf(&_288_00366DC0, temp_a1, temp_a2, objet);
        return 0;
    }
    return objet->unk20 + (temp_v1 * 0x10);
}
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", stAlloc__9mgCMemoryFi);
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", Alloc__9mgCMemoryFi);
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", stAlign64__9mgCMemoryFv);
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", Align64__9mgCMemoryFv);
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", stSetBuffer__9mgCMemoryFP1i);
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", mgCopyString__FPcP9mgCMemory);
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", SetShadowData__FPUiPA4_f);
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", CreateFacePacket__12mgCShadowMDTFPUiP7mgCFace);
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", CreateFace__12mgCShadowMDTFP8FACES_IDP9mgCMemoryP9mgCMemoryPP7mgCFace);
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", CreatePacket__12mgCShadowMDTFP14mgCDrawManager);
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", DataAssignMDT__12mgCShadowMDTFP10MDT_HEADERP9mgCMemoryP17mgCTextureManager);
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", CreateRenderInfoPacket__12mgCShadowMDTFPUiPA4_fP13mgRENDER_INFO);
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", CreateRenderInfoPacket__11mgC3DSpriteFPUiPA4_fP13mgRENDER_INFO);
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", Draw__11mgC3DSpriteFPUiPA4_fP14mgCDrawManager);
extern "C" u8 mgDrawManager[128];
struct inferred;
typedef struct mgC3DSprite_infere {
    /* 0x00 */ char pad0[0x20];
    /* 0x20 */ s32 unk20;                           /* inferred */
    /* 0x24 */ void *unk24;                         /* inferred */
    /* 0x28 */ s32 unk28;                           /* inferred */
    /* 0x2C */ s32 unk2C;                           /* inferred */
    /* 0x30 */ char pad30[0x14];                    /* maybe part of unk2C[6]void */
    /* 0x44 */ s32 unk44;                           /* inferred */
    /* 0x48 */ s32 unk48;                           /* inferred */
} mgC3DSprite_infere;                                      /* size >= 0x4C */
typedef struct mgCDrawManager {
    /* 0x00 */ char pad0[0x60];
    /* 0x60 */ void *unk60;                         /* inferred */
} mgCDrawManager;                                   /* size >= 0x64 */
struct temp_a2_champs {
    char pad0[0x20];
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
};
extern "C" void BeginCreatePacket__11mgC3DSpriteFiP14mgCDrawManager(mgC3DSprite_infere *objet, s32 arg0, mgCDrawManager *arg1) {
    mgCDrawManager *var_a2;
    struct temp_a2_champs *temp_a2;

    var_a2 = (mgCDrawManager *) (arg1);
    if (var_a2 == NULL) {
        var_a2 = (mgCDrawManager *) (&mgDrawManager);
    }
    objet->unk24 = var_a2->unk60;
    temp_a2 = (struct temp_a2_champs *) (objet->unk24);
    objet->unk20 = temp_a2->unk20 + (temp_a2->unk24 * 0x10);
    objet->unk28 = objet->unk20 | 0x20000000;
    objet->unk2C = objet->unk28;
    objet->unk44 = arg0;
    objet->unk48 = 0;
}
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", CPSetDrawEnv__11mgC3DSpriteFP10mgCDrawEnv);
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", CPSetTexture__11mgC3DSpriteFP10mgCTexture);
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", BeginCPSprite__11mgC3DSpriteFv);
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", CPSetSprite__11mgC3DSpriteFPfPfPfPfPf);
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", EndCPSprite__11mgC3DSpriteFv);
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", EndCreatePacket__11mgC3DSpriteFv);
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", Initialize__9mgCSpriteFv);
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", SetColor__9mgCSpriteFiiii);
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", CreatePacket__9mgCSpriteFP14mgCDrawManager);
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", Draw__9mgCSpriteFPUiPA4_fP14mgCDrawManager);
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", Draw__9mgCSpriteFPA4_fP14mgCDrawManager);
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", Iam__13mgCVisualPrimFv);
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", Draw__11mgC3DSpriteFPA4_fP14mgCDrawManager);
void mgC3DSprite::Initialize(void) {
    this->field_0x20 = 0;
    this->field_0x0 = 0;
    this->field_0x4 = 0;
    this->field_0x8 = 0;
    this->field_0x14 = 0;
    this->field_0x10 = 0;
}
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", __ct__15mgCTexAnimeDataFv);
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", Initialize__15mgCTexAnimeDataFv);
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", TexAnime__15mgCTextureAnimeFiP13sceVif1Packet);
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", Initialize__15mgCTextureAnimeFv);
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", __ct__15mgCTextureAnimeFv);
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", SetGroupName__15mgCTextureAnimeFiPc);
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", GetEmptyGroup__15mgCTextureAnimeFv);
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", SearchGroupName__15mgCTextureAnimeFPc);
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", NewTexAnimeData__15mgCTextureAnimeFP9mgCMemory);
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", Initialize__24CList_15mgCTexAnimeData_Fv);
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", NewTexAnimeGroupData__15mgCTextureAnimeFiP9mgCMemory);
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", EnterTexAnime__15mgCTextureAnimeFP15mgCTexAnimeDataP9mgCMemory);
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", DeleteGroup__15mgCTextureAnimeFi);
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", DisableAll__15mgCTextureAnimeFv);
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", Enable__15mgCTextureAnimeFi);
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", Disable__15mgCTextureAnimeFi);
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", GetAnimeList__15mgCTextureAnimeFi);
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", LoadCFGFile__17mgCTextureManagerFPciP9mgCMemoryP15mgCTextureAnime);
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", texTEX_ANIME__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", texTEX_ANIME_DATA__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", texSRC_TEX__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", texDEST_TEX__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", texSCROLL__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", texCLUT_COPY__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", texCOLOR__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", texALPHA_BLEND__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", texALPHA_TEST__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", texWAIT__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", texTEX_ANIME_DATA_END__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", texTEX_ANIME_END__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", texBUG_PATCH__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", Set__9mgRect_i_Fiiii);
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", GetScrPad__Fv);
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", SendDMA__FPvi);
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", mgSetPkTEX0__FPUiUlUl);
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", mgSetPkTEX0__FPUiUlUlUl);
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", mgSetPkTexFlush_TagCnt__FPUi);
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", SetPointLight__FPUiPA4_fPA4_f);
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", SetMaterialRef__12mgCVisualMDTFP1P10mgMateriali);
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", SetPModeRef__12mgCVisualMDTFP1i);
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", Initialize__13mgCVisualAttrFv);
struct mgCVisualAttr {
    s32 field_0;
    s32 field_4;
    s32 field_8;
    s32 field_C;
    s32 field_10;
    s32 field_14;
};
extern "C" s32 Initialize__13mgCVisualAttrFv(mgCVisualAttr *objet);
extern "C" mgCVisualAttr *__ct__13mgCVisualAttrFv(mgCVisualAttr *objet) {
    Initialize__13mgCVisualAttrFv(objet);
    return objet;
}
extern "C" u8 mgTexManager[540];
struct mgCVisual;
typedef struct mgCVisual {
    /* 0x0 */ char pad0[8];
    /* 0x8 */ void *unk8;                              /* inferred */
} mgCVisual;                                        /* size >= 0xC */
extern "C" void *GetTextureManager__9mgCVisualFv(mgCVisual *objet) {
    void *temp_v0;
    temp_v0 = (void *) (objet->unk8);
    if (temp_v0 != NULL) {
        return temp_v0;
    }
    return &mgTexManager;
}
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", SetDrawEnvGifTag__9mgCVisualFP1P13mgRENDER_INFOP10mgCDrawEnv);
void mgCVisualMDT::Initialize(void) {
    this->field_0x20 = 0;
    this->field_0x30 = 0;
    this->field_0x24 = 0;
    this->field_0x34 = 0;
    this->field_0x28 = 0;
    this->field_0x38 = 0;
    this->field_0x2C = 0;
    this->field_0x3C = 0;
    this->field_0x40 = 0;
    this->field_0x44 = 0;
    this->field_0x48 = 0;
    this->field_0x0 = 0;
    this->field_0x4 = 0;
    this->field_0x8 = 0;
    this->field_0x14 = 0;
    this->field_0x10 = 0;
    this->field_0x10 = 60;
    this->field_0x14 = 180;
}
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", CopyMaterial__FP10mgMaterialP13MDT_MATERIAL_P17mgCTextureManager);
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", CopyMDTData__12mgCVisualMDTFP10MDT_HEADERP9mgCMemory);
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", CopyMDTDataPointer__12mgCVisualMDTFP10MDT_HEADERP9mgCMemory);
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", GetMaterial__12mgCVisualMDTFi);
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", GetColor__12mgCVisualMDTFPi);
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", CreateBBox__12mgCVisualMDTFPfPfPA4_f);
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", CreateFace__12mgCVisualMDTFP8FACES_IDP9mgCMemoryP9mgCMemoryPP7mgCFace);
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", DataAssignMDT__12mgCVisualMDTFP10MDT_HEADERP9mgCMemoryP17mgCTextureManager);
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", DataAssignMDT__15mgCVisualFixMDTFP10MDT_HEADERP9mgCMemoryP17mgCTextureManager);
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", Draw__12mgCVisualMDTFPUiPA4_fP14mgCDrawManager);
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", CreatePacket__12mgCVisualMDTFP14mgCDrawManager);
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", CreatePacket__15mgCVisualFixMDTFP14mgCDrawManager);
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", SetData0__FiiPPiP1P1P1P1P1);
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", SetData1__FiiPPiP1P1P1P1P1);
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", SetData2__FiiPPiP1P1P1P1P1);
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", SetData3__FiiPPiP1P1P1P1P1);
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", SetData4__FiiPPiP1P1P1P1P1);
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", SetData5__FiiPPiP1P1P1P1P1);
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", SetData6__FiiPPiP1P1P1P1P1);
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", SetData7__FiiPPiP1P1P1P1P1);
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", CreateFacePacket__12mgCVisualMDTFPUiP7mgCFace);
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", CreateRenderInfoPacket__12mgCVisualMDTFPUiPA4_fP13mgRENDER_INFO);
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", CreateExtRenderInfoPacket__12mgCVisualMDTFPUiPA4_fP13mgRENDER_INFO);
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", Copy__15mgCVisualFixMDTFP9mgCMemory);
typedef struct mgCVisualMDT_infere {
    /* 0x00 */ s32 unk0;                            /* inferred */
    /* 0x04 */ s32 unk4;                            /* inferred */
    /* 0x08 */ s32 unk8;                            /* inferred */
    /* 0x0C */ s32 unkC;                            /* inferred */
    /* 0x10 */ s32 unk10;                           /* inferred */
    /* 0x14 */ s32 unk14;                           /* inferred */
    /* 0x18 */ s32 unk18;                           /* inferred */
    /* 0x1C */ char pad1C[4];
    /* 0x20 */ s32 unk20;                           /* inferred */
    /* 0x24 */ s32 unk24;                           /* inferred */
    /* 0x28 */ s32 unk28;                           /* inferred */
    /* 0x2C */ s32 unk2C;                           /* inferred */
    /* 0x30 */ s32 unk30;                           /* inferred */
    /* 0x34 */ s32 unk34;                           /* inferred */
    /* 0x38 */ s32 unk38;                           /* inferred */
    /* 0x3C */ s32 unk3C;                           /* inferred */
    /* 0x40 */ s32 unk40;                           /* inferred */
    /* 0x44 */ s32 unk44;                           /* inferred */
    /* 0x48 */ s32 unk48;                           /* inferred */
} mgCVisualMDT_infere;                                     /* size >= 0x4C */
extern "C" mgCVisualMDT_infere *__as__12mgCVisualMDTFRC12mgCVisualMDT(mgCVisualMDT_infere *objet, mgCVisualMDT_infere *arg0) {
    objet->unk0 = arg0->unk0;
    objet->unk4 = arg0->unk4;
    objet->unk8 = arg0->unk8;
    objet->unkC = arg0->unkC;
    objet->unk10 = arg0->unk10;
    objet->unk14 = arg0->unk14;
    objet->unk18 = arg0->unk18;
    objet->unk20 = arg0->unk20;
    objet->unk24 = arg0->unk24;
    objet->unk28 = arg0->unk28;
    objet->unk2C = arg0->unk2C;
    objet->unk30 = arg0->unk30;
    objet->unk34 = arg0->unk34;
    objet->unk38 = arg0->unk38;
    objet->unk3C = arg0->unk3C;
    objet->unk40 = arg0->unk40;
    objet->unk44 = arg0->unk44;
    objet->unk48 = arg0->unk48;
    return objet;
}
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", SetDrawEnv__FP10mgCDrawEnvP13mgCVisualAttrP10mgCDrawEnv);
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", CreateRenderInfoPacket__13mgCVisualPrimFPUiPA4_fP13mgRENDER_INFO);
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", Initialize__13mgCVisualPrimFv);
INCLUDE_ASM("nonmatchings/mglib/mgcvisualmdt", Iam__15mgCVisualFixMDTFv);
