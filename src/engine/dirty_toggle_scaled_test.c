/**
 * Auto-split from misc_matchesV.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;
extern unsigned int g_acc_00542078;

/* @addr 0x0043a630 (58b)
 *   mov     eax, [g_currentNodeIdx]
 *   mov     edx, [g_xformDirtyFlags]
 *   mov     ecx, 4
 *   mov     eax, [eax*4 + 0]
 *   or      edx, ecx
 *   test    eax, eax
 *   mov     [g_currentNodeIdx], eax
 *   mov     [g_xformDirtyFlags], edx
 *   je      +0x11
 *   xor     edx, ecx
 *   test    eax, eax
 *   mov     [g_xformDirtyFlags], edx
 *   je      +5
 *   jmp     +7
 *   ret
 */
extern void QuadFieldEarlyJmpThenInstall(void);
void DirtyToggleScaledTest(void) {
    unsigned int s = *(unsigned int *)(g_currentNodeIdx * 4);
    g_currentNodeIdx = s;
    g_xformDirtyFlags = g_xformDirtyFlags | 4;
    if (s != 0) {
        g_xformDirtyFlags = g_xformDirtyFlags ^ 4;
    }
    if (s != 0) {
        QuadFieldEarlyJmpThenInstall();
    }
}
