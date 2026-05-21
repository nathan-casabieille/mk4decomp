/**
 * Auto-split from misc_matchesKK.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;
extern u32 g_pendingNodeType;
extern packed_ptr g_fightGroupHead;

/* === ScaledInitOrSelfPtrSetType cluster (68b each) === */

/* @addr 0x0048a7c0 (68b): zero 6 dwords at offsets 0x6c..0x80 of fightGroupHead*4 */
void ZeroSixStores6c80_0048a7c0(void) {
    unsigned char *base = (unsigned char *)(g_fightGroupHead * 4);
    g_walkCallback = 0;
    *(unsigned int *)(base + 0x6c) = 0;
    *(unsigned int *)(base + 0x70) = (unsigned int)g_walkCallback;
    *(unsigned int *)(base + 0x74) = (unsigned int)g_walkCallback;
    *(unsigned int *)(base + 0x78) = (unsigned int)g_walkCallback;
    *(unsigned int *)(base + 0x7c) = (unsigned int)g_walkCallback;
    *(unsigned int *)(base + 0x80) = (unsigned int)g_walkCallback;
}
