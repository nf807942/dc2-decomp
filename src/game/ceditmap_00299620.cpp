/* CEditMap, CEditGrid, CMovie, CGridData
 *
 * Unité découpée par `make carve` : 111 fonctions, 24460 octets, de
 * 0x00299620 à 0x0029F850. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"
#include "gen/VideoDec.hpp"
#include "gen/VoBuf.hpp"

/* Les globales que ces accesseurs servent. Leur taille déclarée est celle que
 * le découpage leur donne, et c'est elle qui décide du `%gp_rel`. */
extern u8 isStarted;

/* Les corps ne rendent qu'un code : ni la classe ni les arguments ne sont
 * déréférencés, donc leur disposition reste à établir. */

struct sceMpeg;
struct sceMpegCbDataError;

class CMovie {
public:
    char pad_0[0x14];
    /* L'ordre des declarations decide de l'attribution des registres chez
     * MWCC. Celui-ci n'est pas celui de m2c : il a ete trouve en enumerant
     * les ordres possibles, et c'est le seul qui rende les octets du disque.
     * */
    s32 field_14;
    s32 field_18;
    s32 field_1C;
    s32 field_20;
    char pad_24[0x5C];
    s32 field_80;
    s32 field_84;
    char pad_88[0x40];
    s32 field_C8;
    s32 field_CC;
    char pad_D0[0x8830];
    u8 field_8900;
    char pad_8901[0x1AFFF];
    u8 field_23900;

    s32 IsStarted();
    s32 GetViBufTagSize();
};

INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", MenuNPCQuestViewInit__FP9mgCMemoryPii);
extern "C" void *MenuQuestView;
extern "C" void KeyStep__14CMenuQuestViewFv(void *);
extern "C" void MenuNPCQuestViewKey__Fv(void) { KeyStep__14CMenuQuestViewFv(MenuQuestView); }
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", MenuNPCQuestViewDraw__Fv);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", PlaceRiver__8CEditMapFPf);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", RemoveRiver__8CEditMapFPf);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", CreateGrid__8CEditMapFPfPfP9mgCMemoryPf);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", GetRiverNum__8CEditMapFPf);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", IsRiverGrid__8CEditMapFPf);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", GetRiverNum__8CEditMapFif);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", DrawRiverMask__8CEditMapFv);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", DrawRiver__8CEditMapFv);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", Create__9CEditGridFiiP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", __ct__9CGridDataFv);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", Clear__9CEditGridFv);
extern "C" void mgZeroVector__FPf(...);
struct CEditGrid_i { int f0, f4, f8, fC, f10; };
extern "C" void Initialize__9CEditGridFv(CEditGrid_i *o) {
    o->f4 = 0;
    o->f0 = 0;
    o->f8 = 0;
    o->f10 = 0;
    o->fC = 0;
    mgZeroVector__FPf((float *)o + 8);
}
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", Check__9CEditGridFii);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", Get__9CEditGridFii);
struct inferred;
typedef struct CEditGrid_infere {
    /* 0x0 */ s32 unk0;                             /* inferred */
    /* 0x4 */ char pad4[4];
    /* 0x8 */ s32 unk8;                             /* inferred */
} CEditGrid_infere;                                        /* size >= 0xC */
extern "C" s32 GetFast__9CEditGridFii(CEditGrid_infere *objet, s32 arg0, s32 arg1) {
    return objet->unk8 + ((arg0 + (arg1 * objet->unk0)) * 0x14);
}
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", GetLPos__9CEditGridFPiff);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", GetWPos__9CEditGridFPfii);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", SetRiver__9CEditGridFff);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", ResetRiver__9CEditGridFff);
struct CEditGrid;
extern "C" s32 Get__9CEditGridFii(void *, s32, s32);
extern "C" s32 UpdateRiver__9CEditGridFii(void *, s32, s32);
extern "C" s32 SetRiver__9CEditGridFii(CEditGrid *objet, s32 arg0, s32 arg1) {
    s32 *temp_v0;

    temp_v0 = (s32 *) (Get__9CEditGridFii(objet, arg0, arg1));
    if (temp_v0 == NULL) {
        return 0;
    }
    *temp_v0 = 1;
    UpdateRiver__9CEditGridFii(objet, arg0, arg1);
    UpdateRiver__9CEditGridFii(objet, arg0 - 1, arg1);
    UpdateRiver__9CEditGridFii(objet, arg0 + 1, arg1);
    UpdateRiver__9CEditGridFii(objet, arg0, arg1 + 1);
    UpdateRiver__9CEditGridFii(objet, arg0, arg1 - 1);
    UpdateRiver__9CEditGridFii(objet, arg0 - 1, arg1 - 1);
    UpdateRiver__9CEditGridFii(objet, arg0 + 1, arg1 - 1);
    UpdateRiver__9CEditGridFii(objet, arg0 + 1, arg1 + 1);
    UpdateRiver__9CEditGridFii(objet, arg0 - 1, arg1 + 1);
    return 1;
}
extern "C" s32 Get__9CEditGridFii(void *, s32, s32);
struct CEditGrid {
    s32 field_0;
    s32 field_4;
    char pad_8[0x4];
    f32 field_C;
    f32 field_10;
    char pad_14[0xC];
    f32 field_20;
    f32 field_24;
    f32 field_28;
};
extern "C" s32 UpdateRiver__9CEditGridFii(void *, s32, s32);
extern "C" s32 ResetRiver__9CEditGridFii(CEditGrid *objet, s32 arg0, s32 arg1) {
    s32 *temp_v0;

    temp_v0 = (s32 *) (Get__9CEditGridFii(objet, arg0, arg1));
    if (temp_v0 == NULL) {
        return 0;
    }
    if (*temp_v0 == 0) {
        return 0;
    }
    *temp_v0 = 0;
    UpdateRiver__9CEditGridFii(objet, arg0, arg1);
    UpdateRiver__9CEditGridFii(objet, arg0 - 1, arg1);
    UpdateRiver__9CEditGridFii(objet, arg0 + 1, arg1);
    UpdateRiver__9CEditGridFii(objet, arg0, arg1 + 1);
    UpdateRiver__9CEditGridFii(objet, arg0, arg1 - 1);
    UpdateRiver__9CEditGridFii(objet, arg0 - 1, arg1 - 1);
    UpdateRiver__9CEditGridFii(objet, arg0 + 1, arg1 - 1);
    UpdateRiver__9CEditGridFii(objet, arg0 + 1, arg1 + 1);
    UpdateRiver__9CEditGridFii(objet, arg0 - 1, arg1 + 1);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", UpdateRiver__9CEditGridFii);
extern "C" s32 River__9CEditGridFii(CEditGrid *objet, s32 arg0, s32 arg1) {
    s32 *temp_v0;

    temp_v0 = (s32 *) (Get__9CEditGridFii(objet, arg0, arg1));
    if (temp_v0 != NULL) {
        return *temp_v0;
    }
    return 0;
}
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", GetRiverPos__9CEditGridFiiPA4_f);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", GetRiverPos__9CEditGridFiiPf);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", GetRiverPoly__9CEditGridFP6CCPolyRC9mgVu0FBOXif);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", GetGridBox__9CEditGridFP9mgVu0FBOXPf);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", Load__6CMovieFPcPP9mgCMemoryiibbb);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", Load__6CMovieFPcP9mgCMemoryiibb);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", Load__6CMovieFPcP9mgCMemoryiibbb);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", Play__6CMovieFPc);
struct inferred;
typedef struct CMovie_infere {
    /* 0x00000 */ char pad0[0x23900];
    /* 0x23900 */ u8 unk23900;                      /* inferred */
} CMovie_infere;                                           /* size >= 0x23901 */
extern "C" s32 switchThread__Fv(void);
extern "C" void SwitchThread__6CMovieFv(CMovie_infere *objet) {
    s32 var_s0;

    var_s0 = 0;
    if (objet->unk23900 != 0) {
        do {
            switchThread__Fv();
            var_s0 += 1;
        } while (var_s0 < 4);
    }
}
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", Term__6CMovieFv);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", EndCheck__6CMovieFv);
s32 CMovie::IsStarted(void) {
    return isStarted;
}
extern "C" s32 GetVoBufDataSize__6CMovieFv(void *) { return 0x1C0000; }
extern "C" s32 GetViBufDataSize__6CMovieFv(void *) { return 0x80000; }
s32 CMovie::GetViBufTagSize(void) {
    return 0x1010;
}
extern "C" s32 GetMpegWorkSize__6CMovieFii(CMovie *objet, s32 arg0, s32 arg1) {
    s32 var_v0;
    s32 temp_v1;

    temp_v1 = arg0 * arg1 * 9;
    var_v0 = temp_v1 >> 1;
    if (temp_v1 < 0) {
        var_v0 = (s32) (temp_v1 + 1) >> 1;
    }
    return var_v0 + 0x1768;
}

