/* Fonctions libres — à décrire.
 *
 * Unité découpée par `make carve` : 19 fonctions, 2744 octets, de
 * 0x0010E9D8 à 0x0010F4C0. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

INCLUDE_ASM("nonmatchings/sdk/initseq", _initSeqAgain);
INCLUDE_ASM("nonmatchings/sdk/initseq", _lastFrame);
INCLUDE_ASM("nonmatchings/sdk/initseq", _clearOnce);
INCLUDE_ASM("nonmatchings/sdk/initseq", _clearEach);
INCLUDE_ASM("nonmatchings/sdk/initseq", _ErrMessage);
INCLUDE_ASM("nonmatchings/sdk/initseq", _Error1);
INCLUDE_ASM("nonmatchings/sdk/initseq", _Error);
INCLUDE_ASM("nonmatchings/sdk/initseq", _sendDataToIPU);
INCLUDE_ASM("nonmatchings/sdk/initseq", _RefImageInit);
INCLUDE_ASM("nonmatchings/sdk/initseq", _sequenceHeader);
INCLUDE_ASM("nonmatchings/sdk/initseq", _initSeq);
INCLUDE_ASM("nonmatchings/sdk/initseq", _initRefImages);
INCLUDE_ASM("nonmatchings/sdk/initseq", _setDefaultQM);
INCLUDE_ASM("nonmatchings/sdk/initseq", _sequenceExtension);
INCLUDE_ASM("nonmatchings/sdk/initseq", _sequenceDisplayExtension);
INCLUDE_ASM("nonmatchings/sdk/initseq", _sequenceScalableExtension);
INCLUDE_ASM("nonmatchings/sdk/initseq", _unknown_extension);
INCLUDE_ASM("nonmatchings/sdk/initseq", _pictureSpatialScalableExtension);
INCLUDE_ASM("nonmatchings/sdk/initseq", _pictureTemporalScalableExtension);
