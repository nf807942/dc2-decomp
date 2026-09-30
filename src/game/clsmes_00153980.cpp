/* ClsMes
 *
 * Unité découpée par `make carve` : 22 fonctions, 13416 octets, de
 * 0x00153980 à 0x00156E60. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"
#include "gen/ClsMes.hpp"

struct ClsMesA4a {
    char p0[0xB8]; s32 fB8; char pBC[0xC]; s32 fC8; s32 fCC; char pD0[0x68];
    u32 f138; char p13C[0x1D10]; s32 f1E4C; char p1E50[0x420]; s32 f2270; char p2274[0x1C]; s32 f2290;
};
extern "C" s32 SetDefColor__6ClsMesFUi(void *, u32);
extern "C" void SetWindowMode__6ClsMesFi(ClsMesA4a *o, s32 mode) {
    if (mode == 2) {
        mode = 4;
    }
    o->f138 = mode;
    switch (mode) {
    case 1:
        o->fC8 = 0xF;
        o->fCC = 0x18;
        SetDefColor__6ClsMesFUi(o, 0x80202020U);
        o->f2290 = 0;
        o->fB8 = 0;
        o->f1E4C = 1;
        o->f2270 = 2;
        break;
    case 2:
        SetDefColor__6ClsMesFUi(o, 0x80686A6BU);
        o->f2290 = 0;
        o->fB8 = 5;
        o->f1E4C = 0;
        o->f2270 = 0;
        break;
    case 3:
        SetDefColor__6ClsMesFUi(o, 0x80686A6BU);
        o->f2290 = 0;
        o->fB8 = 5;
        o->f1E4C = 0;
        o->f2270 = 0;
        break;
    case 4:
        SetDefColor__6ClsMesFUi(o, 0x80686A6BU);
        o->f2290 = 0;
        o->fB8 = 5;
        o->f1E4C = 0;
        o->f2270 = 0;
        break;
    case 5:
        SetDefColor__6ClsMesFUi(o, 0x80686A6BU);
        o->f2290 = 0;
        o->fB8 = 5;
        o->f1E4C = 0;
        o->f2270 = 0;
        break;
    case 6:
        SetDefColor__6ClsMesFUi(o, 0x80686A6BU);
        o->f2290 = 0;
        o->fB8 = 5;
        o->f1E4C = 0;
        o->f2270 = 0;
        break;
    case 8:
        SetDefColor__6ClsMesFUi(o, 0x80686A6BU);
        o->f2290 = 0;
        o->fB8 = 5;
        o->f1E4C = 0;
        o->f2270 = 0;
        break;
    case 7:
        SetDefColor__6ClsMesFUi(o, 0x80686A6BU);
        o->f2290 = 0;
        o->fB8 = 8;
        o->f1E4C = 1;
        o->f2270 = 0;
        break;
    case 9:
    case 10:
        SetDefColor__6ClsMesFUi(o, 0x80686A6BU);
        o->f2290 = 0;
        o->fB8 = 4;
        o->f1E4C = 1;
        o->f2270 = 0;
        break;
    case 11:
        SetDefColor__6ClsMesFUi(o, 0x80202020U);
        o->f2290 = 0;
        o->fB8 = 0;
        o->f1E4C = 1;
        o->f2270 = 0;
        break;
    case 12:
        o->f138 = 0;
        SetDefColor__6ClsMesFUi(o, 0x80202020U);
        o->f2290 = 0;
        o->fB8 = 0;
        o->f1E4C = 0;
        o->f2270 = 0;
        break;
    default:
        o->f138 = 0;
        SetDefColor__6ClsMesFUi(o, 0x80686A6BU);
        o->f2290 = 0;
        o->fB8 = 8;
        o->f1E4C = 0;
        o->f2270 = 0;
        break;
    }
}
s32 ClsMes::GetWindowMode(void) {
    return this->field_0x138;
}
void ClsMes::SetWindowBgOpaqueFlg(s32 arg0) {
    this->field_0x13C = arg0;
}
INCLUDE_ASM("nonmatchings/game/clsmes_00153980", StepNpcName__6ClsMesFv);
INCLUDE_ASM("nonmatchings/game/clsmes_00153980", StepNormal__6ClsMesFv);
INCLUDE_ASM("nonmatchings/game/clsmes_00153980", Step__6ClsMesFv);
INCLUDE_ASM("nonmatchings/game/clsmes_00153980", State__6ClsMesFv);
struct inferred;
typedef struct ClsMes_infere {
    /* 0x0000 */ char pad0[0xE8];
    /* 0x00E8 */ s32 unkE8;                         /* inferred */
    /* 0x00EC */ char padEC[0xEC];                  /* maybe part of unkE8[0x3C]void */
    /* 0x01D8 */ s32 unk1D8;                        /* inferred */
    /* 0x01DC */ char pad1DC[0x10];                 /* maybe part of unk1D8[5]void */
    /* 0x01EC */ s32 unk1EC;                        /* inferred */
    /* 0x01F0 */ s32 unk1F0;                        /* inferred */
    /* 0x01F4 */ char pad1F4[0x1C40];               /* maybe part of unk1F0[0x711]void */
    /* 0x1E34 */ s32 unk1E34;                       /* inferred */
} ClsMes_infere;                                           /* size >= 0x1E38 */
extern "C" void GoNextPage__6ClsMesFv(ClsMes_infere *objet) {
    if (objet->unk1D8 != 0) {
        objet->unk1D8 = 0;
        objet->unkE8 += 1;
        objet->unk1E34 = 0;
        objet->unk1F0 = objet->unk1EC;
    }
}
INCLUDE_ASM("nonmatchings/game/clsmes_00153980", MyTextureMake_sub__6ClsMesFv);
INCLUDE_ASM("nonmatchings/game/clsmes_00153980", MyTextureMake__6ClsMesFv);
INCLUDE_ASM("nonmatchings/game/clsmes_00153980", SetAndGetNameRegistTbl__Fi);
INCLUDE_ASM("nonmatchings/game/clsmes_00153980", MakeMesWinTbl_value__6ClsMesFPiPi);
INCLUDE_ASM("nonmatchings/game/clsmes_00153980", MakeMesWinTbl_value__6ClsMesFiPiPi);
INCLUDE_ASM("nonmatchings/game/clsmes_00153980", MakeMesWinTbl_str__6ClsMesFPcPiPi);
extern "C" void MakeMesWinTbl_str__6ClsMesFPcPiPi(void *, char *, int *, int *);
extern "C" void MakeMesWinTbl_str__6ClsMesFiPiPi(void *self, int i, int *a2, int *a3) { MakeMesWinTbl_str__6ClsMesFPcPiPi(self, (char*)self + i*50 + 0x1E59, a2, a3); }
INCLUDE_ASM("nonmatchings/game/clsmes_00153980", MakeMesWinTbl_item__6ClsMesFiPiPi);
INCLUDE_ASM("nonmatchings/game/clsmes_00153980", GetMesWidth_system__6ClsMesFi);
INCLUDE_ASM("nonmatchings/game/clsmes_00153980", GetTextLineDataTop__6ClsMesFi);
INCLUDE_ASM("nonmatchings/game/clsmes_00153980", GetTextLineDataTop_system__6ClsMesFi);
struct MesWinEnt {
    s16 a;
    s16 b;
    s16 c;
    s32 d;
    s8 e;
};
struct ClsMesWin {
    char pad0[0x1F8];
    MesWinEnt tbl[450];
    s32 f0;
    s32 f1;
    s32 f2;
    s32 f3;
};
extern "C" void InitMesWinTbl__6ClsMesFv(ClsMesWin *self) {
    s32 i;
    for (i = 0; i < 450; i++) {
        self->tbl[i].a = 0;
        self->tbl[i].b = 0;
        self->tbl[i].c = 0;
        self->tbl[i].d = 0;
        self->tbl[i].e = 0;
    }
    self->f0 = 0;
    self->f1 = 0;
    self->f2 = 0;
    self->f3 = 0;
}
INCLUDE_ASM("nonmatchings/game/clsmes_00153980", SetMesWinTbl__6ClsMesFiss);
INCLUDE_ASM("nonmatchings/game/clsmes_00153980", CalcSpaceW__6ClsMesFiiPUs);
