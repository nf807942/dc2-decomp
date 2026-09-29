/* CDngFloorManager, CStarEffect, CPlaceAnime, CPaintEffect
 *
 * Unité découpée par `make carve` : 68 fonctions, 24440 octets, de
 * 0x002FEED0 à 0x00304FC0. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"
#include "gen/PlaceAnimeData.hpp"

/* Les globales que ces accesseurs servent. Leur taille déclarée est celle que
 * le découpage leur donne, et c'est elle qui décide du `%gp_rel`. */
extern s32 NextCharaMode;
extern s32 RetCode;
struct CScene;

extern PlaceAnimeData PlaceAnime;


INCLUDE_ASM("nonmatchings/game/cdngfloormanager", GetActiveFloorInfo__16CDngFloorManagerFv);
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", RelationGlid__16CDngFloorManagerFv);
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", CheckDrawGlidInfo__16CDngFloorManagerFv);
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", GetNextGlid__16CDngFloorManagerFP9GLID_INFOPi);
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", GetNextRoom__16CDngFloorManagerFiiP9GLID_INFOiPi);
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", GetKeyNextRoom__16CDngFloorManagerFiiP9GLID_INFO);
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", GetDngMapNextFloorID__16CDngFloorManagerFii);
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", GetFloorTitle__16CDngFloorManagerFi);
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", GetDngMapNextRoot__16CDngFloorManagerFi);
extern "C" s32 GetFloorInfoPtr__16CSaveDataDungeonFii(void *, s32, s32);
extern "C" void *menu_GetSaveDataDungeon__Fv(void);
extern "C" s32 GetCountSphedaClear__Fv(void) {
    void *save;
    s32 count;
    s32 i;
    s32 j;
    u8 *info;

    save = menu_GetSaveDataDungeon__Fv();
    count = 0;
    if (save == NULL) {
        return 0;
    }
    for (i = 0; i < 7; i++) {
        for (j = 0; j < 0x28; j++) {
            info = (u8 *) GetFloorInfoPtr__16CSaveDataDungeonFii(save, i, j);
            if (info == NULL) {
                break;
            }
            if (*(u16 *) (info + 0xC) > 0) {
                count += 1;
            }
        }
    }
    return count;
}
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", CheckFishingRecord__Ff);
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", EditSetEffectBuffer__FP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", __ct__12CPaintEffectFv);
extern "C" u32 EffectFlag;
extern "C" u32 EffectState;
extern "C" u32 PaintEffect;
typedef struct _StarEffect_champs {
    char pad0[112];
    s32 unk70;
    char pad74[252];
    s32 unk170;
    char pad174[252];
    s32 unk270;
    char pad274[140];
} _StarEffect_champs;
extern "C" _StarEffect_champs _StarEffect;
struct PaintEffect_champs_6ae7fc {
    char pad0[0x70];
    /* 0x70 */ s32 unk70;
    /* 0x74 */ s32 unk74;
};
extern "C" void EditInitPlaceEffect__Fv(void) {
    struct PaintEffect_champs_6ae7fc *paint;

    _StarEffect.unk70 = 0;
    EffectFlag = 0;
    _StarEffect.unk170 = 0;
    EffectState = 0;
    _StarEffect.unk270 = 0;
    paint = (struct PaintEffect_champs_6ae7fc *) PaintEffect;
    if (paint != NULL) {
        paint->unk70 = 0;
        paint->unk74 = 0;
    }
}
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", EditPlaceEffect__FP10CEditPartsPf);
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", EditPaintEffect__FP10CEditPartsPfPfi);
extern "C" s32 Step__11CStarEffectFv(void *);
extern "C" s32 Step__12CPaintEffectFv(...);
extern "C" void EditPEffectStep__Fv(void) {
    s32 var_s0;
    s32 var_s0_2;
    s32 var_s1;
    s32 var_s1_2;

    var_s0 = 0;
    if (EffectFlag != 0) {
        var_s1 = 0;
        do {
            Step__11CStarEffectFv((u8 *) &_StarEffect + var_s1);
            var_s0 += 1;
            var_s1 += 0x100;
        } while (var_s0 < 3);
        var_s0_2 = 0;
        var_s1_2 = 0;
        do {
            Step__12CPaintEffectFv(PaintEffect + var_s1_2);
            var_s0_2 += 1;
            var_s1_2 += 0x400;
        } while (var_s0_2 <= 0);
    }
}
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", EditPEffectDraw__Fi);
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", EditGetPEffectState__Fv);
extern "C" s32 EditGetPEffectState__Fv(void);
extern "C" s32 EditPEffectEndCheck__Fv(void) {
    if (EditGetPEffectState__Fv() == 3) {
        EditInitPlaceEffect__Fv();
        return 3;
    }
    return (EditGetPEffectState__Fv() == 0) ^ 1;
}
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", ParamInit__11CStarEffectFPfi);
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", Step__11CStarEffectFv);
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", Draw__11CStarEffectFv);
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", ParamInit__12CPaintEffectFf);
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", Step__12CPaintEffectFv);
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", Draw__12CPaintEffectFv);
void EditInitPlaceAnime(void) {
    PlaceAnime.field_0x0 = 0;
    PlaceAnime.field_0x4 = 0;
    PlaceAnime.field_0x8 = 0;
    PlaceAnime.field_0x90 = 0;
    PlaceAnime.field_0x94 = 0;
    PlaceAnime.field_0x98 = 0;
    PlaceAnime.field_0x120 = 0;
    PlaceAnime.field_0x124 = 0;
    PlaceAnime.field_0x128 = 0;
}
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", EditNowPlaceAnime__Fv);
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", EditSetPlaceAnime__FiP9CMapParts);
extern "C" s32 Step__11CPlaceAnimeFv(void *);
extern "C" void EditPlaceAnime__Fv(void) {
    s32 var_s0;
    s32 var_s1;

    var_s1 = 0;
    var_s0 = 0;
    do {
        Step__11CPlaceAnimeFv((u8 *) &PlaceAnime + var_s1);
        var_s0 += 1;
        var_s1 += 0x90;
    } while (var_s0 < 3);
}
extern "C" s32 Step2__11CPlaceAnimeFv(void *);
extern "C" void EditPlaceAnime2__Fv(void) {
    s32 var_s0;
    s32 var_s1;

    var_s1 = 0;
    var_s0 = 0;
    do {
        Step2__11CPlaceAnimeFv((u8 *) &PlaceAnime + var_s1);
        var_s0 += 1;
        var_s1 += 0x90;
    } while (var_s0 < 3);
}
extern "C" s32 Draw__11CPlaceAnimeFv(void *);
extern "C" void EditPlaceAnimeDraw__Fv(void) {
    s32 var_s0;
    s32 var_s1;

    var_s1 = 0;
    var_s0 = 0;
    do {
        Draw__11CPlaceAnimeFv((u8 *) &PlaceAnime + var_s1);
        var_s0 += 1;
        var_s1 += 0x90;
    } while (var_s0 < 3);
}
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", Step__11CPlaceAnimeFv);
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", Step2__11CPlaceAnimeFv);
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", Draw__11CPlaceAnimeFv);
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", EditGetPlaceAnimeState__Fv);
extern "C" s32 EditGetPlaceAnimeState__Fv(void);
extern "C" s32 EditInitPlaceAnime__Fv(void);
extern "C" s32 EditPlaceAnimeEndCheck__Fv(void) {
    if (EditGetPlaceAnimeState__Fv() == 3) {
        EditInitPlaceAnime__Fv();
        return 3;
    }
    return (EditGetPlaceAnimeState__Fv() == 0) ^ 1;
}
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", __ct__11CStarEffectFv);
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", GetFishParam__Fi);
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", EsaInit__Fv);
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", ReplayPrevBGM__FP6CScene);
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", LoadExMotionBG__FP11SubGameInfoP1);
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", LoadExMotionStep__FP11SubGameInfoP9mgCMemory);
void SetNextMode(s32 value) {
    NextCharaMode = value;
}
void ExitFishing(CScene * arg0) {
    RetCode = 1;
}
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", sgInitFishing__FP11SubGameInfo);
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", sgRestartFishing__FP11SubGameInfo);
extern "C" u8 BgmStatus[28];
extern "C" u32 CastOKFlag;
extern "C" u32 CharaMode;
extern "C" u32 DrawCongra;
extern "C" u32 DrawHit;
extern "C" u32 EffectMan_0037E61C;
extern "C" u32 EsaNo;
extern "C" s32 GetNowSubGameInfo__Fv(void);
extern "C" u32 MardanEventMap;
extern "C" u32 MardanEventPlace;
extern "C" u32 RodNo;
extern "C" u32 RunEventNo_0037E67C;
extern "C" u32 oldPadRx;
extern "C" u32 oldPadRy;
struct mgCMemory_load {
    char pad0[0x1C];
    s32 unk1C;
    char pad20[4];
    s32 unk24;
};
struct temp_v0_champs_16c961 {
    /* 0x0 */ s32 unk0;
    char pad4[0x1C];
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ s32 unk28;
    /* 0x2C */ s32 unk2C;
};
extern "C" s32 Align64__9mgCMemoryFv(void *);
extern "C" s32 AssignStack__6CSceneFi(void *, s32);
extern "C" s32 CheckLoadBGM__6CSceneFi(void *, s32);
extern "C" s32 GetActiveBgmStatus__6CSceneFPQ26CScene10BGM_STATUS(...);
extern "C" s32 GetDefBgmNo__6CSceneFi(void *, s32);
extern "C" s32 GetEffect__6CSceneFi(void *, s32);
extern "C" s32 GetStack__6CSceneFi(void *, s32);
extern "C" s32 StopBGM__6CSceneFi(void *, s32);
extern "C" s32 InitDataLoading__Fv(void) {
    struct temp_v0_champs_16c961 *temp_v0;
    void *temp_s1;
    s32 temp_s2;
    mgCMemory_load *temp_a0;

    temp_v0 = (struct temp_v0_champs_16c961 *) (GetNowSubGameInfo__Fv());
    temp_a0 = (mgCMemory_load *) (temp_v0->unk2C);
    temp_s1 = (void *) (temp_v0->unk0);
    if (temp_a0 != NULL) {
        temp_a0->unk24 = 0;
        temp_a0->unk1C = 0;
        Align64__9mgCMemoryFv(temp_a0);
    } else {
        AssignStack__6CSceneFi(temp_s1, 5);
        GetStack__6CSceneFi(temp_s1, 5);
    }
    temp_s2 = (s32) (GetDefBgmNo__6CSceneFi(temp_s1, 0x205));
    if (temp_v0->unk28 == 0) {
        GetActiveBgmStatus__6CSceneFPQ26CScene10BGM_STATUS(temp_s1, &BgmStatus);
        if (CheckLoadBGM__6CSceneFi(temp_s1, temp_s2) != 0) {
            StopBGM__6CSceneFi(temp_s1, 0);
        }
    }
    EffectMan_0037E61C = GetEffect__6CSceneFi(temp_s1, 0);
    CharaMode = 0;
    NextCharaMode = -1;
    RunEventNo_0037E67C = -1;
    CastOKFlag = 0;
    MardanEventMap = 0;
    MardanEventPlace = 0;
    RodNo = temp_v0->unk20;
    EsaNo = temp_v0->unk24;
    RetCode = 0;
    oldPadRy = 0;
    oldPadRx = 0;
    DrawCongra = 0;
    DrawHit = 0;
    return 1;
}
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", switch_thread__Fv);
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", CreateLoadThread__FP9mgCMemory);
extern "C" u32 ThreadRunning;
extern "C" u32 step_end_flag;
extern "C" s32 switch_thread__Fv(void);
extern "C" s32 StepLoadThread__Fv(void) {
    if (ThreadRunning == 0) {
        return 0;
    }
    switch_thread__Fv();
    return !(step_end_flag != 0);
}
extern "C" u32 TheadID_0037E724;
extern "C" u32 ThreadRunning;
extern "C" s32 DeleteThread(...);
extern "C" s32 TerminateThread(...);
extern "C" s32 StepLoadThread__Fv(void);
extern "C" void DeleteLoadThread__Fv(void) {
    if (ThreadRunning != 0) {
        do {

        } while (StepLoadThread__Fv() != 0);
        TerminateThread(TheadID_0037E724);
        DeleteThread(TheadID_0037E724);
        ThreadRunning = 0;
    }
}
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", StepDataLoading__FPv);
extern "C" s32 GetNowSubGameInfo__Fv(void);
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
extern "C" s32 sgExitFishing__FP11SubGameInfo(...);
extern "C" s32 sgBreakFishing__Fv(void) {
    DeleteLoadThread__Fv();
    sgExitFishing__FP11SubGameInfo(GetNowSubGameInfo__Fv());
    return 1;
}
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", sgExitFishing__FP11SubGameInfo);
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", sgLoopFishing__FP11SubGameInfo);
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", sgLoopFishing2__FP11SubGameInfo);
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", sgDrawFishing__FP11SubGameInfo);
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", DrawNumber__FP11mgCDrawPrimiii);
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", sgSystemDrawFishing__FP11SubGameInfo);
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", CharaControl__FP6CSceneP11CPadControl_00303FC0);
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", InitSelectCastingPoint__FP6CScene);
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", EndSelectCastingPoint__FP6CScene);
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", SelectCastingPoint__FP6CSceneP11CPadControl);
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", DrawHamon__FPff);
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", DrawSplash__FPff);
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", GetMotionCount__FP11CCharacter2Pciii);
INCLUDE_ASM("nonmatchings/game/cdngfloormanager", InitCasting__FP6CScene);
