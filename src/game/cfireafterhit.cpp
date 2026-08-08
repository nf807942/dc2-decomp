/* CFireAfterHit, CChillAfterHit, CTornado
 *
 * Unité découpée par `make carve` : 19 fonctions, 16208 octets, de
 * 0x001BD800 à 0x001C17C0. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

INCLUDE_ASM("nonmatchings/game/cfireafterhit", DrawMainUnitStatusBord__Ff);
INCLUDE_ASM("nonmatchings/game/cfireafterhit", DrawRoboUnitStatusBord__Ff);
INCLUDE_ASM("nonmatchings/game/cfireafterhit", DrawMonsterUnitStatusBord__Ff);
INCLUDE_ASM("nonmatchings/game/cfireafterhit", DrawStatusBord__Fv);

float trans_effect_rate(int rate) {
    float f = (float)rate / 255.0f;
    if (1.0f < f) {
        f = 1.0f;
    }
    return f;
}
INCLUDE_ASM("nonmatchings/game/cfireafterhit", trans_float_to_sceVector__FPfPfi);
INCLUDE_ASM("nonmatchings/game/cfireafterhit", Initialize__14CChillAfterHitFv);
INCLUDE_ASM("nonmatchings/game/cfireafterhit", SetPos__14CChillAfterHitFPffi);
INCLUDE_ASM("nonmatchings/game/cfireafterhit", Step__14CChillAfterHitFv);
INCLUDE_ASM("nonmatchings/game/cfireafterhit", LocalTransWorldPrimPos__FPA4_iPffff);
INCLUDE_ASM("nonmatchings/game/cfireafterhit", Draw__14CChillAfterHitFv);
INCLUDE_ASM("nonmatchings/game/cfireafterhit", Initialize__13CFireAfterHitFv);
INCLUDE_ASM("nonmatchings/game/cfireafterhit", SetPos__13CFireAfterHitFPffi);
INCLUDE_ASM("nonmatchings/game/cfireafterhit", Step__13CFireAfterHitFv);
INCLUDE_ASM("nonmatchings/game/cfireafterhit", Draw__13CFireAfterHitFv);
INCLUDE_ASM("nonmatchings/game/cfireafterhit", SetPos__8CTornadoFPfff);
INCLUDE_ASM("nonmatchings/game/cfireafterhit", Draw__8CTornadoFv);
INCLUDE_ASM("nonmatchings/game/cfireafterhit", Step__8CTornadoFv);
INCLUDE_ASM("nonmatchings/game/cfireafterhit", Initialize__8CTornadoFv);
