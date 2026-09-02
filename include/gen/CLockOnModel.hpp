#ifndef GEN_CLOCKONMODEL_HPP
#define GEN_CLOCKONMODEL_HPP

#include "common.h"

struct CScene;

/* Déclaration engendrée par `scripts/diff/petites.py`.
 * Seuls les champs qu'un accesseur touche sont connus ; leur nom dit
 * leur décalage, faute de mieux, et le reste est du remplissage. Ni
 * la taille de la classe ni ses méthodes virtuelles n'y paraissent :
 * déclarer une virtuelle ferait émettre une table que le disque
 * porte déjà. */
struct CLockOnModel {
    u8 pad_0x0[0x80];
    CScene * field_0x80;
    u8 pad_0x84[0x8];
    s32 field_0x8C;

    void Initialize(CScene * arg0);
};

#endif /* GEN_CLOCKONMODEL_HPP */
