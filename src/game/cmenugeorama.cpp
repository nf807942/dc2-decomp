/* CMenuGeorama
 *
 * Unité découpée par `make carve` : 36 fonctions, 25592 octets, de
 * 0x001F6F40 à 0x001FD400. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

/* Les globales que ces accesseurs servent. Leur taille déclarée est celle que
 * le découpage leur donne, et c'est elle qui décide du `%gp_rel`. */
extern s8 DownLoadInfoDrawFlag;

void DrawDownLoadAnaunceSwitch(s32 value) {
    DownLoadInfoDrawFlag = value;
}
INCLUDE_ASM("nonmatchings/game/cmenugeorama", StepDownLoadAnaunce__Fi);
INCLUDE_ASM("nonmatchings/game/cmenugeorama", DrawDownLoadAnaunce__Fv);
INCLUDE_ASM("nonmatchings/game/cmenugeorama", MakeDownLoadAnaunce__FiP9mgCMemoryPiPiPi);
INCLUDE_ASM("nonmatchings/game/cmenugeorama", InitMenuDl3__FP10mgCTexture);
INCLUDE_ASM("nonmatchings/game/cmenugeorama", StepMenuDl3__Fv);
INCLUDE_ASM("nonmatchings/game/cmenugeorama", MenuPlacedHouseDraw__FRi);
INCLUDE_ASM("nonmatchings/game/cmenugeorama", MenuPlacedHouseMessMake__FP14CEditPartsInfoP10CEditHousei);
INCLUDE_ASM("nonmatchings/game/cmenugeorama", MenuPlacedHousePosLinkMes__Fv);
INCLUDE_ASM("nonmatchings/game/cmenugeorama", MenuMapPartsDraw__FRi);
INCLUDE_ASM("nonmatchings/game/cmenugeorama", MenuGeoramaMessageMake__Fi);
INCLUDE_ASM("nonmatchings/game/cmenugeorama", CheckGekkaViewMode__Fi);
INCLUDE_ASM("nonmatchings/game/cmenugeorama", InitEnd__12CMenuGeoramaFv);
extern "C" u32 GeoRequestFlag;
typedef struct MenuGeoramaSystemData_pointe {
    char pad0[80];
    s16 unk50;
    s16 unk52;
    s16 unk54;
    s16 unk56;
    s16 unk58;
    s16 unk5A;
    s16 unk5C;
    s16 unk5E;
    s16 unk60;
    s16 unk62;
    s16 unk64;
    s16 unk66;
    s16 unk68;
    s16 unk6A;
} MenuGeoramaSystemData_pointe;
extern "C" MenuGeoramaSystemData_pointe *MenuGeoramaSystemData;
struct mgCMemory;
struct inferred;
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
typedef struct CMenuGeorama_infere {
    /* 0x00000 */ char pad0[0x1B7F4];
    /* 0x1B7F4 */ s16 unk1B7F4;                     /* inferred */
    /* 0x1B7F6 */ char pad1B7F6[2];
    /* 0x1B7F8 */ s16 unk1B7F8;                     /* inferred */
    /* 0x1B7FA */ char pad1B7FA[2];
    /* 0x1B7FC */ s16 unk1B7FC;                     /* inferred */
    /* 0x1B7FE */ char pad1B7FE[2];
    /* 0x1B800 */ s16 unk1B800;                     /* inferred */
    /* 0x1B802 */ char pad1B802[2];
    /* 0x1B804 */ s16 unk1B804;                     /* inferred */
    /* 0x1B806 */ char pad1B806[2];
    /* 0x1B808 */ s16 unk1B808;                     /* inferred */
    /* 0x1B80A */ char pad1B80A[2];
    /* 0x1B80C */ s16 unk1B80C;                     /* inferred */
    /* 0x1B80E */ char pad1B80E[2];
    /* 0x1B810 */ s16 unk1B810;                     /* inferred */
    /* 0x1B812 */ char pad1B812[2];
    /* 0x1B814 */ s16 unk1B814;                     /* inferred */
    /* 0x1B816 */ char pad1B816[2];
    /* 0x1B818 */ s16 unk1B818;                     /* inferred */
    /* 0x1B81A */ char pad1B81A[2];
    /* 0x1B81C */ s16 unk1B81C;                     /* inferred */
    /* 0x1B81E */ char pad1B81E[2];
    /* 0x1B820 */ s16 unk1B820;                     /* inferred */
    /* 0x1B822 */ char pad1B822[2];
    /* 0x1B824 */ s16 unk1B824;                     /* inferred */
    /* 0x1B826 */ char pad1B826[2];
    /* 0x1B828 */ s16 unk1B828;                     /* inferred */
} CMenuGeorama_infere;                                     /* size >= 0x1B82A */
extern "C" s32 InitDownLoadAnaunce__FP9mgCMemory(mgCMemory *);
extern "C" s32 InitMenuDl__FP10mgCTexturei(mgCTexture *, s32);
extern "C" void ExitEnd__12CMenuGeoramaFv(CMenuGeorama_infere *objet) {
    MenuGeoramaSystemData->unk50 = (s16) objet->unk1B7F4;
    MenuGeoramaSystemData->unk52 = (s16) objet->unk1B7F8;
    MenuGeoramaSystemData->unk54 = (s16) objet->unk1B7FC;
    MenuGeoramaSystemData->unk56 = (s16) objet->unk1B800;
    MenuGeoramaSystemData->unk58 = (s16) objet->unk1B804;
    MenuGeoramaSystemData->unk5A = (s16) objet->unk1B808;
    MenuGeoramaSystemData->unk5C = (s16) objet->unk1B80C;
    MenuGeoramaSystemData->unk5E = (s16) objet->unk1B810;
    MenuGeoramaSystemData->unk60 = (s16) objet->unk1B814;
    MenuGeoramaSystemData->unk62 = (s16) objet->unk1B818;
    MenuGeoramaSystemData->unk64 = (s16) objet->unk1B81C;
    MenuGeoramaSystemData->unk66 = (s16) objet->unk1B820;
    MenuGeoramaSystemData->unk68 = (s16) objet->unk1B824;
    MenuGeoramaSystemData->unk6A = (s16) objet->unk1B828;
    InitMenuDl__FP10mgCTexturei(NULL, 0);
    InitDownLoadAnaunce__FP9mgCMemory(NULL);
    GeoRequestFlag = 0;
}
INCLUDE_ASM("nonmatchings/game/cmenugeorama", GetPartsIDListNum__12CMenuGeoramaFi);
INCLUDE_ASM("nonmatchings/game/cmenugeorama", GetNowMakePartsNum__12CMenuGeoramaFi);
INCLUDE_ASM("nonmatchings/game/cmenugeorama", GetPenkiItemNo__Fi);
INCLUDE_ASM("nonmatchings/game/cmenugeorama", ArrangePartsList__12CMenuGeoramaFii);
INCLUDE_ASM("nonmatchings/game/cmenugeorama", UpdateGeoramaPartsList__12CMenuGeoramaFv);
INCLUDE_ASM("nonmatchings/game/cmenugeorama", GetNowModeLoadPartsID__12CMenuGeoramaFv);
INCLUDE_ASM("nonmatchings/game/cmenugeorama", GetNowSelectEditPartsInfo__12CMenuGeoramaFii);
INCLUDE_ASM("nonmatchings/game/cmenugeorama", LoadGeoramaPart__12CMenuGeoramaFii);
INCLUDE_ASM("nonmatchings/game/cmenugeorama", UpdateGeoramaPartColor__12CMenuGeoramaFi);
INCLUDE_ASM("nonmatchings/game/cmenugeorama", AttachFormInfo__12CMenuGeoramaFv);
INCLUDE_ASM("nonmatchings/game/cmenugeorama", SetGeoListInfo__12CMenuGeoramaFiii);
extern "C" u8 _3181[15];
extern "C" u8 _3182[16];
#include "menu.hpp"
struct inferred;
typedef struct CMenuGeorama {
    /* 0x000 */ char pad0[0x14];
    /* 0x014 */ s16 unk14;                          /* inferred */
    /* 0x016 */ char pad16[0x132];                  /* maybe part of unk14[0x9A]void */
    /* 0x148 */ s32 unk148;                         /* inferred */
} CMenuGeorama;                                     /* size >= 0x14C */
extern "C" s32 ExeScript__14CBaseMenuClassFPc(...);
extern "C" s32 ReturnSelectMode__12CMenuGeoramaFi(CMenuGeorama *objet, s32 arg0) {
    objet->unk148 = objet->unk14 - 1;
    objet->unk14 = 0;
    if (arg0 == 0) {
        ExeScript__14CBaseMenuClassFPc((CBaseMenuClass *) objet, &_3181);
    }
    if (arg0 == 1) {
        ExeScript__14CBaseMenuClassFPc((CBaseMenuClass *) objet, &_3182);
    }
    return 1;
}
INCLUDE_ASM("nonmatchings/game/cmenugeorama", GetNowViewModeMax__12CMenuGeoramaFi);
INCLUDE_ASM("nonmatchings/game/cmenugeorama", LRCheck__12CMenuGeoramaFv);
INCLUDE_ASM("nonmatchings/game/cmenugeorama", MakeMsgPartsItemInfo__FP7CDC2MesP14CEditPartsInfoP21MENUFORM_MAKEBRD_INFO);
INCLUDE_ASM("nonmatchings/game/cmenugeorama", IsMakeObject__12CMenuGeoramaFii);
INCLUDE_ASM("nonmatchings/game/cmenugeorama", CalcCursorPosition__12CMenuGeoramaFv);
INCLUDE_ASM("nonmatchings/game/cmenugeorama", CalcTex__12CMenuGeoramaFv);
INCLUDE_ASM("nonmatchings/game/cmenugeorama", CalcMakeBrd__12CMenuGeoramaFv);
INCLUDE_ASM("nonmatchings/game/cmenugeorama", MenuGeoramaBasePush__FP12CMenuGeoramaii);
INCLUDE_ASM("nonmatchings/game/cmenugeorama", georama_menu_local_key__Fi);
INCLUDE_ASM("nonmatchings/game/cmenugeorama", MenuGeoramaPlacePush__FP12CMenuGeoramaii);
