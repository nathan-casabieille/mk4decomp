/**
 * Auto-split from misc_matchesA.c
 */
#include "engine/scenegraph.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

/* @addr 0x004bcc50 (24b)
 *   xor     eax, eax
 *   mov     word ptr [0x00ab47fc], 0x1000
 *   mov     word ptr [0x00ab47f8], ax
 *   mov     word ptr [0x00ab47fa], ax
 *   ret
 */
extern unsigned short g_camRotZBam;
extern unsigned short g_camRotXBam;
extern unsigned short g_camRotYBam;
void Init16BitFields(void) {
    g_camRotZBam = 0x1000;
    g_camRotXBam = 0;
    g_camRotYBam = 0;
}
