#ifndef GEN_PLACEANIMEDATA_HPP
#define GEN_PLACEANIMEDATA_HPP

#include "common.h"

/* Déclaration engendrée par `scripts/diff/petites.py`.
 * Seuls les champs qu'un accesseur touche sont connus ; leur nom dit
 * leur décalage, faute de mieux, et le reste est du remplissage. Ni
 * la taille de la classe ni ses méthodes virtuelles n'y paraissent :
 * déclarer une virtuelle ferait émettre une table que le disque
 * porte déjà. */
struct PlaceAnimeData {
    s32 field_0x0;
    s32 field_0x4;
    s32 field_0x8;
    u8 pad_0xC[0x84];
    s32 field_0x90;
    s32 field_0x94;
    s32 field_0x98;
    u8 pad_0x9C[0x84];
    s32 field_0x120;
    s32 field_0x124;
    s32 field_0x128;
};

#endif /* GEN_PLACEANIMEDATA_HPP */
