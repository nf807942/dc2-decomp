#ifndef GCC_STDARG_H
#define GCC_STDARG_H

/* Le `stdarg.h` que le paquet d'ee-gcc ne porte pas. Ne sert qu'aux déclarations :
 * une fonction qui lit ses arguments variables demande le vrai. */

typedef char *__gnuc_va_list;
typedef __gnuc_va_list va_list;

#endif /* GCC_STDARG_H */
