/* Les deux rappels que `sceMpegCreate` (0x0010DF28) installe par défaut pour
 * suspendre et reprendre le DMA autour du décodage. Il les range dans la zone
 * de travail, en 0x1C et 0x24, et c'est le descripteur qu'ils reçoivent.
 *
 * L'unité est une contribution d'objet entière, bornée par les symboles de
 * section : de 0x0010F4C0 à 0x0010F4E0, deux fonctions de douze octets.
 */

#include "common.h"
#include "mpeg.hpp"

/* Les deux symboles ne portent pas de mangling : le C++ les nommerait par leur
 * signature, et l'éditeur de liens attend le nom que le binaire porte. */
extern "C" {
void _defStopDMA(sceMpeg *mpeg);
void _defRestartDMA(sceMpeg *mpeg);
}

/* Le paramètre est réaffecté plutôt que doublé d'une variable locale : le
 * commerce enchaîne les deux calculs dans `$a0`, et le compilateur ne réemploie
 * cette case que là où la source y écrit. Un pointeur local, même mort aussitôt,
 * lui fait choisir `$v0` et l'appariement retombe à 96,67 %. Les transtypages
 * sont le prix de cette forme ; le type du paramètre reste celui que
 * `sceMpegCreate` montre. */
void _defStopDMA(sceMpeg *mpeg) {
    mpeg = (sceMpeg *)mpeg->work;
    sceIpuStopDMA(&((sceMpegWork *)mpeg)->dma);
}

void _defRestartDMA(sceMpeg *mpeg) {
    mpeg = (sceMpeg *)mpeg->work;
    sceIpuRestartDMA(&((sceMpegWork *)mpeg)->dma);
}
