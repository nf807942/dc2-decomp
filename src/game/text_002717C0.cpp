/* Fonctions libres — à décrire.
 *
 * Unité découpée par `make carve` : 65 fonctions, 7056 octets, de
 * 0x002717C0 à 0x002734D0. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

#include "runscript.hpp"

INCLUDE_ASM("nonmatchings/game/text_002717C0", _GET_FISHINGTOURNAMENT_ETC__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002717C0", _SET_CHARA_FAR_DIST__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002717C0", _SET_MODEL_LIGHT_SWITCH__FP12RS_STACKDATAi_00271C40);
INCLUDE_ASM("nonmatchings/game/text_002717C0", _SET_MODEL_LIGHT_COLOR__FP12RS_STACKDATAi_00271D30);
extern "C" u32 OmakeFlag;
extern "C" s32 SetStack__FP12RS_STACKDATAi_00262E70(...);
extern "C" s32 _GET_OMAKE_FLAG__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    SetStack__FP12RS_STACKDATAi_00262E70(arg0, OmakeFlag);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_002717C0", _SET_WIND__FP12RS_STACKDATAi);
extern "C" u32 OmakeFlag;
extern "C" s32 GetStackInt__FP12RS_STACKDATA_00262DA0(RS_STACKDATA *);
extern "C" s32 _SET_OMAKE_FLAG__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    OmakeFlag = GetStackInt__FP12RS_STACKDATA_00262DA0(arg0);
    return 1;
}
extern "C" s32 GetActiveCamera__Fv(void);
extern "C" s32 GetCamera__Fv(void) {
    return GetActiveCamera__Fv();
}
INCLUDE_ASM("nonmatchings/game/text_002717C0", _SET_CAMERA_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002717C0", _GET_CAMERA_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002717C0", _SET_CAMERA_REF__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002717C0", _GET_CAMERA_REF__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002717C0", _SET_CAMERA_SPEED__FP12RS_STACKDATAi_00272290);
INCLUDE_ASM("nonmatchings/game/text_002717C0", _CAMERA_STEP__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002717C0", _GET_BEFORE_CAMERA_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002717C0", _GET_BEFORE_CAMERA_REF__FP12RS_STACKDATAi);
s32 _ASQ_INIT(RS_STACKDATA *stack, int argc) {
    return 1;
}
s32 _ASQ_SYNC_CHARA(RS_STACKDATA *stack, int argc) {
    return 1;
}
s32 _ASQ_SET_POS(RS_STACKDATA *stack, int argc) {
    return 1;
}
s32 _ASQ_MOVE(RS_STACKDATA *stack, int argc) {
    return 1;
}
s32 _ASQ_MOVE_STEP(RS_STACKDATA *stack, int argc) {
    return 1;
}
s32 _ASQ_ROT_REF(RS_STACKDATA *stack, int argc) {
    return 1;
}
s32 _ASQ_ROT_ANGLE(RS_STACKDATA *stack, int argc) {
    return 1;
}
s32 _ASQ_CLEAR_ROT(RS_STACKDATA *stack, int argc) {
    return 1;
}
s32 _ASQ_WAIT_ROT(RS_STACKDATA *stack, int argc) {
    return 1;
}
s32 _ASQ_ROT_MOVE(RS_STACKDATA *stack, int argc) {
    return 1;
}
s32 _ASQ_SET_ROT(RS_STACKDATA *stack, int argc) {
    return 1;
}
s32 _ASQ_DELAY_ROT(RS_STACKDATA *stack, int argc) {
    return 1;
}
s32 _ASQ_MOTION_TRG(RS_STACKDATA *stack, int argc) {
    return 1;
}
s32 _ASQ_MOTION_PLAY(RS_STACKDATA *stack, int argc) {
    return 1;
}
s32 _ASQ_MOTION_STOP(RS_STACKDATA *stack, int argc) {
    return 1;
}
s32 _ASQ_MOTION_NEXT(RS_STACKDATA *stack, int argc) {
    return 1;
}
s32 _ASQ_ANIME_TRG(RS_STACKDATA *stack, int argc) {
    return 1;
}
s32 _ASQ_ANIME(RS_STACKDATA *stack, int argc) {
    return 1;
}
s32 _ASQ_SE_PLAY(RS_STACKDATA *stack, int argc) {
    return 1;
}
extern "C" u8 esMother[1088];
extern "C" void SetDraw__18CEventSpriteMotherFii(void *, s32, s32);
extern "C" void _IMG_SET_DRAW__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    s32 id;

    id = GetStackInt__FP12RS_STACKDATA_00262DA0(arg0++);
    SetDraw__18CEventSpriteMotherFii(esMother, GetStackInt__FP12RS_STACKDATA_00262DA0(arg0), id);
}
INCLUDE_ASM("nonmatchings/game/text_002717C0", _IMG_SET_GET__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002717C0", _IMG_SET_PUT__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002717C0", _IMG_SET_NAME__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002717C0", _IMG_SET_MOVE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002717C0", _IMG_SET_FADE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002717C0", _IMG_SET_COLOR__FP12RS_STACKDATAi);
extern "C" u8 EventSprite2[6144];
extern "C" s32 GetEventSprite__Fi(s32 index) {
    if (index < 0 || index >= 0x30) return 0;
    return (s32)(EventSprite2 + index * 0x80);
}
extern "C" s32 GetEventSprite__Fi(s32);
#include "gen/CEventSprite2.hpp"
extern "C" s32 GetStackInt__FP12RS_STACKDATA_00262DA0(RS_STACKDATA *);
extern "C" s32 Initialize__13CEventSprite2Fv(void *);
extern "C" s32 _SPRITE_INIT__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    CEventSprite2 *temp_v0;

    temp_v0 = (CEventSprite2 *) (GetEventSprite__Fi(GetStackInt__FP12RS_STACKDATA_00262DA0(arg0)));
    if (temp_v0 == NULL) {
        return 0;
    }
    Initialize__13CEventSprite2Fv(temp_v0);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_002717C0", _SPRITE_SET_DRAW__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002717C0", _SPRITE_SET_TYPE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002717C0", _SPRITE_SET_TEXTURE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002717C0", _SPRITE_SET_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002717C0", _SPRITE_SET_PUTSIZE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002717C0", _SPRITE_SET_UVSIZE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002717C0", _SPRITE_SET_COLOR__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002717C0", _SPRITE_SET_SCALE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002717C0", _SPRITE_SET_ALPHAB__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002717C0", _CMRS_CHECK__FP12RS_STACKDATAi);
extern "C" u8 CameraSeq[2832];
extern "C" s32 Clear__12CSceneCmrSeqFv(void *);
extern "C" s32 _CMRS_INIT__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    Clear__12CSceneCmrSeqFv(&CameraSeq);
    return 1;
}
extern "C" u8 CameraSeq[2832];
extern "C" s32 GetStackInt__FP12RS_STACKDATA_00262DA0(RS_STACKDATA *);
extern "C" s32 PRDelay__12CSceneCmrSeqFi(void *, s32);
extern "C" s32 _CMRS_PRDELAY__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    PRDelay__12CSceneCmrSeqFi(&CameraSeq, GetStackInt__FP12RS_STACKDATA_00262DA0(arg0));
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_002717C0", _CMRS_SET_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002717C0", _CMRS_SET_REF__FP12RS_STACKDATAi);
extern "C" s32 AHDDelay__12CSceneCmrSeqFi(void *, s32);
extern "C" s32 _CMRS_AHDDELAY__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    AHDDelay__12CSceneCmrSeqFi(&CameraSeq, GetStackInt__FP12RS_STACKDATA_00262DA0(arg0));
    return 1;
}
extern "C" float GetStackFloat__FP12RS_STACKDATA_00262DE0(RS_STACKDATA *);
extern "C" int SetAngle__12CSceneCmrSeqFf(void *, float);
extern "C" int _CMRS_SET_ANGLE__FP12RS_STACKDATAi(RS_STACKDATA *arg0, int arg1) {
    SetAngle__12CSceneCmrSeqFf(&CameraSeq, GetStackFloat__FP12RS_STACKDATA_00262DE0(arg0));
    return 1;
}
extern "C" float GetStackFloat__FP12RS_STACKDATA_00262DE0(RS_STACKDATA *);
extern "C" int SetHeight__12CSceneCmrSeqFf(void *, float);
extern "C" int _CMRS_SET_HEIGHT__FP12RS_STACKDATAi(RS_STACKDATA *arg0, int arg1) {
    SetHeight__12CSceneCmrSeqFf(&CameraSeq, GetStackFloat__FP12RS_STACKDATA_00262DE0(arg0));
    return 1;
}
extern "C" float GetStackFloat__FP12RS_STACKDATA_00262DE0(RS_STACKDATA *);
extern "C" int SetDist__12CSceneCmrSeqFf(void *, float);
extern "C" int _CMRS_SET_DIST__FP12RS_STACKDATAi(RS_STACKDATA *arg0, int arg1) {
    SetDist__12CSceneCmrSeqFf(&CameraSeq, GetStackFloat__FP12RS_STACKDATA_00262DE0(arg0));
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_002717C0", _CMRS_SET_AHD__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002717C0", _CMRS_MOVE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002717C0", _CMRS_MOVE2__FP12RS_STACKDATAi);
