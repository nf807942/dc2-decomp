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


INCLUDE_ASM("nonmatchings/game/cfont", CheckKanjiFont__5CFontFi);
INCLUDE_ASM("nonmatchings/game/cfont", CheckHalfFont__5CFontFi);
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
INCLUDE_ASM("nonmatchings/game/cfont", SetColor__5CFontFiiii);
INCLUDE_ASM("nonmatchings/game/cfont", SetColor__5CFontF10RGBAQ_TYPE);
INCLUDE_ASM("nonmatchings/game/cfont", SetColor__5CFontFUi);
void CFont::SetFuchi(s32 arg0) {
    this->field_0x80 = arg0;
}
INCLUDE_ASM("nonmatchings/game/cfont", SetStr__5CFontFPc);
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
INCLUDE_ASM("nonmatchings/game/cfont", Preset__5CFontFi);
INCLUDE_ASM("nonmatchings/game/cfont", Init__5CFontFv);
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
INCLUDE_ASM("nonmatchings/game/cfont", GetGaijiImgPtr__Fv);
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
INCLUDE_ASM("nonmatchings/game/cfont", EditModeControlLock__Fv);
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
INCLUDE_ASM("nonmatchings/game/cfont", GetUserData__Fv_002DD7A0);
extern "C" f32 ConvColor__Ff(f32 arg0) {
    return arg0 / 128.0f;
}
INCLUDE_ASM("nonmatchings/game/cfont", ConvColorV__FPf);
INCLUDE_ASM("nonmatchings/game/cfont", emSearchColorCode__FPf);
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
INCLUDE_ASM("nonmatchings/game/cfont", OpenSystemMes__FP6CSceneii);
INCLUDE_ASM("nonmatchings/game/cfont", SystemMesClose__FP6CScene);
#include "sphida.hpp"
extern "C" void SystemMesClose__FP6CScene(CScene *arg0);
extern "C" void SystemMesStep__FP6CScene(CScene *arg0) {
    if (SysMesNo >= 0) {
        if (SysMesCnt < 0) {
            SystemMesClose__FP6CScene(arg0);
            SysMesCnt = 0;
        }
        SysMesCnt -= 1;
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
INCLUDE_ASM("nonmatchings/game/cfont", ClearUndoFlag__Fv);
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
INCLUDE_ASM("nonmatchings/game/cfont", GetUndoData__Fv);
INCLUDE_ASM("nonmatchings/game/cfont", UndoEnable__Fv);
INCLUDE_ASM("nonmatchings/game/cfont", UndoPlaceParts__FP6CScene);
INCLUDE_ASM("nonmatchings/game/cfont", StackUndoData__FP9UNDO_DATA);
INCLUDE_ASM("nonmatchings/game/cfont", StartEditPutWall__FPQ210CEditParts8WallInfo);
INCLUDE_ASM("nonmatchings/game/cfont", PlaceEditParts__FP8CEditMapPfPfP13EP_PLACE_INFO);
INCLUDE_ASM("nonmatchings/game/cfont", PlaceRiverStart__FP8CEditMapPf);
INCLUDE_ASM("nonmatchings/game/cfont", PlaceRiverStep__FP8CEditMap);
INCLUDE_ASM("nonmatchings/game/cfont", NowPlaceRiver__Fv);
INCLUDE_ASM("nonmatchings/game/cfont", RemoveMtnStart__FP8CEditMapPfPf);
INCLUDE_ASM("nonmatchings/game/cfont", RemoveMtnStep__FP6CScene);
INCLUDE_ASM("nonmatchings/game/cfont", RemoveEditParts__FP6CSceneiPf);
INCLUDE_ASM("nonmatchings/game/cfont", DeleteKanketuParts__FP6CSceneP8CEditMapPfi);
