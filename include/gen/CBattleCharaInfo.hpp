#ifndef GEN_CBATTLECHARAINFO_HPP
#define GEN_CBATTLECHARAINFO_HPP

#include "common.h"

/* Déclaration engendrée par `scripts/diff/petites.py`.
 * Seuls les champs qu'un accesseur touche sont connus ; leur nom dit
 * leur décalage, faute de mieux, et le reste est du remplissage. Ni
 * la taille de la classe ni ses méthodes virtuelles n'y paraissent :
 * déclarer une virtuelle ferait émettre une table que le disque
 * porte déjà. */
struct CBattleCharaInfo {
    u8 pad_0x0[0x4];
    s16 field_0x4;
    u8 pad_0x6[0x66];
    s16 field_0x6C;

    s16 GetDefenceVol(void);
    s16 GetNowNPC(void);
};

#endif /* GEN_CBATTLECHARAINFO_HPP */
