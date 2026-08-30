/**
 * PendingMatch_00459510 (0x459510, 2728b) - THE FIGHT SCRIPT VM.
 *
 * A bytecode interpreter: fetch a 32-bit word from the group's script
 * stream (the PC is the packed word index at baseSel[+0x48], advanced by
 * ScaledIterStep_0045c020), take the opcode from the top byte, dispatch
 * through the 49-entry table at 0x4e8970. Every handler either loops back
 * into the fetch, or installs itself as the controller's per-frame
 * callback (node +8) with a tagged entry on the queue and PAUSES - the
 * "wait" opcodes. On the next frame the pump re-dispatches the handler
 * with +0x84 = 1 and it re-enters the VM.
 *
 * This is what animates a fight. The wait opcodes write the ANIMATION ID
 * into the group's +0x24 and a repeat count into +0x28 - the exact fields
 * the walk-toward band and the anim pump read - and the dispatch opcodes
 * (the PendingMatch_ScaledArrStore cluster, ops 3/5/13..20/30/34/40/41)
 * are what enter the code table states like 185 = RoundSetupSpawn, the
 * head of the track-installer chain. The infamous "872-function closure"
 * of that cluster is just this VM's handler set seen through the static
 * call graph.
 *
 * It was a weak no-op called 50 times a frame (MK4_TRACE_STUBS found it),
 * so every fight script silently did nothing - which is why the fighters'
 * 17 track records exist but stay empty, and why the round flow never
 * advances past the walk-in.
 *
 * CONVERSION SHAPE. The core loop and the handlers that live inside this
 * symbol's own 2728 bytes are converted; the handler clusters at other
 * addresses (ScaledArrStore, ComboMoveSelect, Phase3IndirectInstall,
 * ScaledIterStep) are NOT yet - their opcodes log once, rewind the PC by
 * one word so the stream stays positioned, and pause. MK4_TRACE_STUBS
 * plus the VMOP log then name exactly which opcodes the real scripts
 * use, in the order they are reached - the same measure-first loop that
 * found the VM itself. Handler helpers that are still hollow keep their
 * weak traced stubs on purpose.
 *
 * NATIVE-ONLY twin: the matching build synthesizes the original bytes.
 */
#ifdef NON_MATCHING

#include "portable/mem_model.h"

extern void SDL_Log(const char *fmt, ...);
extern char *getenv(const char *);

/* real */
extern void ScaledChainJmp_00429470(void);
extern void EsiInstallDecCallChain_StackPopDispatchTagged_004293d0(void);
extern void EsiInstallDecCallChain_StackPopDispatchTagged_004294a0(void);
extern void AllocNode(void);
extern void MStackPushSet0008(void);
extern void CopyJmp_SlotCmp3way_g_currentNodeIdx(void);
extern void StackPopDispatchTagged(void);
extern void TaggedSceneDispatch(int tag);
/* weak-stubbed until converted - the stub trace reports each hit */
extern void ScaledLoadJmp_00428d20(void);
extern void ScaledLoadJmp_00429390(void);
extern void EsiInstallDecGlobalJmp(void);
extern void EntryThunkBodyStateMachine(void);
extern void DualBranchWordLookup(void);
extern void ByteWordTableTaggedDispatch(void);
extern void TableLookupCall_g_eventTbl_112(void);
extern void TableLookupCall_g_eventTbl_19(void);
extern void TableLookupCall_g_eventTbl_65(void);
extern void MStackPush4IndirectCall(void);
extern void State208cBit0Flag(void);
extern void CallDirty4DualJmp(void);
extern void HitReactionCluster(void);
extern void MoveListCursorCluster(void);

void PendingMatch_00459510(void);

#define g_currentNodeIdx  (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_pendingNodeType (*(unsigned int *)MK4_VA(unsigned int, 0x54204cu))
#define g_eventQueueTotal (*(unsigned int *)MK4_VA(unsigned int, 0x542050u))
#define g_groupHead       (*(unsigned int *)MK4_VA(unsigned int, 0x54205cu))
#define g_baseSel         (*(unsigned int *)MK4_VA(unsigned int, 0x542060u))
#define g_walkCallback    (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#define g_eventQueueCur   (*(unsigned int *)MK4_VA(unsigned int, 0x542070u))
#define g_slot74          (*(unsigned int *)MK4_VA(unsigned int, 0x542074u))
#define g_eventQueueNotMask (*(unsigned int *)MK4_VA(unsigned int, 0x54207cu))
#define g_slot80          (*(unsigned int *)MK4_VA(unsigned int, 0x542080u))
#define g_xformDirtyFlags (*(unsigned int *)MK4_VA(unsigned int, 0x54208cu))
#define g_framePauseFlag  (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#define g_matrixStackTop  (*(unsigned int *)MK4_VA(unsigned int, 0x4d57acu))

