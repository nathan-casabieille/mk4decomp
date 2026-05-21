/**
 * Auto-split from misc_matches5.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;
extern unsigned int g_baseSel_00542060;

/* @addr 0x0045e0b0 (30b)
 *   mov     eax, [g_xformScratch2088]
 *   mov     [g_acc_00542078], 4
 *   test    eax, eax
 *   je      ret
 *   mov     [g_acc_00542078], 3
 *   ret
 */
extern unsigned int g_acc_00542078;
void ConditionalAcc4or3_0045e0b0(void) {
    g_acc_00542078 = 4;
    if (g_xformScratch2088) {
        g_acc_00542078 = 3;
    }
}
