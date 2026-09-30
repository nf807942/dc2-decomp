/* Fonctions libres — à décrire.
 *
 * Unité découpée par `make carve` : 137 fonctions, 24556 octets, de
 * 0x00266E10 à 0x0026D190. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"
#include "gen/EdEventInfoData.hpp"
#include "gen/MenuArgData.hpp"

#include "runscript.hpp"
extern EdEventInfoData EdEventInfo;
extern MenuArgData MenuArg;
struct RS_STACKDATA;


extern "C" s32 GetStackString__FP12RS_STACKDATA_00262E60(...);
extern "C" char _2393_00371D10[];
extern "C" char _1083_00371A88[];
extern "C" s32 SetCurrentDir__FPc(...);
extern "C" s32 strcmp(...);
extern "C" s32 _SET_CURRENT_DIR__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    s8 *var_s0;

    var_s0 = (s8 *) (NULL);
    if (arg1 > 0) {
        var_s0 = (s8 *) (GetStackString__FP12RS_STACKDATA_00262E60(arg0));
    }
    if (var_s0 == NULL || strcmp(var_s0, _2393_00371D10) == 0 || strcmp(var_s0, _1083_00371A88) == 0) {
        SetCurrentDir__FPc(NULL);
    } else {
        SetCurrentDir__FPc(var_s0);
    }
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_00266E10", _CHANGE_DIR__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _DELETE_CHARA__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _LOAD_MOTION_sub__FiPciPUi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _LOAD_MOTION__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _MAP_JUMP__FP12RS_STACKDATAi);
extern "C" u8 EventRain[44016];
extern "C" s32 GetStackInt__FP12RS_STACKDATA_00262DA0(...);
extern "C" s32 Start__5CRainFv(void *);
extern "C" s32 Stop__5CRainFv(void *);
extern "C" s32 _SET_RAIN__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    if (GetStackInt__FP12RS_STACKDATA_00262DA0(arg0) != 0) {
        Start__5CRainFv(&EventRain);
    } else {
        Stop__5CRainFv(&EventRain);
    }
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_00266E10", _DEL_EXT_MOTION__FP12RS_STACKDATAi);
s32 _SET_MARKER(RS_STACKDATA *stack, int argc) {
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_00266E10", _SET_WORLD_COORD__FP12RS_STACKDATAi);
extern "C" void EdEventFinish__Fv(void);
extern "C" void _FINISH__FP12RS_STACKDATAi(void *, int) { EdEventFinish__Fv(); }

extern "C" s32 SetStack__FP12RS_STACKDATAf_00262E90(RS_STACKDATA *, f32);
extern "C" s32 GetStackInt__FP12RS_STACKDATA_00262DA0(...);
extern "C" s32 GetDungeonEventPoint__FPfPfi(f32 *, f32 *, s32);
extern "C" s32 _GET_DUN_WORLD_COORD__FP12RS_STACKDATAi(RS_STACKDATA *p, s32 arg1) {
    f32 a[4];
    f32 b[6];
    f32 c;
    f32 d;

    if (arg1 == 4) {
        if (GetDungeonEventPoint__FPfPfi(a, &c, 0) == 0) {
            return 0;
        }
        SetStack__FP12RS_STACKDATAf_00262E90(p++, a[0]);
        SetStack__FP12RS_STACKDATAf_00262E90(p++, a[1]);
        SetStack__FP12RS_STACKDATAf_00262E90(p++, a[2]);
        SetStack__FP12RS_STACKDATAf_00262E90(p, c);
        return 1;
    }
    if (arg1 == 5) {
        if (GetDungeonEventPoint__FPfPfi(b, &d, GetStackInt__FP12RS_STACKDATA_00262DA0(p + 4)) == 0) {
            return 0;
        }
        SetStack__FP12RS_STACKDATAf_00262E90(p++, b[0]);
        SetStack__FP12RS_STACKDATAf_00262E90(p++, b[1]);
        SetStack__FP12RS_STACKDATAf_00262E90(p++, b[2]);
        SetStack__FP12RS_STACKDATAf_00262E90(p, d);
        return 1;
    }
    return 0;
}

INCLUDE_ASM("nonmatchings/game/text_00266E10", _LOAD_IMG__FP12RS_STACKDATAi);
extern "C" u8 mgTexManager[540];
struct EventScene_pointe;
extern "C" EventScene_pointe *EventScene;
struct EventScene_champs_ba8473 {
    char pad0[0x2E7C];
    /* 0x2E7C */ s32 unk2E7C;
};
extern "C" s32 DeleteBlock__17mgCTextureManagerFi(void *, s32);
extern "C" s32 _DEL_IMG__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    DeleteBlock__17mgCTextureManagerFi(&mgTexManager, ((struct EventScene_champs_ba8473 *) EventScene)->unk2E7C + GetStackInt__FP12RS_STACKDATA_00262DA0(arg0));
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_00266E10", _SET_DNG_MAP__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _LOAD_ITEM__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _GOTO_USE_ITEM__FP12RS_STACKDATAi);
extern "C" s32 GetStackInt__FP12RS_STACKDATA_00262DA0(...);
extern "C" s32 SetLocalFlag__Fii(s32, s32);
extern "C" s32 _SET_LOCAL_FLAG__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    s32 temp_s0;

    temp_s0 = (s32) (GetStackInt__FP12RS_STACKDATA_00262DA0(arg0++));
    SetLocalFlag__Fii(temp_s0, GetStackInt__FP12RS_STACKDATA_00262DA0(arg0));
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_00266E10", _GET_LOCAL_FLAG__FP12RS_STACKDATAi);
s32 _GOTO_SELECT_PARTY(RS_STACKDATA * arg0, s32 arg1) {
    MenuArg.field_0x28 = 4;
    EdEventInfo.field_0xD0 = 3;
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_00266E10", _SET_LOADBG_FILE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _SET_LOADBG_FILE_MONS_TALK__FP12RS_STACKDATAi);
extern "C" s32 ReadBGSync__Fv(void);
extern "C" s32 SetStack__FP12RS_STACKDATAi_00262E70(RS_STACKDATA *, s32);
extern "C" s32 _CHECK_LOADBG_FILE__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    arg1 = ReadBGSync__Fv();
    SetStack__FP12RS_STACKDATAi_00262E70(arg0, arg1);
    return 1;
}

