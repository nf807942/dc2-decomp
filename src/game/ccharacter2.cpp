/* CCharacter2, CDynamicAnime, CDAColPipe, CObject, CDACollision, CCharaLOD
 *
 * Unité découpée par `make carve` : 136 fonctions, 29776 octets, de
 * 0x00175F10 à 0x0017D680. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"
#include "gen/CCharaLOD.hpp"
#include "gen/CDynamicAnime.hpp"
#include "gen/CDynamicAnime.hpp"

/* Le corps ne rend qu'un code : ni la classe ni les arguments ne sont
 * déréférencés, donc leur disposition reste à établir. */
class CDACollision {
public:
    char pad_0[0x4];
    /* L'ordre des declarations decide de l'attribution des registres chez
     * MWCC. Celui-ci n'est pas celui de m2c : il a ete trouve en enumerant
     * les ordres possibles, et c'est le seul qui rende les octets du disque.
     * */
    s32 field_4;
    char pad_8[0x8];
    f32 field_10;
    char pad_14[0xC];
    f32 field_20;

    s32 CheckHit(f32 *point);
};

/* La pile de l'interpréteur de script d'objet. Les commandes qui ne rendent
 * qu'un code de retour ne la déréférencent pas : sa disposition reste à
 * établir. */
struct SPI_STACK;

