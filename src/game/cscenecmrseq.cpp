/* CSceneCmrSeq, CSceneObjSeq, CEoh
 *
 * Unité découpée par `make carve` : 174 fonctions, 24600 octets, de
 * 0x0025A670 à 0x00260B80. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"
#include "gen/CEoh.hpp"
#include "gen/CSceneCmrSeq.hpp"
#include "gen/CSceneObjSeq.hpp"

/* Le corps ne rend qu'un code : ni la classe ni les arguments ne sont
 * déréférencés, donc leur disposition reste à établir. */
struct _SEN_CMR_SEQ;
struct _SEN_OBJ_SEQ;
struct CSceneCmrSeq;
struct CSceneObjSeq;

INCLUDE_ASM("nonmatchings/game/cscenecmrseq", scsMoveAHD2__FP12_SEN_CMR_SEQP12CSceneCmrSeq);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", scsSetSyncObj__FP12_SEN_CMR_SEQP12CSceneCmrSeq);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", scsReleaseSyncObj__FP12_SEN_CMR_SEQP12CSceneCmrSeq);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", scsAHDSlowing__FP12_SEN_CMR_SEQP12CSceneCmrSeq);
s32 scsAHDKeep(_SEN_CMR_SEQ * arg0, CSceneCmrSeq * arg1) {
    arg1->field_0x34 = arg0;
    return 0;
}
s32 scsAHDReturn(_SEN_CMR_SEQ *sequence, CSceneCmrSeq *owner) {
    return 2;
}
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", scsInitPas__FP12_SEN_CMR_SEQP12CSceneCmrSeq);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", scsSetPasFrm__FP12_SEN_CMR_SEQP12CSceneCmrSeq);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", scsAddPas__FP12_SEN_CMR_SEQP12CSceneCmrSeq);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", scsStartPas__FP12_SEN_CMR_SEQP12CSceneCmrSeq);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", scsPRSlowing__FP12_SEN_CMR_SEQP12CSceneCmrSeq);
s32 scsPRKeep(_SEN_CMR_SEQ * arg0, CSceneCmrSeq * arg1) {
    arg1->field_0x30 = arg0;
    return 0;
}
s32 scsPRReturn(_SEN_CMR_SEQ *sequence, CSceneCmrSeq *owner) {
    return 2;
}
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", scsFadeDelay__FP12_SEN_CMR_SEQP12CSceneCmrSeq);
s32 scsFadeInit(_SEN_CMR_SEQ *sequence, CSceneCmrSeq *owner) {
    return 0;
}
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", scsFadeIn__FP12_SEN_CMR_SEQP12CSceneCmrSeq);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", scsFadeOut__FP12_SEN_CMR_SEQP12CSceneCmrSeq);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", scsQuakeDelay__FP12_SEN_CMR_SEQP12CSceneCmrSeq);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", scsQuake__FP12_SEN_CMR_SEQP12CSceneCmrSeq);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", scsQuake2__FP12_SEN_CMR_SEQP12CSceneCmrSeq);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", scsCharaDelay__FP12_SEN_CMR_SEQP12CSceneCmrSeq);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", scsCharaAttach__FP12_SEN_CMR_SEQP12CSceneCmrSeq);
s32 scsDummy(_SEN_CMR_SEQ *sequence, CSceneCmrSeq *owner) {
    return 1;
}
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", InitSceneCmrSeq__FP12_SEN_CMR_SEQ);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", __ct__12CSceneCmrSeqFv);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", ZeroInitialize__12CSceneCmrSeqFv);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", Initialize__12CSceneCmrSeqFP12_SEN_CMR_SEQi);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", Clear__12CSceneCmrSeqFv);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", CheckEnd__12CSceneCmrSeqFv);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", Play__12CSceneCmrSeqFv);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", SearchSeq__12CSceneCmrSeqFv);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", SearchNextPrSeq__12CSceneCmrSeqFv);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", SearchNextAhdSeq__12CSceneCmrSeqFv);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", SearchNextFadeSeq__12CSceneCmrSeqFv);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", SearchNextQuakeSeq__12CSceneCmrSeqFv);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", SearchNextCharaSeq__12CSceneCmrSeqFv);
struct irregular;
typedef struct CSceneCmrSeq_infere {
    /* 0x00 */ char pad0[0x30];
    /* 0x30 */ s32 unk30;                           /* inferred */
    /* 0x34 */ s32 unk34;                           /* inferred */
} CSceneCmrSeq_infere;                                     /* size >= 0x38 */
typedef struct _SEN_CMR_SEQ {
    /* 0x00 */ char pad0[0x5C];
    /* 0x5C */ s32 unk5C;                           /* inferred */
} _SEN_CMR_SEQ;                                     /* size >= 0x60 */
extern "C" s32 InitSceneCmrSeq__FP12_SEN_CMR_SEQ(_SEN_CMR_SEQ *arg0);
extern "C" s32 GetNextSeq__12CSceneCmrSeqFP12_SEN_CMR_SEQi(CSceneCmrSeq_infere *objet, _SEN_CMR_SEQ *arg0, s32 arg1) {
    s32 temp_s0;

    if (arg0 == NULL) {
        return 0;
    }
    temp_s0 = arg0->unk5C;
    switch (arg1) {                                 /* irregular */
    case 0:
        if (objet->unk30 == 0) {
            InitSceneCmrSeq__FP12_SEN_CMR_SEQ(arg0);
        }
        break;
    case 1:
        if (objet->unk34 == 0) {
            InitSceneCmrSeq__FP12_SEN_CMR_SEQ(arg0);
        }
        break;
    case 2:
        InitSceneCmrSeq__FP12_SEN_CMR_SEQ(arg0);
        break;
    }
    return temp_s0;
}
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", PRDelay__12CSceneCmrSeqFi);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", SetPos__12CSceneCmrSeqFPf);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", SetRef__12CSceneCmrSeqFPf);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", Move__12CSceneCmrSeqFPfPfi);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", Move2__12CSceneCmrSeqFPfPfiif);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", MoveRef__12CSceneCmrSeqFPfi);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", MovePos__12CSceneCmrSeqFPfi);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", InitPas__12CSceneCmrSeqFv);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", SetPasFrm__12CSceneCmrSeqFi);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", AddPas__12CSceneCmrSeqFPfPf);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", StartPas__12CSceneCmrSeqFv);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", PRSlowing__12CSceneCmrSeqFfi);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", PRKeep__12CSceneCmrSeqFv);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", PRReturn__12CSceneCmrSeqFv);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", AHDDelay__12CSceneCmrSeqFi);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", SetAngle__12CSceneCmrSeqFf);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", SetHeight__12CSceneCmrSeqFf);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", SetDist__12CSceneCmrSeqFf);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", SetAHD__12CSceneCmrSeqFfff);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", MoveAHD__12CSceneCmrSeqFfffi);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", MoveAHD2__12CSceneCmrSeqFfffiif);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", SetSyncObj__12CSceneCmrSeqFiPffffiPc);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", ReleaseSyncObj__12CSceneCmrSeqFv);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", AHDSlowing__12CSceneCmrSeqFfi);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", AHDKeep__12CSceneCmrSeqFv);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", AHDReturn__12CSceneCmrSeqFv);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", FadeDelay__12CSceneCmrSeqFi);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", FadeInit__12CSceneCmrSeqFv);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", FadeIn__12CSceneCmrSeqFifff);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", FadeOut__12CSceneCmrSeqFifff);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", QuakeDelay__12CSceneCmrSeqFi);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", Quake__12CSceneCmrSeqFPfi);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", Quake2__12CSceneCmrSeqFPfi);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", CharaDelay__12CSceneCmrSeqFi);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", CharaAttach__12CSceneCmrSeqFifi);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", scsPosDelay__FP12_SEN_OBJ_SEQP12CSceneObjSeq);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", scsSetPos__FP12_SEN_OBJ_SEQP12CSceneObjSeq);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", scsMove__FP12_SEN_OBJ_SEQP12CSceneObjSeq);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", scsMove2__FP12_SEN_OBJ_SEQP12CSceneObjSeq);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", scsInitPas__FP12_SEN_OBJ_SEQP12CSceneObjSeq);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", scsSetPasFrm__FP12_SEN_OBJ_SEQP12CSceneObjSeq);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", scsAddPas__FP12_SEN_OBJ_SEQP12CSceneObjSeq);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", scsStartPas__FP12_SEN_OBJ_SEQP12CSceneObjSeq);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", scsJump__FP12_SEN_OBJ_SEQP12CSceneObjSeq);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", scsSetEohFramePos__FP12_SEN_OBJ_SEQP12CSceneObjSeq);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", scsAddPos__FP12_SEN_OBJ_SEQP12CSceneObjSeq);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", scsAttachCamera__FP12_SEN_OBJ_SEQP12CSceneObjSeq);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", scsResetDAPosition__FP12_SEN_OBJ_SEQP12CSceneObjSeq);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", scsRotDelay__FP12_SEN_OBJ_SEQP12CSceneObjSeq);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", scsSetRot__FP12_SEN_OBJ_SEQP12CSceneObjSeq);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", scsRotation__FP12_SEN_OBJ_SEQP12CSceneObjSeq);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", scsRotation2__FP12_SEN_OBJ_SEQP12CSceneObjSeq);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", scsReference__FP12_SEN_OBJ_SEQP12CSceneObjSeq);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", scsMotionDelay__FP12_SEN_OBJ_SEQP12CSceneObjSeq);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", scsSetMotion__FP12_SEN_OBJ_SEQP12CSceneObjSeq);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", scsNextMotion__FP12_SEN_OBJ_SEQP12CSceneObjSeq);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", scsMotionWait__FP12_SEN_OBJ_SEQP12CSceneObjSeq);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", scsMotionTrg__FP12_SEN_OBJ_SEQP12CSceneObjSeq);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", scsSetMotStep__FP12_SEN_OBJ_SEQP12CSceneObjSeq);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", scsSetMotChangeStep__FP12_SEN_OBJ_SEQP12CSceneObjSeq);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", scsResetMotion__FP12_SEN_OBJ_SEQP12CSceneObjSeq);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", scsSetMotionNowTime__FP12_SEN_OBJ_SEQP12CSceneObjSeq);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", scsSetMotionWaitTime__FP12_SEN_OBJ_SEQP12CSceneObjSeq);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", scsNormalDrive__FP12_SEN_OBJ_SEQP12CSceneObjSeq);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", scsMotionTrgWait__FP12_SEN_OBJ_SEQP12CSceneObjSeq);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", scsTexAnimeDelay__FP12_SEN_OBJ_SEQP12CSceneObjSeq);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", scsTexAnime__FP12_SEN_OBJ_SEQP12CSceneObjSeq);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", scsColorDelay__FP12_SEN_OBJ_SEQP12CSceneObjSeq);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", scsSetColor__FP12_SEN_OBJ_SEQP12CSceneObjSeq);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", scsScaleDelay__FP12_SEN_OBJ_SEQP12CSceneObjSeq);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", scsSetScale__FP12_SEN_OBJ_SEQP12CSceneObjSeq);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", scsSeDelay__FP12_SEN_OBJ_SEQP12CSceneObjSeq);
typedef struct _SEN_OBJ_SEQ_infere {
    /* 0x00 */ char pad0[0x20];
    /* 0x20 */ u32 unk20;                           /* inferred */
    /* 0x24 */ s32 unk24;                           /* inferred */
} _SEN_OBJ_SEQ_infere;                                     /* size >= 0x28 */
extern "C" s32 sndSePlay__FUiii(u32 arg0, s32 arg1, s32 arg2);
extern "C" s32 scsSePlay__FP12_SEN_OBJ_SEQP12CSceneObjSeq(_SEN_OBJ_SEQ_infere *arg0, CSceneObjSeq *arg1) {
    sndSePlay__FUiii(arg0->unk20, arg0->unk24, 0);
    return 0;
}
s32 scsDummy(_SEN_OBJ_SEQ *sequence, CSceneObjSeq *owner) {
    return 1;
}
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", InitSceneObjSeq__FP12_SEN_OBJ_SEQ);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", __ct__12CSceneObjSeqFv);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", ZeroInitialize__12CSceneObjSeqFv);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", Initialize__12CSceneObjSeqFP12_SEN_OBJ_SEQi);
typedef struct CSceneObjSeq_infere {
    /* 0x000 */ char pad0[8];
    /* 0x008 */ s32 unk8;                           /* inferred */
    /* 0x00C */ s32 unkC;                           /* inferred */
    /* 0x010 */ s32 unk10;                          /* inferred */
    /* 0x014 */ s32 unk14;                          /* inferred */
    /* 0x018 */ s32 unk18;                          /* inferred */
    /* 0x01C */ s32 unk1C;                          /* inferred */
    /* 0x020 */ s32 unk20;                          /* inferred */
    /* 0x024 */ s32 unk24;                          /* inferred */
    /* 0x028 */ s32 unk28;                          /* inferred */
    /* 0x02C */ s32 unk2C;                          /* inferred */
    /* 0x030 */ s32 unk30;                          /* inferred */
    /* 0x034 */ s32 unk34;                          /* inferred */
    /* 0x038 */ s32 unk38;                          /* inferred */
    /* 0x03C */ s32 unk3C;                          /* inferred */
    /* 0x040 */ s32 unk40;                          /* inferred */
    /* 0x044 */ s32 unk44;                          /* inferred */
    /* 0x048 */ s32 unk48;                          /* inferred */
    /* 0x04C */ s32 unk4C;                          /* inferred */
    /* 0x050 */ s32 unk50;                          /* inferred */
    /* 0x054 */ s32 unk54;                          /* inferred */
    /* 0x058 */ s32 unk58;                          /* inferred */
    /* 0x05C */ char pad5C[8];                      /* maybe part of unk58[3]? */
    /* 0x064 */ s32 unk64;                          /* inferred */
    /* 0x068 */ char pad68[8];                      /* maybe part of unk64[3]? */
    /* 0x070 */ f32 unk70;                          /* inferred */
    /* 0x074 */ char pad74[0xC];                    /* maybe part of unk70[4]? */
    /* 0x080 */ f32 unk80;                          /* inferred */
    /* 0x084 */ char pad84[0x2C];                   /* maybe part of unk80[0xC]? */
    /* 0x0B0 */ f32 unkB0;                          /* inferred */
    /* 0x0B4 */ char padB4[0xC];                    /* maybe part of unkB0[4]? */
    /* 0x0C0 */ f32 unkC0;                          /* inferred */
    /* 0x0C4 */ char padC4[0xC];                    /* maybe part of unkC0[4]? */
    /* 0x0D0 */ f32 unkD0;                          /* inferred */
    /* 0x0D4 */ char padD4[0xC];                    /* maybe part of unkD0[4]? */
    /* 0x0E0 */ f32 unkE0;                          /* inferred */
    /* 0x0E4 */ char padE4[0xC];                    /* maybe part of unkE0[4]? */
    /* 0x0F0 */ s32 unkF0;                          /* inferred */
    /* 0x0F4 */ s32 unkF4;                          /* inferred */
    /* 0x0F8 */ char padF8[0x28];                   /* maybe part of unkF4[0xB]? */
    /* 0x120 */ f32 unk120;                         /* inferred */
} CSceneObjSeq_infere;                                     /* size >= 0x124 */
extern "C" s32 mgZeroVector__FPf(f32 *arg0);
extern "C" void Clear__12CSceneObjSeqFv(CSceneObjSeq_infere *objet) {
    objet->unk64 = -1;
    mgZeroVector__FPf(&objet->unk70);
    mgZeroVector__FPf(&objet->unk80);
    mgZeroVector__FPf(&objet->unk120);
    mgZeroVector__FPf(&objet->unkB0);
    mgZeroVector__FPf(&objet->unkD0);
    objet->unkF0 = 0;
    mgZeroVector__FPf(&objet->unkC0);
    mgZeroVector__FPf(&objet->unkE0);
    objet->unkF4 = 0;
    objet->unk8 = 0;
    objet->unkC = 0;
    objet->unk10 = 0;
    objet->unk14 = 0;
    objet->unk18 = 0;
    objet->unk1C = 0;
    objet->unk20 = 0;
    objet->unk24 = 0;
    objet->unk28 = 0;
    objet->unk2C = 0;
    objet->unk30 = 0;
    objet->unk34 = 0;
    objet->unk38 = 0;
    objet->unk3C = 0;
    objet->unk40 = 0;
    objet->unk44 = 0;
    objet->unk48 = 0;
    objet->unk4C = 0;
    objet->unk50 = 0;
    objet->unk54 = 0;
    objet->unk58 = 0;
}
void CSceneObjSeq::SetEohNo(s32 arg0) {
    this->field_0x64 = arg0;
}
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", SearchSeq__12CSceneObjSeqFv);
typedef struct _SEN_OBJ_SEQ {
    /* 0x00 */ char pad0[0x4C];
    /* 0x4C */ s32 unk4C;                           /* inferred */
} _SEN_OBJ_SEQ;                                     /* size >= 0x50 */
extern "C" void InitSceneObjSeq__FP12_SEN_OBJ_SEQ(_SEN_OBJ_SEQ *arg0);
extern "C" s32 GetNextSeq__12CSceneObjSeqFP12_SEN_OBJ_SEQ(CSceneObjSeq *objet, _SEN_OBJ_SEQ *arg0) {
    s32 temp_s0;

    if (arg0 == NULL) {
        return 0;
    }
    temp_s0 = arg0->unk4C;
    InitSceneObjSeq__FP12_SEN_OBJ_SEQ(arg0);
    return temp_s0;
}
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", SearchNextPosSeq__12CSceneObjSeqFv);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", SearchNextRotSeq__12CSceneObjSeqFv);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", SearchNextMotSeq__12CSceneObjSeqFv);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", SearchNextAnmSeq__12CSceneObjSeqFv);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", SearchNextColSeq__12CSceneObjSeqFv);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", SearchNextScaleSeq__12CSceneObjSeqFv);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", SearchNextSeSeq__12CSceneObjSeqFv);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", CheckEnd__12CSceneObjSeqFv);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", Play__12CSceneObjSeqFv);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", PosDelay__12CSceneObjSeqFi);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", SetPos__12CSceneObjSeqFPf);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", Move__12CSceneObjSeqFPfii);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", Move2__12CSceneObjSeqFPfiif);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", InitPas__12CSceneObjSeqFv);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", SetPasFrm__12CSceneObjSeqFi);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", AddPas__12CSceneObjSeqFPf);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", StartPas__12CSceneObjSeqFi);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", Jump__12CSceneObjSeqFPffi);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", SetEohFramePos__12CSceneObjSeqFiPciPf);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", AddPos__12CSceneObjSeqFPfi);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", AttachCamera__12CSceneObjSeqFfi);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", RotDelay__12CSceneObjSeqFi);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", SetRot__12CSceneObjSeqFPf);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", Rotation__12CSceneObjSeqFPfi);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", Rotation2__12CSceneObjSeqFPfiif);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", Reference__12CSceneObjSeqFPfi);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", MotionDelay__12CSceneObjSeqFi);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", SetMotion__12CSceneObjSeqFPcif);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", NextMotion__12CSceneObjSeqFPcif);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", MotionWait__12CSceneObjSeqFv);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", SetMotionTrg__12CSceneObjSeqFv);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", MotionTrgWait__12CSceneObjSeqFv);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", SetStep__12CSceneObjSeqFf);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", SetChengeStep__12CSceneObjSeqFf);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", ResetMotion__12CSceneObjSeqFv);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", SetMotionNowTime__12CSceneObjSeqFf);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", SetMotionWaitTime__12CSceneObjSeqFf);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", NormalDrive__12CSceneObjSeqFv);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", TexAnimeDelay__12CSceneObjSeqFi);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", TexAnime__12CSceneObjSeqFPci);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", ColorDelay__12CSceneObjSeqFi);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", SetColor__12CSceneObjSeqFPfi);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", ScaleDelay__12CSceneObjSeqFi);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", SetScale__12CSceneObjSeqFPfi);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", SeDelay__12CSceneObjSeqFi);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", SePlay__12CSceneObjSeqFii);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", ResetDAPosition__12CSceneObjSeqFv);
CEoh::CEoh(void) {
    this->field_0x0 = -1;
    this->field_0x4 = -1;
    this->field_0x8 = 1;
    this->field_0xC = 0;
    this->field_0xC = 0;
    this->field_0xC = 0;
    this->field_0xC = 0;
    this->field_0xC = 0;
}
struct CObject {
    f32 field_0;
    char pad_4[0xC];
    f32 field_10;
    f32 field_14;
    f32 field_18;
    f32 field_1C;
    f32 field_20;
    f32 field_24;
    f32 field_28;
    f32 field_2C;
    f32 field_30;
    f32 field_34;
    f32 field_38;
    f32 field_3C;
    s32 field_40;
    s32 field_44;
    char pad_48[0x8];
    f32 field_50;
    s32 field_54;
    f32 field_58;
    f32 field_5C;
    f32 field_60;
    s32 field_64;
    s32 field_68;
    char pad_6C[0x4];
    s32 field_70;
    char pad_74[0xC];
    f32 field_80;
    f32 field_84;
    f32 field_88;
    s32 field_8C;
    s32 field_90;
    s32 field_94;
    f32 field_98;
    f32 field_9C;
    f32 field_A0;
    char pad_A4[0x5C];
    f32 field_100;
    s32 field_104;
    s32 field_108;
    f32 field_10C;
    f32 field_110;
    f32 field_114;
    s32 field_118;
    s32 field_11C;
    s16 field_120;
    char pad_122[0x2];
    s32 field_124;
    s32 field_128;
    s32 field_12C;
    s32 field_130;
    s32 field_134;
    f32 field_138;
    f32 field_13C;
    char pad_140[0x180];
    s32 field_2C0;
    f32 field_2C4;
    f32 field_2C8;
    f32 field_2CC;
    f32 field_2D0;
    f32 field_2D4;
    f32 field_2D8;
    s32 field_2DC;
    s32 field_2E0;
    s32 field_2E4;
    char pad_2E8[0x60];
    s32 field_348;
    s32 field_34C;
    s32 field_350;
    s32 field_354;
    s32 field_358;
    s32 field_35C;
    s32 field_360;
    s32 field_364;
    s32 field_368;
    s32 field_36C;
    s32 field_370;
    s32 field_374;
    s32 field_378;
    s32 field_37C;
    s32 field_380;
    s32 field_384;
    f32 field_388;
    f32 field_38C;
    f32 field_390;
    s32 field_394;
    s32 field_398;
    s32 field_39C;
    f32 field_3A0;
    s32 field_3A4;
    s32 field_3A8;
    s32 field_3AC;
    s32 field_3B0;
    s32 field_3B4;
    s32 field_3B8;
    s32 field_3BC;
    char pad_3C0[0x140];
    s32 field_500;
    s32 field_504;
    f32 field_508;
    f32 field_50C;
    f32 field_510;
    f32 field_514;
    f32 field_518;
    f32 field_51C;
    f32 field_520;
    f32 field_524;
    f32 field_528;
    f32 field_52C;
    f32 field_530;
    f32 field_534;
    f32 field_538;
    f32 field_53C;
    f32 field_540;
    f32 field_544;
    f32 field_548;
    f32 field_54C;
    f32 field_550;
    f32 field_554;
    f32 field_558;
    f32 field_55C;
    f32 field_560;
    f32 field_564;
    f32 field_568;
    f32 field_56C;
    f32 field_570;
    f32 field_574;
    f32 field_578;
    f32 field_57C;
    f32 field_580;
    f32 field_584;
    f32 field_588;
    f32 field_58C;
    f32 field_590;
    f32 field_594;
    f32 field_598;
    f32 field_59C;
    f32 field_5A0;
    f32 field_5A4;
    f32 field_5A8;
    f32 field_5AC;
    f32 field_5B0;
    f32 field_5B4;
    f32 field_5B8;
    f32 field_5BC;
    f32 field_5C0;
    f32 field_5C4;
    f32 field_5C8;
    f32 field_5CC;
    f32 field_5D0;
    f32 field_5D4;
    f32 field_5D8;
    f32 field_5DC;
    f32 field_5E0;
    s32 field_5E4;
    s32 field_5E8;
    char pad_5EC[0x60];
    s32 field_64C;
    s32 field_650;
};
typedef struct CEoh_infere {
    /* 0x00 */ s32 unk0;                            /* inferred */
    /* 0x04 */ char pad4[4];
    /* 0x08 */ s32 unk8;                            /* inferred */
    /* 0x0C */ CObject *unkC;                       /* inferred */
} CEoh_infere;                                             /* size >= 0x10 */
extern "C" s32 Set__4CEohFiP7CObjecti(CEoh_infere *objet, s32 arg0, CObject *arg1, s32 arg2) {
    if (arg1 == NULL) {
        return 0;
    }
    objet->unk0 = arg0;
    if (objet->unk0 != 1) {
        return 0;
    }
    objet->unkC = arg1;
    objet->unk8 = arg2;
    return 1;
}
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", Set__4CEohFiiP11CCharacter2);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", Set__4CEohFiP13CEventSprite2);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", Set__4CEohFiP8mgCFrame);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", Set__4CEohFiP10CFuncPoint);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", VectMatMul__FPfPfPA4_f_00260A70);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", CalcPosWorldCoord__FPf);
