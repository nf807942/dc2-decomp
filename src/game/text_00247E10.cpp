/* Le menu de mise au point des objets : la touche que chacun de ses modes
 * consulte. Une seule fonction, mais l'aiguillage la partage en sept écrans —
 * l'objet tiré au clavier, la jauge d'un personnage, la fusion, les attributs
 * d'une arme, le robot, et la canne à pêche.
 *
 * Unité découpée par `make carve` : 1 fonctions, 5836 octets, de
 * 0x00247E10 à 0x002494E0.
 */

#include "common.h"
#include "menu.hpp"
#include "gamepad.hpp"
#include "gamedataused.hpp"

/* Ce que `GetGameDataPt` rend : seul le nombre d'objets connus est atteint. */
struct GAME_DATA_PT {
    u8 unknown_00[0x20];
    u16 unknown_20;  /* 0x20 — le plus grand identifiant d'objet */
};

/* Les caractéristiques d'une arme, telles que la table les donne. Les paires
 * lues vont deux à deux : la première moitié est le maximum, la seconde la
 * valeur de départ. */
struct WEAPON_INFO {
    u8 unknown_00[0x4];
    s16 unknown_04;  /* 0x04 */
    s16 unknown_06;  /* 0x06 */
    s16 unknown_08;  /* 0x08 */
    s16 unknown_0A;  /* 0x0A */
    s16 unknown_0C;  /* 0x0C */
    s16 unknown_0E;  /* 0x0E */
    s16 unknown_10;  /* 0x10 */
    s16 unknown_12;  /* 0x12 */
    s16 unknown_14;  /* 0x14 */
    s16 unknown_16;  /* 0x16 */
    s16 unknown_18;  /* 0x18 */
    s16 unknown_1A;  /* 0x1A */
    s16 unknown_1C;  /* 0x1C */
    s16 unknown_1E;  /* 0x1E */
    s16 unknown_20;  /* 0x20 */
    s16 unknown_22;  /* 0x22 */
    s16 unknown_24;  /* 0x24 */
    s16 unknown_26;  /* 0x26 */
    s16 unknown_28;  /* 0x28 */
    s16 unknown_2A;  /* 0x2A */
};

/* Les caractéristiques que l'écran des armes modifie. La ligne retenue décale
 * la structure de deux octets, si bien que le champ atteint suit le rang. */
struct WEAPON_STATUS {
    u8 unknown_00[0x20];
    s16 unknown_20;  /* 0x20 */
    s16 unknown_22;  /* 0x22 */
    s16 unknown_24;  /* 0x24 */
    s16 unknown_26;  /* 0x26 */
};

/* La jauge d'un personnage, telle que les six entrées de `MenuUserParam` la
 * désignent. `ROBO_DATA` est le nom que le binaire donne à la classe, celle du
 * robot en étant la troisième. */
struct ROBO_DATA {
    void AddPoint(f32 value);

    f32 max;          /* 0x00 */
    f32 point;        /* 0x04 */
    u8 unknown_08[2];
    u16 unknown_0A;   /* 0x0A */
    u8 unknown_0C[0x1C - 0x0C];
    s8 unknown_1C;    /* 0x1C */
};

/* Le gestionnaire des données du joueur. */
class CUserDataManager {
public:
    s32 AddMoney(s32 amount);
    void AddRoboAbs(f32 value);
    void AddWhp(s32 kind, s32 a, s32 b);
    void GetItemNotOver(s32 item, s32 count);
    void SetCharaStatusAttirbuteVol(s32 chara, u32 attribute, s32 value);
};

/* Les données du jeu chargées depuis le disque. */
class CGameData {
public:
    void LoadData();
    void LoadItemSystemMes(s32 language);

    /* La taille que le binaire lui donne. C'est elle qui décide de
     * l'adressage : au-delà du seuil des petites données, MWCC passe par
     * `%hi`/`%lo` et non par `$gp`. */
    u8 unknown_00[0x30];
};

/* Le cadre d'un modèle, dont l'échelle s'ajuste. */
class mgCFrame;

/* Le gestionnaire des textures du middleware. */
class mgCTextureManager {
public:
    void DeleteBlock(s32 block);

    /* Sa taille le met hors du seuil des petites données. */
    u8 unknown_000[0x21C];
};

/* La caméra du middleware, et celle qui suit une cible. La seconde dérive de la
 * première : le menu range l'objet construit dans un pointeur de caméra. */
class mgCCameraBase {
public:
    u8 unknown_00[0x60];
};

