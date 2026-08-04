#ifndef GAMEPAD_HPP
#define GAMEPAD_HPP

#include "types.h"

/* Les deux ports de manette que le jeu ouvre, et le service du SDK qui les
 * porte. `scePadPortClose` prend le port et son emplacement — le second vaut
 * toujours zéro ici, le jeu n'employant pas de multitap. */
extern "C" {
int scePadPortClose(int port, int slot);
int scePadEnd(void);
}

class CGamePad {
public:
    void Close();
};

#endif /* GAMEPAD_HPP */
