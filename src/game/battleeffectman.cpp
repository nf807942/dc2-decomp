/* BattleEffectMan, CHitEffectImage, CDeadEffect, CMapEffect_Sprite, CThunder, CSWordAfterImage, CMapEffectsManeger, CHealingEffectMan, CPowerLine, CSparcEffect, CSwordLuminous, CFlushEffect, CAfterWire, CMiniEffPrim, CMiniEffPrimMan, CPalletAnime, CCharacter2
 *
 * Unité découpée par `make carve` : 61 fonctions, 22208 octets, de
 * 0x001C17C0 à 0x001C6FD0. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"
#include "gen/CAfterWire.hpp"
#include "gen/CThunder.hpp"
#include "gen/CHealingEffectMan.hpp"
#include "gen/CMiniEffPrim.hpp"
#include "gen/CPalletAnime.hpp"
#include "gen/CSparcEffect.hpp"

INCLUDE_ASM("nonmatchings/game/battleeffectman", SetPos__8CThunderFPfff);
INCLUDE_ASM("nonmatchings/game/battleeffectman", Draw__8CThunderFv);
INCLUDE_ASM("nonmatchings/game/battleeffectman", Step__8CThunderFv);
void CThunder::Initialize(void) {
    this->field_0xDB0 = 0;
    this->field_0xDB1 = 0;
    this->field_0xF4 = &this->field_0x110;
}
INCLUDE_ASM("nonmatchings/game/battleeffectman", Draw__12CSparcEffectFv);
INCLUDE_ASM("nonmatchings/game/battleeffectman", Step__12CSparcEffectFv);
void CSparcEffect::Initialize(void) {
    this->field_0xA9 = 0;
}
INCLUDE_ASM("nonmatchings/game/battleeffectman", SetPrim__12CMiniEffPrimFPfi);
INCLUDE_ASM("nonmatchings/game/battleeffectman", Draw__12CMiniEffPrimFP10CPreSprite);
INCLUDE_ASM("nonmatchings/game/battleeffectman", Step__12CMiniEffPrimFv);
void CMiniEffPrim::Initialize(void) {
    this->field_0x10 = 0;
}
INCLUDE_ASM("nonmatchings/game/battleeffectman", CreatPrim__15CMiniEffPrimManFPfi);
INCLUDE_ASM("nonmatchings/game/battleeffectman", Draw__15CMiniEffPrimManFv);
INCLUDE_ASM("nonmatchings/game/battleeffectman", Step__15CMiniEffPrimManFv);
INCLUDE_ASM("nonmatchings/game/battleeffectman", Initialize__15CMiniEffPrimManFv);
INCLUDE_ASM("nonmatchings/game/battleeffectman", SetAnim__12CPalletAnimeFssssss);
INCLUDE_ASM("nonmatchings/game/battleeffectman", CreatPallet__12CPalletAnimeFPfPf);
INCLUDE_ASM("nonmatchings/game/battleeffectman", Step__12CPalletAnimeFv);
void CPalletAnime::Initialize(void) {
    this->field_0xA = 0;
    this->field_0x8 = 0;
}
INCLUDE_ASM("nonmatchings/game/battleeffectman", Draw__17CHealingEffectManFP9mgCCamera);
INCLUDE_ASM("nonmatchings/game/battleeffectman", Step__17CHealingEffectManFv);
void CHealingEffectMan::SetMode(s32 arg0) {
    this->field_0x314 = arg0;
}
INCLUDE_ASM("nonmatchings/game/battleeffectman", Set__17CHealingEffectManFPf);
INCLUDE_ASM("nonmatchings/game/battleeffectman", Initialize__17CHealingEffectManFv);
INCLUDE_ASM("nonmatchings/game/battleeffectman", Draw__14CSwordLuminousFv);
INCLUDE_ASM("nonmatchings/game/battleeffectman", Step__14CSwordLuminousFv);
INCLUDE_ASM("nonmatchings/game/battleeffectman", Draw__16CSWordAfterImageFv);
INCLUDE_ASM("nonmatchings/game/battleeffectman", CreatPointList__16CSWordAfterImageFv);
INCLUDE_ASM("nonmatchings/game/battleeffectman", AddPoint__16CSWordAfterImageFPfPff);
INCLUDE_ASM("nonmatchings/game/battleeffectman", Step__16CSWordAfterImageFv);
INCLUDE_ASM("nonmatchings/game/battleeffectman", Initialize__16CSWordAfterImageFP9mgCMemoryii);
void CAfterWire::SetMode(s32 arg0) {
    this->field_0x0 = arg0;
    this->field_0x116 = 0;
    this->field_0x118 = 0;
    this->field_0x112 = 0;
    this->field_0x114 = 0;
}
INCLUDE_ASM("nonmatchings/game/battleeffectman", SetPos__10CAfterWireFPf);
INCLUDE_ASM("nonmatchings/game/battleeffectman", DrawWire__10CAfterWireFPA4_f);
INCLUDE_ASM("nonmatchings/game/battleeffectman", StepWire__10CAfterWireFv);
INCLUDE_ASM("nonmatchings/game/battleeffectman", SethitEffect__15CHitEffectImageFPfPfffffii);
INCLUDE_ASM("nonmatchings/game/battleeffectman", Step__15CHitEffectImageFv);
INCLUDE_ASM("nonmatchings/game/battleeffectman", Draw__15CHitEffectImageFv);
INCLUDE_ASM("nonmatchings/game/battleeffectman", DrawBord__15CHitEffectImageFv);
INCLUDE_ASM("nonmatchings/game/battleeffectman", DrawSpark__15CHitEffectImageFf);
INCLUDE_ASM("nonmatchings/game/battleeffectman", Draw__12CFlushEffectFv);
INCLUDE_ASM("nonmatchings/game/battleeffectman", Step__12CFlushEffectFv);
INCLUDE_ASM("nonmatchings/game/battleeffectman", CreatPrim__10CPowerLineFv);
INCLUDE_ASM("nonmatchings/game/battleeffectman", Step__10CPowerLineFv);
INCLUDE_ASM("nonmatchings/game/battleeffectman", Draw__10CPowerLineFv);
INCLUDE_ASM("nonmatchings/game/battleeffectman", SetDeadEffect__11CDeadEffectFPffffi);
INCLUDE_ASM("nonmatchings/game/battleeffectman", CreatPrim__11CDeadEffectFi);
INCLUDE_ASM("nonmatchings/game/battleeffectman", Step__11CDeadEffectFv);
INCLUDE_ASM("nonmatchings/game/battleeffectman", Draw__11CDeadEffectFv);
INCLUDE_ASM("nonmatchings/game/battleeffectman", Set__17CMapEffect_SpriteFPf);
INCLUDE_ASM("nonmatchings/game/battleeffectman", Step__17CMapEffect_SpriteFP9mgCCamera);
INCLUDE_ASM("nonmatchings/game/battleeffectman", Draw__17CMapEffect_SpriteFP9mgCCameraP10CPreSprite);
INCLUDE_ASM("nonmatchings/game/battleeffectman", Init_LightBoll__18CMapEffectsManegerFP9mgCMemoryi);
INCLUDE_ASM("nonmatchings/game/battleeffectman", Step__18CMapEffectsManegerFP9mgCCamera);
INCLUDE_ASM("nonmatchings/game/battleeffectman", Draw__18CMapEffectsManegerFP9mgCCamera);
INCLUDE_ASM("nonmatchings/game/battleeffectman", AllocEffect__15BattleEffectManFiP9mgCMemoryi);
INCLUDE_ASM("nonmatchings/game/battleeffectman", __ct__11CCharacter2Fv);
INCLUDE_ASM("nonmatchings/game/battleeffectman", __ct__10CPowerLineFv);
INCLUDE_ASM("nonmatchings/game/battleeffectman", __ct__15CHitEffectImageFv);
INCLUDE_ASM("nonmatchings/game/battleeffectman", Step__15BattleEffectManFv);
INCLUDE_ASM("nonmatchings/game/battleeffectman", Draw__15BattleEffectManFv);
