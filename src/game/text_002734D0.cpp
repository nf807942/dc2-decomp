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
/* Pose par `make forge`, qui a compose les reparations connues et verifie l'image entiere. Voir docs/IDIOMES_MWCC.md pour le detail de chacune. */
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
extern "C" s32 CharaAttach__12CSceneCmrSeqFifi(void *, s32, f32, s32);
extern "C" float GetStackFloat__FP12RS_STACKDATA_00262DE0(RS_STACKDATA *);
extern "C" s32 GetStackInt__FP12RS_STACKDATA_00262DA0(...);
extern "C" s32 _CMRS_CHARA_ATTACH__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    s32 chara;
    f32 rate;

    chara = GetStackInt__FP12RS_STACKDATA_00262DA0(arg0++);
    rate = GetStackFloat__FP12RS_STACKDATA_00262DE0(arg0++);
    CharaAttach__12CSceneCmrSeqFifi(&CameraSeq, chara, rate, GetStackInt__FP12RS_STACKDATA_00262DA0(arg0));
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_002734D0", _CMRS_MOVE_POS__FP12RS_STACKDATAi);
extern "C" s32 GetObjSeq__Fi(s32);
extern "C" s32 CheckEnd__12CSceneObjSeqFv(void *);
extern "C" s32 SetStack__FP12RS_STACKDATAi_00262E70(...);
extern "C" s32 _OBJS_CHECK__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    void *seq;

    seq = (void *) GetObjSeq__Fi(GetStackInt__FP12RS_STACKDATA_00262DA0(arg0++));
    if (seq == NULL) {
        return 0;
    }
    SetStack__FP12RS_STACKDATAi_00262E70(arg0, (u8) ((CheckEnd__12CSceneObjSeqFv(seq) != 0) ^ 1));
    return 1;
}
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
extern "C" s32 GetStackInt__FP12RS_STACKDATA_00262DA0(...);
extern "C" s32 StartPas__12CSceneObjSeqFi(void *, s32);
/* La case suivante s'atteint en avancant le pointeur (`arg0++`) : MWCC pose alors
 * `addiu s3, a0, 8` des le prologue. `arg0 + 1` en garde `arg0` et rend 96,47 %. */
extern "C" s32 _OBJS_START_PAS__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    CSceneObjSeq *temp_v0;
    s32 temp_s0;
    s32 var_s1;

    var_s1 = 0;
    temp_s0 = (s32) (GetStackInt__FP12RS_STACKDATA_00262DA0(arg0++));
    if (arg1 >= 2) {
        var_s1 = (s32) (GetStackInt__FP12RS_STACKDATA_00262DA0(arg0));
    }
    temp_v0 = (CSceneObjSeq *) (GetObjSeq__Fi(temp_s0));
    if (temp_v0 == NULL) {
        return 0;
    }
    StartPas__12CSceneObjSeqFi(temp_v0, var_s1);
    return 1;
}
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
extern "C" s32 GetStackInt__FP12RS_STACKDATA_00262DA0(...);
extern "C" s32 sndSePause__FUii(u32, s32);
extern "C" s32 _SND_SE_PAUSE__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    u32 id;

    id = GetStackInt__FP12RS_STACKDATA_00262DA0(arg0++);
    sndSePause__FUii(id, GetStackInt__FP12RS_STACKDATA_00262DA0(arg0));
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_002734D0", _SND_SE_PLAY__FP12RS_STACKDATAi);
extern "C" s32 GetStackInt__FP12RS_STACKDATA_00262DA0(...);
extern "C" s32 sndSeStop__FUiii(u32, s32, s32);
extern "C" s32 _SND_SE_STOP__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    u32 id;

    id = GetStackInt__FP12RS_STACKDATA_00262DA0(arg0++);
    sndSeStop__FUiii(id, GetStackInt__FP12RS_STACKDATA_00262DA0(arg0), 0);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_002734D0", _SND_SET_SE_VOL__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _SND_SET_SE_PAN__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _SND_SET_SE_PITCH__FP12RS_STACKDATAi);
