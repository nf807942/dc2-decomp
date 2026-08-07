/* CActionChara, CCharacter2
 *
 * Unité découpée par `make carve` : 52 fonctions, 24508 octets, de
 * 0x0016FE00 à 0x00175F10. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

INCLUDE_ASM("nonmatchings/game/cactionchara_0016FE00", RoboBikeMoveIF__12CActionCharaFi);
INCLUDE_ASM("nonmatchings/game/cactionchara_0016FE00", RoboAirMoveIF__12CActionCharaFii);
INCLUDE_ASM("nonmatchings/game/cactionchara_0016FE00", MonsterMoveIF__12CActionCharaFv);
INCLUDE_ASM("nonmatchings/game/cactionchara_0016FE00", GuardEffectSet__FP6CScenePf);
INCLUDE_ASM("nonmatchings/game/cactionchara_0016FE00", HitEffectSet__FP6CScenePf);
INCLUDE_ASM("nonmatchings/game/cactionchara_0016FE00", CheckAmuletAvoid__Fi);
INCLUDE_ASM("nonmatchings/game/cactionchara_0016FE00", CheckEquipSetItem__Fi);
INCLUDE_ASM("nonmatchings/game/cactionchara_0016FE00", CheckDamage__12CActionCharaFv);
INCLUDE_ASM("nonmatchings/game/cactionchara_0016FE00", LoadActionFile__12CActionCharaFPciP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/cactionchara_0016FE00", InitScript__12CActionCharaFv);
INCLUDE_ASM("nonmatchings/game/cactionchara_0016FE00", SetHold__12CActionCharaFv);
INCLUDE_ASM("nonmatchings/game/cactionchara_0016FE00", RunScript__12CActionCharaFP6CSceneP14RUN_SCRIPT_ENV);
INCLUDE_ASM("nonmatchings/game/cactionchara_0016FE00", CheckReleaseTimming__12CActionCharaFi);
INCLUDE_ASM("nonmatchings/game/cactionchara_0016FE00", StepParam__12CActionCharaFv);
INCLUDE_ASM("nonmatchings/game/cactionchara_0016FE00", Step__12CActionCharaFv);
INCLUDE_ASM("nonmatchings/game/cactionchara_0016FE00", ShadowStep__12CActionCharaFv);
INCLUDE_ASM("nonmatchings/game/cactionchara_0016FE00", Initialize__12CActionCharaFP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/cactionchara_0016FE00", Copy__12CActionCharaFR12CActionCharaP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/cactionchara_0016FE00", __as__11CCharacter2FRC11CCharacter2);
INCLUDE_ASM("nonmatchings/game/cactionchara_0016FE00", SetPosition__11CCharacter2FPf);
INCLUDE_ASM("nonmatchings/game/cactionchara_0016FE00", AddOutLine__11CCharacter2FPcP12COutLineDraw);
INCLUDE_ASM("nonmatchings/game/cactionchara_0016FE00", CopyOutLine__11CCharacter2FP11CCharacter2);
INCLUDE_ASM("nonmatchings/game/cactionchara_0016FE00", Draw__11CCharacter2Fv);
INCLUDE_ASM("nonmatchings/game/cactionchara_0016FE00", SetDeformMesh__11CCharacter2Fv);
INCLUDE_ASM("nonmatchings/game/cactionchara_0016FE00", DrawStep__11CCharacter2Fv);
INCLUDE_ASM("nonmatchings/game/cactionchara_0016FE00", GetCameraDist__11CCharacter2Fv);
INCLUDE_ASM("nonmatchings/game/cactionchara_0016FE00", DrawDirect__11CCharacter2Fv);
INCLUDE_ASM("nonmatchings/game/cactionchara_0016FE00", DrawShadowDirect__11CCharacter2Fv);
INCLUDE_ASM("nonmatchings/game/cactionchara_0016FE00", UpdatePosition__11CCharacter2Fv);
INCLUDE_ASM("nonmatchings/game/cactionchara_0016FE00", ResetDAPosition__11CCharacter2Fv);
INCLUDE_ASM("nonmatchings/game/cactionchara_0016FE00", GetDefaultStep__11CCharacter2Fv);
INCLUDE_ASM("nonmatchings/game/cactionchara_0016FE00", SetStep__11CCharacter2Ff);
INCLUDE_ASM("nonmatchings/game/cactionchara_0016FE00", ResetMotion__11CCharacter2Fv);
INCLUDE_ASM("nonmatchings/game/cactionchara_0016FE00", GetChgStepWait__11CCharacter2Fv);
INCLUDE_ASM("nonmatchings/game/cactionchara_0016FE00", CheckMotionEnd__11CCharacter2Fv);
INCLUDE_ASM("nonmatchings/game/cactionchara_0016FE00", SetMotion__11CCharacter2Fii);
INCLUDE_ASM("nonmatchings/game/cactionchara_0016FE00", SetMotion__11CCharacter2FPci);
INCLUDE_ASM("nonmatchings/game/cactionchara_0016FE00", SetNowFrameWeight__11CCharacter2Ff);
INCLUDE_ASM("nonmatchings/game/cactionchara_0016FE00", SetMotionPara__11CCharacter2FPcii);
INCLUDE_ASM("nonmatchings/game/cactionchara_0016FE00", SetDAnimeEnable__11CCharacter2Fi);
INCLUDE_ASM("nonmatchings/game/cactionchara_0016FE00", GetSoundInfoCopy__11CCharacter2FP9mgCMemory);
INCLUDE_ASM("nonmatchings/game/cactionchara_0016FE00", CheckFootEffect__11CCharacter2Fv);
INCLUDE_ASM("nonmatchings/game/cactionchara_0016FE00", SePlay__11CCharacter2Fv);
INCLUDE_ASM("nonmatchings/game/cactionchara_0016FE00", Step__11CCharacter2Fv);
INCLUDE_ASM("nonmatchings/game/cactionchara_0016FE00", StepDA__11CCharacter2Fi);
INCLUDE_ASM("nonmatchings/game/cactionchara_0016FE00", SetWind__11CCharacter2FfPf);
INCLUDE_ASM("nonmatchings/game/cactionchara_0016FE00", ResetWind__11CCharacter2Fv);
INCLUDE_ASM("nonmatchings/game/cactionchara_0016FE00", SetFloor__11CCharacter2Ff);
INCLUDE_ASM("nonmatchings/game/cactionchara_0016FE00", ResetFloor__11CCharacter2Fv);
INCLUDE_ASM("nonmatchings/game/cactionchara_0016FE00", NormalDrive__11CCharacter2Fv);
INCLUDE_ASM("nonmatchings/game/cactionchara_0016FE00", ShadowStep__11CCharacter2Fv);
INCLUDE_ASM("nonmatchings/game/cactionchara_0016FE00", GetKeyListIndexPtr__11CCharacter2FiPi);
