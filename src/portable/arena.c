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

int MK4_ArenaInitFromFile(const char *path)
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
    buf = (unsigned char *)malloc((size_t)n);
    if (buf == 0) {
        fclose(f);
        return 0;
    }
    ok = (fread(buf, 1, (size_t)n, f) == (size_t)n);
    fclose(f);
    if (ok)
        ok = MK4_ArenaInitFromMemory(buf, (unsigned)n);
    free(buf);
    return ok;
}

#endif /* NON_MATCHING */
