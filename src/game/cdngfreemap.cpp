/* CDngFreeMap, CPreSprite
 *
 * Unité découpée par `make carve` : 73 fonctions, 33988 octets, de
 * 0x001E8790 à 0x001F0E00. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"
#include "gen/CDngFreeMap.hpp"

INCLUDE_ASM("nonmatchings/game/cdngfreemap", _CHECK_PAUSE__FP12RS_STACKDATAi_001E8790);
INCLUDE_ASM("nonmatchings/game/cdngfreemap", _GET_BIT_FLAG__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/cdngfreemap", _SET_BIT_FLAG__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/cdngfreemap", _GET_ATT_TYPE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/cdngfreemap", _GET_USER_ATTR__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/cdngfreemap", _TRANS_RESERV_IMG__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/cdngfreemap", _GET_STS_ATTR__FP12RS_STACKDATAi);
typedef struct nowMonster_pointe {
    char pad0[4720];
    s32 unk1270;
    char pad1274[196];
    s16 unk1338;
    s16 unk133A;
} nowMonster_pointe;
extern "C" nowMonster_pointe *nowMonster;
struct nowMonster_pointe;
#include "runscript.hpp"
struct inferred;
struct mgCObject;
typedef struct mgCObject {
    /* 0x0000 */ char pad0[0x1270];
    /* 0x1270 */ char pad1270[0xC8];
    /* 0x1338 */ s16 unk1338;                       /* inferred */
    /* 0x133A */ s16 unk133A;                       /* inferred */
} mgCObject;                                        /* size >= 0x133C */
extern "C" s32 Set__7CPiyoriFP9mgCObjects(...);
extern "C" s32 _SET_PIYORI_MARK__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    nowMonster->unk1338 = nowMonster->unk133A;
    Set__7CPiyoriFP9mgCObjects(&nowMonster->unk1270, nowMonster, nowMonster->unk1338);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/cdngfreemap", _CHECK_PIYORI__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/cdngfreemap", _GET_BASE_ATTACK__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/cdngfreemap", _GET_NEAR_MONS_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/cdngfreemap", _SET_INDEXOBJ_SIZE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/cdngfreemap", _GET_INDEXOBJ_SIZE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/cdngfreemap", _SET_MOTION_BLUR__FP12RS_STACKDATAi_001E8CF0);
