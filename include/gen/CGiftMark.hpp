#ifndef GEN_CGIFTMARK_HPP
#define GEN_CGIFTMARK_HPP

#include "common.h"

/* Déclaration engendrée par `scripts/diff/petites.py`.
 * Seuls les champs qu'un accesseur touche sont connus ; leur nom dit
 * leur décalage, faute de mieux, et le reste est du remplissage. Ni
 * la taille de la classe ni ses méthodes virtuelles n'y paraissent :
 * déclarer une virtuelle ferait émettre une table que le disque
 * porte déjà. */
struct CGiftMark {
    s32 field_0x0;
    u8 pad_0x4[0x4];
    s32 field_0x8;
    s32 field_0xC;
    s16 field_0x10;

    void Initialize(void);
};

#endif /* GEN_CGIFTMARK_HPP */
