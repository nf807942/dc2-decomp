/* Fonctions libres — à décrire.
 *
 * Unité découpée par `make carve` : 4 fonctions, 808 octets, de
 * 0x00118E50 à 0x00119180. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

INCLUDE_ASM("nonmatchings/sdk/scesdremote", sceSdRemoteInit);
INCLUDE_ASM("nonmatchings/sdk/scesdremote", sceSdTransToIOP);
INCLUDE_ASM("nonmatchings/sdk/scesdremote", sceSdCallBack);
INCLUDE_ASM("nonmatchings/sdk/scesdremote", sceSdRemote);
