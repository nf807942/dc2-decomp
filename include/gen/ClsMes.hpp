#ifndef GEN_CLSMES_HPP
#define GEN_CLSMES_HPP

#include "common.h"

/* Déclaration engendrée par `scripts/diff/petites.py`.
 * Seuls les champs qu'un accesseur touche sont connus ; leur nom dit
 * leur décalage, faute de mieux, et le reste est du remplissage. Ni
 * la taille de la classe ni ses méthodes virtuelles n'y paraissent :
 * déclarer une virtuelle ferait émettre une table que le disque
 * porte déjà. */
struct ClsMes {
    u8 pad_0x0[0x138];
    s32 field_0x138;
    s32 field_0x13C;

    s32 GetWindowMode(void);
    void SetWindowBgOpaqueFlg(s32 arg0);
};

#endif /* GEN_CLSMES_HPP */
