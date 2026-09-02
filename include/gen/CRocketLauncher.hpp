#ifndef GEN_CROCKETLAUNCHER_HPP
#define GEN_CROCKETLAUNCHER_HPP

#include "common.h"

/* Déclaration engendrée par `scripts/diff/petites.py`.
 * Seuls les champs qu'un accesseur touche sont connus ; leur nom dit
 * leur décalage, faute de mieux, et le reste est du remplissage. Ni
 * la taille de la classe ni ses méthodes virtuelles n'y paraissent :
 * déclarer une virtuelle ferait émettre une table que le disque
 * porte déjà. */
struct CRocketLauncher {
    s32 field_0x0;
    u8 pad_0x4[0x14C];
    s32 field_0x150;
    s32 field_0x154;
    u8 pad_0x158[0x8];
    s32 field_0x160;
    s32 field_0x164;
    u8 pad_0x168[0xC];
    s32 field_0x174;

    void Initialize(void);
};

#endif /* GEN_CROCKETLAUNCHER_HPP */
