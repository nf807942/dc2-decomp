/* CScriptInterpreter, input_str, mgCMemory, SPI_STACK
 *
 * Unité découpée par `make carve` : 124 fonctions, 23904 octets, de
 * 0x00141850 à 0x00147890. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"
#include "gen/mgRenderInfoData.hpp"
#include "gen/CScriptInterpreter.hpp"
#include "gen/input_str.hpp"
extern s32 draw_performance_meter;
extern s32 rot_priority;
struct SPI_STACK;

extern mgRenderInfoData mgRenderInfo;


void mgPerformanceMeter(s32 arg0) {
    draw_performance_meter = arg0;
}
s32 mgGetPerformanceMeterFlag(void) {
    return draw_performance_meter;
}
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", VSyncCallBack__Fi_00141870);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgInitVSyncCallBack__FPFi_i);
void mgSetRotateThread(s32 arg0) {
    rot_priority = arg0;
}
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", WaitVSync__Fii);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgGetVSyncCount__Fv);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", GetScreenSize__FiPiPiPiPiPiPi);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgInit__Fii);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgInitVif1Packet__FP1P1i);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgSetPacketBuffer__FP9mgCMemoryP9mgCMemory);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgSetDataBuffer__FP9mgCMemoryP9mgCMemoryi);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgGetDataBuffer__Fv);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgGetTopVRAMAddress__Fv);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgGetNowFrameRate__Fv);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgBeginFrame__FP14mgCDrawManager);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgBeginPacket__FP14mgCDrawManager);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgBeginDraw__FP9mgCMemoryPiP14mgCDrawManager);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgEndDraw__FP14mgCDrawManager);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgPreEndDraw__FP14mgCDrawManager);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgEndDrawReloadTexture__FiP14mgCDrawManager);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgEndDraw__FiP14mgCDrawManager);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgStoreFrameImage__Fv);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgEndFrame__FP14mgCDrawManager);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgSendPacket__FP14mgCDrawManager);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgEndPacket__FP14mgCDrawManager);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgWaitFrame__Fv);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgDraw__FP8mgCFrame);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgDrawDirect__FP8mgCFrame);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgDrawDirect__FP9mgCVisualPA4_f);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgDrawDirectStart__Fv);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgDrawDirect2__FP8mgCFrame);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgDrawDirectEnd__Fv);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgGetDrawRect__FP8mgCFrameP9mgVu0FBOX);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgBeginDrawShadow__FP10mgCTextureP10mgCTexture);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgEndDrawShadow__FP10mgCTextureP10mgCTexture);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgSetRenderInfo__Ffff);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgSetProjection__Ff);
f32 mgGetProjection(void) {
    return mgRenderInfo.field_0x0;
}
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgSetBackGround__FPf);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgSetBackGround__Fffff);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgInitLighting__Fv);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgInitActiveLighting__Fv);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgActiveLighting__Fii);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgSetLight__FPA4_fPA4_f);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgGetLight__FPA4_fPA4_f);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgSetLight__FiPfPf);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgSetAmbient__FPf);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgGetAmbient__FPf);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgSetPlight__FiPfPfff);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgSetPlight__FiP13mgPOINT_LIGHT);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgGetPlight__FiP13mgPOINT_LIGHT);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgResetPlight__Fv);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgSetViewMatrix__FPA4_fPf);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgSetDropShadowMatrix__FPfPfPf);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgFogEnable__Fi);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgGetFogEnable__Fv);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgPlightEnable__Fi);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgGetPlightEnable__Fv);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgSetFogParam__FffUcUcUcff);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgSetFogParam__FP11mgFOG_PARAM);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgGetFogParam__FP11mgFOG_PARAM);
void mgSetAllScissorFlag(s32 arg0) {
    mgRenderInfo.field_0xFA0 = arg0;
}
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgFlushRenderInfo__Fv);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgSetPkTextureRepeat__Fi);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgSetPkTextureRepeat__F10sceGsClamp);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgSetPkFrameBuffer__FP10mgCTexture);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgSetPkFrameBuffer__Fiiii);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgGetFrameBuffer__FP10mgCTexture);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgGetFrameBackBuffer__FP10mgCTexture);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgGetpDrawEnv__Fi);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgSetPkMoveImage__FP10mgCTexture9mgRect_i_P10mgCTextureiii);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgSetPkMoveImage__FP9sceGsTex09mgRect_i_P9sceGsTex0iii);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgSetPkMoveImage__FP10mgCTexture9mgRect_i_P10mgCTexture9mgRect_i_P10mgCDrawEnv);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgSetPkMoveImage__FP9sceGsTex09mgRect_i_P9sceGsTex0i9mgRect_i_P10mgCDrawEnv);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgSetPkClearScreen__FUcUcUcUc);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgStoreImage__FP10mgCTextureP1);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgStoreZBuffImage__FR9mgRect_i_P1);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgConvZBuffToDist__FUi);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgGetTextureZ__Fi);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", prim_clip_check__FPf);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgTransWorldPrim__FPiPf);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgTransWorldScreen__FPiPf);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgTransViewPrim__FPiPf);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgTransWorldView__FPfPf);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgTransZPrim__Ff);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgGetDistFromCamera__FPf);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgGetDirFromCamera__FPfPf);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgGetCameraPos__FPf);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgGetCameraPose__FPA4_f);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgTransWorldPrim3DSprite__FPiPiPfffi);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", CheckVuProgID__Fi);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgGetVuProgPacket__Fi);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgSendVuProg__FPUii);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgSetUserVuProg__FPP1i);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgSetUserVuProgAdr__FiP1);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", StoreImage__Fi);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgInitFont__Fv);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgCloseFont__Fv);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", __ct__9mgCMemoryFv);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", GetLine__9input_strFPciPc);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", get__9input_strFPi);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", spiGetStackInt__FP9SPI_STACK);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", spiGetStackFloat__FP9SPI_STACK);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", spiGetStackString__FP9SPI_STACK);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", spiGetStackVector__FPfP9SPI_STACK);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", PushStack__18CScriptInterpreterF9SPI_STACK);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", __as__9SPI_STACKFRC9SPI_STACK);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", GetNextTAG__18CScriptInterpreterFi);
void CScriptInterpreter::SetStack(SPI_STACK * arg0, s32 arg1) {
    this->field_0x14 = arg0;
    this->field_0x10 = arg1;
    this->field_0xC = 0;
}
void CScriptInterpreter::SetStringBuff(char * arg0, s32 arg1) {
    this->field_0x20 = arg0;
    this->field_0x18 = arg1;
    this->field_0x1C = this->field_0x20;
}
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", Run__18CScriptInterpreterFv);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", hash__18CScriptInterpreterFPc);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", SetTag__18CScriptInterpreterFP13SPI_TAG_PARAM);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", SetScript__18CScriptInterpreterFPci);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", __ct__18CScriptInterpreterFv);
input_str::input_str(void) {
    this->field_0x4 = 0;
    this->field_0x8 = 0;
    this->field_0x0 = 0;
}
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", GetArgBin__18CScriptInterpreterFv);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", GetArg__18CScriptInterpreterFv);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", back__9input_strFv);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", SearchCommand__18CScriptInterpreterFPi);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", SkipSpace__FR9input_str);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", CheckChar__Fc);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", PreProcess__FR9input_str);
