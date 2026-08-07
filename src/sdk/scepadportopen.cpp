/* Fonctions libres — à décrire.
 *
 * Unité découpée par `make carve` : 30 fonctions, 4952 octets, de
 * 0x00120E50 à 0x001221E8. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

INCLUDE_ASM("nonmatchings/sdk/scepadportopen", _send_to_iop);
INCLUDE_ASM("nonmatchings/sdk/scepadportopen", scePadInit);
INCLUDE_ASM("nonmatchings/sdk/scepadportopen", scePadInit2);
INCLUDE_ASM("nonmatchings/sdk/scepadportopen", scePadEnd);
INCLUDE_ASM("nonmatchings/sdk/scepadportopen", scePadPortOpen);
INCLUDE_ASM("nonmatchings/sdk/scepadportopen", scePadPortClose);
INCLUDE_ASM("nonmatchings/sdk/scepadportopen", scePadGetDmaStr);
INCLUDE_ASM("nonmatchings/sdk/scepadportopen", scePadGetFrameCount);
INCLUDE_ASM("nonmatchings/sdk/scepadportopen", scePadRead);
INCLUDE_ASM("nonmatchings/sdk/scepadportopen", scePadGetState);
INCLUDE_ASM("nonmatchings/sdk/scepadportopen", scePadStateIntToStr);
INCLUDE_ASM("nonmatchings/sdk/scepadportopen", scePadSetReqState);
INCLUDE_ASM("nonmatchings/sdk/scepadportopen", scePadGetReqState);
INCLUDE_ASM("nonmatchings/sdk/scepadportopen", scePadReqIntToStr);
INCLUDE_ASM("nonmatchings/sdk/scepadportopen", scePadInfoAct);
INCLUDE_ASM("nonmatchings/sdk/scepadportopen", scePadInfoComb);
INCLUDE_ASM("nonmatchings/sdk/scepadportopen", scePadInfoMode);
INCLUDE_ASM("nonmatchings/sdk/scepadportopen", scePadSetMainMode);
INCLUDE_ASM("nonmatchings/sdk/scepadportopen", scePadSetActDirect);
INCLUDE_ASM("nonmatchings/sdk/scepadportopen", scePadSetActAlign);
INCLUDE_ASM("nonmatchings/sdk/scepadportopen", scePadGetButtonMask);
INCLUDE_ASM("nonmatchings/sdk/scepadportopen", scePadSetButtonInfo);
INCLUDE_ASM("nonmatchings/sdk/scepadportopen", scePadInfoPressMode);
INCLUDE_ASM("nonmatchings/sdk/scepadportopen", scePadEnterPressMode);
INCLUDE_ASM("nonmatchings/sdk/scepadportopen", scePadExitPressMode);
INCLUDE_ASM("nonmatchings/sdk/scepadportopen", scePadSetVrefParam);
INCLUDE_ASM("nonmatchings/sdk/scepadportopen", scePadGetPortMax);
INCLUDE_ASM("nonmatchings/sdk/scepadportopen", scePadGetSlotMax);
INCLUDE_ASM("nonmatchings/sdk/scepadportopen", scePadGetModVersion);
INCLUDE_ASM("nonmatchings/sdk/scepadportopen", scePadSetWarningLevel);
