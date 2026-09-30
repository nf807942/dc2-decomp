/* CActionChara, CCharacter2
 *
 * Unité découpée par `make carve` : 52 fonctions, 24508 octets, de
 * 0x0016FE00 à 0x00175F10. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

INCLUDE_ASM("nonmatchings/game/cactionchara_0016FE00", RoboBikeMoveIF__12CActionCharaFi);
INCLUDE_ASM("nonmatchings/game/cactionchara_0016FE00", RoboAirMoveIF__12CActionCharaFii);
INCLUDE_ASM("nonmatchings/game/cactionchara_0016FE00", MonsterMoveIF__12CActionCharaFv);
INCLUDE_ASM("nonmatchings/game/cactionchara_0016FE00", GuardEffectSet__FP6CScenePf);
INCLUDE_ASM("nonmatchings/game/cactionchara_0016FE00", HitEffectSet__FP6CScenePf);
INCLUDE_ASM("nonmatchings/game/cactionchara_0016FE00", CheckAmuletAvoid__Fi);
INCLUDE_ASM("nonmatchings/game/cactionchara_0016FE00", CheckEquipSetItem__Fi);
INCLUDE_ASM("nonmatchings/game/cactionchara_0016FE00", CheckDamage__12CActionCharaFv);
INCLUDE_ASM("nonmatchings/game/cactionchara_0016FE00", LoadActionFile__12CActionCharaFPciP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/cactionchara_0016FE00", InitScript__12CActionCharaFv);
INCLUDE_ASM("nonmatchings/game/cactionchara_0016FE00", SetHold__12CActionCharaFv);
INCLUDE_ASM("nonmatchings/game/cactionchara_0016FE00", RunScript__12CActionCharaFP6CSceneP14RUN_SCRIPT_ENV);
INCLUDE_ASM("nonmatchings/game/cactionchara_0016FE00", CheckReleaseTimming__12CActionCharaFi);
INCLUDE_ASM("nonmatchings/game/cactionchara_0016FE00", StepParam__12CActionCharaFv);
INCLUDE_ASM("nonmatchings/game/cactionchara_0016FE00", Step__12CActionCharaFv);
struct inferred;
typedef struct CActionChara {
    /* 0x000 */ char pad0[0x678];
    /* 0x678 */ CActionChara *unk678;               /* inferred */
} CActionChara;                                     /* size >= 0x67C */
typedef struct CCharacter2_infere {
    /* 0x000 */ char pad0[0x678];
    /* 0x678 */ CCharacter2_infere *unk678;                /* inferred */
} CCharacter2_infere;                                      /* size >= 0x67C */
extern "C" s32 ShadowStep__11CCharacter2Fv(void *);
extern "C" void ShadowStep__12CActionCharaFv(CActionChara *objet) {
    CActionChara *var_s0;

    var_s0 = (CActionChara *) (objet);
    if (objet != NULL) {
        do {
            ShadowStep__11CCharacter2Fv((CCharacter2_infere *) var_s0);
            var_s0 = (CActionChara *) (var_s0->unk678);
        } while (var_s0 != NULL);
    }
}
INCLUDE_ASM("nonmatchings/game/cactionchara_0016FE00", Initialize__12CActionCharaFP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/cactionchara_0016FE00", Copy__12CActionCharaFR12CActionCharaP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/cactionchara_0016FE00", __as__11CCharacter2FRC11CCharacter2);
extern "C" void SetPosition__9mgCObjectFPf(void *, float *);
extern "C" void SetPosition__11CCharacter2FPf(void *o, float *p) { SetPosition__9mgCObjectFPf(o, p); }

