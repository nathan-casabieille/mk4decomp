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
    unsigned off = va - 0x00400000u;

    if (va < 0x00400000u || off >= g_mk4ArenaSize) {
        static int reported;

        /* Only the first few, then stop: a bad VA inside a walk repeats. */
        if (reported++ < 16)
            fprintf(stderr, "MK4_PTR out of range: va=0x%08x (offset 0x%08x, "
                            "arena %u bytes) at %s:%d\n",
                    va, off, g_mk4ArenaSize, file, line);
        if (getenv("MK4_ARENA_CHECK_ABORT"))
            abort();
        return g_mk4Arena;          /* a mapped page, so the walk can continue */
    }
    return g_mk4Arena + off;
}

#endif
