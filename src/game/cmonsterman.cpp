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
struct CMonsterMan {
    char pad_0[0xFFF4];
    s32 field_FFF4;
    s32 field_FFF8;
    s32 field_FFFC;
    char pad_10000[0x80];
    s16 field_10080;
    char pad_10082[0x5E];
    s32 field_100E0;
};
struct calcul0_champs_4987d4 {
    char pad0[0x484];
    /* 0x484 */ s32 unk484;
};
struct temp_v1_champs_4987d4 {
    char pad0[0x1330];
    /* 0x1330 */ s32 unk1330;
};
extern "C" s32 SearchActiveMonsterBlock__11CMonsterManFv(CMonsterMan *objet) {
    s32 var_a1;
    s32 var_v0;
    struct temp_v1_champs_4987d4 *temp_v1;

    var_v0 = 0;
    var_a1 = 0;
loop_1:
    /* La conversion en `u8 *` porte l'arithmetique en octets. Sans elle, MWCC
     * met le pas a l'echelle du type pointe et la constante emise est
     * multipliee d'autant. */
    temp_v1 = (struct temp_v1_champs_4987d4 *) (((struct calcul0_champs_4987d4 *) ((u8 *) objet + var_a1))->unk484);
    if (temp_v1 == NULL) {
        return var_v0;
    }
    if (temp_v1->unk1330 == 0) {
        return var_v0;
    }
    var_v0 += 1;
    var_a1 += 4;
    if (var_v0 >= 0x18) {
        return -1;
    }
    goto loop_1;
}

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
typedef struct nowScene_0037D4E4_pointe {
    char pad0[11860];
    s32 unk2E54;
} nowScene_0037D4E4_pointe;
extern "C" nowScene_0037D4E4_pointe *nowScene_0037D4E4;
struct nowScene_0037D4E4_pointe;
extern "C" s32 GetCamera__6CSceneFi(void *, s32);
struct CCameraControl {
    f32 field_0;
    char pad_4[0x70];
    f32 field_74;
    f32 field_78;
    f32 field_7C;
    char pad_80[0x4];
    f32 field_84;
    f32 field_88;
    f32 field_8C;
    char pad_90[0x24];
    f32 field_B4;
    f32 field_B8;
    f32 field_BC;
    char pad_C0[0x10];
    s32 field_D0;
    char pad_D4[0x10];
    f32 field_E4;
    f32 field_E8;
    f32 field_EC;
    char pad_F0[0xB8];
    f32 field_1A8;
    f32 field_1AC;
    f32 field_1B0;
    f32 field_1B4;
    f32 field_1B8;
    f32 field_1BC;
    f32 field_1C0;
    f32 field_1C4;
    f32 field_1C8;
    f32 field_1CC;
    char pad_1D0[0x4];
    f32 field_1D4;
    f32 field_1D8;
    f32 field_1DC;
};
struct inferred;
struct mgCCameraFollow {
    char pad_0[0x48];
    f32 field_48;
    char pad_4C[0x4];
    f32 field_50;
    char pad_54[0x8];
    s32 field_5C;
    char pad_60[0x10];
    f32 field_70;
    f32 field_74;
    f32 field_78;
    f32 field_7C;
    f32 field_80;
    f32 field_84;
    f32 field_88;
    f32 field_8C;
    f32 field_90;
    f32 field_94;
    f32 field_98;
    f32 field_9C;
    s32 field_A0;
    char pad_A4[0xC];
    f32 field_B0;
    f32 field_B4;
    f32 field_B8;
    f32 field_BC;
    char pad_C0[0x4];
    s32 field_C4;
};
struct CScene;
typedef struct CScene {
    /* 0x0000 */ char pad0[0x2E54];
    /* 0x2E54 */ s32 unk2E54;                       /* inferred */
} CScene;                                           /* size >= 0x2E58 */
extern "C" s32 ControlOff__14CCameraControlFv(void *);
extern "C" s32 ControlOn__14CCameraControlFv(void *);
extern "C" s32 FollowOff__15mgCCameraFollowFv(void *);
extern "C" s32 FollowOn__15mgCCameraFollowFv(void *);
extern "C" s32 GetStackInt__FP12RS_STACKDATA_001E1B60(RS_STACKDATA *);
extern "C" s32 _SET_CAMERA_FOLLOW__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    mgCCameraFollow *temp_v0;

    temp_v0 = (mgCCameraFollow *) (GetCamera__6CSceneFi(nowScene_0037D4E4, nowScene_0037D4E4->unk2E54));
    if (temp_v0 == NULL) {
        return 0;
    }
    if (GetStackInt__FP12RS_STACKDATA_001E1B60(arg0) != 0) {
        FollowOn__15mgCCameraFollowFv(temp_v0);
        ControlOn__14CCameraControlFv((CCameraControl *) temp_v0);
    } else {
        FollowOff__15mgCCameraFollowFv(temp_v0);
        ControlOff__14CCameraControlFv((CCameraControl *) temp_v0);
    }
    return 1;
}
INCLUDE_ASM("nonmatchings/game/cmonsterman", _SET_CAMERA_NEXT_POS__FP12RS_STACKDATAi_001E2260);
INCLUDE_ASM("nonmatchings/game/cmonsterman", _GET_DIST_VECTOR__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/cmonsterman", _GET_DIST_VECTOR2__FP12RS_STACKDATAi);
