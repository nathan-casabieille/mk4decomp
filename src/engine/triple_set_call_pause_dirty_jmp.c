/**
 * Auto-split from misc_matchesG.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00446150 (44b)
 *   mov     eax, [g_eventQueueIdx]
 *   mov     [g_fightGroupHead], eax
 *   mov     [g_scaledInit_00542044], eax
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
void TripleSetCallPauseDirtyJmp_00446150(void) {
    unsigned int v = g_eventQueueIdx;
    g_fightGroupHead = v;
    g_scaledInit_00542044 = v;
    MStackBracket4_ListInsertZeroFill();
    if (g_framePauseFlag != 0) return;
    if ((g_xformDirtyFlags & 4) != 0) return;
    MStackPushTwoEntryChainCall();
}
