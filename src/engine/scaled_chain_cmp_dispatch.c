/**
 * Auto-split from misc_matchesOO.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;
extern unsigned int g_state_004d57ac;
extern unsigned int g_state_00537e94;
extern u32 g_eventQueueCurrent;
extern u32 g_eventQueueWorkType;

/* @addr 0x0048e4f0 (84b)
 *   arg sar 2 → g_scaledInit; load baseSel*4+0x34 → walk; cmp 0x10;
 *   if !=, set walk=2 (always); cmp 0x11; if !=, set walk=4 (always);
 *   add eax, walk → g_scaledInit; load *4+0 → g_scaledInit; jmp eax.
 */
void ScaledChainCmpDispatch_0048e4f0(int arg) {
    unsigned int idx = (unsigned int)(arg >> 2);
    unsigned int walk;
    unsigned int target;
    g_scaledInit_00542044 = idx;
    walk = *(unsigned int *)(g_baseSel_00542060 * 4 + 0x34);
    g_walkCallback = (void (*)(void))walk;
    if (walk == 0x10) {
        walk = 2;
        g_walkCallback = (void (*)(void))walk;
    }
    if (walk == 0x11) {
        walk = 4;
        g_walkCallback = (void (*)(void))walk;
    }
    idx += walk;
    g_scaledInit_00542044 = idx;
    target = *(unsigned int *)(idx * 4);
    g_scaledInit_00542044 = target;
    ((void (*)(void))target)();
}
