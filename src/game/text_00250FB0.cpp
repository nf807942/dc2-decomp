/* La boucle d'entrée du menu des objets : elle installe le sous-menu demandé,
 * lui passe la main, et retourne au jeu quand il rend la main.
 *
 * Unité découpée par `make carve` : 1 fonctions, 1392 octets, de
 * 0x00250FB0 à 0x00251520. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"
#include "menu.hpp"

/* Le menu des objets. Les champs déclarés sont ceux que `MenuItemKey` atteint :
 * le sous-menu affiché, celui qui est demandé, le personnage actif, et les
 * trois panneaux qui montrent les personnages. */
class CMenuItemInfo : public CBaseMenuClass {
public:
    s32 KeyStep();
    void CalcTex();
    void CalcCursorPosition();
    void MenuModeMalloc(mgCMemory *memory);
    void EnterDataMenu(u32 *data);
    s32 GetActiveCharaNo();
    void ModelReadStart(int viewMode, int a, int b);
    void ModelReadEndCheck();

    s16 unknown_114;  /* 0x114 — le personnage retenu */
    u8 unknown_116[0x13A - 0x116];
    s8 unknown_13A;   /* 0x13A */
    u8 unknown_13B[0x176 - 0x13B];
    s16 unknown_176;  /* 0x176 — le sous-menu affiché */
    s16 unknown_178;  /* 0x178 — le sous-menu demandé */
    u8 unknown_17A[0x1A8 - 0x17A];
    CMenuPosDataForm *unknown_1A8[3];  /* 0x1A8 */
};

extern CMenuItemInfo *CMenuItemInfoPt;

/* Ce que le menu retient de son chargement, dans huit octets que `$gp`
 * adresse. */
struct MENU_LOAD_INFO {
    s8 unknown_0;
    s8 unknown_1;
    s8 unknown_2;
    s8 unknown_3;
    s8 unknown_4;
    s8 unknown_5;
    s8 unknown_6[2];
};

extern MENU_LOAD_INFO MenuLoadInfo;

/* Les allocateurs du menu des objets, chacun pour une sorte de contenu. */
extern mgCMemory MenuItemMemory;
extern mgCMemory MenuItemMemory2;
extern mgCMemory MenuItemMainMemory;
extern mgCMemory MenuItemBGDataMemory;
extern mgCMemory MenuMainTextureReadBuf;
extern mgCMemory MenuCharaLoadStack;
extern mgCMemory MenuActionCharaBuffer[7];

/* L'arme en cours de forge ; seul le demi-mot de tête est établi, et
 * `MenuItemKey` le remet à zéro en quittant. */
struct BUILD_UP_WEAPON_INFO {
    s16 unknown_00;
    u8 unknown_02[0x44 - 0x02];
};

extern BUILD_UP_WEAPON_INFO BuildUpWeaponInfo;

/* Les deux valeurs que le menu retient d'une ouverture à l'autre, avec le
 * témoin que MWCC leur attache : une statique locale à fonction reçoit un
 * témoin d'initialisation, et le compilateur nomme les trois en leur ajoutant
 * un numéro. Tant que le découpage des données n'est pas fait, l'unité ne peut
 * pas définir ses propres statiques ; elle les déclare donc, et écrit le
 * témoin que le compilateur aurait produit. */
extern s32 old_viewmode_8715;
extern s8 init_8716;
extern s32 old_chrid_8718;
extern s8 init_8719;

/* Les noms de fichier et de panneau que la fonction emploie. Les littéraux
 * restent dans le désassemblage ; seuls leurs symboles sont nommés ici. */
extern char _8819[];  /* itemmn0.pac */
extern char _8820[];  /* main_form_dmy1 */
extern char _8821[];  /* msg0 */
extern char _8822[];  /* msg5 */
extern char _8823[];  /* mb2.pac */
extern char _5281[];  /* poly_chr1 */

/* Le chargement d'un fichier de menu. Son second paramètre porte un type que le
 * mangling ne rend pas — `P1i` n'est pas une signature qu'une déclaration C++
 * reproduise —, donc l'appel vise le symbole par son nom. */
extern "C" void LoadFileMenu__FPcP1i(char *name, u8 *buffer, int flag);
#define LoadFileMenu LoadFileMenu__FPcP1i

