/* Fonctions libres — à décrire.
 *
 * Unité découpée par `make carve` : 16 fonctions, 3136 octets, de
 * 0x0026DD80 à 0x0026EA00. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"
#include "gen/EdEventInfoData.hpp"
extern EdEventInfoData EdEventInfo;
struct RS_STACKDATA;


INCLUDE_ASM("nonmatchings/game/text_0026DD80", _GET_SAVEDATA_ETC__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_0026DD80", _DEL_MONSTER__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_0026DD80", _SET_MENU_ETC__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_0026DD80", _GET_MENU_ETC__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_0026DD80", _GET_ANALYZE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_0026DD80", _GET_DIORAMA_PERCENT__FP12RS_STACKDATAi);
extern "C" u32 EventScene;
struct GeoFuncParam;
extern "C" s32 GeoramaFunc__FP12GeoFuncParamP12RS_STACKDATAi(GeoFuncParam *, RS_STACKDATA *, s32);
extern "C" void _GEORAMA_FUNC__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    s32 sp1C;

    sp1C = EventScene;
    GeoramaFunc__FP12GeoFuncParamP12RS_STACKDATAi((GeoFuncParam *) &sp1C, arg0, arg1);
}
INCLUDE_ASM("nonmatchings/game/text_0026DD80", _GET_CHARA_ID__FP12RS_STACKDATAi);
s32 _GOTO_EDITMODE(RS_STACKDATA * arg0, s32 arg1) {
    EdEventInfo.field_0xCC = 17;
    return 1;
}
extern "C" s32 GetSaveData__Fv(void);
#include "dngfloormanager.hpp"
#include "runscript.hpp"
extern "C" s32 GetNowChapter__FP9CSaveData(CSaveData *);
extern "C" s32 SetStack__FP12RS_STACKDATAi_00262E70(RS_STACKDATA *, s32);
extern "C" s32 _GET_CHAPTER__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    CSaveData *temp_v0;

    temp_v0 = (CSaveData *) (GetSaveData__Fv());
    if (temp_v0 == NULL) {
        return 0;
    }
    SetStack__FP12RS_STACKDATAi_00262E70(arg0, GetNowChapter__FP9CSaveData(temp_v0));
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_0026DD80", _GET_NPC_TRAIN_ETC__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_0026DD80", _REGISTER_VILLAGER__FP12RS_STACKDATAi);
extern "C" s32 EyeViewDrawOnOff__6CSceneFi(...);
extern "C" s32 GetStackInt__FP12RS_STACKDATA_00262DA0(RS_STACKDATA *);
extern "C" s32 _EYE_VIEW_DRAW_ON_OFF__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    EyeViewDrawOnOff__6CSceneFi(EventScene, GetStackInt__FP12RS_STACKDATA_00262DA0(arg0));
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_0026DD80", _SET_QUEST_ETC__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_0026DD80", _GET_QUEST_ETC__FP12RS_STACKDATAi);
extern "C" s32 GetOldInteriorMapNo__Fv(void);
extern "C" s32 _GET_OLD_INTERIOR_MAP_NO__FP12RS_STACKDATAi(RS_STACKDATA *arg0, s32 arg1) {
    SetStack__FP12RS_STACKDATAi_00262E70(arg0, GetOldInteriorMapNo__Fv());
    return 1;
}
