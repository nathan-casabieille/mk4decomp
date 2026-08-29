/**
 * The per-frame leaves the fight calls 50-100 times each and that were all
 * weak no-ops until now. MK4_TRACE_STUBS found them: none is dispatched
 * through the trampoline, so every one was invisible to MK4_TRACE_CODE.
 *
 * The one that matters visually is ChainSetupBitToggle. It measures the
 * vector from the group to the OTHER fighter, runs it through
 * Atan2QuadrantLookup and stores the resulting BAM at the group's +0x64 -
 * that field is what turns a fighter to face its opponent. Against a no-op
 * it stayed at whatever the spawn left there, so both fighters faced a
 * fixed direction regardless of where the other one stood.
 *
 * MStackPush2ChainSwap compares the camera-anchor's x against the group's
 * x and leaves the answer in dirty-bit 0, optionally swapping the two
 * first when g_phaseThunkState is set. GuardedDualAndFlagToggle then folds
 * that bit against the group's own +0x34 bit 0: equal clears the bit,
 * different sets it. That pair is the left/right side test.
 *
 * The rest are small state leaves: ScaledOrStore_004903d0 (set +0x34 bit
 * 0), ZeroState, Init6Struct (reset the point-light accumulator - note the
 * three colour fields are WORDS, see [[feedback_width16_matrix_trap]]),
 * DirtyFlagsManipB, StateInitShuffle and TestZeroJmp.
 *
 * NATIVE-ONLY twins: the matching build synthesizes the original bytes.
 */
#ifdef NON_MATCHING

#include "portable/mem_model.h"

extern void DualBitGateInitCall(void);
extern void Atan2QuadrantLookup(void);
extern void BootMod6487eClampAndChainMul10(void);

void MStackPush2ChainSwap(void);

#define g_currentNodeIdx   (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_xformEntityIdx   (*(unsigned int *)MK4_VA(unsigned int, 0x542048u))
#define g_fightGroupHead   (*(unsigned int *)MK4_VA(unsigned int, 0x54205cu))
#define g_baseSel          (*(unsigned int *)MK4_VA(unsigned int, 0x542060u))
#define g_walkCallback     (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#define g_eventQueueCurMm  (*(unsigned int *)MK4_VA(unsigned int, 0x542070u))
#define g_lit16_542074     (*(unsigned int *)MK4_VA(unsigned int, 0x542074u))
#define g_chainAccumCur    (*(unsigned int *)MK4_VA(unsigned int, 0x542078u))
#define g_currentNodeFlags (*(unsigned int *)MK4_VA(unsigned int, 0x542084u))
#define g_xformScratch2088 (*(unsigned int *)MK4_VA(unsigned int, 0x542088u))
#define g_xformDirtyFlags  (*(unsigned int *)MK4_VA(unsigned int, 0x54208cu))
#define g_xformScratch94   (*(unsigned int *)MK4_VA(unsigned int, 0x542094u))
#define g_framePauseFlag   (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#define g_matrixStackTop   (*(unsigned int *)MK4_VA(unsigned int, 0x4d57acu))
#define g_player1NodeIdx   (*(unsigned int *)MK4_VA(unsigned int, 0x538158u))
#define g_player2NodeIdx   (*(unsigned int *)MK4_VA(unsigned int, 0x53815cu))
#define g_phaseThunkState  (*(unsigned int *)MK4_VA(unsigned int, 0x53a730u))
#define g_active_0053a408  (*(unsigned int *)MK4_VA(unsigned int, 0x53a408u))
#define g_armedReloadA     (*(unsigned int *)MK4_VA(unsigned int, 0x541fa4u))
#define g_zeroJmpGate      (*(unsigned int *)MK4_VA(unsigned int, 0x543824u))
#define g_hitPhase         (*(unsigned int *)MK4_VA(unsigned int, 0x537f30u))
#define g_dlNalt1          (*(unsigned int *)MK4_VA(unsigned int, 0x537f48u))
#define g_dlNalt2          (*(unsigned int *)MK4_VA(unsigned int, 0x5380e0u))
#define g_dlChar13         (*(unsigned int *)MK4_VA(unsigned int, 0x541ec4u))
#define g_dlChar24         (*(unsigned int *)MK4_VA(unsigned int, 0x541ec8u))
#define g_audioInitState1  (*(unsigned int *)MK4_VA(unsigned int, 0x541ed0u))
#define g_audioInitState2  (*(unsigned int *)MK4_VA(unsigned int, 0x541eccu))
#define g_audioInitState3  (*(unsigned int *)MK4_VA(unsigned int, 0x53a790u))
#define g_audioInitState4  (*(unsigned int *)MK4_VA(unsigned int, 0x53a1ccu))
#define g_audioInitState5  (*(unsigned int *)MK4_VA(unsigned int, 0x537edcu))
#define g_audioInitState6  (*(unsigned int *)MK4_VA(unsigned int, 0x537ea0u))
#define g_finalDest_53a178 (*(unsigned int *)MK4_VA(unsigned int, 0x53a178u))
#define g_finalDest_53a250 (*(unsigned int *)MK4_VA(unsigned int, 0x53a250u))
#define g_installCountdownPair (*(unsigned int *)MK4_VA(unsigned int, 0x543894u))
#define g_dispatchSave8    (*(unsigned int *)MK4_VA(unsigned int, 0x543898u))
#define g_pointPosX        (*(unsigned int *)MK4_VA(unsigned int, 0xab4e50u))
#define g_pointPosY        (*(unsigned int *)MK4_VA(unsigned int, 0xab4e54u))
#define g_pointPosZ        (*(unsigned int *)MK4_VA(unsigned int, 0xab4e58u))
/* WORD stores in the original - a dword alias here would spill into the
 * neighbouring colour channel. */
