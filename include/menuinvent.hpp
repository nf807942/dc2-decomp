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

/* Un panneau de menu, avec le script qui l'anime. `SetAction` lui donne la
 * suite à jouer, désignée par son nom. */
class CMenuPosDataForm {
public:
    void SetAction(char *action);
};

/* Les neuf panneaux de message que les menus se partagent. Le binaire leur
 * donne 0x24 octets en 0x01EFBB30, et `NextDifferentMode` n'atteint que le
 * premier. C'est cette taille qui décide de l'adressage : au-delà du seuil des
 * petites données, MWCC passe par `%hi`/`%lo` et non par `$gp`. */
extern CMenuPosDataForm *MenuMesForm[9];

/* Ce que tous les menus ont en commun, atteint par un pointeur que `$gp`
 * adresse. Seul le demi-mot que `NextDifferentMode` consulte est établi : il
 * décide si le passage au mode 2 est permis. */
struct MENU_COMMON_INFO {
    u8 unknown_00[0xC2];
    s16 unknown_C2;
};

extern MENU_COMMON_INFO *MenuCommonInfo;

void MenuSePlay(int se);

/* La base de tous les menus. Elle exécute les scripts qui les animent, chacun
 * désigné par son nom — en japonais dans le binaire.
 *
 * Sa taille n'est pas établie : les tampons la portent jusqu'au premier champ
 * que `CMenuInvent` expose, ce qui suffit à placer ceux-là et ne prétend rien
 * de ce qu'ils recouvrent. */
class CBaseMenuClass {
public:
    void ExeScript(char *script);

    u8 unknown_00[0x14];
    /* Le mode courant du menu, que `NextDifferentMode` relit avant de le
     * remplacer. */
    s16 mode;
    u8 unknown_16[0x114 - 0x16];
};

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
