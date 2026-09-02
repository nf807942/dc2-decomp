#ifndef GEN_CMAPPIECE_HPP
#define GEN_CMAPPIECE_HPP

#include "common.h"

struct PieceMaterial;

/* Déclaration engendrée par `scripts/diff/petites.py`.
 * Seuls les champs qu'un accesseur touche sont connus ; leur nom dit
 * leur décalage, faute de mieux, et le reste est du remplissage. Ni
 * la taille de la classe ni ses méthodes virtuelles n'y paraissent :
 * déclarer une virtuelle ferait émettre une table que le disque
 * porte déjà. */
struct CMapPiece {
    u8 pad_0x0[0x80];
    char * field_0x80;
    u8 pad_0x84[0x8];
    s32 field_0x8C;
    PieceMaterial * field_0x90;
    f32 field_0x94;
    f32 field_0x98;

    void SetMaterial(PieceMaterial * arg0, s32 arg1);
    void SetName(char * arg0);
    void SetTimeBand(f32 arg0, f32 arg1);
};

#endif /* GEN_CMAPPIECE_HPP */
