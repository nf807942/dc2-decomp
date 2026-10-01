/* Fonctions libres — à décrire.
 *
 * Unité découpée par `make carve` : 33 fonctions, 6292 octets, de
 * 0x00104D58 à 0x00106630. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

INCLUDE_ASM("nonmatchings/sdk/scedevconsprintf", sceDevFontDefault);
INCLUDE_ASM("nonmatchings/sdk/scedevconsprintf", sceDevFontIdle);
INCLUDE_ASM("nonmatchings/sdk/scedevconsprintf", sceDevFontSetColor);
INCLUDE_ASM("nonmatchings/sdk/scedevconsprintf", sceDevConsInit);
INCLUDE_ASM("nonmatchings/sdk/scedevconsprintf", sceDevConsOpen);
INCLUDE_ASM("nonmatchings/sdk/scedevconsprintf", sceDevConsClose);
INCLUDE_ASM("nonmatchings/sdk/scedevconsprintf", sceDevConsRef);
INCLUDE_ASM("nonmatchings/sdk/scedevconsprintf", sceDevConsDraw);
INCLUDE_ASM("nonmatchings/sdk/scedevconsprintf", sceDevConsDrawS);
INCLUDE_ASM("nonmatchings/sdk/scedevconsprintf", sceDevConsClear);
extern void sceDevFontSetColor(void *, int, int, int, int);
void sceDevConsSetColor(char *c, int r, int g, int b, int a) { sceDevFontSetColor(c + 0x18, r & 0xFF, g & 0xFF, b & 0xFF, a & 0xFF); }
INCLUDE_ASM("nonmatchings/sdk/scedevconsprintf", sceDevConsPrintf);
INCLUDE_ASM("nonmatchings/sdk/scedevconsprintf", sceDevConsLocate);
INCLUDE_ASM("nonmatchings/sdk/scedevconsprintf", sceDevConsPut);
INCLUDE_ASM("nonmatchings/sdk/scedevconsprintf", sceDevConsGet);
void sceDevConsAttribute(unsigned char *c, int a) { c[12] = a; }
INCLUDE_ASM("nonmatchings/sdk/scedevconsprintf", sceDevConsClearBox);
INCLUDE_ASM("nonmatchings/sdk/scedevconsprintf", sceDevConsMove);
INCLUDE_ASM("nonmatchings/sdk/scedevconsprintf", sceDevConsRollup);
INCLUDE_ASM("nonmatchings/sdk/scedevconsprintf", sceDevConsMessage);
INCLUDE_ASM("nonmatchings/sdk/scedevconsprintf", sceDevConsFrame);
unsigned euc2jis(unsigned c) { return (c & 0xFFFF) ^ 0x8080; }
INCLUDE_ASM("nonmatchings/sdk/scedevconsprintf", sjis2jis);
INCLUDE_ASM("nonmatchings/sdk/scedevconsprintf", sceDevFontRefDirectImage);
INCLUDE_ASM("nonmatchings/sdk/scedevconsprintf", sceDevFontRefStrN);
INCLUDE_ASM("nonmatchings/sdk/scedevconsprintf", sceDevConsPutc);
INCLUDE_ASM("nonmatchings/sdk/scedevconsprintf", sceDevConsGetc);
INCLUDE_ASM("nonmatchings/sdk/scedevconsprintf", sceDevConsPiece);
INCLUDE_ASM("nonmatchings/sdk/scedevconsprintf", sceDevFontKnj2Chr);
INCLUDE_ASM("nonmatchings/sdk/scedevconsprintf", chaGifPkOpenGifTag2);
INCLUDE_ASM("nonmatchings/sdk/scedevconsprintf", chaMemAlloc);
INCLUDE_ASM("nonmatchings/sdk/scedevconsprintf", chaMemFree);
INCLUDE_ASM("nonmatchings/sdk/scedevconsprintf", sceDevFont);
