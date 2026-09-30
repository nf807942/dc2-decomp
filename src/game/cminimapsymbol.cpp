/* CMiniMapSymbol, CHealingPoint, CDamageScore, CThunder, CFireAfterHit, CChillAfterHit, CAfterWire
 *
 * Unité découpée par `make carve` : 34 fonctions, 20916 octets, de
 * 0x001D1AF0 à 0x001D6D80. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"
#include "gen/CAfterWire.hpp"

INCLUDE_ASM("nonmatchings/game/cminimapsymbol", DngStep__Fv);
INCLUDE_ASM("nonmatchings/game/cminimapsymbol", RunMainEvent__Fv);
INCLUDE_ASM("nonmatchings/game/cminimapsymbol", DngMainKey__Fv);
INCLUDE_ASM("nonmatchings/game/cminimapsymbol", IsEventRun__Fv);
INCLUDE_ASM("nonmatchings/game/cminimapsymbol", EventScriptSetup__FP18SYSTEM_SCRIPT_INFO);
INCLUDE_ASM("nonmatchings/game/cminimapsymbol", IsRunDeadEvent__FP12CActionChara);
INCLUDE_ASM("nonmatchings/game/cminimapsymbol", ChangeSetUnit__Fi);
INCLUDE_ASM("nonmatchings/game/cminimapsymbol", CheckStatusError__Fv);
INCLUDE_ASM("nonmatchings/game/cminimapsymbol", InitEyeCamera__FP12CActionChara);
INCLUDE_ASM("nonmatchings/game/cminimapsymbol", CheckWeaponEnable__Fv);
INCLUDE_ASM("nonmatchings/game/cminimapsymbol", ResetEyeView__FP12CActionChara);
INCLUDE_ASM("nonmatchings/game/cminimapsymbol", EyeCamera__FP9mgCCameraP11CCharacter2i_001D53B0);
INCLUDE_ASM("nonmatchings/game/cminimapsymbol", DebugMainDraw__Fv);
INCLUDE_ASM("nonmatchings/game/cminimapsymbol", DBGCMD_RunScript__Fi);
struct CFireAfterHit {
    s32 field_0;
    s32 field_4;
    s32 field_8;
    f32 field_C;
    f32 field_10;
    char pad_14[0x29C];
    f32 field_2B0;
};
extern "C" s32 Initialize__13CFireAfterHitFv(void *);
extern "C" CFireAfterHit *__ct__13CFireAfterHitFv(CFireAfterHit *objet) {
    Initialize__13CFireAfterHitFv(objet);
    return objet;
}
struct CChillAfterHit {
    s32 field_0;
    s32 field_4;
    f32 field_8;
    char pad_C[0x4];
    f32 field_10;
    char pad_14[0xC];
    f32 field_20;
};
extern "C" s32 Initialize__14CChillAfterHitFv(void *);
extern "C" CChillAfterHit *__ct__14CChillAfterHitFv(CChillAfterHit *objet) {
    Initialize__14CChillAfterHitFv(objet);
    return objet;
}
extern "C" void __ct__8mgCFrameFv(void *);
extern "C" void *__ct__12mgCFrameAttrFv(void *);
extern "C" void *__ct__8CThunderFv(void *objet) {
    __ct__8mgCFrameFv(objet);
    __ct__12mgCFrameAttrFv((char *)objet + 0x110);
    return objet;
}
CAfterWire::CAfterWire(void) {
    this->field_0x0 = 0;
}
struct inferred;
typedef struct CDamageScore {
    /* 0x00 */ char pad0[0x48];
    /* 0x48 */ char unk48;                             /* inferred */
    /* 0x48 */ char pad48[1];
} CDamageScore;                                     /* size >= 0x49 */
extern "C" s32 memset(...);
extern "C" CDamageScore *__ct__12CDamageScoreFv(CDamageScore *objet) {
    memset(&objet->unk48, 0x80, 6);
    return objet;
}
INCLUDE_ASM("nonmatchings/game/cminimapsymbol", SetMapInfo__14CMiniMapSymbolFP4CMapP13CAutoMapPartsiiff);
INCLUDE_ASM("nonmatchings/game/cminimapsymbol", DrawSymbolOpen__14CMiniMapSymbolFv);
INCLUDE_ASM("nonmatchings/game/cminimapsymbol", DrawSymbolClose__14CMiniMapSymbolFv);
INCLUDE_ASM("nonmatchings/game/cminimapsymbol", DrawSymbol__14CMiniMapSymbolFPfi);
INCLUDE_ASM("nonmatchings/game/cminimapsymbol", DrawSymbol_Chara__14CMiniMapSymbolFP11CCharacter2);
INCLUDE_ASM("nonmatchings/game/cminimapsymbol", Draw__14CMiniMapSymbolFPf);
extern "C" u8 HealingEffectMan[816];
struct inferred;
typedef struct CHealingPoint {
    /* 0x0 */ s32 unk0;                             /* inferred */
    /* 0x4 */ s32 unk4;                             /* inferred */
} CHealingPoint;                                    /* size >= 0x8 */
extern "C" s32 SetMode__17CHealingEffectManFi(void *, s32);
extern "C" s32 CheckHealingTime__13CHealingPointFv(CHealingPoint *objet) {
    if (objet->unk0 == 0) {
        return 0;
    }
    if (objet->unk4 > 0) {
        return 0;
    }
    SetMode__17CHealingEffectManFi(&HealingEffectMan, 1);
    objet->unk4 = 0x708;
    return 1;
}
typedef struct CHealingPoint_infere {
    /* 0x0 */ s32 unk0;                             /* inferred */
    /* 0x4 */ s32 unk4;                             /* inferred */
} CHealingPoint_infere;                                    /* size >= 0x8 */
extern "C" void Step__13CHealingPointFv(CHealingPoint_infere *objet) {
    s32 temp_v1;

    if (objet->unk0 != 0) {
        temp_v1 = objet->unk4;
        if (temp_v1 > 0) {
            objet->unk4 = temp_v1 - 1;
        }
        if (objet->unk4 <= 0) {
            SetMode__17CHealingEffectManFi(&HealingEffectMan, 2);
        }
    }
}
typedef struct nowPriset_pointe {
    char pad0[12];
    s32 unkC;
} nowPriset_pointe;
extern "C" nowPriset_pointe *nowPriset;
struct SPI_STACK {
    s32 field_0;
    s32 field_4;
};
extern "C" s32 spiGetStackInt__FP9SPI_STACK(SPI_STACK *);
extern "C" s32 _ROOM_FIXED__FP9SPI_STACKi(SPI_STACK *arg0, s32 arg1) {
    nowPriset->unkC = spiGetStackInt__FP9SPI_STACK(arg0);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/cminimapsymbol", _GRID_SIZE__FP9SPI_STACKi);
extern "C" int spiGetStackInt__FP9SPI_STACK(SPI_STACK *);
extern "C" int _ROOM_ID__FP9SPI_STACKi(SPI_STACK *arg0, int arg1) {
    *(int *)nowPriset = spiGetStackInt__FP9SPI_STACK(arg0);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/cminimapsymbol", _ROOM_SIZE__FP9SPI_STACKi);
struct nowPriset_champs_f0d9ee {
    char pad0[0x10];
    /* 0x10 */ s32 unk10;
};
extern "C" s32 _ROOM_RATE__FP9SPI_STACKi(SPI_STACK *arg0, s32 arg1) {
    ((struct nowPriset_champs_f0d9ee *) nowPriset)->unk10 = spiGetStackInt__FP9SPI_STACK(arg0);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/cminimapsymbol", _RD__FP9SPI_STACKi);
extern "C" s32 _ROOM_END__FP9SPI_STACKi(void *arg0, s32 arg1) {
    nowPriset = (nowPriset_pointe *) ((u8 *) nowPriset + 0x18);
    return 1;
}
