#ifndef GEN_CEFFECTMANAGER_HPP
#define GEN_CEFFECTMANAGER_HPP

#include "common.h"

/* Déclaration engendrée par `scripts/diff/petites.py`.
 * Seuls les champs qu'un accesseur touche sont connus ; leur nom dit
 * leur décalage, faute de mieux, et le reste est du remplissage. Ni
 * la taille de la classe ni ses méthodes virtuelles n'y paraissent :
 * déclarer une virtuelle ferait émettre une table que le disque
 * porte déjà. */
struct CEffectManager {
    u8 pad_0x0[0x24];
    s32 field_0x24;
    u8 pad_0x28[0x4];
    s32 field_0x2C;

    void SetEffectNums(s32 arg0, s32 arg1);
};

#endif /* GEN_CEFFECTMANAGER_HPP */
