#ifndef GEN_CREPAIREFFECT_HPP
#define GEN_CREPAIREFFECT_HPP

#include "common.h"

/* Déclaration engendrée par `scripts/diff/petites.py`.
 * Seuls les champs qu'un accesseur touche sont connus ; leur nom dit
 * leur décalage, faute de mieux, et le reste est du remplissage. Ni
 * la taille de la classe ni ses méthodes virtuelles n'y paraissent :
 * déclarer une virtuelle ferait émettre une table que le disque
 * porte déjà. */
struct CRepairEffect {
    s8 field_0x0;
    u8 pad_0x1[0x3];
    s32 field_0x4;
    u8 pad_0x8[0x10];
    s32 field_0x18;
    s32 field_0x1C;
    s32 field_0x20;

    void Initialize(void);
};

#endif /* GEN_CREPAIREFFECT_HPP */
