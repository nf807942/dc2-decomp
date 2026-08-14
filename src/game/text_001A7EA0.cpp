/* Fonctions libres — à décrire.
 *
 * Unité découpée par `make carve` : 14 fonctions, 6400 octets, de
 * 0x001A7EA0 à 0x001A9820. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

/* Les globales que ces accesseurs servent. Leur taille déclarée est celle que
 * le découpage leur donne, et c'est elle qui décide du `%gp_rel`. */
extern s32 EditDebugFlag;
extern s32 LEditFlag;

INCLUDE_ASM("nonmatchings/game/text_001A7EA0", LadderControl__FP6CSceneP11CPadControl);
INCLUDE_ASM("nonmatchings/game/text_001A7EA0", EditStepChara__FP6CScene);
INCLUDE_ASM("nonmatchings/game/text_001A7EA0", EditDrawShadowChara__FP6CScene);
INCLUDE_ASM("nonmatchings/game/text_001A7EA0", EditDrawChara__FP6CScene);
INCLUDE_ASM("nonmatchings/game/text_001A7EA0", EditDrawEffectChara__FP6CScene);
INCLUDE_ASM("nonmatchings/game/text_001A7EA0", EditDebugInit__Fv);
s32 EditDebugMode(void) {
    return EditDebugFlag;
}
INCLUDE_ASM("nonmatchings/game/text_001A7EA0", EditDebugStart__FiP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/text_001A7EA0", PrintCursor__FPci);
INCLUDE_ASM("nonmatchings/game/text_001A7EA0", EditDebugLoop__FP6CSceneP13EditDebugInfo);
INCLUDE_ASM("nonmatchings/game/text_001A7EA0", EditDebugEnd__Fv);
void InitLightingEdit(void) {
    LEditFlag = 0;
}
INCLUDE_ASM("nonmatchings/game/text_001A7EA0", EndLightingEdit__Fv);
s32 IsLightingEditMode(void) {
    return LEditFlag;
}
