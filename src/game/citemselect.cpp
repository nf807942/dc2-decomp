/* CItemSelect
 *
 * Unité découpée par `make carve` : 56 fonctions, 12288 octets, de
 * 0x00251520 à 0x00254660. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

INCLUDE_ASM("nonmatchings/game/citemselect", MenuItemDraw__Fv);
INCLUDE_ASM("nonmatchings/game/citemselect", SetPtrList__11CItemSelectFv);
INCLUDE_ASM("nonmatchings/game/citemselect", GetExistThisPosData__11CItemSelectFi);
INCLUDE_ASM("nonmatchings/game/citemselect", CheckUse__11CItemSelectFP13CGameDataUsed);
INCLUDE_ASM("nonmatchings/game/citemselect", KeyStep__11CItemSelectFv);
INCLUDE_ASM("nonmatchings/game/citemselect", Draw__11CItemSelectFv);
INCLUDE_ASM("nonmatchings/game/citemselect", MenuItemSelectInit__FP9mgCMemoryPii);
struct CItemSelect;
extern "C" CItemSelect *ItemSelectPtr;
struct CItemSelect {
    s16 field_0;
    char pad_2[0x1A];
    s32 field_1C;
    char pad_20[0xF0];
    s32 field_110;
    char pad_114[0x2EE];
    s16 field_402;
    s32 field_404;
    s32 field_408;
    char pad_40C[0x8];
    f32 field_414;
    char pad_418[0x8];
    f32 field_420;
    f32 field_424;
    f32 field_428;
    f32 field_42C;
    f32 field_430;
    f32 field_434;
    f32 field_438;
    char pad_43C[0x4];
    s32 field_440;
    s32 field_444;
    f32 field_448;
};
extern "C" s32 KeyStep__11CItemSelectFv(void *);
extern "C" s32 MenuItemSelectKey__Fv(void) {
    s32 var_v0;

    var_v0 = 1;
    if (ItemSelectPtr != NULL) {
        var_v0 = KeyStep__11CItemSelectFv(ItemSelectPtr);
    }
    return var_v0;
}
INCLUDE_ASM("nonmatchings/game/citemselect", MenuItemSelectDraw__Fv);
INCLUDE_ASM("nonmatchings/game/citemselect", GetRandI__Fi);
extern "C" float mgRnd__Fv(void);
extern "C" float GetRandF__Ff(float arg0) { return arg0 * mgRnd__Fv(); }
INCLUDE_ASM("nonmatchings/game/citemselect", ReCalcBox__FP9mgVu0FBOX9mgVu0FBOX);
INCLUDE_ASM("nonmatchings/game/citemselect", MenuAdjustPolygonScale__FP8mgCFramef);
INCLUDE_ASM("nonmatchings/game/citemselect", MenuAdjustPolygonScale__F9mgVu0FBOXf);
INCLUDE_ASM("nonmatchings/game/citemselect", MenuAdjustPolygonScale__FP11CCharacter2f);
INCLUDE_ASM("nonmatchings/game/citemselect", AddRotationCharaY__FP11CCharacter2f);
extern "C" u32 SystemSND_ID;
extern "C" s32 MenuSePlay__FUii(u32, s32);
extern "C" void MenuSePlay__Fi(s32 arg0) {
    if (arg0 >= 0) {
        MenuSePlay__FUii(SystemSND_ID, arg0);
    }
}
extern "C" int sndSePlay__FUiii(unsigned int, int, int);
extern "C" int MenuSePlay__FUii(unsigned int arg0, int arg1) {
    if (arg1 >= 0) sndSePlay__FUiii(arg0, arg1, 0);
}
INCLUDE_ASM("nonmatchings/game/citemselect", MenuSePlay__FiPUiP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/citemselect", StopEnvSoundMenu__Fi);
INCLUDE_ASM("nonmatchings/game/citemselect", ReStartEnvSoundMenu__Fv);
INCLUDE_ASM("nonmatchings/game/citemselect", CompGameData__Fii);
INCLUDE_ASM("nonmatchings/game/citemselect", SeitonItemBoardSub__FP13CGameDataUsedi);
INCLUDE_ASM("nonmatchings/game/citemselect", MenuSeiton__FP13CGameDataUsedi);
INCLUDE_ASM("nonmatchings/game/citemselect", GetSameAdrressUserData__FP13CGameDataUsedi);
INCLUDE_ASM("nonmatchings/game/citemselect", local_sort1__FRiPiPi);
INCLUDE_ASM("nonmatchings/game/citemselect", GetNowChapter__FP9CSaveData);
extern "C" s32 MenuCalcBufAlignment__FP1(s32 arg0) {
    s32 var_v0;
    s32 var_v0_2;

    var_v0 = arg0;
    if ((arg0 % 64) != 0) {
        var_v0_2 = arg0 >> 6;
        if (arg0 < 0) {
            var_v0_2 = (s32) (arg0 + 0x3F) >> 6;
        }
        var_v0 = (var_v0_2 + 1) << 6;
    }
    return var_v0;
}
INCLUDE_ASM("nonmatchings/game/citemselect", LoadFileMenu__FPcP1i);
INCLUDE_ASM("nonmatchings/game/citemselect", ConvertFontCode__FPcPc);
INCLUDE_ASM("nonmatchings/game/citemselect", CheckNowEurope__Fv);
INCLUDE_ASM("nonmatchings/game/citemselect", MenuCommonReadData__FP9mgCMemoryPPci);
INCLUDE_ASM("nonmatchings/game/citemselect", MenuDeleteTextureBlock__FPi);
INCLUDE_ASM("nonmatchings/game/citemselect", MenuWorkTextureEnter__FiPciii);
INCLUDE_ASM("nonmatchings/game/citemselect", MenuEnterIMG__FiPUcPc);
extern "C" int GetCurrentDir__FPc(char *);
extern "C" int GetReadBGFile__FPc(char *);
extern "C" char *strcat(char *, const char *);
extern "C" void GetReadBGInfo__FPc(signed char *arg0) {
    signed char sp20[0x80];
    GetCurrentDir__FPc((char *)sp20);
    strcat((char *)sp20, (char *)arg0);
    GetReadBGFile__FPc((char *)sp20);
}
INCLUDE_ASM("nonmatchings/game/citemselect", CalcMenu1__FfPfffi);
INCLUDE_ASM("nonmatchings/game/citemselect", CalcMenu1__FiPiiii);
INCLUDE_ASM("nonmatchings/game/citemselect", CalcMenuAdd__FPiii);
INCLUDE_ASM("nonmatchings/game/citemselect", CalcMenuAdd__FPfff);
extern "C" s32 CalcMenuAdd2__FPiii(s32 *arg0, s32 arg1, s32 arg2) {
    if (arg0 == NULL) {
        return -1;
    }
    if ((arg1 < 0) && ((*arg0 + arg1) < arg2)) {
        return 1;
    }
    if ((arg1 > 0) && (arg2 < (*arg0 + arg1))) {
        return 1;
    }
    *arg0 += arg1;
    return 0;
}
INCLUDE_ASM("nonmatchings/game/citemselect", GetNumberKeta__Fi);
extern "C" s32 fptosi(...);
extern "C" s32 GetDispVolumeForFloat__Ff(f32 arg0) {
    s32 temp_v0;

    temp_v0 = fptosi();
    if ((arg0 - (f32) temp_v0) < 0.00005f) {
        return temp_v0;
    }
    return temp_v0 + 1;
}
extern "C" f32 GetFloatCommaValue__Ff(f32 arg0) {
    return arg0 - (f32) fptosi();
}
INCLUDE_ASM("nonmatchings/game/citemselect", CalcScrlBarPutPos__Fifif);
INCLUDE_ASM("nonmatchings/game/citemselect", Trans3DPosTo2DPos__FP9mgCCameraP8mgCFramePi);
INCLUDE_ASM("nonmatchings/game/citemselect", _ETCINFO_MALLOC__FP9SPI_STACKi);
extern "C" u16 Menu_Target_No;
extern "C" u16 Menu_Target_No_local;
struct SPI_STACK {
    s32 field_0;
    s32 field_4;
};
extern "C" s32 spiGetStackInt__FP9SPI_STACK(SPI_STACK *);
extern "C" s32 _MENU_ETCINFO_OFFSET__FP9SPI_STACKi(SPI_STACK *arg0, s32 arg1) {
    Menu_Target_No = spiGetStackInt__FP9SPI_STACK(arg0);
    Menu_Target_No_local = 0;
    return 1;
}
INCLUDE_ASM("nonmatchings/game/citemselect", _MENU_ETCINFO__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/citemselect", _MENU_ETCINFO_CLEAR__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/citemselect", _ETCINFO2_MALLOC__FP9SPI_STACKi);
extern "C" s32 _MENU_ETCINFO2_OFFSET__FP9SPI_STACKi(SPI_STACK *arg0, s32 arg1) {
    Menu_Target_No = spiGetStackInt__FP9SPI_STACK(arg0);
    Menu_Target_No_local = 0;
    return 1;
}
INCLUDE_ASM("nonmatchings/game/citemselect", _MENU_ETCINFO2__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/citemselect", _MENU_ETCINFO2_CLEAR__FP9SPI_STACKi);
struct CPosDataManage;
extern "C" CPosDataManage *MenuPosData;
struct CPosDataManage {
    char pad_0[0x4];
    u16 field_4;
    char pad_6[0x6];
    u16 field_C;
    char pad_E[0x2];
    s32 field_10;
    u16 field_14;
    char pad_16[0x2];
    s32 field_18;
    u16 field_1C;
    u8 field_1E;
    char pad_1F[0x39];
    s32 field_58;
};
extern "C" s32 ResetTextureInfoAll__14CPosDataManageFv(void *);
extern "C" s32 _MENU_RESET_TEXINFO__FP9SPI_STACKi(SPI_STACK *arg0, s32 arg1) {
    ResetTextureInfoAll__14CPosDataManageFv(MenuPosData);
    return 1;
}
extern "C" s32 InitDrawList__14CPosDataManageFv(void *);
extern "C" s32 _MENU_INIT_DRAWLIST__FP9SPI_STACKi(SPI_STACK *arg0, s32 arg1) {
    InitDrawList__14CPosDataManageFv(MenuPosData);
    return 1;
}
