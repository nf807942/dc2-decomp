#ifndef GEN_CCHARAPAS_HPP
#define GEN_CCHARAPAS_HPP

#include "common.h"

/* Déclaration engendrée par `scripts/diff/petites.py`.
 * Seuls les champs qu'un accesseur touche sont connus ; leur nom dit
 * leur décalage, faute de mieux, et le reste est du remplissage. Ni
 * la taille de la classe ni ses méthodes virtuelles n'y paraissent :
 * déclarer une virtuelle ferait émettre une table que le disque
 * porte déjà. */
struct CCharaPas {
    u8 pad_0x0[0x100];
    s32 field_0x100;

    s32 GetFrame(void);
    void SetFrame(s32 arg0);
};

#endif /* GEN_CCHARAPAS_HPP */
