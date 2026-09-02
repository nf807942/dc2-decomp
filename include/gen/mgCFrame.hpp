#ifndef GEN_MGCFRAME_HPP
#define GEN_MGCFRAME_HPP

#include "common.h"

/* Déclaration engendrée par `scripts/diff/petites.py`.
 * Seuls les champs qu'un accesseur touche sont connus ; leur nom dit
 * leur décalage, faute de mieux, et le reste est du remplissage. Ni
 * la taille de la classe ni ses méthodes virtuelles n'y paraissent :
 * déclarer une virtuelle ferait émettre une table que le disque
 * porte déjà. */
struct mgCFrame {
    u8 pad_0x0[0x40];
    s32 field_0x40;
    u8 pad_0x44[0xC];
    char * field_0x50;
    s32 field_0x54;
    u8 pad_0x58[0xA4];
    s32 field_0xFC;

    void DeleteReference(void);
    void SetName(char * arg0);
};

#endif /* GEN_MGCFRAME_HPP */
