/**
 * Auto-split from misc_matchesW.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

/* @addr 0x00490030 (54b)
 *   mov     eax, [g_fightGroupHead]
 *   mov     ecx, [g_baseSel]
 *   mov     [g_currentNodeIdx], eax
 *   mov     edx, [ecx*4 + 0x38]
 *   mov     [g_fightGroupHead], edx
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     +0x0a
 *   mov     eax, [g_currentNodeIdx]
 *   mov     [g_fightGroupHead], eax
 *   ret
 */
extern void DualMaskCmpJmp(void);
void SwapCallRestore(void) {
    g_currentNodeIdx = g_fightGroupHead;
    g_fightGroupHead = *(unsigned int *)(g_baseSel * 4 + 0x38);
    DualMaskCmpJmp();
    if (g_framePauseFlag != 0) return;
    g_fightGroupHead = g_currentNodeIdx;
}
