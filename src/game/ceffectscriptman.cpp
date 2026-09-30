/* CEffectScriptMan
 *
 * Unité découpée par `make carve` : 126 fonctions, 24516 octets, de
 * 0x002E4DE0 à 0x002EB000. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

INCLUDE_ASM("nonmatchings/game/ceffectscriptman", Initialize__16CEffectScriptManFP9mgCMemoryii);
extern "C" void SetWorkBuffer__16CEffectScriptManFP9mgCMemory(void *arg0, void *arg1) {
    if (arg1 != NULL) {
        *(void **) ((u8 *) arg0 + 4) = arg1;
    }
}
struct CEffectScriptMan {
    char pad_0[0xC];
    s32 field_C;
    s32 field_10;
    s32 field_14;
    s32 field_18;
    s32 field_1C;
    s32 field_20;
    s32 field_24;
    s32 field_28;
    char pad_2C[0x154];
    s32 field_180;
    char pad_184[0x1D8];
    s32 field_35C;
    s32 field_360;
    s32 field_364;
};
extern "C" s32 strcmp(s32, s8 *);
extern "C" s32 GetEffSptBaseDefPtr__Fi(s32 arg0);
extern "C" s32 SearchBaseNo__16CEffectScriptManFPc(CEffectScriptMan *objet, s8 *arg0) {
    s32 temp_v0;
    s32 var_s0;

    var_s0 = 0;
loop_1:
    temp_v0 = GetEffSptBaseDefPtr__Fi(var_s0);
    if (temp_v0 == 0) {
        return -1;
    }
    if (strcmp(temp_v0, arg0) == 0) {
        return var_s0;
    }
    var_s0 += 1;
    goto loop_1;
}
INCLUDE_ASM("nonmatchings/game/ceffectscriptman", LoadBaseEffSpt__16CEffectScriptManFiP9mgCMemoryi);
#include "menu.hpp"
extern "C" void LoadBaseEffSpt__16CEffectScriptManFiP9mgCMemoryi(CEffectScriptMan *objet, s32 arg0, mgCMemory *arg1, s32 arg2);
extern "C" s32 SearchBaseNo__16CEffectScriptManFPc(CEffectScriptMan *objet, s8 *arg0);
extern "C" void LoadBaseEffSpt__16CEffectScriptManFPcP9mgCMemoryi(CEffectScriptMan *objet, s8 *arg0, mgCMemory *arg1, s32 arg2) {
    LoadBaseEffSpt__16CEffectScriptManFiP9mgCMemoryi(objet, SearchBaseNo__16CEffectScriptManFPc(objet, arg0), arg1, arg2);
}
INCLUDE_ASM("nonmatchings/game/ceffectscriptman", ClearBaseFromLevel__16CEffectScriptManFiPii);
INCLUDE_ASM("nonmatchings/game/ceffectscriptman", GetBaseChara__16CEffectScriptManFi);
extern "C" void GetBaseChara__16CEffectScriptManFi(CEffectScriptMan *objet, s32 arg0);
extern "C" s32 SearchBaseNo__16CEffectScriptManFPc(CEffectScriptMan *objet, s8 *arg0);
extern "C" void GetBaseChara__16CEffectScriptManFPc(CEffectScriptMan *objet, s8 *arg0) {
    GetBaseChara__16CEffectScriptManFi(objet, SearchBaseNo__16CEffectScriptManFPc(objet, arg0));
}
struct inferred;
typedef struct CEffectScriptMan_infere2 {
    /* 0x00 */ char pad0[0x10];
    /* 0x10 */ s32 unk10;                           /* inferred */
    /* 0x14 */ s32 unk14;                           /* inferred */
    /* 0x18 */ s32 unk18;                           /* inferred */
} CEffectScriptMan_infere2;                                 /* size >= 0x1C */
extern "C" s32 GetNotUsedTexb__16CEffectScriptManFv(CEffectScriptMan_infere2 *objet) {
    s32 temp_v1;

    temp_v1 = objet->unk18;
    if (temp_v1 >= objet->unk14) {
        return -1;
    }
    return objet->unk10 + temp_v1;
}
struct effect_manager_l1c { char pad[0xC]; s32 unkC; char pad10[4]; s32 unk14; s32 unk18; };
struct effect_item_l1c { char pad[0x1C]; s32 unk1C; };
extern "C" void AddTexb__16CEffectScriptManFv(effect_manager_l1c *objet) {
    s32 count = objet->unk18;
    if (count < objet->unk14) {
        objet->unk18 = count + 1;
        effect_item_l1c *item = (effect_item_l1c *) ((objet->unkC << 2) + (s32) objet);
        item->unk1C = item->unk1C + 1;
    }
}
INCLUDE_ASM("nonmatchings/game/ceffectscriptman", BuildBase__16CEffectScriptManFiP1iP1iP9mgCMemoryi);
INCLUDE_ASM("nonmatchings/game/ceffectscriptman", BuildBase__16CEffectScriptManFPcP1iP1iP9mgCMemoryi);
INCLUDE_ASM("nonmatchings/game/ceffectscriptman", BuildPack__16CEffectScriptManFiPUiP9mgCMemoryi);
extern "C" s32 BuildPack__16CEffectScriptManFiPUiP9mgCMemoryi(void *, s32, u32 *, mgCMemory *, s32);
extern "C" void BuildPack__16CEffectScriptManFPcPUiP9mgCMemoryi(CEffectScriptMan *objet, s8 *arg0, u32 *arg1, mgCMemory *arg2, s32 arg3) {
    BuildPack__16CEffectScriptManFiPUiP9mgCMemoryi(objet, SearchBaseNo__16CEffectScriptManFPc(objet, arg0), arg1, arg2, arg3);
}
INCLUDE_ASM("nonmatchings/game/ceffectscriptman", GetNeedFilePath__16CEffectScriptManFiPcPc);
extern "C" void GetNeedFilePath__16CEffectScriptManFiPcPc(CEffectScriptMan *objet, s32 arg0, s8 *arg1, s8 *arg2);
extern "C" s32 SearchBaseNo__16CEffectScriptManFPc(CEffectScriptMan *objet, s8 *arg0);
extern "C" void GetNeedFilePath__16CEffectScriptManFPcPcPc(CEffectScriptMan *objet, s8 *arg0, s8 *arg1, s8 *arg2) {
    GetNeedFilePath__16CEffectScriptManFiPcPc(objet, SearchBaseNo__16CEffectScriptManFPc(objet, arg0), arg1, arg2);
}
INCLUDE_ASM("nonmatchings/game/ceffectscriptman", CreateEffSpt__16CEffectScriptManFiii);
extern "C" s32 CreateEffSpt__16CEffectScriptManFiii(void *, s32, s32, s32);
struct temp_v0_champs {
    char pad0[0xAC];
    /* 0xAC */ s32 unkAC;
};
extern "C" s32 CreateEffSpt__16CEffectScriptManFPcii(CEffectScriptMan *objet, s8 *arg0, s32 arg1, s32 arg2) {
    struct temp_v0_champs *temp_v0;

    temp_v0 = (struct temp_v0_champs *) (CreateEffSpt__16CEffectScriptManFiii(objet, SearchBaseNo__16CEffectScriptManFPc(objet, arg0), arg1, arg2));
    if (temp_v0 != NULL) {
        return temp_v0->unkAC;
    }
    return -1;
}
INCLUDE_ASM("nonmatchings/game/ceffectscriptman", ClearEffectFromChrid__16CEffectScriptManFi);
INCLUDE_ASM("nonmatchings/game/ceffectscriptman", ClearEffectFromLevel__16CEffectScriptManFi);
INCLUDE_ASM("nonmatchings/game/ceffectscriptman", DeleteEffSpt__16CEffectScriptManFP11_EFF_SCRIPT);
INCLUDE_ASM("nonmatchings/game/ceffectscriptman", DeleteEffSpt__16CEffectScriptManFii);
INCLUDE_ASM("nonmatchings/game/ceffectscriptman", AllClearEffSpt__16CEffectScriptManFv);
INCLUDE_ASM("nonmatchings/game/ceffectscriptman", Step__16CEffectScriptManFv);
INCLUDE_ASM("nonmatchings/game/ceffectscriptman", Draw__16CEffectScriptManFv);
INCLUDE_ASM("nonmatchings/game/ceffectscriptman", AssignSprite__16CEffectScriptManFi);
INCLUDE_ASM("nonmatchings/game/ceffectscriptman", DeleteSprite__16CEffectScriptManFP10_ES_SPRITE);
INCLUDE_ASM("nonmatchings/game/ceffectscriptman", AssignCharacter__16CEffectScriptManFP11_EFF_SCRIPTi);
INCLUDE_ASM("nonmatchings/game/ceffectscriptman", SetScriptProgNo__16CEffectScriptManFiii);
INCLUDE_ASM("nonmatchings/game/ceffectscriptman", Pause__16CEffectScriptManFiii);
struct inferred;
typedef struct CEffectScriptMan_infere {
    /* 0x0000 */ char pad0[0x1188];
    /* 0x1188 */ void *unk1188;                     /* inferred */
} CEffectScriptMan_infere;                                 /* size >= 0x118C */
struct var_a0_champs {
    char pad0[0x24];
    /* 0x24 */ s32 unk24;
    char pad28[0x114];
    /* 0x13C */ s32 unk13C;
    char pad140[0x4];
    /* 0x144 */ s32 unk144;
};
extern "C" void PauseFromLevel__16CEffectScriptManFii(CEffectScriptMan_infere *objet, s32 arg0, s32 arg1) {
    struct var_a0_champs *var_a0;

    var_a0 = (struct var_a0_champs *) (objet->unk1188);
    if (var_a0 != NULL) {
        do {
            if (var_a0->unk24 == arg0) {
                var_a0->unk13C = arg1;
            }
            var_a0 = (struct var_a0_champs *) (var_a0->unk144);
        } while (var_a0 != NULL);
    }
}
INCLUDE_ASM("nonmatchings/game/ceffectscriptman", SetScriptVect1__16CEffectScriptManFPfii);
INCLUDE_ASM("nonmatchings/game/ceffectscriptman", GetScriptVect1__16CEffectScriptManFPfii);
INCLUDE_ASM("nonmatchings/game/ceffectscriptman", SetScriptVect2__16CEffectScriptManFPfii);
INCLUDE_ASM("nonmatchings/game/ceffectscriptman", GetScriptVect2__16CEffectScriptManFPfii);
INCLUDE_ASM("nonmatchings/game/ceffectscriptman", SetScriptTargetId__16CEffectScriptManFiii);
INCLUDE_ASM("nonmatchings/game/ceffectscriptman", GetScriptTargetId__16CEffectScriptManFRiii);
INCLUDE_ASM("nonmatchings/game/ceffectscriptman", SetScriptUserId__16CEffectScriptManFiii);
INCLUDE_ASM("nonmatchings/game/ceffectscriptman", GetScriptUserId__16CEffectScriptManFRiii);
INCLUDE_ASM("nonmatchings/game/ceffectscriptman", SetColPrim__16CEffectScriptManFP8CColPrimii);
INCLUDE_ASM("nonmatchings/game/ceffectscriptman", SetValue__16CEffectScriptManFiiii);
INCLUDE_ASM("nonmatchings/game/ceffectscriptman", SetValue__16CEffectScriptManFifii);
INCLUDE_ASM("nonmatchings/game/ceffectscriptman", SetOrigin__16CEffectScriptManFPfii);
INCLUDE_ASM("nonmatchings/game/ceffectscriptman", GetCharacter__16CEffectScriptManFii);
INCLUDE_ASM("nonmatchings/game/ceffectscriptman", SetCharacter__16CEffectScriptManFP11CCharacter2ii);
INCLUDE_ASM("nonmatchings/game/ceffectscriptman", SetTexb__16CEffectScriptManFiii);
INCLUDE_ASM("nonmatchings/game/ceffectscriptman", GetEffSptBaseDefPtr__Fi);
INCLUDE_ASM("nonmatchings/game/ceffectscriptman", DrawEffSptSprite__FP11_EFF_SCRIPTP10mgCTexturePfP11mgC3DSpriteP16CMapLightingInfo);
INCLUDE_ASM("nonmatchings/game/ceffectscriptman", GetSpritePtr__FP11_EFF_SCRIPTi);
extern "C" s32 fptosi(f32);
extern "C" s32 GetStackInt__FP12RS_STACKDATA_002E8280(void *arg0) {
    if (*(s32 *) arg0 == 1) {
        return fptosi(*(f32 *) ((u8 *) arg0 + 4));
    }
    return *(s32 *) ((u8 *) arg0 + 4);
}
extern "C" f32 GetStackFloat__FP12RS_STACKDATA_002E82C0(void *arg0) {
    if (*(s32 *) arg0 == 0) {
        return (f32) *(s32 *) ((u8 *) arg0 + 4);
    }
    return *(f32 *) ((u8 *) arg0 + 4);
}
INCLUDE_ASM("nonmatchings/game/ceffectscriptman", GetStackVector__FPfP12RS_STACKDATA_002E82F0);
extern "C" s32 GetStackString__FP12RS_STACKDATA_002E8340(void *arg0) {
    return *(s32 *) ((u8 *) arg0 + 4);
}
struct arg0_champs_aef12e {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ struct unk4_champs_aef12e *unk4;
};
struct unk4_champs_aef12e {
    char pad0[0x4];
    /* 0x4 */ s32 unk4;
};
extern "C" void SetStack__FP12RS_STACKDATAi_002E8350(struct arg0_champs_aef12e *arg0, s32 arg1) {
    if (arg0->unk0 == 3) {
        arg0->unk4->unk4 = arg1;
    }
}
extern "C" void SetStack__FP12RS_STACKDATAf_002E8370(struct arg0_champs_aef12e *arg0, f32 arg1) {
    if (arg0->unk0 == 3) {
        *(f32 *) ((u8 *) arg0->unk4 + 4) = arg1;
    }
}
INCLUDE_ASM("nonmatchings/game/ceffectscriptman", _ZERO_VECTOR__FP12RS_STACKDATAi_002E8390);
INCLUDE_ASM("nonmatchings/game/ceffectscriptman", _NORMAL_VECTOR__FP12RS_STACKDATAi_002E83E0);
INCLUDE_ASM("nonmatchings/game/ceffectscriptman", _COPY_VECTOR__FP12RS_STACKDATAi_002E8490);
INCLUDE_ASM("nonmatchings/game/ceffectscriptman", _ADD_VECTOR__FP12RS_STACKDATAi_002E8500);
INCLUDE_ASM("nonmatchings/game/ceffectscriptman", _SUB_VECTOR__FP12RS_STACKDATAi_002E8580);
INCLUDE_ASM("nonmatchings/game/ceffectscriptman", _SCALE_VECTOR__FP12RS_STACKDATAi_002E8600);
INCLUDE_ASM("nonmatchings/game/ceffectscriptman", _DIV_VECTOR__FP12RS_STACKDATAi_002E8670);
INCLUDE_ASM("nonmatchings/game/ceffectscriptman", _DIST_VECTOR__FP12RS_STACKDATAi_002E8730);
INCLUDE_ASM("nonmatchings/game/ceffectscriptman", _DIST_VECTOR2__FP12RS_STACKDATAi_002E8790);
INCLUDE_ASM("nonmatchings/game/ceffectscriptman", _SQRT__FP12RS_STACKDATAi_002E8800);
INCLUDE_ASM("nonmatchings/game/ceffectscriptman", _ATAN2F__FP12RS_STACKDATAi_002E8860);
INCLUDE_ASM("nonmatchings/game/ceffectscriptman", _ANGLE_CMP__FP12RS_STACKDATAi_002E88C0);
INCLUDE_ASM("nonmatchings/game/ceffectscriptman", _ANGLE_LIMIT__FP12RS_STACKDATAi_002E8930);
INCLUDE_ASM("nonmatchings/game/ceffectscriptman", _GET_RAND__FP12RS_STACKDATAi_002E8980);
INCLUDE_ASM("nonmatchings/game/ceffectscriptman", _GET_REF_ROT__FP12RS_STACKDATAi_002E8A70);
INCLUDE_ASM("nonmatchings/game/ceffectscriptman", _GET_DIR_VECTOR__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/ceffectscriptman", _SET_ORIGIN__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/ceffectscriptman", _GET_ORIGIN__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/ceffectscriptman", _AUTO_SET_OFFSET__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/ceffectscriptman", _GET_WORK_VECT1__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/ceffectscriptman", _GET_WORK_VECT2__FP12RS_STACKDATAi);
#include "runscript.hpp"
extern "C" u32 now_script;
struct target_script_l1c { char pad[0x110]; s32 unk110; };
struct arg0_champs_aef12e;
extern "C" void SetStack__FP12RS_STACKDATAi_002E8350(arg0_champs_aef12e *, s32);
extern "C" s32 _GET_TARGET_ID__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    if (arg1 != 1) return 0;
    SetStack__FP12RS_STACKDATAi_002E8350((arg0_champs_aef12e *) arg0, ((target_script_l1c *) now_script)->unk110);
    return 1;
}
#include "runscript.hpp"
extern "C" u32 now_script;
struct user_script_l1c { char pad[0xA8]; s32 unkA8; };
struct arg0_champs_aef12e;
extern "C" void SetStack__FP12RS_STACKDATAi_002E8350(arg0_champs_aef12e *, s32);
extern "C" s32 _GET_USER_ID__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    if (arg1 != 1) return 0;
    SetStack__FP12RS_STACKDATAi_002E8350((arg0_champs_aef12e *) arg0, ((user_script_l1c *) now_script)->unkA8);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/ceffectscriptman", _GET_VALUE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/ceffectscriptman", _SET_VALUE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/ceffectscriptman", _CHR_SET_SHOW__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/ceffectscriptman", _CHR_GET_SHOW__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/ceffectscriptman", _CHR_SET_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/ceffectscriptman", _CHR_GET_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/ceffectscriptman", _CHR_SET_ROT__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/ceffectscriptman", _CHR_GET_ROT__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/ceffectscriptman", _CHR_SET_SCALE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/ceffectscriptman", _CHR_GET_SCALE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/ceffectscriptman", _CHR_SET_MOTION__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/ceffectscriptman", _CHR_SET_MOT_STEP__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/ceffectscriptman", _CHR_GET_MOT_WAIT__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/ceffectscriptman", _CHR_GET_DIR_VECTOR__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/ceffectscriptman", _CHR_GET_REF_ROT__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/ceffectscriptman", _CHR_ADD_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/ceffectscriptman", _CHR_ADD_ROT__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/ceffectscriptman", _CHR_ADD_SCALE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/ceffectscriptman", _CHR_COPY_CHARA__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/ceffectscriptman", _CHR_SET_POS2__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/ceffectscriptman", _CHR_SET_ROT2__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/ceffectscriptman", _CHR_SET_SCALE2__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/ceffectscriptman", _CHR_SET_MOTION2__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/ceffectscriptman", _CHR_ADD_POS2__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/ceffectscriptman", _CHR_ADD_ROT2__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/ceffectscriptman", _CHR_ADD_SCALE2__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/ceffectscriptman", _CHR_SET_SHOW2__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/ceffectscriptman", _CHR_GET_FRAME_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/ceffectscriptman", _CHR_SET_FRAME_SHOW__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/ceffectscriptman", _CHR_CHK_MOT_END__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/ceffectscriptman", _CHR_SET_LIGHT_COLOR__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/ceffectscriptman", _SPT_ASSIGN_SPRITE__FP12RS_STACKDATAi);
