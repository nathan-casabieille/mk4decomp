/**
 * Auto-split from misc_matchesPP.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;

/* @addr 0x00470cc0 (71b)
 *   eax = arg0 >> 2 → g_eventQueueEnd; clears g_currentNodeFlags;
 *   walks 3 entries through [eax*4+0]: stores them into
 *   g_eventQueueNotMask, g_xformEntityIdx, and g_walkCallback (1st);
 *   each step inc eax + restore to g_eventQueueEnd; jmp T.
 */
extern void InstallSelfBranchIndirect_00470d10(void);
void PackedLoadAdvanceJmp_00470cc0(int arg) {
    unsigned int packed = (unsigned int)(arg >> 2);
    unsigned int v1, v2;
    g_currentNodeFlags = 0;
    g_eventQueueEnd = packed;
    v1 = *(unsigned int *)(packed * 4);
    packed++;
    g_eventQueueNotMask = v1;
    g_eventQueueEnd = packed;
    v2 = *(unsigned int *)(packed * 4);
    packed++;
    g_xformEntityIdx = v2;
    g_eventQueueEnd = packed;
    g_walkCallback = (void (*)(void))v1;
    InstallSelfBranchIndirect_00470d10();
}
