/* mgCFrame, mgCDrawPrim, mgCDrawManager, mgCMDTBuilder, mgCCamera, mgCCameraFollow, mgCObject, mgCVisual, mgCFrameAttr, mgCVisualMDT, mgCVisualFixMDT, mgCFrameBase
 *
 * Unité découpée par `make carve` : 209 fonctions, 29960 octets, de
 * 0x00131560 à 0x00138EE0. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"
#include "gen/mgCDrawPrim.hpp"
#include "gen/mgCFrame.hpp"
#include "gen/mgCObject.hpp"

extern "C" s32 rand();
extern "C" f32 mgRnd__Fv(void) {
    return (f32) rand() / 2.1474836e9f;
}
INCLUDE_ASM("nonmatchings/mglib/mgcframe", mgNRnd__Fv);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", mgCreateSinTable__Fv);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", mgSinf__Ff);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", mgCosf__Ff);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", Step__9mgCCameraFi);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", Stay__9mgCCameraFv);
typedef struct mgCCamera {
    /* 0x00 */ f32 unk0;                            /* inferred */
    /* 0x04 */ f32 unk4;                            /* inferred */
    /* 0x08 */ f32 unk8;                            /* inferred */
    /* 0x0C */ s32 unkC;                            /* inferred */
    /* 0x10 */ char pad10[0x10];                    /* maybe part of unkC[5]? */
    /* 0x20 */ f32 unk20;                           /* inferred */
    /* 0x24 */ f32 unk24;                           /* inferred */
    /* 0x28 */ f32 unk28;                           /* inferred */
    /* 0x2C */ s32 unk2C;                           /* inferred */
} mgCCamera;                                        /* size >= 0x30 */
extern "C" void SetPos__9mgCCameraFfff(mgCCamera *objet, f32 arg0, f32 arg1, f32 arg2) {
    objet->unk20 = arg0;
    objet->unk0 = arg0;
    objet->unk24 = arg1;
    objet->unk4 = arg1;
    objet->unk28 = arg2;
    objet->unk8 = arg2;
    objet->unk2C = 0x3F800000;
    objet->unkC = 0x3F800000;
}
INCLUDE_ASM("nonmatchings/mglib/mgcframe", SetPos__9mgCCameraFPf);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", SetNextPos__9mgCCameraFfff);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", SetNextPos__9mgCCameraFPf);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", SetRef__9mgCCameraFfff);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", SetRef__9mgCCameraFPf);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", SetNextRef__9mgCCameraFfff);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", SetNextRef__9mgCCameraFPf);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", GetDir__9mgCCameraFPf);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", GetCameraMatrix__9mgCCameraFPA4_f);
typedef struct mgCCamera_infere {
    /* 0x00 */ char pad0[0x48];
    /* 0x48 */ f32 unk48;                           /* inferred */
    /* 0x4C */ f32 unk4C;                           /* inferred */
} mgCCamera_infere;                                        /* size >= 0x50 */
extern "C" void SetSpeed__9mgCCameraFff(mgCCamera_infere *objet, f32 arg0, f32 arg1) {
    objet->unk48 = arg0;
    objet->unk4C = arg1;
    if (arg1 < 0.0f) {
        objet->unk4C = objet->unk48;
    }
}
INCLUDE_ASM("nonmatchings/mglib/mgcframe", SetRoll__9mgCCameraFf);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", GetPos__9mgCCameraFPf);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", GetRef__9mgCCameraFPf);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", GetNextPos__9mgCCameraFPf);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", GetNextRef__9mgCCameraFPf);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", GetAngleH__9mgCCameraFv);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", GetAngleV__9mgCCameraFv);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", __ct__9mgCCameraFf);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", GetFollowNextPos__15mgCCameraFollowFPf);
typedef struct mgCCameraFollow {
    /* 0x00 */ char pad0[0x80];
    /* 0x80 */ f32 unk80;                           /* inferred */
} mgCCameraFollow;                                  /* size >= 0x84 */
extern "C" void mgAddVector__FPfPf(f32 *arg0, f32 *arg1);
extern "C" void GetFollow__15mgCCameraFollowFPf(mgCCameraFollow *objet, f32 *arg0);
extern "C" void GetFollowNext__15mgCCameraFollowFPf(mgCCameraFollow *objet, f32 *arg0) {
    GetFollow__15mgCCameraFollowFPf(objet, arg0);
    mgAddVector__FPfPf(arg0, &objet->unk80);
}
INCLUDE_ASM("nonmatchings/mglib/mgcframe", Step__15mgCCameraFollowFi);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", Stay__15mgCCameraFollowFv);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", SetFollow__15mgCCameraFollowFfff);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", FollowOn__15mgCCameraFollowFv);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", FollowOff__15mgCCameraFollowFv);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", SetAngle__15mgCCameraFollowFf);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", SetAngleSoon__15mgCCameraFollowFf);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", GetAngle__15mgCCameraFollowFv);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", AddAngle__15mgCCameraFollowFf);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", SetDistance__15mgCCameraFollowFf);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", GetDistance__15mgCCameraFollowFv);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", AddDistance__15mgCCameraFollowFf);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", SetHeight__15mgCCameraFollowFf);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", GetHeight__15mgCCameraFollowFv);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", AddHeight__15mgCCameraFollowFf);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", SetFollowOffset__15mgCCameraFollowFfff);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", GetFollow__15mgCCameraFollowFPf);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", GetFollowOffset__15mgCCameraFollowFPf);
extern "C" s32 __ct__9mgCCameraFf(void *, f32);
extern "C" u8 __vt__15mgCCameraFollow[36];
struct inferred;
typedef struct mgCCameraFollow_infere {
    /* 0x00 */ char pad0[0x60];
    /* 0x60 */ void *unk60;                            /* inferred */
    /* 0x64 */ char pad64[0x1C];                    /* maybe part of unk60[8]void */
    /* 0x80 */ f32 unk80;                           /* inferred */
    /* 0x84 */ char pad84[0xC];                     /* maybe part of unk80[4]void */
    /* 0x90 */ f32 unk90;                           /* inferred */
    /* 0x94 */ f32 unk94;                           /* inferred */
    /* 0x98 */ f32 unk98;                           /* inferred */
    /* 0x9C */ f32 unk9C;                           /* inferred */
    /* 0xA0 */ s32 unkA0;                           /* inferred */
    /* 0xA4 */ char padA4[0xC];                     /* maybe part of unkA0[4]void */
    /* 0xB0 */ s32 unkB0;                           /* inferred */
    /* 0xB4 */ s32 unkB4;                           /* inferred */
    /* 0xB8 */ s32 unkB8;                           /* inferred */
} mgCCameraFollow_infere;                                  /* size >= 0xBC */
extern "C" s32 mgZeroVector__FPf(f32 *arg0);
extern "C" mgCCameraFollow_infere *__ct__15mgCCameraFollowFffff(mgCCameraFollow_infere *objet, f32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    __ct__9mgCCameraFf((mgCCamera *) objet, arg3);
    objet->unk60 = &__vt__15mgCCameraFollow;
    objet->unkB0 = 0;
    objet->unkB4 = 0;
    objet->unkB8 = 0;
    objet->unk98 = arg2;
    objet->unk9C = arg2;
    objet->unk90 = arg0;
    objet->unk94 = arg1;
    objet->unkA0 = 1;
    mgZeroVector__FPf(&objet->unk80);
    /* L'ordre des declarations decide de l'attribution des registres chez
     * MWCC. Celui-ci n'est pas celui de m2c : il a ete trouve en enumerant
     * les ordres possibles, et c'est le seul qui rende les octets du disque.
     * */
    return objet;
}
INCLUDE_ASM("nonmatchings/mglib/mgcframe", Iam__15mgCCameraFollowFv);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", Suspend__9mgCCameraFv);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", Resume__9mgCCameraFv);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", Iam__9mgCCameraFv);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", conv_new_text__FPcPc);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", htoi__FPc);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", mgSetFrameAttr__FP8mgCFramei);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", SearchVisualType__FP18mgCreateVisualTypePc);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", CreateFrameVisual__FP8mgCFrameP9mgCMemoryP9mgCMemoryP8mgCFrameP13MDTOBJ_HEADERP10MDT_HEADERiP17mgCTextureManagerPUiiPP8mgCFramePA4_A4_f);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", SetVisual__8mgCFrameFP9mgCVisual);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", Initialize__15mgCVisualFixMDTFv);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", Initialize__9mgCVisualFv);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", mgLoadMDSFile__FP10MDS_HEADERP9mgCMemoryP18mgCreateVisualTypeP17mgCTextureManager);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", mgLoadMDSFile__FP10mgLoadData);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", mgCreateBBoxSphere__FPfPfPfPA4_fi);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", CopyFrame__FP8mgCFrameP8mgCFrameP9mgCMemoryiPP8mgCFrame);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", Iam__9mgCVisualFv);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", Copy__9mgCVisualFP9mgCMemory);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", CopyFrameSub__FP8mgCFrameP9mgCMemoryiPP8mgCFrame);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", mgCopyFrame__FP8mgCFrameP9mgCMemoryi);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", Begin__13mgCMDTBuilderFP9mgCMemory);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", End__13mgCMDTBuilderFv);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", End__13mgCMDTBuilderFP8mgCFrameP12mgCVisualMDTP10mgLoadData);
typedef struct mgCMDTBuilder {
    /* 0x00 */ char pad0[8];
    /* 0x08 */ s32 unk8;                            /* inferred */
    /* 0x0C */ s32 unkC;                            /* inferred */
    /* 0x10 */ s32 unk10;                           /* inferred */
    /* 0x14 */ char pad14[0x14];                    /* maybe part of unk10[6]? */
    /* 0x28 */ s32 unk28;                           /* inferred */
} mgCMDTBuilder;                                    /* size >= 0x2C */
extern "C" void BeginData__13mgCMDTBuilderFi(mgCMDTBuilder *objet, s32 arg0) {
    if (objet->unk28 == 0) {
        objet->unkC = objet->unk8;
        objet->unk10 = 0;
        objet->unk28 = arg0;
    }
}
INCLUDE_ASM("nonmatchings/mglib/mgcframe", SetData__13mgCMDTBuilderFPf);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", SetData__13mgCMDTBuilderFffff);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", SetMaterial__13mgCMDTBuilderFPfPc);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", EndData__13mgCMDTBuilderFv);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", BeginFaces__13mgCMDTBuilderFv);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", EndFaces__13mgCMDTBuilderFv);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", BeginPrim__13mgCMDTBuilderFii);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", AddFace__13mgCMDTBuilderFi);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", EndPrim__13mgCMDTBuilderFv);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", Iam__12mgCVisualMDTFv);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", GetMaterialNum__12mgCVisualMDTFv);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", GetpMaterial__12mgCVisualMDTFv);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", Draw__12mgCVisualMDTFPA4_fP14mgCDrawManager);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", CreatePacket__9mgCVisualFP9mgCMemoryP9mgCMemory);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", GetMaterialNum__9mgCVisualFv);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", GetpMaterial__9mgCVisualFv);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", GetMaterial__9mgCVisualFi);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", CreateBBox__9mgCVisualFPfPfPA4_f);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", CreateRenderInfoPacket__9mgCVisualFPUiPA4_fP13mgRENDER_INFO);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", Draw__9mgCVisualFPUiPA4_fP14mgCDrawManager);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", Draw__9mgCVisualFPA4_fP14mgCDrawManager);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", __ct__11mgCDrawPrimFv);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", Initialize__11mgCDrawPrimFP9mgCMemoryP13sceVif1Packet);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", Begin__11mgCDrawPrimFi);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", BeginDma__11mgCDrawPrimFv);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", EndDma__11mgCDrawPrimFv);
extern "C" void BeginDma__11mgCDrawPrimFv(...);
extern "C" void EndDma__11mgCDrawPrimFv(...);
extern "C" void Flush__11mgCDrawPrimFv(mgCDrawPrim *objet) {
    EndDma__11mgCDrawPrimFv(objet);
    BeginDma__11mgCDrawPrimFv(objet);
}
typedef struct mgCDrawPrim_infere {
    /* 0x00 */ char pad0[0xD0];
    /* 0xD0 */ s32 unkD0;                           /* inferred */
} mgCDrawPrim_infere;                                      /* size >= 0xD4 */
extern "C" s32 End2__11mgCDrawPrimFv(void *);
extern "C" void End__11mgCDrawPrimFv(mgCDrawPrim_infere *objet) {
    if (objet->unkD0 == 0) {
        EndDma__11mgCDrawPrimFv(objet);
        End2__11mgCDrawPrimFv(objet);
    }
}
INCLUDE_ASM("nonmatchings/mglib/mgcframe", Begin2__11mgCDrawPrimFv);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", BeginPrim2__11mgCDrawPrimFi);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", BeginPrim2__11mgCDrawPrimFiUiUii);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", EndPrim2__11mgCDrawPrimFv);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", End2__11mgCDrawPrimFv);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", Data0__11mgCDrawPrimFPf);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", Data4__11mgCDrawPrimFPf);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", Data__11mgCDrawPrimFPi);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", DirectData__11mgCDrawPrimFi);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", Vertex__11mgCDrawPrimFiii);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", Vertex__11mgCDrawPrimFfff);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", Vertex__11mgCDrawPrimFPf);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", Vertex4__11mgCDrawPrimFiii);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", Vertex4__11mgCDrawPrimFPi);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", Color__11mgCDrawPrimFiiii);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", Color__11mgCDrawPrimFPf);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", TextureCrd4__11mgCDrawPrimFii);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", TextureCrd__11mgCDrawPrimFii);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", Direct__11mgCDrawPrimFUlUl);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", Texture__11mgCDrawPrimFP10mgCTexture);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", AlphaBlendEnable__11mgCDrawPrimFi);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", AlphaBlend__11mgCDrawPrimFi);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", AlphaTestEnable__11mgCDrawPrimFi);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", AlphaTest__11mgCDrawPrimFii);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", DAlphaTest__11mgCDrawPrimFii);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", DepthTestEnable__11mgCDrawPrimFi);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", DepthTest__11mgCDrawPrimFi);
void mgCDrawPrim::ZMask(s32 arg0) {
    this->field_0xCC = arg0;
}
INCLUDE_ASM("nonmatchings/mglib/mgcframe", TextureMapEnable__11mgCDrawPrimFi);
void mgCDrawPrim::Bilinear(s32 arg0) {
    this->field_0xC8 = arg0;
}
INCLUDE_ASM("nonmatchings/mglib/mgcframe", Shading__11mgCDrawPrimFi);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", AntiAliasing__11mgCDrawPrimFi);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", FogEnable__11mgCDrawPrimFi);
void mgCDrawPrim::Coord(s32 arg0) {
    this->field_0xFC = arg0;
}
INCLUDE_ASM("nonmatchings/mglib/mgcframe", GetOffset__11mgCDrawPrimFPiPi);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", __ct__14mgCDrawManagerFv);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", SetSortTable__14mgCDrawManagerFi);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", BeginDraw__14mgCDrawManagerFP9mgCMemoryPi);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", ClearTable__14mgCDrawManagerFv);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", PreEndDraw__14mgCDrawManagerFv);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", ReloadTexture__14mgCDrawManagerFiP13sceVif1Packet);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", Draw__14mgCDrawManagerFiP13sceVif1Packet);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", EndDraw__14mgCDrawManagerFP13sceVif1Packet);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", AddPacket__14mgCDrawManagerFiP1P1i);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", Initialize__12mgCFrameAttrFv);
extern "C" void __ct__13mgCVisualAttrFv(void *);
struct mgCFrameAttr {
    char pad_0[0x4];
    s32 field_4;
    s32 field_8;
    s32 field_C;
    s32 field_10;
    char pad_14[0xC];
    s32 field_20;
    s32 field_24;
    s32 field_28;
    char pad_2C[0xC];
    s32 field_38;
    s32 field_3C;
    char pad_40[0x4];
    s32 field_44;
    char pad_48[0x4];
    s32 field_4C;
    char pad_50[0x10];
    s32 field_60;
    char pad_64[0x1C];
    s32 field_80;
    s32 field_84;
    s32 field_88;
    char pad_8C[0x4];
    f32 field_90;
    f32 field_94;
    f32 field_98;
    f32 field_9C;
    f32 field_A0;
    f32 field_A4;
    f32 field_A8;
    f32 field_AC;
};
struct mgCVisualAttr {
    s32 field_0;
    s32 field_4;
    s32 field_8;
    s32 field_C;
    s32 field_10;
    s32 field_14;
};
extern "C" s32 Initialize__12mgCFrameAttrFv(mgCFrameAttr *objet);
extern "C" mgCFrameAttr *__ct__12mgCFrameAttrFv(mgCFrameAttr *objet) {
    __ct__13mgCVisualAttrFv((mgCVisualAttr *) objet);
    Initialize__12mgCFrameAttrFv(objet);
    return objet;
}
INCLUDE_ASM("nonmatchings/mglib/mgcframe", QuatToMat__FPfPA4_f);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", test1__FPA4_fPA4_fPA4_fPfPf);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", test2__FPfPf);
struct mgVu0FBOX {
    f32 unk0;
    u8 pad4[0xC];
    f32 unk10;
};
extern "C" s32 mgCreateBox8__FPA4_fPfPf(...);
extern "C" s32 mgInsideScreen__FPA4_fPA4_fPfPf(...);
extern "C" s32 mgUnitMatrix__FPA4_f(...);
extern "C" void mgInsideScreen__FPA4_fPA4_f(f32 (*)[4], f32 (*)[4]);
extern "C" void mgInsideScreen__FP9mgVu0FBOX(mgVu0FBOX *arg0) {
    f32 sp20[16];
    f32 sp60[32];
    mgUnitMatrix__FPA4_f((f32 (*)[4]) sp20);
    mgCreateBox8__FPA4_fPfPf((f32 (*)[4]) sp60, &arg0->unk0, &arg0->unk10);
    mgInsideScreen__FPA4_fPA4_f((f32 (*)[4]) sp60, (f32 (*)[4]) sp20);
}
extern "C" void mgInsideScreen__FP9mgVu0FBOXPA4_f(mgVu0FBOX *arg0, f32 (*arg1)[4]) {
    f32 sp20[32];
    mgCreateBox8__FPA4_fPfPf((f32 (*)[4]) sp20, &arg0->unk0, &arg0->unk10);
    mgInsideScreen__FPA4_fPA4_f((f32 (*)[4]) sp20, arg1);
}
extern "C" void mgInsideScreen__FP9mgVu0FBOXPA4_fPfPf(mgVu0FBOX *arg0, f32 (*arg1)[4], f32 *arg2, f32 *arg3) {
    f32 sp40[32];
    mgCreateBox8__FPA4_fPfPf((f32 (*)[4]) sp40, &arg0->unk0, &arg0->unk10);
    mgInsideScreen__FPA4_fPA4_fPfPf((f32 (*)[4]) sp40, arg1, arg2, arg3);
}

