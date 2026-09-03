/**
 * The ROUND INTRO band: what runs between "the match scene is built" and
 * "FIGHT!". Screen_ArcadeEnding hands its state-5 frame slice to
 * Install3WayCountdownGame, and its walk-in path (state 5 with the round
 * flag clear) to MkIntroFsm; both were weak stubs, which is why the boot
 * chain parked on a live match screen (f9d23be66) - the queued continuation
 * waits for a StackPopDispatchTagged that a no-op never performs.
 *
 * Install3WayCountdownGame (0x421b00, 214b): the round countdown. First
 * visit arms the count (0x23 at slot +0x80) and derives the round TIMER
 * from the demo key (9 with 0x7af91c up, 99 without - neg/sbb/and/add/xor
 * in the original), parking it in 0x53a718, the count the fight HUD shows. Each later visit decrements the count while 0x543438 (the pause
 * hold) is clear; at zero DecBoundCheckCallJmp steps the countdown word
 * itself, fires the tick sound below 0x15 through event table 112, and
 * tails into PollThenInit. When the walk-in flag (0x54206c on entry) is
 * clear it pops the queue with 0x542070 = 0; when the round-start gate
 * 0x537f94 is already up it pops with 1.
 *
 * MkIntroFsm (0x4218b0, 584b): the walk-in intro. State 0 primes the
 * fighters - Push16Call event 0, a 0x4214a0 controller node on each
 * fighter group (an INTERIOR entry of Phase3InstallSelfChain, logged
 * unresolved until converted), the camera record at 0x4d56d8 walked into
 * place - and parks as state 1 with a 0x10 countdown. State 1 fires event
 * 0x2d (the ROUND announcement) through event table 112 and parks as
 * state 2 with 0x90. State 2 runs the 0x24b record under SaveCallRestore
 * and parks as state 3 with 8. State 3+ is the FIGHT! edge: when both
 * fighters' ready words (0x538160/0x538164) are up, or the energy ramp at
 * 0x53a6dc/0x537f2c meets, it raises the round gate 0x537f94 (2 on the
 * ready path, 1 on the ramp path) and pops the queue - the gate
 * MK4_BOOT_ROUND used to force.
 *
 * TableLookupCall_g_eventTbl_112 (0x489ff0) and its sibling _65 (0x48a130)
 * are the two audio event lookups: word tables at 0x4efa00 (0x71 entries)
 * and 0x4efd18 (0x42), a zero word meaning no sound, dispatched through
 * TaggedSceneDispatch. ScaledStoreE0 (0x41f550) parks its argument in the
 * controller node's +0xe0.
 *
 * NATIVE-ONLY twins: the matching build synthesizes the original bytes.
 */
#ifdef NON_MATCHING

#include "portable/mem_model.h"

extern void TaggedSceneDispatch(int tag);
extern void StackPopDispatchTagged(void);
extern void PollThenInit(void);
extern void Cmp2DirtyToggle(void);
extern void Push16Call(void);
extern void Thunk_ChainNodeInit(void);
extern void Push70CallScaleArith(void);
extern void DualAddSar(void);
extern void SaveCallRestore(int rec);