struct mgCFrameAO {
    char pad0[0x54];
    s32 f54;
    char pad58[0x9C];
    struct FrameFlag *fF4;
};
struct FrameFlag {
    char pad0[0x18];
    s32 flags;
};
struct COutLineDrawAO {
    COutLineDrawAO *next;
    char pad4[0x30];
    mgCFrameAO *frame;
};
struct CCharacter2AO {
    char pad0[0x70];
    mgCFrameAO *root;
    char pad74[0xB0];
    COutLineDrawAO *outline;
};
extern "C" mgCFrameAO *SearchFrame__8mgCFrameFPc(mgCFrameAO *, s8 *);
extern "C" void SetFrame__12COutLineDrawFP8mgCFrame(COutLineDrawAO *, mgCFrameAO *);
extern "C" void AddOutLine__11CCharacter2FPcP12COutLineDraw(CCharacter2AO *self, s8 *name, COutLineDrawAO *line) {
    mgCFrameAO *frame;
    COutLineDrawAO *p;
    COutLineDrawAO *last;
    COutLineDrawAO *q;
    if (name != NULL) {
        frame = self->root;
        if (*name != 0) {
            frame = SearchFrame__8mgCFrameFPc(frame, name);
            if (frame == NULL) {
                for (p = self->outline; p != NULL; p = p->next) {
                    frame = SearchFrame__8mgCFrameFPc(p->frame, name);
                    if (frame != NULL) {
                        break;
                    }
                }
            }
        }
        if (frame != NULL) {
            if (frame->f54 != 0) {
                FrameFlag *fl = frame->fF4;
                if (fl != NULL) {
                    fl->flags |= 4;
                }
            }
            SetFrame__12COutLineDrawFP8mgCFrame(line, frame);
            last = self->outline;
            if (last == NULL) {
                self->outline = line;
                return;
            }
            if (last != NULL) {
                do {
                    q = last->next;
                    if (q == NULL) {
                        break;
                    }
                    last = q;
                } while (q != NULL);
            }
            last->next = line;
        }
    }
}

INCLUDE_ASM("nonmatchings/game/cactionchara_0016FE00", CopyOutLine__11CCharacter2FP11CCharacter2);
INCLUDE_ASM("nonmatchings/game/cactionchara_0016FE00", Draw__11CCharacter2Fv);
INCLUDE_ASM("nonmatchings/game/cactionchara_0016FE00", SetDeformMesh__11CCharacter2Fv);
INCLUDE_ASM("nonmatchings/game/cactionchara_0016FE00", DrawStep__11CCharacter2Fv);
INCLUDE_ASM("nonmatchings/game/cactionchara_0016FE00", GetCameraDist__11CCharacter2Fv);
INCLUDE_ASM("nonmatchings/game/cactionchara_0016FE00", DrawDirect__11CCharacter2Fv);
INCLUDE_ASM("nonmatchings/game/cactionchara_0016FE00", DrawShadowDirect__11CCharacter2Fv);
INCLUDE_ASM("nonmatchings/game/cactionchara_0016FE00", UpdatePosition__11CCharacter2Fv);
INCLUDE_ASM("nonmatchings/game/cactionchara_0016FE00", ResetDAPosition__11CCharacter2Fv);
INCLUDE_ASM("nonmatchings/game/cactionchara_0016FE00", GetDefaultStep__11CCharacter2Fv);
extern "C" void SetStep__11CCharacter2Ff(void *objet, f32 arg0) {
    *(f32 *) ((u8 *) objet + 0x390) = arg0;
}
extern "C" void ResetMotion__11CCharacter2Fv(void *objet) {
    *(s32 *) ((u8 *) objet + 0x374) = 0;
    *(s32 *) ((u8 *) objet + 0x368) = 0;
    *(s32 *) ((u8 *) objet + 0x3A8) = 0;
    *(s32 *) ((u8 *) objet + 0x3A4) = 0;
}
typedef struct CCharacter2_infere2 {
    /* 0x000 */ char pad0[0x384];
    /* 0x384 */ s32 unk384;                         /* inferred */
    /* 0x388 */ char pad388[0x180];                 /* maybe part of unk384[0x61]void */
    /* 0x508 */ f32 unk508;                         /* inferred */
} CCharacter2_infere2;                                      /* size >= 0x50C */
extern "C" f32 GetChgStepWait__11CCharacter2Fv(CCharacter2_infere2 *objet) {
    if (objet->unk384 != 3) {
        return -1.0f;
    }
    return objet->unk508;
}
INCLUDE_ASM("nonmatchings/game/cactionchara_0016FE00", CheckMotionEnd__11CCharacter2Fv);
struct inferred;
typedef struct CCharacter2 {
    /* 0x000 */ char pad0[0x368];
    /* 0x368 */ s32 unk368;                         /* inferred */
    /* 0x36C */ s32 unk36C;                         /* inferred */
    /* 0x370 */ s32 unk370;                         /* inferred */
    /* 0x374 */ char pad374[4];
    /* 0x378 */ s32 unk378;                         /* inferred */
    /* 0x37C */ char pad37C[0x2C];                  /* maybe part of unk378[0xC]void */
    /* 0x3A8 */ s32 unk3A8;                         /* inferred */
    /* 0x3AC */ char pad3AC[0xC];                   /* maybe part of unk3A8[4]void */
    /* 0x3B8 */ s32 unk3B8;                         /* inferred */
    /* 0x3BC */ char pad3BC[0x150];                 /* maybe part of unk3B8[0x55]void */
    /* 0x50C */ s32 unk50C;                         /* inferred */
} CCharacter2;                                      /* size >= 0x510 */
extern "C" s32 GetKeyListIndexPtr__11CCharacter2FiPi(void *, s32, s32 *);
extern "C" void SetMotion__11CCharacter2Fii(CCharacter2 *objet, s32 arg0, s32 arg1) {
    s32 sp3C;
    s32 temp_v0;

    temp_v0 = (s32) (GetKeyListIndexPtr__11CCharacter2FiPi(objet, arg0, &sp3C));
    if (temp_v0 != 0) {
        objet->unk368 = temp_v0;
        objet->unk36C = arg1;
        objet->unk370 = sp3C;
        objet->unk50C = 0x3E4CCCCD;
        objet->unk378 = 0;
        objet->unk3A8 = 0;
        objet->unk3B8 = 0;
    }
}
extern "C" void SetMotionPara__11CCharacter2FPcii(void *, char *, int, int);
extern "C" void SetMotion__11CCharacter2FPci(void *o, char *n, int i) { SetMotionPara__11CCharacter2FPcii(o, n, i, -1); }