#define MSTACK_AT(i)      (*(unsigned int *)MK4_PTR((i) * 4u))
#define NODE_W(n,off)     MK4_NODE_AT(unsigned int, (n), (off))

/* ---- the fetch (ScaledIterStep_0045c020, 45b): PC = baseSel[+0x48] ---- */
void ScaledIterStep_0045c020(void)
{
    unsigned int cam = g_baseSel;
    unsigned int pc = NODE_W(cam, 0x48);

    g_eventQueueTotal = pc;
    g_walkCallback = *(unsigned int *)MK4_PTR(pc * 4u);
    pc++;
    g_eventQueueTotal = pc;
    NODE_W(cam, 0x48) = pc;
}

/* ---- TableLookupCall_g_eventTbl_50 (0x489f60, 33b) ---- */
void TableLookupCall_g_eventTbl_50(void)
{
    unsigned int v = g_walkCallback;
    unsigned short id;

    if (v > 0x32u)
        return;
    id = *(unsigned short *)MK4_PTR(0x4ef998u + v * 2u);
    if (id == 0)
        return;
    TaggedSceneDispatch((int)id);
}

/* ---- the shared install-self + tagged-queue + pause sequence every
 * wait opcode ends with. tag24 is the byte queued above the VA. ---- */
static void vm_install_wait(unsigned int selfVA, unsigned int tag24)
{
    unsigned int cam = g_baseSel;
    unsigned int q;

    NODE_W(cam, 8) = selfVA;
    NODE_W(g_baseSel, 0x84) = tag24 >> 24;
    q = NODE_W(cam, 4);
    g_currentNodeIdx = q;
    *(unsigned int *)MK4_PTR(q * 4u) = selfVA + tag24;
    g_currentNodeIdx = q + 1;
    NODE_W(cam, 4) = q + 1;
    NODE_W(g_baseSel, 0x84) = 0;
}

/* ---- unknown / foreign-cluster opcode: keep the stream positioned and
 * report. The PC has already advanced past the command word, so step it
 * back one word; the VM retries the same opcode next frame. ---- */
static void vm_unknown_op(unsigned int op, unsigned int target)
{
    static unsigned int seen[256];

    NODE_W(g_baseSel, 0x48) -= 1;
    if (op < 256u && !seen[op]) {
        seen[op] = 1;
        SDL_Log("VMOP %u -> 0x%08x unconverted (foreign cluster) - stream held",
                op, target);
    }
    g_framePauseFlag = 1;
}

/* ---- op 1 (0x459a40): repeat = operand -> group+0x28, fetch anim ->
 * group+0x24, install self, ScaledLoadJmp_00428d20, pause. Re-entry with
 * a pump command resumes the VM. ---- */
void VMOp_Resume_00459a40(void)
{
    unsigned int cam = g_baseSel;
    unsigned int cmd = NODE_W(cam, 0x84);

    NODE_W(cam, 0x84) = 0;
    if (cmd != 0) {
        PendingMatch_00459510();
        return;
    }
    g_eventQueueCur &= 0xffu;
    if (g_framePauseFlag != 0) return;

    NODE_W(g_groupHead, 0x28) = g_eventQueueCur;
    ScaledIterStep_0045c020();
    if (g_framePauseFlag != 0) return;
    NODE_W(g_groupHead, 0x24) = g_walkCallback;

    vm_install_wait(0x459a40u, 0x1000000u);
    ScaledLoadJmp_00428d20();
    g_framePauseFlag = 1;
}

/* ---- op 9 (0x459b20): fetch anim -> group+0x24, install self,
 * ScaledChainJmp_00429470, pause. ---- */
