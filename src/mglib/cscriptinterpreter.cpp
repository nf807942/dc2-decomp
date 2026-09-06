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
extern "C" s32 RotateThreadReadyQueue(...);
extern "C" s32 mgGetVSyncCount__Fv(void);
extern "C" void WaitVSync__Fii(s32 arg0, s32 arg1) {
loop_1:
    if ((mgGetVSyncCount__Fv() - arg0) < arg1) {
        if (rot_priority > 0) {
            RotateThreadReadyQueue(rot_priority);
        }
        goto loop_1;
    }
}
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
extern "C" u32 mgVif1Packet;
struct mgCDrawManager_ddd6cf {
    s32 field_0;
    char pad_4[0x4];
    s32 field_8;
    s32 field_C;
    char pad_10[0xC];
    u32 field_1C;
    s32 field_20;
    f32 field_24;
    f32 field_28;
    f32 field_2C;
    f32 field_30;
    char pad_34[0x10];
    f32 field_44;
    f32 field_48;
    f32 field_4C;
    char pad_50[0x8];
    s32 field_58;
    char pad_5C[0x8];
    s32 field_64;
    s32 field_68;
    s32 field_6C;
    s32 field_70;
};
extern "C" s32 sceVif1PkEnd(...);
extern "C" s32 sceVif1PkTerminate(...);
extern "C" void mgEndPacket__FP14mgCDrawManager(mgCDrawManager_ddd6cf *arg0) {
    sceVif1PkEnd(mgVif1Packet, 0);
    sceVif1PkTerminate(mgVif1Packet);
}
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgWaitFrame__Fv);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgDraw__FP8mgCFrame);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgDrawDirect__FP8mgCFrame);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgDrawDirect__FP9mgCVisualPA4_f);
extern "C" u32 ddraw_size;
extern "C" u32 mgVif1Packet;
extern "C" s32 sceVif1PkTerminate(...);
extern "C" void mgDrawDirectStart__Fv(void) {
    sceVif1PkTerminate(mgVif1Packet);
    ddraw_size = 0;
}
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgDrawDirect2__FP8mgCFrame);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgDrawDirectEnd__Fv);
struct mgCDrawManager {
    s32 field_0;
    char pad_4[0x4];
    s32 field_8;
    s32 field_C;
    char pad_10[0xC];
    u32 field_1C;
    s32 field_20;
    f32 field_24;
    f32 field_28;
    f32 field_2C;
    f32 field_30;
    char pad_34[0x10];
    f32 field_44;
    f32 field_48;
    f32 field_4C;
    char pad_50[0x8];
    s32 field_58;
    char pad_5C[0x8];
    s32 field_64;
    s32 field_68;
    s32 field_6C;
    s32 field_70;
};
#include "gen/mgCFrame.hpp"
#include "sphida.hpp"
extern "C" s32 GetDrawRect__8mgCFrameFP9mgVu0FBOXP14mgCDrawManager(void *, mgVu0FBOX *, mgCDrawManager *);
extern "C" s32 mgGetDrawRect__FP8mgCFrameP9mgVu0FBOX(mgCFrame *arg0, mgVu0FBOX *arg1) {
    if (arg0 != NULL) {
        return GetDrawRect__8mgCFrameFP9mgVu0FBOXP14mgCDrawManager(arg0, arg1, NULL);
    }
    return 0;
}
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgBeginDrawShadow__FP10mgCTextureP10mgCTexture);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgEndDrawShadow__FP10mgCTextureP10mgCTexture);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgSetRenderInfo__Ffff);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgSetProjection__Ff);
f32 mgGetProjection(void) {
    return mgRenderInfo.field_0x0;
}
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgSetBackGround__FPf);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgSetBackGround__Fffff);
extern "C" u32 mgChangeLight;
extern "C" s32 InitLighting__13mgRENDER_INFOFv(void *);
extern "C" void mgInitLighting__Fv(void) {
    InitLighting__13mgRENDER_INFOFv(&mgRenderInfo);
    mgChangeLight = 1;
}
extern "C" s32 InitActiveLighting__13mgRENDER_INFOFv(void *);
extern "C" void mgInitActiveLighting__Fv(void) {
    InitActiveLighting__13mgRENDER_INFOFv(&mgRenderInfo);
    mgChangeLight = 1;
}
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgActiveLighting__Fii);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgSetLight__FPA4_fPA4_f);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgGetLight__FPA4_fPA4_f);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgSetLight__FiPfPf);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgSetAmbient__FPf);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgGetAmbient__FPf);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgSetPlight__FiPfPfff);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgSetPlight__FiP13mgPOINT_LIGHT);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgGetPlight__FiP13mgPOINT_LIGHT);
extern "C" u32 mgChangeLight;
struct mgPOINT_LIGHT {
    f32 field_0;
    f32 field_4;
    f32 field_8;
    char pad_C[0x4];
    f32 field_10;
    f32 field_14;
    f32 field_18;
    f32 field_1C;
    f32 field_20;
    f32 field_24;
};
extern "C" s32 SetPlight__13mgRENDER_INFOFiP13mgPOINT_LIGHT(void *, s32, mgPOINT_LIGHT *);
extern "C" void mgResetPlight__Fv(void) {
    s32 var_s0;

    mgChangeLight = 1;
    var_s0 = 0;
    do {
        SetPlight__13mgRENDER_INFOFiP13mgPOINT_LIGHT(&mgRenderInfo, var_s0, NULL);
        var_s0 += 1;
    } while (var_s0 < 4);
}
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgSetViewMatrix__FPA4_fPf);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgSetDropShadowMatrix__FPfPfPf);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgFogEnable__Fi);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgGetFogEnable__Fv);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgPlightEnable__Fi);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgGetPlightEnable__Fv);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgSetFogParam__FffUcUcUcff);
struct inferred;
typedef struct mgFOG_PARAM {
    /* 0x00 */ f32 unk0;                            /* inferred */
    /* 0x04 */ f32 unk4;                            /* inferred */
    /* 0x08 */ u8 unk8;                             /* inferred */
    /* 0x09 */ u8 unk9;                             /* inferred */
    /* 0x0A */ u8 unkA;                             /* inferred */
    /* 0x0B */ char padB[5];                        /* maybe part of unkA[6]void */
    /* 0x10 */ f32 unk10;                           /* inferred */
    /* 0x14 */ f32 unk14;                           /* inferred */
} mgFOG_PARAM;                                      /* size >= 0x18 */
extern "C" s32 SetFogParam__13mgRENDER_INFOFffUcUcUcff(void *, f32, f32, u8, u8, u8, f32, f32);
extern "C" void mgSetFogParam__FP11mgFOG_PARAM(mgFOG_PARAM *arg0) {
    SetFogParam__13mgRENDER_INFOFffUcUcUcff(&mgRenderInfo, arg0->unk0, arg0->unk4, arg0->unk8, arg0->unk9, arg0->unkA, arg0->unk10, arg0->unk14);
}
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
extern "C" u32 font_cons;
extern "C" u32 mgScreenOffx;
extern "C" u32 mgScreenOffy;
extern "C" s32 sceDevConsInit(...);
extern "C" s32 sceDevConsOpen(...);
extern "C" s32 mgInitFont__Fv(void) {
    sceDevConsInit();
    font_cons = sceDevConsOpen((mgScreenOffx + 8) * 0x10, (mgScreenOffy + 8) * 0x10, 0x28, 0x18);
    return font_cons;
}
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", mgCloseFont__Fv);
#include "menu.hpp"
extern "C" s32 Init__9mgCMemoryFv(void *);
extern "C" mgCMemory *__ct__9mgCMemoryFv(mgCMemory *objet) {
    Init__9mgCMemoryFv(objet);
    return objet;
}
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
extern "C" s32 GetNextTAG__18CScriptInterpreterFi(void *, s32);
extern "C" void Run__18CScriptInterpreterFv(CScriptInterpreter *objet) {
    do {

    } while (GetNextTAG__18CScriptInterpreterFi(objet, 1) >= 0);
}
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", hash__18CScriptInterpreterFPc);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", SetTag__18CScriptInterpreterFP13SPI_TAG_PARAM);
INCLUDE_ASM("nonmatchings/mglib/cscriptinterpreter", SetScript__18CScriptInterpreterFPci);
extern "C" s32 __ct__9input_strFv(void *);
struct inferred;
typedef struct CScriptInterpreter_infere {
    /* 0x00 */ s32 unk0;                            /* inferred */
    /* 0x04 */ s32 unk4;                            /* inferred */
    /* 0x08 */ s32 unk8;                            /* inferred */
    /* 0x0C */ s32 unkC;                            /* inferred */
    /* 0x10 */ char pad10[4];
    /* 0x14 */ s32 unk14;                           /* inferred */
    /* 0x18 */ char pad18[0x14];                    /* maybe part of unk14[6]void */
    /* 0x2C */ s32 unk2C;                           /* inferred */
} CScriptInterpreter_infere;                               /* size >= 0x30 */
extern "C" CScriptInterpreter_infere *__ct__18CScriptInterpreterFv(CScriptInterpreter_infere *objet) {
    __ct__9input_strFv((input_str *) objet);
    objet->unk0 = 0;
    objet->unk4 = 0;
    objet->unk8 = 0;
    objet->unkC = 0;
    objet->unk14 = 0;
    objet->unk2C = 0;
    return objet;
}
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
