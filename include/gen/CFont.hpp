#ifndef GEN_CFONT_HPP
#define GEN_CFONT_HPP

#include "common.h"

/* Déclaration engendrée par `scripts/diff/petites.py`.
 * Seuls les champs qu'un accesseur touche sont connus ; leur nom dit
 * leur décalage, faute de mieux, et le reste est du remplissage. Ni
 * la taille de la classe ni ses méthodes virtuelles n'y paraissent :
 * déclarer une virtuelle ferait émettre une table que le disque
 * porte déjà. */
struct CFont {
    u8 pad_0x0[0x80];
    s32 field_0x80;
    u8 pad_0x84[0x10];
    s32 field_0x94;
    s32 field_0x98;
    s32 field_0x9C;
    s32 field_0xA0;
    s32 field_0xA4;
    s32 field_0xA8;

    void SetClearance(s32 arg0, s32 arg1);
    void SetDrawSize(s32 arg0, s32 arg1);
    void SetFuchi(s32 arg0);
    void SetPos(s32 arg0, s32 arg1);
};

#endif /* GEN_CFONT_HPP */
