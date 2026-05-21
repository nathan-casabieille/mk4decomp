/**
 * Auto-split from misc_matchesAA.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;
extern packed_ptr g_xformEntityIdx;
extern packed_ptr g_fightGroupHead;
extern u32 g_eventQueueNotMask;
extern u32 g_eventQueueIdx;
extern u32 g_eventQueueEnd;

/* @addr 0x00490740 (51b)
 *   load fightGroupHead*4 into eax; xor ecx,ecx → g_walkCallback;
 *   set [eax+0x6c]=0; reload walk into ecx; set [eax+0x70]=ecx; etc. for 0x74, 0x4c
 *   then jmp.
 */
extern void ZeroThreeSlots_00490780(void);
void ScaledZeroFour_00490740(void) {
    unsigned int *base = (unsigned int *)(g_fightGroupHead * 4);
    g_walkCallback = 0;
    base[0x6c/4] = 0;
    base[0x70/4] = (unsigned int)g_walkCallback;
    base[0x74/4] = (unsigned int)g_walkCallback;
    base[0x4c/4] = (unsigned int)g_walkCallback;
    ZeroThreeSlots_00490780();
}
