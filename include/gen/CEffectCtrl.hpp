#ifndef GEN_CEFFECTCTRL_HPP
#define GEN_CEFFECTCTRL_HPP

#include "common.h"

/* Déclaration engendrée par `scripts/diff/petites.py`.
 * Seuls les champs qu'un accesseur touche sont connus ; leur nom dit
 * leur décalage, faute de mieux, et le reste est du remplissage. Ni
 * la taille de la classe ni ses méthodes virtuelles n'y paraissent :
 * déclarer une virtuelle ferait émettre une table que le disque
 * porte déjà. */
struct CEffectCtrl {
    u8 pad_0x0[0x10];
    s32 field_0x10;
    u8 pad_0x14[0x3C];
    s32 field_0x50;
    u8 pad_0x54[0x10];
    s32 field_0x64;

    void Run(void);
};

#endif /* GEN_CEFFECTCTRL_HPP */
