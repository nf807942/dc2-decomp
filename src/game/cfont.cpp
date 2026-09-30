/* CFont, COcclusion
 *
 * Unité découpée par `make carve` : 90 fonctions, 24920 octets, de
 * 0x002D8EE0 à 0x002DF230. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"
#include "gen/CFont.hpp"

/* Les globales que ces accesseurs servent. Leur taille déclarée est celle que
 * le découpage leur donne, et c'est elle qui décide du `%gp_rel`. */
extern s32 CtrlLockFlag;
extern s32 FontTex_2_Buff;
extern s32 PartsInfoID;
extern s32 PreMenuCount;
extern s32 PreMenuMaxCount;

extern s32 CursorLockCnt;
extern s32 EditHelpMesNo;
extern s32 EditHelpMesParam2;
extern s32 EditHelpMesParam;
extern s32 PlaceRiverCnt;
extern s32 RemoveMtnCnt;
extern s32 SysMesCnt;
extern s32 SysMesNo;


extern "C" u32 LanguageCode;
extern "C" s32 GetKanjiTopNo__Fv(void);
extern "C" s32 GetYoyakuTblNum__Fv(void);
extern "C" s32 CheckKanjiFont__5CFontFi(CFont *objet, s32 arg0) {
    if (LanguageCode == 6) {
        return 0;
    }
    if (GetKanjiTopNo__Fv() == 0) {
        return 0;
    }
    if (arg0 < GetKanjiTopNo__Fv()) {
        return 0;
    }
    return (arg0 >= GetYoyakuTblNum__Fv()) ^ 1;
}
extern "C" s32 GetHalfFontNum__Fv(void);
extern "C" s32 CheckHalfFont__5CFontFi(CFont *objet, s32 arg0) {
    if (arg0 == 0xFF02) {
        return 1;
    }
    if (LanguageCode != 1) {
        if ((arg0 >= 0x5E) && (arg0 < 0x9D)) {
            return 1;
        }
        if ((arg0 >= 0x9D) && (arg0 < 0xB5)) {
            return 0;
        }
        goto block_9;
    }
block_9:
    if (arg0 < 0) {
        return 0;
    }
    return (arg0 >= GetHalfFontNum__Fv()) ^ 1;
}
void CFont::SetDrawSize(s32 arg0, s32 arg1) {
    this->field_0xA4 = arg0;
    this->field_0xA8 = arg1;
}
void CFont::SetClearance(s32 arg0, s32 arg1) {
    this->field_0x9C = arg0;
    this->field_0xA0 = arg1;
}
void CFont::SetPos(s32 arg0, s32 arg1) {
    this->field_0x94 = arg0;
    this->field_0x98 = arg1;
}
extern "C" void SetColor__5CFontFiiii(void *self, s32 r, s32 g, s32 b, s32 a) {
    u8 *p = (u8 *)self;
    p[0x88] = r;
    p[0x89] = g;
    p[0x8A] = b;
    p[0x8B] = a;
}

