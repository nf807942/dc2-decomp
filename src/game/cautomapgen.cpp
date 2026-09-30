/* CAutoMapGen, CActionChara, CActiveMonster, CMonsterLocateInfo
 *
 * Unité découpée par `make carve` : 37 fonctions, 21612 octets, de
 * 0x001D6D80 à 0x001DC2F0. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

INCLUDE_ASM("nonmatchings/game/cautomapgen", SetupRoomInfo__11CAutoMapGenFPciP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/cautomapgen", CreatRoom__11CAutoMapGenFiiii);
INCLUDE_ASM("nonmatchings/game/cautomapgen", LinkConnectCheck__11CAutoMapGenFiiiii);
INCLUDE_ASM("nonmatchings/game/cautomapgen", SetRoadLinkMark__11CAutoMapGenFiii);
INCLUDE_ASM("nonmatchings/game/cautomapgen", RoomLink__11CAutoMapGenFii);
INCLUDE_ASM("nonmatchings/game/cautomapgen", CreatDummyRoot__11CAutoMapGenFi);
INCLUDE_ASM("nonmatchings/game/cautomapgen", CreatTermParts__11CAutoMapGenFv);
INCLUDE_ASM("nonmatchings/game/cautomapgen", CreatDoorRoom__11CAutoMapGenFv);
INCLUDE_ASM("nonmatchings/game/cautomapgen", SearchDoorParts__11CAutoMapGenFv);
INCLUDE_ASM("nonmatchings/game/cautomapgen", SetPartsIndex__11CAutoMapGenFv);
INCLUDE_ASM("nonmatchings/game/cautomapgen", SetDummyMountain__11CAutoMapGenFv);
INCLUDE_ASM("nonmatchings/game/cautomapgen", SetDummyTree__11CAutoMapGenFv);
INCLUDE_ASM("nonmatchings/game/cautomapgen", SearchHealingPoint__11CAutoMapGenFP4CMap);
INCLUDE_ASM("nonmatchings/game/cautomapgen", IndexToPartsPlace__11CAutoMapGenFv);
INCLUDE_ASM("nonmatchings/game/cautomapgen", SetInOutPartsIndex__11CAutoMapGenFi);
INCLUDE_ASM("nonmatchings/game/cautomapgen", SetHealingPointIndex__11CAutoMapGenFv);
INCLUDE_ASM("nonmatchings/game/cautomapgen", CreatFixedMap__11CAutoMapGenFi);
INCLUDE_ASM("nonmatchings/game/cautomapgen", RandomMapMainProc__11CAutoMapGenFv);
INCLUDE_ASM("nonmatchings/game/cautomapgen", Build__11CAutoMapGenFv);
INCLUDE_ASM("nonmatchings/game/cautomapgen", MinimapVisTest__11CAutoMapGenFPf);
INCLUDE_ASM("nonmatchings/game/cautomapgen", MinimapDoorOpen__11CAutoMapGenFPf);
INCLUDE_ASM("nonmatchings/game/cautomapgen", SearchRandomStone__11CAutoMapGenFPff);
INCLUDE_ASM("nonmatchings/game/cautomapgen", ClearRandomStone__11CAutoMapGenFv);
extern "C" void Step__13CHealingPointFv(void *);
extern "C" void Step__11CAutoMapGenFv(void *o) { Step__13CHealingPointFv((unsigned char *)o + 0x1C0); }
INCLUDE_ASM("nonmatchings/game/cautomapgen", GetAttrStatus__11CAutoMapGenFPf);
INCLUDE_ASM("nonmatchings/game/cautomapgen", MinimapAllVisible__11CAutoMapGenFv);
INCLUDE_ASM("nonmatchings/game/cautomapgen", GetNaviDistance__11CAutoMapGenFPf);
INCLUDE_ASM("nonmatchings/game/cautomapgen", UpdateNaviMap__11CAutoMapGenFPfi);
INCLUDE_ASM("nonmatchings/game/cautomapgen", IsDraw__14CActiveMonsterFi);
INCLUDE_ASM("nonmatchings/game/cautomapgen", CheckStatusAttr__14CActiveMonsterFv);
struct CActiveMonsterView {
    char pad0[0x12E4];
    s16 state;
    char pad12E6[2];
    f32 scale;
    char pad12EC[4];
    s16 view;
    char pad12F2[2];
    f32 x;
    char pad12F8[4];
    f32 y;
    char pad1300[0x48];
    s32 flags;
};
extern "C" s16 CheckView__14CActiveMonsterFi(CActiveMonsterView *objet, s32 arg0) {
    s32 v;

    v = objet->view;
    if (v < 0) {
        v = 99;
    }
    if (objet->flags & 0x200) {
        objet->state = 2;
        objet->scale = 1.0f;
        return objet->state;
    }
    if (objet->state == 0) {
        if (objet->x < objet->y) {
            objet->state = 2;
            objet->scale = 1.0f;
        } else {
            objet->state = 1;
            objet->scale = 1.0f;
        }
        return objet->state;
    }
    if (objet->state == 2) {
        if (!(objet->x <= 30.0f + objet->y) || v >= arg0) {
            objet->state = 4;
        }
    }
    if (objet->state == 1 && objet->x < objet->y && v < arg0) {
        objet->state = 3;
    }
    return objet->state;
}
extern "C" void Step__12CActionCharaFv(void *);
extern "C" void Step__14CActiveMonsterFv(void *o) { Step__12CActionCharaFv(o); }
INCLUDE_ASM("nonmatchings/game/cautomapgen", Copy__14CActiveMonsterFR14CActiveMonsterP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/cautomapgen", __as__12CActionCharaFRC12CActionChara);
struct CActiveMonsterInitView {
    char pad0[0xBF4];
    /* 0xBF4 */ s8 unkBF4;
    /* 0xBF5 */ s8 unkBF5;
    char padBF6[0x55E];
    /* 0x1154 */ s16 unk1154;
    /* 0x1156 */ s16 unk1156;
    /* 0x1158 */ s16 unk1158;
    /* 0x115A */ s16 unk115A;
    /* 0x115C */ s32 unk115C;
    /* 0x1160 */ s32 unk1160;
    /* 0x1164 */ s32 unk1164;
    /* 0x1168 */ s32 unk1168;
    /* 0x116C */ s32 unk116C;
    /* 0x1170 */ s32 unk1170;
    /* 0x1174 */ s32 unk1174;
    /* 0x1178 */ s32 unk1178;
    s32 unk117C[32];
    /* 0x11FC */ s32 unk11FC;
    char pad1200[0x4];
    /* 0x1204 */ s16 unk1204;
    char pad1206[0x2];
    /* 0x1208 */ s32 unk1208;
    char pad120C[0x14];
    /* 0x1220 */ s32 unk1220;
    char pad1224[0x80];
    /* 0x12A4 */ s16 unk12A4;
    char pad12A6[0x2];
    /* 0x12A8 */ s32 unk12A8;
    char pad12AC[0x10];
    /* 0x12BC */ s32 unk12BC;
    /* 0x12C0 */ s32 unk12C0;
    /* 0x12C4 */ s32 unk12C4;
    char pad12C8[0x18];
    /* 0x12E0 */ s16 unk12E0;
    /* 0x12E2 */ s16 unk12E2;
    /* 0x12E4 */ s16 unk12E4;
    char pad12E6[0x2];
    /* 0x12E8 */ s32 unk12E8;
    /* 0x12EC */ s32 unk12EC;
    /* 0x12F0 */ s16 unk12F0;
    char pad12F2[0xA];
    /* 0x12FC */ s32 unk12FC;
    /* 0x1300 */ s32 unk1300;
    /* 0x1304 */ s32 unk1304;
    /* 0x1308 */ s16 unk1308;
    char pad130A[0x2];
    /* 0x130C */ s32 unk130C;
    /* 0x1310 */ s32 unk1310;
    /* 0x1314 */ s32 unk1314;
    /* 0x1318 */ s16 unk1318;
    char pad131A[0x2];
    /* 0x131C */ s32 unk131C;
    /* 0x1320 */ s16 unk1320;
    /* 0x1322 */ s16 unk1322;
    /* 0x1324 */ s16 unk1324;
    /* 0x1326 */ s16 unk1326;
    /* 0x1328 */ s32 unk1328;
    /* 0x132C */ s32 unk132C;
    /* 0x1330 */ s32 unk1330;
    /* 0x1334 */ s32 unk1334;
    /* 0x1338 */ s16 unk1338;
    /* 0x133A */ s16 unk133A;
    /* 0x133C */ s32 unk133C;
    char pad1340[0x8];
    /* 0x1348 */ s32 unk1348;
    /* 0x134C */ s32 unk134C;
    /* 0x1350 */ s32 unk1350;
    /* 0x1354 */ s16 unk1354;
    /* 0x1356 */ s16 unk1356;
    /* 0x1358 */ s8 unk1358;
    char pad1359[0x117];
    /* 0x1470 */ s32 unk1470;
    /* 0x1474 */ s32 unk1474;
    /* 0x1478 */ s32 unk1478;
    /* 0x147C */ s32 unk147C;
    /* 0x1480 */ s32 unk1480;
    /* 0x1484 */ s32 unk1484;
    /* 0x1488 */ s32 unk1488;
    /* 0x148C */ s32 unk148C;
    /* 0x1490 */ s32 unk1490;
    /* 0x1494 */ s32 unk1494;
};
extern "C" s32 Initialize__12CActionCharaFP9mgCMemory(void *, void *);
extern "C" s32 Initialize__14CEnemyLifeGageFi(void *, s32);
extern "C" void Initialize__14CActiveMonsterFv(CActiveMonsterInitView *objet) {
    s32 i;

    Initialize__12CActionCharaFP9mgCMemory(objet, NULL);
    objet->unk1154 = 0;
    objet->unk1156 = 0;
    objet->unk1158 = -1;
    objet->unk115A = -1;
    objet->unk12E2 = 0;
    objet->unk12E4 = 0;
    objet->unk12E8 = 0;
    objet->unk12EC = 0x3F800000;
    objet->unk12F0 = 0x3E7;
    objet->unk12FC = 0x43FA0000;
    objet->unk1300 = 0x43C80000;
    objet->unk1304 = 0x43960000;
    objet->unk1308 = 0xB4;
    objet->unk12A4 = -1;
    objet->unkBF4 = 0;
    objet->unkBF5 = 0;
    objet->unk1338 = 0;
    objet->unk133A = 0;
    objet->unk12E0 = -1;
    objet->unk12C4 = 0;
    objet->unk12C0 = 0;
    objet->unk115C = 0;
    objet->unk1160 = 0;
    objet->unk1164 = 0;
    objet->unk1168 = 0;
    objet->unk116C = 0;
    objet->unk1170 = 0;
    objet->unk1174 = 0;
    objet->unk1178 = 0;
    for (i = 0; i < 32; i++) {
        objet->unk117C[i] = 0;
    }
    objet->unk1310 = 0;
    objet->unk1314 = 0;
    objet->unk1330 = 0;
    objet->unk1334 = 0;
    objet->unk11FC = 0;
    objet->unk1204 = 0;
    objet->unk1208 = 0;
    objet->unk1318 = 0;
    Initialize__14CEnemyLifeGageFi(&objet->unk1220, 0);
    objet->unk12A8 = 0;
    objet->unk12BC = -1;
    objet->unk131C = 0;
    objet->unk1320 = 0;
    objet->unk1328 = 0;
    objet->unk132C = 0;
    objet->unk1322 = 0;
    objet->unk1324 = 0;
    objet->unk1326 = 0;
    objet->unk134C = -1;
    objet->unk1350 = 0;
    objet->unk1354 = -1;
    objet->unk1356 = 0;
    objet->unk130C = 0;
    objet->unk133C = 0;
    objet->unk1358 = 0;
    objet->unk1478 = 0;
    objet->unk1474 = 0;
    objet->unk1470 = 0;
    objet->unk147C = 0x3F800000;
    objet->unk1480 = 0;
    objet->unk1484 = 0;
    objet->unk1488 = 0;
    objet->unk148C = 0;
    objet->unk1490 = 0;
    objet->unk1494 = 0;
    objet->unk1348 = 0;
}
INCLUDE_ASM("nonmatchings/game/cautomapgen", GetMonsterTable__Fi);
struct CMonsterLocateInfoView {
    s32 unk0;
    s32 unk4;
    s32 unk8;
};
extern "C" void SetPutFlag__18CMonsterLocateInfoFii(CMonsterLocateInfoView *objet, s32 arg0, s32 arg1) {
    if (arg1 != 0) {
        if (objet->unk4 < objet->unk0) {
            objet->unk8 |= 1 << arg0;
            objet->unk4 += 1;
        }
    } else if (objet->unk4 > 0) {
        objet->unk8 &= ~(1 << arg0);
        objet->unk4 -= 1;
    }
}
