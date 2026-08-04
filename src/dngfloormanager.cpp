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

INCLUDE_ASM("nonmatchings/dngfloormanager", IsGeoStone__16CDngFloorManagerFi);

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
    SaveDataDungeon *dungeon = menu_GetSaveDataDungeon();
    if (dungeon == NULL) {
        return 0;
    }
    return GetSphedaPrize(dungeon->floors[dungeon->current], index, prize, count);
}

INCLUDE_ASM("nonmatchings/dngfloormanager", IsPlaySubGame__16CDngFloorManagerFv);
INCLUDE_ASM("nonmatchings/dngfloormanager", IsSealFloor__16CDngFloorManagerFi);
INCLUDE_ASM("nonmatchings/dngfloormanager", IsClearMostFastDestroy__16CDngFloorManagerFv);
