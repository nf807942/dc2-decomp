#ifndef GEN_CMENUEFFECT_HPP
#define GEN_CMENUEFFECT_HPP

#include "common.h"

/* Déclaration engendrée par `scripts/diff/petites.py`.
 * Seuls les champs qu'un accesseur touche sont connus ; leur nom dit
 * leur décalage, faute de mieux, et le reste est du remplissage. Ni
 * la taille de la classe ni ses méthodes virtuelles n'y paraissent :
 * déclarer une virtuelle ferait émettre une table que le disque
 * porte déjà. */
struct CMenuEffect {
    s16 field_0x0;
    u8 pad_0x2[0x2];
    s32 field_0x4;
    u8 pad_0x8[0x1];
    s8 field_0x9;
    s8 field_0xA;
    u8 pad_0xB[0x1];
    s16 field_0xC;
    u8 pad_0xE[0x2];
    s32 field_0x10;
    u8 pad_0x14[0x20];
    s16 field_0x34;
    s16 field_0x36;

    void EffectStart(void);
    void Initialize(void);
};

#endif /* GEN_CMENUEFFECT_HPP */
