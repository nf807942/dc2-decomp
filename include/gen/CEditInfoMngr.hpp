#ifndef GEN_CEDITINFOMNGR_HPP
#define GEN_CEDITINFOMNGR_HPP

#include "common.h"

struct CEditPartsInfo;
struct ePlaceData;

/* Déclaration engendrée par `scripts/diff/petites.py`.
 * Seuls les champs qu'un accesseur touche sont connus ; leur nom dit
 * leur décalage, faute de mieux, et le reste est du remplissage. Ni
 * la taille de la classe ni ses méthodes virtuelles n'y paraissent :
 * déclarer une virtuelle ferait émettre une table que le disque
 * porte déjà. */
struct CEditInfoMngr {
    s32 field_0x0;
    CEditPartsInfo * field_0x4;
    s32 field_0x8;
    ePlaceData * field_0xC;
    s32 field_0x10;
    s32 field_0x14;

    void Initialize(void);
    void SeteFixPartsTable(ePlaceData * arg0, s32 arg1);
    void SetePartsInfoTable(CEditPartsInfo * arg0, s32 arg1);
};

#endif /* GEN_CEDITINFOMNGR_HPP */
