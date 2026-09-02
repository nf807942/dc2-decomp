/* CPosDataManage, CMenuPosDataManage, CRepairManager, CLevelUpEffect, CEffVerticalLine, CRepairEffect, CLevelUpEffectManager, CStarDust
 *
 * Unité découpée par `make carve` : 93 fonctions, 21036 octets, de
 * 0x0022C990 à 0x00231DD0. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"
#include "gen/CLevelUpEffect.hpp"
#include "gen/CRepairEffect.hpp"
#include "gen/CLevelUpEffect.hpp"

INCLUDE_ASM("nonmatchings/game/cposdatamanage", Initialize__14CPosDataManageFv);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", GetTexGetInfo__14CPosDataManageFi);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", GetTexGetInfo__14CPosDataManageFPc);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", GetTexGetInfoTblNo__14CPosDataManageFPc);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", TexGetInfoClear__14CPosDataManageFii);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", ResetTextureBlockNo__14CPosDataManageFPci);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", ResetTextureInfoAll__14CPosDataManageFv);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", EtcTblClear__14CPosDataManageFii);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", GetEtcTbl__14CPosDataManageFPc);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", GetEtcTblValue__14CPosDataManageFPcRiRi);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", GetEtcTbl2__14CPosDataManageFPc);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", GetEtcTbl2Value__14CPosDataManageFPcPfi);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", EtcTbl2Clear__14CPosDataManageFii);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", GetMenuMainIconChar__Fi);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", GetFormInfo__14CPosDataManageFPc);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", GetFormInfo__14CPosDataManageFi);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", FormInfoClear__14CPosDataManageFii);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", SetFormPos__14CPosDataManageFPcPi);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", InitDrawList__14CPosDataManageFv);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", GetDrawTopList__14CPosDataManageFv);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", FormReLink__14CPosDataManageFPcPc);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", FormReLink2__14CPosDataManageFPcPcPcPc);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", FormStep__14CPosDataManageFv);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", MenuDrawParamStep__Fv);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", FormDraw__14CPosDataManageFv);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", ClearPos__14CPosDataManageFv);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", AttachCommonTexInfo__18CMenuPosDataManageFv);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", StepMainMenuIconMove__18CMenuPosDataManageFPiii);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", CheckItemUseVariable__FP13CGameDataUsedP14CItemUseTarget);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", Func_MenuItemBrdPrepare__FP18MENUFORMPARTS_TYPEP13CGameDataUsedP13CGameDataUsedi);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", Func_MenuItemBrdPrepare2__FP18MENUFORMPARTS_TYPEP13CGameDataUsedP13CGameDataUsed);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", NowUseNeedItemCheck__FP16CUserDataManager);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", Func_MenuIconDrawPrepare__FP18MENUFORMPARTS_TYPEP13CGameDataUsedi);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", CheckItemBoardFunc_MenuIconDrawPrepare__FP16CUserDataManagerP18MENUFORMPARTS_TYPE);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", MenuItemBrdScrlBarStep__Fiii);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", Func_MenuItemBrdPosStep__Fi);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", GetPosMenuItemBrdKoma__18CMenuPosDataManageFPiii);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", GetPosMenuItemOnItemBrd__18CMenuPosDataManageFPiii);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", GetPosMenuItemBrdForEffect__18CMenuPosDataManageFPiii);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", Func_MenuItemIconSetEffectOne__FP18MENUFORMPARTS_TYPE);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", MenuItemBrdItemIconEffectMalloc__FP9mgCMemoryP18MENUFORMPARTS_TYPEi);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", MallocPallet__18CMenuPosDataManageFP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", SearchTransPalletNo__18CMenuPosDataManageFv);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", InitializeCMenuPosDataManage__18CMenuPosDataManageFv);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", MenuCapture__FiP9mgCMemoryi);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", SetBGFrameForMenu__FiPc);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", MenuFrameImageDraw__FP11mgCDrawPrimP10mgCTexture9mgRect_f_9mgRect_i_iii);
void CRepairEffect::Initialize(void) {
    this->field_0x0 = 0;
    this->field_0x18 = 0;
    this->field_0x1C = 0;
    this->field_0x20 = 0;
    this->field_0x4 = 0;
}
INCLUDE_ASM("nonmatchings/game/cposdatamanage", Generate__13CRepairEffectFP9mgCMemoryi);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", Step__13CRepairEffectFv);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", Draw__13CRepairEffectFv);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", Initialize__14CRepairManagerFv);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", SetStack__14CRepairManagerFP9mgCMemoryi);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", Clear__14CRepairManagerFv);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", LoadDataBG__14CRepairManagerFP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", CheckDataBG__14CRepairManagerFi);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", SetRepairData__14CRepairManagerFP9mgCMemoryiPUi);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", GeneratePoly__14CRepairManagerFPfi);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", Generate__14CRepairManagerFii);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", IsRunModel__14CRepairManagerFv);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", IsRun__14CRepairManagerFv);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", Step__14CRepairManagerFv);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", Draw__14CRepairManagerFv);
void CLevelUpEffect::Initialize(void) {
    this->field_0x0 = 0;
    this->field_0x24 = 0;
    this->field_0x20 = 0;
}
INCLUDE_ASM("nonmatchings/game/cposdatamanage", Generate__14CLevelUpEffectFP10mgCTextureiii);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", Generate__14CLevelUpEffectFP10mgCTextureiP11CCharacter2);
u8 CLevelUpEffect::IsRun(void) {
    return this->field_0x0;
}
INCLUDE_ASM("nonmatchings/game/cposdatamanage", Step__14CLevelUpEffectFv);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", Draw__14CLevelUpEffectFv);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", Initialize__21CLevelUpEffectManagerFv);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", IsRun__21CLevelUpEffectManagerFv);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", Generate__21CLevelUpEffectManagerFiii);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", Generate__21CLevelUpEffectManagerFiP11CCharacter2);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", Step__21CLevelUpEffectManagerFv);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", Draw__21CLevelUpEffectManagerFv);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", Generate__9CStarDustFiiii);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", Step__9CStarDustFv);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", Draw__9CStarDustFP10mgCTextureii);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", CheckNotRunStarDust__FP9CStarDusti);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", CheckRunStarDust__FP9CStarDusti);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", Generate__16CEffVerticalLineFPfff);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", Step__16CEffVerticalLineFv);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", Draw__16CEffVerticalLineFv);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", InitInitBuildUpInfoEffectPos__Fv);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", InitBuildUpInfoEffect__FP9mgCMemoryP10mgCTextureif);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", SetBuildUpInfoChara__FP11CCharacter2f);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", StepBuildUpInfoEffect__Fv);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", DrawBuildUpInfoEffect__Fv);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", InitFishBoiledEffect__FPiP10mgCTexture);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", StepFishBoiledEffect__Fv);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", DrawFishBoiledEffect__Fv);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", SetEffectSpectolBreak__FP9mgCMemoryP11CMenuEffecti);
INCLUDE_ASM("nonmatchings/game/cposdatamanage", SetEffectSpectolFusion__FP9mgCMemoryPP11CMenuEffectP13CGameDataUsedi);
