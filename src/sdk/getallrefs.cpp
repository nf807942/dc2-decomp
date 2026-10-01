/* Fonctions libres — à décrire.
 *
 * Unité découpée par `make carve` : 65 fonctions, 19412 octets, de
 * 0x00107A50 à 0x0010C6B0. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

INCLUDE_ASM("nonmatchings/sdk/getallrefs", _motionComp0);
INCLUDE_ASM("nonmatchings/sdk/getallrefs", _getAllRefs);
INCLUDE_ASM("nonmatchings/sdk/getallrefs", _getRef0);
INCLUDE_ASM("nonmatchings/sdk/getallrefs", _doMC);
INCLUDE_ASM("nonmatchings/sdk/getallrefs", _rix_000);
INCLUDE_ASM("nonmatchings/sdk/getallrefs", _ri0_000);
INCLUDE_ASM("nonmatchings/sdk/getallrefs", _rix_001);
INCLUDE_ASM("nonmatchings/sdk/getallrefs", _ri0_001);
INCLUDE_ASM("nonmatchings/sdk/getallrefs", _rix_010);
INCLUDE_ASM("nonmatchings/sdk/getallrefs", _ri0_010);
INCLUDE_ASM("nonmatchings/sdk/getallrefs", _rix_011);
INCLUDE_ASM("nonmatchings/sdk/getallrefs", _ri0_011);
INCLUDE_ASM("nonmatchings/sdk/getallrefs", _rix_100);
INCLUDE_ASM("nonmatchings/sdk/getallrefs", _ri0_100);
INCLUDE_ASM("nonmatchings/sdk/getallrefs", _rix_101);
INCLUDE_ASM("nonmatchings/sdk/getallrefs", _ri0_101);
INCLUDE_ASM("nonmatchings/sdk/getallrefs", _rix_110);
INCLUDE_ASM("nonmatchings/sdk/getallrefs", _ri0_110);
INCLUDE_ASM("nonmatchings/sdk/getallrefs", _rix_111);
INCLUDE_ASM("nonmatchings/sdk/getallrefs", _ri0_111);
INCLUDE_ASM("nonmatchings/sdk/getallrefs", _copyAddRefImage);
INCLUDE_ASM("nonmatchings/sdk/getallrefs", _copyRefImage);
INCLUDE_ASM("nonmatchings/sdk/getallrefs", _ipuSetMPEG1);
INCLUDE_ASM("nonmatchings/sdk/getallrefs", _waitBdecOut);
extern int _ipuVdec(int, int);
int _dmVector(int a) { return _ipuVdec(a, 3); }
INCLUDE_ASM("nonmatchings/sdk/getallrefs", _dualPrimeVector);
INCLUDE_ASM("nonmatchings/sdk/getallrefs", _mbAddressIncrement);
INCLUDE_ASM("nonmatchings/sdk/getallrefs", _pictureData0);
INCLUDE_ASM("nonmatchings/sdk/getallrefs", _sliceA0);
INCLUDE_ASM("nonmatchings/sdk/getallrefs", _slice0);
INCLUDE_ASM("nonmatchings/sdk/getallrefs", _skipMB0);
INCLUDE_ASM("nonmatchings/sdk/getallrefs", _decMB0);
INCLUDE_ASM("nonmatchings/sdk/getallrefs", _decode_motion_vector);
INCLUDE_ASM("nonmatchings/sdk/getallrefs", _motionVectors);
INCLUDE_ASM("nonmatchings/sdk/getallrefs", _motionVector);
INCLUDE_ASM("nonmatchings/sdk/getallrefs", _sendIpuCommand);
INCLUDE_ASM("nonmatchings/sdk/getallrefs", _waitIpuIdle);
INCLUDE_ASM("nonmatchings/sdk/getallrefs", _waitIpuIdle64);
INCLUDE_ASM("nonmatchings/sdk/getallrefs", _ipuVdec);
INCLUDE_ASM("nonmatchings/sdk/getallrefs", _peepBit);
INCLUDE_ASM("nonmatchings/sdk/getallrefs", _flushBuf);
INCLUDE_ASM("nonmatchings/sdk/getallrefs", _nextBit);
INCLUDE_ASM("nonmatchings/sdk/getallrefs", _nextStartCode);
INCLUDE_ASM("nonmatchings/sdk/getallrefs", _sliceB);
INCLUDE_ASM("nonmatchings/sdk/getallrefs", _nextHeader);
INCLUDE_ASM("nonmatchings/sdk/getallrefs", _pictureHeader);
INCLUDE_ASM("nonmatchings/sdk/getallrefs", _extensionAndUserData);
INCLUDE_ASM("nonmatchings/sdk/getallrefs", _pictureCodingExtension);
INCLUDE_ASM("nonmatchings/sdk/getallrefs", _extrainfo);
INCLUDE_ASM("nonmatchings/sdk/getallrefs", _updateTempTackData);
INCLUDE_ASM("nonmatchings/sdk/getallrefs", _groupOfPicturesHeader);
INCLUDE_ASM("nonmatchings/sdk/getallrefs", _quantMatrixExtension);
INCLUDE_ASM("nonmatchings/sdk/getallrefs", _pictureDisplayExtension);
INCLUDE_ASM("nonmatchings/sdk/getallrefs", _copyrightExtension);
INCLUDE_ASM("nonmatchings/sdk/getallrefs", _decPicture);
INCLUDE_ASM("nonmatchings/sdk/getallrefs", _outputFrame);
INCLUDE_ASM("nonmatchings/sdk/getallrefs", _updateRefImage);
INCLUDE_ASM("nonmatchings/sdk/getallrefs", _isOutSizeOK);
INCLUDE_ASM("nonmatchings/sdk/getallrefs", _cpr8);
INCLUDE_ASM("nonmatchings/sdk/getallrefs", _markOutput);
INCLUDE_ASM("nonmatchings/sdk/getallrefs", _getPtsDtsFlags);
INCLUDE_ASM("nonmatchings/sdk/getallrefs", _dispRefImage);
INCLUDE_ASM("nonmatchings/sdk/getallrefs", _dispRefImageField);
INCLUDE_ASM("nonmatchings/sdk/getallrefs", dmaRefImage);
INCLUDE_ASM("nonmatchings/sdk/getallrefs", receiveDataFromIPU);
