/**
 * Auto-split from misc_matchesA.c
 */
#include "engine/scenegraph.h"

extern unsigned int g_baseSel;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004bf0b0 (16b)
 *   mov     eax, [g_dispatchSave1401]
 *   add     eax, 0x00200000
 *   mov     [0x00f4d028], eax
 *   ret
 */
extern unsigned int g_dispatchSave1401;
extern unsigned int g_dispatchSave1340;
void AddStore(void) {
    g_dispatchSave1340 = g_dispatchSave1401 + 0x00200000;
}