s32 _GET_TB_ITEMNO(RS_STACKDATA *stack, int argc) {
    return 0;
}
INCLUDE_ASM("nonmatchings/game/text_00266E10", _SET_TB_STATUS__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _SET_TB_ANGLE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _ADD_ITEM__FP12RS_STACKDATAi);
#include "dngfloormanager.hpp"
extern "C" s32 DeleteItem__16CUserDataManagerFii(void *, s32, s32);
extern "C" s32 GetSaveData__Fv(void);
extern "C" s32 _SUB_ITEM__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    CUserDataManager *temp_a0;
    s32 temp_s0;
    s32 temp_v0;
    s32 var_s1;

    var_s1 = 1;
    temp_s0 = (s32) (GetStackInt__FP12RS_STACKDATA_00262DA0(arg0++));
    if (arg1 >= 2) {
        var_s1 = (s32) (GetStackInt__FP12RS_STACKDATA_00262DA0(arg0));
    }
    temp_v0 = GetSaveData__Fv();
    if (temp_v0 == 0) {
        return 0;
    }
    temp_a0 = (CUserDataManager *) ((u8 *) temp_v0 + 0x1D2A0);
    if (temp_a0 == NULL) {
        return 0;
    }
    DeleteItem__16CUserDataManagerFii(temp_a0, temp_s0, var_s1);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_00266E10", _GET_ITEM_TYPE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _GET_ITEM_SPACE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", GetConfigCaptionOff__Fv);
INCLUDE_ASM("nonmatchings/game/text_00266E10", LoadMovie__FPcP9mgCMemoryb);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _LOAD_MOVIE__FP12RS_STACKDATAi);
extern "C" void InitLocalCnt__Fv(void);
extern "C" s32 _INIT_LOCAL_CNT__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    InitLocalCnt__Fv();
    return 1;
}

