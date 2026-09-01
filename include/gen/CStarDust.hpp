#ifndef GEN_CSTARDUST_HPP
#define GEN_CSTARDUST_HPP

#include "common.h"

/* Déclaration engendrée par `scripts/diff/petites.py`.
 * Seuls les champs qu'un accesseur touche sont connus ; leur nom dit
 * leur décalage, faute de mieux, et le reste est du remplissage. Ni
 * la taille de la classe ni ses méthodes virtuelles n'y paraissent :
 * déclarer une virtuelle ferait émettre une table que le disque
 * porte déjà. */
struct CStarDust {
    u8 pad_0x0[0xA];
    s8 field_0xA;

    CStarDust(void);
};

#endif /* GEN_CSTARDUST_HPP */
