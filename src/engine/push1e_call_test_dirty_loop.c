/**
 * Auto-split from misc_matchesAA.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004923b0 (63b)
 *   push ebx; do { push 0x1e; call F1; add esp; push 0x1e; call F2;
 *                  load dirty flag; bl=4; if (dirty & bl) break; } while (1)
 *   pop ebx; ret
 */
extern void SaveCallRestore_004049d0(int);
extern void SaveCallRestoreOrXor_00404a00(int);
void Push1eCallTestDirtyLoop_004923b0(void) {
    SaveCallRestore_004049d0(0x1e);
    SaveCallRestoreOrXor_00404a00(0x1e);
    if ((g_xformDirtyFlags & 4) != 0) return;
    do {
        SaveCallRestore_004049d0(0x1e);
        SaveCallRestoreOrXor_00404a00(0x1e);
    } while ((g_xformDirtyFlags & 4) == 0);
}
