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
    f32 charaPos[4];
    CCPoly polys[128];
    mgVu0FBOX box;
    f32 from[4];
    f32 to[4];
    f32 hit[4];
    CTreasureBoxManager *boxes;
    int count;
    int dngNo;
    CSaveData *save;
    f32 navi;

    DngMainScene->GetCharacter(DngMainScene->unknown_2E50)->vf18(charaPos);
    boxes = DngMainScene->unknown_300C;
    SearchMapEventParts(1, parts, dists, 0x80);

    do {
    } while (!SearchMapFlatPosition(this->pos, &AutoMapGen) ||
             !boxes->CheckArea(this->pos, 60.0f) ||
             !RandomCircle.CheckArea(this->pos, 60.0f) ||
             mgDistVector(charaPos, this->pos) < 60.0f);
    this->pos[1] += 30.0f;

    do {
    } while (!SearchMapFlatPosition(this->target, &AutoMapGen) ||
             !boxes->CheckArea(this->target, 40.0f) ||
             /* Le second tirage éprouve les cercles sur la place *déjà* posée,
              * non sur celle qu'il cherche. Le binaire le fait ainsi. */
             !RandomCircle.CheckArea(this->pos, 60.0f) ||
             mgDistVector(this->pos, this->target) < 200.0f);

    box.max[0] = 20.0f + this->target[0];
    box.min[0] = this->target[0] - 20.0f;
    box.max[1] = 20.0f + this->target[1];
    box.min[1] = this->target[1] - 20.0f;
    box.max[2] = 20.0f + this->target[2];
    box.min[2] = this->target[2] - 20.0f;
    box.max[3] = 1.0f;
    box.min[3] = 1.0f;
    /* Le vecteur se copie de son quadmot : seize octets en deux
     * instructions, `lq` puis `sq`. Le transtypage vit dans
     * l'instruction, non dans un argument, donc il ne déplace rien. */
    *(VECTOR *)from = *(VECTOR *)this->target;
    *(VECTOR *)to = *(VECTOR *)this->target;
    from[1] += 18.0f;
    to[1] -= 18.0f;
    count = DngMainScene->GetColPoly(polys, box, 0x80);
    if (CheckHit(polys, count, from, to, hit, 1, 0xC) >=
        0) {
        *(VECTOR *)this->target = *(VECTOR *)hit;
    }

    this->target[1] += 3.0f;
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
        AutoMapGen.UpdateNaviMap(this->target, 0x28);
        navi = AutoMapGen.GetNaviDistance(this->pos);
        if (navi < 0.0f) {
            this->unknown_B8 =
                (int)(mgDistVector(this->pos, this->target) /
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
            (int)(mgDistVector(this->pos, this->target) /
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

/* La mise en place d'essai : Sphida est posé à des coordonnées fixes, celles
 * du dix-septième niveau, au lieu d'être placé dans une clairière tirée au
 * hasard comme le fait `SetUp`. Tout le reste est identique — le nombre
 * d'étapes du trajet, la copie du modèle de repère, l'initialisation de la
 * vignette d'état. */
void CSphida::s17_SetUp(int arg) {
    this->pos[0] = -1.09f;
    this->pos[1] = 201.0f;
    this->pos[2] = -478.03f;
    this->pos[3] = 1.0f;
    this->target[0] = 0.0f;
    this->target[1] = 65.57f;
    this->target[2] = 1305.04f;
    this->target[3] = 1.0f;
    this->unknown_B0 = 1;
    this->unknown_B4 = 0;

    this->unknown_B8 =
        (int)(mgDistVector(this->pos, this->target) / 800.0f) + 1;
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
