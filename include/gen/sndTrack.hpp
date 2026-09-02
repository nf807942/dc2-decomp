#ifndef GEN_SNDTRACK_HPP
#define GEN_SNDTRACK_HPP

#include "common.h"

/* Déclaration engendrée par `scripts/diff/petites.py`.
 * Seuls les champs qu'un accesseur touche sont connus ; leur nom dit
 * leur décalage, faute de mieux, et le reste est du remplissage. Ni
 * la taille de la classe ni ses méthodes virtuelles n'y paraissent :
 * déclarer une virtuelle ferait émettre une table que le disque
 * porte déjà. */
struct sndTrack {
    u8 pad_0x0[0x2];
    s8 field_0x2;
    u8 pad_0x3[0x1];
    s8 field_0x4;
    s8 field_0x5;

    s32 PitchBend(s32 arg0, s32 arg1);
    s32 ProgChg(s32 arg0);
};

#endif /* GEN_SNDTRACK_HPP */
