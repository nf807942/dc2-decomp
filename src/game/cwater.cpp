/* CWater, CMapSky, dbgCJISFont, CFireRaster, CRunScript, CWaterFrame, CThunderEffect
 *
 * Unité découpée par `make carve` : 72 fonctions, 16636 octets, de
 * 0x001846F0 à 0x00188970. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"
#include "gen/CWaterFrame.hpp"
#include "gen/dbgCJISFont.hpp"

INCLUDE_ASM("nonmatchings/game/cwater", Initialize__7CMapSkyFv);
INCLUDE_ASM("nonmatchings/game/cwater", DrawSkyBack__7CMapSkyFPfPfPf);
INCLUDE_ASM("nonmatchings/game/cwater", DrawSky__7CMapSkyFPfPfPfiPfPf);
INCLUDE_ASM("nonmatchings/game/cwater", LoadPack__7CMapSkyFPUiiP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/cwater", LoadSkyPack__FP12MAP_SKY_INFOPci);
INCLUDE_ASM("nonmatchings/game/cwater", CheckSkyID__Fi);
INCLUDE_ASM("nonmatchings/game/cwater", _SKY_IMG__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cwater", _SKY_MDS__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cwater", _SUN_MDS__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cwater", _SKYB_MDS__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cwater", _SKY_BG__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cwater", _SKY_ANIME__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cwater", _SKYB_ANIME__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/cwater", Step__11CFireRasterFv);
INCLUDE_ASM("nonmatchings/game/cwater", SetTexture__11CFireRasterFP10mgCTexture);
INCLUDE_ASM("nonmatchings/game/cwater", Draw__11CFireRasterFPfPf);
INCLUDE_ASM("nonmatchings/game/cwater", Initialize__11CFireRasterFv);
INCLUDE_ASM("nonmatchings/game/cwater", Init__14CThunderEffectFv);
INCLUDE_ASM("nonmatchings/game/cwater", Hamon__6CWaterFv);
INCLUDE_ASM("nonmatchings/game/cwater", SetVertex__6CWaterFPfPf);
INCLUDE_ASM("nonmatchings/game/cwater", Shake__6CWaterFiif);
INCLUDE_ASM("nonmatchings/game/cwater", Shake__11CWaterFrameFfff);
s32 CWaterFrame::GetWater(void) {
    return this->field_0xF8;
}
INCLUDE_ASM("nonmatchings/game/cwater", SetSize__6CWaterFiiP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/cwater", SetParam__6CWaterFffff);
INCLUDE_ASM("nonmatchings/game/cwater", SetColor__6CWaterFUcUcUcUc);
INCLUDE_ASM("nonmatchings/game/cwater", __ct__6CWaterFv);
INCLUDE_ASM("nonmatchings/game/cwater", CreateRenderInfoPacket__6CWaterFPUiPA4_fP13mgRENDER_INFO);
INCLUDE_ASM("nonmatchings/game/cwater", Draw__6CWaterFPUiPA4_fP14mgCDrawManager);
INCLUDE_ASM("nonmatchings/game/cwater", CreatePacket__6CWaterFP14mgCDrawManager);
INCLUDE_ASM("nonmatchings/game/cwater", SetTexture__11CWaterFrameFP10mgCTexture);
INCLUDE_ASM("nonmatchings/game/cwater", Step__11CWaterFrameFv);
INCLUDE_ASM("nonmatchings/game/cwater", SetParam__11CWaterFrameFffff);
INCLUDE_ASM("nonmatchings/game/cwater", SetColor__11CWaterFrameFUcUcUcUc);
INCLUDE_ASM("nonmatchings/game/cwater", Shake__11CWaterFrameFiif);
INCLUDE_ASM("nonmatchings/game/cwater", CreatePacket__11CWaterFrameFv);
INCLUDE_ASM("nonmatchings/game/cwater", CreateWaterFrame__FiiPfPfP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/cwater", Initialize__11CWaterFrameFv);
INCLUDE_ASM("nonmatchings/game/cwater", SjisToJis__FUl);
INCLUDE_ASM("nonmatchings/game/cwater", SjisToSerno__FUl);
INCLUDE_ASM("nonmatchings/game/cwater", ascii2serno__FUc);
INCLUDE_ASM("nonmatchings/game/cwater", __ct__11dbgCJISFontFv);
INCLUDE_ASM("nonmatchings/game/cwater", Initialize__11dbgCJISFontFv);
INCLUDE_ASM("nonmatchings/game/cwater", InitTexture__11dbgCJISFontFiPciPciPc);
void dbgCJISFont::Clear(void) {
    this->field_0x88 = 0;
}
INCLUDE_ASM("nonmatchings/game/cwater", __putc__11dbgCJISFontFUl);
INCLUDE_ASM("nonmatchings/game/cwater", PrintDirect__11dbgCJISFontFiiPce);
INCLUDE_ASM("nonmatchings/game/cwater", runerror__FPCc);
INCLUDE_ASM("nonmatchings/game/cwater", stkoverflow__Fv);
INCLUDE_ASM("nonmatchings/game/cwater", chk_int__F12RS_STACKDATAP8funcdata);
INCLUDE_ASM("nonmatchings/game/cwater", is_true__F12RS_STACKDATA);
INCLUDE_ASM("nonmatchings/game/cwater", divby0error__Fv);
INCLUDE_ASM("nonmatchings/game/cwater", modby0error__Fv);
INCLUDE_ASM("nonmatchings/game/cwater", print__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/cwater", __ct__10CRunScriptFv);
INCLUDE_ASM("nonmatchings/game/cwater", DeleteProgram__10CRunScriptFv);
INCLUDE_ASM("nonmatchings/game/cwater", check_stack__10CRunScriptFv);
INCLUDE_ASM("nonmatchings/game/cwater", push__10CRunScriptF12RS_STACKDATA);
INCLUDE_ASM("nonmatchings/game/cwater", push_int__10CRunScriptFi);
INCLUDE_ASM("nonmatchings/game/cwater", push_str__10CRunScriptFPc);
INCLUDE_ASM("nonmatchings/game/cwater", push_ptr__10CRunScriptFP12RS_STACKDATA);
INCLUDE_ASM("nonmatchings/game/cwater", push_float__10CRunScriptFf);
INCLUDE_ASM("nonmatchings/game/cwater", pop__10CRunScriptFv);
INCLUDE_ASM("nonmatchings/game/cwater", call_func__10CRunScriptFP8funcdataP8vmcode_t);
INCLUDE_ASM("nonmatchings/game/cwater", ret_func__10CRunScriptFv);
INCLUDE_ASM("nonmatchings/game/cwater", ext__10CRunScriptFP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/cwater", load__10CRunScriptFP14RS_PROG_HEADERP12RS_STACKDATAiP11RS_CALLDATAi);
INCLUDE_ASM("nonmatchings/game/cwater", ext_func__10CRunScriptFPPFP12RS_STACKDATAi_ii);
INCLUDE_ASM("nonmatchings/game/cwater", resume__10CRunScriptFv);
INCLUDE_ASM("nonmatchings/game/cwater", run__10CRunScriptFi);
INCLUDE_ASM("nonmatchings/game/cwater", check_program__10CRunScriptFi);
INCLUDE_ASM("nonmatchings/game/cwater", skip__10CRunScriptFv);
