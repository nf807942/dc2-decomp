/* Fonctions libres — à décrire.
 *
 * Unité découpée par `make carve` : 17 fonctions, 2736 octets, de
 * 0x00104288 à 0x00104D58. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

INCLUDE_ASM("nonmatchings/sdk/scedmaputenv", memclr);
INCLUDE_ASM("nonmatchings/sdk/scedmaputenv", sceDmaGetChan);
INCLUDE_ASM("nonmatchings/sdk/scedmaputenv", sceDmaReset);
INCLUDE_ASM("nonmatchings/sdk/scedmaputenv", sceDmaDebug);
INCLUDE_ASM("nonmatchings/sdk/scedmaputenv", sceDmaPutEnv);
INCLUDE_ASM("nonmatchings/sdk/scedmaputenv", sceDmaGetEnv);
INCLUDE_ASM("nonmatchings/sdk/scedmaputenv", sceDmaPutStallAddr);
INCLUDE_ASM("nonmatchings/sdk/scedmaputenv", sceDmaSend);
INCLUDE_ASM("nonmatchings/sdk/scedmaputenv", sceDmaSendN);
INCLUDE_ASM("nonmatchings/sdk/scedmaputenv", sceDmaSendI);
INCLUDE_ASM("nonmatchings/sdk/scedmaputenv", sceDmaRecv);
INCLUDE_ASM("nonmatchings/sdk/scedmaputenv", sceDmaRecvN);
INCLUDE_ASM("nonmatchings/sdk/scedmaputenv", sceDmaRecvI);
INCLUDE_ASM("nonmatchings/sdk/scedmaputenv", sceDmaSync);
INCLUDE_ASM("nonmatchings/sdk/scedmaputenv", sceDmaWatch);
INCLUDE_ASM("nonmatchings/sdk/scedmaputenv", sceDmaPause);
INCLUDE_ASM("nonmatchings/sdk/scedmaputenv", sceDmaRestart);