class mgCCamera : public mgCCameraBase {
public:
    /* La première virtuelle déclarée occupe 0x08 de la table, les deux
     * premières entrées étant réservées. */
    virtual void vf08(s32 flag);

    void SetRef(f32 x, f32 y, f32 z);
    void SetPos(f32 x, f32 y, f32 z);
};

class mgCCameraFollow : public mgCCamera {
public:
    f32 GetAngle();

    u8 unknown_64[0xC0 - 0x68];
};

/* Le personnage animé que le menu affiche pour montrer un objet. Sa classe
 * n'est pas reconstruite : ses méthodes se prennent dans la table virtuelle, à
 * l'emplacement que le binaire leur donne. */
class CDebugModel {
public:
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void SetPos(f32 x, f32 y, f32 z);  /* 0x14 */
    virtual void vf18();
    virtual void SetRotate(f32 *rotation);  /* 0x1C */
    virtual void SetPosition(f32 x, f32 y, f32 z);  /* 0x20 */
    virtual void GetRotate(f32 *rotation);  /* 0x24 */
    virtual void vf28();
    virtual void SetScale(f32 x, f32 y, f32 z);  /* 0x2C */
    virtual void SetRotateAlso(f32 *rotation);  /* 0x30 */
    virtual void vf34();
    virtual void vf38();
    virtual void Initialize();  /* 0x3C */
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5C();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6C();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void LoadModel(void *data, char *name, mgCMemory *a, mgCMemory *b, mgCMemory *c, s32 texBlock, s32 flag);  /* 0x7C */
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8C();
    virtual void vf90();
    virtual void vf94();
    virtual void vf98();
    virtual void vf9C();
    virtual void vfA0();
    virtual void vfA4();
    virtual void vfA8();
    virtual void vfAC();
    virtual void vfB0();
    virtual void vfB4();
    virtual void vfB8();
    virtual void vfBC();
    virtual void vfC0();
    virtual void vfC4();
    virtual void vfC8();
    virtual void vfCC();
    virtual void vfD0();
    virtual void ResetPose();  /* 0xD4 */
    virtual void vfD8();
    virtual void vfDC();
    virtual void vfE0();
    virtual void vfE4();
    virtual void vfE8();
    virtual void vfEC();
    virtual void vfF0();
    virtual void vfF4();
    virtual void vfF8();
    virtual void vfFC();
    virtual void vf100();
    virtual void vf104();
    virtual void vf108();
    virtual void vf10C();
    virtual void vf110();
    virtual void vf114();
    virtual void SetVisible(s32 visible);  /* 0x118 */

    /* La table virtuelle occupe 0x00 : les champs propres commencent après. */
    u8 unknown_004[0x70 - 0x04];
    mgCFrame *unknown_070;  /* 0x70 — le cadre dont l'échelle s'ajuste */
    u8 unknown_074[0x35C - 0x74];
    s32 unknown_35C;  /* 0x35C */
    s32 unknown_360;  /* 0x360 */
    s32 unknown_364;  /* 0x364 */
    u8 unknown_368[0x6BC - 0x368];
    u8 unknown_6BC[0x910 - 0x6BC];  /* le script que porte le personnage */
    u8 unknown_910[0x1030 - 0x910];
};

/* Le menu des objets. Les champs déclarés sont ceux que `MenuItemDebugKey`
 * atteint : l'objet retenu, le personnage actif, l'identifiant tiré et le
 * nombre d'exemplaires. */
class CMenuItemInfo : public CBaseMenuClass {
public:
    s16 unknown_114;  /* 0x114 — le personnage retenu */
    u8 unknown_116[0x17C - 0x116];
    CGameDataUsed *unknown_17C;  /* 0x17C — l'objet que le menu montre */
    u8 unknown_180[0x1A4 - 0x180];
    CMenuPosDataForm *unknown_1A4;  /* 0x1A4 — le panneau des sous */
    u8 unknown_1A8[0x2FE - 0x1A8];
    s16 unknown_2FE;  /* 0x2FE — l'identifiant de l'objet tiré */
    u8 unknown_300;   /* 0x300 — le nombre d'exemplaires, de 1 à 100 */
};

extern CMenuItemInfo *CMenuItemInfoPt;
extern CUserDataManager *MenuUserDataManPtr;
extern ROBO_DATA *MenuUserParam[6];
extern CGameData GameItemDataManage;
extern mgCTextureManager mgTexManager;

/* La pile où le modèle de mise au point est chargé, et ce qu'il en occupe. */
extern mgCMemory MenuDebugStack;
extern s32 MenuDebugSize;
extern mgCCamera *MenuDebugCamera;
extern CDebugModel *MenuDebugItemModel;
extern s8 MenuDebugModelDrawFlag;
extern s8 MenuDebugModel_AdjustFlag;

