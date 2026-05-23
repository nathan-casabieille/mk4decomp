/**
 * Auto-split from misc_matchesN.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00458880 (46b)
 *   mov     eax, [0x0053a278]
 *   mov     [g_acc_00542078], eax
 *   inc     eax
 *   cmp     eax, 0x28
 *   mov     [g_walkCallback], eax
 *   jl      .skip
 *   mov     [g_walkCallback], 0
 *   mov     [g_eventQueueEnd], 1
 *   jmp     T
 */
extern unsigned int g_state_0053a278;
extern unsigned int g_acc_00542078;
extern u32 g_eventQueueEnd;
extern void func_00458886(void);
void IncCmp28StoreOrJmp_00458880(void) {
    int v = (int)g_state_0053a278;
    g_acc_00542078 = (unsigned int)v;
    v++;
    g_walkCallback = (void (*)(void))v;
    if (v >= 0x28) {
        g_walkCallback = 0;
    }
    g_eventQueueEnd = 1;
    func_00458886();
}
