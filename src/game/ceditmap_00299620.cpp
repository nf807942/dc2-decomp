/* CEditMap, CEditGrid, CMovie, CGridData
 *
 * Unité découpée par `make carve` : 111 fonctions, 24460 octets, de
 * 0x00299620 à 0x0029F850. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"
#include "gen/VideoDec.hpp"
#include "gen/VoBuf.hpp"

/* Les globales que ces accesseurs servent. Leur taille déclarée est celle que
 * le découpage leur donne, et c'est elle qui décide du `%gp_rel`. */
extern u8 isStarted;

/* Les corps ne rendent qu'un code : ni la classe ni les arguments ne sont
 * déréférencés, donc leur disposition reste à établir. */

struct sceMpeg;
struct sceMpegCbDataError;

class CMovie {
public:
    char pad_0[0x14];
    s32 field_14;
    s32 field_18;
    s32 field_1C;
    s32 field_20;
    char pad_24[0x5C];
    s32 field_80;
    s32 field_84;
    char pad_88[0x40];
    s32 field_C8;
    s32 field_CC;
    char pad_D0[0x8830];
    u8 field_8900;
    char pad_8901[0x1AFFF];
    u8 field_23900;

    s32 IsStarted();
    s32 GetViBufTagSize();
};

INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", MenuNPCQuestViewInit__FP9mgCMemoryPii);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", MenuNPCQuestViewKey__Fv);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", MenuNPCQuestViewDraw__Fv);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", PlaceRiver__8CEditMapFPf);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", RemoveRiver__8CEditMapFPf);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", CreateGrid__8CEditMapFPfPfP9mgCMemoryPf);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", GetRiverNum__8CEditMapFPf);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", IsRiverGrid__8CEditMapFPf);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", GetRiverNum__8CEditMapFif);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", DrawRiverMask__8CEditMapFv);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", DrawRiver__8CEditMapFv);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", Create__9CEditGridFiiP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", __ct__9CGridDataFv);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", Clear__9CEditGridFv);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", Initialize__9CEditGridFv);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", Check__9CEditGridFii);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", Get__9CEditGridFii);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", GetFast__9CEditGridFii);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", GetLPos__9CEditGridFPiff);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", GetWPos__9CEditGridFPfii);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", SetRiver__9CEditGridFff);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", ResetRiver__9CEditGridFff);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", SetRiver__9CEditGridFii);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", ResetRiver__9CEditGridFii);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", UpdateRiver__9CEditGridFii);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", River__9CEditGridFii);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", GetRiverPos__9CEditGridFiiPA4_f);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", GetRiverPos__9CEditGridFiiPf);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", GetRiverPoly__9CEditGridFP6CCPolyRC9mgVu0FBOXif);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", GetGridBox__9CEditGridFP9mgVu0FBOXPf);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", Load__6CMovieFPcPP9mgCMemoryiibbb);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", Load__6CMovieFPcP9mgCMemoryiibb);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", Load__6CMovieFPcP9mgCMemoryiibbb);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", Play__6CMovieFPc);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", SwitchThread__6CMovieFv);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", Term__6CMovieFv);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", EndCheck__6CMovieFv);
s32 CMovie::IsStarted(void) {
    return isStarted;
}
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", GetVoBufDataSize__6CMovieFv);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", GetViBufDataSize__6CMovieFv);
s32 CMovie::GetViBufTagSize(void) {
    return 0x1010;
}
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", GetMpegWorkSize__6CMovieFii);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", GetReadBufSize__6CMovieFv);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", GetTagProgSize__6CMovieFii);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", videoDecCreate__6CMovieFP8VideoDecPUciP1P1iP9TimeStampi);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", videoDecSetStream__6CMovieFP8VideoDeciiPFP7sceMpegP13sceMpegCbDataPv_iPv);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", videoDecDelete__6CMovieFP8VideoDec);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", videoDecFlush__6CMovieFP8VideoDec);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", defMain__FPv);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", videoDecMain__FPv);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", stepMain__FPv);
s32 mpegError(sceMpeg *mpeg, sceMpegCbDataError *error, void *user) {
    return 1;
}
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", mpegNodata__FP7sceMpegP13sceMpegCbDataPv);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", mpegStopDMA__FP7sceMpegP13sceMpegCbDataPv);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", mpegRestartDMA__FP7sceMpegP13sceMpegCbDataPv);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", mpegTS__FP7sceMpegP22sceMpegCbDataTimeStampPv);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", videoCallback__FP7sceMpegP16sceMpegCbDataStrPv);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", pcmCallback__FP7sceMpegP16sceMpegCbDataStrPv);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", vblankHandler__Fi);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", handler_endimage__Fi);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", voBufCreate__FP5VoBufP6VoDataP5VoTagi);
void voBufReset(VoBuf * arg0) {
    arg0->field_0xC = 0;
    arg0->field_0x10 = 0;
}
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", voBufIsFull__FP5VoBuf);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", voBufIncCount__FP5VoBuf);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", voBufGetData__FP5VoBuf);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", voBufIsEmpty__FP5VoBuf);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", voBufGetTag__FP5VoBuf);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", voBufDecCount__FP5VoBuf);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", getFIFOindex__FP5ViBufPv);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", setD3_CHCR__FUi);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", setD4_CHCR__FUi);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", scTag2__FP5QWORDPvUiUi);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", viBufCreate__FP5ViBufP1P1iP9TimeStampi);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", viBufReset__FP5ViBuf);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", viBufBeginPut__FP5ViBufPPUcPiPPUcPi);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", viBufEndPut__FP5ViBufi);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", viBufAddDMA__FP5ViBuf);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", viBufStopDMA__FP5ViBuf);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", viBufRestartDMA__FP5ViBuf);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", viBufDelete__FP5ViBuf);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", viBufFlush__FP5ViBuf);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", viBufModifyPts__FP5ViBufP9TimeStamp);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", viBufPutTs__FP5ViBufP9TimeStamp);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", viBufGetTs__FP5ViBufP9TimeStamp);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", strFileOpen__FP7StrFilePc);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", strFileSeek__FP7StrFile);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", strFileClose__FP7StrFile);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", strFileRead__FP7StrFilePvi);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", readBufCreate__FP7ReadBuf);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", readBufBeginPut__FP7ReadBufPPUc);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", readBufEndPut__FP7ReadBufi);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", readBufBeginGet__FP7ReadBufPPUc);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", readBufEndGet__FP7ReadBufi);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", audioDecCreate__FP8AudioDecPUcii);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", audioDecDelete__FP8AudioDec);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", audioDecPause__FP8AudioDec);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", audioDecResume__FP8AudioDec);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", audioDecStart__FP8AudioDec);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", audioDecReset__FP8AudioDec);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", audioDecIsPreset__FP8AudioDec);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", audioDecSendToIOP__FP8AudioDec);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", iopGetArea__FPiPiPiPiP8AudioDeci);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", sendToIOP2area__FiiiiPUciPUci);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", sendToIOP__FiPUci);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", changeMasterVolume__FUi);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", changeInputVolume__FUi);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", startDisplay__Fi);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", switchThread__Fv);
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", videoDecSetState__FP8VideoDecUi);
s32 videoDecGetState(VideoDec * arg0) {
    return arg0->field_0xA8;
}
INCLUDE_ASM("nonmatchings/game/ceditmap_00299620", decBs0__FP8VideoDec);
