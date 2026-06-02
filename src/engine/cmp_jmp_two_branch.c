/**
 * Auto-split from misc_matches2.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;
extern unsigned int g_baseSel;

/* @addr 0x004871d0 (19b)
 *   cmp     [g_eventQueueChild], 5
 *   jge     +5
 *   jmp     T1
 *   jmp     T2
 */
extern void Wrapper_ScaledChainPushCall_004ef900(void);
extern void Wrapper_ScaledChainPushCall_004ef910(void);
void CmpJmpTwoBranch(void) {
    if ((int)g_eventQueueChild < 5) {
        Wrapper_ScaledChainPushCall_004ef900();
        return;
    }
    Wrapper_ScaledChainPushCall_004ef910();
}
