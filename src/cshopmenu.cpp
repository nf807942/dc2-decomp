/* CShopMenu, CEventSprite2, CShop, CEventSprite, CEventSpriteMother, CMarker
 *
 * Unité découpée par `make carve` : 67 fonctions, 19360 octets, de
 * 0x002931B0 à 0x00297F10. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

INCLUDE_ASM("nonmatchings/cshopmenu", LoadDungeonMapFile__FPcPci);
INCLUDE_ASM("nonmatchings/cshopmenu", MinimapDoorEnable__FPf);
INCLUDE_ASM("nonmatchings/cshopmenu", LoadMonsterFile__Fv);
INCLUDE_ASM("nonmatchings/cshopmenu", LoadMonsterFile__Fii);
INCLUDE_ASM("nonmatchings/cshopmenu", ParabolicInitialVectorY__Fffff);
INCLUDE_ASM("nonmatchings/cshopmenu", CalcPosParabolicJump__FPfPfPffff);
INCLUDE_ASM("nonmatchings/cshopmenu", Draw__7CMarkerFv);
INCLUDE_ASM("nonmatchings/cshopmenu", Set__7CMarkerFi);
INCLUDE_ASM("nonmatchings/cshopmenu", Init__7CMarkerFv);
INCLUDE_ASM("nonmatchings/cshopmenu", SetName__12CEventSpriteFPc);
INCLUDE_ASM("nonmatchings/cshopmenu", SetDraw__12CEventSpriteFi);
INCLUDE_ASM("nonmatchings/cshopmenu", SetGet__12CEventSpriteFiiii);
INCLUDE_ASM("nonmatchings/cshopmenu", SetPut__12CEventSpriteFiiii);
INCLUDE_ASM("nonmatchings/cshopmenu", SetMove__12CEventSpriteFiii);
INCLUDE_ASM("nonmatchings/cshopmenu", SetFade__12CEventSpriteFii);
INCLUDE_ASM("nonmatchings/cshopmenu", SetColor__12CEventSpriteFiiii);
INCLUDE_ASM("nonmatchings/cshopmenu", Step__12CEventSpriteFv);
INCLUDE_ASM("nonmatchings/cshopmenu", Draw__12CEventSpriteFv);
INCLUDE_ASM("nonmatchings/cshopmenu", Init__12CEventSpriteFv);
INCLUDE_ASM("nonmatchings/cshopmenu", SetName__18CEventSpriteMotherFiPc);
INCLUDE_ASM("nonmatchings/cshopmenu", SetDraw__18CEventSpriteMotherFii);
INCLUDE_ASM("nonmatchings/cshopmenu", SetGet__18CEventSpriteMotherFiiiii);
INCLUDE_ASM("nonmatchings/cshopmenu", SetPut__18CEventSpriteMotherFiiiii);
INCLUDE_ASM("nonmatchings/cshopmenu", SetMove__18CEventSpriteMotherFiiii);
INCLUDE_ASM("nonmatchings/cshopmenu", SetFade__18CEventSpriteMotherFiii);
INCLUDE_ASM("nonmatchings/cshopmenu", SetColor__18CEventSpriteMotherFiiiii);
INCLUDE_ASM("nonmatchings/cshopmenu", Step__18CEventSpriteMotherFv);
INCLUDE_ASM("nonmatchings/cshopmenu", Draw__18CEventSpriteMotherFv);
INCLUDE_ASM("nonmatchings/cshopmenu", Set__18CEventSpriteMotherFii);
INCLUDE_ASM("nonmatchings/cshopmenu", Init__18CEventSpriteMotherFv);
INCLUDE_ASM("nonmatchings/cshopmenu", __ct__13CEventSprite2Fv);
INCLUDE_ASM("nonmatchings/cshopmenu", Initialize__13CEventSprite2Fv);
INCLUDE_ASM("nonmatchings/cshopmenu", SetTexture__13CEventSprite2FPci);
INCLUDE_ASM("nonmatchings/cshopmenu", SetDrawFlag__13CEventSprite2Fi);
INCLUDE_ASM("nonmatchings/cshopmenu", SetSpriteType__13CEventSprite2Fi);
INCLUDE_ASM("nonmatchings/cshopmenu", SetPosition__13CEventSprite2FPf);
INCLUDE_ASM("nonmatchings/cshopmenu", SetColor__13CEventSprite2FPf);
INCLUDE_ASM("nonmatchings/cshopmenu", SetPutSize__13CEventSprite2Fii);
INCLUDE_ASM("nonmatchings/cshopmenu", SetUvSize__13CEventSprite2Fiiii);
INCLUDE_ASM("nonmatchings/cshopmenu", SetScale__13CEventSprite2Fff);
INCLUDE_ASM("nonmatchings/cshopmenu", GetScale__13CEventSprite2FPfPf);
INCLUDE_ASM("nonmatchings/cshopmenu", GetPosition__13CEventSprite2FPf);
INCLUDE_ASM("nonmatchings/cshopmenu", GetColor__13CEventSprite2FPf);
INCLUDE_ASM("nonmatchings/cshopmenu", GetType__13CEventSprite2Fv);
INCLUDE_ASM("nonmatchings/cshopmenu", SetAlphaBlend__13CEventSprite2Fi);
INCLUDE_ASM("nonmatchings/cshopmenu", SetRotZ__13CEventSprite2Ff);
INCLUDE_ASM("nonmatchings/cshopmenu", GetRotZ__13CEventSprite2Fv);
INCLUDE_ASM("nonmatchings/cshopmenu", NormalDraw__13CEventSprite2Fv);
INCLUDE_ASM("nonmatchings/cshopmenu", FirstDraw__13CEventSprite2Fv);
INCLUDE_ASM("nonmatchings/cshopmenu", Draw__13CEventSprite2Fv);
INCLUDE_ASM("nonmatchings/cshopmenu", GetDonyShopLineUp__FPiPi);
INCLUDE_ASM("nonmatchings/cshopmenu", CheckSyojiHin__5CShopFv);
INCLUDE_ASM("nonmatchings/cshopmenu", CheckRobotCore__Fv);
INCLUDE_ASM("nonmatchings/cshopmenu", CheckEventItem__5CShopFv);
INCLUDE_ASM("nonmatchings/cshopmenu", GetPrice__5CShopFP13CGameDataUsedPiPi);
INCLUDE_ASM("nonmatchings/cshopmenu", CheckMoney__5CShopFv);
INCLUDE_ASM("nonmatchings/cshopmenu", AddMoney__5CShopFi);
INCLUDE_ASM("nonmatchings/cshopmenu", _SHOP_ANALYZE__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/cshopmenu", _PRICE__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/cshopmenu", AnalyzeShopList__5CShopFPci);
INCLUDE_ASM("nonmatchings/cshopmenu", AttachForm__9CShopMenuFv);
INCLUDE_ASM("nonmatchings/cshopmenu", IsCancelNoneLoadItem__9CShopMenuFv);
INCLUDE_ASM("nonmatchings/cshopmenu", UpdataScrlBar__9CShopMenuFv);
INCLUDE_ASM("nonmatchings/cshopmenu", InitEnd__9CShopMenuFv);
INCLUDE_ASM("nonmatchings/cshopmenu", KeyStep__9CShopMenuFv);
INCLUDE_ASM("nonmatchings/cshopmenu", CalcTex__9CShopMenuFv);
INCLUDE_ASM("nonmatchings/cshopmenu", CalcCursorPosition__9CShopMenuFv);
