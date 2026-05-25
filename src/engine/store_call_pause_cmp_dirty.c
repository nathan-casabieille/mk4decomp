/**
 * Auto-split from misc_matchesV.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;
extern u32 g_eventQueueWorkType;
extern unsigned int g_acc_00542078;
extern packed_ptr g_xformEntityIdx;

/* @addr 0x00464240 (60b)
 *   mov     eax, [0x0053a3c0]
 *   mov     [g_eventQueueCurrent], eax
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     +0x23
 *   mov     ecx, [g_eventQueueCurrent]
 *   mov     eax, [g_walkCallback]
 *   cmp     ecx, eax
 *   mov     eax, [g_xformDirtyFlags]
 *   jbe     +8
 *   or      al, 1
 *   mov     [g_xformDirtyFlags], eax
 *   ret
 *   and     al, 0xfe
 *   mov     [g_xformDirtyFlags], eax
 *   ret
 */
extern unsigned int g_stateCountdown_0053a3c0;
extern void func_00463ec0(void);
void StoreCallPauseCmpDirty_00464240(void) {
    g_eventQueueCurrent = g_stateCountdown_0053a3c0;
    func_00463ec0();
    if (g_framePauseFlag != 0) return;
    if (g_eventQueueCurrent > (unsigned int)g_walkCallback) {
        g_xformDirtyFlags = g_xformDirtyFlags | 1;
        return;
    }
    g_xformDirtyFlags = g_xformDirtyFlags & 0xFFFFFFFEu;
}