INCLUDE_ASM("nonmatchings/game/text_00266E10", _SET_CROSSFADE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _GET_ADJUST_POLYGON_SCALE__FP12RS_STACKDATAi);
extern "C" f32 GetStackFloat__FP12RS_STACKDATA_00262DE0(RS_STACKDATA *);
extern "C" s32 SetTime__6CSceneFf(void *, f32);
extern "C" s32 _SET_TIME__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    SetTime__6CSceneFf(EventScene, GetStackFloat__FP12RS_STACKDATA_00262DE0(arg0));
    return 1;
}
struct CMap_champs_98 {
    char pad0[0x98];
    s32 unk98;
    s32 unk9C;
};
extern "C" s32 GetActiveMap__6CSceneFPP4CMapi(void *, CMap_champs_98 **, s32);
extern "C" s32 _SET_ACTIVE_LIGHT__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    /* 0x20 octets de pile : le commerce place le pointeur en 0x20(sp) et le cadre
     * en 0x40, là où un simple pointeur donne 0x2C et 0x30. */
    CMap_champs_98 *sp20[8];
    s32 temp_s0;

    temp_s0 = (s32) (GetStackInt__FP12RS_STACKDATA_00262DA0(arg0));
    if (GetActiveMap__6CSceneFPP4CMapi(EventScene, sp20, 8) <= 0) {
        return 0;
    }
    if (temp_s0 >= 0) {
        if (temp_s0 < sp20[0]->unk9C) {
            sp20[0]->unk98 = temp_s0;
        }
    }
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_00266E10", _SET_PAKU_ANIM__FP12RS_STACKDATAi);
extern "C" u32 PakuAnimEohNo;
extern "C" u8 PakuAnimName[64];
extern "C" u8 PakuAnimName2[64];
extern "C" s32 memset(...);
extern "C" s32 _RESET_PAKU_ANIM__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    PakuAnimEohNo = -1;
    memset(&PakuAnimName, 0, 0x40);
    memset(&PakuAnimName2, 0, 0x40);
    return 1;
}
extern "C" u8 EventObjHandleMother[512];
extern "C" char _1083_00371A88[];
extern "C" s32 SetTexAnim__10CEohMotherFiiPc(...);
extern "C" s32 strcmp(...);
extern "C" s32 _TRG_PAKU_ANIM__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    if (GetStackInt__FP12RS_STACKDATA_00262DA0(arg0) != 0) {
        if (strcmp(&PakuAnimName2, _1083_00371A88) != 0) {
            SetTexAnim__10CEohMotherFiiPc(&EventObjHandleMother, PakuAnimEohNo, 0, &PakuAnimName2);
        }
        SetTexAnim__10CEohMotherFiiPc(&EventObjHandleMother, PakuAnimEohNo, 1, &PakuAnimName);
    } else {
        SetTexAnim__10CEohMotherFiiPc(&EventObjHandleMother, PakuAnimEohNo, 0, &PakuAnimName);
        if (strcmp(&PakuAnimName2, _1083_00371A88) != 0) {
            SetTexAnim__10CEohMotherFiiPc(&EventObjHandleMother, PakuAnimEohNo, 1, &PakuAnimName2);
        }
    }
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_00266E10", _RESET_CAMERA__FP12RS_STACKDATAi);
struct var_s0_champs_aef074 {
    char pad0[0x44D96];
    /* 0x44D96 */ s16 unk44D96;
};
extern "C" s32 GetSaveData__Fv(void);
extern "C" s32 SetStack__FP12RS_STACKDATAi_00262E70(RS_STACKDATA *, s32);
extern "C" s32 _GET_ACTIVE_CHR_NO__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    s32 temp_v0;
    struct var_s0_champs_aef074 *var_s0;

    var_s0 = (struct var_s0_champs_aef074 *) (NULL);
    temp_v0 = GetSaveData__Fv();
    if (temp_v0 != 0) {
        /* La conversion en `u8 *` porte l'arithmetique en octets. Sans elle,
         * MWCC met le pas a l'echelle du type pointe et la constante emise
         * est multipliee d'autant. */
        var_s0 = (struct var_s0_champs_aef074 *) ((u8 *) temp_v0 + 0x1D2A0);
    }
    if (var_s0 == NULL) {
        return 0;
    }
    SetStack__FP12RS_STACKDATAi_00262E70(arg0, var_s0->unk44D96);
    return 1;
}

#include "dngfloormanager.hpp"
extern "C" s32 GetSaveData__Fv(void);
extern "C" s32 SetActiveChrNo__16CUserDataManagerFi(void *, s32);
extern "C" s32 _SET_ACTIVE_CHR_NO__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    CUserDataManager *var_s0;
    s32 temp_v0;

    var_s0 = (CUserDataManager *) (NULL);
    temp_v0 = GetSaveData__Fv();
    if (temp_v0 != 0) {
        var_s0 = (CUserDataManager *) ((u8 *) temp_v0 + 0x1D2A0);
    }
    if (var_s0 == NULL) {
        return 0;
    }
    SetActiveChrNo__16CUserDataManagerFi(var_s0, GetStackInt__FP12RS_STACKDATA_00262DA0(arg0));
    return 1;
}

#include "dngfloormanager.hpp"
extern "C" s32 GetSaveData__Fv(void);
extern "C" s32 SetFloorID__16CSaveDataDungeonFi(void *, s32);
extern "C" s32 _DNG_SET_FLOOR_ID__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    CSaveDataDungeon *temp_a0;
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = (s32) (GetStackInt__FP12RS_STACKDATA_00262DA0(arg0));
    temp_v0 = GetSaveData__Fv();
    if (temp_v0 == 0) {
        return 0;
    }
    temp_a0 = (CSaveDataDungeon *) ((u8 *) temp_v0 + 0x1C5B4);
    if (temp_a0 == NULL) {
        return 0;
    }
    SetFloorID__16CSaveDataDungeonFi(temp_a0, temp_s0);
    return 1;
}

INCLUDE_ASM("nonmatchings/game/text_00266E10", _DNG_GET_FLOOR_ID__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _SET_PAKU_MOTION__FP12RS_STACKDATAi);
extern "C" u32 PakuMotionEohNo;
extern "C" u8 PakuMotionName[64];
extern "C" u8 PakuMotionName2[64];
extern "C" s32 _RESET_PAKU_MOTION__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    PakuMotionEohNo = -1;
    memset(&PakuMotionName, 0, 0x40);
    memset(&PakuMotionName2, 0, 0x40);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_00266E10", _TRG_PAKU_MOTION__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _SET_BG_COLOR__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _GOTO_DNG_MAP__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _GOTO_DNG__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _GOTO_EDIT__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _GET_MENU_PARAM__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _LOAD_CHARA_NPC__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _AUTO_SET_TREASURE_BOX__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _AUTO_SET_MONSTER__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _LOAD_DUNGEON_MAP_FILE__FP12RS_STACKDATAi);
