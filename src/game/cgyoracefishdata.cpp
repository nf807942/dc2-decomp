/* CGyoraceFishData
 *
 * Unité découpée par `make carve` : 39 fonctions, 8556 octets, de
 * 0x0021A510 à 0x0021C790. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

/* Les globales que ces accesseurs servent. Leur taille déclarée est celle que
 * le découpage leur donne, et c'est elle qui décide du `%gp_rel`. */
extern s8 GyoRaceAquariumNo;
extern s8 GyoRaceClass;
extern s8 GyoRaceProgressNum;
extern s8 GyoRaceRankingData;
extern s32 GyoraceFish;

INCLUDE_ASM("nonmatchings/game/cgyoracefishdata", MenuAquaInit__FP9mgCMemoryPii);
INCLUDE_ASM("nonmatchings/game/cgyoracefishdata", MenuAquaKey__Fv);
INCLUDE_ASM("nonmatchings/game/cgyoracefishdata", MenuAquaDraw__Fv);
INCLUDE_ASM("nonmatchings/game/cgyoracefishdata", MenuGyoraceFishSelInit__FP9mgCMemoryPii);
INCLUDE_ASM("nonmatchings/game/cgyoracefishdata", MenuGyoraceFishSelKey__Fv);
INCLUDE_ASM("nonmatchings/game/cgyoracefishdata", MenuGyoraceFishSelDraw__Fv);
s32 GetGyoRaceFish(void) {
    return GyoraceFish;
}
void SetGyoRaceAquariumNo(s32 value) {
    GyoRaceAquariumNo = value;
}
s32 GetGyoRaceAquariumNo(void) {
    return GyoRaceAquariumNo;
}
void SetGyoRaceClass(s32 value) {
    GyoRaceClass = value;
}
s32 GetGyoRaceClass(void) {
    return GyoRaceClass;
}
INCLUDE_ASM("nonmatchings/game/cgyoracefishdata", SetGyoRaceNo__Fi);
s32 GetGyoRaceNo(void) {
    return GyoRaceProgressNum;
}
INCLUDE_ASM("nonmatchings/game/cgyoracefishdata", SetGyoRaceRanking__Fi);
s32 GetGyoRaceRanking(void) {
    return GyoRaceRankingData;
}
INCLUDE_ASM("nonmatchings/game/cgyoracefishdata", _GYORACE_LISTNUM__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cgyoracefishdata", _GYORACE_DATA__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cgyoracefishdata", LoadData__16CGyoraceFishDataFP9mgCMemoryP1);
INCLUDE_ASM("nonmatchings/game/cgyoracefishdata", GetRaceFish__16CGyoraceFishDataFii);
INCLUDE_ASM("nonmatchings/game/cgyoracefishdata", _PRIZE_LISTNUM__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cgyoracefishdata", _PRIZE_GROUP__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cgyoracefishdata", _PRIZE__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cgyoracefishdata", InitFishPrize__Fv);
INCLUDE_ASM("nonmatchings/game/cgyoracefishdata", LoadFishPrize__Fi);
INCLUDE_ASM("nonmatchings/game/cgyoracefishdata", LoadFishPrize__FiP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/cgyoracefishdata", RefreshFishPrize__Fv);
INCLUDE_ASM("nonmatchings/game/cgyoracefishdata", GetFishPrize__FiiP15FISH_PRIZE_INFO);
INCLUDE_ASM("nonmatchings/game/cgyoracefishdata", TuriTourCount__Fv);
INCLUDE_ASM("nonmatchings/game/cgyoracefishdata", GyoraceCFGAnalyze__FPc);
INCLUDE_ASM("nonmatchings/game/cgyoracefishdata", SearchOmakeGyoracer__Fi);
INCLUDE_ASM("nonmatchings/game/cgyoracefishdata", CheckSameRacerFish__Fi);
INCLUDE_ASM("nonmatchings/game/cgyoracefishdata", GetOmakeGyoracer2__Fi);
INCLUDE_ASM("nonmatchings/game/cgyoracefishdata", GetOmakeGyoracerTactics__Fi);
INCLUDE_ASM("nonmatchings/game/cgyoracefishdata", SetOmakeGyoracerTactics__Fii);
INCLUDE_ASM("nonmatchings/game/cgyoracefishdata", GyoracerListUpdate__Fv);
INCLUDE_ASM("nonmatchings/game/cgyoracefishdata", GyoraceSubGameInitData__Fv);
INCLUDE_ASM("nonmatchings/game/cgyoracefishdata", GyoraceMenuInit__FP9mgCMemoryPii);
INCLUDE_ASM("nonmatchings/game/cgyoracefishdata", OmakeGyoraceSelect__Fi);
INCLUDE_ASM("nonmatchings/game/cgyoracefishdata", ForceSetGyoList__Fv);
