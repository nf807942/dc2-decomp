/* CMiniMapSymbol, CHealingPoint, CDamageScore, CThunder, CFireAfterHit, CChillAfterHit, CAfterWire
 *
 * Unité découpée par `make carve` : 34 fonctions, 20916 octets, de
 * 0x001D1AF0 à 0x001D6D80. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"
#include "gen/CAfterWire.hpp"

INCLUDE_ASM("nonmatchings/game/cminimapsymbol", DngStep__Fv);
INCLUDE_ASM("nonmatchings/game/cminimapsymbol", RunMainEvent__Fv);
INCLUDE_ASM("nonmatchings/game/cminimapsymbol", DngMainKey__Fv);
INCLUDE_ASM("nonmatchings/game/cminimapsymbol", IsEventRun__Fv);
INCLUDE_ASM("nonmatchings/game/cminimapsymbol", EventScriptSetup__FP18SYSTEM_SCRIPT_INFO);
INCLUDE_ASM("nonmatchings/game/cminimapsymbol", IsRunDeadEvent__FP12CActionChara);
INCLUDE_ASM("nonmatchings/game/cminimapsymbol", ChangeSetUnit__Fi);
INCLUDE_ASM("nonmatchings/game/cminimapsymbol", CheckStatusError__Fv);
INCLUDE_ASM("nonmatchings/game/cminimapsymbol", InitEyeCamera__FP12CActionChara);
INCLUDE_ASM("nonmatchings/game/cminimapsymbol", CheckWeaponEnable__Fv);
INCLUDE_ASM("nonmatchings/game/cminimapsymbol", ResetEyeView__FP12CActionChara);
INCLUDE_ASM("nonmatchings/game/cminimapsymbol", EyeCamera__FP9mgCCameraP11CCharacter2i_001D53B0);
INCLUDE_ASM("nonmatchings/game/cminimapsymbol", DebugMainDraw__Fv);
INCLUDE_ASM("nonmatchings/game/cminimapsymbol", DBGCMD_RunScript__Fi);
INCLUDE_ASM("nonmatchings/game/cminimapsymbol", __ct__13CFireAfterHitFv);
INCLUDE_ASM("nonmatchings/game/cminimapsymbol", __ct__14CChillAfterHitFv);
INCLUDE_ASM("nonmatchings/game/cminimapsymbol", __ct__8CThunderFv);
CAfterWire::CAfterWire(void) {
    this->field_0x0 = 0;
}
INCLUDE_ASM("nonmatchings/game/cminimapsymbol", __ct__12CDamageScoreFv);
INCLUDE_ASM("nonmatchings/game/cminimapsymbol", SetMapInfo__14CMiniMapSymbolFP4CMapP13CAutoMapPartsiiff);
INCLUDE_ASM("nonmatchings/game/cminimapsymbol", DrawSymbolOpen__14CMiniMapSymbolFv);
INCLUDE_ASM("nonmatchings/game/cminimapsymbol", DrawSymbolClose__14CMiniMapSymbolFv);
INCLUDE_ASM("nonmatchings/game/cminimapsymbol", DrawSymbol__14CMiniMapSymbolFPfi);
INCLUDE_ASM("nonmatchings/game/cminimapsymbol", DrawSymbol_Chara__14CMiniMapSymbolFP11CCharacter2);
INCLUDE_ASM("nonmatchings/game/cminimapsymbol", Draw__14CMiniMapSymbolFPf);
INCLUDE_ASM("nonmatchings/game/cminimapsymbol", CheckHealingTime__13CHealingPointFv);
INCLUDE_ASM("nonmatchings/game/cminimapsymbol", Step__13CHealingPointFv);
INCLUDE_ASM("nonmatchings/game/cminimapsymbol", _ROOM_FIXED__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cminimapsymbol", _GRID_SIZE__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cminimapsymbol", _ROOM_ID__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cminimapsymbol", _ROOM_SIZE__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cminimapsymbol", _ROOM_RATE__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cminimapsymbol", _RD__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cminimapsymbol", _ROOM_END__FP9SPI_STACKi);
