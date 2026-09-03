/* CMosBookMenu, CMenuCostumeSel, CManualMenu, CMenuOption, mgRect_s_
 *
 * Unité découpée par `make carve` : 38 fonctions, 26188 octets, de
 * 0x002C06D0 à 0x002C6E30. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"
#include "gen/MnOnePictTexData.hpp"
#include "gen/CMosBookMenu.hpp"
extern MnOnePictTexData MnOnePictTex;


INCLUDE_ASM("nonmatchings/game/cmosbookmenu", KeyMainCharaBG__Fv);
INCLUDE_ASM("nonmatchings/game/cmosbookmenu", DrawMainCharaBG__Fv);
INCLUDE_ASM("nonmatchings/game/cmosbookmenu", MenuNPCModelLoad__FP9mgCMemoryii);
INCLUDE_ASM("nonmatchings/game/cmosbookmenu", MenuNPCLoadCheck__FP12CActionCharaP9mgCMemoryi);
INCLUDE_ASM("nonmatchings/game/cmosbookmenu", UpdateCostumeList__15CMenuCostumeSelFiUl);
INCLUDE_ASM("nonmatchings/game/cmosbookmenu", CosutmeSelDefaultSet__FiPs);
INCLUDE_ASM("nonmatchings/game/cmosbookmenu", LoadMenuData__15CMenuCostumeSelFP9mgCMemoryPi);
INCLUDE_ASM("nonmatchings/game/cmosbookmenu", KeyStep__15CMenuCostumeSelFv);
INCLUDE_ASM("nonmatchings/game/cmosbookmenu", Draw__15CMenuCostumeSelFv);
INCLUDE_ASM("nonmatchings/game/cmosbookmenu", MenuCostumeInit__FP9mgCMemoryPii);
INCLUDE_ASM("nonmatchings/game/cmosbookmenu", MenuCostumeKey__Fv);
INCLUDE_ASM("nonmatchings/game/cmosbookmenu", MenuCostumeDraw__Fv);
INCLUDE_ASM("nonmatchings/game/cmosbookmenu", GetMonsterBaseInfoForMonsterMemoIndex__Fi);
void CMosBookMenu::InitMonsterInfo(void) {
    this->field_0x7EC = 0;
    this->field_0x82C = 0;
    this->field_0x86C = 0;
    this->field_0x904 = 0;
    this->field_0x908 = 0;
    this->field_0x90C = 0;
    this->field_0x910 = 0;
    this->field_0x914 = 0;
    this->field_0x918 = 0;
    this->field_0x939 = 0;
    this->field_0x95A = 0;
    this->field_0x8AC = 0;
}
INCLUDE_ASM("nonmatchings/game/cmosbookmenu", SetMonsterInfo__12CMosBookMenuFP16BASE_MONSTER_TBL);
INCLUDE_ASM("nonmatchings/game/cmosbookmenu", InitEnd__12CMosBookMenuFv);
INCLUDE_ASM("nonmatchings/game/cmosbookmenu", Draw__12CMosBookMenuFv);
INCLUDE_ASM("nonmatchings/game/cmosbookmenu", KeyStep__12CMosBookMenuFv);
INCLUDE_ASM("nonmatchings/game/cmosbookmenu", MonsterBookInit__FP9mgCMemoryPii);
INCLUDE_ASM("nonmatchings/game/cmosbookmenu", MonsterBookKey__Fv);
INCLUDE_ASM("nonmatchings/game/cmosbookmenu", MonsterBookDraw__Fv);
INCLUDE_ASM("nonmatchings/game/cmosbookmenu", Set__9mgRect_s_Fssss);
INCLUDE_ASM("nonmatchings/game/cmosbookmenu", InitMenuReturnMsg__FP9mgCMemory);
extern "C" u32 LanguageCode;
extern "C" u32 MenuReturnMsg;
extern "C" u8 MenuReturnMsgDrawFlag;
extern "C" void SetMenuReturnMsgCtrl__Fi(s32 arg0) {
    MenuReturnMsgDrawFlag = arg0 != 0;
    if (LanguageCode == 0) {
        MenuReturnMsgDrawFlag = 0;
    }
    if (MenuReturnMsg == 0) {
        MenuReturnMsgDrawFlag = 0;
    }
}
INCLUDE_ASM("nonmatchings/game/cmosbookmenu", DrawMenuReturnMsg__Fv);
INCLUDE_ASM("nonmatchings/game/cmosbookmenu", CheckOmakeVtuto__Fi);
void InitMnOnePictTex(void) {
    MnOnePictTex.field_0x0 = 0;
    MnOnePictTex.field_0x4 = 0;
    MnOnePictTex.field_0x8 = 0;
    MnOnePictTex.field_0xC = 0;
    MnOnePictTex.field_0x10 = 0;
    MnOnePictTex.field_0x14 = 0;
    MnOnePictTex.field_0x18 = 0;
    MnOnePictTex.field_0x1C = 0;
}
INCLUDE_ASM("nonmatchings/game/cmosbookmenu", MenuManualInit__FP9mgCMemoryPii);
INCLUDE_ASM("nonmatchings/game/cmosbookmenu", MenuManualKey__Fv);
INCLUDE_ASM("nonmatchings/game/cmosbookmenu", MenuManualDraw__Fv);
INCLUDE_ASM("nonmatchings/game/cmosbookmenu", KeyStep__11CManualMenuFv);
INCLUDE_ASM("nonmatchings/game/cmosbookmenu", CalcTex__11CManualMenuFv);
INCLUDE_ASM("nonmatchings/game/cmosbookmenu", CalcCursorPosition__11CManualMenuFv);
INCLUDE_ASM("nonmatchings/game/cmosbookmenu", KeyStep__11CMenuOptionFv);
INCLUDE_ASM("nonmatchings/game/cmosbookmenu", CalcTex__11CMenuOptionFv);
INCLUDE_ASM("nonmatchings/game/cmosbookmenu", DefaultButton__11CMenuOptionFPP18MENUFORMPARTS_TYPE);
INCLUDE_ASM("nonmatchings/game/cmosbookmenu", EnableButton__11CMenuOptionFP18MENUFORMPARTS_TYPE);
INCLUDE_ASM("nonmatchings/game/cmosbookmenu", UpdateOptionForm__11CMenuOptionFv);
