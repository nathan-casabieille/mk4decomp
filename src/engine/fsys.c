/**
 * FSYS - asset archive subsystem.
 *
 * See include/engine/fsys.h for the public API and
 * analysis/notes/architecture.md for the on-disk layout.
 */
#include "engine/fsys.h"

/*
 * Position-shifted accumulator hash. Each character is sign-extended,
 * shifted left by an 8-bit-stepping counter (0, 8, 16, 24, then back
 * to 0), and added into the running hash. The final return adds the
 * string length so two prefixes never collide.
 *
 * Match status: 49/50 bytes. The single remaining diff is the SIB
 * encoding of the final `lea eax, [esi+edx]` (0x16 vs 0x32). Both
 * forms compute the identical address; MSVC 5.0 SP3's heuristic
 * picks the opposite base/index assignment. Semantically equivalent.
 *
 * @addr 0x004b1f50
 */
u32 FSYS_HashName(const char *normalized_path)
{
    int hash = 0;
    int shift = 0;
    int i = 0;

    while (normalized_path[i] != 0) {
        hash += (int)(signed char)normalized_path[i] << shift;
        shift += 8;
        if (shift > 24) {
            shift = 0;
        }
        i++;
    }
    return (u32)(hash + i);
}
