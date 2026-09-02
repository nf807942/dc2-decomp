#ifndef GEN_CCOLPRIM_HPP
#define GEN_CCOLPRIM_HPP

#include "common.h"

/* Déclaration engendrée par `scripts/diff/petites.py`.
 * Seuls les champs qu'un accesseur touche sont connus ; leur nom dit
 * leur décalage, faute de mieux, et le reste est du remplissage. Ni
 * la taille de la classe ni ses méthodes virtuelles n'y paraissent :
 * déclarer une virtuelle ferait émettre une table que le disque
 * porte déjà. */
struct CColPrim {
    u8 pad_0x0[0xC];
    s32 field_0xC;
    s32 field_0x10;
    u8 pad_0x14[0x4];
    s64 field_0x18;
    s32 field_0x20;
    s32 field_0x24;
    s32 field_0x28;
    u8 pad_0x2C[0x8];
    s32 field_0x34;
    s32 field_0x38;
    s32 field_0x3C;
    u8 pad_0x40[0x44];
    s32 field_0x84;
    u8 pad_0x88[0x4];
    s32 field_0x8C;
    u8 pad_0x90[0x30];
    s8 field_0xC0;
    u8 pad_0xC1[0x25];
    s8 field_0xE6;

    void DebugDraw(void);
    void Initialize(void);
};

#endif /* GEN_CCOLPRIM_HPP */
