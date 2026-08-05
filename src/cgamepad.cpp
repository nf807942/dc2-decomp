/* CGamePad
 *
 * Unité découpée par `make carve` : 69 fonctions, 24592 octets, de
 * 0x0014B500 à 0x00151690. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

INCLUDE_ASM("nonmatchings/cgamepad", CancelAutoRepeat2__8CGamePadFi);
INCLUDE_ASM("nonmatchings/cgamepad", SetAutoRepeat__8CGamePadFiii);
INCLUDE_ASM("nonmatchings/cgamepad", SetAutoRepeat2__8CGamePadFiii);
INCLUDE_ASM("nonmatchings/cgamepad", KeyLock__8CGamePadFi);
INCLUDE_ASM("nonmatchings/cgamepad", KeyLock2__8CGamePadFi);
INCLUDE_ASM("nonmatchings/cgamepad", DebugKeyLock__8CGamePadFi);
INCLUDE_ASM("nonmatchings/cgamepad", GetPadOn__8CGamePadFv);
INCLUDE_ASM("nonmatchings/cgamepad", GetPadDown__8CGamePadFv);
INCLUDE_ASM("nonmatchings/cgamepad", GetPadUp__8CGamePadFv);
INCLUDE_ASM("nonmatchings/cgamepad", GetRXf__8CGamePadFv);
INCLUDE_ASM("nonmatchings/cgamepad", GetRYf__8CGamePadFv);
INCLUDE_ASM("nonmatchings/cgamepad", GetLXf__8CGamePadFv);
INCLUDE_ASM("nonmatchings/cgamepad", GetLYf__8CGamePadFv);
INCLUDE_ASM("nonmatchings/cgamepad", GetRXf2__8CGamePadFv);
INCLUDE_ASM("nonmatchings/cgamepad", On__8CGamePadFi);
INCLUDE_ASM("nonmatchings/cgamepad", On2__8CGamePadFi);
INCLUDE_ASM("nonmatchings/cgamepad", Down__8CGamePadFi);
INCLUDE_ASM("nonmatchings/cgamepad", Down2__8CGamePadFi);
INCLUDE_ASM("nonmatchings/cgamepad", Up__8CGamePadFi);
INCLUDE_ASM("nonmatchings/cgamepad", AutoRepeatOff__8CGamePadFv);
INCLUDE_ASM("nonmatchings/cgamepad", MenuModeOn__8CGamePadFi);
INCLUDE_ASM("nonmatchings/cgamepad", MenuModeOff__8CGamePadFv);
INCLUDE_ASM("nonmatchings/cgamepad", SetVibration__8CGamePadFiii);
INCLUDE_ASM("nonmatchings/cgamepad", VibrationEnable__8CGamePadFi);
INCLUDE_ASM("nonmatchings/cgamepad", StopVibration__8CGamePadFv);
INCLUDE_ASM("nonmatchings/cgamepad", CaptureStart__8CGamePadFv);
INCLUDE_ASM("nonmatchings/cgamepad", CaptureEnd__8CGamePadFv);
INCLUDE_ASM("nonmatchings/cgamepad", CapturePlay__8CGamePadFv);
INCLUDE_ASM("nonmatchings/cgamepad", Capture__8CGamePadFP10PAD_STATUS);
INCLUDE_ASM("nonmatchings/cgamepad", Play__8CGamePadFP10PAD_STATUS);
INCLUDE_ASM("nonmatchings/cgamepad", SaveCapture__8CGamePadFv);
INCLUDE_ASM("nonmatchings/cgamepad", LoadCapture__8CGamePadFv);
INCLUDE_ASM("nonmatchings/cgamepad", SwitchGamePadThread__Fv);
INCLUDE_ASM("nonmatchings/cgamepad", GamePadStep__FPv);
INCLUDE_ASM("nonmatchings/cgamepad", CreateGamePadThread__FP8CGamePad);
INCLUDE_ASM("nonmatchings/cgamepad", QuatSlerp__FPfPffPf);
INCLUDE_ASM("nonmatchings/cgamepad", MotionProc__FP8mgCFramefP8Mot_ListP9mgCCamera);
INCLUDE_ASM("nonmatchings/cgamepad", MotionProc__FP8mgCFrameUiUifP8Mot_ListP9mgCCamera);
INCLUDE_ASM("nonmatchings/cgamepad", testVUnew__FPA4_fPfPfPfPf);
INCLUDE_ASM("nonmatchings/cgamepad", MotionProc2__FP8mgCFrameP14tagMOTION_TYPEP12tagFRAME_INFP8Mot_List);
INCLUDE_ASM("nonmatchings/cgamepad", MotionProc3__FP8mgCFrameP14tagMOTION_TYPEP12tagFRAME_INFP8Mot_List);
INCLUDE_ASM("nonmatchings/cgamepad", SetMotionTime__FP8mgCFrameP14tagMOTION_TYPEfP9mgCCamera);
INCLUDE_ASM("nonmatchings/cgamepad", ChangeMotion__FP8mgCFrameP14tagMOTION_TYPEUiUifP9mgCCamera);
INCLUDE_ASM("nonmatchings/cgamepad", DeformMesh__FP8mgCFrameP14tagMOTION_TYPEP12tagFRAME_INFb);
INCLUDE_ASM("nonmatchings/cgamepad", SetKeyFrame__FP8Mot_ListP20FRAME_VECTOR_EX_DATAP9mgCMemory);
INCLUDE_ASM("nonmatchings/cgamepad", ChangeWeight__FP8Mot_ListP9mgCMemoryPUciP12tagFRAME_INFP12mgCVisualMDTP8mgCFrameP8mgCFrame);
INCLUDE_ASM("nonmatchings/cgamepad", CreateAnimeDataEX__FP14tagMOTION_TYPEP9mgCMemoryP16MOTION_FILE_INFO);
INCLUDE_ASM("nonmatchings/cgamepad", AnimeDataInit__FP8mgCFrameP14tagMOTION_TYPEP9mgCMemoryPP12tagFRAME_INF);
INCLUDE_ASM("nonmatchings/cgamepad", AnimeDataInit__FP8mgCFrameP14tagMOTION_TYPEP9mgCMemoryP12tagFRAME_INF);
INCLUDE_ASM("nonmatchings/cgamepad", CheckHit__FP6CCPolyiPfPfPfii);
INCLUDE_ASM("nonmatchings/cgamepad", CheckHit__FP13CollisionInfoPfPfPfii);
INCLUDE_ASM("nonmatchings/cgamepad", CheckHitVertical__FP6CCPolyiPffPfi);
INCLUDE_ASM("nonmatchings/cgamepad", CheckHitVertical__FP13CollisionInfoPffPfi);
INCLUDE_ASM("nonmatchings/cgamepad", CheckHits__FP6CCPolyiPfPfiPiPA4_fii);
INCLUDE_ASM("nonmatchings/cgamepad", CheckHits__FP13CollisionInfoPfPfiPiPA4_fii);
INCLUDE_ASM("nonmatchings/cgamepad", CheckHitsPipeY__FP6CCPolyiPffiPiPA4_fii);
INCLUDE_ASM("nonmatchings/cgamepad", CheckHitsPipe__FP6CCPolyiPfPfiPiPA4_fii);
INCLUDE_ASM("nonmatchings/cgamepad", CheckHitsSphere__FP6CCPolyiPfiPiPA4_fii);
INCLUDE_ASM("nonmatchings/cgamepad", MoveCheck__FPfPfPfP13MoveCheckInfoP6CCPolyii);
INCLUDE_ASM("nonmatchings/cgamepad", GetFootPoly__FPffP6CCPolyPfP6CCPolyii);
INCLUDE_ASM("nonmatchings/cgamepad", GetCPolyAttr__FP13MoveCheckInfoPfPffP6CCPolyii);
INCLUDE_ASM("nonmatchings/cgamepad", CheckWidth__FP6CCPolyiPffPfi);
INCLUDE_ASM("nonmatchings/cgamepad", CheckWidthPipe__FP6CCPolyiPffPfi);
INCLUDE_ASM("nonmatchings/cgamepad", CreateCharaCPoly__FP6CCPolyiPfPfff);
INCLUDE_ASM("nonmatchings/cgamepad", LinerInterpolation__Ffff);
INCLUDE_ASM("nonmatchings/cgamepad", LinerInterpolationI__Fiiii);
INCLUDE_ASM("nonmatchings/cgamepad", RollPos__FPfPffPf);
INCLUDE_ASM("nonmatchings/cgamepad", CheckPosInOutForRect__FP4RECTii);
INCLUDE_ASM("nonmatchings/cgamepad", GetDisPosToRect__FP4RECTii);
