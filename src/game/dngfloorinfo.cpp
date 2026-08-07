/* CDngFloorManager::GetDngMapFloorInfo.
 *
 * Unité séparée : `IsClearPractice`, qui la précède, porte une table de saut
 * qu'un sous-segment de données référence, et ne peut donc pas être greffée.
 */

#include "common.h"
#include "dngfloormanager.hpp"

/* L'information de l'étage demandé. */
DngMapFloorInfo *CDngFloorManager::GetDngMapFloorInfo(int floor) {
    if (this->table == NULL) {
        return NULL;
    }

    DngMapFloorGlidInfo *glid = GetDngMapFloorGlidInfo(floor);
    if (glid != NULL) {
        return &glid->info;
    }
    return NULL;
}
