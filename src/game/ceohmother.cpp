/* CEohMother, CScreenEffect, CRaster, CEventScriptArg
 *
 * Unité découpée par `make carve` : 122 fonctions, 24576 octets, de
 * 0x00260B80 à 0x00266E10. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"
#include "gen/EdEventInfoData.hpp"
#include "gen/CRaster.hpp"
extern EdEventInfoData EdEventInfo;


INCLUDE_ASM("nonmatchings/game/ceohmother", CalcPosWorldCoordGyaku__FPf);
INCLUDE_ASM("nonmatchings/game/ceohmother", SetCamWorldCoord__FP9mgCCamera);
INCLUDE_ASM("nonmatchings/game/ceohmother", SetCamWorldCoordGyaku__FP9mgCCamera);
INCLUDE_ASM("nonmatchings/game/ceohmother", __ct__10CEohMotherFv);
INCLUDE_ASM("nonmatchings/game/ceohmother", Set__10CEohMotherFiiP7CObjecti);
INCLUDE_ASM("nonmatchings/game/ceohmother", Set__10CEohMotherFiiiP11CCharacter2);
INCLUDE_ASM("nonmatchings/game/ceohmother", Set__10CEohMotherFiiP13CEventSprite2);
INCLUDE_ASM("nonmatchings/game/ceohmother", Set__10CEohMotherFiiP8mgCFrame);
INCLUDE_ASM("nonmatchings/game/ceohmother", Set__10CEohMotherFiiP10CFuncPoint);
INCLUDE_ASM("nonmatchings/game/ceohmother", SetPos__10CEohMotherFifff);
INCLUDE_ASM("nonmatchings/game/ceohmother", SetRot__10CEohMotherFifff);
INCLUDE_ASM("nonmatchings/game/ceohmother", GetPos__10CEohMotherFiPf);
INCLUDE_ASM("nonmatchings/game/ceohmother", GetRot__10CEohMotherFiPf);
INCLUDE_ASM("nonmatchings/game/ceohmother", SetMotion__10CEohMotherFiPcif);
INCLUDE_ASM("nonmatchings/game/ceohmother", CheckMotionEnd__10CEohMotherFi);
INCLUDE_ASM("nonmatchings/game/ceohmother", SetMotionTrg__10CEohMotherFi);
INCLUDE_ASM("nonmatchings/game/ceohmother", GetSeqStatus__10CEohMotherFi);
INCLUDE_ASM("nonmatchings/game/ceohmother", SetStep__10CEohMotherFif);
INCLUDE_ASM("nonmatchings/game/ceohmother", SetChangeStep__10CEohMotherFif);
INCLUDE_ASM("nonmatchings/game/ceohmother", ResetMotion__10CEohMotherFi);
INCLUDE_ASM("nonmatchings/game/ceohmother", SetTexAnim__10CEohMotherFiiPc);
INCLUDE_ASM("nonmatchings/game/ceohmother", SetScale__10CEohMotherFifff);
INCLUDE_ASM("nonmatchings/game/ceohmother", GetScale__10CEohMotherFiPf);
INCLUDE_ASM("nonmatchings/game/ceohmother", SetShow__10CEohMotherFii);
INCLUDE_ASM("nonmatchings/game/ceohmother", GetShow__10CEohMotherFiPi);
INCLUDE_ASM("nonmatchings/game/ceohmother", SearchFrame__10CEohMotherFiPc);
INCLUDE_ASM("nonmatchings/game/ceohmother", SetFrameShow__10CEohMotherFiPci);
INCLUDE_ASM("nonmatchings/game/ceohmother", SetShadow__10CEohMotherFii);
INCLUDE_ASM("nonmatchings/game/ceohmother", SetShadowFrameShow__10CEohMotherFiPci);
INCLUDE_ASM("nonmatchings/game/ceohmother", SetTranslate__10CEohMotherFiPf);
INCLUDE_ASM("nonmatchings/game/ceohmother", SetColor__10CEohMotherFiPf);
INCLUDE_ASM("nonmatchings/game/ceohmother", GetColor__10CEohMotherFiPf);
INCLUDE_ASM("nonmatchings/game/ceohmother", GetNowMotionName__10CEohMotherFi);
INCLUDE_ASM("nonmatchings/game/ceohmother", GetNowMotionStatus__10CEohMotherFi);
INCLUDE_ASM("nonmatchings/game/ceohmother", SetMotionNowTime__10CEohMotherFif);
INCLUDE_ASM("nonmatchings/game/ceohmother", SetMotionWaitTime__10CEohMotherFif);
INCLUDE_ASM("nonmatchings/game/ceohmother", SetFootSoundID__10CEohMotherFii);
INCLUDE_ASM("nonmatchings/game/ceohmother", GetFramePos__10CEohMotherFiPcPf);
INCLUDE_ASM("nonmatchings/game/ceohmother", SetSoundID__10CEohMotherFiUi);
INCLUDE_ASM("nonmatchings/game/ceohmother", GetFrameShow__10CEohMotherFiPc);
INCLUDE_ASM("nonmatchings/game/ceohmother", SetFadeFlag__10CEohMotherFii);
INCLUDE_ASM("nonmatchings/game/ceohmother", ResetDAPosition__10CEohMotherFi);
INCLUDE_ASM("nonmatchings/game/ceohmother", NormalDrive__10CEohMotherFi);
INCLUDE_ASM("nonmatchings/game/ceohmother", UpdatePosition__10CEohMotherFi);
INCLUDE_ASM("nonmatchings/game/ceohmother", SetFrameObjAlpha__10CEohMotherFiPcf);
INCLUDE_ASM("nonmatchings/game/ceohmother", SetFootSeId__10CEohMotherFii);
INCLUDE_ASM("nonmatchings/game/ceohmother", FileNameConvLanguage__FPc);
INCLUDE_ASM("nonmatchings/game/ceohmother", GetStackInt__FP12RS_STACKDATA_00262DA0);
INCLUDE_ASM("nonmatchings/game/ceohmother", GetStackFloat__FP12RS_STACKDATA_00262DE0);
INCLUDE_ASM("nonmatchings/game/ceohmother", GetStackVector__FPfP12RS_STACKDATA_00262E10);
INCLUDE_ASM("nonmatchings/game/ceohmother", GetStackString__FP12RS_STACKDATA_00262E60);
INCLUDE_ASM("nonmatchings/game/ceohmother", SetStack__FP12RS_STACKDATAi_00262E70);
INCLUDE_ASM("nonmatchings/game/ceohmother", SetStack__FP12RS_STACKDATAf_00262E90);
INCLUDE_ASM("nonmatchings/game/ceohmother", BuildArgData__15CEventScriptArgFPUi);
INCLUDE_ASM("nonmatchings/game/ceohmother", _DATA__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/ceohmother", _ID_OFFSET__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/ceohmother", GetArgInt__FP8ARG_DATA);
INCLUDE_ASM("nonmatchings/game/ceohmother", GetArgFloat__FP8ARG_DATA);
INCLUDE_ASM("nonmatchings/game/ceohmother", GetArgString__FP8ARG_DATA);
INCLUDE_ASM("nonmatchings/game/ceohmother", GetArgVector__FPfP8ARG_DATA);
void CRaster::Initialize(void) {
    this->field_0x0 = 0;
    this->field_0x8 = 0;
    this->field_0x4 = 0;
    this->field_0x10 = 0;
    this->field_0xC = 0;
    this->field_0x18 = 0;
    this->field_0x14 = 0;
    this->field_0x20 = 0;
    this->field_0x1C = 0;
    this->field_0x24 = -1;
    this->field_0x28 = 0;
}
INCLUDE_ASM("nonmatchings/game/ceohmother", SetParam__7CRasterFfff);
INCLUDE_ASM("nonmatchings/game/ceohmother", StartRaster__7CRasterFfffi);
INCLUDE_ASM("nonmatchings/game/ceohmother", StopRaster__7CRasterFfffi);
INCLUDE_ASM("nonmatchings/game/ceohmother", StepRaster__7CRasterFv);
INCLUDE_ASM("nonmatchings/game/ceohmother", DrawRaster__7CRasterFv);
INCLUDE_ASM("nonmatchings/game/ceohmother", Initialize__13CScreenEffectFv);
INCLUDE_ASM("nonmatchings/game/ceohmother", Step__13CScreenEffectFv);
INCLUDE_ASM("nonmatchings/game/ceohmother", Draw__13CScreenEffectFv);
INCLUDE_ASM("nonmatchings/game/ceohmother", InitRaster__13CScreenEffectFfff);
INCLUDE_ASM("nonmatchings/game/ceohmother", StartRaster__13CScreenEffectFfffi);
INCLUDE_ASM("nonmatchings/game/ceohmother", StopRaster__13CScreenEffectFfffi);
INCLUDE_ASM("nonmatchings/game/ceohmother", SetSepiaTexture__13CScreenEffectFP10mgCTextureP1);
INCLUDE_ASM("nonmatchings/game/ceohmother", CaptureSepiaScreen__13CScreenEffectFv);
INCLUDE_ASM("nonmatchings/game/ceohmother", SetSepiaFlag__13CScreenEffectFi);
INCLUDE_ASM("nonmatchings/game/ceohmother", SetMonoFlashTexture__13CScreenEffectFPP10mgCTexturePP1);
INCLUDE_ASM("nonmatchings/game/ceohmother", CaptureMonoFlashScreen__13CScreenEffectFv);
INCLUDE_ASM("nonmatchings/game/ceohmother", SetMonoFlashFlag__13CScreenEffectFii);
INCLUDE_ASM("nonmatchings/game/ceohmother", InitWorldCoord__Fv);
INCLUDE_ASM("nonmatchings/game/ceohmother", GetLocalFlag__Fi);
INCLUDE_ASM("nonmatchings/game/ceohmother", SetLocalFlag__Fii);
INCLUDE_ASM("nonmatchings/game/ceohmother", GetLocalCnt__Fi);
INCLUDE_ASM("nonmatchings/game/ceohmother", SetLocalCnt__Fii);
INCLUDE_ASM("nonmatchings/game/ceohmother", GetLocalCnt2__Fi);
INCLUDE_ASM("nonmatchings/game/ceohmother", InitLocalCnt__Fv);
INCLUDE_ASM("nonmatchings/game/ceohmother", EdEventInfoCommandInitialize__Fv);
INCLUDE_ASM("nonmatchings/game/ceohmother", EventSeqInit__Fv);
INCLUDE_ASM("nonmatchings/game/ceohmother", EdEventInit__Fv);
INCLUDE_ASM("nonmatchings/game/ceohmother", EventTimeDraw__Fv);
INCLUDE_ASM("nonmatchings/game/ceohmother", EdEventDraw__Fv);
INCLUDE_ASM("nonmatchings/game/ceohmother", EdEventFirstDraw__Fv);
INCLUDE_ASM("nonmatchings/game/ceohmother", EdEventFinish__Fv);
INCLUDE_ASM("nonmatchings/game/ceohmother", EdEventStep__Fv);
void InitDramaScene(void) {
    EdEventInfo.field_0xE0 = 0;
    EdEventInfo.field_0xE4 = 0;
    EdEventInfo.field_0xD4 = 1;
    EdEventInfo.field_0xD8 = 15;
    EdEventInfo.field_0xE8 = 0;
    EdEventInfo.field_0xEC = 0;
}
void CancelDramaScene(void) {
    EdEventInfo.field_0xD4 = 0;
}
INCLUDE_ASM("nonmatchings/game/ceohmother", EdEventMenuExit__Fv);
INCLUDE_ASM("nonmatchings/game/ceohmother", EdEventLoopInit__Fv);
void EdSetBrokenObject(void) {
}
INCLUDE_ASM("nonmatchings/game/ceohmother", ResetMesFileBuffAll__Fv);
INCLUDE_ASM("nonmatchings/game/ceohmother", EdEventMapInit__Fv);
INCLUDE_ASM("nonmatchings/game/ceohmother", EdEventTermination__Fv);
INCLUDE_ASM("nonmatchings/game/ceohmother", EdEventEnd__Fv);
INCLUDE_ASM("nonmatchings/game/ceohmother", GetObjSeq__Fi);
INCLUDE_ASM("nonmatchings/game/ceohmother", _GET_PADON__FP12RS_STACKDATAi_00266260);
INCLUDE_ASM("nonmatchings/game/ceohmother", _GET_PADDOWN__FP12RS_STACKDATAi_002662B0);
INCLUDE_ASM("nonmatchings/game/ceohmother", _GET_PADUP__FP12RS_STACKDATAi_00266300);
INCLUDE_ASM("nonmatchings/game/ceohmother", _GET_APAD__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/ceohmother", CheckLoadedBGFile__FPcPi);
INCLUDE_ASM("nonmatchings/game/ceohmother", GetLoadBGBuff__FPcPi);
INCLUDE_ASM("nonmatchings/game/ceohmother", _GOTO_INTERIOR__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/ceohmother", _GOTO_OUTSIDE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/ceohmother", _INITIALIZE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/ceohmother", _LOAD_CHARA_sub__FiPPciPUii);
INCLUDE_ASM("nonmatchings/game/ceohmother", _LOAD_CHARA_sub__FiPPciPUi);
INCLUDE_ASM("nonmatchings/game/ceohmother", _LOAD_CHARA__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/ceohmother", _CHARA_ACTIVE__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/ceohmother", _CLEAR_STACK__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/ceohmother", _ASSIGN_STACK__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/ceohmother", _SET_FLAG__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/ceohmother", _GET_FLAG__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/ceohmother", _SET_CNT__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/ceohmother", _GET_CNT__FP12RS_STACKDATAi);
