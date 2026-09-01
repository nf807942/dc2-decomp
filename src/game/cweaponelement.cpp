/* CWeaponElement, CEnemyLifeGage, CLevelupInfo, CPiyori, CGiftMark, CEnemyGekirin
 *
 * Unité découpée par `make carve` : 41 fonctions, 19680 octets, de
 * 0x001C6FD0 à 0x001CBDA0. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"
#include "gen/CPiyori.hpp"

INCLUDE_ASM("nonmatchings/game/cweaponelement", Initialize__14CWeaponElementFv);
INCLUDE_ASM("nonmatchings/game/cweaponelement", Set__14CWeaponElementFPA4_fPffif);
INCLUDE_ASM("nonmatchings/game/cweaponelement", Step__14CWeaponElementFv);
INCLUDE_ASM("nonmatchings/game/cweaponelement", Draw__14CWeaponElementFv);
INCLUDE_ASM("nonmatchings/game/cweaponelement", Init_Cold__14CWeaponElementFPf);
INCLUDE_ASM("nonmatchings/game/cweaponelement", Step_Cold__14CWeaponElementFv);
INCLUDE_ASM("nonmatchings/game/cweaponelement", Draw_Cold__14CWeaponElementFv);
INCLUDE_ASM("nonmatchings/game/cweaponelement", Init_Wind__14CWeaponElementFPf);
INCLUDE_ASM("nonmatchings/game/cweaponelement", Step_Wind__14CWeaponElementFv);
INCLUDE_ASM("nonmatchings/game/cweaponelement", Draw_Wind__14CWeaponElementFv);
INCLUDE_ASM("nonmatchings/game/cweaponelement", Init_Fire__14CWeaponElementFPf);
INCLUDE_ASM("nonmatchings/game/cweaponelement", Step_Fire__14CWeaponElementFv);
INCLUDE_ASM("nonmatchings/game/cweaponelement", Draw_Fire__14CWeaponElementFv);
INCLUDE_ASM("nonmatchings/game/cweaponelement", Init_Thunder__14CWeaponElementFPf);
INCLUDE_ASM("nonmatchings/game/cweaponelement", Step_Thunder__14CWeaponElementFv);
INCLUDE_ASM("nonmatchings/game/cweaponelement", Draw_Thunder__14CWeaponElementFv);
INCLUDE_ASM("nonmatchings/game/cweaponelement", CreatSmoothPass__FPA4_fPA4_fiiii);
INCLUDE_ASM("nonmatchings/game/cweaponelement", unitRotation__FP8mgCFrameff);
INCLUDE_ASM("nonmatchings/game/cweaponelement", iRand__Fi);
INCLUDE_ASM("nonmatchings/game/cweaponelement", fRand__Ff);
INCLUDE_ASM("nonmatchings/game/cweaponelement", SetLevelUpInfo__12CLevelupInfoFiiii);
INCLUDE_ASM("nonmatchings/game/cweaponelement", Draw__12CLevelupInfoFv);
INCLUDE_ASM("nonmatchings/game/cweaponelement", Step__12CLevelupInfoFv);
void CPiyori::Initialize(void) {
    this->field_0x0 = 0;
}
void CPiyori::Reset(void) {
    this->field_0x0 = 0;
    this->field_0x1C = 0;
}
INCLUDE_ASM("nonmatchings/game/cweaponelement", Set__7CPiyoriFP9mgCObjectffs);
INCLUDE_ASM("nonmatchings/game/cweaponelement", Set__7CPiyoriFP9mgCObjects);
INCLUDE_ASM("nonmatchings/game/cweaponelement", Draw__7CPiyoriFv);
INCLUDE_ASM("nonmatchings/game/cweaponelement", Step__7CPiyoriFv);
INCLUDE_ASM("nonmatchings/game/cweaponelement", Set__9CGiftMarkFP11CCharacter2f);
INCLUDE_ASM("nonmatchings/game/cweaponelement", Draw__9CGiftMarkFv);
INCLUDE_ASM("nonmatchings/game/cweaponelement", Step__9CGiftMarkFv);
INCLUDE_ASM("nonmatchings/game/cweaponelement", Initialize__9CGiftMarkFv);
INCLUDE_ASM("nonmatchings/game/cweaponelement", Draw__13CEnemyGekirinFP10CPreSpriteii);
INCLUDE_ASM("nonmatchings/game/cweaponelement", Step__13CEnemyGekirinFv);
INCLUDE_ASM("nonmatchings/game/cweaponelement", SetView__14CEnemyLifeGageFi);
INCLUDE_ASM("nonmatchings/game/cweaponelement", Set__14CEnemyLifeGageFPfiiii);
INCLUDE_ASM("nonmatchings/game/cweaponelement", Draw__14CEnemyLifeGageFi);
INCLUDE_ASM("nonmatchings/game/cweaponelement", Step__14CEnemyLifeGageFv);
INCLUDE_ASM("nonmatchings/game/cweaponelement", ResetGekirin__14CEnemyLifeGageFi);
INCLUDE_ASM("nonmatchings/game/cweaponelement", Initialize__14CEnemyLifeGageFi);
