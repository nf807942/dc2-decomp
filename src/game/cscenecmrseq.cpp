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
extern "C" s32 SearchNextAhdSeq__12CSceneCmrSeqFv(void *);
extern "C" s32 SearchNextAnmSeq__12CSceneObjSeqFv(void *);
extern "C" s32 SearchNextCharaSeq__12CSceneCmrSeqFv(void *);
extern "C" s32 SearchNextColSeq__12CSceneObjSeqFv(void *);
extern "C" s32 SearchNextFadeSeq__12CSceneCmrSeqFv(void *);
extern "C" s32 SearchNextMotSeq__12CSceneObjSeqFv(void *);
extern "C" s32 SearchNextPosSeq__12CSceneObjSeqFv(void *);
extern "C" s32 SearchNextPrSeq__12CSceneCmrSeqFv(void *);
extern "C" s32 SearchNextQuakeSeq__12CSceneCmrSeqFv(void *);
extern "C" s32 SearchNextRotSeq__12CSceneObjSeqFv(void *);
extern "C" s32 SearchNextScaleSeq__12CSceneObjSeqFv(void *);
extern "C" s32 SearchNextSeSeq__12CSceneObjSeqFv(void *);
extern "C" s32 SearchNextPrSeq__12CSceneCmrSeqFv(void *);
extern "C" s32 sceVu0CopyVector(...);

