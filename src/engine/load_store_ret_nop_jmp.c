/**
 * Auto-split from misc_matchesA.c
 */
#include "engine/scenegraph.h"

extern unsigned int g_baseSel;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004bf090 (11b)
 *   mov     eax, [g_dispatchSave1401_00f85b38]
 *   mov     [0x00f85b34], eax
 *   ret
 */
extern unsigned int g_dispatchSave1400_00f85b34;
extern unsigned int g_dispatchSave1401_00f85b38;
extern void AddStore(void);
void LoadStoreRetNopJmp(void) {
    g_dispatchSave1400_00f85b34 = g_dispatchSave1401_00f85b38;
}
