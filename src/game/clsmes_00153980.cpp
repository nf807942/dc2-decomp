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
INCLUDE_ASM("nonmatchings/game/clsmes_00153980", GoNextPage__6ClsMesFv);
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
