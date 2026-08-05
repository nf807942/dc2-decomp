/* CGameDataUsed — un objet que le joueur porte : arme, poisson, pièce de
 * robot, boîte-cadeau. La jauge COMMON_GAGE et les aides libres qui la
 * précèdent appartiennent à la même unité.
 */

#include "common.h"
#include "gamedataused.hpp"

INCLUDE_ASM("nonmatchings/gamedataused", CheckFill__11COMMON_GAGEFv);
INCLUDE_ASM("nonmatchings/gamedataused", GetRate__11COMMON_GAGEFv);
INCLUDE_ASM("nonmatchings/gamedataused", SetFillRate__11COMMON_GAGEFf);
INCLUDE_ASM("nonmatchings/gamedataused", AddPoint__11COMMON_GAGEFf);
INCLUDE_ASM("nonmatchings/gamedataused", AddRate__11COMMON_GAGEFf);
INCLUDE_ASM("nonmatchings/gamedataused", GetCommonGageRate__FP11COMMON_GAGE);
INCLUDE_ASM("nonmatchings/gamedataused", CalcBreedFishParam__FP14BREEDFISH_USED);
INCLUDE_ASM("nonmatchings/gamedataused", SetFishingGamePreEquip__FP13CGameDataUsed);
INCLUDE_ASM("nonmatchings/gamedataused", ReEquipFishingGameWeapon__Fv);
INCLUDE_ASM("nonmatchings/gamedataused", CheckFishingWeapon__FP13CGameDataUsed);
INCLUDE_ASM("nonmatchings/gamedataused", GameDataSwap__FP13CGameDataUsedP13CGameDataUsedi);
INCLUDE_ASM("nonmatchings/gamedataused", CheckNowRoboUseCapacity__FP9ROBO_DATAPi);
INCLUDE_ASM("nonmatchings/gamedataused", __ct__13CGameDataUsedFv);
INCLUDE_ASM("nonmatchings/gamedataused", Init__13CGameDataUsedFv);
INCLUDE_ASM("nonmatchings/gamedataused", CheckTypeEnableStack__13CGameDataUsedFv);
INCLUDE_ASM("nonmatchings/gamedataused", GetDataPath__13CGameDataUsedFv);
INCLUDE_ASM("nonmatchings/gamedataused", IsWhoEquip__13CGameDataUsedFv);
INCLUDE_ASM("nonmatchings/gamedataused", GetLevel__13CGameDataUsedFv);
INCLUDE_ASM("nonmatchings/gamedataused", GetPalletColor__13CGameDataUsedFv);
INCLUDE_ASM("nonmatchings/gamedataused", GetSpectolNo__13CGameDataUsedFv);
INCLUDE_ASM("nonmatchings/gamedataused", CheckStackRemain__13CGameDataUsedFv);
INCLUDE_ASM("nonmatchings/gamedataused", GetNum__13CGameDataUsedFv);
INCLUDE_ASM("nonmatchings/gamedataused", GetActiveSetNum__13CGameDataUsedFv);
INCLUDE_ASM("nonmatchings/gamedataused", AddNum__13CGameDataUsedFii);
INCLUDE_ASM("nonmatchings/gamedataused", GetUseCapacity__13CGameDataUsedFv);
INCLUDE_ASM("nonmatchings/gamedataused", AddFishHp__13CGameDataUsedFi);
INCLUDE_ASM("nonmatchings/gamedataused", Boiled__13CGameDataUsedFv);
INCLUDE_ASM("nonmatchings/gamedataused", IsActiveSet__13CGameDataUsedFv);
INCLUDE_ASM("nonmatchings/gamedataused", SetName__13CGameDataUsedFPc);
INCLUDE_ASM("nonmatchings/gamedataused", GetName__13CGameDataUsedFi);
INCLUDE_ASM("nonmatchings/gamedataused", TransToPassword__13CGameDataUsedFPci);
INCLUDE_ASM("nonmatchings/gamedataused", TransToData__13CGameDataUsedFPci);
INCLUDE_ASM("nonmatchings/gamedataused", DeleteNum__13CGameDataUsedFi);
INCLUDE_ASM("nonmatchings/gamedataused", RemainFusion__13CGameDataUsedFv);
INCLUDE_ASM("nonmatchings/gamedataused", AddFusionPoint__13CGameDataUsedFi);
INCLUDE_ASM("nonmatchings/gamedataused", GetEffectReadType__13CGameDataUsedFPPcPPcPi);
INCLUDE_ASM("nonmatchings/gamedataused", GetMsgAddInfo__13CGameDataUsedFPPcPPcPi);
INCLUDE_ASM("nonmatchings/gamedataused", GetWHp__13CGameDataUsedFPi);
INCLUDE_ASM("nonmatchings/gamedataused", IsRepair__13CGameDataUsedFv);
INCLUDE_ASM("nonmatchings/gamedataused", Repair__13CGameDataUsedFi);
INCLUDE_ASM("nonmatchings/gamedataused", GetEnableRepairItemNo__13CGameDataUsedFv);
INCLUDE_ASM("nonmatchings/gamedataused", IsEnableUseRepair__13CGameDataUsedFi);
INCLUDE_ASM("nonmatchings/gamedataused", GetRoboInfoType__13CGameDataUsedFv);
INCLUDE_ASM("nonmatchings/gamedataused", GetRoboJointName__13CGameDataUsedFPc);
INCLUDE_ASM("nonmatchings/gamedataused", GetRoboSoundFileName__13CGameDataUsedFPc);
INCLUDE_ASM("nonmatchings/gamedataused", IsBroken__13CGameDataUsedFv);
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
INCLUDE_ASM("nonmatchings/gamedataused", LevelUp__13CGameDataUsedFv);
INCLUDE_ASM("nonmatchings/gamedataused", IsTrush__13CGameDataUsedFv);
INCLUDE_ASM("nonmatchings/gamedataused", IsSpectolTrans__13CGameDataUsedFv);
INCLUDE_ASM("nonmatchings/gamedataused", ToSpectolTrans__13CGameDataUsedFP13CGameDataUsedi);
INCLUDE_ASM("nonmatchings/gamedataused", GetStatusParam__13CGameDataUsedFPs);
INCLUDE_ASM("nonmatchings/gamedataused", GetStatusParam__13CGameDataUsedFPsf);
INCLUDE_ASM("nonmatchings/gamedataused", IsBuildUp__13CGameDataUsedFPiPiPi);
INCLUDE_ASM("nonmatchings/gamedataused", IsFishingRod__13CGameDataUsedFv);
INCLUDE_ASM("nonmatchings/gamedataused", GetActiveElem__13CGameDataUsedFv);
INCLUDE_ASM("nonmatchings/gamedataused", GetAttackType__13CGameDataUsedFv);
INCLUDE_ASM("nonmatchings/gamedataused", GetModelNo__13CGameDataUsedFv);
INCLUDE_ASM("nonmatchings/gamedataused", GetMainCharaModelName__FiPci);
INCLUDE_ASM("nonmatchings/gamedataused", CheckParamLimmit__13CGameDataUsedFv);
INCLUDE_ASM("nonmatchings/gamedataused", TimeCheck__13CGameDataUsedFi);
INCLUDE_ASM("nonmatchings/gamedataused", GetGiftBoxItemNum__13CGameDataUsedFv);
INCLUDE_ASM("nonmatchings/gamedataused", SetGiftBoxItem__13CGameDataUsedFii);
INCLUDE_ASM("nonmatchings/gamedataused", GetGiftBoxItemNo__13CGameDataUsedFi);
INCLUDE_ASM("nonmatchings/gamedataused", GetGiftBoxSameItemNum__13CGameDataUsedFi);
INCLUDE_ASM("nonmatchings/gamedataused", CopyGameData__13CGameDataUsedFP13CGameDataUsed);
INCLUDE_ASM("nonmatchings/gamedataused", CopyDataWeapon__13CGameDataUsedFi);
INCLUDE_ASM("nonmatchings/gamedataused", CopyDataAttach__13CGameDataUsedFi);
INCLUDE_ASM("nonmatchings/gamedataused", CopyDataItem__13CGameDataUsedFi);
INCLUDE_ASM("nonmatchings/gamedataused", CopyDataFish__13CGameDataUsedFi);
INCLUDE_ASM("nonmatchings/gamedataused", CopyDataGiftBox__13CGameDataUsedFi);
INCLUDE_ASM("nonmatchings/gamedataused", CopyDataItem__13CGameDataUsedFP13CGameDataUsed);
INCLUDE_ASM("nonmatchings/gamedataused", CopyDataRoboPart__13CGameDataUsedFi);
