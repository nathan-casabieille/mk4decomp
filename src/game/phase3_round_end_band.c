/**
 * The PHASE-3 / ROUND-END band: Phase3InstallSelfChain (0x421380), the exit
 * every pass of Screen_ArcadeEnding's round loop takes, and the leaves it
 * needs. With the round gate up (the walk-in band's job, MK4_BOOT_ROUND
 * meanwhile), the sequencer reached its round loop for the first time in
 * 939a2edcb and parked exactly here.
 *
 * Phase3InstallSelfChain routes three ways:
 *   cmd 0: flag 0x52d724, the stage event push (TwinMStackPushScaledChain)
 *          unless flags bit 3 says not to, then chain(1) + RoundEndFsm -
 *          the round OUTRO.
 *   cmd 1, round count == the ovr limit: the MATCH is decided -
 *          PendingMatch_0042d240 (tail).
 *   cmd 1, otherwise: next round - bump 0x537f30, CallPauseClear3CallTriple
 *          (clears the fighter node slots 0x538158/0x53815c and re-runs the
 *          stage copy), ScenegraphWalk (unlink every node but the
 *          controller), and tail back into Screen_ArcadeEnding.
 *
 * Interior entries, both nop-padded tails of their symbols:
 *   RoundStartFighterInit (0x4214a0, in Phase3InstallSelfChain's symbol):
 *          the per-fighter round-start controller MkIntroFsm installs via
 *          Thunk_ChainNodeInit - xform init, record clears, the walk bits,
 *          tailing into the 0x4314f0 keep-alive.
 *   StageEventRearm (0x422200, in TwinMStackPushScaledChain's symbol): the
 *          stage MUSIC re-arm - on command, re-push the stage's event id + 2
 *          unless flags bit 3 or a live stream (0x53a430) says not to, then
 *          CallSetPause; unfired it parks with a 0x28 countdown.
 *
 * The audio leaves share one shape: clear a bit of 0x53a7b0 and stop the
 * parked 3D source handle (0x541fa4 / 0x541fa8) through Snd3DSourceCleanup.
 *
 * ScenegraphWalk (0x41f7d0) walks the node ARENA 0x53e368..0x541d68 stride
 * 0xe8 and NodeUnlinks every live node (+0xd8 set) except the current
 * controller. A host-pointer twin of it exists in the unlinked shell
 * src/boot/scenegraph_walk.c; this one is the arena spelling.
 *
 * NATIVE-ONLY twins: the matching build synthesizes the original bytes.
 */
#ifdef NON_MATCHING

#include "portable/mem_model.h"

extern void SwapOrPassSet(void);
extern void PendingMatch_0042d240(void);
extern void Screen_ArcadeEnding(void);
extern void RoundEndFsm(void);
extern void NodeUnlink(void *node);
extern void BootInitChainHeavy(void);
extern void DualEntryInitCmp(void);
extern void StageParticleEmitterInit(void);
extern void FiveFieldChainCopyTableWalk(void);
extern void Push16Call(void);
extern void CallSetPause(void);
extern void Snd3DSourceCleanup(int a, int b);
extern void ScaledInit_GuardedDirtyXformFromTable_g_scaledInit(void);
extern void CopyJmp_GuardedChainPushSetCallPop_g_currentNodeIdx(void);
extern void ScaledZero44(void);
extern void ScaledZeroFour(void);
extern void MStackPushSet0001(void);
extern void MStackPushSet0004(void);

