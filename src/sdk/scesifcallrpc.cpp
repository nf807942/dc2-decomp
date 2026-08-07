/* Fonctions libres — à décrire.
 *
 * Unité découpée par `make carve` : 22 fonctions, 3892 octets, de
 * 0x00112880 à 0x001137E0. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

INCLUDE_ASM("nonmatchings/sdk/scesifcallrpc", sceSifInitRpc);
INCLUDE_ASM("nonmatchings/sdk/scesifcallrpc", sceSifExitRpc);
INCLUDE_ASM("nonmatchings/sdk/scesifcallrpc", _sceRpcGetPacket);
INCLUDE_ASM("nonmatchings/sdk/scesifcallrpc", _sceRpcFreePacket);
INCLUDE_ASM("nonmatchings/sdk/scesifcallrpc", _sceRpcGetFPacket);
INCLUDE_ASM("nonmatchings/sdk/scesifcallrpc", _sceRpcGetFPacket2);
INCLUDE_ASM("nonmatchings/sdk/scesifcallrpc", _request_end);
INCLUDE_ASM("nonmatchings/sdk/scesifcallrpc", _request_rdata);
INCLUDE_ASM("nonmatchings/sdk/scesifcallrpc", sceSifGetOtherData);
INCLUDE_ASM("nonmatchings/sdk/scesifcallrpc", _search_svdata);
INCLUDE_ASM("nonmatchings/sdk/scesifcallrpc", _request_bind);
INCLUDE_ASM("nonmatchings/sdk/scesifcallrpc", sceSifBindRpc);
INCLUDE_ASM("nonmatchings/sdk/scesifcallrpc", _request_call);
INCLUDE_ASM("nonmatchings/sdk/scesifcallrpc", sceSifCallRpc);
INCLUDE_ASM("nonmatchings/sdk/scesifcallrpc", sceSifCheckStatRpc);
INCLUDE_ASM("nonmatchings/sdk/scesifcallrpc", sceSifSetRpcQueue);
INCLUDE_ASM("nonmatchings/sdk/scesifcallrpc", sceSifRegisterRpc);
INCLUDE_ASM("nonmatchings/sdk/scesifcallrpc", sceSifRemoveRpc);
INCLUDE_ASM("nonmatchings/sdk/scesifcallrpc", sceSifRemoveRpcQueue);
INCLUDE_ASM("nonmatchings/sdk/scesifcallrpc", sceSifGetNextRequest);
INCLUDE_ASM("nonmatchings/sdk/scesifcallrpc", sceSifExecRequest);
INCLUDE_ASM("nonmatchings/sdk/scesifcallrpc", sceSifRpcLoop);