void VMOp_Resume_00459b20(void)
{
    unsigned int cam = g_baseSel;
    unsigned int cmd = NODE_W(cam, 0x84);

    NODE_W(cam, 0x84) = 0;
    if (cmd != 0) {
        PendingMatch_00459510();
        return;
    }
    ScaledIterStep_0045c020();
    if (g_framePauseFlag != 0) return;
    NODE_W(g_groupHead, 0x24) = g_walkCallback;

    vm_install_wait(0x459b20u, 0x1000000u);
    ScaledChainJmp_00429470();
    g_framePauseFlag = 1;
}

/* ---- op 6 (0x459bd0): operand -> 0x542080, install self,
 * EsiInstallDecCallChain..._004293d0, pause. ---- */
void VMOp_Resume_00459bd0(void)
{
    unsigned int cam = g_baseSel;
    unsigned int cmd = NODE_W(cam, 0x84);

    NODE_W(cam, 0x84) = 0;
    if (cmd != 0) {
        PendingMatch_00459510();
        return;
    }
    g_eventQueueCur &= 0xffu;
    if (g_framePauseFlag != 0) return;
    g_slot80 = g_eventQueueCur;

    vm_install_wait(0x459bd0u, 0x1000000u);
    EsiInstallDecCallChain_StackPopDispatchTagged_004293d0();
    g_framePauseFlag = 1;
}

/* ---- op 7 (0x459c80): the LOOP opcode - while group+0x28 counts down,
 * re-install and pause; at zero fall back into the VM. ---- */
void VMOp_Resume_00459c80(void)
{
    unsigned int cam = g_baseSel;
    unsigned int cmd = NODE_W(cam, 0x84);
    unsigned int ctr;

    NODE_W(cam, 0x84) = 0;
    if (cmd != 0) {
        PendingMatch_00459510();
        return;
    }
    ctr = NODE_W(g_groupHead, 0x28);
    g_walkCallback = ctr;
    if (ctr == 0) {
        PendingMatch_00459510();
        return;
    }
    ctr--;
    g_walkCallback = ctr;
    NODE_W(g_groupHead, 0x28) = ctr;

    vm_install_wait(0x459c80u, 0x1000000u);
    ScaledLoadJmp_00429390();
    g_framePauseFlag = 1;
}

/* ---- op 8 (0x459d30): two-tag wait. Non-zero operand: anim + count,
 * install with tag 2; zero operand: anim only, tag 1. Both re-enter the
 * VM on any pump command. ---- */
void VMOp_Resume_00459d30(void)
{
    unsigned int cam = g_baseSel;
    unsigned int cmd = NODE_W(cam, 0x84);
    unsigned int operand;

    NODE_W(cam, 0x84) = 0;
    if (cmd != 0) {
        PendingMatch_00459510();
        return;
    }
    g_eventQueueCur &= 0xffu;
    if (g_framePauseFlag != 0) return;
    operand = g_eventQueueCur;

    ScaledIterStep_0045c020();
    if (g_framePauseFlag != 0) return;
    NODE_W(g_groupHead, 0x24) = g_walkCallback;
    if (operand != 0) {
        g_slot80 = g_eventQueueCur;
        vm_install_wait(0x459d30u, 0x2000000u);
    } else {
        vm_install_wait(0x459d30u, 0x1000000u);
    }
    EsiInstallDecGlobalJmp();
    g_framePauseFlag = 1;
}

/* ---- op 2 (0x459ea0): clear group+0x28, operand -> 0x542080, fetch
 * anim -> group+0x24, install self, ..._004294a0, pause. ---- */
void VMOp_Resume_00459ea0(void)
{
    unsigned int cam = g_baseSel;
    unsigned int cmd = NODE_W(cam, 0x84);

    NODE_W(cam, 0x84) = 0;
    if (cmd != 0) {
        PendingMatch_00459510();
        return;
    }
    g_walkCallback = 0;
    NODE_W(g_groupHead, 0x28) = 0;
    g_eventQueueCur &= 0xffu;
    if (g_framePauseFlag != 0) return;
    g_slot80 = g_eventQueueCur;

    ScaledIterStep_0045c020();
    if (g_framePauseFlag != 0) return;
    NODE_W(g_groupHead, 0x24) = g_walkCallback;

    vm_install_wait(0x459ea0u, 0x1000000u);
    EsiInstallDecCallChain_StackPopDispatchTagged_004294a0();
    g_framePauseFlag = 1;
}

