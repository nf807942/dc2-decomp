#ifndef GEN_CLASERGUN_HPP
#define GEN_CLASERGUN_HPP

#include "common.h"

/* Déclaration engendrée par `scripts/diff/petites.py`.
 * Seuls les champs qu'un accesseur touche sont connus ; leur nom dit
 * leur décalage, faute de mieux, et le reste est du remplissage. Ni
 * la taille de la classe ni ses méthodes virtuelles n'y paraissent :
 * déclarer une virtuelle ferait émettre une table que le disque
 * porte déjà. */
struct CLaserGun {
    s32 field_0x0;
    u8 pad_0x4[0xCC];
    s32 field_0xD0;
    s32 field_0xD4;
    u8 pad_0xD8[0x10];
    s32 field_0xE8;
    s32 field_0xEC;
    u8 pad_0xF0[0x30];
    s32 field_0x120;

    void Initialize(void);
};

#endif /* GEN_CLASERGUN_HPP */
