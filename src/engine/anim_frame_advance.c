/**
 * GuardedChainCmpDualBitXor (0x4299a0, 160b) - the per-frame ANIM ADVANCE
 * and done-test, called ~1.4x per frame by the fight-script VM's wait
 * callees. It was the most-called hollow stub left (686 hits per 500
 * frames), which meant no animation ever advanced and no wait opcode
 * ever saw its anim finish.
 *
 * group+0x24 holds the anim record, group+0x28 the frame cursor, and the
 * record's +4 its frame count. Under the count the cursor advances
 * through BootMStackBracket3SubdispatchPair; at or past it the cursor
 * clamps. Dirty-bit 2 (mask 4) is the DONE flag: set, then xored back
 * off unless the cursor sits exactly at the count - the callers resume
 * the script when it stays set.
 *
 * NATIVE-ONLY twin: the matching build synthesizes the original bytes.
 */
#ifdef NON_MATCHING

#include "portable/mem_model.h"

extern void BootMStackBracket3SubdispatchPair(void);

#define g_currentNodeIdx  (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_fightGroupHead  (*(unsigned int *)MK4_VA(unsigned int, 0x54205cu))
#define g_walkCallback    (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#define g_xformDirtyFlags (*(unsigned int *)MK4_VA(unsigned int, 0x54208cu))
#define g_framePauseFlag  (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))

void GuardedChainCmpDualBitXor(void)
{
    unsigned int group = g_fightGroupHead;
    unsigned int frame = MK4_NODE_AT(unsigned int, group, 0x28);
    unsigned int anim;

    g_walkCallback = frame;
    anim = MK4_NODE_AT(unsigned int, group, 0x24);
    g_currentNodeIdx = anim;
    if (anim == 0)
        return;

    if ((int)frame >= (int)MK4_NODE_AT(unsigned int, anim, 4)) {
        anim = MK4_NODE_AT(unsigned int, group, 0x24);
        g_currentNodeIdx = anim;
        frame = MK4_NODE_AT(unsigned int, anim, 4);
        g_walkCallback = frame;
        MK4_NODE_AT(unsigned int, group, 0x28) = frame;
    } else {
        BootMStackBracket3SubdispatchPair();
        if (g_framePauseFlag != 0)
            return;
    }

    group = g_fightGroupHead;
    g_xformDirtyFlags |= 4u;
    frame = MK4_NODE_AT(unsigned int, group, 0x28);
    g_walkCallback = frame;
    anim = MK4_NODE_AT(unsigned int, group, 0x24);
    g_currentNodeIdx = anim;
    if (MK4_NODE_AT(unsigned int, anim, 4) != frame)
        g_xformDirtyFlags ^= 4u;
}

#endif /* NON_MATCHING */
