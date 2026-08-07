/* CGamePad — la manette, telle que le jeu la voit.
 *
 * Première unité reconstruite. Les fonctions encore intactes gardent les
 * instructions du disque, que mwccgap greffe dans cet objet ; elles sont
 * données dans l'ordre des adresses, celui que l'éditeur de liens attend.
 */

#include "common.h"
#include "gamepad.hpp"

/* Les données de l'unité restent en assembleur tant que sa `rodata` et sa
 * `sdata` n'y sont pas passées : les nommer ici les placerait ailleurs, et le
 * binaire n'y survivrait pas. Elles portent le nom que le désassemblage leur
 * donne — un numéro pour un littéral, un numéro accolé pour une statique. */
extern "C" {
extern s16 rpad_256;
extern s8 init_257;
extern s32 cnt_374;
extern s8 init_375;
extern char _248[];
extern u8 pad_dma_buf[];
extern u8 pad_dma_buf2[];
}

/* Ouvre les deux ports et remet tout à zéro. La boucle d'attente sur
 * `sceGsSyncV` laisse au SDK le temps de s'établir avant l'initialisation. */
void CGamePad::Init() {
    int i;
    int j;

    m_unk45C = 0;
    m_muteSecond = 0;
    m_vibration = 1;
    m_vibTime = 0;
    m_unk470 = 0;
    m_unk474 = 0;
    while (sceGsSyncV(0) == 0) {
    }
    scePadInit(0);

    m_unk134[0] = 0;
    m_unk134[1] = 0;
    m_unk134[2] = 0;
    m_unk134[3] = 0;
    for (i = 0; i < 2; i++) {
        m_pad[i].phase = 0;
        m_pad[i].btns = 0;
        m_pad[i].ry = 0;
        m_pad[i].rx = 0;
        m_pad[i].ly = 0;
        m_pad[i].lx = 0;
        /* L'indice du port sert aussi d'indice d'actionneur : pour le port 1,
         * la remise à zéro tombe donc sur le second minuteur et non sur le
         * premier. C'est ce que le binaire fait, et `Step` décompte pourtant
         * les deux. */
        for (j = 0; j < 6; j++) {
            m_pad[i].act[j] = 0;
            m_pad[i].actTime[i] = 0;
        }
        m_stickRange[i] = 0;
        m_repeat[i].down = 0;
        m_repeat[i].repeat = 0;
        for (j = 0; j < 32; j++) {
            m_repeat[i].wait[j] = 0;
            m_repeat[i].count[j] = 0;
            m_repeat[i].period[j] = 0;
        }
    }

    if (scePadPortOpen(0, 0, pad_dma_buf) == 0) {
        printf(_248);
        return;
    }
    sceGsSyncV(0);
    sceGsSyncV(0);
    if (scePadPortOpen(1, 0, pad_dma_buf2) == 0) {
        printf(_248);
        return;
    }
    sceGsSyncV(0);
    sceGsSyncV(0);
}

void CGamePad::Close() {
    scePadPortClose(0, 0);
    scePadPortClose(1, 0);
    scePadEnd();
}

/* Une lecture du port. Le SDK rend trente-deux octets : le premier dit si la
 * trame est valide, le deuxième porte le type de contrôleur dans ses quatre
 * bits hauts, les deux suivants les boutons — actifs à zéro, donc inversés —
 * et les quatre derniers les courses de manche. */
int pad_button_read(PAD_STATUS *pad, int port, int slot) {
    u8 rdata[PAD_RDATA_SIZE];
    int term;
    int btns;

    /* Le compte est mis à zéro avant la lecture : le commerce le loge alors
     * dans un registre sauvegardé, qui survit à l'appel. */
    if (init_257 == 0) {
        rpad_256 = 0;
        init_257 = 1;
    }
    term = 0;
    if (scePadRead(port, slot, rdata) == 0) {
        return 0;
    }
    if (rdata[0] == 0) {
        /* Le complément est séparé de son opérande : le commerce l'écrit
         * `xori`, là où la forme en une expression loge la constante dans
         * un registre. */
        btns = ((rdata[2] << 8) | rdata[3]);
        btns = btns ^ 0xFFFF;
        pad->btns = btns & 0xFFFF;
        pad->rx = rdata[4];
        pad->ry = rdata[5];
        pad->lx = rdata[6];
        pad->ly = rdata[7];
        rpad_256 = btns;
        term = rdata[1] >> 4;
    }
    return term;
}

