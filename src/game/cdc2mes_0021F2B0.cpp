/* CDC2Mes, CMenuMoveItem
 *
 * Unité découpée par `make carve` : 33 fonctions, 5108 octets, de
 * 0x0021F2B0 à 0x00220740. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

INCLUDE_ASM("nonmatchings/game/cdc2mes_0021F2B0", MsgPreset__7CDC2MesFi);
extern "C" u32 LanguageCode;
struct inferred;
typedef struct CDC2Mes {
    /* 0x0000 */ char pad0[0x2248];
    /* 0x2248 */ s32 unk2248;                       /* inferred */
} CDC2Mes;                                          /* size >= 0x224C */
extern "C" s32 MsgPreset__7CDC2MesFi(void *, s32);
extern "C" void MsgPreset__7CDC2MesFii(CDC2Mes *objet, s32 arg0, s32 arg1) {
    MsgPreset__7CDC2MesFi(objet, arg0);
    if (LanguageCode == 1) {
        objet->unk2248 = 1;
    }
}
struct CDC2Mes_setcursor { char pad0[0x2959]; s8 unk2959; };
extern "C" void SetMsgCursor__7CDC2MesFi(CDC2Mes_setcursor *objet, s32 arg0) {
    objet->unk2959 = (s8) arg0;
}
INCLUDE_ASM("nonmatchings/game/cdc2mes_0021F2B0", AddMsgCursor2__7CDC2MesFiii);
INCLUDE_ASM("nonmatchings/game/cdc2mes_0021F2B0", AddMsgCursor__7CDC2MesFiiii);
INCLUDE_ASM("nonmatchings/game/cdc2mes_0021F2B0", CommandMsgCursor__7CDC2MesFv);
INCLUDE_ASM("nonmatchings/game/cdc2mes_0021F2B0", YesNoCursor__7CDC2MesFv);
INCLUDE_ASM("nonmatchings/game/cdc2mes_0021F2B0", YesNoCursor2__7CDC2MesFi);
struct CDC2Mes_msgcursor { char pad0[0x2959]; s8 unk2959; };
extern "C" s8 GetMsgCursor__7CDC2MesFv(CDC2Mes_msgcursor *objet) {
    return objet->unk2959;
}
struct CDC2Mes_itemnumbers { char pad0[0x217C]; s32 unk217C[1]; };
extern "C" s32 GetMsgItemNo__7CDC2MesFi(CDC2Mes_itemnumbers *objet, s32 arg0) {
    return objet->unk217C[arg0];
}
INCLUDE_ASM("nonmatchings/game/cdc2mes_0021F2B0", SetFontColor__7CDC2MesFiiii);
extern "C" u32 mgScreenWidth;
typedef struct CDC2Mes_infere {
    /* 0x0000 */ char pad0[0xE0];
    /* 0x00E0 */ s32 unkE0;                         /* inferred */
    /* 0x00E4 */ char padE4[0xB8];                  /* maybe part of unkE0[0x2F]void */
    /* 0x019C */ s32 unk19C;                        /* inferred */
    /* 0x01A0 */ s32 unk1A0;                        /* inferred */
    /* 0x01A4 */ s32 unk1A4;                        /* inferred */
    /* 0x01A8 */ s32 unk1A8;                        /* inferred */
    /* 0x01AC */ char pad1AC[0x27B5];               /* maybe part of unk1A8[0x9EE]void */
    /* 0x2961 */ s8 unk2961;                        /* inferred */
} CDC2Mes_infere;                                          /* size >= 0x2962 */
extern "C" void SetPutPos__7CDC2MesFiiii(CDC2Mes_infere *objet, s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    objet->unk19C = arg0;
    objet->unk1A0 = arg1;
    objet->unk1A4 = arg2;
    objet->unk1A8 = arg3;
    if (objet->unk2961 != 0) {
        objet->unk19C = (s32) (mgScreenWidth - objet->unkE0) >> 1;
    }
}
INCLUDE_ASM("nonmatchings/game/cdc2mes_0021F2B0", SetPutPos__7CDC2MesFPi);
struct CDC2Mes_abspos { char pad0[0x158]; s32 unk158; };
extern "C" void SetAbsPos__7CDC2MesFi(CDC2Mes_abspos *objet, s32 arg0) {
    objet->unk158 = arg0;
}
#include "gen/ClsMes.hpp"
extern "C" s32 GetStrWidth__6ClsMesFPc(...);
extern "C" s32 GetStringDrawWidthDC__7CDC2MesFPc(CDC2Mes *objet, s8 *arg0) {
    s32 temp_v0;

    temp_v0 = (s32) (GetStrWidth__6ClsMesFPc((ClsMes *) objet, arg0));
    if (temp_v0 >= 0) {
        return temp_v0;
    }
    return 0;
}
INCLUDE_ASM("nonmatchings/game/cdc2mes_0021F2B0", SetMovePosCenteringGyou__7CDC2MesFiii);
INCLUDE_ASM("nonmatchings/game/cdc2mes_0021F2B0", SetMsgItemNo__7CDC2MesFPii);
INCLUDE_ASM("nonmatchings/game/cdc2mes_0021F2B0", SetMsgItemNo__7CDC2MesFPPci);
INCLUDE_ASM("nonmatchings/game/cdc2mes_0021F2B0", SetMsgVolumeNo__7CDC2MesFPii);
INCLUDE_ASM("nonmatchings/game/cdc2mes_0021F2B0", SetMsgVolumeNo__7CDC2MesFPiPii);
INCLUDE_ASM("nonmatchings/game/cdc2mes_0021F2B0", SetMsgVolumeNoOne__7CDC2MesFi);
INCLUDE_ASM("nonmatchings/game/cdc2mes_0021F2B0", SetMsgItemPos__7CDC2MesFPii);
INCLUDE_ASM("nonmatchings/game/cdc2mes_0021F2B0", MakeMsg__7CDC2MesFi);
typedef struct CDC2Mes_infere2 {
    /* 0x0000 */ char pad0[0x295E];
    /* 0x295E */ s16 unk295E;                       /* inferred */
    /* 0x2960 */ char pad2960[0x20];                /* maybe part of unk295E[0x11]void */
    /* 0x2980 */ s8 unk2980;                        /* inferred */
} CDC2Mes_infere2;                                          /* size >= 0x2981 */
extern "C" s32 strcpy(...);
extern "C" void MakeMsg__7CDC2MesFPc(CDC2Mes_infere2 *objet, s8 *arg0) {
    objet->unk295E = -1;
    objet->unk2980 = 0;
    if (arg0 != NULL) {
        strcpy(&objet->unk2980);
    }
}
INCLUDE_ASM("nonmatchings/game/cdc2mes_0021F2B0", MakeMsg__7CDC2MesFP13CGameDataUsed);
INCLUDE_ASM("nonmatchings/game/cdc2mes_0021F2B0", MakeMsg__7CDC2MesFP13CGameDataUsedP13CGameDataUsed);
INCLUDE_ASM("nonmatchings/game/cdc2mes_0021F2B0", StepMsg__7CDC2MesFv);
INCLUDE_ASM("nonmatchings/game/cdc2mes_0021F2B0", DrawMsg__7CDC2MesFv);
INCLUDE_ASM("nonmatchings/game/cdc2mes_0021F2B0", SetMsgAlpha__7CDC2MesFi);
INCLUDE_ASM("nonmatchings/game/cdc2mes_0021F2B0", Initialize__13CMenuMoveItemFv);
INCLUDE_ASM("nonmatchings/game/cdc2mes_0021F2B0", AttachForm__13CMenuMoveItemFv);
INCLUDE_ASM("nonmatchings/game/cdc2mes_0021F2B0", CheckMove__13CMenuMoveItemFv);
INCLUDE_ASM("nonmatchings/game/cdc2mes_0021F2B0", SetMoveItemInfo__13CMenuMoveItemFP19MENU_ITEM_MOVE_INFOPiPi);