INCLUDE_ASM("nonmatchings/game/cfont", SetColor__5CFontF10RGBAQ_TYPE);
INCLUDE_ASM("nonmatchings/game/cfont", SetColor__5CFontFUi);
void CFont::SetFuchi(s32 arg0) {
    this->field_0x80 = arg0;
}
extern "C" u8 _936_003761D0[26];
extern "C" s32 memset(...);
extern "C" s32 printf(...);
extern "C" s32 strcpy(...);
extern "C" s32 strlen(...);
extern "C" void SetStr__5CFontFPc(CFont *objet, s8 *arg0) {
    memset(objet, 0, 0x80);
    if (strlen(arg0) >= 0x80U) {
        printf(&_936_003761D0);
        return;
    }
    strcpy(objet, arg0);
}
INCLUDE_ASM("nonmatchings/game/cfont", GetGaijiFontNo__FPc);
INCLUDE_ASM("nonmatchings/game/cfont", GetGaijiLen__FUs);
INCLUDE_ASM("nonmatchings/game/cfont", GetAlphabeticalFontNo_uc__FUc);
INCLUDE_ASM("nonmatchings/game/cfont", GetAlphabeticalFontNo_cp__FPc);
INCLUDE_ASM("nonmatchings/game/cfont", GetFontGaijiFontNo__FPc);
INCLUDE_ASM("nonmatchings/game/cfont", GetAlphabeticalFontNo_us__FUs);
INCLUDE_ASM("nonmatchings/game/cfont", GetFontNoFromFontGaijiCode__FUs);
INCLUDE_ASM("nonmatchings/game/cfont", GetFontGaijiHankaku__FUs);
INCLUDE_ASM("nonmatchings/game/cfont", GetFontNo__FPc);
INCLUDE_ASM("nonmatchings/game/cfont", GetHalfFontNo__Fc);
INCLUDE_ASM("nonmatchings/game/cfont", GetDigitNo__5CFontFi);
INCLUDE_ASM("nonmatchings/game/cfont", set2DSpriteEasyFont__FP11mgCDrawPrim9mgRect_i_9mgRect_i_P10RGBAQ_TYPE);
INCLUDE_ASM("nonmatchings/game/cfont", set2DSprite_Fuchi__FP11mgCDrawPrim4RECT4RECTii);
INCLUDE_ASM("nonmatchings/game/cfont", DrawChar__5CFontFP11mgCDrawPrimiiii10RGBAQ_TYPEUc);
INCLUDE_ASM("nonmatchings/game/cfont", DrawChar__5CFontFP11mgCDrawPrimPcii);
extern "C" u8 mgTexManager[540];
extern "C" s32 GetTexture__17mgCTextureManagerFPci(...);
#include "gen/mgCDrawPrim.hpp"
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
extern "C" s32 Texture__11mgCDrawPrimFP10mgCTexture(...);
extern "C" void MySetTex__FPcP11mgCDrawPrim(s8 *arg0, mgCDrawPrim *arg1) {
    Texture__11mgCDrawPrimFP10mgCTexture(arg1, GetTexture__17mgCTextureManagerFPci(&mgTexManager, arg0, -1));
}
extern "C" s32 GetFontTexture__Fi(s32);
extern "C" void MySetTex__FiP11mgCDrawPrim(s32 arg0, mgCDrawPrim *arg1) {
    if ((arg0 == 0) || (arg0 == 1)) {
        Texture__11mgCDrawPrimFP10mgCTexture(arg1, GetFontTexture__Fi(arg0));
    }
}
INCLUDE_ASM("nonmatchings/game/cfont", DrawGaiji_sub__FP11mgCDrawPrimiii10RGBAQ_TYPEi);
INCLUDE_ASM("nonmatchings/game/cfont", DrawGaiji__5CFontFP11mgCDrawPrimiii);
extern "C" void UpDateWH__FPiPiii(s32 *arg0, s32 *arg1, s32 arg2, s32 arg3) {
    if (*arg0 < arg2) {
        *arg0 = arg2;
    }
    if (*arg1 < arg3) {
        *arg1 = arg3;
    }
}
INCLUDE_ASM("nonmatchings/game/cfont", CalcDrawWH__5CFontFPcPiPi);
INCLUDE_ASM("nonmatchings/game/cfont", DrawDirect__5CFontFPcii);
extern "C" s32 SetColor__5CFontFUi(void *, u32);
extern "C" s32 SetFuchi__5CFontFi(void *, s32);
extern "C" void Preset__5CFontFi(CFont *objet, s32 arg0) {
    switch (arg0) {
    case 0:
    case 1:
        SetColor__5CFontFUi(objet, 0x80202020U);
        SetFuchi__5CFontFi(objet, 2);
        break;
    case 2:
    case 3:
        SetColor__5CFontFUi(objet, 0x80686A6BU);
        SetFuchi__5CFontFi(objet, 8);
        break;
    case 4:
        SetColor__5CFontFUi(objet, 0x80686A6BU);
        SetFuchi__5CFontFi(objet, 5);
        break;
    }
}
struct objet_champs_5cea16 {
    char pad0[0x88];
    /* 0x88 */ u8 unk88;
    /* 0x89 */ u8 unk89;
    /* 0x8A */ u8 unk8A;
    /* 0x8B */ u8 unk8B;
    char pad8C[0x4];
    /* 0x90 */ s32 unk90;
    /* 0x94 */ s32 unk94;
    /* 0x98 */ s32 unk98;
    /* 0x9C */ s32 unk9C;
    /* 0xA0 */ s32 unkA0;
    /* 0xA4 */ s32 unkA4;
    /* 0xA8 */ s32 unkA8;
    /* 0xAC */ s32 unkAC;
    /* 0xB0 */ s32 unkB0;
    /* 0xB4 */ s32 unkB4;
};
extern "C" s32 memset(...);
extern "C" s32 SetFuchi__5CFontFi(void *, s32);
extern "C" void Init__5CFontFv(CFont *objet) {
    memset(objet, 0, 0x80);
    SetFuchi__5CFontFi(objet, 3);
    ((struct objet_champs_5cea16 *) objet)->unk8B = 0x80;
    ((struct objet_champs_5cea16 *) objet)->unk8A = 0x80;
    ((struct objet_champs_5cea16 *) objet)->unk89 = 0x80;
    ((struct objet_champs_5cea16 *) objet)->unk88 = 0x80;
    ((struct objet_champs_5cea16 *) objet)->unk90 = 0x80;
    ((struct objet_champs_5cea16 *) objet)->unk98 = 0;
    ((struct objet_champs_5cea16 *) objet)->unk94 = 0;
    ((struct objet_champs_5cea16 *) objet)->unk9C = 0xF;
    ((struct objet_champs_5cea16 *) objet)->unkA0 = 0x18;
    ((struct objet_champs_5cea16 *) objet)->unkA4 = 0x10;
    ((struct objet_champs_5cea16 *) objet)->unkA8 = 0x14;
    ((struct objet_champs_5cea16 *) objet)->unkAC = 0;
    ((struct objet_champs_5cea16 *) objet)->unkB0 = 0;
    ((struct objet_champs_5cea16 *) objet)->unkB4 = 0;
}
INCLUDE_ASM("nonmatchings/game/cfont", Setup__10COcclusionFPA4_f);
INCLUDE_ASM("nonmatchings/game/cfont", CheckSphere__10COcclusionFPf);
INCLUDE_ASM("nonmatchings/game/cfont", CalcSelectCursorPos__F4RECTPi);
typedef struct RECT {
    /* 0x0 */ char pad0[8];
    /* 0x8 */ s32 unk8;                             /* inferred */
} RECT;                                             /* size >= 0xC */
extern "C" void OffsetYesNoWin__FP4RECTP4RECT(RECT *arg0, RECT *arg1) {
    if (arg0->unk8 < 0xA6) {
        arg0->unk8 = 0xA6;
        arg1->unk8 = 0xA6;
    }
}
INCLUDE_ASM("nonmatchings/game/cfont", DrawVersatileWin_yesno__FP11mgCDrawPrim4RECTP10RGBAQ_TYPEii);
INCLUDE_ASM("nonmatchings/game/cfont", MyMenuHelpWinDraw__FP11mgCDrawPrim4RECTi);
INCLUDE_ASM("nonmatchings/game/cfont", MyMenuFloatingWinDraw__FP11mgCDrawPrim4RECTiiP10RGBAQ_TYPEP10RGBAQ_TYPE);
INCLUDE_ASM("nonmatchings/game/cfont", DrawVersatileWin_1__FP11mgCDrawPrim4RECTP10RGBAQ_TYPEii);
INCLUDE_ASM("nonmatchings/game/cfont", DrawVersatileWin_1__FP11mgCDrawPrim4RECTP10RGBAQ_TYPEi);
INCLUDE_ASM("nonmatchings/game/cfont", DrawVersatileWin_3__FP11mgCDrawPrim4RECTiP10RGBAQ_TYPEii);
INCLUDE_ASM("nonmatchings/game/cfont", DrawVersatileWin_4__FP11mgCDrawPrim4RECTP10RGBAQ_TYPEii);
INCLUDE_ASM("nonmatchings/game/cfont", DrawVersatileWin_4__FP11mgCDrawPrim4RECTP10RGBAQ_TYPEi);
INCLUDE_ASM("nonmatchings/game/cfont", DrawDQFukidashi__FP11mgCDrawPrim4RECTiiP10RGBAQ_TYPEii);
INCLUDE_ASM("nonmatchings/game/cfont", LoadGaijiImg__Fv);
extern "C" u8 GaijiBuff[];
extern "C" void *GetGaijiImgPtr__Fv(void) {
    return GaijiBuff;
}

