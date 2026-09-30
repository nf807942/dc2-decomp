/* Fonctions libres — à décrire.
 *
 * Unité découpée par `make carve` : 14 fonctions, 6400 octets, de
 * 0x001A7EA0 à 0x001A9820. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"
#include "gen/mgCMemory.hpp"

/* Les globales que ces accesseurs servent. Leur taille déclarée est celle que
 * le découpage leur donne, et c'est elle qui décide du `%gp_rel`. */
extern s32 EditDebugFlag;
extern s32 LEditFlag;
extern s32 EditDebugTexb;
extern s32 Select;


INCLUDE_ASM("nonmatchings/game/text_001A7EA0", LadderControl__FP6CSceneP11CPadControl);
struct inferred;
typedef struct CScene {
    /* 0x0000 */ char pad0[0x2E50];
    /* 0x2E50 */ s32 unk2E50;                       /* inferred */
} CScene;                                           /* size >= 0x2E54 */
extern "C" s32 StepChara__6CSceneFi(void *, s32);
extern "C" void EditStepChara__FP6CScene(CScene *arg0) {
    s32 var_s0;

    StepChara__6CSceneFi(arg0, arg0->unk2E50);
    var_s0 = 8;
    do {
        StepChara__6CSceneFi(arg0, var_s0);
        var_s0 += 1;
    } while (var_s0 < 0x40);
    StepChara__6CSceneFi(arg0, 0x78);
    StepChara__6CSceneFi(arg0, 0x79);
    StepChara__6CSceneFi(arg0, 0x7A);
    StepChara__6CSceneFi(arg0, 0x7B);
}
typedef struct CScene_infere2 {
    /* 0x0000 */ char pad0[0x2E50];
    /* 0x2E50 */ s32 unk2E50;                       /* inferred */
} CScene_infere2;                                           /* size >= 0x2E54 */
extern "C" s32 DrawCharaShadow__6CSceneFi(void *, s32);
extern "C" void EditDrawShadowChara__FP6CScene(CScene_infere2 *arg0) {
    s32 var_s0;

    DrawCharaShadow__6CSceneFi(arg0, arg0->unk2E50);
    var_s0 = 8;
    do {
        DrawCharaShadow__6CSceneFi(arg0, var_s0);
        var_s0 += 1;
    } while (var_s0 < 0x40);
}
typedef struct CScene_infere {
    /* 0x0000 */ char pad0[0x2E50];
    /* 0x2E50 */ s32 unk2E50;                       /* inferred */
} CScene_infere;                                           /* size >= 0x2E54 */
extern "C" s32 DrawChara__6CSceneFii(void *, s32, s32);
extern "C" s32 GetType__6CSceneFii(void *, s32, s32);
extern "C" void EditDrawChara__FP6CScene(CScene_infere *arg0) {
    s32 var_s0;

    DrawChara__6CSceneFii(arg0, arg0->unk2E50, 0);
    var_s0 = 8;
    do {
        if (GetType__6CSceneFii(arg0, 1, var_s0) != 4) {
            DrawChara__6CSceneFii(arg0, var_s0, 1);
        }
        var_s0 += 1;
    } while (var_s0 < 0x40);
}
extern "C" void EditDrawEffectChara__FP6CScene(CScene *arg0) {
    s32 var_s0;

    var_s0 = 8;
    do {
        if (GetType__6CSceneFii(arg0, 1, var_s0) == 4) {
            DrawChara__6CSceneFii(arg0, var_s0, 2);
        }
        var_s0 += 1;
    } while (var_s0 < 0x40);
}
void EditDebugInit(void) {
    EditDebugFlag = 0;
    Select = 0;
    EditDebugTexb = -1;
}
s32 EditDebugMode(void) {
    return EditDebugFlag;
}
void EditDebugStart(s32 arg0, mgCMemory * arg1) {
    arg1->field_0x24 = 0;
    arg1->field_0x1C = 0;
    EditDebugFlag = 1;
    EditDebugTexb = arg0;
}
INCLUDE_ASM("nonmatchings/game/text_001A7EA0", PrintCursor__FPci);
INCLUDE_ASM("nonmatchings/game/text_001A7EA0", EditDebugLoop__FP6CSceneP13EditDebugInfo);
extern "C" void EditDebugInit__Fv(void);
extern "C" void EditDebugEnd__Fv(void) {
    EditDebugInit__Fv();
}
void InitLightingEdit(void) {
    LEditFlag = 0;
}
extern "C" void InitLightingEdit__Fv(void);
extern "C" void EndLightingEdit__Fv(void) {
    InitLightingEdit__Fv();
}
s32 IsLightingEditMode(void) {
    return LEditFlag;
}
