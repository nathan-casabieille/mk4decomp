/**
 * Auto-split from misc_matchesV.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;
extern unsigned int g_acc_00542078;

/* @addr 0x0046c520 (51b)
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     +0x24
 *   mov     eax, [g_eventQueueNotMask]
 *   mov     [g_scaledInit_00542044], eax
 *   mov     eax, [eax*4 + 0x0c]
 *   mov     [g_scaledInit_00542044], eax
 *   mov     eax, [eax*4 + 0]
 *   mov     [g_scaledInit_00542044], eax
 *   jmp     eax
 *   ret
 */
extern void MStackBitFlagDispatch_00494750(void);
void CallPauseTripleScaledJmp_0046c520(void) {
    unsigned int v;
    MStackBitFlagDispatch_00494750();
    if (g_framePauseFlag) return;
    v = g_eventQueueNotMask;
    g_scaledInit_00542044 = v;
    v = ((ScenegraphNode *)(v * 4))->alloc_work_type;
    g_scaledInit_00542044 = v;
    v = *(unsigned int *)(v * 4);
    g_scaledInit_00542044 = v;
    ((void (*)(void))v)();
}