#define g_currentNodeIdx  (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_xformEntityIdx  (*(unsigned int *)MK4_VA(unsigned int, 0x542048u))
#define g_pendingNodeType (*(unsigned int *)MK4_VA(unsigned int, 0x54204cu))
#define g_baseSel         (*(unsigned int *)MK4_VA(unsigned int, 0x542060u))
#define g_walkSlot6c      (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#define g_slot70          (*(unsigned int *)MK4_VA(unsigned int, 0x542070u))
#define g_slot74          (*(unsigned int *)MK4_VA(unsigned int, 0x542074u))
#define g_slot78          (*(unsigned int *)MK4_VA(unsigned int, 0x542078u))
#define g_slot7c          (*(unsigned int *)MK4_VA(unsigned int, 0x54207cu))
#define g_slot80          (*(unsigned int *)MK4_VA(unsigned int, 0x542080u))
#define g_stateBits8c     (*(unsigned int *)MK4_VA(unsigned int, 0x54208cu))
#define g_framePauseFlag  (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#define g_pauseHold543438 (*(unsigned int *)MK4_VA(unsigned int, 0x543438u))
#define g_texXorKey       (*(unsigned int *)MK4_VA(unsigned int, 0x7af91cu))
#define g_roundCountdown  (*(unsigned int *)MK4_VA(unsigned int, 0x53a718u))
#define g_roundPhase      (*(unsigned int *)MK4_VA(unsigned int, 0x537f94u))
#define g_p1Group         (*(unsigned int *)MK4_VA(unsigned int, 0x538038u))
#define g_p2Group         (*(unsigned int *)MK4_VA(unsigned int, 0x53803cu))
#define g_readyP1         (*(unsigned int *)MK4_VA(unsigned int, 0x538160u))
#define g_readyP2         (*(unsigned int *)MK4_VA(unsigned int, 0x538164u))
#define g_rampA           (*(unsigned int *)MK4_VA(unsigned int, 0x53a6dcu))
#define g_rampB           (*(unsigned int *)MK4_VA(unsigned int, 0x537f2cu))
#define g_flag52d724      (*(unsigned int *)MK4_VA(unsigned int, 0x52d724u))

void TableLookupCall_g_eventTbl_112(void)
{
    unsigned int id = g_walkSlot6c;
    unsigned short w;

    if (id > 0x70)
        return;
    w = *MK4_VA(unsigned short, 0x4efa00u + id * 2u);
    if (w != 0)
        TaggedSceneDispatch((int)w);
}

void TableLookupCall_g_eventTbl_65(void)
{
    unsigned int id = g_walkSlot6c;
    unsigned short w;

    if (id > 0x41)
        return;
    w = *MK4_VA(unsigned short, 0x4efd18u + id * 2u);
    if (w != 0)
        TaggedSceneDispatch((int)w);
}

void ScaledStoreE0(unsigned int v)
{
    MK4_NODE_AT(unsigned int, g_baseSel, 0xe0) = v;
}

void DecBoundCheckCallJmp(void)
{
    unsigned int c = g_roundCountdown - 1;

    g_slot80 = 0x28;
    g_walkSlot6c = c;
    g_roundCountdown = c;
    if ((int)c < 0x14) {
        g_walkSlot6c = 0x32;                    /* the countdown tick sound */
        TableLookupCall_g_eventTbl_112();
        if (g_framePauseFlag != 0)
            return;
    }
    PollThenInit();                             /* jmp in the original */
}

void Install3WayCountdownGame(void)
{
    unsigned int cmd;

    cmd = MK4_NODE_AT(unsigned int, g_baseSel, 0x84);
    MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 0;

#ifdef TARGET_SDL
    { extern void SDL_Log(const char *, ...); extern char *getenv(const char *);
      static unsigned n;
      /* the first few visits matter as much as the periodic ones - a
       * controller that runs once and stops was invisible at %40 */
      if (getenv("MK4_TRACE_RIB") && (++n <= 3 || n % 40 == 0))
          SDL_Log("countdown visit %u cmd=%u slot80=%u timer=%u walk6c=0x%x phase=%u"
                  " node=%x cb=%08x q=%x",
                  n, cmd, g_slot80, g_roundCountdown, g_walkSlot6c, g_roundPhase,
                  g_baseSel, MK4_NODE_AT(unsigned int, g_baseSel, 0xd8),
                  MK4_NODE_AT(unsigned int, g_baseSel, 4)); }
#endif

    if (cmd == 0) {
        ScaledStoreE0(0x1000);
        g_slot80 = 0x23;
        /* the round timer: 99 with the demo key clear, 9 with it up - the
         * original spells it neg/sbb/and 0x5a/add 0x18/xor 0x7b over
         * 0x7af91c, which lands on 0x63 or 9 */
        g_walkSlot6c = (g_texXorKey != 0) ? 9u : 0x63u;
        g_roundCountdown = g_walkSlot6c;
    } else {
        if (g_pauseHold543438 == 0)
            g_slot80 -= 1;
        if (g_slot80 == 0) {
            DecBoundCheckCallJmp();
            if (g_framePauseFlag != 0)
                return;
        }
        if (g_walkSlot6c == 0) {
            g_slot70 = 0;
            StackPopDispatchTagged();
            return;
        }
        g_walkSlot6c = g_roundPhase;
        if (g_roundPhase != 0) {
            g_slot70 = 1;
            StackPopDispatchTagged();
            return;
        }
    }
    MK4_NODE_AT(unsigned int, g_baseSel, 8) = 0x421b00u;
    MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 1;
    g_pendingNodeType = 1;
    g_framePauseFlag = 1;
}

