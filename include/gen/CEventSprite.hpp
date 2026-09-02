#ifndef GEN_CEVENTSPRITE_HPP
#define GEN_CEVENTSPRITE_HPP

#include "common.h"

/* Déclaration engendrée par `scripts/diff/petites.py`.
 * Seuls les champs qu'un accesseur touche sont connus ; leur nom dit
 * leur décalage, faute de mieux, et le reste est du remplissage. Ni
 * la taille de la classe ni ses méthodes virtuelles n'y paraissent :
 * déclarer une virtuelle ferait émettre une table que le disque
 * porte déjà. */
struct CEventSprite {
    s32 field_0x0;
    u8 pad_0x4[0x74];
    s32 field_0x78;
    s32 field_0x7C;
    s32 field_0x80;
    s32 field_0x84;

    void SetDraw(s32 arg0);
    void SetMove(s32 arg0, s32 arg1, s32 arg2);
};

#endif /* GEN_CEVENTSPRITE_HPP */
