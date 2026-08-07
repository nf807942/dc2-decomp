/* CWater, CMapSky, dbgCJISFont, CFireRaster, CRunScript, CWaterFrame, CThunderEffect
 *
 * Unité découpée par `make carve` : 72 fonctions, 16636 octets, de
 * 0x001846F0 à 0x00188970. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

INCLUDE_ASM("nonmatchings/cwater", Initialize__7CMapSkyFv);
INCLUDE_ASM("nonmatchings/cwater", DrawSkyBack__7CMapSkyFPfPfPf);
INCLUDE_ASM("nonmatchings/cwater", DrawSky__7CMapSkyFPfPfPfiPfPf);
INCLUDE_ASM("nonmatchings/cwater", LoadPack__7CMapSkyFPUiiP9mgCMemory);
INCLUDE_ASM("nonmatchings/cwater", LoadSkyPack__FP12MAP_SKY_INFOPci);
INCLUDE_ASM("nonmatchings/cwater", CheckSkyID__Fi);
INCLUDE_ASM("nonmatchings/cwater", _SKY_IMG__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/cwater", _SKY_MDS__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/cwater", _SUN_MDS__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/cwater", _SKYB_MDS__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/cwater", _SKY_BG__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/cwater", _SKY_ANIME__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/cwater", _SKYB_ANIME__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/cwater", Step__11CFireRasterFv);
INCLUDE_ASM("nonmatchings/cwater", SetTexture__11CFireRasterFP10mgCTexture);
INCLUDE_ASM("nonmatchings/cwater", Draw__11CFireRasterFPfPf);
INCLUDE_ASM("nonmatchings/cwater", Initialize__11CFireRasterFv);
INCLUDE_ASM("nonmatchings/cwater", Init__14CThunderEffectFv);
INCLUDE_ASM("nonmatchings/cwater", Hamon__6CWaterFv);
INCLUDE_ASM("nonmatchings/cwater", SetVertex__6CWaterFPfPf);
INCLUDE_ASM("nonmatchings/cwater", Shake__6CWaterFiif);
INCLUDE_ASM("nonmatchings/cwater", Shake__11CWaterFrameFfff);
INCLUDE_ASM("nonmatchings/cwater", GetWater__11CWaterFrameFv);
INCLUDE_ASM("nonmatchings/cwater", SetSize__6CWaterFiiP9mgCMemory);
INCLUDE_ASM("nonmatchings/cwater", SetParam__6CWaterFffff);
INCLUDE_ASM("nonmatchings/cwater", SetColor__6CWaterFUcUcUcUc);
INCLUDE_ASM("nonmatchings/cwater", __ct__6CWaterFv);
INCLUDE_ASM("nonmatchings/cwater", CreateRenderInfoPacket__6CWaterFPUiPA4_fP13mgRENDER_INFO);
INCLUDE_ASM("nonmatchings/cwater", Draw__6CWaterFPUiPA4_fP14mgCDrawManager);
INCLUDE_ASM("nonmatchings/cwater", CreatePacket__6CWaterFP14mgCDrawManager);
INCLUDE_ASM("nonmatchings/cwater", SetTexture__11CWaterFrameFP10mgCTexture);
INCLUDE_ASM("nonmatchings/cwater", Step__11CWaterFrameFv);
INCLUDE_ASM("nonmatchings/cwater", SetParam__11CWaterFrameFffff);
INCLUDE_ASM("nonmatchings/cwater", SetColor__11CWaterFrameFUcUcUcUc);
INCLUDE_ASM("nonmatchings/cwater", Shake__11CWaterFrameFiif);
INCLUDE_ASM("nonmatchings/cwater", CreatePacket__11CWaterFrameFv);
INCLUDE_ASM("nonmatchings/cwater", CreateWaterFrame__FiiPfPfP9mgCMemory);
INCLUDE_ASM("nonmatchings/cwater", Initialize__11CWaterFrameFv);
INCLUDE_ASM("nonmatchings/cwater", SjisToJis__FUl);
INCLUDE_ASM("nonmatchings/cwater", SjisToSerno__FUl);
INCLUDE_ASM("nonmatchings/cwater", ascii2serno__FUc);
INCLUDE_ASM("nonmatchings/cwater", __ct__11dbgCJISFontFv);
INCLUDE_ASM("nonmatchings/cwater", Initialize__11dbgCJISFontFv);
INCLUDE_ASM("nonmatchings/cwater", InitTexture__11dbgCJISFontFiPciPciPc);
INCLUDE_ASM("nonmatchings/cwater", Clear__11dbgCJISFontFv);
INCLUDE_ASM("nonmatchings/cwater", __putc__11dbgCJISFontFUl);
INCLUDE_ASM("nonmatchings/cwater", PrintDirect__11dbgCJISFontFiiPce);
INCLUDE_ASM("nonmatchings/cwater", runerror__FPCc);
INCLUDE_ASM("nonmatchings/cwater", stkoverflow__Fv);
INCLUDE_ASM("nonmatchings/cwater", chk_int__F12RS_STACKDATAP8funcdata);
INCLUDE_ASM("nonmatchings/cwater", is_true__F12RS_STACKDATA);
INCLUDE_ASM("nonmatchings/cwater", divby0error__Fv);
INCLUDE_ASM("nonmatchings/cwater", modby0error__Fv);
INCLUDE_ASM("nonmatchings/cwater", print__FP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/cwater", __ct__10CRunScriptFv);
INCLUDE_ASM("nonmatchings/cwater", DeleteProgram__10CRunScriptFv);
INCLUDE_ASM("nonmatchings/cwater", check_stack__10CRunScriptFv);
INCLUDE_ASM("nonmatchings/cwater", push__10CRunScriptF12RS_STACKDATA);
INCLUDE_ASM("nonmatchings/cwater", push_int__10CRunScriptFi);
INCLUDE_ASM("nonmatchings/cwater", push_str__10CRunScriptFPc);
INCLUDE_ASM("nonmatchings/cwater", push_ptr__10CRunScriptFP12RS_STACKDATA);
INCLUDE_ASM("nonmatchings/cwater", push_float__10CRunScriptFf);
INCLUDE_ASM("nonmatchings/cwater", pop__10CRunScriptFv);
INCLUDE_ASM("nonmatchings/cwater", call_func__10CRunScriptFP8funcdataP8vmcode_t);
INCLUDE_ASM("nonmatchings/cwater", ret_func__10CRunScriptFv);
INCLUDE_ASM("nonmatchings/cwater", ext__10CRunScriptFP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/cwater", load__10CRunScriptFP14RS_PROG_HEADERP12RS_STACKDATAiP11RS_CALLDATAi);
INCLUDE_ASM("nonmatchings/cwater", ext_func__10CRunScriptFPPFP12RS_STACKDATAi_ii);
INCLUDE_ASM("nonmatchings/cwater", resume__10CRunScriptFv);
INCLUDE_ASM("nonmatchings/cwater", run__10CRunScriptFi);
INCLUDE_ASM("nonmatchings/cwater", check_program__10CRunScriptFi);
INCLUDE_ASM("nonmatchings/cwater", skip__10CRunScriptFv);
