/* Fonctions libres — à décrire.
 *
 * Unité découpée par `make carve` : 16 fonctions, 1828 octets, de
 * 0x00112138 à 0x00112880. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

INCLUDE_ASM("nonmatchings/sdk/scesifinitcmd", _set_sreg);
INCLUDE_ASM("nonmatchings/sdk/scesifinitcmd", _change_addr);
INCLUDE_ASM("nonmatchings/sdk/scesifinitcmd", sceSifGetSreg);
INCLUDE_ASM("nonmatchings/sdk/scesifinitcmd", sceSifSetSreg);
INCLUDE_ASM("nonmatchings/sdk/scesifinitcmd", sceSifGetDataTable);
INCLUDE_ASM("nonmatchings/sdk/scesifinitcmd", sceSifInitCmd);
INCLUDE_ASM("nonmatchings/sdk/scesifinitcmd", sceSifExitCmd);
INCLUDE_ASM("nonmatchings/sdk/scesifinitcmd", sceSifSetCmdBuffer);
INCLUDE_ASM("nonmatchings/sdk/scesifinitcmd", sceSifSetSysCmdBuffer);
INCLUDE_ASM("nonmatchings/sdk/scesifinitcmd", sceSifAddCmdHandler);
INCLUDE_ASM("nonmatchings/sdk/scesifinitcmd", sceSifRemoveCmdHandler);
INCLUDE_ASM("nonmatchings/sdk/scesifinitcmd", _sceSifSendCmd);
INCLUDE_ASM("nonmatchings/sdk/scesifinitcmd", sceSifSendCmd);
INCLUDE_ASM("nonmatchings/sdk/scesifinitcmd", isceSifSendCmd);
INCLUDE_ASM("nonmatchings/sdk/scesifinitcmd", _sceSifCmdIntrHdlr);
INCLUDE_ASM("nonmatchings/sdk/scesifinitcmd", sceSifWriteBackDCache);
