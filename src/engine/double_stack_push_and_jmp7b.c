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

/* @addr 0x00474090 (63b): DoubleStackPushAndJmp variant, value=0x7b */
extern void func_004740d0_zz(void);
void DoubleStackPushAndJmp7b_00474090(void) {
    g_state_004d57ac++;
    *(unsigned int *)(g_state_004d57ac * 4) = g_scaledInit_00542044;
    g_state_004d57ac++;
    *(unsigned int *)(g_state_004d57ac * 4) = g_fightGroupHead;
    g_scaledInit_00542044 = 0x7b;
    func_004740d0_zz();
}
