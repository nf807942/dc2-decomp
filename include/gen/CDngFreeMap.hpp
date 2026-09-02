#ifndef GEN_CDNGFREEMAP_HPP
#define GEN_CDNGFREEMAP_HPP

#include "common.h"

/* Déclaration engendrée par `scripts/diff/petites.py`.
 * Seuls les champs qu'un accesseur touche sont connus ; leur nom dit
 * leur décalage, faute de mieux, et le reste est du remplissage. Ni
 * la taille de la classe ni ses méthodes virtuelles n'y paraissent :
 * déclarer une virtuelle ferait émettre une table que le disque
 * porte déjà. */
struct CDngFreeMap {
    u8 pad_0x0[0xD0];
    s16 field_0xD0;
    u8 pad_0xD2[0x2];
    s32 field_0xD4;
    s32 field_0xD8;
    s32 field_0xDC;
    s32 field_0xE0;

    void InitTexture(void);
};

#endif /* GEN_CDNGFREEMAP_HPP */