struct inferred;
struct irregular;
struct RS_STACKDATA_infere;
typedef struct RS_STACKDATA_infere {
    /* 0x0 */ char pad0[8];
    /* 0x8 */ char unk8;                               /* inferred */
    /* 0x8 */ char pad8[1];
} RS_STACKDATA_infere;                                     /* size >= 0x9 */
extern "C" s32 GetNowLoopNo__Fv(void);
extern "C" s32 LoadMonsterFile__Fii(s32, s32);
extern "C" s32 LoadMonsterFile__Fv(void);
extern "C" s32 _LOAD_MONSTER_FILE__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    s32 temp_s0;

    if (GetNowLoopNo__Fv() != 2) {
        return 0;
    }
    switch (arg1) {
    case 1:
        LoadMonsterFile__Fv();
        break;
    case 2:
        temp_s0 = (s32) (GetStackInt__FP12RS_STACKDATA_00262DA0(arg0++));
        LoadMonsterFile__Fii(temp_s0, GetStackInt__FP12RS_STACKDATA_00262DA0(arg0));
        break;
    default:
        return 0;
    }
    return 1;
}
#include "dngfloormanager.hpp"
extern "C" s32 GetPartyCharaStatus__16CUserDataManagerFi(void *, s32);
extern "C" s32 GetSaveData__Fv(void);
extern "C" s32 SetStack__FP12RS_STACKDATAi_00262E70(RS_STACKDATA *, s32);
extern "C" s32 _GET_NPC_STATUS__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    s32 temp_v0;
    CUserDataManager *var_s1;
    s32 temp_v0_2;

    temp_v0 = (s32) (GetStackInt__FP12RS_STACKDATA_00262DA0(arg0++));
    if (temp_v0 <= 0) {
        return 0;
    }
    var_s1 = (CUserDataManager *) (NULL);
    if (temp_v0 > 0x20) {
        return 0;
    }
    temp_v0_2 = GetSaveData__Fv();
    if (temp_v0_2 != 0) {
        var_s1 = (CUserDataManager *) ((u8 *) temp_v0_2 + 0x1D2A0);
    }
    if (var_s1 == NULL) {
        return 0;
    }
    SetStack__FP12RS_STACKDATAi_00262E70(arg0, GetPartyCharaStatus__16CUserDataManagerFi(var_s1, temp_v0));
    return 1;
}
#include "dngfloormanager.hpp"
extern "C" s32 GetSaveData__Fv(void);
extern "C" s32 SetPartyCharaStatus__16CUserDataManagerFii(void *, s32, s32);
extern "C" s32 _SET_NPC_STATUS__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    s32 temp_s0;
    s32 temp_s1;
    CUserDataManager *var_s2;
    s32 temp_v0;

    temp_s0 = (s32) (GetStackInt__FP12RS_STACKDATA_00262DA0(arg0++));
    temp_s1 = (s32) (GetStackInt__FP12RS_STACKDATA_00262DA0(arg0));
    if (temp_s0 <= 0) {
        return 0;
    }
    var_s2 = (CUserDataManager *) (NULL);
    if (temp_s0 > 0x20) {
        return 0;
    }
    temp_v0 = GetSaveData__Fv();
    if (temp_v0 != 0) {
        var_s2 = (CUserDataManager *) ((u8 *) temp_v0 + 0x1D2A0);
    }
    if (var_s2 == NULL) {
        return 0;
    }
    SetPartyCharaStatus__16CUserDataManagerFii(var_s2, temp_s0, temp_s1);
    return 1;
}
#include "dngfloormanager.hpp"
extern "C" s32 GetSaveData__Fv(void);
extern "C" s32 NowPartyCharaID__16CUserDataManagerFv(void *);
extern "C" s32 SetStack__FP12RS_STACKDATAi_00262E70(RS_STACKDATA *, s32);
extern "C" s32 _GET_NOW_PARTY_CHARA__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    CUserDataManager *var_s0;
    s32 temp_v0;

    var_s0 = (CUserDataManager *) (NULL);
    temp_v0 = GetSaveData__Fv();
    if (temp_v0 != 0) {
        var_s0 = (CUserDataManager *) ((u8 *) temp_v0 + 0x1D2A0);
    }
    if (var_s0 == NULL) {
        return 0;
    }
    SetStack__FP12RS_STACKDATAi_00262E70(arg0, NowPartyCharaID__16CUserDataManagerFv(var_s0));
    return 1;
}

