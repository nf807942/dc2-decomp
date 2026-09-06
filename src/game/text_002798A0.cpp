/* Fonctions libres — à décrire.
 *
 * Unité découpée par `make carve` : 178 fonctions, 24580 octets, de
 * 0x002798A0 à 0x0027FCE0. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"
#include "gen/GeoStoneData.hpp"

#include "runscript.hpp"
extern s32 SwordEffect;
struct RS_STACKDATA;

extern GeoStoneData GeoStone;


INCLUDE_ASM("nonmatchings/game/text_002798A0", _SPHIDA_SET_MINIMAP_FLAG__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _SPHIDA_SET_MM_LINE_FLAG__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _SPHIDA_SET_MM_LINE_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _SPHIDA_SET_PIN_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _SPHIDA_GET_PIN_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _SPHIDA_SET_BALL_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _SPHIDA_GET_BALL_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _SPHIDA_SET_PIN_COL__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _SPHIDA_GET_PIN_COL__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _SPHIDA_SET_BALL_COL__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _SPHIDA_GET_BALL_COL__FP12RS_STACKDATAi);
extern "C" u32 DebugFlag;
typedef struct Sphida_pointe {
    char pad0[184];
    s32 unkB8;
} Sphida_pointe;
extern "C" Sphida_pointe *Sphida;
extern "C" s32 GetStackInt__FP12RS_STACKDATA_00262DA0(...);
extern "C" s32 _SPHIDA_SET_PAR_COUNT__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    s32 temp_v0;

    temp_v0 = (s32) (GetStackInt__FP12RS_STACKDATA_00262DA0(arg0));
    if (Sphida == NULL) {
        return 0;
    }
    if (DebugFlag == 0) {
        Sphida->unkB8 = temp_v0;
    }
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_002798A0", _SPHIDA_GET_PAR_COUNT__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _SPHIDA_GET_MINI_LEVEL__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _SPHIDA_GET_TEXB__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _SPHIDA_SET_STATUS_FLAG__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _SPHIDA_RESET_POWGAGE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _SPHIDA_START_POWGAGE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _SPHIDA_TRIGGER_POWGAGE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _SPHIDA_GET_SHOT_POW__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _SPHIDA_GET_POWGAGE_CODE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _SPHIDA_SET_POWGAGE_SAFE_LEVEL__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _SPHIDA_GET_CULB_DEF__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _SPHIDA_SET_SPIN_MARK_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _SPHIDA_SET_CULB_NO__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _SPHIDA_CALC_CARRY__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _SPHIDA_GET_PG_CURSOR_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _SPHIDA_SET_COL_MODEL__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _SPHIDA_GET_PRIZE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _SPHIDA_SET_LAST_CHALLENGE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _SPHIDA_GET_LAST_CHALLENGE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _SPHIDA_GET_OMAKE_MODE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _SPHIDA_SET_NOW_HOLE__FP12RS_STACKDATAi);
extern "C" s32 GetSphidaData__12CSubGameDataFv(void *);
extern "C" s32 GetSubGameSaveData__Fv(void);
#include "gen/CSphidaData.hpp"
#include "gen/CSubGameData.hpp"
extern "C" s32 GetNowHorl__11CSphidaDataFv(void *);
extern "C" s32 SetStack__FP12RS_STACKDATAi_00262E70(...);
extern "C" s32 _SPHIDA_GET_NOW_HOLE__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    CSphidaData *temp_v0_2;
    CSubGameData *temp_v0;

    if (arg1 != 1) {
        return 0;
    }
    temp_v0 = (CSubGameData *) (GetSubGameSaveData__Fv());
    if (temp_v0 == NULL) {
        return 0;
    }
    temp_v0_2 = (CSphidaData *) (GetSphidaData__12CSubGameDataFv(temp_v0));
    if (temp_v0_2 == NULL) {
        return 0;
    }
    SetStack__FP12RS_STACKDATAi_00262E70(arg0, GetNowHorl__11CSphidaDataFv(temp_v0_2));
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_002798A0", _SPHIDA_SET_SCORE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _SPHIDA_GET_SCORE__FP12RS_STACKDATAi);
s32 _TEST(RS_STACKDATA *stack, int argc) {
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_002798A0", _MT_TEST__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _ZERO_VECTOR__FP12RS_STACKDATAi_0027A530);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _NORMAL_VECTOR__FP12RS_STACKDATAi_0027A570);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _COPY_VECTOR__FP12RS_STACKDATAi_0027A610);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _ADD_VECTOR__FP12RS_STACKDATAi_0027A670);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _SUB_VECTOR__FP12RS_STACKDATAi_0027A6E0);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _SCALE_VECTOR__FP12RS_STACKDATAi_0027A750);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _DIV_VECTOR__FP12RS_STACKDATAi_0027A7B0);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _DIST_VECTOR__FP12RS_STACKDATAi_0027A860);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _DIST_VECTOR2__FP12RS_STACKDATAi_0027A8B0);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _SQRT__FP12RS_STACKDATAi_0027A910);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _ATAN2F__FP12RS_STACKDATAi_0027A960);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _ANGLE_CMP__FP12RS_STACKDATAi_0027A9B0);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _ANGLE_LIMIT__FP12RS_STACKDATAi_0027AA10);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _GET_RAND__FP12RS_STACKDATAi_0027AA50);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _LINE_POINT_DIST__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _CREATE_SWORD_EFFECT__FP12RS_STACKDATAi);
s32 _DELETE_SWORD_EFFECT(RS_STACKDATA * arg0, s32 arg1) {
    SwordEffect = 0;
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_002798A0", _SWORD_EFFECT_COLOR__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _SWORD_EFFECT_ADD_POINT__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _ADD_CHARA_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _ADD_CHARA_ROT__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _POST_TREASURE_BOX__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _GET_PARTS_ORIGIN__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _CTRLC_STEP__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _CTRLC_SET_ROTATE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _CTRLC_ROT_BACK__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _CTRLC_MOVE_CAMERA__FP12RS_STACKDATAi);
extern "C" s32 GetCamera__Fv(void);
extern "C" s32 GetStackInt__FP12RS_STACKDATA_00262DA0(...);
extern "C" s32 SetRotCameraCancel__14CCameraControlFi(...);
extern "C" s32 _CTRLC_SET_ROT_CANCEL__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    s32 temp_s0;

    temp_s0 = (s32) (GetStackInt__FP12RS_STACKDATA_00262DA0(arg0));
    SetRotCameraCancel__14CCameraControlFi(GetCamera__Fv(), temp_s0);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_002798A0", _CTRLC_MOVE_RANGE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _GET_NEAR_TBOX_POS__FP12RS_STACKDATAi);
s32 _CONV_CHRNO_S2L(RS_STACKDATA *stack, int argc) {
    return 0;
}
INCLUDE_ASM("nonmatchings/game/text_002798A0", _SWE_INIT__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _SWE_SET_COLOR__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _SWE_SET_TEXTURE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _SWE_START_EFFECT__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _SET_CHARA_TYPE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _GET_EVENT_DATA__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _DNG_SET_PREV_FLOOR__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _DNG_GET_PREV_FLOOR__FP12RS_STACKDATAi);
s32 _DNG_SET_FAST_FLOOR(RS_STACKDATA *stack, int argc) {
    return 0;
}
INCLUDE_ASM("nonmatchings/game/text_002798A0", _SET_FLOOR_INFO__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _GET_FLOOR_INFO__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _GET_NEXT_FLOOR__FP12RS_STACKDATAi);
#include "gamepad.hpp"
extern "C" void AutoRepeatOff__8CGamePadFv(CGamePad *objet);
extern "C" s32 _PAD_AUTO_REPEAT_OFF__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    AutoRepeatOff__8CGamePadFv(&GamePad_003FA5A0);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_002798A0", _PAD_SET_AUTO_REPEAT__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _DNG_PAUSE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _DNG_CHECK_PAUSE__FP12RS_STACKDATAi);
extern "C" u32 EventScene;
struct temp_v0_champs {
    char pad0[0x10];
    /* 0x10 */ s32 unk10;
};
extern "C" s32 _DNG_RESET_TIMER__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    struct temp_v0_champs *temp_v0;

    temp_v0 = (struct temp_v0_champs *) (EventScene + 0x2F90);
    if (temp_v0 == NULL) {
        return 0;
    }
    temp_v0->unk10 = 0;
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_002798A0", _DNG_GET_TIMER__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _LOAD_SKIN__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _CHK_CAMERA_COL__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _GET_PARTS_FUNC_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _RANDOM_CIRCLE_GET_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _RANDOM_CIRCLE_OFF__FP12RS_STACKDATAi);
extern "C" void XChgMapLighting__Fv();
extern "C" s32 _DNG_XCHG_MAP_LIGHT__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    XChgMapLighting__Fv();
    return 1;
}
s32 _GEOSTONE_ANIME_OFF(RS_STACKDATA * arg0, s32 arg1) {
    GeoStone.field_0x668 = 0;
    return 1;
}
extern "C" s32 GetStackInt__FP12RS_STACKDATA_00262DA0(...);
extern "C" s32 SetFlag__9CGeoStoneFi(void *, s32);
extern "C" s32 _GEOSTONE_SET_FLAG__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    SetFlag__9CGeoStoneFi(&GeoStone, GetStackInt__FP12RS_STACKDATA_00262DA0(arg0));
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_002798A0", _GEOSTONE_SET_REFERENCE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _GEOSTONE_DEL_REFERENCE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _GET_ROBO_MOVE_TYPE__FP12RS_STACKDATAi);
struct EventScene_champs_d974f8 {
    char pad0[0x2F64];
    /* 0x2F64 */ s32 unk2F64;
};
extern "C" s32 _SET_EXIT_FLAG__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    ((struct EventScene_champs_d974f8 *) EventScene)->unk2F64 = GetStackInt__FP12RS_STACKDATA_00262DA0(arg0);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_002798A0", _GET_EXIT_FLAG__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _GET_E3_VERSION__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _CHK_PAD_CTRL__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _CTRLC_STAY__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _BSCN_SET_BLIGHT_RATE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _GET_RND_CIRCLE_TRAPID__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _SET_RND_CIRCLE_STATUS__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _SET_STATUSBAR_SHOW__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _SET_PULL_ITEM__FP12RS_STACKDATAi);
typedef struct EdEventInfo_champs {
    char pad0[208];
    s32 unkD0;
    char padD4[4556];
} EdEventInfo_champs;
extern "C" EdEventInfo_champs EdEventInfo;
typedef struct MenuArg_champs {
    char pad0[40];
    s32 unk28;
    char pad2C[108];
} MenuArg_champs;
extern "C" MenuArg_champs MenuArg;
extern "C" s32 _MENU_CHARA_CHENGE__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    GetStackInt__FP12RS_STACKDATA_00262DA0(arg0);
    MenuArg.unk28 = 0xE;
    EdEventInfo.unkD0 = 3;
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_002798A0", _GET_EVENT_INFO_SNDID__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _GET_PARTS_POS__FP12RS_STACKDATAi);
extern "C" void CancelDramaScene__Fv();
extern "C" s32 _CANCEL_DRAMA_SCENE__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    CancelDramaScene__Fv();
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_002798A0", _GET_RNDC_MOT_NOWT__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _SET_CHARA_MOT_NOWT__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _CHARA_NORMAL_DRIVE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _CHARA_RESET_DA__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _DNG_SETUP_MAIN_UNIT__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _JOIN_PARTY_MEMBER__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _SET_CHARA_CHANGE_FLAG__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _SET_CHARA_CHANGE_MASK__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _SET_CHARA_EQUIP__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _LOAD_PACK_FILE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _SET_BIT_CTRL__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _GET_BIT_CTRL__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _LOAD_ARG__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _GET_ITEM_HAVE_NUM__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _SET_SKIP_BOTTON__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _SET_SKIP_FCOL__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _GET_DEBUG_MODE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _GET_MAP_TYPE__FP12RS_STACKDATAi);
extern "C" u8 ColPrimMan[17424];
#include "sphida.hpp"
extern "C" s32 Initialize__11CColPrimManFP6CScene(void *, CScene *);
extern "C" s32 _DNG_COLLISION_ALL_CLR__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    Initialize__11CColPrimManFP6CScene(&ColPrimMan, DngMainScene);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_002798A0", _SET_MAP_DRAW__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _CHECK_MC_LOAD__FP12RS_STACKDATAi);
extern "C" s32 SetNowMapNo__6CSceneFi(...);
extern "C" s32 _SET_NOW_MAP_NO__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    SetNowMapNo__6CSceneFi(EventScene, GetStackInt__FP12RS_STACKDATA_00262DA0(arg0));
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_002798A0", _GET_TBOX_PARAM__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _CANCEL_LOAD_VILLAGER__FP12RS_STACKDATAi);
extern "C" void CancelNowLoading__Fv();
extern "C" s32 _CANCEL_NOW_LOADING__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    CancelNowLoading__Fv();
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_002798A0", _ESM_INITIALIZE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _ESM_INIT_FIX__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _ESM_CLEAR__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _ESM_LOAD_BASE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _ESM_CREATE__FP12RS_STACKDATAi_0027E3C0);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _ESM_FINISH__FP12RS_STACKDATAi_0027E4C0);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _ESM_DELETE__FP12RS_STACKDATAi_0027E520);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _ESM_SET_VECT1__FP12RS_STACKDATAi_0027E580);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _ESM_SET_VECT2__FP12RS_STACKDATAi_0027E640);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _ESM_SET_TARGET_ID__FP12RS_STACKDATAi_0027E700);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _ESM_LOAD_BASE_PACK__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _ESM_SET_VALUE__FP12RS_STACKDATAi_0027E840);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _SET_CHARA_CONDITION__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _ADD_WHP__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _ADD_HP_RATE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _GET_TIME__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _CHECK_GET_ITEM_LIMIT__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _CHECK_ITEM_OVER__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _GET_NOW_LOOP_NO__FP12RS_STACKDATAi);
extern "C" u32 EventScene;
#include "dngfloormanager.hpp"
extern "C" s32 IsClearMostFastDestroy__16CDngFloorManagerFv(void *);
extern "C" s32 _IS_CLEAR_DESTROY__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    CDngFloorManager *temp_a0;
    s32 temp_v0;

    temp_v0 = EventScene + 0x2F90;
    if (temp_v0 == 0) {
        return 0;
    }
    temp_a0 = (CDngFloorManager *) (temp_v0 + 0x14);
    if (temp_a0 == NULL) {
        return 0;
    }
    SetStack__FP12RS_STACKDATAi_00262E70(arg0, IsClearMostFastDestroy__16CDngFloorManagerFv(temp_a0));
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_002798A0", _IS_CLEAR_PRACTICE__FP12RS_STACKDATAi);
extern "C" s32 IsPlaySubGame__16CDngFloorManagerFv(void *);
extern "C" s32 _IS_PLAY_SUB_GAME__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    CDngFloorManager *temp_a0;
    s32 temp_v0;

    temp_v0 = EventScene + 0x2F90;
    if (temp_v0 == 0) {
        return 0;
    }
    temp_a0 = (CDngFloorManager *) (temp_v0 + 0x14);
    if (temp_a0 == NULL) {
        return 0;
    }
    SetStack__FP12RS_STACKDATAi_00262E70(arg0, IsPlaySubGame__16CDngFloorManagerFv(temp_a0));
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_002798A0", _RESET_SUBJECT_COUNTER__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _SCR_EFF_INIT_RASTER__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _SCR_EFF_START_RASTER__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _SCR_EFF_STOP_RASTER__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _SET_MPCHARA_MOTION__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _FUNC_POINT_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _PARTS_NAME_STRCMP__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _GET_TRIAL_VERSION__FP12RS_STACKDATAi);
extern "C" u8 StartupEpisodeTitle[24];
extern "C" s32 GetStackInt__FP12RS_STACKDATA_00262DA0(...);
extern "C" s32 Switch__20CStartupEpisodeTitleFi(void *, s32);
extern "C" s32 _SET_FLOOR_EPISODE__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    Switch__20CStartupEpisodeTitleFi(&StartupEpisodeTitle, GetStackInt__FP12RS_STACKDATA_00262DA0(arg0));
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_002798A0", _FUNC_POINT_GET_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _FUNC_POINT_GET_ROT__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _ACTCHR_SET_DEF_MOTION__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _ADD_FUSION_POINT__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _GET_DEBUG_FLAG__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _MINIMAP_DOOR_ENABLE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _DNG_CHECK_BOSS_MAP__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _DNG_RUN_EVENT__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _CHECK_ENABLE_CHARA_CHANGE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002798A0", _INIT_SEPIA__FP12RS_STACKDATAi);
