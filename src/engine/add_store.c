/**
 * Auto-split from misc_matchesA.c
 */
#include "engine/scenegraph.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004bf0b0 (16b)
 *   mov     eax, [g_dispatchSave1401_00f85b38]
 *   add     eax, 0x00200000
 *   mov     [0x00f4d028], eax
 *   ret
 */
extern unsigned int g_dispatchSave1401_00f85b38;
extern unsigned int g_dispatchSave1340_00f4d028;
void AddStore_004bf0b0(void) {
    g_dispatchSave1340_00f4d028 = g_dispatchSave1401_00f85b38 + 0x00200000;
}
