/**
 * The CHARACTER SELECT screen itself: AmbientMonitorCluster (0x49e3c0) and
 * the three controllers packed behind it in the same 1047-byte symbol.
 *
 * SceneEvalFsm calls the first for the build and installs the other three by
 * VA, so all three need config/codeptr_extras.yaml entries - by VA is the
 * only way anything reaches them.
 *
 *   AmbientMonitorCluster (0x49e3c0) - the BUILD. Re-enter the scene, flatten
 *     the title node (its scale triple zeroed by ZeroThreeFields, position
 *     zeroed, z parked at 0xff830000), load the select screen's .geo at
 *     0x50b118 twice - once for the geometry, once for the textures, the
 *     loader's own two-pass shape - then CopyGlobal and the flag block that
 *     arms the two pickers: 0x541d88 / 0x537ea8 / 0x537f88 set to 1,
 *     0x537e90 to 5, and five more cleared.
 *   0x49e490 (tag 0x251) - the IDLE TIMEOUT. Command 0 loads 0x5380e4 with
 *     0x14, or 0x19 when g_dlMode is set. Every later tick counts it down at
 *     0x3c-tick intervals; at zero it probes tags 0x23d, 0x23e, 0x242, 0x243
 *     and, if none of them is still in the chain, installs the two pickers
 *     (0x49e610 tag 0x252, 0x49e700 tag 0x253). With a player still active
 *     it just pauses; with neither, it re-enters the scene and hands off to
 *     GuardedSeq_ZeroTriple_then_PendingMatch - the attract path.
 *   0x49e610 (tag 0x252) and 0x49e700 (tag 0x253) - P1's and P2's PICKERS,
 *     the same body against different globals. Each waits until its three
 *     tags are clear (0x15 / 0x23d / 0x242 for P1, 0x16 / 0x23e / 0x243 for
 *     P2), then reads its phase word - 0x537f88 for P1, 0x537e90 for P2 -
 *     and at 0x12 installs the confirm controller (0x49f190 / 0x49f1c0,
 *     packed inside ThrowAnimTriggerCluster) and parks as state 1; otherwise
 *     it runs the cursor step - GameNetSyncState for P1,
 *     AudioCmpCascadeDispatcher for P2 - and parks as state 2 on a 5-tick
 *     beat, or pauses outright when g_dlMode is clear.
 *   ZeroThreeFields_00404ed0 - zero a node's +0x60/+0x64/+0x68 scale triple.
 *
 * Still hollow above this: GameNetSyncState (0x49fb70, 473b),
 * AudioCmpCascadeDispatcher (0x49fd50, 469b) - the two cursor steps - and
 * ThrowAnimTriggerCluster (0x49efa0, 578b), which carries the confirm pair.
 *
 * NATIVE-ONLY twins: the matching build synthesizes the original bytes.
 */
#ifdef NON_MATCHING

#include "portable/mem_model.h"

extern void BootInitGuardedCallChain(void);
extern void LoadGeoAsset_Default(void);
extern void CopyGlobal(void);
extern void StoreTwoCall(int fn, int arg);
extern void CallSetPause(void);
extern void GuardedSeq_ZeroTriple_then_PendingMatch(void);
extern void DualPushSetCallDualPop(unsigned int tag);
/* still hollow - the two cursor steps */
extern void GameNetSyncState(void);
extern void AudioCmpCascadeDispatcher(void);
extern void DispatcherComplex260_MStackBracket1_TreeWalkRecursive2(void);
extern void MStackBracket4_ListInsertZeroFill(void);
extern void MStackPush3LinkedListWalk(void);
extern void MStackPush4LLWalkPop4(void);
extern void MStackCall_MStackPush2ChainPrepend_00406340(void);
extern void RoundWinTransition(void);
extern void GameStateTick(void);


