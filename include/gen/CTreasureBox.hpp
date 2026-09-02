#ifndef GEN_CTREASUREBOX_HPP
#define GEN_CTREASUREBOX_HPP

#include "common.h"

/* Déclaration engendrée par `scripts/diff/petites.py`.
 * Seuls les champs qu'un accesseur touche sont connus ; leur nom dit
 * leur décalage, faute de mieux, et le reste est du remplissage. Ni
 * la taille de la classe ni ses méthodes virtuelles n'y paraissent :
 * déclarer une virtuelle ferait émettre une table que le disque
 * porte déjà. */
struct CTreasureBox {
    u8 pad_0x0[0x50];
    s32 field_0x50;
    s8 field_0x54;
    u8 pad_0x55[0x3];
    s32 field_0x58;

    void Initialize(void);
};

#endif /* GEN_CTREASUREBOX_HPP */