INCLUDE_ASM("nonmatchings/game/cscenecmrseq", scsMoveAHD2__FP12_SEN_CMR_SEQP12CSceneCmrSeq);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", scsSetSyncObj__FP12_SEN_CMR_SEQP12CSceneCmrSeq);
extern "C" char _1527_00371A40[];
extern "C" s32 strcpy(...);
extern "C" s32 mgZeroVector__FPf(f32 *arg0);
extern "C" s32 scsReleaseSyncObj__FP12_SEN_CMR_SEQP12CSceneCmrSeq(_SEN_CMR_SEQ *arg0, CSceneCmrSeq *arg1) {
    s32 *p = (s32 *) arg1;
    p[31] = 0;
    p[32] = 0;
    p[33] = 0;
    mgZeroVector__FPf((f32 *) (p + 36));
    p[40] = 0;
    p[41] = 0;
    p[42] = 0;
    strcpy((u8 *) p + 0xAC, _1527_00371A40);
    return 0;
}
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", scsAHDSlowing__FP12_SEN_CMR_SEQP12CSceneCmrSeq);
s32 scsAHDKeep(_SEN_CMR_SEQ * arg0, CSceneCmrSeq * arg1) {
    arg1->field_0x34 = arg0;
    return 0;
}
s32 scsAHDReturn(_SEN_CMR_SEQ *sequence, CSceneCmrSeq *owner) {
    return 2;
}
struct _SEN_CMR_SEQ_f5ef6a {
    s32 field_0;
    char pad_4[0xC];
    f32 field_10;
    f32 field_14;
    f32 field_18;
    char pad_1C[0x4];
    f32 field_20;
    char pad_24[0xC];
    s32 field_30;
    s32 field_34;
    f32 field_38;
    s8 field_3C;
};
struct CSceneCmrSeq_infere_f5ef6a;
typedef struct CSceneCmrSeq_infere_f5ef6a {
    /* 0x000 */ char pad0[0x1C0];
    /* 0x1C0 */ char pad1C0[1];
} CSceneCmrSeq_infere_f5ef6a;                                     /* size >= 0x1C1 */
struct arg1_champs_f5ef6a {
    char pad0[0x1C0];
    /* 0x1C0 */ s32 unk1C0;
};
extern "C" s32 Initialize__10CCameraPasFv(void *);
extern "C" s32 scsInitPas__FP12_SEN_CMR_SEQP12CSceneCmrSeq(_SEN_CMR_SEQ_f5ef6a *arg0, CSceneCmrSeq_infere_f5ef6a *arg1) {
    Initialize__10CCameraPasFv(&((struct arg1_champs_f5ef6a *) arg1)->unk1C0);
    return 0;
}
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
struct inferred;
typedef struct CSceneCmrSeq_infere3 {
    /* 0x00 */ char pad0[0x40];
    /* 0x40 */ s32 unk40;                           /* inferred */
} CSceneCmrSeq_infere3;                                     /* size >= 0x44 */
typedef struct _SEN_CMR_SEQ_infere {
    /* 0x00 */ char pad0[0x30];
    /* 0x30 */ s32 unk30;                           /* inferred */
} _SEN_CMR_SEQ_infere;                                     /* size >= 0x34 */
extern "C" s32 scsFadeDelay__FP12_SEN_CMR_SEQP12CSceneCmrSeq(_SEN_CMR_SEQ_infere *arg0, CSceneCmrSeq_infere3 *arg1) {
    s32 temp_v1;

    temp_v1 = arg1->unk40;
    if (temp_v1 >= arg0->unk30) {
        arg1->unk40 = 0;
        return 0;
    }
    arg1->unk40 = temp_v1 + 1;
    return 1;
}
s32 scsFadeInit(_SEN_CMR_SEQ *sequence, CSceneCmrSeq *owner) {
    return 0;
}
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", scsFadeIn__FP12_SEN_CMR_SEQP12CSceneCmrSeq);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", scsFadeOut__FP12_SEN_CMR_SEQP12CSceneCmrSeq);
struct inferred;
typedef struct CSceneCmrSeq_infere4 {
    /* 0x00 */ char pad0[0x44];
    /* 0x44 */ s32 unk44;                           /* inferred */
} CSceneCmrSeq_infere4;                                     /* size >= 0x48 */
typedef struct _SEN_CMR_SEQ_infere2 {
    /* 0x00 */ char pad0[0x30];
    /* 0x30 */ s32 unk30;                           /* inferred */
} _SEN_CMR_SEQ_infere2;                                     /* size >= 0x34 */
extern "C" s32 scsQuakeDelay__FP12_SEN_CMR_SEQP12CSceneCmrSeq(_SEN_CMR_SEQ_infere2 *arg0, CSceneCmrSeq_infere4 *arg1) {
    s32 temp_v1;

    temp_v1 = arg1->unk44;
    if (temp_v1 >= arg0->unk30) {
        arg1->unk44 = 0;
        return 0;
    }
    arg1->unk44 = temp_v1 + 1;
    return 1;
}
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", scsQuake__FP12_SEN_CMR_SEQP12CSceneCmrSeq);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", scsQuake2__FP12_SEN_CMR_SEQP12CSceneCmrSeq);
typedef struct CSceneCmrSeq_infere5 {
    /* 0x00 */ char pad0[0x48];
    /* 0x48 */ s32 unk48;                           /* inferred */
} CSceneCmrSeq_infere5;                                     /* size >= 0x4C */
typedef struct _SEN_CMR_SEQ_infere3 {
    /* 0x00 */ char pad0[0x30];
    /* 0x30 */ s32 unk30;                           /* inferred */
} _SEN_CMR_SEQ_infere3;                                     /* size >= 0x34 */
extern "C" s32 scsCharaDelay__FP12_SEN_CMR_SEQP12CSceneCmrSeq(_SEN_CMR_SEQ_infere3 *arg0, CSceneCmrSeq_infere5 *arg1) {
    s32 temp_v1;

    temp_v1 = arg1->unk48;
    if (temp_v1 >= arg0->unk30) {
        arg1->unk48 = 0;
        return 0;
    }
    arg1->unk48 = temp_v1 + 1;
    return 1;
}
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", scsCharaAttach__FP12_SEN_CMR_SEQP12CSceneCmrSeq);
s32 scsDummy(_SEN_CMR_SEQ *sequence, CSceneCmrSeq *owner) {
    return 1;
}
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", InitSceneCmrSeq__FP12_SEN_CMR_SEQ);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", __ct__12CSceneCmrSeqFv);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", ZeroInitialize__12CSceneCmrSeqFv);
struct inferred;
typedef struct CSceneCmrSeq_infere2 {
    /* 0x0 */ _SEN_CMR_SEQ *unk0;                   /* inferred */
    /* 0x4 */ s32 unk4;                             /* inferred */
} CSceneCmrSeq_infere2;                                     /* size >= 0x8 */
extern "C" s32 Clear__12CSceneCmrSeqFv(void *);
extern "C" s32 ZeroInitialize__12CSceneCmrSeqFv(void *);
extern "C" void Initialize__12CSceneCmrSeqFP12_SEN_CMR_SEQi(CSceneCmrSeq_infere2 *objet, _SEN_CMR_SEQ *arg0, s32 arg1) {
    ZeroInitialize__12CSceneCmrSeqFv(objet);
    objet->unk0 = arg0;
    objet->unk4 = arg1;
    Clear__12CSceneCmrSeqFv(objet);
}
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", Clear__12CSceneCmrSeqFv);
extern "C" s32 CheckEnd__12CSceneCmrSeqFv(CSceneCmrSeq *objet) {
    s32 *p = (s32 *) objet;
    if (p[2] == 0) {
        if (p[4] == 0 && p[6] == 0 && p[8] == 0) {
            return 1;
        }
    }
    return 0;
}
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
extern "C" s32 InitSceneCmrSeq__FP12_SEN_CMR_SEQ(...);
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
extern "C" void PRDelay__12CSceneCmrSeqFi(CSceneCmrSeq *objet, s32 arg0) {
    s32 *temp_v0;

    temp_v0 = (s32 *) (SearchNextPrSeq__12CSceneCmrSeqFv(objet));
    if (temp_v0 != NULL) {
        if (arg0 > 0) {
            arg0 = (arg0 * 50) / 60;
            if (arg0 <= 0) {
                arg0 = 1;
            }
        }
        *temp_v0 = 1;
        temp_v0[12] = arg0;
    }
}
extern "C" s32 SearchNextPrSeq__12CSceneCmrSeqFv(void *);
extern "C" s32 sceVu0CopyVector(...);
extern "C" void SetPos__12CSceneCmrSeqFPf(CSceneCmrSeq *objet, f32 *arg0) {
    s32 *temp_v0;

    temp_v0 = (s32 *) (SearchNextPrSeq__12CSceneCmrSeqFv(objet));
    if (temp_v0 != NULL) {
        *temp_v0 = 2;
        sceVu0CopyVector(((s32 *) ((u8 *) temp_v0 + 0x10)), arg0);
    }
}
extern "C" void SetRef__12CSceneCmrSeqFPf(CSceneCmrSeq *objet, f32 *arg0) {
    s32 *temp_v0;

    temp_v0 = (s32 *) (SearchNextPrSeq__12CSceneCmrSeqFv(objet));
    if (temp_v0 != NULL) {
        *temp_v0 = 3;
        sceVu0CopyVector(((s32 *) ((u8 *) temp_v0 + 0x20)), arg0);
    }
}
extern "C" void Move__12CSceneCmrSeqFPfPfi(CSceneCmrSeq *objet, f32 *arg0, f32 *arg1, s32 arg2) {
    s32 *temp_v0;

    temp_v0 = (s32 *) (SearchNextPrSeq__12CSceneCmrSeqFv(objet));
    if (temp_v0 != NULL) {
        if (arg2 > 0) {
            arg2 = (arg2 * 50) / 60;
            if (arg2 <= 0) {
                arg2 = 1;
            }
        }
        *temp_v0 = 0x4;
        sceVu0CopyVector(temp_v0 + 4, arg0);
        sceVu0CopyVector(temp_v0 + 8, arg1);
        temp_v0[12] = arg2;
    }
}
extern "C" void Move2__12CSceneCmrSeqFPfPfiif(CSceneCmrSeq *objet, f32 *arg0, f32 *arg1, s32 arg2, s32 arg3, f32 arg4) {
    s32 *temp_v0;

    temp_v0 = (s32 *) (SearchNextPrSeq__12CSceneCmrSeqFv(objet));
    if (temp_v0 != NULL) {
        if (arg2 > 0) {
            arg2 = (arg2 * 50) / 60;
            if (arg2 <= 0) {
                arg2 = 1;
            }
        }
        *temp_v0 = 0x5;
        sceVu0CopyVector(temp_v0 + 4, arg0);
        sceVu0CopyVector(temp_v0 + 8, arg1);
        temp_v0[12] = arg2;
        temp_v0[13] = arg3;
        ((f32 *) temp_v0)[14] = arg4;
    }
}
extern "C" void MoveRef__12CSceneCmrSeqFPfi(CSceneCmrSeq *objet, f32 *arg0, s32 arg1) {
    s32 *temp_v0;

    temp_v0 = (s32 *) (SearchNextPrSeq__12CSceneCmrSeqFv(objet));
    if (temp_v0 != NULL) {
        if (arg1 > 0) {
            arg1 = (arg1 * 50) / 60;
            if (arg1 <= 0) {
                arg1 = 1;
            }
        }
        *temp_v0 = 0x6;
        sceVu0CopyVector(temp_v0 + 8, arg0);
        temp_v0[12] = arg1;
    }
}
extern "C" void MovePos__12CSceneCmrSeqFPfi(CSceneCmrSeq *objet, f32 *arg0, s32 arg1) {
    s32 *temp_v0;

    temp_v0 = (s32 *) (SearchNextPrSeq__12CSceneCmrSeqFv(objet));
    if (temp_v0 != NULL) {
        if (arg1 > 0) {
            arg1 = (arg1 * 50) / 60;
            if (arg1 <= 0) {
                arg1 = 1;
            }
        }
        *temp_v0 = 0x7;
        sceVu0CopyVector(temp_v0 + 4, arg0);
        temp_v0[12] = arg1;
    }
}
extern "C" s32 SearchNextPrSeq__12CSceneCmrSeqFv(void *);
extern "C" void InitPas__12CSceneCmrSeqFv(CSceneCmrSeq *objet) {
    s32 *temp_v0;

    temp_v0 = (s32 *) (SearchNextPrSeq__12CSceneCmrSeqFv(objet));
    if (temp_v0 != NULL) {
        *temp_v0 = 8;
    }
}
extern "C" void SetPasFrm__12CSceneCmrSeqFi(CSceneCmrSeq *objet, s32 arg0) {
    s32 *temp_v0;

    temp_v0 = (s32 *) (SearchNextPrSeq__12CSceneCmrSeqFv(objet));
    if (temp_v0 != NULL) {
        if (arg0 > 0) {
            arg0 = (arg0 * 50) / 60;
            if (arg0 <= 0) {
                arg0 = 1;
            }
        }
        *temp_v0 = 0x9;
        temp_v0[12] = arg0;
    }
}
extern "C" s32 sceVu0CopyVector(...);
extern "C" void AddPas__12CSceneCmrSeqFPfPf(CSceneCmrSeq *objet, f32 *arg0, f32 *arg1) {
    s32 *temp_v0;

    temp_v0 = (s32 *) (SearchNextPrSeq__12CSceneCmrSeqFv(objet));
    if (temp_v0 != NULL) {
        *temp_v0 = 0xA;
        sceVu0CopyVector(((s32 *) ((u8 *) temp_v0 + 0x10)), arg0);
        sceVu0CopyVector(((s32 *) ((u8 *) temp_v0 + 0x20)), arg1);
    }
}
extern "C" void StartPas__12CSceneCmrSeqFv(CSceneCmrSeq *objet) {
    s32 *temp_v0;

    temp_v0 = (s32 *) (SearchNextPrSeq__12CSceneCmrSeqFv(objet));
    if (temp_v0 != NULL) {
        *temp_v0 = 0xB;
    }
}
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", PRSlowing__12CSceneCmrSeqFfi);
extern "C" void PRKeep__12CSceneCmrSeqFv(CSceneCmrSeq *objet) {
    s32 *temp_v0;

    temp_v0 = (s32 *) (SearchNextPrSeq__12CSceneCmrSeqFv(objet));
    if (temp_v0 != NULL) {
        *temp_v0 = 0xD;
    }
}
extern "C" void PRReturn__12CSceneCmrSeqFv(CSceneCmrSeq *objet) {
    s32 *temp_v0;

    temp_v0 = (s32 *) (SearchNextPrSeq__12CSceneCmrSeqFv(objet));
    if (temp_v0 != NULL) {
        *temp_v0 = 0xE;
    }
}
extern "C" void AHDDelay__12CSceneCmrSeqFi(CSceneCmrSeq *objet, s32 arg0) {
    s32 *temp_v0;

    temp_v0 = (s32 *) (SearchNextAhdSeq__12CSceneCmrSeqFv(objet));
    if (temp_v0 != NULL) {
        if (arg0 > 0) {
            arg0 = (arg0 * 50) / 60;
            if (arg0 <= 0) {
                arg0 = 1;
            }
        }
        *temp_v0 = 0xf;
        temp_v0[12] = arg0;
    }
}
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", SetAngle__12CSceneCmrSeqFf);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", SetHeight__12CSceneCmrSeqFf);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", SetDist__12CSceneCmrSeqFf);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", SetAHD__12CSceneCmrSeqFfff);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", MoveAHD__12CSceneCmrSeqFfffi);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", MoveAHD2__12CSceneCmrSeqFfffiif);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", SetSyncObj__12CSceneCmrSeqFiPffffiPc);
extern "C" s32 SearchNextAhdSeq__12CSceneCmrSeqFv(void *);
extern "C" void ReleaseSyncObj__12CSceneCmrSeqFv(CSceneCmrSeq *objet) {
    s32 *temp_v0;

    temp_v0 = (s32 *) (SearchNextAhdSeq__12CSceneCmrSeqFv(objet));
    if (temp_v0 != NULL) {
        *temp_v0 = 0x17;
    }
}
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", AHDSlowing__12CSceneCmrSeqFfi);
extern "C" void AHDKeep__12CSceneCmrSeqFv(CSceneCmrSeq *objet) {
    s32 *temp_v0;

    temp_v0 = (s32 *) (SearchNextAhdSeq__12CSceneCmrSeqFv(objet));
    if (temp_v0 != NULL) {
        *temp_v0 = 0x19;
    }
}
extern "C" void AHDReturn__12CSceneCmrSeqFv(CSceneCmrSeq *objet) {
    s32 *temp_v0;

    temp_v0 = (s32 *) (SearchNextAhdSeq__12CSceneCmrSeqFv(objet));
    if (temp_v0 != NULL) {
        *temp_v0 = 0x1A;
    }
}
extern "C" void FadeDelay__12CSceneCmrSeqFi(CSceneCmrSeq *objet, s32 arg0) {
    s32 *temp_v0;

    temp_v0 = (s32 *) (SearchNextFadeSeq__12CSceneCmrSeqFv(objet));
    if (temp_v0 != NULL) {
        if (arg0 > 0) {
            arg0 = (arg0 * 50) / 60;
            if (arg0 <= 0) {
                arg0 = 1;
            }
        }
        *temp_v0 = 0x1b;
        temp_v0[12] = arg0;
    }
}
extern "C" s32 SearchNextFadeSeq__12CSceneCmrSeqFv(void *);
extern "C" void FadeInit__12CSceneCmrSeqFv(CSceneCmrSeq *objet) {
    s32 *temp_v0;

    temp_v0 = (s32 *) (SearchNextFadeSeq__12CSceneCmrSeqFv(objet));
    if (temp_v0 != NULL) {
        *temp_v0 = 0x1C;
    }
}
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", FadeIn__12CSceneCmrSeqFifff);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", FadeOut__12CSceneCmrSeqFifff);
extern "C" void QuakeDelay__12CSceneCmrSeqFi(CSceneCmrSeq *objet, s32 arg0) {
    s32 *temp_v0;

    temp_v0 = (s32 *) (SearchNextQuakeSeq__12CSceneCmrSeqFv(objet));
    if (temp_v0 != NULL) {
        if (arg0 > 0) {
            arg0 = (arg0 * 50) / 60;
            if (arg0 <= 0) {
                arg0 = 1;
            }
        }
        *temp_v0 = 0x1f;
        temp_v0[12] = arg0;
    }
}
extern "C" void Quake__12CSceneCmrSeqFPfi(CSceneCmrSeq *objet, f32 *arg0, s32 arg1) {
    s32 *temp_v0;

    temp_v0 = (s32 *) (SearchNextQuakeSeq__12CSceneCmrSeqFv(objet));
    if (temp_v0 != NULL) {
        if (arg1 > 0) {
            arg1 = (arg1 * 50) / 60;
            if (arg1 <= 0) {
                arg1 = 1;
            }
        }
        *temp_v0 = 0x20;
        sceVu0CopyVector(temp_v0 + 4, arg0);
        temp_v0[12] = arg1;
    }
}
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", Quake2__12CSceneCmrSeqFPfi);
extern "C" void CharaDelay__12CSceneCmrSeqFi(CSceneCmrSeq *objet, s32 arg0) {
    s32 *temp_v0;

    temp_v0 = (s32 *) (SearchNextCharaSeq__12CSceneCmrSeqFv(objet));
    if (temp_v0 != NULL) {
        if (arg0 > 0) {
            arg0 = (arg0 * 50) / 60;
            if (arg0 <= 0) {
                arg0 = 1;
            }
        }
        *temp_v0 = 0x22;
        temp_v0[12] = arg0;
    }
}
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", CharaAttach__12CSceneCmrSeqFifi);
typedef struct CSceneObjSeq_infere4 {
    /* 0x00 */ char pad0[0x40];
    /* 0x40 */ s32 unk40;                           /* inferred */
} CSceneObjSeq_infere4;                                     /* size >= 0x44 */
typedef struct _SEN_OBJ_SEQ_infere3 {
    /* 0x00 */ char pad0[0x20];
    /* 0x20 */ s32 unk20;                           /* inferred */
} _SEN_OBJ_SEQ_infere3;                                     /* size >= 0x24 */
extern "C" s32 scsPosDelay__FP12_SEN_OBJ_SEQP12CSceneObjSeq(_SEN_OBJ_SEQ_infere3 *arg0, CSceneObjSeq_infere4 *arg1) {
    s32 temp_v1;

    temp_v1 = arg1->unk40;
    if (temp_v1 >= arg0->unk20) {
        arg1->unk40 = 0;
        return 0;
    }
    arg1->unk40 = temp_v1 + 1;
    return 1;
}
typedef struct CSceneObjSeq_infere15 {
    /* 0x00 */ char pad0[0x70];
    /* 0x70 */ char unk70;                             /* inferred */
    /* 0x70 */ char pad70[1];
} CSceneObjSeq_infere15;                                     /* size >= 0x71 */
typedef struct _SEN_OBJ_SEQ_infere14 {
    /* 0x00 */ char pad0[0x10];
    /* 0x10 */ char unk10;                             /* inferred */
    /* 0x10 */ char pad10[1];
} _SEN_OBJ_SEQ_infere14;                                     /* size >= 0x11 */
extern "C" s32 sceVu0CopyVector(...);
extern "C" s32 scsSetPos__FP12_SEN_OBJ_SEQP12CSceneObjSeq(_SEN_OBJ_SEQ_infere14 *arg0, CSceneObjSeq_infere15 *arg1) {
    sceVu0CopyVector(&arg1->unk70, &arg0->unk10);
    return 0;
}
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", scsMove__FP12_SEN_OBJ_SEQP12CSceneObjSeq);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", scsMove2__FP12_SEN_OBJ_SEQP12CSceneObjSeq);
struct _SEN_OBJ_SEQ_630ed8 {
    s32 field_0;
    char pad_4[0xC];
    f32 field_10;
    f32 field_14;
    f32 field_18;
    char pad_1C[0x4];
    s32 field_20;
    s32 field_24;
    f32 field_28;
    s8 field_2C;
};
struct CSceneObjSeq_infere_630ed8;
typedef struct CSceneObjSeq_infere_630ed8 {
    /* 0x000 */ char pad0[0x140];
    /* 0x140 */ char pad140[1];
} CSceneObjSeq_infere_630ed8;                                     /* size >= 0x141 */
struct arg1_champs_630ed8 {
    char pad0[0x140];
    /* 0x140 */ s32 unk140;
};
extern "C" s32 Initialize__9CCharaPasFv(void *);
extern "C" s32 scsInitPas__FP12_SEN_OBJ_SEQP12CSceneObjSeq(_SEN_OBJ_SEQ_630ed8 *arg0, CSceneObjSeq_infere_630ed8 *arg1) {
    Initialize__9CCharaPasFv(&((struct arg1_champs_630ed8 *) arg1)->unk140);
    return 0;
}
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", scsSetPasFrm__FP12_SEN_OBJ_SEQP12CSceneObjSeq);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", scsAddPas__FP12_SEN_OBJ_SEQP12CSceneObjSeq);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", scsStartPas__FP12_SEN_OBJ_SEQP12CSceneObjSeq);
struct inferred;
typedef struct CSceneObjSeq_infere2 {
    /* 0x000 */ char pad0[0x40];
    /* 0x040 */ s32 unk40;                          /* inferred */
    /* 0x044 */ char pad44[0x2C];                   /* maybe part of unk40[0xC]void */
    /* 0x070 */ f32 unk70;                          /* inferred */
    /* 0x074 */ char pad74[0x8C];                   /* maybe part of unk70[0x24]void */
    /* 0x100 */ f32 unk100;                         /* inferred */
    /* 0x104 */ char pad104[0xC];                   /* maybe part of unk100[4]void */
    /* 0x110 */ f32 unk110;                         /* inferred */
} CSceneObjSeq_infere2;                                     /* size >= 0x114 */
typedef struct _SEN_OBJ_SEQ_infere2 {
    /* 0x00 */ char pad0[0x10];
    /* 0x10 */ f32 unk10;                           /* inferred */
    /* 0x14 */ char pad14[0xC];                     /* maybe part of unk10[4]void */
    /* 0x20 */ f32 unk20;                           /* inferred */
    /* 0x24 */ s32 unk24;                           /* inferred */
} _SEN_OBJ_SEQ_infere2;                                     /* size >= 0x28 */
extern "C" s32 CalcPosParabolicJump__FPfPfPffff(f32 *, f32 *, f32 *, f32, f32, f32);
extern "C" s32 sceVu0CopyVector(...);
extern "C" s32 scsJump__FP12_SEN_OBJ_SEQP12CSceneObjSeq(_SEN_OBJ_SEQ_infere2 *arg0, CSceneObjSeq_infere2 *arg1) {
    s32 temp_v1;

    if (arg1->unk40 <= 0) {
        sceVu0CopyVector(&arg1->unk100, &arg1->unk70);
        sceVu0CopyVector(&arg1->unk110, &arg0->unk10);
    }
    temp_v1 = arg1->unk40;
    if (temp_v1 >= arg0->unk24) {
        sceVu0CopyVector(&arg1->unk70, &arg1->unk110);
        arg1->unk40 = 0;
        return 0;
    }
    arg1->unk40 = temp_v1 + 1;
    CalcPosParabolicJump__FPfPfPffff(&arg1->unk70, &arg1->unk100, &arg1->unk110, arg0->unk20, (f32) arg0->unk24, (f32) arg1->unk40);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", scsSetEohFramePos__FP12_SEN_OBJ_SEQP12CSceneObjSeq);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", scsAddPos__FP12_SEN_OBJ_SEQP12CSceneObjSeq);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", scsAttachCamera__FP12_SEN_OBJ_SEQP12CSceneObjSeq);
