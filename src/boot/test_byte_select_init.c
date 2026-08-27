/**
 * Auto-split from misc_matchesN.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"
#include "portable/mem_model.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

/* @addr 0x004111d0 (28b): byte-gate + set g_eventQueueIdx = (0x004d5c38>>2);
 * tail-jmp PendingMatch_StoreTwoCall_00411210 (= PendingMatch_StoreTwoCall_00411210 via extras_map). Entry A
 * of the original 50-byte packed block; sub-entry at +0x20 (func_set_g_eventQueueIdx_then_PendingMatch)
 * referenced from data table at g_dispatchSave904 in data.c. */
extern unsigned char g_bootGatedByte360c;
extern unsigned int g_dispatchSave1180;
extern unsigned int g_dispatchSave1181;
extern void PendingMatch_StoreTwoCall_00411210(void);
extern void PendingMatch_StoreTwoCall_00411210(void);
void TestByteSelectInit(void) {
    if (g_bootGatedByte360c == 0) return;
    g_eventQueueIdx = (unsigned int)MK4_UNPTR(&g_dispatchSave1181) >> 2;
    PendingMatch_StoreTwoCall_00411210();
}