/* ---- the pump-facing WAIT callback at 0x459890: swallow one frame,
 * then re-install itself and yield again until a command arrives. ---- */
void VMWait_00459890(void)
{
    unsigned int cam = g_baseSel;
    unsigned int cmd = NODE_W(cam, 0x84);

    NODE_W(cam, 0x84) = 0;
    if (cmd != 0) {
        PendingMatch_00459510();
        return;
    }
    g_eventQueueCur &= 0xffu;
    if (g_framePauseFlag != 0) return;
    g_pendingNodeType = g_eventQueueCur;
    NODE_W(cam, 8) = 0x459890u;
    NODE_W(cam, 0x84) = 1;
    g_framePauseFlag = 1;
}

/* ---- the pump-facing resume-with-hit-check at 0x459910 ---- */
void VMResumeHit_00459910(void)
{
    unsigned int cam = g_baseSel;
    unsigned int cmd = NODE_W(cam, 0x84);
    unsigned int top, flags;

    NODE_W(cam, 0x84) = 0;
    if (cmd != 0) {
        PendingMatch_00459510();
        return;
    }
    top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    MSTACK_AT(top) = g_xformDirtyFlags;
    HitReactionCluster();
    if (g_framePauseFlag != 0) return;      /* pops skipped - abort leak */
    top = g_matrixStackTop;
    flags = MSTACK_AT(top);
    g_matrixStackTop = top - 1;
    g_xformDirtyFlags = flags;
    g_pendingNodeType = g_walkCallback;
    if ((flags & 1u) != 0)
        g_pendingNodeType = g_eventQueueCur;
    if (g_pendingNodeType == 0) {
        PendingMatch_00459510();
        return;
    }
}

/* ---- the core loop. The dispatch table at 0x4e8970 is DATA in the
 * image (about 200 entries; 61 of them point at Thunk_ScaledNeg1SetPause,
 * the engine's own invalid-opcode behavior), so the twin reads the LIVE
 * table from the arena and dispatches on the target VA - no mirror to
 * keep in sync, and the table's real size is always right. ---- */

extern void *MK4_ResolveCode(unsigned va);
extern void Thunk_ScaledNeg1SetPause(void);

