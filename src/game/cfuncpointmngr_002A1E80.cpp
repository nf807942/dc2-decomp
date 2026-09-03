/* CFuncPointMngr
 *
 * Unité découpée par `make carve` : 16 fonctions, 8040 octets, de
 * 0x002A1E80 à 0x002A3E30. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

/* Les globales que ces accesseurs servent. Leur taille déclarée est celle que
 * le découpage leur donne, et c'est elle qui décide du `%gp_rel`. */
extern s16 TitleOmakeFlag;
extern s32 OmakeFlag;


INCLUDE_ASM("nonmatchings/game/cfuncpointmngr_002A1E80", UpdateStatus__14CFuncPointMngrFv);
INCLUDE_ASM("nonmatchings/game/cfuncpointmngr_002A1E80", Copy__14CFuncPointMngrFR14CFuncPointMngrP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/cfuncpointmngr_002A1E80", Initialize__14CFuncPointMngrFv);
INCLUDE_ASM("nonmatchings/game/cfuncpointmngr_002A1E80", DrawFireEffect__FPA4_fP14CFuncPointMngrP15CFuncPointCheckfP10mgCTextureP10mgCTexture);
INCLUDE_ASM("nonmatchings/game/cfuncpointmngr_002A1E80", DrawFireRaster__FPA4_fP14CFuncPointMngrP15CFuncPointCheckP11CFireRaster);
INCLUDE_ASM("nonmatchings/game/cfuncpointmngr_002A1E80", GetSeSrcVolPan__FPA4_fP14CFuncPointMngrP15CFuncPointCheckPiPfPfi);
INCLUDE_ASM("nonmatchings/game/cfuncpointmngr_002A1E80", GetLightAnimeWeight__FP10CFuncPointi);
extern "C" s32 mgGetVSyncCount__Fv(void);
extern "C" s32 srand(...);
extern "C" void title_init_rand__Fv(void) {
    srand(mgGetVSyncCount__Fv());
}
INCLUDE_ASM("nonmatchings/game/cfuncpointmngr_002A1E80", SetSoundMode__Fv);
void InitTitleOmakeFlag(void) {
    TitleOmakeFlag = 0;
    OmakeFlag = 0;
}
void TitleOmakeOn(void) {
    TitleOmakeFlag = 1;
}
s32 CheckOmakeFlag(void) {
    return TitleOmakeFlag;
}
INCLUDE_ASM("nonmatchings/game/cfuncpointmngr_002A1E80", InitOmakeEnv__FiP13INIT_LOOP_ARGPi);
INCLUDE_ASM("nonmatchings/game/cfuncpointmngr_002A1E80", TitleInit__F13INIT_LOOP_ARG);
INCLUDE_ASM("nonmatchings/game/cfuncpointmngr_002A1E80", TitleBootInit__Fv);
extern "C" u8 GamePad_003FA5A0[1144];
extern "C" u8 _1267[12];
extern "C" u32 mgFrameRate;
extern "C" s32 AutoRepeatOff__8CGamePadFv(void *);
extern "C" s32 MenuModeOff__8CGamePadFv(void *);
extern "C" s32 mgCloseFont__Fv(void);
extern "C" s32 printf(...);
extern "C" s32 sndSeAllStop__Fi(s32);
extern "C" s32 CheckOmakeFlag__Fv(void);
extern "C" void TitleExit__Fv(void) {
    if (CheckOmakeFlag__Fv() != 0) {
        OmakeFlag = 1;
    }
    printf(&_1267, OmakeFlag);
    sndSeAllStop__Fi(-1);
    AutoRepeatOff__8CGamePadFv(&GamePad_003FA5A0);
    MenuModeOff__8CGamePadFv(&GamePad_003FA5A0);
    mgFrameRate = 2;
    mgCloseFont__Fv();
}
