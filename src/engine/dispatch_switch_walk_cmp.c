/**
 * Auto-split from misc_matchesPP.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_state_004d57ac;
extern unsigned int g_scaledInit_00542044;
extern u32 g_eventQueueWorkType;
extern packed_ptr g_xformEntityIdx;
extern u32 g_eventQueueEnd;
extern u32 g_tickW1;
extern packed_ptr g_fightGroupHead;

/* @addr 0x00438bf0 (72b)
 *   eax = baseSel*4+0x34; walk = eax;
 *   if eax == 0x10: walk = 2; if eax == 0x11: walk = 7;
 *   if eax == 5 or 6: jmp T1; else jmp T2.
 *   The `if==X then walk=N` arms keep eax intact for next cmp.
 */
extern void Wrapper_00438c40(void);
extern void Wrapper_00438ee0(void);
void DispatchSwitchWalkCmp_00438bf0(void) {
    unsigned int v = *(unsigned int *)(g_baseSel_00542060 * 4 + 0x34);
    g_walkCallback = (void (*)(void))v;
    if (v == 0x10) {
        v = 2;
        g_walkCallback = (void (*)(void))v;
    }
    if (v == 0x11) {
        v = 7;
        g_walkCallback = (void (*)(void))v;
    }
    if (v == 5) {
        Wrapper_00438c40();
        return;
    }
    if (v == 6) {
        Wrapper_00438c40();
        return;
    }
    Wrapper_00438ee0();
}
