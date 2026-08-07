/* Fonctions libres — à décrire.
 *
 * Unité découpée par `make carve` : 40 fonctions, 13888 octets, de
 * 0x001137E0 à 0x00116E78. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

INCLUDE_ASM("nonmatchings/sdk/scefs_rcv_intr", _sceFsIobSemaMK);
INCLUDE_ASM("nonmatchings/sdk/scefs_rcv_intr", new_iob);
INCLUDE_ASM("nonmatchings/sdk/scefs_rcv_intr", get_iob);
INCLUDE_ASM("nonmatchings/sdk/scefs_rcv_intr", _sceFs_Rcv_Intr);
INCLUDE_ASM("nonmatchings/sdk/scefs_rcv_intr", _sceFsSemInit);
INCLUDE_ASM("nonmatchings/sdk/scefs_rcv_intr", _sceFsWaitS);
INCLUDE_ASM("nonmatchings/sdk/scefs_rcv_intr", _sceFsSigSema);
INCLUDE_ASM("nonmatchings/sdk/scefs_rcv_intr", scePowerOffHandler);
INCLUDE_ASM("nonmatchings/sdk/scefs_rcv_intr", _sceFs_Poff_Intr);
INCLUDE_ASM("nonmatchings/sdk/scefs_rcv_intr", sceFsInit);
INCLUDE_ASM("nonmatchings/sdk/scefs_rcv_intr", _fs_version);
INCLUDE_ASM("nonmatchings/sdk/scefs_rcv_intr", sceFsReset);
INCLUDE_ASM("nonmatchings/sdk/scefs_rcv_intr", sceOpen);
INCLUDE_ASM("nonmatchings/sdk/scefs_rcv_intr", sceClose);
INCLUDE_ASM("nonmatchings/sdk/scefs_rcv_intr", sceLseek);
INCLUDE_ASM("nonmatchings/sdk/scefs_rcv_intr", sceRead);
INCLUDE_ASM("nonmatchings/sdk/scefs_rcv_intr", sceWrite);
INCLUDE_ASM("nonmatchings/sdk/scefs_rcv_intr", sceIoctl);
INCLUDE_ASM("nonmatchings/sdk/scefs_rcv_intr", sceIoctl2);
INCLUDE_ASM("nonmatchings/sdk/scefs_rcv_intr", _sceCallCode);
INCLUDE_ASM("nonmatchings/sdk/scefs_rcv_intr", sceRemove);
INCLUDE_ASM("nonmatchings/sdk/scefs_rcv_intr", sceMkdir);
INCLUDE_ASM("nonmatchings/sdk/scefs_rcv_intr", sceRmdir);
INCLUDE_ASM("nonmatchings/sdk/scefs_rcv_intr", sceFormat);
INCLUDE_ASM("nonmatchings/sdk/scefs_rcv_intr", sceAddDrv);
INCLUDE_ASM("nonmatchings/sdk/scefs_rcv_intr", sceDelDrv);
INCLUDE_ASM("nonmatchings/sdk/scefs_rcv_intr", sceDopen);
INCLUDE_ASM("nonmatchings/sdk/scefs_rcv_intr", sceDclose);
INCLUDE_ASM("nonmatchings/sdk/scefs_rcv_intr", sceDread);
INCLUDE_ASM("nonmatchings/sdk/scefs_rcv_intr", sceGetstat);
INCLUDE_ASM("nonmatchings/sdk/scefs_rcv_intr", sceChstat);
INCLUDE_ASM("nonmatchings/sdk/scefs_rcv_intr", sceRename);
INCLUDE_ASM("nonmatchings/sdk/scefs_rcv_intr", sceChdir);
INCLUDE_ASM("nonmatchings/sdk/scefs_rcv_intr", sceSync);
INCLUDE_ASM("nonmatchings/sdk/scefs_rcv_intr", sceMount);
INCLUDE_ASM("nonmatchings/sdk/scefs_rcv_intr", sceUmount);
INCLUDE_ASM("nonmatchings/sdk/scefs_rcv_intr", sceLseek64);
INCLUDE_ASM("nonmatchings/sdk/scefs_rcv_intr", sceDevctl);
INCLUDE_ASM("nonmatchings/sdk/scefs_rcv_intr", sceSymlink);
INCLUDE_ASM("nonmatchings/sdk/scefs_rcv_intr", sceReadlink);
