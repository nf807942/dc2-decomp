/* CDngFloorManager — les étages d'un donjon.
 *
 * Unité bornée aux deux surcharges de `GetSphedaPrize` : la classe est
 * entrecoupée par onze fonctions d'ailleurs, donc sa plage entière porterait
 * plusieurs unités de traduction.
 */

#include "common.h"
#include "dngfloormanager.hpp"

/* L'entrée de l'étage demandé, cherchée parmi celles que le fichier a
 * chargées. Une entrée ne compte que si son genre vaut un.
 *
 * L'entrée courante est tenue à part de l'indice : le compilateur en fait un
 * pointeur qu'il rétablit à chaque tour depuis le décalage, et recalcule
 * l'adresse une seconde fois pour la rendre. */
DngMapFloorGlidInfo *CDngFloorManager::GetDngMapFloorGlidInfo(int floor) {
    int i;
    /* L'indice est mis à zéro dans la condition même : le compilateur le tient
     * alors pour disponible avant le branchement et le loge dans son créneau de
     * délai, là où une initialisation placée après lui coûte un `nop`. */
    if (this->table == NULL || (i = 0, this->count) <= 0) {
        return NULL;
    }
    for (; i < this->count; i++) {
        if (this->table[i].kind == 1 && floor == this->table[i].info.floor) {
            return &this->table[i];
        }
    }
    return NULL;
}

/* L'étage porte-t-il une géo-pierre ? L'étage absent en est dépourvu. */
int CDngFloorManager::IsGeoStone(int floor) {
    DngMapFloorInfo *info = GetDngMapFloorInfo(floor);
    if (info != NULL) {
        return info->geoStone;
    }
    return 0;
}

/* Le prix de Spheda d'un étage, et le nombre de coups qu'il accorde. L'étage
 * en porte trois de chaque ; un indice au-delà retombe sur le dernier, et un
 * indice négatif est refusé. Chacune des deux sorties est facultative. */
int CDngFloorManager::GetSphedaPrize(int floor, int index, int *prize, int *count) {
    DngMapFloorInfo *info = GetDngMapFloorInfo(floor);
    if (info == NULL) {
        return 0;
    }
    if (index < 0) {
        return 0;
    }
    if (index >= 3) {
        index = 2;
    }
    if (prize != NULL) {
        *prize = info->sphedaPrize[index];
    }
    if (count != NULL) {
        *count = info->sphedaCount[index];
    }
    return 1;
}

/* Le prix de Spheda pour l'étage où la partie en cours se trouve. La surcharge
 * qui prend l'étage fait le reste ; celle-ci ne résout que l'étage. */
int CDngFloorManager::GetSphedaPrize(int index, int *prize, int *count) {
    CSaveDataDungeon *dungeon = menu_GetSaveDataDungeon();
    if (dungeon == NULL) {
        return 0;
    }
    return GetSphedaPrize(dungeon->floors[dungeon->current], index, prize, count);
}

/* Les sous-jeux que l'étage courant propose, en un masque de deux bits. */
int CDngFloorManager::IsPlaySubGame() {
    int games = 0;
    DngMapFloorInfo *info = GetActiveFloorInfo();
    if (info == NULL) {
        return 0;
    }
    if (info->subGame1 != 0) {
        games |= 2;
    }
    if (info->subGame0 != 0) {
        games |= 1;
    }
    return games;
}


/* Ce qui scelle un étage, une fois pris en compte ce que la partie a déjà
 * ouvert et qui l'accompagne. Un étage négatif désigne celui où l'on se
 * trouve. */
int CDngFloorManager::IsSealFloor(int floor) {
    CSaveDataDungeon *dungeon = menu_GetSaveDataDungeon();
    if (dungeon == NULL) {
        return 0;
    }
    if (floor < 0) {
        floor = dungeon->floors[dungeon->current];
    }
    DngMapFloorInfo *info = GetDngMapFloorInfo(floor);
    if (info == NULL) {
        return 0;
    }
    DngFloorSaveInfo *saved = dungeon->GetFloorInfoPtr(dungeon->current, floor);
    int seal = info->seal;
    if (saved != NULL && (saved->flags & DNG_FLOOR_SEAL_OPENED)) {
        seal = 0;
    }

    CUserDataManager *user = GetUserDataMan();
    if (user != NULL) {
        int members = user->GetNowPartyMember();
        if (seal == 1 && !(members & 2)) {
            seal = 0;
        }
        if (seal == 2 && !(members & 1)) {
            seal = 0;
        }
    }
    return seal;
}


/* L'étage vient-il d'être vaincu au plus vite ? Le temps mis est comparé à
 * l'objectif de l'étage la première fois, au meilleur temps ensuite ; un
 * premier succès vaut une médaille. Rend 1 pour l'objectif battu, 2 pour un
 * record, 0 sinon. */
int CDngFloorManager::IsClearMostFastDestroy() {
    CBattleAreaScene *scene = menu_GetBattleAreaScene();
    CSaveData *save = GetSaveData();
    CSaveDataDungeon *dungeon = &save->dungeon;
    if (dungeon == NULL || scene == NULL) {
        return 0;
    }
    int floor = dungeon->floors[dungeon->current];
    DngMapFloorInfo *info = GetDngMapFloorInfo(floor);
    DngFloorSaveInfo *saved = dungeon->GetFloorInfoPtr(dungeon->current, floor);
    if (info == NULL || saved == NULL) {
        return 0;
    }

    int elapsed = (save->now - scene->startTime) * 6 / 5;
    int result = 0;
    if (saved->bestTime == 0) {
        if (elapsed < info->targetTime) {
            saved->bestTime = elapsed;
            result = 1;
            GetUserDataMan()->AddYarikomiMedal(result);
            saved->flags |= 0x10;
        }
    } else if (elapsed < saved->bestTime) {
        saved->bestTime = elapsed;
        result = 2;
    }
    return result;
}


