/* CPowGage, CSphida
 *
 * Unité découpée par `make carve` : 6 fonctions, 2012 octets, de
 * 0x002EDF20 à 0x002EE720. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

/* Les globales que ces accesseurs servent. Leur taille déclarée est celle que
 * le découpage leur donne, et c'est elle qui décide du `%gp_rel`. */
extern s32 Sphida;

INCLUDE_ASM("nonmatchings/game/cpowgage_002EDF20", Step__8CPowGageFv);
INCLUDE_ASM("nonmatchings/game/cpowgage_002EDF20", Draw__8CPowGageFv);
void InitSphida(void) {
    Sphida = 0;
}
s32 GetSphidaPtr(void) {
    return Sphida;
}
INCLUDE_ASM("nonmatchings/game/cpowgage_002EDF20", __ct__7CSphidaFv);
INCLUDE_ASM("nonmatchings/game/cpowgage_002EDF20", Initialize__7CSphidaFv);
