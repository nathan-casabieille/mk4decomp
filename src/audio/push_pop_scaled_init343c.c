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

/* @addr 0x004aa940 (76b)
 *   PushPopScaledInit save/restore wrapper around: load [0x54343c]
 *   into g_scaledInit, call helper, clear [0x54343c]. Standard
 *   "scoped global swap" pattern.
 */
extern unsigned int g_data_0054343c;
extern void MStackPush2ChainLLInsert_00406790(void);
void PushPopScaledInit343c_004aa940(void) {
    g_state_004d57ac++;
    *(unsigned int *)(g_state_004d57ac * 4) = g_scaledInit_00542044;
    g_scaledInit_00542044 = g_data_0054343c;
    MStackPush2ChainLLInsert_00406790();
    g_data_0054343c = 0;
    g_scaledInit_00542044 = *(unsigned int *)(g_state_004d57ac * 4);
    g_state_004d57ac--;
}
