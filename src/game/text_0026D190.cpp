/* Fonctions libres — à décrire.
 *
 * Unité découpée par `make carve` : 8 fonctions, 2268 octets, de
 * 0x0026D190 à 0x0026DAA0. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

#include "runscript.hpp"

struct RS_STACKDATA_pair { int a; int b; };
extern "C" int GetStackInt__FP12RS_STACKDATA_00262DA0(...);
extern "C" int CheckInventItem__Fi(int);
extern "C" void SetStack__FP12RS_STACKDATAi_00262E70(int, int);
extern "C" int _CHECK_INVENT_ITEM__FP12RS_STACKDATAi(RS_STACKDATA_pair *arg0, int arg1) {
    int value = CheckInventItem__Fi(GetStackInt__FP12RS_STACKDATA_00262DA0(arg0++));
    SetStack__FP12RS_STACKDATAi_00262E70((int)arg0, value);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_0026D190", _SET_AI__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_0026D190", _CHECK_INVENT_PHOTO__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_0026D190", _GET_PHOTO_NUM__FP12RS_STACKDATAi);
s32 _SET_CONTENTS_ETC(RS_STACKDATA *stack, int argc) {
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_0026D190", _SET_STATUS__FP12RS_STACKDATAi_0026D370);
INCLUDE_ASM("nonmatchings/game/text_0026D190", _GOTO_SUBGAME__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_0026D190", _SET_GYORACE_ETC__FP12RS_STACKDATAi);