void SetMenuFrameRate(int rate);
void MenuMonsterBoxInit(mgCMemory *memory, int *data, int arg);
void MenuAquaInit(mgCMemory *memory, int *data, int arg);
void NameRegistInit(mgCMemory *memory, int *data, int arg);
void MenuNPCQuestViewInit(mgCMemory *memory, int *data, int arg);
void MonsterBookInit(mgCMemory *memory, int *data, int arg);
s32 MenuAquaKey(void);
s32 MenuMonsterBoxKey(void);
s32 NameRegistKey(void);
s32 MenuNPCQuestViewKey(void);
s32 MonsterBookKey(void);
void MenuBaseTextureReEnter(void);
s16 *GetSystemMesBuffer(void);
s16 *GetMenuMainMessageBuffer(void);
void AttachMessageForm(void);
void MenuMainFrameModeSet(int a, int b);
s32 GetMenuLoopType(void);
void CheckEnableHaveItemNum(void);
void MenuMemoryAdjust(mgCMemory *a, mgCMemory *b, mgCMemory *c, int chara);
s32 ReadBGSync(void);
void ReadBG(void);

/* Le pas du menu des objets, appelé une fois par image.
 *
 * Le sous-menu demandé (0x178) et celui qui est affiché (0x176) valent -1 tant
 * qu'aucun n'est actif ; c'est ce -1 qui fait que le compilateur normalise les
 * deux aiguillages en ajoutant un avant d'indexer leur table.
 *
 * Trois états s'enchaînent. Aucun sous-menu affiché ni demandé : le pas
 * ordinaire, touches et animation. Un sous-menu demandé et rien d'affiché : son
 * installation, une fois le fondu terminé. Un sous-menu affiché : sa boucle de
 * touches, et son retour rend la main au menu principal, ce qui recharge
 * textures, messages et modèles. */
