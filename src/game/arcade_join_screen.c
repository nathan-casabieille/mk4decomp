/**
 * ARCADE: the PLAYER JOIN screen - what the mode-select row's handler
 * (0x4a9cc0) actually is, and the first thing that happens after the menu
 * fades out.
 *
 * It has no symbol of its own: it is packed at +0x380 inside the 2736-byte
 * TeamMode_JoinScreen blob at 0x4a9940, alongside ENDURANCE (+0x90) and the
 * arrow blinker (+0x2c0). The menu reaches it INDIRECTLY - state 4 parks the
 * row's handler word in 0x543574 and states 5..7 do `call [0x543574]` - so
 * both it and the blinker need entries in config/codeptr_extras.yaml or
 * MK4_ResolveCode hands back nothing and the call is a no-op.
 *
 * Controller states, keyed off g_baseSel[+0x84] as usual, except that the
 * DEFAULT case (3 and up) is the per-frame body, not state 0:
 *
 *   0  BUILD. g_dbgByte543590 - which the menu's own TripleCallByteCheck
 *      set to 1 or 2 for the player who pressed - decides which of the two
 *      join flags starts raised (P1 0x5433d0, P2 0x543708). Then the screen:
 *      FiveTableWalkInit, the .geo at 0x50b208, the two backdrop records
 *      0x50fb94 / 0x50fbb0 each placed and handed to PushSetCallPop, and
 *      0x50d1e8 - the arrow - parked at kind 0x24e and stored in
 *      g_fightGroupHead, with the title node flattened to z = 0xfffb0000.
 *      StoreTwoCall(0x4a9c00, 0x235) starts the blinker. The two "PRESS
 *      START" strings (0x4d55e8 / 0x4d55f8) go out through the text band and
 *      the controller parks as state 3.
 *   3  PER FRAME. Recycle the two marker nodes, re-emit each player's label
 *      from 0x4d5610 (joined) or 0x4d5608 (not), slide the arrow to the
 *      selected row, read the CONTROLLER/PLAYERS toggle off 0x4d50a4, and
 *      take each player's join press: the FIRST press raises that player's
 *      flag, a SECOND one drops the arrow (recycling g_fightGroupHead and
 *      rolling the chain back through TripleStageRollback). The 0x708 idle
 *      countdown, or RetZero_004a1c40 reporting a back-out, chains on
 *      through the fade - to state 1 and state 2 respectively.
 *   1  EXIT FORWARD, four ways: both players in picks MatchStartCluster or
 *      AudioModeInitVariant by the toggle, one player picks
 *      AudioTriEntryFlagPairInit or AudioModeInit. All four are still
 *      hollow: that is the fighter-select screen, not this one.
 *   2  EXIT BACK - straight into the mode-select controller.
 *
 * Converted with it, because nothing else linked them:
 *   MovsxAnd4Shr / MovsxAnd20Shr5 (0x4a1ce0 / 0x4a1cf0) - bit 2 and bit 5 of
 *     the second pad byte 0x4d50c0, the two players' alternate join buttons.
 *   RetZero_004a1c40 - returns zero. It is the back-out hook, and the
 *     original really is `xor eax, eax; ret`.
 *   TripleStageRollback (0x404a50) - walk the tagged chain back: match on
 *     the tag with slot70 = 0xffff, then while dirty bit 0 stays set, step
 *     through Thunk_LoadShlDerefCallSkip and match again. Both pause exits
 *     return WITHOUT restoring the three saved slots, as the original does.
 *
 * NATIVE-ONLY twins: the matching build synthesizes the original bytes.
 */
#ifdef NON_MATCHING

#include "portable/mem_model.h"

