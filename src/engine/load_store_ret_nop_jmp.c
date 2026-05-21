/**
 * Auto-split from misc_matchesA.c
 */
#include "engine/scenegraph.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004bf090 (11b)
 *   mov     eax, [g_state_00f85b38]
 *   mov     [0x00f85b34], eax
 *   ret
 */
extern unsigned int g_state_00f85b34;
extern void func_004bf0a8(void);
void LoadStoreRetNopJmp_004bf090(void) {
    g_state_00f85b34 = g_state_00f85b38;
}
