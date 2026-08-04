#ifndef GAMEPAD_HPP
#define GAMEPAD_HPP

#include "types.h"

/* Le service de manette du SDK. `scePadPortClose` prend le port et son
 * emplacement — le second vaut toujours zéro ici, le jeu n'employant pas de
 * multitap. */
extern "C" {
int scePadPortClose(int port, int slot);
int scePadEnd(void);
int scePadGetState(int port, int slot);
}

/* Les états qu'un port traverse. Le jeu tient la manette pour présente dans
 * deux d'entre eux : quand la liaison est établie, et quand le port a reconnu
 * un contrôleur du premier type — celui de la manette numérique. */
#define scePadStateFindCTP1 2
#define scePadStateStable   6

/* Centre la course d'un manche : 128 est le point mort, une zone autour est
 * morte, et la course qui reste est ramenée. Les cinq getters de `CGamePad`
 * s'en remettent à elle pour leurs quatre manches et leur seconde poussée. */
int AxisCalibration(int value);

class CGamePad {
public:
    void Close();
    int Connect();

    int GetRX();
    int GetRY();
    int GetLX();
    int GetLY();
    int GetRX2();

private:
    /* 0x00 : usage inconnu — aucune fonction de l'unité n'y touche encore. */
    int m_root;
    /* Les données du premier port telles que `read_pad` les remplit depuis
     * le SDK : boutons, puis les quatre manches. */
    int m_btns;   /* 0x04 */
    int m_ly;     /* 0x08 */
    int m_lx;     /* 0x0C */
    int m_ry;     /* 0x10 */
    int m_rx;     /* 0x14 */
    /* 0x18 à 0x60 : auto-répétitions, second port, vibreur — à établir. */
    char m_pad[0x48];
    int m_rx2;    /* 0x60 */
};

#endif /* GAMEPAD_HPP */
