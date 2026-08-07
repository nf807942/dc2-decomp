/* CShopMenu, CEventSprite2, CShop, CEventSprite, CEventSpriteMother, CMarker
 *
 * Unité découpée par `make carve` : 67 fonctions, 19360 octets, de
 * 0x002931B0 à 0x00297F10. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

INCLUDE_ASM("nonmatchings/game/cshopmenu", LoadDungeonMapFile__FPcPci);
INCLUDE_ASM("nonmatchings/game/cshopmenu", MinimapDoorEnable__FPf);
INCLUDE_ASM("nonmatchings/game/cshopmenu", LoadMonsterFile__Fv);
INCLUDE_ASM("nonmatchings/game/cshopmenu", LoadMonsterFile__Fii);
INCLUDE_ASM("nonmatchings/game/cshopmenu", ParabolicInitialVectorY__Fffff);
INCLUDE_ASM("nonmatchings/game/cshopmenu", CalcPosParabolicJump__FPfPfPffff);
INCLUDE_ASM("nonmatchings/game/cshopmenu", Draw__7CMarkerFv);
INCLUDE_ASM("nonmatchings/game/cshopmenu", Set__7CMarkerFi);
INCLUDE_ASM("nonmatchings/game/cshopmenu", Init__7CMarkerFv);
INCLUDE_ASM("nonmatchings/game/cshopmenu", SetName__12CEventSpriteFPc);
INCLUDE_ASM("nonmatchings/game/cshopmenu", SetDraw__12CEventSpriteFi);
INCLUDE_ASM("nonmatchings/game/cshopmenu", SetGet__12CEventSpriteFiiii);
INCLUDE_ASM("nonmatchings/game/cshopmenu", SetPut__12CEventSpriteFiiii);
INCLUDE_ASM("nonmatchings/game/cshopmenu", SetMove__12CEventSpriteFiii);
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
INCLUDE_ASM("nonmatchings/game/cshopmenu", SetDrawFlag__13CEventSprite2Fi);
INCLUDE_ASM("nonmatchings/game/cshopmenu", SetSpriteType__13CEventSprite2Fi);
INCLUDE_ASM("nonmatchings/game/cshopmenu", SetPosition__13CEventSprite2FPf);
INCLUDE_ASM("nonmatchings/game/cshopmenu", SetColor__13CEventSprite2FPf);
INCLUDE_ASM("nonmatchings/game/cshopmenu", SetPutSize__13CEventSprite2Fii);
INCLUDE_ASM("nonmatchings/game/cshopmenu", SetUvSize__13CEventSprite2Fiiii);
INCLUDE_ASM("nonmatchings/game/cshopmenu", SetScale__13CEventSprite2Fff);
INCLUDE_ASM("nonmatchings/game/cshopmenu", GetScale__13CEventSprite2FPfPf);
INCLUDE_ASM("nonmatchings/game/cshopmenu", GetPosition__13CEventSprite2FPf);
INCLUDE_ASM("nonmatchings/game/cshopmenu", GetColor__13CEventSprite2FPf);
INCLUDE_ASM("nonmatchings/game/cshopmenu", GetType__13CEventSprite2Fv);
INCLUDE_ASM("nonmatchings/game/cshopmenu", SetAlphaBlend__13CEventSprite2Fi);
INCLUDE_ASM("nonmatchings/game/cshopmenu", SetRotZ__13CEventSprite2Ff);
INCLUDE_ASM("nonmatchings/game/cshopmenu", GetRotZ__13CEventSprite2Fv);
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
