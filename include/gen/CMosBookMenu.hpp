#ifndef GEN_CMOSBOOKMENU_HPP
#define GEN_CMOSBOOKMENU_HPP

#include "common.h"

/* Déclaration engendrée par `scripts/diff/petites.py`.
 * Seuls les champs qu'un accesseur touche sont connus ; leur nom dit
 * leur décalage, faute de mieux, et le reste est du remplissage. Ni
 * la taille de la classe ni ses méthodes virtuelles n'y paraissent :
 * déclarer une virtuelle ferait émettre une table que le disque
 * porte déjà. */
struct CMosBookMenu {
    u8 pad_0x0[0x7EC];
    s8 field_0x7EC;
    u8 pad_0x7ED[0x3F];
    s8 field_0x82C;
    u8 pad_0x82D[0x3F];
    s8 field_0x86C;
    u8 pad_0x86D[0x3F];
    s8 field_0x8AC;
    u8 pad_0x8AD[0x57];
    s32 field_0x904;
    s32 field_0x908;
    s32 field_0x90C;
    s32 field_0x910;
    s32 field_0x914;
    s8 field_0x918;
    u8 pad_0x919[0x20];
    s8 field_0x939;
    u8 pad_0x93A[0x20];
    s8 field_0x95A;

    void InitMonsterInfo(void);
};

#endif /* GEN_CMOSBOOKMENU_HPP */
