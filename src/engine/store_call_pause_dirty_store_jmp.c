/**
 * Auto-split from misc_matchesV.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;
extern unsigned int g_acc_00542078;

/* @addr 0x004396c0 (51b)
 *   mov     eax, [g_cj_00535df0]
 *   mov     [g_eventQueueIdx], eax
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     +0x1a
 *   test    byte [g_xformDirtyFlags], 1
 *   jne     +0x11
 *   mov     ecx, [g_state_0053a2c0]
 *   mov     [g_eventQueueIdx], ecx
 *   jmp     +0x0e
 *   ret
 */
extern unsigned int g_cj_00535df0;
extern unsigned int g_state_0053a2c0;
extern void func_004396f1(void);
extern void func_004396ff(void);
void StoreCallPauseDirtyStoreJmp_004396c0(void) {
    g_eventQueueIdx = g_cj_00535df0;
    func_004396f1();
    if (g_framePauseFlag != 0) return;
    if ((g_xformDirtyFlags & 1) != 0) return;
    g_eventQueueIdx = g_state_0053a2c0;
    func_004396ff();
}
