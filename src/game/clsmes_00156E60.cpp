/* ClsMes
 *
 * Unité découpée par `make carve` : 3 fonctions, 2340 octets, de
 * 0x00156E60 à 0x00157790. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

INCLUDE_ASM("nonmatchings/game/clsmes_00156E60", MakeMesWinTbl__6ClsMesFi);
INCLUDE_ASM("nonmatchings/game/clsmes_00156E60", MakeMesWinTbl__6ClsMesFPc);
struct irregular;
struct match;
extern "C" s32 GetItemNoFromFontNo__Fi(s32 arg0) {
    s32 temp_v1;
    s32 var_v0;

    temp_v1 = (arg0 - 0x8000) - 0x7B00;
    var_v0 = 1;
    if (temp_v1 != 0xFE) {
        var_v0 = 2;
        switch (temp_v1) {                          /* irregular */
        case 0xE7:
            return 0x10;
        case 0xE8:
            return 0xF;
        case 0xE9:
            return 0xE;
        case 0xEA:
            return 0xD;
        case 0xEB:
            return 0xC;
        case 0xEC:
            return 0xB;
        case 0xED:
            return 0xA;
        case 0xEE:
            return 9;
        case 0xEF:
            return 8;
        case 0xF0:
            return 7;
        case 0xF1:
            return 6;
        case 0xF2:
            return 5;
        case 0xFB:
            return 4;
        case 0xFC:
            return 3;
        case 0xFD:
            /* Duplicate return node #32. Try simplifying control flow for better match */
            return var_v0;
        default:
            return -1;
        }
    } else {
        return var_v0;
    }
}
