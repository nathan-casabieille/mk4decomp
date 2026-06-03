/**
 * Auto-split from misc_matchesI.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

/* @addr 0x00446380 (42b)
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   test    byte [g_xformDirtyFlags], 4
 *   jne     +0x12
 *   mov     eax, [g_baseSel]
 *   mov     ecx, [g_currentNodeIdx]
 *   mov     [eax*4 + 0x4c], ecx
 *   ret
 */
extern void BootPhaseGateBracketedInit(void);
void CallPauseDirtyScaledStore(void) {
    BootPhaseGateBracketedInit();
    if (g_framePauseFlag != 0) return;
    if ((g_xformDirtyFlags & 4) != 0) return;
    *(unsigned int *)(g_baseSel * 4 + 0x4c) = g_currentNodeIdx;
}
