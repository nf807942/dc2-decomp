#ifndef GEN_CEVENTSPRITE2_HPP
#define GEN_CEVENTSPRITE2_HPP

#include "common.h"

/* Déclaration engendrée par `scripts/diff/petites.py`.
 * Seuls les champs qu'un accesseur touche sont connus ; leur nom dit
 * leur décalage, faute de mieux, et le reste est du remplissage. Ni
 * la taille de la classe ni ses méthodes virtuelles n'y paraissent :
 * déclarer une virtuelle ferait émettre une table que le disque
 * porte déjà. */
struct CEventSprite2 {
    s32 field_0x0;
    s32 field_0x4;
    u8 pad_0x8[0x24];
    s32 field_0x2C;
    u8 pad_0x30[0x20];
    f32 field_0x50;
    s32 field_0x54;
    s32 field_0x58;
    u8 pad_0x5C[0x10];
    f32 field_0x6C;
    f32 field_0x70;

    f32 GetRotZ(void);
    s32 GetType(void);
    void SetAlphaBlend(s32 arg0);
    void SetDrawFlag(s32 arg0);
    void SetPutSize(s32 arg0, s32 arg1);
    void SetRotZ(f32 arg0);
    void SetScale(f32 arg0, f32 arg1);
    void SetSpriteType(s32 arg0);
};

#endif /* GEN_CEVENTSPRITE2_HPP */
