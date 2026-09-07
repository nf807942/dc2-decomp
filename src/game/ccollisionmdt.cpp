/* CCollisionMDT, CColFrame, CCollision
 *
 * Unité découpée par `make carve` : 62 fonctions, 11300 octets, de
 * 0x00147890 à 0x0014A650. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

/* Les globales que ces accesseurs servent. Leur taille déclarée est celle que
 * le découpage leur donne, et c'est elle qui décide du `%gp_rel`. */
extern s32 DefaultFileDev;
/* Le rappel d'erreur d'entrée-sortie : un pointeur, donc quatre octets, donc
 * `%gp_rel` comme les autres. */
extern s32 (*error_cb)(s32);

#include "sphida.hpp"

/* Le corps ne rend qu'un code : ni la classe ni les arguments ne sont
 * déréférencés, donc leur disposition reste à établir. */

struct CCPoly;
struct mgCDrawManager;

class CColFrame {
public:
    char pad_0[0xF0];
    s32 field_F0;
    char pad_F4[0x1C];
    s32 field_110;

    s32 Draw(mgCDrawManager *manager);
    s32 Draw(u32 *mask, mgCDrawManager *manager);
};

class CCollision {
public:
    s32 field_0;
    char pad_4[0xC];
    f32 field_10;
    char pad_14[0xC];
    f32 field_20;

    s32 GetMaxY(f32 *y);
    s32 Intersection(f32 *a, f32 *b, f32 *c);
    s32 PickUpNearPoly(CCPoly *poly, const mgVu0FBOX &box, s32 flag);
};

