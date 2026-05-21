/**
 * Auto-split from misc_matchesFF.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;
extern packed_ptr g_xformEntityIdx;

/* @addr 0x00421be0 (61b)
 *   load g_state_0053a718; set g_eventQueueChild = 0x28;
 *   eax = state - 1; if (eax < 0x14) return-tail; else set walk=0x32
 *   call F; pause-test; jmp T.
 */
extern unsigned int g_state_0053a718;
extern void func_00489ff0_ff(void);
extern void PollThenInit_00477920(void);
void DecBoundCheckCallJmp_00421be0(void) {
    int s = (int)g_state_0053a718;
    g_eventQueueChild = 0x28;
    s--;
    g_walkCallback = (void(*)(void))s;
    g_state_0053a718 = s;
    if (s < 0x14) {
        g_walkCallback = (void(*)(void))0x32;
        func_00489ff0_ff();
        if (g_framePauseFlag) return;
    }
    PollThenInit_00477920();
}