#define g_currentNodeIdx  (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_pendingNodeType (*(unsigned int *)MK4_VA(unsigned int, 0x54204cu))
#define g_baseSel         (*(unsigned int *)MK4_VA(unsigned int, 0x542060u))
#define g_walkSlot6c      (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#define g_stateBits8c     (*(unsigned int *)MK4_VA(unsigned int, 0x54208cu))
#define g_framePauseFlag  (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#define g_titleLogoNode   (*(unsigned int *)MK4_VA(unsigned int, 0x52ab10u))
#define g_activeP1        (*(unsigned int *)MK4_VA(unsigned int, 0x53a408u))
#define g_activeP2        (*(unsigned int *)MK4_VA(unsigned int, 0x537e88u))
#define g_dlMode          (*(unsigned int *)MK4_VA(unsigned int, 0x542004u))
#define g_selectIdle      (*(unsigned int *)MK4_VA(unsigned int, 0x5380e4u))
#define g_phaseP1         (*(unsigned int *)MK4_VA(unsigned int, 0x537f88u))
#define g_phaseP2         (*(unsigned int *)MK4_VA(unsigned int, 0x537e90u))
#define g_xformEntityIdx  (*(unsigned int *)MK4_VA(unsigned int, 0x542048u))
#define g_fightGroupHead  (*(unsigned int *)MK4_VA(unsigned int, 0x54205cu))
#define g_slot70          (*(unsigned int *)MK4_VA(unsigned int, 0x542070u))
#define g_matrixStackTop  (*(unsigned int *)MK4_VA(unsigned int, 0x4d57acu))
#define g_charSelectCam   (*(unsigned int *)MK4_VA(unsigned int, 0x535e6cu))

#define IDLE_VA   0x49e490u
#define PICK1_VA  0x49e610u
#define PICK2_VA  0x49e700u

/* 0x404ed0 */
void ZeroThreeFields_00404ed0(void)
{
    unsigned int node = g_currentNodeIdx;

    MK4_NODE_AT(unsigned int, node, 0x60) = 0;
    MK4_NODE_AT(unsigned int, node, 0x64) = 0;
    g_walkSlot6c = 0;
    MK4_NODE_AT(unsigned int, node, 0x68) = 0;
}

/* 0x49e3c0 - BUILD */
void AmbientMonitorCluster(void)
{
    unsigned int node;

    BootInitGuardedCallChain();
    if (g_framePauseFlag != 0) return;

    node = g_titleLogoNode;
    g_currentNodeIdx = node;
    ZeroThreeFields_00404ed0();
    MK4_NODE_AT(unsigned int, node, 0x54) = 0;
    MK4_NODE_AT(unsigned int, node, 0x58) = 0;
    g_walkSlot6c = 0xff830000u;
    MK4_NODE_AT(unsigned int, node, 0x5c) = 0xff830000u;

    g_currentNodeIdx = 0x50b118u >> 2;
    LoadGeoAsset_Default();
    if (g_framePauseFlag != 0) return;
    g_currentNodeIdx = 0x50b118u >> 2;
    LoadGeoAsset_Default();
    if (g_framePauseFlag != 0) return;

    g_walkSlot6c = 0;
    CopyGlobal();
    if (g_framePauseFlag != 0) return;

    *MK4_VA(unsigned int, 0x538090u) = 0;
    *MK4_VA(unsigned int, 0x541d88u) = 1;
    *MK4_VA(unsigned int, 0x537ea8u) = 1;
    g_phaseP1 = 1;
    *MK4_VA(unsigned int, 0x53a1bcu) = 0;
    *MK4_VA(unsigned int, 0x53a354u) = 0;
    *MK4_VA(unsigned int, 0x541dd4u) = 0;
    *MK4_VA(unsigned int, 0x53a2e8u) = 0;
    g_walkSlot6c = 5;
    g_phaseP2 = 5;
}

/* park this controller as state N on a `type` beat */
static void cs_rearm(unsigned int va, unsigned int state, unsigned int type)
{
    MK4_NODE_AT(unsigned int, g_baseSel, 8) = va;
    MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = state;
    g_pendingNodeType = type;
    g_framePauseFlag = 1;
}

