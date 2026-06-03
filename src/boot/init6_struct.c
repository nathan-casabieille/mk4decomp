/**
 * Auto-split from misc_matchesE.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

/* @addr 0x00404e20 (41b): zero a struct of various sizes
 *   xor     eax, eax
 *   mov     [0x00ab4e50], eax
 *   mov     [0x00ab4e54], eax
 *   mov     [0x00ab4e58], eax
 *   mov     eax, 0x8000
 *   mov     [0x00ab4e44], ax
 *   mov     [0x00ab4e48], ax
 *   mov     [0x00ab4e4c], ax
 *   ret
 */
extern unsigned int g_pointColorR;
extern unsigned int g_pointColorG;
extern unsigned int g_pointColorB;
extern unsigned int g_pointPosX;
extern unsigned int g_pointPosY;
extern unsigned int g_pointPosZ;
void Init6Struct(void) {
    g_pointPosX = 0;
    g_pointPosY = 0;
    g_pointPosZ = 0;
    *(unsigned short *)&g_pointColorR = 0x8000;
    *(unsigned short *)&g_pointColorG = 0x8000;
    *(unsigned short *)&g_pointColorB = 0x8000;
}
