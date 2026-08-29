/**
 * SlotPhaseResetInstallChain (0x48e0e0, 348b) - the per-round slot reset,
 * called 50 times a match and a weak no-op until now.
 *
 * It clears the camera slot's phase fields (+0x7c, +0x74, +0x80), masks
 * the group's +0x40 down with 0xfffffd17, zeroes +0x44, then seeds
 * 0x10000 into one of two packed slots - 0x53a3e4 when the group IS
 * player one, 0x53a474 otherwise - and latches state 6. Finally, if the
 * camera slot still carries a +0x30 callback it runs ScaledAddDeref with
 * a phase of 3 before handing off to GuardedDirtyXformFromTable.
 *
 * ScaledAndAlfb (0x490370, 28b) is the sister of ScaledAndAlfe already in
 * walk_toward_band.c: same shape, clearing bit 2 of the group's +0x40
 * instead of bit 0.
 *
 * PushCallPauseScaledJmpInd (0x48e2f0) is left hollow deliberately. It
 * only runs when the camera slot's +0x7c has reached 3, and it tails into
 * an INDIRECT jump through g_currentNodeIdx, so it needs the codeptr
 * trampoline and a converted ArgScaledLoadCmpP1 underneath. Stubbing it
 * keeps the reset path live and makes MK4_TRACE_STUBS report whether that
 * branch is ever taken.
 *
 * NATIVE-ONLY twins: the matching build synthesizes the original bytes.
 */
#ifdef NON_MATCHING

#include "portable/mem_model.h"

extern void PushCallPauseScaledJmpInd(void);
extern void ScaledAndAlfe(void);
extern void DualCallPauseDirtyJmp_00490c30(void);
extern void State6Latch(void);
extern void ScaledAddDeref(void);
extern void GuardedDirtyXformFromTable(void);

#define g_currentNodeIdx   (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_xformEntityIdx   (*(unsigned int *)MK4_VA(unsigned int, 0x542048u))
#define g_fightGroupHead   (*(unsigned int *)MK4_VA(unsigned int, 0x54205cu))
#define g_baseSel          (*(unsigned int *)MK4_VA(unsigned int, 0x542060u))
#define g_walkCallback     (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#define g_eventQueueCurMm  (*(unsigned int *)MK4_VA(unsigned int, 0x542070u))
#define g_currentNodeFlags (*(unsigned int *)MK4_VA(unsigned int, 0x542084u))
#define g_framePauseFlag   (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#define g_player1NodeIdx   (*(unsigned int *)MK4_VA(unsigned int, 0x538158u))

void ScaledAndAlfb(void)
{
    unsigned int group = g_fightGroupHead;
    unsigned int v = MK4_NODE_AT(unsigned int, group, 0x40) & 0xfffffffbu;

    g_eventQueueCurMm = v;
    MK4_NODE_AT(unsigned int, group, 0x40) = v;
}

void SlotPhaseResetInstallChain(void)
{
    unsigned int cam, group, slot, v;

    g_eventQueueCurMm = 0;
    v = MK4_NODE_AT(unsigned int, g_baseSel, 0x7c);
    g_walkCallback = v;
    if ((int)v >= 3) {
        PushCallPauseScaledJmpInd();
        if (g_framePauseFlag != 0) return;
    }

    ScaledAndAlfe();
    if (g_framePauseFlag != 0) return;
    ScaledAndAlfb();
    if (g_framePauseFlag != 0) return;

    group = g_fightGroupHead;
    v = MK4_NODE_AT(unsigned int, group, 0x40) & 0xfffffd17u;
    g_eventQueueCurMm = v;
    MK4_NODE_AT(unsigned int, group, 0x40) = v;

    DualCallPauseDirtyJmp_00490c30();
    if (g_framePauseFlag != 0) return;

    group = g_fightGroupHead;
    g_walkCallback = 0;
    MK4_NODE_AT(unsigned int, group, 0x44) = 0;
    MK4_NODE_AT(unsigned int, g_baseSel, 0x7c) = g_walkCallback;
    MK4_NODE_AT(unsigned int, g_baseSel, 0x74) = g_walkCallback;
    MK4_NODE_AT(unsigned int, g_baseSel, 0x80) = 0;

    /* player one seeds its own slot, the other side seeds the phase array */
    slot = 0x53a3e4u >> 2;
    g_walkCallback = 0x10000u;
    g_currentNodeIdx = slot;
    g_xformEntityIdx = 0x53a474u >> 2;
    if (g_fightGroupHead != g_player1NodeIdx) {
        slot = 0x53a474u >> 2;
        g_currentNodeIdx = slot;
    }
    *(unsigned int *)MK4_PTR(slot * 4u) = 0x10000u;

    State6Latch();
    if (g_framePauseFlag != 0) return;

    cam = g_baseSel;
    g_currentNodeIdx = 0x4ea040u >> 2;
    v = MK4_NODE_AT(unsigned int, cam, 0x30);
    g_walkCallback = v;
    if (v != 0) {
        g_walkCallback = 3;
        ScaledAddDeref();
        if (g_framePauseFlag != 0) return;
    }
    GuardedDirtyXformFromTable();
}

#endif /* NON_MATCHING */