/* La négociation d'un port, menée une étape par trame. Une manette numérique
 * (identifiant 4) passe en mode analogique, une DualShock (7) reçoit en plus
 * l'alignement de ses actionneurs ; tout autre identifiant mène à 99, l'étape
 * dont on ne sort plus. Rend 1 quand la lecture de la trame a abouti. */
int read_pad(PAD_STATUS *pad, int port, int slot) {
    int ok;
    int id;
    /* Les champs de l'état sont pris par leur adresse : le commerce les tient
     * dans des registres sauvegardés pendant toute la négociation, là où un
     * accès par `pad->` reforme l'offset après chaque appel. */
    int *phase = &pad->phase;
    int *state = &pad->state;
    int *mode = &pad->mode;
    int *term = &pad->term;
    int *lastTerm = &pad->lastTerm;

    *state = scePadGetState(port, slot);
    if (*state == 0) {
        *phase = 0;
    }
    ok = 0;
    switch (*phase) {
    case 0:
        if (*state == scePadStateStable || *state == scePadStateFindCTP1) {
            id = scePadInfoMode(port, slot, 1, 0);
            if (id != 0) {
                *mode = scePadInfoMode(port, slot, 2, 0);
                if (*mode > 0) {
                    id = *mode;
                }
                /* Les identifiants sont énumérés un à un, y compris ceux
                 * qui mènent tous à la même étape : c'est ce que le binaire
                 * compare, dans cet ordre. */
                switch (id) {
                case 2:
                    *phase = 99;
                    break;
                case 3:
                    *phase = 99;
                    break;
                case 4:
                    *phase = 40;
                    break;
                case 5:
                    *phase = 99;
                    break;
                case 6:
                    *phase = 99;
                    break;
                case 7:
                    *phase = 70;
                    break;
                case 0x100:
                    *phase = 99;
                    break;
                case 0x300:
                    *phase = 99;
                    break;
                default:
                    *phase = 99;
                    break;
                }
            }
        }
        break;
    case 40:
        if (scePadInfoMode(port, slot, 2, 0) == 0) {
            *phase = 99;
            break;
        }
        (*phase)++;
        /* L'étape suivante s'enchaîne dans la même trame. */
    case 41:
        if (scePadSetMainMode(port, slot, 1, 3) == 1) {
            (*phase)++;
        }
        break;
    case 42:
        if (scePadGetState(port, slot) != 5) {
            *phase = 0;
        }
        break;
    case 70:
        if (scePadInfoAct(port, slot, -1, 0) == 0) {
            *phase = 99;
        }
        pad->align[0] = 0;
        pad->align[1] = 1;
        pad->align[2] = 0xFF;
        pad->align[3] = 0xFF;
        pad->align[4] = 0xFF;
        pad->align[5] = 0xFF;
        if (scePadSetActAlign(port, slot, pad->align) != 0) {
            (*phase)++;
        }
        break;
    case 71:
        if (scePadGetState(port, slot) != 5) {
            *phase = 99;
        }
        break;
    default:
        if (*state == scePadStateStable || *state == scePadStateFindCTP1) {
            /* L'affectation est évaluée dans le test : le commerce garde
             * alors la valeur rendue par l'appel, et ne relit le champ que
             * pour la comparaison qui suit. */
            if ((*term = pad_button_read(pad, port, slot)) != 0) {
                if (*lastTerm != 0 && *term != *lastTerm) {
                    *lastTerm = 0;
                    *phase = 0;
                } else {
                    ok = 1;
                }
                *lastTerm = *term;
            }
        }
        break;
    }
    if (ok == 0) {
        pad->btns = 0;
        pad->ly = 128;
        pad->lx = 128;
        pad->ry = 128;
        pad->rx = 128;
    }
    /* Une manette numérique n'a pas de manche : ses courses restent au repos. */
    if (*term == 4) {
        pad->ly = 128;
        pad->lx = 128;
        pad->ry = 128;
        pad->rx = 128;
    }
    return ok;
}

