/* Fonctions libres — à décrire.
 *
 * Unité découpée par `make carve` : 35 fonctions, 2808 octets, de
 * 0x0010DE88 à 0x0010E9D8. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

INCLUDE_ASM("nonmatchings/sdk/scempegcreate", sceMpegInit);
INCLUDE_ASM("nonmatchings/sdk/scempegcreate", sceMpegCreate);
INCLUDE_ASM("nonmatchings/sdk/scempegcreate", sceMpegDelete);
INCLUDE_ASM("nonmatchings/sdk/scempegcreate", sceMpegAddBs);
INCLUDE_ASM("nonmatchings/sdk/scempegcreate", sceMpegGetPicture);
INCLUDE_ASM("nonmatchings/sdk/scempegcreate", sceMpegGetPictureRAW8);
INCLUDE_ASM("nonmatchings/sdk/scempegcreate", sceMpegGetPictureRAW8xy);
INCLUDE_ASM("nonmatchings/sdk/scempegcreate", sceMpegSetDecodeMode);
INCLUDE_ASM("nonmatchings/sdk/scempegcreate", sceMpegGetDecodeMode);
INCLUDE_ASM("nonmatchings/sdk/scempegcreate", sceMpegIsEnd);
INCLUDE_ASM("nonmatchings/sdk/scempegcreate", sceMpegIsRefBuffEmpty);
INCLUDE_ASM("nonmatchings/sdk/scempegcreate", sceMpegReset);
INCLUDE_ASM("nonmatchings/sdk/scempegcreate", sceMpegClearRefBuff);
INCLUDE_ASM("nonmatchings/sdk/scempegcreate", sceMpegAddCallback);
INCLUDE_ASM("nonmatchings/sdk/scempegcreate", _dispatchMpegCallback);
INCLUDE_ASM("nonmatchings/sdk/scempegcreate", _dispatchMpegCbNodata);
INCLUDE_ASM("nonmatchings/sdk/scempegcreate", sceMpegSetDefaultPtsGap);
INCLUDE_ASM("nonmatchings/sdk/scempegcreate", sceMpegResetDefaultPtsGap);
INCLUDE_ASM("nonmatchings/sdk/scempegcreate", sceMpegSetImageBuff);
INCLUDE_ASM("nonmatchings/sdk/scempegcreate", sceMpegDispWidth);
INCLUDE_ASM("nonmatchings/sdk/scempegcreate", sceMpegDispHeight);
INCLUDE_ASM("nonmatchings/sdk/scempegcreate", sceMpegDispCenterOffX);
INCLUDE_ASM("nonmatchings/sdk/scempegcreate", sceMpegDispCenterOffY);
INCLUDE_ASM("nonmatchings/sdk/scempegcreate", sceSetBrokenLink);
INCLUDE_ASM("nonmatchings/sdk/scempegcreate", sceSetPtm);
INCLUDE_ASM("nonmatchings/sdk/scempegcreate", _alalcInit);
INCLUDE_ASM("nonmatchings/sdk/scempegcreate", _alalcSetDynamic);
INCLUDE_ASM("nonmatchings/sdk/scempegcreate", _alalcFree);
INCLUDE_ASM("nonmatchings/sdk/scempegcreate", _alalcAlloc);
INCLUDE_ASM("nonmatchings/sdk/scempegcreate", _alalcRest);
INCLUDE_ASM("nonmatchings/sdk/scempegcreate", _getpic);
INCLUDE_ASM("nonmatchings/sdk/scempegcreate", _decodeOrSkipFrame);
INCLUDE_ASM("nonmatchings/sdk/scempegcreate", _decodeOrSkip);
INCLUDE_ASM("nonmatchings/sdk/scempegcreate", _decodeOrSkipField);
INCLUDE_ASM("nonmatchings/sdk/scempegcreate", _sceMpegFlush);
