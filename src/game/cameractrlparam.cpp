/* CameraCtrlParam
 *
 * Unité découpée par `make carve` : 16 fonctions, 13996 octets, de
 * 0x001A9820 à 0x001ACF40. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

/* Les globales que ces accesseurs servent. Leur taille déclarée est celle que
 * le découpage leur donne, et c'est elle qui décide du `%gp_rel`. */
extern s32 LockChara;
extern s32 EditModeChgCnt;
extern s32 EditModeChgEvent;
extern s32 EditModeChgFlag;


INCLUDE_ASM("nonmatchings/game/cameractrlparam", LightingEdit__FP6CScene);
INCLUDE_ASM("nonmatchings/game/cameractrlparam", tagGyoFish__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cameractrlparam", LoadGyorace__Fv);
extern "C" s32 GetSaveData__Fv(void);
extern "C" s32 GetUserData__Fv_001AAEF0(void) {
    s32 temp_v0;

    temp_v0 = GetSaveData__Fv();
    if (temp_v0 != 0) {
        return (s32) ((u8 *) temp_v0 + 0x1D2A0);
    }
    return 0;
}
void InitLockCharaCtrl(void) {
    LockChara = 0;
}
extern "C" void LockCharaCtrl__Fv(void) {
    LockChara++;
}
extern "C" void UnLockCharaCtrl__Fv(void) {
    LockChara -= 1;
    if (LockChara < 0) {
        LockChara = 0;
    }
}
INCLUDE_ASM("nonmatchings/game/cameractrlparam", IsEditMode__Fv);
void InitEditModeChg(void) {
    EditModeChgFlag = 0;
    EditModeChgCnt = 0;
    EditModeChgEvent = 0;
}
struct EditModeChgFlag;
struct EditModeChgCnt;
extern "C" s32 NowEditModeChg__Fv(void) {
    if (EditModeChgFlag != 0) {
        return EditModeChgCnt > 0;
    }
    return 0;
}
INCLUDE_ASM("nonmatchings/game/cameractrlparam", EditModeChg__Fi);
INCLUDE_ASM("nonmatchings/game/cameractrlparam", EditModeChgStep__FP6CScene);
INCLUDE_ASM("nonmatchings/game/cameractrlparam", SetDataPacket__Fi);
#include "sphida.hpp"
extern "C" s32 BreakReadBG__Fv(void);
extern "C" s32 BurnEditParts__Fv(void);
extern "C" s32 EdEventTermination__Fv(void);
extern "C" s32 EditDataSave__Fv(void);
extern "C" s32 InitBGM__6CSceneFv(void *);
extern "C" s32 ResetNpcTalkMes__Fv(void);
extern "C" s32 SeAllStop__6CSceneFv(void *);
extern "C" s32 StopBGM__6CSceneFi(void *, s32);
extern "C" s32 sgBreakSubGame__Fv(void);
extern "C" s32 sndStopVoice__Fi(s32);
extern "C" void PreExitLoop__FP6CScene(CScene *arg0) {
    BurnEditParts__Fv();
    EditDataSave__Fv();
    sgBreakSubGame__Fv();
    StopBGM__6CSceneFi(arg0, 0);
    InitBGM__6CSceneFv(arg0);
    SeAllStop__6CSceneFv(arg0);
    BreakReadBG__Fv();
    sndStopVoice__Fi(1);
    ResetNpcTalkMes__Fv();
    EdEventTermination__Fv();
}
INCLUDE_ASM("nonmatchings/game/cameractrlparam", EditInit__F13INIT_LOOP_ARG);
struct inferred;
typedef struct CameraCtrlParam {
    /* 0x00 */ f32 unk0;                            /* inferred */
    /* 0x04 */ f32 unk4;                            /* inferred */
    /* 0x08 */ f32 unk8;                            /* inferred */
    /* 0x0C */ f32 unkC;                            /* inferred */
    /* 0x10 */ f32 unk10;                           /* inferred */
    /* 0x14 */ f32 unk14;                           /* inferred */
    /* 0x18 */ f32 unk18;                           /* inferred */
    /* 0x1C */ f32 unk1C;                           /* inferred */
    /* 0x20 */ f32 unk20;                           /* inferred */
    /* 0x24 */ f32 unk24;                           /* inferred */
    /* 0x28 */ s32 unk28;                           /* inferred */
} CameraCtrlParam;                                  /* size >= 0x2C */
extern "C" CameraCtrlParam *__as__15CameraCtrlParamFRC15CameraCtrlParam(CameraCtrlParam *objet, CameraCtrlParam *arg0) {
    objet->unk0 = arg0->unk0;
    objet->unk4 = arg0->unk4;
    objet->unk8 = arg0->unk8;
    objet->unkC = arg0->unkC;
    objet->unk10 = arg0->unk10;
    objet->unk14 = arg0->unk14;
    objet->unk18 = arg0->unk18;
    objet->unk1C = arg0->unk1C;
    objet->unk20 = arg0->unk20;
    objet->unk24 = arg0->unk24;
    objet->unk28 = arg0->unk28;
    return objet;
}