/* Les trois tables que la condition d'entraînement consulte. Elles vivent en
 * `.data` de l'unité d'origine, donc sans qualificatif de constance, et leur
 * contenu reste dans le désassemblage : seule leur forme est déduite, des
 * tailles que la table des symboles donne et des décalages que le code lit.
 *
 * `diff_conditiontable_1102` fait 0xE octets, soit deux lignes de sept — une
 * par difficulté, une colonne par genre de condition. `check_bittable_1123`
 * fait 0x24, soit trois lignes de six demi-mots, et `cbit_1158` 0x28, soit
 * quatre lignes de cinq. */
extern s8 diff_conditiontable_1102[2][7];
extern u16 check_bittable_1123[3][6];
extern u16 cbit_1158[4][5];

/* L'étage porte-t-il une condition d'entraînement, et vient-elle d'être
 * remplie ? La condition tient en un genre — de 0 à 6, qui choisit l'épreuve —
 * et un paramètre, et la difficulté demandée dit lesquels comptent.
 *
 * Rend 2 quand la condition est remplie pour la première fois, 3 quand elle
 * l'était déjà, 1 pour le seul genre 5 qui distingue son échec, 0 sinon. Une
 * première réussite vaut une médaille. */
int CDngFloorManager::IsClearPractice(int difficulty) {
    CSaveDataDungeon *dungeon = menu_GetSaveDataDungeon();
    CBattleAreaScene *scene = menu_GetBattleAreaScene();
    int floor = dungeon->floors[dungeon->current];
    DngMapFloorInfo *info = GetDngMapFloorInfo(floor);
    DngFloorSaveInfo *saved = dungeon->GetFloorInfoPtr(dungeon->current, floor);
    if (info == NULL || saved == NULL || scene == NULL) {
        return 0;
    }

    /* L'ordre de ces déclarations décide des registres : MWCC attribue dans cet
     * ordre, non par usage. Il est mesuré, non choisi — 120 ordres éprouvés sur
     * les cinq premières, et six places pour `r`.
     *
     * Chaque boucle porte son propre compteur. Un seul, réutilisé, échange le
     * compteur et le décalage d'octets que la réduction de force en tire : le
     * commerce tient le premier en `a4` et le second en `a5`, et l'inverse coûte
     * dix-huit instructions. */
    int result;
    int mask;
    int found;
    int kind;
    int active;
    int r;
    int i;
    int j;
    int k;
    int l;
    int m;

    kind = info->practiceKind;
    if (kind < 0) {
        return 0;
    }
    active = scene->unknown_5C;
    result = 0;
    if (diff_conditiontable_1102[difficulty][kind] == 0) {
        return 0;
    }

    mask = scene->unknown_98;

    /* Une boucle de sept tours, sans corps, que le commerce émet bel et bien :
     * incrémentation, comparaison, quatre créneaux vides, branchement. Ce que ce
     * compte servait à l'origine ne se lit plus dans le binaire.
     *
     * L'incrémentation est dans la condition parce que c'est la seule forme que
     * ce compilateur garde : écrite `for (j = 0; j < 7; j++) {}`, la boucle
     * disparaît entièrement, et une trentaine de formes de corps mort n'y
     * changent rien. Seuls le test `!=` et l'incrémentation portée dans la
     * condition la retiennent, et cette dernière seule laisse le `slti` signé
     * que le commerce porte. */
    j = 0;
    while (++j < 7) {
    }

    switch (kind) {
    case 0:
        if (active != 0) {
            if (scene->unknown_10 < info->practiceParam) {
                result = 2;
            }
        }
        break;
    case 1:
    case 2:
    case 3:
    case 4:
        if (active != 0) {
            found = 0;
            if (kind == 1) {
                for (i = 0; i < 6; i++) {
                    if (mask & check_bittable_1123[0][i]) {
                        found = 1;
                    }
                }
            }
            if (kind == 3) {
                for (k = 0; k < 6; k++) {
                    if (mask & check_bittable_1123[1][k]) {
                        found = 1;
                    }
                }
            }
            if (kind == 4) {
                for (l = 0; l < 6; l++) {
                    if (mask & check_bittable_1123[2][l]) {
                        found = 1;
                    }
                }
            }
            if (kind == 2) {
                if ((mask & 0x1) || (mask & 0x20) || (mask & 0x40)) {
                    found = 1;
                } else {
                    /* L'indice de ligne se matérialise avant l'accès : le
                     * commerce garde `practiceParam - 1` dans un registre et
                     * l'emploie deux fois, là où l'indexation directe replie le
                     * calcul dans l'adresse. */
                    r = info->practiceParam - 1;
                    for (m = 0; m < 5; m++) {
                        if (mask & cbit_1158[r][m]) {
                            found = 1;
                        }
                    }
                }
            }
            if ((mask & (1 << info->practiceParam)) && found == 0) {
                result = 2;
            }
        }
        break;
    case 5:
        result = 2;
        if (mask & 0x80) {
            result = 1;
        }
        break;
    case 6:
        break;
    }

    if (result == 2) {
        if (saved->flags & DNG_FLOOR_PRACTICE_DONE) {
            result = 3;
        }
    }
    if (result == 2 || result == 3) {
        saved->flags |= DNG_FLOOR_PRACTICE_DONE;
    }
    if (result == 2) {
        GetUserDataMan()->AddYarikomiMedal(1);
    }
    return result;
}
