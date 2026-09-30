/* CScene, CEditMap, CEditData, EditAnalyzeSrc, EditAnalyzeDataSrc
 *
 * Unité découpée par `make carve` : 125 fonctions, 23632 octets, de
 * 0x002A9FF0 à 0x002AFEE0. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"
#include "gen/EditAnalyzeDataSrc.hpp"
extern s32 eaAnaData;
extern s32 eaAnaSrc;
struct SPI_STACK;


INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", Init__Q26CScene8BGM_INFOFv);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", InitSnd__6CSceneFv);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", InitBGM__6CSceneFv);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", InitSeSrc__6CSceneFv);
struct CScene_d4a978 {
    char pad0[0xA040];
    /* 0xA040 */ s32 unkA040;
    /* 0xA044 */ s32 unkA044;
    char padA048[0x8];
    /* 0xA050 */ s32 unkA050;
    char padA054[0x3FC];
    /* 0xA450 */ s32 unkA450;
    char padA454[0x2C];
    /* 0xA480 */ s32 unkA480;
    /* 0xA484 */ s32 unkA484;
    /* 0xA488 */ s32 unkA488;
    /* 0xA48C */ s32 unkA48C;
    /* 0xA490 */ s32 unkA490;
    /* 0xA494 */ s32 unkA494;
};
extern "C" s32 sndDeletePort__Fi(s32);
extern "C" s32 sndInitPort__Fi(s32);
extern "C" s32 sndSeAllStop__Fi(s32);
extern "C" s32 stSetBuffer__9mgCMemoryFP1i(...);
extern "C" s32 InitSeSrc__6CSceneFv(void *);
extern "C" s32 StopEnvBGM__6CSceneFv(void *);
extern "C" void InitSeEnv__6CSceneFv(void *arg0) {
    CScene_d4a978 *objet = (CScene_d4a978 *) arg0;
    StopEnvBGM__6CSceneFv(objet);
    sndSeAllStop__Fi(2);
    sndDeletePort__Fi(2);
    InitSeSrc__6CSceneFv(objet);
    objet->unkA040 = -1;
    objet->unkA044 = -1;
    stSetBuffer__9mgCMemoryFP1i(&objet->unkA450, &objet->unkA050, 0x40);
    sndInitPort__Fi(2);
    objet->unkA488 = 0;
    objet->unkA480 = 0;
    objet->unkA48C = 0x3F800000;
    objet->unkA484 = -1;
    objet->unkA490 = 0;
    objet->unkA494 = 0;
    InitSeSrc__6CSceneFv(objet);
}
struct CSceneBattleFields {
    char pad0[0xC4D0];
    /* 0xC4D0 */ s32 unkC4D0;
    /* 0xC4D4 */ s32 unkC4D4;
    char padC4D8[0x8];
    /* 0xC4E0 */ s32 unkC4E0;
    char padC4E4[0x1FFC];
    /* 0xE4E0 */ s32 unkE4E0;
};
extern "C" void InitSeBattle__6CSceneFv(void *arg0) {
    CSceneBattleFields *objet = (CSceneBattleFields *) arg0;
    sndSeAllStop__Fi(9);
    sndDeletePort__Fi(9);
    objet->unkC4D0 = -1;
    objet->unkC4D4 = -1;
    stSetBuffer__9mgCMemoryFP1i(&objet->unkE4E0, &objet->unkC4E0, 0x200);
    sndInitPort__Fi(9);
    InitSeEnv__6CSceneFv(objet);
}
struct CSceneBasFields {
    char pad0[0xA498];
    /* 0xA498 */ s32 unkA498;
    /* 0xA49C */ s32 unkA49C;
    /* 0xA4A0 */ s32 unkA4A0;
    char padA4A4[0x1FFC];
    /* 0xC4A0 */ s32 unkC4A0;
};
extern "C" void InitSeBas__6CSceneFv(void *arg0) {
    CSceneBasFields *objet = (CSceneBasFields *) arg0;
    sndSeAllStop__Fi(3);
    objet->unkA498 = -1;
    objet->unkA49C = -1;
    stSetBuffer__9mgCMemoryFP1i(&objet->unkC4A0, &objet->unkA4A0, 0x200);
    sndDeletePort__Fi(3);
    sndInitPort__Fi(3);
    InitSeBattle__6CSceneFv(objet);
}
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", SeAllStop__6CSceneFv);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", SoundAllStop__6CSceneFv);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", InitLooSeMngr__6CSceneFv);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", GetActiveBgmInfo__6CSceneFv);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", PlayBGM__6CSceneFiif);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", PauseBGM__6CSceneFv);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", RePlayBGM__6CSceneFv);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", StopBGM__6CSceneFi);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", SetVolBGM__6CSceneFi);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", GetVolBGM__6CSceneFv);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", GetBGMState__6CSceneFv);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", SetVolfBGM__6CSceneFf);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", GetVolfBGM__6CSceneFv);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", FadeOutBGM__6CSceneFi);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", FadeInBGM__6CSceneFi);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", AutoChangeBGMVol__6CSceneFi);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", GetActiveBgmStatus__6CSceneFPQ26CScene10BGM_STATUS);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", SetActiveBgmStatus__6CSceneFPQ26CScene10BGM_STATUS);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", PlayEnvBGM__6CSceneFif);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", SetEnvBGMVol__6CSceneFf);
struct EnvSceneC { char pad[0xA48C]; f32 vol; };
extern "C" f32 GetEnvBGMVol__6CSceneFv(EnvSceneC *self) {
    return self->vol;
}

INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", StopEnvBGM__6CSceneFv);
struct EnvSceneA { char pad[0xA490]; s32 f490; s32 f494; };
extern "C" s32 AutoChangeEnvBGM__6CSceneFi(void *self, s32 v) {
    ((EnvSceneA *) self)->f490 = v;
}

struct EnvSceneB { char pad[0xA494]; s32 f494; };
extern "C" void AutoChangeEnvOffset__6CSceneFi(EnvSceneB *self, s32 v) {
    self->f494 = v;
}

extern "C" s32 SearchSndDataID__6CSceneFi(void *, s32);
struct PlayEnvBgmScene {
    char pad0[0x9068];
    /* 0x9068 */ s32 unk9068;
    char pad906C[0x141C];
    /* 0xA488 */ s32 unkA488;
};
struct PlayEnvBgmData {
    char pad0[0xA];
    /* 0xA */ s16 unkA;
    /* 0xC */ s16 unkC;
};
extern "C" s32 AutoChangeEnvBGM__6CSceneFi(void *, s32);
extern "C" s32 PlayEnvBGM__6CSceneFif(void *, s32, f32);
extern "C" s32 SetEnvBGMVol__6CSceneFf(void *, f32);
extern "C" void PlayEnvBgm__6CSceneFv(void *arg0) {
    PlayEnvBgmData *temp_v0;
    PlayEnvBgmScene *objet = (PlayEnvBgmScene *) arg0;
    s16 temp_a1;

    temp_v0 = (PlayEnvBgmData *) (SearchSndDataID__6CSceneFi(objet, objet->unk9068));
    if (temp_v0 != NULL) {
        temp_a1 = (s16) (temp_v0->unkA);
        if (temp_a1 >= 0) {
            PlayEnvBGM__6CSceneFif(objet, (s32) temp_a1, 1.0f);
            return;
        }
        AutoChangeEnvBGM__6CSceneFi(objet, 1);
        objet->unkA488 = 0xBF800000;
        SetEnvBGMVol__6CSceneFf(objet, (f32) temp_v0->unkC / 127.0f);
    }
}
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", GetSeSrcID__6CSceneFi);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", GetNumber3__FPci);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", GetBgmFile__6CSceneFPci);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", GetSeSrcFile__6CSceneFPci);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", GetSeEnvFile__6CSceneFPci);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", GetSeBaseFile__6CSceneFPci);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", GetSeBattleFile__6CSceneFPci);
struct CScene;
extern "C" s32 GetActiveBgmInfo__6CSceneFv(void *);
struct temp_v0_champs {
    char pad0[0x8];
    /* 0x8 */ s32 unk8;
};
extern "C" s32 CheckLoadBGM__6CSceneFi(CScene *objet, s32 arg0) {
    struct temp_v0_champs *temp_v0;

    temp_v0 = (struct temp_v0_champs *) (GetActiveBgmInfo__6CSceneFv(objet));
    if (arg0 < 0) {
        return 0;
    }
    return arg0 != temp_v0->unk8;
}
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", CheckLoadSeSrc__6CSceneFi);
struct inferred;
typedef struct CScene_infere {
    /* 0x0000 */ char pad0[0xA044];
    /* 0xA044 */ s32 unkA044;                       /* inferred */
} CScene_infere;                                           /* size >= 0xA048 */
extern "C" s32 CheckLoadSeEnv__6CSceneFi(CScene_infere *objet, s32 arg0) {
    if (arg0 < 0) {
        return 0;
    }
    return objet->unkA044 != arg0;
}
typedef struct CScene_infere2 {
    /* 0x0000 */ char pad0[0xC4D4];
    /* 0xC4D4 */ s32 unkC4D4;                       /* inferred */
} CScene_infere2;                                           /* size >= 0xC4D8 */
extern "C" s32 CheckLoadSeBattle__6CSceneFi(CScene_infere2 *objet, s32 arg0) {
    if (arg0 < 0) {
        return 0;
    }
    return objet->unkC4D4 != arg0;
}
typedef struct CScene_infere3 {
    /* 0x0000 */ char pad0[0xA49C];
    /* 0xA49C */ s32 unkA49C;                       /* inferred */
} CScene_infere3;                                           /* size >= 0xA4A0 */
extern "C" s32 CheckLoadSeBase__6CSceneFi(CScene_infere3 *objet, s32 arg0) {
    if (arg0 < 0) {
        return 0;
    }
    return objet->unkA49C != arg0;
}
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", SearchSndDataID__6CSceneFi);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", GetDefBgmNo__6CSceneFi);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", GetDefEventSeFile__6CSceneFiPc);
extern "C" s32 SearchSndDataID__6CSceneFi(void *, s32);
extern "C" u8 _1194[15];
extern "C" u8 _1195[14];
struct CScene_9cdf83;
typedef struct CScene_9cdf83 {
    /* 0x0000 */ char pad0[0x9068];
    /* 0x9068 */ s32 unk9068;                       /* inferred */
    /* 0x906C */ char pad906C[4];
    /* 0x9070 */ s32 unk9070;                       /* inferred */
} CScene_9cdf83;                                           /* size >= 0x9074 */
struct calcul0_champs_9cdf83 {
    char pad0[0xE];
    /* 0xE */ s16 unkE;
};
struct calcul1_champs_9cdf83 {
    char pad0[0x9984];
    /* 0x9984 */ s32 unk9984;
};
struct calcul2_champs_9cdf83 {
    char pad0[0xE];
    /* 0xE */ s16 unkE;
};
struct temp_v0_champs_9cdf83 {
    char pad0[0x4];
    /* 0x4 */ s16 unk4;
    /* 0x6 */ s16 unk6;
    /* 0x8 */ s32 unk8;
    char padC[0x2];
    /* 0xE */ s16 unkE;
    char pad10[0x12];
    /* 0x22 */ u8 unk22;
    /* 0x23 */ u8 unk23;
};
extern "C" s32 printf(...);
extern "C" s32 sndSetReverb__Fiii(s32, s32, s32);
extern "C" s32 LoadSeBase__6CSceneFiP1(...);
extern "C" s32 LoadSeBattle__6CSceneFiP1(...);
extern "C" s32 LoadSeEnv__6CSceneFiP1(...);
extern "C" s32 LoadSeSrc__6CSceneFiP1(...);
extern "C" s32 LoadSound__6CSceneFiP1(CScene_9cdf83 *arg0, s32 arg1, s32 arg2) {
    struct temp_v0_champs_9cdf83 *temp_v0;
    s16 temp_a1;
    s16 temp_a1_2;
    s16 temp_a1_3;
    s16 temp_a1_4;
    s16 temp_v1;
    s16 temp_v1_2;
    s32 var_a0;
    s32 var_a1;
    s32 var_a2;
    s32 var_a3;
    s32 var_s1;
    s32 var_s2;

    if (arg0->unk9070 != 0) {
        arg0->unk9070 = 0;
        return 0;
    }
    printf(&_1194);
    temp_v0 = (struct temp_v0_champs_9cdf83 *) (SearchSndDataID__6CSceneFi(arg0, arg1));
    if (temp_v0 == NULL) {
        return 0;
    }
    temp_a1 = (s16) (temp_v0->unk4);
    if (temp_a1 < 0) {
        InitSeBas__6CSceneFv(arg0);
    } else if (temp_a1 != 0x270F) {
        LoadSeBase__6CSceneFiP1(arg0, temp_a1, arg2);
    }
    temp_a1_2 = (s16) (temp_v0->unk6);
    if (temp_a1_2 < 0) {
        InitSeBattle__6CSceneFv(arg0);
    } else if (temp_a1_2 != 0x270F) {
        LoadSeBattle__6CSceneFiP1(arg0, temp_a1_2, arg2);
    }
    temp_a1_3 = (s16) (temp_v0->unk8);
    if (temp_a1_3 < 0) {
        InitSeEnv__6CSceneFv(arg0);
    } else if (temp_a1_3 != 0x270F) {
        LoadSeEnv__6CSceneFiP1(arg0, temp_a1_3, arg2);
    }
    temp_v1 = (s16) (temp_v0->unkE);
    if (temp_v1 != 0x270F) {
        if (temp_v1 < 0) {
            InitSeSrc__6CSceneFv(arg0);
        } else {
            var_a0 = 0;
            var_a1 = 0;
            var_a2 = 0;
            var_a3 = 0;
            do {
                temp_v1_2 = (s16) (((struct calcul0_champs_9cdf83 *) (((struct temp_v0_champs_9cdf83 *) ((u8 *) temp_v0 + var_a2))))->unkE);
                if ((temp_v1_2 >= 0) && (temp_v1_2 != ((struct calcul1_champs_9cdf83 *) (((CScene_9cdf83 *) ((u8 *) arg0 + var_a3))))->unk9984)) {
                    var_a0 = 1;
                }
                var_a1 += 1;
                var_a2 += 2;
                var_a3 += 4;
            } while (var_a1 < 8);
            if (var_a0 != 0) {
                InitSeSrc__6CSceneFv(arg0);
                var_s1 = 0;
                var_s2 = 0;
                do {
                    temp_a1_4 = (s16) (((struct calcul2_champs_9cdf83 *) (((struct temp_v0_champs_9cdf83 *) ((u8 *) temp_v0 + var_s2))))->unkE);
                    if (temp_a1_4 >= 0) {
                        LoadSeSrc__6CSceneFiP1(arg0, temp_a1_4, arg2);
                    }
                    var_s1 += 1;
                    var_s2 += 2;
                } while (var_s1 < 8);
            }
        }
    }
    sndSetReverb__Fiii(1, (s32) temp_v0->unk22, (s32) temp_v0->unk23);
    printf(&_1195, temp_v0->unk22, temp_v0->unk23);
    arg0->unk9068 = arg1;
    PlayEnvBgm__6CSceneFv(arg0);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", LoadBGM__6CSceneFiP1);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", LoadSeSrc__6CSceneFiP1);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", LoadSeEnv__6CSceneFiP1);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", LoadSeBattle__6CSceneFiP1);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", LoadSeBase__6CSceneFiP1);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", LoadBGMPack__6CSceneFiPUi);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", LoadSeSrcPack__6CSceneFiPUi);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", LoadSeEnvPack__6CSceneFiPUi);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", LoadSeBattlePack__6CSceneFiPUi);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", LoadSeBasePack__6CSceneFiPUi);
