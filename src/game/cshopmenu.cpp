/* CShopMenu, CEventSprite2, CShop, CEventSprite, CEventSpriteMother, CMarker
 *
 * Unité découpée par `make carve` : 67 fonctions, 19360 octets, de
 * 0x002931B0 à 0x00297F10. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"
#include "gen/CEventSprite.hpp"
#include "gen/CEventSprite2.hpp"
#include "gen/CMarker.hpp"

INCLUDE_ASM("nonmatchings/game/cshopmenu", LoadDungeonMapFile__FPcPci);
INCLUDE_ASM("nonmatchings/game/cshopmenu", MinimapDoorEnable__FPf);
INCLUDE_ASM("nonmatchings/game/cshopmenu", LoadMonsterFile__Fv);
INCLUDE_ASM("nonmatchings/game/cshopmenu", LoadMonsterFile__Fii);
INCLUDE_ASM("nonmatchings/game/cshopmenu", ParabolicInitialVectorY__Fffff);
INCLUDE_ASM("nonmatchings/game/cshopmenu", CalcPosParabolicJump__FPfPfPffff);
INCLUDE_ASM("nonmatchings/game/cshopmenu", Draw__7CMarkerFv);
void CMarker::Set(s32 arg0) {
    this->field_0x0 = arg0;
}
INCLUDE_ASM("nonmatchings/game/cshopmenu", Init__7CMarkerFv);
INCLUDE_ASM("nonmatchings/game/cshopmenu", SetName__12CEventSpriteFPc);
void CEventSprite::SetDraw(s32 arg0) {
    this->field_0x0 = arg0;
}
INCLUDE_ASM("nonmatchings/game/cshopmenu", SetGet__12CEventSpriteFiiii);
INCLUDE_ASM("nonmatchings/game/cshopmenu", SetPut__12CEventSpriteFiiii);
void CEventSprite::SetMove(s32 arg0, s32 arg1, s32 arg2) {
    this->field_0x78 = -1;
    this->field_0x7C = -1;
    this->field_0x80 = -1;
    this->field_0x84 = -1;
    this->field_0x78 = 0;
    this->field_0x7C = arg0;
    this->field_0x80 = arg1;
    this->field_0x84 = arg2;
}
INCLUDE_ASM("nonmatchings/game/cshopmenu", SetFade__12CEventSpriteFii);
INCLUDE_ASM("nonmatchings/game/cshopmenu", SetColor__12CEventSpriteFiiii);
INCLUDE_ASM("nonmatchings/game/cshopmenu", Step__12CEventSpriteFv);
INCLUDE_ASM("nonmatchings/game/cshopmenu", Draw__12CEventSpriteFv);
INCLUDE_ASM("nonmatchings/game/cshopmenu", Init__12CEventSpriteFv);
INCLUDE_ASM("nonmatchings/game/cshopmenu", SetName__18CEventSpriteMotherFiPc);
INCLUDE_ASM("nonmatchings/game/cshopmenu", SetDraw__18CEventSpriteMotherFii);
INCLUDE_ASM("nonmatchings/game/cshopmenu", SetGet__18CEventSpriteMotherFiiiii);
INCLUDE_ASM("nonmatchings/game/cshopmenu", SetPut__18CEventSpriteMotherFiiiii);
INCLUDE_ASM("nonmatchings/game/cshopmenu", SetMove__18CEventSpriteMotherFiiii);
INCLUDE_ASM("nonmatchings/game/cshopmenu", SetFade__18CEventSpriteMotherFiii);
INCLUDE_ASM("nonmatchings/game/cshopmenu", SetColor__18CEventSpriteMotherFiiiii);
INCLUDE_ASM("nonmatchings/game/cshopmenu", Step__18CEventSpriteMotherFv);
INCLUDE_ASM("nonmatchings/game/cshopmenu", Draw__18CEventSpriteMotherFv);
INCLUDE_ASM("nonmatchings/game/cshopmenu", Set__18CEventSpriteMotherFii);
INCLUDE_ASM("nonmatchings/game/cshopmenu", Init__18CEventSpriteMotherFv);
INCLUDE_ASM("nonmatchings/game/cshopmenu", __ct__13CEventSprite2Fv);
INCLUDE_ASM("nonmatchings/game/cshopmenu", Initialize__13CEventSprite2Fv);
INCLUDE_ASM("nonmatchings/game/cshopmenu", SetTexture__13CEventSprite2FPci);
void CEventSprite2::SetDrawFlag(s32 arg0) {
    this->field_0x0 = arg0;
}
void CEventSprite2::SetSpriteType(s32 arg0) {
    this->field_0x4 = arg0;
}
INCLUDE_ASM("nonmatchings/game/cshopmenu", SetPosition__13CEventSprite2FPf);
INCLUDE_ASM("nonmatchings/game/cshopmenu", SetColor__13CEventSprite2FPf);
void CEventSprite2::SetPutSize(s32 arg0, s32 arg1) {
    this->field_0x54 = arg0;
    this->field_0x58 = arg1;
}
INCLUDE_ASM("nonmatchings/game/cshopmenu", SetUvSize__13CEventSprite2Fiiii);
void CEventSprite2::SetScale(f32 arg0, f32 arg1) {
    this->field_0x6C = arg0;
    this->field_0x70 = arg1;
}
INCLUDE_ASM("nonmatchings/game/cshopmenu", GetScale__13CEventSprite2FPfPf);
INCLUDE_ASM("nonmatchings/game/cshopmenu", GetPosition__13CEventSprite2FPf);
INCLUDE_ASM("nonmatchings/game/cshopmenu", GetColor__13CEventSprite2FPf);
s32 CEventSprite2::GetType(void) {
    return this->field_0x4;
}
void CEventSprite2::SetAlphaBlend(s32 arg0) {
    this->field_0x2C = arg0;
}
void CEventSprite2::SetRotZ(f32 arg0) {
    this->field_0x50 = arg0;
}
f32 CEventSprite2::GetRotZ(void) {
    return this->field_0x50;
}
INCLUDE_ASM("nonmatchings/game/cshopmenu", NormalDraw__13CEventSprite2Fv);
INCLUDE_ASM("nonmatchings/game/cshopmenu", FirstDraw__13CEventSprite2Fv);
INCLUDE_ASM("nonmatchings/game/cshopmenu", Draw__13CEventSprite2Fv);
INCLUDE_ASM("nonmatchings/game/cshopmenu", GetDonyShopLineUp__FPiPi);
INCLUDE_ASM("nonmatchings/game/cshopmenu", CheckSyojiHin__5CShopFv);
INCLUDE_ASM("nonmatchings/game/cshopmenu", CheckRobotCore__Fv);
INCLUDE_ASM("nonmatchings/game/cshopmenu", CheckEventItem__5CShopFv);
INCLUDE_ASM("nonmatchings/game/cshopmenu", GetPrice__5CShopFP13CGameDataUsedPiPi);
INCLUDE_ASM("nonmatchings/game/cshopmenu", CheckMoney__5CShopFv);
INCLUDE_ASM("nonmatchings/game/cshopmenu", AddMoney__5CShopFi);
INCLUDE_ASM("nonmatchings/game/cshopmenu", _SHOP_ANALYZE__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cshopmenu", _PRICE__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cshopmenu", AnalyzeShopList__5CShopFPci);
INCLUDE_ASM("nonmatchings/game/cshopmenu", AttachForm__9CShopMenuFv);
INCLUDE_ASM("nonmatchings/game/cshopmenu", IsCancelNoneLoadItem__9CShopMenuFv);
INCLUDE_ASM("nonmatchings/game/cshopmenu", UpdataScrlBar__9CShopMenuFv);
INCLUDE_ASM("nonmatchings/game/cshopmenu", InitEnd__9CShopMenuFv);
INCLUDE_ASM("nonmatchings/game/cshopmenu", KeyStep__9CShopMenuFv);
INCLUDE_ASM("nonmatchings/game/cshopmenu", CalcTex__9CShopMenuFv);
INCLUDE_ASM("nonmatchings/game/cshopmenu", CalcCursorPosition__9CShopMenuFv);
