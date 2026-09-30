/* Fonctions libres — à décrire.
 *
 * Unité découpée par `make carve` : 8 fonctions, 1908 octets, de
 * 0x00271030 à 0x002717C0. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

INCLUDE_ASM("nonmatchings/game/text_00271030", _SET_MES_ETC__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00271030", _GET_MES_ETC__FP12RS_STACKDATAi);
extern "C" u32 EventScene;
extern "C" s32 GetStack__6CSceneFi(void *, s32);
extern "C" s32 Align64__9mgCMemoryFv(void *);
extern "C" s32 GetLoadBGBuff__FPcPi(...);
extern "C" s32 memcpy(...);
extern "C" s32 stAlloc64__9mgCMemoryFi(void *, s32);
extern "C" s32 stAllocTest__9mgCMemoryFi(void *, s32);
struct LoadMesDst {
    char pad0[0x1E44];
    s32 buf;
    s32 size;
};
extern "C" s32 _LOAD_MES_sub__FPciP6ClsMes(char *arg0, s32 arg1, LoadMesDst *arg2) {
    s32 size;
    s32 src;
    void *mem;
    s32 dst;
    s32 t;


    if (arg0 == NULL) {
        return 0;
    }
    if (arg2 == NULL) {
        return 0;
    }
    src = GetLoadBGBuff__FPcPi(arg0, &size);
    if (src == 0) {
        return 0;
    }
    mem = (void *) GetStack__6CSceneFi((void *) EventScene, arg1);
    Align64__9mgCMemoryFv(mem);
    dst = stAllocTest__9mgCMemoryFi(mem, size / 16 + 1);
    if (dst == 0) {
        return 0;
    }
    stAlloc64__9mgCMemoryFi(mem, size / 16 + 1);
    memcpy(dst, src, size);
    t = size;
    arg2->buf = dst;
    arg2->size = t;
    return 1;
}
INCLUDE_ASM("nonmatchings/game/text_00271030", _LOAD_MES__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00271030", _LOAD_MES_MONS_TALK__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00271030", _MES_SE_PLAY__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00271030", _SET_MES_STR__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/text_00271030", _GET_MES_OKURI__FP12RS_STACKDATAi);
