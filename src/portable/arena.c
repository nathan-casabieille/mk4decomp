/**
 * Arena loader - see include/portable/arena.h.
 *
 * Portable / WASM only (compiled under -DNON_MATCHING). Not part of the
 * matching build (the matching binary keeps the original flat VA layout
 * via the linker, so it never touches the arena) - under matching this
 * whole TU is empty.
 */
#ifdef NON_MATCHING

#include "portable/arena.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

unsigned char *g_mk4Arena     = 0;
unsigned int   g_mk4ArenaSize = 0;
/* frame counter, published for diagnostics that must correlate across TUs */
unsigned int   g_mk4FrameNo = 0;

int MK4_ArenaInitFromMemory(const void *image, unsigned size)
{
    if (image == 0 || size == 0)
        return 0;
    g_mk4Arena = (unsigned char *)malloc(size);
    if (g_mk4Arena == 0)
        return 0;
    memcpy(g_mk4Arena, image, size);
    g_mk4ArenaSize = size;
    return 1;
}

int MK4_ArenaInitFromFileReserve(const char *path, unsigned extra)
{
    FILE *f;
    long n;
    unsigned char *buf;
    int ok;

    f = fopen(path, "rb");
    if (f == 0)
        return 0;
    fseek(f, 0, SEEK_END);
    n = ftell(f);
    fseek(f, 0, SEEK_SET);
    if (n <= 0) {
        fclose(f);
        return 0;
    }
    buf = (unsigned char *)calloc(1, (size_t)n + extra);
    if (buf == 0) {
        fclose(f);
        return 0;
    }
    ok = (fread(buf, 1, (size_t)n, f) == (size_t)n);
    fclose(f);
    if (ok)
        ok = MK4_ArenaInitFromMemory(buf, (unsigned)n + extra);
    free(buf);
    return ok;
}

int MK4_ArenaInitFromFile(const char *path)
{
    return MK4_ArenaInitFromFileReserve(path, 0);
}

#endif /* NON_MATCHING */
