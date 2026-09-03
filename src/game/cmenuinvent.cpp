/* CMenuInvent
 *
 * Unité découpée par `make carve` : 3 fonctions, 5980 octets, de
 * 0x00203E90 à 0x00205600. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

INCLUDE_ASM("nonmatchings/game/cmenuinvent", IsCreateObject__11CMenuInventFii);
INCLUDE_ASM("nonmatchings/game/cmenuinvent", CalcMakeBrd__11CMenuInventFi);
#include "menuinvent.hpp"
extern "C" s32 GetHatsumeiNum__15CInventUserDataFv(void *);
extern "C" s32 EnableSelectMaxCardList__11CMenuInventFv(CMenuInvent *objet) {
    s32 var_v0;

    var_v0 = GetHatsumeiNum__15CInventUserDataFv(InventUserDataPtr) + 1;
    if (var_v0 < 5) {
        var_v0 = 5;
    }
    return var_v0;
}