#define g_currentNodeIdx  (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_pendingNodeType (*(unsigned int *)MK4_VA(unsigned int, 0x54204cu))
#define g_baseSel         (*(unsigned int *)MK4_VA(unsigned int, 0x542060u))
#define g_walkSlot6c      (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#define g_slot70          (*(unsigned int *)MK4_VA(unsigned int, 0x542070u))
#define g_slot74          (*(unsigned int *)MK4_VA(unsigned int, 0x542074u))
#define g_scratch94       (*(unsigned int *)MK4_VA(unsigned int, 0x542094u))
#define g_framePauseFlag  (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#define g_matrixStackTop  (*(unsigned int *)MK4_VA(unsigned int, 0x4d57acu))
#define g_flags52ab40     (*(unsigned int *)MK4_VA(unsigned int, 0x52ab40u))
#define g_flag52d724      (*(unsigned int *)MK4_VA(unsigned int, 0x52d724u))
#define g_ovrValue        (*(unsigned int *)MK4_VA(unsigned int, 0x4f3608u))
#define g_roundNumber     (*(unsigned int *)MK4_VA(unsigned int, 0x537f30u))
#define g_p1NodeSlot      (*(unsigned int *)MK4_VA(unsigned int, 0x538158u))
#define g_p2NodeSlot      (*(unsigned int *)MK4_VA(unsigned int, 0x53815cu))
#define g_stageIdx        (*(unsigned int *)MK4_VA(unsigned int, 0x53a51cu))
#define g_sndBits53a7b0   (*(unsigned int *)MK4_VA(unsigned int, 0x53a7b0u))
#define g_sndHandleA      (*(unsigned int *)MK4_VA(unsigned int, 0x541fa4u))
#define g_sndHandleB      (*(unsigned int *)MK4_VA(unsigned int, 0x541fa8u))
#define g_streamState     (*(unsigned int *)MK4_VA(unsigned int, 0x53a430u))

void PushArgPushNeg1Call(int handle)
{
    Snd3DSourceCleanup(-1, handle);
}

void SlideAttackEventCluster(void)
{
    unsigned int v = g_sndBits53a7b0 & ~1u;

    g_slot70 = v;
    g_sndBits53a7b0 = v;
    if (g_sndHandleA != 0) {
        PushArgPushNeg1Call((int)g_sndHandleA);
        g_sndHandleA = 0;
    }
}

void AndStorePushCallZero(void)
{
    unsigned int v = g_sndBits53a7b0 & ~2u;

    g_slot70 = v;
    g_sndBits53a7b0 = v;
    if (g_sndHandleB != 0) {
        PushArgPushNeg1Call((int)g_sndHandleB);
        g_sndHandleB = 0;
    }
}

void ScenegraphWalk(void)
{
    unsigned int va;

    unsigned int n = 0;

    for (va = 0x53e368u; va < 0x541d68u; va += 0xe8u) {
        if (*MK4_VA(unsigned int, va + 0xd8u) == 0)
            continue;
        g_currentNodeIdx = va >> 2;
        if ((va >> 2) == g_baseSel)
            continue;
        NodeUnlink(MK4_VA(void, va));
        n++;
    }
#ifdef TARGET_SDL
    { extern void SDL_Log(const char *, ...); extern char *getenv(const char *);
      if (getenv("MK4_TRACE_P3"))
          SDL_Log("P3 scenegraph sweep: %u nodes unlinked, head 0x%x", n,
                  *MK4_VA(unsigned int, 0x52ab3cu)); }
#endif
}

void CallPauseClear3CallTriple(void)
{
    BootInitChainHeavy();
    if (g_framePauseFlag != 0) return;
    g_walkSlot6c = 0;
    g_p1NodeSlot = 0;
    g_p2NodeSlot = 0;
    DualEntryInitCmp();
    if (g_framePauseFlag != 0) return;
    StageParticleEmitterInit();
    if (g_framePauseFlag != 0) return;
    FiveFieldChainCopyTableWalk();               /* jmp in the original */
}

void TwinMStackPushScaledChain(void)
{
    unsigned int stage = g_stageIdx;
    unsigned int top;

    /* the stage's event base lives in the word table at 0x4dfd18 */
    g_walkSlot6c = stage;
    g_currentNodeIdx = (0x4dfd18u >> 2) + stage;
    g_slot74 = *MK4_VA(unsigned int, 0x4dfd18u + stage * 4u) + 3;
    Push16Call();
    if (g_framePauseFlag != 0) return;

    top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    *(unsigned int *)MK4_PTR(top * 4) = g_walkSlot6c;
    top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    *(unsigned int *)MK4_PTR(top * 4) = g_slot70;
    top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    *(unsigned int *)MK4_PTR(top * 4) = g_slot74;

    SlideAttackEventCluster();
    if (g_framePauseFlag != 0) return;
    AndStorePushCallZero();
    if (g_framePauseFlag != 0) return;

    top = g_matrixStackTop;
    g_slot74 = *(unsigned int *)MK4_PTR(top * 4);
    top -= 1;
    g_matrixStackTop = top;
    g_slot70 = *(unsigned int *)MK4_PTR(top * 4);
    g_matrixStackTop = top - 2;
    g_walkSlot6c = 0;
    g_sndBits53a7b0 = 0;
}