extern s32 debug_common_data;
extern s8 ItemOverFlowCheckFlag;
extern s32 LanguageCode;
extern s16 MenuItemBoardTotalNum;
extern s16 MenuItemBoardTotalLine;
extern s16 MenuItem_ItemBoardTopLine;
extern s16 MenuItem_ItemBoardTopSelect;

/* Les arguments du menu des objets, dont deux champs suivent le contenu du
 * sac. */
struct ITEM_MENU_ARG {
    u8 unknown_00[0x56];
    s16 unknown_56;  /* 0x56 */
    u8 unknown_58[2];
    s8 unknown_5A;   /* 0x5A */
    u8 unknown_5B[0x1B0 - 0x5B];
};

extern ITEM_MENU_ARG item_menu_argtbl;

/* Les statiques que MWCC numérote : un compteur et son témoin
 * d'initialisation, par écran. Le découpage des données n'étant pas fait, elles
 * se déclarent `extern` et le témoin s'écrit à la main. */
extern s32 cnt_6161;
extern s8 init_6162;
extern s32 testcnt_6298;
extern s8 init_6299;

/* La table des attributs que l'écran des armes fait tourner. */
extern u32 table_6164[7];

/* Les littéraux que les fonctions se partagent : les écrire en clair les ferait
 * émettre dans le `.rodata` de cette unité. */
extern char dbox_path_6083[];
extern char _4954[];
extern char _1493_00370170[];

/* Les modèles d'initialisation que MWCC pose pour les agrégats locaux. Chacun
 * fait huit octets — les deux axes d'un manche — et vit dans le bss, donc à
 * zéro ; la recopie s'écrit ici faute de pouvoir placer le modèle. */
extern u64 _6133;
extern u64 _6176;
extern u64 _6220;
extern u64 _6234;
extern u64 _6256;
extern u64 _6265;

GAME_DATA_PT *GetGameDataPt();
s32 GetCommonItemData(s32 item);
WEAPON_INFO *GetWeaponInfoData(s32 kind);
s16 GetNowBagMax(s32 kind);
char *GetItemFilePath(s32 item, s32 index);
s32 LoadFile2(char *path, void *buffer, s32 *size, s32 flag);
void DebugGetItem(CUserDataManager *manager, s32 item);
void CheckEnableHaveItemNum();
s32 CheckItemOver();
s32 CheckTrushMenu();
u32 CheckWeaponAttribute(u32 current, u32 mask);
f32 MenuAdjustPolygonScale(mgCFrame *frame, f32 size);

/* La réservation que le menu emploie. Son nom manglé porte `P1`, que rien de ce
 * que MWCC produit ne rend : un pointeur de classe donne `P1X` pour une classe
 * `X`, et la lettre manque ici. Le type du second paramètre reste donc à
 * établir, et la fonction s'appelle sous le nom que le binaire porte.
 *
 * Ce qui suit — la réservation, le contrôle de nullité, l'appel du
 * constructeur — est ce que `new` produirait ; l'écrire à la main est le prix de
 * ce nom qu'on ne sait pas reformer. */
extern "C" void *__nw__FUiP1(u32 size, s32 block);
extern "C" void *__ct__15mgCCameraFollowFffff(void *self, f32 a, f32 b, f32 c,
                                              f32 d);
extern "C" void *__ct__10CRunScriptFv(void *self);
extern "C" void *memset(void *dst, s32 value, u32 size);

/* Les tables virtuelles que le constructeur du personnage pose l'une après
 * l'autre, une par niveau de la hiérarchie. */
extern void *__vt__9mgCObject[];
extern void *__vt__7CObject[];
extern void *__vt__12CObjectFrame[];
extern void *__vt__11CCharacter2[];
extern void *__vt__12CActionChara[];

/* Les emplacements des méthodes du modèle dans sa table virtuelle. MWCC en
 * réserve les deux premières entrées, donc `0x14` est la troisième déclarée. */

/* Ramène un angle dans le tour, à un tour près. Le commerce la développe sur
 * place aux trois axes, donc elle est déclarée `inline`. */
inline void WrapAngle(f32 *angle) {
    if (*angle > 3.1415927f) {
        *angle -= 6.2831855f;
    } else if (*angle < -3.1415927f) {
        *angle += 6.2831855f;
    }
}

INCLUDE_ASM("nonmatchings/game/text_00247E10", MenuItemDebugKey__Fv);

