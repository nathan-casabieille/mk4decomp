/**
 * The three controllers the character select's PICKER chain hands off to,
 * all of them weak no-ops until now - which is why pressing the confirm
 * installed nodes that did nothing.
 *
 *   AudioInitInstallSelfPeriodic (0x004a0610, 216b) - the one-shot that
 *     arms P2's side of the select. Guarded twice: it does nothing unless
 *     g_dlMode is set AND the 0x53a354 latch is still clear. On the way
 *     through it raises that latch, clears P2's settle flag and 0x53a2e8,
 *     parks P2's phase word at 4, zeroes the node's own tag, and re-enters
 *     the scene through RoundWinTransition. Every path ends in CallSetPause
 *     - it releases itself either way.
 *
 *   0x004a0680 - packed at +0x70 inside that symbol and reached ONLY as the
 *     tag-0x250 callback, so it needs a config/codeptr_extras.yaml entry or
 *     it silently resolves to nothing. A countdown gate: on command 0 it
 *     decrements 0x542054 and releases itself once that goes NEGATIVE;
 *     otherwise it looks at the 0x538090 latch and either re-arms itself on
 *     a 2-tick beat (latch set) or tail-jumps into InstallSelfStride5.
 *
 *   InstallSelfStride5 (0x004a06f0, 165b) - the stride-5 walker. On command
 *     0 it multiplies 0x542054 by five, indexes the table based at 0x541fc4,
 *     reads that entry's +4 into the walk slot and runs GuardedScaledCall,
 *     then re-arms on a 0x32-tick beat; on any later command it clears the
 *     latch and releases. The x5 is the select grid's row stride - the same
 *     five that the horizontal cursor steppers use.
 *
 *   0x0045d5e0 - the controller the SELECTION itself installs, twice, with
 *     work type 0x11 (so the pump runs it every frame whatever screen owns
 *     g_gameMode). Packed near the end of PendingMatch_ZeroNDwords and
 *     reached only by VA, so it needs a codeptr_extras entry too. Two gates,
 *     both of which RELEASE the node: the match-start flag set with the
 *     audio path idle and the GT mode byte at 2, or the audio path busy on
 *     its own. Otherwise it dispatches through the twelve-entry table at
 *     0x4e9030, indexed by the game phase in g_tickFlagF - the fan-out into
 *     the round / intro / outcome handlers.
 *
 *   0x0045d830 / 0x0045d840 / 0x0045d860 - three of the twelve leaves that
 *     table fans out to, packed inside RoundEndFsmCluster. Two are a bare
 *     release; the middle one runs the select's own "is the phase 3" step
 *     first. All three are reached only through the table, so all three need
 *     a codeptr_extras entry.
 *
 *   DispatcherComplex115_Cmp3DirtyToggle (0x0049f900) - that middle leaf's
 *     body. Ask Cmp3DirtyToggle whether the screen phase is 3, and if it is
 *     and neither player is still busy, promote P1 to state 2, re-enter the
 *     scene through RoundWinTransition, bump the idle counter by five
 *     (capped at 8 - StateAdd5Capped, 29 bytes, folded in here) and fire the
 *     scene tag at 0x4e286c.
 *
 * NATIVE-ONLY twins: the matching build synthesizes the original bytes.
 */
#ifdef NON_MATCHING

#include "portable/mem_model.h"

extern void CallSetPause(void);
extern void RoundWinTransition(void);
extern void GuardedScaledCall(void);
extern void InstallSelfStride5(void);
extern void ArgSarAddDerefJmp(int table_va);
extern void Cmp3DirtyToggle(void);
extern void TaggedSceneDispatch(unsigned int tag);

#define g_currentNodeIdx  (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_pendingNodeType (*(unsigned int *)MK4_VA(unsigned int, 0x54204cu))
#define g_slot54          (*(unsigned int *)MK4_VA(unsigned int, 0x542054u))
#define g_baseSel         (*(unsigned int *)MK4_VA(unsigned int, 0x542060u))
#define g_walkSlot6c      (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#define g_framePauseFlag  (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#define g_dlMode          (*(unsigned int *)MK4_VA(unsigned int, 0x542004u))
#define g_p2ArmLatch      (*(unsigned int *)MK4_VA(unsigned int, 0x53a354u))
#define g_settlingP2      (*(unsigned int *)MK4_VA(unsigned int, 0x537ea8u))
#define g_selectAux2e8    (*(unsigned int *)MK4_VA(unsigned int, 0x53a2e8u))
#define g_phaseP2         (*(unsigned int *)MK4_VA(unsigned int, 0x537e90u))
#define g_strideLatch     (*(unsigned int *)MK4_VA(unsigned int, 0x538090u))
#define g_strideTableBase (*(unsigned int *)MK4_VA(unsigned int, 0x541fc4u))
#define g_audioMatchStartFlag (*(unsigned int *)MK4_VA(unsigned int, 0x543714u))
#define g_matchGate3568   (*(unsigned int *)MK4_VA(unsigned int, 0x543568u))
#define g_gtModeByte      (*(unsigned char *)MK4_VA(unsigned char, 0x543590u))
#define g_audioPathFlag   (*(unsigned int *)MK4_VA(unsigned int, 0x54355cu))
#define g_stateBits8c     (*(unsigned int *)MK4_VA(unsigned int, 0x54208cu))
#define g_activeP1        (*(unsigned int *)MK4_VA(unsigned int, 0x53a408u))
#define g_settlingP1      (*(unsigned int *)MK4_VA(unsigned int, 0x541d88u))
#define g_roundSlot3e0    (*(unsigned int *)MK4_VA(unsigned int, 0x53a3e0u))
#define g_selectIdle      (*(unsigned int *)MK4_VA(unsigned int, 0x5380e4u))