extern "C" s32 GetReadBufSize__6CMovieFv(void *) { return 0x50050; }
extern "C" s32 GetTagProgSize__6CMovieFii(CMovie *objet, s32 arg0, s32 arg1) {
    s32 temp_v0;
    s32 var_v0;
    s32 temp_v1;
    s32 var_v0_2;
    s32 var_v1;

    var_v0_2 = arg0 >> 4;
    if (arg0 < 0) {
        var_v0_2 = (s32) (arg0 + 0xF) >> 4;
    }
    temp_v0 = var_v0_2 * arg1;
    var_v1 = temp_v0 >> 4;
    if (temp_v0 < 0) {
        var_v1 = (s32) (temp_v0 + 0xF) >> 4;
    }
    temp_v1 = (((var_v1 * 6) + 0x6E) * 4) + 0x3F;
    var_v0 = temp_v1 >> 6;
    if (temp_v1 < 0) {
        var_v0 = (s32) (temp_v1 + 0x3F) >> 6;
    }
    return var_v0 << 8;
}

INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", videoDecCreate__6CMovieFP8VideoDecPUciP1P1iP9TimeStampi);
#include "mpeg.hpp"
struct sceMpegCbData;
extern "C" s32 sceMpegAddStrCallback(...);
extern "C" s32 videoDecSetStream__6CMovieFP8VideoDeciiPFP7sceMpegP13sceMpegCbDataPv_iPv(CMovie *objet, VideoDec *arg0, s32 arg1, s32 arg2, s32 (*arg3)(sceMpeg *, sceMpegCbData *, void *), void *arg4) {
    sceMpegAddStrCallback(arg0, arg1 & 0xFF, arg2, arg3, arg4);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", videoDecDelete__6CMovieFP8VideoDec);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", videoDecFlush__6CMovieFP8VideoDec);
extern "C" s32 defMain__FPv(void *) {
    for (;;) {
        switchThread__Fv();
    }
}
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", videoDecMain__FPv);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", stepMain__FPv);
s32 mpegError(sceMpeg *mpeg, sceMpegCbDataError *error, void *user) {
    return 1;
}
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", mpegNodata__FP7sceMpegP13sceMpegCbDataPv);
extern "C" u8 videoDec[184];
struct sceMpegCbData;
extern "C" s32 viBufStopDMA__FP5ViBuf(...);
extern "C" s32 mpegStopDMA__FP7sceMpegP13sceMpegCbDataPv(sceMpeg *arg0, sceMpegCbData *arg1, void *arg2) {
    viBufStopDMA__FP5ViBuf(videoDec + 0x48);
    return 1;
}
extern "C" u8 videoDec[184];
struct sceMpegCbData;
extern "C" s32 viBufRestartDMA__FP5ViBuf(...);
extern "C" s32 mpegRestartDMA__FP7sceMpegP13sceMpegCbDataPv(sceMpeg *arg0, sceMpegCbData *arg1, void *arg2) {
    viBufRestartDMA__FP5ViBuf(videoDec + 0x48);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", mpegTS__FP7sceMpegP22sceMpegCbDataTimeStampPv);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", videoCallback__FP7sceMpegP16sceMpegCbDataStrPv);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", pcmCallback__FP7sceMpegP16sceMpegCbDataStrPv);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", vblankHandler__Fi);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", handler_endimage__Fi);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", voBufCreate__FP5VoBufP6VoDataP5VoTagi);