extern "C" u32 EffScriptMan;
extern "C" u32 now_script;
#include "runscript.hpp"
struct _ES_SPRITE {
    char pad_0[0x4];
    s32 field_4;
};
struct now_script_champs_52d9e2 {
    char pad0[0x28];
    /* 0x28 */ s32 unk28;
    /* 0x2C */ s32 unk2C;
};
extern "C" void DeleteSprite__16CEffectScriptManFP10_ES_SPRITE(u32, _ES_SPRITE *);
extern "C" s32 _SPT_DELETE_SPRITE__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    _ES_SPRITE *temp_a1;

    temp_a1 = (_ES_SPRITE *) (((struct now_script_champs_52d9e2 *) now_script)->unk28);
    if (temp_a1 == NULL) {
        return 0;
    }
    DeleteSprite__16CEffectScriptManFP10_ES_SPRITE(EffScriptMan, temp_a1);
    ((struct now_script_champs_52d9e2 *) now_script)->unk28 = NULL;
    ((struct now_script_champs_52d9e2 *) now_script)->unk2C = 0;
    return 1;
}
extern "C" u32 now_script;
#include "runscript.hpp"
extern "C" void strcpy(s32, s32);
extern "C" s32 GetStackString__FP12RS_STACKDATA_002E8340(void *);
extern "C" s32 _SPT_SET_TEXNAME__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    strcpy(now_script + 0x30, GetStackString__FP12RS_STACKDATA_002E8340(arg0));
    return 1;
}
INCLUDE_ASM("nonmatchings/game/ceffectscriptman", _SPT_SET_ALPHAB__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/ceffectscriptman", _SPT_INIT_SPRITE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/ceffectscriptman", _SPT_SET_DRAW_FLAG__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/ceffectscriptman", _SPT_GET_DRAW_FLAG__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/ceffectscriptman", _SPT_SET_UV_SIZE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/ceffectscriptman", _SPT_SET_PUT_SIZE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/ceffectscriptman", _SPT_SET_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/ceffectscriptman", _SPT_GET_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/ceffectscriptman", _SPT_SET_ROTZ__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/ceffectscriptman", _SPT_GET_ROTZ__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/ceffectscriptman", _SPT_SET_SCALE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/ceffectscriptman", _SPT_GET_SCALE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/ceffectscriptman", _SPT_SET_COLOR__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/ceffectscriptman", _SPT_GET_COLOR__FP12RS_STACKDATAi);
