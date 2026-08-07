/* Fonctions libres — à décrire.
 *
 * Unité découpée par `make carve` : 28 fonctions, 6188 octets, de
 * 0x001221E8 à 0x00123A50. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

INCLUDE_ASM("nonmatchings/sdk/scemcsetfileinfo", sceMcInit);
INCLUDE_ASM("nonmatchings/sdk/scemcsetfileinfo", sceMcEnd);
INCLUDE_ASM("nonmatchings/sdk/scemcsetfileinfo", _lmcGetClientPtr);
INCLUDE_ASM("nonmatchings/sdk/scemcsetfileinfo", sceMcChangeThreadPriority);
INCLUDE_ASM("nonmatchings/sdk/scemcsetfileinfo", sceMcGetSlotMax);
INCLUDE_ASM("nonmatchings/sdk/scemcsetfileinfo", sceMcOpen);
INCLUDE_ASM("nonmatchings/sdk/scemcsetfileinfo", sceMcMkdir);
INCLUDE_ASM("nonmatchings/sdk/scemcsetfileinfo", sceMcClose);
INCLUDE_ASM("nonmatchings/sdk/scemcsetfileinfo", sceMcSeek);
INCLUDE_ASM("nonmatchings/sdk/scemcsetfileinfo", mceIntrReadFixAlign);
INCLUDE_ASM("nonmatchings/sdk/scemcsetfileinfo", sceMcRead);
INCLUDE_ASM("nonmatchings/sdk/scemcsetfileinfo", sceMcWrite);
INCLUDE_ASM("nonmatchings/sdk/scemcsetfileinfo", mcHearAlarm);
INCLUDE_ASM("nonmatchings/sdk/scemcsetfileinfo", mcDelayThread);
INCLUDE_ASM("nonmatchings/sdk/scemcsetfileinfo", sceMcSync);
INCLUDE_ASM("nonmatchings/sdk/scemcsetfileinfo", mceGetInfoApdx);
INCLUDE_ASM("nonmatchings/sdk/scemcsetfileinfo", sceMcGetInfo);
INCLUDE_ASM("nonmatchings/sdk/scemcsetfileinfo", sceMcUdCheckNewCard);
INCLUDE_ASM("nonmatchings/sdk/scemcsetfileinfo", sceMcGetDir);
INCLUDE_ASM("nonmatchings/sdk/scemcsetfileinfo", mceStorePwd);
INCLUDE_ASM("nonmatchings/sdk/scemcsetfileinfo", sceMcChdir);
INCLUDE_ASM("nonmatchings/sdk/scemcsetfileinfo", sceMcFormat);
INCLUDE_ASM("nonmatchings/sdk/scemcsetfileinfo", sceMcDelete);
INCLUDE_ASM("nonmatchings/sdk/scemcsetfileinfo", sceMcFlush);
INCLUDE_ASM("nonmatchings/sdk/scemcsetfileinfo", sceMcSetFileInfo);
INCLUDE_ASM("nonmatchings/sdk/scemcsetfileinfo", sceMcRename);
INCLUDE_ASM("nonmatchings/sdk/scemcsetfileinfo", sceMcUnformat);
INCLUDE_ASM("nonmatchings/sdk/scemcsetfileinfo", sceMcGetEntSpace);