extern "C" s32 GetStackInt__FP12RS_STACKDATA_00262DA0(...);
extern "C" s32 SetLocalCnt__Fii(s32, s32);
extern "C" s32 _SET_LOCAL_CNT__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    s32 temp_s0;

    temp_s0 = (s32) (GetStackInt__FP12RS_STACKDATA_00262DA0(arg0++));
    return SetLocalCnt__Fii(temp_s0, GetStackInt__FP12RS_STACKDATA_00262DA0(arg0)) > 0;
}
INCLUDE_ASM("nonmatchings/game/text_00266E10", _GET_LOCAL_CNT__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _GET_LOCAL_CNT2__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _GET_TRAIN_NPC_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _GOTO_DRAW_CHAPTER__FP12RS_STACKDATAi);
struct EdEventInfo;
extern "C" s32 _SET_PROJECTION__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    EdEventInfo.projection = GetStackFloat__FP12RS_STACKDATA_00262DE0(arg0);
    return 1;
}

struct EdEventInfo;
extern "C" s32 _GET_PROJECTION__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    SetStack__FP12RS_STACKDATAf_00262E90(arg0, EdEventInfo.projection);
    return 1;
}

INCLUDE_ASM("nonmatchings/game/text_00266E10", _SET_FADE_IN__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _SET_FADE_OUT__FP12RS_STACKDATAi);
extern "C" s32 GetStackInt__FP12RS_STACKDATA_00262DA0(...);
extern "C" void ScriptDebugCommand__Fi(s32);
extern "C" s32 _DNG_DEBUG_COMMAND__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    ScriptDebugCommand__Fi(GetStackInt__FP12RS_STACKDATA_00262DA0(arg0));
    return 1;
}

INCLUDE_ASM("nonmatchings/game/text_00266E10", _CD_SEEK__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _GET_ROT_LOOK_POS__FP12RS_STACKDATAi);
struct EventScene_champs_4533e0 {
    char pad0[0x2C9C];
    /* 0x2C9C */ s32 unk2C9C;
};
extern "C" s32 _SET_MOTION_BLUR__FP12RS_STACKDATAi_0026A4F0(void) {
    ((struct EventScene_champs_4533e0 *) EventScene)->unk2C9C = GetStackInt__FP12RS_STACKDATA_00262DA0();
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_00266E10", _LOAD_SCRIPT__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _SET_TALK_CAMERA__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _HIT_EFFECT__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _COPY_CHARA__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _GET_START_BUTTON__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _MOVE_INTERIOR__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _GET_MONSTER_TALK_DATA__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _FUNC_POINT_SHOW__FP12RS_STACKDATAi);
struct EventScene_champs_a {
    char pad0[0x2E60];
    /* 0x2E60 */ s32 unk2E60;
};
extern "C" s32 _GET_NOW_MAP_NO__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    SetStack__FP12RS_STACKDATAi_00262E70(arg0, ((struct EventScene_champs_a *) EventScene)->unk2E60);
    return 1;
}
struct EventScene_champs_b {
    char pad0[0x2E64];
    /* 0x2E64 */ s32 unk2E64;
};
extern "C" s32 _GET_NOW_SUBMAP_NO__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    SetStack__FP12RS_STACKDATAi_00262E70(arg0, ((struct EventScene_champs_b *) EventScene)->unk2E64);
    return 1;
}
struct EventScene_champs_c {
    char pad0[0x2E68];
    /* 0x2E68 */ s32 unk2E68;
};
extern "C" s32 _GET_OLD_MAP_NO__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    SetStack__FP12RS_STACKDATAi_00262E70(arg0, ((struct EventScene_champs_c *) EventScene)->unk2E68);
    return 1;
}
struct EventScene_champs_d {
    char pad0[0x2E6C];
    /* 0x2E6C */ s32 unk2E6C;
};
extern "C" s32 _GET_OLD_SUBMAP_NO__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    SetStack__FP12RS_STACKDATAi_00262E70(arg0, ((struct EventScene_champs_d *) EventScene)->unk2E6C);
    return 1;
}
extern "C" s32 SetCharNo__5CRainFi(void *, s32);
extern "C" s32 _SET_RAIN_CHARA_NO__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    SetCharNo__5CRainFi(&EventRain, GetStackInt__FP12RS_STACKDATA_00262DA0(arg0));
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_00266E10", _GET_EDIT_PARTS_POS__FP12RS_STACKDATAi);
s32 _GET_CONTENTS_POS(RS_STACKDATA *stack, int argc) {
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_00266E10", _GET_BPOT_POS__FP12RS_STACKDATAi);
struct BTsuboData {
    s32 field_0;
    u8 pad[124];
};
extern "C" BTsuboData BTsubo;
extern "C" s32 _GET_BPOT_STATUS__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    SetStack__FP12RS_STACKDATAi_00262E70(arg0, BTsubo.field_0);
    return 1;
}
s32 _GET_PERSON_STATUS(RS_STACKDATA *stack, int argc) {
    return 0;
}
struct EventScene_champs_e {
    char pad0[0x2E50];
    /* 0x2E50 */ s32 unk2E50;
};
extern "C" s32 _GET_CONTROL_CHRID__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    SetStack__FP12RS_STACKDATAi_00262E70(arg0, ((struct EventScene_champs_e *) EventScene)->unk2E50);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_00266E10", _SET_CAMERA_NEXT_REF__FP12RS_STACKDATAi_0026B110);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _GOTO_MENU__FP12RS_STACKDATAi);
s32 _GET_MENU_STATUS(RS_STACKDATA *stack, int argc) {
    return 0;
}
INCLUDE_ASM("nonmatchings/game/text_00266E10", _LOAD_EQUIP__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _GET_EQUIP_ITEMNO__FP12RS_STACKDATAi);
struct EventScene_champs_621c45 {
    char pad0[0x2F74];
    /* 0x2F74 */ s32 unk2F74;
};
extern "C" s32 _SET_TIME_STEP_ENABLE__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    ((struct EventScene_champs_621c45 *) EventScene)->unk2F74 = GetStackInt__FP12RS_STACKDATA_00262DA0(arg0);
    return 1;
}
s32 _SET_DOOR_MATERIAL(RS_STACKDATA *stack, int argc) {
    return 1;
}
extern "C" void InitDramaScene__Fv(void);
extern "C" s32 _INIT_DRAMA_SCENE__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    InitDramaScene__Fv();
    return 1;
}

