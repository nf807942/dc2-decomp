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
INCLUDE_ASM("nonmatchings/game/ccharacter2", _SHAPE_ANIME__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ccharacter2", _KEY_START__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ccharacter2", _KEY__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ccharacter2", _KEY_END__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ccharacter2", _SEQ_START__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ccharacter2", _SEQ__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ccharacter2", _SEQ_END__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ccharacter2", _CLOTH_START__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ccharacter2", __ct__13CDynamicAnimeFv);
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
INCLUDE_ASM("nonmatchings/game/ccharacter2", _EFFECT_START__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ccharacter2", _EFFECT__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ccharacter2", _EFFECT_END__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ccharacter2", InitEffect__11CCharacter2Fv);
INCLUDE_ASM("nonmatchings/game/ccharacter2", ExecEntryEffect__11CCharacter2FP15CHRINFO_KEY_SET);
INCLUDE_ASM("nonmatchings/game/ccharacter2", CtrlEffect__11CCharacter2Fv);
INCLUDE_ASM("nonmatchings/game/ccharacter2", StepEffect__11CCharacter2Fv);
INCLUDE_ASM("nonmatchings/game/ccharacter2", DrawEffect__11CCharacter2Fv);
INCLUDE_ASM("nonmatchings/game/ccharacter2", ScanInfoSkinFile__FP11CCharacter2PUiPcPcP9mgCMemoryi);
INCLUDE_ASM("nonmatchings/game/ccharacter2", _SKIN_IMG__FP9SPI_STACKi);
s32 _SKIN_IMG_END(SPI_STACK *stack, int argc) {
    return 1;
}
INCLUDE_ASM("nonmatchings/game/ccharacter2", _SKIN_MODEL__FP9SPI_STACKi);
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
INCLUDE_ASM("nonmatchings/game/ccharacter2", SetWind__13CDynamicAnimeFfPf);
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
INCLUDE_ASM("nonmatchings/game/ccharacter2", dynFRAME_START__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ccharacter2", dynFRAME__FP9SPI_STACKi);
s32 dynFRAME_END(SPI_STACK *stack, int argc) {
    return 1;
}
INCLUDE_ASM("nonmatchings/game/ccharacter2", dynVERTEX_START__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ccharacter2", dynVERTEX__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ccharacter2", dynVERTEX_L__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ccharacter2", dynVERTEX_END__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ccharacter2", dynFIX_VERTEX_START__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ccharacter2", dynFixVertex__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ccharacter2", dynFIX_VERTEX__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ccharacter2", dynFIX_VERTEX_C__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ccharacter2", dynFIX_VERTEX_S__FP9SPI_STACKi);
s32 dynFIX_VERTEX_END(SPI_STACK *stack, int argc) {
    return 1;
}
INCLUDE_ASM("nonmatchings/game/ccharacter2", FRAME_POSE_Sub__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ccharacter2", dynFRAME_POSE_L__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ccharacter2", dynFRAME_POSE__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ccharacter2", dynDRAW_FRAME__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ccharacter2", dynBIND_VERTEX_START__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ccharacter2", dynBIND_VERTEX__FP9SPI_STACKi);
s32 dynBIND_VERTEX_END(SPI_STACK *stack, int argc) {
    return 1;
}
INCLUDE_ASM("nonmatchings/game/ccharacter2", dynBOUNDING_BOX_START__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ccharacter2", dynBOUNDING_BOX__FP9SPI_STACKi);
s32 dynBOUNDING_BOX_END(SPI_STACK *stack, int argc) {
    return 1;
}
INCLUDE_ASM("nonmatchings/game/ccharacter2", dynCOLLISION_START__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ccharacter2", dynCOLLISION__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ccharacter2", Initialize__10CDAColPipeFv);
INCLUDE_ASM("nonmatchings/game/ccharacter2", Initialize__12CDACollisionFv);
s32 dynCOLLISION_END(SPI_STACK *stack, int argc) {
    return 1;
}
INCLUDE_ASM("nonmatchings/game/ccharacter2", dynGRAVITY__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ccharacter2", dynK__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ccharacter2", dynWind__FP9SPI_STACKi);
INCLUDE_ASM("nonmatchings/game/ccharacter2", Load__13CDynamicAnimeFPciP8mgCFrameP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/ccharacter2", CheckHit__10CDAColPipeFPf);
