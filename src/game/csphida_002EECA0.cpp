/* CSphida, CameraCtrlParam
 *
 * Unité découpée par `make carve` : 11 fonctions, 8620 octets, de
 * 0x002EECA0 à 0x002F0E80. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

INCLUDE_ASM("nonmatchings/game/csphida_002EECA0", Omake_SetUp__7CSphidaFii);
INCLUDE_ASM("nonmatchings/game/csphida_002EECA0", Step__7CSphidaFv);
extern "C" u8 mgTexManager[540];
extern "C" u8 _1221_00377728[11];
struct inferred;
typedef struct CSphida {
    /* 0x0 */ s32 unk0;                             /* inferred */
    /* 0x4 */ s32 unk4;                             /* inferred */
    /* 0x8 */ s32 unk8;                             /* inferred */
} CSphida;                                          /* size >= 0xC */
extern "C" s32 GetTexture__17mgCTextureManagerFPci(...);
extern "C" void InitStatusSprite__7CSphidaFv(CSphida *objet) {
    s32 temp_v0;

    temp_v0 = GetTexture__17mgCTextureManagerFPci(&mgTexManager, &_1221_00377728, -1);
    objet->unk0 = 0x43800000;
    objet->unk4 = 0x43CB3333;
    objet->unk8 = temp_v0;
}
INCLUDE_ASM("nonmatchings/game/csphida_002EECA0", DrawStatusSprite__7CSphidaFv);
INCLUDE_ASM("nonmatchings/game/csphida_002EECA0", DrawParCounter__7CSphidaFv);
INCLUDE_ASM("nonmatchings/game/csphida_002EECA0", Draw__7CSphidaFv);
struct MDS_HEADER {
    u32 field_0;
    char pad_4[0x4];
    u32 field_8;
};
#include "menu.hpp"
typedef struct CSphida_infere {
    /* 0x000 */ char pad0[0x208];
    /* 0x208 */ s32 unk208;                         /* inferred */
} CSphida_infere;                                          /* size >= 0x20C */
extern "C" s32 LoadCollisionFile__FP10MDS_HEADERP9mgCMemory(MDS_HEADER *, mgCMemory *);
extern "C" s32 SetCollisionModel__7CSphidaFP10MDS_HEADERP9mgCMemory(CSphida_infere *objet, MDS_HEADER *arg0, mgCMemory *arg1) {
    objet->unk208 = LoadCollisionFile__FP10MDS_HEADERP9mgCMemory(arg0, arg1);
    return objet->unk208 != 0;
}
INCLUDE_ASM("nonmatchings/game/csphida_002EECA0", PickupCollision__7CSphidaFPfP6CCPoly9mgVu0FBOXi);
INCLUDE_ASM("nonmatchings/game/csphida_002EECA0", DrawMiniMapSymbol__7CSphidaFP14CMiniMapSymbol);
INCLUDE_ASM("nonmatchings/game/csphida_002EECA0", SetFixHeight__15CameraCtrlParamFf);
INCLUDE_ASM("nonmatchings/game/csphida_002EECA0", SetFixDist__15CameraCtrlParamFf);
