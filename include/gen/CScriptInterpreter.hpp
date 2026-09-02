#ifndef GEN_CSCRIPTINTERPRETER_HPP
#define GEN_CSCRIPTINTERPRETER_HPP

#include "common.h"

struct SPI_STACK;

/* Déclaration engendrée par `scripts/diff/petites.py`.
 * Seuls les champs qu'un accesseur touche sont connus ; leur nom dit
 * leur décalage, faute de mieux, et le reste est du remplissage. Ni
 * la taille de la classe ni ses méthodes virtuelles n'y paraissent :
 * déclarer une virtuelle ferait émettre une table que le disque
 * porte déjà. */
struct CScriptInterpreter {
    u8 pad_0x0[0xC];
    s32 field_0xC;
    s32 field_0x10;
    SPI_STACK * field_0x14;
    s32 field_0x18;
    char * field_0x1C;
    char * field_0x20;

    void SetStack(SPI_STACK * arg0, s32 arg1);
    void SetStringBuff(char * arg0, s32 arg1);
};

#endif /* GEN_CSCRIPTINTERPRETER_HPP */
