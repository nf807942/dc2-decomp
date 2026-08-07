/* Fonctions libres — à décrire.
 *
 * Unité découpée par `make carve` : 18 fonctions, 3388 octets, de
 * 0x00117178 à 0x00117ED8. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

INCLUDE_ASM("nonmatchings/sdk/scesifloadmodule", _lf_bind);
INCLUDE_ASM("nonmatchings/sdk/scesifloadmodule", _lf_version);
INCLUDE_ASM("nonmatchings/sdk/scesifloadmodule", sceSifLoadFileReset);
INCLUDE_ASM("nonmatchings/sdk/scesifloadmodule", _sceSifLoadModuleBuffer);
INCLUDE_ASM("nonmatchings/sdk/scesifloadmodule", sceSifStopModule);
INCLUDE_ASM("nonmatchings/sdk/scesifloadmodule", sceSifUnloadModule);
INCLUDE_ASM("nonmatchings/sdk/scesifloadmodule", sceSifSearchModuleByName);
INCLUDE_ASM("nonmatchings/sdk/scesifloadmodule", sceSifSearchModuleByAddress);
INCLUDE_ASM("nonmatchings/sdk/scesifloadmodule", sceSifLoadModuleBuffer);
INCLUDE_ASM("nonmatchings/sdk/scesifloadmodule", sceSifLoadStartModuleBuffer);
INCLUDE_ASM("nonmatchings/sdk/scesifloadmodule", _sceSifLoadModule);
INCLUDE_ASM("nonmatchings/sdk/scesifloadmodule", sceSifLoadModule);
INCLUDE_ASM("nonmatchings/sdk/scesifloadmodule", sceSifLoadStartModule);
INCLUDE_ASM("nonmatchings/sdk/scesifloadmodule", _sceSifLoadElfPart);
INCLUDE_ASM("nonmatchings/sdk/scesifloadmodule", sceSifLoadElfPart);
INCLUDE_ASM("nonmatchings/sdk/scesifloadmodule", sceSifLoadElf);
INCLUDE_ASM("nonmatchings/sdk/scesifloadmodule", sceSifGetIopAddr);
INCLUDE_ASM("nonmatchings/sdk/scesifloadmodule", sceSifSetIopAddr);
