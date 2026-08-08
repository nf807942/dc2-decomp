/* Deux commandes de l'interpréteur de script : celle qui interroge la course
 * de poissons et l'aquarium, celle qui écrit dans la sauvegarde.
 *
 * Unité découpée par `make carve` : 2 fonctions, 728 octets, de
 * 0x0026DAA0 à 0x0026DD80. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"
#include "runscript.hpp"
#include "savedata.hpp"

/* Le binaire porte quatre `GetStackInt` et quatre `SetStack`, statiques, une
 * paire par unité de traduction d'origine ; le désassembleur les départage par
 * leur adresse, et c'est ce nom-là que l'appel doit porter. Le raccourci ne
 * vaut donc que pour cette unité : une autre appellerait une autre copie. */
extern "C" s32 GetStackInt__FP12RS_STACKDATA_00262DA0(RS_STACKDATA *stack);
extern "C" void SetStack__FP12RS_STACKDATAi_00262E70(RS_STACKDATA *stack,
                                                     s32 value);
#define GetStackInt GetStackInt__FP12RS_STACKDATA_00262DA0
#define SetStack SetStack__FP12RS_STACKDATAi_00262E70

/* Ce que `GetFishPrize` rend d'un prix de course : deux mots que la commande
 * reverse tels quels sur la pile du script. */
struct FISH_PRIZE_INFO {
    s32 unknown_00;
    s32 unknown_04;
};

s32 GetGyoRaceAquariumNo(void);
s32 GetGyoRaceRanking(void);
s32 GetGyoRaceClass(void);
s32 GetGyoRaceNo(void);
s32 GetFishPrize(s32 raceNo, s32 rank, FISH_PRIZE_INFO *info);
void DeleteErekiFish(void);

/* La commande qui interroge la course de poissons. Le premier argument dit
 * laquelle des six questions est posée, et la réponse est reversée sur la pile
 * à la case suivante. Le prix d'une course en rend deux, et le classement
 * demandé part de un quand la fonction interne compte de zéro.
 *
 * La commande rend un quand elle a répondu, zéro sinon. */
s32 _GET_GYORACE_ETC(RS_STACKDATA *stack, int argc) {
    FISH_PRIZE_INFO info;
    s32 raceNo;

    switch (GetStackInt(stack++)) {
    case 0:
        SetStack(stack++, GetGyoRaceAquariumNo());
        break;
    case 1:
        SetStack(stack++, GetGyoRaceRanking());
        break;
    case 2:
        SetStack(stack++, GetGyoRaceClass());
        break;
    case 3:
        SetStack(stack++, GetGyoRaceNo());
        break;
    case 4:
        raceNo = GetStackInt(stack++);
        if (!GetFishPrize(raceNo, GetStackInt(stack++) - 1, &info)) {
            return 0;
        }
        SetStack(stack++, info.unknown_00);
        SetStack(stack++, info.unknown_04);
        break;
    case 5: {
        CSaveData *save = GetSaveData();
        if (save == NULL) {
            return 0;
        }
        SetStack(stack++, save->GetTourCountEtc());
        break;
    }
    default:
        return 0;
    }
    return 1;
}

/* La commande qui écrit dans la sauvegarde. Le premier argument dit laquelle
 * des cinq écritures est demandée : le numéro que le script y range, le
 * recrutement d'un monstre, la réparation de toutes les armes, un octet bien
 * plus loin dans la sauvegarde, et la suppression du poisson électrique.
 *
 * Chacune renonce et rend zéro si la sauvegarde n'est pas là. */
s32 _SET_SAVEDATA_ETC(RS_STACKDATA *stack, int argc) {
    CSaveData *save;
    CUserDataManager *user;
    MONSTER_BAJJI_DATA *bajji;

    switch (GetStackInt(stack++)) {
    case 0:
        save = GetSaveData();
        if (save == NULL) {
            return 0;
        }
        save->unknown_1A08 = GetStackInt(stack);
        break;
    case 1:
        save = GetSaveData();
        if (save == NULL) {
            return 0;
        }
        user = (CUserDataManager *)((u8 *)save + SAVE_USER_DATA_OFFSET);
        if (user == NULL) {
            return 0;
        }
        bajji = user->GetMonsterBajjiDataPtrMosId(GetStackInt(stack));
        if (bajji == NULL) {
            return 0;
        }
        bajji->unknown_0A = 1;
        break;
    case 2:
        save = GetSaveData();
        if (save == NULL) {
            return 0;
        }
        user = (CUserDataManager *)((u8 *)save + SAVE_USER_DATA_OFFSET);
        if (user == NULL) {
            return 0;
        }
        user->AllWeaponRepair();
        break;
    case 3:
        save = GetSaveData();
        if (save == NULL) {
            return 0;
        }
        save->unknown_643C9 = GetStackInt(stack);
        break;
    case 4:
        DeleteErekiFish();
        break;
    default:
        return 0;
    }
    return 1;
}
