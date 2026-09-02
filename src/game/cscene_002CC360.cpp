/* CScene, CPot, CBPot, CFragment, CVillagerMngr, CVillagerPlaceInfo, CVillagerData, CVil
 *
 * Unité découpée par `make carve` : 84 fonctions, 22980 octets, de
 * 0x002CC360 à 0x002D1F20. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

INCLUDE_ASM("nonmatchings/game/cscene_002CC360", UpDateMapInfo__6CSceneFv);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", GetColPoly__6CSceneFP6CCPolyR9mgVu0FBOXi);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", GetCameraPoly__6CSceneFP6CCPolyR9mgVu0FBOXi);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", RunEvent__6CSceneFiP15CSceneEventData);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", GetMapEvent__6CSceneFPfiP15CSceneEventData);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", GetFixCameraPos__6CSceneFPfPf);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", FixCameraPartsOnOff__6CSceneFPf);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", EyeViewDrawOnOff__6CSceneFi);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", GetSunPosition__6CSceneFPf);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", GetMoonPosition__6CSceneFPf);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", DrawSky__6CSceneFi);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", DrawLensFlare__6CSceneFiPcPc);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", EffectStep__6CSceneFv);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", DrawEffect__6CSceneFi);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", GetChrFileSize__FPUii);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", CheckDrawChara__6CSceneFi);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", CheckDrawCharaShadow__6CSceneFi);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", StepChara__6CSceneFi);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", GetCharaLighting__6CSceneFPA4_fPf);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", DrawChara__6CSceneFii);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", DrawCharaShadow__6CSceneFi);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", DrawExclamationMark__6CSceneFP8mgCFrame);
#include "sphida.hpp"
extern "C" s32 GetCharaTexb__6CSceneFi(CScene *objet, s32 arg0);
extern "C" s32 SearchCharaTexb__6CSceneFi(CScene *objet, s32 arg0) {
    s32 texb;
    s32 autre;
    s32 i;
    s32 j;

    texb = GetCharaTexb__6CSceneFi(objet, arg0);
    i = 0;
    if (texb < 0) {
        return -1;
    }
    do {
        j = i + 8;
        if (j != arg0) {
            autre = GetCharaTexb__6CSceneFi(objet, j);
            if ((autre >= 0) && (autre == texb)) {
                return j;
            }
        }
        i += 1;
    } while (i < 0x18);
    return -1;
}
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", PreLoadVillager__6CSceneFiP1);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", PreLoadVillagerEnd__6CSceneFv);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", DeleteVillager__6CSceneFi);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", DeleteSubVillager__6CSceneFv);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", DeleteVillager__6CSceneFv);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", SearchCharaID__6CSceneFi);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", GetNowVillagerTime__6CSceneFv);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", GetLoadVillagerList__6CSceneFiPiPP18CVillagerPlaceInfo);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", SearchCopyModel__6CSceneFi);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", GetObjectNameList__FPcP11CCharacter2PP8mgCFramei);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", CharaObjectOnOff__6CSceneFiP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", LoadVillager__6CSceneFii);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", LoadSubVillager__6CSceneFii);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", RegisterVillager__6CSceneFiii);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", RegisterVillager__6CSceneFiiP18CVillagerPlaceInfo);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", RegisterVillager__6CSceneFiiP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", GetTalkEvent__6CSceneFPfP15CSceneEventData);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", GetMotionName__Fi);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", GetMotionID__FPc);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", SetCharaMotion__FP11CCharacter2ii);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", StepVillager__6CSceneFv);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", StayNearVillager__6CSceneFPfPi);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", CancelStayVillager__6CSceneFPi);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", StayVillager__6CSceneFi);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", CancelStayVillager__6CSceneFi);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", ExModeVillager__6CSceneFi);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", SetActiveVillager__6CSceneFv);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", InScreenChara__6CSceneFPQ26CScene17InScreenCharaInfoPf);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", LoadGameObject__6CSceneFiiP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", GetGameObjectEvent__6CSceneFPfP15CSceneEventData);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", DrawGameObject__6CSceneFi);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", CalcReflectionVector__FPfPfPf);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", Draw__9CFragmentFPff);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", Step__9CFragmentFP6CCPolyi);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", Set__9CFragmentFPfPf);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", Init__9CFragmentFv);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", Clash__5CBPotFPfPfPf);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", Step__5CBPotFv);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", SetObject2__5CBPotFiP9CMapParts);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", Init__5CBPotFv);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", HoldStep__4CPotFv);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", FlyStep__4CPotFv);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", Clear__4CPotFv);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", Bakuhatsu__4CPotFPfPf);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", Step__4CPotFv);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", Throw__4CPotFv);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", Hold__4CPotFP9CMapParts);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", Init__4CPotFi);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", Init__Q214CVillagerPlace12ProgressInfoFv);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", Initialize__13CVillagerDataFv);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", Add__18CVillagerPlaceInfoFP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", Initialize__13CVillagerMngrFv);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", GetData__13CVillagerMngrFi);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", Stay__13CVillagerMngrFi);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", CancelStay__13CVillagerMngrFi);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", ExMode__13CVillagerMngrFi);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", SearchDataIDatCharaID__13CVillagerMngrFi);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", Register__13CVillagerMngrFiiP18CVillagerPlaceInfo);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", DeleteCharaID__13CVillagerMngrFi);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", NewData__13CVillagerMngrFv);
INCLUDE_ASM("nonmatchings/game/cscene_002CC360", CheckStay__13CVillagerMngrFi);
