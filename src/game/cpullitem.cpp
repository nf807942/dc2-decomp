/* CPullItem, CLaserGun, CColPrim, CRoboVoiceSystem, CMachineGun, CColPrimMan, CRocketLauncherMan, CLaserGunMan, CPullItemManager, CTreasureBox
 *
 * Unité découpée par `make carve` : 63 fonctions, 23076 octets, de
 * 0x001B7C50 à 0x001BD800. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"
#include "gen/CColPrim.hpp"
#include "gen/CLaserGun.hpp"
#include "gen/CPullItem.hpp"
#include "gen/CRoboVoiceSystem.hpp"
#include "gen/CTreasureBox.hpp"

INCLUDE_ASM("nonmatchings/game/cpullitem", Get__18CRocketLauncherManFv);
INCLUDE_ASM("nonmatchings/game/cpullitem", Draw__18CRocketLauncherManFv);
INCLUDE_ASM("nonmatchings/game/cpullitem", Step__18CRocketLauncherManFv);
INCLUDE_ASM("nonmatchings/game/cpullitem", Clear__18CRocketLauncherManFv);
INCLUDE_ASM("nonmatchings/game/cpullitem", Initialize__18CRocketLauncherManFP8mgCFrameiP10mgCTexture);
INCLUDE_ASM("nonmatchings/game/cpullitem", Set__11CMachineGunFPfPf);
INCLUDE_ASM("nonmatchings/game/cpullitem", Step__11CMachineGunFv);
INCLUDE_ASM("nonmatchings/game/cpullitem", SetPos__9CLaserGunFPfPfPf);
INCLUDE_ASM("nonmatchings/game/cpullitem", SetVisualCode__9CLaserGunFi);
INCLUDE_ASM("nonmatchings/game/cpullitem", Step__9CLaserGunFv);
INCLUDE_ASM("nonmatchings/game/cpullitem", Draw__9CLaserGunFv);
void CLaserGun::Initialize(void) {
    this->field_0x0 = -1;
    this->field_0xD0 = 0;
    this->field_0xD4 = 0;
    this->field_0x120 = 0;
    this->field_0xE8 = -1;
    this->field_0xEC = 0;
}
INCLUDE_ASM("nonmatchings/game/cpullitem", Get__12CLaserGunManFv);
INCLUDE_ASM("nonmatchings/game/cpullitem", Draw__12CLaserGunManFv);
INCLUDE_ASM("nonmatchings/game/cpullitem", Step__12CLaserGunManFv);
INCLUDE_ASM("nonmatchings/game/cpullitem", Clear__12CLaserGunManFv);
INCLUDE_ASM("nonmatchings/game/cpullitem", Initialize__12CLaserGunManFP8mgCFrameiP10mgCTexture);
INCLUDE_ASM("nonmatchings/game/cpullitem", Draw__9CPullItemFP10mgCTexture);
INCLUDE_ASM("nonmatchings/game/cpullitem", Step__9CPullItemFv);
INCLUDE_ASM("nonmatchings/game/cpullitem", IsGet__9CPullItemFPf);
INCLUDE_ASM("nonmatchings/game/cpullitem", SetItem__9CPullItemFPfPfi);
void CPullItem::Clear(void) {
    this->field_0x74 = -1;
    this->field_0x7C = 0;
}
void CPullItem::Initialize(void) {
    this->field_0x7C = 0;
    this->field_0x42 = 0;
    this->field_0x30 = 0;
    this->field_0x32 = 0;
    this->field_0x34 = 32;
    this->field_0x36 = 32;
    this->field_0x50 = 0;
    this->field_0x44 = 0;
}
INCLUDE_ASM("nonmatchings/game/cpullitem", GetList__16CPullItemManagerFi);
INCLUDE_ASM("nonmatchings/game/cpullitem", Clear__16CPullItemManagerFv);
void CRoboVoiceSystem::SetStatus(s32 arg0, s32 arg1) {
    this->field_0x0 = 1;
    this->field_0xC = arg0;
    this->field_0x10 = arg1;
}
INCLUDE_ASM("nonmatchings/game/cpullitem", StartVoiceSystem__16CRoboVoiceSystemFv);
INCLUDE_ASM("nonmatchings/game/cpullitem", StopVoice__16CRoboVoiceSystemFi);
INCLUDE_ASM("nonmatchings/game/cpullitem", Step__16CRoboVoiceSystemFv);
INCLUDE_ASM("nonmatchings/game/cpullitem", SetDamage__8CColPrimFPci);
INCLUDE_ASM("nonmatchings/game/cpullitem", SetCoord__8CColPrimFPff);
INCLUDE_ASM("nonmatchings/game/cpullitem", SetCoord__8CColPrimFPfPff);
INCLUDE_ASM("nonmatchings/game/cpullitem", SetCoord__8CColPrimFP8mgCFramef);
INCLUDE_ASM("nonmatchings/game/cpullitem", SetCoord__8CColPrimFP8mgCFrameP8mgCFramef);
INCLUDE_ASM("nonmatchings/game/cpullitem", IsHit__8CColPrimFP6CScenei);
INCLUDE_ASM("nonmatchings/game/cpullitem", IsReversVec__8CColPrimFP8CColPrim);
INCLUDE_ASM("nonmatchings/game/cpullitem", GetReversVec__8CColPrimFPf);
void CColPrim::DebugDraw(void) {
}
INCLUDE_ASM("nonmatchings/game/cpullitem", Step__8CColPrimFv);
INCLUDE_ASM("nonmatchings/game/cpullitem", Delete__8CColPrimFi);
void CColPrim::Initialize(void) {
    this->field_0xC = 0;
    this->field_0x10 = -1;
    this->field_0x18 = 0;
    this->field_0x20 = 0;
    this->field_0x24 = -1;
    this->field_0x28 = 0;
    this->field_0xC0 = 0;
    this->field_0xE6 = 0;
    this->field_0x34 = 0;
    this->field_0x3C = 0;
    this->field_0x38 = 0;
    this->field_0x84 = 0;
    this->field_0x8C = -1;
}
INCLUDE_ASM("nonmatchings/game/cpullitem", GetPrim__11CColPrimManFv);
INCLUDE_ASM("nonmatchings/game/cpullitem", GetID2Prim__11CColPrimManFi);
INCLUDE_ASM("nonmatchings/game/cpullitem", ActivePrimNum__11CColPrimManFv);
INCLUDE_ASM("nonmatchings/game/cpullitem", Delete__11CColPrimManFi);
INCLUDE_ASM("nonmatchings/game/cpullitem", CheckHit__11CColPrimManFi);
INCLUDE_ASM("nonmatchings/game/cpullitem", IsReversVec__11CColPrimManFP8CColPrim);
INCLUDE_ASM("nonmatchings/game/cpullitem", Step__11CColPrimManFv);
INCLUDE_ASM("nonmatchings/game/cpullitem", Initialize__11CColPrimManFP6CScene);
INCLUDE_ASM("nonmatchings/game/cpullitem", dngGetDebugInfo__Fv);
INCLUDE_ASM("nonmatchings/game/cpullitem", dngDebugInit__Fv);
INCLUDE_ASM("nonmatchings/game/cpullitem", dngDebugStart__Fv);
INCLUDE_ASM("nonmatchings/game/cpullitem", dngDebugDraw__Fv);
INCLUDE_ASM("nonmatchings/game/cpullitem", dngDebugExit__Fv);
INCLUDE_ASM("nonmatchings/game/cpullitem", dngDebugKey__Fv);
void CTreasureBox::Initialize(void) {
    this->field_0x54 = 0;
    this->field_0x50 = 0;
    this->field_0x58 = 1;
}
INCLUDE_ASM("nonmatchings/game/cpullitem", DBGCMD_ReloadEnemy__Fii);
INCLUDE_ASM("nonmatchings/game/cpullitem", DrawSystemParamInfo__Fv);
INCLUDE_ASM("nonmatchings/game/cpullitem", DrawSystemParamInfo2__Fv);
INCLUDE_ASM("nonmatchings/game/cpullitem", DrawDebugWindow__Fv);
INCLUDE_ASM("nonmatchings/game/cpullitem", PrintV__FiiiP10mgCTexture9mgRect_i_iiiP7SP_RGBA);
INCLUDE_ASM("nonmatchings/game/cpullitem", DrawDrumCounter__Fiii);
INCLUDE_ASM("nonmatchings/game/cpullitem", DrawActiveItemCursor__Fiif);
