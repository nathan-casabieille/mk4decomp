/**
 * Scaled-init install-self with counter + type 0x28.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;

/* @addr 0x00446940 (53b): same as 0x0041f1b0 but with diff IMM and value */
void ScaledInitWithCounterAndType_00446940(void) {
    unsigned char *base = (unsigned char *)(g_baseSel_00542060 * 4);
    *(unsigned int *)(base + 0x84) = 0;
    *(unsigned int *)(base + 8) = (unsigned int)ScaledInitWithCounterAndType_00446940;
    *(unsigned int *)(base + 0x84) = 1;
    g_pendingNodeType = 0x28;
    g_framePauseFlag = 1;
}
