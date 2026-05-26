/**
 * Auto-split from misc_matchesH.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004389e0 (44b)
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   cmp     [g_eventQueueChild], 0x64
 *   jge     +5
 *   jmp     +0x14
 *   mov     [g_eventQueueChild], 0x1e
 *   jmp     +5
 *   ret
 */
extern void PushPop84TripleCall_00438b90(void);
extern void InstallSelfCountdownDispatch_00438a10(void);
extern void InstallSelfCountdownDispatch_00438a10(void);
void CmpJmpConstStoreJmp_004389e0(void) {
    PushPop84TripleCall_00438b90();
    if (g_framePauseFlag) return;
    if ((int)g_eventQueueChild < 0x64) {
        InstallSelfCountdownDispatch_00438a10();
        return;
    }
    g_eventQueueChild = 0x1e;
    InstallSelfCountdownDispatch_00438a10();
}
