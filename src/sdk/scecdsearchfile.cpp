/* Fonctions libres — à décrire.
 *
 * Unité découpée par `make carve` : 21 fonctions, 4844 octets, de
 * 0x0011F258 à 0x00120570. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

INCLUDE_ASM("nonmatchings/sdk/scecdsearchfile", CB_DelayTh);
INCLUDE_ASM("nonmatchings/sdk/scecdsearchfile", sceCdDelayThread);
INCLUDE_ASM("nonmatchings/sdk/scecdsearchfile", sceCdCallback);
INCLUDE_ASM("nonmatchings/sdk/scecdsearchfile", _sceCd_cd_callback);
INCLUDE_ASM("nonmatchings/sdk/scecdsearchfile", _Cdvd_cbLoop);
INCLUDE_ASM("nonmatchings/sdk/scecdsearchfile", sceCdInitEeCB);
INCLUDE_ASM("nonmatchings/sdk/scecdsearchfile", _sceCd_cd_read_intr);
INCLUDE_ASM("nonmatchings/sdk/scecdsearchfile", cmd_sem_init);
INCLUDE_ASM("nonmatchings/sdk/scecdsearchfile", cdvd_exit);
INCLUDE_ASM("nonmatchings/sdk/scecdsearchfile", sceCdPOffCallback);
INCLUDE_ASM("nonmatchings/sdk/scecdsearchfile", _sceCd_Poff_Intr);
INCLUDE_ASM("nonmatchings/sdk/scecdsearchfile", PowerOffCB);
INCLUDE_ASM("nonmatchings/sdk/scecdsearchfile", sceCdSearchFile);
INCLUDE_ASM("nonmatchings/sdk/scecdsearchfile", _sceCd_ncmd_prechk);
INCLUDE_ASM("nonmatchings/sdk/scecdsearchfile", sceCdNcmdDiskReady);
INCLUDE_ASM("nonmatchings/sdk/scecdsearchfile", sceCdSync);
INCLUDE_ASM("nonmatchings/sdk/scecdsearchfile", sceCdSyncS);
INCLUDE_ASM("nonmatchings/sdk/scecdsearchfile", _sceCd_scmd_prechk);
INCLUDE_ASM("nonmatchings/sdk/scecdsearchfile", sceCdInit);
INCLUDE_ASM("nonmatchings/sdk/scecdsearchfile", sceCdDiskReady);
INCLUDE_ASM("nonmatchings/sdk/scecdsearchfile", sceCdMmode);
