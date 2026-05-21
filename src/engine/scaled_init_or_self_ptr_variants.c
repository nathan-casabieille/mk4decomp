/**
 * Auto-split from misc_matchesZ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;
extern unsigned int g_state_004d57ac;
extern packed_ptr g_fightGroupHead;
extern u32 g_eventQueueNotMask;

/* @addr 0x00474b10 (64b): ScaledInitOrSelfPtr, store=own, jmp=0x474b50 */
extern void NetEntityScanAndPunish_00474b50(void);
void ScaledInitOrSelfPtr_00474b10(void) {
    unsigned char *base = (unsigned char *)(g_baseSel_00542060 * 4);
    unsigned int ptr = *(unsigned int *)(base + 0x84);
    *(unsigned int *)(base + 0x84) = 0;
    if (ptr) {
        NetEntityScanAndPunish_00474b50();
        return;
    }
    *(unsigned int *)(base + 8) = (unsigned int)ScaledInitOrSelfPtr_00474b10;
    *(unsigned int *)(base + 0x84) = 1;
    g_pendingNodeType = 1;
    g_framePauseFlag = 1;
}

/* @addr 0x00489130 (64b): ScaledInitOrSelfPtr, store=own, jmp=0x41f780 */
extern void func_0041f780_z(void);
void ScaledInitOrSelfPtr_00489130(void) {
    unsigned char *base = (unsigned char *)(g_baseSel_00542060 * 4);
    unsigned int ptr = *(unsigned int *)(base + 0x84);
    *(unsigned int *)(base + 0x84) = 0;
    if (ptr) {
        func_0041f780_z();
        return;
    }
    *(unsigned int *)(base + 8) = (unsigned int)ScaledInitOrSelfPtr_00489130;
    *(unsigned int *)(base + 0x84) = 1;
    g_pendingNodeType = 1;
    g_framePauseFlag = 1;
}
