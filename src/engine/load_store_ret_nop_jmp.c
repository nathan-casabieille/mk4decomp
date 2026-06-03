/**
 * Auto-split from misc_matchesA.c
 */
#include "engine/scenegraph.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

/* @addr 0x004bf090 (11b)
 *   mov     eax, [g_dispatchSave1401]
 *   mov     [0x00f85b34], eax
 *   ret
 */
extern unsigned int g_dispatchSave1400;
extern unsigned int g_dispatchSave1401;
extern void AddStore(void);
void LoadStoreRetNopJmp(void) {
    g_dispatchSave1400 = g_dispatchSave1401;
}