extern "C" u32 LanguageCode;
extern "C" u8 _278_003765B0[17];
extern "C" s32 LoadFile__FPcPvPi(...);
extern "C" s32 LoadFontTex2Img__Fv(void) {
    s32 sp1C;

    if (FontTex_2_Buff == NULL) {
        return 0;
    }
    if (LanguageCode != 0) {
        return 0;
    }
    LoadFile__FPcPvPi(&_278_003765B0, FontTex_2_Buff, &sp1C);
    return sp1C;
}
s32 GetFontTex2ImgPtr(void) {
    return FontTex_2_Buff;
}
s32 CheckControl(void) {
    return CtrlLockFlag;
}
extern "C" void EditModeControlLock__Fv(void) {
    CtrlLockFlag++;
}

extern "C" void EditModeControlUnLock__Fv(void) {
    CtrlLockFlag -= 1;
    if (CtrlLockFlag < 0) {
        CtrlLockFlag = 0;
    }
}
void SetHelpMes(s32 arg0, s32 arg1, s32 arg2) {
    EditHelpMesNo = arg0;
    EditHelpMesParam = arg1;
    EditHelpMesParam2 = arg2;
}
extern "C" s32 GetSaveData__Fv(void);
extern "C" s32 GetUserData__Fv_002DD7A0(void) {
    u8 *p;

    p = (u8 *) GetSaveData__Fv();
    if (p != 0) {
        return (s32) (p + 0x1D2A0);
    }
    return 0;
}
extern "C" f32 ConvColor__Ff(f32 arg0) {
    return arg0 / 128.0f;
}
INCLUDE_ASM("nonmatchings/game/cfont", ConvColorV__FPf);
extern "C" s32 EditPartsCmpColor__FPfPf(f32 *, f32 *);
extern "C" s32 GetPenkiColor__FiPf(s32, f32 *);
extern "C" s32 ConvColorV__FPf(f32 *);
extern "C" s32 emSearchColorCode__FPf(f32 *arg0) {
    f32 sp30[4];
    s32 i;

    for (i = 0; i < 8; i++) {
        GetPenkiColor__FiPf(i, sp30);
        ConvColorV__FPf(sp30);
        if (EditPartsCmpColor__FPfPf(arg0, sp30) != 0) {
            return i;
        }
    }
    return -1;
}
extern "C" s32 GetPenkiItemNo__Fi(s32 arg0);
extern "C" s32 emGetPenkiItemNo__Fi(s32 arg0) {
    if ((arg0 < 0) || (arg0 >= 8)) {
        return -1;
    }
    return GetPenkiItemNo__Fi(arg0);
}
extern "C" s32 emGetPenkiItemNo__Fi(s32 arg0);
extern "C" s32 emSearchColorCode__FPf(f32 *arg0);
extern "C" void emGetPenkiItemNo__FPf(f32 *arg0) {
    emGetPenkiItemNo__Fi(emSearchColorCode__FPf(arg0));
}
void IntiSystemMes(void) {
    SysMesCnt = 0;
    SysMesNo = -1;
}
extern "C" s32 GetMessage__6CSceneFi(void *, s32);
#include "sphida.hpp"
struct inferred;
struct ClsMes;
typedef struct ClsMes {
    /* 0x000 */ char pad0[0x158];
    /* 0x158 */ s32 unk158;                         /* inferred */
} ClsMes;                                           /* size >= 0x15C */
extern "C" s32 MakeMesWin__6ClsMesFi(void *, s32);
extern "C" s32 Preset__6ClsMesFi(void *, s32);
extern "C" s32 SetWindowMode__6ClsMesFi(void *, s32);
extern "C" void OpenSystemMes__FP6CSceneii(CScene *arg0, s32 arg1, s32 arg2) {
    ClsMes *temp_v0;

    temp_v0 = (ClsMes *) (GetMessage__6CSceneFi(arg0, 1));
    if (temp_v0 != NULL) {
        Preset__6ClsMesFi(temp_v0, 4);
        SetWindowMode__6ClsMesFi(temp_v0, 4);
        MakeMesWin__6ClsMesFi(temp_v0, arg1);
        temp_v0->unk158 = 8;
        SysMesCnt = arg2;
        SysMesNo = arg1;
    }
}
INCLUDE_ASM("nonmatchings/game/cfont", SystemMesClose__FP6CScene);
#include "sphida.hpp"
extern "C" void SystemMesClose__FP6CScene(CScene *arg0);
extern "C" void SystemMesStep__FP6CScene(CScene *arg0) {
    if (SysMesNo >= 0) {
        if (SysMesCnt < 0) {
            SystemMesClose__FP6CScene(arg0);
            SysMesCnt = 0;
        }
        SysMesCnt = SysMesCnt - 1;
    }
}
INCLUDE_ASM("nonmatchings/game/cfont", EditStartPlaceEffect__FP10CEditPartsPf);
INCLUDE_ASM("nonmatchings/game/cfont", EditEndPlaceEffect__Fv);
void EditPreMenuAnime(s32 arg0) {
    PreMenuMaxCount = arg0;
    PreMenuCount = 0;
}
INCLUDE_ASM("nonmatchings/game/cfont", LoadEditCursor__FP9mgCMemoryi);
s32 GetSelPartsInfoID(void) {
    return PartsInfoID;
}
void ClearEditStepCnt(void) {
    PlaceRiverCnt = 0;
    CursorLockCnt = 0;
    RemoveMtnCnt = 0;
}
struct UndoData_t {
    s32 flag0;
    s32 flag4;
    u8 pad8[4088];
};
extern "C" UndoData_t UndoData;
extern "C" void ClearUndoFlag__Fv(void) {
    UndoData.flag0 = -1;
    UndoData.flag4 = -1;
}

