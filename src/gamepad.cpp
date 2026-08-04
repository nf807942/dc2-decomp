/* CGamePad — la manette, telle que le jeu la voit.
 *
 * Première unité reconstruite. Les fonctions encore intactes gardent les
 * instructions du disque, que mwccgap greffe dans cet objet ; elles sont
 * données dans l'ordre des adresses, celui que l'éditeur de liens attend.
 */

#include "common.h"
#include "gamepad.hpp"

INCLUDE_ASM("nonmatchings/gamepad", Init__8CGamePadFv);

void CGamePad::Close() {
    scePadPortClose(0, 0);
    scePadPortClose(1, 0);
    scePadEnd();
}

INCLUDE_ASM("nonmatchings/gamepad", pad_button_read__FP10PAD_STATUSii);
INCLUDE_ASM("nonmatchings/gamepad", read_pad__FP10PAD_STATUSii);
INCLUDE_ASM("nonmatchings/gamepad", WaitEnable__8CGamePadFv);
/* La manette répond-elle ? Deux états du port valent oui : la liaison
 * établie, et le port qui vient de reconnaître un contrôleur. */
int CGamePad::Connect() {
    int state = scePadGetState(0, 0);
    if (state == scePadStateStable) {
        return 1;
    }
    return state == scePadStateFindCTP1;
}
INCLUDE_ASM("nonmatchings/gamepad", UpDate__8CGamePadFv);
INCLUDE_ASM("nonmatchings/gamepad", Step__8CGamePadFi);
INCLUDE_ASM("nonmatchings/gamepad", AxisCalibration__Fi);
int CGamePad::GetRX() {
    return AxisCalibration(m_rx);
}
int CGamePad::GetRY() {
    return AxisCalibration(m_ry);
}
int CGamePad::GetLX() {
    return AxisCalibration(m_lx);
}
int CGamePad::GetLY() {
    return AxisCalibration(m_ly);
}
int CGamePad::GetRX2() {
    return AxisCalibration(m_rx2);
}
INCLUDE_ASM("nonmatchings/gamepad", CancelAutoRepeat__8CGamePadFi);
