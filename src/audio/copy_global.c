/**
 * Auto-split from misc_matchesB.c
 */
#include "engine/scenegraph.h"

extern unsigned int g_scaledInit_00542044;

/* @addr 0x004ac1f0 (11b)
 *   mov     eax, [g_walkCallback]
 *   mov     [g_target_0053a6fc], eax
 *   ret
 */
extern unsigned int g_target_0053a6fc;
void CopyGlobal_004ac1f0(void) {
    g_target_0053a6fc = (unsigned int)g_walkCallback;
}
