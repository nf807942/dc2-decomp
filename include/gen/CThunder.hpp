#ifndef GEN_CTHUNDER_HPP
#define GEN_CTHUNDER_HPP

#include "common.h"

/* Déclaration engendrée par `scripts/diff/petites.py`.
 * Seuls les champs qu'un accesseur touche sont connus ; leur nom dit
 * leur décalage, faute de mieux, et le reste est du remplissage. Ni
 * la taille de la classe ni ses méthodes virtuelles n'y paraissent :
 * déclarer une virtuelle ferait émettre une table que le disque
 * porte déjà. */
struct CThunder {
    u8 pad_0x0[0xF4];
    void * field_0xF4;
    u8 pad_0xF8[0x18];
    s32 field_0x110;
    u8 pad_0x114[0xC9C];
    s8 field_0xDB0;
    s8 field_0xDB1;

    void Initialize(void);
};

#endif /* GEN_CTHUNDER_HPP */
