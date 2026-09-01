#ifndef GEN_CCAMERAPAS_HPP
#define GEN_CCAMERAPAS_HPP

#include "common.h"

/* Déclaration engendrée par `scripts/diff/petites.py`.
 * Seuls les champs qu'un accesseur touche sont connus ; leur nom dit
 * leur décalage, faute de mieux, et le reste est du remplissage. Ni
 * la taille de la classe ni ses méthodes virtuelles n'y paraissent :
 * déclarer une virtuelle ferait émettre une table que le disque
 * porte déjà. */
struct CCameraPas {
    u8 pad_0x0[0x204];
    s32 field_0x204;
    u8 pad_0x208[0x738];
    s32 field_0x940;

    s32 GetFrame(void);
    s32 SetFrame(s32 arg0);
    void Run(void);
};

#endif /* GEN_CCAMERAPAS_HPP */