#define g_pointColorR      (*(unsigned short *)MK4_VA(unsigned short, 0xab4e44u))
#define g_pointColorG      (*(unsigned short *)MK4_VA(unsigned short, 0xab4e48u))
#define g_pointColorB      (*(unsigned short *)MK4_VA(unsigned short, 0xab4e4cu))

#define MSTACK_AT(i)       (*(unsigned int *)MK4_PTR((i) * 4u))

void ScaledOrStore_004903d0(void)
{
    unsigned int group = g_fightGroupHead;
    unsigned int v = MK4_NODE_AT(unsigned int, group, 0x34) | 1u;

    g_walkCallback = v;
    MK4_NODE_AT(unsigned int, group, 0x34) = v;
}

void ZeroState(void)
{
    g_armedReloadA = 0;
}

void TestZeroJmp(void)
{
    if (g_zeroJmpGate == 0)
        return;
    g_zeroJmpGate = 0;
    DualBitGateInitCall();               /* jmp in the original */
}

void Init6Struct(void)
{
    g_pointPosX = 0;
    g_pointPosY = 0;
    g_pointPosZ = 0;
    g_pointColorR = 0x8000u;
    g_pointColorG = 0x8000u;
    g_pointColorB = 0x8000u;
}

void DirtyFlagsManipB(void)
{
    unsigned int d = g_xformDirtyFlags;
    unsigned int a = g_active_0053a408;

    g_walkCallback = a;
    d |= 4u;
    g_xformDirtyFlags = d;
    if (a == 0)
        return;
    g_xformDirtyFlags = d ^ 4u;
}

void StateInitShuffle(void)
{
    g_audioInitState6 = g_dlNalt2;
    g_installCountdownPair = 0;
    g_dispatchSave8 = 0;
    g_audioInitState3 = g_dlNalt1;
    g_audioInitState5 = g_finalDest_53a178;
    g_audioInitState4 = g_finalDest_53a250;
    g_audioInitState2 = g_dlChar13;
    g_audioInitState1 = g_dlChar24;
    g_walkCallback = 1;
    g_hitPhase = 1;
}