INCLUDE_ASM("nonmatchings/game/cfont", ClearEditFlag__Fv);
extern "C" u32 EditModeNo;
extern "C" u32 HighSpeedMoveCnt;
extern "C" u32 MagnetEnable;
extern "C" u32 eCameraDist;
extern "C" void EditInitPlaceAnime__Fv();
extern "C" void EditInitPlaceEffect__Fv();
extern "C" void ClearEditFlag__Fv();
extern "C" void InitEditFlag__Fv(void) {
    eCameraDist = 0x44160000;
    EditModeNo = 0;
    ClearEditFlag__Fv();
    EditInitPlaceAnime__Fv();
    EditInitPlaceEffect__Fv();
    CtrlLockFlag = 0;
    MagnetEnable = 1;
    HighSpeedMoveCnt = 0;
}
INCLUDE_ASM("nonmatchings/game/cfont", StartEditMode__FP6CScene);
INCLUDE_ASM("nonmatchings/game/cfont", EndEditMode__FP6CScenePf);
INCLUDE_ASM("nonmatchings/game/cfont", StartEditModeFromMenu__FP6CSceneiPi);
extern "C" void *GetUndoData__Fv(void) {
    return &UndoData;
}

extern "C" void *GetUndoData__Fv(void);
extern "C" s32 UndoEnable__Fv(void) {
    return *(s32 *)GetUndoData__Fv() >= 0;
}

