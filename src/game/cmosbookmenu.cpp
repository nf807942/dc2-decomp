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
extern "C" s32 CosutmeSelDefaultSet__FiPs(s32 arg0, s16 *arg1) {
    s32 var_a2;
    s32 var_v0;

    var_v0 = 0;
    var_a2 = 0;
loop_1:
    if (arg0 == *(arg1 + var_a2)) {
        return var_v0;
    }
    /* m2c compte les pas de pointeur en octets ; MWCC les met a
    * l'echelle du type pointe. Le pas est donc ecrit en elements,
    * et le commerce rend la meme constante. */
    var_v0 += 1;
    var_a2 += 1;
    if (var_v0 >= 5) {
        return 0;
    }
    goto loop_1;
}

INCLUDE_ASM("nonmatchings/game/cmosbookmenu", LoadMenuData__15CMenuCostumeSelFP9mgCMemoryPi);
INCLUDE_ASM("nonmatchings/game/cmosbookmenu", KeyStep__15CMenuCostumeSelFv);
INCLUDE_ASM("nonmatchings/game/cmosbookmenu", Draw__15CMenuCostumeSelFv);
INCLUDE_ASM("nonmatchings/game/cmosbookmenu", MenuCostumeInit__FP9mgCMemoryPii);
extern "C" void *MenuCosPtr;
extern "C" void KeyStep__15CMenuCostumeSelFv(void *);
extern "C" void MenuCostumeKey__Fv(void) { KeyStep__15CMenuCostumeSelFv(MenuCosPtr); }
extern "C" void *MenuCosPtr;
extern "C" void Draw__15CMenuCostumeSelFv(void *);
extern "C" void MenuCostumeDraw__Fv(void) { Draw__15CMenuCostumeSelFv(MenuCosPtr); }
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
extern "C" void KeyStep__12CMosBookMenuFv(void *);
extern "C" void *MenuMosBookPtr;
extern "C" void MonsterBookKey__Fv(void) {
    KeyStep__12CMosBookMenuFv(MenuMosBookPtr);
}
INCLUDE_ASM("nonmatchings/game/cmosbookmenu", MonsterBookDraw__Fv);
extern "C" void Set__9mgRect_s_Fssss(s16 *arg0, s16 a, s16 b, s16 c, s16 d) {
    arg0[0] = a;
    arg0[1] = b;
    arg0[2] = c;
    arg0[3] = d;
}
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
extern "C" u8 mgTexManager[540];
typedef struct MenuArg_champs {
    char pad0[52];
    s32 unk34;
    char pad38[96];
} MenuArg_champs;
extern "C" MenuArg_champs MenuArg;
struct sceVif1Packet;
extern "C" s32 DrawMsg__7CDC2MesFv(...);
extern "C" s32 ReloadTexture__17mgCTextureManagerFiP13sceVif1Packet(void *, s32, sceVif1Packet *);
extern "C" s32 StepMsg__7CDC2MesFv(...);
extern "C" void DrawMenuReturnMsg__Fv(void) {
    if ((MenuReturnMsgDrawFlag != 0) && (MenuReturnMsg != NULL)) {
        ReloadTexture__17mgCTextureManagerFiP13sceVif1Packet(&mgTexManager, MenuArg.unk34, NULL);
        StepMsg__7CDC2MesFv(MenuReturnMsg);
        DrawMsg__7CDC2MesFv(MenuReturnMsg);
    }
}
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
extern "C" void *CManualPtr;
extern "C" void KeyStep__11CManualMenuFv(void *);
extern "C" void MenuManualKey__Fv(void) { KeyStep__11CManualMenuFv(CManualPtr); }
INCLUDE_ASM("nonmatchings/game/cmosbookmenu", MenuManualDraw__Fv);
INCLUDE_ASM("nonmatchings/game/cmosbookmenu", KeyStep__11CManualMenuFv);
INCLUDE_ASM("nonmatchings/game/cmosbookmenu", CalcTex__11CManualMenuFv);
INCLUDE_ASM("nonmatchings/game/cmosbookmenu", CalcCursorPosition__11CManualMenuFv);
INCLUDE_ASM("nonmatchings/game/cmosbookmenu", KeyStep__11CMenuOptionFv);
INCLUDE_ASM("nonmatchings/game/cmosbookmenu", CalcTex__11CMenuOptionFv);
INCLUDE_ASM("nonmatchings/game/cmosbookmenu", DefaultButton__11CMenuOptionFPP18MENUFORMPARTS_TYPE);
extern "C" void EnableButton__11CMenuOptionFP18MENUFORMPARTS_TYPE(void *objet, u8 *p) {
    p[7] = 0x80;
    p[8] = 0x80;
    p[9] = 0x80;
}
INCLUDE_ASM("nonmatchings/game/cmosbookmenu", UpdateOptionForm__11CMenuOptionFv);
