/* CGamePad
 *
 * Unité découpée par `make carve` : 69 fonctions, 24592 octets, de
 * 0x0014B500 à 0x00151690. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

INCLUDE_ASM("nonmatchings/game/cgamepad", CancelAutoRepeat2__8CGamePadFi);
INCLUDE_ASM("nonmatchings/game/cgamepad", SetAutoRepeat__8CGamePadFiii);
INCLUDE_ASM("nonmatchings/game/cgamepad", SetAutoRepeat2__8CGamePadFiii);
INCLUDE_ASM("nonmatchings/game/cgamepad", KeyLock__8CGamePadFi);
INCLUDE_ASM("nonmatchings/game/cgamepad", KeyLock2__8CGamePadFi);
INCLUDE_ASM("nonmatchings/game/cgamepad", DebugKeyLock__8CGamePadFi);
struct inferred;
typedef struct CGamePad_infere8 {
    /* 0x000 */ char pad0[4];
    /* 0x004 */ s32 unk4;                           /* inferred */
    /* 0x008 */ char pad8[0x454];                   /* maybe part of unk4[0x116]void */
    /* 0x45C */ s32 unk45C;                         /* inferred */
} CGamePad_infere8;                                         /* size >= 0x460 */
extern "C" s32 GetPadOn__8CGamePadFv(CGamePad_infere8 *objet) {
    if (objet->unk45C != 0) {
        return 0;
    }
    return objet->unk4;
}
struct inferred;
typedef struct CGamePad_infere5 {
    /* 0x000 */ char pad0[4];
    /* 0x004 */ s32 unk4;                           /* inferred */
    /* 0x008 */ char pad8[0x94];                    /* maybe part of unk4[0x26]void */
    /* 0x09C */ s32 unk9C;                          /* inferred */
    /* 0x0A0 */ char padA0[0x3BC];                  /* maybe part of unk9C[0xF0]void */
    /* 0x45C */ s32 unk45C;                         /* inferred */
} CGamePad_infere5;                                         /* size >= 0x460 */
extern "C" s32 GetPadDown__8CGamePadFv(CGamePad_infere5 *objet) {
    if (objet->unk45C != 0) {
        return 0;
    }
    return objet->unk4 & ~objet->unk9C;
}
typedef struct CGamePad_infere6 {
    /* 0x000 */ char pad0[4];
    /* 0x004 */ s32 unk4;                           /* inferred */
    /* 0x008 */ char pad8[0x94];                    /* maybe part of unk4[0x26]void */
    /* 0x09C */ s32 unk9C;                          /* inferred */
    /* 0x0A0 */ char padA0[0x3BC];                  /* maybe part of unk9C[0xF0]void */
    /* 0x45C */ s32 unk45C;                         /* inferred */
} CGamePad_infere6;                                         /* size >= 0x460 */
extern "C" s32 GetPadUp__8CGamePadFv(CGamePad_infere6 *objet) {
    if (objet->unk45C != 0) {
        return 0;
    }
    return ~objet->unk4 & objet->unk9C;
}
struct CGamePad;
extern "C" s32 GetRX__8CGamePadFv(void *);
extern "C" f32 GetRXf__8CGamePadFv(CGamePad *objet) {
    return (f32) GetRX__8CGamePadFv(objet) / 128.0f;
}
extern "C" s32 GetRY__8CGamePadFv(void *);
extern "C" f32 GetRYf__8CGamePadFv(CGamePad *objet) {
    return (f32) GetRY__8CGamePadFv(objet) / 128.0f;
}
extern "C" s32 GetLX__8CGamePadFv(void *);
extern "C" f32 GetLXf__8CGamePadFv(CGamePad *objet) {
    return (f32) GetLX__8CGamePadFv(objet) / 128.0f;
}
extern "C" s32 GetLY__8CGamePadFv(void *);
extern "C" f32 GetLYf__8CGamePadFv(CGamePad *objet) {
    return (f32) GetLY__8CGamePadFv(objet) / 128.0f;
}
extern "C" s32 GetRX2__8CGamePadFv(void *);
extern "C" f32 GetRXf2__8CGamePadFv(CGamePad *objet) {
    return (f32) GetRX2__8CGamePadFv(objet) / 128.0f;
}
typedef struct CGamePad_infere7 {
    /* 0x000 */ char pad0[4];
    /* 0x004 */ s32 unk4;                           /* inferred */
    /* 0x008 */ char pad8[0x454];                   /* maybe part of unk4[0x116]void */
    /* 0x45C */ s32 unk45C;                         /* inferred */
} CGamePad_infere7;                                         /* size >= 0x460 */
extern "C" s32 On__8CGamePadFi(CGamePad_infere7 *objet, s32 arg0) {
    if (objet->unk45C != 0) {
        return 0;
    }
    return (objet->unk4 & arg0) != 0;
}
struct inferred;
typedef struct CGamePad_infere2 {
    /* 0x000 */ char pad0[0x50];
    /* 0x050 */ s32 unk50;                          /* inferred */
    /* 0x054 */ char pad54[0x408];                  /* maybe part of unk50[0x103]void */
    /* 0x45C */ s32 unk45C;                         /* inferred */
    /* 0x460 */ s32 unk460;                         /* inferred */
} CGamePad_infere2;                                         /* size >= 0x464 */
extern "C" s32 On2__8CGamePadFi(CGamePad_infere2 *objet, s32 arg0) {
    if (objet->unk45C != 0) {
        return 0;
    }
    if (objet->unk460 != 0) {
        return 0;
    }
    return (objet->unk50 & arg0) != 0;
}
typedef struct CGamePad_infere3 {
    /* 0x000 */ char pad0[4];
    /* 0x004 */ s32 unk4;                           /* inferred */
    /* 0x008 */ char pad8[0x94];                    /* maybe part of unk4[0x26]void */
    /* 0x09C */ s32 unk9C;                          /* inferred */
    /* 0x0A0 */ char padA0[0x3BC];                  /* maybe part of unk9C[0xF0]void */
    /* 0x45C */ s32 unk45C;                         /* inferred */
} CGamePad_infere3;                                         /* size >= 0x460 */
extern "C" s32 Down__8CGamePadFi(CGamePad_infere3 *objet, s32 arg0) {
    if (objet->unk45C != 0) {
        return 0;
    }
    return (arg0 & (objet->unk4 & ~objet->unk9C)) != 0;
}
struct inferred;
typedef struct CGamePad_infere {
    /* 0x000 */ char pad0[0x50];
    /* 0x050 */ s32 unk50;                          /* inferred */
    /* 0x054 */ char pad54[0x94];                   /* maybe part of unk50[0x26]void */
    /* 0x0E8 */ s32 unkE8;                          /* inferred */
    /* 0x0EC */ char padEC[0x370];                  /* maybe part of unkE8[0xDD]void */
    /* 0x45C */ s32 unk45C;                         /* inferred */
    /* 0x460 */ s32 unk460;                         /* inferred */
} CGamePad_infere;                                         /* size >= 0x464 */
extern "C" s32 Down2__8CGamePadFi(CGamePad_infere *objet, s32 arg0) {
    if (objet->unk45C != 0) {
        return 0;
    }
    if (objet->unk460 != 0) {
        return 0;
    }
    return (arg0 & (objet->unk50 & ~objet->unkE8)) != 0;
}
typedef struct CGamePad_infere4 {
    /* 0x000 */ char pad0[4];
    /* 0x004 */ s32 unk4;                           /* inferred */
    /* 0x008 */ char pad8[0x94];                    /* maybe part of unk4[0x26]void */
    /* 0x09C */ s32 unk9C;                          /* inferred */
    /* 0x0A0 */ char padA0[0x3BC];                  /* maybe part of unk9C[0xF0]void */
    /* 0x45C */ s32 unk45C;                         /* inferred */
} CGamePad_infere4;                                         /* size >= 0x460 */
extern "C" s32 Up__8CGamePadFi(CGamePad_infere4 *objet, s32 arg0) {
    if (objet->unk45C != 0) {
        return 0;
    }
    return (arg0 & (~objet->unk4 & objet->unk9C)) != 0;
}
INCLUDE_ASM("nonmatchings/game/cgamepad", AutoRepeatOff__8CGamePadFv);
INCLUDE_ASM("nonmatchings/game/cgamepad", MenuModeOn__8CGamePadFi);
INCLUDE_ASM("nonmatchings/game/cgamepad", MenuModeOff__8CGamePadFv);
INCLUDE_ASM("nonmatchings/game/cgamepad", SetVibration__8CGamePadFiii);
INCLUDE_ASM("nonmatchings/game/cgamepad", VibrationEnable__8CGamePadFi);
#include "gamepad.hpp"
extern "C" s32 Step__8CGamePadFi(void *, s32);
extern "C" s32 SetVibration__8CGamePadFiii(void *, s32, s32, s32);
extern "C" void StopVibration__8CGamePadFv(CGamePad *objet) {
    SetVibration__8CGamePadFiii(objet, 0, 0, 0);
    SetVibration__8CGamePadFiii(objet, 1, 0, 0);
    Step__8CGamePadFi(objet, 1);
}
INCLUDE_ASM("nonmatchings/game/cgamepad", CaptureStart__8CGamePadFv);
INCLUDE_ASM("nonmatchings/game/cgamepad", CaptureEnd__8CGamePadFv);
INCLUDE_ASM("nonmatchings/game/cgamepad", CapturePlay__8CGamePadFv);
INCLUDE_ASM("nonmatchings/game/cgamepad", Capture__8CGamePadFP10PAD_STATUS);
INCLUDE_ASM("nonmatchings/game/cgamepad", Play__8CGamePadFP10PAD_STATUS);
INCLUDE_ASM("nonmatchings/game/cgamepad", SaveCapture__8CGamePadFv);
INCLUDE_ASM("nonmatchings/game/cgamepad", LoadCapture__8CGamePadFv);
INCLUDE_ASM("nonmatchings/game/cgamepad", SwitchGamePadThread__Fv);
INCLUDE_ASM("nonmatchings/game/cgamepad", GamePadStep__FPv);
INCLUDE_ASM("nonmatchings/game/cgamepad", CreateGamePadThread__FP8CGamePad);
INCLUDE_ASM("nonmatchings/game/cgamepad", QuatSlerp__FPfPffPf);
INCLUDE_ASM("nonmatchings/game/cgamepad", MotionProc__FP8mgCFramefP8Mot_ListP9mgCCamera);
INCLUDE_ASM("nonmatchings/game/cgamepad", MotionProc__FP8mgCFrameUiUifP8Mot_ListP9mgCCamera);
INCLUDE_ASM("nonmatchings/game/cgamepad", testVUnew__FPA4_fPfPfPfPf);
INCLUDE_ASM("nonmatchings/game/cgamepad", MotionProc2__FP8mgCFrameP14tagMOTION_TYPEP12tagFRAME_INFP8Mot_List);
INCLUDE_ASM("nonmatchings/game/cgamepad", MotionProc3__FP8mgCFrameP14tagMOTION_TYPEP12tagFRAME_INFP8Mot_List);
INCLUDE_ASM("nonmatchings/game/cgamepad", SetMotionTime__FP8mgCFrameP14tagMOTION_TYPEfP9mgCCamera);
INCLUDE_ASM("nonmatchings/game/cgamepad", ChangeMotion__FP8mgCFrameP14tagMOTION_TYPEUiUifP9mgCCamera);
INCLUDE_ASM("nonmatchings/game/cgamepad", DeformMesh__FP8mgCFrameP14tagMOTION_TYPEP12tagFRAME_INFb);
INCLUDE_ASM("nonmatchings/game/cgamepad", SetKeyFrame__FP8Mot_ListP20FRAME_VECTOR_EX_DATAP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/cgamepad", ChangeWeight__FP8Mot_ListP9mgCMemoryPUciP12tagFRAME_INFP12mgCVisualMDTP8mgCFrameP8mgCFrame);
INCLUDE_ASM("nonmatchings/game/cgamepad", CreateAnimeDataEX__FP14tagMOTION_TYPEP9mgCMemoryP16MOTION_FILE_INFO);
INCLUDE_ASM("nonmatchings/game/cgamepad", AnimeDataInit__FP8mgCFrameP14tagMOTION_TYPEP9mgCMemoryPP12tagFRAME_INF);
INCLUDE_ASM("nonmatchings/game/cgamepad", AnimeDataInit__FP8mgCFrameP14tagMOTION_TYPEP9mgCMemoryP12tagFRAME_INF);
INCLUDE_ASM("nonmatchings/game/cgamepad", CheckHit__FP6CCPolyiPfPfPfii);
INCLUDE_ASM("nonmatchings/game/cgamepad", CheckHit__FP13CollisionInfoPfPfPfii);
INCLUDE_ASM("nonmatchings/game/cgamepad", CheckHitVertical__FP6CCPolyiPffPfi);
INCLUDE_ASM("nonmatchings/game/cgamepad", CheckHitVertical__FP13CollisionInfoPffPfi);
INCLUDE_ASM("nonmatchings/game/cgamepad", CheckHits__FP6CCPolyiPfPfiPiPA4_fii);
INCLUDE_ASM("nonmatchings/game/cgamepad", CheckHits__FP13CollisionInfoPfPfiPiPA4_fii);
INCLUDE_ASM("nonmatchings/game/cgamepad", CheckHitsPipeY__FP6CCPolyiPffiPiPA4_fii);
INCLUDE_ASM("nonmatchings/game/cgamepad", CheckHitsPipe__FP6CCPolyiPfPfiPiPA4_fii);
INCLUDE_ASM("nonmatchings/game/cgamepad", CheckHitsSphere__FP6CCPolyiPfiPiPA4_fii);
INCLUDE_ASM("nonmatchings/game/cgamepad", MoveCheck__FPfPfPfP13MoveCheckInfoP6CCPolyii);
INCLUDE_ASM("nonmatchings/game/cgamepad", GetFootPoly__FPffP6CCPolyPfP6CCPolyii);
INCLUDE_ASM("nonmatchings/game/cgamepad", GetCPolyAttr__FP13MoveCheckInfoPfPffP6CCPolyii);
INCLUDE_ASM("nonmatchings/game/cgamepad", CheckWidth__FP6CCPolyiPffPfi);
INCLUDE_ASM("nonmatchings/game/cgamepad", CheckWidthPipe__FP6CCPolyiPffPfi);
INCLUDE_ASM("nonmatchings/game/cgamepad", CreateCharaCPoly__FP6CCPolyiPfPfff);
INCLUDE_ASM("nonmatchings/game/cgamepad", LinerInterpolation__Ffff);
INCLUDE_ASM("nonmatchings/game/cgamepad", LinerInterpolationI__Fiiii);
INCLUDE_ASM("nonmatchings/game/cgamepad", RollPos__FPfPffPf);
struct inferred;
typedef struct RECT {
    /* 0x00 */ s32 unk0;                            /* inferred */
    /* 0x04 */ s32 unk4;                            /* inferred */
    /* 0x08 */ s32 unk8;                            /* inferred */
    /* 0x0C */ s32 unkC;                            /* inferred */
} RECT;                                             /* size >= 0x10 */
extern "C" s32 CheckPosInOutForRect__FP4RECTii(RECT *arg0, s32 arg1, s32 arg2) {
    s32 temp_v1;
    s32 temp_v1_2;

    temp_v1_2 = (s32) (arg0->unk0);
    if (arg1 < temp_v1_2) {
        return 0;
    }
    if ((temp_v1_2 + arg0->unk8) < arg1) {
        return 0;
    }
    temp_v1 = (s32) (arg0->unk4);
    if (arg2 < temp_v1) {
        return 0;
    }
    return (temp_v1 + arg0->unkC) >= arg2;
}
INCLUDE_ASM("nonmatchings/game/cgamepad", GetDisPosToRect__FP4RECTii);