extern void MStackPush2ChainLLInsert(void);
extern void GuardedSetupCallTailJmp(unsigned int textVA, unsigned int y);
extern void Helper_AudioStub_4140(void);
extern void Helper_AudioStub_4160(void);
extern void SetJmp_Push16Call_004a1ac0(void);
extern void SetJmp_Push16Call_004a1ad0(void);
extern int  InputPollFlagBits(void);
extern int  InputPollFlagBitsHalf(void);
extern int  TestQueueGateState(void);
extern void Push16Call(void);
extern void FiveTableWalkInit(void);
extern void LoadGeoAsset_Default(void);
extern void DispatcherComplex260_MStackBracket1_TreeWalkRecursive2(void);
extern void PushSetCallPop(void);
extern void MStackCall_MStackPush2ChainPrepend_00406340(void);
extern void StoreTwoCall(int fn, int arg);
extern void InstallSelfPackedF80(void);
extern void PendingMatch_004a2a80(void);
extern void Thunk_NodeChainMaskMatch(void);
extern void Thunk_LoadShlDerefCallSkip(void);
/* the four forward exits - still hollow, the fighter-select screen */
extern void MatchStartCluster(void);
extern void AudioModeInitVariant(void);
extern void AudioTriEntryFlagPairInit(void);
extern void AudioModeInit(void);

#define g_currentNodeIdx  (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_xformEntityIdx  (*(unsigned int *)MK4_VA(unsigned int, 0x542048u))
#define g_pendingNodeType (*(unsigned int *)MK4_VA(unsigned int, 0x54204cu))
#define g_fightGroupHead  (*(unsigned int *)MK4_VA(unsigned int, 0x54205cu))
#define g_baseSel         (*(unsigned int *)MK4_VA(unsigned int, 0x542060u))
#define g_walkSlot6c      (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#define g_slot70          (*(unsigned int *)MK4_VA(unsigned int, 0x542070u))
#define g_slot74          (*(unsigned int *)MK4_VA(unsigned int, 0x542074u))
#define g_stateBits8c     (*(unsigned int *)MK4_VA(unsigned int, 0x54208cu))
#define g_framePauseFlag  (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#define g_titleLogoNode   (*(unsigned int *)MK4_VA(unsigned int, 0x52ab10u))
#define g_tickFlagF       (*(unsigned int *)MK4_VA(unsigned int, 0x52aac4u))
#define g_phaseIdx        (*(unsigned int *)MK4_VA(unsigned int, 0x53a50cu))
#define g_confirmPlayer   (*(unsigned char *)MK4_VA(unsigned char, 0x543590u))
#define g_joinedP1        (*(unsigned int *)MK4_VA(unsigned int, 0x5433d0u))
#define g_joinedP2        (*(unsigned int *)MK4_VA(unsigned int, 0x543708u))
#define g_joinIdle        (*(unsigned int *)MK4_VA(unsigned int, 0x5433fcu))
#define g_padByte50a4     (*(unsigned int *)MK4_VA(unsigned int, 0x4d50a4u))
#define g_padByte50c0     (*(signed char *)MK4_VA(signed char, 0x4d50c0u))

#define ARCADE_VA   0x4a9cc0u
#define BLINK_VA    0x4a9c00u

/* 0x4a1ce0 / 0x4a1cf0 */
int MovsxAnd4Shr(void)   { return ((int)g_padByte50c0 & 4) >> 2; }
int MovsxAnd20Shr5(void) { return ((int)g_padByte50c0 & 0x20) >> 5; }

/* 0x4a1c40 - the back-out hook; the original really is xor eax,eax / ret */
int RetZero_004a1c40(void) { return 0; }

/* 0x404a50 - roll the tagged chain back */
void TripleStageRollback(unsigned int tag)
{
    unsigned int savedType = g_pendingNodeType;
    unsigned int savedNode = g_currentNodeIdx;
    unsigned int savedSlot = g_slot70;

    g_walkSlot6c = tag;
    g_slot70 = 0xffff;
    Thunk_NodeChainMaskMatch();
    if (g_framePauseFlag != 0)
        return;                                  /* no restore, as original */

    while ((g_stateBits8c & 1u) != 0) {
        g_pendingNodeType = g_currentNodeIdx;
        Thunk_LoadShlDerefCallSkip();
        if (g_framePauseFlag != 0)
            return;
        g_walkSlot6c = tag;
        g_slot70 = 0xffff;
        Thunk_NodeChainMaskMatch();
        if (g_framePauseFlag != 0)
            return;
    }

    g_currentNodeIdx = savedNode;
    g_pendingNodeType = savedType;
    g_slot70 = savedSlot;
}

