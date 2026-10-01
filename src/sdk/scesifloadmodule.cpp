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
extern int _sceSifLoadModuleBuffer(int, int, int, int);
int sceSifLoadModuleBuffer(int a, int b, int c)
{
    int k8d[4];
    return _sceSifLoadModuleBuffer(a, b, c, (int)k8d);
}
extern int _sceSifLoadModuleBuffer(int, int, int, int);
int sceSifLoadStartModuleBuffer(int a, int b, int c, int d)
{
    return _sceSifLoadModuleBuffer(a, b, c, d);
}
INCLUDE_ASM("nonmatchings/sdk/scesifloadmodule", _sceSifLoadModule);
INCLUDE_ASM("nonmatchings/sdk/scesifloadmodule", sceSifLoadModule);
extern int _sceSifLoadModule(int, int, int, int, int);
int sceSifLoadStartModule(int a, int b, int c, int d)
{
    return _sceSifLoadModule(a, b, c, d, 0);
}
INCLUDE_ASM("nonmatchings/sdk/scesifloadmodule", _sceSifLoadElfPart);
extern int _sceSifLoadElfPart(int, int, int, int);
int sceSifLoadElfPart(int a, int b, int c)
{
    return _sceSifLoadElfPart(a, b, c, 1);
}
INCLUDE_ASM("nonmatchings/sdk/scesifloadmodule", sceSifLoadElf);
INCLUDE_ASM("nonmatchings/sdk/scesifloadmodule", sceSifGetIopAddr);
INCLUDE_ASM("nonmatchings/sdk/scesifloadmodule", sceSifSetIopAddr);
