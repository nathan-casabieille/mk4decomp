/**
 * Auto-split from misc_matchesI.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00446380 (42b)
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   test    byte [g_xformDirtyFlags], 4
 *   jne     +0x12
 *   mov     eax, [g_baseSel_00542060]
 *   mov     ecx, [g_scaledInit_00542044]
 *   mov     [eax*4 + 0x4c], ecx
 *   ret
 */
extern void BootPhaseGateBracketedInit_004060c0(void);
void CallPauseDirtyScaledStore_00446380(void) {
    BootPhaseGateBracketedInit_004060c0();
    if (g_framePauseFlag != 0) return;
    if ((g_xformDirtyFlags & 4) != 0) return;
    *(unsigned int *)(g_baseSel_00542060 * 4 + 0x4c) = g_scaledInit_00542044;
}
