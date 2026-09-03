/* CMenuChrCngMenu
 *
 * Unité découpée par `make carve` : 23 fonctions, 23472 octets, de
 * 0x002B4920 à 0x002BA570. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

INCLUDE_ASM("nonmatchings/game/cmenuchrcngmenu", AttachForm__15CMenuChrCngMenuFv);
INCLUDE_ASM("nonmatchings/game/cmenuchrcngmenu", EnterDataMenu__15CMenuChrCngMenuFPUc);
INCLUDE_ASM("nonmatchings/game/cmenuchrcngmenu", LoadNPCFaceData__15CMenuChrCngMenuFP9mgCMemoryi);
extern "C" u8 _1319[11];
extern "C" u8 mgTexManager[540];
#include "menu.hpp"
struct inferred;
struct mgCEnterIMGInfo {
    char pad_0[0x4];
    s32 field_4;
};
#include "menu.hpp"
typedef struct CMenuChrCngMenu {
    /* 0x000 */ char pad0[0x18];
    /* 0x018 */ s32 unk18;                          /* inferred */
    /* 0x01C */ char pad1C[0x1E4];                  /* maybe part of unk18[0x7A]void */
    /* 0x200 */ s8 unk200;                          /* inferred */
    /* 0x201 */ s8 unk201;                          /* inferred */
    /* 0x202 */ char pad202[2];                     /* maybe part of unk201[3]void */
    /* 0x204 */ u8 *unk204;                         /* inferred */
} CMenuChrCngMenu;                                  /* size >= 0x208 */
extern "C" s32 EnterIMGFile__17mgCTextureManagerFPUciP9mgCMemoryP15mgCEnterIMGInfo(void *, u8 *, s32, mgCMemory *, mgCEnterIMGInfo *);
extern "C" s32 ExeScript__14CBaseMenuClassFPc(...);
extern "C" s32 ReadBGSync__Fv(void);
extern "C" void EnterNPCFaceData__15CMenuChrCngMenuFv(CMenuChrCngMenu *objet) {
    s8 temp_a0;

    if ((objet->unk200 == 0) && ((temp_a0 = objet->unk201, (temp_a0 == 1)) || ((temp_a0 == 0) && (ReadBGSync__Fv() == 0)))) {
        EnterIMGFile__17mgCTextureManagerFPUciP9mgCMemoryP15mgCEnterIMGInfo(&mgTexManager, objet->unk204, objet->unk18, NULL, NULL);
        objet->unk200 = 1;
        ExeScript__14CBaseMenuClassFPc((CBaseMenuClass *) objet, &_1319);
    }
}
INCLUDE_ASM("nonmatchings/game/cmenuchrcngmenu", LoadBGNPCModel__15CMenuChrCngMenuFi);
INCLUDE_ASM("nonmatchings/game/cmenuchrcngmenu", CheckBGNPCModel__15CMenuChrCngMenuFv);
INCLUDE_ASM("nonmatchings/game/cmenuchrcngmenu", EditCharaPrepare__Fv);
INCLUDE_ASM("nonmatchings/game/cmenuchrcngmenu", KeyChangeMain__15CMenuChrCngMenuFv);
INCLUDE_ASM("nonmatchings/game/cmenuchrcngmenu", CalcTex__15CMenuChrCngMenuFv);
INCLUDE_ASM("nonmatchings/game/cmenuchrcngmenu", CheckChrChange__15CMenuChrCngMenuFv);
INCLUDE_ASM("nonmatchings/game/cmenuchrcngmenu", MenuLocalLoop__15CMenuChrCngMenuFv);
INCLUDE_ASM("nonmatchings/game/cmenuchrcngmenu", InitStarInfo__15CMenuChrCngMenuFv);
INCLUDE_ASM("nonmatchings/game/cmenuchrcngmenu", UpdataLife__15CMenuChrCngMenuFv);
INCLUDE_ASM("nonmatchings/game/cmenuchrcngmenu", MenuCharaChangeStarDraw__Fv);
INCLUDE_ASM("nonmatchings/game/cmenuchrcngmenu", MenuCharaChangeInit__FP9mgCMemoryPii);
INCLUDE_ASM("nonmatchings/game/cmenuchrcngmenu", MenuCharaChangeKey__Fv);
INCLUDE_ASM("nonmatchings/game/cmenuchrcngmenu", MenuCharaChangeDraw__Fv);
extern "C" s32 GetMonsterTable__Fi(s32);
extern "C" s32 GetMonsterName__Fi(s32 arg0) {
    s32 temp_v0;

    temp_v0 = GetMonsterTable__Fi(arg0);
    if (temp_v0 != 0) {
        return temp_v0 + 4;
    }
    return 0;
}
INCLUDE_ASM("nonmatchings/game/cmenuchrcngmenu", get_gajji_id_from_monster_progress_table__FiPi);
INCLUDE_ASM("nonmatchings/game/cmenuchrcngmenu", GetMonsterProgressTableNo__Fii);
INCLUDE_ASM("nonmatchings/game/cmenuchrcngmenu", get_monster_tbl_bajjilevel__FPiiii);
INCLUDE_ASM("nonmatchings/game/cmenuchrcngmenu", get_default_monster_progresstbl__Fi);
INCLUDE_ASM("nonmatchings/game/cmenuchrcngmenu", GetMonsterModelFile__FiiPc);