void PendingMatch_00459510(void)
{
    unsigned int top, w, op, v, target;

    for (;;) {
        top = g_matrixStackTop + 1;
        g_matrixStackTop = top;
        MSTACK_AT(top) = g_xformDirtyFlags;

        ScaledIterStep_0045c020();
        if (g_framePauseFlag != 0)
            return;                          /* flags stay pushed - abort leak */

        w = g_walkCallback;
        g_eventQueueCur = w;
        op = w >> 24;
        g_walkCallback = op;
        g_currentNodeIdx = (0x4e8970u >> 2) + op;
        target = *(unsigned int *)MK4_PTR(0x4e8970u + op * 4u);
        g_currentNodeIdx = target;

        top = g_matrixStackTop;
        g_xformDirtyFlags = MSTACK_AT(top);
        g_matrixStackTop = top - 1;

        switch (target) {
        case 0x459510u:                      /* NOP opcodes re-enter the VM */
            continue;

        case 0x459a40u: VMOp_Resume_00459a40(); break;
        case 0x459b20u: VMOp_Resume_00459b20(); break;
        case 0x459bd0u: VMOp_Resume_00459bd0(); break;
        case 0x459c80u: VMOp_Resume_00459c80(); break;
        case 0x459d30u: VMOp_Resume_00459d30(); break;
        case 0x459ea0u: VMOp_Resume_00459ea0(); break;

        case 0x4595d0u:                      /* word -> cam+0x68 */
            ScaledIterStep_0045c020();
            if (g_framePauseFlag != 0) return;
            NODE_W(g_baseSel, 0x68) = g_walkCallback;
            continue;

        case 0x459590u:                      /* eventTbl_50 */
            v = g_eventQueueCur & 0xffu;
            g_eventQueueCur = v;
            if (g_framePauseFlag != 0) return;
            g_walkCallback = v;
            TableLookupCall_g_eventTbl_50();
            break;

        case 0x459740u:                      /* eventTbl_65 */
            v = g_eventQueueCur & 0xffu;
            g_eventQueueCur = v;
            if (g_framePauseFlag != 0) return;
            g_walkCallback = v;
            TableLookupCall_g_eventTbl_65();
            break;

        case 0x459700u:                      /* eventTbl_19 */
            v = g_eventQueueCur & 0xffu;
            g_eventQueueCur = v;
            if (g_framePauseFlag != 0) return;
            g_walkCallback = v;
            TableLookupCall_g_eventTbl_19();
            break;

        case 0x4596c0u:                      /* eventTbl_112 */
            v = g_eventQueueCur & 0xffu;
            g_eventQueueCur = v;
            if (g_framePauseFlag != 0) return;
            g_walkCallback = v;
            TableLookupCall_g_eventTbl_112();
            break;

        case 0x459600u:
            v = g_eventQueueCur & 0xffu;
            g_eventQueueCur = v;
            if (g_framePauseFlag != 0) return;
            g_eventQueueNotMask = v;
            EntryThunkBodyStateMachine();
            break;

        case 0x459680u:
            v = g_eventQueueCur & 0xffu;
            g_eventQueueCur = v;
            if (g_framePauseFlag != 0) return;
            g_walkCallback = v;
            ByteWordTableTaggedDispatch();
            break;

        case 0x459640u:
            v = g_eventQueueCur & 0xffu;
            g_eventQueueCur = v;
            if (g_framePauseFlag != 0) return;
            g_walkCallback = v;
            DualBranchWordLookup();
            break;

        case 0x459780u:                      /* indirect through 0x48a050 */
            v = g_eventQueueCur & 0xffu;
            g_eventQueueCur = v;
            if (g_framePauseFlag != 0) return;
            g_currentNodeIdx = 0x48a050u;
            g_walkCallback = v;
            MStackPush4IndirectCall();
            break;

        case 0x4597c0u:                      /* cam+0x74 = 0x1007 */
            g_walkCallback = 0x1007u;
            NODE_W(g_baseSel, 0x74) = 0x1007u;
            continue;

        case 0x4597e0u:
            MStackPushSet0008();
            break;

        case 0x459800u:
            CopyJmp_SlotCmp3way_g_currentNodeIdx();
            if (g_framePauseFlag != 0) return;
            if ((g_xformDirtyFlags & 1u) != 0) {
                MoveListCursorCluster();     /* jmp in the original */
                return;
            }
            ScaledIterStep_0045c020();       /* fetch-and-discard */
            if (g_framePauseFlag != 0) return;
            continue;

        case 0x459830u:
            State208cBit0Flag();
            if (g_framePauseFlag != 0) return;
            if ((g_xformDirtyFlags & 1u) != 0) {
                MoveListCursorCluster();     /* jmp in the original */
                return;
            }
            ScaledIterStep_0045c020();
            if (g_framePauseFlag != 0) return;
            continue;

        case 0x459860u:
            CallDirty4DualJmp();
            break;

        case 0x459880u:                      /* script end */
            StackPopDispatchTagged();        /* jmp in the original */
            return;

        case 0x459890u:
            VMWait_00459890();
            break;

        case 0x4598f0u:                      /* fetch a VA, tail-jump to it */
            ScaledIterStep_0045c020();
            if (g_framePauseFlag != 0) return;
            ((void (*)(void))MK4_ResolveCode(g_walkCallback))();
            return;

        case 0x459910u:
            VMResumeHit_00459910();
            break;

        case 0x4599c0u:                      /* fetch a VA, call it, loop */
            ScaledIterStep_0045c020();
            if (g_framePauseFlag != 0) return;
            g_currentNodeIdx = g_walkCallback;
            ((void (*)(void))MK4_ResolveCode(g_walkCallback))();
            break;

        case 0x4599f0u:                      /* fetch pair, AllocNode, loop */
            ScaledIterStep_0045c020();
            if (g_framePauseFlag != 0) return;
            g_slot74 = g_walkCallback;
            ScaledIterStep_0045c020();
            if (g_framePauseFlag != 0) return;
            g_pendingNodeType = g_walkCallback;
            AllocNode();
            break;

        case 0x49cbc0u:                      /* invalid opcode: pause thunk */
            Thunk_ScaledNeg1SetPause();
            break;

        default:
            vm_unknown_op(op, target);
            return;
        }
        if (g_framePauseFlag != 0)
            return;
    }
}

#endif /* NON_MATCHING */