typedef struct CScene {
    /* 0x0000 */ char pad0[0x9E00];
    /* 0x9E00 */ s32 unk9E00;                       /* inferred */
    /* 0x9E04 */ s32 unk9E04;                       /* inferred */
    /* 0x9E08 */ char pad9E08[0x80];                /* maybe part of unk9E04[0x21]? */
    /* 0x9E88 */ s32 unk9E88;                       /* inferred */
    /* 0x9E8C */ s32 unk9E8C;                       /* inferred */
    /* 0x9E90 */ char pad9E90[0x80];                /* maybe part of unk9E8C[0x21]? */
    /* 0x9F10 */ s32 unk9F10;                       /* inferred */
    /* 0x9F14 */ s32 unk9F14;                       /* inferred */
    /* 0x9F18 */ char pad9F18[0x80];                /* maybe part of unk9F14[0x21]? */
    /* 0x9F98 */ s32 unk9F98;                       /* inferred */
    /* 0x9F9C */ s32 unk9F9C;                       /* inferred */
} CScene;                                           /* size >= 0x9FA0 */
extern "C" void PrePlaySeSrc__6CSceneFv(CScene *objet) {
    objet->unk9E00 = -1;
    objet->unk9E04 = 0;
    objet->unk9E88 = -1;
    objet->unk9E8C = 0;
    objet->unk9F10 = -1;
    objet->unk9F14 = 0;
    objet->unk9F98 = -1;
    objet->unk9F9C = 0;
}
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", PlaySeSrc__6CSceneFiff);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", check_se_play__6CSceneFi);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", GetTimeBgmVolf__6CSceneFv);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", StepSnd__6CSceneFv);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", StopSeSrc__6CSceneFv);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", PlayMapSeSrc__6CSceneFv);
struct CSceneSndOff { u8 pad0[0x8864]; u32 revCount; u8 revInfo[0x1C30]; u32 sndHandle; };
extern "C" s32 sndSePlay__FUiii(u32, s32, s32);
extern "C" void SePlayOpenDoor__6CSceneFiPf(char *self, s32 arg1, f32 *arg2) {
    sndSePlay__FUiii(((CSceneSndOff *) self)->sndHandle, arg1 * 2 + 0x3C, 0);
}

