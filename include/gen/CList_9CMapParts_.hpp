#ifndef GEN_CLIST_9CMAPPARTS__HPP
#define GEN_CLIST_9CMAPPARTS__HPP

#include "common.h"

/* Déclaration engendrée par `scripts/diff/petites.py`.
 * Seuls les champs qu'un accesseur touche sont connus ; leur nom dit
 * leur décalage, faute de mieux, et le reste est du remplissage. Ni
 * la taille de la classe ni ses méthodes virtuelles n'y paraissent :
 * déclarer une virtuelle ferait émettre une table que le disque
 * porte déjà. */
struct CList_9CMapParts_ {
    s32 field_0x0;
    s32 field_0x4;
    u8 pad_0x8[0x8];
    s32 field_0x10;

    void * pGetData(void);
    void Initialize(void);
};

#endif /* GEN_CLIST_9CMAPPARTS__HPP */
