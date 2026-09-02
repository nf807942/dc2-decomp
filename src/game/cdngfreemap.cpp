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
INCLUDE_ASM("nonmatchings/game/cdngfreemap", _SET_PIYORI_MARK__FP12RS_STACKDATAi);
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
INCLUDE_ASM("nonmatchings/game/cdngfreemap", Preset2D__10CPreSpriteFv);
INCLUDE_ASM("nonmatchings/game/cdngfreemap", SetIRect__10CPreSpriteFiiiiii);
INCLUDE_ASM("nonmatchings/game/cdngfreemap", SetIStretch__10CPreSpriteFiiiiiiii);
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
INCLUDE_ASM("nonmatchings/game/cdngfreemap", SetupUnitMan__FP6CSceneP16CUserDataManageriP14ROBO_INFO_DATA);
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
INCLUDE_ASM("nonmatchings/game/cdngfreemap", CalcGlidPutPos__11CDngFreeMapFP9GLID_INFORfRfi);
INCLUDE_ASM("nonmatchings/game/cdngfreemap", CheckIsViewMove__11CDngFreeMapFiiRfRf);
INCLUDE_ASM("nonmatchings/game/cdngfreemap", SetNextRoomPos__11CDngFreeMapFP9GLID_INFO);
INCLUDE_ASM("nonmatchings/game/cdngfreemap", GetNextGlid__11CDngFreeMapFP9GLID_INFOPi);
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