s32 MenuItemKey(void) {
    s32 ret;

    if (!init_8716) {
        old_viewmode_8715 = 0;
        init_8716 = 1;
    }
    if (!init_8719) {
        old_chrid_8718 = 0;
        init_8719 = 1;
    }

    switch (CMenuItemInfoPt->unknown_176) {
    case -1: {
        s32 faded;

        ret = 0;
        faded = CMenuItemInfoPt->FadeCheckMenu();
        switch (CMenuItemInfoPt->unknown_178) {
            case 0:
            case 1:
            case 2:
            case 3:
            case 4:
            case 5: {
                int i;

                if (!faded) {
                    break;
                }
                CMenuItemInfoPt->DeleteTexBlock();
                MenuItemMemory.unknown_24 = 0;
                MenuItemMemory.unknown_1C = 0;
                for (i = 0; i < 3; i++) {
                    CMenuItemInfoPt->unknown_1A8[i]->SetActionCharaPtr(NULL, -1,
                                                                       -1);
                }

                old_viewmode_8715 = CMenuItemInfoPt->unknown_110;
                old_chrid_8718 = CMenuItemInfoPt->unknown_114;
                if (CMenuItemInfoPt->unknown_178 == 1) {
                    MenuCommonInfo->SetWakuType(-1);
                    MenuMonsterBoxInit(&MenuItemMemory,
                                       (int *)&CMenuItemInfoPt->unknown_18, 0);
                }
                if (CMenuItemInfoPt->unknown_178 == 0) {
                    SetMenuFrameRate(2);
                    MenuAquaInit(&MenuItemMemory,
                                 (int *)&CMenuItemInfoPt->unknown_18, 0);
                }
                if (CMenuItemInfoPt->unknown_178 == 2) {
                    NameRegistInit(&MenuItemMemory,
                                   (int *)&CMenuItemInfoPt->unknown_18, 0);
                }
                if (CMenuItemInfoPt->unknown_178 == 3) {
                    MenuNPCQuestViewInit(&MenuItemMemory,
                                         (int *)&CMenuItemInfoPt->unknown_18, 0);
                }
                if (CMenuItemInfoPt->unknown_178 == 4) {
                    MenuNPCQuestViewInit(&MenuItemMemory,
                                         (int *)&CMenuItemInfoPt->unknown_18, 1);
                }
                if (CMenuItemInfoPt->unknown_178 == 5) {
                    MonsterBookInit(&MenuItemMemory,
                                    (int *)&CMenuItemInfoPt->unknown_18, 0);
                }
                CMenuItemInfoPt->unknown_176 = CMenuItemInfoPt->unknown_178;
                break;
            }
            case -1:
                if (faded) {
                    ret = CMenuItemInfoPt->KeyStep();
                } else {
                    MenuPosData->FormStep();
                    CMenuItemInfoPt->CalcTex();
                    CMenuItemInfoPt->CalcCursorPosition();
                }
                break;
            default:
                break;
        }
        return ret;
    }
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        ret = 0;
        if (CMenuItemInfoPt->unknown_176 == 0) {
            ret = MenuAquaKey();
        }
        if (CMenuItemInfoPt->unknown_176 == 1) {
            ret = MenuMonsterBoxKey();
        }
        if (CMenuItemInfoPt->unknown_176 == 2) {
            ret = NameRegistKey();
        }
        if (CMenuItemInfoPt->unknown_176 == 3 ||
            CMenuItemInfoPt->unknown_176 == 4) {
            ret = MenuNPCQuestViewKey();
        }
        if (CMenuItemInfoPt->unknown_176 == 5) {
            ret = MonsterBookKey();
        }
        if (ret == 1) {
            SetMenuFrameRate(1);
            MenuItemMemory.unknown_24 = 0;
            MenuItemMemory.unknown_1C = 0;
            MenuItemMemory2.unknown_24 = 0;
            MenuItemMemory2.unknown_1C = 0;
            CMenuItemInfoPt->MenuModeMalloc(&MenuItemMainMemory);
            {
                u8 *buffer = MenuItemBGDataMemory.unknown_20;
                LoadFileMenu(_8819, buffer, 1);
                CMenuItemInfoPt->EnterDataMenu((u32 *)buffer);
            }
            if (CMenuItemInfoPt->unknown_176 == 1) {
                MenuPosData->InitDrawList();
                MenuPosData->FormReLink(_8820, _5281);
                MenuPosData->FormReLink(_8821, _8822);
            }
            LoadFileMenu(_8823, MenuMainTextureReadBuf.unknown_20, 1);
            MenuBaseTextureReEnter();
            {
                s16 *system = GetSystemMesBuffer();
                MenuDCMsg[0]->SetMessData(system, GetMenuMainMessageBuffer());
            }
            MenuDCMsg[0]->unknown_2958 = 1;
            MenuMoveItemPtr->AttachForm();
            AttachMessageForm();
            MenuMainFrameModeSet(2, 0);
            MenuLoadInfo.unknown_0 = 0;
            MenuLoadInfo.unknown_2 = 0;
            MenuLoadInfo.unknown_5 = 0;
            MenuLoadInfo.unknown_4 = -1;
            MenuLoadInfo.unknown_1 = 0;
            if (!GetMenuLoopType()) {
                MenuLoadInfo.unknown_1 = 1;
            }
            {
                s32 chara = CMenuItemInfoPt->GetActiveCharaNo();
                MenuLoadInfo.unknown_3 = chara;
                if (MenuLoadInfo.unknown_3 == 0 || MenuLoadInfo.unknown_3 == 1) {
                    MenuLoadInfo.unknown_2 = 1;
                }
                CMenuItemInfoPt->unknown_110 = CMenuItemInfoPt->unknown_112;
                if (CMenuItemInfoPt->unknown_110 == 0) {
                    CMenuItemInfoPt->unknown_114 = 0;
                }
                if (CMenuItemInfoPt->unknown_110 == 1) {
                    CMenuItemInfoPt->unknown_114 = 1;
                }
                CheckEnableHaveItemNum();
                MenuMemoryAdjust(&MenuItemMemory, &MenuCharaLoadStack,
                                 MenuActionCharaBuffer, chara);
            }
            CMenuItemInfoPt->ModelReadStart(CMenuItemInfoPt->unknown_110, 1, 1);
            if (ReadBGSync()) {
                do {
                    ReadBG();
                    MenuPosData->FormStep();
                    CMenuItemInfoPt->CalcTex();
                } while (ReadBGSync());
            }
            CMenuItemInfoPt->ModelReadEndCheck();
            BuildUpWeaponInfo.unknown_00 = 0;
            CMenuItemInfoPt->unknown_00 = 0;
            CMenuItemInfoPt->unknown_178 = -1;
            CMenuItemInfoPt->unknown_176 = -1;
            CMenuItemInfoPt->FadeInMenu(0x28, 0.0f);
            CMenuItemInfoPt->unknown_13A = 1;
        }
        return 0;
    default:
        return 0;
    }
}
