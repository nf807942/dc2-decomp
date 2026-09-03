/* Fonctions libres — à décrire.
 *
 * Unité découpée par `make carve` : 137 fonctions, 24556 octets, de
 * 0x00266E10 à 0x0026D190. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"
#include "gen/EdEventInfoData.hpp"
#include "gen/MenuArgData.hpp"

#include "runscript.hpp"
extern EdEventInfoData EdEventInfo;
extern MenuArgData MenuArg;
struct RS_STACKDATA;


INCLUDE_ASM("nonmatchings/game/text_00266E10", _SET_CURRENT_DIR__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _CHANGE_DIR__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _DELETE_CHARA__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _LOAD_MOTION_sub__FiPciPUi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _LOAD_MOTION__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _MAP_JUMP__FP12RS_STACKDATAi);
extern "C" u8 EventRain[44016];
extern "C" s32 GetStackInt__FP12RS_STACKDATA_00262DA0(...);
extern "C" s32 Start__5CRainFv(void *);
extern "C" s32 Stop__5CRainFv(void *);
extern "C" s32 _SET_RAIN__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    if (GetStackInt__FP12RS_STACKDATA_00262DA0(arg0) != 0) {
        Start__5CRainFv(&EventRain);
    } else {
        Stop__5CRainFv(&EventRain);
    }
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_00266E10", _DEL_EXT_MOTION__FP12RS_STACKDATAi);
s32 _SET_MARKER(RS_STACKDATA *stack, int argc) {
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_00266E10", _SET_WORLD_COORD__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _FINISH__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _GET_DUN_WORLD_COORD__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _LOAD_IMG__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _DEL_IMG__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _SET_DNG_MAP__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _LOAD_ITEM__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _GOTO_USE_ITEM__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _SET_LOCAL_FLAG__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _GET_LOCAL_FLAG__FP12RS_STACKDATAi);
s32 _GOTO_SELECT_PARTY(RS_STACKDATA * arg0, s32 arg1) {
    MenuArg.field_0x28 = 4;
    EdEventInfo.field_0xD0 = 3;
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_00266E10", _SET_LOADBG_FILE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _SET_LOADBG_FILE_MONS_TALK__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _CHECK_LOADBG_FILE__FP12RS_STACKDATAi);
s32 _GET_TB_ITEMNO(RS_STACKDATA *stack, int argc) {
    return 0;
}
INCLUDE_ASM("nonmatchings/game/text_00266E10", _SET_TB_STATUS__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _SET_TB_ANGLE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _ADD_ITEM__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _SUB_ITEM__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _GET_ITEM_TYPE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _GET_ITEM_SPACE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", GetConfigCaptionOff__Fv);
INCLUDE_ASM("nonmatchings/game/text_00266E10", LoadMovie__FPcP9mgCMemoryb);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _LOAD_MOVIE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _INIT_LOCAL_CNT__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _SET_CROSSFADE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _GET_ADJUST_POLYGON_SCALE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _SET_TIME__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _SET_ACTIVE_LIGHT__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _SET_PAKU_ANIM__FP12RS_STACKDATAi);
extern "C" u32 PakuAnimEohNo;
extern "C" u8 PakuAnimName[64];
extern "C" u8 PakuAnimName2[64];
extern "C" s32 memset(...);
extern "C" s32 _RESET_PAKU_ANIM__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    PakuAnimEohNo = -1;
    memset(&PakuAnimName, 0, 0x40);
    memset(&PakuAnimName2, 0, 0x40);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_00266E10", _TRG_PAKU_ANIM__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _RESET_CAMERA__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _GET_ACTIVE_CHR_NO__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _SET_ACTIVE_CHR_NO__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _DNG_SET_FLOOR_ID__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _DNG_GET_FLOOR_ID__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _SET_PAKU_MOTION__FP12RS_STACKDATAi);
extern "C" u32 PakuMotionEohNo;
extern "C" u8 PakuMotionName[64];
extern "C" u8 PakuMotionName2[64];
extern "C" s32 _RESET_PAKU_MOTION__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    PakuMotionEohNo = -1;
    memset(&PakuMotionName, 0, 0x40);
    memset(&PakuMotionName2, 0, 0x40);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_00266E10", _TRG_PAKU_MOTION__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _SET_BG_COLOR__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _GOTO_DNG_MAP__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _GOTO_DNG__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _GOTO_EDIT__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _GET_MENU_PARAM__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _LOAD_CHARA_NPC__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _AUTO_SET_TREASURE_BOX__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _AUTO_SET_MONSTER__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _LOAD_DUNGEON_MAP_FILE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _LOAD_MONSTER_FILE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _GET_NPC_STATUS__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _SET_NPC_STATUS__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _GET_NOW_PARTY_CHARA__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _SET_LOCAL_CNT__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _GET_LOCAL_CNT__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _GET_LOCAL_CNT2__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _GET_TRAIN_NPC_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _GOTO_DRAW_CHAPTER__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _SET_PROJECTION__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _GET_PROJECTION__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _SET_FADE_IN__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _SET_FADE_OUT__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _DNG_DEBUG_COMMAND__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _CD_SEEK__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _GET_ROT_LOOK_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _SET_MOTION_BLUR__FP12RS_STACKDATAi_0026A4F0);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _LOAD_SCRIPT__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _SET_TALK_CAMERA__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _HIT_EFFECT__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _COPY_CHARA__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _GET_START_BUTTON__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _MOVE_INTERIOR__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _GET_MONSTER_TALK_DATA__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _FUNC_POINT_SHOW__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _GET_NOW_MAP_NO__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _GET_NOW_SUBMAP_NO__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _GET_OLD_MAP_NO__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _GET_OLD_SUBMAP_NO__FP12RS_STACKDATAi);
extern "C" s32 SetCharNo__5CRainFi(void *, s32);
extern "C" s32 _SET_RAIN_CHARA_NO__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    SetCharNo__5CRainFi(&EventRain, GetStackInt__FP12RS_STACKDATA_00262DA0(arg0));
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_00266E10", _GET_EDIT_PARTS_POS__FP12RS_STACKDATAi);
s32 _GET_CONTENTS_POS(RS_STACKDATA *stack, int argc) {
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_00266E10", _GET_BPOT_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _GET_BPOT_STATUS__FP12RS_STACKDATAi);
s32 _GET_PERSON_STATUS(RS_STACKDATA *stack, int argc) {
    return 0;
}
INCLUDE_ASM("nonmatchings/game/text_00266E10", _GET_CONTROL_CHRID__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _SET_CAMERA_NEXT_REF__FP12RS_STACKDATAi_0026B110);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _GOTO_MENU__FP12RS_STACKDATAi);
s32 _GET_MENU_STATUS(RS_STACKDATA *stack, int argc) {
    return 0;
}
INCLUDE_ASM("nonmatchings/game/text_00266E10", _LOAD_EQUIP__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _GET_EQUIP_ITEMNO__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _SET_TIME_STEP_ENABLE__FP12RS_STACKDATAi);
s32 _SET_DOOR_MATERIAL(RS_STACKDATA *stack, int argc) {
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_00266E10", _INIT_DRAMA_SCENE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _SET_ACTIVE_CMRID__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _SET_BEFORE_CMRID__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _DNGMAP_LOAD__FP12RS_STACKDATAi);
extern "C" u8 EventDngMap[272];
extern "C" s32 DeleteTexBlock__11CDngFreeMapFv(void *);
extern "C" s32 _DNGMAP_DELETE__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    DeleteTexBlock__11CDngFreeMapFv(&EventDngMap);
    return 1;
}
extern "C" u8 EventDngMap[272];
extern "C" s32 SetKomaMove__11CDngFreeMapFi(void *, s32);
extern "C" s32 _DNGMAP_MOVE_PIECE__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    SetKomaMove__11CDngFreeMapFi(&EventDngMap, GetStackInt__FP12RS_STACKDATA_00262DA0(arg0));
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_00266E10", _DNGMAP_ONOFF__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _DNGMAP_SET_FADE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _GET_BEFORE_CAMERA_NEXT_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _GET_BEFORE_CAMERA_NEXT_REF__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _SET_CAMERA_NEXT_POS__FP12RS_STACKDATAi_0026BC60);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _CHK_INTERSECTION_POINT__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _CHK_INTERSECTION_POINT_PIPE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _SET_FCAMERA_FOLLOW__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _SET_FCAMERA_FOLLOW_A__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _SET_FCAMERA_FOLLOW_OFS__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _SET_FCAMERA_FOLLOW_FLAG__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _FCAMERA_STEP__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _SET_FCAMERA_ANGLE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _SET_FCAMERA_HEIGHT__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _SET_FCAMERA_DIST__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _GET_REF_ANGLE__FP12RS_STACKDATAi_0026C9B0);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _DNG_SET_STAGE_ID__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _DNG_GET_STAGE_ID__FP12RS_STACKDATAi);
typedef struct EventScene_pointe {
    char pad0[11860];
    s32 unk2E54;
} EventScene_pointe;
extern "C" EventScene_pointe *EventScene;
extern "C" s32 GetCamera__6CSceneFi(void *, s32);
struct CCameraControl {
    f32 field_0;
    char pad_4[0x70];
    f32 field_74;
    f32 field_78;
    f32 field_7C;
    char pad_80[0x4];
    f32 field_84;
    f32 field_88;
    f32 field_8C;
    char pad_90[0x24];
    f32 field_B4;
    f32 field_B8;
    f32 field_BC;
    char pad_C0[0x10];
    s32 field_D0;
    char pad_D4[0x10];
    f32 field_E4;
    f32 field_E8;
    f32 field_EC;
    char pad_F0[0xB8];
    f32 field_1A8;
    f32 field_1AC;
    f32 field_1B0;
    f32 field_1B4;
    f32 field_1B8;
    f32 field_1BC;
    f32 field_1C0;
    f32 field_1C4;
    f32 field_1C8;
    f32 field_1CC;
    char pad_1D0[0x4];
    f32 field_1D4;
    f32 field_1D8;
    f32 field_1DC;
};
struct inferred;
struct mgCCameraFollow {
    char pad_0[0x48];
    f32 field_48;
    char pad_4C[0x4];
    f32 field_50;
    char pad_54[0x8];
    s32 field_5C;
    char pad_60[0x10];
    f32 field_70;
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
    char pad_A4[0xC];
    f32 field_B0;
    f32 field_B4;
    f32 field_B8;
    f32 field_BC;
    char pad_C0[0x4];
    s32 field_C4;
};
typedef struct CScene {
    /* 0x0000 */ char pad0[0x2E54];
    /* 0x2E54 */ s32 unk2E54;                       /* inferred */
} CScene;                                           /* size >= 0x2E58 */
extern "C" s32 ControlOff__14CCameraControlFv(void *);
extern "C" s32 ControlOn__14CCameraControlFv(void *);
extern "C" s32 FollowOff__15mgCCameraFollowFv(void *);
extern "C" s32 FollowOn__15mgCCameraFollowFv(void *);
extern "C" s32 _SET_CAMERA_CTRL__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    mgCCameraFollow *temp_v0;

    temp_v0 = (mgCCameraFollow *) (GetCamera__6CSceneFi(EventScene, EventScene->unk2E54));
    if (temp_v0 == NULL) {
        return 0;
    }
    if (GetStackInt__FP12RS_STACKDATA_00262DA0(arg0) != 0) {
        FollowOn__15mgCCameraFollowFv(temp_v0);
        ControlOn__14CCameraControlFv((CCameraControl *) temp_v0);
    } else {
        FollowOff__15mgCCameraFollowFv(temp_v0);
        ControlOff__14CCameraControlFv((CCameraControl *) temp_v0);
    }
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_00266E10", _GET_FCAMERA_ANGLE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _GET_FCAMERA_HEIGHT__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _GET_FCAMERA_DIST__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _GET_INVENTION_ID__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _FUNCTION_MAP_JUMP__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _FUNCTION_DOOR_MODE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _GET_MONEY__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _ADD_MONEY__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _GET_ITEM_NUM__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _CHECK_BUTTON__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _GET_LANGUAGE__FP12RS_STACKDATAi);
