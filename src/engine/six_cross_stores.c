/**
 * Auto-split from misc_matchesMM.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;
extern unsigned int g_state_004d57ac;
extern u32 g_eventQueueEnd;
extern u32 g_eventQueueIdx;
extern u32 g_pendingNodeType;

/* @addr 0x0049d8e0 (89b)
 *   load g_baseSel and g_fightGroupHead, scaled by 4;
 *   six cross-stores: [edx + N] from [eax + M] for (M,N) pairs at +0x38..+0x4c → +0x54..+0x74.
 */
void SixCrossStores_0049d8e0(void) {
    unsigned char *src = (unsigned char *)(g_baseSel_00542060 * 4);
    unsigned char *dst = (unsigned char *)(g_fightGroupHead * 4);
    unsigned int v;
    v = *(unsigned int *)(src + 0x38); g_walkCallback = (void(*)(void))v; *(unsigned int *)(dst + 0x54) = v;
    v = *(unsigned int *)(src + 0x3c); g_walkCallback = (void(*)(void))v; *(unsigned int *)(dst + 0x58) = v;
    v = *(unsigned int *)(src + 0x40); g_walkCallback = (void(*)(void))v; *(unsigned int *)(dst + 0x5c) = v;
    v = *(unsigned int *)(src + 0x44); g_walkCallback = (void(*)(void))v; *(unsigned int *)(dst + 0x6c) = v;
    v = *(unsigned int *)(src + 0x48); g_walkCallback = (void(*)(void))v; *(unsigned int *)(dst + 0x70) = v;
    v = *(unsigned int *)(src + 0x4c); g_walkCallback = (void(*)(void))v; *(unsigned int *)(dst + 0x74) = v;
}