INCLUDE_ASM("nonmatchings/game/cdngfreemap", _MONS_SE_PLAY__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/cdngfreemap", _MONS_SE_STOP__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/cdngfreemap", _MONS_SE_LOOP__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/cdngfreemap", _MONS_VOL_CTRL__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/cdngfreemap", _SET_MAPOBJ_SHOW__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/cdngfreemap", SetMonsterScript__FP10CRunScriptPcP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/cdngfreemap", SetMonsterExtendTable__Fv);
struct mgCDrawPrim;
struct CPreSprite;
extern "C" s32 AlphaBlendEnable__11mgCDrawPrimFi(void *, s32);
extern "C" s32 AlphaBlend__11mgCDrawPrimFi(void *, s32);
extern "C" s32 AlphaTestEnable__11mgCDrawPrimFi(void *, s32);
extern "C" s32 AlphaTest__11mgCDrawPrimFii(void *, s32, s32);
extern "C" s32 Bilinear__11mgCDrawPrimFi(void *, s32);
extern "C" s32 DepthTestEnable__11mgCDrawPrimFi(void *, s32);
extern "C" s32 TextureMapEnable__11mgCDrawPrimFi(void *, s32);
extern "C" s32 ZMask__11mgCDrawPrimFi(void *, s32);
extern "C" void Preset2D__10CPreSpriteFv(CPreSprite *objet) {
    AlphaBlendEnable__11mgCDrawPrimFi((mgCDrawPrim *) objet, 1);
    AlphaBlend__11mgCDrawPrimFi((mgCDrawPrim *) objet, 1);
    AlphaTestEnable__11mgCDrawPrimFi((mgCDrawPrim *) objet, 1);
    AlphaTest__11mgCDrawPrimFii((mgCDrawPrim *) objet, 1, 0);
    DepthTestEnable__11mgCDrawPrimFi((mgCDrawPrim *) objet, 0);
    ZMask__11mgCDrawPrimFi((mgCDrawPrim *) objet, -1);
    Bilinear__11mgCDrawPrimFi((mgCDrawPrim *) objet, 0);
    TextureMapEnable__11mgCDrawPrimFi((mgCDrawPrim *) objet, 1);
}
struct mgCDrawPrim;
extern "C" s32 TextureCrd__11mgCDrawPrimFii(void *, s32, s32);
struct CPreSprite;
extern "C" s32 Vertex__11mgCDrawPrimFiii(void *, s32, s32, s32);
extern "C" void SetIRect__10CPreSpriteFiiiiii(CPreSprite *objet, s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    TextureCrd__11mgCDrawPrimFii((mgCDrawPrim *) objet, arg4, arg5);
    Vertex__11mgCDrawPrimFiii((mgCDrawPrim *) objet, arg0, arg1, 0);
    TextureCrd__11mgCDrawPrimFii((mgCDrawPrim *) objet, arg4 + arg2, arg5 + arg3);
    Vertex__11mgCDrawPrimFiii((mgCDrawPrim *) objet, arg0 + arg2, arg1 + arg3, 0);
}
struct CPreSprite;
#include "gen/mgCDrawPrim.hpp"
extern "C" s32 TextureCrd__11mgCDrawPrimFii(void *, s32, s32);
extern "C" s32 Vertex__11mgCDrawPrimFiii(void *, s32, s32, s32);
extern "C" void SetIStretch__10CPreSpriteFiiiiiiii(CPreSprite *objet, s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    TextureCrd__11mgCDrawPrimFii((mgCDrawPrim *) objet, arg4, arg5);
    Vertex__11mgCDrawPrimFiii((mgCDrawPrim *) objet, arg0, arg1, 0);
    TextureCrd__11mgCDrawPrimFii((mgCDrawPrim *) objet, arg4 + arg6, arg5 + arg7);
    Vertex__11mgCDrawPrimFiii((mgCDrawPrim *) objet, arg0 + arg2, arg1 + arg3, 0);
}
INCLUDE_ASM("nonmatchings/game/cdngfreemap", SetScirror__10CPreSpriteFiiii);
INCLUDE_ASM("nonmatchings/game/cdngfreemap", SetAlphaBlend__10CPreSpriteFi);
INCLUDE_ASM("nonmatchings/game/cdngfreemap", GetTextureInfo__FP6CScene);
INCLUDE_ASM("nonmatchings/game/cdngfreemap", MainTextureInterface__FP9mgCMemoryP6CScene);
INCLUDE_ASM("nonmatchings/game/cdngfreemap", calcWeaponParamWhp__FP14CActiveMonsterP8CColPrim);
INCLUDE_ASM("nonmatchings/game/cdngfreemap", calcWeaponParam2__Fii);
INCLUDE_ASM("nonmatchings/game/cdngfreemap", SetDamageParam__FP8CColPrimi);
INCLUDE_ASM("nonmatchings/game/cdngfreemap", AddExpWeaponParam__Ffii);
INCLUDE_ASM("nonmatchings/game/cdngfreemap", SetSwordBlurEffect__FP11CCharacter2P9mgCMemoryi);
INCLUDE_ASM("nonmatchings/game/cdngfreemap", GetCharacterSnd__FP16CUserDataManageriPc);
INCLUDE_ASM("nonmatchings/game/cdngfreemap", SetupMainUnit__FP1P9mgCMemoryP9mgCMemoryiP6CSceneP16CUserDataManagerii);
INCLUDE_ASM("nonmatchings/game/cdngfreemap", GetCharaMemAllocSize__Fv);
INCLUDE_ASM("nonmatchings/game/cdngfreemap", GetCharaMemAllocPtr__FP9mgCMemoryP9mgCMemoryii);
extern "C" s32 GetCharacter__6CSceneFi(void *, s32);
extern "C" s32 GetSaveData__Fv(void);
#include "dngfloormanager.hpp"
struct ROBO_INFO_DATA {
    char pad_0[0x1C];
    s32 field_1C;
    s32 field_20;
};
struct inferred;
struct irregular;
typedef struct CCharacter2 {
    /* 0x000 */ char pad0[0x5A0];
    /* 0x5A0 */ void *unk5A0;                          /* inferred */
} CCharacter2;                                      /* size >= 0x5A4 */
typedef struct CScene {
    /* 0x00000 */ char pad0[0x10540];
    /* 0x10540 */ char unk10540;                       /* inferred */
    /* 0x10540 */ char pad10540[1];
} CScene;                                           /* size >= 0x10541 */
extern "C" s32 AtraMiriaOnOff__FiP11CCharacter2i(s32, CCharacter2 *, s32);
extern "C" s32 GetBitCtrl__9CSaveDataFv(...);
extern "C" s32 SetupMints__FP6CSceneP16CUserDataManager(CScene *, CUserDataManager *);
extern "C" s32 SetupMonica__FP6CSceneP16CUserDataManager(CScene *, CUserDataManager *);
extern "C" s32 SetupMonster__FP6CSceneP16CUserDataManager(CScene *, CUserDataManager *);
extern "C" s32 SetupRobo__FP6CSceneP16CUserDataManagerP14ROBO_INFO_DATA(CScene *, CUserDataManager *, ROBO_INFO_DATA *);
extern "C" void SetupUnitMan__FP6CSceneP16CUserDataManageriP14ROBO_INFO_DATA(CScene *arg0, CUserDataManager *arg1, s32 arg2, ROBO_INFO_DATA *arg3) {
    CCharacter2 *temp_v0;
    CCharacter2 *temp_v0_2;
    s32 var_a1;

    switch (arg2) {                                 /* irregular */
    case 0:
        SetupMints__FP6CSceneP16CUserDataManager(arg0, arg1);
        break;
    case 1:
        SetupMonica__FP6CSceneP16CUserDataManager(arg0, arg1);
        break;
    case 2:
        SetupRobo__FP6CSceneP16CUserDataManagerP14ROBO_INFO_DATA(arg0, arg1, arg3);
        break;
    case 3:
        SetupMonster__FP6CSceneP16CUserDataManager(arg0, arg1);
        break;
    }
    temp_v0 = (CCharacter2 *) (GetCharacter__6CSceneFi(arg0, 0));
    if (temp_v0 != NULL) {
        temp_v0->unk5A0 = &arg0->unk10540;
    }
    var_a1 = 0;
    if (arg2 == 2) {
        var_a1 = 3;
    }
    temp_v0_2 = (CCharacter2 *) (GetCharacter__6CSceneFi(arg0, var_a1));
    if ((temp_v0_2 != NULL) && (GetBitCtrl__9CSaveDataFv(GetSaveData__Fv()) & 8)) {
        AtraMiriaOnOff__FiP11CCharacter2i(arg2, temp_v0_2, 0);
    }
}
INCLUDE_ASM("nonmatchings/game/cdngfreemap", SetupMints__FP6CSceneP16CUserDataManager);
INCLUDE_ASM("nonmatchings/game/cdngfreemap", SetupMonica__FP6CSceneP16CUserDataManager);
INCLUDE_ASM("nonmatchings/game/cdngfreemap", SetupRobo__FP6CSceneP16CUserDataManagerP14ROBO_INFO_DATA);
INCLUDE_ASM("nonmatchings/game/cdngfreemap", GetRoboPartsInfo__FP16CUserDataManager);
INCLUDE_ASM("nonmatchings/game/cdngfreemap", SetupMonster__FP6CSceneP16CUserDataManager);
INCLUDE_ASM("nonmatchings/game/cdngfreemap", Initialize__11CDngFreeMapFv);
void CDngFreeMap::InitTexture(void) {
    this->field_0xD8 = 0;
    this->field_0xDC = 0;
    this->field_0xE0 = 0;
    this->field_0xD4 = 0;
    this->field_0xD0 = -1;
}
INCLUDE_ASM("nonmatchings/game/cdngfreemap", SetUserGlid__11CDngFreeMapFi);
typedef struct CDngFreeMap_infere {
    /* 0x000 */ char pad0[0x100];
    /* 0x100 */ f32 unk100;                         /* inferred */
    /* 0x104 */ f32 unk104;                         /* inferred */
} CDngFreeMap_infere;                                      /* size >= 0x108 */
typedef struct GLID_INFO {
    /* 0x0 */ char pad0[2];
    /* 0x2 */ s16 unk2;                             /* inferred */
    /* 0x4 */ s16 unk4;                             /* inferred */
} GLID_INFO;                                        /* size >= 0x6 */
extern "C" void CalcGlidPutPos__11CDngFreeMapFP9GLID_INFORfRfi(CDngFreeMap_infere *objet, GLID_INFO *arg0, f32 *arg1, f32 *arg2, s32 arg3) {
    if (arg0 != NULL) {
        *arg1 = (f32) ((arg0->unk2 * 0x34) + (arg0->unk4 * -0x10));
        *arg2 = (f32) (arg0->unk4 * 0x14);
        if (arg3 == 0) {
            *arg1 += objet->unk100;
            *arg2 += objet->unk104;
        }
    }
}
INCLUDE_ASM("nonmatchings/game/cdngfreemap", CheckIsViewMove__11CDngFreeMapFiiRfRf);
INCLUDE_ASM("nonmatchings/game/cdngfreemap", SetNextRoomPos__11CDngFreeMapFP9GLID_INFO);
typedef struct CDngFreeMap_infere2 {
    /* 0x0 */ char pad0[4];
    /* 0x4 */ CDngFloorManager *unk4;               /* inferred */
} CDngFreeMap_infere2;                                      /* size >= 0x8 */
extern "C" s32 GetNextGlid__16CDngFloorManagerFP9GLID_INFOPi(void *, GLID_INFO *, s32 *);
extern "C" s32 GetNextGlid__11CDngFreeMapFP9GLID_INFOPi(CDngFreeMap_infere2 *objet, GLID_INFO *arg0, s32 *arg1) {
    CDngFloorManager *temp_a0;

    if ((arg0 == NULL) || (temp_a0 = objet->unk4, (temp_a0 == NULL))) {
        return 0;
    }
    return GetNextGlid__16CDngFloorManagerFP9GLID_INFOPi(temp_a0, arg0, arg1);
}
INCLUDE_ASM("nonmatchings/game/cdngfreemap", GetRoomGlid__11CDngFreeMapFi);
INCLUDE_ASM("nonmatchings/game/cdngfreemap", GetEntranceRoomGlid__11CDngFreeMapFv);
INCLUDE_ASM("nonmatchings/game/cdngfreemap", SetTextureInfo__11CDngFreeMapFv);
INCLUDE_ASM("nonmatchings/game/cdngfreemap", ResetDngMapPos__11CDngFreeMapFii);
INCLUDE_ASM("nonmatchings/game/cdngfreemap", DrawBackPattern__11CDngFreeMapFi);
INCLUDE_ASM("nonmatchings/game/cdngfreemap", DrawDngName__11CDngFreeMapFi);
INCLUDE_ASM("nonmatchings/game/cdngfreemap", DrawLast__11CDngFreeMapFv);
INCLUDE_ASM("nonmatchings/game/cdngfreemap", DrawRoot__11CDngFreeMapF9mgRect_f_P16DNGMAP_ROOT_INFOiUii);
INCLUDE_ASM("nonmatchings/game/cdngfreemap", DrawGlidCheck__11CDngFreeMapFP9GLID_INFO);
INCLUDE_ASM("nonmatchings/game/cdngfreemap", DrawRoomOne__11CDngFreeMapF9mgRect_f_P16DNGMAP_ROOM_INFOUiif);
INCLUDE_ASM("nonmatchings/game/cdngfreemap", DrawGlid__11CDngFreeMapF9mgRect_f_);
INCLUDE_ASM("nonmatchings/game/cdngfreemap", CheckGeoramaMateria__FP22TRESURE_BOX_FLOOR_INFOiPi);
INCLUDE_ASM("nonmatchings/game/cdngfreemap", DrawDngRoomInfo__FP16DNGMAP_ROOM_INFO);
INCLUDE_ASM("nonmatchings/game/cdngfreemap", DrawGeoramaMateria__FiPciPii);
INCLUDE_ASM("nonmatchings/game/cdngfreemap", DrawTreeMap__11CDngFreeMapFi);
INCLUDE_ASM("nonmatchings/game/cdngfreemap", DrawPlayer__11CDngFreeMapFi);
INCLUDE_ASM("nonmatchings/game/cdngfreemap", Step__11CDngFreeMapFv);
INCLUDE_ASM("nonmatchings/game/cdngfreemap", Draw__11CDngFreeMapFv);
INCLUDE_ASM("nonmatchings/game/cdngfreemap", FadeIn__11CDngFreeMapFi);
INCLUDE_ASM("nonmatchings/game/cdngfreemap", FadeOut__11CDngFreeMapFi);
INCLUDE_ASM("nonmatchings/game/cdngfreemap", DeleteTexBlock__11CDngFreeMapFv);
INCLUDE_ASM("nonmatchings/game/cdngfreemap", SetKomaMove__11CDngFreeMapFi);
INCLUDE_ASM("nonmatchings/game/cdngfreemap", LoadDngInfo__11CDngFreeMapFP9mgCMemoryiiii);