void MStackPush2ChainSwap(void)
{
    unsigned int top, anchor, group, phase, a, b;

    top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    MSTACK_AT(top) = g_currentNodeIdx;
    top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    MSTACK_AT(top) = g_walkCallback;

    anchor = g_baseSel;
    group  = g_fightGroupHead;
    phase  = g_phaseThunkState;

    anchor = MK4_NODE_AT(unsigned int, anchor, 0x38);
    g_xformEntityIdx = anchor;
    a = MK4_NODE_AT(unsigned int, anchor, 0x54);
    g_currentNodeFlags = a;
    b = MK4_NODE_AT(unsigned int, group, 0x54);
    g_xformScratch2088 = b;
    g_walkCallback = phase;
    if (phase != 0) {
        unsigned int t = a;
        a = b;
        b = t;
        g_currentNodeFlags = a;
        g_xformScratch2088 = b;
    }

    top = g_matrixStackTop;
    g_walkCallback = MSTACK_AT(top);
    top--;
    g_matrixStackTop = top;
    g_currentNodeIdx = MSTACK_AT(top);
    top--;
    g_matrixStackTop = top;

    if ((int)a >= (int)b)
        g_xformDirtyFlags |= 1u;
    else
        g_xformDirtyFlags &= 0xfffffffeu;
}

void GuardedDualAndFlagToggle(void)
{
    unsigned int group = g_fightGroupHead;
    unsigned int w;

    g_walkCallback = MK4_NODE_AT(unsigned int, group, 0x34);
    MStackPush2ChainSwap();
    if (g_framePauseFlag != 0)
        return;

    /* the side bit and the group's own bit agree -> clear, differ -> set */
    if ((g_xformDirtyFlags & 1u) != 0) {
        w = g_walkCallback & 1u;
        g_xformScratch94 = w;
        if (w == 0) {
            g_xformDirtyFlags |= 1u;
            return;
        }
        g_xformDirtyFlags &= 0xfffffffeu;
        return;
    }
    w = g_walkCallback & 1u;
    g_xformScratch94 = w;
    if (w != 0) {
        g_xformDirtyFlags |= 1u;
        return;
    }
    g_xformDirtyFlags &= 0xfffffffeu;
}

void ChainSetupBitToggle(void)
{
    unsigned int group = g_fightGroupHead;
    unsigned int other = g_player1NodeIdx;
    int gx, gz, ox, oz;

    g_currentNodeIdx = other;
    if (group == other) {
        other = g_player2NodeIdx;
        g_currentNodeIdx = other;
    }

    gx = (int)MK4_NODE_AT(unsigned int, group, 0x54);
    g_walkCallback = (unsigned int)gx;
    gz = (int)MK4_NODE_AT(unsigned int, group, 0x5c);
    g_eventQueueCurMm = (unsigned int)gz;
    ox = (int)MK4_NODE_AT(unsigned int, other, 0x54);
    g_lit16_542074 = (unsigned int)ox;
    oz = (int)MK4_NODE_AT(unsigned int, other, 0x5c);

    ox -= gx;
    oz -= gz;
    g_walkCallback   = (unsigned int)ox;
    g_lit16_542074   = (unsigned int)oz;
    g_chainAccumCur  = (unsigned int)ox;

    Atan2QuadrantLookup();
    if (g_framePauseFlag != 0)
        return;

    g_eventQueueCurMm = MK4_NODE_AT(unsigned int, g_fightGroupHead, 0x34);
    g_xformScratch94  = g_eventQueueCurMm & 1u;
    if (g_xformScratch94 == 0)
        g_walkCallback = (unsigned int)(-(int)g_walkCallback);

    BootMod6487eClampAndChainMul10();
    if (g_framePauseFlag != 0)
        return;
    MK4_NODE_AT(unsigned int, g_fightGroupHead, 0x64) = g_walkCallback;
}

#endif /* NON_MATCHING */
