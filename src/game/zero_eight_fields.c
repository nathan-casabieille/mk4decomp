/**
 * Auto-split from misc_matchesM.c
 */
#include "engine/scenegraph.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

/* @addr 0x004b8f20 (43b): zero 8 fields
 *   xor     eax, eax
 *   mov     [0x00ab4d9c], eax
 *   mov     [0x00ab4da0], eax
 *   mov     [0x00ab4da4], eax
 *   mov     [0x00ab4da8], eax
 *   mov     [0x00ab4dac], eax
 *   mov     [0x00ab4db0], eax
 *   mov     [0x00ab4db4], eax
 *   mov     [0x00ab4db8], eax
 *   ret
 */
extern unsigned int g_dispatchSave1559;
extern unsigned int g_dispatchSave1560;
extern unsigned int g_dispatchSave1561;
extern unsigned int g_dispatchSave1562;
extern unsigned int g_dispatchSave1563;
extern unsigned int g_dispatchSave1564;
extern unsigned int g_dispatchSave1565;
extern unsigned int g_dispatchSave1566;
void ZeroEightFields(void) {
    g_dispatchSave1559 = 0;
    g_dispatchSave1560 = 0;
    g_dispatchSave1561 = 0;
    g_dispatchSave1562 = 0;
    g_dispatchSave1563 = 0;
    g_dispatchSave1564 = 0;
    g_dispatchSave1565 = 0;
    g_dispatchSave1566 = 0;
}
