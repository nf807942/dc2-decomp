/* Fonctions libres — à décrire.
 *
 * Unité découpée par `make carve` : 178 fonctions, 24560 octets, de
 * 0x002734D0 à 0x002798A0. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

#include "runscript.hpp"

INCLUDE_ASM("nonmatchings/game/text_002734D0", _CMRS_MOVE_REF__FP12RS_STACKDATAi);
extern "C" u8 CameraSeq[2832];
extern "C" s32 InitPas__12CSceneCmrSeqFv(void *);
extern "C" s32 _CMRS_INIT_PAS__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    InitPas__12CSceneCmrSeqFv(&CameraSeq);
    return 1;
}
extern "C" s32 GetStackInt__FP12RS_STACKDATA_00262DA0(...);
extern "C" s32 SetPasFrm__12CSceneCmrSeqFi(void *, s32);
extern "C" s32 _CMRS_SET_PAS_FRM__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    SetPasFrm__12CSceneCmrSeqFi(&CameraSeq, GetStackInt__FP12RS_STACKDATA_00262DA0());
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_002734D0", _CMRS_ADD_PAS__FP12RS_STACKDATAi);
extern "C" s32 StartPas__12CSceneCmrSeqFv(void *);
extern "C" s32 _CMRS_START_PAS__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    StartPas__12CSceneCmrSeqFv(&CameraSeq);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_002734D0", _CMRS_PR_SLOWING__FP12RS_STACKDATAi);
extern "C" s32 PRKeep__12CSceneCmrSeqFv(void *);
extern "C" s32 _CMRS_PR_KEEP__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    PRKeep__12CSceneCmrSeqFv(&CameraSeq);
    return 1;
}
extern "C" s32 PRReturn__12CSceneCmrSeqFv(void *);
extern "C" s32 _CMRS_PR_RETURN__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    PRReturn__12CSceneCmrSeqFv(&CameraSeq);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_002734D0", _CMRS_MOVE_AHD__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _CMRS_SYNC_OBJ__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _CMRS_MOVE_AHD2__FP12RS_STACKDATAi);
extern "C" s32 ReleaseSyncObj__12CSceneCmrSeqFv(void *);
extern "C" s32 _CMRS_RELEASE_OBJ__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    ReleaseSyncObj__12CSceneCmrSeqFv(&CameraSeq);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_002734D0", _CMRS_AHD_SLOWING__FP12RS_STACKDATAi);
extern "C" s32 AHDKeep__12CSceneCmrSeqFv(void *);
extern "C" s32 _CMRS_AHD_KEEP__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    AHDKeep__12CSceneCmrSeqFv(&CameraSeq);
    return 1;
}
extern "C" s32 AHDReturn__12CSceneCmrSeqFv(void *);
extern "C" s32 _CMRS_AHD_RETURN__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    AHDReturn__12CSceneCmrSeqFv(&CameraSeq);
    return 1;
}
extern "C" s32 FadeDelay__12CSceneCmrSeqFi(void *, s32);
extern "C" s32 GetStackInt__FP12RS_STACKDATA_00262DA0(...);
extern "C" s32 _CMRS_FADE_DELAY__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    FadeDelay__12CSceneCmrSeqFi(&CameraSeq, GetStackInt__FP12RS_STACKDATA_00262DA0());
    return 1;
}
extern "C" s32 FadeInit__12CSceneCmrSeqFv(void *);
extern "C" s32 _CMRS_FADE_INIT__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    FadeInit__12CSceneCmrSeqFv(&CameraSeq);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_002734D0", _CMRS_FADE_IN__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _CMRS_FADE_OUT__FP12RS_STACKDATAi);
extern "C" s32 QuakeDelay__12CSceneCmrSeqFi(void *, s32);
extern "C" s32 _CMRS_QUAKE_DELAY__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    QuakeDelay__12CSceneCmrSeqFi(&CameraSeq, GetStackInt__FP12RS_STACKDATA_00262DA0());
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_002734D0", _CMRS_QUAKE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _CMRS_QUAKE2__FP12RS_STACKDATAi);
extern "C" s32 CharaDelay__12CSceneCmrSeqFi(void *, s32);
extern "C" s32 _CMRS_CHARA_DELAY__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    CharaDelay__12CSceneCmrSeqFi(&CameraSeq, GetStackInt__FP12RS_STACKDATA_00262DA0());
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_002734D0", _CMRS_CHARA_ATTACH__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _CMRS_MOVE_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _OBJS_CHECK__FP12RS_STACKDATAi);
extern "C" s32 GetObjSeq__Fi(s32);
#include "gen/CSceneObjSeq.hpp"
extern "C" s32 Clear__12CSceneObjSeqFv(void *);
extern "C" s32 GetStackInt__FP12RS_STACKDATA_00262DA0(...);
extern "C" s32 _OBJS_INIT__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    CSceneObjSeq *temp_v0;

    temp_v0 = (CSceneObjSeq *) (GetObjSeq__Fi(GetStackInt__FP12RS_STACKDATA_00262DA0()));
    if (temp_v0 == NULL) {
        return 0;
    }
    Clear__12CSceneObjSeqFv(temp_v0);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_002734D0", _OBJS_SYNC_OBJ__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _OBJS_POS_DELAY__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _OBJS_SET_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _OBJS_MOVE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _OBJS_MOVE2__FP12RS_STACKDATAi);
extern "C" s32 InitPas__12CSceneObjSeqFv(void *);
extern "C" s32 _OBJS_INIT_PAS__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    CSceneObjSeq *temp_v0;

    temp_v0 = (CSceneObjSeq *) (GetObjSeq__Fi(GetStackInt__FP12RS_STACKDATA_00262DA0()));
    if (temp_v0 == NULL) {
        return 0;
    }
    InitPas__12CSceneObjSeqFv(temp_v0);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_002734D0", _OBJS_SET_PAS_FRM__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _OBJS_ADD_PAS__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _OBJS_START_PAS__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _OBJS_JUMP__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _OBJS_SET_EOH_FRAME_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _OBJS_ADD_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _OBJS_ATTACH_CAMERA__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _OBJS_ROT_DELAY__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _OBJS_SET_ROT__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _OBJS_ROTATION__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _OBJS_ROTATION2__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _OBJS_REFERENCE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _OBJS_MOTION_DELAY__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _OBJS_SET_MOTION__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _OBJS_NEXT_MOTION__FP12RS_STACKDATAi);
extern "C" s32 MotionWait__12CSceneObjSeqFv(void *);
extern "C" s32 _OBJS_MOTION_WAIT__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    CSceneObjSeq *temp_v0;

    temp_v0 = (CSceneObjSeq *) (GetObjSeq__Fi(GetStackInt__FP12RS_STACKDATA_00262DA0()));
    if (temp_v0 == NULL) {
        return 0;
    }
    MotionWait__12CSceneObjSeqFv(temp_v0);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_002734D0", _OBJS_SET_STEP__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _OBJS_CHENGE_STEP__FP12RS_STACKDATAi);
extern "C" s32 SetMotionTrg__12CSceneObjSeqFv(void *);
extern "C" s32 _OBJS_SEQ_MOT_TRG__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    CSceneObjSeq *temp_v0;

    temp_v0 = (CSceneObjSeq *) (GetObjSeq__Fi(GetStackInt__FP12RS_STACKDATA_00262DA0()));
    if (temp_v0 == NULL) {
        return 0;
    }
    SetMotionTrg__12CSceneObjSeqFv(temp_v0);
    return 1;
}
extern "C" s32 MotionTrgWait__12CSceneObjSeqFv(void *);
extern "C" s32 _OBJS_SEQ_MOT_TRG_WAIT__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    CSceneObjSeq *temp_v0;

    temp_v0 = (CSceneObjSeq *) (GetObjSeq__Fi(GetStackInt__FP12RS_STACKDATA_00262DA0()));
    if (temp_v0 == NULL) {
        return 0;
    }
    MotionTrgWait__12CSceneObjSeqFv(temp_v0);
    return 1;
}
extern "C" s32 ResetMotion__12CSceneObjSeqFv(void *);
extern "C" s32 _OBJS_RESET_MOTION__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    CSceneObjSeq *temp_v0;

    temp_v0 = (CSceneObjSeq *) (GetObjSeq__Fi(GetStackInt__FP12RS_STACKDATA_00262DA0()));
    if (temp_v0 == NULL) {
        return 0;
    }
    ResetMotion__12CSceneObjSeqFv(temp_v0);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_002734D0", _OBJS_SET_MOTION_NOW_TIME__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _OBJS_SET_MOTION_WAIT_TIME__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _OBJS_TEXA_DELAY__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _OBJS_TEX_ANIME__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _OBJS_COLOR_DELAY__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _OBJS_SET_COLOR__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _OBJS_SCALE_DELAY__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _OBJS_SET_SCALE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _OBJS_SE_DELAY__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _OBJS_SE_PLAY__FP12RS_STACKDATAi);
extern "C" s32 ResetDAPosition__12CSceneObjSeqFv(void *);
extern "C" s32 _OBJS_RESET_DA_POSITION__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    CSceneObjSeq *temp_v0;

    temp_v0 = (CSceneObjSeq *) (GetObjSeq__Fi(GetStackInt__FP12RS_STACKDATA_00262DA0()));
    if (temp_v0 == NULL) {
        return 0;
    }
    ResetDAPosition__12CSceneObjSeqFv(temp_v0);
    return 1;
}
extern "C" s32 NormalDrive__12CSceneObjSeqFv(void *);
extern "C" s32 _OBJS_NORMAL_DRIVE__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    CSceneObjSeq *temp_v0;

    temp_v0 = (CSceneObjSeq *) (GetObjSeq__Fi(GetStackInt__FP12RS_STACKDATA_00262DA0()));
    if (temp_v0 == NULL) {
        return 0;
    }
    NormalDrive__12CSceneObjSeqFv(temp_v0);
    return 1;
}
s32 _ASQ_CHECK(RS_STACKDATA *stack, int argc) {
    return 1;
}
extern "C" s32 GetStackInt__FP12RS_STACKDATA_00262DA0(...);
extern "C" void sndInitPort__Fi(s32 arg0);
extern "C" s32 _SND_INIT_PORT__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    sndInitPort__Fi(GetStackInt__FP12RS_STACKDATA_00262DA0());
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_002734D0", _SND_LOAD_SOUND__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _GET_SND_ID__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _SND_SE_PAUSE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _SND_SE_PLAY__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _SND_SE_STOP__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _SND_SET_SE_VOL__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _SND_SET_SE_PAN__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _SND_SET_SE_PITCH__FP12RS_STACKDATAi);
extern "C" s32 GetStackInt__FP12RS_STACKDATA_00262DA0(...);
extern "C" void sndSeAllStop__Fi(s32 arg0);
extern "C" s32 _SND_SE_ALL_STOP__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    sndSeAllStop__Fi(GetStackInt__FP12RS_STACKDATA_00262DA0());
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_002734D0", _LOAD_BGM__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _PLAY_BGM__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _STOP_BGM__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", CommandStreamOpenFromFPL__FiPcPc);
INCLUDE_ASM("nonmatchings/game/text_002734D0", CommandStreamOpen__FiPc);
INCLUDE_ASM("nonmatchings/game/text_002734D0", VpkFileNameFromVoiceNo__FPci);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _STREAM_OPEN__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", CommandStreamPlay__Fii);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _STREAM_PLAY__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _STREAM_STOP__FP12RS_STACKDATAi);
extern "C" u8 CSnd;
extern "C" s32 StreamStandBy__6CSoundFi(void *, s32);
extern "C" s32 _STREAM_STANDBY__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    GetStackInt__FP12RS_STACKDATA_00262DA0();
    StreamStandBy__6CSoundFi(&CSnd, 1);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_002734D0", _STREAM_GET_STATUS__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _GET_SYS_SND_ID__FP12RS_STACKDATAi);
extern "C" u8 CSnd;
extern "C" s32 SetStack__FP12RS_STACKDATAi_00262E70(RS_STACKDATA *, s32);
extern "C" s32 StreamOpenState__6CSoundFv(void *);
extern "C" s32 _STREAM_OPEN_CHECK__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    SetStack__FP12RS_STACKDATAi_00262E70(arg0, StreamOpenState__6CSoundFv(&CSnd));
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_002734D0", _LOAD_SE_ENV__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _PLAY_ENV_BGM__FP12RS_STACKDATAi);
extern "C" u32 SystemSND_ID;
extern "C" s32 GetStackInt__FP12RS_STACKDATA_00262DA0(...);
extern "C" void sndSePlay__FUiii(u32 arg0, s32 arg1, s32 arg2);
extern "C" s32 _SYS_SE_PLAY__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    s32 temp_v0;

    temp_v0 = GetStackInt__FP12RS_STACKDATA_00262DA0();
    if (temp_v0 < 0) {
        return 0;
    }
    sndSePlay__FUiii(SystemSND_ID, temp_v0, 0);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_002734D0", _INIT_SE_SRC__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _INIT_SE_ENV__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _INIT_SE_BAS__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _LOAD_SE_SRC__FP12RS_STACKDATAi);
s32 _LOAD_SE_FOOT(RS_STACKDATA *stack, int argc) {
    return 0;
}
s32 _LOAD_SE_DOOR(RS_STACKDATA *stack, int argc) {
    return 0;
}
s32 _LOAD_SE_BOX(RS_STACKDATA *stack, int argc) {
    return 0;
}
INCLUDE_ASM("nonmatchings/game/text_002734D0", _LOAD_SE_BATTLE__FP12RS_STACKDATAi);
extern "C" s32 GetStackInt__FP12RS_STACKDATA_00262DA0(...);
extern "C" void sndDeletePort__Fi(s32 arg0);
extern "C" s32 _SND_DELETE_PORT__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    sndDeletePort__Fi(GetStackInt__FP12RS_STACKDATA_00262DA0());
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_002734D0", _FADE_IN_BGM__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _FADE_OUT_BGM__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _STOP_ENV_BGM__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _SET_BGM_VOL__FP12RS_STACKDATAi);
s32 _SND_SET_REVERB(RS_STACKDATA *stack, int argc) {
    return 0;
}
INCLUDE_ASM("nonmatchings/game/text_002734D0", _SND_SET_ENV_VOL__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _STREAM_SILENT_CHECK__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _AUTO_CHANGE_ENV__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _BGM_LOAD_CANCEL__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _SOUND_LOAD_CANCEL__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _BGM_LOAD_ENABLE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _SOUND_LOAD_ENABLE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _LOAD_SE_BASE__FP12RS_STACKDATAi);
extern "C" u32 EventScene;
extern "C" u32 read_buffer;
extern "C" s32 GetStackInt__FP12RS_STACKDATA_00262DA0(...);
extern "C" void LoadSound__6CSceneFiP1(s32, s32, s32);
extern "C" s32 _LOAD_SOUND__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    LoadSound__6CSceneFiP1(EventScene, GetStackInt__FP12RS_STACKDATA_00262DA0(), read_buffer);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_002734D0", _STREAM_CLOSE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", CommandStreamOpen2__FiPc);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _STREAM_OPEN2__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _LOAD_BGM_PACK__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _GET_BGM_NO__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _GET_MASTER_VOL__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _SET_MASTER_VOL__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _GET_BTL_BGM_VOL__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _SET_BTL_BGM_VOL__FP12RS_STACKDATAi);
extern "C" s32 SndInReverb__6CSoundFb(void *, bool);
extern "C" s32 _SND_IN_REVERB__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    SndInReverb__6CSoundFb(&CSnd, GetStackInt__FP12RS_STACKDATA_00262DA0() != 0);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_002734D0", _SND_STOP_SRC__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _SND_PAUSE_BGM__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _STREAM_OPEN3__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _GET_ACTIVE_BGM_STATUS__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _SET_ACTIVE_BGM_STATUS__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _GET_BGM_STATUS_NOW_NO__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _GET_SE_STATUS__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _SE_ALL_STOP__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _SOUND_ALL_STOP__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _BGM_PLAY_CANCEL__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _BGM_PLAY_ENABLE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _GET_DEF_BGM_NO__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _SET_MOVIE_CC__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _REGISTER_VILLAGER2__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _SET_FISHINGTOURNAMENT_ETC__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _EOH_SYNC_CHARA__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _EOH_SYNC_OBJ__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _EOH_SYNC_EDIT_OBJ__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _EOH_SYNC_SPRITE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _EOH_SET_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _EOH_SET_ROT__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _EOH_GET_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _EOH_GET_ROT__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _EOH_SET_MOTION__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _EOH_SET_STEP__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _EOH_SET_TEX_ANIM__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _EOH_SET_SCALE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _EOH_SET_SHOW__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _EOH_GET_SHOW__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _EOH_SET_FRAME_SHOW__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _EOH_SET_SHADOW__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _EOH_SET_TRANSLATE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _EOH_SET_FOOT_SOUND_ID__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _EOH_SET_FRAME_STATUS__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _EOH_GET_FRAME_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _EOH_SET_SOUND_ID__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _EOH_GET_FRAME_STATUS__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _EOH_SYNC_CHROBJ__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _EOH_SET_FADE_FLAG__FP12RS_STACKDATAi);
extern "C" u8 EventObjHandleMother[512];
extern "C" s32 ResetDAPosition__10CEohMotherFi(void *, s32);
extern "C" void _EOH_RESET_DA_POSITION__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    ResetDAPosition__10CEohMotherFi(&EventObjHandleMother, GetStackInt__FP12RS_STACKDATA_00262DA0());
}
INCLUDE_ASM("nonmatchings/game/text_002734D0", _EOH_SET_SHADOW_FRAME_STATUS__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _EOH_SYNC_GEOSTONE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _EOH_SYNC_SEARCH_CHARA__FP12RS_STACKDATAi);
extern "C" s32 NormalDrive__10CEohMotherFi(void *, s32);
extern "C" void _EOH_NORMAL_DRIVE__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    NormalDrive__10CEohMotherFi(&EventObjHandleMother, GetStackInt__FP12RS_STACKDATA_00262DA0());
}
INCLUDE_ASM("nonmatchings/game/text_002734D0", _EOH_SET_FRAME_ALPHA__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _EOH_SYNC_FUNCP__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _EOH_SET_FOOT_SE_ID__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _EOH_SYNC_DOOR_PARTS__FP12RS_STACKDATAi);
extern "C" void InitSphida__Fv(...);
extern "C" s32 _SPHIDA_INIT__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    InitSphida__Fv();
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_002734D0", _SPHIDA_SET_UP__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _SPHIDA_SET_PLAY_FLAG__FP12RS_STACKDATAi);