void voBufReset(VoBuf * arg0) {
    arg0->field_0xC = 0;
    arg0->field_0x10 = 0;
}
extern "C" s32 voBufIsFull__FP5VoBuf(VoBuf *arg0) {
    return arg0->field_0x10 == *(s32 *) ((u8 *) arg0 + 0x14);
}
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", voBufIncCount__FP5VoBuf);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", voBufGetData__FP5VoBuf);
extern "C" s32 voBufIsEmpty__FP5VoBuf(VoBuf *b) {
    return b->field_0x10 == 0;
}
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", voBufGetTag__FP5VoBuf);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", voBufDecCount__FP5VoBuf);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", getFIFOindex__FP5ViBufPv);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", setD3_CHCR__FUi);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", setD4_CHCR__FUi);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", scTag2__FP5QWORDPvUiUi);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", viBufCreate__FP5ViBufP1P1iP9TimeStampi);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", viBufReset__FP5ViBuf);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", viBufBeginPut__FP5ViBufPPUcPiPPUcPi);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", viBufEndPut__FP5ViBufi);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", viBufAddDMA__FP5ViBuf);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", viBufStopDMA__FP5ViBuf);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", viBufRestartDMA__FP5ViBuf);
typedef struct ViBuf {
    /* 0x00 */ char pad0[0x40];
    /* 0x40 */ s32 unk40;                           /* inferred */
} ViBuf;                                            /* size >= 0x44 */
extern "C" void DeleteSema(s32);
extern "C" void setD4_CHCR__FUi(u32 arg0);
extern "C" s32 viBufDelete__FP5ViBuf(ViBuf *arg0) {
    setD4_CHCR__FUi(5U);
    *(s32 *)0x1000B420 = 0;
    *(s32 *)0x1000B410 = 0;
    *(s32 *)0x1000B430 = 0;
    DeleteSema(arg0->unk40);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", viBufFlush__FP5ViBuf);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", viBufModifyPts__FP5ViBufP9TimeStamp);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", viBufPutTs__FP5ViBufP9TimeStamp);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", viBufGetTs__FP5ViBufP9TimeStamp);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", strFileOpen__FP7StrFilePc);
