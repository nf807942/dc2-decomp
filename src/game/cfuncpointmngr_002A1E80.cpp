/* CFuncPointMngr
 *
 * Unité découpée par `make carve` : 16 fonctions, 8040 octets, de
 * 0x002A1E80 à 0x002A3E30. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

/* Les globales que ces accesseurs servent. Leur taille déclarée est celle que
 * le découpage leur donne, et c'est elle qui décide du `%gp_rel`. */
extern s16 TitleOmakeFlag;
extern s32 OmakeFlag;


INCLUDE_ASM("nonmatchings/game/cfuncpointmngr_002A1E80", UpdateStatus__14CFuncPointMngrFv);
INCLUDE_ASM("nonmatchings/game/cfuncpointmngr_002A1E80", Copy__14CFuncPointMngrFR14CFuncPointMngrP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/cfuncpointmngr_002A1E80", Initialize__14CFuncPointMngrFv);
INCLUDE_ASM("nonmatchings/game/cfuncpointmngr_002A1E80", DrawFireEffect__FPA4_fP14CFuncPointMngrP15CFuncPointCheckfP10mgCTextureP10mgCTexture);
INCLUDE_ASM("nonmatchings/game/cfuncpointmngr_002A1E80", DrawFireRaster__FPA4_fP14CFuncPointMngrP15CFuncPointCheckP11CFireRaster);
struct FpVecA4 {
    f32 v[3];
    u32 w;
};
struct FpMngrA4;
struct FpCheckA4;
struct FpPntA4 {
    char p0[0x20];
    s32 f20;
    f32 f24;
    f32 f28;
    char p2C[4];
    s32 f30;
    char p34[0xC];
    f32 f40[4];
    f32 f50[4];
    char p60[0x10];
    char f70[0x110];
    f32 f180[4];
    char p190[0x20];
    s32 f1B0;
};
extern "C" s32 GetEnd__14CFuncPointMngrFv(void *);
extern "C" FpPntA4 *Get__14CFuncPointMngrFv(void *);
extern "C" s32 GetStart__14CFuncPointMngrFi(void *, s32);
extern "C" s32 UpdateFlag__14CFuncPointMngrFiP15CFuncPointCheck(void *, s32, FpCheckA4 *);
extern "C" s32 GetLWMatrix__8mgCFrameFPA4_f(void *, f32 (*)[4]);
extern "C" s32 mgMulMatrix__FPA4_fPA4_fPA4_f(f32 (*)[4], f32 (*)[4], f32 (*)[4]);
extern "C" void sceVu0ApplyMatrix(f32 *result, f32 (*matrix)[4], f32 *vector);
extern "C" s32 sndGetVolPan__FPfPfPfPfff(f32 *, f32 *, f32 *, f32 *, f32, f32);
extern "C" s32 sndGetVolPan__FPfPfPfff(f32 *, f32 *, f32 *, f32, f32);
extern "C" s32 GetSeSrcVolPan__FPA4_fP14CFuncPointMngrP15CFuncPointCheckPiPfPfi(f32 (*mat)[4], FpMngrA4 *mgr, FpCheckA4 *chk, s32 *kinds, f32 *vols, f32 *pans, s32 max) {
    FpVecA4 q90;
    f32 vA0[4];
    f32 mB0[4][4];
    FpPntA4 *p;
    s32 n;

    n = 0;
    UpdateFlag__14CFuncPointMngrFiP15CFuncPointCheck(mgr, 2, chk);
    GetStart__14CFuncPointMngrFi(mgr, 2);
    p = Get__14CFuncPointMngrFv(mgr);
    if (p != NULL) {
        do {
            if (p->f1B0 != 0) {
                if (n >= max) {
                    return n;
                }
                *(u128 *) q90.v = *(u128 *) p->f180;
                q90.w = 0x3F800000;
                sceVu0ApplyMatrix(q90.v, mat, q90.v);
                sndGetVolPan__FPfPfPfff(vols, pans, q90.v, 10.0f, 1200.0f);
                if (*vols > 0.01f) {
                    vols++;
                    *kinds = 2;
                    pans++;
                    n++;
                    kinds++;
                }
            }
            p = Get__14CFuncPointMngrFv(mgr);
        } while (p != NULL);
    }
    GetEnd__14CFuncPointMngrFv(mgr);
    if (UpdateFlag__14CFuncPointMngrFiP15CFuncPointCheck(mgr, 8, chk) > 0) {
        GetStart__14CFuncPointMngrFi(mgr, 8);
        if ((p = Get__14CFuncPointMngrFv(mgr)) != NULL) {
            do {
                if (p->f1B0 != 0) {
                    if (n >= max) {
                        return n;
                    }
                    if (p->f30 == 1) {
                        GetLWMatrix__8mgCFrameFPA4_f(p->f70, mB0);
                        mgMulMatrix__FPA4_fPA4_fPA4_f(mB0, mB0, mat);
                        sceVu0ApplyMatrix(q90.v, mB0, p->f40);
                        sceVu0ApplyMatrix(vA0, mB0, p->f50);
                        sndGetVolPan__FPfPfPfPfff(vols, pans, q90.v, vA0, p->f24, p->f28);
                    } else {
                        *(u128 *) q90.v = *(u128 *) p->f180;
                        q90.w = 0x3F800000;
                        sceVu0ApplyMatrix(q90.v, mat, q90.v);
                        sndGetVolPan__FPfPfPfff(vols, pans, q90.v, p->f24, p->f28);
                    }
                    if (*vols > 0.01f) {
                        vols++;
                        pans++;
                        n++;
                        *kinds = p->f20;
                        kinds++;
                    }
                }
            } while ((p = Get__14CFuncPointMngrFv(mgr)) != NULL);
        }
        GetEnd__14CFuncPointMngrFv(mgr);
    }
    return n;
}
INCLUDE_ASM("nonmatchings/game/cfuncpointmngr_002A1E80", GetLightAnimeWeight__FP10CFuncPointi);
extern "C" s32 mgGetVSyncCount__Fv(void);
extern "C" s32 srand(...);
extern "C" void title_init_rand__Fv(void) {
    srand(mgGetVSyncCount__Fv());
}
extern "C" u8 CSnd;
struct temp_v0_2_champs_6d2dd0 {
    char pad0[0xC];
    /* 0xC */ s32 unkC;
};
extern "C" s32 GetSaveData__Fv(void);
extern "C" s32 SetStereoMode__6CSoundFi(void *, s32);
extern "C" void SetSoundMode__Fv(void) {
    s32 temp_v0;
    struct temp_v0_2_champs_6d2dd0 *temp_v0_2;

    temp_v0 = GetSaveData__Fv();
    if (temp_v0 != 0) {
        /* La conversion en `u8 *` porte l'arithmetique en octets. Sans elle,
         * MWCC met le pas a l'echelle du type pointe et la constante emise
         * est multipliee d'autant. */
        temp_v0_2 = (struct temp_v0_2_champs_6d2dd0 *) ((u8 *) temp_v0 + 0x1C574);
        if (temp_v0_2 != NULL) {
            if (temp_v0_2->unkC == 0) {
                SetStereoMode__6CSoundFi(&CSnd, 1);
                return;
            }
            goto block_5;
        }
block_5:
        SetStereoMode__6CSoundFi(&CSnd, 0);
    }
}

void InitTitleOmakeFlag(void) {
    TitleOmakeFlag = 0;
    OmakeFlag = 0;
}
void TitleOmakeOn(void) {
    TitleOmakeFlag = 1;
}
s32 CheckOmakeFlag(void) {
    return TitleOmakeFlag;
}
INCLUDE_ASM("nonmatchings/game/cfuncpointmngr_002A1E80", InitOmakeEnv__FiP13INIT_LOOP_ARGPi);
INCLUDE_ASM("nonmatchings/game/cfuncpointmngr_002A1E80", TitleInit__F13INIT_LOOP_ARG);
INCLUDE_ASM("nonmatchings/game/cfuncpointmngr_002A1E80", TitleBootInit__Fv);
extern "C" u8 GamePad_003FA5A0[1144];
extern "C" u8 _1267[12];
extern "C" u32 mgFrameRate;
extern "C" s32 AutoRepeatOff__8CGamePadFv(void *);
extern "C" s32 MenuModeOff__8CGamePadFv(void *);
extern "C" s32 mgCloseFont__Fv(void);
extern "C" s32 printf(...);
extern "C" s32 sndSeAllStop__Fi(s32);
extern "C" s32 CheckOmakeFlag__Fv(void);
extern "C" void TitleExit__Fv(void) {
    if (CheckOmakeFlag__Fv() != 0) {
        OmakeFlag = 1;
    }
    printf(&_1267, OmakeFlag);
    sndSeAllStop__Fi(-1);
    AutoRepeatOff__8CGamePadFv(&GamePad_003FA5A0);
    MenuModeOff__8CGamePadFv(&GamePad_003FA5A0);
    mgFrameRate = 2;
    mgCloseFont__Fv();
}
