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
INCLUDE_ASM("nonmatchings/game/cgamepad", GetPadOn__8CGamePadFv);
INCLUDE_ASM("nonmatchings/game/cgamepad", GetPadDown__8CGamePadFv);
INCLUDE_ASM("nonmatchings/game/cgamepad", GetPadUp__8CGamePadFv);
INCLUDE_ASM("nonmatchings/game/cgamepad", GetRXf__8CGamePadFv);
INCLUDE_ASM("nonmatchings/game/cgamepad", GetRYf__8CGamePadFv);
INCLUDE_ASM("nonmatchings/game/cgamepad", GetLXf__8CGamePadFv);
INCLUDE_ASM("nonmatchings/game/cgamepad", GetLYf__8CGamePadFv);
INCLUDE_ASM("nonmatchings/game/cgamepad", GetRXf2__8CGamePadFv);
INCLUDE_ASM("nonmatchings/game/cgamepad", On__8CGamePadFi);
INCLUDE_ASM("nonmatchings/game/cgamepad", On2__8CGamePadFi);
INCLUDE_ASM("nonmatchings/game/cgamepad", Down__8CGamePadFi);
INCLUDE_ASM("nonmatchings/game/cgamepad", Down2__8CGamePadFi);
INCLUDE_ASM("nonmatchings/game/cgamepad", Up__8CGamePadFi);
INCLUDE_ASM("nonmatchings/game/cgamepad", AutoRepeatOff__8CGamePadFv);
INCLUDE_ASM("nonmatchings/game/cgamepad", MenuModeOn__8CGamePadFi);
INCLUDE_ASM("nonmatchings/game/cgamepad", MenuModeOff__8CGamePadFv);
INCLUDE_ASM("nonmatchings/game/cgamepad", SetVibration__8CGamePadFiii);
INCLUDE_ASM("nonmatchings/game/cgamepad", VibrationEnable__8CGamePadFi);
INCLUDE_ASM("nonmatchings/game/cgamepad", StopVibration__8CGamePadFv);
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
INCLUDE_ASM("nonmatchings/game/cgamepad", CheckPosInOutForRect__FP4RECTii);
INCLUDE_ASM("nonmatchings/game/cgamepad", GetDisPosToRect__FP4RECTii);
