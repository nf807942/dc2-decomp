#ifndef GEN_DBGCJISFONT_HPP
#define GEN_DBGCJISFONT_HPP

#include "common.h"

/* Déclaration engendrée par `scripts/diff/petites.py`.
 * Seuls les champs qu'un accesseur touche sont connus ; leur nom dit
 * leur décalage, faute de mieux, et le reste est du remplissage. Ni
 * la taille de la classe ni ses méthodes virtuelles n'y paraissent :
 * déclarer une virtuelle ferait émettre une table que le disque
 * porte déjà. */
struct dbgCJISFont {
    s32 field_0x0;
    s32 field_0x4;
    s32 field_0x8;
    s32 field_0xC;
    s8 field_0x10;
    u8 pad_0x11[0x1F];
    s8 field_0x30;
    u8 pad_0x31[0x1F];
    s8 field_0x50;
    u8 pad_0x51[0x1F];
    s32 field_0x70;
    s32 field_0x74;
    s32 field_0x78;
    s32 field_0x7C;
    u8 pad_0x80[0x8];
    s8 field_0x88;
    u8 pad_0x89[0x7FF];
    s32 field_0x888;
    s32 field_0x88C;
    s32 field_0x890;
    s32 field_0x894;
    s32 field_0x898;
    s32 field_0x89C;
    s32 field_0x8A0;
    s32 field_0x8A4;
    s32 field_0x8A8;
    s32 field_0x8AC;

    void Clear(void);
    void Initialize(void);
};

#endif /* GEN_DBGCJISFONT_HPP */
