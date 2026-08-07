/* CGameDataUsed — un objet que le joueur porte : arme, poisson, pièce de
 * robot, boîte-cadeau. La jauge COMMON_GAGE et les aides libres qui la
 * précèdent appartiennent à la même unité.
 */

#include "common.h"
#include "gamedataused.hpp"

INCLUDE_ASM("nonmatchings/game/gamedataused", CheckFill__11COMMON_GAGEFv);
INCLUDE_ASM("nonmatchings/game/gamedataused", GetRate__11COMMON_GAGEFv);
INCLUDE_ASM("nonmatchings/game/gamedataused", SetFillRate__11COMMON_GAGEFf);
INCLUDE_ASM("nonmatchings/game/gamedataused", AddPoint__11COMMON_GAGEFf);
INCLUDE_ASM("nonmatchings/game/gamedataused", AddRate__11COMMON_GAGEFf);
INCLUDE_ASM("nonmatchings/game/gamedataused", GetCommonGageRate__FP11COMMON_GAGE);
INCLUDE_ASM("nonmatchings/game/gamedataused", CalcBreedFishParam__FP14BREEDFISH_USED);
INCLUDE_ASM("nonmatchings/game/gamedataused", SetFishingGamePreEquip__FP13CGameDataUsed);
INCLUDE_ASM("nonmatchings/game/gamedataused", ReEquipFishingGameWeapon__Fv);
INCLUDE_ASM("nonmatchings/game/gamedataused", CheckFishingWeapon__FP13CGameDataUsed);
INCLUDE_ASM("nonmatchings/game/gamedataused", GameDataSwap__FP13CGameDataUsedP13CGameDataUsedi);
INCLUDE_ASM("nonmatchings/game/gamedataused", CheckNowRoboUseCapacity__FP9ROBO_DATAPi);
INCLUDE_ASM("nonmatchings/game/gamedataused", __ct__13CGameDataUsedFv);
INCLUDE_ASM("nonmatchings/game/gamedataused", Init__13CGameDataUsedFv);
INCLUDE_ASM("nonmatchings/game/gamedataused", CheckTypeEnableStack__13CGameDataUsedFv);
INCLUDE_ASM("nonmatchings/game/gamedataused", GetDataPath__13CGameDataUsedFv);
INCLUDE_ASM("nonmatchings/game/gamedataused", IsWhoEquip__13CGameDataUsedFv);
INCLUDE_ASM("nonmatchings/game/gamedataused", GetLevel__13CGameDataUsedFv);
INCLUDE_ASM("nonmatchings/game/gamedataused", GetPalletColor__13CGameDataUsedFv);
INCLUDE_ASM("nonmatchings/game/gamedataused", GetSpectolNo__13CGameDataUsedFv);
INCLUDE_ASM("nonmatchings/game/gamedataused", CheckStackRemain__13CGameDataUsedFv);
INCLUDE_ASM("nonmatchings/game/gamedataused", GetNum__13CGameDataUsedFv);
INCLUDE_ASM("nonmatchings/game/gamedataused", GetActiveSetNum__13CGameDataUsedFv);
INCLUDE_ASM("nonmatchings/game/gamedataused", AddNum__13CGameDataUsedFii);
INCLUDE_ASM("nonmatchings/game/gamedataused", GetUseCapacity__13CGameDataUsedFv);
INCLUDE_ASM("nonmatchings/game/gamedataused", AddFishHp__13CGameDataUsedFi);
INCLUDE_ASM("nonmatchings/game/gamedataused", Boiled__13CGameDataUsedFv);
INCLUDE_ASM("nonmatchings/game/gamedataused", IsActiveSet__13CGameDataUsedFv);
INCLUDE_ASM("nonmatchings/game/gamedataused", SetName__13CGameDataUsedFPc);
INCLUDE_ASM("nonmatchings/game/gamedataused", GetName__13CGameDataUsedFi);
INCLUDE_ASM("nonmatchings/game/gamedataused", TransToPassword__13CGameDataUsedFPci);
INCLUDE_ASM("nonmatchings/game/gamedataused", TransToData__13CGameDataUsedFPci);
INCLUDE_ASM("nonmatchings/game/gamedataused", DeleteNum__13CGameDataUsedFi);
INCLUDE_ASM("nonmatchings/game/gamedataused", RemainFusion__13CGameDataUsedFv);
INCLUDE_ASM("nonmatchings/game/gamedataused", AddFusionPoint__13CGameDataUsedFi);
INCLUDE_ASM("nonmatchings/game/gamedataused", GetEffectReadType__13CGameDataUsedFPPcPPcPi);
INCLUDE_ASM("nonmatchings/game/gamedataused", GetMsgAddInfo__13CGameDataUsedFPPcPPcPi);
INCLUDE_ASM("nonmatchings/game/gamedataused", GetWHp__13CGameDataUsedFPi);
INCLUDE_ASM("nonmatchings/game/gamedataused", IsRepair__13CGameDataUsedFv);
INCLUDE_ASM("nonmatchings/game/gamedataused", Repair__13CGameDataUsedFi);
INCLUDE_ASM("nonmatchings/game/gamedataused", GetEnableRepairItemNo__13CGameDataUsedFv);
INCLUDE_ASM("nonmatchings/game/gamedataused", IsEnableUseRepair__13CGameDataUsedFi);
INCLUDE_ASM("nonmatchings/game/gamedataused", GetRoboInfoType__13CGameDataUsedFv);
INCLUDE_ASM("nonmatchings/game/gamedataused", GetRoboJointName__13CGameDataUsedFPc);
INCLUDE_ASM("nonmatchings/game/gamedataused", GetRoboSoundFileName__13CGameDataUsedFPc);
INCLUDE_ASM("nonmatchings/game/gamedataused", IsBroken__13CGameDataUsedFv);
/* L'objet est-il prêt à monter d'un niveau ? Seul le genre 3 en porte un, et il
 * plafonne à 99. La montée tient quand l'expérience acquise, arrondie comme
 * l'affichage la montre, atteint ce que la jauge réclame — c'est `CheckFill` à
 * la tolérance de l'affichage près. */
