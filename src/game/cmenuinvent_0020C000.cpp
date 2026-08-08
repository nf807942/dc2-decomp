/* CMenuInvent
 *
 * Unité découpée par `make carve` : 1 fonctions, 344 octets, de
 * 0x0020C000 à 0x0020C160. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"
#include "menuinvent.hpp"

/* Les noms des scripts que la fonction déclenche, en japonais dans le binaire.
 * Les littéraux restent dans le désassemblage ; seuls leurs symboles sont
 * nommés ici, sous le nom que Metrowerks leur a donné. */
extern char _5066[];  /* 左下へ — « vers le bas à gauche » */
extern char _5067[];  /* ネタ単語リストOFF — « liste de mots d'idées OFF » */
extern char _2313[];  /* 中へ — « vers le milieu » */

/* Le passage d'un mode du menu d'invention à un autre. Chaque mode a sa mise
 * en scène : le panneau de message glisse à une nouvelle place, le panneau de
 * bascule est recréé du bon côté, les positions de curseur sont recalculées.
 * Le son de menu est joué dans tous les cas, et le mode retenu à la fin.
 *
 * Le second paramètre n'est pas employé.
 *
 * Le passage au mode 2 est refusé quand le menu commun le signale : la demande
 * est alors détournée vers le mode 3. */
void CMenuInvent::NextDifferentMode(int next, int arg) {
    switch (next) {
    case 0:
    case 1:
        break;
    case 2:
        if (MenuCommonInfo->unknown_C2 > 0) {
            next = 3;
            break;
        }
        if (this->mode == 3) {
            MenuMesForm[0]->SetAction(_5066);
            this->CreateModeSwapForm(0);
        }
        break;
    case 3:
        this->CreateModeSwapForm(1);
        MenuMesForm[0]->SetAction(_2313);
        this->unknown_11C =
            (this->unknown_120 + (this->unknown_114 - this->unknown_118)) * 6;
        break;
    case 4: {
        int gap;
        this->unknown_124 = this->unknown_128 * 2;
        gap = this->unknown_12C / 2 - this->unknown_130;
        if (gap < 3) {
            gap = 0;
        } else {
            gap = gap - 2;
        }
        this->unknown_124 = this->unknown_124 + (gap * 2 + 1);
        break;
    }
    case 5:
    case 6:
    case 7:
        break;
    case 8:
        this->ExeScript(_5067);
        break;
    case 9:
        break;
    }
    MenuSePlay(0);
    this->mode = next;
}