extern "C" s32 GetStackInt__FP12RS_STACKDATA_00262DA0(...);
extern "C" void sndSeAllStop__Fi(s32 arg0);
extern "C" s32 _SND_SE_ALL_STOP__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    sndSeAllStop__Fi(GetStackInt__FP12RS_STACKDATA_00262DA0());
    return 1;
}
extern "C" u32 EventScene;
extern "C" u32 read_buffer;
extern "C" s32 CheckLoadBGM__6CSceneFi(...);
extern "C" s32 LoadBGM__6CSceneFiP1(...);
extern "C" s32 _LOAD_BGM__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    s32 temp_v0;

    temp_v0 = (s32) (GetStackInt__FP12RS_STACKDATA_00262DA0(arg0));
    if (CheckLoadBGM__6CSceneFi(EventScene, temp_v0) == 0) {
        return 0;
    }
    return LoadBGM__6CSceneFiP1(EventScene, temp_v0, read_buffer);
}
INCLUDE_ASM("nonmatchings/game/text_002734D0", _PLAY_BGM__FP12RS_STACKDATAi);
extern "C" s32 StopBGM__6CSceneFi(...);
extern "C" s32 _STOP_BGM__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    StopBGM__6CSceneFi(EventScene, GetStackInt__FP12RS_STACKDATA_00262DA0(arg0));
    return 1;
}
extern "C" u8 CSnd;
extern "C" u8 _6773_00372128[];
extern "C" u8 _6774_00372138[];
extern "C" u8 _6775_00372140[];
extern "C" u8 _6776_00372148[];
extern "C" s32 StreamOpenFromFPLFast__6CSoundFiPcPc(...);
extern "C" s32 strcat(...);
extern "C" s32 strcpy(...);
extern "C" s32 strncat(...);
extern "C" s32 CommandStreamOpenFromFPL__FiPcPc(s32 arg0, s8 *arg1, s8 *arg2) {
    s8 sp40[64];
    s8 sp80[64];

    strcpy(sp40, &_6773_00372128);
    strncat(sp40, arg1, 3);
    strcat(sp40, &_6774_00372138);
    strcat(sp40, arg1);
    strcat(sp40, &_6775_00372140);
    strcpy(sp80, arg2);
    strcat(sp80, &_6776_00372148);
    StreamOpenFromFPLFast__6CSoundFiPcPc(&CSnd, arg0, sp40, sp80);
    return 1;
}
extern "C" u8 CSnd;
extern "C" u8 _6781_00372150[15];
extern "C" u8 _6782_00372160[];
extern "C" s32 StreamOpenFast__6CSoundFiPc(...);
extern "C" s32 strcat(...);
extern "C" s32 strcpy(...);
extern "C" s32 CommandStreamOpen__FiPc(s32 arg0, s8 *arg1) {
    s8 sp30[64];

    strcpy(sp30, &_6781_00372150);
    strcat(sp30, arg1);
    strcat(sp30, &_6782_00372160);
    StreamOpenFast__6CSoundFiPc(&CSnd, arg0, sp30);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_002734D0", VpkFileNameFromVoiceNo__FPci);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _STREAM_OPEN__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", CommandStreamPlay__Fii);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _STREAM_PLAY__FP12RS_STACKDATAi);
