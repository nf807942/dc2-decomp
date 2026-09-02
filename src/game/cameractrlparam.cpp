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
INCLUDE_ASM("nonmatchings/game/cameractrlparam", GetUserData__Fv_001AAEF0);
void InitLockCharaCtrl(void) {
    LockChara = 0;
}
INCLUDE_ASM("nonmatchings/game/cameractrlparam", LockCharaCtrl__Fv);
INCLUDE_ASM("nonmatchings/game/cameractrlparam", UnLockCharaCtrl__Fv);
INCLUDE_ASM("nonmatchings/game/cameractrlparam", IsEditMode__Fv);
void InitEditModeChg(void) {
    EditModeChgFlag = 0;
    EditModeChgCnt = 0;
    EditModeChgEvent = 0;
}
INCLUDE_ASM("nonmatchings/game/cameractrlparam", NowEditModeChg__Fv);
INCLUDE_ASM("nonmatchings/game/cameractrlparam", EditModeChg__Fi);
INCLUDE_ASM("nonmatchings/game/cameractrlparam", EditModeChgStep__FP6CScene);
INCLUDE_ASM("nonmatchings/game/cameractrlparam", SetDataPacket__Fi);
INCLUDE_ASM("nonmatchings/game/cameractrlparam", PreExitLoop__FP6CScene);
INCLUDE_ASM("nonmatchings/game/cameractrlparam", EditInit__F13INIT_LOOP_ARG);
INCLUDE_ASM("nonmatchings/game/cameractrlparam", __as__15CameraCtrlParamFRC15CameraCtrlParam);
