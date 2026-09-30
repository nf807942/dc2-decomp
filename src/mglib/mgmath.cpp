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
extern "C" void Initialize__10mgCTextureFv(void *);
struct mgCTexture;
#pragma schedule off
extern "C" mgCTexture *__ct__10mgCTextureFv(mgCTexture *objet) {
    Initialize__10mgCTextureFv(objet);
    return objet;
}
#pragma schedule reset
INCLUDE_ASM("nonmatchings/mglib/mgmath", Initialize__10mgCTextureFv);
INCLUDE_ASM("nonmatchings/mglib/mgmath", Bilinear__10mgCTextureFi);
struct mgCTextureBlock;
extern "C" void Initialize__15mgCTextureBlockFv(u32 *objet);
#pragma schedule off
extern "C" mgCTextureBlock *__ct__15mgCTextureBlockFv(mgCTextureBlock *objet) {
    Initialize__15mgCTextureBlockFv((u32 *) objet);
    return objet;
}
#pragma schedule reset
#pragma schedule off
extern "C" void Initialize__15mgCTextureBlockFv(u32 *objet) {
    objet[1] = 0;
    objet[0] = 0;
    objet[3] = 0;
    objet[2] = 0;
}
#pragma schedule reset
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
struct sceGsTex0_a { u64 v; };
#pragma schedule off
extern "C" sceGsTex0_a *__as__9sceGsTex0FRC9sceGsTex0(sceGsTex0_a *arg0, const sceGsTex0_a *arg1) {
    arg0->v = arg1->v;
    return arg0;
}
#pragma schedule reset
INCLUDE_ASM("nonmatchings/mglib/mgmath", ReloadCLUT__17mgCTextureManagerFP10mgCTexturePUi);
INCLUDE_ASM("nonmatchings/mglib/mgmath", ReloadCLUT__17mgCTextureManagerFP10mgCTextureP13sceVif1Packet);
INCLUDE_ASM("nonmatchings/mglib/mgmath", TexAnimeOn__17mgCTextureManagerFiPc);
INCLUDE_ASM("nonmatchings/mglib/mgmath", TexAnimeOff__17mgCTextureManagerFiPc);
struct mgTexBlockView {
    char pad0[0xC];
    void *anime;
};
extern "C" mgTexBlockView *GetTextureBlock__17mgCTextureManagerFi(...);
extern "C" s32 DisableAll__15mgCTextureAnimeFv(...);
#pragma schedule off
extern "C" void TexAnimeAllOff__17mgCTextureManagerFi(void *manager, s32 index) {
    mgTexBlockView *block = GetTextureBlock__17mgCTextureManagerFi(manager, index);
    if (block != NULL) {
        void *anime = block->anime;
        if (anime != NULL) {
            DisableAll__15mgCTextureAnimeFv(anime);
        }
    }
}
INCLUDE_ASM("nonmatchings/mglib/mgmath", GetGroupNameList__17mgCTextureManagerFiPi);
INCLUDE_ASM("nonmatchings/mglib/mgmath", DeleteTexAnimeGroup__17mgCTextureManagerFii);
extern "C" void DeleteTexAnime__17mgCTextureManagerFi(void *manager, s32 index) {
    mgTexBlockView *block = GetTextureBlock__17mgCTextureManagerFi(manager, index);
    if (block != NULL) {
        block->anime = NULL;
    }
}
#pragma schedule reset
INCLUDE_ASM("nonmatchings/mglib/mgmath", GetTexAnime__17mgCTextureManagerFi);
INCLUDE_ASM("nonmatchings/mglib/mgmath", BlockConv32to8__FPUcPUc);
INCLUDE_ASM("nonmatchings/mglib/mgmath", PageConv32to8__FiiPUcPUc);
INCLUDE_ASM("nonmatchings/mglib/mgmath", Conv32To8__FiiPUc);
extern "C" void mgFotI4__FPiPf(s32 *dst, float *src) {
    asm {
        lqc2 vf1, 0(src)
        vftoi4.xyzw vf1, vf1
        sqc2 vf1, 0(dst)
    }
}
INCLUDE_ASM("nonmatchings/mglib/mgmath", mgCreateBox8__FPA4_fPfPf);
extern "C" void mgZeroVector__FPf(u128 *arg0) {
    *arg0 = 0;
}
extern "C" void mgZeroVectorW__FPf(float *v) {
    asm {
        sqc2 vf0, 0(v)
    }
}
INCLUDE_ASM("nonmatchings/mglib/mgmath", mgClipBoxVertex__FPfPfPf);
INCLUDE_ASM("nonmatchings/mglib/mgmath", mgClipBox__FPfPfPfPf);
INCLUDE_ASM("nonmatchings/mglib/mgmath", mgClipBoxW__FPfPfPfPf);
INCLUDE_ASM("nonmatchings/mglib/mgmath", mgClipInBox__FPfPfPfPf);
INCLUDE_ASM("nonmatchings/mglib/mgmath", mgClipInBoxW__FPfPfPfPf);
extern "C" void mgAddVector__FPfPf(float *a, float *b) {
    asm {
        lqc2 vf15, 0(a)
        lqc2 vf16, 0(b)
        vadd.xyzw vf15, vf15, vf16
        sqc2 vf15, 0(a)
    }
}
extern "C" void mgSubVector__FPfPf(float *a, float *b) {
    asm {
        lqc2 vf15, 0(a)
        lqc2 vf16, 0(b)
        vsub.xyzw vf15, vf15, vf16
        sqc2 vf15, 0(a)
    }
}
INCLUDE_ASM("nonmatchings/mglib/mgmath", mgNormalizeVector__FPfPff);
extern "C" void mgVectorMin__FPfPfPf(float *d, float *a, float *b) {
    asm {
        lqc2 vf15, 0(a)
        lqc2 vf16, 0(b)
        vmini.xyzw vf18, vf15, vf16
        sqc2 vf18, 0(d)
    }
}
extern "C" void mgVectorMin__FPfPfPfPfPf(f32 *out, f32 *a, f32 *b, f32 *c, f32 *d) {
    asm {
        lqc2 vf15, 0(a)
        lqc2 vf16, 0(b)
        lqc2 vf17, 0(c)
        lqc2 vf18, 0(d)
        vmini.xyzw vf20, vf15, vf16
        vmini.xyzw vf20, vf20, vf17
        vmini.xyzw vf20, vf20, vf18
        sqc2 vf20, 0(out)
    }
}
extern "C" void mgVectorMaxMin__FPfPfPfPf(float *mx, float *mn, float *a, float *b) {
    asm {
        lqc2 vf15, 0(a)
        lqc2 vf16, 0(b)
        vmax.xyzw vf18, vf15, vf16
        vmini.xyzw vf20, vf15, vf16
        sqc2 vf18, 0(mx)
        sqc2 vf20, 0(mn)
    }
}
extern "C" void mgVectorMaxMin__FPfPfPfPfPf(f32 *mx, f32 *mn, f32 *a, f32 *b, f32 *c) {
    asm {
        lqc2 vf15, 0(a)
        lqc2 vf16, 0(b)
        lqc2 vf17, 0(c)
        vmax.xyzw vf18, vf15, vf16
        vmini.xyzw vf20, vf15, vf16
        vmax.xyzw vf19, vf18, vf17
        vmini.xyzw vf21, vf20, vf17
        sqc2 vf19, 0(mx)
        sqc2 vf21, 0(mn)
    }
}
INCLUDE_ASM("nonmatchings/mglib/mgmath", mgVectorMaxMin__FPfPfPfPfPfPf);
INCLUDE_ASM("nonmatchings/mglib/mgmath", mgBoxMaxMin__FP9mgVu0FBOXP9mgVu0FBOX);
extern "C" void mgPlaneNormal__FPfPfPfPf(f32 *out, f32 *a, f32 *b, f32 *c) {
    asm {
        lqc2 vf15, 0(a)
        lqc2 vf16, 0(b)
        lqc2 vf17, 0(c)
        vsub.xyzw vf10, vf16, vf15
        vsub.xyzw vf11, vf17, vf15
        vopmula.xyz ACC, vf10, vf11
        vopmsub.xyz vf12, vf11, vf10
        sqc2 vf12, 0(out)
    }
}
extern "C" f32 sceVu0InnerProduct(...);
extern "C" s32 sceVu0SubVector(...);
extern "C" void mgDistPlanePoint__FPfPfPf(f32 *arg0, f32 *arg1, f32 *arg2) {
    s32 sp20[4];
    sceVu0SubVector(&sp20[0], arg2, arg1);
    sceVu0InnerProduct(arg0, &sp20[0]);
}
INCLUDE_ASM("nonmatchings/mglib/mgmath", mgDistLinePoint__FPfPfPfPf);
INCLUDE_ASM("nonmatchings/mglib/mgmath", mgReflectionPlane__FPfPfPfPf);
INCLUDE_ASM("nonmatchings/mglib/mgmath", mgIntersectionSphereLine0__FfPfPfPA4_f);
extern "C" s32 mgIntersectionSphereLine0__FfPfPfPA4_f(f32, f32 *, f32 *, f32 (*)[4]);
extern "C" s32 mgIntersectionSphereLine__FPfPfPfPA4_f(f32 *arg0, f32 *arg1, f32 *arg2, f32 (*arg3)[4]) {
    f32 sp70[4];
    f32 sp80[4];
    f32 radius;
    s32 n;
    s32 i;

    radius = arg0[3];
    sceVu0SubVector(sp70, arg1, arg0);
    sceVu0SubVector(sp80, arg2, arg0);
    n = mgIntersectionSphereLine0__FfPfPfPA4_f(radius, sp70, sp80, arg3);
    for (i = 0; i < n; i++) {
        mgAddVector__FPfPf(arg3[i], arg0);
    }
    return n;
}
extern "C" s32 sceVu0AddVector(...);
extern "C" void sceVu0ScaleVector(f32 *, f32 *, f32);
extern "C" s32 mgCheckPointPoly3_XYZ__FPfPfPfPfPf(f32 *, f32 *, f32 *, f32 *, f32 *);
extern "C" s32 mgIntersectionPoint_line_poly3__FPfPfPfPfPfPfPf(f32 *arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4, f32 *arg5, f32 *arg6) {
    f32 sp80[4];
    f32 sp90[4];
    f32 spA0[4];
    f32 spB0[4];
    f32 temp_f0;
    f32 temp_f20;

    sceVu0SubVector(sp80, arg1, arg0);
    sceVu0SubVector(sp90, arg2, arg0);
    sceVu0SubVector(spA0, arg3, arg0);
    sceVu0SubVector(spB0, arg4, arg0);
    temp_f20 = -sceVu0InnerProduct(arg5, sp90);
    temp_f0 = sceVu0InnerProduct(arg5, sp80);
    if (temp_f0 == 0.0f) {
        return 0;
    }
    sceVu0ScaleVector(arg6, sp80, -temp_f20 / temp_f0);
    sceVu0AddVector(arg6, arg6, arg0);
    return mgCheckPointPoly3_XYZ__FPfPfPfPfPf(arg6, arg2, arg3, arg4, arg5);
}
extern "C" s32 sceVu0OuterProduct(...);
extern "C" s32 mgCheckPointPoly3_XYZ__FPfPfPfPfPf(f32 *arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4) {
    s32 sp70[4];
    s32 sp80[4];
    s32 sp90[4];
    s32 spA0[4];
    s32 spB0[4];
    s32 spC0[4];
    s32 spD0[4];
    s32 spE0[4];
    s32 spF0[4];
    f32 temp_f0;
    f32 temp_f20;
    f32 temp_f21;

    sceVu0SubVector(sp70, arg0, arg1);
    sceVu0SubVector(sp80, arg0, arg2);
    sceVu0SubVector(sp90, arg0, arg3);
    sceVu0SubVector(spA0, arg2, arg1);
    sceVu0SubVector(spB0, arg3, arg2);
    sceVu0SubVector(spC0, arg1, arg3);
    sceVu0OuterProduct(spD0, spA0, sp70);
    sceVu0OuterProduct(spE0, spB0, sp80);
    sceVu0OuterProduct(spF0, spC0, sp90);
    temp_f20 = sceVu0InnerProduct(spD0, arg4);
    temp_f21 = sceVu0InnerProduct(spE0, arg4);
    temp_f0 = sceVu0InnerProduct(spF0, arg4);
    if (!(temp_f20 < 0.0f) && !(temp_f21 < 0.0f) && !(temp_f0 < 0.0f)) {
        return 1;
    }
    if (temp_f20 <= 0.0f) {
        if (temp_f21 <= 0.0f) {
            if (temp_f0 <= 0.0f) {
                return 1;
            }
        }
    }
    return 0;
}
extern "C" s32 Check_Point_Poly3__Fffffffff(f32, f32, f32, f32, f32, f32, f32, f32);
extern "C" s32 mgCheckPointPoly3_XZ__FPfPfPfPf(f32 *a, f32 *b, f32 *c, f32 *d) {
    return Check_Point_Poly3__Fffffffff(a[0], a[2], b[0], b[2], c[0], c[2], d[0], d[2]);
}
extern "C" s32 Check_Point_Poly3__Fffffffff(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7) {
    f32 temp_f1;
    f32 temp_f4;
    f32 temp_f6;
    f32 var_f0;
    f32 var_f0_2;
    f32 var_f0_3;
    f32 var_f0_4;

    var_f0 = (arg2 < arg4) ? ((arg2 < arg6) ? arg2 : arg6) : ((arg4 < arg6) ? arg4 : arg6);
    if (!(var_f0 <= arg0)) {
        return 0;
    }
    var_f0_2 = (arg2 > arg4) ? ((arg2 > arg6) ? arg2 : arg6) : ((arg4 > arg6) ? arg4 : arg6);
    if (!(arg0 <= var_f0_2)) {
        return 0;
    }
    var_f0_3 = (arg3 < arg5) ? ((arg3 < arg7) ? arg3 : arg7) : ((arg5 < arg7) ? arg5 : arg7);
    if (!(var_f0_3 <= arg1)) {
        return 0;
    }
    var_f0_4 = (arg3 > arg5) ? ((arg3 > arg7) ? arg3 : arg7) : ((arg5 > arg7) ? arg5 : arg7);
    if (!(arg1 <= var_f0_4)) {
        return 0;
    }
    temp_f6 = ((arg4 - arg2) * (arg1 - arg3)) - ((arg5 - arg3) * (arg0 - arg2));
    temp_f4 = ((arg6 - arg4) * (arg1 - arg5)) - ((arg7 - arg5) * (arg0 - arg4));
    temp_f1 = ((arg2 - arg6) * (arg1 - arg7)) - ((arg3 - arg7) * (arg0 - arg6));
    if (temp_f6 == 0.0f) {
        return 2;
    }
    if (temp_f4 == 0.0f) {
        return 3;
    }
    if (temp_f1 == 0.0f) {
        return 4;
    }
    if (!(temp_f6 <= 0.0f) && !(temp_f4 <= 0.0f) && !(temp_f1 <= 0.0f)) {
        return 1;
    }
    if (temp_f6 < 0.0f) {
        if (temp_f4 < 0.0f) {
            if (temp_f1 < 0.0f) {
                return 1;
            }
        }
    }
    return 0;
}
INCLUDE_ASM("nonmatchings/mglib/mgmath", mgDistVector__FPf);
extern "C" f32 mgDistVectorXZ__FPf(f32 *v) {
    asm {
        lqc2 vf4, 0(v)
        vmul.xyz vf4, vf4, vf4
        vmr32.xy vf5, vf4
        vmr32.x vf6, vf5
        vadd.x vf7, vf4, vf6
        vsqrt Q, vf7x
        vwaitq
        cfc2.ni v0, vi22
        mtc1 v0, f0
        jr ra
        nop
        nop
    }
}
extern "C" f32 mgDistVector2__FPf(f32 *v) {
    asm {
        lqc2 vf4, 0(v)
        vmul.xyz vf4, vf4, vf4
        vmr32.xy vf5, vf4
        vmr32.x vf6, vf5
        vadd.x vf7, vf4, vf5
        vadd.x vf5, vf6, vf7
        qmfc2.ni v0, vf5
        mtc1 v0, f0
        jr ra
        nop
    }
}
INCLUDE_ASM("nonmatchings/mglib/mgmath", mgDistVector__FPfPf);
INCLUDE_ASM("nonmatchings/mglib/mgmath", mgDistVectorXZ__FPfPf);
INCLUDE_ASM("nonmatchings/mglib/mgmath", mgDistVector2__FPfPf);
extern "C" f32 mgDistVectorXZ2__FPfPf(f32 *a, f32 *b) {
    asm {
        lqc2 vf2, 0(a)
        lqc2 vf3, 0(b)
        vsub.xyz vf4, vf3, vf2
        vmul.xyz vf4, vf4, vf4
        vmr32.xy vf5, vf4
        vmr32.x vf6, vf5
        vadd.x vf7, vf4, vf6
        qmfc2.ni v0, vf7
        mtc1 v0, f0
        jr ra
        nop
        nop
    }
}
extern "C" void mgUnitMatrix__FPA4_f(f32 (*arg0)[4]) {
    asm {
        vmr32.xyzw vf1, vf0
        vmr32.xyzw vf2, vf1
        vmr32.xyzw vf3, vf2
        sqc2 vf0, 0x30(arg0)
        sqc2 vf1, 0x20(arg0)
        sqc2 vf2, 0x10(arg0)
        sqc2 vf3, 0x0(arg0)
    }
}
extern "C" void mgZeroMatrix__FPA4_f(float (*m)[4]) {
    asm {
        vsub.xyzw vf1, vf1, vf1
        sqc2 vf1, 0x30(m)
        sqc2 vf1, 0x20(m)
        sqc2 vf1, 0x10(m)
        sqc2 vf1, 0(m)
    }
}
INCLUDE_ASM("nonmatchings/mglib/mgmath", MulMatrix3__FPA4_fPA4_fPA4_f);
INCLUDE_ASM("nonmatchings/mglib/mgmath", mgMulMatrix__FPA4_fPA4_fPA4_f);
INCLUDE_ASM("nonmatchings/mglib/mgmath", mgInversMatrix__FPA4_fPA4_f);
INCLUDE_ASM("nonmatchings/mglib/mgmath", mgRotMatrixX__FPA4_ff);
INCLUDE_ASM("nonmatchings/mglib/mgmath", mgRotMatrixY__FPA4_ff);
INCLUDE_ASM("nonmatchings/mglib/mgmath", mgRotMatrixZ__FPA4_ff);
extern "C" void mgRotMatrixX__FPA4_ff(f32 (*)[4], f32);
extern "C" void mgRotMatrixY__FPA4_ff(f32 (*)[4], f32);
extern "C" void mgRotMatrixZ__FPA4_ff(f32 (*)[4], f32);
extern "C" void MulMatrix3__FPA4_fPA4_fPA4_f(f32 (*)[4], f32 (*)[4], f32 (*)[4]);
extern "C" void mgRotMatrixXYZ__FPA4_fPf(f32 (*arg0)[4], f32 *arg1) {
    f32 mx[4][4];
    f32 my[4][4];
    mgRotMatrixX__FPA4_ff(mx, arg1[0]);
    mgRotMatrixY__FPA4_ff(my, arg1[1]);
    mgRotMatrixZ__FPA4_ff(arg0, arg1[2]);
    MulMatrix3__FPA4_fPA4_fPA4_f(arg0, my, mx);
}
INCLUDE_ASM("nonmatchings/mglib/mgmath", mgCreateMatrixPY__FPA4_fPff);
INCLUDE_ASM("nonmatchings/mglib/mgmath", mgLookAtMatrixZ__FPA4_fPf);
INCLUDE_ASM("nonmatchings/mglib/mgmath", mgShadowMatrix__FPA4_fPfPfPf);
INCLUDE_ASM("nonmatchings/mglib/mgmath", mgApplyMatrixN__FPA4_fPA4_fPA4_fi);
INCLUDE_ASM("nonmatchings/mglib/mgmath", mgApplyMatrixN_MaxMin__FPA4_fPA4_fPA4_fiPfPf);
INCLUDE_ASM("nonmatchings/mglib/mgmath", mgVectorMinMaxN__FPfPfPA4_fi);
extern "C" s32 mgApplyMatrixN_MaxMin__FPA4_fPA4_fPA4_fiPfPf(...);
extern "C" s32 mgCreateBox8__FPA4_fPfPf(...);
extern "C" void mgApplyMatrix__FPfPfPA4_fPfPf(f32 *arg0, f32 *arg1, f32 (*arg2)[4], f32 *arg3, f32 *arg4) {
    u8 sp40[0x80];
    mgCreateBox8__FPA4_fPfPf((f32 (*)[4]) &sp40[0], arg3, arg4);
    mgApplyMatrixN_MaxMin__FPA4_fPA4_fPA4_fiPfPf((f32 (*)[4]) &sp40[0], arg2, (f32 (*)[4]) &sp40[0], 8, arg0, arg1);
}
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
extern "C" f32 mgAngleLimit__Ff(f32 x) {
    if (x < 3.1415927f && x > -3.1415927f) {
        return x;
    }
    x = x - 6.2831855f * (f32) (s32) (x / 6.2831855f);
    if (x > 3.1415927f) {
        x -= 6.2831855f;
    }
    if (x < -3.1415927f) {
        x += 6.2831855f;
    }
    return x;
}
