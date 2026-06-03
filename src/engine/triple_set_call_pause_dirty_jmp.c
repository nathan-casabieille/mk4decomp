/**
 * Auto-split from misc_matchesG.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

/* @addr 0x00446150 (44b)
 *   mov     eax, [g_eventQueueIdx]
 *   mov     [g_fightGroupHead], eax
 *   mov     [g_currentNodeIdx], eax
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   test    byte [g_xformDirtyFlags], 4
 *   jne     .ret
 *   jmp     T
 *   ret
 */
extern void MStackBracket4_ListInsertZeroFill(void);
extern void MStackPushTwoEntryChainCall(void);
void TripleSetCallPauseDirtyJmp(void) {
    unsigned int v = g_eventQueueIdx;
    g_fightGroupHead = v;
    g_currentNodeIdx = v;
    MStackBracket4_ListInsertZeroFill();
    if (g_framePauseFlag != 0) return;
    if ((g_xformDirtyFlags & 4) != 0) return;
    MStackPushTwoEntryChainCall();
}