extern "C" s32 sndSePlay__FUiii(u32, s32, s32);
extern "C" void SePlayCloseDoor__6CSceneFiPf(char *self, s32 arg1, f32 *arg2) {
    sndSePlay__FUiii(((CSceneSndOff *) self)->sndHandle, arg1 * 2 + 0x3D, 0);
}

INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", SePlayFoot__6CSceneFiiPf);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", GetLine__FPPcPcPc_002AC650);
extern "C" s32 memcpy(...);
extern "C" void LoadSndRevInfo__6CSceneFPci(CSceneSndOff *self, char *src, u32 n) {
    self->revCount = n >> 3;
    memcpy(self->revInfo, src, n);
}

INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", LoadSndFileInfo__6CSceneFPci);
void EditAnalyzeDataSrc::Init(void) {
    this->field_0x0 = 0;
    this->field_0x4 = 0;
    this->field_0x6 = 0;
    this->field_0x8 = -1;
    this->field_0x9 = -1;
    this->field_0xA = -1;
    this->field_0xB = -1;
    this->field_0xC = -1;
    this->field_0xD = -1;
    this->field_0xE = -1;
    this->field_0xF = -1;
    this->field_0x10 = -1;
    this->field_0x14 = 0;
    this->field_0x18 = 0;
}
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", Init__14EditAnalyzeSrcFv);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", GetAnalyzeDataSrc__Fii);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", Initialize__9CEditDataFv);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", InitPlaceData__9CEditDataFv);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", SaveData__8CEditMapFP9CEditData);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", LoadData__8CEditMapFP9CEditData);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", GetCulturePoint__FP10CEditPartsi);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", CultureAnalyzeParts__8CEditMapFii);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", CultureAnalyze__8CEditMapFi);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", GetOnOffParts__8CEditMapFPcPP9CMapPartsPP9CMapPiecei);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", PartsOnOff__8CEditMapFiP9CEditData);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", GetPartsNumID__9CEditDataFi);
extern "C" s32 GetAnalyzeDataSrc__Fii(s32, s32);
extern "C" u8 _1131_00373D10[17];
struct CEditData_analyze {
    char pad0[0x5050];
    s8 unk5050[0x40];
};
extern "C" s32 printf(...);
extern "C" s8 Analyze__9CEditDataFiiPii(CEditData_analyze *objet, s32 arg0, s32 arg1, s32 *arg2, s32 arg3) {
    s32 *src;
    s8 result;
    s32 i;
    s8 idx;

    if (arg3 > 0x40) {
        printf(&_1131_00373D10);
        return 0;
    }
    src = (s32 *) GetAnalyzeDataSrc__Fii(arg1, arg0);
    if (src == NULL) {
        return 0;
    }
    result = 0;
    if (*src == 0) {
        return 0;
    }
    for (i = 0; i < 8; i++) {
        idx = *((s8 *) src + 8 + i);
        if (idx < 0) {
            break;
        }
        result = 1;
        if (arg2[idx] >= 0) {
            objet->unk5050[idx] = Analyze__9CEditDataFiiPii(objet, arg2[idx], arg1, arg2, arg3 + 1);
            arg2[idx] = -1;
        }
        if (objet->unk5050[idx] == 0) {
            return 0;
        }
    }
    return result;
}
extern "C" void Analize__9CEditDataFiPiPi(CEditData_analyze *objet, s32 arg0, s32 *arg1, s32 *arg2) {
    s32 i;
    s32 j;

    for (i = 0; i < 0x40; i++) {
        if (arg2[i] < 0) {
            objet->unk5050[i] = (s8) arg1[i];
        }
    }
    for (j = 0; j < 0x40; j++) {
        if (arg2[j] >= 0) {
            objet->unk5050[j] = Analyze__9CEditDataFiiPii(objet, arg2[j], arg0, arg2, 0);
            arg2[j] = -1;
        }
    }
}
extern "C" s32 GetAnalyzeData__9CEditDataFii(void *, s32 a, s32 b) {
    return GetAnalyzeDataSrc__Fii(a, b);
}

INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", GetAnalyzeSrc__9CEditDataFi);
extern "C" s32 GetAnalyzeDataSrc__Fii(s32, s32);
struct AnalyzeSrcEntry {
    s32 unk0;
    s16 unk4;
};
struct CEditData;
extern "C" s32 GetAnalyzeFlag__9CEditDataFii(CEditData *, s32, s32);
extern "C" s32 GetAnalyzePercent__9CEditDataFi(CEditData *objet, s32 arg0) {
    s32 var_s2;
    s32 var_s3;
    struct AnalyzeSrcEntry *temp_v0;

    var_s3 = 0;
    var_s2 = 0;
loop_1:
    temp_v0 = (struct AnalyzeSrcEntry *) (GetAnalyzeDataSrc__Fii(arg0, var_s3));
    if (temp_v0 == NULL) {
        return var_s2;
    }
    if ((temp_v0->unk0 != 0) && (GetAnalyzeFlag__9CEditDataFii(objet, arg0, var_s3) != 0)) {
        var_s2 += temp_v0->unk4;
    }
    var_s3 += 1;
    if (var_s3 >= 0x10) {
        return var_s2;
    }
    goto loop_1;
}
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", GetAnalyzeFlag__9CEditDataFiiPiPi);
struct CEditData {
    s32 field_0;
    s32 field_4;
    s32 field_8;
    s32 field_C;
    char pad_10[0x2A30];
    s32 field_2A40;
    char pad_2A44[0x21FC];
    u8 field_4C40;
    char pad_4C41[0x3FF];
    s32 field_5040;
};
extern "C" s32 GetAnalyzeFlag__9CEditDataFiiPiPi(void *, s32, s32, s32 *, s32 *);
extern "C" s32 GetAnalyzeFlag__9CEditDataFii(CEditData *objet, s32 arg0, s32 arg1) {
    /* Les emplacements de pile portent la taille que le commerce leur donne,
     * lue sur l'ecart entre deux adresses prises, et ils sont declares dans
     * l'ordre croissant de leur decalage : MWCC attribue la pile dans l'ordre
     * des declarations, m2c les ecrit a l'envers. Deux entiers a la place de
     * ces tableaux rendaient un cadre de la moitie, et l'ordre de m2c les
     * echangeait. */
    s32 sp10[8];
    s32 sp30[8];
    return GetAnalyzeFlag__9CEditDataFiiPiPi(objet, arg0, arg1, sp10, sp30);
}
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", dbgSetContintionFlag__9CEditDataFiii);
extern "C" s32 GetAnalyzeData__9CEditDataFii(void *, s32, s32);
struct AnalyzeDataCond {
    char pad0[0x8];
    /* 0x8 */ s32 unk8;
};
extern "C" s32 dbgSetContintionFlag__9CEditDataFiii(void *, s32, s32, s32);
extern "C" void dbgSetAnalyzeFlag__9CEditDataFiii(CEditData *objet, s32 arg0, s32 arg1, s32 arg2) {
    u8 *data;
    s32 i;

    data = (u8 *) GetAnalyzeData__9CEditDataFii(objet, arg0, arg1);
    if (data == NULL) {
        return;
    }
    for (i = 0; i < 8; i++) {
        s8 flag = (s8) data[8 + i];
        if (flag < 0) {
            break;
        }
        dbgSetContintionFlag__9CEditDataFiii(objet, arg0, flag, arg2);
    }
}
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", dbgSetAllContintionFlag__9CEditDataFii);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", dbgGetContintionFlag__9CEditDataFiiPc);
typedef struct Stack_1272_champs {
    char pad0[36];
    s32 unk24;
    s32 unk28;
    char pad2C[4];
} Stack_1272_champs;
extern "C" Stack_1272_champs Stack_1272;
extern "C" u8 _1281_00373D28[10];
extern "C" u8 _1282_00373D40[26];
extern "C" s8 init_1273;
extern "C" u8 buff_1271[12288];
extern "C" s32 Init__9mgCMemoryFv(void *);
extern "C" s32 LoadFile2__FPcPvPii(...);
extern "C" s32 printf(...);
extern "C" s32 sprintf(...);
extern "C" s32 stSetBuffer__9mgCMemoryFP1i(...);
extern "C" s32 LoadEditAnalyzeData__FPciP9mgCMemory(...);
extern "C" void LoadEditAnalyzeData__FiP1(s32 arg0, s8 *arg1) {
    s8 sp30[0x4C];
    s32 sp7C;

    if (init_1273 == 0) {
        Init__9mgCMemoryFv(&Stack_1272);
        init_1273 = 1;
    }
    stSetBuffer__9mgCMemoryFP1i(&Stack_1272, &buff_1271, 0x300);
    sprintf(sp30, &_1281_00373D28, arg0);
    if (LoadFile2__FPcPvPii(sp30, arg1, &sp7C, 0) != 0) {
        LoadEditAnalyzeData__FPciP9mgCMemory(arg1, sp7C, &Stack_1272);
    }
    printf(&_1282_00373D40, ((Stack_1272.unk28 - Stack_1272.unk24) * 16) / 1024);
}
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", LoadEditAnalyzeData__FPciP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", eaGEO_ANALYZE__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", eaCONDITION__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", eaANALYZE__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", eaCON_NO__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", eaON_PARTS__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", eaOFF_PARTS__FP9SPI_STACKi);
struct eaAnaData_champs {
    char pad0[0x4];
    /* 0x4 */ s16 unk4;
};
extern "C" s32 spiGetStackInt__FP9SPI_STACK(SPI_STACK *arg0);
extern "C" s32 eaPERCENT__FP9SPI_STACKi(SPI_STACK *arg0, s32 arg1) {
    if (eaAnaData == NULL) {
        return 0;
    }
    ((struct eaAnaData_champs *) eaAnaData)->unk4 = spiGetStackInt__FP9SPI_STACK(arg0);
    return 1;
}
s32 eaEND_ANALYZE(SPI_STACK * arg0, s32 arg1) {
    eaAnaData = 0;
    return 1;
}
s32 eaEND_GEO_ANALYZE(SPI_STACK * arg0, s32 arg1) {
    eaAnaSrc = 0;
    return 1;
}
struct irregular;
struct match;
extern "C" s32 GetMaxPolyn__Fi(s32 arg0) {
    s32 var_v0;

    var_v0 = 0xFA0;
    if (arg0 != 4) {
        var_v0 = 0x1770;
        switch (arg0) {                             /* irregular */
        case 0:
            return 0xFA0;
        case 1:
            return 0x1770;
        case 2:
            return 0x1770;
        case 3:
            /* Duplicate return node #10. Try simplifying control flow for better match */
            return var_v0;
        default:
            return 0;
        }
    } else {
        return var_v0;
    }
}
struct irregular;
struct match;
extern "C" s32 GetMaxDrawMem__Fi(s32 arg0) {
    s32 var_v0;

    var_v0 = 0xBB80;
    if (arg0 != 4) {
        var_v0 = 0xD2F0;
        switch (arg0) {                             /* irregular */
        case 0:
            return 0xBB80;
        case 1:
            return 0xC350;
        case 2:
            return 0xD2F0;
        case 3:
            /* Duplicate return node #10. Try simplifying control flow for better match */
            return var_v0;
        default:
            return 0;
        }
    } else {
        return var_v0;
    }
}
struct EditAnalyzeSrc;
extern "C" s32 Init__14EditAnalyzeSrcFv(void *);
extern "C" EditAnalyzeSrc *__ct__14EditAnalyzeSrcFv(EditAnalyzeSrc *objet) {
    Init__14EditAnalyzeSrcFv(objet);
    return objet;
}
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", MenuChapterInit__FP9mgCMemoryPiii);
extern "C" u8 CSnd;
extern "C" u32 MenuChapterInfo;
extern "C" u32 MenuChapterMode;
extern "C" u32 MenuChapterSnd_ID;
extern "C" u32 MenuMainScene;
extern "C" s8 init_919;
extern "C" s8 init_922;
extern "C" s32 menu_chap_error_check_cnt;
extern "C" s32 menu_snd_counter;
extern "C" u32 voiceflag_921;
extern "C" u32 wait_cnt_918;
struct MenuChapterInfo_champs_852b18 {
    char pad0[0x18];
    /* 0x18 */ s32 unk18;
};
extern "C" s32 CalcMenuAdd__FPfff(u32, f32, f32);
extern "C" s32 FadeCheck__10CFadeInOutFv(...);
extern "C" s32 FadeOut__10CFadeInOutFifff(u32, s32, f32, f32, f32);
extern "C" s32 StreamClose__6CSoundFi(void *, s32);
extern "C" s32 StreamGetState__6CSoundFi(void *, s32);
extern "C" s32 StreamPlay__6CSoundFi(void *, s32);
extern "C" s32 StreamSetVol__6CSoundFiii(void *, s32, s32, s32);
extern "C" s32 StreamStop__6CSoundFi(void *, s32);
extern "C" s32 sndSePlay__FUiii(u32, s32, s32);
extern "C" s32 MenuChapterKey__Fv(void) {
    s32 temp_v0;
    s32 temp_v0_2;
    s32 var_s0;

    var_s0 = 0;
    if (init_919 == 0) {
        wait_cnt_918 = 0;
        init_919 = 1;
    }
    if (init_922 == 0) {
        voiceflag_921 = 0;
        init_922 = 1;
    }
    temp_v0 = FadeCheck__10CFadeInOutFv(MenuMainScene + 0x2C70);
    switch (MenuChapterMode) {
    case 0:
        if (temp_v0 != 0) {
            menu_snd_counter += 1;
            if (menu_snd_counter == 2) {
                StreamSetVol__6CSoundFiii(&CSnd, 1, 0x7FFF, 0x7FFF);
                StreamPlay__6CSoundFi(&CSnd, 1);
                wait_cnt_918 = 0;
            }
            if (CalcMenuAdd__FPfff(MenuChapterInfo + 0x1C, 3.0f, 128.0f) != 0) {
                MenuChapterMode = 1;
                ((struct MenuChapterInfo_champs_852b18 *) MenuChapterInfo)->unk18 = 0;
                menu_snd_counter = 0;
                menu_chap_error_check_cnt = 0;
                voiceflag_921 = 0;
            }
        }
        break;
    case 1:
        ((struct MenuChapterInfo_champs_852b18 *) MenuChapterInfo)->unk18 = (s32) (((struct MenuChapterInfo_champs_852b18 *) MenuChapterInfo)->unk18 + 1);
        menu_chap_error_check_cnt += 1;
        temp_v0_2 = StreamGetState__6CSoundFi(&CSnd, 1);
        if (temp_v0_2 != 0x8000) {
            if (menu_chap_error_check_cnt > 0x5DC) {
                goto block_16;
            }
        } else {
block_16:
            voiceflag_921 = 1;
        }
        if ((voiceflag_921 != 0) && (temp_v0_2 == 0)) {
            if (menu_snd_counter == 0) {
                StreamStop__6CSoundFi(&CSnd, 1);
                StreamClose__6CSoundFi(&CSnd, 1);
            }
            menu_snd_counter += 1;
        }
        if (menu_snd_counter == 0x24) {
            sndSePlay__FUiii(MenuChapterSnd_ID, 0, 0);
        }
        if ((((struct MenuChapterInfo_champs_852b18 *) MenuChapterInfo)->unk18 > 0x12C) && (menu_snd_counter >= 0x15A)) {
            FadeOut__10CFadeInOutFifff(MenuMainScene + 0x2C70, 0x3C, 0.0f, 0.0f, 0.0f);
            MenuChapterMode = 2;
        }
        break;
    case 2:
        if (temp_v0 != 0) {
            var_s0 = 1;
        }
        break;
    }
    return var_s0;
}
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", MenuChapterDraw__Fv);
extern "C" u32 NpcBaseDataTotalNum;
struct SPI_STACK {
    s32 field_0;
    s32 field_4;
};
extern "C" s32 spiGetStackInt__FP9SPI_STACK(SPI_STACK *arg0);
extern "C" s32 _NPC_NUM__FP9SPI_STACKi(SPI_STACK *arg0, s32 arg1) {
    NpcBaseDataTotalNum = spiGetStackInt__FP9SPI_STACK(arg0);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", _NPC_INFO__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", LoadNPCCfg__Fv);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", GetPartyCharaMessage__Fiii);
extern "C" s32 GetPartyNPCData__Fi(s32 arg0);
extern "C" s32 GetNPCModelName__Fi(s32 arg0) {
    s32 temp_v0;

    temp_v0 = GetPartyNPCData__Fi(arg0);
    if (temp_v0 != 0) {
        return temp_v0 + 0x1F;
    }
    return 0;
}
extern "C" s32 GetPartyNPCData__Fi(s32 arg0);
extern "C" s32 GetNPCName__Fi(s32 arg0) {
    s32 temp_v0;

    temp_v0 = GetPartyNPCData__Fi(arg0);
    if (temp_v0 != 0) {
        return temp_v0 + 3;
    }
    return 0;
}
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", GetPartyCharaModelName__Fii);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", GetPartyNPCData__Fi);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", _WMAP_POSNUM__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", _WMAP_POS__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", _WMAP_AREANUM__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", _WMAP_AREA__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cscene_002A9FF0", worldmap_analyze__FP9mgCMemoryPci);
