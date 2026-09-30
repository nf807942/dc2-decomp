/* CGamePad
 *
 * Unité découpée par `make carve` : 69 fonctions, 24592 octets, de
 * 0x0014B500 à 0x00151690. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

typedef struct PAD_REPEAT_local {
    s32 down;
    s32 repeat;
    s32 wait[32];
    s32 period[32];
    s32 count[32];
} PAD_REPEAT_local;
typedef struct CGamePad_repeat_local {
    char pad0[0x144];
    PAD_REPEAT_local repeat[2];
} CGamePad_repeat_local;
extern "C" void CancelAutoRepeat2__8CGamePadFi(void *thisPtr, s32 mask) {
    int i;
    int bit;
    PAD_REPEAT_local *rep = &((CGamePad_repeat_local *)thisPtr)->repeat[1];

    bit = 1;
    for (i = 0; i < 32; i++, bit *= 2) {
        if (mask & bit) {
            rep->down &= ~bit;
            rep->repeat &= ~bit;
            rep->wait[i] = 0;
            rep->period[i] = 0;
            rep->count[i] = 0;
        }
    }
}
extern "C" void SetAutoRepeat__8CGamePadFiii(void *thisPtr, s32 mask, s32 wait, s32 period) {
    int i;
    int bit;
    PAD_REPEAT_local *rep;

    bit = 1;
    if (period < 2) {
        period = 2;
    }
    if (wait < 2) {
        wait = 2;
    }
    rep = &((CGamePad_repeat_local *)thisPtr)->repeat[0];
    for (i = 0; i < 32; i++, bit *= 2) {
        if (mask & bit) {
            rep->down |= bit;
            rep->repeat &= ~bit;
            rep->wait[i] = 0;
            rep->period[i] = wait;
            rep->count[i] = period;
        }
    }
}
extern "C" void SetAutoRepeat2__8CGamePadFiii(void *thisPtr, s32 mask, s32 wait, s32 period) {
    int i;
    int bit;
    PAD_REPEAT_local *rep;

    bit = 1;
    if (period < 2) {
        period = 2;
    }
    if (wait < 2) {
        wait = 2;
    }
    rep = &((CGamePad_repeat_local *)thisPtr)->repeat[1];
    for (i = 0; i < 32; i++, bit *= 2) {
        if ((rep->down & bit) == 0 && (mask & bit)) {
            rep->down |= bit;
            rep->repeat &= ~bit;
            rep->wait[i] = 0;
            rep->period[i] = wait;
            rep->count[i] = period;
        }
    }
}
typedef struct CGamePad_keylock {
    char pad0[0x45C];
    s32 value;
} CGamePad_keylock;
extern "C" void KeyLock__8CGamePadFi(CGamePad_keylock *objet, s32 arg0) {
    objet->value = arg0;
}
typedef struct CGamePad_keylock2 {
    char pad0[0x460];
    s32 value;
    s32 debugValue;
} CGamePad_keylock2;
extern "C" void KeyLock2__8CGamePadFi(CGamePad_keylock2 *objet, s32 arg0) {
    objet->value = arg0;
}
extern "C" void DebugKeyLock__8CGamePadFi(CGamePad_keylock2 *objet, s32 arg0) {
    objet->debugValue = arg0;
    KeyLock2__8CGamePadFi(objet, arg0);
}
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
extern "C" void CancelAutoRepeat__8CGamePadFi(void *, s32);
extern "C" void AutoRepeatOff__8CGamePadFv(void *objet) {
    CancelAutoRepeat__8CGamePadFi(objet, -1);
}
typedef struct CGamePad_menu_mode {
    char pad0[0x454];
    s32 value;
} CGamePad_menu_mode;
extern "C" void MenuModeOn__8CGamePadFi(CGamePad_menu_mode *objet, s32 arg0) {
    objet->value = arg0;
}
extern "C" void MenuModeOff__8CGamePadFv(CGamePad_menu_mode *objet) {
    objet->value = 0;
}
INCLUDE_ASM("nonmatchings/game/cgamepad", SetVibration__8CGamePadFiii);
typedef struct CGamePad_vibration_enable {
    char pad0[0x468];
    s32 value;
} CGamePad_vibration_enable;
extern "C" void VibrationEnable__8CGamePadFi(CGamePad_vibration_enable *objet, s32 arg0) {
    objet->value = arg0;
}
#include "gamepad.hpp"
extern "C" s32 Step__8CGamePadFi(void *, s32);
extern "C" s32 SetVibration__8CGamePadFiii(void *, s32, s32, s32);
extern "C" void StopVibration__8CGamePadFv(CGamePad *objet) {
    SetVibration__8CGamePadFiii(objet, 0, 0, 0);
    SetVibration__8CGamePadFiii(objet, 1, 0, 0);
    Step__8CGamePadFi(objet, 1);
}
typedef struct CGamePad_capture {
    char pad0[0x470];
    s32 mode;
    s32 frame;
} CGamePad_capture;
extern "C" void CaptureStart__8CGamePadFv(CGamePad_capture *objet) {
    objet->mode = 1;
    objet->frame = 0;
}
extern "C" void CaptureEnd__8CGamePadFv(CGamePad_capture *objet) {
    objet->mode = 0;
    objet->frame = 0;
}
extern "C" void CapturePlay__8CGamePadFv(CGamePad_capture *objet) {
    objet->mode = 2;
}
INCLUDE_ASM("nonmatchings/game/cgamepad", Capture__8CGamePadFP10PAD_STATUS);
INCLUDE_ASM("nonmatchings/game/cgamepad", Play__8CGamePadFP10PAD_STATUS);
typedef struct CGamePad_save_capture {
    char pad0[0x474];
    s32 frameCount;
} CGamePad_save_capture;
extern "C" s32 WriteFile__FPcPvi(s8 *, void *, s32);
extern s8 _904_00367090[];
extern "C" s32 SaveCapture__8CGamePadFv(CGamePad_save_capture *objet) {
    return WriteFile__FPcPvi(_904_00367090, (void *)0x03000000, objet->frameCount * 6);
}
extern "C" s32 SetCurrentDir__FPc(s8 *);
extern "C" s32 LoadFile2__FPcPvPii(s8 *, void *, s32 *, s32);
extern s8 _909_003670A8[];
extern s8 _910_003670B0[];
extern "C" void LoadCapture__8CGamePadFv(void *) {
    SetCurrentDir__FPc(_909_003670A8);
    LoadFile2__FPcPvPii(_910_003670B0, (void *)0x03000000, NULL, 0);
    SetCurrentDir__FPc(NULL);
}
extern "C" void RotateThreadReadyQueue(s32);
extern "C" void SwitchGamePadThread__Fv(void) {
    RotateThreadReadyQueue(10);
}
extern "C" s32 mgGetVSyncCount__Fv(void);
extern "C" CGamePad *GamePad_0037CF44;
extern "C" s32 old_vsync_0037CF48;
extern "C" void GamePadStep__FPv(void *) {
    for (;;) {
        s32 current = mgGetVSyncCount__Fv();
        s32 elapsed = current - old_vsync_0037CF48;
        if (elapsed < 0) {
            elapsed = 1;
        }
        if (elapsed > 0 && GamePad_0037CF44 != NULL) {
            Step__8CGamePadFi(GamePad_0037CF44, elapsed);
        }
        SwitchGamePadThread__Fv();
        old_vsync_0037CF48 = current;
    }
}
typedef struct GamePad_thread_param {
    s32 unknown0;
    void (*entry)(void *);
    void *stack;
    s32 stackSize;
    void *gp;
    s32 priority;
    char pad18[8];
    s32 option;
} GamePad_thread_param;
extern "C" s32 CreateThread(GamePad_thread_param *);
extern "C" s32 StartThread(s32, void *);
extern "C" s32 TheadID_0037CF40;
extern u8 ThreadStack_003ECBC0[];
extern s8 D_003846F0;
extern "C" void CreateGamePadThread__FP8CGamePad(CGamePad *pad) {
    GamePad_thread_param param;

    param.entry = GamePadStep__FPv;
    param.stack = ThreadStack_003ECBC0;
    param.stackSize = 0x400;
    param.priority = 10;
    param.gp = &D_003846F0;
    param.option = 0;
    TheadID_0037CF40 = CreateThread(&param);
    GamePad_0037CF44 = pad;
    StartThread(TheadID_0037CF40, NULL);
}
INCLUDE_ASM("nonmatchings/game/cgamepad", QuatSlerp__FPfPffPf);
INCLUDE_ASM("nonmatchings/game/cgamepad", MotionProc__FP8mgCFramefP8Mot_ListP9mgCCamera);
INCLUDE_ASM("nonmatchings/game/cgamepad", MotionProc__FP8mgCFrameUiUifP8Mot_ListP9mgCCamera);
INCLUDE_ASM("nonmatchings/game/cgamepad", testVUnew__FPA4_fPfPfPfPf);
INCLUDE_ASM("nonmatchings/game/cgamepad", MotionProc2__FP8mgCFrameP14tagMOTION_TYPEP12tagFRAME_INFP8Mot_List);
INCLUDE_ASM("nonmatchings/game/cgamepad", MotionProc3__FP8mgCFrameP14tagMOTION_TYPEP12tagFRAME_INFP8Mot_List);
INCLUDE_ASM("nonmatchings/game/cgamepad", SetMotionTime__FP8mgCFrameP14tagMOTION_TYPEfP9mgCCamera);
typedef struct tagMOTION_TYPE_change_motion {
    char pad0[4];
    void *list;
} tagMOTION_TYPE_change_motion;
extern "C" void *MotionProc__FP8mgCFrameUiUifP8Mot_ListP9mgCCamera(void *, u32, u32, f32, void *, void *);
extern "C" void ChangeMotion__FP8mgCFrameP14tagMOTION_TYPEUiUifP9mgCCamera(void *frame, tagMOTION_TYPE_change_motion *motion, u32 arg2, u32 arg3, f32 weight, void *camera) {
    void *list = motion->list;

    if (list != NULL) {
        do {
            list = MotionProc__FP8mgCFrameUiUifP8Mot_ListP9mgCCamera(frame, arg2, arg3, weight, list, camera);
        } while (list != NULL);
    }
}
typedef struct tagMOTION_TYPE_deform_mesh {
    char pad0[8];
    void *list;
} tagMOTION_TYPE_deform_mesh;
extern "C" void *MotionProc2__FP8mgCFrameP14tagMOTION_TYPEP12tagFRAME_INFP8Mot_List(void *, tagMOTION_TYPE_deform_mesh *, void *, void *);
extern "C" void *MotionProc3__FP8mgCFrameP14tagMOTION_TYPEP12tagFRAME_INFP8Mot_List(void *, tagMOTION_TYPE_deform_mesh *, void *, void *);
extern s32 OldSkinFrame;
extern "C" void DeformMesh__FP8mgCFrameP14tagMOTION_TYPEP12tagFRAME_INFb(void *frame, tagMOTION_TYPE_deform_mesh *motion, void *frameInfo, s32 deform) {
    void *list = motion->list;

    if (deform != 0) {
        if (list != NULL) {
            do {
                list = MotionProc3__FP8mgCFrameP14tagMOTION_TYPEP12tagFRAME_INFP8Mot_List(frame, motion, frameInfo, list);
            } while (list != NULL);
        }
    } else if (list != NULL) {
        do {
            list = MotionProc2__FP8mgCFrameP14tagMOTION_TYPEP12tagFRAME_INFP8Mot_List(frame, motion, frameInfo, list);
        } while (list != NULL);
    }
    OldSkinFrame = 0;
}
INCLUDE_ASM("nonmatchings/game/cgamepad", SetKeyFrame__FP8Mot_ListP20FRAME_VECTOR_EX_DATAP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/cgamepad", ChangeWeight__FP8Mot_ListP9mgCMemoryPUciP12tagFRAME_INFP12mgCVisualMDTP8mgCFrameP8mgCFrame);
INCLUDE_ASM("nonmatchings/game/cgamepad", CreateAnimeDataEX__FP14tagMOTION_TYPEP9mgCMemoryP16MOTION_FILE_INFO);
extern "C" s32 GetFrameNum__8mgCFrameFv(void *);
extern "C" void *stAlloc64__9mgCMemoryFi(void *, s32);
extern "C" void AnimeDataInit__FP8mgCFrameP14tagMOTION_TYPEP9mgCMemoryP12tagFRAME_INF(void *, void *, void *, void *);
extern "C" void AnimeDataInit__FP8mgCFrameP14tagMOTION_TYPEP9mgCMemoryPP12tagFRAME_INF(void *frame, void *motion, void *memory, void **output) {
    *output = stAlloc64__9mgCMemoryFi(memory, ((((u32)(GetFrameNum__8mgCFrameFv(frame) + 0xA)) << 5) >> 4) + 1);
    AnimeDataInit__FP8mgCFrameP14tagMOTION_TYPEP9mgCMemoryP12tagFRAME_INF(frame, motion, memory, *output);
}
INCLUDE_ASM("nonmatchings/game/cgamepad", AnimeDataInit__FP8mgCFrameP14tagMOTION_TYPEP9mgCMemoryP12tagFRAME_INF);
typedef struct CollisionInfo_vertical_wrap {
    s32 unk0;
    void *poly;
    s32 unk8;
    s32 unkC;
} CollisionInfo_vertical_wrap;
extern "C" void CheckHit__FP13CollisionInfoPfPfPfii(void *, f32 *, f32 *, f32 *, s32, s32);
extern "C" void CheckHit__FP6CCPolyiPfPfPfii(void *poly, s32 flags, f32 *arg2, f32 *arg3, f32 *arg4, s32 arg5, s32 arg6) {
    CollisionInfo_vertical_wrap info;

    info.unk0 = flags;
    info.poly = poly;
    info.unk8 = 0;
    info.unkC = 0;
    CheckHit__FP13CollisionInfoPfPfPfii(&info, arg2, arg3, arg4, arg5, arg6);
}
INCLUDE_ASM("nonmatchings/game/cgamepad", CheckHit__FP13CollisionInfoPfPfPfii);
extern "C" void CheckHitVertical__FP13CollisionInfoPffPfi(void *, f32 *, f32, f32 *, s32);
extern "C" void CheckHitVertical__FP6CCPolyiPffPfi(void *poly, s32 flags, f32 *arg2, f32 arg3, f32 *arg4, s32 arg5) {
    CollisionInfo_vertical_wrap info;

    info.unk0 = flags;
    info.poly = poly;
    info.unk8 = 0;
    info.unkC = 0;
    CheckHitVertical__FP13CollisionInfoPffPfi(&info, arg2, arg3, arg4, arg5);
}
INCLUDE_ASM("nonmatchings/game/cgamepad", CheckHitVertical__FP13CollisionInfoPffPfi);
extern "C" void CheckHits__FP13CollisionInfoPfPfiPiPA4_fii(void *, f32 *, f32 *, s32, s32 *, f32 (*)[4], s32, s32);
extern "C" void CheckHits__FP6CCPolyiPfPfiPiPA4_fii(void *poly, s32 flags, f32 *arg2, f32 *arg3, s32 arg4, s32 *arg5, f32 (*arg6)[4], s32 arg7, s32 arg8) {
    CollisionInfo_vertical_wrap info;

    info.unk0 = flags;
    info.poly = poly;
    info.unk8 = 0;
    info.unkC = 0;
    CheckHits__FP13CollisionInfoPfPfiPiPA4_fii(&info, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
}
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
extern "C" f32 LinerInterpolation__Ffff(f32 arg0, f32 arg1, f32 arg2) {
    return arg0 + (arg2 * (arg1 - arg0));
}
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
