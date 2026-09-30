#ifndef GCC_STDDEF_H
#define GCC_STDDEF_H

/* Le `stddef.h` que GCC fournit d'ordinaire et que le paquet d'ee-gcc ne porte pas. Ce
 * qu'en réclament les en-têtes de newlib : des tailles et des pointeurs nuls. */

#ifndef _SIZE_T
#define _SIZE_T
typedef unsigned int size_t;
#endif
typedef int ptrdiff_t;
typedef int wchar_t;

#ifndef NULL
#define NULL ((void *) 0)
#endif
#define offsetof(type, member) ((size_t) &((type *) 0)->member)

#endif /* GCC_STDDEF_H */
