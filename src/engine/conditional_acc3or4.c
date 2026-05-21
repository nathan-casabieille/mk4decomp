/**
 * Auto-split from misc_matches5.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;
extern unsigned int g_baseSel_00542060;

/* @addr 0x0045e0d0 (30b): same shape, default=3, override=4 */
void ConditionalAcc3or4_0045e0d0(void) {
    g_acc_00542078 = 3;
    if (g_xformScratch2088) {
        g_acc_00542078 = 4;
    }
}
