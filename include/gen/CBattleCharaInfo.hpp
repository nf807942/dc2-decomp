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
    u8 pad_0x6[0x12];
    s16 field_0x18;
    s16 field_0x1A;
    s16 field_0x1C;
    s16 field_0x1E;
    s16 field_0x20;
    s16 field_0x22;
    s16 field_0x24;
    s16 field_0x26;
    s16 field_0x28;
    u8 pad_0x2A[0x42];
    s16 field_0x6C;

    s16 GetDefenceVol(void);
    s16 GetNowNPC(void);
    void ClearMagicSwordPow(void);
};

#endif /* GEN_CBATTLECHARAINFO_HPP */
