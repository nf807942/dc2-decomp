/* CDngFreeMap, CPreSprite
 *
 * Unité découpée par `make carve` : 73 fonctions, 33988 octets, de
 * 0x001E8790 à 0x001F0E00. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

INCLUDE_ASM("nonmatchings/cdngfreemap", _CHECK_PAUSE__FP12RS_STACKDATAi_001E8790);
INCLUDE_ASM("nonmatchings/cdngfreemap", _GET_BIT_FLAG__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/cdngfreemap", _SET_BIT_FLAG__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/cdngfreemap", _GET_ATT_TYPE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/cdngfreemap", _GET_USER_ATTR__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/cdngfreemap", _TRANS_RESERV_IMG__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/cdngfreemap", _GET_STS_ATTR__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/cdngfreemap", _SET_PIYORI_MARK__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/cdngfreemap", _CHECK_PIYORI__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/cdngfreemap", _GET_BASE_ATTACK__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/cdngfreemap", _GET_NEAR_MONS_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/cdngfreemap", _SET_INDEXOBJ_SIZE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/cdngfreemap", _GET_INDEXOBJ_SIZE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/cdngfreemap", _SET_MOTION_BLUR__FP12RS_STACKDATAi_001E8CF0);
INCLUDE_ASM("nonmatchings/cdngfreemap", _MONS_SE_PLAY__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/cdngfreemap", _MONS_SE_STOP__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/cdngfreemap", _MONS_SE_LOOP__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/cdngfreemap", _MONS_VOL_CTRL__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/cdngfreemap", _SET_MAPOBJ_SHOW__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/cdngfreemap", SetMonsterScript__FP10CRunScriptPcP9mgCMemory);
INCLUDE_ASM("nonmatchings/cdngfreemap", SetMonsterExtendTable__Fv);
INCLUDE_ASM("nonmatchings/cdngfreemap", Preset2D__10CPreSpriteFv);
INCLUDE_ASM("nonmatchings/cdngfreemap", SetIRect__10CPreSpriteFiiiiii);
INCLUDE_ASM("nonmatchings/cdngfreemap", SetIStretch__10CPreSpriteFiiiiiiii);
INCLUDE_ASM("nonmatchings/cdngfreemap", SetScirror__10CPreSpriteFiiii);
INCLUDE_ASM("nonmatchings/cdngfreemap", SetAlphaBlend__10CPreSpriteFi);
INCLUDE_ASM("nonmatchings/cdngfreemap", GetTextureInfo__FP6CScene);
INCLUDE_ASM("nonmatchings/cdngfreemap", MainTextureInterface__FP9mgCMemoryP6CScene);
INCLUDE_ASM("nonmatchings/cdngfreemap", calcWeaponParamWhp__FP14CActiveMonsterP8CColPrim);
INCLUDE_ASM("nonmatchings/cdngfreemap", calcWeaponParam2__Fii);
INCLUDE_ASM("nonmatchings/cdngfreemap", SetDamageParam__FP8CColPrimi);
INCLUDE_ASM("nonmatchings/cdngfreemap", AddExpWeaponParam__Ffii);
INCLUDE_ASM("nonmatchings/cdngfreemap", SetSwordBlurEffect__FP11CCharacter2P9mgCMemoryi);
INCLUDE_ASM("nonmatchings/cdngfreemap", GetCharacterSnd__FP16CUserDataManageriPc);
INCLUDE_ASM("nonmatchings/cdngfreemap", SetupMainUnit__FP1P9mgCMemoryP9mgCMemoryiP6CSceneP16CUserDataManagerii);
INCLUDE_ASM("nonmatchings/cdngfreemap", GetCharaMemAllocSize__Fv);
INCLUDE_ASM("nonmatchings/cdngfreemap", GetCharaMemAllocPtr__FP9mgCMemoryP9mgCMemoryii);
INCLUDE_ASM("nonmatchings/cdngfreemap", SetupUnitMan__FP6CSceneP16CUserDataManageriP14ROBO_INFO_DATA);
INCLUDE_ASM("nonmatchings/cdngfreemap", SetupMints__FP6CSceneP16CUserDataManager);
INCLUDE_ASM("nonmatchings/cdngfreemap", SetupMonica__FP6CSceneP16CUserDataManager);
INCLUDE_ASM("nonmatchings/cdngfreemap", SetupRobo__FP6CSceneP16CUserDataManagerP14ROBO_INFO_DATA);
INCLUDE_ASM("nonmatchings/cdngfreemap", GetRoboPartsInfo__FP16CUserDataManager);
INCLUDE_ASM("nonmatchings/cdngfreemap", SetupMonster__FP6CSceneP16CUserDataManager);
INCLUDE_ASM("nonmatchings/cdngfreemap", Initialize__11CDngFreeMapFv);
INCLUDE_ASM("nonmatchings/cdngfreemap", InitTexture__11CDngFreeMapFv);
INCLUDE_ASM("nonmatchings/cdngfreemap", SetUserGlid__11CDngFreeMapFi);
INCLUDE_ASM("nonmatchings/cdngfreemap", CalcGlidPutPos__11CDngFreeMapFP9GLID_INFORfRfi);
INCLUDE_ASM("nonmatchings/cdngfreemap", CheckIsViewMove__11CDngFreeMapFiiRfRf);
INCLUDE_ASM("nonmatchings/cdngfreemap", SetNextRoomPos__11CDngFreeMapFP9GLID_INFO);
INCLUDE_ASM("nonmatchings/cdngfreemap", GetNextGlid__11CDngFreeMapFP9GLID_INFOPi);
INCLUDE_ASM("nonmatchings/cdngfreemap", GetRoomGlid__11CDngFreeMapFi);
INCLUDE_ASM("nonmatchings/cdngfreemap", GetEntranceRoomGlid__11CDngFreeMapFv);
INCLUDE_ASM("nonmatchings/cdngfreemap", SetTextureInfo__11CDngFreeMapFv);
INCLUDE_ASM("nonmatchings/cdngfreemap", ResetDngMapPos__11CDngFreeMapFii);
INCLUDE_ASM("nonmatchings/cdngfreemap", DrawBackPattern__11CDngFreeMapFi);
INCLUDE_ASM("nonmatchings/cdngfreemap", DrawDngName__11CDngFreeMapFi);
INCLUDE_ASM("nonmatchings/cdngfreemap", DrawLast__11CDngFreeMapFv);
INCLUDE_ASM("nonmatchings/cdngfreemap", DrawRoot__11CDngFreeMapF9mgRect_f_P16DNGMAP_ROOT_INFOiUii);
INCLUDE_ASM("nonmatchings/cdngfreemap", DrawGlidCheck__11CDngFreeMapFP9GLID_INFO);
INCLUDE_ASM("nonmatchings/cdngfreemap", DrawRoomOne__11CDngFreeMapF9mgRect_f_P16DNGMAP_ROOM_INFOUiif);
INCLUDE_ASM("nonmatchings/cdngfreemap", DrawGlid__11CDngFreeMapF9mgRect_f_);
INCLUDE_ASM("nonmatchings/cdngfreemap", CheckGeoramaMateria__FP22TRESURE_BOX_FLOOR_INFOiPi);
INCLUDE_ASM("nonmatchings/cdngfreemap", DrawDngRoomInfo__FP16DNGMAP_ROOM_INFO);
INCLUDE_ASM("nonmatchings/cdngfreemap", DrawGeoramaMateria__FiPciPii);
INCLUDE_ASM("nonmatchings/cdngfreemap", DrawTreeMap__11CDngFreeMapFi);
INCLUDE_ASM("nonmatchings/cdngfreemap", DrawPlayer__11CDngFreeMapFi);
INCLUDE_ASM("nonmatchings/cdngfreemap", Step__11CDngFreeMapFv);
INCLUDE_ASM("nonmatchings/cdngfreemap", Draw__11CDngFreeMapFv);
INCLUDE_ASM("nonmatchings/cdngfreemap", FadeIn__11CDngFreeMapFi);
INCLUDE_ASM("nonmatchings/cdngfreemap", FadeOut__11CDngFreeMapFi);
INCLUDE_ASM("nonmatchings/cdngfreemap", DeleteTexBlock__11CDngFreeMapFv);
INCLUDE_ASM("nonmatchings/cdngfreemap", SetKomaMove__11CDngFreeMapFi);
INCLUDE_ASM("nonmatchings/cdngfreemap", LoadDngInfo__11CDngFreeMapFP9mgCMemoryiiii);
