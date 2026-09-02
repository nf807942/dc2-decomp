#ifndef GEN_CPULLITEM_HPP
#define GEN_CPULLITEM_HPP

#include "common.h"

/* Déclaration engendrée par `scripts/diff/petites.py`.
 * Seuls les champs qu'un accesseur touche sont connus ; leur nom dit
 * leur décalage, faute de mieux, et le reste est du remplissage. Ni
 * la taille de la classe ni ses méthodes virtuelles n'y paraissent :
 * déclarer une virtuelle ferait émettre une table que le disque
 * porte déjà. */
struct CPullItem {
    u8 pad_0x0[0x30];
    s16 field_0x30;
    s16 field_0x32;
    s16 field_0x34;
    s16 field_0x36;
    u8 pad_0x38[0xA];
    s16 field_0x42;
    s16 field_0x44;
    u8 pad_0x46[0xA];
    s16 field_0x50;
    u8 pad_0x52[0x22];
    s8 field_0x74;
    u8 pad_0x75[0x7];
    s32 field_0x7C;

    void Clear(void);
    void Initialize(void);
};

#endif /* GEN_CPULLITEM_HPP */
