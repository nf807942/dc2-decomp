/* CMonsterMan
 *
 * Unité découpée par `make carve` : 61 fonctions, 24536 octets, de
 * 0x001DC2F0 à 0x001E2410. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

INCLUDE_ASM("nonmatchings/cmonsterman", Initialize__11CMonsterManFP6CScene);
INCLUDE_ASM("nonmatchings/cmonsterman", DrawEffectScript__11CMonsterManFv);
INCLUDE_ASM("nonmatchings/cmonsterman", StepEffectScript__11CMonsterManFv);
INCLUDE_ASM("nonmatchings/cmonsterman", IsBattleStyleDist__11CMonsterManFv);
INCLUDE_ASM("nonmatchings/cmonsterman", CheckMonsterTolk__11CMonsterManFPf);
INCLUDE_ASM("nonmatchings/cmonsterman", CheckThrowTarget__11CMonsterManFP8mgCFrame);
INCLUDE_ASM("nonmatchings/cmonsterman", SearchBaseIndex__11CMonsterManFi);
INCLUDE_ASM("nonmatchings/cmonsterman", GetMonsterNum__11CMonsterManFf);
INCLUDE_ASM("nonmatchings/cmonsterman", GetReferPtr2__11CMonsterManFi);
INCLUDE_ASM("nonmatchings/cmonsterman", SearchActiveMonsterBlock__11CMonsterManFv);
INCLUDE_ASM("nonmatchings/cmonsterman", SearchReferBlock__11CMonsterManFv);
INCLUDE_ASM("nonmatchings/cmonsterman", EntryRefer__11CMonsterManFiP9mgCMemory);
INCLUDE_ASM("nonmatchings/cmonsterman", LoadReferMonsterFile__11CMonsterManFiP16BASE_MONSTER_TBLP9mgCMemory);
INCLUDE_ASM("nonmatchings/cmonsterman", SetActiveMonster__11CMonsterManFiPfPfi);
INCLUDE_ASM("nonmatchings/cmonsterman", DrawMiniMapSymbol__11CMonsterManFP14CMiniMapSymbol);
INCLUDE_ASM("nonmatchings/cmonsterman", DrawLifeGage__11CMonsterManFii);
INCLUDE_ASM("nonmatchings/cmonsterman", DrawPiyori__11CMonsterManFv);
INCLUDE_ASM("nonmatchings/cmonsterman", DrawActMonster__11CMonsterManFv);
INCLUDE_ASM("nonmatchings/cmonsterman", DrawInvisibleMonster__11CMonsterManFv);
INCLUDE_ASM("nonmatchings/cmonsterman", DrawShadowActMonster__11CMonsterManFv);
INCLUDE_ASM("nonmatchings/cmonsterman", PriorityLevelCheck__11CMonsterManFv);
INCLUDE_ASM("nonmatchings/cmonsterman", GetPriorityLevelIndex__11CMonsterManFiPi);
INCLUDE_ASM("nonmatchings/cmonsterman", CheckPhoto__11CMonsterManFPQ26CScene17InScreenCharaInfo);
INCLUDE_ASM("nonmatchings/cmonsterman", SetNearAreaPiyori__11CMonsterManFf);
INCLUDE_ASM("nonmatchings/cmonsterman", IsRunEvent__11CMonsterManFv);
INCLUDE_ASM("nonmatchings/cmonsterman", CollisionCheck__11CMonsterManFP14CActiveMonsterPfPfPf);
INCLUDE_ASM("nonmatchings/cmonsterman", SearchArea__FP6CScenePfPff);
INCLUDE_ASM("nonmatchings/cmonsterman", HitEffectSet__FP6CScenePfi);
INCLUDE_ASM("nonmatchings/cmonsterman", GuardEffectSet__FP6CScenePfi);
INCLUDE_ASM("nonmatchings/cmonsterman", HitScoreSet__FPfii);
INCLUDE_ASM("nonmatchings/cmonsterman", CheckGiftPack__FP14CActiveMonsterP8CColPrim);
INCLUDE_ASM("nonmatchings/cmonsterman", CheckDamage__11CMonsterManFv);
INCLUDE_ASM("nonmatchings/cmonsterman", MoveUnit__11CMonsterManFP14CActiveMonsterP6CCPolyi);
INCLUDE_ASM("nonmatchings/cmonsterman", ThinkHost__11CMonsterManFv);
INCLUDE_ASM("nonmatchings/cmonsterman", _MONSTER_NAME__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/cmonsterman", LoadMonsterLanguage__Fi);
INCLUDE_ASM("nonmatchings/cmonsterman", RunScript__11CMonsterManFi);
INCLUDE_ASM("nonmatchings/cmonsterman", GetStackInt__FP12RS_STACKDATA_001E1B60);
INCLUDE_ASM("nonmatchings/cmonsterman", GetStackFloat__FP12RS_STACKDATA_001E1BA0);
INCLUDE_ASM("nonmatchings/cmonsterman", GetStackString__FP12RS_STACKDATA_001E1BD0);
INCLUDE_ASM("nonmatchings/cmonsterman", SetStack__FP12RS_STACKDATAi_001E1BE0);
INCLUDE_ASM("nonmatchings/cmonsterman", SetStack__FP12RS_STACKDATAf_001E1C00);
INCLUDE_ASM("nonmatchings/cmonsterman", GetStackVector__FPfPP12RS_STACKDATA);
INCLUDE_ASM("nonmatchings/cmonsterman", SetStackVector__FPfPP12RS_STACKDATA);
INCLUDE_ASM("nonmatchings/cmonsterman", _SQRT__FP12RS_STACKDATAi_001E1CE0);
INCLUDE_ASM("nonmatchings/cmonsterman", _ATAN2F__FP12RS_STACKDATAi_001E1D30);
INCLUDE_ASM("nonmatchings/cmonsterman", _ND_TEST__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/cmonsterman", _GET_TARGET_ROT__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/cmonsterman", _GET_MONSTER_INDEX__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/cmonsterman", _SET_MONSTER_LIFE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/cmonsterman", _GET_USERID__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/cmonsterman", _GET_MONSTER_ID__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/cmonsterman", _RESET_MOTION__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/cmonsterman", _GET_INDEX_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/cmonsterman", _SET_CAMERA_NEXT_REF__FP12RS_STACKDATAi_001E2070);
INCLUDE_ASM("nonmatchings/cmonsterman", _SET_ALPHA__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/cmonsterman", _SET_INDEX_ALPHA__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/cmonsterman", _SET_CAMERA_FOLLOW__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/cmonsterman", _SET_CAMERA_NEXT_POS__FP12RS_STACKDATAi_001E2260);
INCLUDE_ASM("nonmatchings/cmonsterman", _GET_DIST_VECTOR__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/cmonsterman", _GET_DIST_VECTOR2__FP12RS_STACKDATAi);
