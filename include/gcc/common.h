#ifndef GCC_COMMON_H
#define GCC_COMMON_H

/* Ce que toute unité compilée par `ee-gcc` inclut. C'est le pendant de
 * `include/common.h` pour la voie GCC : les unités de `config/gcc_units.txt` sont
 * du C, non du C++ de MWCC, et n'ont besoin ni des types ni des conventions du
 * jeu — seulement de quoi nommer des entiers de largeur connue.
 *
 * `INCLUDE_ASM` reste vide : c'est `mwccgap` qui l'interprète avant le
 * compilateur, exactement comme pour MWCC. */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long u64;
typedef signed char s8;
typedef short s16;
typedef int s32;
typedef long s64;

#define INCLUDE_ASM(FOLDER, NAME)
#define INCLUDE_RODATA(FOLDER, NAME)

#endif /* GCC_COMMON_H */
