/**
 * 2 "copy + scaled-load + install + tail-jmp" helpers (34 bytes each).
 *
 * Pattern:
 *   mov     eax, [g_A]
 *   mov     ecx, [g_baseSel]
 *   mov     [g_fightGroupHead], eax
 *   mov     edx, [ecx*4 + 0x30]
 *   mov     [g_currentNodeIdx], edx
 *   jmp     Tail
 */
#include "engine/scenegraph.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

extern void MStackBracket2_TreeWalkRecursive(void);
extern void BootChainBidirRecurseWalk(void);

/* @addr 0x00445ed0 */
void CopyLoadInstallJmp_00445ed0(void) {
    g_fightGroupHead = g_eventQueueIdx;
    g_currentNodeIdx = *(unsigned int *)(g_baseSel * 4 + 0x30);
    MStackBracket2_TreeWalkRecursive();
}

/* @addr 0x00446210 */
void CopyLoadInstallJmp_00446210(void) {
    g_fightGroupHead = g_eventQueueEnd;
    g_currentNodeIdx = *(unsigned int *)(g_baseSel * 4 + 0x30);
    BootChainBidirRecurseWalk();
}
