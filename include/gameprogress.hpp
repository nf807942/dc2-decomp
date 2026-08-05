#ifndef GAMEPROGRESS_HPP
#define GAMEPROGRESS_HPP

#include "types.h"

/* Une entrée de la table d'avancement, douze octets. La largeur de chaque champ
 * vient de la boucle par laquelle `LoadGameInfo` met la table à zéro : deux
 * demi-mots puis deux mots, huit entrées par tour, 0x60 octets de pas. */
struct GameProgressInfo {
    /* Le chapitre de l'entrée : `GetGameChapter` ne fait que le rendre, et le
     * lit sur seize bits signés. */
    s16 chapter;
    s16 unknown_02;
    int unknown_04;
    int unknown_08;
};

/* La table elle-même, 256 entrées — `LoadGameInfo` en écrit autant et pose ce
 * même 256 dans le compte. */
extern GameProgressInfo ProgressInfo[256];

/* Le nombre d'entrées valides, borne de tout accès par indice. */
extern int ProgressNum;

GameProgressInfo *GetGameProgressInfo(int index);
int GetGameChapter(int index);
int GetGameProgressNum(void);

#endif /* GAMEPROGRESS_HPP */
