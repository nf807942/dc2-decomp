/* CSphida, le guide du donjon : deux façons de le mettre en place, l'une qui
 * cherche une clairière au hasard, l'autre qui pose des coordonnées fixes.
 *
 * Unité découpée par `make carve` : 2 fonctions, 1396 octets, de
 * 0x002EE720 à 0x002EECA0. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"
#include "sphida.hpp"
#include "savedata.hpp"

extern u8 *RedMarkModel;

f32 mgDistVector(f32 *a, f32 *b);
extern "C" void *memcpy(void *dst, const void *src, u32 size);
extern "C" int rand(void);
extern "C" int printf(const char *format, ...);

/* Les deux traces que la mise en place laisse sur la console de mise au point.
 * Les littéraux restent dans le désassemblage ; seuls leurs symboles sont
 * nommés ici. */
extern char _1088[];            /* "SETUP_SFIDA[DIST %d]\n" */
extern char _1089_003776C0[];   /* "SETUP_SFIDA[NAVI %d]\n" */

/* Le numéro de donjon, à cet emplacement de la sauvegarde. */
#define SAVE_DUNGEON_NO_OFFSET 0x1C5B4

/* La mise en place ordinaire reste greffée. Elle est reconstruite à 98,17 %,
 * pour la taille exacte du commerce — 1 152 octets —, et les treize
 * instructions qui divergent sont toutes le même fait : quand un argument se
 * pose par un déplacement de registre et un autre par un calcul d'adresse, le
 * commerce émet le déplacement d'abord, MWCC le remet dans le créneau de délai.
 * Le corps qui rend ce taux est en annexe de ce fichier, sous `#if 0`.
 *
 * Ce qui a été éliminé : les 21 versions de compilateur — la nôtre est la
 * meilleure, 98,17 % contre 97,83 pour la suivante —, dix jeux de drapeaux,
 * 151 essais du permuteur, et six formes d'appel dont celle qui rend l'objet
 * explicite sous son nom manglé. L'écart ne vient donc ni de la version, ni des
 * drapeaux, ni de la forme du C atteinte jusqu'ici. */
INCLUDE_ASM("nonmatchings/game/csphida", SetUp__7CSphidaFi);

#if 0
/* La mise en place ordinaire : Sphida est posé dans une clairière tirée au
 * hasard, et il désigne une seconde clairière comme but.
 *
 * Chacune des deux places est cherchée par tirages successifs jusqu'à ce
 * qu'elle satisfasse tout : être plate, être loin des coffres, être hors des
 * cercles décoratifs, et être assez éloignée de ce qui précède. La seconde est
 * ensuite reposée sur le sol par un lancer de rayon dans une boîte de quarante
 * unités de côté.
 *
 * Le nombre d'étapes du trajet vient du chemin que la carte sait tracer quand
 * le donjon en a un, et de la distance à vol d'oiseau sinon. */
