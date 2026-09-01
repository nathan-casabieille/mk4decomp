/**
 * Three leaves the fighter-select entry needs, and the reason the flow
 * stopped dead the moment the character select finished tearing down.
 *
 * InstallSelfDualBranchInit (0x004201a0) forks on g_optionsVar3 and, on the
 * branch this build takes, chains into Set5CallPauseTestByteJmpCall - which
 * was a weak frontier no-op. A chain hand-off queues its continuation on the
 * node's spare chain at +4 and lets the SUB pop it; with the sub doing
 * nothing, the continuation is never popped and the node sits there with a
 * resume word of 0 forever. MK4_TRACE_DUALBRANCH shows exactly one visit,
 * cmd 0, and then silence.
 *
 *   Set5CallPauseTestByteJmpCall (0x00491950, 54b) - park the game phase at
 *     5 (g_tickFlagF, which is what the 0x4e9030 phase table indexes), ask
 *     whether BOTH players are in, and either pop the continuation
 *     (single player) or count the round up and go on to the round-start
 *     cluster.
 *
 * DualTestDirtyToggle_004282c0 - dirty bit 0 = "both players are active" -
 * was already converted in src/game/fight_frame_drivers.c; only its stale
 * weak FRONTIER_STUB is dropped here, since a duplicate weak stub for a
 * converted function keeps it on the MK4_TRACE_STUBS work-list for no
 * reason.
 *
 *   IncCapped3e7 (0x00491920, 34b) - the round counter at 0x535de4, capped
 *     at 999.
 *
 * NATIVE-ONLY twins: the matching build synthesizes the original bytes.
 */
#ifdef NON_MATCHING

#include "portable/mem_model.h"

extern void StackPopDispatchTagged(void);
extern void DualTestDirtyToggle_004282c0(void);   /* src/game/fight_frame_drivers.c */
extern void RoundStartCluster_RemapWalkAndJmp(void);

#define g_walkSlot6c      (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#define g_stateBits8c     (*(unsigned int *)MK4_VA(unsigned int, 0x54208cu))
#define g_framePauseFlag  (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#define g_tickFlagF       (*(unsigned int *)MK4_VA(unsigned int, 0x52aac4u))
#define g_activeP1        (*(unsigned int *)MK4_VA(unsigned int, 0x53a408u))
#define g_activeP2        (*(unsigned int *)MK4_VA(unsigned int, 0x537e88u))
#define g_roundCounter    (*(unsigned int *)MK4_VA(unsigned int, 0x535de4u))

/* 0x00491920 (34b) */
void IncCapped3e7(void)
{
    unsigned int v = g_roundCounter + 1u;

    g_walkSlot6c = v;
    if ((int)v > 0x3e7) {
        v = 0x3e7;
        g_walkSlot6c = v;
    }
    g_roundCounter = v;
}

/* 0x00491950 (54b) */
void Set5CallPauseTestByteJmpCall(void)
{
    g_walkSlot6c = 5;
    g_tickFlagF = 5;
    DualTestDirtyToggle_004282c0();
    if (g_framePauseFlag != 0)
        return;
    if ((g_stateBits8c & 1u) == 0) {
        StackPopDispatchTagged();                /* tail-jmp in the original */
        return;
    }
    IncCapped3e7();
    RoundStartCluster_RemapWalkAndJmp();         /* tail-jmp in the original */
}

#endif /* NON_MATCHING */
