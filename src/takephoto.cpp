/* Le service de photographie. `EndTakePhoto` seul, pour l'instant : les
 * autres fonctions du bloc attendent d'etre ouvertes. */

#include "common.h"

void InitTakePhoto();

/* Terminer la prise : le jeu revient a l'etat initial, sans memoire. */
void EndTakePhoto() {
    InitTakePhoto();
}