extern "C" u8 CSnd;
typedef struct EdEventInfo_champs {
    char pad0[308];
    s32 unk134;
    s32 unk138;
    char pad13C[196];
    s32 unk200;
    char pad204[4208];
    u8 unk1274[4];
    s32 bgmStatusNowNo;
    u8 pad127C[36];
} EdEventInfo_champs;
extern "C" EdEventInfo_champs EdEventInfo;
extern "C" s32 StreamClose__6CSoundFi(void *, s32);
extern "C" s32 StreamEND__6CSoundFi(void *, s32);
extern "C" s32 StreamSetVol__6CSoundFiii(void *, s32, s32, s32);
extern "C" s32 _STREAM_STOP__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    EdEventInfo.unk134 = 0;
    GetStackInt__FP12RS_STACKDATA_00262DA0(arg0);
    if (EdEventInfo.unk138 == 1) {
        StreamEND__6CSoundFi(&CSnd, 1);
    } else {
        StreamSetVol__6CSoundFiii(&CSnd, 1, EdEventInfo.unk200, EdEventInfo.unk200);
        StreamClose__6CSoundFi(&CSnd, 1);
    }
    return 1;
}
extern "C" u8 CSnd;
extern "C" s32 StreamStandBy__6CSoundFi(void *, s32);
extern "C" s32 _STREAM_STANDBY__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    GetStackInt__FP12RS_STACKDATA_00262DA0();
    StreamStandBy__6CSoundFi(&CSnd, 1);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_002734D0", _STREAM_GET_STATUS__FP12RS_STACKDATAi);
