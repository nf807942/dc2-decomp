/* CGyoraceFishData
 *
 * Unité découpée par `make carve` : 39 fonctions, 8556 octets, de
 * 0x0021A510 à 0x0021C790. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"
#include "menu.hpp"
#include "gen/GyoracerIndexNoData.hpp"
#include "gen/GyoracerTacticsNoData.hpp"

/* Les globales que ces accesseurs servent. Leur taille déclarée est celle que
 * le découpage leur donne, et c'est elle qui décide du `%gp_rel`. */
extern s8 GyoRaceAquariumNo;
extern s8 GyoRaceClass;
extern s8 GyoRaceProgressNum;
extern s8 GyoRaceRankingData;
extern s32 GyoraceFish;
extern s16 FishTournamentGoodsNum;
extern s32 FishTournamentGoods;
extern s32 fish_prize_buildstack;
extern s32 spi_fish_prize_info;

extern GyoracerIndexNoData GyoracerIndexNo;
extern GyoracerTacticsNoData GyoracerTacticsNo;


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
struct SPI_STACK {
    s32 field_0;
    s32 field_4;
};
extern "C" s32 Alloc__9mgCMemoryFi(...);
extern "C" s32 __nwa__FUiP1(...);
extern "C" s32 spiGetStackInt__FP9SPI_STACK(SPI_STACK *);
extern "C" s32 _PRIZE_LISTNUM__FP9SPI_STACKi(SPI_STACK *arg0, s32 arg1) {
    u32 temp_s0;
    u32 var_v0;

    temp_s0 = (u32) (spiGetStackInt__FP9SPI_STACK(arg0) * 0x44);
    if (temp_s0 & 0xF) {
        var_v0 = (temp_s0 >> 4) + 1;
    } else {
        var_v0 = temp_s0 >> 4;
    }
    FishTournamentGoods = __nwa__FUiP1(temp_s0, Alloc__9mgCMemoryFi(fish_prize_buildstack, var_v0 + 2));
    FishTournamentGoodsNum = 0;
    return 1;
}
extern "C" u32 spiFishTournamentGoods;
struct calcul0_champs_f213cc {
    char pad0[0x4];
    s32 unk4;
};
struct spiFishTournamentGoods_champs_f213cc {
    s32 unk0;
    char pad4[0x3C];
    s32 unk40;
};
extern "C" s32 _PRIZE_GROUP__FP9SPI_STACKi(SPI_STACK *arg0, s32 arg1) {
    s32 temp_v0;
    s32 var_s1;
    s32 var_s2;
    void *var_s3;
    void *temp_a0;
    s32 temp_a1;
    u32 temp_s0;
    u32 var_v0;

    var_s3 = (void *) (((u8 *) arg0) + 8);
    spiFishTournamentGoods = FishTournamentGoods + (FishTournamentGoodsNum++ * 0x11) * 4;
    temp_v0 = (s32) (spiGetStackInt__FP9SPI_STACK(arg0));
    var_s1 = 0;
    var_s2 = 0;
    ((struct spiFishTournamentGoods_champs_f213cc *) spiFishTournamentGoods)->unk0 = temp_v0;
    do {
        temp_a0 = (void *) (var_s3);
        var_s3 = (void *) (((u8 *) temp_a0) + 8);
        ((struct calcul0_champs_f213cc *) (spiFishTournamentGoods + var_s2))->unk4 = spiGetStackInt__FP9SPI_STACK((SPI_STACK *) temp_a0);
        var_s1 += 1;
        var_s2 += 4;
    } while (var_s1 < 8);
    temp_s0 = temp_v0 * 0x1C;
    if (temp_s0 & 0xF) {
        var_v0 = (temp_s0 >> 4) + 1;
    } else {
        var_v0 = temp_s0 >> 4;
    }
    ((struct spiFishTournamentGoods_champs_f213cc *) spiFishTournamentGoods)->unk40 = __nwa__FUiP1(temp_s0, Alloc__9mgCMemoryFi(fish_prize_buildstack, var_v0 + 2));
    spi_fish_prize_info = ((struct spiFishTournamentGoods_champs_f213cc *) spiFishTournamentGoods)->unk40;
    return 1;
}
struct spi_fish_prize_info_champs_9e2ada {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
};
extern "C" s32 _PRIZE__FP9SPI_STACKi(SPI_STACK *arg0, s32 arg1) {
    SPI_STACK *p;

    p = arg0 + 1;
    if (spi_fish_prize_info == NULL) {
        return 0;
    }
    ((struct spi_fish_prize_info_champs_9e2ada *) spi_fish_prize_info)->unk0 = spiGetStackInt__FP9SPI_STACK(arg0);
    ((struct spi_fish_prize_info_champs_9e2ada *) spi_fish_prize_info)->unk4 = spiGetStackInt__FP9SPI_STACK(p++);
    ((struct spi_fish_prize_info_champs_9e2ada *) spi_fish_prize_info)->unk8 = spiGetStackInt__FP9SPI_STACK(p++);
    ((struct spi_fish_prize_info_champs_9e2ada *) spi_fish_prize_info)->unkC = spiGetStackInt__FP9SPI_STACK(p++);
    ((struct spi_fish_prize_info_champs_9e2ada *) spi_fish_prize_info)->unk10 = spiGetStackInt__FP9SPI_STACK(p++);
    ((struct spi_fish_prize_info_champs_9e2ada *) spi_fish_prize_info)->unk14 = spiGetStackInt__FP9SPI_STACK(p++);
    ((struct spi_fish_prize_info_champs_9e2ada *) spi_fish_prize_info)->unk18 = spiGetStackInt__FP9SPI_STACK(p);
    spi_fish_prize_info += 0x1C;
    return 1;
}
void InitFishPrize(void) {
    fish_prize_buildstack = 0;
    FishTournamentGoods = 0;
    FishTournamentGoodsNum = 0;
    spi_fish_prize_info = 0;
}
extern "C" s32 Align64__9mgCMemoryFv(mgCMemory *);
extern "C" s32 Init__9mgCMemoryFv(mgCMemory *);
extern "C" s32 stSetBuffer__9mgCMemoryFP1i(mgCMemory *, void *, s32);
extern "C" s32 LoadFishPrize__FiP9mgCMemory(...);
extern "C" s32 LoadFishPrize__Fi(s32 arg0) {
    u8 sp20[0x2800];
    mgCMemory sp2820;
    Init__9mgCMemoryFv(&sp2820);
    stSetBuffer__9mgCMemoryFP1i(&sp2820, sp20, 0x280);
    Align64__9mgCMemoryFv(&sp2820);
    LoadFishPrize__FiP9mgCMemory(arg0, &sp2820);
    return 0;
}
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
void GyoraceSubGameInitData(void) {
    GyoracerIndexNo.field_0x0 = -1;
    GyoracerTacticsNo.field_0x0 = -1;
    GyoracerIndexNo.field_0x2 = -1;
    GyoracerTacticsNo.field_0x2 = -1;
    GyoracerIndexNo.field_0x4 = -1;
    GyoracerTacticsNo.field_0x4 = -1;
    GyoracerIndexNo.field_0x6 = -1;
    GyoracerTacticsNo.field_0x6 = -1;
    GyoracerIndexNo.field_0x8 = -1;
    GyoracerTacticsNo.field_0x8 = -1;
    GyoracerIndexNo.field_0xA = -1;
    GyoracerTacticsNo.field_0xA = -1;
}
INCLUDE_ASM("nonmatchings/game/cgyoracefishdata", GyoraceMenuInit__FP9mgCMemoryPii);
INCLUDE_ASM("nonmatchings/game/cgyoracefishdata", OmakeGyoraceSelect__Fi);
INCLUDE_ASM("nonmatchings/game/cgyoracefishdata", ForceSetGyoList__Fv);
