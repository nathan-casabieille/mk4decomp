/**
 * Auto-split from misc_matchesFF.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x0041f7d0 (61b)
 *   walk a fixed-stride scenegraph chain from 0x0053e368 to 0x00541d68 step 0xe8;
 *   for each entry whose [+0xd8] != 0, set g_scaledInit_00542044 to (esi >> 2)
 *   and call F if it differs from g_baseSel_00542060.
 */
extern void NodeUnlink_0041f710(void *p);
extern unsigned int g_data_00541d68;
void ScenegraphWalk_0041f7d0(void) {
    unsigned char *p = (unsigned char *)&g_nodeSlotsArea;
    do {
        unsigned int v;
        if (*(unsigned int *)(p + 0xd8) == 0) goto advance;
        v = (unsigned int)((int)(unsigned int)p >> 2);
        g_scaledInit_00542044 = v;
        if (v == g_baseSel_00542060) goto advance;
        NodeUnlink_0041f710(p);
    advance:
        p += 0xe8;
    } while ((unsigned int)p < (unsigned int)&g_data_00541d68);
}
