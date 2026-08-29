/**
 * TripleStateSwapCall - 0x0048cc40 (95b engine.download)
 *
 * The tail GuardedDualPushTailJmp jumps to after a spawn. Snapshots the
 * three staging globals (0x542074/0x542070/0x54206c) in callee-saved
 * registers, runs MStackPush2BiasResolveChain, and - unless paused or
 * bit 2 of 0x54208c came up - replays the saved 0x542070 into 0x54206c
 * for PushBitFieldMergePop, then re-roots g_currentNodeIdx at the group
 * head 0x54205c and restores the other two saves for
 * PushCallPopScaledJmpIndirect.
 *
 * NATIVE-ONLY twin: the matching build synthesizes the original bytes.
 */
#ifdef NON_MATCHING

#include "portable/mem_model.h"

extern void MStackPush2BiasResolveChain(void);
extern void PushBitFieldMergePop(void);
extern void PushCallPopScaledJmpIndirect(void);

#define g_save74          (*(unsigned int *)MK4_VA(unsigned int, 0x542074u))
#define g_save70          (*(unsigned int *)MK4_VA(unsigned int, 0x542070u))
#define g_save6c          (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#define g_currentNodeIdx  (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_groupHead       (*(unsigned int *)MK4_VA(unsigned int, 0x54205cu))
#define g_framePauseFlag  (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#define g_dirtyBits8c     (*(unsigned char *)MK4_VA(unsigned char, 0x54208cu))

void TripleStateSwapCall(void)
{
    unsigned int s74 = g_save74;
    unsigned int s70 = g_save70;
    unsigned int s6c = g_save6c;

    MStackPush2BiasResolveChain();
    if (g_framePauseFlag != 0)
        return;
    if ((g_dirtyBits8c & 4) != 0)
        return;

    g_save6c = s70;
    PushBitFieldMergePop();
    if (g_framePauseFlag != 0)
        return;

    g_currentNodeIdx = g_groupHead;
    g_save6c = s6c;
    g_save74 = s74;
    PushCallPopScaledJmpIndirect();
}

#endif /* NON_MATCHING */
