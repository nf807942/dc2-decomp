#ifndef SAVEDATA_HPP
#define SAVEDATA_HPP

#include "types.h"

/* Ce que `CUserDataManager::GetMonsterBajjiDataPtrMosId` rend pour un monstre :
 * seul l'octet que `_SET_SAVEDATA_ETC` y pose est établi. Il est mis à un
 * lorsque le script déclare le monstre recruté. */
struct MONSTER_BAJJI_DATA {
    u8 unknown_00[0xA];
    s8 unknown_0A;  /* 0xA */
};

/* Les données du joueur, à 0x1D2A0 de la sauvegarde. Sa taille n'est pas
 * établie, donc elle ne s'y déclare pas comme champ. */
class CUserDataManager {
public:
    MONSTER_BAJJI_DATA *GetMonsterBajjiDataPtrMosId(s32 mosId);
    void AllWeaponRepair();
};

/* La sauvegarde entière, telle que `GetSaveData` la rend. Seuls les champs que
 * les commandes de script atteignent sont déclarés ; ce qu'ils désignent reste
 * à établir. */
class CSaveData {
public:
    s32 GetTourCountEtc();

    u8 unknown_00000[0x1A08];
    s32 unknown_1A08;  /* 0x1A08 */
    u8 unknown_01A0C[0x643C9 - 0x1A0C];
    s8 unknown_643C9;  /* 0x643C9 */
};

/* L'emplacement du gestionnaire de données du joueur dans la sauvegarde. Il ne
 * peut pas être un champ de `CSaveData`, la taille de sa classe n'étant pas
 * établie et un champ que le binaire place après lui l'étant, elle. */
#define SAVE_USER_DATA_OFFSET 0x1D2A0

CSaveData *GetSaveData(void);

#endif /* SAVEDATA_HPP */
