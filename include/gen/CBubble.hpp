#ifndef GEN_CBUBBLE_HPP
#define GEN_CBUBBLE_HPP

#include "common.h"

struct mgCTexture;

/* Déclaration engendrée par `scripts/diff/petites.py`.
 * Seuls les champs qu'un accesseur touche sont connus ; leur nom dit
 * leur décalage, faute de mieux, et le reste est du remplissage. Ni
 * la taille de la classe ni ses méthodes virtuelles n'y paraissent :
 * déclarer une virtuelle ferait émettre une table que le disque
 * porte déjà. */
struct CBubble {
    u8 pad_0x0[0x1];
    s8 field_0x1;
    u8 pad_0x2[0x2];
    s32 field_0x4;
    u8 pad_0x8[0x20];
    mgCTexture * field_0x28;
    s16 field_0x2C;
    s16 field_0x2E;

    void RunOff(void);
    void SetTexture(mgCTexture * arg0, s32 arg1, s32 arg2);
};

#endif /* GEN_CBUBBLE_HPP */
