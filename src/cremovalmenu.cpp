/* CRemovalMenu, CInventUserData, CInventDataManage, CScoopDataManager, CDC2AlbumData, CCharaFrameMatching, CBaseMenuClass
 *
 * Unité découpée par `make carve` : 75 fonctions, 18696 octets, de
 * 0x001FD400 à 0x00201EE0. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

INCLUDE_ASM("nonmatchings/cremovalmenu", MenuGeoramaMakePush__FP12CMenuGeoramaii);
INCLUDE_ASM("nonmatchings/cremovalmenu", MenuGeoramaCheckPointPush__FP12CMenuGeoramaii);
INCLUDE_ASM("nonmatchings/cremovalmenu", MenuGeoramaAnalyzeSelect__FP12CMenuGeoramaii);
INCLUDE_ASM("nonmatchings/cremovalmenu", MenuGeoramaPaintSelect__FP12CMenuGeoramaii);
INCLUDE_ASM("nonmatchings/cremovalmenu", MenuGeoramaPushKey__Fii);
INCLUDE_ASM("nonmatchings/cremovalmenu", MakeNPCList__12CRemovalMenuFv);
INCLUDE_ASM("nonmatchings/cremovalmenu", KeyStep__12CRemovalMenuFv);
INCLUDE_ASM("nonmatchings/cremovalmenu", MenuRemovalInit__FP9mgCMemoryPi);
INCLUDE_ASM("nonmatchings/cremovalmenu", Initialize__19CCharaFrameMatchingFv);
INCLUDE_ASM("nonmatchings/cremovalmenu", MenuRemovalKey__Fv);
INCLUDE_ASM("nonmatchings/cremovalmenu", MenuRemovalDraw__Fv);
INCLUDE_ASM("nonmatchings/cremovalmenu", InitEnd__14CBaseMenuClassFv);
INCLUDE_ASM("nonmatchings/cremovalmenu", GetInventUserDataPtr__Fv);
INCLUDE_ASM("nonmatchings/cremovalmenu", Init_USER_PICTURE_INFO__FP17USER_PICTURE_INFO);
INCLUDE_ASM("nonmatchings/cremovalmenu", Copy_USER_PICTURE_INFO__FP17USER_PICTURE_INFOP17USER_PICTURE_INFO);
INCLUDE_ASM("nonmatchings/cremovalmenu", PictureSeiton__FP17USER_PICTURE_INFOPci);
INCLUDE_ASM("nonmatchings/cremovalmenu", AttachPictTex__FiPP10mgCTextureP17USER_PICTURE_INFOi);
INCLUDE_ASM("nonmatchings/cremovalmenu", CheckPhotoDataNoNeed__FP17USER_PICTURE_INFOiPi);
INCLUDE_ASM("nonmatchings/cremovalmenu", IsTakePhoto__Fv);
INCLUDE_ASM("nonmatchings/cremovalmenu", Initialize__13CDC2AlbumDataFv);
INCLUDE_ASM("nonmatchings/cremovalmenu", RelateAlbumPicData__13CDC2AlbumDataFv);
INCLUDE_ASM("nonmatchings/cremovalmenu", DeletePhotoData__13CDC2AlbumDataFi);
INCLUDE_ASM("nonmatchings/cremovalmenu", GetAlbumPhotoInfo__13CDC2AlbumDataFi);
INCLUDE_ASM("nonmatchings/cremovalmenu", Initialize__15CInventUserDataFv);
INCLUDE_ASM("nonmatchings/cremovalmenu", ResetAddress__15CInventUserDataFv);
INCLUDE_ASM("nonmatchings/cremovalmenu", PhotoCheckEnd__15CInventUserDataFv);
INCLUDE_ASM("nonmatchings/cremovalmenu", GetPhotoInfo__15CInventUserDataFi);
INCLUDE_ASM("nonmatchings/cremovalmenu", GetPhototWorkAdr__15CInventUserDataFv);
INCLUDE_ASM("nonmatchings/cremovalmenu", IsPhotoSpace__15CInventUserDataFPi);
INCLUDE_ASM("nonmatchings/cremovalmenu", DeletePhotoData__15CInventUserDataFi);
INCLUDE_ASM("nonmatchings/cremovalmenu", CheckNetaFlag__15CInventUserDataFi);
INCLUDE_ASM("nonmatchings/cremovalmenu", GetNetaID__15CInventUserDataFi);
INCLUDE_ASM("nonmatchings/cremovalmenu", SetNetaFlag__15CInventUserDataFi);
INCLUDE_ASM("nonmatchings/cremovalmenu", CheckNetaFlagHavePhoto__15CInventUserDataFi);
INCLUDE_ASM("nonmatchings/cremovalmenu", CountNeta__15CInventUserDataFv);
INCLUDE_ASM("nonmatchings/cremovalmenu", CountScoop__15CInventUserDataFv);
INCLUDE_ASM("nonmatchings/cremovalmenu", AddShutterNum__15CInventUserDataFi);
INCLUDE_ASM("nonmatchings/cremovalmenu", GetNowHavePictureNum__15CInventUserDataFv);
INCLUDE_ASM("nonmatchings/cremovalmenu", GetPictureNum__15CInventUserDataFPi);
INCLUDE_ASM("nonmatchings/cremovalmenu", CalcPhotoExp__15CInventUserDataFv);
INCLUDE_ASM("nonmatchings/cremovalmenu", LevelCheck__15CInventUserDataFP17USER_PICTURE_INFO);
INCLUDE_ASM("nonmatchings/cremovalmenu", GetLevel__15CInventUserDataFv);
INCLUDE_ASM("nonmatchings/cremovalmenu", SetCreateItemFlag__15CInventUserDataFii);
INCLUDE_ASM("nonmatchings/cremovalmenu", GetCreateItemID__15CInventUserDataFi);
INCLUDE_ASM("nonmatchings/cremovalmenu", IsAlreadyCreatedItem__15CInventUserDataFi);
INCLUDE_ASM("nonmatchings/cremovalmenu", GetHatsumeiNum__15CInventUserDataFv);
INCLUDE_ASM("nonmatchings/cremovalmenu", TranslateInventUserData__FP15CInventUserDataP15CInventUserData);
INCLUDE_ASM("nonmatchings/cremovalmenu", GetScoopDataTable__Fi);
INCLUDE_ASM("nonmatchings/cremovalmenu", GetScoopDataTableIndex__Fi);
INCLUDE_ASM("nonmatchings/cremovalmenu", InitScoopString__Fv);
INCLUDE_ASM("nonmatchings/cremovalmenu", _SCOOP_STR__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/cremovalmenu", AnalyzeScoopString__FP9mgCMemoryPci);
INCLUDE_ASM("nonmatchings/cremovalmenu", GetScoopInfo__17CScoopDataManagerFi);
INCLUDE_ASM("nonmatchings/cremovalmenu", SetViewFlag__17CScoopDataManagerFii);
INCLUDE_ASM("nonmatchings/cremovalmenu", KnowScoop__17CScoopDataManagerFv);
INCLUDE_ASM("nonmatchings/cremovalmenu", CheckScoop__17CScoopDataManagerFv);
INCLUDE_ASM("nonmatchings/cremovalmenu", GetScoopTotal__17CScoopDataManagerFPi);
INCLUDE_ASM("nonmatchings/cremovalmenu", _PIC_INFO__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/cremovalmenu", _PIC_NAME__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/cremovalmenu", LoadFilePictureName__Fv);
INCLUDE_ASM("nonmatchings/cremovalmenu", GetPhotoName__FP17USER_PICTURE_INFO);
INCLUDE_ASM("nonmatchings/cremovalmenu", GetPhotoNameStr__FiPc);
INCLUDE_ASM("nonmatchings/cremovalmenu", GetPhotoNameCheck__FP17USER_PICTURE_INFO);
INCLUDE_ASM("nonmatchings/cremovalmenu", CheckPhotoFlag__Fv);
INCLUDE_ASM("nonmatchings/cremovalmenu", GetInventDataInfoByItemID__17CInventDataManageFi);
INCLUDE_ASM("nonmatchings/cremovalmenu", CheckInventEnable__17CInventDataManageFPiPi);
INCLUDE_ASM("nonmatchings/cremovalmenu", HowMuchZairyouMakeItem__17CInventDataManageFiiPi);
INCLUDE_ASM("nonmatchings/cremovalmenu", DeleteUserUsedItem__17CInventDataManageFii);
INCLUDE_ASM("nonmatchings/cremovalmenu", CheckMakeItem__17CInventDataManageFiiP13CGameDataUsed);
INCLUDE_ASM("nonmatchings/cremovalmenu", _INVENT_DATATABLESET__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/cremovalmenu", _INVENT_DATASET__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/cremovalmenu", LoadAnalyzeInventFile__17CInventDataManageFPci);
INCLUDE_ASM("nonmatchings/cremovalmenu", CheckInventItem__Fi);
INCLUDE_ASM("nonmatchings/cremovalmenu", CheckItemTable__FiPi);
INCLUDE_ASM("nonmatchings/cremovalmenu", CheckInventPhoto__Fii);
