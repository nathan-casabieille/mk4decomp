/**
 * Auto-split from misc_matchesN.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x0045f570 (48b)
 *   call    F
 *   mov     eax, [g_walkCallback]
 *   mov     ecx, [g_eventQueueCurrent]
 *   cmp     eax, ecx
 *   mov     eax, [g_xformDirtyFlags]
 *   je      +0x0d
 *   and     al, 0xfe
 *   mov     [g_xformDirtyFlags], eax
 *   mov     eax, 1
 *   ret
 *   or      al, 1
 *   mov     [g_xformDirtyFlags], eax
 *   xor     eax, eax
 *   ret
 */
extern void CmpP1ScaledLoad74_0045f5d0(void);
int CallCmpDirtyTrueOrFalse_0045f570(void) {
    CmpP1ScaledLoad74_0045f5d0();
    if ((unsigned int)g_walkCallback != g_eventQueueCurrent) {
        g_xformDirtyFlags = g_xformDirtyFlags & 0xFFFFFFFEu;
        return 1;
    }
    g_xformDirtyFlags = g_xformDirtyFlags | 1;
    return 0;
}

/* @addr 0x0045f5a0 (48b): same shape, swapped: jne (75) instead of je (74) */
extern void func_0045f5d0_b(void);
int CallCmpDirtyTrueOrFalse_0045f5a0(void) {
    func_0045f5d0_b();
    if ((unsigned int)g_walkCallback == g_eventQueueCurrent) {
        g_xformDirtyFlags = g_xformDirtyFlags & 0xFFFFFFFEu;
        return 1;
    }
    g_xformDirtyFlags = g_xformDirtyFlags | 1;
    return 0;
}
