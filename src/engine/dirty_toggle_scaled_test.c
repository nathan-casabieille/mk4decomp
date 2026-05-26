/**
 * Auto-split from misc_matchesV.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;
extern unsigned int g_acc_00542078;

/* @addr 0x0043a630 (58b)
 *   mov     eax, [g_scaledInit_00542044]
 *   mov     edx, [g_xformDirtyFlags]
 *   mov     ecx, 4
 *   mov     eax, [eax*4 + 0]
 *   or      edx, ecx
 *   test    eax, eax
 *   mov     [g_scaledInit_00542044], eax
 *   mov     [g_xformDirtyFlags], edx
 *   je      +0x11
 *   xor     edx, ecx
 *   test    eax, eax
 *   mov     [g_xformDirtyFlags], edx
 *   je      +5
 *   jmp     +7
 *   ret
 */
extern void QuadFieldEarlyJmpThenInstall_0043a670(void);
void DirtyToggleScaledTest_0043a630(void) {
    unsigned int s = *(unsigned int *)(g_scaledInit_00542044 * 4);
    g_scaledInit_00542044 = s;
    g_xformDirtyFlags = g_xformDirtyFlags | 4;
    if (s != 0) {
        g_xformDirtyFlags = g_xformDirtyFlags ^ 4;
    }
    if (s != 0) {
        QuadFieldEarlyJmpThenInstall_0043a670();
    }
}
