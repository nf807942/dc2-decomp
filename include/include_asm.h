#ifndef INCLUDE_ASM_H
#define INCLUDE_ASM_H

/* Une fonction encore en assembleur, à l'intérieur d'une unité de traduction
 * par ailleurs compilée.
 *
 * MWCC accepte de l'assembleur dans une fonction `asm`, mais exige alors que
 * tout ce qu'elle nomme soit défini — ce qui interdit de reprendre le
 * désassemblage tel quel. `mwccgap` contourne cela : il remplace la fonction
 * marquée par autant de `nop` qu'elle occupe, laisse MWCC compiler le reste,
 * assemble le `.s` de référence à part, puis greffe le résultat dans l'objet
 * en réparant symboles et relocations.
 *
 * Ces macros doivent donc rester vides : c'est `mwccgap` qui les interprète,
 * avant que le compilateur ne les voie.
 *
 *     INCLUDE_ASM("text/0012C1A8", Close__8CGamePadFv);
 *
 * Le premier argument est le chemin du `.s` sous `asm/`, sans extension ; le
 * second le symbole, tel que le binaire le porte. */
#define INCLUDE_ASM(FOLDER, NAME)
#define INCLUDE_RODATA(FOLDER, NAME)

#endif /* INCLUDE_ASM_H */
