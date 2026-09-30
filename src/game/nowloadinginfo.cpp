/* NowLoadingInfo
 *
 * Unité découpée par `make carve` : 28 fonctions, 19612 octets, de
 * 0x0030AC00 à 0x0030F950. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

/* Les globales que ces accesseurs servent. Leur taille déclarée est celle que
 * le découpage leur donne, et c'est elle qui décide du `%gp_rel`. */
extern s32 PauseFlag_0037E850;
extern s32 cancel_now_loading;
struct SubGameInfo;


INCLUDE_ASM("nonmatchings/game/nowloadinginfo", sgLoopGyoRace__FP11SubGameInfo);
INCLUDE_ASM("nonmatchings/game/nowloadinginfo", AutoCam__FP11SubGameInfo);
s32 sgMapDrawGyoRace(SubGameInfo * arg0) {
    return 0;
}
INCLUDE_ASM("nonmatchings/game/nowloadinginfo", sgCharaDrawGyoRace__FP11SubGameInfo);
INCLUDE_ASM("nonmatchings/game/nowloadinginfo", DivSpriteScreen__FR11mgCDrawPrim_0030C940);
INCLUDE_ASM("nonmatchings/game/nowloadinginfo", sgEffectDrawGyoRace__FP11SubGameInfo);
INCLUDE_ASM("nonmatchings/game/nowloadinginfo", sgSysDrawGyoRace__FP11SubGameInfo);
INCLUDE_ASM("nonmatchings/game/nowloadinginfo", Jikkyou__FP11SubGameInfo);
extern "C" void RotateThreadReadyQueue(int);
extern "C" void SwitchNowLoadingThread__Fv(void) { RotateThreadReadyQueue(10); }
INCLUDE_ASM("nonmatchings/game/nowloadinginfo", NowLoadingLoop__FPv);
void CancelNowLoading(void) {
    cancel_now_loading = 1;
}
INCLUDE_ASM("nonmatchings/game/nowloadinginfo", CreateNowLoading__FP14NowLoadingInfo);
INCLUDE_ASM("nonmatchings/game/nowloadinginfo", NowLoadingBarStep__Fv);
struct LoadInfo_t {
    s32 pad0[14];
    u32 f38;
    s32 pad3C;
};
extern "C" LoadInfo_t LoadInfo;
extern "C" u32 ProgBarWidthStep;
extern "C" u32 ProgBarCnt;
extern "C" void NowLoadingBarSteEnd__Fv(void) {

    ProgBarCnt = LoadInfo.f38;
    ProgBarWidthStep = 0x3D4CCCCD;
}
INCLUDE_ASM("nonmatchings/game/nowloadinginfo", DeleteNowLoading__Fv);
INCLUDE_ASM("nonmatchings/game/nowloadinginfo", __ct__14NowLoadingInfoFv);
INCLUDE_ASM("nonmatchings/game/nowloadinginfo", InitPauseData__Fv);
INCLUDE_ASM("nonmatchings/game/nowloadinginfo", InitPause__Fi);
extern "C" s32 PauseEnableFlag;
extern "C" s32 PauseEnable__Fi(s32 arg0) { s32 old = PauseEnableFlag; PauseEnableFlag = arg0; return old; }
s32 GetPauseFlag(void) {
    return PauseFlag_0037E850;
}
INCLUDE_ASM("nonmatchings/game/nowloadinginfo", PauseStart__FP10PAUSE_INFO);
void PauseCancel(void) {
    PauseFlag_0037E850 = 0;
}
INCLUDE_ASM("nonmatchings/game/nowloadinginfo", PauseEnd__Fv);
INCLUDE_ASM("nonmatchings/game/nowloadinginfo", PauseLoop__Fv);
INCLUDE_ASM("nonmatchings/game/nowloadinginfo", PauseCount__Fv);
INCLUDE_ASM("nonmatchings/game/nowloadinginfo", SCElogoFade__FiP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/nowloadinginfo", SetEventKeyword__FPcPci);
INCLUDE_ASM("nonmatchings/game/nowloadinginfo", CheckDeleteNameRegisteItem__FP13CGameDataUsed);
