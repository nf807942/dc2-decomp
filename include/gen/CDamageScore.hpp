#ifndef GEN_CDAMAGESCORE_HPP
#define GEN_CDAMAGESCORE_HPP

#include "common.h"

/* Déclaration engendrée par `scripts/diff/petites.py`.
 * Seuls les champs qu'un accesseur touche sont connus ; leur nom dit
 * leur décalage, faute de mieux, et le reste est du remplissage. Ni
 * la taille de la classe ni ses méthodes virtuelles n'y paraissent :
 * déclarer une virtuelle ferait émettre une table que le disque
 * porte déjà. */
struct CDamageScore {
    u8 pad_0x0[0x48];
    s16 field_0x48;
    s16 field_0x4A;
    s16 field_0x4C;

    void SetColor(s16 arg0, s16 arg1, s16 arg2);
};

#endif /* GEN_CDAMAGESCORE_HPP */