struct EventScene_champs_d3dc51 {
    char pad0[0x2E54];
    /* 0x2E54 */ s32 unk2E54;
};
extern "C" s32 _SET_ACTIVE_CMRID__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    ((struct EventScene_champs_d3dc51 *) EventScene)->unk2E54 = GetStackInt__FP12RS_STACKDATA_00262DA0(arg0);
    return 1;
}
struct EventScene_champs_e348cc {
    char pad0[0x2E58];
    /* 0x2E58 */ s32 unk2E58;
};
extern "C" s32 _SET_BEFORE_CMRID__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    ((struct EventScene_champs_e348cc *) EventScene)->unk2E58 = GetStackInt__FP12RS_STACKDATA_00262DA0(arg0);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_00266E10", _DNGMAP_LOAD__FP12RS_STACKDATAi);
extern "C" u8 EventDngMap[272];
extern "C" s32 DeleteTexBlock__11CDngFreeMapFv(void *);
extern "C" s32 _DNGMAP_DELETE__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    DeleteTexBlock__11CDngFreeMapFv(&EventDngMap);
    return 1;
}
extern "C" u8 EventDngMap[272];
extern "C" s32 SetKomaMove__11CDngFreeMapFi(void *, s32);
extern "C" s32 _DNGMAP_MOVE_PIECE__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    SetKomaMove__11CDngFreeMapFi(&EventDngMap, GetStackInt__FP12RS_STACKDATA_00262DA0(arg0));
    return 1;
}
extern "C" s32 _DNGMAP_ONOFF__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    EventDngMap[8] = (u8) (GetStackInt__FP12RS_STACKDATA_00262DA0(arg0) != 0);
    return 1;
}

