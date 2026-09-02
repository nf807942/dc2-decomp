/* CScene, CRain, CMap, SCN_LOADMAP_INFO2, CSceneMessage, CSceneCamera, CSceneSky, CSceneEffect, CSceneMap, CSceneCharacter, CSceneData, CSceneGameObj, mgCObjectStack_21CList_12EMAP_MESSAGE__
 *
 * Unité découpée par `make carve` : 94 fonctions, 15700 octets, de
 * 0x00285F50 à 0x00289E48. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"
#include "gen/CSceneData.hpp"
#include "gen/CRain.hpp"
#include "gen/mgCObjectStack_21CList_12EMAP_MESSAGE__.hpp"

INCLUDE_ASM("nonmatchings/game/cscene", SetCharNo__5CRainFi);
INCLUDE_ASM("nonmatchings/game/cscene", ParticleBirth__5CRainFPfi);
void CRain::Stop(void) {
    this->field_0x0 = 0;
}
INCLUDE_ASM("nonmatchings/game/cscene", Start__5CRainFv);
INCLUDE_ASM("nonmatchings/game/cscene", Step__5CRainFv);
INCLUDE_ASM("nonmatchings/game/cscene", Init__5CRainFv);
INCLUDE_ASM("nonmatchings/game/cscene", DrawScreenRain__Fv);
INCLUDE_ASM("nonmatchings/game/cscene", Draw__5CRainFv);
void CSceneData::Initialize(void) {
    this->field_0x0 = 0;
    this->field_0x8 = 0;
    this->field_0x30 = 0;
    this->field_0x28 = -1;
    this->field_0x2C = 0;
    this->field_0x4 = 0;
}
INCLUDE_ASM("nonmatchings/game/cscene", AssignData__15CSceneCharacterFP11CCharacter2Pc);
INCLUDE_ASM("nonmatchings/game/cscene", Initialize__15CSceneCharacterFv);
INCLUDE_ASM("nonmatchings/game/cscene", Initialize__9CSceneMapFv);
INCLUDE_ASM("nonmatchings/game/cscene", AssignData__9CSceneMapFP4CMapPc);
INCLUDE_ASM("nonmatchings/game/cscene", Initialize__13CSceneMessageFv);
INCLUDE_ASM("nonmatchings/game/cscene", AssignData__13CSceneMessageFP6ClsMesPc);
INCLUDE_ASM("nonmatchings/game/cscene", AssignData__12CSceneCameraFP9mgCCameraPc);
INCLUDE_ASM("nonmatchings/game/cscene", Initialize__12CSceneCameraFv);
INCLUDE_ASM("nonmatchings/game/cscene", AssignData__9CSceneSkyFP7CMapSkyPc);
INCLUDE_ASM("nonmatchings/game/cscene", Initialize__9CSceneSkyFv);
INCLUDE_ASM("nonmatchings/game/cscene", Initialize__13CSceneGameObjFv);
INCLUDE_ASM("nonmatchings/game/cscene", Initialize__12CSceneEffectFv);
INCLUDE_ASM("nonmatchings/game/cscene", AssignData__12CSceneEffectFP16CEffectScriptManPc);
INCLUDE_ASM("nonmatchings/game/cscene", InitAllData__6CSceneFv);
INCLUDE_ASM("nonmatchings/game/cscene", Initialize__6CSceneFv);
INCLUDE_ASM("nonmatchings/game/cscene", SetStack__6CSceneFiP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/cscene", GetStack__6CSceneFi);
INCLUDE_ASM("nonmatchings/game/cscene", ClearStack__6CSceneFi);
INCLUDE_ASM("nonmatchings/game/cscene", AssignStack__6CSceneFi);
INCLUDE_ASM("nonmatchings/game/cscene", GetSceneCharacter__6CSceneFi);
INCLUDE_ASM("nonmatchings/game/cscene", GetSceneMap__6CSceneFi);
INCLUDE_ASM("nonmatchings/game/cscene", GetSceneMessage__6CSceneFi);
INCLUDE_ASM("nonmatchings/game/cscene", GetSceneCamera__6CSceneFi);
INCLUDE_ASM("nonmatchings/game/cscene", GetSceneSky__6CSceneFi);
INCLUDE_ASM("nonmatchings/game/cscene", GetSceneGameObj__6CSceneFi);
INCLUDE_ASM("nonmatchings/game/cscene", GetSceneEffect__6CSceneFi);
INCLUDE_ASM("nonmatchings/game/cscene", CheckIMGName__6CSceneFiPc);
INCLUDE_ASM("nonmatchings/game/cscene", CheckMDSName__6CSceneFiPc);
INCLUDE_ASM("nonmatchings/game/cscene", GetData__6CSceneFii);
INCLUDE_ASM("nonmatchings/game/cscene", AssignCamera__6CSceneFiP9mgCCameraPc);
INCLUDE_ASM("nonmatchings/game/cscene", GetCameraID__6CSceneFPc);
INCLUDE_ASM("nonmatchings/game/cscene", GetCamera__6CSceneFi);
INCLUDE_ASM("nonmatchings/game/cscene", AssignMessage__6CSceneFiP6ClsMesPc);
INCLUDE_ASM("nonmatchings/game/cscene", GetMessage__6CSceneFi);
INCLUDE_ASM("nonmatchings/game/cscene", AssignChara__6CSceneFiP11CCharacter2Pc);
INCLUDE_ASM("nonmatchings/game/cscene", SetCharaNo__6CSceneFii);
INCLUDE_ASM("nonmatchings/game/cscene", GetCharaNo__6CSceneFi);
INCLUDE_ASM("nonmatchings/game/cscene", GetCharacter__6CSceneFi);
INCLUDE_ASM("nonmatchings/game/cscene", AssignMap__6CSceneFiP4CMapPc);
INCLUDE_ASM("nonmatchings/game/cscene", GetMapName__6CSceneFi);
INCLUDE_ASM("nonmatchings/game/cscene", GetMapID__6CSceneFPc);
INCLUDE_ASM("nonmatchings/game/cscene", GetMap__6CSceneFi);
INCLUDE_ASM("nonmatchings/game/cscene", GetSky__6CSceneFi);
INCLUDE_ASM("nonmatchings/game/cscene", GetMainMapNo__6CSceneFv);
INCLUDE_ASM("nonmatchings/game/cscene", InScreenFunc__6CSceneFP16InScreenFuncInfo);
INCLUDE_ASM("nonmatchings/game/cscene", DrawScreenFunc__6CSceneFP8mgCFrame);
INCLUDE_ASM("nonmatchings/game/cscene", AssignSky__6CSceneFiP7CMapSkyPc);
INCLUDE_ASM("nonmatchings/game/cscene", DeleteSky__6CSceneFi);
INCLUDE_ASM("nonmatchings/game/cscene", AssignEffect__6CSceneFiP16CEffectScriptManPc);
INCLUDE_ASM("nonmatchings/game/cscene", DeleteEffect__6CSceneFi);
INCLUDE_ASM("nonmatchings/game/cscene", GetEffect__6CSceneFi);
INCLUDE_ASM("nonmatchings/game/cscene", StepEffectScript__6CSceneFi);
INCLUDE_ASM("nonmatchings/game/cscene", DrawEffectScript__6CSceneFi);
INCLUDE_ASM("nonmatchings/game/cscene", IsActive__6CSceneFii);
INCLUDE_ASM("nonmatchings/game/cscene", SetActive__6CSceneFii);
INCLUDE_ASM("nonmatchings/game/cscene", ResetActive__6CSceneFii);
INCLUDE_ASM("nonmatchings/game/cscene", SetStatus__6CSceneFiii);
INCLUDE_ASM("nonmatchings/game/cscene", ResetStatus__6CSceneFiii);
INCLUDE_ASM("nonmatchings/game/cscene", GetStatus__6CSceneFii);
INCLUDE_ASM("nonmatchings/game/cscene", SetType__6CSceneFiii);
INCLUDE_ASM("nonmatchings/game/cscene", GetType__6CSceneFii);
INCLUDE_ASM("nonmatchings/game/cscene", GetActiveMap__6CSceneFPP4CMapi);
INCLUDE_ASM("nonmatchings/game/cscene", GetCharaTexb__6CSceneFi);
INCLUDE_ASM("nonmatchings/game/cscene", SetCharaTexb__6CSceneFii);
INCLUDE_ASM("nonmatchings/game/cscene", SetTime__6CSceneFf);
INCLUDE_ASM("nonmatchings/game/cscene", AddTime__6CSceneFf);
INCLUDE_ASM("nonmatchings/game/cscene", TimeStep__6CSceneFf);
INCLUDE_ASM("nonmatchings/game/cscene", SetWind__6CSceneFfPf);
INCLUDE_ASM("nonmatchings/game/cscene", ResetWind__6CSceneFv);
INCLUDE_ASM("nonmatchings/game/cscene", GetWind__6CSceneFPf);
INCLUDE_ASM("nonmatchings/game/cscene", SetNowMapNo__6CSceneFi);
INCLUDE_ASM("nonmatchings/game/cscene", SetNowSubMapNo__6CSceneFi);
INCLUDE_ASM("nonmatchings/game/cscene", LoadMapData__FR17SCN_LOADMAP_INFO2i);
INCLUDE_ASM("nonmatchings/game/cscene", Initialize__17SCN_LOADMAP_INFO2Fv);
INCLUDE_ASM("nonmatchings/game/cscene", LoadChara__6CSceneFiPUiPcP9mgCMemoryP9mgCMemoryP9mgCMemoryii);
INCLUDE_ASM("nonmatchings/game/cscene", DeleteChara__6CSceneFi);
INCLUDE_ASM("nonmatchings/game/cscene", CopyChara__6CSceneFiiP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/cscene", LoadMapFromMemory__6CSceneFiP17SCN_LOADMAP_INFO2);
INCLUDE_ASM("nonmatchings/game/cscene", LoadMapFromMemory__6CSceneFiiP17SCN_LOADMAP_INFO2);
void mgCObjectStack_21CList_12EMAP_MESSAGE__::Initialize(void) {
    this->field_0x8 = 0;
}
INCLUDE_ASM("nonmatchings/game/cscene", __ct__4CMapFv);
INCLUDE_ASM("nonmatchings/game/cscene", LoadMapBGStep__6CSceneFP17SCN_LOADMAP_INFO2);
INCLUDE_ASM("nonmatchings/game/cscene", LoadMap__6CSceneFiP17SCN_LOADMAP_INFO2i);
INCLUDE_ASM("nonmatchings/game/cscene", __as__17SCN_LOADMAP_INFO2FRC17SCN_LOADMAP_INFO2);
INCLUDE_ASM("nonmatchings/game/cscene", DeleteMap__6CSceneFii);
