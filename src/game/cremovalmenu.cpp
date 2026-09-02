/* CRemovalMenu, CInventUserData, CInventDataManage, CScoopDataManager, CDC2AlbumData, CCharaFrameMatching, CBaseMenuClass
 *
 * Unité découpée par `make carve` : 75 fonctions, 18696 octets, de
 * 0x001FD400 à 0x00201EE0. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"
#include "gen/CCharaFrameMatching.hpp"

INCLUDE_ASM("nonmatchings/game/cremovalmenu", MenuGeoramaMakePush__FP12CMenuGeoramaii);
INCLUDE_ASM("nonmatchings/game/cremovalmenu", MenuGeoramaCheckPointPush__FP12CMenuGeoramaii);
INCLUDE_ASM("nonmatchings/game/cremovalmenu", MenuGeoramaAnalyzeSelect__FP12CMenuGeoramaii);
INCLUDE_ASM("nonmatchings/game/cremovalmenu", MenuGeoramaPaintSelect__FP12CMenuGeoramaii);
INCLUDE_ASM("nonmatchings/game/cremovalmenu", MenuGeoramaPushKey__Fii);
INCLUDE_ASM("nonmatchings/game/cremovalmenu", MakeNPCList__12CRemovalMenuFv);
INCLUDE_ASM("nonmatchings/game/cremovalmenu", KeyStep__12CRemovalMenuFv);
INCLUDE_ASM("nonmatchings/game/cremovalmenu", MenuRemovalInit__FP9mgCMemoryPi);
void CCharaFrameMatching::Initialize(void) {
    this->field_0x0 = 0;
    this->field_0x8 = 0;
    this->field_0x4 = 0;
}
INCLUDE_ASM("nonmatchings/game/cremovalmenu", MenuRemovalKey__Fv);
INCLUDE_ASM("nonmatchings/game/cremovalmenu", MenuRemovalDraw__Fv);
INCLUDE_ASM("nonmatchings/game/cremovalmenu", InitEnd__14CBaseMenuClassFv);
INCLUDE_ASM("nonmatchings/game/cremovalmenu", GetInventUserDataPtr__Fv);
INCLUDE_ASM("nonmatchings/game/cremovalmenu", Init_USER_PICTURE_INFO__FP17USER_PICTURE_INFO);
INCLUDE_ASM("nonmatchings/game/cremovalmenu", Copy_USER_PICTURE_INFO__FP17USER_PICTURE_INFOP17USER_PICTURE_INFO);
INCLUDE_ASM("nonmatchings/game/cremovalmenu", PictureSeiton__FP17USER_PICTURE_INFOPci);
INCLUDE_ASM("nonmatchings/game/cremovalmenu", AttachPictTex__FiPP10mgCTextureP17USER_PICTURE_INFOi);
INCLUDE_ASM("nonmatchings/game/cremovalmenu", CheckPhotoDataNoNeed__FP17USER_PICTURE_INFOiPi);
INCLUDE_ASM("nonmatchings/game/cremovalmenu", IsTakePhoto__Fv);
INCLUDE_ASM("nonmatchings/game/cremovalmenu", Initialize__13CDC2AlbumDataFv);
INCLUDE_ASM("nonmatchings/game/cremovalmenu", RelateAlbumPicData__13CDC2AlbumDataFv);
INCLUDE_ASM("nonmatchings/game/cremovalmenu", DeletePhotoData__13CDC2AlbumDataFi);
INCLUDE_ASM("nonmatchings/game/cremovalmenu", GetAlbumPhotoInfo__13CDC2AlbumDataFi);
INCLUDE_ASM("nonmatchings/game/cremovalmenu", Initialize__15CInventUserDataFv);
INCLUDE_ASM("nonmatchings/game/cremovalmenu", ResetAddress__15CInventUserDataFv);
INCLUDE_ASM("nonmatchings/game/cremovalmenu", PhotoCheckEnd__15CInventUserDataFv);
INCLUDE_ASM("nonmatchings/game/cremovalmenu", GetPhotoInfo__15CInventUserDataFi);
INCLUDE_ASM("nonmatchings/game/cremovalmenu", GetPhototWorkAdr__15CInventUserDataFv);
INCLUDE_ASM("nonmatchings/game/cremovalmenu", IsPhotoSpace__15CInventUserDataFPi);
INCLUDE_ASM("nonmatchings/game/cremovalmenu", DeletePhotoData__15CInventUserDataFi);
INCLUDE_ASM("nonmatchings/game/cremovalmenu", CheckNetaFlag__15CInventUserDataFi);
INCLUDE_ASM("nonmatchings/game/cremovalmenu", GetNetaID__15CInventUserDataFi);
INCLUDE_ASM("nonmatchings/game/cremovalmenu", SetNetaFlag__15CInventUserDataFi);
INCLUDE_ASM("nonmatchings/game/cremovalmenu", CheckNetaFlagHavePhoto__15CInventUserDataFi);
INCLUDE_ASM("nonmatchings/game/cremovalmenu", CountNeta__15CInventUserDataFv);
INCLUDE_ASM("nonmatchings/game/cremovalmenu", CountScoop__15CInventUserDataFv);
INCLUDE_ASM("nonmatchings/game/cremovalmenu", AddShutterNum__15CInventUserDataFi);
INCLUDE_ASM("nonmatchings/game/cremovalmenu", GetNowHavePictureNum__15CInventUserDataFv);
INCLUDE_ASM("nonmatchings/game/cremovalmenu", GetPictureNum__15CInventUserDataFPi);
INCLUDE_ASM("nonmatchings/game/cremovalmenu", CalcPhotoExp__15CInventUserDataFv);
INCLUDE_ASM("nonmatchings/game/cremovalmenu", LevelCheck__15CInventUserDataFP17USER_PICTURE_INFO);
INCLUDE_ASM("nonmatchings/game/cremovalmenu", GetLevel__15CInventUserDataFv);
INCLUDE_ASM("nonmatchings/game/cremovalmenu", SetCreateItemFlag__15CInventUserDataFii);
INCLUDE_ASM("nonmatchings/game/cremovalmenu", GetCreateItemID__15CInventUserDataFi);
INCLUDE_ASM("nonmatchings/game/cremovalmenu", IsAlreadyCreatedItem__15CInventUserDataFi);
INCLUDE_ASM("nonmatchings/game/cremovalmenu", GetHatsumeiNum__15CInventUserDataFv);
INCLUDE_ASM("nonmatchings/game/cremovalmenu", TranslateInventUserData__FP15CInventUserDataP15CInventUserData);
INCLUDE_ASM("nonmatchings/game/cremovalmenu", GetScoopDataTable__Fi);
INCLUDE_ASM("nonmatchings/game/cremovalmenu", GetScoopDataTableIndex__Fi);
INCLUDE_ASM("nonmatchings/game/cremovalmenu", InitScoopString__Fv);
INCLUDE_ASM("nonmatchings/game/cremovalmenu", _SCOOP_STR__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cremovalmenu", AnalyzeScoopString__FP9mgCMemoryPci);
INCLUDE_ASM("nonmatchings/game/cremovalmenu", GetScoopInfo__17CScoopDataManagerFi);
INCLUDE_ASM("nonmatchings/game/cremovalmenu", SetViewFlag__17CScoopDataManagerFii);
INCLUDE_ASM("nonmatchings/game/cremovalmenu", KnowScoop__17CScoopDataManagerFv);
INCLUDE_ASM("nonmatchings/game/cremovalmenu", CheckScoop__17CScoopDataManagerFv);
INCLUDE_ASM("nonmatchings/game/cremovalmenu", GetScoopTotal__17CScoopDataManagerFPi);
INCLUDE_ASM("nonmatchings/game/cremovalmenu", _PIC_INFO__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cremovalmenu", _PIC_NAME__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cremovalmenu", LoadFilePictureName__Fv);
INCLUDE_ASM("nonmatchings/game/cremovalmenu", GetPhotoName__FP17USER_PICTURE_INFO);
INCLUDE_ASM("nonmatchings/game/cremovalmenu", GetPhotoNameStr__FiPc);
INCLUDE_ASM("nonmatchings/game/cremovalmenu", GetPhotoNameCheck__FP17USER_PICTURE_INFO);
INCLUDE_ASM("nonmatchings/game/cremovalmenu", CheckPhotoFlag__Fv);
INCLUDE_ASM("nonmatchings/game/cremovalmenu", GetInventDataInfoByItemID__17CInventDataManageFi);
INCLUDE_ASM("nonmatchings/game/cremovalmenu", CheckInventEnable__17CInventDataManageFPiPi);
INCLUDE_ASM("nonmatchings/game/cremovalmenu", HowMuchZairyouMakeItem__17CInventDataManageFiiPi);
INCLUDE_ASM("nonmatchings/game/cremovalmenu", DeleteUserUsedItem__17CInventDataManageFii);
INCLUDE_ASM("nonmatchings/game/cremovalmenu", CheckMakeItem__17CInventDataManageFiiP13CGameDataUsed);
INCLUDE_ASM("nonmatchings/game/cremovalmenu", _INVENT_DATATABLESET__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cremovalmenu", _INVENT_DATASET__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cremovalmenu", LoadAnalyzeInventFile__17CInventDataManageFPci);
INCLUDE_ASM("nonmatchings/game/cremovalmenu", CheckInventItem__Fi);
INCLUDE_ASM("nonmatchings/game/cremovalmenu", CheckItemTable__FiPi);
INCLUDE_ASM("nonmatchings/game/cremovalmenu", CheckInventPhoto__Fii);
