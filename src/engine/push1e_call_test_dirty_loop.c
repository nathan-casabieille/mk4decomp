/**
 * Auto-split from misc_matchesAA.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

/* @addr 0x004923b0 (63b)
 *   push ebx; do { push 0x1e; call F1; add esp; push 0x1e; call F2;
 *                  load dirty flag; bl=4; if (dirty & bl) break; } while (1)
 *   pop ebx; ret
 */
extern void SaveCallRestore(int);
extern void SaveCallRestoreOrXor(int);
void Push1eCallTestDirtyLoop(void) {
    SaveCallRestore(0x1e);
    SaveCallRestoreOrXor(0x1e);
    if ((g_xformDirtyFlags & 4) != 0) return;
    do {
        SaveCallRestore(0x1e);
        SaveCallRestoreOrXor(0x1e);
    } while ((g_xformDirtyFlags & 4) == 0);
}
