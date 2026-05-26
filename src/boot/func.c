/**
 * Auto-split from misc_matchesN.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;
extern unsigned int g_dispatchSave1180_004d5c20;

/* @addr 0x004111f0 (18b): set g_eventQueueIdx = (0x004d5c20>>2); tail-jmp
 * func_00411202 (= PendingMatch_00411210). The 4-byte nop gap before this
 * entry is filled by 0x90-fill. Referenced from g_dispatchSave904_004d5818 in data.c. */
void func_004111f0(void) {
    g_eventQueueIdx = (unsigned int)&g_dispatchSave1180_004d5c20 >> 2;
    func_00411202();
}

/* h1 @ 0x00416e20 (48b): bootstrap wrapper - install func_00416e50
 * as state callback w/ priority 0xb6, then store packed_ptr into
 * scaled-state slot. */
extern void StoreTwoCall_0049cb40(unsigned int, unsigned int);
extern void func_00416e50(void);
void PendingMatch_00416e20(void) {
    StoreTwoCall_0049cb40((unsigned int)&func_00416e50, 0xb6);
    ((ScenegraphNode *)(g_currentNodeIdx * 4))->group_head = g_fightGroupHead;
}
