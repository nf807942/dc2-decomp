#ifndef RUNSCRIPT_HPP
#define RUNSCRIPT_HPP

#include "types.h"

/* Une case de la pile de l'interpréteur de script.
 *
 * Le champ de tête dit ce que les quatre octets suivants portent, et
 * `GetStackInt` (0x00262DA0) comme `SetStack` (0x00262E70) le montrent : la
 * première convertit la valeur quand le type vaut 1, donc elle y lit un
 * flottant ; la seconde n'écrit qu'à travers elle quand le type vaut 3, donc
 * elle y lit l'adresse d'une autre case. Les autres types rendent la valeur
 * telle quelle, et rien de plus n'est établi.
 *
 * Les commandes de script reçoivent la première case de leurs arguments et
 * avancent d'une case à chaque valeur lue ou rendue. */
struct RS_STACKDATA {
    s32 type;   /* 0x0 */
    s32 value;  /* 0x4 — entier, flottant ou adresse, selon le type */
};

#endif /* RUNSCRIPT_HPP */