typedef struct StrFile {
    /* 0x00 */ s32 unk0;                            /* inferred */
    /* 0x04 */ char pad4[0x20];                     /* maybe part of unk0[9]void */
    /* 0x24 */ s32 unk24;                           /* inferred */
    /* 0x28 */ s32 unk28;                           /* inferred */
} StrFile;                                          /* size >= 0x2C */
extern "C" s32 sceCdStSeekF(...);
extern "C" s32 sceLseek(...);
extern "C" void strFileSeek__FP7StrFile(StrFile *arg0) {
    if (arg0->unk28 != 0) {
        sceCdStSeekF(arg0->unk0);
        return;
    }
    sceLseek(arg0->unk24, 0, 0);
}
typedef struct StrFile_infere {
    /* 0x00 */ char pad0[0x24];
    /* 0x24 */ s32 unk24;                           /* inferred */
    /* 0x28 */ s32 unk28;                           /* inferred */
} StrFile_infere;                                          /* size >= 0x2C */
extern "C" s32 sceCdStStop(...);
extern "C" s32 sceClose(...);
extern "C" s32 strFileClose__FP7StrFile(StrFile_infere *arg0) {
    if (arg0->unk28 != 0) {
        sceCdStStop();
    } else {
        sceClose(arg0->unk24);
    }
    return 1;
}
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", strFileRead__FP7StrFilePvi);
typedef struct ReadBuf {
    /* 0x00000 */ char pad0[0x50000];
    /* 0x50000 */ s32 unk50000;                     /* inferred */
    /* 0x50004 */ s32 unk50004;                     /* inferred */
    /* 0x50008 */ s32 unk50008;                     /* inferred */
} ReadBuf;                                          /* size >= 0x5000C */
extern "C" void readBufCreate__FP7ReadBuf(ReadBuf *arg0) {
    arg0->unk50004 = 0;
    arg0->unk50000 = 0;
    arg0->unk50008 = 0x50000;
}
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", readBufBeginPut__FP7ReadBufPPUc);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", readBufEndPut__FP7ReadBufi);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", readBufBeginGet__FP7ReadBufPPUc);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", readBufEndGet__FP7ReadBufi);
extern "C" u8 _0_buf[2048];
extern "C" u8 _1109_003735B0[28];
extern "C" u8 _1110_003735D0[41];
struct inferred;
typedef struct AudioDec {
    /* 0x00 */ s32 unk0;                            /* inferred */
    /* 0x04 */ char pad4[0x28];                     /* maybe part of unk0[0xB]void */
    /* 0x2C */ s32 unk2C;                           /* inferred */
    /* 0x30 */ u8 *unk30;                           /* inferred */
    /* 0x34 */ s32 unk34;                           /* inferred */
    /* 0x38 */ s32 unk38;                           /* inferred */
    /* 0x3C */ s32 unk3C;                           /* inferred */
    /* 0x40 */ s32 unk40;                           /* inferred */
    /* 0x44 */ s32 unk44;                           /* inferred */
    /* 0x48 */ s32 unk48;                           /* inferred */
    /* 0x4C */ s32 unk4C;                           /* inferred */
    /* 0x50 */ s32 unk50;                           /* inferred */
    /* 0x54 */ s32 unk54;                           /* inferred */
    /* 0x58 */ s32 unk58;                           /* inferred */
} AudioDec;                                         /* size >= 0x5C */
extern "C" s32 memset(...);
extern "C" s32 printf(...);
extern "C" s32 sceSifAllocIopHeap(...);
extern "C" s32 sndSetMasterVol__Fif(s32, f32);
extern "C" s32 changeMasterVolume__FUi(u32);
extern "C" s32 sendToIOP__FiPUci(...);
extern "C" s32 audioDecCreate__FP8AudioDecPUcii(AudioDec *arg0, u8 *arg1, s32 arg2, s32 arg3) {
    s32 temp_a1;
    s32 temp_a1_2;

    arg0->unk0 = 0;
    arg0->unk2C = 0;
    arg0->unk30 = arg1;
    arg0->unk34 = 0;
    arg0->unk38 = 0;
    arg0->unk3C = arg2;
    arg0->unk40 = 0;
    arg0->unk54 = 0;
    arg0->unk48 = arg3;
    arg0->unk4C = 0;
    arg0->unk50 = 0;
    arg0->unk44 = sceSifAllocIopHeap(arg3);
    temp_a1 = (s32) (arg0->unk44);
    if (temp_a1 < 0) {
        printf(&_1109_003735B0, temp_a1);
        return 0;
    }
    printf(&_1110_003735D0, temp_a1, arg3);
    arg0->unk58 = sceSifAllocIopHeap(0x800);
    temp_a1_2 = (s32) (arg0->unk58);
    if (temp_a1_2 < 0) {
        printf(&_1109_003735B0, temp_a1_2);
        return 0;
    }
    printf(&_1110_003735D0, temp_a1_2, 0x800);
    memset(&_0_buf, 0, 0x800);
    sendToIOP__FiPUci(arg0->unk58, &_0_buf, 0x800);
    changeMasterVolume__FUi(0x3FFFU);
    sndSetMasterVol__Fif(0, 1.0f);
    sndSetMasterVol__Fif(1, 1.0f);
    return 1;
}
typedef struct AudioDec_infere2 {
    /* 0x00 */ char pad0[0x44];
    /* 0x44 */ s32 unk44;                           /* inferred */
    /* 0x48 */ char pad48[0x10];                    /* maybe part of unk44[5]void */
    /* 0x58 */ s32 unk58;                           /* inferred */
} AudioDec_infere2;                                         /* size >= 0x5C */
extern "C" s32 sceSifFreeIopHeap(...);
extern "C" s32 audioDecDelete__FP8AudioDec(AudioDec_infere2 *arg0) {
    sceSifFreeIopHeap(arg0->unk44);
    sceSifFreeIopHeap(arg0->unk58);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", audioDecPause__FP8AudioDec);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", audioDecResume__FP8AudioDec);
