/* CEditMap, CCameraControl, CEditEvent, CPadControl, CMenuSystemData
 *
 * Unité découpée par `make carve` : 70 fonctions, 22128 octets, de
 * 0x002F0E80 à 0x002F6690. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

/* La caméra du middleware, telle que ce constructeur l'emploie. Sa table
 * virtuelle est à `0x60` : c'est là que `__ct__15mgCCameraFollowFffff` écrit la
 * sienne, en 00132150. La hiérarchie est donc coupée là — MWCC place le témoin
 * au début du premier niveau polymorphe, donc `0x60` octets muets viennent
 * avant. Sa taille est de `0xC0` octets, ce que la temporaire de pile dit : le
 * cadre de `0xE0` la range à `sp + 0x20` et s'arrête juste après.
 *
 * Déclarer la classe polymorphe n'est pas cosmétique. C'est ce qui décide de la
 * forme des quatre constantes de son constructeur : muette, notre chaîne
 * apparie les `lui` et rejette le `mtc1 zero` en queue ; polymorphe, elle rend
 * la séquence du commerce aux deux sites de cette fonction. Bissecté sur
 * `perm/variantes4` — ni la position du témoin ni un stockage de plus ne
 * changent quoi que ce soit. */
/* Le quadmot est ce qui fait la différence entre `lq`/`sq` et huit instructions :
 * MWCC ne recopie un vecteur d'un coup que si son type le porte. Il ne peut pas
 * être celui des champs pour autant : il alignerait la classe sur seize, ce qui
 * bourre `mgCCamera` jusqu'à `0x70` et décale tout ce qui suit de seize octets.
 * Les champs restent donc en `f32[4]`, et la copie seule prend ce type-là. */
union VECTOR {
    f32 f[4];
    u128 qw;
};

class mgCCameraBase {
public:
    f32 unknown_00[4];
    f32 unknown_10[4];
    /* Ce que `ControlOn` sauvegarde avant de prendre la main. */
    f32 saved_00[4];
    f32 saved_10[4];
    u8 unknown_40[0x60 - 0x40];
};

class mgCCamera : public mgCCameraBase {
public:
    virtual void vf08();

    void Stay();
};

class mgCCameraFollow : public mgCCamera {
public:
    mgCCameraFollow(f32 a, f32 b, f32 c, f32 d);

    void Stay();
    void SetHeight(f32 height);

    u8 unknown_64[0xC0 - 0x64];
};

/* Les onze champs que `__as__15CameraCtrlParamFRC15CameraCtrlParam` recopie un
 * à un, en 001ACEE0 : dix en `lwc1`/`swc1`, le dernier en `lw`/`sw`. La
 * structure fait donc `0x2C` octets, ce que le pas de `GetActiveParam` confirme
 * — l'indice y est multiplié par `0x2C`. */
struct CameraCtrlParam {
    /* Recopie champ par champ, et non membre à membre : le commerce appelle la
     * fonction, donc l'opérateur est écrit, pas engendré. */
    CameraCtrlParam &operator=(const CameraCtrlParam &src);

    f32 unknown_00;
    f32 unknown_04;
    f32 unknown_08;
    f32 unknown_0C;
    f32 unknown_10;
    f32 unknown_14;
    f32 unknown_18;
    f32 unknown_1C;
    f32 unknown_20;
    f32 unknown_24;
    s32 unknown_28;
};

/* `mgZeroVector` reçoit un `f32 *`, ce qui ne dit pas sa longueur ; les seize
 * octets entre `0xE0` et le champ suivant la donnent. */
void mgZeroVector(f32 *vector);
void mgUnitMatrix(f32 (*matrix)[4]);
f32 mgAngleLimit(f32 angle);
f32 mgDistVectorXZ(f32 *a, f32 *b);

/* La statique locale que `SetRotate` recopie dans son vecteur de travail. Elle
 * vit dans le bss, donc elle ne porte que des zéros ; elle se déclare sous le
 * nom que le désassembleur lui a donné pour ne pas en créer une seconde. */
extern f32 _373_01F58890[4];

/* Celle que la variante à trois flottants de `SetCheckRef` recopie avant
 * d'écrire ses trois composantes. Elle vit dans les données, non dans le bss. */
extern f32 _396_003613A0[4];

