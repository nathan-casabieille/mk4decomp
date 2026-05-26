/**
 * Auto-split from misc_matches2.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;
extern unsigned int g_baseSel_00542060;

/* @addr 0x004871d0 (19b)
 *   cmp     [g_eventQueueChild], 5
 *   jge     +5
 *   jmp     T1
 *   jmp     T2
 */
extern void func_004ba317(void);
extern void Wrapper_0048a310(void);
void CmpJmpTwoBranch_004871d0(void) {
    if ((int)g_eventQueueChild < 5) {
        func_004ba317();
        return;
    }
    Wrapper_0048a310();
}
