/* CNameRegiMenu
 *
 * Unité découpée par `make carve` : 33 fonctions, 16428 octets, de
 * 0x0030F950 à 0x00313A30. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

INCLUDE_ASM("nonmatchings/game/cnameregimenu", GetActiveFontMode__13CNameRegiMenuFv);
INCLUDE_ASM("nonmatchings/game/cnameregimenu", CopyAsciiToJis__13CNameRegiMenuFPcPc);
INCLUDE_ASM("nonmatchings/game/cnameregimenu", CopyJisToAscii__13CNameRegiMenuFPcPc);
INCLUDE_ASM("nonmatchings/game/cnameregimenu", CheckChronicleKanjiFont__FP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/cnameregimenu", GetNameRegistFontKanjiList__FiPc);
INCLUDE_ASM("nonmatchings/game/cnameregimenu", AdjustWaku__FP7CDC2MesP4RECT);
INCLUDE_ASM("nonmatchings/game/cnameregimenu", search_txt_jis__FPc);
INCLUDE_ASM("nonmatchings/game/cnameregimenu", search_txt_asci__FPc);
INCLUDE_ASM("nonmatchings/game/cnameregimenu", ConvertShitJiss2Ascii__FPcPc);
INCLUDE_ASM("nonmatchings/game/cnameregimenu", ConvertAscii2ShitJiss__FPcPc);
INCLUDE_ASM("nonmatchings/game/cnameregimenu", NameRegistInit__FP9mgCMemoryPii);
struct CNameRegiMenu;
extern "C" void KeyStep__13CNameRegiMenuFv(CNameRegiMenu *);
extern "C" CNameRegiMenu *NameRegiMenuPtr;
extern "C" void NameRegistKey__Fv(void) {
    KeyStep__13CNameRegiMenuFv(NameRegiMenuPtr);
}
struct CNameRegiMenu;
extern "C" CNameRegiMenu *NameRegiMenuPtr;
extern "C" u32 OldReloadTexNumber;
struct CNameRegiMenu {
    s16 field_0;
    s16 field_2;
    char pad_4[0x2];
    s16 field_6;
    char pad_8[0xC];
    s16 field_14;
    char pad_16[0xFA];
    s32 field_110;
    s32 field_114;
    s32 field_118;
    s32 field_11C;
    char pad_120[0x10];
    u8 field_130;
    char pad_131[0x3];
    f32 field_134;
    f32 field_138;
    s32 field_13C;
    char pad_140[0x10];
    s32 field_150;
    char pad_154[0xE];
    s16 field_162;
    s16 field_164;
    s16 field_166;
    s16 field_168;
    s16 field_16A;
    char pad_16C[0xC];
    f32 field_178;
    f32 field_17C;
    char pad_180[0x94];
    s32 field_214;
    s32 field_218;
    char pad_21C[0x1C];
    s32 field_238;
    f32 field_23C;
    s8 field_240;
    char pad_241[0x60];
    s8 field_2A1;
    char pad_2A2[0x62];
    s32 field_304;
    char pad_308[0x94];
    s32 field_39C;
    s32 field_3A0;
    char pad_3A4[0x14];
    s32 field_3B8;
    s32 field_3BC;
    s32 field_3C0;
    f32 field_3C4;
};
extern "C" s32 DrawActiveFont__13CNameRegiMenuFv(void *);
extern "C" s32 DrawBaseBoard__13CNameRegiMenuFv(void *);
extern "C" s32 DrawMarkCursor__13CNameRegiMenuFv(void *);
extern "C" s32 DrawMessage__13CNameRegiMenuFv(void *);
extern "C" s32 DrawSelectedWord__13CNameRegiMenuFv(void *);
extern "C" void NameRegistDraw__Fv(void) {
    OldReloadTexNumber = -1;
    DrawBaseBoard__13CNameRegiMenuFv(NameRegiMenuPtr);
    DrawSelectedWord__13CNameRegiMenuFv(NameRegiMenuPtr);
    DrawActiveFont__13CNameRegiMenuFv(NameRegiMenuPtr);
    DrawMarkCursor__13CNameRegiMenuFv(NameRegiMenuPtr);
    DrawMessage__13CNameRegiMenuFv(NameRegiMenuPtr);
}
INCLUDE_ASM("nonmatchings/game/cnameregimenu", CheckInputWord__FPc);
INCLUDE_ASM("nonmatchings/game/cnameregimenu", nameregist_local_key__FP17MENU_SELECT_PARAMRiPsi);
INCLUDE_ASM("nonmatchings/game/cnameregimenu", ConvertPositionNameRegi__13CNameRegiMenuFi);
INCLUDE_ASM("nonmatchings/game/cnameregimenu", CheckKanjiPosition__13CNameRegiMenuFiPsi);
INCLUDE_ASM("nonmatchings/game/cnameregimenu", KeyStep__13CNameRegiMenuFv);
INCLUDE_ASM("nonmatchings/game/cnameregimenu", GetSelectedActiveFont__13CNameRegiMenuFPc);
INCLUDE_ASM("nonmatchings/game/cnameregimenu", ChangeFontSelectMode__13CNameRegiMenuFi);
INCLUDE_ASM("nonmatchings/game/cnameregimenu", ConvertNameRegiBaseBoardTable__Fi);
INCLUDE_ASM("nonmatchings/game/cnameregimenu", DrawBaseBoard__13CNameRegiMenuFv);
INCLUDE_ASM("nonmatchings/game/cnameregimenu", DrawActiveFont__13CNameRegiMenuFv);
INCLUDE_ASM("nonmatchings/game/cnameregimenu", StepMarkCursor__13CNameRegiMenuFv);
INCLUDE_ASM("nonmatchings/game/cnameregimenu", DrawMarkCursor__13CNameRegiMenuFv);
INCLUDE_ASM("nonmatchings/game/cnameregimenu", DrawSelectedWord__13CNameRegiMenuFv);
INCLUDE_ASM("nonmatchings/game/cnameregimenu", DrawMessage__13CNameRegiMenuFv);
INCLUDE_ASM("nonmatchings/game/cnameregimenu", GetMesTxt__Fi);
INCLUDE_ASM("nonmatchings/game/cnameregimenu", PhotoAddProjection__Fv);
extern "C" u8 PhotoTitle[];
extern "C" s32 ShowTitleCnt;
extern "C" s32 InitPhotoTitle__Fv(void) {
    ShowTitleCnt = 0;
    PhotoTitle[0] = 0;
}
extern "C" u32 AddProj_0037E8CC;
extern "C" u32 CameraTexb;
extern "C" u32 OpenMenu;
extern "C" u32 ShowLevelUpCnt;
extern "C" u32 ShowTakePhotoCnt;
extern "C" u32 ShutterAnmCnt;
extern "C" u32 TakePhotoMode;
extern "C" s32 InitPhotoTitle__Fv(void);
extern "C" void InitTakePhoto__Fv(void) {
    TakePhotoMode = 0;
    AddProj_0037E8CC = 0;
    InitPhotoTitle__Fv();
    ShowTakePhotoCnt = 0;
    CameraTexb = -1;
    ShutterAnmCnt = 0;
    OpenMenu = 0;
    ShowLevelUpCnt = 0;
}
extern "C" u32 CameraTexb;
extern "C" u8 Font_01F5D370[184];
extern "C" u32 WorkTex;
extern "C" u8 mgTexManager[540];
extern "C" u8 _852_00378C00[9];
struct U;
struct i {
    u8 field_0;
    char pad_1[0x3];
    s32 field_4;
    char pad_8[0x18];
    s64 field_20;
    s64 field_28;
};
extern "C" s32 EnterTexture__17mgCTextureManagerFiPcPP1iiiP1Uli(...);
extern "C" s32 Init__5CFontFv(void *);
extern "C" s32 Preset__5CFontFi(void *, s32);
extern "C" s32 SetClearance__5CFontFii(void *, s32, s32);
extern "C" s32 SetFuchi__5CFontFi(void *, s32);
extern "C" void LoadTakePhoto__FiP9mgCMemoryP1(s32 arg0) {
    WorkTex = EnterTexture__17mgCTextureManagerFiPcPP1iiiP1Uli(&mgTexManager, 0x7FFF, &_852_00378C00, NULL, 0x40, 0x40, (U *)0x10, 0, (s32) 0, /* extra? */ 0);
    CameraTexb = arg0;
    Init__5CFontFv(&Font_01F5D370);
    Preset__5CFontFi(&Font_01F5D370, 4);
    SetFuchi__5CFontFi(&Font_01F5D370, 3);
    SetClearance__5CFontFii(&Font_01F5D370, 0xF, 0x18);
}
extern "C" void StartTakePhoto__Fv(void) {
    InitTakePhoto__Fv();
    TakePhotoMode = 2;
}
