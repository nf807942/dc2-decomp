#ifndef GEN_MGCMEMORY_HPP
#define GEN_MGCMEMORY_HPP

#include "common.h"

/* Déclaration engendrée par `scripts/diff/petites.py`.
 * Seuls les champs qu'un accesseur touche sont connus ; leur nom dit
 * leur décalage, faute de mieux, et le reste est du remplissage. Ni
 * la taille de la classe ni ses méthodes virtuelles n'y paraissent :
 * déclarer une virtuelle ferait émettre une table que le disque
 * porte déjà. */
struct mgCMemory {
    u8 pad_0x0[0x1C];
    s32 field_0x1C;
    u8 pad_0x20[0x4];
    s32 field_0x24;
};

#endif /* GEN_MGCMEMORY_HPP */
