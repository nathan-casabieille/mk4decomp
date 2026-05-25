/**
 * Auto-split from misc_matchesAA.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00494140 (61b)
 *   arg sar 2 → g_eventQueueTotal; scaled load [baseSel*4 + 0x30] → g_walkCallback
 *   scaled load [arg*4 + 0] → g_xformEntityIdx; if walk!=0 also load +4.
 */
void ArgScaledTestStore_00494140(int arg) {
    unsigned int packed = (unsigned int)(arg >> 2);
    unsigned int *src = (unsigned int *)(packed * 4);
    unsigned int cb;
    g_eventQueueTotal = packed;
    cb = *(unsigned int *)(g_baseSel_00542060 * 4 + 0x30);
    g_walkCallback = (void (*)(void))cb;
    g_xformEntityIdx = src[0];
    if (cb != 0) {
        g_xformEntityIdx = src[1];
    }
}
