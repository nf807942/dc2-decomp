/* CMenuMosSelect
 *
 * Unité découpée par `make carve` : 31 fonctions, 24760 octets, de
 * 0x002BA570 à 0x002C06D0. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

INCLUDE_ASM("nonmatchings/game/cmenumosselect", AttachForm__14CMenuMosSelectFv);
INCLUDE_ASM("nonmatchings/game/cmenumosselect", MonsterScaleCheck__FP11CCharacter2);
INCLUDE_ASM("nonmatchings/game/cmenumosselect", MonsterEffectRead__FP9mgCMemoryii);
INCLUDE_ASM("nonmatchings/game/cmenumosselect", MonsterEffectEnter__FP6CSceneP1i);
INCLUDE_ASM("nonmatchings/game/cmenumosselect", CheckLoadBGMonster__14CMenuMosSelectFv);
INCLUDE_ASM("nonmatchings/game/cmenumosselect", GetBajjiPosition__FP16CMenuPosDataFormiiPi);
INCLUDE_ASM("nonmatchings/game/cmenumosselect", CalcCursorPosition__14CMenuMosSelectFv);
INCLUDE_ASM("nonmatchings/game/cmenumosselect", CalcTex__14CMenuMosSelectFv);
INCLUDE_ASM("nonmatchings/game/cmenumosselect", KeyNormalMode__14CMenuMosSelectFiii);
INCLUDE_ASM("nonmatchings/game/cmenumosselect", MenuMonsterBoxInit__FP9mgCMemoryPii);
INCLUDE_ASM("nonmatchings/game/cmenumosselect", KeyStep__14CMenuMosSelectFv);
extern "C" void *MenuMosSelectPtr;
extern "C" void KeyStep__14CMenuMosSelectFv(void *);
extern "C" void MenuMonsterBoxKey__Fv(void) { KeyStep__14CMenuMosSelectFv(MenuMosSelectPtr); }
INCLUDE_ASM("nonmatchings/game/cmenumosselect", MenuMonsterBoxDraw__Fv);
INCLUDE_ASM("nonmatchings/game/cmenumosselect", MenuTimeStepEnvFunc__FP6CSceneP12CActionCharai);
INCLUDE_ASM("nonmatchings/game/cmenumosselect", MenuWeaponRealStepEnvFunc__FP12CActionCharai);
INCLUDE_ASM("nonmatchings/game/cmenumosselect", MenuItemCharaDataLoad__FP9mgCMemoryiPP17MENU_BGREAD_INFO2i);
INCLUDE_ASM("nonmatchings/game/cmenumosselect", MenuItemCharaDataLoadPack__FiP12CActionCharaP12CActionCharaiPUiP9mgCMemoryii);
INCLUDE_ASM("nonmatchings/game/cmenumosselect", MenuItemCharaDataLoadEndCheck__FPP17MENU_BGREAD_INFO2P9mgCMemoryPP12CActionCharaiii);
INCLUDE_ASM("nonmatchings/game/cmenumosselect", MenuCharaSoundLoad__FP9mgCMemoryii);
INCLUDE_ASM("nonmatchings/game/cmenumosselect", MenuCharaSoundEnter__FP6CSceneP12CActionCharai);
INCLUDE_ASM("nonmatchings/game/cmenumosselect", MenuItemChrLoad__FP9mgCMemoryiiP17MENU_BGREAD_INFO2i);
INCLUDE_ASM("nonmatchings/game/cmenumosselect", MenuItemChrLoadEndCheck__FP17MENU_BGREAD_INFO2P12CActionCharaP9mgCMemoryi);
INCLUDE_ASM("nonmatchings/game/cmenumosselect", MenuItemRoboDataLoad__FP9mgCMemoryPP17MENU_BGREAD_INFO2i);
INCLUDE_ASM("nonmatchings/game/cmenumosselect", DeleteOutLineMenu__FP12CActionCharai);
INCLUDE_ASM("nonmatchings/game/cmenumosselect", MenuItemRoboDataLoadEndCheck__FPP17MENU_BGREAD_INFO2P9mgCMemoryPP12CActionCharaii);
extern "C" u8 _4517_00374C70[];
extern "C" s32 SearchFrame__8mgCFrameFPc(...);
#include "gen/mgCFrame.hpp"
struct temp_v0_champs_a42004 {
    char pad0[0xF4];
    /* 0xF4 */ struct unkF4_champs_a42004 *unkF4;
};
struct unkF4_champs_a42004 {
    char pad0[0x18];
    /* 0x18 */ s32 unk18;
};
/* Pose par `make forge`, qui a compose les reparations connues et verifie l'image entiere. Voir docs/IDIOMS.md pour le detail de chacune. */
extern "C" void MenuRoboPartsLightOff__FP8mgCFrame(mgCFrame *arg0) {
    struct temp_v0_champs_a42004 *temp_v0;

    if (arg0 != NULL) {
        temp_v0 = (struct temp_v0_champs_a42004 *) (SearchFrame__8mgCFrameFPc(arg0, &_4517_00374C70));
        if (temp_v0 != NULL) {
            temp_v0->unkF4->unk18 = 0;
        }
    }
}

INCLUDE_ASM("nonmatchings/game/cmenumosselect", MenuMonsterLoadBG__FP9mgCMemoryPP17MENU_BGREAD_INFO2ii);
INCLUDE_ASM("nonmatchings/game/cmenumosselect", MenuMonsterLoadBGCheck__FPP17MENU_BGREAD_INFO2PP12CActionCharaii);
INCLUDE_ASM("nonmatchings/game/cmenumosselect", MenuItemCharaDataLoadEndCheckAfter__FPP17MENU_BGREAD_INFO2i);
INCLUDE_ASM("nonmatchings/game/cmenumosselect", InitMainCharaBG__FiP9mgCMemoryi);
INCLUDE_ASM("nonmatchings/game/cmenumosselect", ReadMainCharaBG__Fv);
