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
INCLUDE_ASM("nonmatchings/sdk/scevu0dropshadowmatrix", sceVu0OuterProduct);
INCLUDE_ASM("nonmatchings/sdk/scevu0dropshadowmatrix", sceVu0InnerProduct);
INCLUDE_ASM("nonmatchings/sdk/scevu0dropshadowmatrix", sceVu0Normalize);
INCLUDE_ASM("nonmatchings/sdk/scevu0dropshadowmatrix", sceVu0TransposeMatrix);
INCLUDE_ASM("nonmatchings/sdk/scevu0dropshadowmatrix", sceVu0InversMatrix);
INCLUDE_ASM("nonmatchings/sdk/scevu0dropshadowmatrix", sceVu0DivVector);
INCLUDE_ASM("nonmatchings/sdk/scevu0dropshadowmatrix", sceVu0DivVectorXYZ);
INCLUDE_ASM("nonmatchings/sdk/scevu0dropshadowmatrix", sceVu0InterVector);
INCLUDE_ASM("nonmatchings/sdk/scevu0dropshadowmatrix", sceVu0AddVector);
INCLUDE_ASM("nonmatchings/sdk/scevu0dropshadowmatrix", sceVu0SubVector);
INCLUDE_ASM("nonmatchings/sdk/scevu0dropshadowmatrix", sceVu0MulVector);
INCLUDE_ASM("nonmatchings/sdk/scevu0dropshadowmatrix", sceVu0ScaleVector);
INCLUDE_ASM("nonmatchings/sdk/scevu0dropshadowmatrix", sceVu0TransMatrix);
typedef int u128_cv __attribute__((mode(TI)));
void sceVu0CopyVector(u128_cv *d, u128_cv *s)
{
    register u128_cv t __asm__("$6");
    t = *s;
    *d = t;
}
INCLUDE_ASM("nonmatchings/sdk/scevu0dropshadowmatrix", sceVu0CopyMatrix);
INCLUDE_ASM("nonmatchings/sdk/scevu0dropshadowmatrix", sceVu0FTOI4Vector);
INCLUDE_ASM("nonmatchings/sdk/scevu0dropshadowmatrix", sceVu0FTOI0Vector);
INCLUDE_ASM("nonmatchings/sdk/scevu0dropshadowmatrix", sceVu0ITOF4Vector);
INCLUDE_ASM("nonmatchings/sdk/scevu0dropshadowmatrix", sceVu0ITOF0Vector);
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
INCLUDE_ASM("nonmatchings/sdk/scevu0dropshadowmatrix", sceVu0ScaleVectorXYZ);
INCLUDE_ASM("nonmatchings/sdk/scevu0dropshadowmatrix", sceVu0ClipScreen);
INCLUDE_ASM("nonmatchings/sdk/scevu0dropshadowmatrix", sceVu0ClipScreen3);
INCLUDE_ASM("nonmatchings/sdk/scevu0dropshadowmatrix", sceVu0ClipAll);
INCLUDE_ASM("nonmatchings/sdk/scevu0dropshadowmatrix", sceVpu0Reset);
