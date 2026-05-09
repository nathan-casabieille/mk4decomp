/**
 * FSYS - asset archive subsystem.
 *
 * See include/engine/fsys.h for the public API and
 * analysis/notes/architecture.md for the on-disk layout.
 */
#include "engine/fsys.h"
#include "platform/install.h"  /* for ShowErrorMessage */

/*
 * Return the value stored in the file slot (= current read offset
 * after fopen / fseek / fread). Out-of-range handles return -1.
 *
 * @addr 0x004b2100
 */
int FSYS_ftell(int fh)
{
    if ((unsigned int)fh > 0x400) {
        return -1;
    }
    return g_fsys_files[fh];
}

/*
 * Normalize a path: uppercase letters, copy into the static
 * g_fsys_normalized_path buffer, validate that it begins with a
 * drive letter ("X:\..."). On a missing prefix the function calls
 * ShowErrorMessage but still returns the (partial) buffer.
 *
 * NULL or empty input returns NULL.
 *
 * Match status: drafted. Functionally equivalent but our /O2 output
 * is ~17 bytes shorter than the original because MSVC removed a
 * dead `i < 0x3ff` bound check and didn't spill the char to stack
 * the way the original compile did. Re-matching needs reproducing
 * the source-level form that triggered the original codegen.
 *
 * @addr 0x004b1ec0
 */
char *FSYS_NormalizePath(const char *path)
{
    int i;
    char c;

    if (path == 0)  return 0;
    if (*path == 0) return 0;

    i = 0;
    if (i < 0x3ff) {
        do {
            c = path[i];
            if (c >= 'a' && c <= 'z') {
                g_fsys_normalized_path[i] = c - 0x20;
            } else {
                g_fsys_normalized_path[i] = c;
            }
            i++;
        } while (path[i] != 0);
    }
    g_fsys_normalized_path[i] = 0;

    if (g_fsys_normalized_path[1] != ':' ||
        g_fsys_normalized_path[2] != '\\') {
        ShowErrorMessage("Partial filename");
    }
    return g_fsys_normalized_path;
}

/*
 * Query the size of a file by name. Opens, seeks to end, reads
 * position, closes.
 *
 * @addr 0x004b2120
 */
u32 FSYS_fsize(const char *path)
{
    int fh;
    int size;

    fh = FSYS_fopen(path, "rb");
    FSYS_fseek(fh, 0, 2);
    size = FSYS_ftell(fh);
    FSYS_fclose(fh);
    return (u32)size;
}

/*
 * Free a file handle. Marks the slot as available; out-of-range
 * handles silently no-op.
 *
 * @addr 0x004b1f90
 */
int FSYS_fclose(int fh)
{
    if ((unsigned int)fh > 0x400) {
        return 0;
    }
    g_fsys_files[fh] = -1;
    return 0;
}

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
