#ifndef GEN_CCHARAFRAMEMATCHING_HPP
#define GEN_CCHARAFRAMEMATCHING_HPP

#include "common.h"

/* Déclaration engendrée par `scripts/diff/petites.py`.
 * Seuls les champs qu'un accesseur touche sont connus ; leur nom dit
 * leur décalage, faute de mieux, et le reste est du remplissage. Ni
 * la taille de la classe ni ses méthodes virtuelles n'y paraissent :
 * déclarer une virtuelle ferait émettre une table que le disque
 * porte déjà. */
struct CCharaFrameMatching {
    s32 field_0x0;
    s32 field_0x4;
    s32 field_0x8;

    void Initialize(void);
};

#endif /* GEN_CCHARAFRAMEMATCHING_HPP */
