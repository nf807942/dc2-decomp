/* CFuncPointMngr, CObjAnime, CEditMap, CFuncPoint, CList_10CFuncPoint_
 *
 * Unité découpée par `make carve` : 39 fonctions, 9504 octets, de
 * 0x0029F850 à 0x002A1E80. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"
#include "gen/CFuncPointMngr.hpp"
#include "gen/CList_10CFuncPoint_.hpp"

INCLUDE_ASM("nonmatchings/game/cfuncpointmngr", setImageTag__FPUiPviii);
INCLUDE_ASM("nonmatchings/game/cfuncpointmngr", videoDecBeginPut__FP8VideoDecPPUcPiPPUcPi);
INCLUDE_ASM("nonmatchings/game/cfuncpointmngr", videoDecPutTs__FP8VideoDecllPUci);
INCLUDE_ASM("nonmatchings/game/cfuncpointmngr", videoDecEndPut__FP8VideoDeci);
INCLUDE_ASM("nonmatchings/game/cfuncpointmngr", cpy2area__FPUciPUciPUciPUci);
INCLUDE_ASM("nonmatchings/game/cfuncpointmngr", audioDecBeginPut__FP8AudioDecPPUcPiPPUcPi);
INCLUDE_ASM("nonmatchings/game/cfuncpointmngr", audioDecEndPut__FP8AudioDeci);
INCLUDE_ASM("nonmatchings/game/cfuncpointmngr", isAudioOK__Fv);
INCLUDE_ASM("nonmatchings/game/cfuncpointmngr", DrawFireEffect__8CEditMapFi);
INCLUDE_ASM("nonmatchings/game/cfuncpointmngr", DrawFireRaster__8CEditMapFv);
INCLUDE_ASM("nonmatchings/game/cfuncpointmngr", DrawEffect__8CEditMapFv);
INCLUDE_ASM("nonmatchings/game/cfuncpointmngr", AnimeStep__8CEditMapFP12CObjAnimeEnv);
INCLUDE_ASM("nonmatchings/game/cfuncpointmngr", CheckTime__Ffff);
INCLUDE_ASM("nonmatchings/game/cfuncpointmngr", LimitTime__Ff);
INCLUDE_ASM("nonmatchings/game/cfuncpointmngr", SubTime__Fff);
INCLUDE_ASM("nonmatchings/game/cfuncpointmngr", Initialize__10CFuncPointFv);
INCLUDE_ASM("nonmatchings/game/cfuncpointmngr", Check__10CFuncPointFP15CFuncPointCheck);
INCLUDE_ASM("nonmatchings/game/cfuncpointmngr", CheckOver__FPfPfPf);
INCLUDE_ASM("nonmatchings/game/cfuncpointmngr", Step__9CObjAnimeFP12CObjAnimeEnv);
INCLUDE_ASM("nonmatchings/game/cfuncpointmngr", SetParam__9CObjAnimeFPf);
INCLUDE_ASM("nonmatchings/game/cfuncpointmngr", GetParam__9CObjAnimeFPf);
INCLUDE_ASM("nonmatchings/game/cfuncpointmngr", AssignFuncAnime__9CObjAnimeFP10CFuncPointP9CMapParts);
INCLUDE_ASM("nonmatchings/game/cfuncpointmngr", Add__14CFuncPointMngrFiP9mgCMemory);
void CList_10CFuncPoint_::Initialize(void) {
    this->field_0x4 = 0;
    this->field_0x0 = 0;
}
INCLUDE_ASM("nonmatchings/game/cfuncpointmngr", Add__14CFuncPointMngrFiP19CList_10CFuncPoint_);
INCLUDE_ASM("nonmatchings/game/cfuncpointmngr", Reserve__14CFuncPointMngrFiP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/cfuncpointmngr", __ct__19CList_10CFuncPoint_Fv);
INCLUDE_ASM("nonmatchings/game/cfuncpointmngr", GetReserve__14CFuncPointMngrFv);
INCLUDE_ASM("nonmatchings/game/cfuncpointmngr", AddFromReserve__14CFuncPointMngrFi);
INCLUDE_ASM("nonmatchings/game/cfuncpointmngr", GetNum__14CFuncPointMngrFi);
INCLUDE_ASM("nonmatchings/game/cfuncpointmngr", GetEventNum__14CFuncPointMngrFi);
INCLUDE_ASM("nonmatchings/game/cfuncpointmngr", EnableFuncNum__14CFuncPointMngrFi);
INCLUDE_ASM("nonmatchings/game/cfuncpointmngr", GetStart__14CFuncPointMngrFi);
INCLUDE_ASM("nonmatchings/game/cfuncpointmngr", Get__14CFuncPointMngrFv);
void CFuncPointMngr::GetEnd(void) {
    this->field_0x2C = 0;
}
INCLUDE_ASM("nonmatchings/game/cfuncpointmngr", Search__14CFuncPointMngrFPc);
INCLUDE_ASM("nonmatchings/game/cfuncpointmngr", GetLight__14CFuncPointMngrFPfP10CFuncPointiP15CFuncPointChecki);
INCLUDE_ASM("nonmatchings/game/cfuncpointmngr", Step__14CFuncPointMngrFiP15CFuncPointCheck);
INCLUDE_ASM("nonmatchings/game/cfuncpointmngr", UpdateFlag__14CFuncPointMngrFiP15CFuncPointCheck);
