#ifndef GEN_CLEVELUPEFFECT_HPP
#define GEN_CLEVELUPEFFECT_HPP

#include "common.h"

/* Déclaration engendrée par `scripts/diff/petites.py`.
 * Seuls les champs qu'un accesseur touche sont connus ; leur nom dit
 * leur décalage, faute de mieux, et le reste est du remplissage. Ni
 * la taille de la classe ni ses méthodes virtuelles n'y paraissent :
 * déclarer une virtuelle ferait émettre une table que le disque
 * porte déjà. */
struct CLevelUpEffect {
    s8 field_0x0;
    u8 pad_0x1[0x1F];
    s32 field_0x20;
    s32 field_0x24;

    u8 IsRun(void);
    void Initialize(void);
};

#endif /* GEN_CLEVELUPEFFECT_HPP */