extern "C" void audioDecResume__FP8AudioDec(void *);
extern "C" void audioDecStart__FP8AudioDec(void *a) { audioDecResume__FP8AudioDec(a); }
typedef struct AudioDec_infere {
    /* 0x00 */ s32 unk0;                            /* inferred */
    /* 0x04 */ char pad4[0x28];                     /* maybe part of unk0[0xB]void */
    /* 0x2C */ s32 unk2C;                           /* inferred */
    /* 0x30 */ char pad30[4];
    /* 0x34 */ s32 unk34;                           /* inferred */
    /* 0x38 */ s32 unk38;                           /* inferred */
    /* 0x3C */ char pad3C[4];
    /* 0x40 */ s32 unk40;                           /* inferred */
    /* 0x44 */ char pad44[8];                       /* maybe part of unk40[3]void */
    /* 0x4C */ s32 unk4C;                           /* inferred */
    /* 0x50 */ s32 unk50;                           /* inferred */
    /* 0x54 */ s32 unk54;                           /* inferred */
} AudioDec_infere;                                         /* size >= 0x58 */
extern "C" s32 audioDecPause__FP8AudioDec(AudioDec_infere *);
extern "C" void audioDecReset__FP8AudioDec(AudioDec_infere *arg0) {
    audioDecPause__FP8AudioDec(arg0);
    arg0->unk0 = 0;
    arg0->unk2C = 0;
    arg0->unk34 = 0;
    arg0->unk38 = 0;
    arg0->unk40 = 0;
    arg0->unk54 = 0;
    arg0->unk4C = 0;
    arg0->unk50 = 0;
}
extern "C" s32 audioDecIsPreset__FP8AudioDec(AudioDec *arg0) {
    return arg0->unk54 >= arg0->unk48;
}
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", audioDecSendToIOP__FP8AudioDec);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", iopGetArea__FPiPiPiPiP8AudioDeci);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", sendToIOP2area__FiiiiPUciPUci);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", sendToIOP__FiPUci);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", changeMasterVolume__FUi);
extern "C" s32 sceSdRemote(...);
extern "C" void changeInputVolume__FUi(u32 arg0) {
    sceSdRemote(1, 0x8010, 0xF81, arg0);
    sceSdRemote(1, 0x8010, 0x1081, arg0);
}
extern "C" u32 frd;
extern "C" u8 isCountVblank;
extern "C" s32 sceGsSyncV(...);
extern "C" void startDisplay__Fi(s32 arg0) {
    do {

    } while (arg0 == sceGsSyncV(0));
    frd = 0;
    isCountVblank = 1;
}
extern "C" s32 switchThread__Fv(void);
extern "C" s32 RotateThreadReadyQueue(...);
extern "C" s32 switchThread__Fv(void) { return RotateThreadReadyQueue(10); }
extern "C" u32 videoDecSetState__FP8VideoDecUi(void *objet, u32 arg0) {
    u32 old = *(u32 *) ((u8 *) objet + 0xA8);
    *(u32 *) ((u8 *) objet + 0xA8) = arg0;
    return old;
}
s32 videoDecGetState(VideoDec * arg0) {
    return arg0->field_0xA8;
}
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", decBs0__FP8VideoDec);