INCLUDE_ASM("nonmatchings/game/cfont", UndoPlaceParts__FP6CScene);
INCLUDE_ASM("nonmatchings/game/cfont", StackUndoData__FP9UNDO_DATA);
INCLUDE_ASM("nonmatchings/game/cfont", StartEditPutWall__FPQ210CEditParts8WallInfo);
INCLUDE_ASM("nonmatchings/game/cfont", PlaceEditParts__FP8CEditMapPfPfP13EP_PLACE_INFO);
INCLUDE_ASM("nonmatchings/game/cfont", PlaceRiverStart__FP8CEditMapPf);
extern "C" u8 PlaceRiverPos[16];
extern "C" u8 _1268_0035B6C0[16];
extern "C" s32 EditPaintEffect__FP10CEditPartsPfPfi(...);
extern "C" s32 GetSystemSndID__Fv(void);
extern "C" s32 mgZeroVector__FPf(f32 *);
extern "C" s32 sndSePlay__FUiii(u32, s32, s32);
extern "C" s32 PlaceEditParts__FP8CEditMapPfPfP13EP_PLACE_INFO(...);
extern "C" s32 PlaceRiverStep__FP8CEditMap(void *arg0) {
    f32 sp20[4];
    f32 sp30[4];

    if (PlaceRiverCnt <= 0) {
        return 0;
    }
    PlaceRiverCnt -= 1;
    if (PlaceRiverCnt >= 0x1E) {
        CursorLockCnt = 5;
    }
    if (PlaceRiverCnt == 0x28) {
        sndSePlay__FUiii(GetSystemSndID__Fv(), 0x22, 0);
    }
    if (PlaceRiverCnt == 0x1E) {
        mgZeroVector__FPf(sp20);
        if (PlaceEditParts__FP8CEditMapPfPfP13EP_PLACE_INFO(arg0, &PlaceRiverPos, sp20, NULL) != 0) {
            *(u128 *) sp30 = *(u128 *) _1268_0035B6C0;
            EditPaintEffect__FP10CEditPartsPfPfi(NULL, &PlaceRiverPos, sp30, 1);
        }
    }
    if (PlaceRiverCnt <= 0) {
        PlaceRiverCnt = 0;
    }
    return 0;
}
extern "C" s32 NowPlaceRiver__Fv(void) {
    return PlaceRiverCnt > 0;
}

