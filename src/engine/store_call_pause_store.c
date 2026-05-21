/**
 * Auto-split from misc_matchesJ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x0048b450 (37b)
 *   mov     eax, [g_eventQueueChild]
 *   mov     [g_eventQueueWorkType], eax
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   mov     ecx, [g_acc_00542078]
 *   mov     [g_currentNodeFlags], ecx
 *   ret
 */
extern unsigned int g_acc_00542078;
extern void func_0048b606(void);
void StoreCallPauseStore_0048b450(void) {
    g_eventQueueWorkType = g_eventQueueChild;
    func_0048b606();
    if (g_framePauseFlag != 0) return;
    g_currentNodeFlags = g_acc_00542078;
}
