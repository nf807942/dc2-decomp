/* CDngFloorManager — les étages d'un donjon.
 *
 * Unité bornée aux deux surcharges de `GetSphedaPrize` : la classe est
 * entrecoupée par onze fonctions d'ailleurs, donc sa plage entière porterait
 * plusieurs unités de traduction.
 */

#include "common.h"
#include "dngfloormanager.hpp"

/* L'entrée de l'étage demandé, cherchée parmi celles que le fichier a
 * chargées. Une entrée ne compte que si son genre vaut un.
 *
 * L'entrée courante est tenue à part de l'indice : le compilateur en fait un
 * pointeur qu'il rétablit à chaque tour depuis le décalage, et recalcule
 * l'adresse une seconde fois pour la rendre. */
DngMapFloorGlidInfo *CDngFloorManager::GetDngMapFloorGlidInfo(int floor) {
    int i;
    /* L'indice est mis à zéro dans la condition même : le compilateur le tient
     * alors pour disponible avant le branchement et le loge dans son créneau de
     * délai, là où une initialisation placée après lui coûte un `nop`. */
    if (this->table == NULL || (i = 0, this->count) <= 0) {
        return NULL;
    }
    for (; i < this->count; i++) {
        if (this->table[i].kind == 1 && floor == this->table[i].info.floor) {
            return &this->table[i];
        }
    }
    return NULL;
}

/* L'étage porte-t-il une géo-pierre ? L'étage absent en est dépourvu. */
int CDngFloorManager::IsGeoStone(int floor) {
    DngMapFloorInfo *info = GetDngMapFloorInfo(floor);
    if (info != NULL) {
        return info->geoStone;
    }
    return 0;
}

/* Le prix de Spheda d'un étage, et le nombre de coups qu'il accorde. L'étage
 * en porte trois de chaque ; un indice au-delà retombe sur le dernier, et un
 * indice négatif est refusé. Chacune des deux sorties est facultative. */
int CDngFloorManager::GetSphedaPrize(int floor, int index, int *prize, int *count) {
    DngMapFloorInfo *info = GetDngMapFloorInfo(floor);
    if (info == NULL) {
        return 0;
    }
    if (index < 0) {
        return 0;
    }
    if (index >= 3) {
        index = 2;
    }
    if (prize != NULL) {
        *prize = info->sphedaPrize[index];
    }
    if (count != NULL) {
        *count = info->sphedaCount[index];
    }
    return 1;
}

/* Le prix de Spheda pour l'étage où la partie en cours se trouve. La surcharge
 * qui prend l'étage fait le reste ; celle-ci ne résout que l'étage. */
int CDngFloorManager::GetSphedaPrize(int index, int *prize, int *count) {
    CSaveDataDungeon *dungeon = menu_GetSaveDataDungeon();
    if (dungeon == NULL) {
        return 0;
    }
    return GetSphedaPrize(dungeon->floors[dungeon->current], index, prize, count);
}

/* Les sous-jeux que l'étage courant propose, en un masque de deux bits. */
int CDngFloorManager::IsPlaySubGame() {
    int games = 0;
    DngMapFloorInfo *info = GetActiveFloorInfo();
    if (info == NULL) {
        return 0;
    }
    if (info->subGame1 != 0) {
        games |= 2;
    }
    if (info->subGame0 != 0) {
        games |= 1;
    }
    return games;
}


/* Ce qui scelle un étage, une fois pris en compte ce que la partie a déjà
 * ouvert et qui l'accompagne. Un étage négatif désigne celui où l'on se
 * trouve. */
int CDngFloorManager::IsSealFloor(int floor) {
    CSaveDataDungeon *dungeon = menu_GetSaveDataDungeon();
    if (dungeon == NULL) {
        return 0;
    }
    if (floor < 0) {
        floor = dungeon->floors[dungeon->current];
    }
    DngMapFloorInfo *info = GetDngMapFloorInfo(floor);
    if (info == NULL) {
        return 0;
    }
    DngFloorSaveInfo *saved = dungeon->GetFloorInfoPtr(dungeon->current, floor);
    int seal = info->seal;
    if (saved != NULL && (saved->flags & DNG_FLOOR_SEAL_OPENED)) {
        seal = 0;
    }

    CUserDataManager *user = GetUserDataMan();
    if (user != NULL) {
        int members = user->GetNowPartyMember();
        if (seal == 1 && !(members & 2)) {
            seal = 0;
        }
        if (seal == 2 && !(members & 1)) {
            seal = 0;
        }
    }
    return seal;
}


/* L'étage vient-il d'être vaincu au plus vite ? Le temps mis est comparé à
 * l'objectif de l'étage la première fois, au meilleur temps ensuite ; un
 * premier succès vaut une médaille. Rend 1 pour l'objectif battu, 2 pour un
 * record, 0 sinon. */
int CDngFloorManager::IsClearMostFastDestroy() {
    CBattleAreaScene *scene = menu_GetBattleAreaScene();
    CSaveData *save = GetSaveData();
    CSaveDataDungeon *dungeon = &save->dungeon;
    if (dungeon == NULL || scene == NULL) {
        return 0;
    }
    int floor = dungeon->floors[dungeon->current];
    DngMapFloorInfo *info = GetDngMapFloorInfo(floor);
    DngFloorSaveInfo *saved = dungeon->GetFloorInfoPtr(dungeon->current, floor);
    if (info == NULL || saved == NULL) {
        return 0;
    }

    int elapsed = (save->now - scene->startTime) * 6 / 5;
    int result = 0;
    if (saved->bestTime == 0) {
        if (elapsed < info->targetTime) {
            saved->bestTime = elapsed;
            result = 1;
            GetUserDataMan()->AddYarikomiMedal(result);
            saved->flags |= 0x10;
        }
    } else if (elapsed < saved->bestTime) {
        saved->bestTime = elapsed;
        result = 2;
    }
    return result;
}

