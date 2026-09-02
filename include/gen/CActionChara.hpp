#ifndef GEN_CACTIONCHARA_HPP
#define GEN_CACTIONCHARA_HPP

#include "common.h"

/* Déclaration engendrée par `scripts/diff/petites.py`.
 * Seuls les champs qu'un accesseur touche sont connus ; leur nom dit
 * leur décalage, faute de mieux, et le reste est du remplissage. Ni
 * la taille de la classe ni ses méthodes virtuelles n'y paraissent :
 * déclarer une virtuelle ferait émettre une table que le disque
 * porte déjà. */
struct CActionChara {
    u8 pad_0x0[0x780];
    s32 field_0x780;
    s32 field_0x784;
    s32 field_0x788;
    u8 pad_0x78C[0x4];
    s32 field_0x790;

    void ResetAccele(void);
};

#endif /* GEN_CACTIONCHARA_HPP */