/* 0x4a9c00 - the arrow blinker: flip the head node's record every 8 ticks */
void ArcadeJoin_Blinker_004a9c00(void)
{
    unsigned int cmd = MK4_NODE_AT(unsigned int, g_baseSel, 0x84);

    MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 0;

    if (cmd == 1) {
        g_walkSlot6c = 0x50d204u >> 2;
        MK4_NODE_AT(unsigned int, g_fightGroupHead, 0x24) = 0x50d204u >> 2;
        MK4_NODE_AT(unsigned int, g_baseSel, 8) = BLINK_VA;
        MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 2;
        g_pendingNodeType = 8;
        g_framePauseFlag = 1;
        return;
    }
    if (cmd == 0)                                /* once: descend to the child */
        g_fightGroupHead = MK4_NODE_AT(unsigned int, g_fightGroupHead, 0x18);

    g_walkSlot6c = 0x50d1e8u >> 2;
    MK4_NODE_AT(unsigned int, g_fightGroupHead, 0x24) = 0x50d1e8u >> 2;
    MK4_NODE_AT(unsigned int, g_baseSel, 8) = BLINK_VA;
    MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 1;
    g_pendingNodeType = 8;
    g_framePauseFlag = 1;
}

/* queue the tagged continuation for state N, then hand the frame on */
static void aj_chain(unsigned int state)
{
    unsigned int q;

    MK4_NODE_AT(unsigned int, g_baseSel, 8) = ARCADE_VA;
    MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = state;
    q = MK4_NODE_AT(unsigned int, g_baseSel, 4);
    g_currentNodeIdx = q;
    *(unsigned int *)MK4_PTR(q * 4) = ARCADE_VA + (state << 24);
    g_currentNodeIdx = q + 1;
    MK4_NODE_AT(unsigned int, g_baseSel, 4) = q + 1;
    MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 0;
}

/* one player's label: 0x4d5610 when joined, 0x4d5608 when not */
static void aj_label(int joined, unsigned int y, unsigned int dx)
{
    GuardedSetupCallTailJmp(joined ? 0x4d5610u : 0x4d5608u, y);
    MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x5c) = 0x14000;
    MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x54) += dx;
}