/* 0x422200, packed after TwinMStackPushScaledChain */
void StageEventRearm_00422200(void)
{
    unsigned int cmd;

    cmd = MK4_NODE_AT(unsigned int, g_baseSel, 0x84);
    MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 0;

    if (cmd != 0) {
        unsigned int flags = g_flags52ab40;

        g_walkSlot6c = flags;
        g_scratch94 = flags & 8;
        if ((flags & 8) == 0) {
            g_walkSlot6c = g_streamState;
            if (g_streamState == 0) {
                unsigned int stage = g_stageIdx;

                g_walkSlot6c = stage;
                g_currentNodeIdx = (0x4dfd18u >> 2) + stage;
                g_slot74 = *MK4_VA(unsigned int, 0x4dfd18u + stage * 4u) + 2;
                Push16Call();
                if (g_framePauseFlag != 0) return;
            }
        }
        CallSetPause();                          /* jmp in the original */
        return;
    }
    MK4_NODE_AT(unsigned int, g_baseSel, 8) = 0x422200u;
    MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 1;
    g_pendingNodeType = 0x28;
    g_framePauseFlag = 1;
}

void ScaledInitWithCounterAndType_004314f0(void)
{
    MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 0;
    MK4_NODE_AT(unsigned int, g_baseSel, 8) = 0x4314f0u;
    MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 1;
    g_pendingNodeType = 0x28;
    g_framePauseFlag = 1;
}

/* 0x4214a0, packed after Phase3InstallSelfChain: the per-fighter
 * round-start controller MkIntroFsm installs */
void RoundStartFighterInit_004214a0(void)
{
    ScaledInit_GuardedDirtyXformFromTable_g_scaledInit();
    if (g_framePauseFlag != 0) return;
    CopyJmp_GuardedChainPushSetCallPop_g_currentNodeIdx();
    if (g_framePauseFlag != 0) return;
    ScaledZero44();
    if (g_framePauseFlag != 0) return;
    ScaledZeroFour();
    if (g_framePauseFlag != 0) return;
    MStackPushSet0001();
    if (g_framePauseFlag != 0) return;
    MStackPushSet0004();
    if (g_framePauseFlag != 0) return;
    ScaledInitWithCounterAndType_004314f0();     /* jmp in the original */
}

void Phase3InstallSelfChain(void)
{
    unsigned int cmd, q;

    cmd = MK4_NODE_AT(unsigned int, g_baseSel, 0x84);
    MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 0;

    if (cmd != 0) {
        SwapOrPassSet();
        if (g_framePauseFlag != 0) return;
#ifdef TARGET_SDL
        { extern void SDL_Log(const char *, ...); extern char *getenv(const char *);
          if (getenv("MK4_TRACE_P3"))
              SDL_Log("P3 cmd=%u walk6c=0x%x ovr=0x%x round=%u -> %s", cmd,
                      g_walkSlot6c, g_ovrValue, g_roundNumber,
                      (g_walkSlot6c == g_ovrValue) ? "MATCH DECIDED" : "NEXT ROUND"); }
#endif
        if (g_walkSlot6c == g_ovrValue) {
            PendingMatch_0042d240();             /* the match is decided */
            return;
        }
        g_walkSlot6c = g_roundNumber + 1;        /* next round */
        g_roundNumber = g_walkSlot6c;
        CallPauseClear3CallTriple();
        if (g_framePauseFlag != 0) return;
        ScenegraphWalk();
        if (g_framePauseFlag != 0) return;
        Screen_ArcadeEnding();
        return;
    }

    g_flag52d724 = 1;
    g_walkSlot6c = g_flags52ab40;
    g_scratch94 = g_flags52ab40 & 8;
    if ((g_flags52ab40 & 8) == 0) {
        TwinMStackPushScaledChain();
        if (g_framePauseFlag != 0) return;
    }
    MK4_NODE_AT(unsigned int, g_baseSel, 8) = 0x421380u;
    MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 1;
    q = MK4_NODE_AT(unsigned int, g_baseSel, 4);
    g_currentNodeIdx = q;
    *(unsigned int *)MK4_PTR(q * 4) = 0x421380u + 0x1000000u;
    g_currentNodeIdx = q + 1;
    MK4_NODE_AT(unsigned int, g_baseSel, 4) = q + 1;
    MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 0;
    RoundEndFsm();
    g_framePauseFlag = 1;
}

#endif /* NON_MATCHING */
