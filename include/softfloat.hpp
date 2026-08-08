#ifndef SOFTFLOAT_HPP
#define SOFTFLOAT_HPP

#include "types.h"

/* L'émulation logicielle du flottant, telle que le binaire la porte : la
 * simple précision de 0x0028C5F0 à 0x0028D160 (`runtime/fpmul`), la double
 * juste avant, de 0x0028B8F8 à 0x0028C5F0 (`runtime/dpmul`), nom pour nom.
 *
 * La forme vient de `fp-bit.c`, que Metrowerks a repris : un nombre y voyage
 * décomposé entre l'extraction (`__unpack_f`) et le réassemblage (`__pack_f`),
 * et chaque opération travaille sur cette forme-là. Les constantes, en
 * revanche, sont celles que ce binaire teste, relevées dans son
 * désassemblage. */

/* La nature d'un nombre décomposé, en 0x0 de la structure. Les valeurs sont
 * celles que `__unpack_f` écrit (0x0028C700) et que `__pack_f` aiguille
 * (0x0028C5F0) ; elles ne suivent pas l'ordre de `fp-bit.c`, où l'infini
 * précède le zéro. */
typedef enum {
    CLASS_SNAN = 0,
    CLASS_QNAN = 1,
    CLASS_ZERO = 2,
    CLASS_NUMBER = 3,
    CLASS_INFINITY = 4
} fp_class_type;

/* Un nombre décomposé. Le champ 0x0 s'appelle `class` dans `fp-bit.c`, qui est
 * du C ; notre chaîne compile en C++, qui en fait un mot réservé. Le nom d'un
 * champ ne paraît pas dans l'objet, donc le renommer ne coûte rien. */
struct fp_number_type {
    fp_class_type cls;  /* 0x0 */
    u32 sign;           /* 0x4 */
    s32 normal_exp;     /* 0x8 */
    u32 fraction;       /* 0xC */
};

/* Le flottant vu de ses deux côtés. `__unpack_f` reçoit son adresse, non sa
 * valeur : c'est par là que les bits se lisent. */
union FLO_union_type {
    f32 value;
    u32 bits;
};

/* La disposition IEEE simple précision, telle que `__unpack_f` la découpe. */
#define FRACBITS 23
#define EXPBITS 8
#define EXPMAX 0xFF
#define EXPBIAS 0x7F
#define FRAC_MASK 0x007FFFFF

/* Les sept bits de garde que la forme décomposée ajoute sous la fraction :
 * `__unpack_f` décale de sept et pose le bit implicite en 2^30. */
#define NGARDS 7
#define IMPLICIT_1 0x40000000

/* Le bit qui distingue un NaN silencieux d'un signalant. Le binaire teste
 * 2^20 (0x0028C750) et le pose au réassemblage (0x0028C60C) — ce n'est pas le
 * bit de silence de la norme IEEE, qui est 2^22 ; c'est ce que ce runtime
 * emploie, et rien de plus n'en est établi. */
#define QUIET_NAN 0x00100000

/* La borne basse des exposants normaux : sous elle, `__pack_f` dénormalise. */
#define NORMAL_EXPMIN (-(EXPBIAS - 1))

extern "C" {

void __unpack_f(FLO_union_type *src, fp_number_type *dst);
f32 __pack_f(const fp_number_type *src);
s32 __fpcmp_parts_f(const fp_number_type *a, const fp_number_type *b);

/* Le binaire porte deux `_fpadd_parts` statiques, un par précision, et le
 * désassembleur les départage par leur adresse. C'est ce nom-là que la
 * comparaison attend, donc c'est celui que la source porte. */
fp_number_type *_fpadd_parts_0028C790(const fp_number_type *a,
                                      const fp_number_type *b,
                                      fp_number_type *tmp);

}

#endif /* SOFTFLOAT_HPP */
