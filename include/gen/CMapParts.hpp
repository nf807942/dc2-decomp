#ifndef GEN_CMAPPARTS_HPP
#define GEN_CMAPPARTS_HPP

#include "common.h"

/* Déclaration engendrée par `scripts/diff/petites.py`.
 * Seuls les champs qu'un accesseur touche sont connus ; leur nom dit
 * leur décalage, faute de mieux, et le reste est du remplissage. Ni
 * la taille de la classe ni ses méthodes virtuelles n'y paraissent :
 * déclarer une virtuelle ferait émettre une table que le disque
 * porte déjà. */
struct CMapParts {
    u8 pad_0x0[0x1D0];
    s32 field_0x1D0;
    s32 field_0x1D4;
    f32 * field_0x1D8;

    s32 GetLODBlend(void);
    void SetLODBlend(s32 arg0);
    void SetLODDist(f32 * arg0, s32 arg1);
};

#endif /* GEN_CMAPPARTS_HPP */
