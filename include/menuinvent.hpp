#ifndef MENUINVENT_HPP
#define MENUINVENT_HPP

#include "types.h"
#include "menu.hpp"

/* L'état de menu que la sauvegarde retient d'une session à l'autre :
 * `GetMenuSysData` le rend, à 0x640C0 de la sauvegarde. Seuls les champs
 * qu'`ExitEnd` y recopie sont établis, tous sur seize bits. */
struct MENU_SYS_DATA {
    u8 unknown_00[0x20];
    s16 unknown_20;
    s16 unknown_22;
    u8 unknown_24[0x0A];
    s16 unknown_2E;
    s16 unknown_30;
    s16 unknown_32;
    s16 unknown_34;
    s16 unknown_36;
    s16 unknown_38;
    s16 unknown_3A;
    s16 unknown_3C;
    s16 unknown_3E;
};

MENU_SYS_DATA *GetMenuSysData(void);

/* Ce que la partie retient du menu d'invention : les photos prises, les idées
 * trouvées. `PhotoCheckEnd` clôt la vérification des photos. */
class CInventUserData {
public:
    void PhotoCheckEnd();
};

extern CInventUserData *InventUserDataPtr;

/* Le menu d'invention. Les dix champs déclarés sont ceux qu'`ExitEnd` reverse
 * dans la sauvegarde, plus un onzième bien plus loin. Ils tiennent sur trente
 * -deux bits : `NextDifferentMode` les lit et les écrit par mots entiers, et le
 * produit qu'elle range en 0x11C déborde le demi-mot. `ExitEnd`, qui n'en garde
 * que la moitié basse, ne pouvait pas trancher.
 *
 * Ce que chacun désigne reste à établir. */
class CMenuInvent : public CBaseMenuClass {
public:
    void ExitEnd();
    void CreateModeSwapForm(int side);
    void NextDifferentMode(int next, int arg);

    s32 unknown_114;
    s32 unknown_118;
    s32 unknown_11C;
    s32 unknown_120;
    s32 unknown_124;
    s32 unknown_128;
    s32 unknown_12C;
    s32 unknown_130;
    s32 unknown_134;
    s32 unknown_138;
    u8 unknown_13C[0x392 - 0x13C];
    s16 unknown_392;
};

#endif /* MENUINVENT_HPP */
