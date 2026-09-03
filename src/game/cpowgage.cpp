/* CPowGage
 *
 * Unité découpée par `make carve` : 62 fonctions, 11640 octets, de
 * 0x002EB000 à 0x002EDF20. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"
#include "gen/CPowGage.hpp"

#include "runscript.hpp"

INCLUDE_ASM("nonmatchings/game/cpowgage", _SPT_VAN_SET_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/cpowgage", _SPT_VAN_SET_ROT__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/cpowgage", _SPT_VAN_SET_COL__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/cpowgage", _SPT_VAN_SET_SCL__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/cpowgage", _SPT_ADD_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/cpowgage", _SPT_ADD_ROTZ__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/cpowgage", _SPT_ADD_COLOR__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/cpowgage", _SPT_WORLD_ROT__FP12RS_STACKDATAi);
s32 _SPT_SET_LIFE(RS_STACKDATA *stack, int argc) {
    return 0;
}
INCLUDE_ASM("nonmatchings/game/cpowgage", _SPT_SET_VELO_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/cpowgage", _SPT_SET_ACC_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/cpowgage", _SPT_SET_VELO_ROTZ__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/cpowgage", _SPT_SET_ACC_ROTZ__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/cpowgage", _SPT_SET_VELO_COL__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/cpowgage", _SPT_SET_ACC_COL__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/cpowgage", _SPT_SET_BLINKING__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/cpowgage", _SPT_SET_VELO_SCL__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/cpowgage", _SPT_SET_ACC_SCL__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/cpowgage", _SPT_SCALE_CONV__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/cpowgage", _SPT_COLOR_CONV__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/cpowgage", _SCN_GET_CHR_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/cpowgage", _SCN_GET_CHR_ROT__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/cpowgage", _SCN_GET_CHR_FRM_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/cpowgage", _SCN_GET_CHR_FRM_DIR__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/cpowgage", _SCN_GET_CHR_FRM_ROT__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/cpowgage", _SCN_GET_ENTRY_OBJ_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/cpowgage", _INTERSECTION_POINT__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/cpowgage", _MON_SE_PLAY__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/cpowgage", _MON_SE_STOP__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/cpowgage", _BTL_SE_PLAY__FP12RS_STACKDATAi);
typedef struct now_scene_pointe {
    char pad0[50384];
    s32 unkC4D0;
} now_scene_pointe;
extern "C" now_scene_pointe *now_scene;
extern "C" s32 GetStackInt__FP12RS_STACKDATA_002E8280(RS_STACKDATA *);
extern "C" s32 sndSeStop__FUiii(u32, s32, s32);
extern "C" s32 _BTL_SE_STOP__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    u32 temp_s0;

    temp_s0 = now_scene->unkC4D0;
    sndSeStop__FUiii(temp_s0, GetStackInt__FP12RS_STACKDATA_002E8280(arg0), 0);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/cpowgage", _BSE_SE_PLAY__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/cpowgage", _BSE_SE_STOP__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/cpowgage", _MON_SE_PLAY2__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/cpowgage", _MON_SE_STOP2__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/cpowgage", _SET_LIGHT_FLAG__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/cpowgage", _SCN_GET_CHR_ENTOBJ_POS__FP12RS_STACKDATAi);
extern "C" u8 _3398[62];
extern "C" s32 printf(...);
extern "C" s32 _CREATE_DAMAGE__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    printf(&_3398);
    return 0;
}
s32 _DELETE_DAMAGE(RS_STACKDATA *stack, int argc) {
    return 0;
}
s32 _DMG_SET_POS(RS_STACKDATA *stack, int argc) {
    return 0;
}
s32 _DMG_SET_FRONT_VECT(RS_STACKDATA *stack, int argc) {
    return 0;
}
extern "C" s32 _DMG_SET_DAMAGE__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    printf(&_3398);
    return 0;
}
INCLUDE_ASM("nonmatchings/game/cpowgage", _COLPRIM_CREATE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/cpowgage", _COLPRIM_SET_COORD__FP12RS_STACKDATAi);
typedef struct now_script_pointe {
    char pad0[308];
    s32 unk134;
} now_script_pointe;
extern "C" now_script_pointe *now_script;
#include "gen/CColPrim.hpp"
extern "C" s32 Delete__8CColPrimFi(void *, s32);
extern "C" s32 GetStackInt__FP12RS_STACKDATA_002E8280(RS_STACKDATA *);
extern "C" s32 _COLPRIM_DELETE__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    CColPrim *temp_a0;

    if (now_script == NULL) {
        return 0;
    }
    GetStackInt__FP12RS_STACKDATA_002E8280(arg0);
    temp_a0 = (CColPrim *) (now_script->unk134);
    if (temp_a0 == NULL) {
        return 0;
    }
    Delete__8CColPrimFi(temp_a0, -1);
    now_script->unk134 = NULL;
    return 1;
}
INCLUDE_ASM("nonmatchings/game/cpowgage", _COLPRIM_GET_HITCNT__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/cpowgage", _COLPRIM_GET_GIFT__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/cpowgage", _COLPRIM_GET_REVCNT__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/cpowgage", _COLPRIM_SET_DAMAGE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/cpowgage", _COLPRIM_GET_HIT_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/cpowgage", _ES_CREATE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/cpowgage", _ES_SET_VECT1__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/cpowgage", _ES_SET_VECT2__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/cpowgage", _ES_SET_TARGET_ID__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/cpowgage", _ES_SET_VALUE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/cpowgage", _ES_SET_COLPRIM__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/cpowgage", _GET_EOH_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/cpowgage", SetEffectScript__FP10CRunScriptPcP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/cpowgage", SetEffectScriptFunc__Fv);
INCLUDE_ASM("nonmatchings/game/cpowgage", GetSphidaClubDef__Fi);
#include "gen/mgCDrawPrim.hpp"
extern "C" s32 TextureCrd__11mgCDrawPrimFii(void *, s32, s32);
extern "C" s32 Vertex__11mgCDrawPrimFfff(void *, f32, f32, f32);
extern "C" void DPrimEnterSprite__FP11mgCDrawPrimiiiiffff(mgCDrawPrim *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8) {
    f32 temp_f20;
    f32 temp_f21;

    TextureCrd__11mgCDrawPrimFii(arg0, arg1, arg2);
    temp_f21 = arg7 / 2.0f;
    temp_f20 = arg8 / 2.0f;
    Vertex__11mgCDrawPrimFfff(arg0, arg5 - temp_f21, arg6 - temp_f20, 0.0f);
    TextureCrd__11mgCDrawPrimFii(arg0, arg1 + arg3, arg2 + arg4);
    Vertex__11mgCDrawPrimFfff(arg0, arg5 + temp_f21, arg6 + temp_f20, 0.0f);
}
void CPowGage::Initialize(void) {
    this->field_0x4 = 0;
    this->field_0x0 = 0;
    this->field_0x8 = 0;
    this->field_0xC = 0;
    this->field_0x10 = 2;
    this->field_0x14 = -10;
    this->field_0x1C = -1;
    this->field_0x20 = 0;
}
