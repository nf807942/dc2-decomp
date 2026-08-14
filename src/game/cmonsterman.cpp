/* CMonsterMan
 *
 * Unité découpée par `make carve` : 61 fonctions, 24536 octets, de
 * 0x001DC2F0 à 0x001E2410. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

#include "runscript.hpp"

INCLUDE_ASM("nonmatchings/game/cmonsterman", Initialize__11CMonsterManFP6CScene);
INCLUDE_ASM("nonmatchings/game/cmonsterman", DrawEffectScript__11CMonsterManFv);
INCLUDE_ASM("nonmatchings/game/cmonsterman", StepEffectScript__11CMonsterManFv);
INCLUDE_ASM("nonmatchings/game/cmonsterman", IsBattleStyleDist__11CMonsterManFv);
INCLUDE_ASM("nonmatchings/game/cmonsterman", CheckMonsterTolk__11CMonsterManFPf);
INCLUDE_ASM("nonmatchings/game/cmonsterman", CheckThrowTarget__11CMonsterManFP8mgCFrame);
INCLUDE_ASM("nonmatchings/game/cmonsterman", SearchBaseIndex__11CMonsterManFi);
INCLUDE_ASM("nonmatchings/game/cmonsterman", GetMonsterNum__11CMonsterManFf);
INCLUDE_ASM("nonmatchings/game/cmonsterman", GetReferPtr2__11CMonsterManFi);
INCLUDE_ASM("nonmatchings/game/cmonsterman", SearchActiveMonsterBlock__11CMonsterManFv);
INCLUDE_ASM("nonmatchings/game/cmonsterman", SearchReferBlock__11CMonsterManFv);
INCLUDE_ASM("nonmatchings/game/cmonsterman", EntryRefer__11CMonsterManFiP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/cmonsterman", LoadReferMonsterFile__11CMonsterManFiP16BASE_MONSTER_TBLP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/cmonsterman", SetActiveMonster__11CMonsterManFiPfPfi);
INCLUDE_ASM("nonmatchings/game/cmonsterman", DrawMiniMapSymbol__11CMonsterManFP14CMiniMapSymbol);
INCLUDE_ASM("nonmatchings/game/cmonsterman", DrawLifeGage__11CMonsterManFii);
INCLUDE_ASM("nonmatchings/game/cmonsterman", DrawPiyori__11CMonsterManFv);
INCLUDE_ASM("nonmatchings/game/cmonsterman", DrawActMonster__11CMonsterManFv);
INCLUDE_ASM("nonmatchings/game/cmonsterman", DrawInvisibleMonster__11CMonsterManFv);
INCLUDE_ASM("nonmatchings/game/cmonsterman", DrawShadowActMonster__11CMonsterManFv);
INCLUDE_ASM("nonmatchings/game/cmonsterman", PriorityLevelCheck__11CMonsterManFv);
INCLUDE_ASM("nonmatchings/game/cmonsterman", GetPriorityLevelIndex__11CMonsterManFiPi);
INCLUDE_ASM("nonmatchings/game/cmonsterman", CheckPhoto__11CMonsterManFPQ26CScene17InScreenCharaInfo);
INCLUDE_ASM("nonmatchings/game/cmonsterman", SetNearAreaPiyori__11CMonsterManFf);
INCLUDE_ASM("nonmatchings/game/cmonsterman", IsRunEvent__11CMonsterManFv);
INCLUDE_ASM("nonmatchings/game/cmonsterman", CollisionCheck__11CMonsterManFP14CActiveMonsterPfPfPf);
INCLUDE_ASM("nonmatchings/game/cmonsterman", SearchArea__FP6CScenePfPff);
INCLUDE_ASM("nonmatchings/game/cmonsterman", HitEffectSet__FP6CScenePfi);
INCLUDE_ASM("nonmatchings/game/cmonsterman", GuardEffectSet__FP6CScenePfi);
INCLUDE_ASM("nonmatchings/game/cmonsterman", HitScoreSet__FPfii);
INCLUDE_ASM("nonmatchings/game/cmonsterman", CheckGiftPack__FP14CActiveMonsterP8CColPrim);
INCLUDE_ASM("nonmatchings/game/cmonsterman", CheckDamage__11CMonsterManFv);
INCLUDE_ASM("nonmatchings/game/cmonsterman", MoveUnit__11CMonsterManFP14CActiveMonsterP6CCPolyi);
INCLUDE_ASM("nonmatchings/game/cmonsterman", ThinkHost__11CMonsterManFv);
INCLUDE_ASM("nonmatchings/game/cmonsterman", _MONSTER_NAME__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cmonsterman", LoadMonsterLanguage__Fi);
INCLUDE_ASM("nonmatchings/game/cmonsterman", RunScript__11CMonsterManFi);
INCLUDE_ASM("nonmatchings/game/cmonsterman", GetStackInt__FP12RS_STACKDATA_001E1B60);
INCLUDE_ASM("nonmatchings/game/cmonsterman", GetStackFloat__FP12RS_STACKDATA_001E1BA0);
INCLUDE_ASM("nonmatchings/game/cmonsterman", GetStackString__FP12RS_STACKDATA_001E1BD0);
INCLUDE_ASM("nonmatchings/game/cmonsterman", SetStack__FP12RS_STACKDATAi_001E1BE0);
INCLUDE_ASM("nonmatchings/game/cmonsterman", SetStack__FP12RS_STACKDATAf_001E1C00);
INCLUDE_ASM("nonmatchings/game/cmonsterman", GetStackVector__FPfPP12RS_STACKDATA);
INCLUDE_ASM("nonmatchings/game/cmonsterman", SetStackVector__FPfPP12RS_STACKDATA);
INCLUDE_ASM("nonmatchings/game/cmonsterman", _SQRT__FP12RS_STACKDATAi_001E1CE0);
INCLUDE_ASM("nonmatchings/game/cmonsterman", _ATAN2F__FP12RS_STACKDATAi_001E1D30);
s32 _ND_TEST(RS_STACKDATA *stack, int argc) {
    return 1;
}
INCLUDE_ASM("nonmatchings/game/cmonsterman", _GET_TARGET_ROT__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/cmonsterman", _GET_MONSTER_INDEX__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/cmonsterman", _SET_MONSTER_LIFE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/cmonsterman", _GET_USERID__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/cmonsterman", _GET_MONSTER_ID__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/cmonsterman", _RESET_MOTION__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/cmonsterman", _GET_INDEX_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/cmonsterman", _SET_CAMERA_NEXT_REF__FP12RS_STACKDATAi_001E2070);
INCLUDE_ASM("nonmatchings/game/cmonsterman", _SET_ALPHA__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/cmonsterman", _SET_INDEX_ALPHA__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/cmonsterman", _SET_CAMERA_FOLLOW__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/cmonsterman", _SET_CAMERA_NEXT_POS__FP12RS_STACKDATAi_001E2260);
INCLUDE_ASM("nonmatchings/game/cmonsterman", _GET_DIST_VECTOR__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/cmonsterman", _GET_DIST_VECTOR2__FP12RS_STACKDATAi);
