#ifndef GEN_CSCENECMRSEQ_HPP
#define GEN_CSCENECMRSEQ_HPP

#include "common.h"

struct _SEN_CMR_SEQ;

/* Déclaration engendrée par `scripts/diff/petites.py`.
 * Seuls les champs qu'un accesseur touche sont connus ; leur nom dit
 * leur décalage, faute de mieux, et le reste est du remplissage. Ni
 * la taille de la classe ni ses méthodes virtuelles n'y paraissent :
 * déclarer une virtuelle ferait émettre une table que le disque
 * porte déjà. */
struct CSceneCmrSeq {
    u8 pad_0x0[0x30];
    _SEN_CMR_SEQ * field_0x30;
    _SEN_CMR_SEQ * field_0x34;
};

#endif /* GEN_CSCENECMRSEQ_HPP */