struct inferred;
typedef struct CCollision_infere {
    /* 0x00 */ char pad0[0x10];
    /* 0x10 */ f32 unk10;                           /* inferred */
    /* 0x14 */ char pad14[0xC];                     /* maybe part of unk10[4]void */
    /* 0x20 */ f32 unk20;                           /* inferred */
} CCollision_infere;                                       /* size >= 0x24 */
extern "C" s32 mgClipBoxVertex__FPfPfPf(f32 *, f32 *, f32 *);
/* Pose par `make forge`, qui a compose les reparations connues et verifie l'image entiere. Voir docs/IDIOMES_MWCC.md pour le detail de chacune. */
extern "C" s32 InsidePoint__10CCollisionFPf(CCollision_infere *objet, f32 *arg0) {
    return mgClipBoxVertex__FPfPfPf(arg0, &objet->unk10, &objet->unk20) != 0;
}
INCLUDE_ASM("nonmatchings/game/ccollisionmdt", Copy__13CCollisionMDTFR13CCollisionMDTP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/ccollisionmdt", CreateBBox__13CCollisionMDTFv);
INCLUDE_ASM("nonmatchings/game/ccollisionmdt", GetMaxY__13CCollisionMDTFPf);
INCLUDE_ASM("nonmatchings/game/ccollisionmdt", PickUpNearPoly__13CCollisionMDTFP6CCPolyRC9mgVu0FBOXi);
s32 CCollision::Intersection(f32 *a, f32 *b, f32 *c) {
    return 0;
}
INCLUDE_ASM("nonmatchings/game/ccollisionmdt", InsidePoint__9CColFrameFPf);
INCLUDE_ASM("nonmatchings/game/ccollisionmdt", pre_trance_normal__FPA4_f);
INCLUDE_ASM("nonmatchings/game/ccollisionmdt", trance_normal__FPfPfPfPf);
INCLUDE_ASM("nonmatchings/game/ccollisionmdt", PickUpNearPoly__9CColFrameFP6CCPolyRC9mgVu0FBOXi);
s32 CCollision::PickUpNearPoly(CCPoly *poly, const mgVu0FBOX &box, s32 flag) {
    return 0;
}
INCLUDE_ASM("nonmatchings/game/ccollisionmdt", GetWorldBBox__9CColFrameFP9mgVu0FBOX);
INCLUDE_ASM("nonmatchings/game/ccollisionmdt", LoadCollisionFile__FP10MDS_HEADERP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/ccollisionmdt", Initialize__9CColFrameFv);
INCLUDE_ASM("nonmatchings/game/ccollisionmdt", __ct__9CColFrameFv);
INCLUDE_ASM("nonmatchings/game/ccollisionmdt", CreateCollisionMDT__FPUiP9mgCMemory);
s32 CColFrame::Draw(u32 *mask, mgCDrawManager *manager) {
    return 0;
}
s32 CColFrame::Draw(mgCDrawManager *manager) {
    return 0;
}
struct CCollisionMDT;
typedef struct CCollisionMDT {
    /* 0x00 */ s32 unk0;                            /* inferred */
    /* 0x04 */ char pad4[0xC];                      /* maybe part of unk0[4]void */
    /* 0x10 */ char unk10;                             /* inferred */
    /* 0x10 */ char pad10[0x30];
    /* 0x40 */ s32 unk40;                           /* inferred */
    /* 0x44 */ s32 unk44;                           /* inferred */
} CCollisionMDT;                                    /* size >= 0x48 */
struct objet_champs_332138 {
    /* 0x0 */ s32 unk0;
    char pad4[0xC];
    /* 0x10 */ s32 unk10;
    char pad14[0x2C];
    /* 0x40 */ s32 unk40;
    /* 0x44 */ s32 unk44;
};
extern "C" s32 memset(...);
extern "C" void Initialize__13CCollisionMDTFv(CCollisionMDT *objet) {
    ((struct objet_champs_332138 *) objet)->unk0 = 0;
    memset(&((struct objet_champs_332138 *) objet)->unk10, 0, 0x20);
    ((struct objet_champs_332138 *) objet)->unk40 = 0;
    ((struct objet_champs_332138 *) objet)->unk44 = 0;
}
INCLUDE_ASM("nonmatchings/game/ccollisionmdt", Copy__10CCollisionFR10CCollisionP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/ccollisionmdt", CreateBBox__10CCollisionFv);
s32 CCollision::GetMaxY(f32 *y) {
    return 0;
}
INCLUDE_ASM("nonmatchings/game/ccollisionmdt", Initialize__10CCollisionFv);
extern "C" s32 size_to_sector__Fi(s32 arg0) {
    s32 var_v0;

    var_v0 = arg0 >> 0xB;
    if (arg0 < 0) {
        var_v0 = (s32) (arg0 + 0x7FF) >> 0xB;
    }
    if ((arg0 % 2048) != 0) {
        var_v0 += 1;
    }
    return var_v0;
}
s32 GetMainFileDev(void) {
    return DefaultFileDev;
}
INCLUDE_ASM("nonmatchings/game/ccollisionmdt", ChangeHddFile__Fv);
INCLUDE_ASM("nonmatchings/game/ccollisionmdt", ChangeDefaultFile__Fv);
void SetIoErrCallBack(s32 (*callback)(s32)) {
    error_cb = callback;
}
extern "C" u8 CurrentDir[256];
extern "C" u8 TopDir[256];
extern "C" s32 strcpy(...);
extern "C" void SetCurrentDir__FPc(s8 *arg0) {
    s8 *var_a1;

    var_a1 = (s8 *) (arg0);
    if (var_a1 != NULL) {
        if (*var_a1 == 0x2F) {
            var_a1 += 1;
        }
        strcpy(&CurrentDir, var_a1);
        return;
    }
    strcpy(&CurrentDir, &TopDir);
}
INCLUDE_ASM("nonmatchings/game/ccollisionmdt", GetCurrentDir__FPc);
extern "C" u8 CurrentDir[256];
extern "C" u8 TopDir[256];
extern "C" s32 strcat(...);
extern "C" s32 strcpy(...);
extern "C" void ChangeDir__FPc(s8 *arg0) {
    s8 *var_s0;

    var_s0 = (s8 *) (arg0);
    strcpy(&CurrentDir, &TopDir);
    if (var_s0 != NULL) {
        if (*var_s0 == 0x2F) {
            var_s0 += 1;
        }
        strcat(&CurrentDir, var_s0);
    }
}
INCLUDE_ASM("nonmatchings/game/ccollisionmdt", SearchFile__FPc);
INCLUDE_ASM("nonmatchings/game/ccollisionmdt", InitReadBG__Fv);
INCLUDE_ASM("nonmatchings/game/ccollisionmdt", LoadFileBG__FPcP1Pi);
INCLUDE_ASM("nonmatchings/game/ccollisionmdt", GetReadBGFile__FPc);
INCLUDE_ASM("nonmatchings/game/ccollisionmdt", GetReadBGFile__Fi);
INCLUDE_ASM("nonmatchings/game/ccollisionmdt", StartReadBG__Fv);
INCLUDE_ASM("nonmatchings/game/ccollisionmdt", ReadBG__Fv);
INCLUDE_ASM("nonmatchings/game/ccollisionmdt", ReadBGSync__Fv);
extern "C" u8 bg_read_info[9216];
struct var_s0_champs_31f614 {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
    char pad8[0x4];
    /* 0xC */ s32 unkC;
    char pad10[0x108];
    /* 0x118 */ s32 unk118;
};
extern "C" s32 sceCdBreak(...);
extern "C" s32 sceClose(...);
extern "C" s32 InitReadBG__Fv(void);
extern "C" s32 ReadBGSync__Fv(void);
extern "C" void BreakReadBG__Fv(void) {
    void *var_s0;
    s32 var_s1;

    if (ReadBGSync__Fv() != 0) {
        sceCdBreak();
        var_s1 = 0;
        var_s0 = (void *) (&bg_read_info);
        do {
            if ((((struct var_s0_champs_31f614 *) var_s0)->unk0 != 0) && (((struct var_s0_champs_31f614 *) var_s0)->unk4 != 1)) {
                sceClose(((struct var_s0_champs_31f614 *) var_s0)->unk118);
                ((struct var_s0_champs_31f614 *) var_s0)->unkC = 1;
            }
            var_s1 += 1;
            ((u8 *) var_s0) += 0x120;
        } while (var_s1 < 0x20);
        InitReadBG__Fv();
    }
}
INCLUDE_ASM("nonmatchings/game/ccollisionmdt", InitCDFile__Fv);
INCLUDE_ASM("nonmatchings/game/ccollisionmdt", GetDevType__FPcPc);
INCLUDE_ASM("nonmatchings/game/ccollisionmdt", ConvStr__FPc);
INCLUDE_ASM("nonmatchings/game/ccollisionmdt", GetFullPath__FPcPc);
extern "C" u8 _571_00367010[26];
extern "C" s32 Exit(...);
extern "C" s32 printf(...);
extern "C" s32 LoadFile2__FPcPvPii(...);
extern "C" s32 LoadFile__FPcPvPi(s8 *arg0, void *arg1, s32 *arg2) {
    if (LoadFile2__FPcPvPii(arg0, arg1, arg2, 0) == 0) {
        printf(&_571_00367010, arg0);
        Exit(0);
    }
    return 1;
}
INCLUDE_ASM("nonmatchings/game/ccollisionmdt", LoadFile2__FPcPvPii);
INCLUDE_ASM("nonmatchings/game/ccollisionmdt", CDRead__FPcPUiPi);
INCLUDE_ASM("nonmatchings/game/ccollisionmdt", align_size__FUiUi);
INCLUDE_ASM("nonmatchings/game/ccollisionmdt", GetNewFileCache__Fv);
INCLUDE_ASM("nonmatchings/game/ccollisionmdt", InitFileCache__FP1i);
INCLUDE_ASM("nonmatchings/game/ccollisionmdt", DeleteFileCache__Fv);
INCLUDE_ASM("nonmatchings/game/ccollisionmdt", EntryFileCache__FPcP1i);
INCLUDE_ASM("nonmatchings/game/ccollisionmdt", LoadFileCacheBG__FPc);
INCLUDE_ASM("nonmatchings/game/ccollisionmdt", SearchFileCache__FPc);
extern "C" s32 SearchFileCache__FPc(...);
struct temp_v0_champs {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
};
extern "C" s32 SearchFileCache__FPcPi(s8 *arg0, s32 *arg1) {
    struct temp_v0_champs *temp_v0;

    if (arg1 != NULL) {
        *arg1 = 0;
    }
    temp_v0 = (struct temp_v0_champs *) (SearchFileCache__FPc(arg0));
    if (temp_v0 == NULL) {
        return 0;
    }
    if (arg1 != NULL) {
        *arg1 = temp_v0->unk4;
    }
    return temp_v0->unk0;
}
INCLUDE_ASM("nonmatchings/game/ccollisionmdt", WriteFile__FPcPvi);
INCLUDE_ASM("nonmatchings/game/ccollisionmdt", GetPackFile__FPUiPcPi);
INCLUDE_ASM("nonmatchings/game/ccollisionmdt", GetPackFile__FPUiiPPcPi);
INCLUDE_ASM("nonmatchings/game/ccollisionmdt", GetPackFileExt__FPUiPcPPUiiPiPPc);
extern "C" s32 GetPackFile__FPUiiPPcPi(...);
extern "C" s32 GetPackFileNum__FPUi(u32 *arg0) {
    s32 sp38;
    s8 *sp3C;
    s32 var_s0;

    var_s0 = 0;
loop_1:
    if (GetPackFile__FPUiiPPcPi(arg0, var_s0, &sp3C, &sp38) != 0) {
        var_s0 += 1;
        goto loop_1;
    }
    return var_s0;
}

INCLUDE_ASM("nonmatchings/game/ccollisionmdt", DivPathName__FPcPcPc);
INCLUDE_ASM("nonmatchings/game/ccollisionmdt", DivPathNameExt__FPcPcPcPc);
