/* Fonctions libres — à décrire.
 *
 * Unité découpée par `make carve` : 42 fonctions, 3312 octets, de
 * 0x00106D00 à 0x00107A50. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

INCLUDE_ASM("nonmatchings/sdk/scevu0dropshadowmatrix", sceVu0ApplyMatrix);
INCLUDE_ASM("nonmatchings/sdk/scevu0dropshadowmatrix", sceVu0MulMatrix);
void sceVu0OuterProduct(float *d, float *a, float *b)
{
    __asm__ volatile (
        "lqc2 $vf4,0(%1)\n"
        "lqc2 $vf5,0(%2)\n"
        "vopmula.xyz ACC,vf4,vf5\n"
        "vopmsub.xyz vf6,vf5,vf4\n"
        "vsub.w $vf6,$vf6,$vf6\n"
        "sqc2 $vf6,0(%0)\n"
        : : "r"(d), "r"(a), "r"(b) : "memory");
}
INCLUDE_ASM("nonmatchings/sdk/scevu0dropshadowmatrix", sceVu0InnerProduct);
INCLUDE_ASM("nonmatchings/sdk/scevu0dropshadowmatrix", sceVu0Normalize);
INCLUDE_ASM("nonmatchings/sdk/scevu0dropshadowmatrix", sceVu0TransposeMatrix);
INCLUDE_ASM("nonmatchings/sdk/scevu0dropshadowmatrix", sceVu0InversMatrix);
INCLUDE_ASM("nonmatchings/sdk/scevu0dropshadowmatrix", sceVu0DivVector);
INCLUDE_ASM("nonmatchings/sdk/scevu0dropshadowmatrix", sceVu0DivVectorXYZ);
INCLUDE_ASM("nonmatchings/sdk/scevu0dropshadowmatrix", sceVu0InterVector);
void sceVu0AddVector(float *d, float *a, float *b)
{
    __asm__ volatile (
        "lqc2 $vf4,0(%1)\n"
        "lqc2 $vf5,0(%2)\n"
        "vadd.xyzw $vf6,$vf4,$vf5\n"
        "sqc2 $vf6,0(%0)\n"
        : : "r"(d), "r"(a), "r"(b) : "memory");
}
void sceVu0SubVector(float *d, float *a, float *b)
{
    __asm__ volatile (
        "lqc2 $vf4,0(%1)\n"
        "lqc2 $vf5,0(%2)\n"
        "vsub.xyzw $vf6,$vf4,$vf5\n"
        "sqc2 $vf6,0(%0)\n"
        : : "r"(d), "r"(a), "r"(b) : "memory");
}
void sceVu0MulVector(float *d, float *a, float *b)
{
    __asm__ volatile (
        "lqc2 $vf4,0(%1)\n"
        "lqc2 $vf5,0(%2)\n"
        "vmul.xyzw $vf6,$vf4,$vf5\n"
        "sqc2 $vf6,0(%0)\n"
        : : "r"(d), "r"(a), "r"(b) : "memory");
}
void sceVu0ScaleVector(float *d, float *a, float x)
{
    __asm__ volatile (
        "lqc2 $vf4,0(%1)\n"
        "mfc1 $8,%2\n"
        "qmtc2.ni $8,$vf5\n"
        "vmulx.xyzw $vf6,$vf4,$vf5x\n"
        "sqc2 $vf6,0(%0)\n"
        : : "r"(d), "r"(a), "f"(x) : "$8","memory");
}
INCLUDE_ASM("nonmatchings/sdk/scevu0dropshadowmatrix", sceVu0TransMatrix);
typedef int u128_cv __attribute__((mode(TI)));
void sceVu0CopyVector(u128_cv *d, u128_cv *s)
{
    register u128_cv t __asm__("$6");
    t = *s;
    *d = t;
}
INCLUDE_ASM("nonmatchings/sdk/scevu0dropshadowmatrix", sceVu0CopyMatrix);
void sceVu0FTOI4Vector(float *d, float *a)
{
    __asm__ volatile (
        "lqc2 $vf4,0(%1)\n"
        "vftoi4.xyzw $vf5,$vf4\n"
        "sqc2 $vf5,0(%0)\n"
        : : "r"(d), "r"(a) : "memory");
}
void sceVu0FTOI0Vector(float *d, float *a)
{
    __asm__ volatile (
        "lqc2 $vf4,0(%1)\n"
        "vftoi0.xyzw $vf5,$vf4\n"
        "sqc2 $vf5,0(%0)\n"
        : : "r"(d), "r"(a) : "memory");
}
void sceVu0ITOF4Vector(float *d, float *a)
{
    __asm__ volatile (
        "lqc2 $vf4,0(%1)\n"
        "vitof4.xyzw $vf5,$vf4\n"
        "sqc2 $vf5,0(%0)\n"
        : : "r"(d), "r"(a) : "memory");
}
void sceVu0ITOF0Vector(float *d, float *a)
{
    __asm__ volatile (
        "lqc2 $vf4,0(%1)\n"
        "vitof0.xyzw $vf5,$vf4\n"
        "sqc2 $vf5,0(%0)\n"
        : : "r"(d), "r"(a) : "memory");
}
INCLUDE_ASM("nonmatchings/sdk/scevu0dropshadowmatrix", sceVu0UnitMatrix);
INCLUDE_ASM("nonmatchings/sdk/scevu0dropshadowmatrix", _sceVu0ecossin);
INCLUDE_ASM("nonmatchings/sdk/scevu0dropshadowmatrix", sceVu0RotMatrixZ);
INCLUDE_ASM("nonmatchings/sdk/scevu0dropshadowmatrix", sceVu0RotMatrixX);
INCLUDE_ASM("nonmatchings/sdk/scevu0dropshadowmatrix", sceVu0RotMatrixY);
INCLUDE_ASM("nonmatchings/sdk/scevu0dropshadowmatrix", sceVu0RotMatrix);
INCLUDE_ASM("nonmatchings/sdk/scevu0dropshadowmatrix", sceVu0ClampVector);
INCLUDE_ASM("nonmatchings/sdk/scevu0dropshadowmatrix", sceVu0CameraMatrix);
INCLUDE_ASM("nonmatchings/sdk/scevu0dropshadowmatrix", sceVu0NormalLightMatrix);
INCLUDE_ASM("nonmatchings/sdk/scevu0dropshadowmatrix", sceVu0LightColorMatrix);
INCLUDE_ASM("nonmatchings/sdk/scevu0dropshadowmatrix", sceVu0ViewScreenMatrix);
INCLUDE_ASM("nonmatchings/sdk/scevu0dropshadowmatrix", sceVu0DropShadowMatrix);
INCLUDE_ASM("nonmatchings/sdk/scevu0dropshadowmatrix", sceVu0RotTransPersN);
INCLUDE_ASM("nonmatchings/sdk/scevu0dropshadowmatrix", sceVu0RotTransPers);
void sceVu0CopyVectorXYZ(float *d, float *s)
{
    d[0] = s[0];
    d[1] = s[1];
    d[2] = s[2];
}
INCLUDE_ASM("nonmatchings/sdk/scevu0dropshadowmatrix", sceVu0InterVectorXYZ);
void sceVu0ScaleVectorXYZ(float *d, float *a, float x)
{
    __asm__ volatile (
        "lqc2 $vf4,0(%1)\n"
        "mfc1 $8,%2\n"
        "qmtc2.ni $8,$vf5\n"
        "vmulx.xyz $vf4,$vf4,$vf5x\n"
        "sqc2 $vf4,0(%0)\n"
        : : "r"(d), "r"(a), "f"(x) : "$8","memory");
}
INCLUDE_ASM("nonmatchings/sdk/scevu0dropshadowmatrix", sceVu0ClipScreen);
INCLUDE_ASM("nonmatchings/sdk/scevu0dropshadowmatrix", sceVu0ClipScreen3);
INCLUDE_ASM("nonmatchings/sdk/scevu0dropshadowmatrix", sceVu0ClipAll);
INCLUDE_ASM("nonmatchings/sdk/scevu0dropshadowmatrix", sceVpu0Reset);
