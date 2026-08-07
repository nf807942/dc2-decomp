/* Fonctions libres — à décrire.
 *
 * Unité découpée par `make carve` : 8 fonctions, 3580 octets, de
 * 0x0010D080 à 0x0010DE88. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

INCLUDE_ASM("nonmatchings/sdk/pes_packet", _type2id);
INCLUDE_ASM("nonmatchings/sdk/pes_packet", _id2type);
INCLUDE_ASM("nonmatchings/sdk/pes_packet", sceMpegDemuxPssRing);
INCLUDE_ASM("nonmatchings/sdk/pes_packet", sceMpegDemuxPss);
INCLUDE_ASM("nonmatchings/sdk/pes_packet", sceMpegAddStrCallback);
INCLUDE_ASM("nonmatchings/sdk/pes_packet", _pack_header);
INCLUDE_ASM("nonmatchings/sdk/pes_packet", _system_header);
INCLUDE_ASM("nonmatchings/sdk/pes_packet", _PES_packet);
