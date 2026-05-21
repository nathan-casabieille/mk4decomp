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

/* @addr 0x0048d070 (80b)
 *   eax = g_baseSel * 4; clear [eax+0x84]; if g_fightGroupHead ==
 *   [0x538158] or [0x53815c]: jmp 0x41f780 (drop frame).
 *   Else: ecx = 1; [eax+8] = OFFSET self (0x48d070); [eax+0x84] = 1;
 *   pendingNodeType = 0xa; framePauseFlag = 1; ret.
 */
extern unsigned int g_data_0053815c;
extern void GuardedSelfRefSet_0048d070(void);
void GuardedSelfRefSet_0048d070(void) {
    unsigned char *base = (unsigned char *)(g_baseSel_00542060 * 4);
    *(unsigned int *)(base + 0x84) = 0;
    do {
        if (g_fightGroupHead == g_data_00538158) break;
        if (g_fightGroupHead == g_data_0053815c) break;
        *(unsigned int *)(base + 8) = (unsigned int)&GuardedSelfRefSet_0048d070;
        *(unsigned int *)(base + 0x84) = 1;
        g_pendingNodeType = 0x0a;
        g_framePauseFlag = 1;
        return;
    } while (0);
    func_0041f780_pp();
}
