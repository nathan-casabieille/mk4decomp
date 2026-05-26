/**
 * Auto-split from misc_matchesK.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004911c0 (42b)
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   mov     eax, [g_eventQueueChild]
 *   mov     ecx, [g_eventQueueChild]
 *   wait, that's two same loads - actually:
 *   a17c205400 = mov eax, [0x0054207c]
 *   8b0d80205400 = mov ecx, [0x00542080]
 *   a374205400 = mov [0x00542074], eax
 *   890d78205400 = mov [0x00542078], ecx
 *   jmp T
 */
extern unsigned int g_acc_00542078;
extern void ScaledChainDouble_004911f0(void);
extern void Atan2QuadrantLookup_004245b0(void);
void SwapTwoGlobals_004911c0(void) {
    unsigned int a, b;
    ScaledChainDouble_004911f0();
    if (g_framePauseFlag != 0) return;
    a = g_eventQueueNotMask;
    b = g_eventQueueChild;
    g_eventQueueWorkType = a;
    g_acc_00542078 = b;
    Atan2QuadrantLookup_004245b0();
}
