/* CDC2Mes, CMenuFont
 *
 * Unité découpée par `make carve` : 14 fonctions, 10944 octets, de
 * 0x0021C790 à 0x0021F2B0. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

INCLUDE_ASM("nonmatchings/game/cdc2mes", GyoraceMenuKey__Fv);
INCLUDE_ASM("nonmatchings/game/cdc2mes", GyoraceMenuDraw__Fv);
INCLUDE_ASM("nonmatchings/game/cdc2mes", DrawSubGameTitle__FP10mgCTextureiiii);
INCLUDE_ASM("nonmatchings/game/cdc2mes", DrawSubGameListFix__FP10mgCTextureiiii);
INCLUDE_ASM("nonmatchings/game/cdc2mes", DrawSubGameScrlList__FP10mgCTexturePiPi);
INCLUDE_ASM("nonmatchings/game/cdc2mes", DrawSubGameUnderLine__FP10mgCTextureiii);
INCLUDE_ASM("nonmatchings/game/cdc2mes", GetHatena__Fv);
INCLUDE_ASM("nonmatchings/game/cdc2mes", GetMenuBigNum__Fi);
INCLUDE_ASM("nonmatchings/game/cdc2mes", SetMenuBigNum2__FPci);
INCLUDE_ASM("nonmatchings/game/cdc2mes", SetMenuBigNum__FPci);
#include "gen/CFont.hpp"
struct inferred;
typedef struct CMenuFont {
    /* 0x00 */ char pad0[0xB0];
    /* 0xB0 */ s32 unkB0;                           /* inferred */
    /* 0xB4 */ s32 unkB4;                           /* inferred */
} CMenuFont;                                        /* size >= 0xB8 */
extern "C" s32 Init__5CFontFv(void *);
extern "C" s32 SetClearance__5CFontFii(void *, s32, s32);
extern "C" s32 SetColor__5CFontFUi(void *, u32);
extern "C" s32 SetFuchi__5CFontFi(void *, s32);
extern "C" CMenuFont *__ct__9CMenuFontFv(CMenuFont *objet) {
    Init__5CFontFv((CFont *) objet);
    Init__5CFontFv((CFont *) objet);
    SetClearance__5CFontFii((CFont *) objet, 0x10, 0x14);
    SetFuchi__5CFontFi((CFont *) objet, 5);
    SetColor__5CFontFUi((CFont *) objet, 0x80686A6BU);
    objet->unkB0 = 0;
    objet->unkB4 = 0;
    return objet;
}
INCLUDE_ASM("nonmatchings/game/cdc2mes", MenuMesInit__FP6ClsMes);
INCLUDE_ASM("nonmatchings/game/cdc2mes", __ct__7CDC2MesFv);
#include "menu.hpp"
#include "gen/ClsMes.hpp"
extern "C" s32 SetBuff__6ClsMesFPs(void *, s16 *);
extern "C" s32 SetBuff_system__6ClsMesFPs(void *, s16 *);
extern "C" void SetMessData__7CDC2MesFPsPs(CDC2Mes *objet, s16 *arg0, s16 *arg1) {
    SetBuff_system__6ClsMesFPs((ClsMes *) objet, arg0);
    SetBuff__6ClsMesFPs((ClsMes *) objet, arg1);
}
