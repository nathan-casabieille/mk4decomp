/**
 * Auto-split from misc_matches9.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00439b80 (30b)
 *   mov     eax, [g_state]
 *   test    eax, eax
 *   mov     [g_walkCallback], eax
 *   jne     .skip1
 *   jmp     +0x0d
 * .skip1:
 *   cmp     eax, 1
 *   jne     .skip2
 *   jmp     +3
 * .skip2:
 *   ret
 */
extern unsigned int g_counter_0053a51c;
extern void DualEntryBitGated_00439ba0(void);
extern void DualEntryBitGated_00439ba0(void);
void TwoConditionalJmp_00439b80(void) {
    unsigned int v = g_counter_0053a51c;
    g_walkCallback = (void (*)(void))v;
    if (v == 0) {
        DualEntryBitGated_00439ba0();
        return;
    }
    if (v == 1) {
        DualEntryBitGated_00439ba0();
    }
}