extern "C" void mgInsideScreen__FPA4_fPA4_f(f32 (*arg0)[4], f32 (*arg1)[4]) {
    /* Les emplacements de pile portent la taille que le commerce leur donne,
     * lue sur l'ecart entre deux adresses prises, et ils sont declares dans
     * l'ordre croissant de leur decalage : MWCC attribue la pile dans l'ordre
     * des declarations, m2c les ecrit a l'envers. Deux entiers a la place de
     * ces tableaux rendaient un cadre de la moitie, et l'ordre de m2c les
     * echangeait. */
    f32 sp10[4];
    f32 sp20[4];
    mgInsideScreen__FPA4_fPA4_fPfPf(arg0, arg1, sp10, sp20);
}
INCLUDE_ASM("nonmatchings/mglib/mgcframe", mgInsideScreen__FPA4_fPA4_fPfPf);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", SetPosition__9mgCObjectFPf);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", SetPosition__9mgCObjectFfff);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", GetPosition__9mgCObjectFPf);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", SetRotation__9mgCObjectFPf);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", SetRotation__9mgCObjectFfff);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", GetRotation__9mgCObjectFPf);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", SetScale__9mgCObjectFPf);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", SetScale__9mgCObjectFfff);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", GetScale__9mgCObjectFPf);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", Initialize__9mgCObjectFv);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", __ct__8mgCFrameFv);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", Initialize__12mgCFrameBaseFv);
struct mgCFrame_infere_014b63;
typedef struct mgCFrame_infere_014b63 {
    /* 0x000 */ char pad0[0x50];
    /* 0x050 */ s32 unk50;                          /* inferred */
    /* 0x054 */ s32 unk54;                          /* inferred */
    /* 0x058 */ s32 unk58;                          /* inferred */
    /* 0x05C */ s32 unk5C;                          /* inferred */
    /* 0x060 */ s32 unk60;                          /* inferred */
    /* 0x064 */ s32 unk64;                          /* inferred */
    /* 0x068 */ s32 unk68;                          /* inferred */
    /* 0x06C */ s32 unk6C;                          /* inferred */
    /* 0x070 */ char unk70;                            /* inferred */
    /* 0x070 */ char pad70[0x40];
    /* 0x0B0 */ char unkB0;                            /* inferred */
    /* 0x0B0 */ char padB0[0x40];
    /* 0x0F0 */ s32 unkF0;                          /* inferred */
    /* 0x0F4 */ s32 unkF4;                          /* inferred */
    /* 0x0F8 */ s32 unkF8;                          /* inferred */
    /* 0x0FC */ s32 unkFC;                          /* inferred */
    /* 0x100 */ s32 unk100;                         /* inferred */
} mgCFrame_infere_014b63;                                         /* size >= 0x104 */
struct objet_champs_014b63 {
    char pad0[0x50];
    /* 0x50 */ s32 unk50;
    /* 0x54 */ s32 unk54;
    /* 0x58 */ s32 unk58;
    /* 0x5C */ s32 unk5C;
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ s32 unk68;
    /* 0x6C */ s32 unk6C;
    /* 0x70 */ s32 unk70;
    char pad74[0x3C];
    /* 0xB0 */ s32 unkB0;
    char padB4[0x3C];
    /* 0xF0 */ s32 unkF0;
    /* 0xF4 */ s32 unkF4;
    /* 0xF8 */ s32 unkF8;
    /* 0xFC */ s32 unkFC;
    /* 0x100 */ s32 unk100;
};
extern "C" s32 sceVu0UnitMatrix(...);
extern "C" s32 Initialize__9mgCObjectFv(void *);
extern "C" void Initialize__8mgCFrameFv(mgCFrame_infere_014b63 *objet) {
    ((struct objet_champs_014b63 *) objet)->unk60 = 0;
    ((struct objet_champs_014b63 *) objet)->unk5C = 0;
    ((struct objet_champs_014b63 *) objet)->unk58 = 0;
    ((struct objet_champs_014b63 *) objet)->unk54 = 0;
    sceVu0UnitMatrix(&((struct objet_champs_014b63 *) objet)->unk70);
    sceVu0UnitMatrix(&((struct objet_champs_014b63 *) objet)->unkB0);
    ((struct objet_champs_014b63 *) objet)->unk50 = 0;
    ((struct objet_champs_014b63 *) objet)->unk100 = 0;
    ((struct objet_champs_014b63 *) objet)->unkFC = 0;
    ((struct objet_champs_014b63 *) objet)->unkF8 = 0;
    ((struct objet_champs_014b63 *) objet)->unkF4 = 0;
    ((struct objet_champs_014b63 *) objet)->unk64 = 0;
    ((struct objet_champs_014b63 *) objet)->unk68 = 0;
    ((struct objet_champs_014b63 *) objet)->unk6C = 0;
    ((struct objet_champs_014b63 *) objet)->unkF0 = 0;
    Initialize__9mgCObjectFv((mgCObject *) objet);
}
void mgCFrame::SetName(char * arg0) {
    this->field_0x50 = arg0;
}
INCLUDE_ASM("nonmatchings/mglib/mgcframe", SetTransMatrix__8mgCFrameFPf);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", SetBBox__8mgCFrameFPfPf);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", GetBBox__8mgCFrameFPfPf);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", SetBSphere__8mgCFrameFPff);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", GetFrame__8mgCFrameFi);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", RemakeBBox__8mgCFrameFPfPf);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", GetWorldBBox__8mgCFrameFP9mgVu0FBOX);
struct mgCFrame_infere_8178eb;
typedef struct mgCFrame_infere_8178eb {
    /* 0x00 */ char pad0[0x58];
    /* 0x58 */ mgCFrame_infere_8178eb *unk58;                     /* inferred */
    /* 0x5C */ mgCFrame_infere_8178eb *unk5C;                     /* inferred */
} mgCFrame_infere_8178eb;                                         /* size >= 0x60 */
struct objet_champs_8178eb {
    char pad0[0x58];
    /* 0x58 */ s32 unk58;
};
extern "C" s32 GetFrameNum__8mgCFrameFv(mgCFrame_infere_8178eb *objet) {
    s32 temp_v0;
    s32 var_s0;
    mgCFrame_infere_8178eb *var_s1;

    var_s1 = (mgCFrame_infere_8178eb *) (((struct objet_champs_8178eb *) objet)->unk58);
    var_s0 = 1;
    if (var_s1 != NULL) {
        do {
            temp_v0 = (s32) (GetFrameNum__8mgCFrameFv(var_s1));
            var_s1 = (mgCFrame_infere_8178eb *) (var_s1->unk5C);
            var_s0 += temp_v0;
        } while (var_s1 != NULL);
    }
    return var_s0;
}

