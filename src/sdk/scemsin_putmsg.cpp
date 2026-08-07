/* Fonctions libres — à décrire.
 *
 * Unité découpée par `make carve` : 7 fonctions, 660 octets, de
 * 0x00123A50 à 0x00123CE8. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

INCLUDE_ASM("nonmatchings/sdk/scemsin_putmsg", sceMSIn_Init);
INCLUDE_ASM("nonmatchings/sdk/scemsin_putmsg", sceMSIn_ATick);
INCLUDE_ASM("nonmatchings/sdk/scemsin_putmsg", sceMSIn_Load);
INCLUDE_ASM("nonmatchings/sdk/scemsin_putmsg", put_message);
INCLUDE_ASM("nonmatchings/sdk/scemsin_putmsg", sceMSIn_PutMsg);
INCLUDE_ASM("nonmatchings/sdk/scemsin_putmsg", sceMSIn_PutExcMsg);
INCLUDE_ASM("nonmatchings/sdk/scemsin_putmsg", sceMSIn_PutHsMsg);
