/* Fonctions libres — à décrire.
 *
 * Unité découpée par `make carve` : 8 fonctions, 1408 octets, de
 * 0x00197BF0 à 0x001981B0. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

INCLUDE_ASM("nonmatchings/game/text_00197BF0", LoadSystemMes__Fv);
extern "C" char SystemMesBuffer[];
extern "C" void *GetSystemMesBuffer__Fv(void) { return SystemMesBuffer; }

extern "C" char SysMesBuffer[];
extern "C" void *GetSysMesBuffer__Fv(void) { return SysMesBuffer; }

extern "C" s32 CreateSystemMes__Fii(s32, s32);
extern "C" void CreateSystemMes__Fv(void) {
    CreateSystemMes__Fii(0, 0);
    CreateSystemMes__Fii(1, 0);
    CreateSystemMes__Fii(2, 0);
}
INCLUDE_ASM("nonmatchings/game/text_00197BF0", CreateSystemMes__Fii);
extern "C" s32 GetSaveData__Fv(void);
extern "C" s32 GetUserDataMan__Fv(void) {
    u8 *p;

    p = (u8 *)GetSaveData__Fv();
    if (p != 0) {
        return (s32)(p + 0x1D2A0);
    }
    return 0;
}
extern "C" s32 GetFishTournament__Fv(void) {
    u8 *p;

    p = (u8 *)GetUserDataMan__Fv();
    if (p != 0) {
        return (s32)(p + 0x451E8);
    }
    return 0;
}
extern "C" s32 GetUserDataMan__Fv(void);
extern "C" s32 GetAquariumData__Fv(void) {
    s32 temp_v0;

    temp_v0 = GetUserDataMan__Fv();
    if (temp_v0 != 0) {
        return temp_v0 + 0x4958;
    }
    return 0;
}
