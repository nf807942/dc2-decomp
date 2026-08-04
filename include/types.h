#ifndef TYPES_H
#define TYPES_H

/* Les types de largeur fixe, tels que le SDK PlayStation 2 les nomme. Le code
 * du jeu emploie ces noms : ils viennent de `sys/types.h` de Sony, que les
 * en-têtes du middleware `mg*` supposent présent. */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef signed long long s64;

typedef float f32;
typedef double f64;

/* Le quadmot est le registre naturel du R5900 : 128 bits, que `lq` et `sq`
 * transportent d'un coup. MWCC l'expose sous ce nom. */
typedef unsigned int u128 __attribute__((mode(TI)));

typedef int BOOL;

#ifndef NULL
#define NULL 0
#endif

#define TRUE 1
#define FALSE 0

#endif /* TYPES_H */
