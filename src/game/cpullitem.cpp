/* CPullItem, CLaserGun, CColPrim, CRoboVoiceSystem, CMachineGun, CColPrimMan, CRocketLauncherMan, CLaserGunMan, CPullItemManager, CTreasureBox
 *
 * Unité découpée par `make carve` : 63 fonctions, 23076 octets, de
 * 0x001B7C50 à 0x001BD800. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"
#include "gen/CColPrim.hpp"
#include "gen/CLaserGun.hpp"
#include "gen/CPullItem.hpp"
#include "gen/CRoboVoiceSystem.hpp"
#include "gen/CTreasureBox.hpp"

INCLUDE_ASM("nonmatchings/game/cpullitem", Get__18CRocketLauncherManFv);
INCLUDE_ASM("nonmatchings/game/cpullitem", Draw__18CRocketLauncherManFv);
INCLUDE_ASM("nonmatchings/game/cpullitem", Step__18CRocketLauncherManFv);
INCLUDE_ASM("nonmatchings/game/cpullitem", Clear__18CRocketLauncherManFv);
INCLUDE_ASM("nonmatchings/game/cpullitem", Initialize__18CRocketLauncherManFP8mgCFrameiP10mgCTexture);
INCLUDE_ASM("nonmatchings/game/cpullitem", Set__11CMachineGunFPfPf);
INCLUDE_ASM("nonmatchings/game/cpullitem", Step__11CMachineGunFv);
INCLUDE_ASM("nonmatchings/game/cpullitem", SetPos__9CLaserGunFPfPfPf);
struct inferred;
typedef struct CLaserGun_infere {
    /* 0x000 */ char pad0[0xDC];
    /* 0x0DC */ s32 unkDC;                          /* inferred */
    /* 0x0E0 */ s32 unkE0;                          /* inferred */
    /* 0x0E4 */ s32 unkE4;                          /* inferred */
    /* 0x0E8 */ char padE8[8];                      /* maybe part of unkE4[3]void */
    /* 0x0F0 */ s32 unkF0;                          /* inferred */
    /* 0x0F4 */ s32 unkF4;                          /* inferred */
    /* 0x0F8 */ s32 unkF8;                          /* inferred */
    /* 0x0FC */ s32 unkFC;                          /* inferred */
    /* 0x100 */ s32 unk100;                         /* inferred */
    /* 0x104 */ s32 unk104;                         /* inferred */
    /* 0x108 */ s16 unk108;                         /* inferred */
    /* 0x10A */ char pad10A[6];                     /* maybe part of unk108[4]void */
    /* 0x110 */ s32 unk110;                         /* inferred */
    /* 0x114 */ s32 unk114;                         /* inferred */
    /* 0x118 */ s32 unk118;                         /* inferred */
} CLaserGun_infere;                                        /* size >= 0x11C */
extern "C" void SetVisualCode__9CLaserGunFi(CLaserGun_infere *objet, s32 arg0) {
    objet->unk108 = (s16) arg0;
    if (arg0 == 0) {
        objet->unkFC = 0x3DCCCCCD;
        objet->unk100 = 0x3DCCCCCD;
        objet->unk104 = 0x3F000000;
        objet->unk110 = 0x42800000;
        objet->unk114 = 0x43000000;
        objet->unk118 = 0x42800000;
    }
    if (arg0 == 1) {
        objet->unkFC = 0x3E4CCCCD;
        objet->unk100 = 0x3ECCCCCD;
        objet->unk104 = 0x3F4CCCCD;
        objet->unkDC = 0x41F00000;
        objet->unk110 = 0x42800000;
        objet->unk114 = 0x42800000;
        objet->unk118 = 0x43000000;
    }
    if (arg0 == 2) {
        objet->unkFC = 0x3E4CCCCD;
        objet->unk100 = 0x3ECCCCCD;
        objet->unk104 = 0x3FB33333;
        objet->unkDC = 0x41700000;
        objet->unkE0 = 0x40A00000;
        objet->unkE4 = 0x42200000;
        objet->unk110 = 0x43000000;
        objet->unk114 = 0x42000000;
        objet->unk118 = 0x43000000;
    }
    if (arg0 == 3) {
        objet->unkFC = 0x3E4CCCCD;
        objet->unk100 = 0x3E4CCCCD;
        objet->unk104 = 0x3F19999A;
        objet->unkDC = 0;
        objet->unkE0 = 0x40000000;
        objet->unkE4 = 0x420C0000;
        objet->unkF0 = 0;
        objet->unkF4 = 0x1869F;
        objet->unkF8 = 0x4B;
        objet->unk110 = 0;
        objet->unk114 = 0x43000000;
        objet->unk118 = 0x43000000;
    }
    if (arg0 == 4) {
        objet->unkFC = 0x3ECCCCCD;
        objet->unk100 = 0x3ECCCCCD;
        objet->unk104 = 0x3FE66666;
        objet->unkDC = 0x41200000;
        objet->unkE0 = 0x40A00000;
        objet->unkE4 = 0x41F00000;
        objet->unkF0 = 0;
        objet->unkF4 = 5;
        objet->unkF8 = 0x4B;
        objet->unk110 = 0x43000000;
        objet->unk114 = 0x42800000;
        objet->unk118 = 0;
    }
}
INCLUDE_ASM("nonmatchings/game/cpullitem", Step__9CLaserGunFv);
INCLUDE_ASM("nonmatchings/game/cpullitem", Draw__9CLaserGunFv);
void CLaserGun::Initialize(void) {
    this->field_0x0 = -1;
    this->field_0xD0 = 0;
    this->field_0xD4 = 0;
    this->field_0x120 = 0;
    this->field_0xE8 = -1;
    this->field_0xEC = 0;
}
INCLUDE_ASM("nonmatchings/game/cpullitem", Get__12CLaserGunManFv);
INCLUDE_ASM("nonmatchings/game/cpullitem", Draw__12CLaserGunManFv);
INCLUDE_ASM("nonmatchings/game/cpullitem", Step__12CLaserGunManFv);
INCLUDE_ASM("nonmatchings/game/cpullitem", Clear__12CLaserGunManFv);
INCLUDE_ASM("nonmatchings/game/cpullitem", Initialize__12CLaserGunManFP8mgCFrameiP10mgCTexture);
INCLUDE_ASM("nonmatchings/game/cpullitem", Draw__9CPullItemFP10mgCTexture);
INCLUDE_ASM("nonmatchings/game/cpullitem", Step__9CPullItemFv);
INCLUDE_ASM("nonmatchings/game/cpullitem", IsGet__9CPullItemFPf);
INCLUDE_ASM("nonmatchings/game/cpullitem", SetItem__9CPullItemFPfPfi);
void CPullItem::Clear(void) {
    this->field_0x74 = -1;
    this->field_0x7C = 0;
}
void CPullItem::Initialize(void) {
    this->field_0x7C = 0;
    this->field_0x42 = 0;
    this->field_0x30 = 0;
    this->field_0x32 = 0;
    this->field_0x34 = 32;
    this->field_0x36 = 32;
    this->field_0x50 = 0;
    this->field_0x44 = 0;
}
INCLUDE_ASM("nonmatchings/game/cpullitem", GetList__16CPullItemManagerFi);
INCLUDE_ASM("nonmatchings/game/cpullitem", Clear__16CPullItemManagerFv);
void CRoboVoiceSystem::SetStatus(s32 arg0, s32 arg1) {
    this->field_0x0 = 1;
    this->field_0xC = arg0;
    this->field_0x10 = arg1;
}
typedef struct CRoboVoiceSystem_infere2 {
    /* 0x00 */ s16 unk0;                            /* inferred */
    /* 0x02 */ char pad2[2];
    /* 0x04 */ s32 unk4;                            /* inferred */
    /* 0x08 */ char pad8[4];
    /* 0x0C */ s32 unkC;                            /* inferred */
    /* 0x10 */ char pad10[2];
    /* 0x12 */ s16 unk12;                           /* inferred */
} CRoboVoiceSystem_infere2;                                 /* size >= 0x14 */
extern "C" s32 iRand__Fi(s32);
extern "C" void StartVoiceSystem__16CRoboVoiceSystemFv(CRoboVoiceSystem_infere2 *objet) {
    objet->unk0 = 5;
    objet->unkC = -1;
    objet->unk12 = iRand__Fi(0xF0) + 0x3C;
    objet->unk4 = 0;
}
extern "C" u8 CSnd;
typedef struct CRoboVoiceSystem_infere {
    /* 0x00 */ s16 unk0;                            /* inferred */
    /* 0x02 */ char pad2[2];
    /* 0x04 */ s32 unk4;                            /* inferred */
    /* 0x08 */ char pad8[0xE];                      /* maybe part of unk4[4]void */
    /* 0x16 */ s16 unk16;                           /* inferred */
} CRoboVoiceSystem_infere;                                 /* size >= 0x18 */
extern "C" s32 StreamClose__6CSoundFi(void *, s32);
extern "C" s32 StreamOpenState__6CSoundFv(void *);
extern "C" void StopVoice__16CRoboVoiceSystemFi(CRoboVoiceSystem_infere *objet, s32 arg0) {
    if (objet->unk4 != 0) {
        do {

        } while (StreamOpenState__6CSoundFv(&CSnd) != 0);
        StreamClose__6CSoundFi(&CSnd, 1);
    }
    objet->unk4 = 0;
    objet->unk0 = 0;
    objet->unk16 = (s16) arg0;
}
INCLUDE_ASM("nonmatchings/game/cpullitem", Step__16CRoboVoiceSystemFv);
INCLUDE_ASM("nonmatchings/game/cpullitem", SetDamage__8CColPrimFPci);
INCLUDE_ASM("nonmatchings/game/cpullitem", SetCoord__8CColPrimFPff);
typedef struct CColPrim_infere {
    /* 0x00 */ char pad0[0x20];
    /* 0x20 */ s32 unk20;                           /* inferred */
    /* 0x24 */ char pad24[0xC];                     /* maybe part of unk20[4]void */
    /* 0x30 */ s32 unk30;                           /* inferred */
    /* 0x34 */ char pad34[0xC];                     /* maybe part of unk30[4]void */
    /* 0x40 */ f32 unk40;                           /* inferred */
    /* 0x44 */ char pad44[0xC];                     /* maybe part of unk40[4]void */
    /* 0x50 */ f32 unk50;                           /* inferred */
    /* 0x54 */ char pad54[0xC];                     /* maybe part of unk50[4]void */
    /* 0x60 */ f32 unk60;                           /* inferred */
    /* 0x64 */ char pad64[0xC];                     /* maybe part of unk60[4]void */
    /* 0x70 */ f32 unk70;                           /* inferred */
    /* 0x74 */ char pad74[0x10];                    /* maybe part of unk70[5]void */
    /* 0x84 */ f32 unk84;                           /* inferred */
    /* 0x88 */ char pad88[0x28];                    /* maybe part of unk84[0xB]void */
    /* 0xB0 */ f32 unkB0;                           /* inferred */
} CColPrim_infere;                                         /* size >= 0xB4 */
struct arg0_champs {
    char pad0[0xC];
    /* 0xC */ s32 unkC;
};
struct arg1_champs {
    char pad0[0xC];
    /* 0xC */ s32 unkC;
};
extern "C" s32 sceVu0CopyVector(...);
extern "C" void SetCoord__8CColPrimFPfPff(CColPrim_infere *objet, struct arg0_champs *arg0, struct arg1_champs *arg1, f32 arg2) {
    arg0->unkC = 0x3F800000;
    arg1->unkC = 0x3F800000;
    if (objet->unk20 == 0) {
        sceVu0CopyVector(&objet->unk40);
        sceVu0CopyVector(&objet->unk50, arg1);
        sceVu0CopyVector(&objet->unk60, arg0);
        sceVu0CopyVector(&objet->unk70, arg1);
        sceVu0CopyVector(&objet->unkB0, arg0);
    } else {
        sceVu0CopyVector(&objet->unk60, &objet->unk40);
        sceVu0CopyVector(&objet->unk70, &objet->unk50);
        sceVu0CopyVector(&objet->unk40, arg0);
        sceVu0CopyVector(&objet->unk50, arg1);
    }
    objet->unk84 = arg2;
    objet->unk30 = 1;
}
#include "gen/mgCFrame.hpp"
typedef struct CColPrim_infere2 {
    /* 0x00 */ char pad0[0x20];
    /* 0x20 */ s32 unk20;                           /* inferred */
    /* 0x24 */ char pad24[0xC];                     /* maybe part of unk20[4]void */
    /* 0x30 */ s32 unk30;                           /* inferred */
    /* 0x34 */ char pad34[4];
    /* 0x38 */ mgCFrame *unk38;                     /* inferred */
    /* 0x3C */ s32 unk3C;                           /* inferred */
    /* 0x40 */ char pad40[0x44];                    /* maybe part of unk3C[0x12]void */
    /* 0x84 */ f32 unk84;                           /* inferred */
    /* 0x88 */ char pad88[0x28];                    /* maybe part of unk84[0xB]void */
    /* 0xB0 */ f32 unkB0;                           /* inferred */
} CColPrim_infere2;                                         /* size >= 0xB4 */
extern "C" s32 GetWorldPosition0__8mgCFrameFPf(void *, f32 *);
extern "C" void SetCoord__8CColPrimFP8mgCFramef(CColPrim_infere2 *objet, mgCFrame *arg0, f32 arg1) {
    objet->unk38 = arg0;
    objet->unk3C = 0;
    objet->unk84 = arg1;
    objet->unk30 = 2;
    if ((objet->unk20 == 0) && (arg0 != NULL)) {
        GetWorldPosition0__8mgCFrameFPf(arg0, &objet->unkB0);
    }
}
typedef struct CColPrim_infere3 {
    /* 0x00 */ char pad0[0x20];
    /* 0x20 */ s32 unk20;                           /* inferred */
    /* 0x24 */ char pad24[0xC];                     /* maybe part of unk20[4]void */
    /* 0x30 */ s32 unk30;                           /* inferred */
    /* 0x34 */ char pad34[4];
    /* 0x38 */ mgCFrame *unk38;                     /* inferred */
    /* 0x3C */ mgCFrame *unk3C;                     /* inferred */
    /* 0x40 */ char pad40[0x44];                    /* maybe part of unk3C[0x12]void */
    /* 0x84 */ f32 unk84;                           /* inferred */
    /* 0x88 */ char pad88[0x28];                    /* maybe part of unk84[0xB]void */
    /* 0xB0 */ f32 unkB0;                           /* inferred */
} CColPrim_infere3;                                         /* size >= 0xB4 */
extern "C" void SetCoord__8CColPrimFP8mgCFrameP8mgCFramef(CColPrim_infere3 *objet, mgCFrame *arg0, mgCFrame *arg1, f32 arg2) {
    objet->unk38 = arg0;
    objet->unk3C = arg1;
    objet->unk84 = arg2;
    objet->unk30 = 2;
    if ((objet->unk20 == 0) && (arg0 != NULL)) {
        GetWorldPosition0__8mgCFrameFPf(arg0, &objet->unkB0);
    }
}
INCLUDE_ASM("nonmatchings/game/cpullitem", IsHit__8CColPrimFP6CScenei);
INCLUDE_ASM("nonmatchings/game/cpullitem", IsReversVec__8CColPrimFP8CColPrim);
INCLUDE_ASM("nonmatchings/game/cpullitem", GetReversVec__8CColPrimFPf);
void CColPrim::DebugDraw(void) {
}
INCLUDE_ASM("nonmatchings/game/cpullitem", Step__8CColPrimFv);
INCLUDE_ASM("nonmatchings/game/cpullitem", Delete__8CColPrimFi);
void CColPrim::Initialize(void) {
    this->field_0xC = 0;
    this->field_0x10 = -1;
    this->field_0x18 = 0;
    this->field_0x20 = 0;
    this->field_0x24 = -1;
    this->field_0x28 = 0;
    this->field_0xC0 = 0;
    this->field_0xE6 = 0;
    this->field_0x34 = 0;
    this->field_0x3C = 0;
    this->field_0x38 = 0;
    this->field_0x84 = 0;
    this->field_0x8C = -1;
}
INCLUDE_ASM("nonmatchings/game/cpullitem", GetPrim__11CColPrimManFv);
INCLUDE_ASM("nonmatchings/game/cpullitem", GetID2Prim__11CColPrimManFi);
INCLUDE_ASM("nonmatchings/game/cpullitem", ActivePrimNum__11CColPrimManFv);
INCLUDE_ASM("nonmatchings/game/cpullitem", Delete__11CColPrimManFi);
INCLUDE_ASM("nonmatchings/game/cpullitem", CheckHit__11CColPrimManFi);
INCLUDE_ASM("nonmatchings/game/cpullitem", IsReversVec__11CColPrimManFP8CColPrim);
INCLUDE_ASM("nonmatchings/game/cpullitem", Step__11CColPrimManFv);
#include "sphida.hpp"
struct inferred;
struct CColPrimMan;
typedef struct CColPrimMan {
    /* 0x0 */ CScene *unk0;                         /* inferred */
} CColPrimMan;                                      /* size >= 0x4 */
struct temp_s2_champs_d98954 {
    char pad0[0x10];
    /* 0x10 */ s32 unk10;
};
extern "C" s32 Initialize__8CColPrimFv(void *);
extern "C" void Initialize__11CColPrimManFP6CScene(CColPrimMan *objet, CScene *arg0) {
    s32 var_s0;
    s32 var_s1;
    struct temp_s2_champs_d98954 *temp_s2;

    var_s1 = 0;
    objet->unk0 = arg0;
    var_s0 = 0;
    do {
        temp_s2 = (struct temp_s2_champs_d98954 *) (((CColPrimMan *) ((u8 *) objet + var_s1)));
        Initialize__8CColPrimFv(((struct temp_s2_champs_d98954 *) ((u8 *) temp_s2 + 0x10)));
        temp_s2->unk10 = var_s0;
        var_s0 += 1;
        var_s1 += 0x110;
    } while (var_s0 < 0x40);
}
INCLUDE_ASM("nonmatchings/game/cpullitem", dngGetDebugInfo__Fv);
extern "C" u8 dbFont[184];
typedef struct dbinfo_champs {
    s16 unk0;
    s16 unk2;
    char pad4[12];
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
} dbinfo_champs;
extern "C" dbinfo_champs dbinfo;
extern "C" s32 Init__5CFontFv(void *);
extern "C" s32 SetClearance__5CFontFii(void *, s32, s32);
extern "C" void dngDebugInit__Fv(void) {
    dbinfo.unk0 = 0;
    dbinfo.unk2 = 0;
    dbinfo.unk10 = 1;
    dbinfo.unk14 = 0;
    dbinfo.unk18 = 0;
    dbinfo.unk1C = 0;
    Init__5CFontFv(&dbFont);
    SetClearance__5CFontFii(&dbFont, 0x14, 0x14);
}
INCLUDE_ASM("nonmatchings/game/cpullitem", dngDebugStart__Fv);
INCLUDE_ASM("nonmatchings/game/cpullitem", dngDebugDraw__Fv);
INCLUDE_ASM("nonmatchings/game/cpullitem", dngDebugExit__Fv);
INCLUDE_ASM("nonmatchings/game/cpullitem", dngDebugKey__Fv);
void CTreasureBox::Initialize(void) {
    this->field_0x54 = 0;
    this->field_0x50 = 0;
    this->field_0x58 = 1;
}
INCLUDE_ASM("nonmatchings/game/cpullitem", DBGCMD_ReloadEnemy__Fii);
INCLUDE_ASM("nonmatchings/game/cpullitem", DrawSystemParamInfo__Fv);
INCLUDE_ASM("nonmatchings/game/cpullitem", DrawSystemParamInfo2__Fv);
typedef struct command_int_champs {
    char pad0[48];
    s32 unk30;
    char pad34[40];
} command_int_champs;
extern "C" command_int_champs command_int;
extern "C" s32 DrawSystemParamInfo2__Fv(void);
extern "C" s32 DrawSystemParamInfo__Fv(void);
extern "C" void DrawDebugWindow__Fv(void) {
    if (command_int.unk30 == 2) {
        DrawSystemParamInfo__Fv();
    }
    if (command_int.unk30 == 3) {
        DrawSystemParamInfo2__Fv();
    }
}
INCLUDE_ASM("nonmatchings/game/cpullitem", PrintV__FiiiP10mgCTexture9mgRect_i_iiiP7SP_RGBA);
INCLUDE_ASM("nonmatchings/game/cpullitem", DrawDrumCounter__Fiii);
INCLUDE_ASM("nonmatchings/game/cpullitem", DrawActiveItemCursor__Fiif);
