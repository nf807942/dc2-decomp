/* CCollisionMDT, CColFrame, CCollision
 *
 * Unité découpée par `make carve` : 62 fonctions, 11300 octets, de
 * 0x00147890 à 0x0014A650. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

INCLUDE_ASM("nonmatchings/ccollisionmdt", InsidePoint__10CCollisionFPf);
INCLUDE_ASM("nonmatchings/ccollisionmdt", Copy__13CCollisionMDTFR13CCollisionMDTP9mgCMemory);
INCLUDE_ASM("nonmatchings/ccollisionmdt", CreateBBox__13CCollisionMDTFv);
INCLUDE_ASM("nonmatchings/ccollisionmdt", GetMaxY__13CCollisionMDTFPf);
INCLUDE_ASM("nonmatchings/ccollisionmdt", PickUpNearPoly__13CCollisionMDTFP6CCPolyRC9mgVu0FBOXi);
INCLUDE_ASM("nonmatchings/ccollisionmdt", Intersection__10CCollisionFPfPfPf);
INCLUDE_ASM("nonmatchings/ccollisionmdt", InsidePoint__9CColFrameFPf);
INCLUDE_ASM("nonmatchings/ccollisionmdt", pre_trance_normal__FPA4_f);
INCLUDE_ASM("nonmatchings/ccollisionmdt", trance_normal__FPfPfPfPf);
INCLUDE_ASM("nonmatchings/ccollisionmdt", PickUpNearPoly__9CColFrameFP6CCPolyRC9mgVu0FBOXi);
INCLUDE_ASM("nonmatchings/ccollisionmdt", PickUpNearPoly__10CCollisionFP6CCPolyRC9mgVu0FBOXi);
INCLUDE_ASM("nonmatchings/ccollisionmdt", GetWorldBBox__9CColFrameFP9mgVu0FBOX);
INCLUDE_ASM("nonmatchings/ccollisionmdt", LoadCollisionFile__FP10MDS_HEADERP9mgCMemory);
INCLUDE_ASM("nonmatchings/ccollisionmdt", Initialize__9CColFrameFv);
INCLUDE_ASM("nonmatchings/ccollisionmdt", __ct__9CColFrameFv);
INCLUDE_ASM("nonmatchings/ccollisionmdt", CreateCollisionMDT__FPUiP9mgCMemory);
INCLUDE_ASM("nonmatchings/ccollisionmdt", Draw__9CColFrameFPUiP14mgCDrawManager);
INCLUDE_ASM("nonmatchings/ccollisionmdt", Draw__9CColFrameFP14mgCDrawManager);
INCLUDE_ASM("nonmatchings/ccollisionmdt", Initialize__13CCollisionMDTFv);
INCLUDE_ASM("nonmatchings/ccollisionmdt", Copy__10CCollisionFR10CCollisionP9mgCMemory);
INCLUDE_ASM("nonmatchings/ccollisionmdt", CreateBBox__10CCollisionFv);
INCLUDE_ASM("nonmatchings/ccollisionmdt", GetMaxY__10CCollisionFPf);
INCLUDE_ASM("nonmatchings/ccollisionmdt", Initialize__10CCollisionFv);
INCLUDE_ASM("nonmatchings/ccollisionmdt", size_to_sector__Fi);
INCLUDE_ASM("nonmatchings/ccollisionmdt", GetMainFileDev__Fv);
INCLUDE_ASM("nonmatchings/ccollisionmdt", ChangeHddFile__Fv);
INCLUDE_ASM("nonmatchings/ccollisionmdt", ChangeDefaultFile__Fv);
INCLUDE_ASM("nonmatchings/ccollisionmdt", SetIoErrCallBack__FPFi_i);
INCLUDE_ASM("nonmatchings/ccollisionmdt", SetCurrentDir__FPc);
INCLUDE_ASM("nonmatchings/ccollisionmdt", GetCurrentDir__FPc);
INCLUDE_ASM("nonmatchings/ccollisionmdt", ChangeDir__FPc);
INCLUDE_ASM("nonmatchings/ccollisionmdt", SearchFile__FPc);
INCLUDE_ASM("nonmatchings/ccollisionmdt", InitReadBG__Fv);
INCLUDE_ASM("nonmatchings/ccollisionmdt", LoadFileBG__FPcP1Pi);
INCLUDE_ASM("nonmatchings/ccollisionmdt", GetReadBGFile__FPc);
INCLUDE_ASM("nonmatchings/ccollisionmdt", GetReadBGFile__Fi);
INCLUDE_ASM("nonmatchings/ccollisionmdt", StartReadBG__Fv);
INCLUDE_ASM("nonmatchings/ccollisionmdt", ReadBG__Fv);
INCLUDE_ASM("nonmatchings/ccollisionmdt", ReadBGSync__Fv);
INCLUDE_ASM("nonmatchings/ccollisionmdt", BreakReadBG__Fv);
INCLUDE_ASM("nonmatchings/ccollisionmdt", InitCDFile__Fv);
INCLUDE_ASM("nonmatchings/ccollisionmdt", GetDevType__FPcPc);
INCLUDE_ASM("nonmatchings/ccollisionmdt", ConvStr__FPc);
INCLUDE_ASM("nonmatchings/ccollisionmdt", GetFullPath__FPcPc);
INCLUDE_ASM("nonmatchings/ccollisionmdt", LoadFile__FPcPvPi);
INCLUDE_ASM("nonmatchings/ccollisionmdt", LoadFile2__FPcPvPii);
INCLUDE_ASM("nonmatchings/ccollisionmdt", CDRead__FPcPUiPi);
INCLUDE_ASM("nonmatchings/ccollisionmdt", align_size__FUiUi);
INCLUDE_ASM("nonmatchings/ccollisionmdt", GetNewFileCache__Fv);
INCLUDE_ASM("nonmatchings/ccollisionmdt", InitFileCache__FP1i);
INCLUDE_ASM("nonmatchings/ccollisionmdt", DeleteFileCache__Fv);
INCLUDE_ASM("nonmatchings/ccollisionmdt", EntryFileCache__FPcP1i);
INCLUDE_ASM("nonmatchings/ccollisionmdt", LoadFileCacheBG__FPc);
INCLUDE_ASM("nonmatchings/ccollisionmdt", SearchFileCache__FPc);
INCLUDE_ASM("nonmatchings/ccollisionmdt", SearchFileCache__FPcPi);
INCLUDE_ASM("nonmatchings/ccollisionmdt", WriteFile__FPcPvi);
INCLUDE_ASM("nonmatchings/ccollisionmdt", GetPackFile__FPUiPcPi);
INCLUDE_ASM("nonmatchings/ccollisionmdt", GetPackFile__FPUiiPPcPi);
INCLUDE_ASM("nonmatchings/ccollisionmdt", GetPackFileExt__FPUiPcPPUiiPiPPc);
INCLUDE_ASM("nonmatchings/ccollisionmdt", GetPackFileNum__FPUi);
INCLUDE_ASM("nonmatchings/ccollisionmdt", DivPathName__FPcPcPc);
INCLUDE_ASM("nonmatchings/ccollisionmdt", DivPathNameExt__FPcPcPcPc);
