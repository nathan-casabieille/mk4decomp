/**
 * Auto-split from misc_matchesV.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;
extern unsigned int g_acc_00542078;

/* @addr 0x0046c520 (51b)
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     +0x24
 *   mov     eax, [g_eventQueueNotMask]
 *   mov     [g_currentNodeIdx], eax
 *   mov     eax, [eax*4 + 0x0c]
 *   mov     [g_currentNodeIdx], eax
 *   mov     eax, [eax*4 + 0]
 *   mov     [g_currentNodeIdx], eax
 *   jmp     eax
 *   ret
 */
extern void MStackBitFlagDispatch(void);
void CallPauseTripleScaledJmp(void) {
    unsigned int v;
    MStackBitFlagDispatch();
    if (g_framePauseFlag) return;
    v = g_eventQueueNotMask;
    g_currentNodeIdx = v;
    v = ((ScenegraphNode *)(v * 4))->alloc_work_type;
    g_currentNodeIdx = v;
    v = *(unsigned int *)(v * 4);
    g_currentNodeIdx = v;
    ((void (*)(void))v)();
}
