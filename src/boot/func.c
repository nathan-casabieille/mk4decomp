/**
 * Auto-split from misc_matchesN.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;
extern unsigned int g_dispatchSave1180;

/* @addr 0x004111f0 (18b): set g_eventQueueIdx = (0x004d5c20>>2); tail-jmp
 * PendingMatch_StoreTwoCall_00411210 (= PendingMatch_StoreTwoCall_00411210). The 4-byte nop gap before this
 * entry is filled by 0x90-fill. Referenced from g_dispatchSave904 in data.c. */
void func_set_g_eventQueueIdx_then_PendingMatch(void) {
    g_eventQueueIdx = (unsigned int)&g_dispatchSave1180 >> 2;
    PendingMatch_StoreTwoCall_00411210();
}

/* h1 @ 0x00416e20 (48b): bootstrap wrapper - install PoseFsmCluster_PendingMatch_00416e50
 * as state callback w/ priority 0xb6, then store packed_ptr into
 * scaled-state slot. */
extern void StoreTwoCall(unsigned int, unsigned int);
extern void PoseFsmCluster_PendingMatch_00416e50(void);
void PendingMatch_00416e20(void) {
    StoreTwoCall((unsigned int)&PoseFsmCluster_PendingMatch_00416e50, 0xb6);
    ((ScenegraphNode *)(g_currentNodeIdx * 4))->group_head = g_fightGroupHead;
}
