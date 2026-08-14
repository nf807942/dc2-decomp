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
    s32 Draw(mgCDrawManager *manager);
    s32 Draw(u32 *mask, mgCDrawManager *manager);
};

class CCollision {
public:
    s32 GetMaxY(f32 *y);
    s32 Intersection(f32 *a, f32 *b, f32 *c);
    s32 PickUpNearPoly(CCPoly *poly, const mgVu0FBOX &box, s32 flag);
};

INCLUDE_ASM("nonmatchings/game/ccollisionmdt", InsidePoint__10CCollisionFPf);
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
INCLUDE_ASM("nonmatchings/game/ccollisionmdt", Initialize__13CCollisionMDTFv);
INCLUDE_ASM("nonmatchings/game/ccollisionmdt", Copy__10CCollisionFR10CCollisionP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/ccollisionmdt", CreateBBox__10CCollisionFv);
s32 CCollision::GetMaxY(f32 *y) {
    return 0;
}
INCLUDE_ASM("nonmatchings/game/ccollisionmdt", Initialize__10CCollisionFv);
INCLUDE_ASM("nonmatchings/game/ccollisionmdt", size_to_sector__Fi);
s32 GetMainFileDev(void) {
    return DefaultFileDev;
}
INCLUDE_ASM("nonmatchings/game/ccollisionmdt", ChangeHddFile__Fv);
INCLUDE_ASM("nonmatchings/game/ccollisionmdt", ChangeDefaultFile__Fv);
void SetIoErrCallBack(s32 (*callback)(s32)) {
    error_cb = callback;
}
INCLUDE_ASM("nonmatchings/game/ccollisionmdt", SetCurrentDir__FPc);
INCLUDE_ASM("nonmatchings/game/ccollisionmdt", GetCurrentDir__FPc);
INCLUDE_ASM("nonmatchings/game/ccollisionmdt", ChangeDir__FPc);
INCLUDE_ASM("nonmatchings/game/ccollisionmdt", SearchFile__FPc);
INCLUDE_ASM("nonmatchings/game/ccollisionmdt", InitReadBG__Fv);
INCLUDE_ASM("nonmatchings/game/ccollisionmdt", LoadFileBG__FPcP1Pi);
INCLUDE_ASM("nonmatchings/game/ccollisionmdt", GetReadBGFile__FPc);
INCLUDE_ASM("nonmatchings/game/ccollisionmdt", GetReadBGFile__Fi);
INCLUDE_ASM("nonmatchings/game/ccollisionmdt", StartReadBG__Fv);
INCLUDE_ASM("nonmatchings/game/ccollisionmdt", ReadBG__Fv);
INCLUDE_ASM("nonmatchings/game/ccollisionmdt", ReadBGSync__Fv);
INCLUDE_ASM("nonmatchings/game/ccollisionmdt", BreakReadBG__Fv);
INCLUDE_ASM("nonmatchings/game/ccollisionmdt", InitCDFile__Fv);
INCLUDE_ASM("nonmatchings/game/ccollisionmdt", GetDevType__FPcPc);
INCLUDE_ASM("nonmatchings/game/ccollisionmdt", ConvStr__FPc);
INCLUDE_ASM("nonmatchings/game/ccollisionmdt", GetFullPath__FPcPc);
INCLUDE_ASM("nonmatchings/game/ccollisionmdt", LoadFile__FPcPvPi);
INCLUDE_ASM("nonmatchings/game/ccollisionmdt", LoadFile2__FPcPvPii);
INCLUDE_ASM("nonmatchings/game/ccollisionmdt", CDRead__FPcPUiPi);
INCLUDE_ASM("nonmatchings/game/ccollisionmdt", align_size__FUiUi);
INCLUDE_ASM("nonmatchings/game/ccollisionmdt", GetNewFileCache__Fv);
INCLUDE_ASM("nonmatchings/game/ccollisionmdt", InitFileCache__FP1i);
INCLUDE_ASM("nonmatchings/game/ccollisionmdt", DeleteFileCache__Fv);
INCLUDE_ASM("nonmatchings/game/ccollisionmdt", EntryFileCache__FPcP1i);
INCLUDE_ASM("nonmatchings/game/ccollisionmdt", LoadFileCacheBG__FPc);
INCLUDE_ASM("nonmatchings/game/ccollisionmdt", SearchFileCache__FPc);
INCLUDE_ASM("nonmatchings/game/ccollisionmdt", SearchFileCache__FPcPi);
INCLUDE_ASM("nonmatchings/game/ccollisionmdt", WriteFile__FPcPvi);
INCLUDE_ASM("nonmatchings/game/ccollisionmdt", GetPackFile__FPUiPcPi);
INCLUDE_ASM("nonmatchings/game/ccollisionmdt", GetPackFile__FPUiiPPcPi);
INCLUDE_ASM("nonmatchings/game/ccollisionmdt", GetPackFileExt__FPUiPcPPUiiPiPPc);
INCLUDE_ASM("nonmatchings/game/ccollisionmdt", GetPackFileNum__FPUi);
INCLUDE_ASM("nonmatchings/game/ccollisionmdt", DivPathName__FPcPcPc);
INCLUDE_ASM("nonmatchings/game/ccollisionmdt", DivPathNameExt__FPcPcPcPc);
