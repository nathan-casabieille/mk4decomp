/**
 * Mem_Free - portable twin.
 *
 * The heap is a single flat run of blocks between g_memHeapStart (0x007b41a0)
 * and g_memHeapEnd (0x00ab4194). Every block starts with a 12-byte header:
 *
 *     +0  flags | size      top bit = FREE, low 24 bits = total block size
 *     +4  owner slot        address of a handle to clear, or 0
 *     +8  back link         address of the previous block (itself if first)
 *     +c  user data         what Mem_Alloc hands out
 *
 * Freeing marks the block, clears the owner's handle, then coalesces with the
 * previous block and with the next one. Both merges use the same idiom:
 *
 *     (((a + b) ^ b) & 0xffffff) ^ b
 *
 * which adds the two sizes in the low 24 bits while keeping b's flag bits -
 * i.e. the surviving header stays FREE and gains the neighbour's size.
 *
 * There is no matching-build definition: Mem_Free is still synthesized from
 * the original bytes, so this whole file is NON_MATCHING-only.
 *
 * @addr 0x004b5b10 (174b)
 */
#ifdef NON_MATCHING

#include "portable/mem_model.h"

extern void Helper_MemMalloc_Post(void);

/* Self-contained like Mem_Malloc: the co-exec extractor compiles the function
 * BODY alone, so file-scope macros (the old HEAP_LO/HDR) never reach it - and
 * with the extractor now searching the LINKED files first, this body is the
 * one the harness actually checks. */
void Mem_Free(void *ptr)
{
    unsigned char *A = (unsigned char *)MK4_PTR(0u);
#define HEAP_LO  0x007b41a0u
#define HEAP_HI  0x00ab4194u
#define HDR(va)  (*(unsigned int *)(A + (va)))
    unsigned int p = MK4_UNPTR(ptr);
    unsigned int blk, owner, hdr, prev, next;

    /* `ja`, not `jae`: a pointer exactly AT g_memHeapEnd is let through. */
    if (p < HEAP_LO || p > HEAP_HI)
        return;

    owner = HDR(p - 8);
    blk   = p - 0xc;
    HDR(blk) |= 0x80000000u;
    if (owner != 0)
        HDR(owner) = 0;

    /* coalesce backwards */
    prev = HDR(blk + 8);
    if (prev != blk && (HDR(prev) & 0x80000000u)) {
        unsigned int ph;

        HDR(blk + (HDR(blk) & 0xffffffu) + 8) = prev;   /* next block's back link */
        hdr = HDR(blk);
        ph  = HDR(prev);
        HDR(prev) = (((hdr + ph) ^ ph) & 0xffffffu) ^ ph;
        blk = prev;
    }

    /* coalesce forwards */
    hdr  = HDR(blk);
    next = (hdr & 0xffffffu) + blk;
    if (next < HEAP_HI && (HDR(next) & 0x80000000u)) {
        unsigned int merged = (((HDR(next) + hdr) ^ hdr) & 0xffffffu) ^ hdr;

        HDR(blk) = merged;
        next = (merged & 0xffffffu) + blk;
        if (next < HEAP_HI)
            HDR(next + 8) = blk;
    }
    Helper_MemMalloc_Post();
#undef HEAP_LO
#undef HEAP_HI
#undef HDR
}

#else
/* matching build: synthesized from the original bytes, nothing to compile */
#endif /* NON_MATCHING */