extern "C" u8 EventObjHandleMother[512];
typedef struct CSceneObjSeq_infere3 {
    /* 0x00 */ char pad0[0x64];
    /* 0x64 */ s32 unk64;                           /* inferred */
    /* 0x68 */ char pad68[8];                       /* maybe part of unk64[3]void */
    /* 0x70 */ f32 unk70;                           /* inferred */
    /* 0x74 */ f32 unk74;                           /* inferred */
    /* 0x78 */ f32 unk78;                           /* inferred */
    /* 0x7C */ char pad7C[4];
    /* 0x80 */ f32 unk80;                           /* inferred */
    /* 0x84 */ f32 unk84;                           /* inferred */
    /* 0x88 */ f32 unk88;                           /* inferred */
} CSceneObjSeq_infere3;                                     /* size >= 0x8C */
extern "C" s32 ResetDAPosition__10CEohMotherFi(void *, s32);
extern "C" s32 SetPos__10CEohMotherFifff(void *, s32, f32, f32, f32);
extern "C" s32 SetRot__10CEohMotherFifff(void *, s32, f32, f32, f32);
extern "C" s32 UpdatePosition__10CEohMotherFi(void *, s32);
extern "C" s32 scsResetDAPosition__FP12_SEN_OBJ_SEQP12CSceneObjSeq(_SEN_OBJ_SEQ *arg0, CSceneObjSeq_infere3 *arg1) {
    SetPos__10CEohMotherFifff(&EventObjHandleMother, arg1->unk64, arg1->unk70, arg1->unk74, arg1->unk78);
    SetRot__10CEohMotherFifff(&EventObjHandleMother, arg1->unk64, arg1->unk80, arg1->unk84, arg1->unk88);
    UpdatePosition__10CEohMotherFi(&EventObjHandleMother, arg1->unk64);
    ResetDAPosition__10CEohMotherFi(&EventObjHandleMother, arg1->unk64);
    return 0;
}
typedef struct CSceneObjSeq_infere5 {
    /* 0x00 */ char pad0[0x44];
    /* 0x44 */ s32 unk44;                           /* inferred */
} CSceneObjSeq_infere5;                                     /* size >= 0x48 */
typedef struct _SEN_OBJ_SEQ_infere4 {
    /* 0x00 */ char pad0[0x20];
    /* 0x20 */ s32 unk20;                           /* inferred */
} _SEN_OBJ_SEQ_infere4;                                     /* size >= 0x24 */
extern "C" s32 scsRotDelay__FP12_SEN_OBJ_SEQP12CSceneObjSeq(_SEN_OBJ_SEQ_infere4 *arg0, CSceneObjSeq_infere5 *arg1) {
    s32 temp_v1;

    temp_v1 = arg1->unk44;
    if (temp_v1 >= arg0->unk20) {
        arg1->unk44 = 0;
        return 0;
    }
    arg1->unk44 = temp_v1 + 1;
    return 1;
}
typedef struct CSceneObjSeq_infere16 {
    /* 0x00 */ char pad0[0x80];
    /* 0x80 */ char unk80;                             /* inferred */
    /* 0x80 */ char pad80[1];
} CSceneObjSeq_infere16;                                     /* size >= 0x81 */
typedef struct _SEN_OBJ_SEQ_infere15 {
    /* 0x00 */ char pad0[0x10];
    /* 0x10 */ char unk10;                             /* inferred */
    /* 0x10 */ char pad10[1];
} _SEN_OBJ_SEQ_infere15;                                     /* size >= 0x11 */
extern "C" s32 sceVu0CopyVector(...);
extern "C" s32 scsSetRot__FP12_SEN_OBJ_SEQP12CSceneObjSeq(_SEN_OBJ_SEQ_infere15 *arg0, CSceneObjSeq_infere16 *arg1) {
    sceVu0CopyVector(&arg1->unk80, &arg0->unk10);
    return 0;
}
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", scsRotation__FP12_SEN_OBJ_SEQP12CSceneObjSeq);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", scsRotation2__FP12_SEN_OBJ_SEQP12CSceneObjSeq);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", scsReference__FP12_SEN_OBJ_SEQP12CSceneObjSeq);
typedef struct CSceneObjSeq_infere6 {
    /* 0x00 */ char pad0[0x48];
    /* 0x48 */ s32 unk48;                           /* inferred */
} CSceneObjSeq_infere6;                                     /* size >= 0x4C */
typedef struct _SEN_OBJ_SEQ_infere5 {
    /* 0x00 */ char pad0[0x20];
    /* 0x20 */ s32 unk20;                           /* inferred */
} _SEN_OBJ_SEQ_infere5;                                     /* size >= 0x24 */
extern "C" s32 scsMotionDelay__FP12_SEN_OBJ_SEQP12CSceneObjSeq(_SEN_OBJ_SEQ_infere5 *arg0, CSceneObjSeq_infere6 *arg1) {
    s32 temp_v1;

    temp_v1 = arg1->unk48;
    if (temp_v1 >= arg0->unk20) {
        arg1->unk48 = 0;
        return 0;
    }
    arg1->unk48 = temp_v1 + 1;
    return 1;
}
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", scsSetMotion__FP12_SEN_OBJ_SEQP12CSceneObjSeq);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", scsNextMotion__FP12_SEN_OBJ_SEQP12CSceneObjSeq);
extern "C" s32 CheckMotionEnd__10CEohMotherFi(void *, s32);
extern "C" s32 scsMotionWait__FP12_SEN_OBJ_SEQP12CSceneObjSeq(_SEN_OBJ_SEQ *arg0, CSceneObjSeq *arg1) {
    return (CheckMotionEnd__10CEohMotherFi(&EventObjHandleMother, arg1->field_0x64) != 0) ^ 1;
}
typedef struct CSceneObjSeq_infere17 {
    /* 0x00 */ char pad0[0x64];
    /* 0x64 */ s32 unk64;                           /* inferred */
} CSceneObjSeq_infere17;                                     /* size >= 0x68 */
extern "C" s32 SetMotionTrg__10CEohMotherFi(void *, s32);
extern "C" s32 scsMotionTrg__FP12_SEN_OBJ_SEQP12CSceneObjSeq(_SEN_OBJ_SEQ *arg0, CSceneObjSeq_infere17 *arg1) {
    SetMotionTrg__10CEohMotherFi(&EventObjHandleMother, arg1->unk64);
    return 0;
}
typedef struct CSceneObjSeq_infere11 {
    /* 0x00 */ char pad0[0x64];
    /* 0x64 */ s32 unk64;                           /* inferred */
} CSceneObjSeq_infere11;                                     /* size >= 0x68 */
typedef struct _SEN_OBJ_SEQ_infere10 {
    /* 0x00 */ char pad0[0x20];
    /* 0x20 */ f32 unk20;                           /* inferred */
} _SEN_OBJ_SEQ_infere10;                                     /* size >= 0x24 */
extern "C" s32 SetStep__10CEohMotherFif(void *, s32, f32);
extern "C" s32 scsSetMotStep__FP12_SEN_OBJ_SEQP12CSceneObjSeq(_SEN_OBJ_SEQ_infere10 *arg0, CSceneObjSeq_infere11 *arg1) {
    SetStep__10CEohMotherFif(&EventObjHandleMother, arg1->unk64, arg0->unk20);
    return 0;
}
typedef struct CSceneObjSeq_infere12 {
    /* 0x00 */ char pad0[0x64];
    /* 0x64 */ s32 unk64;                           /* inferred */
} CSceneObjSeq_infere12;                                     /* size >= 0x68 */
typedef struct _SEN_OBJ_SEQ_infere11 {
    /* 0x00 */ char pad0[0x20];
    /* 0x20 */ f32 unk20;                           /* inferred */
} _SEN_OBJ_SEQ_infere11;                                     /* size >= 0x24 */
extern "C" s32 SetChangeStep__10CEohMotherFif(void *, s32, f32);
extern "C" s32 scsSetMotChangeStep__FP12_SEN_OBJ_SEQP12CSceneObjSeq(_SEN_OBJ_SEQ_infere11 *arg0, CSceneObjSeq_infere12 *arg1) {
    SetChangeStep__10CEohMotherFif(&EventObjHandleMother, arg1->unk64, arg0->unk20);
    return 0;
}
typedef struct CSceneObjSeq_infere18 {
    /* 0x00 */ char pad0[0x64];
    /* 0x64 */ s32 unk64;                           /* inferred */
} CSceneObjSeq_infere18;                                     /* size >= 0x68 */
extern "C" s32 ResetMotion__10CEohMotherFi(void *, s32);
extern "C" s32 scsResetMotion__FP12_SEN_OBJ_SEQP12CSceneObjSeq(_SEN_OBJ_SEQ *arg0, CSceneObjSeq_infere18 *arg1) {
    ResetMotion__10CEohMotherFi(&EventObjHandleMother, arg1->unk64);
    return 0;
}
typedef struct CSceneObjSeq_infere13 {
    /* 0x00 */ char pad0[0x64];
    /* 0x64 */ s32 unk64;                           /* inferred */
} CSceneObjSeq_infere13;                                     /* size >= 0x68 */
typedef struct _SEN_OBJ_SEQ_infere12 {
    /* 0x00 */ char pad0[0x20];
    /* 0x20 */ f32 unk20;                           /* inferred */
} _SEN_OBJ_SEQ_infere12;                                     /* size >= 0x24 */
extern "C" s32 SetMotionNowTime__10CEohMotherFif(void *, s32, f32);
extern "C" s32 scsSetMotionNowTime__FP12_SEN_OBJ_SEQP12CSceneObjSeq(_SEN_OBJ_SEQ_infere12 *arg0, CSceneObjSeq_infere13 *arg1) {
    SetMotionNowTime__10CEohMotherFif(&EventObjHandleMother, arg1->unk64, arg0->unk20);
    return 0;
}
typedef struct CSceneObjSeq_infere14 {
    /* 0x00 */ char pad0[0x64];
    /* 0x64 */ s32 unk64;                           /* inferred */
} CSceneObjSeq_infere14;                                     /* size >= 0x68 */
typedef struct _SEN_OBJ_SEQ_infere13 {
    /* 0x00 */ char pad0[0x20];
    /* 0x20 */ f32 unk20;                           /* inferred */
} _SEN_OBJ_SEQ_infere13;                                     /* size >= 0x24 */
extern "C" s32 SetMotionWaitTime__10CEohMotherFif(void *, s32, f32);
extern "C" s32 scsSetMotionWaitTime__FP12_SEN_OBJ_SEQP12CSceneObjSeq(_SEN_OBJ_SEQ_infere13 *arg0, CSceneObjSeq_infere14 *arg1) {
    SetMotionWaitTime__10CEohMotherFif(&EventObjHandleMother, arg1->unk64, arg0->unk20);
    return 0;
}
typedef struct CSceneObjSeq_infere19 {
    /* 0x00 */ char pad0[0x64];
    /* 0x64 */ s32 unk64;                           /* inferred */
} CSceneObjSeq_infere19;                                     /* size >= 0x68 */
extern "C" s32 NormalDrive__10CEohMotherFi(void *, s32);
extern "C" s32 scsNormalDrive__FP12_SEN_OBJ_SEQP12CSceneObjSeq(_SEN_OBJ_SEQ *arg0, CSceneObjSeq_infere19 *arg1) {
    NormalDrive__10CEohMotherFi(&EventObjHandleMother, arg1->unk64);
    return 0;
}
extern "C" s32 GetSeqStatus__10CEohMotherFi(void *, s32);
extern "C" s32 scsMotionTrgWait__FP12_SEN_OBJ_SEQP12CSceneObjSeq(_SEN_OBJ_SEQ *arg0, CSceneObjSeq *arg1) {
    return (GetSeqStatus__10CEohMotherFi(&EventObjHandleMother, arg1->field_0x64) == 3) ^ 1;
}
typedef struct CSceneObjSeq_infere7 {
    /* 0x00 */ char pad0[0x4C];
    /* 0x4C */ s32 unk4C;                           /* inferred */
} CSceneObjSeq_infere7;                                     /* size >= 0x50 */
typedef struct _SEN_OBJ_SEQ_infere6 {
    /* 0x00 */ char pad0[0x20];
    /* 0x20 */ s32 unk20;                           /* inferred */
} _SEN_OBJ_SEQ_infere6;                                     /* size >= 0x24 */
extern "C" s32 scsTexAnimeDelay__FP12_SEN_OBJ_SEQP12CSceneObjSeq(_SEN_OBJ_SEQ_infere6 *arg0, CSceneObjSeq_infere7 *arg1) {
    s32 temp_v1;

    temp_v1 = arg1->unk4C;
    if (temp_v1 >= arg0->unk20) {
        arg1->unk4C = 0;
        return 0;
    }
    arg1->unk4C = temp_v1 + 1;
    return 1;
}
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", scsTexAnime__FP12_SEN_OBJ_SEQP12CSceneObjSeq);
typedef struct CSceneObjSeq_infere8 {
    /* 0x00 */ char pad0[0x50];
    /* 0x50 */ s32 unk50;                           /* inferred */
} CSceneObjSeq_infere8;                                     /* size >= 0x54 */
typedef struct _SEN_OBJ_SEQ_infere7 {
    /* 0x00 */ char pad0[0x20];
    /* 0x20 */ s32 unk20;                           /* inferred */
} _SEN_OBJ_SEQ_infere7;                                     /* size >= 0x24 */
extern "C" s32 scsColorDelay__FP12_SEN_OBJ_SEQP12CSceneObjSeq(_SEN_OBJ_SEQ_infere7 *arg0, CSceneObjSeq_infere8 *arg1) {
    s32 temp_v1;

    temp_v1 = arg1->unk50;
    if (temp_v1 >= arg0->unk20) {
        arg1->unk50 = 0;
        return 0;
    }
    arg1->unk50 = temp_v1 + 1;
    return 1;
}
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", scsSetColor__FP12_SEN_OBJ_SEQP12CSceneObjSeq);
typedef struct CSceneObjSeq_infere9 {
    /* 0x00 */ char pad0[0x54];
    /* 0x54 */ s32 unk54;                           /* inferred */
} CSceneObjSeq_infere9;                                     /* size >= 0x58 */
typedef struct _SEN_OBJ_SEQ_infere8 {
    /* 0x00 */ char pad0[0x20];
    /* 0x20 */ s32 unk20;                           /* inferred */
} _SEN_OBJ_SEQ_infere8;                                     /* size >= 0x24 */
extern "C" s32 scsScaleDelay__FP12_SEN_OBJ_SEQP12CSceneObjSeq(_SEN_OBJ_SEQ_infere8 *arg0, CSceneObjSeq_infere9 *arg1) {
    s32 temp_v1;

    temp_v1 = arg1->unk54;
    if (temp_v1 >= arg0->unk20) {
        arg1->unk54 = 0;
        return 0;
    }
    arg1->unk54 = temp_v1 + 1;
    return 1;
}
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", scsSetScale__FP12_SEN_OBJ_SEQP12CSceneObjSeq);
typedef struct CSceneObjSeq_infere10 {
    /* 0x00 */ char pad0[0x58];
    /* 0x58 */ s32 unk58;                           /* inferred */
} CSceneObjSeq_infere10;                                     /* size >= 0x5C */
typedef struct _SEN_OBJ_SEQ_infere9 {
    /* 0x00 */ char pad0[0x20];
    /* 0x20 */ s32 unk20;                           /* inferred */
} _SEN_OBJ_SEQ_infere9;                                     /* size >= 0x24 */
extern "C" s32 scsSeDelay__FP12_SEN_OBJ_SEQP12CSceneObjSeq(_SEN_OBJ_SEQ_infere9 *arg0, CSceneObjSeq_infere10 *arg1) {
    s32 temp_v1;

    temp_v1 = arg1->unk58;
    if (temp_v1 >= arg0->unk20) {
        arg1->unk58 = 0;
        return 0;
    }
    arg1->unk58 = temp_v1 + 1;
    return 1;
}
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
extern "C" s32 CheckEnd__12CSceneObjSeqFv(CSceneObjSeq *objet) {
    s32 *p = (s32 *) objet;
    if (p[2] == 0) {
        if (p[4] == 0 && p[6] == 0 && p[8] == 0 && p[10] == 0 && p[12] == 0 && p[14] == 0) {
            return 1;
        }
    }
    return 0;
}
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", Play__12CSceneObjSeqFv);
extern "C" void PosDelay__12CSceneObjSeqFi(CSceneObjSeq *objet, s32 arg0) {
    s32 *temp_v0;

    temp_v0 = (s32 *) (SearchNextPosSeq__12CSceneObjSeqFv(objet));
    if (temp_v0 != NULL) {
        if (arg0 > 0) {
            arg0 = (arg0 * 50) / 60;
            if (arg0 <= 0) {
                arg0 = 1;
            }
        }
        *temp_v0 = 0x1;
        temp_v0[8] = arg0;
    }
}
extern "C" s32 SearchNextPosSeq__12CSceneObjSeqFv(void *);
extern "C" void SetPos__12CSceneObjSeqFPf(CSceneObjSeq *objet, f32 *arg0) {
    s32 *temp_v0;

    temp_v0 = (s32 *) (SearchNextPosSeq__12CSceneObjSeqFv(objet));
    if (temp_v0 != NULL) {
        *temp_v0 = 2;
        sceVu0CopyVector(((s32 *) ((u8 *) temp_v0 + 0x10)), arg0);
    }
}
extern "C" void Move__12CSceneObjSeqFPfii(CSceneObjSeq *objet, f32 *arg0, s32 arg1, s32 arg2) {
    s32 *temp_v0;

    temp_v0 = (s32 *) (SearchNextPosSeq__12CSceneObjSeqFv(objet));
    if (temp_v0 != NULL) {
        if (arg1 > 0) {
            arg1 = (arg1 * 50) / 60;
            if (arg1 <= 0) {
                arg1 = 1;
            }
        }
        *temp_v0 = 0x3;
        sceVu0CopyVector(temp_v0 + 4, arg0);
        temp_v0[8] = arg1;
        temp_v0[9] = arg2;
    }
}
extern "C" void Move2__12CSceneObjSeqFPfiif(CSceneObjSeq *objet, f32 *arg0, s32 arg1, s32 arg2, f32 arg3) {
    s32 *temp_v0;

    temp_v0 = (s32 *) (SearchNextPosSeq__12CSceneObjSeqFv(objet));
    if (temp_v0 != NULL) {
        if (arg1 > 0) {
            arg1 = (arg1 * 50) / 60;
            if (arg1 <= 0) {
                arg1 = 1;
            }
        }
        *temp_v0 = 0x4;
        sceVu0CopyVector(temp_v0 + 4, arg0);
        temp_v0[8] = arg1;
        temp_v0[9] = arg2;
        ((f32 *) temp_v0)[10] = arg3;
    }
}
extern "C" s32 SearchNextPosSeq__12CSceneObjSeqFv(void *);
extern "C" void InitPas__12CSceneObjSeqFv(CSceneObjSeq *objet) {
    s32 *temp_v0;

    temp_v0 = (s32 *) (SearchNextPosSeq__12CSceneObjSeqFv(objet));
    if (temp_v0 != NULL) {
        *temp_v0 = 5;
    }
}
extern "C" void SetPasFrm__12CSceneObjSeqFi(CSceneObjSeq *objet, s32 arg0) {
    s32 *temp_v0;

    temp_v0 = (s32 *) (SearchNextPosSeq__12CSceneObjSeqFv(objet));
    if (temp_v0 != NULL) {
        if (arg0 > 0) {
            arg0 = (arg0 * 50) / 60;
            if (arg0 <= 0) {
                arg0 = 1;
            }
        }
        *temp_v0 = 0x6;
        temp_v0[8] = arg0;
    }
}
extern "C" void AddPas__12CSceneObjSeqFPf(CSceneObjSeq *objet, f32 *arg0) {
    s32 *temp_v0;

    temp_v0 = (s32 *) (SearchNextPosSeq__12CSceneObjSeqFv(objet));
    if (temp_v0 != NULL) {
        *temp_v0 = 7;
        sceVu0CopyVector(((s32 *) ((u8 *) temp_v0 + 0x10)), arg0);
    }
}
struct temp_v0_champs_ce64ab {
    /* 0x0 */ s32 unk0;
    char pad4[0x1C];
    /* 0x20 */ s32 unk20;
};
extern "C" void StartPas__12CSceneObjSeqFi(CSceneObjSeq *objet, s32 arg0) {
    struct temp_v0_champs_ce64ab *temp_v0;

    temp_v0 = (struct temp_v0_champs_ce64ab *) (SearchNextPosSeq__12CSceneObjSeqFv(objet));
    if (temp_v0 != NULL) {
        temp_v0->unk0 = 8;
        temp_v0->unk20 = arg0;
    }
}
extern "C" void Jump__12CSceneObjSeqFPffi(CSceneObjSeq *objet, f32 *arg0, f32 arg1, s32 arg2) {
    s32 *temp_v0;

    temp_v0 = (s32 *) (SearchNextPosSeq__12CSceneObjSeqFv(objet));
    if (temp_v0 != NULL) {
        if (arg2 > 0) {
            arg2 = (arg2 * 50) / 60;
            if (arg2 <= 0) {
                arg2 = 1;
            }
            arg1 = 1.2f * arg1;
        }
        *temp_v0 = 9;
        sceVu0CopyVector(temp_v0 + 4, arg0);
        ((f32 *) temp_v0)[8] = arg1;
        temp_v0[9] = arg2;
    }
}
extern "C" s32 strcpy(...);
extern "C" void SetEohFramePos__12CSceneObjSeqFiPciPf(CSceneObjSeq *objet, s32 arg0, char *arg1, s32 arg2, f32 *arg3) {
    s32 *temp_v0;

    temp_v0 = (s32 *) (SearchNextPosSeq__12CSceneObjSeqFv(objet));
    if (temp_v0 != NULL) {
        if (arg2 > 0) {
            arg2 = (arg2 * 50) / 60;
            if (arg2 <= 0) {
                arg2 = 1;
            }
        }
        *temp_v0 = 0xA;
        temp_v0[8] = arg0;
        strcpy((u8 *) temp_v0 + 0x2C, arg1);
        temp_v0[9] = arg2;
        sceVu0CopyVector(temp_v0 + 4, arg3);
    }
}
extern "C" void AddPos__12CSceneObjSeqFPfi(CSceneObjSeq *objet, f32 *arg0, s32 arg1) {
    s32 *temp_v0;

    temp_v0 = (s32 *) (SearchNextPosSeq__12CSceneObjSeqFv(objet));
    if (temp_v0 != NULL) {
        if (arg1 > 0) {
            arg1 = (arg1 * 50) / 60;
            if (arg1 <= 0) {
                arg1 = 1;
            }
        }
        *temp_v0 = 0xb;
        sceVu0CopyVector(temp_v0 + 4, arg0);
        temp_v0[8] = arg1;
    }
}
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", AttachCamera__12CSceneObjSeqFfi);
extern "C" void RotDelay__12CSceneObjSeqFi(CSceneObjSeq *objet, s32 arg0) {
    s32 *temp_v0;

    temp_v0 = (s32 *) (SearchNextRotSeq__12CSceneObjSeqFv(objet));
    if (temp_v0 != NULL) {
        if (arg0 > 0) {
            arg0 = (arg0 * 50) / 60;
            if (arg0 <= 0) {
                arg0 = 1;
            }
        }
        *temp_v0 = 0xd;
        temp_v0[8] = arg0;
    }
}
extern "C" s32 SearchNextRotSeq__12CSceneObjSeqFv(void *);
extern "C" void SetRot__12CSceneObjSeqFPf(CSceneObjSeq *objet, f32 *arg0) {
    s32 *temp_v0;

    temp_v0 = (s32 *) (SearchNextRotSeq__12CSceneObjSeqFv(objet));
    if (temp_v0 != NULL) {
        *temp_v0 = 0xE;
        sceVu0CopyVector(((s32 *) ((u8 *) temp_v0 + 0x10)), arg0);
    }
}
extern "C" void Rotation__12CSceneObjSeqFPfi(CSceneObjSeq *objet, f32 *arg0, s32 arg1) {
    s32 *temp_v0;

    temp_v0 = (s32 *) (SearchNextRotSeq__12CSceneObjSeqFv(objet));
    if (temp_v0 != NULL) {
        if (arg1 > 0) {
            arg1 = (arg1 * 50) / 60;
            if (arg1 <= 0) {
                arg1 = 1;
            }
        }
        *temp_v0 = 0xf;
        sceVu0CopyVector(temp_v0 + 4, arg0);
        temp_v0[8] = arg1;
    }
}
extern "C" void Rotation2__12CSceneObjSeqFPfiif(CSceneObjSeq *objet, f32 *arg0, s32 arg1, s32 arg2, f32 arg3) {
    s32 *temp_v0;

    temp_v0 = (s32 *) (SearchNextRotSeq__12CSceneObjSeqFv(objet));
    if (temp_v0 != NULL) {
        if (arg1 > 0) {
            arg1 = (arg1 * 50) / 60;
            if (arg1 <= 0) {
                arg1 = 1;
            }
        }
        *temp_v0 = 0x10;
        sceVu0CopyVector(temp_v0 + 4, arg0);
        temp_v0[8] = arg1;
        temp_v0[9] = arg2;
        ((f32 *) temp_v0)[10] = arg3;
    }
}
extern "C" void Reference__12CSceneObjSeqFPfi(CSceneObjSeq *objet, f32 *arg0, s32 arg1) {
    s32 *temp_v0;

    temp_v0 = (s32 *) (SearchNextRotSeq__12CSceneObjSeqFv(objet));
    if (temp_v0 != NULL) {
        if (arg1 > 0) {
            arg1 = (arg1 * 50) / 60;
            if (arg1 <= 0) {
                arg1 = 1;
            }
        }
        *temp_v0 = 0x11;
        sceVu0CopyVector(temp_v0 + 4, arg0);
        temp_v0[8] = arg1;
    }
}
extern "C" void MotionDelay__12CSceneObjSeqFi(CSceneObjSeq *objet, s32 arg0) {
    s32 *temp_v0;

    temp_v0 = (s32 *) (SearchNextMotSeq__12CSceneObjSeqFv(objet));
    if (temp_v0 != NULL) {
        if (arg0 > 0) {
            arg0 = (arg0 * 50) / 60;
            if (arg0 <= 0) {
                arg0 = 1;
            }
        }
        *temp_v0 = 0x12;
        temp_v0[8] = arg0;
    }
}
extern "C" s32 strcpy(...);
extern "C" void SetMotion__12CSceneObjSeqFPcif(CSceneObjSeq *objet, char *arg0, s32 arg1, f32 arg2) {
    s32 *temp_v0;

    temp_v0 = (s32 *) (SearchNextMotSeq__12CSceneObjSeqFv(objet));
    if (temp_v0 != NULL) {
        *temp_v0 = 0x13;
        strcpy((u8 *) temp_v0 + 0x2C, arg0);
        temp_v0[8] = arg1;
        ((f32 *) temp_v0)[9] = arg2;
        temp_v0[10] = 0;
    }
}
extern "C" s32 strcpy(...);
extern "C" void NextMotion__12CSceneObjSeqFPcif(CSceneObjSeq *objet, char *arg0, s32 arg1, f32 arg2) {
    s32 *temp_v0;

    temp_v0 = (s32 *) (SearchNextMotSeq__12CSceneObjSeqFv(objet));
    if (temp_v0 != NULL) {
        *temp_v0 = 0x14;
        strcpy((u8 *) temp_v0 + 0x2C, arg0);
        temp_v0[8] = arg1;
        ((f32 *) temp_v0)[9] = arg2;
        temp_v0[10] = 0;
    }
}
extern "C" s32 SearchNextMotSeq__12CSceneObjSeqFv(void *);
extern "C" void MotionWait__12CSceneObjSeqFv(CSceneObjSeq *objet) {
    s32 *temp_v0;

    temp_v0 = (s32 *) (SearchNextMotSeq__12CSceneObjSeqFv(objet));
    if (temp_v0 != NULL) {
        *temp_v0 = 0x15;
    }
}
extern "C" void SetMotionTrg__12CSceneObjSeqFv(CSceneObjSeq *objet) {
    s32 *temp_v0;

    temp_v0 = (s32 *) (SearchNextMotSeq__12CSceneObjSeqFv(objet));
    if (temp_v0 != NULL) {
        *temp_v0 = 0x16;
    }
}
extern "C" void MotionTrgWait__12CSceneObjSeqFv(CSceneObjSeq *objet) {
    s32 *temp_v0;

    temp_v0 = (s32 *) (SearchNextMotSeq__12CSceneObjSeqFv(objet));
    if (temp_v0 != NULL) {
        *temp_v0 = 0x17;
    }
}
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", SetStep__12CSceneObjSeqFf);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", SetChengeStep__12CSceneObjSeqFf);
extern "C" void ResetMotion__12CSceneObjSeqFv(CSceneObjSeq *objet) {
    s32 *temp_v0;

    temp_v0 = (s32 *) (SearchNextMotSeq__12CSceneObjSeqFv(objet));
    if (temp_v0 != NULL) {
        *temp_v0 = 0x1A;
    }
}
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", SetMotionNowTime__12CSceneObjSeqFf);
INCLUDE_ASM("nonmatchings/game/cscenecmrseq", SetMotionWaitTime__12CSceneObjSeqFf);
extern "C" void NormalDrive__12CSceneObjSeqFv(CSceneObjSeq *objet) {
    s32 *temp_v0;

    temp_v0 = (s32 *) (SearchNextMotSeq__12CSceneObjSeqFv(objet));
    if (temp_v0 != NULL) {
        *temp_v0 = 0x1D;
    }
}
extern "C" void TexAnimeDelay__12CSceneObjSeqFi(CSceneObjSeq *objet, s32 arg0) {
    s32 *temp_v0;

    temp_v0 = (s32 *) (SearchNextAnmSeq__12CSceneObjSeqFv(objet));
    if (temp_v0 != NULL) {
        if (arg0 > 0) {
            arg0 = (arg0 * 50) / 60;
            if (arg0 <= 0) {
                arg0 = 1;
            }
        }
        *temp_v0 = 0x1e;
        temp_v0[8] = arg0;
    }
}
extern "C" char _1527_00371A40[];
extern "C" s32 strcpy(...);
extern "C" void TexAnime__12CSceneObjSeqFPci(CSceneObjSeq *objet, char *arg0, s32 arg1) {
    s32 *temp_v0;

    temp_v0 = (s32 *) (SearchNextAnmSeq__12CSceneObjSeqFv(objet));
    if (temp_v0 != NULL) {
        *temp_v0 = 0x1F;
        if (arg0 != NULL) {
            strcpy((u8 *) temp_v0 + 0x2C, arg0);
        } else {
            strcpy((u8 *) temp_v0 + 0x2C, _1527_00371A40);
        }
        temp_v0[8] = arg1;
    }
}
extern "C" void ColorDelay__12CSceneObjSeqFi(CSceneObjSeq *objet, s32 arg0) {
    s32 *temp_v0;

    temp_v0 = (s32 *) (SearchNextColSeq__12CSceneObjSeqFv(objet));
    if (temp_v0 != NULL) {
        if (arg0 > 0) {
            arg0 = (arg0 * 50) / 60;
            if (arg0 <= 0) {
                arg0 = 1;
            }
        }
        *temp_v0 = 0x20;
        temp_v0[8] = arg0;
    }
}
extern "C" void SetColor__12CSceneObjSeqFPfi(CSceneObjSeq *objet, f32 *arg0, s32 arg1) {
    s32 *temp_v0;

    temp_v0 = (s32 *) (SearchNextColSeq__12CSceneObjSeqFv(objet));
    if (temp_v0 != NULL) {
        if (arg1 > 0) {
            arg1 = (arg1 * 50) / 60;
            if (arg1 <= 0) {
                arg1 = 1;
            }
        }
        *temp_v0 = 0x21;
        sceVu0CopyVector(temp_v0 + 4, arg0);
        temp_v0[8] = arg1;
    }
}
extern "C" void ScaleDelay__12CSceneObjSeqFi(CSceneObjSeq *objet, s32 arg0) {
    s32 *temp_v0;

    temp_v0 = (s32 *) (SearchNextScaleSeq__12CSceneObjSeqFv(objet));
    if (temp_v0 != NULL) {
        if (arg0 > 0) {
            arg0 = (arg0 * 50) / 60;
            if (arg0 <= 0) {
                arg0 = 1;
            }
        }
        *temp_v0 = 0x22;
        temp_v0[8] = arg0;
    }
}
extern "C" void SetScale__12CSceneObjSeqFPfi(CSceneObjSeq *objet, f32 *arg0, s32 arg1) {
    s32 *temp_v0;

    temp_v0 = (s32 *) (SearchNextScaleSeq__12CSceneObjSeqFv(objet));
    if (temp_v0 != NULL) {
        if (arg1 > 0) {
            arg1 = (arg1 * 50) / 60;
            if (arg1 <= 0) {
                arg1 = 1;
            }
        }
        *temp_v0 = 0x23;
        sceVu0CopyVector(temp_v0 + 4, arg0);
        temp_v0[8] = arg1;
    }
}
extern "C" void SeDelay__12CSceneObjSeqFi(CSceneObjSeq *objet, s32 arg0) {
    s32 *temp_v0;

    temp_v0 = (s32 *) (SearchNextSeSeq__12CSceneObjSeqFv(objet));
    if (temp_v0 != NULL) {
        if (arg0 > 0) {
            arg0 = (arg0 * 50) / 60;
            if (arg0 <= 0) {
                arg0 = 1;
            }
        }
        *temp_v0 = 0x24;
        temp_v0[8] = arg0;
    }
}
extern "C" s32 SearchNextSeSeq__12CSceneObjSeqFv(void *);
struct temp_v0_champs {
    /* 0x0 */ s32 unk0;
    char pad4[0x1C];
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
};
extern "C" void SePlay__12CSceneObjSeqFii(CSceneObjSeq *objet, s32 arg0, s32 arg1) {
    struct temp_v0_champs *temp_v0;

    temp_v0 = (struct temp_v0_champs *) (SearchNextSeSeq__12CSceneObjSeqFv(objet));
    if (temp_v0 != NULL) {
        temp_v0->unk0 = 0x25;
        temp_v0->unk20 = arg0;
        temp_v0->unk24 = arg1;
    }
}
extern "C" s32 SearchNextMotSeq__12CSceneObjSeqFv(void *);
extern "C" s32 SearchNextSeSeq__12CSceneObjSeqFv(void *);
extern "C" void ResetDAPosition__12CSceneObjSeqFv(CSceneObjSeq *objet) {
    s32 *temp_v0;
    s32 *temp_v0_2;

    temp_v0 = (s32 *) (SearchNextSeSeq__12CSceneObjSeqFv(objet));
    if (temp_v0 != NULL) {
        *temp_v0 = 0x26;
    }
    temp_v0_2 = (s32 *) (SearchNextMotSeq__12CSceneObjSeqFv(objet));
    if (temp_v0_2 != NULL) {
        *temp_v0_2 = 0x26;
    }
}
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
extern "C" u8 EdEventInfo[4768];
extern "C" u32 SetWorldCoordFlg;
extern "C" s32 mgRotMatrixXYZ__FPA4_fPf(...);
extern "C" s32 sceVu0AddVector(...);
extern "C" s32 VectMatMul__FPfPfPA4_f_00260A70(...);
extern "C" void CalcPosWorldCoord__FPf(f32 *arg0) {
    f32 sp20[16];
    f32 sp60[4];
    if (SetWorldCoordFlg != 0) {
        mgRotMatrixXYZ__FPA4_fPf((f32 (*)[4]) sp20, &EdEventInfo[0x10]);
        VectMatMul__FPfPfPA4_f_00260A70(sp60, arg0, sp20);
        sceVu0AddVector(arg0, &EdEventInfo, sp60);
    }
}
