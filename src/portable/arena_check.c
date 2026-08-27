/**
 * MK4_ARENA_CHECK support - see MK4_PtrChecked in include/portable/mem_model.h.
 *
 * Built only for the diagnostic binary. Every arena deref passes through here,
 * so a VA outside the reserved range is reported with the source line that
 * asked for it rather than becoming a wild pointer.
 */
#if defined(NON_MATCHING) && defined(MK4_ARENA) && defined(MK4_ARENA_CHECK)

#include "portable/arena.h"

#include <stdio.h>
#include <stdlib.h>

void *MK4_PtrChecked(unsigned va, const char *file, int line)
{
    long off = (long)va - (long)0x00400000u;   /* signed: see mem_model.h */

    if (va < 0x00400000u || off >= (long)g_mk4ArenaSize) {
        static int reported;

        /* Only the first few, then stop: a bad VA inside a walk repeats. */
        if (reported++ < 24)
            fprintf(stderr, "MK4_PTR out of range: va=0x%08x (offset 0x%08x, "
                            "arena %u bytes) at %s:%d\n",
                    va, (unsigned)off, g_mk4ArenaSize, file, line);
        if (getenv("MK4_ARENA_CHECK_ABORT"))
            abort();
    }
    /* Always the SAME address the plain macro computes, in range or not.
     *
     * A diagnostic build that returns something else is not diagnosing the
     * program any more, it is running a different one - and this bit it: a
     * BASE-0 packed table is spelled MK4_VA(T, 0) and indexed by the VA, so
     * `g_siblingTable[idx]` deliberately relies on 0 - 0x400000 wrapping and
     * the index adding the VA back. Substituting the arena base for that made
     * fifteen correct accesses look like faults and let the checked build
     * finish a frame the real one could not. */
    return g_mk4Arena + off;
}

#endif
