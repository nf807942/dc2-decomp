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
struct inferred;
typedef struct USER_PICTURE_INFO {
    /* 0x0 */ s8 unk0;                              /* inferred */
    /* 0x1 */ s8 unk1;                              /* inferred */
    /* 0x2 */ s16 unk2;                             /* inferred */
    /* 0x4 */ s16 unk4;                             /* inferred */
    /* 0x6 */ s16 unk6;                             /* inferred */
    /* 0x8 */ s16 unk8;                             /* inferred */
    /* 0xA */ s16 unkA;                             /* inferred */
} USER_PICTURE_INFO;                                /* size >= 0xC */
extern "C" void Init_USER_PICTURE_INFO__FP17USER_PICTURE_INFO(USER_PICTURE_INFO *arg0) {
    if (arg0 != NULL) {
        arg0->unk0 = 0;
        arg0->unk1 = 0;
        arg0->unk2 = -1;
        arg0->unk4 = -1;
        arg0->unk8 = -1;
        arg0->unk6 = -1;
        arg0->unkA = 0;
    }
}
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
struct inferred;
typedef struct CInventUserData {
    /* 0x0 */ s32 unk0;                             /* inferred */
} CInventUserData;                                  /* size >= 0x4 */
extern "C" s32 AddShutterNum__15CInventUserDataFi(CInventUserData *objet, s32 arg0) {
    objet->unk0 += arg0;
    if (objet->unk0 > 0x1869F) {
        objet->unk0 = 0x1869F;
    }
    if (objet->unk0 < 0) {
        objet->unk0 = 0;
    }
    return objet->unk0;
}
INCLUDE_ASM("nonmatchings/game/cremovalmenu", GetNowHavePictureNum__15CInventUserDataFv);
struct arg0_champs {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
};
extern "C" s32 GetNowHavePictureNum__15CInventUserDataFv(void *);
extern "C" s32 GetPictureNum__15CInventUserDataFPi(CInventUserData *objet, struct arg0_champs *arg0) {
    arg0->unk0 = GetNowHavePictureNum__15CInventUserDataFv(objet);
    arg0->unk4 = 0x1E;
    return arg0->unk0;
}
struct calcul0_champs_896dfc {
    char pad0[0x44DD0];
    /* 0x44DD0 */ s32 unk44DD0;
};
extern "C" s32 GetUserDataMan__Fv(void);
extern "C" s32 CalcPhotoExp__15CInventUserDataFv(CInventUserData *objet) {
    s16 temp_v1;
    s32 temp_v0;
    s32 var_a0;
    s32 var_a1;
    s32 var_s0;

    var_s0 = 0;
    temp_v0 = GetUserDataMan__Fv();
    var_a0 = 0;
    var_a1 = 0;
    do {
        temp_v1 = ((struct calcul0_champs_896dfc *) (temp_v0 + var_a1))->unk44DD0;
        if (temp_v1 > 0) {
            if (temp_v1 < 0x3E8) {
                var_s0 += 2;
            } else {
                var_s0 += 5;
            }
        }
        var_a0 += 1;
        var_a1 += 2;
    } while (var_a0 < 0x200);
    return var_s0;
}
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
extern "C" s32 GetScoopInfo__17CScoopDataManagerFi(void *, s32);
struct CScoopDataManager;
extern "C" void SetViewFlag__17CScoopDataManagerFii(CScoopDataManager *objet, s32 arg0, s32 arg1) {
    s8 *temp_v0;

    temp_v0 = (s8 *) (GetScoopInfo__17CScoopDataManagerFi(objet, arg0));
    if (temp_v0 != NULL) {
        *temp_v0 = (s8) arg1;
    }
}
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
