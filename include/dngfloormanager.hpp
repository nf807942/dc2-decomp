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
    u8 unknown_09[0x1B];
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
    u8 unknown_4E[0x22];
};

/* L'état de donjon que la sauvegarde porte : son premier mot indexe le tableau
 * qui suit. Les noms sont déduits de ce seul usage, et la longueur du tableau
 * reste à établir. */
struct SaveDataDungeon {
    int current;
    int floors[1];
};

/* `menu_GetSaveDataDungeon` rend l'aire de donjon dans la sauvegarde —
 * `GetSaveData()` décalé de 0x1C5B4 —, et zéro quand aucune sauvegarde n'est
 * chargée. */
SaveDataDungeon *menu_GetSaveDataDungeon(void);

class CDngFloorManager {
public:
    void Initialize();
    DngMapFloorGlidInfo *GetDngMapFloorGlidInfo(int floor);
    DngMapFloorInfo *GetDngMapFloorInfo(int floor);
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
