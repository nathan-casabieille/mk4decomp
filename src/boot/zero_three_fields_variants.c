/**
 * Auto-split from misc_matches3.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;

/* @addr 0x00404ed0 (26b): zero aux vec3 (+0x60/+0x64/+0x68) and walkCallback */
void ZeroThreeFields_00404ed0(void) {
    AuxVec3Node *node = (AuxVec3Node *)(g_scaledInit_00542044 << 2);
    node->aux_x = 0;
    node->aux_y = 0;
    g_walkCallback = 0;
    node->aux_z = 0;
}

/* @addr 0x0040a8b0 (26b): zero 3 fields at offsets 0x44/0x48/0x4c plus walkCallback */
void ZeroThreeFields_0040a8b0(void) {
    u32 base = g_scaledInit_00542044 << 2;
    g_walkCallback = 0;
    *(u32 *)(base + 0x44) = 0;
    *(u32 *)(base + 0x48) = 0;
    *(u32 *)(base + 0x4c) = 0;
}
