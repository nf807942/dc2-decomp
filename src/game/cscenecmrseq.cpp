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
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", GetNextSeq__12CSceneCmrSeqFP12_SEN_CMR_SEQi);
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
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", scsSePlay__FP12_SEN_OBJ_SEQP12CSceneObjSeq);
s32 scsDummy(_SEN_OBJ_SEQ *sequence, CSceneObjSeq *owner) {
    return 1;
}
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", InitSceneObjSeq__FP12_SEN_OBJ_SEQ);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", __ct__12CSceneObjSeqFv);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", ZeroInitialize__12CSceneObjSeqFv);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", Initialize__12CSceneObjSeqFP12_SEN_OBJ_SEQi);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", Clear__12CSceneObjSeqFv);
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
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", Set__4CEohFiP7CObjecti);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", Set__4CEohFiiP11CCharacter2);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", Set__4CEohFiP13CEventSprite2);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", Set__4CEohFiP8mgCFrame);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", Set__4CEohFiP10CFuncPoint);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", VectMatMul__FPfPfPA4_f_00260A70);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", CalcPosWorldCoord__FPf);
