#ifndef GEN_MGRENDERINFODATA_HPP
#define GEN_MGRENDERINFODATA_HPP

#include "common.h"

/* Déclaration engendrée par `scripts/diff/petites.py`.
 * Seuls les champs qu'un accesseur touche sont connus ; leur nom dit
 * leur décalage, faute de mieux, et le reste est du remplissage. Ni
 * la taille de la classe ni ses méthodes virtuelles n'y paraissent :
 * déclarer une virtuelle ferait émettre une table que le disque
 * porte déjà. */
struct mgRenderInfoData {
    f32 field_0x0;
    u8 pad_0x4[0xF9C];
    s32 field_0xFA0;
};

#endif /* GEN_MGRENDERINFODATA_HPP */
