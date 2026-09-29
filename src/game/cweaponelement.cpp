/* CWeaponElement, CEnemyLifeGage, CLevelupInfo, CPiyori, CGiftMark, CEnemyGekirin
 *
 * Unité découpée par `make carve` : 41 fonctions, 19680 octets, de
 * 0x001C6FD0 à 0x001CBDA0. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"
#include "gen/CGiftMark.hpp"
#include "gen/CPiyori.hpp"

INCLUDE_ASM("nonmatchings/game/cweaponelement", Initialize__14CWeaponElementFv);
INCLUDE_ASM("nonmatchings/game/cweaponelement", Set__14CWeaponElementFPA4_fPffif);
extern "C" s32 Step_Cold__14CWeaponElementFv(void *);
extern "C" s32 Step_Fire__14CWeaponElementFv(void *);
extern "C" s32 Step_Thunder__14CWeaponElementFv(void *);
extern "C" s32 Step_Wind__14CWeaponElementFv(void *);
extern "C" void Step__14CWeaponElementFv(void *objet) {
    s16 temp_v1;

    if (*(s16 *) ((u8 *) objet + 0x5AC) != 0) {
        temp_v1 = *(s16 *) ((u8 *) objet + 0x5A4);
        switch (temp_v1) {
        case 1:
        default:
            Step_Cold__14CWeaponElementFv(objet);
            return;
        case 3:
            Step_Wind__14CWeaponElementFv(objet);
            return;
        case 0:
            Step_Fire__14CWeaponElementFv(objet);
            return;
        case 2:
            Step_Thunder__14CWeaponElementFv(objet);
            break;
        }
    }
}
extern "C" s32 Draw_Cold__14CWeaponElementFv(void *);
extern "C" s32 Draw_Fire__14CWeaponElementFv(void *);
extern "C" s32 Draw_Thunder__14CWeaponElementFv(void *);
extern "C" s32 Draw_Wind__14CWeaponElementFv(void *);
extern "C" void Draw__14CWeaponElementFv(void *objet) {
    s16 temp_v1;

    if (*(s16 *) ((u8 *) objet + 0x5AC) != 0) {
        temp_v1 = *(s16 *) ((u8 *) objet + 0x5A4);
        switch (temp_v1) {
        case 1:
        default:
            Draw_Cold__14CWeaponElementFv(objet);
            return;
        case 3:
            Draw_Wind__14CWeaponElementFv(objet);
            return;
        case 0:
            Draw_Fire__14CWeaponElementFv(objet);
            return;
        case 2:
            Draw_Thunder__14CWeaponElementFv(objet);
            break;
        }
    }
}
INCLUDE_ASM("nonmatchings/game/cweaponelement", Init_Cold__14CWeaponElementFPf);
INCLUDE_ASM("nonmatchings/game/cweaponelement", Step_Cold__14CWeaponElementFv);
INCLUDE_ASM("nonmatchings/game/cweaponelement", Draw_Cold__14CWeaponElementFv);
INCLUDE_ASM("nonmatchings/game/cweaponelement", Init_Wind__14CWeaponElementFPf);
INCLUDE_ASM("nonmatchings/game/cweaponelement", Step_Wind__14CWeaponElementFv);
INCLUDE_ASM("nonmatchings/game/cweaponelement", Draw_Wind__14CWeaponElementFv);
INCLUDE_ASM("nonmatchings/game/cweaponelement", Init_Fire__14CWeaponElementFPf);
INCLUDE_ASM("nonmatchings/game/cweaponelement", Step_Fire__14CWeaponElementFv);
INCLUDE_ASM("nonmatchings/game/cweaponelement", Draw_Fire__14CWeaponElementFv);
INCLUDE_ASM("nonmatchings/game/cweaponelement", Init_Thunder__14CWeaponElementFPf);
INCLUDE_ASM("nonmatchings/game/cweaponelement", Step_Thunder__14CWeaponElementFv);
INCLUDE_ASM("nonmatchings/game/cweaponelement", Draw_Thunder__14CWeaponElementFv);
INCLUDE_ASM("nonmatchings/game/cweaponelement", CreatSmoothPass__FPA4_fPA4_fiiii);
INCLUDE_ASM("nonmatchings/game/cweaponelement", unitRotation__FP8mgCFrameff);
extern "C" s32 rand(...);
extern "C" s32 iRand__Fi(s32 arg0) {
    return (s32) (((f32) arg0 * (f32) rand()) / 2.1474836e9f);
}
extern "C" s32 rand(...);
extern "C" f32 fRand__Ff(f32 arg0) {
    return (arg0 * (f32) rand()) / 2.1474836e9f;
}
struct inferred;
typedef struct CLevelupInfo {
    /* 0x00 */ s32 unk0;                            /* inferred */
    /* 0x04 */ s32 unk4;                            /* inferred */
    /* 0x08 */ s32 unk8;                            /* inferred */
    /* 0x0C */ s32 unkC;                            /* inferred */
    /* 0x10 */ s32 unk10;                           /* inferred */
    /* 0x14 */ s32 unk14;                           /* inferred */
    /* 0x18 */ s32 unk18;                           /* inferred */
    /* 0x1C */ s32 unk1C;                           /* inferred */
    /* 0x20 */ s32 unk20;                           /* inferred */
    /* 0x24 */ s32 unk24;                           /* inferred */
    /* 0x28 */ s32 unk28;                           /* inferred */
    /* 0x2C */ s32 unk2C;                           /* inferred */
    /* 0x30 */ s32 unk30;                           /* inferred */
    /* 0x34 */ s32 unk34;                           /* inferred */
} CLevelupInfo;                                     /* size >= 0x38 */
extern "C" void SetLevelUpInfo__12CLevelupInfoFiiii(CLevelupInfo *objet, s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    objet->unk0 = 0;
    objet->unk4 = 0;
    objet->unk8 = 0;
    objet->unkC = 0;
    objet->unk10 = 0;
    objet->unk14 = 0;
    objet->unk18 = 0;
    objet->unk1C = 0;
    objet->unk20 = 0;
    objet->unk24 = 1;
    objet->unk28 = arg0 - 0x23;
    objet->unk2C = arg1 - 6;
    objet->unk30 = arg2;
    objet->unk34 = arg3;
}
INCLUDE_ASM("nonmatchings/game/cweaponelement", Draw__12CLevelupInfoFv);
INCLUDE_ASM("nonmatchings/game/cweaponelement", Step__12CLevelupInfoFv);
void CPiyori::Initialize(void) {
    this->field_0x0 = 0;
}
void CPiyori::Reset(void) {
    this->field_0x0 = 0;
    this->field_0x1C = 0;
}
INCLUDE_ASM("nonmatchings/game/cweaponelement", Set__7CPiyoriFP9mgCObjectffs);
struct inferred;
typedef struct mgCObject {
    /* 0x000 */ char pad0[0x10C];
    /* 0x10C */ f32 unk10C;                         /* inferred */
    /* 0x110 */ f32 unk110;                         /* inferred */
} mgCObject;                                        /* size >= 0x114 */
extern "C" s32 Set__7CPiyoriFP9mgCObjectffs(void *, mgCObject *, f32, f32, s16);
extern "C" void Set__7CPiyoriFP9mgCObjects(CPiyori *objet, mgCObject *arg0, s16 arg1) {
    if (arg0 != NULL) {
        Set__7CPiyoriFP9mgCObjectffs(objet, arg0, 2.0f * arg0->unk110, 2.0f * arg0->unk10C, arg1);
    }
}
INCLUDE_ASM("nonmatchings/game/cweaponelement", Draw__7CPiyoriFv);
INCLUDE_ASM("nonmatchings/game/cweaponelement", Step__7CPiyoriFv);
#include "sphida.hpp"
struct inferred;
typedef struct CGiftMark_infere {
    /* 0x00 */ CCharacter2 *unk0;                   /* inferred */
    /* 0x04 */ f32 unk4;                            /* inferred */
    /* 0x08 */ char pad8[4];
    /* 0x0C */ s32 unkC;                            /* inferred */
} CGiftMark_infere;                                        /* size >= 0x10 */
extern "C" s32 Initialize__9CGiftMarkFv(void *);
extern "C" void Set__9CGiftMarkFP11CCharacter2f(CGiftMark_infere *objet, CCharacter2 *arg0, f32 arg1) {
    Initialize__9CGiftMarkFv(objet);
    objet->unk0 = arg0;
    objet->unk4 = arg1;
    objet->unkC = 1;
}
INCLUDE_ASM("nonmatchings/game/cweaponelement", Draw__9CGiftMarkFv);
INCLUDE_ASM("nonmatchings/game/cweaponelement", Step__9CGiftMarkFv);
void CGiftMark::Initialize(void) {
    this->field_0x0 = 0;
    this->field_0xC = 0;
    this->field_0x8 = 0;
    this->field_0x10 = 0;
}
INCLUDE_ASM("nonmatchings/game/cweaponelement", Draw__13CEnemyGekirinFP10CPreSpriteii);
extern "C" u8 gekirin_anim[64];
extern "C" void Step__13CEnemyGekirinFv(void *objet) {
    s8 *p = (s8 *) objet;
    if (p[0] == 1) {
        p[1] += 1;
        if (*(s32 *) (gekirin_anim + p[1] * 4) == 0) {
            p[0] = 2;
        }
    }
}
INCLUDE_ASM("nonmatchings/game/cweaponelement", SetView__14CEnemyLifeGageFi);
INCLUDE_ASM("nonmatchings/game/cweaponelement", Set__14CEnemyLifeGageFPfiiii);
INCLUDE_ASM("nonmatchings/game/cweaponelement", Draw__14CEnemyLifeGageFi);
INCLUDE_ASM("nonmatchings/game/cweaponelement", Step__14CEnemyLifeGageFv);
INCLUDE_ASM("nonmatchings/game/cweaponelement", ResetGekirin__14CEnemyLifeGageFi);
typedef struct CEnemyLifeGage {
    /* 0x00 */ char pad0[0x10];
    /* 0x10 */ s32 unk10;                           /* inferred */
    /* 0x14 */ s32 unk14;                           /* inferred */
    /* 0x18 */ char pad18[4];
    /* 0x1C */ s32 unk1C;                           /* inferred */
    /* 0x20 */ s32 unk20;                           /* inferred */
} CEnemyLifeGage;                                   /* size >= 0x24 */
extern "C" s32 ResetGekirin__14CEnemyLifeGageFi(void *, s32);
extern "C" void Initialize__14CEnemyLifeGageFi(CEnemyLifeGage *objet, s32 arg0) {
    ResetGekirin__14CEnemyLifeGageFi(objet, arg0);
    objet->unk14 = 0;
    objet->unk10 = 0;
    objet->unk1C = 0;
    objet->unk20 = 0;
}
