#ifndef DNGFLOORMANAGER_HPP
#define DNGFLOORMANAGER_HPP

#include "types.h"

/* Ce qu'un étage de donjon porte, tel que les prix de Spheda le lisent : trois
 * prix sur seize bits signés à 0x24, et trois comptes sur huit bits signés à
 * 0x2A. Le reste de la structure n'est pas encore établi, d'où le tampon de
 * tête, dimensionné sur le seul décalage connu. */
struct DngMapFloorInfo {
    u8 unknown_00[8];
    /* Le numéro d'étage, sur huit bits signés : c'est à lui que la recherche
     * compare celui qu'on demande. */
    s8 floor;
    u8 unknown_09[7];
    /* Le temps sous lequel l'étage compte pour vaincu au plus vite. */
    int targetTime;
    /* Ce que l'étage scelle : `IsSealFloor` le rend, à condition que l'équipe
     * porte le membre voulu — 1 exige le bit 2, 2 exige le bit 1. */
    s8 seal;
    /* Les deux sous-jeux que l'étage propose. `IsPlaySubGame` les rend en un
     * masque : celui-ci en bit 0x1, le suivant en bit 0x2. */
    s8 subGame0;
    /* Vrai quand l'étage porte une géo-pierre : `IsGeoStone` ne fait que le
     * rendre. Huit bits signés, comme le `lb` qui le lit. */
    s8 geoStone;
    s8 subGame1;
    u8 unknown_18[2];
    /* Le genre de la condition d'entraînement que l'étage porte, de 0 à 6 ;
     * `IsClearPractice` en fait l'indice de sa table de saut. Négatif quand
     * l'étage n'en porte aucune, ce que le `bgez` qui le lit tranche. */
    s8 practiceKind;
    u8 unknown_1B;
    /* Le paramètre de cette condition. Son sens dépend du genre : une borne à
     * ne pas dépasser pour le genre 0, un membre d'équipe pour les genres 1 à
     * 4 — c'est de lui que viennent le bit `1 << practiceParam` et la ligne de
     * `cbit_1158`. */
    int practiceParam;
    u8 unknown_20[4];
    s16 sphedaPrize[3];
    s8 sphedaCount[3];
};

/* L'étage tel que le fichier le range : un en-tête de 0x20 octets, puis
 * l'information d'étage elle-même — c'est ce décalage que
 * `GetDngMapFloorInfo` ajoute. */
struct DngMapFloorGlidInfo {
    /* La recherche ne retient que les entrées dont ce champ vaut un. */
    s16 kind;
    u8 unknown_02[0x1E];
    DngMapFloorInfo info;
    /* L'entrée fait 0x70 octets — le pas que la recherche ajoute à chaque
     * tour —, et l'information d'étage s'y aligne sur quatre à cause de son
     * temps objectif. Ce qui suit comble donc jusqu'à 0x70. */
    u8 unknown_50[0x20];
};

/* Ce que la sauvegarde retient d'un étage. Seul le mot à 0xE est établi : un
 * masque de drapeaux, dont le bit 0x400 lève le scellé. */
struct DngFloorSaveInfo {
    u8 unknown_00[4];
    /* Le meilleur temps déjà réalisé sur l'étage, ou zéro s'il n'y en a pas. */
    int bestTime;
    u8 unknown_08[6];
    u16 flags;
};

/* Le bit du masque de drapeaux qui lève le scellé d'un étage. */
#define DNG_FLOOR_SEAL_OPENED 0x400

/* Le bit qui retient qu'une condition d'entraînement a déjà été remplie sur
 * l'étage : `IsClearPractice` le pose et s'en sert pour distinguer la première
 * réussite des suivantes. */
#define DNG_FLOOR_PRACTICE_DONE 0x8

/* L'état de donjon que la sauvegarde porte : son premier mot indexe le tableau
 * qui suit. Les noms sont déduits de ce seul usage, et la longueur du tableau
 * reste à établir. */
class CSaveDataDungeon {
public:
    DngFloorSaveInfo *GetFloorInfoPtr(int dungeon, int floor);

    int current;
    int floors[1];
};

/* Ce que le jeu sait de la partie en cours. `GetNowPartyMember` rend un masque
 * des membres présents ; les étages scellés s'y rapportent. */
class CUserDataManager {
public:
    int GetNowPartyMember();
    void AddYarikomiMedal(int count);
};

/* La scène de combat en cours ; le temps y est compté depuis l'entrée. Les
 * trois membres que `IsClearPractice` consulte n'ont que cet usage établi. */
class CBattleAreaScene {
public:
    u8 unknown_00[0x10];
    /* Ce que la condition de genre 0 compare à son paramètre. */
    int unknown_10;
    u8 unknown_14[0x48];
    /* Les conditions des genres 0 à 4 ne comptent que s'il est non nul. */
    int unknown_5C;
    u8 unknown_60[0x30];
    int startTime;
    u8 unknown_94[4];
    /* Un masque, éprouvé bit à bit contre `check_bittable_1123` et
     * `cbit_1158`, et contre `1 << practiceParam`. */
    int unknown_98;
};

/* La sauvegarde entière. L'aire de donjon y est un membre, à 0x1C5B4 — c'est
 * ce que `menu_GetSaveDataDungeon` rend une fois la sauvegarde chargée. */
class CSaveData {
public:
    u8 unknown_0000[0x1A00];
    int now;
    u8 unknown_1A04[0x1C5B4 - 0x1A04];
    CSaveDataDungeon dungeon;
};

CBattleAreaScene *menu_GetBattleAreaScene(void);
CSaveData *GetSaveData(void);

CUserDataManager *GetUserDataMan(void);

/* `menu_GetSaveDataDungeon` rend l'aire de donjon dans la sauvegarde —
 * `GetSaveData()` décalé de 0x1C5B4 —, et zéro quand aucune sauvegarde n'est
 * chargée. */
CSaveDataDungeon *menu_GetSaveDataDungeon(void);

class CDngFloorManager {
public:
    void Initialize();
    DngMapFloorGlidInfo *GetDngMapFloorGlidInfo(int floor);
    DngMapFloorInfo *GetDngMapFloorInfo(int floor);
    int IsGeoStone(int floor);
    int IsPlaySubGame();
    int IsSealFloor(int floor);
    DngMapFloorInfo *GetActiveFloorInfo();
    int IsClearMostFastDestroy();
    int IsClearPractice(int difficulty);
    /* L'étage se donne explicitement. */
    int GetSphedaPrize(int floor, int index, int *prize, int *count);
    /* L'étage vient de la sauvegarde. */
    int GetSphedaPrize(int index, int *prize, int *count);

    /* La largeur de chaque membre vient de `Initialize`, qui les met tous à
     * zéro : un octet, deux mots, puis deux demi-mots. `loaded` est le seul
     * dont l'usage soit établi — `GetDngMapFloorInfo` s'y refuse quand il est
     * nul, avant même de chercher l'étage. */
    u8 unknown_00;
    DngMapFloorGlidInfo *table;
    int count;
    u16 unknown_0C;
    u16 unknown_0E;
};

#endif /* DNGFLOORMANAGER_HPP */
