#ifndef GEN_CDATAITEM_HPP
#define GEN_CDATAITEM_HPP

#include "common.h"

/* Déclaration engendrée par `scripts/diff/petites.py`.
 * Seuls les champs qu'un accesseur touche sont connus ; leur nom dit
 * leur décalage, faute de mieux, et le reste est du remplissage. Ni
 * la taille de la classe ni ses méthodes virtuelles n'y paraissent :
 * déclarer une virtuelle ferait émettre une table que le disque
 * porte déjà. */
struct CDataItem {
    s32 field_0x0;
    s32 field_0x4;
    u8 pad_0x8[0x2];
    s16 field_0xA;
    s16 field_0xC;
    s16 field_0xE;

    CDataItem(void);
};

#endif /* GEN_CDATAITEM_HPP */