extern "C" s32 GetSystemSndID__Fv(void);
extern "C" s32 _GET_SYS_SND_ID__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    arg1 = GetSystemSndID__Fv();
    SetStack__FP12RS_STACKDATAi_00262E70(arg0, arg1);
    return 1;
}
extern "C" u8 CSnd;
extern "C" s32 SetStack__FP12RS_STACKDATAi_00262E70(...);
extern "C" s32 StreamOpenState__6CSoundFv(void *);
extern "C" s32 _STREAM_OPEN_CHECK__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    SetStack__FP12RS_STACKDATAi_00262E70(arg0, StreamOpenState__6CSoundFv(&CSnd));
    return 1;
}
extern "C" u32 EventScene;
extern "C" u32 read_buffer;
extern "C" s32 CheckLoadSeEnv__6CSceneFi(...);
extern "C" s32 LoadSeEnv__6CSceneFiP1(...);
extern "C" s32 _LOAD_SE_ENV__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    s32 temp_v0;

    temp_v0 = (s32) (GetStackInt__FP12RS_STACKDATA_00262DA0(arg0));
    if (CheckLoadSeEnv__6CSceneFi(EventScene, temp_v0) == 0) {
        return 0;
    }
    LoadSeEnv__6CSceneFiP1(EventScene, temp_v0, read_buffer);
    return 1;
}
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
extern "C" s32 InitSeSrc__6CSceneFv(...);
extern "C" s32 _INIT_SE_SRC__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    InitSeSrc__6CSceneFv(EventScene);
    return 1;
}
extern "C" s32 InitSeEnv__6CSceneFv(...);
extern "C" s32 _INIT_SE_ENV__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    InitSeEnv__6CSceneFv(EventScene);
    return 1;
}
extern "C" s32 InitSeBas__6CSceneFv(...);
extern "C" s32 _INIT_SE_BAS__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    InitSeBas__6CSceneFv(EventScene);
    return 1;
}
extern "C" s32 CheckLoadSeSrc__6CSceneFi(...);
extern "C" s32 LoadSeSrc__6CSceneFiP1(...);
extern "C" s32 _LOAD_SE_SRC__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    s32 temp_v0;

    temp_v0 = (s32) (GetStackInt__FP12RS_STACKDATA_00262DA0(arg0));
    if (CheckLoadSeSrc__6CSceneFi(EventScene, temp_v0) == 0) {
        return 0;
    }
    return LoadSeSrc__6CSceneFiP1(EventScene, temp_v0, read_buffer);
}
s32 _LOAD_SE_FOOT(RS_STACKDATA *stack, int argc) {
    return 0;
}
s32 _LOAD_SE_DOOR(RS_STACKDATA *stack, int argc) {
    return 0;
}
s32 _LOAD_SE_BOX(RS_STACKDATA *stack, int argc) {
    return 0;
}
extern "C" s32 CheckLoadSeBattle__6CSceneFi(...);
extern "C" s32 LoadSeBattle__6CSceneFiP1(...);
extern "C" s32 _LOAD_SE_BATTLE__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    s32 temp_v0;

    temp_v0 = (s32) (GetStackInt__FP12RS_STACKDATA_00262DA0(arg0));
    if (CheckLoadSeBattle__6CSceneFi(EventScene, temp_v0) == 0) {
        return 0;
    }
    return LoadSeBattle__6CSceneFiP1(EventScene, temp_v0, read_buffer);
}
extern "C" s32 GetStackInt__FP12RS_STACKDATA_00262DA0(...);
extern "C" void sndDeletePort__Fi(s32 arg0);
extern "C" s32 _SND_DELETE_PORT__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    sndDeletePort__Fi(GetStackInt__FP12RS_STACKDATA_00262DA0());
    return 1;
}
extern "C" s32 FadeInBGM__6CSceneFi(...);
extern "C" s32 _FADE_IN_BGM__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    s32 temp_v0;
    s32 var_a1;

    temp_v0 = (s32) (GetStackInt__FP12RS_STACKDATA_00262DA0(arg0));
    var_a1 = temp_v0 * 50 / 60;
    if (var_a1 <= 0) {
        var_a1 = 1;
    }
    FadeInBGM__6CSceneFi(EventScene, var_a1);
    return 1;
}
extern "C" s32 FadeOutBGM__6CSceneFi(...);
extern "C" s32 _FADE_OUT_BGM__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    s32 temp_v0;
    s32 var_a1;

    temp_v0 = (s32) (GetStackInt__FP12RS_STACKDATA_00262DA0(arg0));
    var_a1 = temp_v0 * 50 / 60;
    if (var_a1 <= 0) {
        var_a1 = 1;
    }
    FadeOutBGM__6CSceneFi(EventScene, var_a1);
    return 1;
}
extern "C" s32 StopEnvBGM__6CSceneFv(...);
extern "C" s32 _STOP_ENV_BGM__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    StopEnvBGM__6CSceneFv(EventScene);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_002734D0", _SET_BGM_VOL__FP12RS_STACKDATAi);
s32 _SND_SET_REVERB(RS_STACKDATA *stack, int argc) {
    return 0;
}
extern "C" float GetStackFloat__FP12RS_STACKDATA_00262DE0(RS_STACKDATA *);
extern "C" s32 SetEnvBGMVol__6CSceneFf(u32, float);
extern "C" s32 _SND_SET_ENV_VOL__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    SetEnvBGMVol__6CSceneFf(EventScene, GetStackFloat__FP12RS_STACKDATA_00262DE0(arg0));
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_002734D0", _STREAM_SILENT_CHECK__FP12RS_STACKDATAi);
extern "C" s32 AutoChangeEnvBGM__6CSceneFi(...);
extern "C" s32 _AUTO_CHANGE_ENV__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    AutoChangeEnvBGM__6CSceneFi(EventScene, GetStackInt__FP12RS_STACKDATA_00262DA0(arg0));
    return 1;
}
struct EventSceneBgm { u8 pad[0x906C]; s32 load; s32 play; };
extern "C" s32 _BGM_LOAD_CANCEL__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    ((EventSceneBgm *) EventScene)->load = 1;
    return 1;
}
struct EventScene;
struct EventSceneSnd { u8 pad[0x9070]; s32 load; };
extern "C" s32 _SOUND_LOAD_CANCEL__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    ((EventSceneSnd *) EventScene)->load = 1;
    return 1;
}
extern "C" s32 _BGM_LOAD_ENABLE__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    ((EventSceneBgm *) EventScene)->load = 0;
    return 1;
}
extern "C" s32 _SOUND_LOAD_ENABLE__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    ((EventSceneSnd *) EventScene)->load = 0;
    return 1;
}
extern "C" s32 CheckLoadSeBase__6CSceneFi(...);
extern "C" s32 LoadSeBase__6CSceneFiP1(...);
extern "C" s32 _LOAD_SE_BASE__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    s32 temp_v0;

    temp_v0 = (s32) (GetStackInt__FP12RS_STACKDATA_00262DA0(arg0));
    if (CheckLoadSeBase__6CSceneFi(EventScene, temp_v0) == 0) {
        return 0;
    }
    return LoadSeBase__6CSceneFiP1(EventScene, temp_v0, read_buffer);
}
extern "C" u32 EventScene;
extern "C" u32 read_buffer;
extern "C" s32 GetStackInt__FP12RS_STACKDATA_00262DA0(...);
extern "C" void LoadSound__6CSceneFiP1(s32, s32, s32);
extern "C" s32 _LOAD_SOUND__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    LoadSound__6CSceneFiP1(EventScene, GetStackInt__FP12RS_STACKDATA_00262DA0(), read_buffer);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_002734D0", _STREAM_CLOSE__FP12RS_STACKDATAi);
extern "C" u8 _6781_00372150[15];
extern "C" u8 _6782_00372160[];
extern "C" s32 strcat(...);
extern "C" s32 strcpy(...);
extern "C" s32 CommandStreamOpen2__FiPc(s32 arg0, s8 *arg1) {
    s32 sp20[16];
    strcpy(sp20, &_6781_00372150);
    strcat(sp20, arg1);
    strcat(sp20, &_6782_00372160);
    return 1;
}

