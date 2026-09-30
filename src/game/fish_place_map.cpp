/* FISH_PLACE_MAP, sgCPlayVoice
 *
 * Unité découpée par `make carve` : 55 fonctions, 23272 octets, de
 * 0x00304FC0 à 0x0030AC00. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"
#include "gen/sgCPlayVoice.hpp"

/* Les globales que ces accesseurs servent. Leur taille déclarée est celle que
 * le découpage leur donne, et c'est elle qui décide du `%gp_rel`. */
extern s32 ItemOver;
extern s32 MenuOpenFlag;
extern s32 SubGame;
struct FISH_DATA;

extern s32 RodActFlag;
extern s32 UkiCameraFlag;
extern s32 UkiMode;
extern s32 UkiModeCnt;
struct CScene;


INCLUDE_ASM("nonmatchings/game/fish_place_map", CastingLoop__FP6CSceneP11CPadControl);
s32 InitUkiWait(CScene * arg0) {
    RodActFlag = 0;
    UkiMode = 0;
    UkiModeCnt = 0;
    UkiCameraFlag = 0;
    return 1;
}
INCLUDE_ASM("nonmatchings/game/fish_place_map", ResetUkiCamera__FP14CCameraControl);
INCLUDE_ASM("nonmatchings/game/fish_place_map", UkiWaitLoop__FP6CSceneP11CPadControl);
INCLUDE_ASM("nonmatchings/game/fish_place_map", InitBattle__FP6CScene);
INCLUDE_ASM("nonmatchings/game/fish_place_map", BattleLoop__FP6CSceneP11CPadControl);
INCLUDE_ASM("nonmatchings/game/fish_place_map", GetFishDist__FP6CScene);
INCLUDE_ASM("nonmatchings/game/fish_place_map", DeleteEsa__Fv);
INCLUDE_ASM("nonmatchings/game/fish_place_map", InitFalse__FP6CScene);
INCLUDE_ASM("nonmatchings/game/fish_place_map", FalseLoop__FP6CSceneP11CPadControl);
INCLUDE_ASM("nonmatchings/game/fish_place_map", InitSuccess__FP6CScene);
INCLUDE_ASM("nonmatchings/game/fish_place_map", SuccessLoop__FP6CSceneP11CPadControl);
INCLUDE_ASM("nonmatchings/game/fish_place_map", CheckFishing__FPfP6CCPolyi);
INCLUDE_ASM("nonmatchings/game/fish_place_map", CheckCasting__FP6CScenePfPf);
INCLUDE_ASM("nonmatchings/game/fish_place_map", GetRandamNumber__Ffff);
INCLUDE_ASM("nonmatchings/game/fish_place_map", GetUkiWaitTime__FP9FISH_DATAP6CScenePfii);
INCLUDE_ASM("nonmatchings/game/fish_place_map", GetUkiPokeTime__FP9FISH_DATA);
s32 GetUkiPullTime(FISH_DATA * arg0) {
    return 30;
}
INCLUDE_ASM("nonmatchings/game/fish_place_map", FishLoadBG__FP9FISH_DATAP1);
INCLUDE_ASM("nonmatchings/game/fish_place_map", LineTensionStep__FP9FISH_DATAi);
INCLUDE_ASM("nonmatchings/game/fish_place_map", GetAppearFish__FiPfP10FISH_PLACEi);
INCLUDE_ASM("nonmatchings/game/fish_place_map", SetFishPlace__14FISH_PLACE_MAPFP10FISH_PLACEii);
INCLUDE_ASM("nonmatchings/game/fish_place_map", CheckFishPlace__14FISH_PLACE_MAPFPf);
INCLUDE_ASM("nonmatchings/game/fish_place_map", fpFISH_MAP_NUM__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/fish_place_map", fpFISH_MAP__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/fish_place_map", fpFISH_PLACE__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/fish_place_map", fpFISH__FP9SPI_STACKi);
extern "C" u32 fpNowFishPlaceMap;
extern "C" u32 fpNowFishPlaceMapNum;
struct SPI_STACK {
    s32 field_0;
    s32 field_4;
};
extern "C" s32 fpFISH_MAP_END__FP9SPI_STACKi(SPI_STACK *arg0, s32 arg1) {
    if (fpNowFishPlaceMap == 0) {
        return 0;
    }
    fpNowFishPlaceMapNum += 1;
    return 1;
}
INCLUDE_ASM("nonmatchings/game/fish_place_map", LoadFishPlaceData__FPciP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/fish_place_map", InitSubGame__FP6CScene);
extern s32 SubGame;
extern "C" s32 SubGameRunning__Fv(void) {
    return SubGame != 0;
}
s32 GetSubGameNo(void) {
    return SubGame;
}
extern "C" u8 GameInfo[48];
extern "C" void *GetNowSubGameInfo__Fv(void) {
    return GameInfo;
}
INCLUDE_ASM("nonmatchings/game/fish_place_map", sgMenuOpenEnable__Fv);
void sgSetMenuOpenEnableFlag(s32 value) {
    MenuOpenFlag = value;
}
s32 sgGetItemOver(void) {
    return ItemOver;
}
void sgGetItemOverReset(void) {
    ItemOver = 0;
}
void sgGetItemOverFlagOn(void) {
    ItemOver = 1;
}
INCLUDE_ASM("nonmatchings/game/fish_place_map", sgInitSubGame__FiP11SubGameInfo);
extern "C" u8 GameInfo[48];
struct SubGameInfo {
    char pad_0[0x4];
    s32 field_4;
    s32 field_8;
    s32 field_C;
    s32 field_10;
    s32 field_14;
    s32 field_18;
    s32 field_1C;
    s32 field_20;
    s32 field_24;
    s32 field_28;
    s32 field_2C;
};
struct irregular;
extern "C" s32 sgLoopBuggy__FP11SubGameInfo(...);
extern "C" s32 sgLoopFishing__FP11SubGameInfo(...);
extern "C" s32 sgLoopGyoRace__FP11SubGameInfo(...);
extern "C" s32 SubGameRunning__Fv(void);
extern "C" s32 sgLoopSubGame__Fv(void) {
    s32 var_v0;

    if (SubGameRunning__Fv() == 0) {
        return 0;
    }
    var_v0 = 0;
    switch (SubGame) {                              /* irregular */
    case 1:
        var_v0 = sgLoopFishing__FP11SubGameInfo(&GameInfo);
        break;
    case 2:
        var_v0 = sgLoopGyoRace__FP11SubGameInfo(&GameInfo);
        break;
    case 3:
        var_v0 = sgLoopBuggy__FP11SubGameInfo(&GameInfo);
        break;
    case 4:
        var_v0 = 1;
        break;
    }
    if (var_v0 != 0) {
        SubGame = 0;
    }
    return 0;
}
INCLUDE_ASM("nonmatchings/game/fish_place_map", sgLoopSubGame2__Fv);
INCLUDE_ASM("nonmatchings/game/fish_place_map", sgExitSubGame__Fv);
INCLUDE_ASM("nonmatchings/game/fish_place_map", sgRestartSubGame__FP11SubGameInfo);
INCLUDE_ASM("nonmatchings/game/fish_place_map", sgBreakSubGame__Fv);
extern "C" s32 sgMapDrawGyoRace__FP11SubGameInfo(...);
extern "C" s32 sgDrawSubGameMap__Fv(void) {
    if (SubGameRunning__Fv() == 0) {
        return 0;
    }
    if (SubGame != 2) {
        return 0;
    }
    return sgMapDrawGyoRace__FP11SubGameInfo(&GameInfo);
}
INCLUDE_ASM("nonmatchings/game/fish_place_map", sgDrawSubGameCharaShadow__Fv);
extern "C" s32 sgCharaDrawGyoRace__FP11SubGameInfo(...);
extern "C" s32 sgDrawBuggy__FP11SubGameInfo(...);
extern "C" s32 sgDrawFishing__FP11SubGameInfo(...);
extern "C" s32 sgDrawSubGameChara__Fv(void) {
    if (SubGameRunning__Fv() == 0) {
        return 0;
    }
    switch (SubGame) {                              /* irregular */
    case 1:
        return sgDrawFishing__FP11SubGameInfo(&GameInfo);
    case 2:
        return sgCharaDrawGyoRace__FP11SubGameInfo(&GameInfo);
    case 3:
        return sgDrawBuggy__FP11SubGameInfo(&GameInfo);
    default:
    case 4:
        return 0;
    }
}
extern "C" s32 sgEffectDrawBuggy__FP11SubGameInfo(...);
extern "C" s32 sgEffectDrawGyoRace__FP11SubGameInfo(...);
extern "C" s32 sgDrawSubGameEffect__Fv(void) {
    if (SubGameRunning__Fv() == 0) {
        return 0;
    }
    switch (SubGame) {                              /* irregular */
    case 2:
        return sgEffectDrawGyoRace__FP11SubGameInfo(&GameInfo);
    case 3:
        return sgEffectDrawBuggy__FP11SubGameInfo(&GameInfo);
    default:
        return 0;
    }
}
extern "C" s32 sgSysDrawGyoRace__FP11SubGameInfo(...);
extern "C" s32 sgSystemDrawBuggy__FP11SubGameInfo(...);
extern "C" s32 sgSystemDrawFishing__FP11SubGameInfo(...);
extern "C" s32 sgDrawSubGameSystem__Fv(void) {
    if (SubGameRunning__Fv() == 0) {
        return 0;
    }
    switch (SubGame) {                              /* irregular */
    case 1:
        return sgSystemDrawFishing__FP11SubGameInfo(&GameInfo);
    case 2:
        return sgSysDrawGyoRace__FP11SubGameInfo(&GameInfo);
    case 3:
        return sgSystemDrawBuggy__FP11SubGameInfo(&GameInfo);
    default:
    case 4:
        return 0;
    }
}
struct inferred;
typedef struct sgCPlayVoice_infere2 {
    /* 0x0 */ s32 unk0;                             /* inferred */
    /* 0x4 */ s32 unk4;                             /* inferred */
    /* 0x8 */ s32 unk8;                             /* inferred */
} sgCPlayVoice_infere2;                                     /* size >= 0xC */
extern "C" s32 Close__12sgCPlayVoiceFv(void *);
extern "C" void Open__12sgCPlayVoiceFi(sgCPlayVoice_infere2 *objet, s32 arg0) {
    if (objet->unk0 > 0) {
        Close__12sgCPlayVoiceFv(objet);
    }
    objet->unk0 = 1;
    objet->unk4 = arg0;
    objet->unk8 = 0;
}
struct inferred;
typedef struct sgCPlayVoice_infere {
    /* 0x00 */ char pad0[0xC];
    /* 0x0C */ f32 unkC;                            /* inferred */
    /* 0x10 */ f32 unk10;                           /* inferred */
} sgCPlayVoice_infere;                                     /* size >= 0x14 */
extern "C" void SetVol__12sgCPlayVoiceFff(sgCPlayVoice_infere *objet, f32 arg0, f32 arg1) {
    f32 var_f12;
    f32 var_f13;

    var_f12 = arg0;
    var_f13 = arg1;
    if (var_f12 < 0.0f) {
        var_f12 = 0.0f;
    }
    if (!(var_f12 <= 1.0f)) {
        var_f12 = 1.0f;
    }
    objet->unk10 = var_f12;
    if (var_f13 < 0.0f) {
        var_f13 = var_f12;
    }
    if (!(var_f13 <= 1.0f)) {
        var_f13 = 1.0f;
    }
    objet->unkC = var_f13;
}
void sgCPlayVoice::Play(void) {
    this->field_0x8 = 1;
}
INCLUDE_ASM("nonmatchings/game/fish_place_map", Step__12sgCPlayVoiceFv);
INCLUDE_ASM("nonmatchings/game/fish_place_map", Close__12sgCPlayVoiceFv);
INCLUDE_ASM("nonmatchings/game/fish_place_map", sgInitGyoRace__FP11SubGameInfo);
