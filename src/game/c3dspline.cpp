/* C3DSpline, CCameraPas, CCharaPas
 *
 * Unité découpée par `make carve` : 143 fonctions, 23780 octets, de
 * 0x00254660 à 0x0025A670. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"
#include "gen/EdEventInfoData.hpp"
#include "gen/SPLINE_KEY.hpp"
#include "gen/CCameraPas.hpp"
#include "gen/CCharaPas.hpp"

/* La pile de l'interpréteur de script d'objet. Les commandes qui ne rendent
 * qu'un code de retour ne la déréférencent pas : sa disposition reste à
 * établir. */
struct SPI_STACK;
extern EdEventInfoData EdEventInfo;


INCLUDE_ASM("nonmatchings/game/c3dspline", _MENU_TEXDATA_CLEAR__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/c3dspline", _MENU_FORM_CLEAR__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/c3dspline", _MENU_TEXDATA_MALLOC__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/c3dspline", _MENU_TEXNAME__FP9SPI_STACKi);
extern "C" u16 MenuTexPosNo;
extern "C" u16 MenuTexPosNo_local;
extern "C" s32 spiGetStackInt__FP9SPI_STACK(...);
extern "C" s32 _MENU_TEXDATA_OFFSET__FP9SPI_STACKi(SPI_STACK *arg0, s32 arg1) {
    MenuTexPosNo = spiGetStackInt__FP9SPI_STACK(arg0);
    MenuTexPosNo_local = 0;
    return 1;
}
INCLUDE_ASM("nonmatchings/game/c3dspline", _MENU_TEXDATA__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/c3dspline", _MENU_FORM_MALLOC__FP9SPI_STACKi);
extern "C" u16 menu_analyze_formno;
extern "C" u16 menu_analyze_formno_offset;
extern "C" s32 _MENU_FORM_OFFSET_NO__FP9SPI_STACKi(SPI_STACK *arg0, s32 arg1) {
    menu_analyze_formno = spiGetStackInt__FP9SPI_STACK(arg0);
    menu_analyze_formno_offset = 0;
    return 1;
}
INCLUDE_ASM("nonmatchings/game/c3dspline", _MENU_FORM_SET__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/c3dspline", _MENU_FORM_PARTNUM__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/c3dspline", menu_texdata_to_formpart_copy__FP18MENUFORMPARTS_TYPE);
INCLUDE_ASM("nonmatchings/game/c3dspline", menu_spi_analyze_func_strcut1__FP24MENU_SPI_ANALYZE_STRUCT1Pc);
INCLUDE_ASM("nonmatchings/game/c3dspline", menu_dtype_init__FP16CMenuPosDataFormP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/c3dspline", _MENU_FORM_DTYPE__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/c3dspline", _MENU_FORM_MTYPE__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/c3dspline", _MENU_FORM_DRAWFLG__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/c3dspline", _MENU_FORM_VIBECNT__FP9SPI_STACKi);
s32 _MENU_FORM_SETEND(SPI_STACK *stack, int argc) {
    return 1;
}
INCLUDE_ASM("nonmatchings/game/c3dspline", _MENU_FORM_MOVERATE__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/c3dspline", _MENU_FORM_PUTXY__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/c3dspline", _MENU_FORM_RGBA__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/c3dspline", _MENU_FORM_RGBA_BIT__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/c3dspline", _MENU_ACTION_TABLE_NUM__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/c3dspline", _MENU_ACTION_DEF__FP9SPI_STACKi);
extern "C" u32 menu_formPt;
extern "C" s32 spiGetStackString__FP9SPI_STACK(...);
struct SPI_STACK_bdf4f5 {
    s32 field_0;
    s32 field_4;
};
extern "C" s32 SetAction__16CMenuPosDataFormFPc(...);
extern "C" s32 _MENU_ACTION_SETACTION__FP9SPI_STACKi(SPI_STACK_bdf4f5 *arg0, s32 arg1) {
    if (menu_formPt == NULL) {
        return 0;
    }
    SetAction__16CMenuPosDataFormFPc(menu_formPt, spiGetStackString__FP9SPI_STACK(arg0));
    return 1;
}
INCLUDE_ASM("nonmatchings/game/c3dspline", _MENU_PARTVIBECNT__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/c3dspline", _MENU_PARTVIBER__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/c3dspline", _MENU_SHADOW_ONOFF__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/c3dspline", _CLIP_WH__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/c3dspline", _MENU_PARTRGBA__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/c3dspline", _MENU_PART_ALPHA_BLEND__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/c3dspline", _MENU_PART_ETCINFO__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/c3dspline", _MENU_PART_BILINEAR__FP9SPI_STACKi);
extern "C" u32 MenuSpiStack;
struct SPI_STACK_e9481d {
    s32 field_0;
    s32 field_4;
};
struct inferred;
#include "menu.hpp"
struct MENUFORMPARTS_TYPE;
typedef struct MENUFORMPARTS_TYPE {
    /* 0x0 */ s32 unk0;                             /* inferred */
} MENUFORMPARTS_TYPE;                               /* size >= 0x4 */
struct arg1_champs_e9481d {
    /* 0x0 */ s32 unk0;
};
extern "C" s32 mgCopyString__FPcP9mgCMemory(...);
extern "C" void MakePartsName__FP9SPI_STACKP18MENUFORMPARTS_TYPE(SPI_STACK_e9481d *arg0, MENUFORMPARTS_TYPE *arg1) {
    ((struct arg1_champs_e9481d *) arg1)->unk0 = mgCopyString__FPcP9mgCMemory(spiGetStackString__FP9SPI_STACK(arg0), MenuSpiStack);
}
INCLUDE_ASM("nonmatchings/game/c3dspline", _MENU_PART_DTYPE__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/c3dspline", _MENU_NORMAL__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/c3dspline", _MENU_NORMAL2__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/c3dspline", _MENU_CURSOR__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/c3dspline", _MENU_FUNCINFO__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/c3dspline", _MENU_NUMBER1__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/c3dspline", _MENU_NUMBER2__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/c3dspline", _MENU_FRMIMG__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/c3dspline", _MENU_FORM__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/c3dspline", _MENU_ITEM__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/c3dspline", _MENU_ITEM_CHECKMARK__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/c3dspline", _MENU_FILLBOX__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/c3dspline", _MENU_FILLBOXINFO__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/c3dspline", _MENU_WAKU_RECT__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/c3dspline", _MENU_WAKU_CIRCLE__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/c3dspline", _MENU_PARTS_EFF_NUM__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/c3dspline", _MENU_PARTS_EFFECT__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/c3dspline", MenuDataAnalyze__FPciP9mgCMemory);
extern "C" u8 MenuCommandAnalyzeInfo[104];
extern "C" u8 SpiMenuExeCommandFlag;
extern "C" s32 spiGetStackString__FP9SPI_STACK(...);
extern "C" s32 strcmp(...);
extern "C" s32 _MENU_EXE_COMMAND_NAME__FP9SPI_STACKi(SPI_STACK *arg0, s32 arg1) {
    s32 temp_a1;

    temp_a1 = spiGetStackString__FP9SPI_STACK(arg0);
    SpiMenuExeCommandFlag = 0;
    if (strcmp(&MenuCommandAnalyzeInfo, temp_a1) == 0) {
        SpiMenuExeCommandFlag = 1;
    }
    return 1;
}
INCLUDE_ASM("nonmatchings/game/c3dspline", _MENU_EXE_FORM_DRAWFLAG__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/c3dspline", _MENU_EXE_FORM_RGBA__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/c3dspline", _MENU_EXE_FORM_CALCRGBAPARAM__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/c3dspline", _MENU_EXE_FORM_FADE__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/c3dspline", _MENU_EXE_FORM_SETPOS__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/c3dspline", _MENU_EXE_FORM_SETACTION__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/c3dspline", _MENU_EXE_FORM_PARTSONOFF__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/c3dspline", _MENU_EXE_FORM_PARTSONOFF_GRP__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/c3dspline", _MENU_EXE_FORM_SWAP__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/c3dspline", _MENU_EXE_FORM_GROUP_SWAP__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/c3dspline", _MENU_EXE_MSGENV__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/c3dspline", _MENU_EXE_MAKEMSG__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/c3dspline", _MENU_EXE_SETABSPOS__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/c3dspline", _MENU_EXE_MSGSETSYSTEMBUFF__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/c3dspline", _MENU_EXE_MSGSETBUFF__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/c3dspline", _MENU_EXE_MSGSETFUCHI__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/c3dspline", _MENU_EXE_MSGSETCURSOR__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/c3dspline", _MENU_SET_QUESTIONGYOU__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/c3dspline", _MENU_SET_OPENSPEED__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/c3dspline", _MENU_INPUT_KEY__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/c3dspline", _MENU_CURSOR_ONOFF__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/c3dspline", _MENU_CURSOR_FADE__FP9SPI_STACKi);
extern "C" u8 SpiMenuExeCommandFlag;
#include "menu.hpp"
struct SPI_STACK {
    s32 field_0;
    s32 field_4;
};
extern "C" void SetWakuType__12CMenuKeyFuncFi(...);
extern "C" s32 spiGetStackInt__FP9SPI_STACK(...);
extern "C" s32 _MENU_WAKUTYPE__FP9SPI_STACKi(SPI_STACK *arg0, s32 arg1) {
    if (SpiMenuExeCommandFlag == 0) {
        return 1;
    }
    SetWakuType__12CMenuKeyFuncFi(MenuCommonInfo, spiGetStackInt__FP9SPI_STACK(arg0));
    return 1;
}
INCLUDE_ASM("nonmatchings/game/c3dspline", _MENU_SCENE_FADE__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/c3dspline", _MENU_SE_PLAY__FP9SPI_STACKi);
extern "C" void InitDrawList__14CPosDataManageFv(...);
extern "C" s32 _MENU_EXE_INIT_DRAWLIST__FP9SPI_STACKi(SPI_STACK *arg0, s32 arg1) {
    if (SpiMenuExeCommandFlag == 0) {
        return 1;
    }
    InitDrawList__14CPosDataManageFv(MenuPosData);
    return 1;
}
extern "C" void ResetTextureInfoAll__14CPosDataManageFv(...);
extern "C" s32 _MENU_EXE_RESET_TEXINFO__FP9SPI_STACKi(SPI_STACK *arg0, s32 arg1) {
    if (SpiMenuExeCommandFlag == 0) {
        return 1;
    }
    ResetTextureInfoAll__14CPosDataManageFv(MenuPosData);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/c3dspline", _MENU_DEBUG_PRINTF__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/c3dspline", MenuCommandAnalyze__FPciPc);
INCLUDE_ASM("nonmatchings/game/c3dspline", LoadNpcTalkMes__FP9mgCMemory);
void ResetNpcTalkMes(void) {
    EdEventInfo.field_0x126C = 0;
    EdEventInfo.field_0x1270 = 0;
}
extern "C" s32 GetSaveData__Fv(void);
#include "dngfloormanager.hpp"
extern "C" s32 CheckNowTourEvent__9CSaveDataFv(void *);
extern "C" s32 CheckNowTourType__9CSaveDataFv(void *);
extern "C" s32 GetSquareEvent__Fv(void) {
    CSaveData *temp_v0;

    temp_v0 = (CSaveData *) (GetSaveData__Fv());
    if (temp_v0 == NULL) {
        return 0;
    }
    if (CheckNowTourEvent__9CSaveDataFv(temp_v0) == 0) {
        return 0;
    }
    return CheckNowTourType__9CSaveDataFv(temp_v0);
}
INCLUDE_ASM("nonmatchings/game/c3dspline", InitEvent__FP6CScene);
INCLUDE_ASM("nonmatchings/game/c3dspline", SetEventScript__FPcPcP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/c3dspline", RunEvent__FiP6CScene);
INCLUDE_ASM("nonmatchings/game/c3dspline", EventDoorLoop__Fii);
INCLUDE_ASM("nonmatchings/game/c3dspline", StartEventSyori__Fv);
INCLUDE_ASM("nonmatchings/game/c3dspline", SkipEventStart__Fv);
INCLUDE_ASM("nonmatchings/game/c3dspline", SkipEvent__Fv);
INCLUDE_ASM("nonmatchings/game/c3dspline", CheckEventSkip__Fv);
INCLUDE_ASM("nonmatchings/game/c3dspline", EventLoop__Fv);
struct CScene;
extern "C" CScene *EventScene;
struct CScene {
    s32 field_0;
    s32 field_4;
    char pad_8[0x30];
    s32 field_38;
    s32 field_3C;
    s32 field_40;
    char pad_44[0x2000];
    s32 field_2044;
    char pad_2048[0x1C0];
    s32 field_2208;
    char pad_220C[0x5D4];
    s32 field_27E0;
    char pad_27E4[0xE0];
    s32 field_28C4;
    char pad_28C8[0xE0];
    s32 field_29A8;
    char pad_29AC[0x100];
    s32 field_2AAC;
    char pad_2AB0[0x1EC];
    s32 field_2C9C;
    s32 field_2CA0;
    char pad_2CA4[0x1A0];
    s32 field_2E44;
    s32 field_2E48;
    char pad_2E4C[0x4];
    s32 field_2E50;
    s32 field_2E54;
    s32 field_2E58;
    s32 field_2E5C;
    s32 field_2E60;
    s32 field_2E64;
    s32 field_2E68;
    s32 field_2E6C;
    s32 field_2E70;
    s32 field_2E74;
    s32 field_2E78;
    s32 field_2E7C;
    s32 field_2E80;
    s32 field_2E84;
    s32 field_2E88;
    s32 field_2E8C;
    char pad_2E90[0x8];
    s32 field_2E98;
    char pad_2E9C[0x8];
    s32 field_2EA4;
    f32 field_2EA8;
    f32 field_2EAC;
    f32 field_2EB0;
    f32 field_2EB4;
    char pad_2EB8[0x8];
    f32 field_2EC0;
    f32 field_2EC4;
    f32 field_2EC8;
    f32 field_2ECC;
    f32 field_2ED0;
    f32 field_2ED4;
    f32 field_2ED8;
    f32 field_2EDC;
    f32 field_2EE0;
    f32 field_2EE4;
    f32 field_2EE8;
    f32 field_2EEC;
    char pad_2EF0[0x38];
    f32 field_2F28;
    char pad_2F2C[0x8];
    f32 field_2F34;
    f32 field_2F38;
    char pad_2F3C[0x14];
    s32 field_2F50;
    s32 field_2F54;
    s32 field_2F58;
    s32 field_2F5C;
    s32 field_2F60;
    s32 field_2F64;
    s32 field_2F68;
    f32 field_2F6C;
    f32 field_2F70;
    s32 field_2F74;
    f32 field_2F78;
    char pad_2F7C[0x4];
    f32 field_2F80;
    char pad_2F84[0x10];
    s32 field_2F94;
    s32 field_2F98;
    s16 field_2F9C;
    char pad_2F9E[0x2];
    s32 field_2FA0;
    char pad_2FA4[0x10];
    s8 field_2FB4;
    char pad_2FB5[0x1F];
    s16 field_2FD4;
    s16 field_2FD6;
    s8 field_2FD8;
    s8 field_2FD9;
    char pad_2FDA[0x6];
    f32 field_2FE0;
    s32 field_2FE4;
    s32 field_2FE8;
    s32 field_2FEC;
    char pad_2FF0[0x4];
    s32 field_2FF4;
    char pad_2FF8[0x4];
    s32 field_2FFC;
    char pad_3000[0x8];
    s16 field_3008;
    char pad_300A[0x2];
    s32 field_300C;
    s32 field_3010;
    s32 field_3014;
    s32 field_3018;
    s8 field_301C;
    char pad_301D[0x3];
    s64 field_3020;
    s32 field_3028;
    s8 field_302C;
    char pad_302D[0x1];
    s16 field_302E;
    s32 field_3030;
    char pad_3034[0x4];
    s32 field_3038;
    s32 field_303C;
    char pad_3040[0x14];
    s32 field_3054;
    char pad_3058[0xE08];
    s32 field_3E60;
    s32 field_3E64;
    s32 field_3E68;
    s32 field_3E6C;
    char pad_3E70[0x1F0];
    s32 field_4060;
    char pad_4064[0x4800];
    u32 field_8864;
    char pad_8868[0x800];
    s32 field_9068;
    char pad_906C[0x4];
    s32 field_9070;
    s32 field_9074;
    char pad_9078[0x8];
    s32 field_9080;
    char pad_9084[0x45C];
    s32 field_94E0;
    char pad_94E4[0x45C];
    s32 field_9940;
    char pad_9944[0x4BC];
    s32 field_9E00;
    s32 field_9E04;
    char pad_9E08[0x80];
    s32 field_9E88;
    s32 field_9E8C;
    char pad_9E90[0x80];
    s32 field_9F10;
    s32 field_9F14;
    char pad_9F18[0x80];
    s32 field_9F98;
    s32 field_9F9C;
    char pad_9FA0[0x80];
    s32 field_A020;
    s32 field_A024;
    s32 field_A028;
    s32 field_A02C;
    s32 field_A030;
    s32 field_A034;
    s32 field_A038;
    s32 field_A03C;
    u32 field_A040;
    s32 field_A044;
    char pad_A048[0x424];
    s32 field_A46C;
    char pad_A470[0x4];
    s32 field_A474;
    char pad_A478[0x8];
    s32 field_A480;
    s32 field_A484;
    f32 field_A488;
    f32 field_A48C;
    s32 field_A490;
    s32 field_A494;
    s32 field_A498;
    s32 field_A49C;
    char pad_A4A0[0x2030];
    u32 field_C4D0;
    s32 field_C4D4;
};
extern "C" s32 GetMessage__6CSceneFi(void *, s32);
extern "C" s32 GetEventMessage__Fi(s32 arg0) {
    s32 var_v0;

    var_v0 = 0;
    if (EventScene != NULL) {
        var_v0 = GetMessage__6CSceneFi(EventScene, arg0);
    }
    return var_v0;
}
struct inferred;
struct CScene_infere;
typedef struct CScene_infere {
    /* 0x0000 */ char pad0[0x2E54];
    /* 0x2E54 */ s32 unk2E54;                       /* inferred */
} CScene_infere;                                           /* size >= 0x2E58 */
struct EventScene_champs_55c73b {
    char pad0[0x2E54];
    /* 0x2E54 */ s32 unk2E54;
};
extern "C" s32 GetCamera__6CSceneFi(void *, s32);
extern "C" s32 GetActiveCamera__Fv(void) {
    s32 var_v0;

    var_v0 = 0;
    if (EventScene != NULL) {
        var_v0 = GetCamera__6CSceneFi(EventScene, ((struct EventScene_champs_55c73b *) EventScene)->unk2E54);
    }
    return var_v0;
}
extern "C" s32 GetCharacter__6CSceneFi(void *, s32);
extern "C" s32 GetCharacter__Fi(s32 arg0) {
    s32 var_v0;

    var_v0 = 0;
    if (EventScene != NULL) {
        var_v0 = GetCharacter__6CSceneFi(EventScene, arg0);
    }
    return var_v0;
}
void InitSplineKey(SPLINE_KEY * arg0) {
    arg0->field_0x0 = 0;
    arg0->field_0x4 = 0;
    arg0->field_0x8 = 0;
    arg0->field_0x14 = 0;
    arg0->field_0x20 = 0;
    arg0->field_0x2C = 0;
    arg0->field_0xC = 0;
    arg0->field_0x18 = 0;
    arg0->field_0x24 = 0;
    arg0->field_0x30 = 0;
    arg0->field_0x10 = 0;
    arg0->field_0x1C = 0;
    arg0->field_0x28 = 0;
    arg0->field_0x34 = 0;
}
struct C3DSpline {
    char pad_0[0x380];
    s32 field_380;
    s32 field_384;
    f32 field_388;
    f32 field_38C;
    f32 field_390;
    f32 field_394;
    f32 field_398;
};
extern "C" s32 Initialize__9C3DSplineFv(void *);
extern "C" C3DSpline *__ct__9C3DSplineFv(C3DSpline *objet) {
    Initialize__9C3DSplineFv(objet);
    return objet;
}
INCLUDE_ASM("nonmatchings/game/c3dspline", Initialize__9C3DSplineFv);
INCLUDE_ASM("nonmatchings/game/c3dspline", SetUpSpline__9C3DSplineFPA4_fPiif);
INCLUDE_ASM("nonmatchings/game/c3dspline", StepS__9C3DSplineFv);
INCLUDE_ASM("nonmatchings/game/c3dspline", Step__9C3DSplineFv);
INCLUDE_ASM("nonmatchings/game/c3dspline", GetNowXYZ__9C3DSplineFPf);
INCLUDE_ASM("nonmatchings/game/c3dspline", __ct__10CCameraPasFv);
INCLUDE_ASM("nonmatchings/game/c3dspline", AddCameraPas__10CCameraPasFPfPf);
INCLUDE_ASM("nonmatchings/game/c3dspline", InsCameraPas__10CCameraPasFiPfPf);
INCLUDE_ASM("nonmatchings/game/c3dspline", SetCameraPas__10CCameraPasFiPfPf);
INCLUDE_ASM("nonmatchings/game/c3dspline", GetCameraPas__10CCameraPasFiPfPf);
INCLUDE_ASM("nonmatchings/game/c3dspline", DelCameraPas__10CCameraPasFi);
s32 CCameraPas::SetFrame(s32 arg0) {
    this->field_0x204 = arg0;
    return 0;
}
s32 CCameraPas::GetFrame(void) {
    return this->field_0x204;
}
INCLUDE_ASM("nonmatchings/game/c3dspline", Initialize__10CCameraPasFv);
INCLUDE_ASM("nonmatchings/game/c3dspline", Setup__10CCameraPasFv);
void CCameraPas::Run(void) {
    this->field_0x940 = 1;
}
INCLUDE_ASM("nonmatchings/game/c3dspline", Step__10CCameraPasFPfPf);
INCLUDE_ASM("nonmatchings/game/c3dspline", CheckEnd__10CCameraPasFv);
struct inferred;
typedef struct CCharaPas_infere {
    /* 0x000 */ char pad0[0x108];
    /* 0x108 */ C3DSpline unk108;                   /* inferred */
    /* 0x108 */ char pad108[1];
} CCharaPas_infere;                                        /* size >= 0x109 */
extern "C" s32 Initialize__9CCharaPasFv(void *);
extern "C" CCharaPas_infere *__ct__9CCharaPasFv(CCharaPas_infere *objet) {
    __ct__9C3DSplineFv(&objet->unk108);
    Initialize__9CCharaPasFv(objet);
    return objet;
}
INCLUDE_ASM("nonmatchings/game/c3dspline", Initialize__9CCharaPasFv);
INCLUDE_ASM("nonmatchings/game/c3dspline", AddCharaPas__9CCharaPasFPf);
INCLUDE_ASM("nonmatchings/game/c3dspline", Setup__9CCharaPasFv);
INCLUDE_ASM("nonmatchings/game/c3dspline", Run__9CCharaPasFv);
INCLUDE_ASM("nonmatchings/game/c3dspline", Step__9CCharaPasFPfPf);
INCLUDE_ASM("nonmatchings/game/c3dspline", CheckEnd__9CCharaPasFv);
INCLUDE_ASM("nonmatchings/game/c3dspline", InsCharaPas__9CCharaPasFiPf);
INCLUDE_ASM("nonmatchings/game/c3dspline", SetCharaPas__9CCharaPasFiPf);
INCLUDE_ASM("nonmatchings/game/c3dspline", GetCharaPas__9CCharaPasFiPf);
INCLUDE_ASM("nonmatchings/game/c3dspline", DelCharaPas__9CCharaPasFi);
void CCharaPas::SetFrame(s32 arg0) {
    this->field_0x100 = arg0;
}
s32 CCharaPas::GetFrame(void) {
    return this->field_0x100;
}
struct inferred;
typedef struct CSceneCmrSeq_infere {
    /* 0x00 */ char pad0[0x38];
    /* 0x38 */ s32 unk38;                           /* inferred */
} CSceneCmrSeq_infere;                                     /* size >= 0x3C */
typedef struct _SEN_CMR_SEQ_infere {
    /* 0x00 */ char pad0[0x30];
    /* 0x30 */ s32 unk30;                           /* inferred */
} _SEN_CMR_SEQ_infere;                                     /* size >= 0x34 */
extern "C" s32 scsPRDelay__FP12_SEN_CMR_SEQP12CSceneCmrSeq(_SEN_CMR_SEQ_infere *arg0, CSceneCmrSeq_infere *arg1) {
    s32 temp_v1;

    temp_v1 = arg1->unk38;
    if (temp_v1 >= arg0->unk30) {
        arg1->unk38 = 0;
        return 0;
    }
    arg1->unk38 = temp_v1 + 1;
    return 1;
}
INCLUDE_ASM("nonmatchings/game/c3dspline", scsSetPos__FP12_SEN_CMR_SEQP12CSceneCmrSeq);
INCLUDE_ASM("nonmatchings/game/c3dspline", scsSetRef__FP12_SEN_CMR_SEQP12CSceneCmrSeq);
struct inferred;
typedef struct CSceneCmrSeq_infere2 {
    /* 0x00 */ char pad0[0x3C];
    /* 0x3C */ s32 unk3C;                           /* inferred */
} CSceneCmrSeq_infere2;                                     /* size >= 0x40 */
typedef struct _SEN_CMR_SEQ_infere2 {
    /* 0x00 */ char pad0[0x30];
    /* 0x30 */ s32 unk30;                           /* inferred */
} _SEN_CMR_SEQ_infere2;                                     /* size >= 0x34 */
extern "C" s32 scsAHDDelay__FP12_SEN_CMR_SEQP12CSceneCmrSeq(_SEN_CMR_SEQ_infere2 *arg0, CSceneCmrSeq_infere2 *arg1) {
    s32 temp_v1;

    temp_v1 = arg1->unk3C;
    if (temp_v1 >= arg0->unk30) {
        arg1->unk3C = 0;
        return 0;
    }
    arg1->unk3C = temp_v1 + 1;
    return 1;
}
INCLUDE_ASM("nonmatchings/game/c3dspline", scsSetAngle__FP12_SEN_CMR_SEQP12CSceneCmrSeq);
typedef struct CSceneCmrSeq_infere3 {
    /* 0x00 */ char pad0[0x54];
    /* 0x54 */ f32 unk54;                           /* inferred */
    /* 0x58 */ char pad58[0xC];                     /* maybe part of unk54[4]void */
    /* 0x64 */ f32 unk64;                           /* inferred */
    /* 0x68 */ char pad68[0xC];                     /* maybe part of unk64[4]void */
    /* 0x74 */ f32 unk74;                           /* inferred */
} CSceneCmrSeq_infere3;                                     /* size >= 0x78 */
typedef struct _SEN_CMR_SEQ_infere3 {
    /* 0x00 */ char pad0[0x30];
    /* 0x30 */ f32 unk30;                           /* inferred */
} _SEN_CMR_SEQ_infere3;                                     /* size >= 0x34 */
extern "C" s32 scsSetHeight__FP12_SEN_CMR_SEQP12CSceneCmrSeq(_SEN_CMR_SEQ_infere3 *arg0, CSceneCmrSeq_infere3 *arg1) {
    arg1->unk54 = arg0->unk30 + arg1->unk64;
    arg1->unk74 = arg0->unk30;
    return 0;
}
INCLUDE_ASM("nonmatchings/game/c3dspline", scsSetDist__FP12_SEN_CMR_SEQP12CSceneCmrSeq);
typedef struct CSceneCmrSeq {
    /* 0x00 */ char pad0[0x50];
    /* 0x50 */ f32 unk50;                           /* inferred */
    /* 0x54 */ f32 unk54;                           /* inferred */
    /* 0x58 */ f32 unk58;                           /* inferred */
    /* 0x5C */ char pad5C[4];
    /* 0x60 */ f32 unk60;                           /* inferred */
    /* 0x64 */ f32 unk64;                           /* inferred */
    /* 0x68 */ f32 unk68;                           /* inferred */
    /* 0x6C */ char pad6C[4];
    /* 0x70 */ f32 unk70;                           /* inferred */
    /* 0x74 */ f32 unk74;                           /* inferred */
    /* 0x78 */ f32 unk78;                           /* inferred */
    /* 0x7C */ s32 unk7C;                           /* inferred */
    /* 0x80 */ char pad80[0x20];                    /* maybe part of unk7C[9]? */
    /* 0xA0 */ f32 unkA0;                           /* inferred */
    /* 0xA4 */ f32 unkA4;                           /* inferred */
    /* 0xA8 */ f32 unkA8;                           /* inferred */
} CSceneCmrSeq;                                     /* size >= 0xAC */
typedef struct _SEN_CMR_SEQ {
    /* 0x00 */ char pad0[0x10];
    /* 0x10 */ f32 unk10;                           /* inferred */
    /* 0x14 */ f32 unk14;                           /* inferred */
    /* 0x18 */ f32 unk18;                           /* inferred */
} _SEN_CMR_SEQ;                                     /* size >= 0x1C */
extern "C" f32 cosf(f32);
extern "C" f32 sinf(f32);
extern "C" s32 scsSetAHD__FP12_SEN_CMR_SEQP12CSceneCmrSeq(_SEN_CMR_SEQ *arg0, CSceneCmrSeq *arg1) {
    if (arg1->unk7C != 0) {
        arg1->unkA0 = arg0->unk10;
        arg1->unkA4 = arg0->unk14;
        arg1->unkA8 = arg0->unk18;
    } else {
        arg1->unk50 = arg1->unk60 + (arg0->unk18 * sinf(arg0->unk10));
        arg1->unk54 = arg0->unk14 + arg1->unk64;
        arg1->unk58 = arg1->unk68 + (arg0->unk18 * cosf(arg0->unk10));
        arg1->unk70 = arg0->unk10;
        arg1->unk74 = arg0->unk14;
        arg1->unk78 = arg0->unk18;
    }
    return 0;
}
INCLUDE_ASM("nonmatchings/game/c3dspline", scsMove__FP12_SEN_CMR_SEQP12CSceneCmrSeq);
INCLUDE_ASM("nonmatchings/game/c3dspline", scsMove2__FP12_SEN_CMR_SEQP12CSceneCmrSeq);
INCLUDE_ASM("nonmatchings/game/c3dspline", scsMoveRef__FP12_SEN_CMR_SEQP12CSceneCmrSeq);
INCLUDE_ASM("nonmatchings/game/c3dspline", scsMovePos__FP12_SEN_CMR_SEQP12CSceneCmrSeq);
INCLUDE_ASM("nonmatchings/game/c3dspline", scsMoveAHD__FP12_SEN_CMR_SEQP12CSceneCmrSeq);
