/* CGamePad — la manette, telle que le jeu la voit.
 *
 * Première unité reconstruite du projet. Tout ce qui n'est pas encore écrit
 * reste l'assembleur du disque, greffé par mwccgap.
 */

#include "common.h"
#include "gamepad.hpp"

void CGamePad::Close() {
    scePadPortClose(0, 0);
    scePadPortClose(1, 0);
    scePadEnd();
}
