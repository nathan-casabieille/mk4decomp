/* The CRT heap, natively. The original allocates through MSVC 5's
 * malloc: small blocks via the __sbh, large ones via HeapAlloc on a
 * dedicated growable heap. Win98's HeapAlloc on a fresh heap is
 * DETERMINISTIC, and MK4's static data depends on it: the move tables
 * carry packed pointers straight into heap addresses (0x134xxxx..
 * 0x15cxxxx) that the shipped binary expects the loader's allocations
 * to land on.
 *
 * This is a linear bump allocator over its OWN arena window, placed
 * above the scratch stack - the 0x134xxxx neighbourhood the original's
 * heap used is already spoken for natively (framebuffer, shading
 * table, the loaded .geo), so the emulation cannot sit there without
 * stomping them. Addresses are reproducible run to run, which is what
 * the calibration work needs; matching the ORIGINAL's absolute
 * addresses is a separate question (see the fight-scene status note). Header is one dword (block size
 * including header, low bit = in-use), user data 0x10-aligned like
 * HeapAlloc's granularity.
 *
 * MK4_TRACE_HEAP=1 logs every allocation with its VA so the layout can
 * be calibrated against the addresses the static tables expect.
 */
#include <SDL2/SDL_log.h>
#include <stdlib.h>
#include "portable/mem_model.h"

#define HEAP_BASE 0x1620000u   /* above MK4_SCRATCH_END */
#define HEAP_END  0x1800000u

static unsigned int s_cursor;   /* VA of the next fresh block */

unsigned int MK4_CrtHeapAlloc(unsigned int size)
{
    unsigned int need = (size + 0xfu + 0x10u) & ~0xfu;   /* hdr + align */
    unsigned int blk, user;

    if (s_cursor == 0)
        s_cursor = HEAP_BASE;
    blk = s_cursor;
    if (blk + need > HEAP_END) {
        SDL_Log("crtheap: OUT OF WINDOW (%u bytes at %#x)", size, blk);
        return 0;
    }
    s_cursor = blk + need;
    *MK4_VA(unsigned int, blk) = need | 1u;
    user = blk + 0x10u;
    if (getenv("MK4_TRACE_HEAP"))
        SDL_Log("crtheap: %6u bytes -> VA %#x", size, user);
    return user;
}

void MK4_CrtHeapFree(unsigned int user)
{
    if (user >= HEAP_BASE + 0x10u && user < HEAP_END)
        *MK4_VA(unsigned int, user - 0x10u) &= ~1u;
    /* freed space is not reused - determinism over thrift */
}

/* the CRT entry points the engine calls (cdecl, sizes in bytes) */
unsigned int SmallMalloc(unsigned int size)
{
    return MK4_CrtHeapAlloc(size);
}

unsigned int TryAllocWithHandler(unsigned int size, unsigned int handler)
{
    (void)handler;
    if (size > 0xffffffe0u)
        return 0;
    if (size == 0)
        size = 1;
    return MK4_CrtHeapAlloc(size);
}

unsigned int LoadArgPushCall(unsigned int size)
{
    return TryAllocWithHandler(size, 0);
}
