/* Fonctions libres — à décrire.
 *
 * Unité découpée par `make carve` : 57 fonctions, 9452 octets, de
 * 0x0026EA00 à 0x00271030. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

INCLUDE_ASM("nonmatchings/game/text_0026EA00", _SET_EVENT_DATA__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_0026EA00", _STOPWATCH__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_0026EA00", _SET_FUNC_ETC__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_0026EA00", GetChara__Fi);
INCLUDE_ASM("nonmatchings/game/text_0026EA00", _GET_CHARA_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_0026EA00", _GET_CHARA_TALK_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_0026EA00", _TURN_CHARA__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_0026EA00", _SET_CHARA_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_0026EA00", _SET_CHARA_ROT__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_0026EA00", _GET_CHARA_ROT__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_0026EA00", _SET_MOTION__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_0026EA00", _SET_STEP__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_0026EA00", _SET_TEX_ANIM__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_0026EA00", _SET_SCALE__FP12RS_STACKDATAi_0026F710);
INCLUDE_ASM("nonmatchings/game/text_0026EA00", _SET_REFERENCE__FP12RS_STACKDATAi);
extern "C" s32 GetChara__Fi(s32);
#include "runscript.hpp"
#include "gen/mgCFrame.hpp"
struct temp_v0_champs {
    char pad0[0x70];
    /* 0x70 */ s32 unk70;
};
extern "C" s32 DeleteReference__8mgCFrameFv(void *);
extern "C" s32 GetStackInt__FP12RS_STACKDATA_00262DA0(...);
extern "C" s32 _DEL_REFERENCE__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    mgCFrame *temp_a0;
    struct temp_v0_champs *temp_v0;

    temp_v0 = (struct temp_v0_champs *) (GetChara__Fi(GetStackInt__FP12RS_STACKDATA_00262DA0(arg0)));
    if (temp_v0 == NULL) {
        return 0;
    }
    temp_a0 = (mgCFrame *) (temp_v0->unk70);
    if (temp_a0 == NULL) {
        return 0;
    }
    DeleteReference__8mgCFrameFv(temp_a0);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_0026EA00", _SHADOW_CLIP_OFF__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_0026EA00", _GET_COORDINATE_ANGLE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_0026EA00", _GET_CHARA_WIDTH__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_0026EA00", _GET_CHARA_HEIGHT__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_0026EA00", _GET_CHARA_WEIGHT__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_0026EA00", _SET_CHARA_SHOW__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_0026EA00", _GET_CHARA_SHOW__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_0026EA00", _CHARA_DA_ENABLE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_0026EA00", _GET_MOT_NOW_WAIT__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_0026EA00", _CHECK_MOTION_END__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_0026EA00", _ACTCHR_SET_MOTION__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_0026EA00", _SET_CHARA_EX_SOUNDID__FP12RS_STACKDATAi);
extern "C" s32 GetCharacter__Fi(s32);
#include "gen/CActionChara.hpp"
extern "C" s32 GetStackInt__FP12RS_STACKDATA_00262DA0(...);
extern "C" s32 SetSoundInfoCopy__12CActionCharaFv(void *);
extern "C" s32 _ACTCHR_SOUND_INFO_COPY__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    CActionChara *temp_v0;

    temp_v0 = (CActionChara *) (GetCharacter__Fi(GetStackInt__FP12RS_STACKDATA_00262DA0(arg0)));
    if (temp_v0 == NULL) {
        return 0;
    }
    if (temp_v0 == NULL) {
        return 0;
    }
    SetSoundInfoCopy__12CActionCharaFv(temp_v0);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_0026EA00", GetMes__Fi);
INCLUDE_ASM("nonmatchings/game/text_0026EA00", _MES_MAKE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_0026EA00", _MES_CLOSE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_0026EA00", _MES_NEXTPAGE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_0026EA00", _SET_MES_AUTOSET__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_0026EA00", _SET_MES_SHIPPO__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_0026EA00", _SET_MES_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_0026EA00", _SET_MES_DRAWSPEED__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_0026EA00", _SET_MES_CURSOR__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_0026EA00", _SET_MES_OKURI__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_0026EA00", _SET_MES_WIN_FLAG__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_0026EA00", _CHECK_MES_COMPLETE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_0026EA00", _CHECK_MES_WAIT__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_0026EA00", _CHECK_MES__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_0026EA00", _SET_MES_FUKIDASHI__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_0026EA00", _SET_MES_WINDOW_MODE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_0026EA00", _SET_MES_PRESET__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_0026EA00", _SET_MES_ITEM_DIRECT__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_0026EA00", _SET_MES_ITEM__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_0026EA00", _SET_MES_VALUE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_0026EA00", _GET_MES_STATUS__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_0026EA00", _GET_PARTY_CHARA_MES_NO__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_0026EA00", _MES_SET_BUFF__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_0026EA00", _GET_MES_WINDOW_MODE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_0026EA00", _GET_MES_VOICE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_0026EA00", _SET_MES_QUESTION_GYOU__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_0026EA00", _GET_MES_QUESTION_GYOU__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_0026EA00", _SET_MES_CLOSE_CNT__FP12RS_STACKDATAi);