/* Attend que chaque port réponde. Un port qu'aucun contrôleur n'occupe rend
 * un état nul, et l'attente cesse plutôt que de tourner sans fin. */
void CGamePad::WaitEnable() {
    sceGsSyncV(0);
    while (read_pad(&m_pad[0], 0, 0) == 0) {
        sceGsSyncV(0);
        if (scePadGetState(0, 0) == 0) {
            break;
        }
    }
    while (read_pad(&m_pad[1], 1, 0) == 0) {
        sceGsSyncV(0);
        if (scePadGetState(1, 0) == 0) {
            break;
        }
    }
}

/* La manette répond-elle ? Deux états du port valent oui : la liaison
 * établie, et le port qui vient de reconnaître un contrôleur. */
int CGamePad::Connect() {
    int state = scePadGetState(0, 0);
    if (state == scePadStateStable) {
        return 1;
    }
    return state == scePadStateFindCTP1;
}

/* La trame de la manette : l'image précédente est mise de côté, les deux ports
 * relus, puis les manches convertis en directions et les répétitions
 * automatiques appliquées. */
void CGamePad::UpDate() {
    int i;
    int j;
    int bit;
    PAD_REPEAT *rep;
    int range;

    if (init_375 == 0) {
        cnt_374 = 0;
        init_375 = 1;
    }
    m_prev[0] = m_pad[0];
    read_pad(&m_pad[0], 0, 0);
    m_prev[1] = m_pad[1];
    read_pad(&m_pad[1], 1, 0);

    switch (m_unk470) {
    case 1:
        Capture(&m_pad[0]);
        break;
    case 2:
        Play(&m_pad[0]);
        break;
    }

    /* Le manche gauche du port 0 sert aux deux entrées : c'est ce que le
     * binaire fait, `GetLX` et `GetLY` ne prenant pas de port. */
    for (i = 0; i < 2; i++) {
        range = m_stickRange[i];
        if (range < 0) {
            range = 0;
        }
        if (range > 0) {
            if (range < GetLX()) {
                m_pad[i].btns |= PAD_STICK_RIGHT;
            }
            if (GetLX() < -range) {
                m_pad[i].btns |= PAD_STICK_LEFT;
            }
            if (range < GetLY()) {
                m_pad[i].btns |= PAD_STICK_DOWN;
            }
            if (GetLY() < -range) {
                m_pad[i].btns |= PAD_STICK_UP;
            }
        }
    }

    /* Le bloc de répétition est pris par son adresse : le commerce le tient
     * pendant toute la boucle intérieure, là où un accès par `m_repeat[…]`
     * reforme l'offset à chaque tour. Le compteur extérieur est `j` et
     * l'intérieur `i` : c'est ce qui leur donne les registres du commerce, et
     * l'inverse plafonne à 99,87 %. Mesuré sur les 120 ordres de déclaration et
     * sept structures de boucle — seul ce couple apparie. */
    for (j = 0; j < 2; j++) {
        bit = 1;
        rep = &m_repeat[j];
        for (i = 0; i < 32; i++, bit *= 2) {
            if (rep->down & bit) {
                if (bit & (m_pad[j].btns & rep->down)) {
                    rep->wait[i]++;
                    if (rep->wait[i] >= rep->period[i]) {
                        rep->repeat |= bit;
                    }
                } else {
                    rep->wait[i] = 0;
                    rep->repeat &= ~bit;
                }
                if (rep->wait[i] >= rep->count[i] && (rep->repeat & bit)) {
                    m_pad[j].btns &= ~bit;
                    rep->wait[i] = 0;
                }
            }
        }
    }

    /* Deux directions opposées à la fois n'en font aucune. */
    for (i = 0; i < 2; i++) {
        if ((m_pad[i].btns & PAD_STICK_UP) && (m_pad[i].btns & PAD_STICK_DOWN)) {
            m_pad[i].btns &= ~(PAD_STICK_UP | PAD_STICK_DOWN);
        }
        if ((m_pad[i].btns & PAD_STICK_RIGHT) && (m_pad[i].btns & PAD_STICK_LEFT)) {
            m_pad[i].btns &= ~(PAD_STICK_RIGHT | PAD_STICK_LEFT);
        }
    }

    if (m_muteSecond != 0) {
        m_pad[1].btns = 0;
        m_pad[1].rx = 128;
        m_pad[1].ry = 128;
        m_pad[1].lx = 128;
        m_pad[1].ly = 128;
        m_prev[1].btns = 0;
        m_prev[1].rx = 128;
        m_prev[1].ry = 128;
        m_prev[1].lx = 128;
        m_prev[1].ly = 128;
    }
    /* Le `!` fait écrire au commerce `sltu; xori; andi`, où la forme `== 0`
     * produit un `xor` redondant suivi d'un `sltiu`. Mesuré sur quatre formes. */
    cnt_374 = !cnt_374;
    SwitchGamePadThread();
}

