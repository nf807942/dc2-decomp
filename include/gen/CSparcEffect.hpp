#ifndef GEN_CSPARCEFFECT_HPP
#define GEN_CSPARCEFFECT_HPP

#include "common.h"

/* Déclaration engendrée par `scripts/diff/petites.py`.
 * Seuls les champs qu'un accesseur touche sont connus ; leur nom dit
 * leur décalage, faute de mieux, et le reste est du remplissage. Ni
 * la taille de la classe ni ses méthodes virtuelles n'y paraissent :
 * déclarer une virtuelle ferait émettre une table que le disque
 * porte déjà. */
struct CSparcEffect {
    u8 pad_0x0[0xA9];
    s8 field_0xA9;

    void Initialize(void);
};

#endif /* GEN_CSPARCEFFECT_HPP */