void MkIntroFsm(void)
{
    unsigned int cmd;

    cmd = MK4_NODE_AT(unsigned int, g_baseSel, 0x84);
    MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 0;

    if (cmd == 0) {
        g_slot74 = 0;
        Push16Call();
        if (g_framePauseFlag != 0) return;
        g_walkSlot6c = 1;
        g_flag52d724 = 1;
        g_currentNodeIdx = g_p1Group;
        g_xformEntityIdx = 0x4214a0u;
        Thunk_ChainNodeInit();
        if (g_framePauseFlag != 0) return;
        g_currentNodeIdx = g_p2Group;
        g_xformEntityIdx = 0x4214a0u;
        Thunk_ChainNodeInit();
        if (g_framePauseFlag != 0) return;
        g_walkSlot6c = 0x24b;
        g_slot70 = 4;
        g_slot78 = 0;
        g_slot7c = 0xffc90000u;
        g_xformEntityIdx = 0x4d56d8u >> 2;
        Push70CallScaleArith();
        if (g_framePauseFlag != 0) return;
        g_slot74 = 0x48;
        Push16Call();
        if (g_framePauseFlag != 0) return;
        MK4_NODE_AT(unsigned int, g_baseSel, 8) = 0x4218b0u;
        MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 1;
        g_pendingNodeType = 0x10;
        g_framePauseFlag = 1;
        return;
    }
    if (cmd == 1) {
        g_walkSlot6c = 0x2d;                    /* the ROUND announcement */
        TableLookupCall_g_eventTbl_112();
        if (g_framePauseFlag != 0) return;
        MK4_NODE_AT(unsigned int, g_baseSel, 8) = 0x4218b0u;
        MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 2;
        g_pendingNodeType = 0x90;
        g_framePauseFlag = 1;
        return;
    }
    if (cmd == 2) {
        SaveCallRestore(0x24b);
        MK4_NODE_AT(unsigned int, g_baseSel, 8) = 0x4218b0u;
        MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 3;
        g_pendingNodeType = 8;
        g_framePauseFlag = 1;
        return;
    }

    /* state 3+: the FIGHT! edge. Gate 2 = a decided start (one side ready,
     * or the ramp favours a side); gate 1 = the plain start; an exactly-met
     * 0x10000 ramp pops with no gate change. */
    Cmp2DirtyToggle();
    if (g_framePauseFlag != 0) return;
    if ((g_stateBits8c & 1) != 0) {
        unsigned int r1 = g_readyP1, r2 = g_readyP2;

        if (r1 == 0) {
            if (r2 != 0)
                goto gate2;                      /* only P2 ready */
            /* both pending: ramp */
        } else {
            if (r2 == 0)
                goto gate1;                      /* only P1 ready */
            /* both ready: ramp */
        }
    }
    /* the energy ramp - 0x421aa8 */
    {
        unsigned int a = g_rampA, b = g_rampB;

        g_walkSlot6c = a;
        g_slot70 = b;
        if ((int)a > (int)b)
            goto gate1;
        if ((int)a < (int)b)
            goto gate2;
        if (a == 0x10000) {
            StackPopDispatchTagged();            /* met exactly: no gate */
            return;
        }
        DualAddSar();
        if ((g_walkSlot6c & 1) != 0)
            goto gate2;
    }
gate1:
    g_walkSlot6c = 1;
    g_roundPhase = 1;
    StackPopDispatchTagged();
    return;
gate2:
    g_walkSlot6c = 2;
    g_roundPhase = 2;
    StackPopDispatchTagged();
}

#endif /* NON_MATCHING */
