#ifndef GEN_EDEVENTINFODATA_HPP
#define GEN_EDEVENTINFODATA_HPP

#include "common.h"

/* Déclaration engendrée par `scripts/diff/petites.py`.
 * Seuls les champs qu'un accesseur touche sont connus ; leur nom dit
 * leur décalage, faute de mieux, et le reste est du remplissage. Ni
 * la taille de la classe ni ses méthodes virtuelles n'y paraissent :
 * déclarer une virtuelle ferait émettre une table que le disque
 * porte déjà. */
struct EdEventInfoData {
    u8 pad_0x0[0xCC];
    s32 field_0xCC;
    s32 field_0xD0;
    s32 field_0xD4;
    s32 field_0xD8;
    u8 pad_0xDC[0x4];
    s32 field_0xE0;
    s32 field_0xE4;
    s32 field_0xE8;
    s32 field_0xEC;
    u8 pad_0xF0[0x117C];
    s32 field_0x126C;
    s32 field_0x1270;
};

#endif /* GEN_EDEVENTINFODATA_HPP */