void CSphida::SetUp(int arg) {
    CMapParts *parts[128];
    f32 dists[128];
    VECTOR charaPos;
    CCPoly polys[128];
    mgVu0FBOX box;
    VECTOR from;
    VECTOR to;
    VECTOR hit;
    CTreasureBoxManager *boxes;
    int count;
    int dngNo;
    CSaveData *save;
    f32 navi;

    DngMainScene->GetCharacter(DngMainScene->unknown_2E50)->vf18(&charaPos);
    boxes = DngMainScene->unknown_300C;
    SearchMapEventParts(1, parts, dists, 0x80);

    do {
    } while (!SearchMapFlatPosition((f32 *)&this->pos, &AutoMapGen) ||
             !boxes->CheckArea((f32 *)&this->pos, 60.0f) ||
             !RandomCircle.CheckArea((f32 *)&this->pos, 60.0f) ||
             mgDistVector((f32 *)&charaPos, (f32 *)&this->pos) < 60.0f);
    this->pos.f.y += 30.0f;

    do {
    } while (!SearchMapFlatPosition((f32 *)&this->target, &AutoMapGen) ||
             !boxes->CheckArea((f32 *)&this->target, 40.0f) ||
             /* Le second tirage éprouve les cercles sur la place *déjà* posée,
              * non sur celle qu'il cherche. Le binaire le fait ainsi. */
             !RandomCircle.CheckArea((f32 *)&this->pos, 60.0f) ||
             mgDistVector((f32 *)&this->pos, (f32 *)&this->target) < 200.0f);

    box.max.f.x = 20.0f + this->target.f.x;
    box.min.f.x = this->target.f.x - 20.0f;
    box.max.f.y = 20.0f + this->target.f.y;
    box.min.f.y = this->target.f.y - 20.0f;
    box.max.f.z = 20.0f + this->target.f.z;
    box.min.f.z = this->target.f.z - 20.0f;
    box.max.f.w = 1.0f;
    box.min.f.w = 1.0f;
    from = this->target;
    to = this->target;
    from.f.y += 18.0f;
    to.f.y -= 18.0f;
    count = DngMainScene->GetColPoly(polys, box, 0x80);
    if (CheckHit(polys, count, (f32 *)&from, (f32 *)&to, (f32 *)&hit, 1, 0xC) >=
        0) {
        this->target = hit;
    }

    this->target.f.y += 3.0f;
    this->unknown_B0 = (int)(2.0f * (f32)rand() / 2147483648.0f);
    this->unknown_B4 = (int)(2.0f * (f32)rand() / 2147483648.0f);

    dngNo = -1;
    save = GetSaveData();
    if (save != NULL) {
        int *no = (int *)((u8 *)save + SAVE_DUNGEON_NO_OFFSET);
        if (no != NULL) {
            dngNo = *no;
        }
    }

    switch (dngNo) {
    case 0:
    case 3:
    case 4:
    case 5:
    case 6:
        AutoMapGen.UpdateNaviMap((f32 *)&this->target, 0x28);
        navi = AutoMapGen.GetNaviDistance((f32 *)&this->pos);
        if (navi < 0.0f) {
            this->unknown_B8 =
                (int)(mgDistVector((f32 *)&this->pos, (f32 *)&this->target) /
                      600.0f) +
                1;
            printf(_1088, this->unknown_B8);
        } else {
            this->unknown_B8 = (int)(navi / 1000.0f) + 1;
            printf(_1089_003776C0, this->unknown_B8);
        }
        break;
    case 1:
    case 2:
    default:
        this->unknown_B8 =
            (int)(mgDistVector((f32 *)&this->pos, (f32 *)&this->target) /
                  800.0f) +
            1;
        break;
    }

    if (this->unknown_B8 > 99) {
        this->unknown_B8 = 99;
    }

    if (RedMarkModel != NULL) {
        memcpy(this->unknown_C0, RedMarkModel, 0x90);
    }

    this->unknown_24 = arg;
    this->InitStatusSprite();
    this->unknown_28 = 1;
}

#endif

/* La mise en place d'essai : Sphida est posé à des coordonnées fixes, celles
 * du dix-septième niveau, au lieu d'être placé dans une clairière tirée au
 * hasard comme le fait `SetUp`. Tout le reste est identique — le nombre
 * d'étapes du trajet, la copie du modèle de repère, l'initialisation de la
 * vignette d'état. */
void CSphida::s17_SetUp(int arg) {
    this->pos.f.x = -1.09f;
    this->pos.f.y = 201.0f;
    this->pos.f.z = -478.03f;
    this->pos.f.w = 1.0f;
    this->target.f.x = 0.0f;
    this->target.f.y = 65.57f;
    this->target.f.z = 1305.04f;
    this->target.f.w = 1.0f;
    this->unknown_B0 = 1;
    this->unknown_B4 = 0;

    this->unknown_B8 =
        (int)(mgDistVector((f32 *)&this->pos, (f32 *)&this->target) / 800.0f) + 1;
    if (this->unknown_B8 > 99) {
        this->unknown_B8 = 99;
    }

    if (RedMarkModel != NULL) {
        memcpy(this->unknown_C0, RedMarkModel, 0x90);
    }

    this->unknown_24 = arg;
    this->InitStatusSprite();
    this->unknown_28 = 1;
}
