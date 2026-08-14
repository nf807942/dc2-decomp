#ifndef GAMEDATAUSED_HPP
#define GAMEDATAUSED_HPP

#include "types.h"

/* Arrondit un flottant vers le haut pour l'afficher : la partie fractionnaire
 * au-delà de 1e-5 fait monter d'une unité. Rend un entier. */
int GetDispVolumeForFloat(float value);

/* Une jauge : un plafond et ce qui est acquis. `GetRate` rend le rapport du
 * second au premier, `CheckFill` les dit égaux, `AddPoint` ajoute au second sans
 * dépasser le premier, `SetFillRate` pose le second à une fraction du premier. */
struct COMMON_GAGE {
    float max;
    float point;
};

/* Un objet que le joueur porte. Le genre en tête dit lequel — 3 pour ceux dont
 * `GetLevel` rend le niveau à 0x20, 2 pour ceux qui le portent à 0x28 —, et la
 * disposition n'est établie que sur les champs déjà lus. */
class CGameDataUsed {
public:
    int IsLevelUp();
    /* Le mangling les range dans la classe : `AddFusionPoint__13CGameDataUsedFi`
     * est `CGameDataUsed::AddFusionPoint(int)`, non une fonction libre. */
    void AddFusionPoint(int points);
    void LevelUp();
    int IsFishingRod();

    /* Le genre de l'objet. `GetLevel`, `IsLevelUp` et leurs pareilles s'y
     * réfèrent avant tout autre champ. */
    s16 kind;
    s16 unknown_02;
    /* Éprouvé contre 0xD et 0xF par `IsBroken`, `GetWHp` et `Repair`, qui en
     * tirent laquelle des deux jauges vaut pour l'objet. */
    s8 unknown_04;
    u8 unknown_05[0x0B];
    /* La durabilité : `Repair` y ajoute des points, `IsRepair` dit l'objet
     * entamé quand ce qui reste, arrondi comme l'affichage le montre, tombe
     * sous le plafond, et `LevelUp` relève ce plafond. */
    COMMON_GAGE durability;
    /* L'expérience vers le niveau suivant : le plafond est ce qu'il faut, le
     * point ce qui est acquis. C'est celle que `MenuPosFormValueSetWeapon`
     * affiche à côté de la durabilité, en passant `&this->durability + 1` à
     * `GetRate`. */
    COMMON_GAGE experience;
    /* Le niveau des objets de genre 3, borné à 99. */
    s16 level;
    /* Les dix caractéristiques que l'écran de mise au point recopie depuis la
     * table des armes, cinq par cinq. */
    s16 status[10];   /* 0x22 */
    u8 unknown_36[2];
    /* Les attributs de l'arme, un bit chacun. */
    u32 attribute;    /* 0x38 */
};

#endif /* GAMEDATAUSED_HPP */
