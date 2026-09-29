/* Fonctions libres — à décrire.
 *
 * Unité découpée par `make carve` : 57 fonctions, 9452 octets, de
 * 0x0026EA00 à 0x00271030. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

INCLUDE_ASM("nonmatchings/game/text_0026EA00", _SET_EVENT_DATA__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_0026EA00", _STOPWATCH__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_0026EA00", _SET_FUNC_ETC__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_0026EA00", GetChara__Fi);
INCLUDE_ASM("nonmatchings/game/text_0026EA00", _GET_CHARA_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_0026EA00", _GET_CHARA_TALK_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_0026EA00", _TURN_CHARA__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_0026EA00", _SET_CHARA_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_0026EA00", _SET_CHARA_ROT__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_0026EA00", _GET_CHARA_ROT__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_0026EA00", _SET_MOTION__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_0026EA00", _SET_STEP__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_0026EA00", _SET_TEX_ANIM__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_0026EA00", _SET_SCALE__FP12RS_STACKDATAi_0026F710);
INCLUDE_ASM("nonmatchings/game/text_0026EA00", _SET_REFERENCE__FP12RS_STACKDATAi);
extern "C" s32 GetChara__Fi(s32);
#include "runscript.hpp"
#include "gen/mgCFrame.hpp"
struct temp_v0_champs {
    char pad0[0x70];
    /* 0x70 */ s32 unk70;
};
extern "C" s32 DeleteReference__8mgCFrameFv(void *);
extern "C" s32 GetStackInt__FP12RS_STACKDATA_00262DA0(...);
extern "C" s32 _DEL_REFERENCE__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    mgCFrame *temp_a0;
    struct temp_v0_champs *temp_v0;

    temp_v0 = (struct temp_v0_champs *) (GetChara__Fi(GetStackInt__FP12RS_STACKDATA_00262DA0(arg0)));
    if (temp_v0 == NULL) {
        return 0;
    }
    temp_a0 = (mgCFrame *) (temp_v0->unk70);
    if (temp_a0 == NULL) {
        return 0;
    }
    DeleteReference__8mgCFrameFv(temp_a0);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_0026EA00", _SHADOW_CLIP_OFF__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_0026EA00", _GET_COORDINATE_ANGLE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_0026EA00", _GET_CHARA_WIDTH__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_0026EA00", _GET_CHARA_HEIGHT__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_0026EA00", _GET_CHARA_WEIGHT__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_0026EA00", _SET_CHARA_SHOW__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_0026EA00", _GET_CHARA_SHOW__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_0026EA00", _CHARA_DA_ENABLE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_0026EA00", _GET_MOT_NOW_WAIT__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_0026EA00", _CHECK_MOTION_END__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_0026EA00", _ACTCHR_SET_MOTION__FP12RS_STACKDATAi);
struct inferred;
struct RS_STACKDATA_infere_0f25dc;
typedef struct RS_STACKDATA_infere_0f25dc {
    /* 0x0 */ char pad0[8];
    /* 0x8 */ char unk8;                               /* inferred */
    /* 0x8 */ char pad8[1];
} RS_STACKDATA_infere_0f25dc;                                     /* size >= 0x9 */
struct temp_v0_champs_6d907a {
    char pad0[0x58C];
    /* 0x58C */ s32 unk58C;
};
extern "C" s32 _SET_CHARA_EX_SOUNDID__FP12RS_STACKDATAi(RS_STACKDATA_infere_0f25dc *arg0, s32 arg1) {
    struct temp_v0_champs_6d907a *temp_v0;
    char *next_slot;

    next_slot = &arg0->unk8;
    temp_v0 = (struct temp_v0_champs_6d907a *) (GetChara__Fi(GetStackInt__FP12RS_STACKDATA_00262DA0(arg0)));
    if (temp_v0 == NULL) {
        return 0;
    }
    temp_v0->unk58C = GetStackInt__FP12RS_STACKDATA_00262DA0(next_slot);
    return 1;
}
extern "C" s32 GetCharacter__Fi(s32);
#include "gen/CActionChara.hpp"
extern "C" s32 GetStackInt__FP12RS_STACKDATA_00262DA0(...);
extern "C" s32 SetSoundInfoCopy__12CActionCharaFv(void *);
extern "C" s32 _ACTCHR_SOUND_INFO_COPY__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    CActionChara *temp_v0;

    temp_v0 = (CActionChara *) (GetCharacter__Fi(GetStackInt__FP12RS_STACKDATA_00262DA0(arg0)));
    if (temp_v0 == NULL) {
        return 0;
    }
    if (temp_v0 == NULL) {
        return 0;
    }
    SetSoundInfoCopy__12CActionCharaFv(temp_v0);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_0026EA00", GetMes__Fi);
