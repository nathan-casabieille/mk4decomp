/**
 * ChainDirtyBitWalker - 0x00408c10 (148b): the three-step record lookup
 * the round-setup band uses to find the animation record it installs a
 * track on. TrackInstall calls it four times, once per controller chain.
 *
 * From the group head, follow +0x1c to the chain, add the index in
 * 0x54206c, deref that slot, then take that node's +0x28. Each step
 * leaves its result in g_xformEntityIdx and toggles state-bit 2 around
 * the test: the bit is SET before each deref and cleared again only when
 * the value survives, so a caller that finds bit 2 up on return knows
 * the walk failed and at which depth.
 *
 * Note the two guards differ: the first step needs a value that is
 * strictly POSITIVE (jg), the second only non-negative (jle skips), and
 * a null anywhere leaves the bit set and returns.
 *
 * It was a weak no-op until now, which meant those four walks returned
 * nothing and the track installs had no records to land on - see the
 * fight-scene status note.
 *
 * NATIVE-ONLY twin: the matching build synthesizes the original bytes.
 */
#ifdef NON_MATCHING

#include "portable/mem_model.h"

#define g_xformEntityIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542048u))
#define g_walkSlot6c     (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#define g_groupHead      (*(unsigned int *)MK4_VA(unsigned int, 0x54205cu))
#define g_stateBits8c    (*(unsigned int *)MK4_VA(unsigned int, 0x54208cu))

void ChainDirtyBitWalker(void)
{
    int v;

    v = (int)MK4_NODE_AT(unsigned int, g_groupHead, 0x1c);
    g_xformEntityIdx = (unsigned int)v;
    g_stateBits8c |= 4u;
    if (v == 0) return;
    g_stateBits8c ^= 4u;
    if (v <= 0) {                    /* jg falls through to the set-and-ret */
        g_stateBits8c |= 4u;
        return;
    }

    v += (int)g_walkSlot6c;
    g_xformEntityIdx = (unsigned int)v;
    g_stateBits8c |= 4u;
    v = (int)*(unsigned int *)MK4_PTR((unsigned int)v * 4);
    g_xformEntityIdx = (unsigned int)v;
    if (v == 0) return;
    g_stateBits8c ^= 4u;
    if (v <= 0) return;

    v = (int)MK4_NODE_AT(unsigned int, (unsigned int)v, 0x28);
    g_stateBits8c |= 4u;
    g_xformEntityIdx = (unsigned int)v;
    if (v == 0) return;
    g_stateBits8c ^= 4u;
}

#endif /* NON_MATCHING */
