#ifndef SPHIDA_HPP
#define SPHIDA_HPP

#include "types.h"

/* Un point de l'espace, tel que le R5900 le transporte : quatre flottants sur
 * seize octets. L'union avec un quadmot n'est pas une commodité — c'est elle
 * qui donne au type l'alignement de seize octets, et donc à une affectation de
 * vecteur les deux instructions `lq`/`sq` que le binaire porte. Déclaré en
 * simple structure, MWCC le recopie champ par champ, en huit instructions. */
union VECTOR {
    f32 f[4];
    u128 qw;
};

/* La boîte englobante que le middleware emploie pour interroger les collisions :
 * deux coins opposés, chacun sur seize octets. */
struct mgVu0FBOX {
    f32 max[4];
    f32 min[4];
};

class CMapParts;

/* Un polygone de collision. Sa taille est établie par le tableau que `SetUp`
 * en réserve sur la pile : 0x2800 octets pour 128 entrées. */
class CCPoly {
public:
    u8 unknown_00[0x50];
};

/* Un personnage de la scène. Aucune de ses méthodes n'est nommée : `SetUp`
 * n'en appelle qu'une, par la table virtuelle, et c'est sa place qui la
 * désigne. Les précédentes ne sont déclarées que pour l'y amener. */
class CCharacter2 {
public:
    virtual void vf00() = 0;
    virtual void vf04() = 0;
    virtual void vf08() = 0;
    virtual void vf0C() = 0;
    /* Rend la position du personnage. C'est la cinquième déclarée et le
     * binaire la prend en 0x18 de la table : MWCC en réserve les deux
     * premières entrées. */
    virtual void vf18(f32 *pos) = 0;
};

/* Le gestionnaire des coffres : il dit si un point tombe trop près de l'un
 * d'eux. */
class CTreasureBoxManager {
public:
    int CheckArea(f32 *pos, f32 radius);
};

/* Les cercles tirés au hasard qui décorent le donjon, avec la même question. */
class CRandomCircle {
public:
    int CheckArea(f32 *pos, f32 radius);

    u8 unknown_000[0x6A0];
};

/* La carte que le jeu dessine à mesure qu'on explore, et le chemin qu'elle
 * sait tracer d'un point à un autre. */
class CAutoMapGen {
public:
    void UpdateNaviMap(f32 *pos, int step);
    f32 GetNaviDistance(f32 *pos);

    /* La taille que le binaire lui donne. C'est elle qui décide de
     * l'adressage : au-delà du seuil des petites données, MWCC passe par
     * `%hi`/`%lo` et non par `$gp`. */
    u8 unknown_000[0x2A0];
};

/* La scène du donjon. Seuls les deux champs que `SetUp` atteint sont établis. */
class CScene {
public:
    CCharacter2 *GetCharacter(int index);
    int GetColPoly(CCPoly *polys, mgVu0FBOX &box, int max);

    u8 unknown_0000[0x2E50];
    s32 unknown_2E50;  /* 0x2E50 — le personnage que le joueur mène */
    u8 unknown_2E54[0x300C - 0x2E54];
    CTreasureBoxManager *unknown_300C;  /* 0x300C */
};

extern CScene *DngMainScene;
extern CAutoMapGen AutoMapGen;
extern CRandomCircle RandomCircle;

int SearchMapEventParts(int kind, CMapParts **parts, f32 *dists, int max);
int SearchMapFlatPosition(f32 *pos, CAutoMapGen *map);
int CheckHit(CCPoly *polys, int count, f32 *from, f32 *to, f32 *hit, int a,
             int b);

/* Sphida, le personnage guide du donjon. Les champs déclarés sont ceux que
 * `SetUp` et `s17_SetUp` atteignent : la place qu'il occupe, celle vers
 * laquelle il conduit, deux tirages, le nombre d'étapes du trajet, et la copie
 * du modèle de repère qu'il traîne. */
class CSphida {
public:
    void SetUp(int arg);
    void s17_SetUp(int arg);
    void InitStatusSprite();

    u8 unknown_00[0x24];
    s32 unknown_24;   /* 0x24 */
    s32 unknown_28;   /* 0x28 */
    u8 unknown_2C[0x90 - 0x2C];
    /* Un point se déclare en tableau de flottants, non en
     * structure : c'est ce que les prototypes du binaire disent —
     * `Pf`, pointeur de flottant — et le passer sans transtypage est
     * ce qui décide de l'ordre des registres d'argument. Une
     * conversion, même sans instruction, est matérialisée avant les
     * autres arguments et renverse l'ordre. */
    f32 pos[4];       /* 0x90 — où il se tient */
    f32 target[4];    /* 0xA0 — où il conduit */
    s32 unknown_B0;   /* 0xB0 */
    s32 unknown_B4;   /* 0xB4 */
    s32 unknown_B8;   /* 0xB8 — le nombre d'étapes, plafonné à 99 */
    u8 unknown_BC[0xC0 - 0xBC];
    u8 unknown_C0[0x90];  /* 0xC0 — la copie du modèle de repère */
};

#endif /* SPHIDA_HPP */
