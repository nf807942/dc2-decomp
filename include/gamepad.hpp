#ifndef GAMEPAD_HPP
#define GAMEPAD_HPP

#include "types.h"

/* Le service de manette du SDK. `scePadPortClose` prend le port et son
 * emplacement — le second vaut toujours zéro ici, le jeu n'employant pas de
 * multitap. */
extern "C" {
int scePadInit(int mode);
int scePadEnd(void);
int scePadPortOpen(int port, int slot, u8 *dma);
int scePadPortClose(int port, int slot);
int scePadGetState(int port, int slot);
int scePadRead(int port, int slot, u8 *data);
int scePadInfoMode(int port, int slot, int term, int offset);
int scePadInfoAct(int port, int slot, int actuator, int cmd);
int scePadSetMainMode(int port, int slot, int offset, int lock);
int scePadSetActAlign(int port, int slot, const u8 *align);
int scePadSetActDirect(int port, int slot, const u8 *data);
int sceGsSyncV(int mode);
int printf(const char *format, ...);
}

/* Les états qu'un port traverse. Le jeu tient la manette pour présente dans
 * deux d'entre eux : quand la liaison est établie, et quand le port a reconnu
 * un contrôleur du premier type — celui de la manette numérique. */
#define scePadStateFindCTP1 2
#define scePadStateStable   6

/* Le tampon que le SDK remplit à chaque `scePadRead` : son second octet porte
 * le type de contrôleur dans ses quatre bits hauts, ses deux suivants les
 * boutons, puis les quatre courses de manche. */
#define PAD_RDATA_SIZE 32

/* L'état d'un port, tel que l'unité le tient. Deux exemplaires se suivent dans
 * `CGamePad`, un par port, et `read_pad` mène pour chacun la négociation qui
 * fait passer une manette au mode analogique. */
struct PAD_STATUS {          /* 0x4C */
    int btns;                /* 0x00 */
    int ly;                  /* 0x04 */
    int lx;                  /* 0x08 */
    int ry;                  /* 0x0C */
    int rx;                  /* 0x10 */
    /* L'étape de la négociation. Les valeurs observées ne se suivent pas :
     * 0 ouvre, 0x28 et 0x46 mènent chacune une séquence de deux étapes, et
     * 0x63 marque celle dont on ne sort plus. */
    int phase;               /* 0x14 */
    int state;               /* 0x18 */
    int mode;                /* 0x1C */
    int term;                /* 0x20 */
    int lastTerm;            /* 0x24 */
    /* Ce que `scePadSetActDirect` envoie aux actionneurs, et l'alignement que
     * `scePadSetActAlign` leur donne. */
    u8 act[6];               /* 0x28 */
    u8 align[6];             /* 0x2E */
    /* Six mots d'un seul tenant : `UpDate` les recopie en un bloc, que le
     * compilateur déroule par quatre puis par deux. Les deux premiers sont les
     * minuteurs d'actionneur que `Step` décompte ; les quatre suivants restent
     * à établir. */
    int actTime[6];          /* 0x34 */
};

/* Les répétitions automatiques d'un port : deux masques d'un bit par bouton,
 * puis trois tables de trente-deux compteurs. */
struct PAD_REPEAT {          /* 0x188 */
    int down;                /* 0x000 */
    int repeat;              /* 0x004 */
    int wait[32];            /* 0x008 */
    int period[32];          /* 0x088 */
    int count[32];           /* 0x108 */
};

/* Centre la course d'un manche : 128 est le point mort, une zone autour est
 * morte, et la course qui reste est ramenée. Les cinq getters de `CGamePad`
 * s'en remettent à elle pour leurs quatre manches et leur seconde poussée. */
int AxisCalibration(int value);

int pad_button_read(PAD_STATUS *pad, int port, int slot);
int read_pad(PAD_STATUS *pad, int port, int slot);
void SwitchGamePadThread(void);

/* Les bits que `UpDate` ajoute aux boutons quand le manche gauche sort de son
 * amplitude. Ils tombent dans les quatre bits hauts du mot, que la manette
 * n'emploie pas. */
#define PAD_STICK_RIGHT 0x2000
#define PAD_STICK_DOWN  0x4000
#define PAD_STICK_LEFT  0x8000
#define PAD_STICK_UP    0x1000

class CGamePad {
public:
    void Init();
    void Close();
    int Connect();
    void WaitEnable();
    void UpDate();
    void Step(int elapsed);
    void StopVibration();
    void CancelAutoRepeat(int mask);
    void Capture(PAD_STATUS *pad);
    void Play(PAD_STATUS *pad);

    int GetRX();
    int GetRY();
    int GetLX();
    int GetLY();
    int GetRX2();

private:
    /* 0x000 : usage inconnu — aucune fonction de l'unité n'y touche encore. */
    int m_root;
    PAD_STATUS m_pad[2];              /* 0x004 */
    /* L'image de la trame précédente, que `UpDate` recopie avant de relire les
     * ports : c'est d'elle que se déduit un appui neuf. */
    PAD_STATUS m_prev[2];             /* 0x09C */
    int m_unk134[4];                  /* 0x134 */
    PAD_REPEAT m_repeat[2];           /* 0x144 */
    /* Au-delà de cette amplitude, le manche gauche vaut une direction : quatre
     * bits s'ajoutent alors aux boutons. Une valeur nulle laisse le manche
     * analogique seul. */
    int m_stickRange[2];              /* 0x454 */
    int m_unk45C;                     /* 0x45C */
    /* Non nul, le second port est tenu au repos quoi qu'il rende. */
    int m_muteSecond;                 /* 0x460 */
    int m_unk464;                     /* 0x464 */
    /* Mis à un par `Init`, et consulté par `Step` avant d'effacer la consigne
     * des actionneurs. */
    int m_vibration;                  /* 0x468 */
    int m_vibTime;                    /* 0x46C */
    int m_unk470;                     /* 0x470 */
    int m_unk474;                     /* 0x474 */
};

#endif /* GAMEPAD_HPP */
