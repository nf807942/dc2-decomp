#ifndef GEN_MGCDRAWPRIM_HPP
#define GEN_MGCDRAWPRIM_HPP

#include "common.h"

/* Déclaration engendrée par `scripts/diff/petites.py`.
 * Seuls les champs qu'un accesseur touche sont connus ; leur nom dit
 * leur décalage, faute de mieux, et le reste est du remplissage. Ni
 * la taille de la classe ni ses méthodes virtuelles n'y paraissent :
 * déclarer une virtuelle ferait émettre une table que le disque
 * porte déjà. */
struct mgCDrawPrim {
    u8 pad_0x0[0xC8];
    s32 field_0xC8;
    s32 field_0xCC;
    u8 pad_0xD0[0x2C];
    s32 field_0xFC;

    void Bilinear(s32 arg0);
    void Coord(s32 arg0);
    void ZMask(s32 arg0);
};

#endif /* GEN_MGCDRAWPRIM_HPP */
