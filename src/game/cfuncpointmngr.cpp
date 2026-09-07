/* CFuncPointMngr, CObjAnime, CEditMap, CFuncPoint, CList_10CFuncPoint_
 *
 * Unité découpée par `make carve` : 39 fonctions, 9504 octets, de
 * 0x0029F850 à 0x002A1E80. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"
#include "gen/CFuncPointMngr.hpp"
#include "gen/CList_10CFuncPoint_.hpp"

INCLUDE_ASM("nonmatchings/game/cfuncpointmngr", setImageTag__FPUiPviii);
INCLUDE_ASM("nonmatchings/game/cfuncpointmngr", videoDecBeginPut__FP8VideoDecPPUcPiPPUcPi);
INCLUDE_ASM("nonmatchings/game/cfuncpointmngr", videoDecPutTs__FP8VideoDecllPUci);
INCLUDE_ASM("nonmatchings/game/cfuncpointmngr", videoDecEndPut__FP8VideoDeci);
INCLUDE_ASM("nonmatchings/game/cfuncpointmngr", cpy2area__FPUciPUciPUciPUci);
INCLUDE_ASM("nonmatchings/game/cfuncpointmngr", audioDecBeginPut__FP8AudioDecPPUcPiPPUcPi);
INCLUDE_ASM("nonmatchings/game/cfuncpointmngr", audioDecEndPut__FP8AudioDeci);
INCLUDE_ASM("nonmatchings/game/cfuncpointmngr", isAudioOK__Fv);
INCLUDE_ASM("nonmatchings/game/cfuncpointmngr", DrawFireEffect__8CEditMapFi);
INCLUDE_ASM("nonmatchings/game/cfuncpointmngr", DrawFireRaster__8CEditMapFv);
INCLUDE_ASM("nonmatchings/game/cfuncpointmngr", DrawEffect__8CEditMapFv);
INCLUDE_ASM("nonmatchings/game/cfuncpointmngr", AnimeStep__8CEditMapFP12CObjAnimeEnv);
struct match;
extern "C" s32 CheckTime__Ffff(f32 arg0, f32 arg1, f32 arg2) {
    /* L'ordre des declarations decide de l'attribution des registres chez
     * MWCC. Celui-ci n'est pas celui de m2c : il a ete trouve en enumerant
     * les ordres possibles, et c'est le seul qui rende les octets du disque.
     * */
    s32 var_v0;

    if (!(arg2 <= arg1)) {
        if (arg0 < arg1) {
            return 0;
        }
        var_v0 = 1;
        if (arg0 < arg2) {
            var_v0 = 0;
        }
        return var_v0 ^ 1;
    }
    if (!(arg1 <= arg2)) {
        if (!(arg0 < arg1)) {
            /* Duplicate return node #12. Try simplifying control flow for better match */
            return 1;
        }
        if (!(arg0 < arg2)) {
            return 0;
        }
        /* Duplicate return node #12. Try simplifying control flow for better match */
        return 1;
    }
    return 1;
}
INCLUDE_ASM("nonmatchings/game/cfuncpointmngr", LimitTime__Ff);
INCLUDE_ASM("nonmatchings/game/cfuncpointmngr", SubTime__Fff);
INCLUDE_ASM("nonmatchings/game/cfuncpointmngr", Initialize__10CFuncPointFv);
INCLUDE_ASM("nonmatchings/game/cfuncpointmngr", Check__10CFuncPointFP15CFuncPointCheck);
INCLUDE_ASM("nonmatchings/game/cfuncpointmngr", CheckOver__FPfPfPf);
INCLUDE_ASM("nonmatchings/game/cfuncpointmngr", Step__9CObjAnimeFP12CObjAnimeEnv);
INCLUDE_ASM("nonmatchings/game/cfuncpointmngr", SetParam__9CObjAnimeFPf);
INCLUDE_ASM("nonmatchings/game/cfuncpointmngr", GetParam__9CObjAnimeFPf);
INCLUDE_ASM("nonmatchings/game/cfuncpointmngr", AssignFuncAnime__9CObjAnimeFP10CFuncPointP9CMapParts);
INCLUDE_ASM("nonmatchings/game/cfuncpointmngr", Add__14CFuncPointMngrFiP9mgCMemory);
void CList_10CFuncPoint_::Initialize(void) {
    this->field_0x4 = 0;
    this->field_0x0 = 0;
}
INCLUDE_ASM("nonmatchings/game/cfuncpointmngr", Add__14CFuncPointMngrFiP19CList_10CFuncPoint_);
INCLUDE_ASM("nonmatchings/game/cfuncpointmngr", Reserve__14CFuncPointMngrFiP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/cfuncpointmngr", __ct__19CList_10CFuncPoint_Fv);
INCLUDE_ASM("nonmatchings/game/cfuncpointmngr", GetReserve__14CFuncPointMngrFv);
extern "C" s32 GetReserve__14CFuncPointMngrFv(void *);
extern "C" s32 Add__14CFuncPointMngrFiP19CList_10CFuncPoint_(void *, s32, CList_10CFuncPoint_ *);
extern "C" s32 Initialize__10CFuncPointFv(void *);
extern "C" s32 AddFromReserve__14CFuncPointMngrFi(CFuncPointMngr *objet, s32 arg0) {
    CList_10CFuncPoint_ *temp_v0;

    temp_v0 = (CList_10CFuncPoint_ *) (GetReserve__14CFuncPointMngrFv(objet));
    if (temp_v0 == NULL) {
        return 0;
    }
    Initialize__10CFuncPointFv(((CList_10CFuncPoint_ *) ((u8 *) temp_v0 + 0x10)));
    return Add__14CFuncPointMngrFiP19CList_10CFuncPoint_(objet, arg0, temp_v0);
}
INCLUDE_ASM("nonmatchings/game/cfuncpointmngr", GetNum__14CFuncPointMngrFi);
extern "C" s32 Get__14CFuncPointMngrFv(void *);
struct var_v0_champs {
    char pad0[0x20];
    /* 0x20 */ s32 unk20;
};
extern "C" s32 GetEnd__14CFuncPointMngrFv(void *);
extern "C" s32 GetStart__14CFuncPointMngrFi(void *, s32);
extern "C" s32 GetEventNum__14CFuncPointMngrFi(CFuncPointMngr *objet, s32 arg0) {
    s32 var_s0;
    struct var_v0_champs *var_v0;

    var_s0 = 0;
    GetStart__14CFuncPointMngrFi(objet, 6);
    var_v0 = (struct var_v0_champs *) (Get__14CFuncPointMngrFv(objet));
    if (var_v0 != NULL) {
        do {
            if (var_v0->unk20 & arg0) {
                var_s0 += 1;
            }
            var_v0 = (struct var_v0_champs *) (Get__14CFuncPointMngrFv(objet));
        } while (var_v0 != NULL);
    }
    GetEnd__14CFuncPointMngrFv(objet);
    return var_s0;
}
INCLUDE_ASM("nonmatchings/game/cfuncpointmngr", EnableFuncNum__14CFuncPointMngrFi);
INCLUDE_ASM("nonmatchings/game/cfuncpointmngr", GetStart__14CFuncPointMngrFi);
INCLUDE_ASM("nonmatchings/game/cfuncpointmngr", Get__14CFuncPointMngrFv);
void CFuncPointMngr::GetEnd(void) {
    this->field_0x2C = 0;
}
extern "C" s32 strcasecmp(...);
extern "C" s32 *Search__14CFuncPointMngrFPc(CFuncPointMngr *objet, s8 *arg0) {
    s32 *temp_v0;
    s32 *temp_v0_2;
    s32 var_s0;
    s32 *var_s1;

    var_s0 = 1;
loop_1:
    GetStart__14CFuncPointMngrFi(objet, var_s0);
    temp_v0 = (s32 *) (Get__14CFuncPointMngrFv(objet));
    var_s1 = (s32 *) (temp_v0);
    if (temp_v0 != NULL) {
loop_2:
        if (strcasecmp(*var_s1, arg0) == 0) {
            return var_s1;
        }
        temp_v0_2 = (s32 *) (Get__14CFuncPointMngrFv(objet));
        var_s1 = (s32 *) (temp_v0_2);
        if (temp_v0_2 == NULL) {
            goto block_5;
        }
        goto loop_2;
    }
block_5:
    GetEnd__14CFuncPointMngrFv(objet);
    var_s0 += 1;
    if (var_s0 >= 0xA) {
        return NULL;
    }
    goto loop_1;
}

INCLUDE_ASM("nonmatchings/game/cfuncpointmngr", GetLight__14CFuncPointMngrFPfP10CFuncPointiP15CFuncPointChecki);
INCLUDE_ASM("nonmatchings/game/cfuncpointmngr", Step__14CFuncPointMngrFiP15CFuncPointCheck);
extern "C" s32 Get__14CFuncPointMngrFv(void *);
struct CFuncPointCheck {
    f32 field_0;
    s32 field_4;
};
struct inferred;
typedef struct CFuncPoint {
    /* 0x000 */ char pad0[0x1B0];
    /* 0x1B0 */ s32 unk1B0;                         /* inferred */
} CFuncPoint;                                       /* size >= 0x1B4 */
extern "C" s32 Check__10CFuncPointFP15CFuncPointCheck(void *, CFuncPointCheck *);
extern "C" s32 GetEnd__14CFuncPointMngrFv(void *);
extern "C" s32 GetStart__14CFuncPointMngrFi(void *, s32);
extern "C" s32 UpdateFlag__14CFuncPointMngrFiP15CFuncPointCheck(CFuncPointMngr *objet, s32 arg0, CFuncPointCheck *arg1) {
    CFuncPoint *temp_v0;
    CFuncPoint *temp_v0_2;
    CFuncPoint *var_s0;
    s32 temp_v0_3;
    s32 var_s1;

    GetStart__14CFuncPointMngrFi(objet, arg0);
    var_s1 = 0;
    temp_v0 = (CFuncPoint *) (Get__14CFuncPointMngrFv(objet));
    var_s0 = (CFuncPoint *) (temp_v0);
    if (temp_v0 != NULL) {
        do {
            temp_v0_3 = (s32) (Check__10CFuncPointFP15CFuncPointCheck(var_s0, arg1));
            var_s0->unk1B0 = temp_v0_3;
            if (temp_v0_3 != 0) {
                var_s1 += 1;
            }
            temp_v0_2 = (CFuncPoint *) (Get__14CFuncPointMngrFv(objet));
            var_s0 = (CFuncPoint *) (temp_v0_2);
        } while (temp_v0_2 != NULL);
    }
    GetEnd__14CFuncPointMngrFv(objet);
    return var_s1;
}
