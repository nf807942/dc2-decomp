#ifndef GEN_CHEALINGEFFECTMAN_HPP
#define GEN_CHEALINGEFFECTMAN_HPP

#include "common.h"

/* Déclaration engendrée par `scripts/diff/petites.py`.
 * Seuls les champs qu'un accesseur touche sont connus ; leur nom dit
 * leur décalage, faute de mieux, et le reste est du remplissage. Ni
 * la taille de la classe ni ses méthodes virtuelles n'y paraissent :
 * déclarer une virtuelle ferait émettre une table que le disque
 * porte déjà. */
struct CHealingEffectMan {
    u8 pad_0x0[0x314];
    s16 field_0x314;

    void SetMode(s32 arg0);
};

#endif /* GEN_CHEALINGEFFECTMAN_HPP */