void ArcadeMode_JoinScreen_004a9cc0(void)
{
    unsigned int cmd = MK4_NODE_AT(unsigned int, g_baseSel, 0x84);
    unsigned int node;

    MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 0;

    switch (cmd) {
    case 2:                                      /* 0x4aa07a: back to the menu */
        PendingMatch_004a2a80();
        return;

    case 1:                                      /* 0x4aa084: forward */
        FiveTableWalkInit();
        if (g_framePauseFlag != 0) return;
        if (g_joinedP1 != 0 && g_joinedP2 != 0) {
            if (MK4_NODE_AT(unsigned int, g_baseSel, 0x30) == 0)
                MatchStartCluster();
            else
                AudioModeInitVariant();
        } else {
            if (MK4_NODE_AT(unsigned int, g_baseSel, 0x30) == 0)
                AudioTriEntryFlagPairInit();
            else
                AudioModeInit();
        }
        return;

    case 0: {                                    /* 0x4aa0ea: BUILD */
        unsigned char who = g_confirmPlayer;

        g_joinIdle = 0;
        g_joinedP2 = 0;
        g_joinedP1 = 0;
        if (who == 1) g_joinedP1 = 1; else g_joinedP2 = 1;
        g_tickFlagF = 2;
        g_phaseIdx = 1;

        FiveTableWalkInit();
        if (g_framePauseFlag != 0) return;
        g_currentNodeIdx = 0x50b208u >> 2;
        LoadGeoAsset_Default();
        if (g_framePauseFlag != 0) return;
        g_slot74 = 0x51;
        Push16Call();

        do {
            g_xformEntityIdx = 0x50fb94u >> 2;
            DispatcherComplex260_MStackBracket1_TreeWalkRecursive2();
            if (g_framePauseFlag != 0) return;
            if ((g_stateBits8c & 4u) != 0) break;
            MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x54) = 0xff9d0000u;
            g_walkSlot6c = 0x1f;
            MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x30) = 0x1f;
            PushSetCallPop();
            if (g_framePauseFlag != 0) return;

            g_xformEntityIdx = 0x50fbb0u >> 2;
            DispatcherComplex260_MStackBracket1_TreeWalkRecursive2();
            if (g_framePauseFlag != 0) return;
            if ((g_stateBits8c & 4u) != 0) break;
            MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x54) = 0x640000u;
            g_walkSlot6c = 0x1f;
            MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x30) = 0x1f;
            PushSetCallPop();
            if (g_framePauseFlag != 0) return;

            g_xformEntityIdx = 0x50d1e8u >> 2;
            DispatcherComplex260_MStackBracket1_TreeWalkRecursive2();
            if (g_framePauseFlag != 0) return;
            if ((g_stateBits8c & 4u) != 0) break;
            MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x30) = 0x24e;
            MStackCall_MStackPush2ChainPrepend_00406340();
            if (g_framePauseFlag != 0) return;

            node = g_currentNodeIdx;
            MK4_NODE_AT(unsigned int, node, 0x54) = 0xffffaccdu;
            MK4_NODE_AT(unsigned int, node, 0x58) = 0x1893;
            MK4_NODE_AT(unsigned int, node, 0x5c) = 0xfffccccdu;
            g_fightGroupHead = node;

            node = g_titleLogoNode;
            g_currentNodeIdx = node;
            g_walkSlot6c = 0;
            MK4_NODE_AT(unsigned int, node, 0x60) = 0;
            MK4_NODE_AT(unsigned int, node, 0x64) = 0;
            MK4_NODE_AT(unsigned int, node, 0x68) = 0;
            MK4_NODE_AT(unsigned int, node, 0x54) = 0;
            MK4_NODE_AT(unsigned int, node, 0x58) = 0;
            MK4_NODE_AT(unsigned int, node, 0x5c) = 0xfffb0000u;
            StoreTwoCall((int)BLINK_VA, 0x235);
        } while (0);

        MK4_NODE_AT(unsigned int, g_baseSel, 0x30) = 0;
        MK4_NODE_AT(unsigned int, g_baseSel, 0x34) = 0;
        MK4_NODE_AT(unsigned int, g_baseSel, 0x38) = 0;
        GuardedSetupCallTailJmp(0x4d55e8u, 0x820000u);
        MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x5c) = 0x14000;
        MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x54) += 0xff7e0000u;
        GuardedSetupCallTailJmp(0x4d55f8u, 0x820000u);
        MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x5c) = 0x14000;
        MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x54) += 0x820000u;

        MK4_NODE_AT(unsigned int, g_baseSel, 8) = ARCADE_VA;
        MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 3;
        g_pendingNodeType = 1;
        g_framePauseFlag = 1;
        return;
    }

    default:                                     /* 0x4a9cf4: PER FRAME */
        break;
    }

    g_currentNodeIdx = MK4_NODE_AT(unsigned int, g_baseSel, 0x34);
    MStackPush2ChainLLInsert();
    g_currentNodeIdx = MK4_NODE_AT(unsigned int, g_baseSel, 0x38);
    MStackPush2ChainLLInsert();

    aj_label(g_joinedP1 != 0, 0x960000u, 0xff7e0000u);
    MK4_NODE_AT(unsigned int, g_baseSel, 0x34) = g_currentNodeIdx;
    aj_label(g_joinedP2 != 0, 0x960000u, 0x820000u);
    MK4_NODE_AT(unsigned int, g_baseSel, 0x38) = g_currentNodeIdx;

    if (g_joinedP1 == 0) Helper_AudioStub_4140();
    if (g_joinedP2 == 0) Helper_AudioStub_4160();

    if (g_fightGroupHead == 0) {                 /* 0x4aa013 */
        g_slot70 = 0x20;
        aj_chain(1);
        InstallSelfPackedF80();
        g_framePauseFlag = 1;
        return;
    }

    {   /* slide the arrow to the selected row */
        unsigned int sel = MK4_NODE_AT(unsigned int, g_baseSel, 0x30);

        if (sel == 0 || sel == 1) {
            unsigned int v = sel ? 0x51ebu : 0xffffaccdu;

            g_walkSlot6c = v;
            MK4_NODE_AT(unsigned int, g_fightGroupHead, 0x54) = v;
        }
    }

    {   /* the CONTROLLER / PLAYERS toggle off 0x4d50a4 */
        unsigned int a = g_padByte50a4;

        if ((a & 4u) != 0 && (a & 0x400u) != 0) {
            if ((a & 8u) == 0 || (a & 0x800u) == 0) {
                if (MK4_NODE_AT(unsigned int, g_baseSel, 0x30) != 1) {
                    SetJmp_Push16Call_004a1ad0();
                    MK4_NODE_AT(unsigned int, g_baseSel, 0x30) = 1;
                }
                g_joinIdle = 0;
            }
        } else {
            if (MK4_NODE_AT(unsigned int, g_baseSel, 0x30) != 0) {
                SetJmp_Push16Call_004a1ad0();
                MK4_NODE_AT(unsigned int, g_baseSel, 0x30) = 0;
            }
            g_joinIdle = 0;
        }
    }

    /* P1: first press joins, a second one drops the arrow again */
    if (InputPollFlagBits() != 0 || MovsxAnd4Shr() != 0
        || (g_joinedP1 != 0 && TestQueueGateState() != 0)) {
        g_joinIdle = 0;
        if (g_joinedP1 != 0) {
            g_currentNodeIdx = g_fightGroupHead;
            MStackPush2ChainLLInsert();
            g_fightGroupHead = 0;
            g_slot74 = 0x32a;
            Push16Call();
            TripleStageRollback(0x235);
        } else {
            g_joinedP1 = 1;
            SetJmp_Push16Call_004a1ac0();
        }
    }
    /* P2, the same shape */
    if (InputPollFlagBitsHalf() != 0 || MovsxAnd20Shr5() != 0
        || (g_joinedP2 != 0 && TestQueueGateState() != 0)) {
        g_joinIdle = 0;
        if (g_joinedP2 != 0) {
            g_currentNodeIdx = g_fightGroupHead;
            MStackPush2ChainLLInsert();
            g_fightGroupHead = 0;
            g_slot74 = 0x32a;
            Push16Call();
            TripleStageRollback(0x235);
        } else {
            g_joinedP2 = 1;
            SetJmp_Push16Call_004a1ac0();
        }
    }

    g_joinIdle += 1;
    if ((int)g_joinIdle > 0x708) {               /* 0x4aa018: time out forward */
        g_slot70 = 0x20;
        aj_chain(1);
        InstallSelfPackedF80();
        g_framePauseFlag = 1;
        return;
    }
    if (RetZero_004a1c40() != 0) {               /* back out to the menu */
        g_slot74 = 0x32f;
        Push16Call();
        g_slot70 = 0x20;
        aj_chain(2);
        InstallSelfPackedF80();
        g_framePauseFlag = 1;
        return;
    }

    MK4_NODE_AT(unsigned int, g_baseSel, 8) = ARCADE_VA;
    MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 3;
    g_pendingNodeType = 1;
    g_framePauseFlag = 1;
}

#endif /* NON_MATCHING */
