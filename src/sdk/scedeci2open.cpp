/* Fonctions libres — à décrire.
 *
 * Unité découpée par `make carve` : 10 fonctions, 448 octets, de
 * 0x001110C0 à 0x001112A0. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

INCLUDE_ASM("nonmatchings/sdk/scedeci2open", sceDeci2Open);
INCLUDE_ASM("nonmatchings/sdk/scedeci2open", sceDeci2Close);
INCLUDE_ASM("nonmatchings/sdk/scedeci2open", sceDeci2ReqSend);
INCLUDE_ASM("nonmatchings/sdk/scedeci2open", sceDeci2Poll);
INCLUDE_ASM("nonmatchings/sdk/scedeci2open", sceDeci2ExRecv);
INCLUDE_ASM("nonmatchings/sdk/scedeci2open", sceDeci2ExSend);
INCLUDE_ASM("nonmatchings/sdk/scedeci2open", sceDeci2ExReqSend);
INCLUDE_ASM("nonmatchings/sdk/scedeci2open", sceDeci2ExLock);
INCLUDE_ASM("nonmatchings/sdk/scedeci2open", sceDeci2ExUnLock);
INCLUDE_ASM("nonmatchings/sdk/scedeci2open", kputs);
