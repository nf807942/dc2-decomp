/* 0x0012C2C0 .. 0x00131560 — à décrire.
 *
 * Unité ouverte par `make open` : 103 fonctions, 20428 octets, de
 * 0x0012C2C0 à 0x00131560. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

INCLUDE_ASM("nonmatchings/mglib/mgmath", GetZBufVram__FPi);
INCLUDE_ASM("nonmatchings/mglib/mgmath", CheckCopyToZBufVram__FP10mgCTexturePi);
INCLUDE_ASM("nonmatchings/mglib/mgmath", __ct__10mgCTextureFv);
INCLUDE_ASM("nonmatchings/mglib/mgmath", Initialize__10mgCTextureFv);
INCLUDE_ASM("nonmatchings/mglib/mgmath", Bilinear__10mgCTextureFi);
INCLUDE_ASM("nonmatchings/mglib/mgmath", __ct__15mgCTextureBlockFv);
INCLUDE_ASM("nonmatchings/mglib/mgmath", Initialize__15mgCTextureBlockFv);
INCLUDE_ASM("nonmatchings/mglib/mgmath", Add__15mgCTextureBlockFP10mgCTexture);
INCLUDE_ASM("nonmatchings/mglib/mgmath", Delete__15mgCTextureBlockFP10mgCTexture);
INCLUDE_ASM("nonmatchings/mglib/mgmath", __ct__17mgCTextureManagerFv);
INCLUDE_ASM("nonmatchings/mglib/mgmath", SetTableBuffer__17mgCTextureManagerFiiP9mgCMemory);
INCLUDE_ASM("nonmatchings/mglib/mgmath", Initialize__17mgCTextureManagerFii);
INCLUDE_ASM("nonmatchings/mglib/mgmath", hash__17mgCTextureManagerFPc);
INCLUDE_ASM("nonmatchings/mglib/mgmath", AddHash__17mgCTextureManagerFP10mgCTexture);
INCLUDE_ASM("nonmatchings/mglib/mgmath", DelHash__17mgCTextureManagerFP10mgCTexture);
INCLUDE_ASM("nonmatchings/mglib/mgmath", SearchHash__17mgCTextureManagerFPci);
INCLUDE_ASM("nonmatchings/mglib/mgmath", SearchTextureName__17mgCTextureManagerFPci);
INCLUDE_ASM("nonmatchings/mglib/mgmath", SearchTexture__17mgCTextureManagerFPc);
INCLUDE_ASM("nonmatchings/mglib/mgmath", GetTexture__17mgCTextureManagerFPci);
INCLUDE_ASM("nonmatchings/mglib/mgmath", GetTextureBlock__17mgCTextureManagerFi);
INCLUDE_ASM("nonmatchings/mglib/mgmath", GetRemainVRAM__17mgCTextureManagerFi);
INCLUDE_ASM("nonmatchings/mglib/mgmath", EnterTexture__17mgCTextureManagerFiPcPP1iiiP1Uli);
INCLUDE_ASM("nonmatchings/mglib/mgmath", EnterTexture__17mgCTextureManagerFiPcP8TM2_headii);
INCLUDE_ASM("nonmatchings/mglib/mgmath", EnterIMGFile__17mgCTextureManagerFPUciP9mgCMemoryP15mgCEnterIMGInfo);
INCLUDE_ASM("nonmatchings/mglib/mgmath", GetIMGVersion__FPc);
INCLUDE_ASM("nonmatchings/mglib/mgmath", mgGetIMGHeaderNum__FPc);
INCLUDE_ASM("nonmatchings/mglib/mgmath", mgGetIMGHeader__FPci);
INCLUDE_ASM("nonmatchings/mglib/mgmath", DeleteTexture__17mgCTextureManagerFP10mgCTexture);
INCLUDE_ASM("nonmatchings/mglib/mgmath", DeleteTexture__17mgCTextureManagerFPci);
INCLUDE_ASM("nonmatchings/mglib/mgmath", DeleteBlock__17mgCTextureManagerFi);
INCLUDE_ASM("nonmatchings/mglib/mgmath", EndEnterTexture__17mgCTextureManagerFi);
INCLUDE_ASM("nonmatchings/mglib/mgmath", mgLoadImage__FPUiiiiP1iiiii);
INCLUDE_ASM("nonmatchings/mglib/mgmath", SetTexFlush_TagCnt__FPUi);
INCLUDE_ASM("nonmatchings/mglib/mgmath", ReloadTexture__17mgCTextureManagerFiP13sceVif1Packet);
INCLUDE_ASM("nonmatchings/mglib/mgmath", ReloadTexture__17mgCTextureManagerFiPUi);
INCLUDE_ASM("nonmatchings/mglib/mgmath", __as__9sceGsTex0FRC9sceGsTex0);
INCLUDE_ASM("nonmatchings/mglib/mgmath", ReloadCLUT__17mgCTextureManagerFP10mgCTexturePUi);
INCLUDE_ASM("nonmatchings/mglib/mgmath", ReloadCLUT__17mgCTextureManagerFP10mgCTextureP13sceVif1Packet);
INCLUDE_ASM("nonmatchings/mglib/mgmath", TexAnimeOn__17mgCTextureManagerFiPc);
INCLUDE_ASM("nonmatchings/mglib/mgmath", TexAnimeOff__17mgCTextureManagerFiPc);
INCLUDE_ASM("nonmatchings/mglib/mgmath", TexAnimeAllOff__17mgCTextureManagerFi);
INCLUDE_ASM("nonmatchings/mglib/mgmath", GetGroupNameList__17mgCTextureManagerFiPi);
INCLUDE_ASM("nonmatchings/mglib/mgmath", DeleteTexAnimeGroup__17mgCTextureManagerFii);
INCLUDE_ASM("nonmatchings/mglib/mgmath", DeleteTexAnime__17mgCTextureManagerFi);
INCLUDE_ASM("nonmatchings/mglib/mgmath", GetTexAnime__17mgCTextureManagerFi);
INCLUDE_ASM("nonmatchings/mglib/mgmath", BlockConv32to8__FPUcPUc);
INCLUDE_ASM("nonmatchings/mglib/mgmath", PageConv32to8__FiiPUcPUc);
INCLUDE_ASM("nonmatchings/mglib/mgmath", Conv32To8__FiiPUc);
INCLUDE_ASM("nonmatchings/mglib/mgmath", mgFotI4__FPiPf);
INCLUDE_ASM("nonmatchings/mglib/mgmath", mgCreateBox8__FPA4_fPfPf);
INCLUDE_ASM("nonmatchings/mglib/mgmath", mgZeroVector__FPf);
INCLUDE_ASM("nonmatchings/mglib/mgmath", mgZeroVectorW__FPf);
INCLUDE_ASM("nonmatchings/mglib/mgmath", mgClipBoxVertex__FPfPfPf);
INCLUDE_ASM("nonmatchings/mglib/mgmath", mgClipBox__FPfPfPfPf);
INCLUDE_ASM("nonmatchings/mglib/mgmath", mgClipBoxW__FPfPfPfPf);
INCLUDE_ASM("nonmatchings/mglib/mgmath", mgClipInBox__FPfPfPfPf);
INCLUDE_ASM("nonmatchings/mglib/mgmath", mgClipInBoxW__FPfPfPfPf);
INCLUDE_ASM("nonmatchings/mglib/mgmath", mgAddVector__FPfPf);
INCLUDE_ASM("nonmatchings/mglib/mgmath", mgSubVector__FPfPf);
INCLUDE_ASM("nonmatchings/mglib/mgmath", mgNormalizeVector__FPfPff);
INCLUDE_ASM("nonmatchings/mglib/mgmath", mgVectorMin__FPfPfPf);
INCLUDE_ASM("nonmatchings/mglib/mgmath", mgVectorMin__FPfPfPfPfPf);
INCLUDE_ASM("nonmatchings/mglib/mgmath", mgVectorMaxMin__FPfPfPfPf);
INCLUDE_ASM("nonmatchings/mglib/mgmath", mgVectorMaxMin__FPfPfPfPfPf);
INCLUDE_ASM("nonmatchings/mglib/mgmath", mgVectorMaxMin__FPfPfPfPfPfPf);
INCLUDE_ASM("nonmatchings/mglib/mgmath", mgBoxMaxMin__FP9mgVu0FBOXP9mgVu0FBOX);
INCLUDE_ASM("nonmatchings/mglib/mgmath", mgPlaneNormal__FPfPfPfPf);
INCLUDE_ASM("nonmatchings/mglib/mgmath", mgDistPlanePoint__FPfPfPf);
INCLUDE_ASM("nonmatchings/mglib/mgmath", mgDistLinePoint__FPfPfPfPf);
INCLUDE_ASM("nonmatchings/mglib/mgmath", mgReflectionPlane__FPfPfPfPf);
INCLUDE_ASM("nonmatchings/mglib/mgmath", mgIntersectionSphereLine0__FfPfPfPA4_f);
INCLUDE_ASM("nonmatchings/mglib/mgmath", mgIntersectionSphereLine__FPfPfPfPA4_f);
INCLUDE_ASM("nonmatchings/mglib/mgmath", mgIntersectionPoint_line_poly3__FPfPfPfPfPfPfPf);
INCLUDE_ASM("nonmatchings/mglib/mgmath", mgCheckPointPoly3_XYZ__FPfPfPfPfPf);
INCLUDE_ASM("nonmatchings/mglib/mgmath", mgCheckPointPoly3_XZ__FPfPfPfPf);
INCLUDE_ASM("nonmatchings/mglib/mgmath", Check_Point_Poly3__Fffffffff);
INCLUDE_ASM("nonmatchings/mglib/mgmath", mgDistVector__FPf);
INCLUDE_ASM("nonmatchings/mglib/mgmath", mgDistVectorXZ__FPf);
INCLUDE_ASM("nonmatchings/mglib/mgmath", mgDistVector2__FPf);
INCLUDE_ASM("nonmatchings/mglib/mgmath", mgDistVector__FPfPf);
INCLUDE_ASM("nonmatchings/mglib/mgmath", mgDistVectorXZ__FPfPf);
INCLUDE_ASM("nonmatchings/mglib/mgmath", mgDistVector2__FPfPf);
INCLUDE_ASM("nonmatchings/mglib/mgmath", mgDistVectorXZ2__FPfPf);
INCLUDE_ASM("nonmatchings/mglib/mgmath", mgUnitMatrix__FPA4_f);
INCLUDE_ASM("nonmatchings/mglib/mgmath", mgZeroMatrix__FPA4_f);
INCLUDE_ASM("nonmatchings/mglib/mgmath", MulMatrix3__FPA4_fPA4_fPA4_f);
INCLUDE_ASM("nonmatchings/mglib/mgmath", mgMulMatrix__FPA4_fPA4_fPA4_f);
INCLUDE_ASM("nonmatchings/mglib/mgmath", mgInversMatrix__FPA4_fPA4_f);
INCLUDE_ASM("nonmatchings/mglib/mgmath", mgRotMatrixX__FPA4_ff);
INCLUDE_ASM("nonmatchings/mglib/mgmath", mgRotMatrixY__FPA4_ff);
INCLUDE_ASM("nonmatchings/mglib/mgmath", mgRotMatrixZ__FPA4_ff);
INCLUDE_ASM("nonmatchings/mglib/mgmath", mgRotMatrixXYZ__FPA4_fPf);
INCLUDE_ASM("nonmatchings/mglib/mgmath", mgCreateMatrixPY__FPA4_fPff);
INCLUDE_ASM("nonmatchings/mglib/mgmath", mgLookAtMatrixZ__FPA4_fPf);
INCLUDE_ASM("nonmatchings/mglib/mgmath", mgShadowMatrix__FPA4_fPfPfPf);
INCLUDE_ASM("nonmatchings/mglib/mgmath", mgApplyMatrixN__FPA4_fPA4_fPA4_fi);
INCLUDE_ASM("nonmatchings/mglib/mgmath", mgApplyMatrixN_MaxMin__FPA4_fPA4_fPA4_fiPfPf);
INCLUDE_ASM("nonmatchings/mglib/mgmath", mgVectorMinMaxN__FPfPfPA4_fi);
INCLUDE_ASM("nonmatchings/mglib/mgmath", mgApplyMatrix__FPfPfPA4_fPfPf);
INCLUDE_ASM("nonmatchings/mglib/mgmath", mgVectorInterpolate__FPfPfPffi);
INCLUDE_ASM("nonmatchings/mglib/mgmath", mgAngleInterpolate__Ffffi);
extern "C" s32 mgAngleCmp__Ffff(f32 arg0, f32 arg1, f32 arg2) {
    f32 var_f1;
    s32 var_v0;

    var_f1 = arg0 - arg1;
    if (var_f1 == 0.0f) {
        return 0;
    }
    if (!(var_f1 <= 3.1415927f)) {
        var_f1 -= 6.2831855f;
    }
    if (var_f1 < -3.1415927f) {
        var_f1 += 6.2831855f;
    }
    if (!(var_f1 <= arg2)) {
        return 1;
    }
    var_v0 = 0;
    if (!(var_f1 < -arg2)) {
        return var_v0;
    }
    var_v0 = -1;

    return var_v0;
}
INCLUDE_ASM("nonmatchings/mglib/mgmath", mgAngleLimit__Ff);
