/**
 * Arena seam test (host-native, no Win32 / no asm).
 *
 * Proves the relocated memory model resolves original VAs into the loaded
 * arena correctly: MK4_VA(va) / MK4_NODE(idx) read the bytes the original
 * process saw at `va`.
 *
 * Build + run via `make arena-test` (compiles with the host C compiler
 * under -DMK4_ARENA, loads build/arena.bin).
 */
#define MK4_ARENA 1
#include "portable/arena.h"
#include "portable/mem_model.h"

#include <stdio.h>
#include <string.h>

static int g_failures = 0;

static void check(int cond, const char *what)
{
    printf("  [%s] %s\n", cond ? "PASS" : "FAIL", what);
    if (!cond)
        g_failures++;
}

int main(int argc, char **argv)
{
    const char *blob = (argc > 1) ? argv[1] : "build/arena.bin";
    unsigned char *mz;
    unsigned pe_off;
    unsigned char *pe;
    unsigned char *node;

    if (!MK4_ArenaInitFromFile(blob)) {
        printf("FATAL: could not load %s (run `make arena-blob` first)\n", blob);
        return 2;
    }
    printf("arena: base=%p size=0x%08x\n", (void *)g_mk4Arena, g_mk4ArenaSize);

    /* 1. VA 0x00400000 (image base) must map to the DOS 'MZ' magic. */
    mz = MK4_VA(unsigned char, 0x00400000u);
    check(mz[0] == 'M' && mz[1] == 'Z', "MK4_VA(0x400000) -> 'MZ' (image base)");

    /* 2. e_lfanew at base+0x3c points to the 'PE\0\0' signature. */
    pe_off = *(unsigned *)MK4_VA(unsigned char, 0x00400000u + 0x3c);
    pe = MK4_VA(unsigned char, 0x00400000u + pe_off);
    check(pe[0] == 'P' && pe[1] == 'E' && pe[2] == 0 && pe[3] == 0,
          "MK4_VA(base + e_lfanew) -> 'PE\\0\\0' signature");

    /* 3. A packed-ptr node reference resolves inside the arena.
     *    g_nodeSlotsArea is at VA 0x0053e368 (packed idx = VA/4). */
    node = MK4_NODE(unsigned char, 0x0053e368u / 4u);
    check(node >= g_mk4Arena && node < g_mk4Arena + g_mk4ArenaSize,
          "MK4_NODE(g_nodeSlotsArea/4) lands inside the arena");
    check(node == g_mk4Arena + (0x0053e368u - 0x00400000u),
          "MK4_NODE matches g_mk4Arena + (VA - image_base)");

    printf(g_failures ? "\nFAILED (%d)\n" : "\nOK\n", g_failures);
    return g_failures ? 1 : 0;
}
