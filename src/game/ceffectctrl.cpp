/* CEffectCtrl, CEffect, CEffectManager, CFadeInOut, COutLineDraw, CEffectList, mgC3DSprite
 *
 * Unité découpée par `make carve` : 106 fonctions, 28064 octets, de
 * 0x0017D680 à 0x001846F0. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"
#include "gen/CEffectCtrl.hpp"
#include "gen/CEffectManager.hpp"
#include "gen/CFadeInOut.hpp"
#include "gen/COutLineDraw.hpp"
struct mgCFrame;


INCLUDE_ASM("nonmatchings/game/ceffectctrl", Initialize__12COutLineDrawFv);
void COutLineDraw::SetFrame(mgCFrame * arg0) {
    this->field_0x34 = arg0;
}
INCLUDE_ASM("nonmatchings/game/ceffectctrl", Draw__12COutLineDrawFPfff);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", Draw__12COutLineDrawFff);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", DrawDivSprite__FP11mgCDrawPrim9mgRect_i_P10mgCTexturePiiiii);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", DrawDivSprite4__FP11mgCDrawPrim9mgRect_i_P10mgCTexturePiii);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", LoadEFPFile__11CEffectListFPcPUiiP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", __ct__11mgC3DSpriteFv);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", SaerchEffectIndex__11CEffectListFPc);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", GetEffectVisual__11CEffectListFi);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", Step__11CEffectListFv);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", CreatePacket__11CEffectListFv);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", CreatePacket__14CEffectManagerFP11mgC3DSprite);
void CFadeInOut::Initialize(void) {
    this->field_0xC = 0;
    this->field_0x8 = 0;
    this->field_0x4 = 0;
    this->field_0x0 = 0;
    this->field_0x10 = 0;
    this->field_0x18 = 0;
    this->field_0x14 = 0;
    this->field_0x20 = 0;
    this->field_0x28 = 0;
    this->field_0x2C = 0;
}
void CFadeInOut::ResetFade(void) {
    this->field_0x10 = 0;
    this->field_0xC = 0;
    this->field_0x20 = 0;
}
INCLUDE_ASM("nonmatchings/game/ceffectctrl", FadeIn__10CFadeInOutFifff);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", FadeIn__10CFadeInOutFi);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", FadeOut__10CFadeInOutFifff);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", CrossFade__10CFadeInOutFif);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", CrossFadeIn__10CFadeInOutFiif);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", CrossFadeOut__10CFadeInOutFiif);
s32 CFadeInOut::FadeCheck(void) {
    return this->field_0x14;
}
INCLUDE_ASM("nonmatchings/game/ceffectctrl", NowFade__10CFadeInOutFv);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", FadeStep__10CFadeInOutFv);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", SetCrossTexture__10CFadeInOutFP10mgCTextureP1);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", CaptureScreen__10CFadeInOutFv);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", DivSpriteScreen__FR11mgCDrawPrim_0017EF10);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", DivSpriteScreen__FR11mgCDrawPrimiii);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", Draw__10CFadeInOutFv);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", DepthOfField__FiPfP10mgCTexturef);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", LensFlare__FPiPfiPcPc);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", UniformityRand__Fff);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", RegularityRand__Fffi);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", InitEffectParam__FP12EFFECT_PARAM);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", __ct__7CEffectFv);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", Initialize__7CEffectFv);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", SetEffect__7CEffectFP12EFFECT_PARAM);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", Step__7CEffectFi);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", Draw__7CEffectFv);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", __ct__11CEffectCtrlFv);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", __dt__11CEffectCtrlFv);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", Ctrl__11CEffectCtrlFP7CEffecti);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", Initialize__11CEffectCtrlFv);
void CEffectCtrl::Run(void) {
    this->field_0x10 = 1;
    this->field_0x50 = 0;
    this->field_0x64 = 0;
}
INCLUDE_ASM("nonmatchings/game/ceffectctrl", SetOrigin__11CEffectCtrlFPf);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", __as__11CEffectCtrlFRC11CEffectCtrl);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", __BUFFER_SIZE__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", __EFFECT_START__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", __EFFECT_END__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", __WAIT_FRAME__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", __IMG_NAME__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", __SIZE__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", __DIR__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", __NUM__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", __NUM_RAND__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", __COUNT__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", __CNT_RAND__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", __REPEAT__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", __REP_RAND__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", __POS__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", __POS_RAND__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", __VELO__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", __VELO_RAND__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", __VELO_MUL__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", __ACC__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", __ACC_RAND__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", __ACC_MUL__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", __MOVE_TYPE__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", __MOVE_P1__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", __MOVE_P1_RAND__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", __MOVE_P2__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", __MOVE_P2_RAND__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", __SCALE_TYPE__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", __SCALE__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", __SCALE_RAND__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", __SVELO__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", __SVELO_RAND__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", __SCALE_P1__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", __SCALE_P1_RAND__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", __SCALE_P2__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", __SCALE_P2_RAND__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", __ALPHA_BLEND__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", __ALPHA_TYPE__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", __ALPHA__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", __ALPHA_RAND__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", __ALPHA_P1__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", __ALPHA_P1_RAND__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", __ALPHA_P2__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", __ALPHA_P2_RAND__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", __TEX_GET_RECT__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", __TEX_GET_TYPE__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", __TEX_NAME__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", __GRAVITY__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", __ct__14CEffectManagerFv);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", Initialize__14CEffectManagerFv);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", EntryEffCtrls__14CEffectManagerFP7CEffectiP11CEffectCtrli);
void CEffectManager::SetEffectNums(s32 arg0, s32 arg1) {
    this->field_0x24 = arg0;
    this->field_0x2C = arg1;
}
INCLUDE_ASM("nonmatchings/game/ceffectctrl", Ctrl__14CEffectManagerFv);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", Step__14CEffectManagerFi);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", Draw__14CEffectManagerFv);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", Run__14CEffectManagerFv);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", Stop__14CEffectManagerFv);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", EnterEffectCtrl__14CEffectManagerF11CEffectCtrlPc);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", GetBufferNums__14CEffectManagerFPciPiPi);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", Load__14CEffectManagerFPci);
INCLUDE_ASM("nonmatchings/game/ceffectctrl", SetOrigin__14CEffectManagerFPf);
