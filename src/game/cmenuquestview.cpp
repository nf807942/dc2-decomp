/* CMenuQuestView, CShopMenu
 *
 * Unité découpée par `make carve` : 9 fonctions, 5852 octets, de
 * 0x00297F10 à 0x00299620. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

INCLUDE_ASM("nonmatchings/game/cmenuquestview", SearchNowPosItemExist__9CShopMenuFv);
INCLUDE_ASM("nonmatchings/game/cmenuquestview", ShopSellListDraw__FRiPf);
INCLUDE_ASM("nonmatchings/game/cmenuquestview", MenuShopInit__FP9mgCMemoryPii);
extern "C" void KeyStep__9CShopMenuFv(void *);
extern "C" void *CShopMenuPt;
extern "C" void MenuShopKey__Fv(void) {
    KeyStep__9CShopMenuFv(CShopMenuPt);
}
struct CPosDataManage;
extern "C" void FormDraw__14CPosDataManageFv(void *);
extern "C" CPosDataManage *MenuPosData;
extern "C" void MenuShopDraw__Fv(void) {
    FormDraw__14CPosDataManageFv(MenuPosData);
}
INCLUDE_ASM("nonmatchings/game/cmenuquestview", UnderMsg__14CMenuQuestViewFi);
INCLUDE_ASM("nonmatchings/game/cmenuquestview", SelectMax__14CMenuQuestViewFv);
INCLUDE_ASM("nonmatchings/game/cmenuquestview", InitEnd__14CMenuQuestViewFv);
INCLUDE_ASM("nonmatchings/game/cmenuquestview", KeyStep__14CMenuQuestViewFv);
