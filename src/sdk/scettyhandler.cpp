/* Fonctions libres — à décrire.
 *
 * Unité découpée par `make carve` : 7 fonctions, 1292 octets, de
 * 0x001112A0 à 0x001117C0. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

INCLUDE_ASM("nonmatchings/sdk/scettyhandler", QueueInit);
INCLUDE_ASM("nonmatchings/sdk/scettyhandler", QueuePeekWriteDone);
INCLUDE_ASM("nonmatchings/sdk/scettyhandler", QueuePeekReadDone);
INCLUDE_ASM("nonmatchings/sdk/scettyhandler", sceTtyHandler);
INCLUDE_ASM("nonmatchings/sdk/scettyhandler", sceTtyWrite);
INCLUDE_ASM("nonmatchings/sdk/scettyhandler", sceTtyRead);
INCLUDE_ASM("nonmatchings/sdk/scettyhandler", sceTtyInit);
