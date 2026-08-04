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

class CGamePad {
public:
    void Close();
    int Connect();
};

#endif /* GAMEPAD_HPP */
