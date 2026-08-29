/**
 * Anim_LoadPackFile - 0x00401120 (496b game.anim) and its leaves.
 *
 * Loads <name>.AP1 (the blob pack) into one CRT-heap allocation, reads
 * <name>.AP0 (the directory) into the same buffer first to build the
 * per-id descriptor table at 0x4ffdec (12 bytes per id: +0 the blob
 * pointer = base + cumulative size, +8 keeps its low 15 bits and takes
 * the directory entry's flag bit 15), snapshots the 512-byte header to
 * 0x524158, then reads the full AP1 over the directory. The base lives
 * in [0x524358]. The static move tables carry ABSOLUTE heap addresses,
 * so the CRT-heap emulation (engine_crtheap.c) must place this buffer
 * where the original's HeapAlloc did - MK4_TRACE_HEAP calibrates.
 *
 * OnceCall passes the name VA 0x4d5084 ("anim"); the dev-path prefix
 * 0x4d506c and the "%s%s.AP0/1" formats live beside it.
 *
 * NATIVE-ONLY twins: the matching build synthesizes the original bytes.
 */
#ifdef NON_MATCHING

#include <stdio.h>
#include "portable/mem_model.h"

extern int  FSYS_fopen(const char *path, const char *mode);
extern int  FSYS_fseek(int fh, int off, int whence);
extern int  FSYS_ftell(int fh);
extern int  FSYS_fread(void *buf, unsigned int sz, unsigned int n, int fh);
extern int  FSYS_fclose(int fh);
extern unsigned int LoadArgPushCall(unsigned int size);
extern void ShowErrorMessage(const char *msg);

#define g_animPackBase (*(unsigned int *)MK4_VA(unsigned int, 0x524358u))

void ListInitLoop(void)
{
    unsigned int rec = 0x4ffdecu;

    while (*MK4_VA(int, rec) != -1) {
        *MK4_VA(unsigned int, rec) = 0;
        rec += 0xc;
    }
}

void Init0AndMax(void)
{
    int i;

    for (i = 0; i < 0xc; i++)
        *MK4_VA(unsigned int, 0x523ae8u + i * 4) = 0;
    for (i = 0; i < 0xc; i++)
        *MK4_VA(unsigned int, 0x523b28u + i * 4) = 0x7fffffffu;
}

unsigned int Anim_LoadPackFile(unsigned int name_va)
{
    char path[256];
    const char *dir = (const char *)MK4_PTR(0x4d506cu);
    const char *name = (const char *)MK4_PTR(name_va);
    int f1, f0, size1, size0;
    unsigned int base, cur, rec;
    unsigned char *host;

    sprintf(path, "%s%s.AP1", dir, name);
    f1 = FSYS_fopen(path, "rb");
    if (f1 == 0)
        return 0;
    FSYS_fseek(f1, 0, 2);
    size1 = FSYS_ftell(f1);
    FSYS_fseek(f1, 0, 0);

    base = LoadArgPushCall((unsigned int)size1);
    g_animPackBase = base;
    if (base == 0) {
        ShowErrorMessage((const char *)MK4_PTR(0x4d504cu));
        if (g_animPackBase == 0)
            return 0;
    }

    sprintf(path, "%s%s.AP0", dir, name);
    f0 = FSYS_fopen(path, "rb");
    if (f0 == 0)
        return 0;
    FSYS_fseek(f0, 0, 2);
    size0 = FSYS_ftell(f0);
    if (size0 > size1)
        return 0;
    FSYS_fseek(f0, 0, 0);
    FSYS_fread(MK4_PTR(base), 1, (unsigned int)size0, f0);
    FSYS_fclose(f0);

    /* header snapshot, then the directory walk */
    {
        unsigned char *src = (unsigned char *)MK4_PTR(base);
        unsigned char *dst = (unsigned char *)MK4_PTR(0x524158u);
        int i;
        for (i = 0; i < 0x200; i++)
            dst[i] = src[i];
    }
    ListInitLoop();

    cur = base;
    host = (unsigned char *)MK4_PTR(base + 0x200u);
    for (;;) {
        unsigned int id_flag = *(unsigned short *)host;
        unsigned int size = *(unsigned short *)(host + 2);
        unsigned int id, flag;

        if (id_flag == 0xffffu)
            break;
        id = id_flag & 0x7fffu;
        flag = (id_flag & 0x8000u) << 0;    /* bit 15, kept in place */
        rec = 0x4ffdecu + id * 3u * 4u;
        *MK4_VA(unsigned int, rec) = cur;
        *MK4_VA(unsigned int, rec + 8) =
            (*MK4_VA(unsigned int, rec + 8) & 0xffff7fffu) + flag;
        cur += size;
        host += 4;
    }

    FSYS_fread(MK4_PTR(base), 1, (unsigned int)size1, f1);
    FSYS_fclose(f1);
    return base;
}

#endif /* NON_MATCHING */
