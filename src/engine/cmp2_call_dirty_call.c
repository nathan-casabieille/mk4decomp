/**
 * Auto-split from misc_matchesV.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;
extern unsigned int g_acc_00542078;

/* @addr 0x004398b0 (54b)
 *   mov     eax, [0x0052aac4]
 *   cmp     eax, 2
 *   mov     [g_walkCallback], eax
 *   jne     +0x0b
 *   call    F1
 *   mov     eax, 1
 *   ret
 *   call    F2
 *   test    byte [g_xformDirtyFlags], 1
 *   jne     +0x0b
 *   call    F3
 *   mov     eax, 1
 *   ret
 *   xor     eax, eax
 *   ret
 */
extern unsigned int g_tickFlagF;
extern void Thunk_004399b0(void);
extern void WeightedSumClampHelper_00439920(void);
extern void Thunk_004399b0(void);
int Cmp2CallDirtyCall_004398b0(void) {
    unsigned int v = g_tickFlagF;
    g_walkCallback = (void (*)(void))v;
    if (v == 2) {
        Thunk_004399b0();
        return 1;
    }
    WeightedSumClampHelper_00439920();
    if ((g_xformDirtyFlags & 1) == 0) {
        Thunk_004399b0();
        return 1;
    }
    return 0;
}
