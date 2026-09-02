#ifndef GEN_CREDMARKMODEL_HPP
#define GEN_CREDMARKMODEL_HPP

#include "common.h"

/* Déclaration engendrée par `scripts/diff/petites.py`.
 * Seuls les champs qu'un accesseur touche sont connus ; leur nom dit
 * leur décalage, faute de mieux, et le reste est du remplissage. Ni
 * la taille de la classe ni ses méthodes virtuelles n'y paraissent :
 * déclarer une virtuelle ferait émettre une table que le disque
 * porte déjà. */
struct CRedMarkModel {
    u8 pad_0x0[0x70];
    s32 field_0x70;
    u8 pad_0x74[0xC];
    s32 field_0x80;
    s32 field_0x84;

    void Initialize(void);
};

#endif /* GEN_CREDMARKMODEL_HPP */
