/**
 * Leaves of the per-frame fight camera/pose chain (the
 * HitReactionDispatcher band) that had no native definition.
 *
 * FiveCallScaledChainTailJmp - 0x0045f8d0 (113b): re-root currentNodeIdx
 *   at the group head, then the five-step chain - GuardedChainPushSetCallPop,
 *   MStackPushSet0001, ScaledInit_GuardedDirtyXformFromTable, ScaledZero44,
 *   clear group-head[+0x60], ScaledChainNegStore - each pause-guarded, and
 *   tail into DualCallPauseDirtyJmp_00490c30.
 *
 * ScaledZero44 - 0x00491500 (21b): zero group-head[+0x44] and the 0x54206c
 *   staging word.
 *
 * ScaledChainNegStore - 0x00470310 (46b): node = group-head[+0x18]; take
 *   its +0x34; when non-zero, negate and fall into DualFieldAddSubStore,
 *   else return with 0x54206c = 0.
 *
 * DualFieldAddSubStore - 0x00470340 (76b): node = group-head[+0x18];
 *   node[+0x34] += 0x54206c; group-head[+0x58] -= 0x54206c (both results
 *   mirrored into 0x542070).
 *
 * NATIVE-ONLY twins: the matching build synthesizes the original bytes.
 */
#ifdef NON_MATCHING

#include "portable/mem_model.h"

extern void GuardedChainPushSetCallPop(void);
extern void MStackPushSet0001(void);
extern void ScaledInit_GuardedDirtyXformFromTable_g_scaledInit(void);
extern void DualCallPauseDirtyJmp_00490c30(void);

#define g_currentNodeIdx  (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_walkSlot6c      (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#define g_slot70          (*(unsigned int *)MK4_VA(unsigned int, 0x542070u))
#define g_groupHead       (*(unsigned int *)MK4_VA(unsigned int, 0x54205cu))
#define g_framePauseFlag  (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))

extern void ScaledZeroFour(void);

/* ScaledMove48to58 - 0x00490720 (30b): promote group-head[+0x48] into
 * [+0x58], mirror to 0x54206c, and fall into ScaledZeroFour. */
void ScaledMove48to58(void)
{
    unsigned int v = MK4_NODE_AT(unsigned int, g_groupHead, 0x48);

    g_walkSlot6c = v;
    MK4_NODE_AT(unsigned int, g_groupHead, 0x58) = v;
    ScaledZeroFour();               /* jmp in the original */
}

void ScaledZero44(void)
{
    g_walkSlot6c = 0;
    MK4_NODE_AT(unsigned int, g_groupHead, 0x44) = 0;
}

void DualFieldAddSubStore(void)
{
    unsigned int node = MK4_NODE_AT(unsigned int, g_groupHead, 0x18);
    unsigned int v;

    g_currentNodeIdx = node;
    v = g_walkSlot6c + MK4_NODE_AT(unsigned int, node, 0x34);
    g_slot70 = v;
    MK4_NODE_AT(unsigned int, node, 0x34) = v;

    v = MK4_NODE_AT(unsigned int, g_groupHead, 0x58) - g_walkSlot6c;
    g_slot70 = v;
    MK4_NODE_AT(unsigned int, g_groupHead, 0x58) = v;
}

void ScaledChainNegStore(void)
{
    unsigned int node = MK4_NODE_AT(unsigned int, g_groupHead, 0x18);
    unsigned int v;

    g_currentNodeIdx = node;
    v = MK4_NODE_AT(unsigned int, node, 0x34);
    g_walkSlot6c = v;
    if (v == 0)
        return;
    g_walkSlot6c = (unsigned int)(-(int)v);
    DualFieldAddSubStore();          /* jmp in the original */
}

extern void CallPauseScaledStoreCopyJmp(void);
extern void SlotPhaseDispatcherBigSwitch(void);

/* ZeroScaledZeroCallPauseJmp - 0x0045fa90 (46b): the idle-pose default -
 * clear group-head[+0x28] and the staging word, CallPauseScaledStoreCopyJmp,
 * and unless paused tail into SlotPhaseDispatcherBigSwitch. */
void ZeroScaledZeroCallPauseJmp(void)
{
    g_walkSlot6c = 0;
    MK4_NODE_AT(unsigned int, g_groupHead, 0x28) = 0;
    CallPauseScaledStoreCopyJmp();
    if (g_framePauseFlag != 0)
        return;
    SlotPhaseDispatcherBigSwitch();  /* jmp in the original */
}

void FiveCallScaledChainTailJmp(void)
{
    g_currentNodeIdx = g_groupHead;
    GuardedChainPushSetCallPop();
    if (g_framePauseFlag != 0) return;
    MStackPushSet0001();
    if (g_framePauseFlag != 0) return;
    ScaledInit_GuardedDirtyXformFromTable_g_scaledInit();
    if (g_framePauseFlag != 0) return;
    ScaledZero44();
    if (g_framePauseFlag != 0) return;
    g_walkSlot6c = 0;
    MK4_NODE_AT(unsigned int, g_groupHead, 0x60) = 0;
    ScaledChainNegStore();
    if (g_framePauseFlag != 0) return;
    DualCallPauseDirtyJmp_00490c30();   /* jmp in the original */
}

#endif /* NON_MATCHING */
