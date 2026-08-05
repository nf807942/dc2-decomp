/* La table d'avancement de la partie.
 *
 * `LoadGameInfo` la remplit depuis un script et la laisse à trois accesseurs :
 * l'entrée d'un indice, le chapitre qu'elle porte, et le nombre d'entrées.
 */

#include "common.h"
#include "gameprogress.hpp"

/* L'entrée d'un indice, ou rien si l'indice sort de la table. */
GameProgressInfo *GetGameProgressInfo(int index) {
    if (index < 0 || index >= ProgressNum) {
        return NULL;
    }
    return &ProgressInfo[index];
}

/* Le chapitre auquel une entrée appartient. Une entrée absente n'en porte
 * aucun, et le zéro qu'on rend alors est aussi un chapitre valide. */
int GetGameChapter(int index) {
    GameProgressInfo *info = GetGameProgressInfo(index);
    /* Le cas passant est celui qui tombe droit : le commerce loge la lecture
     * dans le créneau de délai du saut vers la sortie, et fait du retour nul la
     * cible du branchement. La condition inverse échange les deux. */
    if (info != NULL) {
        return info->chapter;
    }
    return 0;
}

/* Le nombre d'entrées que la table porte. */
int GetGameProgressNum(void) {
    return ProgressNum;
}