#define PERIODIC_VA 0x004a0680u
#define STRIDE5_VA  0x004a06f0u

/* 0x004a0610 */
void AudioInitInstallSelfPeriodic(void)
{
    if (g_dlMode != 0) {
        g_walkSlot6c = g_p2ArmLatch;
        if (g_p2ArmLatch == 0) {
            g_p2ArmLatch = 1;
            g_settlingP2 = 0;
            g_selectAux2e8 = 0;
            g_phaseP2 = 4;
            g_walkSlot6c = 0;
            MK4_NODE_AT(unsigned int, g_baseSel, 0xc) = 0;
            RoundWinTransition();
            if (g_framePauseFlag != 0)
                return;
        }
    } else {
        g_walkSlot6c = g_dlMode;
    }
    CallSetPause();
}

/* 0x004a0680 - packed; tag 0x250 */
void SelectPeriodicGate_004a0680(void)
{
    unsigned int cmd = MK4_NODE_AT(unsigned int, g_baseSel, 0x84);

    MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 0;

    if (cmd == 0) {
        /* the countdown is SIGNED - it releases only once it goes past
         * zero, so a seed of N gives N + 1 visits */
        g_slot54 = g_slot54 - 1;
        if ((int)g_slot54 < 0) {
            CallSetPause();                      /* tail-jmp in the original */
            return;
        }
    }

    g_walkSlot6c = g_strideLatch;
    if (g_strideLatch == 0) {
        InstallSelfStride5();                    /* tail-jmp in the original */
        return;
    }
    MK4_NODE_AT(unsigned int, g_baseSel, 8) = PERIODIC_VA;
    MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 1;
    g_pendingNodeType = 2;
    g_framePauseFlag = 1;
}

/* 0x004a06f0 */
void InstallSelfStride5(void)
{
    unsigned int cmd = MK4_NODE_AT(unsigned int, g_baseSel, 0x84);
    unsigned int idx;

    MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 0;

    if (cmd != 0) {
        g_walkSlot6c = 0;
        g_strideLatch = 0;
        CallSetPause();
        return;
    }

    idx = g_slot54 * 5u;
    g_walkSlot6c = 1;
    g_slot54 = idx;
    g_strideLatch = 1;
    idx += g_strideTableBase;
    g_currentNodeIdx = idx;
    g_walkSlot6c = MK4_NODE_AT(unsigned int, idx, 4);
    GuardedScaledCall();
    if (g_framePauseFlag != 0)
        return;
    MK4_NODE_AT(unsigned int, g_baseSel, 8) = STRIDE5_VA;
    MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 1;
    g_pendingNodeType = 0x32;
    g_framePauseFlag = 1;
}

/* 0x0045d5e0 - work type 0x11 */
void SelectConfirmGate_0045d5e0(void)
{
    if (g_audioMatchStartFlag != 0 && g_matchGate3568 == 0 && g_gtModeByte == 2) {
        CallSetPause();                          /* tail-jmp in the original */
        return;
    }
    if (g_audioPathFlag != 0) {
        CallSetPause();                          /* tail-jmp in the original */
        return;
    }
    ArgSarAddDerefJmp(0x004e9030);
}

/* 0x0049fa00 (29b) - bump the select's idle counter by five, capped at 8. */
void StateAdd5Capped(void)
{
    g_walkSlot6c = g_selectIdle;
    if (g_selectIdle <= 8u) {
        g_walkSlot6c = g_selectIdle + 5u;
        g_selectIdle = g_selectIdle + 5u;
    }
}

/* 0x0049f900 (115b) */
void DispatcherComplex115_Cmp3DirtyToggle_0049f900(void)
{
    Cmp3DirtyToggle();
    if (g_framePauseFlag != 0) return;
    if ((g_stateBits8c & 1u) == 0) return;
    g_walkSlot6c = g_activeP1;
    if (g_activeP1 != 0) return;
    g_walkSlot6c = g_settlingP1;
    if (g_settlingP1 != 0) return;

    g_activeP1 = 2;
    g_walkSlot6c = 0;                 /* eax is still the zero the test left */
    g_roundSlot3e0 = 0;
    RoundWinTransition();
    if (g_framePauseFlag != 0) return;
    StateAdd5Capped();
    if (g_framePauseFlag != 0) return;
    TaggedSceneDispatch(*MK4_VA(unsigned short, 0x4e286cu));
}

/* 0x0045d830 - packed in RoundEndFsmCluster */
void RoundEndLeafRelease_0045d830(void)
{
    CallSetPause();                              /* tail-jmp in the original */
}

/* 0x0045d840 - packed in RoundEndFsmCluster */
void RoundEndLeafPhase3_0045d840(void)
{
    DispatcherComplex115_Cmp3DirtyToggle_0049f900();
    if (g_framePauseFlag != 0)
        return;
    CallSetPause();                              /* tail-jmp in the original */
}

/* 0x0045d860 - packed in RoundEndFsmCluster */
void RoundEndLeafRelease_0045d860(void)
{
    CallSetPause();                              /* tail-jmp in the original */
}

#endif /* NON_MATCHING */