int CGameDataUsed::IsLevelUp() {
    /* Le genre se teste par un aiguillage à un seul cas, non par un `if` : la
     * différence est dans le graphe de contrôle. Un `if` fond le retour du
     * mauvais genre avec celui du niveau plafonné — MWCC hisse alors la mise à
     * zéro dans le créneau de délai et saute par-dessus le bloc nul. Le `break`
     * de l'aiguillage les garde distincts, et c'est ce que le commerce porte.
     * Mesuré sur cinquante-six formes ; seule celle-ci apparie. */
    switch (this->kind) {
    case 3:
        if (this->level < 99) {
            if (this->experience.max <= (float)GetDispVolumeForFloat(this->experience.point)) {
                return 1;
            }
        }
        break;
    }
    return 0;
}
INCLUDE_ASM("nonmatchings/game/gamedataused", LevelUp__13CGameDataUsedFv);
INCLUDE_ASM("nonmatchings/game/gamedataused", IsTrush__13CGameDataUsedFv);
INCLUDE_ASM("nonmatchings/game/gamedataused", IsSpectolTrans__13CGameDataUsedFv);
INCLUDE_ASM("nonmatchings/game/gamedataused", ToSpectolTrans__13CGameDataUsedFP13CGameDataUsedi);
INCLUDE_ASM("nonmatchings/game/gamedataused", GetStatusParam__13CGameDataUsedFPs);
INCLUDE_ASM("nonmatchings/game/gamedataused", GetStatusParam__13CGameDataUsedFPsf);
INCLUDE_ASM("nonmatchings/game/gamedataused", IsBuildUp__13CGameDataUsedFPiPiPi);
INCLUDE_ASM("nonmatchings/game/gamedataused", IsFishingRod__13CGameDataUsedFv);
INCLUDE_ASM("nonmatchings/game/gamedataused", GetActiveElem__13CGameDataUsedFv);
INCLUDE_ASM("nonmatchings/game/gamedataused", GetAttackType__13CGameDataUsedFv);
INCLUDE_ASM("nonmatchings/game/gamedataused", GetModelNo__13CGameDataUsedFv);
INCLUDE_ASM("nonmatchings/game/gamedataused", GetMainCharaModelName__FiPci);
INCLUDE_ASM("nonmatchings/game/gamedataused", CheckParamLimmit__13CGameDataUsedFv);
INCLUDE_ASM("nonmatchings/game/gamedataused", TimeCheck__13CGameDataUsedFi);
INCLUDE_ASM("nonmatchings/game/gamedataused", GetGiftBoxItemNum__13CGameDataUsedFv);
INCLUDE_ASM("nonmatchings/game/gamedataused", SetGiftBoxItem__13CGameDataUsedFii);
INCLUDE_ASM("nonmatchings/game/gamedataused", GetGiftBoxItemNo__13CGameDataUsedFi);
INCLUDE_ASM("nonmatchings/game/gamedataused", GetGiftBoxSameItemNum__13CGameDataUsedFi);
INCLUDE_ASM("nonmatchings/game/gamedataused", CopyGameData__13CGameDataUsedFP13CGameDataUsed);
INCLUDE_ASM("nonmatchings/game/gamedataused", CopyDataWeapon__13CGameDataUsedFi);
INCLUDE_ASM("nonmatchings/game/gamedataused", CopyDataAttach__13CGameDataUsedFi);
INCLUDE_ASM("nonmatchings/game/gamedataused", CopyDataItem__13CGameDataUsedFi);
INCLUDE_ASM("nonmatchings/game/gamedataused", CopyDataFish__13CGameDataUsedFi);
INCLUDE_ASM("nonmatchings/game/gamedataused", CopyDataGiftBox__13CGameDataUsedFi);
INCLUDE_ASM("nonmatchings/game/gamedataused", CopyDataItem__13CGameDataUsedFP13CGameDataUsed);
INCLUDE_ASM("nonmatchings/game/gamedataused", CopyDataRoboPart__13CGameDataUsedFi);
