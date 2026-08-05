#ifndef MENUINVENT_HPP
#define MENUINVENT_HPP

#include "types.h"

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

/* La base de tous les menus. Elle exécute les scripts qui les animent, chacun
 * désigné par son nom — en japonais dans le binaire.
 *
 * Sa taille n'est pas établie : le tampon la porte jusqu'au premier champ que
 * `CMenuInvent` expose, ce qui suffit à placer ceux-là et ne prétend rien de
 * ce qu'il recouvre. */
class CBaseMenuClass {
public:
    void ExeScript(char *script);

    u8 unknown_00[0x114];
};

/* Le menu d'invention. Les champs déclarés sont ceux qu'`ExitEnd` reverse dans
 * la sauvegarde : dix demi-mots espacés de quatre octets, plus un onzième bien
 * plus loin. Ce que chacun désigne reste à établir — leur seul usage connu est
 * d'être rangés à la fermeture du menu. */
class CMenuInvent : public CBaseMenuClass {
public:
    void ExitEnd();

    s16 unknown_114;
    s16 unknown_116;
    s16 unknown_118;
    s16 unknown_11A;
    s16 unknown_11C;
    s16 unknown_11E;
    s16 unknown_120;
    s16 unknown_122;
    s16 unknown_124;
    s16 unknown_126;
    s16 unknown_128;
    s16 unknown_12A;
    s16 unknown_12C;
    s16 unknown_12E;
    s16 unknown_130;
    s16 unknown_132;
    s16 unknown_134;
    s16 unknown_136;
    s16 unknown_138;
    s16 unknown_13A;
    u8 unknown_13C[0x392 - 0x13C];
    s16 unknown_392;
};

#endif /* MENUINVENT_HPP */
