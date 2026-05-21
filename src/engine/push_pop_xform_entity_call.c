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

/* @addr 0x0044d1e0 (66b)
 *   Save g_xformEntityIdx (0x542048) on matrix stack, replace it
 *   with g_eventQueueEnd (0x542054), call helper, restore.
 *   Standard "scoped global swap" wrapper.
 */
extern void func_0044aa40(void);
void PushPopXformEntityCall_0044d1e0(void) {
    unsigned int top;
    top = g_state_004d57ac + 1;
    g_state_004d57ac = top;
    *(unsigned int *)(top * 4) = g_xformEntityIdx;
    g_xformEntityIdx = g_eventQueueEnd;
    func_0044aa40();
    top = g_state_004d57ac;
    g_xformEntityIdx = *(unsigned int *)(top * 4);
    g_state_004d57ac = top - 1;
}