INCLUDE_ASM("nonmatchings/game/cactionchara_0016FE00", SetNowFrameWeight__11CCharacter2Ff);
INCLUDE_ASM("nonmatchings/game/cactionchara_0016FE00", SetMotionPara__11CCharacter2FPcii);
INCLUDE_ASM("nonmatchings/game/cactionchara_0016FE00", SetDAnimeEnable__11CCharacter2Fi);
INCLUDE_ASM("nonmatchings/game/cactionchara_0016FE00", GetSoundInfoCopy__11CCharacter2FP9mgCMemory);
typedef struct CCharacter2_infere3 {
    /* 0x000 */ char pad0[0x580];
    /* 0x580 */ s32 unk580;                         /* inferred */
    /* 0x584 */ char pad584[0x18];                  /* maybe part of unk580[7]void */
    /* 0x59C */ s32 unk59C;                         /* inferred */
} CCharacter2_infere3;                                      /* size >= 0x5A0 */
extern "C" s32 CheckFootEffect__11CCharacter2Fv(CCharacter2_infere3 *objet) {
    if (objet->unk59C <= 0) {
        return -1;
    }
    return objet->unk580;
}
INCLUDE_ASM("nonmatchings/game/cactionchara_0016FE00", SePlay__11CCharacter2Fv);
INCLUDE_ASM("nonmatchings/game/cactionchara_0016FE00", Step__11CCharacter2Fv);
INCLUDE_ASM("nonmatchings/game/cactionchara_0016FE00", StepDA__11CCharacter2Fi);
INCLUDE_ASM("nonmatchings/game/cactionchara_0016FE00", SetWind__11CCharacter2FfPf);
INCLUDE_ASM("nonmatchings/game/cactionchara_0016FE00", ResetWind__11CCharacter2Fv);
INCLUDE_ASM("nonmatchings/game/cactionchara_0016FE00", SetFloor__11CCharacter2Ff);
INCLUDE_ASM("nonmatchings/game/cactionchara_0016FE00", ResetFloor__11CCharacter2Fv);
INCLUDE_ASM("nonmatchings/game/cactionchara_0016FE00", NormalDrive__11CCharacter2Fv);
INCLUDE_ASM("nonmatchings/game/cactionchara_0016FE00", ShadowStep__11CCharacter2Fv);
INCLUDE_ASM("nonmatchings/game/cactionchara_0016FE00", GetKeyListIndexPtr__11CCharacter2FiPi);
