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
extern "C" u8 _2543_0036E690[10];
extern "C" u8 _2544_0036E6A0[10];
extern "C" s32 ExeScript__14CBaseMenuClassFPc(...);
extern "C" void CreateModeSwapForm__11CMenuInventFi(CMenuInvent *objet, s32 arg0) {
    if (arg0 == 0) {
        ExeScript__14CBaseMenuClassFPc((CBaseMenuClass *) objet, &_2543_0036E690);
        return;
    }
    ExeScript__14CBaseMenuClassFPc((CBaseMenuClass *) objet, &_2544_0036E6A0);
}
INCLUDE_ASM("nonmatchings/game/menuinvent", GradationSet__11CMenuInventFi);
INCLUDE_ASM("nonmatchings/game/menuinvent", GradationStep__11CMenuInventFv);
extern "C" s32 GetUserDataMan__Fv(void);
extern "C" u32 InventSubDataReadBGInfo;
extern "C" u8 MenuItemBrdCalcManner;
extern "C" u8 _2253_0036E5A8[12];
extern "C" u8 _2712[21];
extern "C" u8 _2713_0036E6D8[9];
struct inferred;
typedef struct CMenuInvent_infere {
    /* 0x000 */ char pad0[0x14];
    /* 0x014 */ s16 unk14;                          /* inferred */
    /* 0x016 */ char pad16[0xFA];                   /* maybe part of unk14[0x7E]void */
    /* 0x110 */ s16 unk110;                         /* inferred */
    /* 0x112 */ char pad112[0x146];                 /* maybe part of unk110[0xA4]void */
    /* 0x258 */ s8 unk258;                          /* inferred */
    /* 0x259 */ char pad259[0xC5D];                 /* maybe part of unk258[0xC5E]void */
    /* 0xEB6 */ s8 unkEB6;                          /* inferred */
} CMenuInvent_infere;                                      /* size >= 0xEB7 */
struct temp_s0_champs {
    char pad0[0x110];
    /* 0x110 */ s32 unk110;
};
extern "C" s32 ExeScript__14CBaseMenuClassFPc(...);
extern "C" s32 GetNumSameItem__16CUserDataManagerFi(...);
extern "C" s32 EnterDataMenu__11CMenuInventFPUc(...);
extern "C" s32 PrepareNextMode__11CMenuInventFi(void *, s32);
extern "C" void InitEnd__11CMenuInventFv(CMenuInvent_infere *objet) {
    struct temp_s0_champs *temp_s0;

    temp_s0 = (struct temp_s0_champs *) (InventSubDataReadBGInfo);
    objet->unk258 = 1;
    if (GetNumSameItem__16CUserDataManagerFi(GetUserDataMan__Fv(), 0x165) <= 0) {
        objet->unk258 = 0;
    }
    if (objet->unk110 == 1) {
        EnterDataMenu__11CMenuInventFPUc(objet, temp_s0->unk110);
        ExeScript__14CBaseMenuClassFPc((CBaseMenuClass *) objet, &_2253_0036E5A8);
        ExeScript__14CBaseMenuClassFPc((CBaseMenuClass *) objet, &_2712);
        PrepareNextMode__11CMenuInventFi(objet, (s32) objet->unk14);
    }
    objet->unkEB6 = 1;
    ExeScript__14CBaseMenuClassFPc((CBaseMenuClass *) objet, &_2713_0036E6D8);
    MenuItemBrdCalcManner = 0;
}
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
