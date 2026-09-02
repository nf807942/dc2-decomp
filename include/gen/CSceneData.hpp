#ifndef GEN_CSCENEDATA_HPP
#define GEN_CSCENEDATA_HPP

#include "common.h"

/* Déclaration engendrée par `scripts/diff/petites.py`.
 * Seuls les champs qu'un accesseur touche sont connus ; leur nom dit
 * leur décalage, faute de mieux, et le reste est du remplissage. Ni
 * la taille de la classe ni ses méthodes virtuelles n'y paraissent :
 * déclarer une virtuelle ferait émettre une table que le disque
 * porte déjà. */
struct CSceneData {
    s32 field_0x0;
    s32 field_0x4;
    s8 field_0x8;
    u8 pad_0x9[0x1F];
    s32 field_0x28;
    s32 field_0x2C;
    s32 field_0x30;

    void Initialize(void);
};

#endif /* GEN_CSCENEDATA_HPP */
