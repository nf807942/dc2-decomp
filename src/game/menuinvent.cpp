/* CMenuInvent — le menu d'invention : les idées, les photos, les cartes
 * d'invention et les objets qu'on en tire.
 */

#include "common.h"
#include "menuinvent.hpp"

INCLUDE_ASM("nonmatchings/game/menuinvent", InitPhotoNetaBoardToAlbum__11CMenuInventFi);
INCLUDE_ASM("nonmatchings/game/menuinvent", CheckRecoverPhotoNum__11CMenuInventFv);
INCLUDE_ASM("nonmatchings/game/menuinvent", AttachFormInfo__11CMenuInventFv);
INCLUDE_ASM("nonmatchings/game/menuinvent", LoadCharaCheck__11CMenuInventFv);
INCLUDE_ASM("nonmatchings/game/menuinvent", GetNowSelectedPictInfo__11CMenuInventFv);
INCLUDE_ASM("nonmatchings/game/menuinvent", GetPhotoInfoFromMode__11CMenuInventFPi);
INCLUDE_ASM("nonmatchings/game/menuinvent", InitNetaCircle__11CMenuInventFi);
INCLUDE_ASM("nonmatchings/game/menuinvent", SetNetaCircle__11CMenuInventFii);
INCLUDE_ASM("nonmatchings/game/menuinvent", CancelNetaCircle__11CMenuInventFi);
INCLUDE_ASM("nonmatchings/game/menuinvent", GetNowSelectNetaID__11CMenuInventFi);
INCLUDE_ASM("nonmatchings/game/menuinvent", SelectedNetaPhotoAlready__11CMenuInventFi);
INCLUDE_ASM("nonmatchings/game/menuinvent", SelectedNetaMemoListAlready__11CMenuInventFi);
INCLUDE_ASM("nonmatchings/game/menuinvent", UpdataRecordBoard__11CMenuInventFv);
INCLUDE_ASM("nonmatchings/game/menuinvent", PrepareNextMode__11CMenuInventFi);
INCLUDE_ASM("nonmatchings/game/menuinvent", SearchNowPosItemExist__11CMenuInventFv);
INCLUDE_ASM("nonmatchings/game/menuinvent", CreateModeSwapForm__11CMenuInventFi);
INCLUDE_ASM("nonmatchings/game/menuinvent", GradationSet__11CMenuInventFi);
INCLUDE_ASM("nonmatchings/game/menuinvent", GradationStep__11CMenuInventFv);
INCLUDE_ASM("nonmatchings/game/menuinvent", InitEnd__11CMenuInventFv);
/* Le nom du script de fin, en japonais dans le binaire : 本終了処理, « le
 * traitement de fin proprement dit ». Le littéral reste dans le désassemblage ;
 * seul son symbole est nommé ici. */
extern char _2720_0036E6E8[];

/* La fermeture du menu d'invention. Tout ce que le joueur y a laissé — onze
 * demi-mots, sans doute les positions de curseur des différents panneaux — est
 * reversé dans l'état de menu que la sauvegarde retient, de sorte que la
 * prochaine ouverture reparte d'où l'on s'était arrêté. La vérification des
 * photos est close, puis le script de fin est lancé.
 *
 * L'absence d'état de menu n'empêche rien : les deux dernières étapes ont lieu
 * de toute façon. */
void CMenuInvent::ExitEnd() {
    MENU_SYS_DATA *sys = GetMenuSysData();
    if (sys != NULL) {
        sys->unknown_20 = this->unknown_11C;
        sys->unknown_22 = this->unknown_120;
        sys->unknown_30 = this->unknown_114;
        sys->unknown_32 = this->unknown_118;
        sys->unknown_34 = this->unknown_124;
        sys->unknown_36 = this->unknown_128;
        sys->unknown_38 = this->unknown_12C;
        sys->unknown_3A = this->unknown_130;
        sys->unknown_3C = this->unknown_134;
        sys->unknown_3E = this->unknown_138;
        sys->unknown_2E = this->unknown_392;
    }
    InventUserDataPtr->PhotoCheckEnd();
    ExeScript(_2720_0036E6E8);
}
INCLUDE_ASM("nonmatchings/game/menuinvent", EnterDataMenu__11CMenuInventFPUc);
INCLUDE_ASM("nonmatchings/game/menuinvent", ItemCmdAfter__11CMenuInventFiP16ITEMCMD_RET_PARA);
