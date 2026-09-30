/* CActionChara
 *
 * Unité découpée par `make carve` : 22 fonctions, 18220 octets, de
 * 0x001ACF40 à 0x001B16D0. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"
extern s32 SubMapLoadBG;
extern s32 now_load_map_no;


INCLUDE_ASM("nonmatchings/game/cactionchara_001ACF40", __ct__12CActionCharaFv);
struct CScene;
extern "C" CScene *MainScene_0037D328;
struct CScene {
    s32 field_0;
    s32 field_4;
    char pad_8[0x30];
    s32 field_38;
    s32 field_3C;
    s32 field_40;
    char pad_44[0x2000];
    s32 field_2044;
    char pad_2048[0x1C0];
    s32 field_2208;
    char pad_220C[0x5D4];
    s32 field_27E0;
    char pad_27E4[0xE0];
    s32 field_28C4;
    char pad_28C8[0xE0];
    s32 field_29A8;
    char pad_29AC[0x100];
    s32 field_2AAC;
    char pad_2AB0[0x1EC];
    s32 field_2C9C;
    s32 field_2CA0;
    char pad_2CA4[0x1A0];
    s32 field_2E44;
    s32 field_2E48;
    char pad_2E4C[0x4];
    s32 field_2E50;
    s32 field_2E54;
    s32 field_2E58;
    s32 field_2E5C;
    s32 field_2E60;
    s32 field_2E64;
    s32 field_2E68;
    s32 field_2E6C;
    s32 field_2E70;
    s32 field_2E74;
    s32 field_2E78;
    s32 field_2E7C;
    s32 field_2E80;
    s32 field_2E84;
    s32 field_2E88;
    s32 field_2E8C;
    char pad_2E90[0x8];
    s32 field_2E98;
    char pad_2E9C[0x8];
    s32 field_2EA4;
    f32 field_2EA8;
    f32 field_2EAC;
    f32 field_2EB0;
    f32 field_2EB4;
    char pad_2EB8[0x8];
    f32 field_2EC0;
    f32 field_2EC4;
    f32 field_2EC8;
    f32 field_2ECC;
    f32 field_2ED0;
    f32 field_2ED4;
    f32 field_2ED8;
    f32 field_2EDC;
    f32 field_2EE0;
    f32 field_2EE4;
    f32 field_2EE8;
    f32 field_2EEC;
    char pad_2EF0[0x38];
    f32 field_2F28;
    char pad_2F2C[0x8];
    f32 field_2F34;
    f32 field_2F38;
    char pad_2F3C[0x14];
    s32 field_2F50;
    s32 field_2F54;
    s32 field_2F58;
    s32 field_2F5C;
    s32 field_2F60;
    s32 field_2F64;
    s32 field_2F68;
    f32 field_2F6C;
    f32 field_2F70;
    s32 field_2F74;
    f32 field_2F78;
    char pad_2F7C[0x4];
    f32 field_2F80;
    char pad_2F84[0x10];
    s32 field_2F94;
    s32 field_2F98;
    s16 field_2F9C;
    char pad_2F9E[0x2];
    s32 field_2FA0;
    char pad_2FA4[0x10];
    s8 field_2FB4;
    char pad_2FB5[0x1F];
    s16 field_2FD4;
    s16 field_2FD6;
    s8 field_2FD8;
    s8 field_2FD9;
    char pad_2FDA[0x6];
    f32 field_2FE0;
    s32 field_2FE4;
    s32 field_2FE8;
    s32 field_2FEC;
    char pad_2FF0[0x4];
    s32 field_2FF4;
    char pad_2FF8[0x4];
    s32 field_2FFC;
    char pad_3000[0x8];
    s16 field_3008;
    char pad_300A[0x2];
    s32 field_300C;
    s32 field_3010;
    s32 field_3014;
    s32 field_3018;
    s8 field_301C;
    char pad_301D[0x3];
    s64 field_3020;
    s32 field_3028;
    s8 field_302C;
    char pad_302D[0x1];
    s16 field_302E;
    s32 field_3030;
    char pad_3034[0x4];
    s32 field_3038;
    s32 field_303C;
    char pad_3040[0x14];
    s32 field_3054;
    char pad_3058[0xE08];
    s32 field_3E60;
    s32 field_3E64;
    s32 field_3E68;
    s32 field_3E6C;
    char pad_3E70[0x1F0];
    s32 field_4060;
    char pad_4064[0x4800];
    u32 field_8864;
    char pad_8868[0x800];
    s32 field_9068;
    char pad_906C[0x4];
    s32 field_9070;
    s32 field_9074;
    char pad_9078[0x8];
    s32 field_9080;
    char pad_9084[0x45C];
    s32 field_94E0;
    char pad_94E4[0x45C];
    s32 field_9940;
    char pad_9944[0x4BC];
    s32 field_9E00;
    s32 field_9E04;
    char pad_9E08[0x80];
    s32 field_9E88;
    s32 field_9E8C;
    char pad_9E90[0x80];
    s32 field_9F10;
    s32 field_9F14;
    char pad_9F18[0x80];
    s32 field_9F98;
    s32 field_9F9C;
    char pad_9FA0[0x80];
    s32 field_A020;
    s32 field_A024;
    s32 field_A028;
    s32 field_A02C;
    s32 field_A030;
    s32 field_A034;
    s32 field_A038;
    s32 field_A03C;
    u32 field_A040;
    s32 field_A044;
    char pad_A048[0x424];
    s32 field_A46C;
    char pad_A470[0x4];
    s32 field_A474;
    char pad_A478[0x8];
    s32 field_A480;
    s32 field_A484;
    f32 field_A488;
    f32 field_A48C;
    s32 field_A490;
    s32 field_A494;
    s32 field_A498;
    s32 field_A49C;
    char pad_A4A0[0x2030];
    u32 field_C4D0;
    s32 field_C4D4;
};
extern "C" s32 BreakReadBG__Fv(void);
extern "C" s32 InitSeSrc__6CSceneFv(void *);
extern "C" s32 SubGameRunning__Fv(void);
extern "C" s32 mgCloseFont__Fv(void);
extern "C" s32 sgExitSubGame__Fv(void);
extern "C" s32 sndSeAllStop__Fi(s32);
extern "C" s32 sndStopVoice__Fi(s32);
extern "C" void EditExit__Fv(void) {
    sndSeAllStop__Fi(1);
    InitSeSrc__6CSceneFv(MainScene_0037D328);
    mgCloseFont__Fv();
    BreakReadBG__Fv();
    sndStopVoice__Fi(1);
    if (SubGameRunning__Fv() != 0) {
        sgExitSubGame__Fv();
    }
}
void InitSubMapLoadStep(void) {
    SubMapLoadBG = 0;
    now_load_map_no = -1;
}
INCLUDE_ASM("nonmatchings/game/cactionchara_001ACF40", SubMapLoadStep__Fv);
INCLUDE_ASM("nonmatchings/game/cactionchara_001ACF40", EditLoop__Fv);
extern "C" u8 EditEvent[336];
extern "C" s32 InitLockCharaCtrl__Fv(void);
extern "C" s32 Reset__10CEditEventFv(void *);
extern "C" void InitEditEvent__Fv(void) {
    InitLockCharaCtrl__Fv();
    Reset__10CEditEventFv(&EditEvent);
}
INCLUDE_ASM("nonmatchings/game/cactionchara_001ACF40", ResetEditEvent__Fv);
INCLUDE_ASM("nonmatchings/game/cactionchara_001ACF40", RestartEditEvent__Fv);
INCLUDE_ASM("nonmatchings/game/cactionchara_001ACF40", EditStep__Fv);
INCLUDE_ASM("nonmatchings/game/cactionchara_001ACF40", EditDraw__Fv);
INCLUDE_ASM("nonmatchings/game/cactionchara_001ACF40", UpdateTrBoxFlag__Fi);
INCLUDE_ASM("nonmatchings/game/cactionchara_001ACF40", BurnEditParts__Fv);
extern "C" u32 read_buffer;
struct inferred;
struct CScene_infere;
typedef struct CScene_infere {
    /* 0x0000 */ char pad0[0x906C];
    /* 0x906C */ s32 unk906C;                       /* inferred */
} CScene_infere;                                           /* size >= 0x9070 */
struct MainScene_0037D328_champs_ef01bb {
    char pad0[0x906C];
    /* 0x906C */ s32 unk906C;
};
extern "C" s32 AutoChangeBGMVol__6CSceneFi(void *, s32);
extern "C" s32 CheckLoadBGM__6CSceneFi(void *, s32);
extern "C" s32 GetDefBgmNo__6CSceneFi(void *, s32);
extern "C" s32 GetMapSndDataID__Fi(s32);
extern "C" s32 LoadBGM__6CSceneFiP1(...);
extern "C" s32 LoadSound__6CSceneFiP1(...);
extern "C" s32 PlayBGM__6CSceneFiif(void *, s32, s32, f32);
extern "C" s32 StepSnd__6CSceneFv(void *);
extern "C" s32 StopBGM__6CSceneFi(void *, s32);
extern "C" s32 sndStep__Ff(f32);
extern "C" void editLoadSound__Fi(s32 arg0) {
    s32 temp_v0;
    s32 temp_v0_2;

    temp_v0 = GetMapSndDataID__Fi(arg0);
    LoadSound__6CSceneFiP1(MainScene_0037D328, temp_v0, read_buffer);
    if (((struct MainScene_0037D328_champs_ef01bb *) MainScene_0037D328)->unk906C == 0) {
        temp_v0_2 = GetDefBgmNo__6CSceneFi(MainScene_0037D328, temp_v0);
        if (temp_v0_2 == -1) {
            StopBGM__6CSceneFi(MainScene_0037D328, 0);
        }
        if ((CheckLoadBGM__6CSceneFi(MainScene_0037D328, temp_v0_2) == 0) || (temp_v0_2 == 0x270F)) {
            PlayBGM__6CSceneFiif(MainScene_0037D328, 0, -1, 1.0f);
            return;
        }
        StopBGM__6CSceneFi(MainScene_0037D328, 0);
        if (LoadBGM__6CSceneFiP1(MainScene_0037D328, temp_v0_2, read_buffer) != 0) {
            PlayBGM__6CSceneFiif(MainScene_0037D328, 0, -1, 1.0f);
            if (temp_v0_2 == 0) {
                AutoChangeBGMVol__6CSceneFi(MainScene_0037D328, 1);
                StepSnd__6CSceneFv(MainScene_0037D328);
                sndStep__Ff(2.0f);
            }
        }
    } else {
        ((struct MainScene_0037D328_champs_ef01bb *) MainScene_0037D328)->unk906C = 0;
    }
}
INCLUDE_ASM("nonmatchings/game/cactionchara_001ACF40", EditMapJump__Fi);
INCLUDE_ASM("nonmatchings/game/cactionchara_001ACF40", EditGotoInterior__Fii);
INCLUDE_ASM("nonmatchings/game/cactionchara_001ACF40", EditExitInterior__Fi);
typedef struct DebugInfo_champs {
    char pad0[8];
    s32 unk8;
    char padC[8];
} DebugInfo_champs;
extern "C" DebugInfo_champs DebugInfo;
extern "C" s32 GetMap__6CSceneFi(void *, s32);
extern "C" s32 GetSaveData__Fv(void);
extern "C" u32 MapNo;
extern "C" u8 _2747[9];
extern "C" s32 GetEditData__9CSaveDataFi(...);
struct CEditData;
struct CEditMap;
struct CScene_infere2;
typedef struct CEditData {
    /* 0x0 */ s32 unk0;                             /* inferred */
    /* 0x4 */ s32 unk4;                             /* inferred */
} CEditData;                                        /* size >= 0x8 */
struct CEditMapPad { char pad0[0xD00]; };
struct CEditMap : CEditMapPad {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual char *v17();
};
typedef struct CScene_infere2 {
    /* 0x0000 */ char pad0[0x2E5C];
    /* 0x2E5C */ s32 unk2E5C;                       /* inferred */
} CScene_infere2;                                           /* size >= 0x2E60 */
struct MainScene_0037D328_champs_dedef6 {
    char pad0[0x2E5C];
    /* 0x2E5C */ s32 unk2E5C;
};
struct unkD00_champs_dedef6 {
    char pad0[0x4C];
    /* 0x4C */ s32 (*unk4C)(...);
};
extern "C" s32 AnalyzeEditMap__FiP8CEditMap(s32, CEditMap *);
extern "C" s32 CultureAnalyze__8CEditMapFi(void *, s32);
extern "C" s32 GetBitFlag__9CSaveDataFi(...);
extern "C" s32 GetMapType__Fi(s32);
extern "C" s32 GroundBalance__8CEditMapFi(void *, s32);
extern "C" s32 InInterior__Fv(void);
extern "C" s32 SaveData__8CEditMapFP9CEditData(void *, CEditData *);
extern "C" s32 UpdateHouse__8CEditMapFv(void *);
extern "C" s32 strcmp(...);
extern "C" void EditDataSave__Fv(void) {
    CEditData *temp_v0;
    CEditMap *temp_v0_2;

    if (InInterior__Fv() == 0) {
        temp_v0 = (CEditData *) (GetEditData__9CSaveDataFi(GetSaveData__Fv(), MapNo));
        if (temp_v0 != NULL) {
            temp_v0_2 = (CEditMap *) (GetMap__6CSceneFi(MainScene_0037D328, ((struct MainScene_0037D328_champs_dedef6 *) MainScene_0037D328)->unk2E5C));
            if ((temp_v0_2 != NULL) && (strcmp(temp_v0_2->v17(), &_2747) == 0) && (temp_v0_2 != NULL)) {
                SaveData__8CEditMapFP9CEditData(temp_v0_2, temp_v0);
                GetBitFlag__9CSaveDataFi(GetSaveData__Fv(), 0x208);
                temp_v0->unk4 = CultureAnalyze__8CEditMapFi(temp_v0_2, 0);
                temp_v0->unk0 += 1;
                GroundBalance__8CEditMapFi(temp_v0_2, 0);
                UpdateHouse__8CEditMapFv(temp_v0_2);
                if ((DebugInfo.unk8 == 0) && (GetMapType__Fi(MapNo) == 1)) {
                    AnalyzeEditMap__FiP8CEditMap(MapNo, temp_v0_2);
                }
            }
        }
    }
}
INCLUDE_ASM("nonmatchings/game/cactionchara_001ACF40", EditDataLoad__Fv);
INCLUDE_ASM("nonmatchings/game/cactionchara_001ACF40", KeepEditAnalyze__Fv);
INCLUDE_ASM("nonmatchings/game/cactionchara_001ACF40", EditAnalyzeChanged__Fv);
void LoadComVillaager(void) {
}
extern "C" void LoadComVillaager__Fv(void);
extern "C" void LoadMap__Fv(void) {
    LoadComVillaager__Fv();
}

