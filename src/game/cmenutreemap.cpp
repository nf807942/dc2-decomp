/* CMenuTreeMap, ClsMes, CBaseMenuClass, mgRect_f_
 *
 * Unité découpée par `make carve` : 29 fonctions, 24696 octets, de
 * 0x001F0E00 à 0x001F6F40. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"
#include "gen/mgRect_f_.hpp"

/* Le corps ne rend qu'un code : ni la classe ni les arguments ne sont
 * déréférencés, donc leur disposition reste à établir. */
struct ITEMCMD_RET_PARA;

class CBaseMenuClass {
public:
    s32 IsAskExtend(s32 a, s32 b);
    s32 IsCreateObject(s32 a, s32 b);
    s32 IsMakeObject(s32 a, s32 b);
    s32 ItemCmdAfter(s32 command, ITEMCMD_RET_PARA *para);
};

INCLUDE_ASM("nonmatchings/game/cmenutreemap", CheckDngTreeMapFuncType__Fv);
INCLUDE_ASM("nonmatchings/game/cmenutreemap", MakeDngTreeMapJumpNo__FiiPiPi);
INCLUDE_ASM("nonmatchings/game/cmenutreemap", InitEnd__12CMenuTreeMapFv);
INCLUDE_ASM("nonmatchings/game/cmenutreemap", MsgInit__12CMenuTreeMapFv);
INCLUDE_ASM("nonmatchings/game/cmenutreemap", Step__12CMenuTreeMapFv);
INCLUDE_ASM("nonmatchings/game/cmenutreemap", Draw__12CMenuTreeMapFv);
INCLUDE_ASM("nonmatchings/game/cmenutreemap", FadeInOutMenu__12CMenuTreeMapFv);
INCLUDE_ASM("nonmatchings/game/cmenutreemap", DngTreeMapInit__FP9mgCMemoryPiii);
INCLUDE_ASM("nonmatchings/game/cmenutreemap", Init__6ClsMesFv);
INCLUDE_ASM("nonmatchings/game/cmenutreemap", DngTreeMapKey__Fv);
INCLUDE_ASM("nonmatchings/game/cmenutreemap", DngTreeMapDraw__Fv);
s32 CBaseMenuClass::IsCreateObject(s32 a, s32 b) {
    return 1;
}
s32 CBaseMenuClass::IsMakeObject(s32 a, s32 b) {
    return 0;
}
s32 CBaseMenuClass::IsAskExtend(s32 a, s32 b) {
    return 0;
}
s32 CBaseMenuClass::ItemCmdAfter(s32 command, ITEMCMD_RET_PARA *para) {
    return 0;
}
INCLUDE_ASM("nonmatchings/game/cmenutreemap", ExitEnd__14CBaseMenuClassFv);
void mgRect_f_::Set(f32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    this->field_0x0 = arg0;
    this->field_0x4 = arg1;
    this->field_0x8 = arg2;
    this->field_0xC = arg3;
}
INCLUDE_ASM("nonmatchings/game/cmenutreemap", GetPenkiColor__FiPf);
INCLUDE_ASM("nonmatchings/game/cmenutreemap", ConvGeoramaDataNo__Fi);
INCLUDE_ASM("nonmatchings/game/cmenutreemap", CheckMenuLine__FPiPiii);
INCLUDE_ASM("nonmatchings/game/cmenutreemap", SetEditMenuEnv__Fv);
INCLUDE_ASM("nonmatchings/game/cmenutreemap", MenuGeoramaInit__FP9mgCMemoryi);
INCLUDE_ASM("nonmatchings/game/cmenutreemap", MenuGeoDebugKey__Fv);
INCLUDE_ASM("nonmatchings/game/cmenutreemap", MenuGeoramaKey__Fv);
INCLUDE_ASM("nonmatchings/game/cmenutreemap", MenuGeoramaDraw__Fv);
INCLUDE_ASM("nonmatchings/game/cmenutreemap", MenuGeoramaTitleDraw__FRiPfi);
INCLUDE_ASM("nonmatchings/game/cmenutreemap", MenuGeoramaListDraw__FRiPfii);
INCLUDE_ASM("nonmatchings/game/cmenutreemap", MenuGeoramaAnalyzeDraw__FRiPfi);
INCLUDE_ASM("nonmatchings/game/cmenutreemap", InitDownLoadAnaunce__FP9mgCMemory);
