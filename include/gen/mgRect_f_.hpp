#ifndef GEN_MGRECT_F__HPP
#define GEN_MGRECT_F__HPP

#include "common.h"

/* Déclaration engendrée par `scripts/diff/petites.py`.
 * Seuls les champs qu'un accesseur touche sont connus ; leur nom dit
 * leur décalage, faute de mieux, et le reste est du remplissage. Ni
 * la taille de la classe ni ses méthodes virtuelles n'y paraissent :
 * déclarer une virtuelle ferait émettre une table que le disque
 * porte déjà. */
struct mgRect_f_ {
    f32 field_0x0;
    f32 field_0x4;
    f32 field_0x8;
    f32 field_0xC;

    void Set(f32 arg0, f32 arg1, f32 arg2, f32 arg3);
};

#endif /* GEN_MGRECT_F__HPP */
