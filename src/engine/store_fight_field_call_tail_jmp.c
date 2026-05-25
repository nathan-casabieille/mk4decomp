/**
 * Auto-split from misc_matchesPP.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;

/* @addr 0x004667a0 (49b)
 *   load g_fightGroupHead, g_eventQueueEnd; push 0x4eaa58;
 *   eax = [fightGroup*4+0x64] - 0x4ccc; mov walk=eax;
 *   mov [eventQueueEnd*4+0x64]=eax; call F; add esp,4; ret.
 */
extern unsigned int g_data_004eaa58;
extern void CallSetPause_0041f830(void);
void StoreFightFieldCallTailJmp_004667a0(void) {
    unsigned int fg = (unsigned int)g_fightGroupHead;
    unsigned int eq = g_eventQueueEnd;
    unsigned int v = *(unsigned int *)(fg * 4 + 0x64) - 0x4ccc;
    g_walkCallback = (void (*)(void))v;
    *(unsigned int *)(eq * 4 + 0x64) = v;
    ArgSarStoreJmp_004594f0(&g_data_004eaa58);
}