/* Les vecteurs du SDK ne sont pas manglés : ils viennent d'un en-tête en C. */
extern "C" void sceVu0SubVector(f32 *result, f32 *a, f32 *b);
extern "C" void sceVu0AddVector(f32 *result, f32 *a, f32 *b);
extern "C" void sceVu0ApplyMatrix(f32 *result, f32 (*matrix)[4], f32 *vector);
extern "C" void sceVu0RotMatrixY(f32 (*result)[4], f32 (*matrix)[4], f32 angle);

class CCameraControl : public mgCCameraFollow {
public:
    CCameraControl();

    CameraCtrlParam *GetActiveParam();
    void SetRotCameraCancel(s32 mask);
    void BitSetRotCameraCancel(s32 mask);
    void BitResetRotCameraCancel(s32 mask);
    void InitStatus();
    void ControlOn();
    void ControlOff();
    void Stay();
    void SetHeight(f32 height);
    void Rotate(f32 angle);
    void SetRotate(f32 angle);
    void SetCheckRef(f32 *ref);
    void SetCheckRef(f32 x, f32 y, f32 z);
    void RotBack(f32 angle);
    void CancelRotBack();
    s32 Iam();

    /* `ControlOff` le remet à zéro. */
    s32 unknown_C0;
    /* Le masque que les trois `RotCameraCancel` posent, allument et éteignent. */
    s32 rot_cancel;
    /* `RotBack` met le drapeau à un et range son angle juste après ;
     * `CancelRotBack` n'éteint que le drapeau. */
    s32 unknown_C8;
    f32 unknown_CC;
    s32 unknown_D0;
    u8 unknown_D4[0xE0 - 0xD4];
    f32 unknown_E0[4];
    /* L'indice que `GetActiveParam` lit puis multiplie par `0x2C`. */
    s32 active;
    CameraCtrlParam param[4];
    CameraCtrlParam current;
    /* Le repère que `SetCheckRef` recopie en `sq`, et le drapeau qu'il lève. */
    f32 check_ref[4];
    s32 unknown_1E0;
};

INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", __ct__14CCameraControlFv);

/* La reconstruction rend 100,00 % — les 288 octets, relocations comprises. Elle
 * n'entre pourtant pas en service : déclarer `CCameraControl` polymorphe, ce que
 * le commerce impose, fait émettre `__vt__14CCameraControl` par notre objet, et
 * l'éditeur de liens la voit alors deux fois — le disque la porte en 0037C5A0,
 * dans la plage `rodata` de 00372BA0. La lever demande de posséder la table :
 * sortir ces neuf mots de la plage du disque, et donner à la section `.vtables`
 * sa place dans le script de lien. Basculer le `#if` remet la fonction en
 * service. */
