#ifndef GEN_CAFTERWIRE_HPP
#define GEN_CAFTERWIRE_HPP

#include "common.h"

/* Déclaration engendrée par `scripts/diff/petites.py`.
 * Seuls les champs qu'un accesseur touche sont connus ; leur nom dit
 * leur décalage, faute de mieux, et le reste est du remplissage. Ni
 * la taille de la classe ni ses méthodes virtuelles n'y paraissent :
 * déclarer une virtuelle ferait émettre une table que le disque
 * porte déjà. */
struct CAfterWire {
    s32 field_0x0;
    u8 pad_0x4[0x10E];
    s16 field_0x112;
    s16 field_0x114;
    s16 field_0x116;
    s16 field_0x118;

    CAfterWire(void);
    void SetMode(s32 arg0);
};

#endif /* GEN_CAFTERWIRE_HPP */
