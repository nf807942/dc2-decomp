#ifndef GEN_CDYNAMICANIME_HPP
#define GEN_CDYNAMICANIME_HPP

#include "common.h"

/* Déclaration engendrée par `scripts/diff/petites.py`.
 * Seuls les champs qu'un accesseur touche sont connus ; leur nom dit
 * leur décalage, faute de mieux, et le reste est du remplissage. Ni
 * la taille de la classe ni ses méthodes virtuelles n'y paraissent :
 * déclarer une virtuelle ferait émettre une table que le disque
 * porte déjà. */
struct CDynamicAnime {
    u8 pad_0x0[0x68];
    s32 field_0x68;
    u8 pad_0x6C[0x1C];
    s32 field_0x88;
    f32 field_0x8C;

    void ResetFloor(void);
    void ResetWind(void);
    void SetFloor(f32 arg0);
};

#endif /* GEN_CDYNAMICANIME_HPP */
