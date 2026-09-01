#ifndef GEN_CSUBGAMEDATA_HPP
#define GEN_CSUBGAMEDATA_HPP

#include "common.h"

/* Déclaration engendrée par `scripts/diff/petites.py`.
 * Seuls les champs qu'un accesseur touche sont connus ; leur nom dit
 * leur décalage, faute de mieux, et le reste est du remplissage. Ni
 * la taille de la classe ni ses méthodes virtuelles n'y paraissent :
 * déclarer une virtuelle ferait émettre une table que le disque
 * porte déjà. */
struct CSubGameData {
    u8 pad_0x0[0x100];
    s32 field_0x100;
    u8 pad_0x104[0x1844];
    s32 field_0x1948;

    void * GetGyoRaceData(void);
    void * GetSphidaData(void);
    void Initialize(void);
};

#endif /* GEN_CSUBGAMEDATA_HPP */
