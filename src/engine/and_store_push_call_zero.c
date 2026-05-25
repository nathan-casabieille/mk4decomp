/**
 * Auto-split from misc_matchesP.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x0048a220 (46b)
 *   mov     eax, [0x0053a7b0]
 *   and     al, 0xfd
 *   mov     [g_eventQueueCurrent], eax
 *   mov     [0x0053a7b0], eax
 *   mov     eax, [0x00541fa8]
 *   test    eax, eax
 *   je      +0x13
 *   push    eax
 *   call    F
 *   add     esp, 4
 *   mov     [0x00541fa8], 0
 *   ret
 */
extern unsigned int g_dualBitGate_0053a7b0;
extern unsigned int g_zero_00541fa8;
extern int func_004be770(void *p);
void AndStorePushCallZero_0048a220(void) {
    unsigned int v;
    void *p;
    v = g_dualBitGate_0053a7b0 & 0xFFFFFFFDu;
    g_eventQueueCurrent = v;
    g_dualBitGate_0053a7b0 = v;
    p = (void *)g_zero_00541fa8;
    if (p == 0) return;
    func_004be770(p);
    g_zero_00541fa8 = 0;
}
