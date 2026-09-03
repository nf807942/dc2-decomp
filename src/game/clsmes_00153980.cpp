/* ClsMes
 *
 * Unité découpée par `make carve` : 22 fonctions, 13416 octets, de
 * 0x00153980 à 0x00156E60. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"
#include "gen/ClsMes.hpp"

INCLUDE_ASM("nonmatchings/game/clsmes_00153980", SetWindowMode__6ClsMesFi);
s32 ClsMes::GetWindowMode(void) {
    return this->field_0x138;
}
void ClsMes::SetWindowBgOpaqueFlg(s32 arg0) {
    this->field_0x13C = arg0;
}
INCLUDE_ASM("nonmatchings/game/clsmes_00153980", StepNpcName__6ClsMesFv);
INCLUDE_ASM("nonmatchings/game/clsmes_00153980", StepNormal__6ClsMesFv);
INCLUDE_ASM("nonmatchings/game/clsmes_00153980", Step__6ClsMesFv);
INCLUDE_ASM("nonmatchings/game/clsmes_00153980", State__6ClsMesFv);
struct inferred;
typedef struct ClsMes_infere {
    /* 0x0000 */ char pad0[0xE8];
    /* 0x00E8 */ s32 unkE8;                         /* inferred */
    /* 0x00EC */ char padEC[0xEC];                  /* maybe part of unkE8[0x3C]void */
    /* 0x01D8 */ s32 unk1D8;                        /* inferred */
    /* 0x01DC */ char pad1DC[0x10];                 /* maybe part of unk1D8[5]void */
    /* 0x01EC */ s32 unk1EC;                        /* inferred */
    /* 0x01F0 */ s32 unk1F0;                        /* inferred */
    /* 0x01F4 */ char pad1F4[0x1C40];               /* maybe part of unk1F0[0x711]void */
    /* 0x1E34 */ s32 unk1E34;                       /* inferred */
} ClsMes_infere;                                           /* size >= 0x1E38 */
extern "C" void GoNextPage__6ClsMesFv(ClsMes_infere *objet) {
    if (objet->unk1D8 != 0) {
        objet->unk1D8 = 0;
        objet->unkE8 += 1;
        objet->unk1E34 = 0;
        objet->unk1F0 = objet->unk1EC;
    }
}
INCLUDE_ASM("nonmatchings/game/clsmes_00153980", MyTextureMake_sub__6ClsMesFv);
INCLUDE_ASM("nonmatchings/game/clsmes_00153980", MyTextureMake__6ClsMesFv);
INCLUDE_ASM("nonmatchings/game/clsmes_00153980", SetAndGetNameRegistTbl__Fi);
INCLUDE_ASM("nonmatchings/game/clsmes_00153980", MakeMesWinTbl_value__6ClsMesFPiPi);
INCLUDE_ASM("nonmatchings/game/clsmes_00153980", MakeMesWinTbl_value__6ClsMesFiPiPi);
INCLUDE_ASM("nonmatchings/game/clsmes_00153980", MakeMesWinTbl_str__6ClsMesFPcPiPi);
INCLUDE_ASM("nonmatchings/game/clsmes_00153980", MakeMesWinTbl_str__6ClsMesFiPiPi);
INCLUDE_ASM("nonmatchings/game/clsmes_00153980", MakeMesWinTbl_item__6ClsMesFiPiPi);
INCLUDE_ASM("nonmatchings/game/clsmes_00153980", GetMesWidth_system__6ClsMesFi);
INCLUDE_ASM("nonmatchings/game/clsmes_00153980", GetTextLineDataTop__6ClsMesFi);
INCLUDE_ASM("nonmatchings/game/clsmes_00153980", GetTextLineDataTop_system__6ClsMesFi);
INCLUDE_ASM("nonmatchings/game/clsmes_00153980", InitMesWinTbl__6ClsMesFv);
INCLUDE_ASM("nonmatchings/game/clsmes_00153980", SetMesWinTbl__6ClsMesFiss);
INCLUDE_ASM("nonmatchings/game/clsmes_00153980", CalcSpaceW__6ClsMesFiiPUs);
