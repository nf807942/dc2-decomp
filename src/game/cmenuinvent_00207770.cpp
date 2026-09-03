/* CMenuInvent, CStarDust
 *
 * Unité découpée par `make carve` : 17 fonctions, 18448 octets, de
 * 0x00207770 à 0x0020C000. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"
#include "gen/CStarDust.hpp"

INCLUDE_ASM("nonmatchings/game/cmenuinvent_00207770", IsAskExtend__11CMenuInventFii);
INCLUDE_ASM("nonmatchings/game/cmenuinvent_00207770", PhotoNetaEnter__11CMenuInventFii);
CStarDust::CStarDust(void) {
    this->field_0xA = 0;
}
INCLUDE_ASM("nonmatchings/game/cmenuinvent_00207770", IsAccessAlbum__11CMenuInventFv);
INCLUDE_ASM("nonmatchings/game/cmenuinvent_00207770", GetNetaBoardCursorPosition__11CMenuInventFiPi);
INCLUDE_ASM("nonmatchings/game/cmenuinvent_00207770", GetNetaMemoCursorPosition__11CMenuInventFiPi);
INCLUDE_ASM("nonmatchings/game/cmenuinvent_00207770", neta_sort__FiiiPi);
INCLUDE_ASM("nonmatchings/game/cmenuinvent_00207770", UpdataNetaMemoStr__11CMenuInventFv);
INCLUDE_ASM("nonmatchings/game/cmenuinvent_00207770", MakeMsgNetaName__FP7CDC2MesP16CMenuPosDataFormP17USER_PICTURE_INFOPii);
INCLUDE_ASM("nonmatchings/game/cmenuinvent_00207770", MenuInventCreateCardDraw__FRiPf);
INCLUDE_ASM("nonmatchings/game/cmenuinvent_00207770", PictureDraw__FP10mgCTextureP17USER_PICTURE_INFOfffiiii);
extern "C" s32 GetMenuPrim__Fv(void);
extern "C" u32 Tex_Hatsumei;
#include "gen/mgCDrawPrim.hpp"
struct mgCTexture {
    s16 field_0;
    s16 field_2;
    s16 field_4;
    s16 field_6;
    char pad_8[0x4];
    s32 field_C;
    s32 field_10;
    s16 field_14;
    char pad_16[0x2];
    s32 field_18;
    s32 field_1C;
    char pad_20[0x8];
    s32 field_28;
    s32 field_2C;
    s32 field_30;
    char pad_34[0x4];
    s64 field_38;
    s64 field_40;
    s64 field_48;
    s32 field_50;
    f32 field_54;
    f32 field_58;
    f32 field_5C;
    s32 field_60;
    s32 field_64;
    s32 field_68;
    char pad_6C[0xA4];
    s32 field_110;
    s32 field_114;
    s32 field_118;
    s16 field_11C;
    s8 field_11E;
    s8 field_11F;
    s16 field_120;
    s16 field_122;
    s32 field_124;
    s32 field_128;
    s8 field_12C;
    s8 field_12D;
    char pad_12E[0x2];
    s32 field_130;
    s32 field_134;
    s32 field_138;
    s32 field_13C;
    char pad_140[0x4];
    s32 field_144;
    s32 field_148;
    s32 field_14C;
    s32 field_150;
    s32 field_154;
    s32 field_158;
    s32 field_15C;
    s32 field_160;
    s32 field_164;
    s32 field_168;
    s32 field_16C;
    s32 field_170;
    s32 field_174;
    s32 field_178;
    s32 field_17C;
    s32 field_180;
    s32 field_184;
    s32 field_188;
    s32 field_18C;
    s32 field_190;
    char pad_194[0x60];
    s32 field_1F4;
    s32 field_1F8;
    s32 field_1FC;
    s8 field_200;
    s8 field_201;
    s16 field_202;
    s32 field_204;
    s8 field_208;
    s8 field_209;
    char pad_20A[0x2];
    s32 field_20C;
    s32 field_210;
    s32 field_214;
    s32 field_218;
    s32 field_21C;
    char pad_220[0xC];
    s32 field_22C;
    s32 field_230;
    s32 field_234;
    s32 field_238;
    s32 field_23C;
    s32 field_240;
    char pad_244[0x4];
    s32 field_248;
    s16 field_24C;
    s16 field_24E;
    char pad_250[0x6];
    s16 field_256;
    f32 field_258;
    f32 field_25C;
    char pad_260[0x4];
    f32 field_264;
    f32 field_268;
    f32 field_26C;
    char pad_270[0x4];
    f32 field_274;
    f32 field_278;
    char pad_27C[0x68];
    s32 field_2E4;
    char pad_2E8[0x74];
    s32 field_35C;
    s32 field_360;
    s32 field_364;
};
extern "C" s32 Begin__11mgCDrawPrimFi(void *, s32);
extern "C" s32 Bilinear__11mgCDrawPrimFi(void *, s32);
extern "C" s32 Color__11mgCDrawPrimFiiii(void *, s32, s32, s32, s32);
extern "C" s32 End__11mgCDrawPrimFv(void *);
extern "C" s32 SetSpriteEnv__FP11mgCDrawPrimi(mgCDrawPrim *, s32);
extern "C" s32 TextureCrd__11mgCDrawPrimFii(void *, s32, s32);
extern "C" s32 Texture__11mgCDrawPrimFP10mgCTexture(...);
extern "C" s32 Vertex__11mgCDrawPrimFfff(void *, f32, f32, f32);
extern "C" void PictureMemoOne__Fffi(f32 arg0, f32 arg1, s32 arg2) {
    mgCDrawPrim *temp_v0;

    temp_v0 = (mgCDrawPrim *) (GetMenuPrim__Fv());
    SetSpriteEnv__FP11mgCDrawPrimi(temp_v0, 0);
    Bilinear__11mgCDrawPrimFi(temp_v0, 1);
    Begin__11mgCDrawPrimFi(temp_v0, 6);
    Texture__11mgCDrawPrimFP10mgCTexture(temp_v0, Tex_Hatsumei);
    Color__11mgCDrawPrimFiiii(temp_v0, 0x80, 0x80, 0x80, arg2);
    TextureCrd__11mgCDrawPrimFii(temp_v0, 0x6E, 0x162);
    Vertex__11mgCDrawPrimFfff(temp_v0, arg0, arg1, 0.0f);
    TextureCrd__11mgCDrawPrimFii(temp_v0, 0x90, 0x184);
    Vertex__11mgCDrawPrimFfff(temp_v0, 34.0f + arg0, 34.0f + arg1, 0.0f);
    End__11mgCDrawPrimFv(temp_v0);
}
INCLUDE_ASM("nonmatchings/game/cmenuinvent_00207770", PictureDraw__FRi9mgRect_f_ifPUc);
INCLUDE_ASM("nonmatchings/game/cmenuinvent_00207770", MenuInventPictureBoardDraw__FPfRii);
INCLUDE_ASM("nonmatchings/game/cmenuinvent_00207770", MenuInventAlbumPictureDraw__FPfRi);
INCLUDE_ASM("nonmatchings/game/cmenuinvent_00207770", MenuInventNetaMemoDraw__FPfRi);
INCLUDE_ASM("nonmatchings/game/cmenuinvent_00207770", MenuInventInit__FP9mgCMemoryPii);