INCLUDE_ASM("nonmatchings/game/text_002734D0", _STREAM_OPEN2__FP12RS_STACKDATAi);
extern "C" s32 GetLoadBGBuff__FPcPi(...);
extern "C" s32 GetBgmFile__6CSceneFPci(...);
extern "C" s32 LoadBGMPack__6CSceneFiPUi(...);
extern "C" s32 _LOAD_BGM_PACK__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    s8 sp20[64];
    s32 temp_v0;
    u32 *temp_v0_2;

    temp_v0 = (s32) (GetStackInt__FP12RS_STACKDATA_00262DA0(arg0));
    if (CheckLoadBGM__6CSceneFi(EventScene, temp_v0) == 0) {
        return 0;
    }
    GetBgmFile__6CSceneFPci(EventScene, sp20, temp_v0);
    temp_v0_2 = (u32 *) (GetLoadBGBuff__FPcPi(sp20, NULL));
    if (temp_v0_2 != NULL) {
        return LoadBGMPack__6CSceneFiPUi(EventScene, temp_v0, temp_v0_2);
    }
    return 0;
}
INCLUDE_ASM("nonmatchings/game/text_002734D0", _GET_BGM_NO__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _GET_MASTER_VOL__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _SET_MASTER_VOL__FP12RS_STACKDATAi);
struct temp_v0_champs_583a14 {
    char pad0[0x88];
    /* 0x88 */ float unk88;
};
extern "C" s32 SetStack__FP12RS_STACKDATAf_00262E90(RS_STACKDATA *, float);
extern "C" s32 _GET_BTL_BGM_VOL__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    struct temp_v0_champs_583a14 *temp_v0;

    temp_v0 = (struct temp_v0_champs_583a14 *) (EventScene + 0x2F90);
    if (temp_v0 == NULL) {
        return 0;
    }
    SetStack__FP12RS_STACKDATAf_00262E90(arg0, temp_v0->unk88);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_002734D0", _SET_BTL_BGM_VOL__FP12RS_STACKDATAi);