INCLUDE_ASM("nonmatchings/game/text_0026EA00", _MES_MAKE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_0026EA00", _MES_CLOSE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_0026EA00", _MES_NEXTPAGE__FP12RS_STACKDATAi);
extern "C" s32 GetMes__Fi(s32);
#include "sphida.hpp"
#include "gen/ClsMes.hpp"
struct inferred;
struct RS_STACKDATA_infere_715566;
typedef struct RS_STACKDATA_infere_715566 {
    /* 0x0 */ char pad0[8];
    /* 0x8 */ char unk8;                               /* inferred */
    /* 0x8 */ char pad8[1];
} RS_STACKDATA_infere_715566;                                     /* size >= 0x9 */
struct calcul0_champs_ac8bde {
    char pad0[0x50];
    /* 0x50 */ s32 unk50;
};
extern "C" s32 AutoSetSub__6ClsMesFP11CCharacter2P11CCharacter2Pi(void *, CCharacter2 *, CCharacter2 *, s32 *);
extern "C" s32 AutoSet__6ClsMesFPi(void *, s32 *);
extern "C" s32 _SET_MES_AUTOSET__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    s32 sp50[4];
    s32 sp60[4];
    RS_STACKDATA *stack;
    ClsMes *temp_v0;
    CCharacter2 *chara1;
    CCharacter2 *chara2;
    s32 i;

    stack = arg0 + 1;
    temp_v0 = (ClsMes *) (GetMes__Fi(GetStackInt__FP12RS_STACKDATA_00262DA0(arg0)));
    if (temp_v0 == NULL) {
        return 0;
    }
    if (arg1 != 3) {
        if (arg1 != 5) {
            return 0;
        }
        for (i = 0; i < 4; i++) {
            sp50[i] = GetStackInt__FP12RS_STACKDATA_00262DA0(stack++);
        }
        AutoSet__6ClsMesFPi(temp_v0, sp50);
    } else {
        chara1 = (CCharacter2 *) (GetChara__Fi(GetStackInt__FP12RS_STACKDATA_00262DA0(stack++)));
        if (chara1 == NULL) {
            return 0;
        }
        chara2 = (CCharacter2 *) (GetChara__Fi(GetStackInt__FP12RS_STACKDATA_00262DA0(stack)));
        if (chara2 == NULL) {
            return 0;
        }
        AutoSetSub__6ClsMesFP11CCharacter2P11CCharacter2Pi(temp_v0, chara1, chara2, sp60);
        AutoSet__6ClsMesFPi(temp_v0, sp60);
    }
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_0026EA00", _SET_MES_SHIPPO__FP12RS_STACKDATAi);
extern "C" s32 GetMes__Fi(s32);
struct inferred;
struct RS_STACKDATA_infere_e00ae6;
typedef struct RS_STACKDATA_infere_e00ae6 {
    /* 0x0 */ char pad0[8];
    /* 0x8 */ char unk8;                               /* inferred */
    /* 0x8 */ char pad8[1];
} RS_STACKDATA_infere_e00ae6;                                     /* size >= 0x9 */
struct temp_v0_champs_6317a7 {
    char pad0[0x158];
    /* 0x158 */ s32 unk158;
};
extern "C" s32 _SET_MES_POS__FP12RS_STACKDATAi(RS_STACKDATA_infere_e00ae6 *arg0, s32 arg1) {
    struct temp_v0_champs_6317a7 *temp_v0;
    char *next_slot;

    next_slot = &arg0->unk8;
    temp_v0 = (struct temp_v0_champs_6317a7 *) (GetMes__Fi(GetStackInt__FP12RS_STACKDATA_00262DA0(arg0)));
    if (temp_v0 == NULL) {
        return 0;
    }
    temp_v0->unk158 = GetStackInt__FP12RS_STACKDATA_00262DA0(next_slot);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_0026EA00", _SET_MES_DRAWSPEED__FP12RS_STACKDATAi);
extern "C" s32 GetMes__Fi(s32);
struct inferred;
struct RS_STACKDATA_infere_29d0e6;
typedef struct RS_STACKDATA_infere_29d0e6 {
    /* 0x0 */ char pad0[8];
    /* 0x8 */ char unk8;                               /* inferred */
    /* 0x8 */ char pad8[1];
} RS_STACKDATA_infere_29d0e6;                                     /* size >= 0x9 */
struct temp_v0_champs_009240 {
    char pad0[0x225C];
    /* 0x225C */ s32 unk225C;
    char pad2260[0x18];
    /* 0x2278 */ s32 unk2278;
};
extern "C" s32 _SET_MES_CURSOR__FP12RS_STACKDATAi(RS_STACKDATA_infere_29d0e6 *arg0, s32 arg1) {
    s32 temp_v0_2;
    struct temp_v0_champs_009240 *temp_v0;
    char *next_slot;

    next_slot = &arg0->unk8;
    temp_v0 = (struct temp_v0_champs_009240 *) (GetMes__Fi(GetStackInt__FP12RS_STACKDATA_00262DA0(arg0)));
    if (temp_v0 == NULL) {
        return 0;
    }
    temp_v0_2 = (s32) (GetStackInt__FP12RS_STACKDATA_00262DA0(next_slot));
    if (temp_v0->unk225C < 0) {
        temp_v0->unk2278 = 0;
    }
    temp_v0->unk225C = temp_v0_2;
    return 1;
}
extern "C" s32 GetMes__Fi(s32);
struct inferred;
struct RS_STACKDATA_infere_6e494a;
typedef struct RS_STACKDATA_infere_6e494a {
    /* 0x0 */ char pad0[8];
    /* 0x8 */ char unk8;                               /* inferred */
    /* 0x8 */ char pad8[1];
} RS_STACKDATA_infere_6e494a;                                     /* size >= 0x9 */
struct temp_v0_champs_e8842c {
    char pad0[0x1E4C];
    /* 0x1E4C */ s32 unk1E4C;
};
extern "C" s32 _SET_MES_OKURI__FP12RS_STACKDATAi(RS_STACKDATA_infere_6e494a *arg0, s32 arg1) {
    struct temp_v0_champs_e8842c *temp_v0;
    char *next_slot;

    next_slot = &arg0->unk8;
    temp_v0 = (struct temp_v0_champs_e8842c *) (GetMes__Fi(GetStackInt__FP12RS_STACKDATA_00262DA0(arg0)));
    if (temp_v0 == NULL) {
        return 0;
    }
    temp_v0->unk1E4C = GetStackInt__FP12RS_STACKDATA_00262DA0(next_slot);
    return 1;
}
extern "C" s32 GetMes__Fi(s32);
struct inferred;
struct RS_STACKDATA_infere_da9d98;
typedef struct RS_STACKDATA_infere_da9d98 {
    /* 0x0 */ char pad0[8];
    /* 0x8 */ char unk8;                               /* inferred */
    /* 0x8 */ char pad8[1];
} RS_STACKDATA_infere_da9d98;                                     /* size >= 0x9 */
struct temp_v0_champs_476d31 {
    char pad0[0x138];
    /* 0x138 */ s32 unk138;
};
extern "C" s32 _SET_MES_WIN_FLAG__FP12RS_STACKDATAi(RS_STACKDATA_infere_da9d98 *arg0, s32 arg1) {
    struct temp_v0_champs_476d31 *temp_v0;
    char *next_slot;

    next_slot = &arg0->unk8;
    temp_v0 = (struct temp_v0_champs_476d31 *) (GetMes__Fi(GetStackInt__FP12RS_STACKDATA_00262DA0(arg0)));
    if (temp_v0 == NULL) {
        return 0;
    }
    if (GetStackInt__FP12RS_STACKDATA_00262DA0(next_slot) != 0) {
        temp_v0->unk138 = 1;
    } else {
        temp_v0->unk138 = 0;
    }
    return 1;
}
extern "C" s32 GetMes__Fi(s32);
#include "gen/ClsMes.hpp"
struct inferred;
struct RS_STACKDATA_infere_c9bb90;
typedef struct RS_STACKDATA_infere_c9bb90 {
    /* 0x0 */ char pad0[8];
    /* 0x8 */ char unk8;                               /* inferred */
    /* 0x8 */ char pad8[1];
} RS_STACKDATA_infere_c9bb90;                                     /* size >= 0x9 */
extern "C" s32 GetStackInt__FP12RS_STACKDATA_00262DA0(...);
extern "C" s32 SetStack__FP12RS_STACKDATAi_00262E70(...);
extern "C" s32 State__6ClsMesFv(void *);
extern "C" s32 _CHECK_MES_COMPLETE__FP12RS_STACKDATAi(RS_STACKDATA_infere_c9bb90 *arg0, s32 arg1) {
    char *next_slot;
    ClsMes *temp_v0;

    /* L'adresse du second emplacement de pile se calcule avant la garde :
     * MWCC la range alors dans le creneau de delai du branchement, ce que
     * le commerce fait. Posee apres, elle rend 94 % — la forme de
     * l'expression n'y change rien, sa place seule decide. */
    next_slot = &arg0->unk8;
    temp_v0 = (ClsMes *) (GetMes__Fi(GetStackInt__FP12RS_STACKDATA_00262DA0(arg0)));
    if (temp_v0 == NULL) {
        return 0;
    }
    SetStack__FP12RS_STACKDATAi_00262E70(next_slot, State__6ClsMesFv(temp_v0) == 3);
    return 1;
}
extern "C" s32 GetMes__Fi(s32);
#include "gen/ClsMes.hpp"
struct inferred;
struct RS_STACKDATA_infere_4de93d;
typedef struct RS_STACKDATA_infere_4de93d {
    /* 0x0 */ char pad0[8];
    /* 0x8 */ char unk8;                               /* inferred */
    /* 0x8 */ char pad8[1];
} RS_STACKDATA_infere_4de93d;                                     /* size >= 0x9 */
extern "C" s32 GetStackInt__FP12RS_STACKDATA_00262DA0(...);
extern "C" s32 SetStack__FP12RS_STACKDATAi_00262E70(...);
extern "C" s32 State__6ClsMesFv(void *);
extern "C" s32 _CHECK_MES_WAIT__FP12RS_STACKDATAi(RS_STACKDATA_infere_4de93d *arg0, s32 arg1) {
    char *next_slot;
    ClsMes *temp_v0;

    /* L'adresse du second emplacement de pile se calcule avant la garde :
     * MWCC la range alors dans le creneau de delai du branchement, ce que
     * le commerce fait. Posee apres, elle rend 94 % — la forme de
     * l'expression n'y change rien, sa place seule decide. */
    next_slot = &arg0->unk8;
    temp_v0 = (ClsMes *) (GetMes__Fi(GetStackInt__FP12RS_STACKDATA_00262DA0(arg0)));
    if (temp_v0 == NULL) {
        return 0;
    }
    SetStack__FP12RS_STACKDATAi_00262E70(next_slot, State__6ClsMesFv(temp_v0) == 5);
    return 1;
}
extern "C" s32 GetMes__Fi(s32);
#include "gen/ClsMes.hpp"
struct inferred;
struct RS_STACKDATA_infere_a2730f;
typedef struct RS_STACKDATA_infere_a2730f {
    /* 0x0 */ char pad0[8];
    /* 0x8 */ char unk8;                               /* inferred */
    /* 0x8 */ char pad8[1];
} RS_STACKDATA_infere_a2730f;                                     /* size >= 0x9 */
extern "C" s32 GetStackInt__FP12RS_STACKDATA_00262DA0(...);
extern "C" s32 SetStack__FP12RS_STACKDATAi_00262E70(...);
extern "C" s32 State__6ClsMesFv(void *);
extern "C" s32 _CHECK_MES__FP12RS_STACKDATAi(RS_STACKDATA_infere_a2730f *arg0, s32 arg1) {
    char *next_slot;
    ClsMes *temp_v0;

    /* L'adresse du second emplacement de pile se calcule avant la garde :
     * MWCC la range alors dans le creneau de delai du branchement, ce que
     * le commerce fait. Posee apres, elle rend 94 % — la forme de
     * l'expression n'y change rien, sa place seule decide. */
    next_slot = &arg0->unk8;
    temp_v0 = (ClsMes *) (GetMes__Fi(GetStackInt__FP12RS_STACKDATA_00262DA0(arg0)));
    if (temp_v0 == NULL) {
        return 0;
    }
    SetStack__FP12RS_STACKDATAi_00262E70(next_slot, State__6ClsMesFv(temp_v0) == 0);
    return 1;
}
extern "C" s32 GetMes__Fi(s32);
#include "gen/ClsMes.hpp"
struct inferred;
struct RS_STACKDATA_infere_2a2142;
typedef struct RS_STACKDATA_infere_2a2142 {
    /* 0x0 */ char pad0[8];
    /* 0x8 */ char unk8;                               /* inferred */
    /* 0x8 */ char pad8[1];
} RS_STACKDATA_infere_2a2142;                                     /* size >= 0x9 */
extern "C" s32 GetStackInt__FP12RS_STACKDATA_00262DA0(...);
extern "C" s32 SetWindowMode__6ClsMesFi(void *, s32);
extern "C" s32 _SET_MES_FUKIDASHI__FP12RS_STACKDATAi(RS_STACKDATA_infere_2a2142 *arg0, s32 arg1) {
    ClsMes *temp_v0;
    char *next_slot;

    next_slot = &arg0->unk8;
    temp_v0 = (ClsMes *) (GetMes__Fi(GetStackInt__FP12RS_STACKDATA_00262DA0(arg0)));
    if (temp_v0 == NULL) {
        return 0;
    }
    GetStackInt__FP12RS_STACKDATA_00262DA0(next_slot);
    SetWindowMode__6ClsMesFi(temp_v0, 1);
    return 1;
}
extern "C" s32 GetMes__Fi(s32);
#include "gen/ClsMes.hpp"
struct inferred;
struct RS_STACKDATA_infere_86bb74;
typedef struct RS_STACKDATA_infere_86bb74 {
    /* 0x0 */ char pad0[8];
    /* 0x8 */ char unk8;                               /* inferred */
    /* 0x8 */ char pad8[1];
} RS_STACKDATA_infere_86bb74;                                     /* size >= 0x9 */
extern "C" s32 GetStackInt__FP12RS_STACKDATA_00262DA0(...);
extern "C" s32 SetWindowMode__6ClsMesFi(void *, s32);
extern "C" s32 _SET_MES_WINDOW_MODE__FP12RS_STACKDATAi(RS_STACKDATA_infere_86bb74 *arg0, s32 arg1) {
    ClsMes *temp_v0;
    char *next_slot;

    next_slot = &arg0->unk8;
    temp_v0 = (ClsMes *) (GetMes__Fi(GetStackInt__FP12RS_STACKDATA_00262DA0(arg0)));
    if (temp_v0 == NULL) {
        return 0;
    }
    SetWindowMode__6ClsMesFi(temp_v0, GetStackInt__FP12RS_STACKDATA_00262DA0(next_slot));
    return 1;
}
extern "C" s32 GetMes__Fi(s32);
#include "gen/ClsMes.hpp"
struct inferred;
struct RS_STACKDATA_infere_8e6001;
typedef struct RS_STACKDATA_infere_8e6001 {
    /* 0x0 */ char pad0[8];
    /* 0x8 */ char unk8;                               /* inferred */
    /* 0x8 */ char pad8[1];
} RS_STACKDATA_infere_8e6001;                                     /* size >= 0x9 */
extern "C" s32 GetStackInt__FP12RS_STACKDATA_00262DA0(...);
extern "C" s32 Preset__6ClsMesFi(void *, s32);
extern "C" s32 _SET_MES_PRESET__FP12RS_STACKDATAi(RS_STACKDATA_infere_8e6001 *arg0, s32 arg1) {
    ClsMes *temp_v0;
    char *next_slot;

    next_slot = &arg0->unk8;
    temp_v0 = (ClsMes *) (GetMes__Fi(GetStackInt__FP12RS_STACKDATA_00262DA0(arg0)));
    if (temp_v0 == NULL) {
        return 0;
    }
    Preset__6ClsMesFi(temp_v0, GetStackInt__FP12RS_STACKDATA_00262DA0(next_slot));
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_0026EA00", _SET_MES_ITEM_DIRECT__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_0026EA00", _SET_MES_ITEM__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_0026EA00", _SET_MES_VALUE__FP12RS_STACKDATAi);
extern "C" s32 GetMes__Fi(s32);
#include "gen/ClsMes.hpp"
struct inferred;
struct RS_STACKDATA_infere_5475c0;
typedef struct RS_STACKDATA_infere_5475c0 {
    /* 0x0 */ char pad0[8];
    /* 0x8 */ char unk8;                               /* inferred */
    /* 0x8 */ char pad8[1];
} RS_STACKDATA_infere_5475c0;                                     /* size >= 0x9 */
extern "C" s32 GetStackInt__FP12RS_STACKDATA_00262DA0(...);
extern "C" s32 SetStack__FP12RS_STACKDATAi_00262E70(...);
extern "C" s32 State__6ClsMesFv(void *);
extern "C" s32 _GET_MES_STATUS__FP12RS_STACKDATAi(RS_STACKDATA_infere_5475c0 *arg0, s32 arg1) {
    char *next_slot;
    ClsMes *temp_v0;

    /* L'adresse du second emplacement de pile se calcule avant la garde :
     * MWCC la range alors dans le creneau de delai du branchement, ce que
     * le commerce fait. Posee apres, elle rend 94 % — la forme de
     * l'expression n'y change rien, sa place seule decide. */
    next_slot = &arg0->unk8;
    temp_v0 = (ClsMes *) (GetMes__Fi(GetStackInt__FP12RS_STACKDATA_00262DA0(arg0)));
    if (temp_v0 == NULL) {
        return 0;
    }
    SetStack__FP12RS_STACKDATAi_00262E70(next_slot, State__6ClsMesFv(temp_v0));
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_0026EA00", _GET_PARTY_CHARA_MES_NO__FP12RS_STACKDATAi);
extern "C" s32 GetMes__Fi(s32);
extern "C" s32 GetSysMesBuffer__Fv(void);
extern "C" s32 GetSystemMesBuffer__Fv(void);
#include "gen/ClsMes.hpp"
struct inferred;
struct RS_STACKDATA_infere_13d5e7;
typedef struct RS_STACKDATA_infere_13d5e7 {
    /* 0x0 */ char pad0[8];
    /* 0x8 */ char unk8;                               /* inferred */
    /* 0x8 */ char pad8[1];
} RS_STACKDATA_infere_13d5e7;                                     /* size >= 0x9 */
extern "C" s32 GetStackInt__FP12RS_STACKDATA_00262DA0(...);
extern "C" s32 SetBuff__6ClsMesFPs(...);
extern "C" s32 SetBuff_system__6ClsMesFPs(...);
extern "C" s32 _MES_SET_BUFF__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    ClsMes *temp_v0;
    s32 temp_s1;
    RS_STACKDATA *temp_s2;

    temp_s2 = arg0 + 1;
    temp_v0 = (ClsMes *) (GetMes__Fi(GetStackInt__FP12RS_STACKDATA_00262DA0(arg0)));
    if (temp_v0 == NULL) {
        return 0;
    }
    temp_s1 = (s32) (GetStackInt__FP12RS_STACKDATA_00262DA0(temp_s2++));
    GetStackInt__FP12RS_STACKDATA_00262DA0(temp_s2);
    if (temp_s1 == 0) {
        SetBuff__6ClsMesFPs(temp_v0, GetSysMesBuffer__Fv());
    } else {
        SetBuff_system__6ClsMesFPs(temp_v0, GetSystemMesBuffer__Fv());
    }
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_0026EA00", _GET_MES_WINDOW_MODE__FP12RS_STACKDATAi);
struct EdEventInfoVoice {
    char pad0[0x134];
    s32 field_0x134;
    char pad138[0x1170];
};
extern "C" EdEventInfoVoice EdEventInfo;
extern "C" s32 SetStack__FP12RS_STACKDATAi_00262E70(...);
extern "C" s32 _GET_MES_VOICE__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    SetStack__FP12RS_STACKDATAi_00262E70(arg0, EdEventInfo.field_0x134);
    return 1;
}
extern "C" s32 GetMes__Fi(s32);
struct inferred;
struct RS_STACKDATA_infere_8054ca;
typedef struct RS_STACKDATA_infere_8054ca {
    /* 0x0 */ char pad0[8];
    /* 0x8 */ char unk8;                               /* inferred */
    /* 0x8 */ char pad8[1];
} RS_STACKDATA_infere_8054ca;                                     /* size >= 0x9 */
struct temp_v0_champs_c8eef4 {
    char pad0[0x228C];
    /* 0x228C */ s32 unk228C;
};
extern "C" s32 _SET_MES_QUESTION_GYOU__FP12RS_STACKDATAi(RS_STACKDATA_infere_8054ca *arg0, s32 arg1) {
    struct temp_v0_champs_c8eef4 *temp_v0;
    char *next_slot;

    next_slot = &arg0->unk8;
    temp_v0 = (struct temp_v0_champs_c8eef4 *) (GetMes__Fi(GetStackInt__FP12RS_STACKDATA_00262DA0(arg0)));
    if (temp_v0 == NULL) {
        return 0;
    }
    temp_v0->unk228C = GetStackInt__FP12RS_STACKDATA_00262DA0(next_slot);
    return 1;
}
extern "C" s32 GetMes__Fi(s32);
struct RS_STACKDATA_infere;
typedef struct RS_STACKDATA_infere {
    /* 0x0 */ char pad0[8];
    /* 0x8 */ char unk8;                               /* inferred */
    /* 0x8 */ char pad8[1];
} RS_STACKDATA_infere;                                     /* size >= 0x9 */
struct temp_v0_champs_9cde97 {
    char pad0[0x228C];
    /* 0x228C */ s32 unk228C;
};
extern "C" s32 SetStack__FP12RS_STACKDATAi_00262E70(...);
extern "C" s32 _GET_MES_QUESTION_GYOU__FP12RS_STACKDATAi(RS_STACKDATA_infere *arg0, s32 arg1) {
    char *next_slot;

    /* L'adresse du second emplacement de pile se calcule avant la garde : MWCC
     * la range alors dans le creneau de delai du branchement, ce que le
     * commerce fait. Posee apres la garde, elle rend 94 % — la forme de
     * l'expression n'y change rien, sa place seule decide. */
    next_slot = &arg0->unk8;

    struct temp_v0_champs_9cde97 *temp_v0;

    temp_v0 = (struct temp_v0_champs_9cde97 *) (GetMes__Fi(GetStackInt__FP12RS_STACKDATA_00262DA0(arg0)));
    if (temp_v0 == NULL) {
        return 0;
    }
    SetStack__FP12RS_STACKDATAi_00262E70(next_slot, temp_v0->unk228C);
    return 1;
}
extern "C" s32 GetMes__Fi(s32);
struct inferred;
struct RS_STACKDATA_infere_033894;
typedef struct RS_STACKDATA_infere_033894 {
    /* 0x0 */ char pad0[8];
    /* 0x8 */ char unk8;                               /* inferred */
    /* 0x8 */ char pad8[1];
} RS_STACKDATA_infere_033894;                                     /* size >= 0x9 */
struct temp_v0_champs_ba36cb {
    char pad0[0x22A0];
    /* 0x22A0 */ s32 unk22A0;
};
extern "C" s32 _SET_MES_CLOSE_CNT__FP12RS_STACKDATAi(RS_STACKDATA_infere_033894 *arg0, s32 arg1) {
    struct temp_v0_champs_ba36cb *temp_v0;
    char *next_slot;

    next_slot = &arg0->unk8;
    temp_v0 = (struct temp_v0_champs_ba36cb *) (GetMes__Fi(GetStackInt__FP12RS_STACKDATA_00262DA0(arg0)));
    if (temp_v0 == NULL) {
        return 0;
    }
    temp_v0->unk22A0 = GetStackInt__FP12RS_STACKDATA_00262DA0(next_slot);
    return 1;
}
