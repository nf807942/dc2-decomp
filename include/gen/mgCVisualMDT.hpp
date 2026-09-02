#ifndef GEN_MGCVISUALMDT_HPP
#define GEN_MGCVISUALMDT_HPP

#include "common.h"

/* Déclaration engendrée par `scripts/diff/petites.py`.
 * Seuls les champs qu'un accesseur touche sont connus ; leur nom dit
 * leur décalage, faute de mieux, et le reste est du remplissage. Ni
 * la taille de la classe ni ses méthodes virtuelles n'y paraissent :
 * déclarer une virtuelle ferait émettre une table que le disque
 * porte déjà. */
struct mgCVisualMDT {
    s32 field_0x0;
    s32 field_0x4;
    s32 field_0x8;
    u8 pad_0xC[0x4];
    s32 field_0x10;
    s32 field_0x14;
    u8 pad_0x18[0x8];
    s32 field_0x20;
    s32 field_0x24;
    s32 field_0x28;
    s32 field_0x2C;
    s32 field_0x30;
    s32 field_0x34;
    s32 field_0x38;
    s32 field_0x3C;
    s32 field_0x40;
    s32 field_0x44;
    s32 field_0x48;

    void Initialize(void);
};

#endif /* GEN_MGCVISUALMDT_HPP */