#if 0
CCameraControl::CCameraControl() : mgCCameraFollow(40.0f, 30.0f, 0.0f, 8.0f) {
    CameraCtrlParam *p;

    p = param;
    do {
        p->unknown_28 = 0;
        p++;
    } while (p < &current);
    current.unknown_28 = 0;

    mgCCameraFollow initial(40.0f, 30.0f, 0.0f, 8.0f);

    active = 0;
    unknown_C0 = 0;

    p = GetActiveParam();
    p->unknown_00 = 100.0f;
    p->unknown_04 = 160.0f;
    p->unknown_08 = 18.0f;
    p->unknown_0C = 10.0f;
    /* L'ordre d'émission des stockages est celui de la source : le commerce
     * range `0x10` entre `0x20` et `0x24`, et rien dans l'ordonnancement ne
     * déplacerait un `sw` par-dessus quatre autres du même objet. */
    p->unknown_14 = 40.0f;
    p->unknown_18 = -15.0f;
    p->unknown_1C = 20.0f;
    p->unknown_20 = -15.0f;
    p->unknown_10 = -15.0f;
    p->unknown_24 = 25.0f;

    unknown_1E0 = 0;
    p->unknown_28 = 0;
    unknown_D0 = 0;
    InitStatus();
    current = *GetActiveParam();
}
#endif
CameraCtrlParam *CCameraControl::GetActiveParam(void) {
    return &param[active];
}
void CCameraControl::SetRotCameraCancel(s32 mask) {
    rot_cancel = mask;
}
void CCameraControl::BitSetRotCameraCancel(s32 mask) {
    rot_cancel |= mask;
}
void CCameraControl::BitResetRotCameraCancel(s32 mask) {
    rot_cancel &= ~mask;
}
void CCameraControl::InitStatus(void) {
    rot_cancel = 0;
    unknown_C8 = 0;
    unknown_CC = 0.0f;
    mgZeroVector(unknown_E0);
}
void CCameraControl::ControlOn(void) {
    CameraCtrlParam *p;

    if (unknown_C0 == 0) {
        *(VECTOR *)saved_10 = *(VECTOR *)unknown_10;
        *(VECTOR *)saved_00 = *(VECTOR *)unknown_00;
        p = GetActiveParam();
        p->unknown_10 = saved_00[1] - saved_10[1];
        if (p->unknown_10 < p->unknown_18) {
            p->unknown_10 = p->unknown_18;
        }
        if (p->unknown_10 > p->unknown_14) {
            p->unknown_10 = p->unknown_14;
        }
    }
    unknown_C0 = 1;
}
void CCameraControl::ControlOff(void) {
    unknown_C0 = 0;
}
void CCameraControl::Stay(void) {
    if (unknown_C0 == 0) {
        mgCCameraFollow::Stay();
    } else {
        mgCCamera::Stay();
    }
}
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", Step__14CCameraControlFi);
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", MoveCamera__14CCameraControlFP11CPadControlPfP6CCPolyi);
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", MoveCamera__14CCameraControlFPQ214CCameraControl7ControlPfP6CCPolyi);
void CCameraControl::Rotate(f32 angle) {
    f32 offset[4];
    f32 matrix[4][4];

    sceVu0SubVector(offset, saved_00, saved_10);
    offset[3] = 0.0f;
    mgUnitMatrix(matrix);
    sceVu0RotMatrixY(matrix, matrix, mgAngleLimit(angle));
    sceVu0ApplyMatrix(offset, matrix, offset);
    sceVu0AddVector(saved_00, saved_10, offset);
}
void CCameraControl::SetRotate(f32 angle) {
    f32 offset[4];
    f32 matrix[4][4];
    f32 distance;
    f32 height;

    distance = mgDistVectorXZ(saved_10, saved_00);
    /* La différence se nomme : le commerce lit les deux hauteurs avant la copie
     * du vecteur, ce que l'expression écrite sur place ne rend pas. */
    height = saved_00[1] - saved_10[1];
    *(VECTOR *)offset = *(VECTOR *)_373_01F58890;
    offset[1] = height;
    offset[2] = distance;
    mgUnitMatrix(matrix);
    sceVu0RotMatrixY(matrix, matrix, mgAngleLimit(angle));
    sceVu0ApplyMatrix(offset, matrix, offset);
    sceVu0AddVector(saved_00, saved_10, offset);
}
void CCameraControl::SetHeight(f32 height) {
    CameraCtrlParam *p;

    if (unknown_C0 == 0) {
        mgCCameraFollow::SetHeight(height);
    }
    /* Le commerce appelle avant de calculer : sans la locale, MWCC hisse la
     * lecture de `saved_10` par-dessus l'appel. */
    p = GetActiveParam();
    saved_00[1] = saved_10[1] + height;
    p->unknown_10 = height;
}
void CCameraControl::RotBack(f32 angle) {
    unknown_C8 = 1;
    unknown_CC = angle;
}
void CCameraControl::CancelRotBack(void) {
    unknown_C8 = 0;
}
void CCameraControl::SetCheckRef(f32 *ref) {
    unknown_1E0 = 1;
    *(VECTOR *)check_ref = *(VECTOR *)ref;
}
void CCameraControl::SetCheckRef(f32 x, f32 y, f32 z) {
    f32 ref[4];

    *(VECTOR *)ref = *(VECTOR *)_396_003613A0;
    ref[0] = x;
    ref[1] = y;
    ref[2] = z;
    SetCheckRef(ref);
}
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", CheckCollision__14CCameraControlFP6CCPolyi);
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", AutoMove__14CCameraControlFP6CCPolyi);
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", CheckGround__14CCameraControlFP6CCPolyi);
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", GetCameraMatrix__14CCameraControlFPA4_f);
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", CopyParam__14CCameraControlFR14CCameraControl);
s32 CCameraControl::Iam(void) {
    return 1000;
}
/* La manette de l'éditeur. `Initialize` efface les masques de ses deux tableaux
 * huit par huit — MWCC déroule la boucle, la source n'en dit rien — et les
 * bornes de `Register*`, `Btn` et `Analog` en donnent les longueurs : 0x80
 * boutons à 0x10, 0x20 axes à 0x410. */
