#ifndef GEN_MENU_BGREAD_INFO2_HPP
#define GEN_MENU_BGREAD_INFO2_HPP

#include "common.h"

/* Déclaration engendrée par `scripts/diff/petites.py`.
 * Seuls les champs qu'un accesseur touche sont connus ; leur nom dit
 * leur décalage, faute de mieux, et le reste est du remplissage. Ni
 * la taille de la classe ni ses méthodes virtuelles n'y paraissent :
 * déclarer une virtuelle ferait émettre une table que le disque
 * porte déjà. */
struct MENU_BGREAD_INFO2 {
    s8 field_0x0;
    u8 pad_0x1[0x1F];
    s8 field_0x20;
    u8 pad_0x21[0x4F];
    s8 field_0x70;
    u8 pad_0x71[0x3];
    s32 field_0x74;
};

#endif /* GEN_MENU_BGREAD_INFO2_HPP */
