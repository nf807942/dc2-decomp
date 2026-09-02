#ifndef GEN_CWATER_HPP
#define GEN_CWATER_HPP

#include "common.h"

/* Déclaration engendrée par `scripts/diff/petites.py`.
 * Seuls les champs qu'un accesseur touche sont connus ; leur nom dit
 * leur décalage, faute de mieux, et le reste est du remplissage. Ni
 * la taille de la classe ni ses méthodes virtuelles n'y paraissent :
 * déclarer une virtuelle ferait émettre une table que le disque
 * porte déjà. */
struct CWater {
    u8 pad_0x0[0x40];
    f32 field_0x40;
    f32 field_0x44;
    f32 field_0x48;
    f32 field_0x4C;

    void SetParam(f32 arg0, f32 arg1, f32 arg2, f32 arg3);
};

#endif /* GEN_CWATER_HPP */
