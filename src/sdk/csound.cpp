/* CSound, sndCSeSeq, sndPortInfo, CLoopSeMngr, sndCSeSeqData, sndTrack, sndBankInfo, SND_LOOP_SE_SEQ, sndSeInfo
 *
 * Unité découpée par `make carve` : 171 fonctions, 31624 octets, de
 * 0x00189E30 à 0x00191DF0. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"
#include "gen/CLoopSeMngr.hpp"
#include "gen/sndCSeSeqData.hpp"
#include "gen/sndSeInfo.hpp"
#include "gen/sndTrack.hpp"

extern "C" u8 _218[25];
struct CSound;
extern "C" void printf(...);
extern "C" s32 sceSdRemote(...);
extern "C" void StopVoice__6CSoundFi(CSound *objet, s32 arg0) {
    sceSdRemote(1, 0x8030, arg0 | 0x1600, 0xFFFFFF);
    printf(&_218, arg0);
}
struct CSound;
extern "C" s32 sceSdRemote(...);
extern "C" void SndInReverb__6CSoundFb(CSound *objet, s32 arg0) {
    if (arg0 != 0) {
        sceSdRemote(1, 0x8010, 0x800, -4);
        sceSdRemote(1, 0x8010, 0x801, -4);
        return;
    }
    sceSdRemote(1, 0x8010, 0x800, -0x34);
    sceSdRemote(1, 0x8010, 0x801, -0x34);
}
INCLUDE_ASM("nonmatchings/sdk/csound", SetReverb__6CSoundFiii);
INCLUDE_ASM("nonmatchings/sdk/csound", set_spu__Fiiii);
INCLUDE_ASM("nonmatchings/sdk/csound", TransHdBd__Fiiii);
INCLUDE_ASM("nonmatchings/sdk/csound", Init__6CSoundFiiii);
INCLUDE_ASM("nonmatchings/sdk/csound", Exit__6CSoundFv);
INCLUDE_ASM("nonmatchings/sdk/csound", DEL_PORT__6CSoundFi);
INCLUDE_ASM("nonmatchings/sdk/csound", SQ_Play__6CSoundFiii);
INCLUDE_ASM("nonmatchings/sdk/csound", SQ_RePlay__6CSoundFi);
INCLUDE_ASM("nonmatchings/sdk/csound", SE_Play__6CSoundFiiiiiiiii);
INCLUDE_ASM("nonmatchings/sdk/csound", SE_SetVol__6CSoundFiiiiii);
INCLUDE_ASM("nonmatchings/sdk/csound", SE_SetPan__6CSoundFiiiiii);
INCLUDE_ASM("nonmatchings/sdk/csound", SE_Stop__6CSoundFiiiii);
INCLUDE_ASM("nonmatchings/sdk/csound", Step__6CSoundFv);
extern "C" u8 _733_00369110[15];
struct CSound;
extern "C" void printf(...);
extern "C" void ezMidi__Fii(s32 arg0, s32 arg1);
extern "C" void Stop__6CSoundFi(CSound *objet, s32 arg0) {
    ezMidi__Fii(arg0 + 0x20, 0);
    printf(&_733_00369110, arg0);
}
struct CSound;
extern "C" s32 fptosi(f32);
extern "C" void ezMidi__Fii(s32 arg0, s32 arg1);
extern "C" void SetVol__6CSoundFii(CSound *objet, s32 arg0, s32 arg1) {
    s32 var_a2;

    var_a2 = arg1;
    if (var_a2 != 0x100) {
        var_a2 = fptosi(2.015748f * (f32) var_a2);
    }
    ezMidi__Fii(arg0 + 0xB0, var_a2);
}
extern "C" void SetStereoMode__6CSoundFi(CSound *objet, s32 arg0) {
    ezMidi__Fii(0xC0, arg0);
}
struct CSound;
extern "C" s32 sceSdRemote(...);
extern "C" void SetMasterVol__6CSoundFii(CSound *objet, s32 arg0, s32 arg1) {
    sceSdRemote(1, 0x8010, arg0 | 0x980, arg1);
    sceSdRemote(1, 0x8010, arg0 | 0xA80, arg1);
}
extern "C" s32 LoadHdBd2__6CSoundFiiiii(void *, s32, s32, s32, s32, s32);
extern "C" s32 LoadHdBd__6CSoundFiiiii(void *self, s32 a, s32 b, s32 c, s32 d, s32 e) {
    return LoadHdBd2__6CSoundFiiiii(self, a, b, c, d, e);
}
INCLUDE_ASM("nonmatchings/sdk/csound", LoadHdBd2__6CSoundFiiiii);
INCLUDE_ASM("nonmatchings/sdk/csound", LoadHdBdAdd__6CSoundFiiiii);
INCLUDE_ASM("nonmatchings/sdk/csound", LoadSeq__6CSoundFiii);
INCLUDE_ASM("nonmatchings/sdk/csound", SE_SetPitch__6CSoundFiiiiii);
INCLUDE_ASM("nonmatchings/sdk/csound", StreamOpenFast__6CSoundFiPc);
INCLUDE_ASM("nonmatchings/sdk/csound", StreamOpenFromFPLFast__6CSoundFiPcPc);
extern "C" void ezBgm__Fii(s32 arg0, s32 arg1);
extern "C" void StreamPlay__6CSoundFi(void *objet, s32 arg0) {
    ezBgm__Fii(arg0 | 0x50, 0);
}
extern "C" void StreamStop__6CSoundFi(CSound *objet, s32 arg0) {
    ezBgm__Fii(arg0 | 0x60, 0);
}
struct CSound;
extern "C" void ezBgm__Fii(s32 arg0, s32 arg1);
extern "C" void StreamClose__6CSoundFi(CSound *objet, s32 arg0) {
    ezBgm__Fii(arg0 | 0x60, 0);
    ezBgm__Fii(arg0 | 0x30, 0);
    ezBgm__Fii(arg0 | 0x10, 0);
}
struct CSound;
extern "C" void ezBgm__Fii(s32 arg0, s32 arg1);
extern "C" void StreamEND__6CSoundFi(CSound *objet, s32 arg0) {
    ezBgm__Fii(arg0 | 0x60, 0);
    ezBgm__Fii(arg0 | 0x70, 0);
    ezBgm__Fii(arg0 | 0x10, 0);
}
extern "C" void StreamPause__6CSoundFi(void *objet, s32 arg0) {
    ezBgm__Fii(arg0 | 0x60, 0);
}
extern "C" void StreamRePlay__6CSoundFi(void *objet, s32 arg0) {
    ezBgm__Fii(arg0 | 0x50, 0);
}
extern "C" void StreamSetVol__6CSoundFiii(CSound *objet, s32 arg0, s32 arg1, s32 arg2) {
    ezBgm__Fii(arg0 | 0x80, (arg1 << 16) | arg2);
}
INCLUDE_ASM("nonmatchings/sdk/csound", StreamGetState__6CSoundFi);
extern "C" void StreamGetLevel__6CSoundFi(CSound *objet, s32 arg0) {
    ezBgm__Fii(arg0 | 0x80E0, 0);
}
INCLUDE_ASM("nonmatchings/sdk/csound", StreamStandBy__6CSoundFi);
struct CSound;
extern "C" s32 sceSdRemote(...);
extern "C" void TransBdState__6CSoundFi(CSound *objet, s32 arg0) {
    sceSdRemote(1, 0x80F0, arg0, 0);
}
extern "C" u8 _33_00369320[23];
typedef struct gCd_champs {
    char pad0[36];
    s32 unk24;
} gCd_champs;
extern "C" gCd_champs gCd;
extern "C" s32 sceSifBindRpc(...);
extern "C" s32 sceSifInitRpc(...);
extern "C" s32 ezMidiInit__Fv(void) {
    s32 temp_v0;
    s32 var_v1;

    sceSifInitRpc(0);
loop_1:
    if (sceSifBindRpc(&gCd, 0x12346, 0) < 0) {
        printf(&_33_00369320);
loop_3:
        goto loop_3;
    }
    var_v1 = 0x2710;
    do {
        temp_v0 = var_v1;
        var_v1 -= 1;
    } while (temp_v0 != 0);
    if (gCd.unk24 != 0) {
        return 1;
    }
    goto loop_1;
}
INCLUDE_ASM("nonmatchings/sdk/csound", ezMidi__Fii);
INCLUDE_ASM("nonmatchings/sdk/csound", ezTransToIOP2__FPvPvi);
INCLUDE_ASM("nonmatchings/sdk/csound", BigToLittle__FPvPvi);
INCLUDE_ASM("nonmatchings/sdk/csound", GetDeltaTime__FPcPi);
INCLUDE_ASM("nonmatchings/sdk/csound", Initialize__8sndTrackFv);
void sndCSeSeqData::Initialize(void) {
    this->field_0x4 = 1;
    this->field_0x8 = 0;
    this->field_0xC = 0;
}
INCLUDE_ASM("nonmatchings/sdk/csound", LoadSMF__13sndCSeSeqDataFPciP9mgCMemory);
INCLUDE_ASM("nonmatchings/sdk/csound", Initialize__9sndCSeSeqFv);
INCLUDE_ASM("nonmatchings/sdk/csound", SetSeID__9sndCSeSeqFi);
struct inferred;
typedef struct sndCSeSeq_infere {
    /* 0x00 */ char pad0[8];
    /* 0x08 */ void *unk8;                          /* inferred */
    /* 0x0C */ char padC[4];
    /* 0x10 */ s32 unk10;                           /* inferred */
    /* 0x14 */ s32 unk14;                           /* inferred */
} sndCSeSeq_infere;                                        /* size >= 0x18 */
struct temp_v1_champs {
    char pad0[0x4];
    /* 0x4 */ s32 unk4;
};
extern "C" s32 fptosi(f32);
extern "C" void Count__9sndCSeSeqFf(sndCSeSeq_infere *objet, f32 arg0) {
    s32 temp_v0;
    struct temp_v1_champs *temp_v1;

    temp_v1 = (struct temp_v1_champs *) (objet->unk8);
    if (temp_v1 != NULL) {
        temp_v0 = (s32) (fptosi(((f32) temp_v1->unk4 * arg0) / 60.0f));
        objet->unk10 += temp_v0;
        objet->unk14 += temp_v0;
    }
}
typedef struct sndCSeSeq {
    /* 0x00 */ char pad0[8];
    /* 0x08 */ s32 unk8;                            /* inferred */
    /* 0x0C */ s32 unkC;                            /* inferred */
    /* 0x10 */ s32 unk10;                           /* inferred */
    /* 0x14 */ s32 unk14;                           /* inferred */
} sndCSeSeq;                                        /* size >= 0x18 */
extern "C" void AllNoteOff__9sndCSeSeqFv(sndCSeSeq *objet);
extern "C" void Stop__9sndCSeSeqFv(sndCSeSeq *objet) {
    AllNoteOff__9sndCSeSeqFv(objet);
    objet->unk14 = 0;
    objet->unk10 = 0;
    objet->unk8 = 0;
    objet->unkC = 0;
}
INCLUDE_ASM("nonmatchings/sdk/csound", Step__9sndCSeSeqFf);
INCLUDE_ASM("nonmatchings/sdk/csound", chk_trk__9sndCSeSeqFi);
INCLUDE_ASM("nonmatchings/sdk/csound", NoteOn__9sndCSeSeqFiii);
INCLUDE_ASM("nonmatchings/sdk/csound", NoteOff__9sndCSeSeqFiii);
INCLUDE_ASM("nonmatchings/sdk/csound", AllNoteOff__9sndCSeSeqFv);
INCLUDE_ASM("nonmatchings/sdk/csound", TrackNoteOff__9sndCSeSeqFi);
INCLUDE_ASM("nonmatchings/sdk/csound", CtrlChg__9sndCSeSeqFiii);
INCLUDE_ASM("nonmatchings/sdk/csound", ProgChg__9sndCSeSeqFii);
INCLUDE_ASM("nonmatchings/sdk/csound", PitchBend__9sndCSeSeqFiii);
INCLUDE_ASM("nonmatchings/sdk/csound", SendVol__9sndCSeSeqFi);
INCLUDE_ASM("nonmatchings/sdk/csound", SendPan__9sndCSeSeqFi);
INCLUDE_ASM("nonmatchings/sdk/csound", SendPitch__9sndCSeSeqFi);
INCLUDE_ASM("nonmatchings/sdk/csound", SaerchVoice__8sndTrackFii);
INCLUDE_ASM("nonmatchings/sdk/csound", GetEmptyVoice__8sndTrackFv);
extern "C" s32 GetEmptyVoice__8sndTrackFv(void *);
struct sndTrack_infere_8ca519;
typedef struct sndTrack_infere_8ca519 {
    /* 0x0 */ char pad0[2];
    /* 0x2 */ s8 unk2;                              /* inferred */
    /* 0x3 */ char pad3[3];                         /* maybe part of unk2[4]void */
    /* 0x6 */ s8 unk6;                              /* inferred */
} sndTrack_infere_8ca519;                                         /* size >= 0x7 */
struct temp_v0_champs_8ca519 {
    /* 0x0 */ s8 unk0;
    /* 0x1 */ s8 unk1;
    /* 0x2 */ s8 unk2;
    /* 0x3 */ s8 unk3;
};
extern "C" s32 SaerchVoice__8sndTrackFii(void *, s32, s32);
extern "C" s32 NoteOn__8sndTrackFii(sndTrack_infere_8ca519 *objet, s32 arg0, s32 arg1) {
    struct temp_v0_champs_8ca519 *temp_v0;

    if (SaerchVoice__8sndTrackFii(objet, (s32) objet->unk2, arg0) != 0) {
        return 1;
    }
    temp_v0 = (struct temp_v0_champs_8ca519 *) (GetEmptyVoice__8sndTrackFv(objet));
    if (temp_v0 == NULL) {
        return 0;
    }
    temp_v0->unk0 = 1;
    temp_v0->unk2 = (s8) arg0;
    temp_v0->unk1 = (s8) objet->unk2;
    temp_v0->unk3 = (s8) objet->unk6;
    return 1;
}
extern "C" s32 SaerchVoice__8sndTrackFii(void *, s32, s32);
struct inferred;
typedef struct sndTrack_infere {
    /* 0x0 */ char pad0[2];
    /* 0x2 */ s8 unk2;                              /* inferred */
} sndTrack_infere;                                         /* size >= 0x3 */
extern "C" s32 NoteOff__8sndTrackFii(sndTrack_infere *objet, s32 arg0, s32 arg1) {
    s8 *temp_v0;

    temp_v0 = (s8 *) (SaerchVoice__8sndTrackFii(objet, (s32) objet->unk2, arg0));
    if (temp_v0 == NULL) {
        return 0;
    }
    *temp_v0 = 0;
    return 1;
}
INCLUDE_ASM("nonmatchings/sdk/csound", CtrlChg__8sndTrackFii);
s32 sndTrack::ProgChg(s32 arg0) {
    this->field_0x2 = arg0;
    return 0;
}
s32 sndTrack::PitchBend(s32 arg0, s32 arg1) {
    this->field_0x4 = arg1;
    this->field_0x5 = arg0;
    return 1;
}
INCLUDE_ASM("nonmatchings/sdk/csound", Create__11CLoopSeMngrFiP9mgCMemory);
extern "C" void *__ct__15SND_LOOP_SE_SEQFv(void *objet) {
    *(s32 *) objet = -1;
    *(f32 *) ((u8 *) objet + 0xC) = -1.0f;
    *(s32 *) ((u8 *) objet + 0x10) = 0;
    return objet;
}
void CLoopSeMngr::Initialize(void) {
    this->field_0x0 = 0;
    this->field_0x4 = 0;
}
INCLUDE_ASM("nonmatchings/sdk/csound", Clear__11CLoopSeMngrFv);
INCLUDE_ASM("nonmatchings/sdk/csound", GetLoopSe__11CLoopSeMngrFPiUii);
extern "C" void SeLoopPlayStop__11CLoopSeMngrFUiiiffi(void *objet, u32 a, s32 b, s32 c, f32 d, f32 e, s32 f);
extern "C" void SeLoopPlayStop__11CLoopSeMngrFUiiii(void *objet, u32 a, s32 b, s32 c, s32 d) {
    SeLoopPlayStop__11CLoopSeMngrFUiiiffi(objet, a, b, c, -1.0f, 0.0f, d);
}
INCLUDE_ASM("nonmatchings/sdk/csound", SeLoopPlayStop__11CLoopSeMngrFUiiiffi);
INCLUDE_ASM("nonmatchings/sdk/csound", Step__11CLoopSeMngrFv);
INCLUDE_ASM("nonmatchings/sdk/csound", AllSeStop__11CLoopSeMngrFv);
INCLUDE_ASM("nonmatchings/sdk/csound", sndGetReverbDepth__Fi);
extern "C" u32 sndCreateID__FUii(u32 a, s32 b) {
    return (a & 0xFFFF0000) | (b & 0xFFFF);
}
extern "C" u32 sndGetSeNo__FUi(u32 arg0) {
    return arg0 & 0xFFFF;
}
INCLUDE_ASM("nonmatchings/sdk/csound", GetPortInfo__Fi);
INCLUDE_ASM("nonmatchings/sdk/csound", GetSeSeq__Fi);
INCLUDE_ASM("nonmatchings/sdk/csound", GetEmptySeSeq__FPi);
extern "C" u32 GetPortNo__FUi(u32 arg0) {
    return (arg0 >> 24) & 0xFF;
}
extern "C" u32 GetBankNo__FUi(u32 arg0) {
    return (arg0 >> 16) & 0xFF;
}
INCLUDE_ASM("nonmatchings/sdk/csound", GetBankInfo__FUi);
INCLUDE_ASM("nonmatchings/sdk/csound", GetSeInfo__FUii);
INCLUDE_ASM("nonmatchings/sdk/csound", sndInitMngr__Fv);
INCLUDE_ASM("nonmatchings/sdk/csound", sndWaitSema__Fv);
INCLUDE_ASM("nonmatchings/sdk/csound", sndSignalSema__Fv);
INCLUDE_ASM("nonmatchings/sdk/csound", sndInitPort__Fi);
INCLUDE_ASM("nonmatchings/sdk/csound", sndInitSeSeq__Fi);
INCLUDE_ASM("nonmatchings/sdk/csound", sndSetReverb__Fiii);
INCLUDE_ASM("nonmatchings/sdk/csound", sndStopVoice__Fi);
INCLUDE_ASM("nonmatchings/sdk/csound", SetMasterVol__Fif);
INCLUDE_ASM("nonmatchings/sdk/csound", FadeMasterVol__Fv);
INCLUDE_ASM("nonmatchings/sdk/csound", sndSetMasterVol__Fif);
INCLUDE_ASM("nonmatchings/sdk/csound", sndGetMasterVol__Fi);
INCLUDE_ASM("nonmatchings/sdk/csound", sndMasterVolFadeInOut__Fiiff);
INCLUDE_ASM("nonmatchings/sdk/csound", sndSetPortVol__Fif);
INCLUDE_ASM("nonmatchings/sdk/csound", sndGetPortVol__Fi);
struct CSound;
extern "C" void TransBdState__6CSoundFi(CSound *objet, s32 arg0);
extern "C" u8 CSnd;
extern "C" void sndTransBdState__Fv(void) {
    TransBdState__6CSoundFi((CSound *) &CSnd, 1);
}
INCLUDE_ASM("nonmatchings/sdk/csound", sndWaitTransBd__Fv);
INCLUDE_ASM("nonmatchings/sdk/csound", CSndStep__Fv);
INCLUDE_ASM("nonmatchings/sdk/csound", CSndStepWait__Fv);
INCLUDE_ASM("nonmatchings/sdk/csound", sndStep__Ff);
extern "C" void CSndStep__Fv();
extern "C" void sndSignalSema__Fv();
extern "C" void sndWaitSema__Fv();
extern "C" void sndFlush__Fv(void) {
    sndWaitSema__Fv();
    CSndStep__Fv();
    sndSignalSema__Fv();
}
INCLUDE_ASM("nonmatchings/sdk/csound", SeAllStop_Sub__Fi);
INCLUDE_ASM("nonmatchings/sdk/csound", sndSeAllStop__Fi);
extern "C" s32 GetSeInfo__FUii(u32, s32);
struct temp_v0_champs_c29f34 {
    char pad0[0x8];
    /* 0x8 */ s32 unk8;
};
extern "C" s8 sndGetSeDefVol__FUii(u32 arg0, s32 arg1) {
    struct temp_v0_champs_c29f34 *temp_v0;

    temp_v0 = (struct temp_v0_champs_c29f34 *) (GetSeInfo__FUii(arg0, arg1));
    if (temp_v0 != NULL) {
        return temp_v0->unk8;
    }
    return 0;
}
INCLUDE_ASM("nonmatchings/sdk/csound", IsBgmPort__Fi);
INCLUDE_ASM("nonmatchings/sdk/csound", GetCSndPortNo__FiPiPiPi);
INCLUDE_ASM("nonmatchings/sdk/csound", sndLoadSound__FiPUiP9mgCMemory);
extern "C" s32 Initialize__13sndCSeSeqDataFv(sndCSeSeqData *objet);
extern "C" sndCSeSeqData *__ct__13sndCSeSeqDataFv(sndCSeSeqData *objet) {
    Initialize__13sndCSeSeqDataFv(objet);
    return objet;
}
INCLUDE_ASM("nonmatchings/sdk/csound", sndDeletePort__Fi);
INCLUDE_ASM("nonmatchings/sdk/csound", GetPortBankNo__FUiPiPi);
extern "C" s32 sndSePlaySeID__FUiiiiiii(...);
extern "C" void sndSePlay__FUiii(u32 a, s32 b, s32 c) {
    sndSePlaySeID__FUiiiiiii(a, b, -1, -1, 0x40, 0x2000, c);
}
extern "C" s32 sndSePlaySeID__FUiiiiiii(...);
extern "C" void sndSePlayV__FUiiii(u32 a, s32 b, s32 c, s32 d) {
    sndSePlaySeID__FUiiiiiii(a, b, -1, c, 0x40, 0x2000, d);
}
extern "C" s32 sndSePlaySeID__FUiiiiiii(...);
extern "C" void sndSePlayVP__FUiiiii(u32 a, s32 b, s32 c, s32 d, s32 e) {
    sndSePlaySeID__FUiiiiiii(a, b, -1, c, d, 0x2000, e);
}
INCLUDE_ASM("nonmatchings/sdk/csound", sndSePlayVPf__FUiiffi);
INCLUDE_ASM("nonmatchings/sdk/csound", sndSePlayVf__FUiifi);
INCLUDE_ASM("nonmatchings/sdk/csound", sndSePause__FUii);
INCLUDE_ASM("nonmatchings/sdk/csound", sndGetSeStatus__FUii);
extern "C" s32 GetPortInfo__Fi(s32);
struct temp_v0_champs_5398fe {
    char pad0[0x4];
    /* 0x4 */ s32 unk4;
    char pad8[0x204];
    /* 0x20C */ s32 unk20C;
    /* 0x210 */ s32 unk210;
};
extern "C" s32 sndSqStop__Fii(s32, s32);
extern "C" void sndPortSqPause__Fi(s32 arg0) {
    struct temp_v0_champs_5398fe *temp_v0;

    temp_v0 = (struct temp_v0_champs_5398fe *) (GetPortInfo__Fi(arg0));
    if ((temp_v0 != NULL) && (temp_v0->unk210 == 1)) {
        sndSqStop__Fii(temp_v0->unk4, temp_v0->unk20C);
        temp_v0->unk210 = 3;
    }
}
extern "C" s32 GetPortInfo__Fi(s32);
struct temp_v0_champs {
    char pad0[0x4];
    /* 0x4 */ s32 unk4;
    char pad8[0x204];
    /* 0x20C */ s32 unk20C;
    /* 0x210 */ s32 unk210;
    /* 0x214 */ s32 unk214;
};
extern "C" s32 sndSetSqVol__Fiii(s32 arg0, s32 arg1, s32 arg2);
extern "C" s32 sndSqRePlay__Fii(s32 arg0, s32 arg1);
extern "C" void sndPortSqReplay__Fi(s32 arg0) {
    struct temp_v0_champs *temp_v0;

    temp_v0 = (struct temp_v0_champs *) (GetPortInfo__Fi(arg0));
    if ((temp_v0 != NULL) && (temp_v0->unk210 == 3)) {
        sndSqRePlay__Fii(temp_v0->unk4, temp_v0->unk20C);
        sndSetSqVol__Fiii(temp_v0->unk4, temp_v0->unk20C, temp_v0->unk214);
        temp_v0->unk210 = 1;
    }
}
INCLUDE_ASM("nonmatchings/sdk/csound", sndSeCheck__FUii);
INCLUDE_ASM("nonmatchings/sdk/csound", sndSePlaySeID__FUiiiiiii);
INCLUDE_ASM("nonmatchings/sdk/csound", sndSeStop__FUiii);
INCLUDE_ASM("nonmatchings/sdk/csound", sndSetSeVol__FUiiii);
INCLUDE_ASM("nonmatchings/sdk/csound", sndSetSePan__FUiiii);
INCLUDE_ASM("nonmatchings/sdk/csound", sndSetSeVolf__FUiifi);
INCLUDE_ASM("nonmatchings/sdk/csound", sndSetSePanf__FUiifi);
INCLUDE_ASM("nonmatchings/sdk/csound", sndSetSePitch__FUiiii);
INCLUDE_ASM("nonmatchings/sdk/csound", sndSetMicPos__FPfPf);
INCLUDE_ASM("nonmatchings/sdk/csound", sndGetVolPan__FPfPfPfff);
INCLUDE_ASM("nonmatchings/sdk/csound", sndGetVolPan__FPfPfPfPfff);
INCLUDE_ASM("nonmatchings/sdk/csound", sndVolLimit__Fi);
INCLUDE_ASM("nonmatchings/sdk/csound", sndSePlayPrKr__FUiiiiiiii);
INCLUDE_ASM("nonmatchings/sdk/csound", sndSeStopPrKr__FUiiii);
INCLUDE_ASM("nonmatchings/sdk/csound", sndSetSeVolPrKr__FUiiiii);
INCLUDE_ASM("nonmatchings/sdk/csound", sndSetSePanPrKr__FUiiiii);
INCLUDE_ASM("nonmatchings/sdk/csound", sndSetSePitchPrKr__FUiiiii);
INCLUDE_ASM("nonmatchings/sdk/csound", sndSePlayPBPrKr__Fiiiiiiiii);
extern "C" u8 CSnd;
extern "C" s32 SE_Stop__6CSoundFiiiii(void *, s32, s32, s32, s32, s32);
extern "C" void sndSeStopPBPrKr__Fiiiii(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    sndWaitSema__Fv();
    SE_Stop__6CSoundFiiiii(&CSnd, arg0, arg1, arg2, arg3, arg4);
    sndSignalSema__Fv();
}
INCLUDE_ASM("nonmatchings/sdk/csound", sndSetSeVolPBPrKr__Fiiiiii);
extern "C" u8 CSnd;
extern "C" s32 SE_SetPan__6CSoundFiiiiii(void *, s32, s32, s32, s32, s32, s32);
extern "C" void sndSetSePanPBPrKr__Fiiiiii(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    sndWaitSema__Fv();
    SE_SetPan__6CSoundFiiiiii(&CSnd, arg0, arg1, arg2, arg3, arg4, arg5);
    sndSignalSema__Fv();
}
extern "C" s32 SE_SetPitch__6CSoundFiiiiii(void *, s32, s32, s32, s32, s32, s32);
extern "C" void sndSetSePitchPBPrKr__Fiiiiii(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    sndWaitSema__Fv();
    SE_SetPitch__6CSoundFiiiiii(&CSnd, arg0, arg1, arg2, arg3, arg4, arg5);
    sndSignalSema__Fv();
}
extern "C" s32 SQ_Play__6CSoundFiii(void *, s32, s32, s32);
extern "C" void sndSqPlay__Fiii(s32 arg0, s32 arg1, s32 arg2) {
    sndWaitSema__Fv();
    SQ_Play__6CSoundFiii(&CSnd, arg0, arg1, arg2);
    sndSignalSema__Fv();
}
INCLUDE_ASM("nonmatchings/sdk/csound", sndSqStop__Fii);
INCLUDE_ASM("nonmatchings/sdk/csound", sndSetSqVol__Fiii);
INCLUDE_ASM("nonmatchings/sdk/csound", sndSqRePlay__Fii);
INCLUDE_ASM("nonmatchings/sdk/csound", GetLine__FPPcPcPc_00190D90);
INCLUDE_ASM("nonmatchings/sdk/csound", SearchSeq__11sndBankInfoFPcPi);
INCLUDE_ASM("nonmatchings/sdk/csound", LoadSeInfoTxt__11sndPortInfoFiPciP9mgCMemory);
sndSeInfo::sndSeInfo(void) {
    this->field_0x0 = 0;
    this->field_0x4 = 0;
}
INCLUDE_ASM("nonmatchings/sdk/csound", LoadVolInfoTxt__11sndPortInfoFiPci);
INCLUDE_ASM("nonmatchings/sdk/csound", sndStopSeSeq__Fi);
INCLUDE_ASM("nonmatchings/sdk/csound", PlaySeSeq__FUiP13sndCSeSeqDatai);
extern "C" s32 GetSeSeq__Fi(s32);
extern "C" void StopSeSeq__Fi(s32 arg0) {
    sndCSeSeq *temp_v0;

    temp_v0 = (sndCSeSeq *) (GetSeSeq__Fi(arg0));
    if (temp_v0 != NULL) {
        Stop__9sndCSeSeqFv(temp_v0);
    }
}
INCLUDE_ASM("nonmatchings/sdk/csound", SetVolSeSeq__Fii);
extern "C" s32 StreamOpenFast__6CSoundFiPc(...);
extern "C" void sndStreamOpenFast__FPc(s8 *arg0) {
    sndWaitSema__Fv();
    StreamOpenFast__6CSoundFiPc(&CSnd, 1, arg0);
    sndSignalSema__Fv();
}
extern "C" s32 StreamOpenState__6CSoundFv(void *);
extern "C" s32 sndStreamOpenState__Fv(void) {
    s32 temp_s0;

    sndWaitSema__Fv();
    temp_s0 = StreamOpenState__6CSoundFv(&CSnd);
    sndSignalSema__Fv();
    return temp_s0;
}
extern "C" s32 StreamStandBy__6CSoundFi(void *, s32);
extern "C" void sndStreamStandBy__Fv(void) {
    sndWaitSema__Fv();
    StreamStandBy__6CSoundFi(&CSnd, 1);
    sndSignalSema__Fv();
}
INCLUDE_ASM("nonmatchings/sdk/csound", sndStreamSetVol__Fff);
extern "C" void StreamPlay__6CSoundFi(void *, s32);
extern "C" void sndStreamPlay__Fv(void) {
    sndWaitSema__Fv();
    StreamPlay__6CSoundFi(&CSnd, 1);
    sndSignalSema__Fv();
}
extern "C" void StreamPause__6CSoundFi(void *, s32);
extern "C" void sndStreamPause__Fv(void) {
    sndWaitSema__Fv();
    StreamPause__6CSoundFi(&CSnd, 1);
    sndSignalSema__Fv();
}
extern "C" void StreamRePlay__6CSoundFi(void *, s32);
extern "C" void sndStreamRePlay__Fv(void) {
    sndWaitSema__Fv();
    StreamRePlay__6CSoundFi(&CSnd, 1);
    sndSignalSema__Fv();
}
extern "C" s32 StreamGetState__6CSoundFi(void *, s32);
extern "C" s32 sndStreamGetState__Fv(void) {
    s32 temp_s0;

    sndWaitSema__Fv();
    temp_s0 = StreamGetState__6CSoundFi(&CSnd, 1);
    sndSignalSema__Fv();
    return temp_s0;
}
INCLUDE_ASM("nonmatchings/sdk/csound", sndStreamClose__Fv);
INCLUDE_ASM("nonmatchings/sdk/csound", __ct__9sndCSeSeqFv);
INCLUDE_ASM("nonmatchings/sdk/csound", __ct__11sndPortInfoFv);
