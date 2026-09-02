#ifndef GEN_MGRENDER_INFO_HPP
#define GEN_MGRENDER_INFO_HPP

#include "common.h"

/* Déclaration engendrée par `scripts/diff/petites.py`.
 * Seuls les champs qu'un accesseur touche sont connus ; leur nom dit
 * leur décalage, faute de mieux, et le reste est du remplissage. Ni
 * la taille de la classe ni ses méthodes virtuelles n'y paraissent :
 * déclarer une virtuelle ferait émettre une table que le disque
 * porte déjà. */
struct mgRENDER_INFO {
    u8 pad_0x0[0xFA4];
    s32 field_0xFA4;
    s32 field_0xFA8;

    s32 GetFogEnable(void);
    s32 GetPlightEnable(void);
    void FogEnable(s32 arg0);
    void PlightEnable(s32 arg0);
};

#endif /* GEN_MGRENDER_INFO_HPP */