INCLUDE_ASM("nonmatchings/mglib/mgcframe", SetParent__8mgCFrameFP8mgCFrame);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", SetBrother__8mgCFrameFP8mgCFrame);
typedef struct mgCFrame_infere {
    /* 0x00 */ char pad0[0x54];
    /* 0x54 */ mgCFrame_infere *unk54;                     /* inferred */
    /* 0x58 */ mgCFrame_infere *unk58;                     /* inferred */
} mgCFrame_infere;                                         /* size >= 0x5C */
extern "C" s32 SetBrother__8mgCFrameFP8mgCFrame(mgCFrame_infere *objet, mgCFrame_infere *arg0);
extern "C" void SetChild__8mgCFrameFP8mgCFrame(mgCFrame_infere *objet, mgCFrame_infere *arg0) {
    mgCFrame_infere *temp_a0;

    if (arg0 != NULL) {
        temp_a0 = objet->unk58;
        if (temp_a0 != NULL) {
            SetBrother__8mgCFrameFP8mgCFrame(temp_a0, arg0);
        } else {
            objet->unk58 = arg0;
        }
        arg0->unk54 = objet;
    }
}
INCLUDE_ASM("nonmatchings/mglib/mgcframe", DeleteParent__8mgCFrameFv);
typedef struct mgCFrame_infere3 {
    /* 0x000 */ char pad0[0x40];
    /* 0x040 */ s32 unk40;                          /* inferred */
    /* 0x044 */ char pad44[0x10];                   /* maybe part of unk40[5]void */
    /* 0x054 */ mgCFrame_infere3 *unk54;                    /* inferred */
    /* 0x058 */ char pad58[0xA4];                   /* maybe part of unk54[0x2A]void */
    /* 0x0FC */ s32 unkFC;                          /* inferred */
} mgCFrame_infere3;                                         /* size >= 0x100 */
extern "C" void SetReference__8mgCFrameFP8mgCFrame(mgCFrame_infere3 *objet, mgCFrame_infere3 *arg0) {
    if ((objet->unk54 == NULL) && (arg0 != NULL)) {
        objet->unk54 = arg0;
        objet->unkFC = 1;
        objet->unk40 = 1;
    }
}
void mgCFrame::DeleteReference(void) {
    this->field_0x54 = 0;
    this->field_0xFC = 0;
    this->field_0x40 = 1;
}
INCLUDE_ASM("nonmatchings/mglib/mgcframe", ClearChildFlag__8mgCFrameFv);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", GetLocalMatrix__8mgCFrameFPA4_f);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", GetBBoardMatrix__8mgCFrameFiPA4_fP13mgRENDER_INFO);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", GetLWMatrix__8mgCFrameFPA4_f);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", GetLWMatrixTopBottom__8mgCFrameFPA4_f);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", GetInverseMatrix__8mgCFrameFPA4_f);
typedef struct mgCFrame_infere2 {
    /* 0x00 */ char pad0[0x40];
    /* 0x40 */ s32 unk40;                           /* inferred */
    /* 0x44 */ char pad44[0x6C];                    /* maybe part of unk40[0x1C]void */
    /* 0xB0 */ char unkB0;                             /* inferred */
    /* 0xB0 */ char padB0[1];
} mgCFrame_infere2;                                         /* size >= 0xB1 */
extern "C" s32 sceVu0CopyMatrix(void *);
extern "C" void SetTransMatrix__8mgCFrameFPA4_f(mgCFrame_infere2 *objet, f32 (*arg0)[4]) {
    sceVu0CopyMatrix(&objet->unkB0);
    objet->unk40 = 1;
}
INCLUDE_ASM("nonmatchings/mglib/mgcframe", StrCmp__FPcPc);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", mgFrameNameComp__FPcPc);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", SearchFrame__8mgCFrameFPc);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", SearchFrameID__8mgCFrameFPc);
extern "C" s32 sceVu0ApplyMatrix(...);
extern "C" s32 GetLWMatrix__8mgCFrameFPA4_f(...);
extern "C" void GetWorldPosition__8mgCFrameFPfPf(mgCFrame *objet, f32 *arg0, f32 *arg1) {
    f32 sp30[16];
    *(s32 *) ((u8 *) arg1 + 0xC) = 0x3F800000;
    GetLWMatrix__8mgCFrameFPA4_f(objet, (f32 (*)[4]) sp30);
    sceVu0ApplyMatrix(arg0, sp30, arg1);
}
INCLUDE_ASM("nonmatchings/mglib/mgcframe", GetWorldPosition0__8mgCFrameFPf);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", GetWorldDir__8mgCFrameFPfPf);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", SetRotation__8mgCFrameFPf);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", SetRotation__8mgCFrameFfff);
typedef struct mgCFrame_infere4 {
    /* 0x000 */ char pad0[0x100];
    /* 0x100 */ s32 unk100;                         /* inferred */
} mgCFrame_infere4;                                         /* size >= 0x104 */
extern "C" void SetRotType__8mgCFrameFi(mgCFrame_infere4 *objet, s32 arg0) {
    objet->unk100 = arg0;
    if (arg0 & 2) {
        objet->unk100 |= 1;
    }
}
INCLUDE_ASM("nonmatchings/mglib/mgcframe", SetAttrParam__8mgCFrameFR12mgCFrameAttrii);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", SetAttrParamObjAlpha__8mgCFrameFfi);
struct mgCFrame_infere5 {
    /* 0x00 */ char pad0[0x58];
    /* 0x58 */ mgCFrame_infere5 *unk58;
    /* 0x5C */ mgCFrame_infere5 *unk5C;
    /* 0x60 */ char pad60[0x94];
    /* 0xF4 */ void *unkF4;
};
struct temp_v1_champs_41162d {
    char pad0[0x18];
    /* 0x18 */ s32 unk18;
};
extern "C" void SetAttrParamDraw__8mgCFrameFii(mgCFrame_infere5 *objet, s32 arg0, s32 arg1) {
    mgCFrame_infere5 *var_s0;
    struct temp_v1_champs_41162d *temp_v1;

    temp_v1 = (struct temp_v1_champs_41162d *) (objet->unkF4);
    if (temp_v1 != NULL) {
        temp_v1->unk18 = arg0;
    }
    if (arg1 == 0) {
        return;
    }
    for (var_s0 = objet->unk58; var_s0 != NULL; var_s0 = var_s0->unk5C) {
        SetAttrParamDraw__8mgCFrameFii(var_s0, arg0, 1);
    }
}
INCLUDE_ASM("nonmatchings/mglib/mgcframe", Draw__8mgCFrameFPUi);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", GetDrawRect__8mgCFrameFP9mgVu0FBOXP14mgCDrawManager);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", __as__8mgCFrameFR8mgCFrame);
INCLUDE_ASM("nonmatchings/mglib/mgcframe", Draw__8mgCFrameFv);
void mgCObject::ChangeParam(void) {
    this->field_0x40 = 1;
}
void mgCObject::UseParam(void) {
    this->field_0x40 = 1;
}
s32 mgCObject::DrawDirect(void) {
    return 0;
}
s32 mgCObject::Draw(void) {
    return 0;
}