struct PadBtn {
    s32 value;
    s32 mask;
};

struct PadAnalog {
    f32 value;
    s32 mask;
};

class CPadControl {
public:
    void Initialize();
    s32 RegisterBtn(s32 index, s32 mask, s32 flags);
    s32 RegisterAnalog(s32 index, s32 mask);
    s32 Btn(s32 index);
    f32 Analog(s32 index);

    u8 unknown_00[0x10];
    PadBtn btn[0x80];
    PadAnalog analog[0x20];
};

void CPadControl::Initialize(void) {
    s32 i;
    s32 j;

    for (i = 0; i < 0x80; i++) {
        btn[i].mask = 0;
    }
    for (j = 0; j < 0x20; j++) {
        analog[j].mask = 0;
    }
}
s32 CPadControl::RegisterBtn(s32 index, s32 mask, s32 flags) {
    if (index < 0 || index >= 0x80) {
        return 0;
    }
    btn[index].value = 0;
    btn[index].mask = flags | mask;
    return 1;
}
s32 CPadControl::RegisterAnalog(s32 index, s32 mask) {
    if (index < 0 || index >= 0x20) {
        return 0;
    }
    analog[index].mask = mask;
    analog[index].value = 0.0f;
    return 1;
}
s32 CPadControl::Btn(s32 index) {
    if (index < 0 || index >= 0x80) {
        return 0;
    }
    return btn[index].value;
}
f32 CPadControl::Analog(s32 index) {
    if (index < 0 || index >= 0x20) {
        return 0.0f;
    }
    return analog[index].value;
}
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", Update__11CPadControlFP8CGamePad);
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", PlaneNormalXZ__FPfPfPfPf);
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", GetEditPartsAlt__8CEditMapFP14CEditPartsInfoPffPP10CEditPartsi);
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", CheckEditParts__8CEditMapFP14CEditPartsInfoPffP13EP_PLACE_INFOPP10CEditPartsi);
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", CheckEditPartsOnRiver__8CEditMapFP14CEditPartsInfoPff);
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", CheckRiverParts__8CEditMapFPf);
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", CheckNormalPlaceParts__8CEditMapFi);
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", CheckNormalPlaceParts__8CEditMapFP10CEditParts);
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", CheckLiveNPC__8CEditMapFii);
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", GetePlacePartsAtInfoID__8CEditMapFiPii);
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", GetTerritoryParts__8CEditMapFiPii);
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", GetChildParts__8CEditMapFiPii);
/* La carte que l'éditeur remanie. Seule `RePaintNum` est écrite ici, et elle ne
 * touche aucun champ : la disposition reste à établir. */
class CEditMap {
public:
    s32 RePaintNum(s32 count);
};

class CScene;

/* L'événement de l'éditeur. Les champs déclarés sont ceux que `Reset` écrit,
 * plus la plage de 0xD0 octets qu'il efface d'un `memset`. */
class CEditEvent {
public:
    void Reset();
    s32 Draw(CScene *scene);

    s32 unknown_00;
    s32 unknown_04;
    u8 unknown_08[0xC - 0x8];
    s32 unknown_0C;
    s32 unknown_10;
    u8 unknown_14[0x20 - 0x14];
    u8 unknown_20[0xF0 - 0x20];
    u8 unknown_F0[0x128 - 0xF0];
    s8 unknown_128;
    u8 unknown_129[0x148 - 0x129];
    s32 unknown_148;
};

/* `MenuSystemDataInit` en efface les quatre premiers octets ; le reste de la
 * classe reste à établir. */
class CMenuSystemData {
public:
    void MenuSystemDataInit();

    u8 unknown_00[4];
};

extern "C" void *memset(void *destination, s32 value, u32 size);
extern s16 DngTreeSaveFlag;

