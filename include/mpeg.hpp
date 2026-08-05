#ifndef MPEG_HPP
#define MPEG_HPP

#include "types.h"

/* Le décodeur MPEG du SDK, dans ce que l'unité `mpegdma` en emploie.
 *
 * Les structures ne sont décrites que jusqu'aux champs que cette unité
 * atteint : le reste de la disposition viendra des fonctions voisines quand
 * elles s'ouvriront. */

/* Ce que `sceIpuStopDMA` (0x0010F5B0) met de côté, dans l'ordre où il l'écrit.
 * Chaque champ porte l'adresse du registre relevée dans son désassemblage ;
 * les canaux 3 et 4 du DMAC sont ceux qui vont de l'unité vidéo et vers elle. */
struct sceIpuDmaSave {
    u32 toIpuMadr;    /* 0x1000B410 */
    u32 toIpuTadr;    /* 0x1000B430 */
    u32 toIpuQwc;     /* 0x1000B420 */
    u32 toIpuChcr;    /* 0x1000B400 */
    u32 fromIpuMadr;  /* 0x1000B010 */
    u32 fromIpuQwc;   /* 0x1000B020 */
    u32 fromIpuChcr;  /* 0x1000B000 */
    /* Le pointeur de bit du flux, que `sceIpuRestartDMA` redonne au matériel
     * par une commande à 0x10002000 après en avoir isolé les sept bits bas. */
    u32 ipuBp;        /* 0x10002020 */
    u32 ipuCtrl;      /* 0x10002010 */
};

/* La zone de travail que `sceMpegCreate` (0x0010DF28) taille dans la mémoire
 * qu'on lui confie, et dont il refuse moins de 0x10C0 octets. */
struct sceMpegWork {
    u8 unknown_00[0x4C];
    sceIpuDmaSave dma;  /* 0x4C */
};

/* Le descripteur que l'appelant tient. `sceMpegCreate` y range la zone de
 * travail qu'il vient d'établir. */
struct sceMpeg {
    u8 unknown_00[0x40];
    sceMpegWork *work;  /* 0x40 */
};

extern "C" {
void sceIpuStopDMA(sceIpuDmaSave *save);
void sceIpuRestartDMA(sceIpuDmaSave *save);
}

#endif /* MPEG_HPP */