INCLUDE_ASM("nonmatchings/game/text_00266E10", _DNGMAP_SET_FADE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _GET_BEFORE_CAMERA_NEXT_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _GET_BEFORE_CAMERA_NEXT_REF__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _SET_CAMERA_NEXT_POS__FP12RS_STACKDATAi_0026BC60);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _CHK_INTERSECTION_POINT__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _CHK_INTERSECTION_POINT_PIPE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _SET_FCAMERA_FOLLOW__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _SET_FCAMERA_FOLLOW_A__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _SET_FCAMERA_FOLLOW_OFS__FP12RS_STACKDATAi);
extern "C" s32 GetCamera__6CSceneFi(void *, s32);
struct inferred;
struct mgCCameraFollow_307bca {
    char pad_0[0x48];
    f32 field_48;
    char pad_4C[0x4];
    f32 field_50;
    char pad_54[0x8];
    s32 field_5C;
    char pad_60[0x10];
    f32 field_70;
    f32 field_74;
    f32 field_78;
    f32 field_7C;
    f32 field_80;
    f32 field_84;
    f32 field_88;
    f32 field_8C;
    f32 field_90;
    f32 field_94;
    f32 field_98;
    f32 field_9C;
    s32 field_A0;
    char pad_A4[0xC];
    f32 field_B0;
    f32 field_B4;
    f32 field_B8;
    f32 field_BC;
    char pad_C0[0x4];
    s32 field_C4;
};
struct CScene_307bca;
typedef struct CScene_307bca {
    /* 0x0000 */ char pad0[0x2E54];
    /* 0x2E54 */ s32 unk2E54;                       /* inferred */
} CScene_307bca;                                           /* size >= 0x2E58 */
struct EventScene_champs_307bca {
    char pad0[0x2E54];
    /* 0x2E54 */ s32 unk2E54;
};
extern "C" s32 FollowOff__15mgCCameraFollowFv(void *);
extern "C" s32 FollowOn__15mgCCameraFollowFv(void *);
extern "C" s32 _SET_FCAMERA_FOLLOW_FLAG__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    mgCCameraFollow_307bca *temp_v0;

    temp_v0 = (mgCCameraFollow_307bca *) (GetCamera__6CSceneFi(EventScene, ((struct EventScene_champs_307bca *) EventScene)->unk2E54));
    if (temp_v0 == NULL) {
        return 0;
    }
    if (GetStackInt__FP12RS_STACKDATA_00262DA0(arg0) == 1) {
        FollowOn__15mgCCameraFollowFv(temp_v0);
    } else {
        FollowOff__15mgCCameraFollowFv(temp_v0);
    }
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_00266E10", _FCAMERA_STEP__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _SET_FCAMERA_ANGLE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _SET_FCAMERA_HEIGHT__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _SET_FCAMERA_DIST__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _GET_REF_ANGLE__FP12RS_STACKDATAi_0026C9B0);
extern "C" s32 GetSaveData__Fv(void);
extern "C" s32 _DNG_SET_STAGE_ID__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    u8 *temp_v0;
    s32 *stage_id;

    temp_v0 = (u8 *) (GetSaveData__Fv());
    if (temp_v0 == NULL) {
        return 0;
    }
    stage_id = (s32 *) (temp_v0 + 0x1C5B4);
    if (stage_id == NULL) {
        return 0;
    }
    *stage_id = GetStackInt__FP12RS_STACKDATA_00262DA0(arg0);
    return 1;
}
extern "C" s32 GetSaveData__Fv(void);
extern "C" s32 SetStack__FP12RS_STACKDATAi_00262E70(RS_STACKDATA *, s32);
extern "C" s32 _DNG_GET_STAGE_ID__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    u8 *temp_v0;
    s32 *stage_id;

    temp_v0 = (u8 *) (GetSaveData__Fv());
    if (temp_v0 == NULL) {
        return 0;
    }
    stage_id = (s32 *) (temp_v0 + 0x1C5B4);
    if (stage_id == NULL) {
        return 0;
    }
    SetStack__FP12RS_STACKDATAi_00262E70(arg0, *stage_id);
    return 1;
}
typedef struct EventScene_pointe {
    char pad0[11860];
    s32 unk2E54;
} EventScene_pointe;
extern "C" EventScene_pointe *EventScene;
extern "C" s32 GetCamera__6CSceneFi(void *, s32);
struct CCameraControl {
    f32 field_0;
    char pad_4[0x70];
    f32 field_74;
    f32 field_78;
    f32 field_7C;
    char pad_80[0x4];
    f32 field_84;
    f32 field_88;
    f32 field_8C;
    char pad_90[0x24];
    f32 field_B4;
    f32 field_B8;
    f32 field_BC;
    char pad_C0[0x10];
    s32 field_D0;
    char pad_D4[0x10];
    f32 field_E4;
    f32 field_E8;
    f32 field_EC;
    char pad_F0[0xB8];
    f32 field_1A8;
    f32 field_1AC;
    f32 field_1B0;
    f32 field_1B4;
    f32 field_1B8;
    f32 field_1BC;
    f32 field_1C0;
    f32 field_1C4;
    f32 field_1C8;
    f32 field_1CC;
    char pad_1D0[0x4];
    f32 field_1D4;
    f32 field_1D8;
    f32 field_1DC;
};
struct inferred;
struct mgCCameraFollow {
    char pad_0[0x48];
    f32 field_48;
    char pad_4C[0x4];
    f32 field_50;
    char pad_54[0x8];
    s32 field_5C;
    char pad_60[0x10];
    f32 field_70;
    f32 field_74;
    f32 field_78;
    f32 field_7C;
    f32 field_80;
    f32 field_84;
    f32 field_88;
    f32 field_8C;
    f32 field_90;
    f32 field_94;
    f32 field_98;
    f32 field_9C;
    s32 field_A0;
    char pad_A4[0xC];
    f32 field_B0;
    f32 field_B4;
    f32 field_B8;
    f32 field_BC;
    char pad_C0[0x4];
    s32 field_C4;
};
typedef struct CScene {
    /* 0x0000 */ char pad0[0x2E54];
    /* 0x2E54 */ s32 unk2E54;                       /* inferred */
} CScene;                                           /* size >= 0x2E58 */
extern "C" s32 ControlOff__14CCameraControlFv(void *);
extern "C" s32 ControlOn__14CCameraControlFv(void *);
extern "C" s32 FollowOff__15mgCCameraFollowFv(void *);
extern "C" s32 FollowOn__15mgCCameraFollowFv(void *);
extern "C" s32 _SET_CAMERA_CTRL__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    mgCCameraFollow *temp_v0;

    temp_v0 = (mgCCameraFollow *) (GetCamera__6CSceneFi(EventScene, EventScene->unk2E54));
    if (temp_v0 == NULL) {
        return 0;
    }
    if (GetStackInt__FP12RS_STACKDATA_00262DA0(arg0) != 0) {
        FollowOn__15mgCCameraFollowFv(temp_v0);
        ControlOn__14CCameraControlFv((CCameraControl *) temp_v0);
    } else {
        FollowOff__15mgCCameraFollowFv(temp_v0);
        ControlOff__14CCameraControlFv((CCameraControl *) temp_v0);
    }
    return 1;
}
extern "C" f32 GetAngle__15mgCCameraFollowFv(void *);
extern "C" s32 SetStack__FP12RS_STACKDATAf_00262E90(RS_STACKDATA *, f32);
extern "C" s32 _GET_FCAMERA_ANGLE__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    mgCCameraFollow *temp_v0;

    temp_v0 = (mgCCameraFollow *) (GetCamera__6CSceneFi(EventScene, EventScene->unk2E54));
    if (temp_v0 == NULL) {
        return 0;
    }
    SetStack__FP12RS_STACKDATAf_00262E90(arg0, GetAngle__15mgCCameraFollowFv(temp_v0));
    return 1;
}
extern "C" f32 GetHeight__15mgCCameraFollowFv(void *);
extern "C" s32 SetStack__FP12RS_STACKDATAf_00262E90(RS_STACKDATA *, f32);
extern "C" s32 _GET_FCAMERA_HEIGHT__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    mgCCameraFollow *temp_v0;

    temp_v0 = (mgCCameraFollow *) (GetCamera__6CSceneFi(EventScene, EventScene->unk2E54));
    if (temp_v0 == NULL) {
        return 0;
    }
    SetStack__FP12RS_STACKDATAf_00262E90(arg0, GetHeight__15mgCCameraFollowFv(temp_v0));
    return 1;
}
extern "C" f32 GetDistance__15mgCCameraFollowFv(void *);
extern "C" s32 SetStack__FP12RS_STACKDATAf_00262E90(RS_STACKDATA *, f32);
extern "C" s32 _GET_FCAMERA_DIST__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    mgCCameraFollow *temp_v0;

    temp_v0 = (mgCCameraFollow *) (GetCamera__6CSceneFi(EventScene, EventScene->unk2E54));
    if (temp_v0 == NULL) {
        return 0;
    }
    SetStack__FP12RS_STACKDATAf_00262E90(arg0, GetDistance__15mgCCameraFollowFv(temp_v0));
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_00266E10", _GET_INVENTION_ID__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _FUNCTION_MAP_JUMP__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _FUNCTION_DOOR_MODE__FP12RS_STACKDATAi);
struct temp_v0_2_champs_b9a5ba {
    char pad0[0x44D9C];
    /* 0x44D9C */ s32 unk44D9C;
};
extern "C" s32 GetSaveData__Fv(void);
extern "C" s32 SetStack__FP12RS_STACKDATAi_00262E70(RS_STACKDATA *, s32);
extern "C" s32 _GET_MONEY__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    s32 temp_v0;
    struct temp_v0_2_champs_b9a5ba *temp_v0_2;

    temp_v0 = GetSaveData__Fv();
    if (temp_v0 == 0) {
        return 0;
    }
    temp_v0_2 = (struct temp_v0_2_champs_b9a5ba *) ((u8 *) temp_v0 + 0x1D2A0);
    if (temp_v0_2 == NULL) {
        return 0;
    }
    SetStack__FP12RS_STACKDATAi_00262E70(arg0, temp_v0_2->unk44D9C);
    return 1;
}

#include "dngfloormanager.hpp"
extern "C" s32 AddMoney__16CUserDataManagerFi(void *, s32);
extern "C" s32 GetSaveData__Fv(void);
extern "C" s32 _ADD_MONEY__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    CUserDataManager *temp_s0;
    s32 temp_v0;

    temp_v0 = GetSaveData__Fv();
    if (temp_v0 == 0) {
        return 0;
    }
    temp_s0 = (CUserDataManager *) ((u8 *) temp_v0 + 0x1D2A0);
    if (temp_s0 == NULL) {
        return 0;
    }
    AddMoney__16CUserDataManagerFi(temp_s0, GetStackInt__FP12RS_STACKDATA_00262DA0(arg0));
    return 1;
}

INCLUDE_ASM("nonmatchings/game/text_00266E10", _GET_ITEM_NUM__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00266E10", _CHECK_BUTTON__FP12RS_STACKDATAi);
extern "C" u32 LanguageCode;
extern "C" s32 _GET_LANGUAGE__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    SetStack__FP12RS_STACKDATAi_00262E70(arg0, LanguageCode);
    return 1;
}
