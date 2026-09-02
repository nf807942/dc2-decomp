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
    u8 pad_0x140[0x9C];
    s32 field_0x1DC;
    u8 pad_0x1E0[0x1C48];
    s32 field_0x1E28;
    s32 field_0x1E2C;
    u8 pad_0x1E30[0xB1C];
    s16 * field_0x294C;
    s16 * field_0x2950;

    s32 GetPageAutoFlg(void);
    s32 GetWindowMode(void);
    void SetBuff(s16 * arg0);
    void SetBuff_system(s16 * arg0);
    void SetDefColor(u32 arg0);
    void SetWindowBgOpaqueFlg(s32 arg0);
};

#endif /* GEN_CLSMES_HPP */