INCLUDE_ASM("nonmatchings/game/ccharacter2", GetKeyListPtr__11CCharacter2FPcPi);
INCLUDE_ASM("nonmatchings/game/ccharacter2", GetSeqHeaderPtr__11CCharacter2FPcPi);
INCLUDE_ASM("nonmatchings/game/ccharacter2", DeleteExtMotion__11CCharacter2Fv);
INCLUDE_ASM("nonmatchings/game/ccharacter2", DeleteImage__11CCharacter2Fv);
INCLUDE_ASM("nonmatchings/game/ccharacter2", GetEntryObjectPos__11CCharacter2FiPf);
INCLUDE_ASM("nonmatchings/game/ccharacter2", GetEntryObjectPos__11CCharacter2FiPA4_f);
INCLUDE_ASM("nonmatchings/game/ccharacter2", GetEntryObjectPos__11CCharacter2FiiPf);
INCLUDE_ASM("nonmatchings/game/ccharacter2", GetWaitToFrame__11CCharacter2FPcf);
INCLUDE_ASM("nonmatchings/game/ccharacter2", LoadSkin__11CCharacter2FPUiPcPcP9mgCMemoryi);
INCLUDE_ASM("nonmatchings/game/ccharacter2", LoadPack__11CCharacter2FPUiPcP9mgCMemoryP9mgCMemoryP9mgCMemoryiP11CCharacter2);
INCLUDE_ASM("nonmatchings/game/ccharacter2", LoadPackNoLine__11CCharacter2FPUiPcP9mgCMemoryP9mgCMemoryP9mgCMemoryiP11CCharacter2);
INCLUDE_ASM("nonmatchings/game/ccharacter2", LoadChrFile__11CCharacter2FPUiPcP9mgCMemoryP9mgCMemoryP9mgCMemoryiP11CCharacter2i);
INCLUDE_ASM("nonmatchings/game/ccharacter2", Initialize__11CCharacter2Fv);
INCLUDE_ASM("nonmatchings/game/ccharacter2", ScanInfoFile__FP11CCharacter2PUiPcP9mgCMemoryP9mgCMemoryP9mgCMemoryiP11CCharacter2i);
s32 _V2(SPI_STACK *stack, int argc) {
    return 1;
}
s32 _NAME(SPI_STACK *stack, int argc) {
    return 1;
}
INCLUDE_ASM("nonmatchings/game/ccharacter2", _BODY_SIZE__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ccharacter2", _SCALE__FP9SPI_STACKi);
s32 _MATERIAL_ANIME(SPI_STACK *stack, int argc) {
    return 1;
}
INCLUDE_ASM("nonmatchings/game/ccharacter2", _POLY_NUM__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ccharacter2", _IMG__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ccharacter2", _IMG_END__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ccharacter2", _OUTLINE__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ccharacter2", _MODEL__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ccharacter2", _SHADOW_MODEL__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ccharacter2", _OBJECT_NAME__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ccharacter2", _OBJECT_NAME2__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ccharacter2", _MOTION__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ccharacter2", _SHADOW_MOTION__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ccharacter2", _VERTEX_ANIME__FP9SPI_STACKi);
typedef struct nowChr_pointe {
    char pad0[308];
    s32 unk134;
} nowChr_pointe;
extern "C" nowChr_pointe *nowChr;
extern "C" s32 spiGetStackInt__FP9SPI_STACK(SPI_STACK *);
extern "C" s32 _SHAPE_ANIME__FP9SPI_STACKi(SPI_STACK *arg0, s32 arg1) {
    if (arg1 != 1) {
        return 0;
    }
    nowChr->unk134 = spiGetStackInt__FP9SPI_STACK(arg0);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/ccharacter2", _KEY_START__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ccharacter2", _KEY__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ccharacter2", _KEY_END__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ccharacter2", _SEQ_START__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ccharacter2", _SEQ__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ccharacter2", _SEQ_END__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ccharacter2", _CLOTH_START__FP9SPI_STACKi);
extern "C" s32 Initialize__13CDynamicAnimeFv(...);
extern "C" CDynamicAnime *__ct__13CDynamicAnimeFv(CDynamicAnime *objet) {
    Initialize__13CDynamicAnimeFv(objet);
    return objet;
}
INCLUDE_ASM("nonmatchings/game/ccharacter2", _CLOTH__FP9SPI_STACKi);
s32 _CLOTH_END(SPI_STACK *stack, int argc) {
    return 1;
}
INCLUDE_ASM("nonmatchings/game/ccharacter2", _POSITION__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ccharacter2", _ROTATION__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ccharacter2", _SE_START__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ccharacter2", _SE__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ccharacter2", _SELP__FP9SPI_STACKi);
s32 _SE_END(SPI_STACK *stack, int argc) {
    return 1;
}
s32 _MOTION_END(SPI_STACK *stack, int argc) {
    return 1;
}
extern "C" u32 eff_pack_ptr;
extern "C" u32 pack_file;
extern "C" s32 spiGetStackString__FP9SPI_STACK(...);
extern "C" u32 eff_pack_size;
struct SPI_STACK_d070e6 {
    s32 field_0;
    s32 field_4;
};
extern "C" s32 GetPackFile__FPUiPcPi(...);
extern "C" s32 _EFFECT_START__FP9SPI_STACKi(SPI_STACK_d070e6 *arg0, s32 arg1) {
    eff_pack_ptr = GetPackFile__FPUiPcPi(pack_file, spiGetStackString__FP9SPI_STACK(arg0), &eff_pack_size);
    return eff_pack_ptr != 0;
}
INCLUDE_ASM("nonmatchings/game/ccharacter2", _EFFECT__FP9SPI_STACKi);
extern "C" u32 eff_pack_ptr;
extern "C" u32 eff_pack_size;
struct SPI_STACK {
    s32 field_0;
    s32 field_4;
};
extern "C" s32 _EFFECT_END__FP9SPI_STACKi(SPI_STACK *arg0, s32 arg1) {
    if (eff_pack_ptr == 0) {
        return 0;
    }
    eff_pack_ptr = 0;
    eff_pack_size = 0;
    return 1;
}
typedef struct CCharacter2 {
    /* 0x000 */ char pad0[0x5E4];
    /* 0x5E4 */ s32 unk5E4;                         /* inferred */
    /* 0x5E8 */ s32 unk5E8;                         /* inferred */
    /* 0x5EC */ s32 unk5EC;                         /* inferred */
    /* 0x5F0 */ s32 unk5F0;                         /* inferred */
    /* 0x5F4 */ s32 unk5F4;                         /* inferred */
    /* 0x5F8 */ s32 unk5F8;                         /* inferred */
    /* 0x5FC */ s32 unk5FC;                         /* inferred */
    /* 0x600 */ s32 unk600;                         /* inferred */
    /* 0x604 */ s32 unk604;                         /* inferred */
    /* 0x608 */ s32 unk608;                         /* inferred */
    /* 0x60C */ s32 unk60C;                         /* inferred */
    /* 0x610 */ s32 unk610;                         /* inferred */
    /* 0x614 */ s32 unk614;                         /* inferred */
    /* 0x618 */ s32 unk618;                         /* inferred */
    /* 0x61C */ s32 unk61C;                         /* inferred */
    /* 0x620 */ s32 unk620;                         /* inferred */
    /* 0x624 */ s32 unk624;                         /* inferred */
    /* 0x628 */ s32 unk628;                         /* inferred */
    /* 0x62C */ s32 unk62C;                         /* inferred */
    /* 0x630 */ s32 unk630;                         /* inferred */
    /* 0x634 */ s32 unk634;                         /* inferred */
    /* 0x638 */ s32 unk638;                         /* inferred */
    /* 0x63C */ s32 unk63C;                         /* inferred */
    /* 0x640 */ s32 unk640;                         /* inferred */
    /* 0x644 */ s32 unk644;                         /* inferred */
    /* 0x648 */ s32 unk648;                         /* inferred */
    /* 0x64C */ s32 unk64C;                         /* inferred */
    /* 0x650 */ s32 unk650;                         /* inferred */
} CCharacter2;                                      /* size >= 0x654 */
extern "C" void InitEffect__11CCharacter2Fv(CCharacter2 *objet) {
    objet->unk5EC = 0;
    objet->unk5F0 = 0;
    objet->unk5F4 = 0;
    objet->unk5F8 = 0;
    objet->unk5FC = 0;
    objet->unk600 = 0;
    objet->unk604 = 0;
    objet->unk608 = 0;
    objet->unk60C = 0;
    objet->unk610 = 0;
    objet->unk614 = 0;
    objet->unk618 = 0;
    objet->unk61C = 0;
    objet->unk620 = 0;
    objet->unk624 = 0;
    objet->unk628 = 0;
    objet->unk62C = 0;
    objet->unk630 = 0;
    objet->unk634 = 0;
    objet->unk638 = 0;
    objet->unk63C = 0;
    objet->unk640 = 0;
    objet->unk644 = 0;
    objet->unk648 = 0;
    objet->unk5E8 = 0;
    objet->unk650 = 1;
    objet->unk64C = 0;
    objet->unk5E4 = 1;
}
INCLUDE_ASM("nonmatchings/game/ccharacter2", ExecEntryEffect__11CCharacter2FP15CHRINFO_KEY_SET);
INCLUDE_ASM("nonmatchings/game/ccharacter2", CtrlEffect__11CCharacter2Fv);
INCLUDE_ASM("nonmatchings/game/ccharacter2", StepEffect__11CCharacter2Fv);
INCLUDE_ASM("nonmatchings/game/ccharacter2", DrawEffect__11CCharacter2Fv);
INCLUDE_ASM("nonmatchings/game/ccharacter2", ScanInfoSkinFile__FP11CCharacter2PUiPcPcP9mgCMemoryi);
INCLUDE_ASM("nonmatchings/game/ccharacter2", _SKIN_IMG__FP9SPI_STACKi);
s32 _SKIN_IMG_END(SPI_STACK *stack, int argc) {
    return 1;
}
extern "C" u8 _1395_00368260[14];
extern "C" u32 pack_file;
extern "C" u8 skin_mds_name[64];
extern "C" s32 spiGetStackString__FP9SPI_STACK(...);
extern "C" s32 GetPackFile__FPUiPcPi(...);
extern "C" s32 printf(...);
extern "C" s32 strcpy(...);
extern "C" s32 _SKIN_MODEL__FP9SPI_STACKi(SPI_STACK *arg0, s32 arg1) {
    s8 *temp_v0;

    if (arg1 != 1) {
        return 0;
    }
    temp_v0 = (s8 *) (spiGetStackString__FP9SPI_STACK(arg0));
    if (GetPackFile__FPUiPcPi(pack_file, temp_v0, NULL) == 0) {
        printf(&_1395_00368260, temp_v0);
        return 0;
    }
    strcpy(&skin_mds_name, temp_v0);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/ccharacter2", CreateChangeFrame__FP10mgLoadDataP8mgCFrame);
INCLUDE_ASM("nonmatchings/game/ccharacter2", _SKIN_MOTION__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ccharacter2", _LOD_MODEL_START__FP9SPI_STACKi);
CCharaLOD::CCharaLOD(void) {
    this->field_0x10 = 0;
    this->field_0x14 = 0;
    this->field_0xC = 0;
    this->field_0x0 = 0;
    this->field_0x8 = 0;
    this->field_0x4 = 0;
}
INCLUDE_ASM("nonmatchings/game/ccharacter2", _LOD_MODEL__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ccharacter2", _LOD_MODEL_END__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ccharacter2", ChangeLOD__11CCharacter2Fi);
INCLUDE_ASM("nonmatchings/game/ccharacter2", Copy__11CCharacter2FR11CCharacter2P9mgCMemory);
INCLUDE_ASM("nonmatchings/game/ccharacter2", __as__7CObjectFRC7CObject);
INCLUDE_ASM("nonmatchings/game/ccharacter2", BindPosition__FPfPfff_0017ABD0);
INCLUDE_ASM("nonmatchings/game/ccharacter2", ResetPosition__13CDynamicAnimeFv);
INCLUDE_ASM("nonmatchings/game/ccharacter2", Step__13CDynamicAnimeFv);
s32 CDACollision::CheckHit(f32 *point) {
    return 0;
}
extern "C" void sceVu0Normalize(f32 *, f32 *);
extern "C" void SetWind__13CDynamicAnimeFfPf(CDynamicAnime *objet, f32 arg0, f32 *arg1) {
    *(f32 *) ((u8 *) objet + 0x68) = arg0;
    sceVu0Normalize((f32 *) ((u8 *) objet + 0x70), arg1);
}
void CDynamicAnime::ResetWind(void) {
    this->field_0x68 = 0;
}
void CDynamicAnime::SetFloor(f32 arg0) {
    this->field_0x88 = 1;
    this->field_0x8C = arg0;
}
void CDynamicAnime::ResetFloor(void) {
    this->field_0x88 = 0;
}
INCLUDE_ASM("nonmatchings/game/ccharacter2", FramePose__13CDynamicAnimeFP8mgCFrameP13DA_FRAME_POSE);
INCLUDE_ASM("nonmatchings/game/ccharacter2", PreCollision__13CDynamicAnimeFv);
INCLUDE_ASM("nonmatchings/game/ccharacter2", Initialize__13CDynamicAnimeFv);
INCLUDE_ASM("nonmatchings/game/ccharacter2", NewFrameTable__13CDynamicAnimeFiP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/ccharacter2", NewVertexTable__13CDynamicAnimeFiP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/ccharacter2", NewFixVertexTable__13CDynamicAnimeFiP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/ccharacter2", NewDrawFrameTable__13CDynamicAnimeFiP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/ccharacter2", NewBindVertexTable__13CDynamicAnimeFiP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/ccharacter2", NewBoundingBoxTable__13CDynamicAnimeFiP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/ccharacter2", NewCollisionTable__13CDynamicAnimeFiP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/ccharacter2", SetFrame__13CDynamicAnimeFiP8mgCFrame);
INCLUDE_ASM("nonmatchings/game/ccharacter2", GetFrame__13CDynamicAnimeFi);
INCLUDE_ASM("nonmatchings/game/ccharacter2", pGetFramePose__13CDynamicAnimeFi);
INCLUDE_ASM("nonmatchings/game/ccharacter2", CheckVertexID__13CDynamicAnimeFi);
INCLUDE_ASM("nonmatchings/game/ccharacter2", SetInitVertex__13CDynamicAnimeFiPf);
INCLUDE_ASM("nonmatchings/game/ccharacter2", GetInitVertex__13CDynamicAnimeFiPf);
INCLUDE_ASM("nonmatchings/game/ccharacter2", SetNowVertex__13CDynamicAnimeFiPf);
INCLUDE_ASM("nonmatchings/game/ccharacter2", SetOldVertex__13CDynamicAnimeFiPf);
INCLUDE_ASM("nonmatchings/game/ccharacter2", pGetFixVertex__13CDynamicAnimeFi);
INCLUDE_ASM("nonmatchings/game/ccharacter2", SetDrawFrame__13CDynamicAnimeFii);
INCLUDE_ASM("nonmatchings/game/ccharacter2", GetDrawFrame__13CDynamicAnimeFi);
INCLUDE_ASM("nonmatchings/game/ccharacter2", pGetBindVertex__13CDynamicAnimeFi);
INCLUDE_ASM("nonmatchings/game/ccharacter2", pGetBoundingBox__13CDynamicAnimeFi);
INCLUDE_ASM("nonmatchings/game/ccharacter2", SetCollision__13CDynamicAnimeFiP12CDACollision);
INCLUDE_ASM("nonmatchings/game/ccharacter2", DrawSub__13CDynamicAnimeFi);
INCLUDE_ASM("nonmatchings/game/ccharacter2", Copy__13CDynamicAnimeFR13CDynamicAnimeP8mgCFrameP9mgCMemory);
extern "C" u32 dynNowDA;
extern "C" u32 dynStack;
#include "menu.hpp"
extern "C" s32 spiGetStackInt__FP9SPI_STACK(SPI_STACK *);
extern "C" s32 NewFrameTable__13CDynamicAnimeFiP9mgCMemory(...);
extern "C" s32 dynFRAME_START__FP9SPI_STACKi(SPI_STACK *arg0, s32 arg1) {
    NewFrameTable__13CDynamicAnimeFiP9mgCMemory(dynNowDA, spiGetStackInt__FP9SPI_STACK(arg0), dynStack);
    return 1;
}
extern "C" u8 _855_00368458[14];
extern "C" u32 dynFrameCount;
extern "C" u32 dynTopFrame;
extern "C" s32 SearchFrame__8mgCFrameFPc(...);
#include "gen/mgCFrame.hpp"
extern "C" s32 printf(...);
extern "C" s32 SetFrame__13CDynamicAnimeFiP8mgCFrame(...);
extern "C" s32 dynFRAME__FP9SPI_STACKi(SPI_STACK *arg0, s32 arg1) {
    s32 temp_a1;
    s8 *temp_v0;
    mgCFrame *temp_v0_2;

    temp_v0 = (s8 *) (spiGetStackString__FP9SPI_STACK(arg0));
    if (temp_v0 == NULL) {
        return 0;
    }
    temp_v0_2 = (mgCFrame *) (SearchFrame__8mgCFrameFPc(dynTopFrame, temp_v0));
    if (temp_v0_2 == NULL) {
        printf(&_855_00368458, temp_v0);
    }
    temp_a1 = dynFrameCount;
    dynFrameCount = temp_a1 + 1;
    SetFrame__13CDynamicAnimeFiP8mgCFrame(dynNowDA, temp_a1, temp_v0_2);
    return 1;
}

s32 dynFRAME_END(SPI_STACK *stack, int argc) {
    return 1;
}
extern "C" s32 spiGetStackInt__FP9SPI_STACK(SPI_STACK *);
extern "C" s32 NewVertexTable__13CDynamicAnimeFiP9mgCMemory(...);
extern "C" s32 dynVERTEX_START__FP9SPI_STACKi(SPI_STACK *arg0, s32 arg1) {
    NewVertexTable__13CDynamicAnimeFiP9mgCMemory(dynNowDA, spiGetStackInt__FP9SPI_STACK(arg0), dynStack);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/ccharacter2", dynVERTEX__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ccharacter2", dynVERTEX_L__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ccharacter2", dynVERTEX_END__FP9SPI_STACKi);
struct inferred;
struct CDynamicAnime_infere;
typedef struct CDynamicAnime_infere {
    /* 0x00 */ char pad0[0x10];
    /* 0x10 */ s32 unk10;                           /* inferred */
} CDynamicAnime_infere;                                    /* size >= 0x14 */
struct dynNowDA_champs_73b007 {
    char pad0[0x10];
    /* 0x10 */ s32 unk10;
};
extern "C" s32 NewFixVertexTable__13CDynamicAnimeFiP9mgCMemory(...);
extern "C" s32 dynFIX_VERTEX_START__FP9SPI_STACKi(SPI_STACK *arg0, s32 arg1) {
    spiGetStackInt__FP9SPI_STACK(arg0);
    NewFixVertexTable__13CDynamicAnimeFiP9mgCMemory(dynNowDA, ((struct dynNowDA_champs_73b007 *) dynNowDA)->unk10, dynStack);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/ccharacter2", dynFixVertex__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ccharacter2", dynFIX_VERTEX__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ccharacter2", dynFIX_VERTEX_C__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ccharacter2", dynFIX_VERTEX_S__FP9SPI_STACKi);
s32 dynFIX_VERTEX_END(SPI_STACK *stack, int argc) {
    return 1;
}
INCLUDE_ASM("nonmatchings/game/ccharacter2", FRAME_POSE_Sub__FP9SPI_STACKi);
extern "C" s32 FRAME_POSE_Sub__FP9SPI_STACKi(SPI_STACK *, s32);
struct temp_s0_champs_131d30 {
    char pad0[0xC];
    /* 0xC */ s32 unkC;
};
extern "C" s32 GetFrame__13CDynamicAnimeFi(...);
extern "C" s32 dynFRAME_POSE_L__FP9SPI_STACKi(SPI_STACK *arg0, s32 arg1) {
    s32 temp_v0;
    struct temp_s0_champs_131d30 *temp_s0;

    temp_s0 = (struct temp_s0_champs_131d30 *) (FRAME_POSE_Sub__FP9SPI_STACKi(arg0, arg1));
    temp_v0 = (s32) (GetFrame__13CDynamicAnimeFi(dynNowDA, spiGetStackInt__FP9SPI_STACK(arg0)));
    if ((temp_s0 == NULL) || (temp_v0 == 0)) {
        return 0;
    }
    temp_s0->unkC = 1;
    return 1;
}
extern "C" s32 FRAME_POSE_Sub__FP9SPI_STACKi(SPI_STACK *, s32);
extern "C" s32 GetFrame__13CDynamicAnimeFi(...);
#include "gen/mgCFrame.hpp"
struct temp_s0_champs_8f5fa6 {
    char pad0[0xC];
    /* 0xC */ s32 unkC;
};
extern "C" s32 DeleteParent__8mgCFrameFv(void *);
extern "C" s32 dynFRAME_POSE__FP9SPI_STACKi(SPI_STACK *arg0, s32 arg1) {
    mgCFrame *temp_v0;
    struct temp_s0_champs_8f5fa6 *temp_s0;

    temp_s0 = (struct temp_s0_champs_8f5fa6 *) (FRAME_POSE_Sub__FP9SPI_STACKi(arg0, arg1));
    temp_v0 = (mgCFrame *) (GetFrame__13CDynamicAnimeFi(dynNowDA, spiGetStackInt__FP9SPI_STACK(arg0)));
    if ((temp_s0 == NULL) || (temp_v0 == NULL)) {
        return 0;
    }
    temp_s0->unkC = 0;
    DeleteParent__8mgCFrameFv(temp_v0);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/ccharacter2", dynDRAW_FRAME__FP9SPI_STACKi);
extern "C" s32 spiGetStackInt__FP9SPI_STACK(SPI_STACK *);
extern "C" s32 NewBindVertexTable__13CDynamicAnimeFiP9mgCMemory(...);
extern "C" s32 dynBIND_VERTEX_START__FP9SPI_STACKi(SPI_STACK *arg0, s32 arg1) {
    NewBindVertexTable__13CDynamicAnimeFiP9mgCMemory(dynNowDA, spiGetStackInt__FP9SPI_STACK(arg0), dynStack);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/ccharacter2", dynBIND_VERTEX__FP9SPI_STACKi);
s32 dynBIND_VERTEX_END(SPI_STACK *stack, int argc) {
    return 1;
}
extern "C" s32 NewBoundingBoxTable__13CDynamicAnimeFiP9mgCMemory(...);
extern "C" s32 dynBOUNDING_BOX_START__FP9SPI_STACKi(SPI_STACK *arg0, s32 arg1) {
    NewBoundingBoxTable__13CDynamicAnimeFiP9mgCMemory(dynNowDA, spiGetStackInt__FP9SPI_STACK(arg0), dynStack);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/ccharacter2", dynBOUNDING_BOX__FP9SPI_STACKi);
s32 dynBOUNDING_BOX_END(SPI_STACK *stack, int argc) {
    return 1;
}
extern "C" s32 NewCollisionTable__13CDynamicAnimeFiP9mgCMemory(...);
extern "C" s32 dynCOLLISION_START__FP9SPI_STACKi(SPI_STACK *arg0, s32 arg1) {
    NewCollisionTable__13CDynamicAnimeFiP9mgCMemory(dynNowDA, spiGetStackInt__FP9SPI_STACK(arg0), dynStack);
    return 1;
}
INCLUDE_ASM("nonmatchings/game/ccharacter2", dynCOLLISION__FP9SPI_STACKi);
typedef struct CDAColPipe {
    /* 0x00 */ char pad0[4];
    /* 0x04 */ s32 unk4;                            /* inferred */
    /* 0x08 */ char pad8[8];                        /* maybe part of unk4[3]? */
    /* 0x10 */ f32 unk10;                           /* inferred */
    /* 0x14 */ char pad14[0xC];                     /* maybe part of unk10[4]? */
    /* 0x20 */ f32 unk20;                           /* inferred */
    /* 0x24 */ char pad24[0xAC];                    /* maybe part of unk20[0x2C]? */
    /* 0xD0 */ s32 unkD0;                           /* inferred */
} CDAColPipe;                                       /* size >= 0xD4 */
extern "C" void mgZeroVector__FPf(...);
extern "C" void Initialize__10CDAColPipeFv(CDAColPipe *objet) {
    objet->unkD0 = 0;
    mgZeroVector__FPf(&objet->unk10);
    mgZeroVector__FPf(&objet->unk20);
    objet->unk4 = 0x3F4CCCCD;
}
struct inferred;
typedef struct CDACollision_infere {
    /* 0x00 */ char pad0[4];
    /* 0x04 */ s32 unk4;                            /* inferred */
    /* 0x08 */ char pad8[8];                        /* maybe part of unk4[3]void */
    /* 0x10 */ f32 unk10;                           /* inferred */
    /* 0x14 */ char pad14[0xC];                     /* maybe part of unk10[4]void */
    /* 0x20 */ f32 unk20;                           /* inferred */
} CDACollision_infere;                                     /* size >= 0x24 */
extern "C" void Initialize__12CDACollisionFv(CDACollision_infere *objet) {
    mgZeroVector__FPf(&objet->unk10);
    mgZeroVector__FPf(&objet->unk20);
    objet->unk4 = 0x3F4CCCCD;
}
s32 dynCOLLISION_END(SPI_STACK *stack, int argc) {
    return 1;
}
struct dynNowDA_champs_0c1c0d {
    char pad0[0x5C];
    /* 0x5C */ s32 unk5C;
};
extern "C" s32 spiGetStackVector__FPfP9SPI_STACK(...);
extern "C" s32 dynGRAVITY__FP9SPI_STACKi(SPI_STACK *arg0, s32 arg1) {
    spiGetStackVector__FPfP9SPI_STACK(dynNowDA + 0x50, arg0);
    ((struct dynNowDA_champs_0c1c0d *) dynNowDA)->unk5C = 0;
    return 1;
}
INCLUDE_ASM("nonmatchings/game/ccharacter2", dynK__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ccharacter2", dynWind__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ccharacter2", Load__13CDynamicAnimeFPciP8mgCFrameP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/ccharacter2", CheckHit__10CDAColPipeFPf);