INCLUDE_ASM("nonmatchings/game/cfont", RemoveMtnStart__FP8CEditMapPfPf);
extern "C" s32 GetMap__6CSceneFi(void *, s32);
extern "C" s32 GetePlaceParts__8CEditMapFi(void *, s32);
extern "C" u8 RemoveMtnPos[16];
extern "C" u8 eCurPos[16];
extern "C" u8 RemoveMtnCurPos[16];
extern "C" s32 EditSetPlaceAnime__FiP9CMapParts(...);
extern "C" s32 GetePlaceParts__8CEditMapFPf(...);
extern "C" s32 RemoveEditParts__FP6CSceneiPf(...);
extern "C" s32 RemoveMtnStep__FP6CScene(void *arg0) {
    void *temp_s0;
    s32 temp_v0;

    if (RemoveMtnCnt <= 0) {
        return 0;
    }
    temp_s0 = (void *) GetMap__6CSceneFi(arg0, *(s32 *) ((u8 *) arg0 + 0x2E5C));
    RemoveMtnCnt -= 1;
    if (RemoveMtnCnt >= 3) {
        CursorLockCnt = 3;
    }
    *(u128 *) eCurPos = *(u128 *) RemoveMtnCurPos;
    *(u128 *) eCurPos = *(u128 *) RemoveMtnCurPos;
    if (RemoveMtnCnt == 3) {
        temp_v0 = GetePlaceParts__8CEditMapFPf(temp_s0, &RemoveMtnPos);
        EditSetPlaceAnime__FiP9CMapParts(3, GetePlaceParts__8CEditMapFi(temp_s0, temp_v0));
        if (RemoveEditParts__FP6CSceneiPf(arg0, temp_v0, &RemoveMtnPos) != 0) {
            sndSePlay__FUiii(GetSystemSndID__Fv(), 0x17, 0);
        } else {
            EditInitPlaceAnime__Fv();
        }
    }
    if (RemoveMtnCnt <= 0) {
        RemoveMtnCnt = 0;
    }
    return 0;
}
INCLUDE_ASM("nonmatchings/game/cfont", RemoveEditParts__FP6CSceneiPf);
INCLUDE_ASM("nonmatchings/game/cfont", DeleteKanketuParts__FP6CSceneP8CEditMapPfi);