/* 0x49e490 - the idle timeout */
void CharSelect_IdleTimeout_0049e490(void)
{
    unsigned int cmd = MK4_NODE_AT(unsigned int, g_baseSel, 0x84);

    MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 0;

    if (cmd == 0) {                              /* 0x49e5c3: seed it */
        g_selectIdle = 0x14;
        g_walkSlot6c = g_dlMode;
        if (g_dlMode != 0) {
            g_walkSlot6c = 0x19;
            g_selectIdle = 0x19;
        }
        cs_rearm(IDLE_VA, 1, 0x3c);
        return;
    }

    g_walkSlot6c = g_selectIdle - 1;
    g_selectIdle = g_selectIdle - 1;
    if (g_selectIdle != 0) {
        cs_rearm(IDLE_VA, 1, 0x3c);
        return;
    }

    g_walkSlot6c = 5;
    g_selectIdle = 5;
#ifdef TARGET_SDL
    /* MK4_TRACE_IDLE: which of the four "a player is still busy" probes
     * blocks the pickers from being installed. All four clear is the only
     * way 0x252 / 0x253 ever get created. */
#define CS_PROBE(T) do { DualPushSetCallDualPop(T); \
        { extern void SDL_Log(const char *, ...); extern char *getenv(const char *); \
          static unsigned n_##T; \
          if (getenv("MK4_TRACE_IDLE") && n_##T < 4) { n_##T++; \
              SDL_Log("IDLE probe %x -> dirty %u", T, g_stateBits8c & 1u); } } \
        if ((g_stateBits8c & 1u) != 0) { cs_rearm(IDLE_VA, 1, 0x3c); return; } \
    } while (0)
#else
#define CS_PROBE(T) do { DualPushSetCallDualPop(T); \
        if ((g_stateBits8c & 1u) != 0) { cs_rearm(IDLE_VA, 1, 0x3c); return; } \
    } while (0)
#endif
    CS_PROBE(0x23d);
    CS_PROBE(0x23e);
    CS_PROBE(0x242);
    CS_PROBE(0x243);
#undef CS_PROBE

    StoreTwoCall((int)PICK1_VA, 0x252);
    StoreTwoCall((int)PICK2_VA, 0x253);

    g_walkSlot6c = g_activeP1;
    if (g_activeP1 == 0) {
        g_walkSlot6c = g_activeP2;
        if (g_activeP2 == 0) {
            BootInitGuardedCallChain();
            if (g_framePauseFlag != 0) return;
            g_walkSlot6c = 0x1000;
            MK4_NODE_AT(unsigned int, g_baseSel, 0xc) = 0x1000;
            GuardedSeq_ZeroTriple_then_PendingMatch();
            return;
        }
    }
    CallSetPause();
}

/* the shared picker body: 0x49e610 for P1, 0x49e700 for P2 */
static void cs_picker(unsigned int selfVA, unsigned int cmd,
                      unsigned int tagA, unsigned int tagB, unsigned int tagC,
                      unsigned int phase, unsigned int confirmVA,
                      void (*cursorStep)(void))
{
    if (cmd >= 2) {
        DualPushSetCallDualPop(tagA);
        if ((g_stateBits8c & 1u) != 0) { cs_rearm(selfVA, 2, 5); return; }
        DualPushSetCallDualPop(tagB);
        if ((g_stateBits8c & 1u) != 0) { cs_rearm(selfVA, 2, 5); return; }
        DualPushSetCallDualPop(tagC);
        if ((g_stateBits8c & 1u) != 0) { cs_rearm(selfVA, 2, 5); return; }
    }
    if (cmd != 1) {                              /* cmd 0 and the fall-through */
        g_walkSlot6c = phase;
        if (phase == 0x12) {                     /* picked: install confirm */
            StoreTwoCall((int)confirmVA, 0x11);
            cs_rearm(selfVA, 1, 1);
            return;
        }
    }
    cursorStep();
    if (g_framePauseFlag != 0) return;
    g_walkSlot6c = g_dlMode;
    if (g_dlMode == 0) {
        CallSetPause();
        return;
    }
    cs_rearm(selfVA, 2, 5);
}

/* 0x49e610 */
void CharSelect_PickerP1_0049e610(void)
{
    unsigned int cmd = MK4_NODE_AT(unsigned int, g_baseSel, 0x84);

    MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 0;
    cs_picker(PICK1_VA, cmd, 0x15, 0x23d, 0x242, g_phaseP1, 0x49f190u,
              GameNetSyncState);
}

