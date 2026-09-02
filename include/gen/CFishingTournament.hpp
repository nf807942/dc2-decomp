#ifndef GEN_CFISHINGTOURNAMENT_HPP
#define GEN_CFISHINGTOURNAMENT_HPP

#include "common.h"

/* Déclaration engendrée par `scripts/diff/petites.py`.
 * Seuls les champs qu'un accesseur touche sont connus ; leur nom dit
 * leur décalage, faute de mieux, et le reste est du remplissage. Ni
 * la taille de la classe ni ses méthodes virtuelles n'y paraissent :
 * déclarer une virtuelle ferait émettre une table que le disque
 * porte déjà. */
struct CFishingTournament {
    u8 pad_0x0[0x20];
    s32 field_0x20;

    void Initialize(void);
    void ResetRecord(void);
};

#endif /* GEN_CFISHINGTOURNAMENT_HPP */
