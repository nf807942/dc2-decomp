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
extern "C" u8 AutoMapGen[672];
extern "C" s32 MinimapDoorOpen__11CAutoMapGenFPf(void *, f32 *);
extern "C" s32 UpdateNaviMap__11CAutoMapGenFPfi(void *, f32 *, s32);
extern "C" void MinimapDoorEnable__FPf(f32 *arg0) {
    MinimapDoorOpen__11CAutoMapGenFPf(&AutoMapGen, arg0);
    UpdateNaviMap__11CAutoMapGenFPfi(&AutoMapGen, arg0, 4);
}
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
struct inferred;
typedef struct CEventSprite_infere {
    /* 0x00 */ char pad0[0x78];
    /* 0x78 */ s32 unk78;                           /* inferred */
    /* 0x7C */ s32 unk7C;                           /* inferred */
    /* 0x80 */ s32 unk80;                           /* inferred */
    /* 0x84 */ s32 unk84;                           /* inferred */
} CEventSprite_infere;                                     /* size >= 0x88 */
extern "C" void SetFade__12CEventSpriteFii(CEventSprite_infere *objet, s32 arg0, s32 arg1) {
    objet->unk78 = -1;
    objet->unk7C = -1;
    objet->unk80 = -1;
    objet->unk84 = -1;
    objet->unk78 = 1;
    if (arg0 != 0) {
        objet->unk7C = 0x80;
    } else {
        objet->unk7C = 0;
    }
    objet->unk80 = arg1;
}
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
extern "C" s32 Initialize__13CEventSprite2Fv(void *);
extern "C" CEventSprite2 *__ct__13CEventSprite2Fv(CEventSprite2 *objet) {
    Initialize__13CEventSprite2Fv(objet);
    return objet;
}
INCLUDE_ASM("nonmatchings/game/cshopmenu", Initialize__13CEventSprite2Fv);
struct inferred;
typedef struct CEventSprite2_infere {
    /* 0x0 */ char pad0[8];
    /* 0x8 */ s32 unk8;                             /* inferred */
    /* 0xC */ char unkC;                               /* inferred */
    /* 0xC */ char padC[1];
} CEventSprite2_infere;                                    /* size >= 0xD */
extern "C" s32 strcpy(...);
extern "C" void SetTexture__13CEventSprite2FPci(CEventSprite2_infere *objet, s8 *arg0, s32 arg1) {
    strcpy(&objet->unkC);
    objet->unk8 = arg1;
}
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
typedef struct CEventSprite2_infere2 {
    /* 0x0 */ s32 unk0;                             /* inferred */
} CEventSprite2_infere2;                                    /* size >= 0x4 */
extern "C" s32 Draw__13CEventSprite2Fv(void *);
extern "C" void NormalDraw__13CEventSprite2Fv(CEventSprite2_infere2 *objet) {
    if (objet->unk0 == 1) {
        Draw__13CEventSprite2Fv(objet);
    }
}
typedef struct CEventSprite2_infere3 {
    /* 0x0 */ s32 unk0;                             /* inferred */
} CEventSprite2_infere3;                                    /* size >= 0x4 */
extern "C" void FirstDraw__13CEventSprite2Fv(CEventSprite2_infere3 *objet) {
    if (objet->unk0 == 2) {
        Draw__13CEventSprite2Fv(objet);
    }
}
INCLUDE_ASM("nonmatchings/game/cshopmenu", Draw__13CEventSprite2Fv);
INCLUDE_ASM("nonmatchings/game/cshopmenu", GetDonyShopLineUp__FPiPi);
INCLUDE_ASM("nonmatchings/game/cshopmenu", CheckSyojiHin__5CShopFv);
extern "C" s32 GetUserDataMan__Fv(void);
extern "C" s32 CheckRobotCore__16CUserDataManagerFv(...);
extern "C" void CheckRobotCore__Fv(void) {
    CheckRobotCore__16CUserDataManagerFv(GetUserDataMan__Fv());
}
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
