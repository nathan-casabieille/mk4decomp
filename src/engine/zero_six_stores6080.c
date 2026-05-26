/**
 * Auto-split from misc_matchesKK.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* === ScaledInitOrSelfPtrSetType cluster (68b each) === */

/* @addr 0x00490e40 (68b): same shape, offsets 0x60, 0x64, 0x68, 0x78, 0x7c, 0x80 */
void ZeroSixStores6080_00490e40(void) {
    AuxVec3Node *node = (AuxVec3Node *)(g_fightGroupHead * 4);
    unsigned char *base = (unsigned char *)node;
    g_walkCallback = 0;
    node->aux_x = 0;
    node->aux_y = (s32)(unsigned int)g_walkCallback;
    node->aux_z = (s32)(unsigned int)g_walkCallback;
    *(unsigned int *)(base + 0x78) = (unsigned int)g_walkCallback;
    *(unsigned int *)(base + 0x7c) = (unsigned int)g_walkCallback;
    *(unsigned int *)(base + 0x80) = (unsigned int)g_walkCallback;
}