extern "C" s32 SndInReverb__6CSoundFb(void *, bool);
extern "C" s32 _SND_IN_REVERB__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    SndInReverb__6CSoundFb(&CSnd, GetStackInt__FP12RS_STACKDATA_00262DA0() != 0);
    return 1;
}
extern "C" s32 StopSeSrc__6CSceneFv(...);
extern "C" s32 _SND_STOP_SRC__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    StopSeSrc__6CSceneFv(EventScene);
    return 1;
}
extern "C" s32 PauseBGM__6CSceneFv(...);
extern "C" s32 _SND_PAUSE_BGM__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    PauseBGM__6CSceneFv(EventScene);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_002734D0", _STREAM_OPEN3__FP12RS_STACKDATAi);
extern "C" s32 GetActiveBgmStatus__6CSceneFPQ26CScene10BGM_STATUS(...);
extern "C" s32 _GET_ACTIVE_BGM_STATUS__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    GetActiveBgmStatus__6CSceneFPQ26CScene10BGM_STATUS(EventScene, EdEventInfo.unk1274);
    return 1;
}
extern "C" int SetActiveBgmStatus__6CSceneFPQ26CScene10BGM_STATUS(void *, void *);
extern "C" int _SET_ACTIVE_BGM_STATUS__FP12RS_STACKDATAi(RS_STACKDATA *arg0, int arg1) {
    SetActiveBgmStatus__6CSceneFPQ26CScene10BGM_STATUS((void *)EventScene, EdEventInfo.unk1274);
    return 1;
}
extern "C" s32 _GET_BGM_STATUS_NOW_NO__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    if (arg1 != 1) {
        return 0;
    }
    return SetStack__FP12RS_STACKDATAi_00262E70(arg0, EdEventInfo.bgmStatusNowNo);
}
INCLUDE_ASM("nonmatchings/game/text_002734D0", _GET_SE_STATUS__FP12RS_STACKDATAi);
extern "C" s32 SeAllStop__6CSceneFv(...);
extern "C" s32 _SE_ALL_STOP__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    SeAllStop__6CSceneFv(EventScene);
    return 1;
}
extern "C" s32 SoundAllStop__6CSceneFv(...);
extern "C" s32 _SOUND_ALL_STOP__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    SoundAllStop__6CSceneFv(EventScene);
    return 1;
}
struct EventSceneBgmPlay { u8 pad[0x9074]; s32 play; };
extern "C" s32 _BGM_PLAY_CANCEL__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    ((EventSceneBgmPlay *) EventScene)->play = 1;
    return 1;
}
extern "C" s32 _BGM_PLAY_ENABLE__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    ((EventSceneBgmPlay *) EventScene)->play = 0;
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_002734D0", _GET_DEF_BGM_NO__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _SET_MOVIE_CC__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _REGISTER_VILLAGER2__FP12RS_STACKDATAi);
extern "C" void *GetFishTournament__Fv(void);
extern "C" s32 GetStackInt__FP12RS_STACKDATA_00262DA0(...);
extern "C" s32 InitFishPrize__Fv(void);
extern "C" s32 LoadFishPrize__Fi(s32);
extern "C" s32 ResetRecord__18CFishingTournamentFv(void *);
extern "C" s32 SetRank__18CFishingTournamentFi(void *, s32);
extern "C" s32 TuriTourCount__Fv(void);
extern "C" s32 _SET_FISHINGTOURNAMENT_ETC__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    void *tournament;
    u8 *next = (u8 *) arg0 + 8;

    switch (GetStackInt__FP12RS_STACKDATA_00262DA0(arg0)) {
    case 0:
        tournament = GetFishTournament__Fv();
        if (tournament == NULL) {
            return 0;
        }
        SetRank__18CFishingTournamentFi(tournament, GetStackInt__FP12RS_STACKDATA_00262DA0(next));
        break;
    case 1:
        tournament = GetFishTournament__Fv();
        if (tournament == NULL) {
            return 0;
        }
        ResetRecord__18CFishingTournamentFv(tournament);
        break;
    case 2:
        InitFishPrize__Fv();
        LoadFishPrize__Fi(1);
        break;
    case 3:
        TuriTourCount__Fv();
        break;
    default:
        return 0;
    }
    return 1;
}
extern "C" u8 EventObjHandleMother[512];
extern "C" void *GetChara__Fi(s32);
extern "C" s32 GetStackInt__FP12RS_STACKDATA_00262DA0(...);
extern "C" s32 Set__10CEohMotherFiiiP11CCharacter2(void *, s32, s32, s32, void *);
extern "C" s32 _EOH_SYNC_CHARA__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    void *chara;
    s32 id;
    s32 charaNo;

    id = GetStackInt__FP12RS_STACKDATA_00262DA0(arg0++);
    charaNo = GetStackInt__FP12RS_STACKDATA_00262DA0(arg0);
    chara = GetChara__Fi(charaNo);
    if (chara != NULL) {
        return Set__10CEohMotherFiiiP11CCharacter2(&EventObjHandleMother, id, 0, charaNo, chara);
    }
    return 0;
}
INCLUDE_ASM("nonmatchings/game/text_002734D0", _EOH_SYNC_OBJ__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _EOH_SYNC_EDIT_OBJ__FP12RS_STACKDATAi);
extern "C" void *GetEventSprite__Fi(s32);
extern "C" s32 Set__10CEohMotherFiiP13CEventSprite2(void *, s32, s32, void *);
extern "C" s32 _EOH_SYNC_SPRITE__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    void *sprite;
    s32 id;

    id = GetStackInt__FP12RS_STACKDATA_00262DA0(arg0++);
    sprite = GetEventSprite__Fi(GetStackInt__FP12RS_STACKDATA_00262DA0(arg0));
    if (sprite != NULL) {
        return Set__10CEohMotherFiiP13CEventSprite2(&EventObjHandleMother, id, 2, sprite);
    }
    return 0;
}
INCLUDE_ASM("nonmatchings/game/text_002734D0", _EOH_SET_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _EOH_SET_ROT__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _EOH_GET_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _EOH_GET_ROT__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _EOH_SET_MOTION__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _EOH_SET_STEP__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _EOH_SET_TEX_ANIM__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _EOH_SET_SCALE__FP12RS_STACKDATAi);
extern "C" u8 EventObjHandleMother[512];
extern "C" s32 GetStackInt__FP12RS_STACKDATA_00262DA0(...);
extern "C" s32 SetShow__10CEohMotherFii(void *, s32, s32);
extern "C" void _EOH_SET_SHOW__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    s32 id;

    id = GetStackInt__FP12RS_STACKDATA_00262DA0(arg0++);
    SetShow__10CEohMotherFii(&EventObjHandleMother, id, GetStackInt__FP12RS_STACKDATA_00262DA0(arg0));
}
extern "C" u8 EventObjHandleMother[512];
struct RS_STACKDATA_infere;
typedef struct RS_STACKDATA_infere {
    /* 0x0 */ char pad0[8];
    /* 0x8 */ char unk8;                               /* inferred */
    /* 0x8 */ char pad8[1];
} RS_STACKDATA_infere;                                     /* size >= 0x9 */
extern "C" s32 GetShow__10CEohMotherFiPi(void *, s32, s32 *);
extern "C" void _EOH_GET_SHOW__FP12RS_STACKDATAi(RS_STACKDATA_infere *arg0, s32 arg1) {
    char *next_slot;

    /* L'adresse du second emplacement de pile se calcule avant la garde : MWCC
     * la range alors dans le creneau de delai du branchement, ce que le
     * commerce fait. Posee apres la garde, elle rend 94 % — la forme de
     * l'expression n'y change rien, sa place seule decide. */
    next_slot = &arg0->unk8;

    s32 sp2C;
    if (GetShow__10CEohMotherFiPi(&EventObjHandleMother, GetStackInt__FP12RS_STACKDATA_00262DA0(arg0), &sp2C) != 0) {
        SetStack__FP12RS_STACKDATAi_00262E70(next_slot, sp2C);
    }
}
INCLUDE_ASM("nonmatchings/game/text_002734D0", _EOH_SET_FRAME_SHOW__FP12RS_STACKDATAi);
extern "C" u8 EventObjHandleMother[512];
extern "C" s32 GetStackInt__FP12RS_STACKDATA_00262DA0(...);
extern "C" s32 SetShadow__10CEohMotherFii(void *, s32, s32);
extern "C" void _EOH_SET_SHADOW__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    s32 id;

    id = GetStackInt__FP12RS_STACKDATA_00262DA0(arg0++);
    SetShadow__10CEohMotherFii(&EventObjHandleMother, id, GetStackInt__FP12RS_STACKDATA_00262DA0(arg0));
}
INCLUDE_ASM("nonmatchings/game/text_002734D0", _EOH_SET_TRANSLATE__FP12RS_STACKDATAi);
extern "C" u8 EventObjHandleMother[512];
extern "C" s32 GetStackInt__FP12RS_STACKDATA_00262DA0(...);
extern "C" s32 SetFootSoundID__10CEohMotherFii(void *, s32, s32);
extern "C" void _EOH_SET_FOOT_SOUND_ID__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    s32 id;

    id = GetStackInt__FP12RS_STACKDATA_00262DA0(arg0++);
    SetFootSoundID__10CEohMotherFii(&EventObjHandleMother, id, GetStackInt__FP12RS_STACKDATA_00262DA0(arg0));
}
INCLUDE_ASM("nonmatchings/game/text_002734D0", _EOH_SET_FRAME_STATUS__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _EOH_GET_FRAME_POS__FP12RS_STACKDATAi);
extern "C" u8 EventObjHandleMother[512];
extern "C" s32 GetStackInt__FP12RS_STACKDATA_00262DA0(...);
extern "C" s32 SetSoundID__10CEohMotherFiUi(void *, s32, u32);
extern "C" void _EOH_SET_SOUND_ID__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    u32 id;

    id = GetStackInt__FP12RS_STACKDATA_00262DA0(arg0++);
    SetSoundID__10CEohMotherFiUi(&EventObjHandleMother, id, GetStackInt__FP12RS_STACKDATA_00262DA0(arg0));
}
INCLUDE_ASM("nonmatchings/game/text_002734D0", _EOH_GET_FRAME_STATUS__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_002734D0", _EOH_SYNC_CHROBJ__FP12RS_STACKDATAi);
extern "C" u8 EventObjHandleMother[512];
extern "C" s32 GetStackInt__FP12RS_STACKDATA_00262DA0(...);
extern "C" s32 SetFadeFlag__10CEohMotherFii(void *, s32, s32);
extern "C" void _EOH_SET_FADE_FLAG__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    s32 id;

    id = GetStackInt__FP12RS_STACKDATA_00262DA0(arg0++);
    SetFadeFlag__10CEohMotherFii(&EventObjHandleMother, id, GetStackInt__FP12RS_STACKDATA_00262DA0(arg0));
}
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
extern "C" u8 EventObjHandleMother[512];
extern "C" s32 GetStackInt__FP12RS_STACKDATA_00262DA0(...);
extern "C" s32 SetFootSeId__10CEohMotherFii(void *, s32, s32);
extern "C" void _EOH_SET_FOOT_SE_ID__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    s32 id;

    id = GetStackInt__FP12RS_STACKDATA_00262DA0(arg0++);
    SetFootSeId__10CEohMotherFii(&EventObjHandleMother, id, GetStackInt__FP12RS_STACKDATA_00262DA0(arg0));
}
INCLUDE_ASM("nonmatchings/game/text_002734D0", _EOH_SYNC_DOOR_PARTS__FP12RS_STACKDATAi);
extern "C" void InitSphida__Fv(...);
extern "C" s32 _SPHIDA_INIT__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    InitSphida__Fv();
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_002734D0", _SPHIDA_SET_UP__FP12RS_STACKDATAi);
typedef struct Sphida_pointe {
    char pad0[40];
    s32 unk28;
} Sphida_pointe;
extern "C" Sphida_pointe *Sphida;
extern "C" s32 _SPHIDA_SET_PLAY_FLAG__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    s32 temp_v0;

    temp_v0 = (s32) (GetStackInt__FP12RS_STACKDATA_00262DA0(arg0));
    if (Sphida == NULL) {
        return 0;
    }
    Sphida->unk28 = temp_v0;
    return 1;
}
