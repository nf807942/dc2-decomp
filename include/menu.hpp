#ifndef MENU_HPP
#define MENU_HPP

#include "types.h"

/* Ce que les menus se partagent : les classes que plusieurs unités atteignent,
 * et les objets globaux qui les portent. Chaque champ déclaré l'est parce
 * qu'une fonction reconstruite l'atteint ; le reste est du remplissage nommé
 * par son décalage. */

/* Un allocateur du middleware, tel que le binaire le dimensionne : 0x30 octets.
 * Les menus en tiennent plusieurs, chacun pour une sorte de contenu. */
class mgCMemory {
public:
    u8 unknown_00[0x1C];
    u32 unknown_1C;  /* 0x1C */
    u8 *unknown_20;  /* 0x20 */
    u32 unknown_24;  /* 0x24 */
    u8 unknown_28[0x30 - 0x28];
};

/* Un personnage animé, que les panneaux de menu affichent. */
class CActionChara;

/* Un panneau de menu, avec le script qui l'anime et le personnage qu'il
 * montre. */
class CMenuPosDataForm {
public:
    void SetAction(char *action);
    void SetActionCharaPtr(CActionChara *chara, int a, int b);
};

/* Le gestionnaire des panneaux : leur pas d'animation, leur liste d'affichage,
 * et le rattachement d'un panneau à un autre. */
class CPosDataManage {
public:
    void FormStep();
    void InitDrawList();
    void FormReLink(char *form, char *target);
};

/* Ce que tous les menus ont en commun, atteint par un pointeur que `$gp`
 * adresse. Seuls les deux champs que les fonctions reconstruites emploient
 * sont établis. */
class CMenuKeyFunc {
public:
    void SetWakuType(int type);

    u8 unknown_00[0xC2];
    s16 unknown_C2;  /* 0xC2 */
};

/* Les messages du jeu, et le tampon dans lequel ils sont composés. */
class CDC2Mes {
public:
    void SetMessData(s16 *system, s16 *main);

    u8 unknown_0000[0x2958];
    s8 unknown_2958;  /* 0x2958 */
};

/* Le panneau des objets qu'on déplace. */
class CMenuMoveItem {
public:
    void AttachForm();
};

/* La base de tous les menus. Elle exécute les scripts qui les animent, chacun
 * désigné par son nom — en japonais dans le binaire —, et porte le fondu
 * d'entrée comme la libération des textures.
 *
 * Sa taille est établie : 0x114 octets, le premier champ propre de
 * `CMenuInvent` comme de `CMenuItemInfo` s'y trouvant. */
class CBaseMenuClass {
public:
    void ExeScript(char *script);
    s32 FadeCheckMenu();
    void DeleteTexBlock();
    void FadeInMenu(int frames, f32 rate);

    s16 unknown_00;  /* 0x00 */
    u8 unknown_02[0x14 - 0x02];
    /* Le mode courant du menu, que `CMenuInvent::NextDifferentMode` relit
     * avant de le remplacer. */
    s16 mode;        /* 0x14 */
    u8 unknown_16[0x18 - 0x16];
    /* Les données que chaque mode reçoit à son initialisation ; les commandes
     * en prennent l'adresse. */
    u32 unknown_18;  /* 0x18 */
    u8 unknown_1C[0x110 - 0x1C];
    s16 unknown_110; /* 0x110 */
    s16 unknown_112; /* 0x112 */
};

/* Les neuf panneaux de message que les menus se partagent. Le binaire leur
 * donne 0x24 octets, et les fonctions reconstruites n'atteignent que le
 * premier. C'est cette taille qui décide de l'adressage : au-delà du seuil des
 * petites données, MWCC passe par `%hi`/`%lo` et non par `$gp`. */
extern CMenuPosDataForm *MenuMesForm[9];

extern CMenuKeyFunc *MenuCommonInfo;
extern CPosDataManage *MenuPosData;
extern CMenuMoveItem *MenuMoveItemPtr;
extern CDC2Mes *MenuDCMsg[9];

void MenuSePlay(int se);

#endif /* MENU_HPP */