/* Décompte les vibrations. Passé une seconde sans qu'on les relance, tout
 * s'arrête ; sinon chaque actionneur voit son minuteur diminuer du temps
 * écoulé, et se tait quand il l'épuise. */
void CGamePad::Step(int elapsed) {
    int i;

    m_vibTime += elapsed;
    if (m_vibTime > 1000) {
        m_vibTime = 0;
        StopVibration();
        return;
    }
    for (i = 0; i < 1; i++) {
        if (m_vibration == 0) {
            m_pad[i].act[0] = 0;
            m_pad[i].act[1] = 0;
        }
        if (m_pad[i].actTime[0] > 0) {
            m_pad[i].actTime[0] -= elapsed;
        } else {
            m_pad[i].actTime[0] = 0;
            m_pad[i].act[0] = 0;
        }
        if (m_pad[i].actTime[1] > 0) {
            m_pad[i].actTime[1] -= elapsed;
        } else {
            m_pad[i].actTime[1] = 0;
            m_pad[i].act[1] = 0;
        }
    }
    scePadSetActDirect(0, 0, m_pad[0].act);
}

/* Centre la course : 128 est le point mort, et la zone morte qui l'entoure
 * n'est pas symétrique — 50 crans d'un côté, 49 de l'autre. Ce qui reste est
 * ramené sur toute la course par un facteur 128/78. */
int AxisCalibration(int value) {
    int low, high;

    /* La course est reprise dans une locale, et chaque correction re-prend la
     * course avant d'appliquer son décalage. Modifier le paramètre
     * (`value -= 128`) et calculer les corrections d'un coup (`high = value
     * - 49`) déplace l'allocation des registres et descend l'appariement :
     * c'est la forme trouvée par le permuteur, qui a escaladé 89,56 % → 89,69 %
     * → 95,56 % → 100 % sur cette seule fonction. */
    int course = value - 128;
    if (course < 50 && course > -50) {
        return 0;
    }
    high = course;
    high = high - 49;
    low = course;
    low = low + 50;
    if (course >= 1) {
        return (high << 7) / 78;
    }
    return (low << 7) / 78;
}

int CGamePad::GetRX() {
    return AxisCalibration(m_pad[0].rx);
}
int CGamePad::GetRY() {
    return AxisCalibration(m_pad[0].ry);
}
int CGamePad::GetLX() {
    return AxisCalibration(m_pad[0].lx);
}
int CGamePad::GetLY() {
    return AxisCalibration(m_pad[0].ly);
}
int CGamePad::GetRX2() {
    return AxisCalibration(m_pad[1].rx);
}

/* Oublie la répétition automatique des boutons que le masque désigne. */
void CGamePad::CancelAutoRepeat(int mask) {
    int i;
    int bit;
    /* Le bloc est pris une fois dans un pointeur, et le compteur declare avant
     * lui : le commerce garde l'adresse pendant toute la boucle et reprend le
     * registre de `this` pour l'indice. */
    PAD_REPEAT *rep = &m_repeat[0];
    bit = 1;
    for (i = 0; i < 32; i++, bit *= 2) {
        if (mask & bit) {
            rep->down &= ~bit;
            rep->repeat &= ~bit;
            rep->wait[i] = 0;
            rep->period[i] = 0;
            rep->count[i] = 0;
        }
    }
}