/* La reconstruction rend 5 836 octets — le compte exact — et 99,84 % : vingt-
 * trois octets diffèrent, en une seule plage, `0x002481E0`..`0x002481F6`. Elle
 * reste ici pour qui reprendra ; basculer le `#if` la remet en service.
 *
 * L'écart tient à la matérialisation des quatre flottants du constructeur de
 * `mgCCameraFollow`. Le commerce n'emploie qu'un registre de travail et comble
 * l'écriture-après-lecture par le `mtc1 zero` du troisième argument ; nous en
 * employons deux, `$v1` et `$a0`, apparions les `lui` et rejetons le zéro en
 * queue. `docs/IDIOMES_MWCC.md` en donne la preuve — un registre d'argument
 * occupé suffit à rendre la forme du commerce —, les deux comptages qui la
 * bornent, et la liste de ce qui a été éprouvé en vain. */
#if 0
void MenuItemDebugKey(void) {
    f32 rotation[4];
    f32 axis3[2];
    f32 axis4[2];
    f32 axis5[2];
    f32 axis5b[2];
    f32 axis7[2];
    f32 axis10[2];
    s32 size;
    s32 key;
    CGameDataUsed *item;

    key = MenuCommonInfo->CheckPushButton();
    item = CMenuItemInfoPt->unknown_17C;

    switch (CMenuItemInfoPt->mode) {
    case 2:
        if (MenuDebugModelDrawFlag == 0) {
                        s32 select;
            void *camera;
            CDebugModel *model;
            s32 step;
            s32 wanted;
            s32 loaded;
            void *buffer;
            s32 used;
            char *path;

            select = MenuCommonInfo->CheckSelectKey();
            if (select & 0x20) {
                CMenuItemInfoPt->unknown_2FE += 0x40;
            }
            if (select & 0x10) {
                CMenuItemInfoPt->unknown_2FE -= 0x40;
            }
            if (select & 1) {
                CMenuItemInfoPt->unknown_2FE -= 8;
            }
            if (select & 2) {
                CMenuItemInfoPt->unknown_2FE += 8;
            }
            if (select & 8) {
                CMenuItemInfoPt->unknown_2FE += 1;
            }
            if (select & 4) {
                CMenuItemInfoPt->unknown_2FE -= 1;
            }

            step = 1;
            if (GamePad_003FA5A0.On(0x40)) {
                step = 5;
            }
            if (select & 0x80) {
                CMenuItemInfoPt->unknown_300 += step;
            }
            if (select & 0x40) {
                CMenuItemInfoPt->unknown_300 -= step;
            }
            if (CMenuItemInfoPt->unknown_300 <= 0) {
                CMenuItemInfoPt->unknown_300 = 1;
            }
            if (CMenuItemInfoPt->unknown_300 > 0x64) {
                CMenuItemInfoPt->unknown_300 = 0x64;
            }
            if (CMenuItemInfoPt->unknown_2FE <= 0) {
                CMenuItemInfoPt->unknown_2FE = 1;
            }
            wanted = CMenuItemInfoPt->unknown_2FE;
            if (GetGameDataPt()->unknown_20 < wanted) {
                CMenuItemInfoPt->unknown_2FE = GetGameDataPt()->unknown_20;
            }
            debug_common_data = GetCommonItemData(CMenuItemInfoPt->unknown_2FE);

            if (GamePad_003FA5A0.Down(0x10)) {
                MenuSePlay(1);
                DebugGetItem(NULL, 0);
                CheckEnableHaveItemNum();
            }

            if (key & 1) {
                if (debug_common_data != 0) {
                    MenuUserDataManPtr->GetItemNotOver(
                        CMenuItemInfoPt->unknown_2FE,
                        CMenuItemInfoPt->unknown_300);
                    if (CheckItemOver() &&
                        (MenuCommonInfo->unknown_50 == 0 ||
                         MenuCommonInfo->unknown_50 == 1)) {
                        MenuCommonInfo->unknown_50 += 0x10;
                        ItemOverFlowCheckFlag = 1;
                    }
                    if (CheckTrushMenu()) {
                        MenuItemBoardTotalNum = GetNowBagMax(1);
                        MenuItem_ItemBoardTopLine = MenuItemBoardTotalNum / 6 - 5;
                        MenuItem_ItemBoardTopSelect = GetNowBagMax(0);
                    }
                    item_menu_argtbl.unknown_56 = MenuItemBoardTotalNum;
                    MenuItemBoardTotalLine = MenuItemBoardTotalNum / 6;
                    item_menu_argtbl.unknown_5A = MenuItemBoardTotalLine;
                    CheckEnableHaveItemNum();
                }
            } else if (key & 0x80) {
                GameItemDataManage.LoadData();
                GameItemDataManage.LoadItemSystemMes(LanguageCode);
            } else if (key & 8) {
                MenuDebugStack.unknown_24 = 0;
                MenuDebugStack.unknown_1C = 0;
                MenuDebugCamera = NULL;
                MenuDebugItemModel = NULL;
                MenuDebugModelDrawFlag = 1;

                /* @@cam */
                s32 block = MenuDebugStack.Alloc(0xE);
                camera = __nw__FUiP1(0xC0, block);
                if (camera != NULL) {
                    camera = __ct__15mgCCameraFollowFffff(camera, 40, 30, 0, 8);
                }
                MenuDebugCamera = (mgCCamera *)camera;
                /* @@fin */

                if ((model = (CDebugModel *)__nw__FUiP1(
                         0x1030, MenuDebugStack.Alloc(0x105))) != NULL) {
                    *(void **)model = __vt__9mgCObject;
                    model->Initialize();
                    *(void **)model = __vt__7CObject;
                    model->Initialize();
                    *(void **)model = __vt__12CObjectFrame;
                    model->Initialize();
                    *(void **)model = __vt__11CCharacter2;
                    model->unknown_35C = 0;
                    model->unknown_364 = 0;
                    model->unknown_360 = 0;
                    model->Initialize();
                    *(void **)model = __vt__12CActionChara;
                    __ct__10CRunScriptFv(model->unknown_6BC);
                    memset(model->unknown_910, 0, 0x110);
                }
                MenuDebugItemModel = model;

                model->SetVisible(0);
                MenuDebugStack.Align64();

                buffer = MenuDebugStack.unknown_20 + MenuDebugStack.unknown_24 * 0x10;
                loaded = 0;
                if (debug_common_data != 0) {
                    path = GetItemFilePath(CMenuItemInfoPt->unknown_2FE, 0);
                    if (path != NULL && LoadFile2(path, buffer, &size, 0)) {
                        MenuDebugStack.Alloc(size / 16 + 1);
                        used = MenuDebugStack.unknown_24;
                        mgTexManager.DeleteBlock(CMenuItemInfoPt->unknown_28);
                        MenuDebugItemModel->LoadModel(buffer, _4954, &MenuDebugStack,
                            &MenuDebugStack, &MenuDebugStack,
                            CMenuItemInfoPt->unknown_28, 0);
                        MenuDebugItemModel->SetPos(0.0f, 0.0f, 0.0f);
                        MenuDebugItemModel->SetScale(1.0f, 1.0f, 1.0f);
                        MenuDebugCamera->SetRef(0.0f, 0.0f, 0.0f);
                        MenuDebugCamera->SetPos(0.0f, 0.0f, 100.0f);
                        MenuDebugSize = MenuDebugStack.unknown_24 - used;
                        MenuDebugSize = MenuDebugSize * 16 / 1024;
                        loaded = 1;
                    }
                }
                if (loaded == 0) {
                    buffer = MenuDebugStack.unknown_20 +
                             MenuDebugStack.unknown_24 * 0x10;
                    LoadFile2(dbox_path_6083, buffer, &size, 0);
                    MenuDebugStack.Alloc(size / 16 + 1);
                    used = MenuDebugStack.unknown_24;
                    mgTexManager.DeleteBlock(CMenuItemInfoPt->unknown_28);
                    MenuDebugItemModel->LoadModel(buffer, _4954, &MenuDebugStack,
                        &MenuDebugStack, &MenuDebugStack,
                        CMenuItemInfoPt->unknown_28, 0);
                    MenuDebugItemModel->SetPos(0.0f, 0.0f, 0.0f);
                    MenuDebugItemModel->SetScale(1.0f, 1.0f, 1.0f);
                    MenuDebugItemModel->ResetPose();
                    MenuDebugCamera->SetRef(0.0f, 0.0f, 0.0f);
                    MenuDebugCamera->SetPos(0.0f, 0.0f, 100.0f);
                    MenuDebugSize = MenuDebugStack.unknown_24 - used;
                    MenuDebugSize = MenuDebugSize * 16 / 1024;
                }
                if (MenuDebugModel_AdjustFlag != 0 && MenuDebugItemModel != NULL) {
                    f32 scale =
                        MenuAdjustPolygonScale(MenuDebugItemModel->unknown_070, 7.0f);
                    MenuDebugItemModel->SetScale(scale, scale, scale);
                }
                GamePad_003FA5A0.MenuModeOff();
            }
        } else if (MenuDebugModelDrawFlag == 1) {
            if (MenuDebugItemModel != NULL) {
                f32 x;
                f32 y;
                s32 turning;

                MenuDebugItemModel->GetRotate(rotation);
                x = GamePad_003FA5A0.GetLXf() / 10.0f;
                y = GamePad_003FA5A0.GetLYf() / 10.0f;
                turning = 0;
                if (GamePad_003FA5A0.On(1)) {
                    turning = 1;
                }
                if (turning) {
                    ((mgCCameraFollow *)MenuDebugCamera)->GetAngle();
                } else {
                    rotation[1] += x;
                    rotation[0] += y;
                }
                WrapAngle(&rotation[0]);
                WrapAngle(&rotation[1]);
                WrapAngle(&rotation[2]);
                MenuDebugItemModel->SetRotate(rotation);
                MenuDebugItemModel->SetRotateAlso(rotation);
                rotation[0] += GamePad_003FA5A0.GetRYf() / 10.0f;
                if (rotation[0] <= 0.1f) {
                    rotation[0] = 0.1f;
                }
                if (rotation[0] >= 100.0f) {
                    rotation[0] = 100.0f;
                }
                MenuDebugItemModel->SetScale(rotation[0], rotation[0], rotation[0]);
            }
            MenuDebugCamera->vf08(1);
            if (key & 4) {
                MenuDebugItemModel->SetScale(1.0f, 1.0f, 1.0f);
                MenuDebugItemModel->SetPosition(0.0f, 0.0f, 0.0f);
                MenuDebugModel_AdjustFlag = 0;
            } else if (key & 8) {
                if (MenuDebugItemModel != NULL) {
                    MenuDebugModel_AdjustFlag ^= 1;
                    if (MenuDebugModel_AdjustFlag != 0) {
                        f32 scale = MenuAdjustPolygonScale(
                            MenuDebugItemModel->unknown_070, 7.0f);
                        MenuDebugItemModel->SetScale(scale, scale, scale);
                    } else {
                        MenuDebugItemModel->SetScale(1.0f, 1.0f, 1.0f);
                    }
                }
            } else if (key & 2) {
                MenuDebugModelDrawFlag = 0;
                MenuDebugItemModel = NULL;
                MenuDebugCamera = NULL;
                GamePad_003FA5A0.MenuModeOn(0x78);
            }
        }
        break;

    case 3: {
        ROBO_DATA *gage;
        s32 shifted;

        gage = MenuUserParam[CMenuItemInfoPt->unknown_114];
        if (gage != NULL) {
            *(u64 *)axis3 = _6133;
            MenuCommonInfo->CheckAnalogKey(0, axis3);
            shifted = 0;
            if (GamePad_003FA5A0.On(1)) {
                shifted = 1;
            }
            if (shifted == 0) {
                gage->point = gage->point + (f32)(s32)axis3[0];
            }
            if (shifted == 1) {
                gage->max = gage->max + (f32)(s32)axis3[0];
            }
            gage->max = GetDispVolumeForFloat(gage->max);
            if (gage->point >= gage->max) {
                gage->point = gage->max;
            }
            if (gage->point <= 0.0f) {
                gage->point = 0.0f;
            }
            if (gage->max > 255.0f) {
                gage->max = 255.0f;
            }
            if (gage->max <= 0.0f) {
                gage->max = 0.0f;
            }
        }
        if (GamePad_003FA5A0.On(0x20)) {
            gage->unknown_0A += 1;
            if (gage->unknown_0A > 0x80) {
                gage->unknown_0A = 0x80;
            }
        } else if (GamePad_003FA5A0.On(0x40)) {
            s32 count = gage->unknown_0A;

            if (0 < count) {
                gage->unknown_0A = count - 1;
            }
        }
        if (key & 4) {
            MenuUserDataManPtr->AddMoney(1000);
            CMenuItemInfoPt->unknown_1A4->SetNumber(
                _1493_00370170, MenuUserDataManPtr->AddMoney(0));
        }
        if (key & 8) {
            if (init_6162 == 0) {
                cnt_6161 = 0;
                init_6162 = 1;
            }
            MenuUserDataManPtr->SetCharaStatusAttirbuteVol(
                CMenuItemInfoPt->unknown_114, table_6164[cnt_6161], 0x78);
            cnt_6161 += 1;
            if (cnt_6161 > 6) {
                cnt_6161 = 0;
            }
        }
        return;
    }

    case 4: {
        s32 shifted;
        s32 onDurability;
        s32 onExperience;

        if (item == NULL) {
            break;
        }
        shifted = 0;
        onDurability = 0;
        onExperience = 0;
        if (GamePad_003FA5A0.On(3)) {
            onDurability = 1;
        }
        if (GamePad_003FA5A0.On(0xC)) {
            onExperience = 1;
        }
        if (GamePad_003FA5A0.On(5)) {
            shifted = 1;
        }
        *(u64 *)axis4 = _6176;
        MenuCommonInfo->CheckAnalogKey(0, axis4);
        if (item->kind == 3) {
            if (onDurability) {
                if (shifted == 0) {
                    item->durability.point += axis4[0];
                }
                if (shifted == 1) {
                    item->durability.max += axis4[0];
                }
                if (item->durability.max < 1.0f) {
                    item->durability.max = 1.0f;
                }
                if (255.0f < item->durability.max) {
                    item->durability.max = 255.0f;
                }
                item->durability.max = GetDispVolumeForFloat(item->durability.max);
                if (item->durability.point < 0.0f) {
                    item->durability.point = 0.0f;
                }
                if (item->durability.max < item->durability.point) {
                    item->durability.point = item->durability.max;
                }
            }
            if (onExperience) {
                if (shifted == 0) {
                    item->experience.point += axis4[0];
                }
                if (shifted == 1) {
                    item->experience.max += axis4[0];
                }
                if (item->experience.max < 1.0f) {
                    item->experience.max = 1.0f;
                }
                if (99999.0f < item->experience.max) {
                    item->experience.max = 99999.0f;
                }
                item->experience.max = GetDispVolumeForFloat(item->experience.max);
                if (item->experience.point < 0.0f) {
                    item->experience.point = 0.0f;
                }
                if (item->experience.max < item->experience.point) {
                    item->experience.point = item->experience.max;
                }
            }
            if (key & 1) {
                item->AddFusionPoint(1);
            }
            if (key & 2) {
                item->AddFusionPoint(-1);
            }
            if (key & 8) {
                item->AddFusionPoint(500);
            }
            if (key & 4) {
                item->LevelUp();
                MenuSePlay(1);
            }
        }
        return;
    }

    case 5: {
        s32 line;
        WEAPON_INFO *info;

        if (item == NULL) {
            break;
        }
        if (item->kind == 3) {
            info = GetWeaponInfoData(item->unknown_02);
            MenuCommonInfo->CheckSelectKey();
            CMenuKeyFunc *common = MenuCommonInfo;

            line = common->unknown_70;
            *(u64 *)axis5 = _6220;
            common->CheckAnalogKey(0, axis5);
            if (line < 2) {
                /* Le champ est atteint cinq fois : le commerce en hisse
                 * l'adresse et n'y touche plus qu'en `0x0(sN)`. */
                s16 *field =
                    &((WEAPON_STATUS *)((line << 1) + (u32)item))->unknown_22;

                *field += (s16)(s32)axis5[0];
                if (*field < 0) {
                    *field = 0;
                }
                if (((WEAPON_INFO *)((line << 1) + (u32)info))->unknown_08 <
                    *field) {
                    *field = ((WEAPON_INFO *)((line << 1) + (u32)info))->unknown_08;
                }
            } else {
                s16 *field =
                    &((WEAPON_STATUS *)(((line - 2) << 1) + (u32)item))->unknown_26;

                *field += (s16)(s32)axis5[0];
                if (*field < 0) {
                    *field = 0;
                }
                if (((WEAPON_INFO *)(((line - 2) << 1) + (u32)info))->unknown_1C <
                    *field) {
                    *field =
                        ((WEAPON_INFO *)(((line - 2) << 1) + (u32)info))->unknown_1C;
                }
            }
        }
        if (item->kind == 5) {
            s16 *field;

            MenuCommonInfo->CheckSelectKey();
            CMenuKeyFunc *common = MenuCommonInfo;

            line = common->unknown_70;
            *(u64 *)axis5b = _6234;
            common->CheckAnalogKey(0, axis5b);
            if (line < 2) {
                field = &((WEAPON_STATUS *)((line << 1) + (u32)item))->unknown_20;
                *field += (s16)(s32)axis5b[0];
                if (*field < 0) {
                    *field = 0;
                }
                if (((WEAPON_STATUS *)((line << 1) + (int)item))->unknown_22 >
                    0xFF) {
                    ((WEAPON_STATUS *)((line << 1) + (int)item))->unknown_22 =
                        0xFF;
                }
            } else {
                field =
                    &((WEAPON_STATUS *)(((line - 2) << 1) + (u32)item))->unknown_24;
                *field += (s16)(s32)axis5b[0];
                if (*field < 0) {
                    *field = 0;
                }
                if (*field > 0xFF) {
                    *field = 0xFF;
                }
            }
        }
        break;
    }

    case 6: {
        f32 amount;

        amount = 1.0f;
        if (GamePad_003FA5A0.On(0xC)) {
            amount = 100.0f;
        }
        if (GamePad_003FA5A0.On(0x20)) {
            MenuUserDataManPtr->AddRoboAbs(amount);
        }
        if (GamePad_003FA5A0.On(0x40)) {
            MenuUserDataManPtr->AddRoboAbs(-amount);
        }
        if (GamePad_003FA5A0.Down(0x10)) {
            MenuUserParam[2]->unknown_1C ^= 1;
        }
        return;
    }

    case 7: {
        s32 line;

        CMenuKeyFunc *common = MenuCommonInfo;

        line = common->unknown_70;
        *(u64 *)axis7 = _6256;
        common->CheckAnalogKey(0, axis7);
        if (line == 0) {
            MenuUserParam[2]->AddPoint(axis7[0]);
        } else if (line == 1) {
            MenuUserDataManPtr->AddWhp(2, 0, (s32)axis7[0]);
        }
        break;
    }

    case 10: {
        s32 line;
        WEAPON_INFO *info;
        s16 *field;

        if (item->IsFishingRod()) {
            info = GetWeaponInfoData(item->unknown_02);
            MenuCommonInfo->CheckSelectKey();
            CMenuKeyFunc *common = MenuCommonInfo;

            line = common->unknown_70;
            *(u64 *)axis10 = _6265;
            common->CheckAnalogKey(0, axis10);
            field = &((WEAPON_STATUS *)((line << 1) + (u32)item))->unknown_26;
            *field += (s16)(s32)axis10[0];
            if (*field < 0) {
                *field = 0;
            }
            if (((WEAPON_INFO *)((line << 1) + (u32)info))->unknown_1C < *field) {
                *field = ((WEAPON_INFO *)((line << 1) + (u32)info))->unknown_1C;
            }
            if (GamePad_003FA5A0.On(0x20)) {
                item->AddFusionPoint(1);
            }
            if (GamePad_003FA5A0.On(0x40)) {
                item->AddFusionPoint(-1);
            }
            if (GamePad_003FA5A0.On(0x10)) {
                item->AddFusionPoint(-500);
            }
            if (GamePad_003FA5A0.On(0x80)) {
                item->AddFusionPoint(500);
            }
        }
        break;
    }

    /* Le mode le plus haut du menu ne fait rien de la touche. Il est déclaré
     * parce que c'est lui qui borne la table de saut : le commerce éprouve
     * `sltiu 0xC`, donc le compilateur en a vu douze entrées. */
    case 11:
        break;
    }

    /* Un aiguillage à un seul cas, non un `if` : c'est lui qui rend le `beq`
     * vers le corps doublé d'un `b` vers la sortie. */
    switch (CMenuItemInfoPt->mode) {
    case 5:
        if (item != NULL) {
            WEAPON_INFO *info = GetWeaponInfoData(item->unknown_02);

            if (key & 4) {
                item->status[0] = info->unknown_08;
                item->status[1] = info->unknown_0A;
                item->status[2] = info->unknown_1C;
                item->status[3] = info->unknown_1E;
                item->status[4] = info->unknown_20;
                item->status[5] = info->unknown_22;
                item->status[6] = info->unknown_24;
                item->status[7] = info->unknown_26;
                item->status[8] = info->unknown_28;
                item->status[9] = info->unknown_2A;
            }
            if (key & 8) {
                item->status[0] = info->unknown_04;
                item->status[1] = info->unknown_06;
                item->status[2] = info->unknown_0C;
                item->status[3] = info->unknown_0E;
                item->status[4] = info->unknown_10;
                item->status[5] = info->unknown_12;
                item->status[6] = info->unknown_14;
                item->status[7] = info->unknown_16;
                item->status[8] = info->unknown_18;
                item->status[9] = info->unknown_1A;
            }
            if (GamePad_003FA5A0.Down(8)) {
                if (init_6299 == 0) {
                    testcnt_6298 = 0;
                    init_6299 = 1;
                }
                /* Le masque se construit en deux temps : le commerce
                 * matérialise le zéro avant d'y poser le bit, ce qu'une
                 * expression repliée ne rend pas. */
                u32 mask = 0;

                mask |= 1 << testcnt_6298;
                item->attribute = CheckWeaponAttribute(item->attribute, mask);
                testcnt_6298 += 1;
                if (testcnt_6298 >= 0xC) {
                    testcnt_6298 = 0;
                }
            }
        }
        break;
    }
}
#endif