/* 0x49e700 */
void CharSelect_PickerP2_0049e700(void)
{
    unsigned int cmd = MK4_NODE_AT(unsigned int, g_baseSel, 0x84);

    MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 0;
    cs_picker(PICK2_VA, cmd, 0x16, 0x23e, 0x243, g_phaseP2, 0x49f1c0u,
              AudioCmpCascadeDispatcher);
}

/* 0x49efa0 - the select screen's SCENE: spawn the frame record 0x50c0bc,
 * insert it, walk in the second record 0x50a0f0, park the result at the
 * origin with kind 6, chain-prepend it, mark +0x34 bit 0x10000 and link the
 * camera (0x535e6c) into its +0x3c after placing the camera at
 * (0x10000, 0, 0xffff8000). All of it under an mstack save of
 * currentNodeIdx / xformEntityIdx / fightGroupHead, and the spawn-dirty exit
 * skips straight to the pops. RoundWinTransition, which puts the two
 * fighters' portraits in, is still hollow. */
void ThrowAnimTriggerCluster(void)
{
    unsigned int top, node, frame, cam;

    top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    *(unsigned int *)MK4_PTR(top * 4) = g_currentNodeIdx;
    top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    *(unsigned int *)MK4_PTR(top * 4) = g_xformEntityIdx;
    top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    *(unsigned int *)MK4_PTR(top * 4) = g_fightGroupHead;

    g_xformEntityIdx = 0x50c0bcu >> 2;
    DispatcherComplex260_MStackBracket1_TreeWalkRecursive2();
    if (g_framePauseFlag != 0) return;           /* mstack leak, as original */
#ifdef TARGET_SDL
    { extern void SDL_Log(const char *, ...); extern char *getenv(const char *);
      if (getenv("MK4_TRACE_TATC"))
          SDL_Log("TATC spawn 0x50c0bc -> node=%x bits=%x", g_currentNodeIdx,
                  g_stateBits8c); }
#endif
    if ((g_stateBits8c & 4u) != 0) goto pops;

    MStackBracket4_ListInsertZeroFill();
    if (g_framePauseFlag != 0) return;
    MStackPush3LinkedListWalk();
    if (g_framePauseFlag != 0) return;

    g_xformEntityIdx = 0x50a0f0u >> 2;
    MStackPush4LLWalkPop4();
    if (g_framePauseFlag != 0) return;

    node = g_currentNodeIdx;
    g_walkSlot6c = 0;
    MK4_NODE_AT(unsigned int, node, 0x54) = 0;
    MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x58) = g_walkSlot6c;
    MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x5c) = g_walkSlot6c;
    g_walkSlot6c = 6;
    MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x30) = 6;
    MStackCall_MStackPush2ChainPrepend_00406340();
    if (g_framePauseFlag != 0) return;

    frame = g_currentNodeIdx;
    g_slot70 = 0x10000;
    MK4_NODE_AT(unsigned int, frame, 0x34) |= 0x10000u;
    g_pendingNodeType = g_currentNodeIdx;

    cam = g_charSelectCam;
    g_currentNodeIdx = cam;
    MK4_NODE_AT(unsigned int, cam, 0x54) = 0x10000;
    MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x58) = 0;
    g_walkSlot6c = 0xffff8000u;
    MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x5c) = 0xffff8000u;
    MK4_NODE_AT(unsigned int, g_pendingNodeType, 0x3c) = g_currentNodeIdx;

    RoundWinTransition();
    if (g_framePauseFlag != 0) return;

pops:
    top = g_matrixStackTop;
    g_fightGroupHead = *(unsigned int *)MK4_PTR(top * 4);
    top -= 1;
    g_matrixStackTop = top;
    g_xformEntityIdx = *(unsigned int *)MK4_PTR(top * 4);
    top -= 1;
    g_matrixStackTop = top;
    g_currentNodeIdx = *(unsigned int *)MK4_PTR(top * 4);
    g_matrixStackTop = top - 1;
}

/* 0x49f190 / 0x49f1c0 turned out NOT to be confirm controllers: they are
 * the character select's UP direction stubs, and they live in
 * src/game/select_cursor_step.c with the rest of that family. */

#endif /* NON_MATCHING */