s32 CEditMap::RePaintNum(s32 count) {
    return count / 2;
}
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", PaintFence__8CEditMapFiPfi);
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", CheckFenceChain__FP10CEditPartsP10CEditParts);
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", PaintFence__8CEditMapFP10CEditParts);
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", UpdateHouse__8CEditMapFv);
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", GroundBalance__8CEditMapFi);
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", BalanceCheck__8CEditMapFv);
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", InScreenFunc__8CEditMapFP16InScreenFuncInfo);
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", DrawScreenFunc__8CEditMapFP8mgCFrame);
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", GetSeSrcVolPan__8CEditMapFPiPfPfi);
void CEditEvent::Reset(void) {
    unknown_04 = 0;
    unknown_0C = 0;
    unknown_00 = 0;
    unknown_10 = -1;
    unknown_148 = -1;
    unknown_128 = 0;
    memset(unknown_20, 0, 0xD0);
}
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", StartEvent__10CEditEventFP15CSceneEventData);
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", Step__10CEditEventFP6CScene);
/* Les deux sorties rendent zéro, et le commerce les garde distinctes sans saut.
 * Ce sont deux `return` et un test inversé — `!= 1`, non `== 1` — qui rendent le
 * `beq` et les vingt-huit octets. Éprouvé en vain : l'aiguillage à un seul cas
 * gagne un `b` (85,71 %), la locale initialisée se replie (70 %), le défaut en
 * tête allonge (71,43 %). */
s32 CEditEvent::Draw(CScene *scene) {
    if (unknown_04 != 1) {
        return 0;
    }
    return 0;
}
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", GeoramaFunc__FP12GeoFuncParamP12RS_STACKDATAi);
extern "C" s32 GetMap__6CSceneFi(void *, s32);
#include "runscript.hpp"
struct inferred;
typedef struct CScene {
    /* 0x0000 */ char pad0[0x2E5C];
    /* 0x2E5C */ s32 unk2E5C;                       /* inferred */
} CScene;                                           /* size >= 0x2E60 */
typedef struct GeoFuncParam {
    /* 0x0 */ CScene *unk0;                         /* inferred */
} GeoFuncParam;                                     /* size >= 0x4 */
extern "C" s32 PlaceBurnParts__8CEditMapFv(void *);
extern "C" s32 rsSetStack__FP12RS_STACKDATAi(RS_STACKDATA *, s32);
extern "C" s32 CheckPlaceBurnParts__FP12GeoFuncParamP12RS_STACKDATAi(GeoFuncParam *arg0, RS_STACKDATA *arg1, s32 arg2) {
    CEditMap *temp_v0;
    CScene *temp_a0;

    if (arg2 != 1) {
        return 0;
    }
    rsSetStack__FP12RS_STACKDATAi(arg1, 0);
    temp_a0 = (CScene *) (arg0->unk0);
    if (temp_a0 == NULL) {
        return 0;
    }
    temp_v0 = (CEditMap *) (GetMap__6CSceneFi(temp_a0, temp_a0->unk2E5C));
    if (temp_v0 == NULL) {
        return 0;
    }
    rsSetStack__FP12RS_STACKDATAi(arg1, PlaceBurnParts__8CEditMapFv(temp_v0));
    return 1;
}
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", LoadIntNPC__FP12GeoFuncParamP12RS_STACKDATAi);
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", LoadGeoNPC__FP12GeoFuncParami);
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", GeoUpdateNpcPos__FP6CScene);
extern "C" s32 MenuSystemDataInit__15CMenuSystemDataFv(void *);
extern "C" CMenuSystemData *__ct__15CMenuSystemDataFv(CMenuSystemData *objet) {
    MenuSystemDataInit__15CMenuSystemDataFv(objet);
    return objet;
}
void CMenuSystemData::MenuSystemDataInit(void) {
    memset(this, 0, 4);
}
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", CheckGetAlready__15CMenuSystemDataFi);
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", GetGhobi__15CMenuSystemDataFi);
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", CopyMCBrowserName__FiPcPUs);
void SetDngTreeFlag(s32 flag) {
    DngTreeSaveFlag = flag;
}
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", MakeMemoryCardFileName__FiPc);
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", MakeMemoryCardAlbumName__FPci);
INCLUDE_ASM("nonmatchings/game/ceditmap_002F0E80", MakeCheckDigit__FiPci);
