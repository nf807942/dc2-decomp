/* Émulation logicielle du flottant simple précision, du runtime Metrowerks.
 *
 * Les quinze fonctions reprennent la structure de `fp-bit.c` : un format
 * décomposé (`__unpack_f`), les opérations sur cette forme, puis le
 * réassemblage (`__pack_f`). `runtime/dpmul`, juste avant elle dans le
 * binaire, en est la version double précision, nom pour nom.
 *
 * L'unité couvre 0x0028C5F0 à 0x0028D1D0. Chaque fonction garde les
 * instructions du disque jusqu'à ce qu'elle soit écrite en C++, et l'ordre
 * est celui des adresses, que l'éditeur de liens attend.
 */

#include "common.h"
#include "softfloat.hpp"

INCLUDE_ASM("nonmatchings/runtime/fpmul", __pack_f);

INCLUDE_ASM("nonmatchings/runtime/fpmul", __unpack_f);
INCLUDE_ASM("nonmatchings/runtime/fpmul", _fpadd_parts_0028C790);
INCLUDE_ASM("nonmatchings/runtime/fpmul", fpadd);
INCLUDE_ASM("nonmatchings/runtime/fpmul", fpsub);
INCLUDE_ASM("nonmatchings/runtime/fpmul", fpmul);
INCLUDE_ASM("nonmatchings/runtime/fpmul", fpdiv);
INCLUDE_ASM("nonmatchings/runtime/fpmul", __fpcmp_parts_f);
INCLUDE_ASM("nonmatchings/runtime/fpmul", fpcmp);
INCLUDE_ASM("nonmatchings/runtime/fpmul", sitofp);
INCLUDE_ASM("nonmatchings/runtime/fpmul", fptosi);
INCLUDE_ASM("nonmatchings/runtime/fpmul", fptoui);
INCLUDE_ASM("nonmatchings/runtime/fpmul", __negsf2);
INCLUDE_ASM("nonmatchings/runtime/fpmul", __make_fp);
INCLUDE_ASM("nonmatchings/runtime/fpmul", fptodp);
