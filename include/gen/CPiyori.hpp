#ifndef GEN_CPIYORI_HPP
#define GEN_CPIYORI_HPP

#include "common.h"

/* Déclaration engendrée par `scripts/diff/petites.py`.
 * Seuls les champs qu'un accesseur touche sont connus ; leur nom dit
 * leur décalage, faute de mieux, et le reste est du remplissage. Ni
 * la taille de la classe ni ses méthodes virtuelles n'y paraissent :
 * déclarer une virtuelle ferait émettre une table que le disque
 * porte déjà. */
struct CPiyori {
    s32 field_0x0;
    u8 pad_0x4[0x18];
    s16 field_0x1C;

    void Initialize(void);
    void Reset(void);
};

#endif /* GEN_CPIYORI_HPP */
